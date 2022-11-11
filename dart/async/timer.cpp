#include "timer.hpp"
TimerCls::TimerCls(Duration duration, std::function<void()> callback) {
    {
        if (ZoneCls::current == ZoneCls::root) {
            return ZoneCls::current->createTimer(duration, callback);
        }
        return ZoneCls::current->createTimer(duration, ZoneCls::current->bindCallbackGuarded(callback));
    }
}

void TimerCls::periodic(Duration duration, std::function<void(Timer timer)> callback) {
    if (ZoneCls::current == ZoneCls::root) {
        return ZoneCls::current->createPeriodicTimer(duration, callback);
    }
    auto boundCallback = ZoneCls::current-><Timer>bindUnaryCallbackGuarded(callback);
    return ZoneCls::current->createPeriodicTimer(duration, boundCallback);
}

void TimerCls::run(std::function<void()> callback) {
    make<TimerCls>(DurationCls::zero, callback);
}
