#ifndef _LEVENT_UTILS_THREAD_POOL_H__
#define _LEVENT_UTILS_THREAD_POOL_H__

#include <deque>
#include <map>

#include <boost/shared_ptr.hpp>

#include <levent/utils/thread.h>

namespace levent
{

class ThreadPool : public boost::noncopyable
{
public:
    typedef boost::function<void ()> Task;
    typedef boost::shared_ptr<Thread> ThreadPtr;

    explicit ThreadPool(int thread_num, int max_task_length);

    ~ThreadPool();

    void Start();

    void Stop();

    void AddTask(Task& t);

private:
    void runInThread();

private:
    bool running_;
    int thread_num_;
    int max_task_length_;
    Mutex mutex_;
    Condition not_full_;
    Condition not_empty_;
    std::map<int, ThreadPtr> threads_;
    std::deque<Task> queue_;
};

}

#endif // _LEVENT_UTILS_THREAD_POOL_H__
