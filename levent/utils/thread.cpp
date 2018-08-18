#include <levent/utils/thread.h>

namespace levent
{

struct ThreadData
{
    pid_t tid;
    WaitGroup wg;
    Thread::ThreadFunc func;
};

void ThreadRoutine(void* arg)
{
    ThreadData* data = static_cast<ThreadData*>(arg);
    data->func();
    data->wg.Done(); 
}

Thread::Thread(ThreadFunc& func, WaitGroup& wg)
    : started_(false),
      joined_(false),
      tid_(0),
      func_(func),
      wg_(wg);
{
}

Thread::~Thread()
{
    if (started_ && !joined_) {
        pthread_detach(tid_);
    }
}

void Thread::Start()
{
    ThreadData* data = new ThreadData(tid_, wg_, func_);
    if (pthread_create(tid_, NULL, ThreadRoutine, data)) {
        started_ = true;
    }
}

int Thread::Join()
{
    pthread_join(tid_, NULL);
    joined_ = true;
}

}
