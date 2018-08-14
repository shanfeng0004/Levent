#include <levent/utils/condition.h>
#include <levent/utils/mutex.h>

namespace levent
{
bool Condition::waitForSeconds(int seconds)
{
    pthread_timestruc_t to;
    to.tv_sec = time(NULL) + seconds;
    to.tv_nsec = 0;

	MutexGuard mg(mutex_)
	err = pthread_cond_timedwait(&cond_, mutex_.getMutex(), &to);
	if (err == ETIMEDOUT) {
		return true;
	}

    return false;
}

}

