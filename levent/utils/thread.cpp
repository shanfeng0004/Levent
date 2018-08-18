#include <levent/utils/thread.h>

namespace levent
{

struct ThreadData
{
public:
    ThreadData(const Thread::ThreadFunc& func, WaitGroup* wg)
        : func(func),
          wg(wg) {}

public:
    Thread::ThreadFunc func;
    WaitGroup* wg;
};

void* ThreadRoutine(void* arg)
{
    ThreadData* data = static_cast<ThreadData*>(arg);
    data->func();
    data->wg->Done();

    return NULL;
}

Thread::Thread(ThreadFunc& func)
    : started_(false),
      joined_(false),
      pthread_id_(0),
      func_(func),
      wg_(1)
{
}

Thread::~Thread()
{
    if (started_ && !joined_) {
        pthread_detach(pthread_id_);
    }
}

void Thread::Start()
{
    ThreadData* data = new ThreadData(func_, &wg_);
    if (pthread_create(&pthread_id_, NULL, &ThreadRoutine, data)) {
        started_ = true;
    }
}

void Thread::Join()
{
    pthread_join(pthread_id_, NULL);
    joined_ = true;
}

}

