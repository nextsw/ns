#include "broadcast_stream_controller.hpp"
template<typename T>
bool _BroadcastStreamCls<T>::isBroadcast() {
    return true;
}

template<typename T>
_BroadcastStreamCls<T>::_BroadcastStreamCls(_StreamControllerLifecycle<T> controller) : _ControllerStream<T>(controller) {
}

template<typename T>
_BroadcastSubscriptionCls<T>::_BroadcastSubscriptionCls(_StreamControllerLifecycle<T> controller, std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError) : _ControllerSubscription<T>(controller, onData, onError, onDone, cancelOnError) {
    {
        _next = _previous = this;
    }
}

template<typename T>
bool _BroadcastSubscriptionCls<T>::_expectsEvent(int eventId) {
    return (_eventState & _STATE_EVENT_ID) == eventId;
}

template<typename T>
void _BroadcastSubscriptionCls<T>::_toggleEventId() {
    _eventState ^= _STATE_EVENT_ID;
}

template<typename T>
bool _BroadcastSubscriptionCls<T>::_isFiring() {
    return (_eventState & _STATE_FIRING) != 0;
}

template<typename T>
void _BroadcastSubscriptionCls<T>::_setRemoveAfterFiring() {
    assert(_isFiring());
    _eventState |= _STATE_REMOVE_AFTER_FIRING;
}

template<typename T>
bool _BroadcastSubscriptionCls<T>::_removeAfterFiring() {
    return (_eventState & _STATE_REMOVE_AFTER_FIRING) != 0;
}

template<typename T>
void _BroadcastSubscriptionCls<T>::_onPause() {
}

template<typename T>
void _BroadcastSubscriptionCls<T>::_onResume() {
}

template<typename T>
std::function<void()> _BroadcastStreamControllerCls<T>::onPause() {
    throw make<UnsupportedErrorCls>(__s("Broadcast stream controllers do not support pause callbacks"));
}

template<typename T>
void _BroadcastStreamControllerCls<T>::onPause(std::function<void()> onPauseHandler) {
    throw make<UnsupportedErrorCls>(__s("Broadcast stream controllers do not support pause callbacks"));
}

template<typename T>
std::function<void()> _BroadcastStreamControllerCls<T>::onResume() {
    throw make<UnsupportedErrorCls>(__s("Broadcast stream controllers do not support pause callbacks"));
}

template<typename T>
void _BroadcastStreamControllerCls<T>::onResume(std::function<void()> onResumeHandler) {
    throw make<UnsupportedErrorCls>(__s("Broadcast stream controllers do not support pause callbacks"));
}

template<typename T>
Stream<T> _BroadcastStreamControllerCls<T>::stream() {
    return <T>make<_BroadcastStreamCls>(this);
}

template<typename T>
StreamSink<T> _BroadcastStreamControllerCls<T>::sink() {
    return <T>make<_StreamSinkWrapperCls>(this);
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::isClosed() {
    return (_state & _STATE_CLOSED) != 0;
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::isPaused() {
    return false;
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::hasListener() {
    return !_isEmpty();
}

template<typename T>
void _BroadcastStreamControllerCls<T>::add(T data) {
    if (!_mayAddEvent()) {
        throw _addEventError();
    }
    _sendData(data);
}

template<typename T>
void _BroadcastStreamControllerCls<T>::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    if (!_mayAddEvent()) {
        throw _addEventError();
    }
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    } else {
        stackTrace |= AsyncErrorCls->defaultStackTrace(error);
    }
    _sendError(error, stackTrace);
}

template<typename T>
Future _BroadcastStreamControllerCls<T>::close() {
    if (isClosed()) {
        assert(_doneFuture != nullptr);
        return _doneFuture!;
    }
    if (!_mayAddEvent()) {
        throw _addEventError();
    }
    _state |= _STATE_CLOSED;
    Future doneFuture = _ensureDoneFuture();
    _sendDone();
    return doneFuture;
}

template<typename T>
Future<void> _BroadcastStreamControllerCls<T>::done() {
    return _ensureDoneFuture();
}

template<typename T>
Future _BroadcastStreamControllerCls<T>::addStream(Stream<T> stream, bool cancelOnError) {
    if (!_mayAddEvent()) {
        throw _addEventError();
    }
    _state |= _STATE_ADDSTREAM;
    auto addStreamState = make<_AddStreamStateCls>(this, stream, cancelOnError | false);
    _addStreamState = addStreamState;
    return addStreamState->addStreamFuture;
}

template<typename T>
_BroadcastStreamControllerCls<T>::_BroadcastStreamControllerCls(std::function<void()> onListen, std::function<FutureOr<void>()> onCancel) {
    {
        _state = _STATE_INITIAL;
    }
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::_hasOneListener() {
    assert(!_isEmpty());
    return identical(_firstSubscription, _lastSubscription);
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::_isFiring() {
    return (_state & _STATE_FIRING) != 0;
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::_isAddingStream() {
    return (_state & _STATE_ADDSTREAM) != 0;
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::_mayAddEvent() {
    return ( < _STATE_CLOSED);
}

template<typename T>
_Future<void> _BroadcastStreamControllerCls<T>::_ensureDoneFuture() {
    return _doneFuture ??= <void>make<_FutureCls>();
}

template<typename T>
bool _BroadcastStreamControllerCls<T>::_isEmpty() {
    return _firstSubscription == nullptr;
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_addListener(_BroadcastSubscription<T> subscription) {
    assert(identical(subscription->_next, subscription));
    subscription->_eventState = (_state & _STATE_EVENT_ID);
    _BroadcastSubscription<T> oldLast = _lastSubscription;
    _lastSubscription = subscription;
    subscription->_next = nullptr;
    subscription->_previous = oldLast;
    if (oldLast == nullptr) {
        _firstSubscription = subscription;
    } else {
        oldLast->_next = subscription;
    }
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_removeListener(_BroadcastSubscription<T> subscription) {
    assert(identical(subscription->_controller, this));
    assert(!identical(subscription->_next, subscription));
    _BroadcastSubscription<T> previous = subscription->_previous;
    _BroadcastSubscription<T> next = subscription->_next;
    if (previous == nullptr) {
        _firstSubscription = next;
    } else {
        previous->_next = next;
    }
    if (next == nullptr) {
        _lastSubscription = previous;
    } else {
        next->_previous = previous;
    }
    subscription->_next = subscription->_previous = subscription;
}

template<typename T>
StreamSubscription<T> _BroadcastStreamControllerCls<T>::_subscribe(std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError) {
    if (isClosed()) {
        return <T>make<_DoneStreamSubscriptionCls>(onDone);
    }
    auto subscription = <T>make<_BroadcastSubscriptionCls>(this, onData, onError, onDone, cancelOnError);
    _addListener(subscription);
    if (identical(_firstSubscription, _lastSubscription)) {
        _runGuarded(onListen);
    }
    return subscription;
}

template<typename T>
Future<void> _BroadcastStreamControllerCls<T>::_recordCancel(StreamSubscription<T> sub) {
    _BroadcastSubscription<T> subscription = as<_BroadcastSubscription<T>>(sub);
    if (identical(subscription->_next, subscription)) {
        return nullptr;
    }
    if (subscription->_isFiring()) {
        subscription->_setRemoveAfterFiring();
    } else {
        _removeListener(subscription);
        if (!_isFiring() && _isEmpty()) {
            _callOnCancel();
        }
    }
    return nullptr;
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_recordPause(StreamSubscription<T> subscription) {
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_recordResume(StreamSubscription<T> subscription) {
}

template<typename T>
Error _BroadcastStreamControllerCls<T>::_addEventError() {
    if (isClosed()) {
        return make<StateErrorCls>(__s("Cannot add new events after calling close"));
    }
    assert(_isAddingStream());
    return make<StateErrorCls>(__s("Cannot add new events while doing an addStream"));
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_add(T data) {
    _sendData(data);
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_addError(Object error, StackTrace stackTrace) {
    _sendError(error, stackTrace);
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_close() {
    assert(_isAddingStream());
    _AddStreamState addState = _addStreamState!;
    _addStreamState = nullptr;
    _state &= ~_STATE_ADDSTREAM;
    addState->complete();
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_forEachListener(std::function<void(_BufferingStreamSubscription<T> subscription)> action) {
    if (_isFiring()) {
        throw make<StateErrorCls>(__s("Cannot fire new event. Controller is already firing an event"));
    }
    if (_isEmpty()) {
        return;
    }
    int id = (_state & _STATE_EVENT_ID);
    _state ^= _STATE_EVENT_ID | _STATE_FIRING;
    _BroadcastSubscription<T> subscription = _firstSubscription;
    while (subscription != nullptr) {
        if (subscription->_expectsEvent(id)) {
            subscription->_eventState |= _BroadcastSubscriptionCls::_STATE_FIRING;
            action(subscription);
            subscription->_toggleEventId();
            _BroadcastSubscription<T> next = subscription->_next;
            if (subscription->_removeAfterFiring()) {
                _removeListener(subscription);
            }
            subscription->_eventState &= ~_BroadcastSubscriptionCls->_STATE_FIRING;
            subscription = next;
        } else {
            subscription = subscription->_next;
        }
    }
    _state &= ~_STATE_FIRING;
    if (_isEmpty()) {
        _callOnCancel();
    }
}

template<typename T>
void _BroadcastStreamControllerCls<T>::_callOnCancel() {
    assert(_isEmpty());
    if (isClosed()) {
        auto doneFuture = _doneFuture!;
        if (doneFuture->_mayComplete()) {
            doneFuture->_asyncComplete(nullptr);
        }
    }
    _runGuarded(onCancel);
}

template<typename T>
_SyncBroadcastStreamControllerCls<T>::_SyncBroadcastStreamControllerCls(std::function<void()> onListen, std::function<void()> onCancel) : _BroadcastStreamController<T>(onListen, onCancel) {
}

template<typename T>
bool _SyncBroadcastStreamControllerCls<T>::_mayAddEvent() {
    return super->_mayAddEvent && !_isFiring();
}

template<typename T>
void _SyncBroadcastStreamControllerCls<T>::_addEventError() {
    if (_isFiring()) {
        return make<StateErrorCls>(__s("Cannot fire new event. Controller is already firing an event"));
    }
    return super->_addEventError();
}

template<typename T>
void _SyncBroadcastStreamControllerCls<T>::_sendData(T data) {
    if (_isEmpty()) {
        return;
    }
    if (_hasOneListener()) {
        _state |= _BroadcastStreamControllerCls::_STATE_FIRING;
        _BroadcastSubscription<T> firstSubscription = as<dynamic>(_firstSubscription);
        firstSubscription->_add(data);
        _state &= ~_BroadcastStreamControllerCls->_STATE_FIRING;
        if (_isEmpty()) {
            _callOnCancel();
        }
        return;
    }
    _forEachListener([=] (_BufferingStreamSubscription<T> subscription) {
        subscription->_add(data);
    });
}

template<typename T>
void _SyncBroadcastStreamControllerCls<T>::_sendError(Object error, StackTrace stackTrace) {
    if (_isEmpty()) {
        return;
    }
    _forEachListener([=] (_BufferingStreamSubscription<T> subscription) {
        subscription->_addError(error, stackTrace);
    });
}

template<typename T>
void _SyncBroadcastStreamControllerCls<T>::_sendDone() {
    if (!_isEmpty()) {
        _forEachListener([=] (_BufferingStreamSubscription<T> subscription) {
            subscription->_close();
        });
    } else {
        assert(_doneFuture != nullptr && _doneFuture!->_mayComplete());
        _doneFuture!->_asyncComplete(nullptr);
    }
}

template<typename T>
_AsyncBroadcastStreamControllerCls<T>::_AsyncBroadcastStreamControllerCls(std::function<void()> onListen, std::function<void()> onCancel) : _BroadcastStreamController<T>(onListen, onCancel) {
}

template<typename T>
void _AsyncBroadcastStreamControllerCls<T>::_sendData(T data) {
    for (; subscription != nullptr; subscription = subscription->_next) {
        subscription->_addPending(<T>make<_DelayedDataCls>(data));
    }
}

template<typename T>
void _AsyncBroadcastStreamControllerCls<T>::_sendError(Object error, StackTrace stackTrace) {
    for (; subscription != nullptr; subscription = subscription->_next) {
        subscription->_addPending(make<_DelayedErrorCls>(error, stackTrace));
    }
}

template<typename T>
void _AsyncBroadcastStreamControllerCls<T>::_sendDone() {
    if (!_isEmpty()) {
        for (; subscription != nullptr; subscription = subscription->_next) {
            subscription->_addPending(make<_DelayedDoneCls>());
        }
    } else {
        assert(_doneFuture != nullptr && _doneFuture!->_mayComplete());
        _doneFuture!->_asyncComplete(nullptr);
    }
}

template<typename T>
void _AsBroadcastStreamControllerCls<T>::add(T data) {
    if (!isClosed() && _isFiring()) {
        _addPendingEvent(<T>make<_DelayedDataCls>(data));
        return;
    }
    super->add(data);
    _flushPending();
}

template<typename T>
void _AsBroadcastStreamControllerCls<T>::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    stackTrace |= AsyncErrorCls->defaultStackTrace(error);
    if (!isClosed() && _isFiring()) {
        _addPendingEvent(make<_DelayedErrorCls>(error, stackTrace));
        return;
    }
    if (!_mayAddEvent()) {
        throw _addEventError();
    }
    _sendError(error, stackTrace);
    _flushPending();
}

template<typename T>
Future _AsBroadcastStreamControllerCls<T>::close() {
    if (!isClosed() && _isFiring()) {
        _addPendingEvent(make<_DelayedDoneCls>());
        _state |= _BroadcastStreamControllerCls::_STATE_CLOSED;
        return super->done;
    }
    Future result = super->close();
    assert(!_hasPending());
    return result;
}

template<typename T>
_AsBroadcastStreamControllerCls<T>::_AsBroadcastStreamControllerCls(std::function<void()> onListen, std::function<void()> onCancel) : _SyncBroadcastStreamController<T>(onListen, onCancel) {
}

template<typename T>
bool _AsBroadcastStreamControllerCls<T>::_hasPending() {
    auto pending = _pending;
    return pending != nullptr && !pending->isEmpty();
}

template<typename T>
void _AsBroadcastStreamControllerCls<T>::_addPendingEvent(_DelayedEvent event) {
    (_pending ??= <T>make<_PendingEventsCls>())->add(event);
}

template<typename T>
void _AsBroadcastStreamControllerCls<T>::_flushPending() {
    auto pending = _pending;
    if (pending != nullptr) {
        while (!pending->isEmpty()) {
            pending->handleNext(this);
        }
    }
}

template<typename T>
void _AsBroadcastStreamControllerCls<T>::_callOnCancel() {
    auto pending = _pending;
    if (pending != nullptr) {
        pending->clear();
        _pending = nullptr;
    }
    super->_callOnCancel();
}
