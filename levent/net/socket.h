#ifndef _LEVENT_NET_SOCKET_H__
#define _LEVENT_NET_SOCKET_H__

namespace levent
{

int Listen();

int Accept(int fd);

int Connect();

int Read();

int Write();

int Close();

int ShutDown();

}

#endif // _LEVENT_NET_SOCKET_H__
