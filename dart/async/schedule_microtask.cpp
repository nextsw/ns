#include "schedule_microtask.hpp"
void _microtaskLoop() {
    for (; entry != nullptr; entry = _nextCallback) {
        _lastPriorityCallback = nullptr;
        auto next = entry.next;
        _nextCallback = next;
        if (next == nullptr)         {
            _lastCallback = nullptr;
        }
        (entry.callback)();
    }
}

void _startMicrotaskLoop() {
    _isInCallbackLoop = true;
    ;
}

void _scheduleAsyncCallback(_AsyncCallback callback) {
    _AsyncCallbackEntry newEntry = _AsyncCallbackEntry(callback);
    _AsyncCallbackEntry lastCallback = _lastCallback;
    if (lastCallback == nullptr) {
        _nextCallback = _lastCallback = newEntry;
        if (!_isInCallbackLoop) {
            _AsyncRun._scheduleImmediate(_startMicrotaskLoop);
        }
    } else {
        lastCallback.next = newEntry;
        _lastCallback = newEntry;
    }
}

void _schedulePriorityAsyncCallback(_AsyncCallback callback) {
    if (_nextCallback == nullptr) {
        _scheduleAsyncCallback(callback);
        _lastPriorityCallback = _lastCallback;
        return;
    }
    _AsyncCallbackEntry entry = _AsyncCallbackEntry(callback);
    _AsyncCallbackEntry lastPriorityCallback = _lastPriorityCallback;
    if (lastPriorityCallback == nullptr) {
        entry.next = _nextCallback;
        _nextCallback = _lastPriorityCallback = entry;
    } else {
        auto next = lastPriorityCallback.next;
        entry.next = next;
        lastPriorityCallback.next = entry;
        _lastPriorityCallback = entry;
        if (next == nullptr) {
            _lastCallback = entry;
        }
    }
}

void scheduleMicrotask(FunctionType callback) {
    _Zone currentZone = Zone._current;
    if (identical(_rootZone, currentZone)) {
        _rootScheduleMicrotask(nullptr, nullptr, _rootZone, callback);
        return;
    }
    _ZoneFunction implementation = currentZone._scheduleMicrotask;
    if (identical(_rootZone, implementation.zone) && _rootZone.inSameErrorZone(currentZone)) {
        _rootScheduleMicrotask(nullptr, nullptr, currentZone, currentZone.registerCallback(callback));
        return;
    }
    Zone.current.scheduleMicrotask(Zone.current.bindCallbackGuarded(callback));
}
