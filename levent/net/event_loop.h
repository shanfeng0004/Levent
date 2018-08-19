#ifndef _LEVENT_NET_CONDITION_H__
#define _LEVENT_NET_CONDITION_H__

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

namespace levent
{

class EventLoop : public boost::noncopyable
{
public:
    typedef boost::function<void ()> AcceptCallback;
    typedef boost::function<void ()> ReadCallback;
    typedef boost::function<void ()> WriteCallback;

    EventLoop();

    ~EventLoop();

    void SetAcceptCallback();

    void SetReadCallback();

    void SetWriteCallback();

    void Loop();

private:
    AcceptCallback accept_cb_; 
    ReadCallback read_cb_;
    WriteCallback write_cb_;
};

}

#endif // _LEVENT_NET_CONDITION_H__
