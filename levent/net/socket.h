#ifndef _LEVENT_NET_SOCKET_H__
#define _LEVENT_NET_SOCKET_H__

namespace levent
{

class Socket : public boost::noncopyable
{
public:
    Socket();

    ~Socket();

    static int Listen();

    static int Accept(int fd);

    static int Connect();

    static int Read();

    static int Write();

    static int Close();

    static int ShutDown();
};

}

#endif // _LEVENT_NET_SOCKET_H__
