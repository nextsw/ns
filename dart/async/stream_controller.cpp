#include "stream_controller.hpp"
StreamController::StreamController(FunctionType onCancel, FunctionType onListen, FunctionType onPause, FunctionType onResume, bool sync) {
    {
        return sync? <T>_SyncStreamController(onListen, onPause, onResume, onCancel) : <T>_AsyncStreamController(onListen, onPause, onResume, onCancel);
    }
}

void StreamController::broadcast(FunctionType onCancel, FunctionType onListen, bool sync) {
    return sync? <T>_SyncBroadcastStreamController(onListen, onCancel) : <T>_AsyncBroadcastStreamController(onListen, onCancel);
}

void _StreamControllerLifecycle::_recordPause(StreamSubscription<T> subscription) {
}

void _StreamControllerLifecycle::_recordResume(StreamSubscription<T> subscription) {
}

Future<void> _StreamControllerLifecycle::_recordCancel(StreamSubscription<T> subscription) {
    return nullptr;
}

Stream<T> _StreamController::stream() {
    return <T>_ControllerStream(this);
}

StreamSink<T> _StreamController::sink() {
    return <T>_StreamSinkWrapper(this);
}

bool _StreamController::hasListener() {
    return (_state & _STATE_SUBSCRIBED) != 0;
}

bool _StreamController::isClosed() {
    return (_state & _STATE_CLOSED) != 0;
}

bool _StreamController::isPaused() {
    return hasListener? _subscription._isInputPaused : !_isCanceled;
}

Future _StreamController::addStream(bool cancelOnError, Stream<T> source) {
    if (!_mayAddEvent)     {
        ;
    }
    if (_isCanceled)     {
        return _Future.immediate(nullptr);
    }
    _StreamControllerAddStreamState<T> addState = <T>_StreamControllerAddStreamState(this, _varData, source, cancelOnError ?? false);
    _varData = addState;
    _state = _STATE_ADDSTREAM;
    return addState.addStreamFuture;
}

Future<void> _StreamController::done() {
    return _ensureDoneFuture();
}

void _StreamController::add(T value) {
    if (!_mayAddEvent)     {
        ;
    }
    _add(value);
}

void _StreamController::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    if (!_mayAddEvent)     {
        ;
    }
    AsyncError replacement = Zone.current.errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement.error;
        stackTrace = replacement.stackTrace;
    } else {
        stackTrace = AsyncError.defaultStackTrace(error);
    }
    _addError(error, stackTrace);
}

Future _StreamController::close() {
    if (isClosed) {
        return _ensureDoneFuture();
    }
    if (!_mayAddEvent)     {
        ;
    }
    _closeUnchecked();
    return _ensureDoneFuture();
}

bool _StreamController::_isCanceled() {
    return (_state & _STATE_CANCELED) != 0;
}

bool _StreamController::_isInitialState() {
    return (_state & _STATE_SUBSCRIPTION_MASK) == _STATE_INITIAL;
}

bool _StreamController::_isAddingStream() {
    return (_state & _STATE_ADDSTREAM) != 0;
}

bool _StreamController::_mayAddEvent() {
    return ( < _STATE_CLOSED);
}

_PendingEvents<T> _StreamController::_pendingEvents() {
    assert(_isInitialState);
    if (!_isAddingStream) {
        return (;
    }
    _StreamControllerAddStreamState<T> state = (;
    return state.varData;
}

_PendingEvents<T> _StreamController::_ensurePendingEvents() {
    assert(_isInitialState);
    if (!_isAddingStream) {
        Object events = _varData;
        if (events == nullptr) {
            _varData = events = <T>_PendingEvents();
        }
        return (;
    }
    _StreamControllerAddStreamState<T> state = (;
    Object events = state.varData;
    if (events == nullptr) {
        state.varData = events = <T>_PendingEvents();
    }
    return (;
}

_ControllerSubscription<T> _StreamController::_subscription() {
    assert(hasListener);
    Object varData = _varData;
    if (_isAddingStream) {
        _StreamControllerAddStreamState<Object> streamState = (;
        varData = streamState.varData;
    }
    return (;
}

Error _StreamController::_badEventState() {
    if (isClosed) {
        return StateError("Cannot add event after closing");
    }
    assert(_isAddingStream);
    return StateError("Cannot add event while adding a stream");
}

Future<void> _StreamController::_ensureDoneFuture() {
    return _doneFuture ??= _isCanceled? Future._nullFuture : <void>_Future();
}

void _StreamController::_closeUnchecked() {
    _state = _STATE_CLOSED;
    if (hasListener) {
        _sendDone();
    } else     {
        if (_isInitialState) {
        _ensurePendingEvents().add(const _DelayedDone());
    }
;
    }}

void _StreamController::_add(T value) {
    if (hasListener) {
        _sendData(value);
    } else     {
        if (_isInitialState) {
        _ensurePendingEvents().add(<T>_DelayedData(value));
    }
;
    }}

void _StreamController::_addError(Object error, StackTrace stackTrace) {
    if (hasListener) {
        _sendError(error, stackTrace);
    } else     {
        if (_isInitialState) {
        _ensurePendingEvents().add(_DelayedError(error, stackTrace));
    }
;
    }}

void _StreamController::_close() {
    assert(_isAddingStream);
    _StreamControllerAddStreamState<T> addState = (;
    _varData = addState.varData;
    _state = ~_STATE_ADDSTREAM;
    addState.complete();
}

StreamSubscription<T> _StreamController::_subscribe(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    if (!_isInitialState) {
        ;
    }
    _ControllerSubscription<T> subscription = <T>_ControllerSubscription(this, onData, onError, onDone, cancelOnError);
    _PendingEvents<T> pendingEvents = _pendingEvents;
    _state = _STATE_SUBSCRIBED;
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = (;
        addState.varData = subscription;
        addState.resume();
    } else {
        _varData = subscription;
    }
    subscription._setPendingEvents(pendingEvents);
    subscription._guardCallback();
    return subscription;
}

Future<void> _StreamController::_recordCancel(StreamSubscription<T> subscription) {
    Future<void> result;
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = (;
        result = addState.cancel();
    }
    _varData = nullptr;
    _state = (_state & ~(_STATE_SUBSCRIBED | _STATE_ADDSTREAM)) | _STATE_CANCELED;
    auto onCancel = this.onCancel;
    if (onCancel != nullptr) {
        if (result == nullptr) {
            ;
        } else {
            result = result.whenComplete(onCancel);
        }
    }
    ;
    if (result != nullptr) {
        result = result.whenComplete(complete);
    } else {
        complete();
    }
    return result;
}

void _StreamController::_recordPause(StreamSubscription<T> subscription) {
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = (;
        addState.pause();
    }
    _runGuarded(onPause);
}

void _StreamController::_recordResume(StreamSubscription<T> subscription) {
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = (;
        addState.resume();
    }
    _runGuarded(onResume);
}

void _SyncStreamControllerDispatch::_sendData(T data) {
    _subscription._add(data);
}

void _SyncStreamControllerDispatch::_sendError(Object error, StackTrace stackTrace) {
    _subscription._addError(error, stackTrace);
}

void _SyncStreamControllerDispatch::_sendDone() {
    _subscription._close();
}

void _AsyncStreamControllerDispatch::_sendData(T data) {
    _subscription._addPending(<T>_DelayedData(data));
}

void _AsyncStreamControllerDispatch::_sendError(Object error, StackTrace stackTrace) {
    _subscription._addPending(_DelayedError(error, stackTrace));
}

void _AsyncStreamControllerDispatch::_sendDone() {
    _subscription._addPending(const _DelayedDone());
}

void _runGuarded(FunctionType notificationHandler) {
    if (notificationHandler == nullptr)     {
        return;
    }
    ;
}

int _ControllerStream::hashCode() {
    return _controller.hashCode ^ 0x35323532;
}

bool _ControllerStream::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return other is _ControllerStream && identical(other._controller, this._controller);
}

StreamSubscription<T> _ControllerStream::_createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return _controller._subscribe(onData, onError, onDone, cancelOnError);
}

_ControllerSubscription::_ControllerSubscription(_StreamControllerLifecycle<T> _controller, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    {
        super(onData, onError, onDone, cancelOnError);
    }
}

Future<void> _ControllerSubscription::_onCancel() {
    return _controller._recordCancel(this);
}

void _ControllerSubscription::_onPause() {
    _controller._recordPause(this);
}

void _ControllerSubscription::_onResume() {
    _controller._recordResume(this);
}

void _StreamSinkWrapper::add(T data) {
    _target.add(data);
}

void _StreamSinkWrapper::addError(Object error, StackTrace stackTrace) {
    _target.addError(error, stackTrace);
}

Future _StreamSinkWrapper::close() {
    return _target.close();
}

Future _StreamSinkWrapper::addStream(Stream<T> source) {
    return _target.addStream(source);
}

Future _StreamSinkWrapper::done() {
    return _target.done;
}

void _AddStreamState::makeErrorHandler(_EventSink controller) {
    return ;
}

void _AddStreamState::pause() {
    addSubscription.pause();
}

void _AddStreamState::resume() {
    addSubscription.resume();
}

Future<void> _AddStreamState::cancel() {
    auto cancel = addSubscription.cancel();
    if (cancel == nullptr) {
        addStreamFuture._asyncComplete(nullptr);
        return Future._nullFuture;
    }
    return cancel.whenComplete();
}

void _AddStreamState::complete() {
    addStreamFuture._asyncComplete(nullptr);
}

_AddStreamState::_AddStreamState(bool cancelOnError, _EventSink<T> controller, Stream<T> source) {
    {
        addStreamFuture = _Future();
        addSubscription = source.listen(controller._addcancelOnError? makeErrorHandler(controller) : controller._addError, controller._close, cancelOnError);
    }
}

_StreamControllerAddStreamState::_StreamControllerAddStreamState(bool cancelOnError, _StreamController<T> controller, Stream<T> source, auto varData) {
    {
        super(controller, source, cancelOnError);
    }
    {
        if (controller.isPaused) {
            addSubscription.pause();
        }
    }
}
