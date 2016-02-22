#include "core/server/connector/pipe_connector_posix.h"

#include <fcntl.h>
#include <poll.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <chrono>
#include <cstddef>
#include <cstring>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "core/frame_request.h"
#include "core/frame_response.h"

using namespace std;

DEFINE_bool(realtime, true, "use realtime");

// static
unique_ptr<Connector> PipeConnectorPosix::create(int playerId, const string& programName)
{
    CHECK(0 <= playerId && playerId < 10) << playerId;

    if (programName.find("fifo:") == 0) {
        string::size_type colon = programName.find(":", 5);
        string uplink_fifo = programName.substr(5, colon - 5);
        string downlink_fifo = programName.substr(colon + 1);
        CHECK(mkfifo(uplink_fifo.c_str(), 0777) == 0);
        CHECK(chmod(uplink_fifo.c_str(), 0777) == 0);
        CHECK(mkfifo(downlink_fifo.c_str(), 0777) == 0);
        CHECK(chmod(downlink_fifo.c_str(), 0777) == 0);
        int uplink_fd = open(uplink_fifo.c_str(), O_RDONLY);
        CHECK(uplink_fd >= 0);
        int downlink_fd = open(downlink_fifo.c_str(), O_WRONLY);
        CHECK(downlink_fd >= 0);

        unique_ptr<Connector> connector(new PipeConnectorPosix(playerId, downlink_fd, uplink_fd));
        return connector;
    }

    // File descriptors.
    int fd_field_status[2];
    int fd_command[2];

    if (pipe(fd_field_status) < 0)
        PLOG(FATAL) << "Pipe error. ";
    if (pipe(fd_command) < 0)
        PLOG(FATAL) << "Pipe error. ";

    pid_t pid = fork();
    if (pid < 0)
        PLOG(FATAL) << "Failed to fork. ";

    if (pid > 0) {
        // Server.
        LOG(INFO) << "Created a child process (pid = " << pid << ")";

        unique_ptr<Connector> connector(new PipeConnectorPosix(playerId, fd_field_status[1], fd_command[0]));
        close(fd_field_status[0]);
        close(fd_command[1]);

        return connector;
    }

    // Client.
    if (dup2(fd_field_status[0], STDIN_FILENO) < 0)
        PLOG(FATAL) << "Failed to dup2. ";
    if (dup2(fd_command[1], STDOUT_FILENO) < 0)
        PLOG(FATAL) << "Failed to dup2. ";

    close(fd_field_status[0]);
    close(fd_field_status[1]);
    close(fd_command[0]);
    close(fd_command[1]);

    char filename[] = "Player_";
    filename[6] = '1' + playerId;

    if (execl(programName.c_str(), programName.c_str(), filename, nullptr) < 0)
        PLOG(FATAL) << "Failed to start a child process. ";

    LOG(FATAL) << "should not be reached.";
    return unique_ptr<Connector>();
}

// static
bool PipeConnectorPosix::pollAndReceive(bool waitTimeout, int frameId, const vector<PipeConnector*>& pipeConnectors, vector<FrameResponse>* cfr)
{
    TimePoint startTimePoint = Clock::now();

    pollfd pollfds[NUM_PLAYERS];
    for (size_t i = 0; i < pipeConnectors.size(); ++i) {
        pollfds[i].fd = static_cast<PipeConnectorPosix*>(pipeConnectors[i])->readerFd_;
        pollfds[i].events = POLLIN;
    }

    bool connection = true;
    bool received_data_for_this_frame[NUM_PLAYERS] {};
    while (true) {
        int timeout_ms = 0;
        if (waitTimeout) {
            // Check timeout.
            timeout_ms = getRemainingMilliSeconds(startTimePoint);
            if (timeout_ms <= 0) {
                break;
            }
        }

        // Wait for user input.
        int actions = poll(pollfds, pipeConnectors.size(), timeout_ms);

        if (actions < 0) {
            LOG(ERROR) << strerror(errno);
            break;
        } else if (actions == 0) {
            if (!waitTimeout)
                break;
            continue;
        }

        for (size_t i = 0; i < pipeConnectors.size(); ++i) {
            PipeConnectorPosix* connector = static_cast<PipeConnectorPosix*>(pipeConnectors[i]);
            if (pollfds[i].revents & POLLIN) {
                FrameResponse response;
                if (connector->receive(&response)) {
                    cfr[connector->playerId()].push_back(response);
                    if (response.frameId == frameId) {
                        received_data_for_this_frame[i] = true;
                    }
                }
            } else if (pollfds[i].revents & (POLLERR | POLLHUP | POLLNVAL)) {
                LOG(ERROR) << "[P" << connector->playerId() << "] Closed the connection.";
                connection = false;
                connector->setClosed(true);
            }
        }

        // If a realtime game flag is not set, do not wait for timeout, and
        // continue the game as soon as possible.
        if (!FLAGS_realtime) {
            bool all_data_is_read = true;
            for (size_t i = 0; i < pipeConnectors.size(); ++i) {
                if (!received_data_for_this_frame[i]) {
                    all_data_is_read = false;
                }
            }
            if (all_data_is_read) {
                break;
            }
        }
    }

    int usec = getUsecFromStart(startTimePoint);
    LOG(INFO) << "Frame " << frameId  << " took " << usec << " [us]";

    return connection;
}

PipeConnectorPosix::PipeConnectorPosix(int player, int writerFd, int readerFd) :
    PipeConnector(player),
    writerFd_(writerFd),
    readerFd_(readerFd)
{
}

PipeConnectorPosix::~PipeConnectorPosix()
{
    if (close(writerFd_) < 0) {
        PLOG(ERROR) << "close";
    }
    if (close(readerFd_) < 0) {
        PLOG(ERROR) << "close";
    }
}

bool PipeConnectorPosix::writeData(const void* data, size_t size)
{
    while (size > 0) {
        ssize_t n = ::write(writerFd_, data, size);
        if (n < 0) {
            if (errno == EAGAIN)
                continue;
            PLOG(ERROR) << "write";
            return false;
        }
        if (n == 0) {
            PLOG(ERROR) << "unexpected write failure";
            return false;
        }

        size -= n;
        data = reinterpret_cast<const void*>(reinterpret_cast<const char*>(data) + size);
    }

    return true;
}

bool PipeConnectorPosix::readData(void* data, size_t size)
{
    while (size > 0) {
        ssize_t n = ::read(readerFd_, data, size);
        if (n < 0) {
            if (errno == EAGAIN)
                continue;
            PLOG(ERROR) << "read";
            return false;
        }

        if (n == 0) {
            LOG(ERROR) << "unexpected EOF";
            return false;
        }

        size -= n;
        data = reinterpret_cast<void*>(reinterpret_cast<char*>(data) + size);
    }

    return true;
}
