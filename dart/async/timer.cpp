#include "timer.hpp"
Timer::Timer(FunctionType callback, Duration duration) {
    {
        if (Zone.current == Zone.root) {
            return Zone.current.createTimer(duration, callback);
        }
        return Zone.current.createTimer(duration, Zone.current.bindCallbackGuarded(callback));
    }
}

void Timer::periodic(FunctionType callback, Duration duration) {
    if (Zone.current == Zone.root) {
        return Zone.current.createPeriodicTimer(duration, callback);
    }
    auto boundCallback = Zone.current.<Timer>bindUnaryCallbackGuarded(callback);
    return Zone.current.createPeriodicTimer(duration, boundCallback);
}

void Timer::run(FunctionType callback) {
    Timer(Duration.zero, callback);
}
