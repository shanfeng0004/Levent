#ifndef _LEVENT_NET_SOCKET_OPERATOR_H__
#define _LEVENT_NET_SOCKET_OPERATOR_H__

namespace levent
{

class SocketOperator
{
    static int Bind(int sock_fd, const struct sockaddr *addr, socklen_t len);

    static int Listen(int sock_fd);

    static int Accept(int sockfd, const struct sockaddr_in6* addr);

    static int Connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);

    static int Read(int sock_fd, void *buf, size_t nbyte);

    static int Write(int sock_fd, void *buf, size_t nbyte);

    static int Close(int sock_fd);

    static int ShutDown(int sock_fd, int how);

    static void SetReuseAddr(int sock_fd);

    static void SetNonBlock(int sock_fd);
};

}

#endif // _LEVENT_NET_SOCKET_OPERATOR_H__
