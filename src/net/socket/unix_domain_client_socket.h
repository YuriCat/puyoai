#ifndef NET_UNIX_DOMAIN_CLIENT_SOCKET_H_
#define NET_UNIX_DOMAIN_CLIENT_SOCKET_H_

#include "base/base.h"
#include "net/socket/socket.h"

namespace net {

class UnixDomainClientSocket : public Socket {
public:
    UnixDomainClientSocket(UnixDomainClientSocket&& socket) noexcept;
    ~UnixDomainClientSocket() override;

    UnixDomainClientSocket& operator=(UnixDomainClientSocket&& socket) noexcept;

    bool connect(const char* path);

private:
    explicit UnixDomainClientSocket(SocketDescriptor sd) : Socket(sd) {}

    friend class SocketFactory;
    DISALLOW_COPY_AND_ASSIGN(UnixDomainClientSocket);
};

} // namespace net

#endif // NET_UNIX_DOMAIN_CLIENT_SOCKET_H_
