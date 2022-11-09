#include "timer.hpp"
TimerCls::TimerCls(void callback() , Duration duration) {
    {
        if (ZoneCls::current == ZoneCls::root) {
            return ZoneCls::current->createTimer(duration, callback);
        }
        return ZoneCls::current->createTimer(duration, ZoneCls::current->bindCallbackGuarded(callback));
    }
}

void TimerCls::periodic(void callback(Timer timer) , Duration duration) {
    if (ZoneCls::current == ZoneCls::root) {
        return ZoneCls::current->createPeriodicTimer(duration, callback);
    }
    auto boundCallback = ZoneCls::current-><Timer>bindUnaryCallbackGuarded(callback);
    return ZoneCls::current->createPeriodicTimer(duration, boundCallback);
}

void TimerCls::run(void callback() ) {
    make<TimerCls>(DurationCls::zero, callback);
}
