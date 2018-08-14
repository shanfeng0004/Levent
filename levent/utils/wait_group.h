#ifndef _LEVENT_WAIT_GROUP_H__
#define _LEVENT_WAIT_GROUP_H__

namespace
{

class WaitGroup : public boost::noncopyable
{
    WaitGroup();

    ~WaitGroup();

    void Add();

    void Done();

    void Wait();

private:
    Mutex mutex_;
    unsigned int count_;
}

}

#endif // _LEVENT_WAIT_GROUP_H__
