#include "stream_impl.hpp"
template<typename T>
void _BufferingStreamSubscriptionCls<T>::zoned(Zone _zone, std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError)

template<typename T>
void _BufferingStreamSubscriptionCls<T>::onData(std::function<void(T event)> handleData) {
    _onData = <T>_registerDataHandler(_zone, handleData);
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::onError(std::function<void ()> handleError) {
    _onError = _registerErrorHandler(_zone, handleError);
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::onDone(std::function<void()> handleDone) {
    _onDone = _registerDoneHandler(_zone, handleDone);
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::pause(Future<void> resumeSignal) {
    if (_isCanceled()) {
        return;
    }
    bool wasPaused = _isPaused();
    bool wasInputPaused = _isInputPaused();
    _state = (_state + _STATE_PAUSE_COUNT) | _STATE_INPUT_PAUSED;
    resumeSignal?->whenComplete(resume);
    if (!wasPaused) {
        _pending?->cancelSchedule();
    }
    if (!wasInputPaused && !_inCallback()) {
        _guardCallback(_onPause);
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::resume() {
    if (_isCanceled()) {
        return;
    }
    if (_isPaused()) {
        _decrementPauseCount();
        if (!_isPaused()) {
            if (_hasPending() && !_pending!->isEmpty()) {
                _pending!->schedule(this);
            } else {
                assert(_mayResumeInput());
                _state &= ~_STATE_INPUT_PAUSED;
                if (!_inCallback()) {
                    _guardCallback(_onResume);
                }
            }
        }
    }
}

template<typename T>
Future _BufferingStreamSubscriptionCls<T>::cancel() {
    _state &= ~_STATE_WAIT_FOR_CANCEL;
    if (!_isCanceled()) {
        _cancel();
    }
    return _cancelFuture | FutureCls::_nullFuture;
}

template<typename T>
template<typename E>
Future<E> _BufferingStreamSubscriptionCls<T>::asFuture(E futureValue) {
    E resultValue;
    if (futureValue == nullptr) {
        if (!<E>typeAcceptsNull()) {
            throw ArgumentErrorCls->notNull(__s("futureValue"));
        }
        resultValue = as<dynamic>(futureValue);
    } else {
        resultValue = futureValue;
    }
    _Future<E> result = <E>make<_FutureCls>();
    _onDone = [=] () {
        result->_complete(resultValue);
    };
    _onError = [=] (Object error,StackTrace stackTrace) {
        Future cancelFuture = cancel();
        if (!identical(cancelFuture, FutureCls::_nullFuture)) {
            cancelFuture->whenComplete([=] () {
                result->_completeError(error, stackTrace);
            });
        } else {
            result->_completeError(error, stackTrace);
        }
    };
    return result;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::isPaused() {
    return _isPaused();
}

template<typename T>
_BufferingStreamSubscriptionCls<T>::_BufferingStreamSubscriptionCls(std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError) {
    {
        this->zoned(ZoneCls::current, onData, onError, onDone, cancelOnError);
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_setPendingEvents(_PendingEvents<T> pendingEvents) {
    assert(_pending == nullptr);
    if (pendingEvents == nullptr) {
        return;
    }
    _pending = pendingEvents;
    if (!pendingEvents->isEmpty()) {
        _state |= _STATE_HAS_PENDING;
        pendingEvents->schedule(this);
    }
}

template<typename T>
template<typename T>
std::function<void(T )> _BufferingStreamSubscriptionCls<T>::_registerDataHandler(Zone zone, std::function<void(T )> handleData) {
    return zone-><void, T>registerUnaryCallback(handleData | _nullDataHandler);
}

template<typename T>
std::function<void ()> _BufferingStreamSubscriptionCls<T>::_registerErrorHandler(Zone zone, std::function<void ()> handleError) {
    handleError |= _nullErrorHandler;
    if (is<std::function<void(Object , StackTrace )>>(handleError)) {
        return zone-><dynamic, Object, StackTrace>registerBinaryCallback(handleError);
    }
    if (is<std::function<void(Object )>>(handleError)) {
        return zone-><dynamic, Object>registerUnaryCallback(handleError);
    }
    throw make<ArgumentErrorCls>(__s("handleError callback must take either an Object (the error), or both an Object (the error) and a StackTrace."));
}

template<typename T>
std::function<void()> _BufferingStreamSubscriptionCls<T>::_registerDoneHandler(Zone zone, std::function<void()> handleDone) {
    return zone->registerCallback(handleDone | _nullDoneHandler);
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_isInputPaused() {
    return (_state & _STATE_INPUT_PAUSED) != 0;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_isClosed() {
    return (_state & _STATE_CLOSED) != 0;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_isCanceled() {
    return (_state & _STATE_CANCELED) != 0;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_waitsForCancel() {
    return (_state & _STATE_WAIT_FOR_CANCEL) != 0;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_inCallback() {
    return (_state & _STATE_IN_CALLBACK) != 0;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_hasPending() {
    return (_state & _STATE_HAS_PENDING) != 0;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_isPaused() {
    return _state >= _STATE_PAUSE_COUNT;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_canFire() {
    return  < _STATE_IN_CALLBACK;
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_mayResumeInput() {
    return !_isPaused() && (_pending?->isEmpty() | true);
}

template<typename T>
bool _BufferingStreamSubscriptionCls<T>::_cancelOnError() {
    return (_state & _STATE_CANCEL_ON_ERROR) != 0;
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_cancel() {
    _state |= _STATE_CANCELED;
    if (_hasPending()) {
        _pending!->cancelSchedule();
    }
    if (!_inCallback()) {
        _pending = nullptr;
    }
    _cancelFuture = _onCancel();
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_decrementPauseCount() {
    assert(_isPaused());
    _state -= _STATE_PAUSE_COUNT;
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_add(T data) {
    assert(!_isClosed());
    if (_isCanceled()) {
        return;
    }
    if (_canFire()) {
        _sendData(data);
    } else {
        _addPending(<T>make<_DelayedDataCls>(data));
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_addError(Object error, StackTrace stackTrace) {
    if (_isCanceled()) {
        return;
    }
    if (_canFire()) {
        _sendError(error, stackTrace);
    } else {
        _addPending(make<_DelayedErrorCls>(error, stackTrace));
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_close() {
    assert(!_isClosed());
    if (_isCanceled()) {
        return;
    }
    _state |= _STATE_CLOSED;
    if (_canFire()) {
        _sendDone();
    } else {
        _addPending(make<_DelayedDoneCls>());
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_onPause() {
    assert(_isInputPaused());
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_onResume() {
    assert(!_isInputPaused());
}

template<typename T>
Future<void> _BufferingStreamSubscriptionCls<T>::_onCancel() {
    assert(_isCanceled());
    return nullptr;
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_addPending(_DelayedEvent event) {
    auto pending = _pending ??= <T>make<_PendingEventsCls>();
    pending->add(event);
    if (!_hasPending()) {
        _state |= _STATE_HAS_PENDING;
        if (!_isPaused()) {
            pending->schedule(this);
        }
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_sendData(T data) {
    assert(!_isCanceled());
    assert(!_isPaused());
    assert(!_inCallback());
    bool wasInputPaused = _isInputPaused();
    _state |= _STATE_IN_CALLBACK;
    _zone->runUnaryGuarded(_onData, data);
    _state &= ~_STATE_IN_CALLBACK;
    _checkState(wasInputPaused);
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_sendError(Object error, StackTrace stackTrace) {
    assert(!_isCanceled());
    assert(!_isPaused());
    assert(!_inCallback());
    bool wasInputPaused = _isInputPaused();
    InlineMethod;
    if (_cancelOnError()) {
        _state |= _STATE_WAIT_FOR_CANCEL;
        _cancel();
        auto cancelFuture = _cancelFuture;
        if (cancelFuture != nullptr && !identical(cancelFuture, FutureCls::_nullFuture)) {
            cancelFuture->whenComplete(sendError);
        } else {
            sendError();
        }
    } else {
        sendError();
        _checkState(wasInputPaused);
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_sendDone() {
    assert(!_isCanceled());
    assert(!_isPaused());
    assert(!_inCallback());
    InlineMethod;
    _cancel();
    _state |= _STATE_WAIT_FOR_CANCEL;
    auto cancelFuture = _cancelFuture;
    if (cancelFuture != nullptr && !identical(cancelFuture, FutureCls::_nullFuture)) {
        cancelFuture->whenComplete(sendDone);
    } else {
        sendDone();
    }
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_guardCallback(std::function<void()> callback) {
    assert(!_inCallback());
    bool wasInputPaused = _isInputPaused();
    _state |= _STATE_IN_CALLBACK;
    callback();
    _state &= ~_STATE_IN_CALLBACK;
    _checkState(wasInputPaused);
}

template<typename T>
void _BufferingStreamSubscriptionCls<T>::_checkState(bool wasInputPaused) {
    assert(!_inCallback());
    if (_hasPending() && _pending!->isEmpty()) {
        _state &= ~_STATE_HAS_PENDING;
        if (_isInputPaused() && _mayResumeInput()) {
            _state &= ~_STATE_INPUT_PAUSED;
        }
    }
    while (true) {
        if (_isCanceled()) {
            _pending = nullptr;
            return;
        }
        bool isInputPaused = _isInputPaused();
        if (wasInputPaused == isInputPaused) {
            break;
        }
        _state ^= _STATE_IN_CALLBACK;
        if (isInputPaused) {
            _onPause();
        } else {
            _onResume();
        }
        _state &= ~_STATE_IN_CALLBACK;
        wasInputPaused = isInputPaused;
    }
    if (_hasPending() && !_isPaused()) {
        _pending!->schedule(this);
    }
}

template<typename T>
StreamSubscription<T> _StreamImplCls<T>::listen(std::function<void(T data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    cancelOnError |= false;
    StreamSubscription<T> subscription = _createSubscription(onData, onError, onDone, cancelOnError);
    _onListen(subscription);
    return subscription;
}

template<typename T>
StreamSubscription<T> _StreamImplCls<T>::_createSubscription(std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError) {
    return <T>make<_BufferingStreamSubscriptionCls>(onData, onError, onDone, cancelOnError);
}

template<typename T>
void _StreamImplCls<T>::_onListen(StreamSubscription subscription) {
}

void _nullDataHandler(dynamic value) {
}

void _nullErrorHandler(Object error, StackTrace stackTrace) {
    ZoneCls::current->handleUncaughtError(error, stackTrace);
}

void _nullDoneHandler() {
}

template<typename T>
void _DelayedDataCls<T>::perform(_EventDispatch<T> dispatch) {
    dispatch->_sendData(value);
}

void _DelayedErrorCls::perform(_EventDispatch dispatch) {
    dispatch->_sendError(error, stackTrace);
}

void _DelayedDoneCls::perform(_EventDispatch dispatch) {
    dispatch->_sendDone();
}

_DelayedEvent _DelayedDoneCls::next() {
    return nullptr;
}

void _DelayedDoneCls::next(_DelayedEvent _) {
    throw make<StateErrorCls>(__s("No events after a done."));
}

template<typename T>
bool _PendingEventsCls<T>::isScheduled() {
    return _state == stateScheduled;
}

template<typename T>
void _PendingEventsCls<T>::schedule(_EventDispatch<T> dispatch) {
    if (isScheduled()) {
        return;
    }
    assert(!isEmpty());
    if (_eventScheduled()) {
        assert(_state == stateCanceled);
        _state = stateScheduled;
        return;
    }
    scheduleMicrotask([=] () {
        int oldState = _state;
        _state = stateUnscheduled;
        if (oldState == stateCanceled) {
            return;
        }
        handleNext(dispatch);
    });
    _state = stateScheduled;
}

template<typename T>
void _PendingEventsCls<T>::cancelSchedule() {
    if (isScheduled()) {
        _state = stateCanceled;
    }
}

template<typename T>
bool _PendingEventsCls<T>::isEmpty() {
    return lastPendingEvent == nullptr;
}

template<typename T>
void _PendingEventsCls<T>::add(_DelayedEvent event) {
    auto lastEvent = lastPendingEvent;
    if (lastEvent == nullptr) {
        firstPendingEvent = lastPendingEvent = event;
    } else {
        lastPendingEvent = lastEvent->next = event;
    }
}

template<typename T>
void _PendingEventsCls<T>::handleNext(_EventDispatch<T> dispatch) {
    assert(!isScheduled());
    assert(!isEmpty());
    _DelayedEvent event = firstPendingEvent!;
    _DelayedEvent nextEvent = event->next;
    firstPendingEvent = nextEvent;
    if (nextEvent == nullptr) {
        lastPendingEvent = nullptr;
    }
    event->perform(dispatch);
}

template<typename T>
void _PendingEventsCls<T>::clear() {
    if (isScheduled()) {
        cancelSchedule();
    }
    firstPendingEvent = lastPendingEvent = nullptr;
}

template<typename T>
bool _PendingEventsCls<T>::_eventScheduled() {
    return _state >= stateScheduled;
}

template<typename T>
bool _DoneStreamSubscriptionCls<T>::isPaused() {
    return _state >= _PAUSED;
}

template<typename T>
void _DoneStreamSubscriptionCls<T>::onData(std::function<void(T data)> handleData) {
}

template<typename T>
void _DoneStreamSubscriptionCls<T>::onError(std::function<void ()> handleError) {
}

template<typename T>
void _DoneStreamSubscriptionCls<T>::onDone(std::function<void()> handleDone) {
    _onDone = handleDone;
}

template<typename T>
void _DoneStreamSubscriptionCls<T>::pause(Future<void> resumeSignal) {
    _state += _PAUSED;
    if (resumeSignal != nullptr) {
        resumeSignal->whenComplete(resume);
    }
}

template<typename T>
void _DoneStreamSubscriptionCls<T>::resume() {
    if (isPaused()) {
        _state -= _PAUSED;
        if (!isPaused() && !_isSent()) {
            _schedule();
        }
    }
}

template<typename T>
Future _DoneStreamSubscriptionCls<T>::cancel() {
    return FutureCls::_nullFuture;
}

template<typename T>
template<typename E>
Future<E> _DoneStreamSubscriptionCls<T>::asFuture(E futureValue) {
    E resultValue;
    if (futureValue == nullptr) {
        if (!<E>typeAcceptsNull()) {
            throw ArgumentErrorCls->notNull(__s("futureValue"));
        }
        resultValue = as<dynamic>(futureValue);
    } else {
        resultValue = futureValue;
    }
    _Future<E> result = <E>make<_FutureCls>();
    _onDone = [=] () {
        result->_completeWithValue(resultValue);
    };
    return result;
}

template<typename T>
_DoneStreamSubscriptionCls<T>::_DoneStreamSubscriptionCls(std::function<void()> _onDone) {
    {
        _zone = ZoneCls::current;
    }
    {
        _schedule();
    }
}

template<typename T>
bool _DoneStreamSubscriptionCls<T>::_isSent() {
    return (_state & _DONE_SENT) != 0;
}

template<typename T>
bool _DoneStreamSubscriptionCls<T>::_isScheduled() {
    return (_state & _SCHEDULED) != 0;
}

template<typename T>
void _DoneStreamSubscriptionCls<T>::_schedule() {
    if (_isScheduled()) {
        return;
    }
    _zone->scheduleMicrotask(_sendDone);
    _state |= _SCHEDULED;
}

template<typename T>
void _DoneStreamSubscriptionCls<T>::_sendDone() {
    _state &= ~_SCHEDULED;
    if (isPaused()) {
        return;
    }
    _state |= _DONE_SENT;
    auto doneHandler = _onDone;
    if (doneHandler != nullptr) {
        _zone->runGuarded(doneHandler);
    }
}

template<typename T>
bool _AsBroadcastStreamCls<T>::isBroadcast() {
    return true;
}

template<typename T>
StreamSubscription<T> _AsBroadcastStreamCls<T>::listen(std::function<void(T data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    auto controller = _controller;
    if (controller == nullptr || controller->isClosed()) {
        return <T>make<_DoneStreamSubscriptionCls>(onDone);
    }
    _subscription |= _source->listen(controller->add, controller->addError, controller->close);
    return controller->_subscribe(onData, onError, onDone, cancelOnError | false);
}

template<typename T>
_AsBroadcastStreamCls<T>::_AsBroadcastStreamCls(Stream<T> _source, std::function<void(StreamSubscription<T> subscription)> onListenHandler, std::function<void(StreamSubscription<T> subscription)> onCancelHandler) {
    {
        _onListenHandler = onListenHandler == nullptr? nullptr : ZoneCls::current-><void, StreamSubscription<T>>registerUnaryCallback(onListenHandler);
        _onCancelHandler = onCancelHandler == nullptr? nullptr : ZoneCls::current-><void, StreamSubscription<T>>registerUnaryCallback(onCancelHandler);
        _zone = ZoneCls::current;
    }
    {
        _controller = <T>make<_AsBroadcastStreamControllerCls>(_onListen, _onCancel);
    }
}

template<typename T>
void _AsBroadcastStreamCls<T>::_onCancel() {
    auto controller = _controller;
    bool shutdown = (controller == nullptr) || controller->isClosed();
    auto cancelHandler = _onCancelHandler;
    if (cancelHandler != nullptr) {
        _zone->runUnary(cancelHandler, <T>make<_BroadcastSubscriptionWrapperCls>(this));
    }
    if (shutdown) {
        auto subscription = _subscription;
        if (subscription != nullptr) {
            subscription->cancel();
            _subscription = nullptr;
        }
    }
}

template<typename T>
void _AsBroadcastStreamCls<T>::_onListen() {
    auto listenHandler = _onListenHandler;
    if (listenHandler != nullptr) {
        _zone->runUnary(listenHandler, <T>make<_BroadcastSubscriptionWrapperCls>(this));
    }
}

template<typename T>
void _AsBroadcastStreamCls<T>::_cancelSubscription() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        _subscription = nullptr;
        _controller = nullptr;
        subscription->cancel();
    }
}

template<typename T>
void _AsBroadcastStreamCls<T>::_pauseSubscription(Future<void> resumeSignal) {
    _subscription?->pause(resumeSignal);
}

template<typename T>
void _AsBroadcastStreamCls<T>::_resumeSubscription() {
    _subscription?->resume();
}

template<typename T>
bool _AsBroadcastStreamCls<T>::_isSubscriptionPaused() {
    return _subscription?->isPaused() | false;
}

template<typename T>
void _BroadcastSubscriptionWrapperCls<T>::onData(std::function<void(T data)> handleData) {
    throw make<UnsupportedErrorCls>(__s("Cannot change handlers of asBroadcastStream source subscription."));
}

template<typename T>
void _BroadcastSubscriptionWrapperCls<T>::onError(std::function<void ()> handleError) {
    throw make<UnsupportedErrorCls>(__s("Cannot change handlers of asBroadcastStream source subscription."));
}

template<typename T>
void _BroadcastSubscriptionWrapperCls<T>::onDone(std::function<void()> handleDone) {
    throw make<UnsupportedErrorCls>(__s("Cannot change handlers of asBroadcastStream source subscription."));
}

template<typename T>
void _BroadcastSubscriptionWrapperCls<T>::pause(Future<void> resumeSignal) {
    _stream->_pauseSubscription(resumeSignal);
}

template<typename T>
void _BroadcastSubscriptionWrapperCls<T>::resume() {
    _stream->_resumeSubscription();
}

template<typename T>
Future _BroadcastSubscriptionWrapperCls<T>::cancel() {
    _stream->_cancelSubscription();
    return FutureCls::_nullFuture;
}

template<typename T>
bool _BroadcastSubscriptionWrapperCls<T>::isPaused() {
    return _stream->_isSubscriptionPaused();
}

template<typename T>
template<typename E>
Future<E> _BroadcastSubscriptionWrapperCls<T>::asFuture(E futureValue) {
    throw make<UnsupportedErrorCls>(__s("Cannot change handlers of asBroadcastStream source subscription."));
}

template<typename T>
T _StreamIteratorCls<T>::current() {
    if (_hasValue) {
        return as<dynamic>(_stateData);
    }
    return as<dynamic>(nullptr);
}

template<typename T>
Future<bool> _StreamIteratorCls<T>::moveNext() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        if (_hasValue) {
            auto future = <bool>make<_FutureCls>();
            _stateData = future;
            _hasValue = false;
            subscription->resume();
            return future;
        }
        throw make<StateErrorCls>(__s("Already waiting for next."));
    }
    return _initializeOrDone();
}

template<typename T>
Future _StreamIteratorCls<T>::cancel() {
    auto subscription = _subscription;
    auto stateData = _stateData;
    _stateData = nullptr;
    if (subscription != nullptr) {
        _subscription = nullptr;
        if (!_hasValue) {
            _Future<bool> future = as<dynamic>(stateData);
            future->_asyncComplete(false);
        } else {
            _hasValue = false;
        }
        return subscription->cancel();
    }
    return FutureCls::_nullFuture;
}

template<typename T>
_StreamIteratorCls<T>::_StreamIteratorCls(Stream<T> stream) {
    {
        _stateData = checkNotNullable(stream, __s("stream"));
    }
}

template<typename T>
Future<bool> _StreamIteratorCls<T>::_initializeOrDone() {
    assert(_subscription == nullptr);
    auto stateData = _stateData;
    if (stateData != nullptr) {
        Stream<T> stream = as<dynamic>(stateData);
        auto future = <bool>make<_FutureCls>();
        _stateData = future;
        auto subscription = stream->listen(_onData, _onError, _onDone, true);
        if (_stateData != nullptr) {
            _subscription = subscription;
        }
        return future;
    }
    return FutureCls::_falseFuture;
}

template<typename T>
void _StreamIteratorCls<T>::_onData(T data) {
    if (_subscription == nullptr) {
        return;
    }
    _Future<bool> moveNextFuture = as<dynamic>(_stateData);
    _stateData = data;
    _hasValue = true;
    moveNextFuture->_complete(true);
    if (_hasValue) {
        _subscription?->pause();
    }
}

template<typename T>
void _StreamIteratorCls<T>::_onError(Object error, StackTrace stackTrace) {
    auto subscription = _subscription;
    _Future<bool> moveNextFuture = as<dynamic>(_stateData);
    _subscription = nullptr;
    _stateData = nullptr;
    if (subscription != nullptr) {
        moveNextFuture->_completeError(error, stackTrace);
    } else {
        moveNextFuture->_asyncCompleteError(error, stackTrace);
    }
}

template<typename T>
void _StreamIteratorCls<T>::_onDone() {
    auto subscription = _subscription;
    _Future<bool> moveNextFuture = as<dynamic>(_stateData);
    _subscription = nullptr;
    _stateData = nullptr;
    if (subscription != nullptr) {
        moveNextFuture->_completeWithValue(false);
    } else {
        moveNextFuture->_asyncCompleteWithValue(false);
    }
}

template<typename T>
bool _EmptyStreamCls<T>::isBroadcast() {
    return true;
}

template<typename T>
StreamSubscription<T> _EmptyStreamCls<T>::listen(std::function<void(T data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    return <T>make<_DoneStreamSubscriptionCls>(onDone);
}

template<typename T>
_EmptyStreamCls<T>::_EmptyStreamCls() {
    {
        super->_internal();
    }
}

template<typename T>
StreamSubscription<T> _MultiStreamCls<T>::listen(std::function<void(T event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    auto controller = <T>make<_MultiStreamControllerCls>();
    controller->onListen = [=] () {
        _onListen(controller);
    };
    return controller->_subscribe(onData, onError, onDone, cancelOnError | false);
}

template<typename T>
void _MultiStreamControllerCls<T>::addSync(T data) {
    if (!_mayAddEvent()) {
        throw _badEventState();
    }
    if (hasListener()) {
        _subscription()->_add(data);
    }
}

template<typename T>
void _MultiStreamControllerCls<T>::addErrorSync(Object error, StackTrace stackTrace) {
    if (!_mayAddEvent()) {
        throw _badEventState();
    }
    if (hasListener()) {
        _subscription()->_addError(error, stackTrace | StackTraceCls::empty);
    }
}

template<typename T>
void _MultiStreamControllerCls<T>::closeSync() {
    if (isClosed()) {
        return;
    }
    if (!_mayAddEvent()) {
        throw _badEventState();
    }
    _state |= _StreamControllerCls::_STATE_CLOSED;
    if (hasListener()) {
        _subscription()->_close();
    }
}

template<typename T>
Stream<T> _MultiStreamControllerCls<T>::stream() {
    throw make<UnsupportedErrorCls>(__s("Not available"));
}

template<typename T>
_MultiStreamControllerCls<T>::_MultiStreamControllerCls() : _AsyncStreamController<T>(nullptr, nullptr, nullptr, nullptr) {
}
