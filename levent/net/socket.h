#ifndef _LEVENT_NET_SOCKET_H__
#define _LEVENT_NET_SOCKET_H__

#include <boost/noncopyable.hpp>

namespace levent
{

class Socket : public boost::noncopyable
{
public:
    Socket();

    ~Socket();

    int Listen();

    int Accept(int fd);

    int Connect();

    int Read();

    int Write();

    int Close();

    int ShutDown();

private:
    const int fd_;
};

}

#endif // _LEVENT_NET_SOCKET_H__
