#include <errno.h>
#include <time.h>
#include <levent/utils/condition.h>

namespace levent
{
bool Condition::waitForSeconds(int seconds)
{
    struct timespec to;
    clock_gettime(CLOCK_REALTIME, &to);

    to.tv_sec += to.tv_sec + seconds;

	MutexGuard mg(mutex_);
	int err = pthread_cond_timedwait(&cond_, mutex_.getPthreadMutex(), &to);
	if (err == ETIMEDOUT) {
		return true;
	}

    return false;
}

}

