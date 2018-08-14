#ifndef _LEVENT_THREAD_H__
#define _LEVENT_THREAD_H__

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <pthread.h>

namespace levent
{
class Thread : public boost::noncopyable
{
public:
    typedef boost::function<void ()> ThreadFunc;

    explicit Thread(ThreadFunc func);

    ~Thread();

    void Start();

    int Join();

    bool IsStarted() { return started_; }

    pid_t Tid() { return tid_; }
    
private:
    bool started_;
    pid_t tid_;
}

}

#endif // _LEVENT_THREAD_H__
