#include "broadcast_stream_controller.hpp"
bool _BroadcastStream::isBroadcast() {
    return true;
}

_BroadcastStream::_BroadcastStream(_StreamControllerLifecycle<T> controller) {
    {
        super(controller);
    }
}

_BroadcastSubscription::_BroadcastSubscription(bool cancelOnError, _StreamControllerLifecycle<T> controller, FunctionType onData, FunctionType onDone, FunctionType onError) {
    {
        super(controller, onData, onError, onDone, cancelOnError);
    }
    {
        _next = _previous = this;
    }
}

bool _BroadcastSubscription::_expectsEvent(int eventId) {
    return (_eventState & _STATE_EVENT_ID) == eventId;
}

void _BroadcastSubscription::_toggleEventId() {
    _eventState = _STATE_EVENT_ID;
}

bool _BroadcastSubscription::_isFiring() {
    return (_eventState & _STATE_FIRING) != 0;
}

void _BroadcastSubscription::_setRemoveAfterFiring() {
    assert(_isFiring);
    _eventState = _STATE_REMOVE_AFTER_FIRING;
}

bool _BroadcastSubscription::_removeAfterFiring() {
    return (_eventState & _STATE_REMOVE_AFTER_FIRING) != 0;
}

void _BroadcastSubscription::_onPause() {
}

void _BroadcastSubscription::_onResume() {
}

FunctionType _BroadcastStreamController::onPause() {
    ;
}

void _BroadcastStreamController::onPause(FunctionType onPauseHandler) {
    ;
}

FunctionType _BroadcastStreamController::onResume() {
    ;
}

void _BroadcastStreamController::onResume(FunctionType onResumeHandler) {
    ;
}

Stream<T> _BroadcastStreamController::stream() {
    return <T>_BroadcastStream(this);
}

StreamSink<T> _BroadcastStreamController::sink() {
    return <T>_StreamSinkWrapper(this);
}

bool _BroadcastStreamController::isClosed() {
    return (_state & _STATE_CLOSED) != 0;
}

bool _BroadcastStreamController::isPaused() {
    return false;
}

bool _BroadcastStreamController::hasListener() {
    return !_isEmpty;
}

void _BroadcastStreamController::add(T data) {
    if (!_mayAddEvent)     {
        ;
    }
    _sendData(data);
}

void _BroadcastStreamController::addError(Object error, StackTrace stackTrace) {
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
    _sendError(error, stackTrace);
}

Future _BroadcastStreamController::close() {
    if (isClosed) {
        assert(_doneFuture != nullptr);
        return _doneFuture!;
    }
    if (!_mayAddEvent)     {
        ;
    }
    _state = _STATE_CLOSED;
    Future doneFuture = _ensureDoneFuture();
    _sendDone();
    return doneFuture;
}

Future<void> _BroadcastStreamController::done() {
    return _ensureDoneFuture();
}

Future _BroadcastStreamController::addStream(bool cancelOnError, Stream<T> stream) {
    if (!_mayAddEvent)     {
        ;
    }
    _state = _STATE_ADDSTREAM;
    auto addStreamState = _AddStreamState(this, stream, cancelOnError ?? false);
    _addStreamState = addStreamState;
    return addStreamState.addStreamFuture;
}

_BroadcastStreamController::_BroadcastStreamController(FunctionType onCancel, FunctionType onListen) {
    {
        _state = _STATE_INITIAL;
    }
}

bool _BroadcastStreamController::_hasOneListener() {
    assert(!_isEmpty);
    return identical(_firstSubscription, _lastSubscription);
}

bool _BroadcastStreamController::_isFiring() {
    return (_state & _STATE_FIRING) != 0;
}

bool _BroadcastStreamController::_isAddingStream() {
    return (_state & _STATE_ADDSTREAM) != 0;
}

bool _BroadcastStreamController::_mayAddEvent() {
    return ( < _STATE_CLOSED);
}

_Future<void> _BroadcastStreamController::_ensureDoneFuture() {
    return _doneFuture ??= <void>_Future();
}

bool _BroadcastStreamController::_isEmpty() {
    return _firstSubscription == nullptr;
}

void _BroadcastStreamController::_addListener(_BroadcastSubscription<T> subscription) {
    assert(identical(subscription._next, subscription));
    subscription._eventState = (_state & _STATE_EVENT_ID);
    _BroadcastSubscription<T> oldLast = _lastSubscription;
    _lastSubscription = subscription;
    subscription._next = nullptr;
    subscription._previous = oldLast;
    if (oldLast == nullptr) {
        _firstSubscription = subscription;
    } else {
        oldLast._next = subscription;
    }
}

void _BroadcastStreamController::_removeListener(_BroadcastSubscription<T> subscription) {
    assert(identical(subscription._controller, this));
    assert(!identical(subscription._next, subscription));
    _BroadcastSubscription<T> previous = subscription._previous;
    _BroadcastSubscription<T> next = subscription._next;
    if (previous == nullptr) {
        _firstSubscription = next;
    } else {
        previous._next = next;
    }
    if (next == nullptr) {
        _lastSubscription = previous;
    } else {
        next._previous = previous;
    }
    subscription._next = subscription._previous = subscription;
}

StreamSubscription<T> _BroadcastStreamController::_subscribe(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    if (isClosed) {
        return <T>_DoneStreamSubscription(onDone);
    }
    auto subscription = <T>_BroadcastSubscription(this, onData, onError, onDone, cancelOnError);
    _addListener(subscription);
    if (identical(_firstSubscription, _lastSubscription)) {
        _runGuarded(onListen);
    }
    return subscription;
}

Future<void> _BroadcastStreamController::_recordCancel(StreamSubscription<T> sub) {
    _BroadcastSubscription<T> subscription = (;
    if (identical(subscription._next, subscription))     {
        return nullptr;
    }
    if (subscription._isFiring) {
        subscription._setRemoveAfterFiring();
    } else {
        _removeListener(subscription);
        if (!_isFiring && _isEmpty) {
            _callOnCancel();
        }
    }
    return nullptr;
}

void _BroadcastStreamController::_recordPause(StreamSubscription<T> subscription) {
}

void _BroadcastStreamController::_recordResume(StreamSubscription<T> subscription) {
}

Error _BroadcastStreamController::_addEventError() {
    if (isClosed) {
        return StateError("Cannot add new events after calling close");
    }
    assert(_isAddingStream);
    return StateError("Cannot add new events while doing an addStream");
}

void _BroadcastStreamController::_add(T data) {
    _sendData(data);
}

void _BroadcastStreamController::_addError(Object error, StackTrace stackTrace) {
    _sendError(error, stackTrace);
}

void _BroadcastStreamController::_close() {
    assert(_isAddingStream);
    _AddStreamState addState = _addStreamState!;
    _addStreamState = nullptr;
    _state = ~_STATE_ADDSTREAM;
    addState.complete();
}

void _BroadcastStreamController::_forEachListener(FunctionType action) {
    if (_isFiring) {
        ;
    }
    if (_isEmpty)     {
        return;
    }
    int id = (_state & _STATE_EVENT_ID);
    _state = _STATE_EVENT_ID | _STATE_FIRING;
    _BroadcastSubscription<T> subscription = _firstSubscription;
    while (subscription != nullptr) {
        if (subscription._expectsEvent(id)) {
            subscription._eventState = _BroadcastSubscription._STATE_FIRING;
            action(subscription);
            subscription._toggleEventId();
            _BroadcastSubscription<T> next = subscription._next;
            if (subscription._removeAfterFiring) {
                _removeListener(subscription);
            }
            subscription._eventState = ~_BroadcastSubscription._STATE_FIRING;
            subscription = next;
        } else {
            subscription = subscription._next;
        }
    }
    _state = ~_STATE_FIRING;
    if (_isEmpty) {
        _callOnCancel();
    }
}

void _BroadcastStreamController::_callOnCancel() {
    assert(_isEmpty);
    if (isClosed) {
        auto doneFuture = _doneFuture!;
        if (doneFuture._mayComplete) {
            doneFuture._asyncComplete(nullptr);
        }
    }
    _runGuarded(onCancel);
}

_SyncBroadcastStreamController::_SyncBroadcastStreamController(FunctionType onCancel, FunctionType onListen) {
    {
        super(onListen, onCancel);
    }
}

bool _SyncBroadcastStreamController::_mayAddEvent() {
    return super._mayAddEvent && !_isFiring;
}

void _SyncBroadcastStreamController::_addEventError() {
    if (_isFiring) {
        return StateError("Cannot fire new event. Controller is already firing an event");
    }
    return super._addEventError();
}

void _SyncBroadcastStreamController::_sendData(T data) {
    if (_isEmpty)     {
        return;
    }
    if (_hasOneListener) {
        _state = _BroadcastStreamController._STATE_FIRING;
        _BroadcastSubscription<T> firstSubscription = (;
        firstSubscription._add(data);
        _state = ~_BroadcastStreamController._STATE_FIRING;
        if (_isEmpty) {
            _callOnCancel();
        }
        return;
    }
    _forEachListener();
}

void _SyncBroadcastStreamController::_sendError(Object error, StackTrace stackTrace) {
    if (_isEmpty)     {
        return;
    }
    _forEachListener();
}

void _SyncBroadcastStreamController::_sendDone() {
    if (!_isEmpty) {
        _forEachListener();
    } else {
        assert(_doneFuture != nullptr && _doneFuture!._mayComplete);
        _doneFuture!._asyncComplete(nullptr);
    }
}

_AsyncBroadcastStreamController::_AsyncBroadcastStreamController(FunctionType onCancel, FunctionType onListen) {
    {
        super(onListen, onCancel);
    }
}

void _AsyncBroadcastStreamController::_sendData(T data) {
    for (; subscription != nullptr; subscription = subscription._next) {
        subscription._addPending(<T>_DelayedData(data));
    }
}

void _AsyncBroadcastStreamController::_sendError(Object error, StackTrace stackTrace) {
    for (; subscription != nullptr; subscription = subscription._next) {
        subscription._addPending(_DelayedError(error, stackTrace));
    }
}

void _AsyncBroadcastStreamController::_sendDone() {
    if (!_isEmpty) {
        for (; subscription != nullptr; subscription = subscription._next) {
            subscription._addPending(const _DelayedDone());
        }
    } else {
        assert(_doneFuture != nullptr && _doneFuture!._mayComplete);
        _doneFuture!._asyncComplete(nullptr);
    }
}

void _AsBroadcastStreamController::add(T data) {
    if (!isClosed && _isFiring) {
        _addPendingEvent(<T>_DelayedData(data));
        return;
    }
    super.add(data);
    _flushPending();
}

void _AsBroadcastStreamController::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    stackTrace = AsyncError.defaultStackTrace(error);
    if (!isClosed && _isFiring) {
        _addPendingEvent(_DelayedError(error, stackTrace));
        return;
    }
    if (!_mayAddEvent)     {
        ;
    }
    _sendError(error, stackTrace);
    _flushPending();
}

Future _AsBroadcastStreamController::close() {
    if (!isClosed && _isFiring) {
        _addPendingEvent(const _DelayedDone());
        _state = _BroadcastStreamController._STATE_CLOSED;
        return super.done;
    }
    Future result = super.close();
    assert(!_hasPending);
    return result;
}

_AsBroadcastStreamController::_AsBroadcastStreamController(FunctionType onCancel, FunctionType onListen) {
    {
        super(onListen, onCancel);
    }
}

bool _AsBroadcastStreamController::_hasPending() {
    auto pending = _pending;
    return pending != nullptr && !pending.isEmpty;
}

void _AsBroadcastStreamController::_addPendingEvent(_DelayedEvent event) {
    (_pending ??= <T>_PendingEvents()).add(event);
}

void _AsBroadcastStreamController::_flushPending() {
    auto pending = _pending;
    if (pending != nullptr) {
        while (!pending.isEmpty) {
            pending.handleNext(this);
        }
    }
}

void _AsBroadcastStreamController::_callOnCancel() {
    auto pending = _pending;
    if (pending != nullptr) {
        pending.clear();
        _pending = nullptr;
    }
    super._callOnCancel();
}
