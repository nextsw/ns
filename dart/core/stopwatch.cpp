#include "stopwatch.hpp"
StopwatchCls::StopwatchCls() {
    {
            Set<E> set1 = make<SetCls<>>();    for (auto _x1 : elements) {    {        set1.add(_x1);    }_frequency;
    }
}

int StopwatchCls::frequency() {
    return _frequency;
}

void StopwatchCls::start() {
    int stop = _stop;
    if (stop != nullptr) {
        _start = _now() - stop;
        _stop = nullptr;
    }
}

void StopwatchCls::stop() {
    _stop = _now();
}

void StopwatchCls::reset() {
    _start = _stop ?? _now();
}

int StopwatchCls::elapsedTicks() {
    return (_stop ?? _now()) - _start;
}

Duration StopwatchCls::elapsed() {
    return make<DurationCls>(elapsedMicroseconds);
}

bool StopwatchCls::isRunning() {
    return _stop == nullptr;
}
