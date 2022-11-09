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
    if (value == muted) {
        return;
    }
    _muted = value;
    if (value) {
        unscheduleTick();
    } else     {
        if (shouldScheduleTick) {
        scheduleTick();
    }
;
    }}

bool TickerCls::isTicking() {
    if (_future == nullptr) {
        return false;
    }
    if (muted) {
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
        if (isActive) {
            ;
        }
        return true;
    }());
    assert(_startTime == nullptr);
    _future = TickerFutureCls->_();
    if (shouldScheduleTick) {
        scheduleTick();
    }
    if (SchedulerBindingCls::instance->schedulerPhase->index > SchedulerPhaseCls::idle->index && SchedulerBindingCls::instance->schedulerPhase->index < SchedulerPhaseCls::postFrameCallbacks->index) {
        _startTime = SchedulerBindingCls::instance->currentFrameTimeStamp;
    }
    return _future!;
}

DiagnosticsNode TickerCls::describeForError(String name) {
    return <Ticker>make<DiagnosticsPropertyCls>(name, thistoString(true));
}

void TickerCls::stop(bool canceled) {
    if (!isActive) {
        return;
    }
    TickerFuture localFuture = _future!;
    _future = nullptr;
    _startTime = nullptr;
    assert(!isActive);
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
    return !muted && isActive && !scheduled;
}

void TickerCls::scheduleTick(bool rescheduling) {
    assert(!scheduled);
    assert(shouldScheduleTick);
    _animationId = SchedulerBindingCls::instance->scheduleFrameCallback(_tickrescheduling);
}

void TickerCls::unscheduleTick() {
    if (scheduled) {
        SchedulerBindingCls::instance->cancelFrameCallbackWithId(_animationId!);
        _animationId = nullptr;
    }
    assert(!shouldScheduleTick);
}

void TickerCls::absorbTicker(Ticker originalTicker) {
    assert(!isActive);
    assert(_future == nullptr);
    assert(_startTime == nullptr);
    assert(_animationId == nullptr);
    assert((originalTicker->_future == nullptr) == (originalTicker->_startTime == nullptr), "Cannot absorb Ticker after it has been disposed.");
    if (originalTicker->_future != nullptr) {
        _future = originalTicker->_future;
        _startTime = originalTicker->_startTime;
        if (shouldScheduleTick) {
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
        assert(!isActive);
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
    buffer->write("${objectRuntimeType(this, 'Ticker')}(");
    assert([=] () {
        buffer->write(debugLabel ?? "");
        return true;
    }());
    buffer->write(")");
    assert([=] () {
        if (debugIncludeStack) {
            buffer->writeln();
            buffer->writeln("The stack trace when the $runtimeType was actually created was:");
            FlutterErrorCls->defaultStackFilter(_debugCreationStack->toString()->trimRight()->split("\n"))->forEach(buffer->writeln);
        }
        return true;
    }());
    return buffer->toString();
}

void TickerCls::_tick(Duration timeStamp) {
    assert(isTicking);
    assert(scheduled);
    _animationId = nullptr;
    _startTime = timeStamp;
    _onTick(timeStamp - _startTime!);
    if (shouldScheduleTick) {
        scheduleTick(true);
    }
}

void TickerFutureCls::complete() {
    _complete();
}

void TickerFutureCls::whenCompleteOrCancel(VoidCallback callback) {
    InlineMethod;
    orCancel-><void>then(thunkthunk);
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
    return _secondaryCompleter!->future;
}

Stream<void> TickerFutureCls::asStream() {
    return _primaryCompleter->future->asStream();
}

Future<void> TickerFutureCls::catchError(void  onError() , bool test(Object ) ) {
    return _primaryCompleter->future->catchError(onErrortest);
}

Future<R> TickerFutureCls::thentemplate<typename R> (void  onError() , FutureOr<R> onValue(void value) ) {
    return _primaryCompleter->future-><R>then(onValueonError);
}

Future<void> TickerFutureCls::timeout(FutureOr<void> onTimeout() , Duration timeLimit) {
    return _primaryCompleter->future->timeout(timeLimitonTimeout);
}

Future<void> TickerFutureCls::whenComplete(dynamic action() ) {
    return _primaryCompleter->future->whenComplete(action);
}

String TickerFutureCls::toString() {
    return "${describeIdentity(this)}(${ _completed == null ? "active" : _completed! ? "complete" : "canceled" })";
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
        return "This ticker was canceled: $ticker";
    }
    return "The ticker was canceled before the "orCancel" property was first used.";
}
