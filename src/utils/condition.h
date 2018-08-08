#ifndef _LEVENT_CONDITION_H__
#define _LEVENT_CONDITION_H__

#include <boost/noncopyable.hpp>
#include <pthread.h>

namespace levent
{

class Condition : public boost::noncopyable
{
public:

private:
    Mutex mutex_;
    Mutex mutex_;
}

}

#endif // _LEVENT_CONDITION_H__
