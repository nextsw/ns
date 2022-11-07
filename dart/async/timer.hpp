#ifndef TIMER_H
#define TIMER_H
#include <memory>




class Timer {
public:

     Timer(FunctionType callback, Duration duration);

    void  periodic(FunctionType callback, Duration duration);

    static void run(FunctionType callback);

    void cancel();

    int tick();

    bool isActive();

private:

    external static Timer _createTimer(FunctionType callback, Duration duration);

    external static Timer _createPeriodicTimer(FunctionType callback, Duration duration);

};

#endif