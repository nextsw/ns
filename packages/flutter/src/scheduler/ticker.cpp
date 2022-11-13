#include "ticker.hpp"
TickerCls::TickerCls(TickerCallback _onTick, String debugLabel) {
    {
        assert([=] () {
            _debugCreationStack = StackTraceCls::current;
            return true;
        }());
    }
}

bool TickerCls::muted() {
    return _muted;
}

void TickerCls::muted(bool value) {
    if (value == muted()) {
        return;
    }
    _muted = value;
    if (value) {
        unscheduleTick();
    } else {
        if (shouldScheduleTick()) {
        scheduleTick();
    }
;
    }}

bool TickerCls::isTicking() {
    if (_future == nullptr) {
        return false;
    }
    if (muted()) {
        return false;
    }
    if (SchedulerBindingCls::instance->framesEnabled) {
        return true;
    }
    if (SchedulerBindingCls::instance->schedulerPhase != SchedulerPhaseCls::idle) {
        return true;
    }
    return false;
}

bool TickerCls::isActive() {
    return _future != nullptr;
}

TickerFuture TickerCls::start() {
    assert([=] () {
        if (isActive()) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    assert(_startTime == nullptr);
    _future = TickerFutureCls->_();
    if (shouldScheduleTick()) {
        scheduleTick();
    }
    if (SchedulerBindingCls::instance->schedulerPhase->index > SchedulerPhaseCls::idle->index && SchedulerBindingCls::instance->schedulerPhase->index < SchedulerPhaseCls::postFrameCallbacks->index) {
        _startTime = SchedulerBindingCls::instance->currentFrameTimeStamp;
    }
    return _future!;
}

DiagnosticsNode TickerCls::describeForError(String name) {
    return <Ticker>make<DiagnosticsPropertyCls>(name, this, toString(true));
}

void TickerCls::stop(bool canceled) {
    if (!isActive()) {
        return;
    }
    TickerFuture localFuture = _future!;
    _future = nullptr;
    _startTime = nullptr;
    assert(!isActive());
    unscheduleTick();
    if (canceled) {
        localFuture->_cancel(this);
    } else {
        localFuture->_complete();
    }
}

bool TickerCls::scheduled() {
    return _animationId != nullptr;
}

bool TickerCls::shouldScheduleTick() {
    return !muted() && isActive() && !scheduled();
}

void TickerCls::scheduleTick(bool rescheduling) {
    assert(!scheduled());
    assert(shouldScheduleTick());
    _animationId = SchedulerBindingCls::instance->scheduleFrameCallback(_tick, rescheduling);
}

void TickerCls::unscheduleTick() {
    if (scheduled()) {
        SchedulerBindingCls::instance->cancelFrameCallbackWithId(_animationId!);
        _animationId = nullptr;
    }
    assert(!shouldScheduleTick());
}

void TickerCls::absorbTicker(Ticker originalTicker) {
    assert(!isActive());
    assert(_future == nullptr);
    assert(_startTime == nullptr);
    assert(_animationId == nullptr);
    assert((originalTicker->_future == nullptr) == (originalTicker->_startTime == nullptr), __s("Cannot absorb Ticker after it has been disposed."));
    if (originalTicker->_future != nullptr) {
        _future = originalTicker->_future;
        _startTime = originalTicker->_startTime;
        if (shouldScheduleTick()) {
            scheduleTick();
        }
        originalTicker->_future = nullptr;
        originalTicker->unscheduleTick();
    }
    originalTicker->dispose();
}

void TickerCls::dispose() {
    if (_future != nullptr) {
        TickerFuture localFuture = _future!;
        _future = nullptr;
        assert(!isActive());
        unscheduleTick();
        localFuture->_cancel(this);
    }
    assert([=] () {
        _startTime = DurationCls::zero;
        return true;
    }());
}

String TickerCls::toString(bool debugIncludeStack) {
    StringBuffer buffer = make<StringBufferCls>();
    buffer->write(__sf("%s(", objectRuntimeType(this, __s("Ticker"))));
    assert([=] () {
        buffer->write(debugLabel | __s(""));
        return true;
    }());
    buffer->write(__s(")"));
    assert([=] () {
        if (debugIncludeStack) {
            buffer->writeln();
            buffer->writeln(__sf("The stack trace when the %s was actually created was:", runtimeType));
            FlutterErrorCls->defaultStackFilter(_debugCreationStack->toString()->trimRight()->split(__s("\n")))->forEach(buffer->writeln);
        }
        return true;
    }());
    return buffer->toString();
}

void TickerCls::_tick(Duration timeStamp) {
    assert(isTicking());
    assert(scheduled());
    _animationId = nullptr;
    _startTime |= timeStamp;
    _onTick(timeStamp - _startTime!);
    if (shouldScheduleTick()) {
        scheduleTick(true);
    }
}

void TickerFutureCls::complete() {
    _complete();
}

void TickerFutureCls::whenCompleteOrCancel(VoidCallback callback) {
    InlineMethod;
    orCancel()-><void>then(thunk, thunk);
}

Future<void> TickerFutureCls::orCancel() {
    if (_secondaryCompleter == nullptr) {
        _secondaryCompleter = <void>make<CompleterCls>();
        if (_completed != nullptr) {
            if (_completed!) {
                _secondaryCompleter!->complete();
            } else {
                _secondaryCompleter!->completeError(make<TickerCanceledCls>());
            }
        }
    }
    return _secondaryCompleter!->future();
}

Stream<void> TickerFutureCls::asStream() {
    return _primaryCompleter->future()->asStream();
}

Future<void> TickerFutureCls::catchError(std::function<void ()> onError, std::function<bool(Object )> test) {
    return _primaryCompleter->future()->catchError(onError, test);
}

template<typename R>
Future<R> TickerFutureCls::then(std::function<FutureOr<R>(void value)> onValue, std::function<void ()> onError) {
    return _primaryCompleter->future()-><R>then(onValue, onError);
}

Future<void> TickerFutureCls::timeout(Duration timeLimit, std::function<FutureOr<void>()> onTimeout) {
    return _primaryCompleter->future()->timeout(timeLimit, onTimeout);
}

Future<void> TickerFutureCls::whenComplete(std::function<Object()> action) {
    return _primaryCompleter->future()->whenComplete(action);
}

String TickerFutureCls::toString() {
    return __sf("%s(%s", describeIdentity(this), _completed == nullptr? __s("active") : _completed!? __s("complete") : __s("canceled)"));
}

void TickerFutureCls::_complete() {
    assert(_completed == nullptr);
    _completed = true;
    _primaryCompleter->complete();
    _secondaryCompleter?->complete();
}

void TickerFutureCls::_cancel(Ticker ticker) {
    assert(_completed == nullptr);
    _completed = false;
    _secondaryCompleter?->completeError(make<TickerCanceledCls>(ticker));
}

String TickerCanceledCls::toString() {
    if (ticker != nullptr) {
        return __sf("This ticker was canceled: %s", ticker);
    }
    return __s("The ticker was canceled before the "orCancel" property was first used.");
}
