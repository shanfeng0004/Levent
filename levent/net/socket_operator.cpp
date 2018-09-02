#include <socket_operator.h>

namespace levent
{

int SocketOperator::Bind(int sock_fd, const struct sockaddr *addr, socklen_t len)
{
    int ret = ::bind(sockfd, addr, addrlen);
    if (ret < 0) {
        LOG(FATAL) << "bind fatal:" << ret;
    }
}

int SocketOperator::Listen(int sock_fd)
{
    int ret = ::listen(sockfd, SOMAXCONN);
    if (ret != 0) {
        LOG(FATAL) << "listen fatal:" << ret;
    }
    
    return ret;
}

int Accept(int sockfd, const struct sockaddr_in6* addr)
{
    socklen_t len = static_cast<socklen_t>(sizeof *addr);
    int conn_fd = ::accept(sockfd, sockaddr_cast(addr), &addrlen);

    if (conn_fd < 0) {
        LOG(FATAL) << "accept fatal:" << conn_fd;
    }

    retrun conn_fd
}

int Connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
    ret = connect(sockfd, (const struct sockaddr *)&seraddr, sizeof(seraddr));

    if (ret < 0) {
        LOG(FATAL) << "connect fatal:" << ret;
    }
}

size_t Read(int sock_fd, void *buf, size_t nbyte)
{
    return ::read(sock_fd, buf, nbyte);
}

size_t Write(int sock_fd, void *buf, size_t nbyte)
{
    return ::write(sock_fd, buf, nbyte);
}

int Close(int sock_fd)
{
    int ret = ::close(sock_fd);

    if (ret != 0) {
        LOG(FATAL) << "close fatal:" << ret;
    }
}

int ShutDown(int sock_fd, int how)
{
    // how: 0-SHUT_RD, 1-SHUT_WR, 2-SHUT_RDWR
    int ret = ::shutdown(sock_fd, how);

    if (ret != 0) {
        LOG(FATAL) << "shutdown fatal:" << ret;
    }
}

}
