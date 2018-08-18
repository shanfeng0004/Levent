#include <thread_pool.h>

namespace levent
{

ThreadPool::ThreadPool()
        : running(false),
          mutex_(),
          not_full_(mutex_),
          not_empty_(mutex_)
{
    threads_.reset();
    queue_.reset();
}

~ThreadPool()
{
    if (runnning_) {
        Stop():
    }
}

void ThreadPool::Start(int thread_num)
{
    for (int i = 0; i < thread_num_; ++i) {
        Thread t(boost::bind(&ThreadPool::runInThread, this));
        threads_[i] = t;
        t.Start();
    }

    is_run = true;
}

void ThreadPool::Stop()
{
    map<int, Thread>::iterator it  = threads_.begin();
    map<int, Thread>::iterator end = threads_.end();
    for (; it != end; ++it) {
        it->second->Join();
    }
}

bool ThreadPool::AddTask(Task& t)
{
}

void ThreadPool::runInThread()
{
}

}
