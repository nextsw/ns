#ifndef DART_ASYNC_TIMER
#define DART_ASYNC_TIMER
#include <base.hpp>

#include <dart/core/core.hpp>


class TimerCls : public ObjectCls {
public:

     TimerCls(std::function<void()> callback, Duration duration);

    virtual void  periodic(std::function<void(Timer timer)> callback, Duration duration);

    static void run(std::function<void()> callback);

    virtual void cancel();
    virtual int tick();
    virtual bool isActive();
private:

    static Timer _createTimer(std::function<void()> callback, Duration duration);
    static Timer _createPeriodicTimer(std::function<void(Timer timer)> callback, Duration duration);
};
using Timer = std::shared_ptr<TimerCls>;


#endif