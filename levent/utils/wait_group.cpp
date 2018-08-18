#include <levent/utils/wait_group.h>

namespace levent
{
WaitGroup::WaitGroup()
            :mutex_(),
             cond_(mutex_),
             count_(0)
{
}

void WaitGroup::Add()
{
    MutexGuard mg(mutex_);
    count_++;
}

void WaitGroup::Done()
{
    MutexGuard mg(mutex_);
    count_--;
    if (count_ == 0) {
        cond_.NoticeAll();
    }
}

void WaitGroup::Wait()
{
    while (count_ > 0) {
        cond_.Wait();
    }
}

}
