#include "mayah_ai.h"

#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "core/probability/puyo_possibility.h"

using namespace std;

DECLARE_int32(num_threads);

int main(int argc, char* argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    PuyoPossibility::initialize();

    LOG(INFO) << "num_threads = " << FLAGS_num_threads;

    if (FLAGS_num_threads > 1) {
        unique_ptr<Executor> executor = Executor::makeDefaultExecutor();
        MayahAI(argc, argv, executor.get()).runLoop();
    } else {
        MayahAI(argc, argv).runLoop();
    }

    return 0;
}
