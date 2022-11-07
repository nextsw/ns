#include "stream_impl.hpp"
void _BufferingStreamSubscription::zoned(Zone _zone, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError)

void _BufferingStreamSubscription::onData(FunctionType handleData) {
    _onData = <T>_registerDataHandler(_zone, handleData);
}

void _BufferingStreamSubscription::onError(FunctionType handleError) {
    _onError = _registerErrorHandler(_zone, handleError);
}

void _BufferingStreamSubscription::onDone(FunctionType handleDone) {
    _onDone = _registerDoneHandler(_zone, handleDone);
}

void _BufferingStreamSubscription::pause(Future<void> resumeSignal) {
    if (_isCanceled)     {
        return;
    }
    bool wasPaused = _isPaused;
    bool wasInputPaused = _isInputPaused;
    _state = (_state + _STATE_PAUSE_COUNT) | _STATE_INPUT_PAUSED;
    resumeSignal?.whenComplete(resume);
    if (!wasPaused)     {
        _pending?.cancelSchedule();
    }
    if (!wasInputPaused && !_inCallback)     {
        _guardCallback(_onPause);
    }
}

void _BufferingStreamSubscription::resume() {
    if (_isCanceled)     {
        return;
    }
    if (_isPaused) {
        _decrementPauseCount();
        if (!_isPaused) {
            if (_hasPending && !_pending!.isEmpty) {
                _pending!.schedule(this);
            } else {
                assert(_mayResumeInput);
                _state = ~_STATE_INPUT_PAUSED;
                if (!_inCallback)                 {
                    _guardCallback(_onResume);
                }
            }
        }
    }
}

Future _BufferingStreamSubscription::cancel() {
    _state = ~_STATE_WAIT_FOR_CANCEL;
    if (!_isCanceled) {
        _cancel();
    }
    return _cancelFuture ?? Future._nullFuture;
}

Future<E> _BufferingStreamSubscription::asFuture<E>(E futureValue) {
    E resultValue;
    if (futureValue == nullptr) {
        if (!<E>typeAcceptsNull()) {
            ;
        }
        resultValue = (;
    } else {
        resultValue = futureValue;
    }
    _Future<E> result = <E>_Future();
    _onDone = ;
    _onError = ;
    return result;
}

bool _BufferingStreamSubscription::isPaused() {
    return _isPaused;
}

_BufferingStreamSubscription::_BufferingStreamSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    {
        this.zoned(Zone.current, onData, onError, onDone, cancelOnError);
    }
}

void _BufferingStreamSubscription::_setPendingEvents(_PendingEvents<T> pendingEvents) {
    assert(_pending == nullptr);
    if (pendingEvents == nullptr)     {
        return;
    }
    _pending = pendingEvents;
    if (!pendingEvents.isEmpty) {
        _state = _STATE_HAS_PENDING;
        pendingEvents.schedule(this);
    }
}

FunctionType _BufferingStreamSubscription::_registerDataHandler<T>(FunctionType handleData, Zone zone) {
    return zone.<void, T>registerUnaryCallback(handleData ?? _nullDataHandler);
}

FunctionType _BufferingStreamSubscription::_registerErrorHandler(FunctionType handleError, Zone zone) {
    handleError = _nullErrorHandler;
    if (handleError is FunctionType) {
        return zone.<dynamic, Object, StackTrace>registerBinaryCallback(handleError);
    }
    if (handleError is FunctionType) {
        return zone.<dynamic, Object>registerUnaryCallback(handleError);
    }
    ;
}

FunctionType _BufferingStreamSubscription::_registerDoneHandler(FunctionType handleDone, Zone zone) {
    return zone.registerCallback(handleDone ?? _nullDoneHandler);
}

bool _BufferingStreamSubscription::_isInputPaused() {
    return (_state & _STATE_INPUT_PAUSED) != 0;
}

bool _BufferingStreamSubscription::_isClosed() {
    return (_state & _STATE_CLOSED) != 0;
}

bool _BufferingStreamSubscription::_isCanceled() {
    return (_state & _STATE_CANCELED) != 0;
}

bool _BufferingStreamSubscription::_waitsForCancel() {
    return (_state & _STATE_WAIT_FOR_CANCEL) != 0;
}

bool _BufferingStreamSubscription::_inCallback() {
    return (_state & _STATE_IN_CALLBACK) != 0;
}

bool _BufferingStreamSubscription::_hasPending() {
    return (_state & _STATE_HAS_PENDING) != 0;
}

bool _BufferingStreamSubscription::_isPaused() {
    return _state >= _STATE_PAUSE_COUNT;
}

bool _BufferingStreamSubscription::_canFire() {
    return  < _STATE_IN_CALLBACK;
}

bool _BufferingStreamSubscription::_mayResumeInput() {
    return !_isPaused && (_pending?.isEmpty ?? true);
}

bool _BufferingStreamSubscription::_cancelOnError() {
    return (_state & _STATE_CANCEL_ON_ERROR) != 0;
}

void _BufferingStreamSubscription::_cancel() {
    _state = _STATE_CANCELED;
    if (_hasPending) {
        _pending!.cancelSchedule();
    }
    if (!_inCallback)     {
        _pending = nullptr;
    }
    _cancelFuture = _onCancel();
}

void _BufferingStreamSubscription::_decrementPauseCount() {
    assert(_isPaused);
    _state = _STATE_PAUSE_COUNT;
}

void _BufferingStreamSubscription::_add(T data) {
    assert(!_isClosed);
    if (_isCanceled)     {
        return;
    }
    if (_canFire) {
        _sendData(data);
    } else {
        _addPending(<T>_DelayedData(data));
    }
}

void _BufferingStreamSubscription::_addError(Object error, StackTrace stackTrace) {
    if (_isCanceled)     {
        return;
    }
    if (_canFire) {
        _sendError(error, stackTrace);
    } else {
        _addPending(_DelayedError(error, stackTrace));
    }
}

void _BufferingStreamSubscription::_close() {
    assert(!_isClosed);
    if (_isCanceled)     {
        return;
    }
    _state = _STATE_CLOSED;
    if (_canFire) {
        _sendDone();
    } else {
        _addPending(const _DelayedDone());
    }
}

void _BufferingStreamSubscription::_onPause() {
    assert(_isInputPaused);
}

void _BufferingStreamSubscription::_onResume() {
    assert(!_isInputPaused);
}

Future<void> _BufferingStreamSubscription::_onCancel() {
    assert(_isCanceled);
    return nullptr;
}

void _BufferingStreamSubscription::_addPending(_DelayedEvent event) {
    auto pending = _pending ??= <T>_PendingEvents();
    pending.add(event);
    if (!_hasPending) {
        _state = _STATE_HAS_PENDING;
        if (!_isPaused) {
            pending.schedule(this);
        }
    }
}

void _BufferingStreamSubscription::_sendData(T data) {
    assert(!_isCanceled);
    assert(!_isPaused);
    assert(!_inCallback);
    bool wasInputPaused = _isInputPaused;
    _state = _STATE_IN_CALLBACK;
    _zone.runUnaryGuarded(_onData, data);
    _state = ~_STATE_IN_CALLBACK;
    _checkState(wasInputPaused);
}

void _BufferingStreamSubscription::_sendError(Object error, StackTrace stackTrace) {
    assert(!_isCanceled);
    assert(!_isPaused);
    assert(!_inCallback);
    bool wasInputPaused = _isInputPaused;
    ;
    if (_cancelOnError) {
        _state = _STATE_WAIT_FOR_CANCEL;
        _cancel();
        auto cancelFuture = _cancelFuture;
        if (cancelFuture != nullptr && !identical(cancelFuture, Future._nullFuture)) {
            cancelFuture.whenComplete(sendError);
        } else {
            sendError();
        }
    } else {
        sendError();
        _checkState(wasInputPaused);
    }
}

void _BufferingStreamSubscription::_sendDone() {
    assert(!_isCanceled);
    assert(!_isPaused);
    assert(!_inCallback);
    ;
    _cancel();
    _state = _STATE_WAIT_FOR_CANCEL;
    auto cancelFuture = _cancelFuture;
    if (cancelFuture != nullptr && !identical(cancelFuture, Future._nullFuture)) {
        cancelFuture.whenComplete(sendDone);
    } else {
        sendDone();
    }
}

void _BufferingStreamSubscription::_guardCallback(FunctionType callback) {
    assert(!_inCallback);
    bool wasInputPaused = _isInputPaused;
    _state = _STATE_IN_CALLBACK;
    callback();
    _state = ~_STATE_IN_CALLBACK;
    _checkState(wasInputPaused);
}

void _BufferingStreamSubscription::_checkState(bool wasInputPaused) {
    assert(!_inCallback);
    if (_hasPending && _pending!.isEmpty) {
        _state = ~_STATE_HAS_PENDING;
        if (_isInputPaused && _mayResumeInput) {
            _state = ~_STATE_INPUT_PAUSED;
        }
    }
    while (true) {
        if (_isCanceled) {
            _pending = nullptr;
            return;
        }
        bool isInputPaused = _isInputPaused;
        if (wasInputPaused == isInputPaused)         {
                    break;
        }
        _state = _STATE_IN_CALLBACK;
        if (isInputPaused) {
            _onPause();
        } else {
            _onResume();
        }
        _state = ~_STATE_IN_CALLBACK;
        wasInputPaused = isInputPaused;
    }
    if (_hasPending && !_isPaused) {
        _pending!.schedule(this);
    }
}

StreamSubscription<T> _StreamImpl::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    cancelOnError = false;
    StreamSubscription<T> subscription = _createSubscription(onData, onError, onDone, cancelOnError);
    _onListen(subscription);
    return subscription;
}

StreamSubscription<T> _StreamImpl::_createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return <T>_BufferingStreamSubscription(onData, onError, onDone, cancelOnError);
}

void _StreamImpl::_onListen(StreamSubscription subscription) {
}

void _nullDataHandler(dynamic value) {
}

void _nullErrorHandler(Object error, StackTrace stackTrace) {
    Zone.current.handleUncaughtError(error, stackTrace);
}

void _nullDoneHandler() {
}

void _DelayedData::perform(_EventDispatch<T> dispatch) {
    dispatch._sendData(value);
}

void _DelayedError::perform(_EventDispatch dispatch) {
    dispatch._sendError(error, stackTrace);
}

void _DelayedDone::perform(_EventDispatch dispatch) {
    dispatch._sendDone();
}

_DelayedEvent _DelayedDone::next() {
    return nullptr;
}

void _DelayedDone::next(_DelayedEvent _) {
    ;
}

bool _PendingEvents::isScheduled() {
    return _state == stateScheduled;
}

void _PendingEvents::schedule(_EventDispatch<T> dispatch) {
    if (isScheduled)     {
        return;
    }
    assert(!isEmpty);
    if (_eventScheduled) {
        assert(_state == stateCanceled);
        _state = stateScheduled;
        return;
    }
    scheduleMicrotask();
    _state = stateScheduled;
}

void _PendingEvents::cancelSchedule() {
    if (isScheduled)     {
        _state = stateCanceled;
    }
}

bool _PendingEvents::isEmpty() {
    return lastPendingEvent == nullptr;
}

void _PendingEvents::add(_DelayedEvent event) {
    auto lastEvent = lastPendingEvent;
    if (lastEvent == nullptr) {
        firstPendingEvent = lastPendingEvent = event;
    } else {
        lastPendingEvent = lastEvent.next = event;
    }
}

void _PendingEvents::handleNext(_EventDispatch<T> dispatch) {
    assert(!isScheduled);
    assert(!isEmpty);
    _DelayedEvent event = firstPendingEvent!;
    _DelayedEvent nextEvent = event.next;
    firstPendingEvent = nextEvent;
    if (nextEvent == nullptr) {
        lastPendingEvent = nullptr;
    }
    event.perform(dispatch);
}

void _PendingEvents::clear() {
    if (isScheduled)     {
        cancelSchedule();
    }
    firstPendingEvent = lastPendingEvent = nullptr;
}

bool _PendingEvents::_eventScheduled() {
    return _state >= stateScheduled;
}

bool _DoneStreamSubscription::isPaused() {
    return _state >= _PAUSED;
}

void _DoneStreamSubscription::onData(FunctionType handleData) {
}

void _DoneStreamSubscription::onError(FunctionType handleError) {
}

void _DoneStreamSubscription::onDone(FunctionType handleDone) {
    _onDone = handleDone;
}

void _DoneStreamSubscription::pause(Future<void> resumeSignal) {
    _state = _PAUSED;
    if (resumeSignal != nullptr)     {
        resumeSignal.whenComplete(resume);
    }
}

void _DoneStreamSubscription::resume() {
    if (isPaused) {
        _state = _PAUSED;
        if (!isPaused && !_isSent) {
            _schedule();
        }
    }
}

Future _DoneStreamSubscription::cancel() {
    return Future._nullFuture;
}

Future<E> _DoneStreamSubscription::asFuture<E>(E futureValue) {
    E resultValue;
    if (futureValue == nullptr) {
        if (!<E>typeAcceptsNull()) {
            ;
        }
        resultValue = (;
    } else {
        resultValue = futureValue;
    }
    _Future<E> result = <E>_Future();
    _onDone = ;
    return result;
}

_DoneStreamSubscription::_DoneStreamSubscription(FunctionType _onDone) {
    {
        _zone = Zone.current;
    }
    {
        _schedule();
    }
}

bool _DoneStreamSubscription::_isSent() {
    return (_state & _DONE_SENT) != 0;
}

bool _DoneStreamSubscription::_isScheduled() {
    return (_state & _SCHEDULED) != 0;
}

void _DoneStreamSubscription::_schedule() {
    if (_isScheduled)     {
        return;
    }
    _zone.scheduleMicrotask(_sendDone);
    _state = _SCHEDULED;
}

void _DoneStreamSubscription::_sendDone() {
    _state = ~_SCHEDULED;
    if (isPaused)     {
        return;
    }
    _state = _DONE_SENT;
    auto doneHandler = _onDone;
    if (doneHandler != nullptr)     {
        _zone.runGuarded(doneHandler);
    }
}

bool _AsBroadcastStream::isBroadcast() {
    return true;
}

StreamSubscription<T> _AsBroadcastStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    auto controller = _controller;
    if (controller == nullptr || controller.isClosed) {
        return <T>_DoneStreamSubscription(onDone);
    }
    _subscription = _source.listen(controller.addcontroller.addError, controller.close);
    return controller._subscribe(onData, onError, onDone, cancelOnError ?? false);
}

_AsBroadcastStream::_AsBroadcastStream(Stream<T> _source, FunctionType onCancelHandler, FunctionType onListenHandler) {
    {
        _onListenHandler = onListenHandler == nullptr? nullptr : Zone.current.<void, StreamSubscription<T>>registerUnaryCallback(onListenHandler);
        _onCancelHandler = onCancelHandler == nullptr? nullptr : Zone.current.<void, StreamSubscription<T>>registerUnaryCallback(onCancelHandler);
        _zone = Zone.current;
    }
    {
        _controller = <T>_AsBroadcastStreamController(_onListen, _onCancel);
    }
}

void _AsBroadcastStream::_onCancel() {
    auto controller = _controller;
    bool shutdown = (controller == nullptr) || controller.isClosed;
    auto cancelHandler = _onCancelHandler;
    if (cancelHandler != nullptr) {
        _zone.runUnary(cancelHandler, <T>_BroadcastSubscriptionWrapper(this));
    }
    if (shutdown) {
        auto subscription = _subscription;
        if (subscription != nullptr) {
            subscription.cancel();
            _subscription = nullptr;
        }
    }
}

void _AsBroadcastStream::_onListen() {
    auto listenHandler = _onListenHandler;
    if (listenHandler != nullptr) {
        _zone.runUnary(listenHandler, <T>_BroadcastSubscriptionWrapper(this));
    }
}

void _AsBroadcastStream::_cancelSubscription() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        _subscription = nullptr;
        _controller = nullptr;
        subscription.cancel();
    }
}

void _AsBroadcastStream::_pauseSubscription(Future<void> resumeSignal) {
    _subscription?.pause(resumeSignal);
}

void _AsBroadcastStream::_resumeSubscription() {
    _subscription?.resume();
}

bool _AsBroadcastStream::_isSubscriptionPaused() {
    return _subscription?.isPaused ?? false;
}

void _BroadcastSubscriptionWrapper::onData(FunctionType handleData) {
    ;
}

void _BroadcastSubscriptionWrapper::onError(FunctionType handleError) {
    ;
}

void _BroadcastSubscriptionWrapper::onDone(FunctionType handleDone) {
    ;
}

void _BroadcastSubscriptionWrapper::pause(Future<void> resumeSignal) {
    _stream._pauseSubscription(resumeSignal);
}

void _BroadcastSubscriptionWrapper::resume() {
    _stream._resumeSubscription();
}

Future _BroadcastSubscriptionWrapper::cancel() {
    _stream._cancelSubscription();
    return Future._nullFuture;
}

bool _BroadcastSubscriptionWrapper::isPaused() {
    return _stream._isSubscriptionPaused;
}

Future<E> _BroadcastSubscriptionWrapper::asFuture<E>(E futureValue) {
    ;
}

T _StreamIterator::current() {
    if (_hasValue)     {
        return (;
    }
    return (;
}

Future<bool> _StreamIterator::moveNext() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        if (_hasValue) {
            auto future = <bool>_Future();
            _stateData = future;
            _hasValue = false;
            subscription.resume();
            return future;
        }
        ;
    }
    return _initializeOrDone();
}

Future _StreamIterator::cancel() {
    auto subscription = _subscription;
    auto stateData = _stateData;
    _stateData = nullptr;
    if (subscription != nullptr) {
        _subscription = nullptr;
        if (!_hasValue) {
            _Future<bool> future = (;
            future._asyncComplete(false);
        } else {
            _hasValue = false;
        }
        return subscription.cancel();
    }
    return Future._nullFuture;
}

_StreamIterator::_StreamIterator(Stream<T> stream) {
    {
        _stateData = checkNotNullable(stream, "stream");
    }
}

Future<bool> _StreamIterator::_initializeOrDone() {
    assert(_subscription == nullptr);
    auto stateData = _stateData;
    if (stateData != nullptr) {
        Stream<T> stream = (;
        auto future = <bool>_Future();
        _stateData = future;
        auto subscription = stream.listen(_onData_onError, _onDone, true);
        if (_stateData != nullptr) {
            _subscription = subscription;
        }
        return future;
    }
    return Future._falseFuture;
}

void _StreamIterator::_onData(T data) {
    if (_subscription == nullptr)     {
        return;
    }
    _Future<bool> moveNextFuture = (;
    _stateData = data;
    _hasValue = true;
    moveNextFuture._complete(true);
    if (_hasValue)     {
        _subscription?.pause();
    }
}

void _StreamIterator::_onError(Object error, StackTrace stackTrace) {
    auto subscription = _subscription;
    _Future<bool> moveNextFuture = (;
    _subscription = nullptr;
    _stateData = nullptr;
    if (subscription != nullptr) {
        moveNextFuture._completeError(error, stackTrace);
    } else {
        moveNextFuture._asyncCompleteError(error, stackTrace);
    }
}

void _StreamIterator::_onDone() {
    auto subscription = _subscription;
    _Future<bool> moveNextFuture = (;
    _subscription = nullptr;
    _stateData = nullptr;
    if (subscription != nullptr) {
        moveNextFuture._completeWithValue(false);
    } else {
        moveNextFuture._asyncCompleteWithValue(false);
    }
}

bool _EmptyStream::isBroadcast() {
    return true;
}

StreamSubscription<T> _EmptyStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return <T>_DoneStreamSubscription(onDone);
}

_EmptyStream::_EmptyStream() {
    {
        super._internal();
    }
}

StreamSubscription<T> _MultiStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    auto controller = <T>_MultiStreamController();
    controller.onListen = ;
    return controller._subscribe(onData, onError, onDone, cancelOnError ?? false);
}

void _MultiStreamController::addSync(T data) {
    if (!_mayAddEvent)     {
        ;
    }
    if (hasListener)     {
        _subscription._add(data);
    }
}

void _MultiStreamController::addErrorSync(Object error, StackTrace stackTrace) {
    if (!_mayAddEvent)     {
        ;
    }
    if (hasListener) {
        _subscription._addError(error, stackTrace ?? StackTrace.empty);
    }
}

void _MultiStreamController::closeSync() {
    if (isClosed)     {
        return;
    }
    if (!_mayAddEvent)     {
        ;
    }
    _state = _StreamController._STATE_CLOSED;
    if (hasListener)     {
        _subscription._close();
    }
}

Stream<T> _MultiStreamController::stream() {
    ;
}

_MultiStreamController::_MultiStreamController() {
    {
        super(nullptr, nullptr, nullptr, nullptr);
    }
}
