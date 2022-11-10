#ifndef DART_CORE_STOPWATCH
#define DART_CORE_STOPWATCH
#include <base.hpp>

#include <dart/core/core.hpp>


class StopwatchCls : public ObjectCls {
public:

     StopwatchCls();

    virtual int frequency();

    virtual void start();

    virtual void stop();

    virtual void reset();

    virtual int elapsedTicks();

    virtual Duration elapsed();

    int elapsedMicroseconds();
    int elapsedMilliseconds();
    virtual bool isRunning();

private:
    static int _frequency;

    int _start;

    int _stop;


    static int _initTicker();
    static int _now();
};
using Stopwatch = std::shared_ptr<StopwatchCls>;


#endif