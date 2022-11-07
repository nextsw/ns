#ifndef SCHEDULE_MICROTASK_H
#define SCHEDULE_MICROTASK_H
#include <memory>




class _AsyncCallbackEntry {
public:
    _AsyncCallback callback;

    _AsyncCallbackEntry next;


private:

     _AsyncCallbackEntry(_AsyncCallback callback);

};
_AsyncCallbackEntry _nextCallback;

_AsyncCallbackEntry _lastCallback;

_AsyncCallbackEntry _lastPriorityCallback;

bool _isInCallbackLoop;

void _microtaskLoop();

void _startMicrotaskLoop();

void _scheduleAsyncCallback(_AsyncCallback callback);

void _schedulePriorityAsyncCallback(_AsyncCallback callback);

void scheduleMicrotask(FunctionType callback);


class _AsyncRun {
public:

private:

    external static void _scheduleImmediate(FunctionType callback);

};

#endif