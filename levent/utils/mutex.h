#ifndef _LEVENT_MUTEX_H__
#define _LEVENT_MUTEX_H__

#include <boost/noncopyable.hpp>
#include <pthread.h>

namespace levent
{

class Mutex : public boost::noncopyable
{
public:
    Mutex()
    {
        pthread_mutex_init(&mutex_, NULL);
    }

    ~Mutex()
    {
        pthread_mutex_destroy(&mutex_);
    }

	pthread_mutex_t* getPthreadMutex()
	{
		return &mutex_;
	}

    void Lock()
    {
        pthread_mutex_lock(&mutex_);
    }

    void UnLock()
    {
        pthread_mutex_unlock(&mutex_);
    }

private:
    pthread_mutex_t mutex_;
};

class MutexGuard : public boost::noncopyable
{
public:
    explicit MutexGuard(Mutex& mutex)
        : mutex_(mutex)
    {
        mutex_.Lock();
    }

    ~MutexGuard()
    {
        mutex_.UnLock();
    }

private:
    Mutex& mutex_;
};

}

#endif // _LEVENT_MUTEX_H__
