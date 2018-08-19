#ifndef _LEVENT_UTILS_THREAD_H__
#define _LEVENT_UTILS_THREAD_H__

#include <pthread.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include <levent/utils/wait_group.h>

namespace levent
{

class Thread : public boost::noncopyable
{
public:
    typedef boost::function<void ()> ThreadFunc;

    explicit Thread(ThreadFunc& func);

    ~Thread();

    void Start();

    void Join();

    bool IsStarted() { return started_; }

    pthread_t PthreadId() { return pthread_id_; }

private:
    bool started_;
    bool joined_;
    pthread_t pthread_id_;
    ThreadFunc func_;
    WaitGroup wg_;
};

}

#endif // _LEVENT_UTILS_THREAD_H__
