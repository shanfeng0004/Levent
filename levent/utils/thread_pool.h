#ifndef _LEVENT_THREAD_POOL_H__
#define _LEVENT_THREAD_POOL_H__

#include <thread.h>

namespace levent
{

class ThreadPool : public boost::noncopyable
{
public:
    typedef boost::function<void ()> Task;

    explicit ThreadPool();

    ~ThreadPool();

    void Start(int thread_num);

    void Stop();

    bool AddTask(Task& t);

private:
    void runInThread();

private:
    bool running_;
    int thread_num_;
    Mutex mutex_;
    Condition not_full_;
    Condition not_empty_;
    map<int, Thread> threads_;
    std::deque<Task> queue_;
};

}

#endif // _LEVENT_THREAD_POOL_H__
