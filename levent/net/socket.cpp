#include <levent/net/socket.h>

namespace levent
{
namespace socket
{
Socket::Socket(const int fd)
         : fd_(fd)
{
}

Socket::~Socket()
{
}

int Socket::Listen()
{
    int ret = ::listen(sockfd, SOMAXCONN);
    if (ret != 0) {
        LOG(ERROR) << "listen error:" << ret;
    }
    
    return ret;
}

int Socket::Accept(int fd)
{
}

int Socket::Connect()
{
}

int Socket::Read()
{
}

int Socket::Write()
{
}

int Socket::Close()
{
}

int Socket::ShutDown()
{
}

}
}

