#include <levent/utils/wait_group.h>

namespace
{
WaitGroup::WaitGroup()
            :mutex_(),
             cond_(mutex_),
             count_(0)
{
}

void WaitGroup::Add()
{
    MutexGuard(mutex_);
    count_++;
}

void WaitGroup::Done()
{
    MutexGuard(mutex_);
    count--;
    cond_.NoticeAll();
}

void WaitGroup::Wait()
{
    while (count_ > 0) {
        cond_.Wait();
    }
}

}
