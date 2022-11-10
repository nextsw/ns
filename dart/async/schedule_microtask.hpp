#ifndef DART_ASYNC_SCHEDULE_MICROTASK
#define DART_ASYNC_SCHEDULE_MICROTASK
#include <base.hpp>

#include <dart/core/core.hpp>


class _AsyncCallbackEntryCls : public ObjectCls {
public:
    _AsyncCallback callback;

    _AsyncCallbackEntry next;


private:

     _AsyncCallbackEntryCls(_AsyncCallback callback);
};
using _AsyncCallbackEntry = std::shared_ptr<_AsyncCallbackEntryCls>;
_AsyncCallbackEntry _nextCallback;

_AsyncCallbackEntry _lastCallback;

_AsyncCallbackEntry _lastPriorityCallback;

bool _isInCallbackLoop;

void _microtaskLoop();

void _startMicrotaskLoop();

void _scheduleAsyncCallback(_AsyncCallback callback);

void _schedulePriorityAsyncCallback(_AsyncCallback callback);

void scheduleMicrotask(void callback() );


class _AsyncRunCls : public ObjectCls {
public:

private:

    static void _scheduleImmediate(void callback() );
};
using _AsyncRun = std::shared_ptr<_AsyncRunCls>;


#endif