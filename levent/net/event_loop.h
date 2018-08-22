#ifndef _LEVENT_NET_CONDITION_H__
#define _LEVENT_NET_CONDITION_H__

#include <boost/function.hpp>

namespace levent
{

class EventLoop : public boost::noncopyable
{
public:
    typedef boost::function<void ()> EventCallback;

    EventLoop();

    ~EventLoop();

    void SetAcceptCallback();

    void SetReadCallback();

    void SetWriteCallback();

    void Loop();

private:
    EventCallback accept_cb_; 
    EventCallback read_cb_;
    EventCallback write_cb_;
};

}

#endif // _LEVENT_NET_CONDITION_H__
