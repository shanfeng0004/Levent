#include <boost/bind.hpp>

#include <levent/utils/thread_pool.h>

namespace levent
{

ThreadPool::ThreadPool(int thread_num, int max_task_length)
        : running_(false),
          thread_num_(thread_num),
          max_task_length_(max_task_length),
          mutex_(),
          not_full_(mutex_),
          not_empty_(mutex_)
{
    threads_.clear();
    queue_.resize(max_task_length);
}

ThreadPool::~ThreadPool()
{
    if (running_) {
        Stop();
    }
}

void ThreadPool::Start()
{
    for (int i = 0; i < thread_num_; ++i) {
        Thread::ThreadFunc func = boost::bind(&ThreadPool::runInThread, this);
        ThreadPtr t(new Thread(func));
        threads_[i] = t;
        t->Start();
    }

    running_ = true;
}

void ThreadPool::Stop()
{
    std::map<int, ThreadPtr>::iterator it  = threads_.begin();
    std::map<int, ThreadPtr>::iterator end = threads_.end();
    for (; it != end; ++it) {
        it->second->Join();
    }
}

void ThreadPool::AddTask(Task& t)
{
    MutexGuard mg(mutex_);
    while (queue_.size() > max_task_length_) {
        not_full_.Wait();
    }

    queue_.push_back(t);
    not_empty_.Notice();
}

void ThreadPool::runInThread()
{
    while (running_) {
        Task t;
        {
            MutexGuard mg(mutex_);

            while (queue_.empty() && running_) {
                not_empty_.Wait();
            }

            if (!queue_.empty()) {
                t = queue_.front();
                queue_.pop_front();

                not_full_.Notice();
            }
        }
        if (t) {
            t();
        }
    }
}

}
