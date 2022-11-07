#include "ticker.hpp"
Ticker::Ticker(TickerCallback _onTick, String debugLabel) {
    {
        assert(());
    }
}

bool Ticker::muted() {
    return _muted;
}

void Ticker::muted(bool value) {
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

bool Ticker::isTicking() {
    if (_future == nullptr) {
        return false;
    }
    if (muted) {
        return false;
    }
    if (SchedulerBinding.instance.framesEnabled) {
        return true;
    }
    if (SchedulerBinding.instance.schedulerPhase != SchedulerPhase.idle) {
        return true;
    }
    return false;
}

bool Ticker::isActive() {
    return _future != nullptr;
}

TickerFuture Ticker::start() {
    assert(());
    assert(_startTime == nullptr);
    _future = TickerFuture._();
    if (shouldScheduleTick) {
        scheduleTick();
    }
    if (SchedulerBinding.instance.schedulerPhase.index > SchedulerPhase.idle.index && SchedulerBinding.instance.schedulerPhase.index < SchedulerPhase.postFrameCallbacks.index) {
        _startTime = SchedulerBinding.instance.currentFrameTimeStamp;
    }
    return _future!;
}

DiagnosticsNode Ticker::describeForError(String name) {
    return <Ticker>DiagnosticsProperty(name, thistoString(true));
}

void Ticker::stop(bool canceled) {
    if (!isActive) {
        return;
    }
    TickerFuture localFuture = _future!;
    _future = nullptr;
    _startTime = nullptr;
    assert(!isActive);
    unscheduleTick();
    if (canceled) {
        localFuture._cancel(this);
    } else {
        localFuture._complete();
    }
}

bool Ticker::scheduled() {
    return _animationId != nullptr;
}

bool Ticker::shouldScheduleTick() {
    return !muted && isActive && !scheduled;
}

void Ticker::scheduleTick(bool rescheduling) {
    assert(!scheduled);
    assert(shouldScheduleTick);
    _animationId = SchedulerBinding.instance.scheduleFrameCallback(_tickrescheduling);
}

void Ticker::unscheduleTick() {
    if (scheduled) {
        SchedulerBinding.instance.cancelFrameCallbackWithId(_animationId!);
        _animationId = nullptr;
    }
    assert(!shouldScheduleTick);
}

void Ticker::absorbTicker(Ticker originalTicker) {
    assert(!isActive);
    assert(_future == nullptr);
    assert(_startTime == nullptr);
    assert(_animationId == nullptr);
    assert((originalTicker._future == nullptr) == (originalTicker._startTime == nullptr), "Cannot absorb Ticker after it has been disposed.");
    if (originalTicker._future != nullptr) {
        _future = originalTicker._future;
        _startTime = originalTicker._startTime;
        if (shouldScheduleTick) {
            scheduleTick();
        }
        originalTicker._future = nullptr;
        originalTicker.unscheduleTick();
    }
    originalTicker.dispose();
}

void Ticker::dispose() {
    if (_future != nullptr) {
        TickerFuture localFuture = _future!;
        _future = nullptr;
        assert(!isActive);
        unscheduleTick();
        localFuture._cancel(this);
    }
    assert(());
}

String Ticker::toString(bool debugIncludeStack) {
    StringBuffer buffer = StringBuffer();
    buffer.write("${objectRuntimeType(this, 'Ticker')}(");
    assert(());
    buffer.write(")");
    assert(());
    return buffer.toString();
}

void Ticker::_tick(Duration timeStamp) {
    assert(isTicking);
    assert(scheduled);
    _animationId = nullptr;
    _startTime = timeStamp;
    _onTick(timeStamp - _startTime!);
    if (shouldScheduleTick) {
        scheduleTick(true);
    }
}

void TickerFuture::complete() {
    _complete();
}

void TickerFuture::whenCompleteOrCancel(VoidCallback callback) {
    ;
    orCancel.<void>then(thunkthunk);
}

Future<void> TickerFuture::orCancel() {
    if (_secondaryCompleter == nullptr) {
        _secondaryCompleter = <void>Completer();
        if (_completed != nullptr) {
            if (_completed!) {
                _secondaryCompleter!.complete();
            } else {
                _secondaryCompleter!.completeError(const TickerCanceled());
            }
        }
    }
    return _secondaryCompleter!.future;
}

Stream<void> TickerFuture::asStream() {
    return _primaryCompleter.future.asStream();
}

Future<void> TickerFuture::catchError(FunctionType onError, FunctionType test) {
    return _primaryCompleter.future.catchError(onErrortest);
}

Future<R> TickerFuture::then<R>(FunctionType onError, FunctionType onValue) {
    return _primaryCompleter.future.<R>then(onValueonError);
}

Future<void> TickerFuture::timeout(FunctionType onTimeout, Duration timeLimit) {
    return _primaryCompleter.future.timeout(timeLimitonTimeout);
}

Future<void> TickerFuture::whenComplete(FunctionType action) {
    return _primaryCompleter.future.whenComplete(action);
}

String TickerFuture::toString() {
    return "${describeIdentity(this)}(${ _completed == null ? "active" : _completed! ? "complete" : "canceled" })";
}

void TickerFuture::_complete() {
    assert(_completed == nullptr);
    _completed = true;
    _primaryCompleter.complete();
    _secondaryCompleter?.complete();
}

void TickerFuture::_cancel(Ticker ticker) {
    assert(_completed == nullptr);
    _completed = false;
    _secondaryCompleter?.completeError(TickerCanceled(ticker));
}

String TickerCanceled::toString() {
    if (ticker != nullptr) {
        return "This ticker was canceled: $ticker";
    }
    return "The ticker was canceled before the "orCancel" property was first used.";
}
