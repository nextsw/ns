#ifndef DART_ASYNC_TIMER
#define DART_ASYNC_TIMER
#include <base.hpp>

#include <dart/core/core.hpp>


class TimerCls : public ObjectCls {
public:

     TimerCls(void callback() , Duration duration);

    virtual void  periodic(void callback(Timer timer) , Duration duration);

    static void run(void callback() );

    virtual void cancel();
    virtual int tick();
    virtual bool isActive();
private:

    static Timer _createTimer(void callback() , Duration duration);
    static Timer _createPeriodicTimer(void callback(Timer timer) , Duration duration);
};
using Timer = std::shared_ptr<TimerCls>;


#endif