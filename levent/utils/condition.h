#ifndef _LEVENT_UTILS_CONDITION_H__
#define _LEVENT_UTILS_CONDITION_H__

#include <boost/noncopyable.hpp>
#include <pthread.h>

#include <levent/utils/mutex.h>

namespace levent
{

class Condition : public boost::noncopyable
{
public:
    explicit Condition(Mutex& mutex)
        : mutex_(mutex)
    {
        pthread_cond_init(&cond_, NULL);
    }

    ~Condition()
    {
        pthread_cond_destroy(&cond_);
    }

    void Wait()
    {
        MutexGuard mg(mutex_);
        pthread_cond_wait(&cond_, mutex_.getPthreadMutex());
    }

    bool waitForSeconds(int seconds);

    void Notice()
    {
        pthread_cond_signal(&cond_);
    }

    void NoticeAll()
    {
        pthread_cond_broadcast(&cond_);
    }

private:
    pthread_cond_t cond_;
    Mutex& mutex_;
};

}

#endif // _LEVENT_UTILS_CONDITION_H__
