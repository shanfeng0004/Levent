#ifndef _LEVENT_NET_SOCKET_OPERATOR_H__
#define _LEVENT_NET_SOCKET_OPERATOR_H__

namespace levent
{

class SocketOperator
{
    static int Bind();

    static int Listen();

    static int Accept(int fd);

    static int Connect();

    static int Read();

    static int Write();

    static int Close();

    static int ShutDown();
};

}

#endif // _LEVENT_NET_SOCKET_OPERATOR_H__
