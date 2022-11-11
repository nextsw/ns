#ifndef DART_ASYNC_TIMER
#define DART_ASYNC_TIMER
#include <base.hpp>

#include <dart/core/core.hpp>


class TimerCls : public ObjectCls {
public:

     TimerCls(Duration duration, std::function<void()> callback);

    virtual void  periodic(Duration duration, std::function<void(Timer timer)> callback);

    static void run(std::function<void()> callback);

    virtual void cancel();
    virtual int tick();
    virtual bool isActive();
private:

    static Timer _createTimer(Duration duration, std::function<void()> callback);
    static Timer _createPeriodicTimer(Duration duration, std::function<void(Timer timer)> callback);
};
using Timer = std::shared_ptr<TimerCls>;


#endif