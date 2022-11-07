#include "stream_pipe.hpp"
void _runUserCode<T>(onSuccess , onError , FunctionType userCode) {
    ;
}

void _cancelAndError(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription) {
    auto cancelFuture = subscription.cancel();
    if (cancelFuture != nullptr && !identical(cancelFuture, Future._nullFuture)) {
        cancelFuture.whenComplete();
    } else {
        future._completeError(error, stackTrace);
    }
}

void _cancelAndErrorWithReplacement(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription) {
    AsyncError replacement = Zone.current.errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement.error;
        stackTrace = replacement.stackTrace;
    }
    _cancelAndError(subscription, future, error, stackTrace);
}

FunctionType _cancelAndErrorClosure(_Future future, StreamSubscription subscription) {
    return ;
}

void _cancelAndValue(value , _Future future, StreamSubscription subscription) {
    auto cancelFuture = subscription.cancel();
    if (cancelFuture != nullptr && !identical(cancelFuture, Future._nullFuture)) {
        cancelFuture.whenComplete();
    } else {
        future._complete(value);
    }
}

bool _ForwardingStream::isBroadcast() {
    return _source.isBroadcast;
}

StreamSubscription<T> _ForwardingStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return _createSubscription(onData, onError, onDone, cancelOnError ?? false);
}

StreamSubscription<T> _ForwardingStream::_createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return <S, T>_ForwardingStreamSubscription(this, onData, onError, onDone, cancelOnError);
}

void _ForwardingStream::_handleError(Object error, _EventSink<T> sink, StackTrace stackTrace) {
    sink._addError(error, stackTrace);
}

void _ForwardingStream::_handleDone(_EventSink<T> sink) {
    sink._close();
}

_ForwardingStreamSubscription::_ForwardingStreamSubscription(_ForwardingStream<S, T> _stream, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    {
        super(onData, onError, onDone, cancelOnError);
    }
    {
        _subscription = _stream._source.listen(_handleData_handleError, _handleDone);
    }
}

void _ForwardingStreamSubscription::_add(T data) {
    if (_isClosed)     {
        return;
    }
    super._add(data);
}

void _ForwardingStreamSubscription::_addError(Object error, StackTrace stackTrace) {
    if (_isClosed)     {
        return;
    }
    super._addError(error, stackTrace);
}

void _ForwardingStreamSubscription::_onPause() {
    _subscription?.pause();
}

void _ForwardingStreamSubscription::_onResume() {
    _subscription?.resume();
}

Future<void> _ForwardingStreamSubscription::_onCancel() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        _subscription = nullptr;
        return subscription.cancel();
    }
    return nullptr;
}

void _ForwardingStreamSubscription::_handleData(S data) {
    _stream._handleData(data, this);
}

void _ForwardingStreamSubscription::_handleError(error , StackTrace stackTrace) {
    _stream._handleError(error, stackTrace, this);
}

void _ForwardingStreamSubscription::_handleDone() {
    _stream._handleDone(this);
}

void _addErrorWithReplacement(Object error, _EventSink sink, StackTrace stackTrace) {
    AsyncError replacement = Zone.current.errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement.error;
        stackTrace = replacement.stackTrace;
    }
    sink._addError(error, stackTrace);
}

_WhereStream::_WhereStream(Stream<T> source, FunctionType test) {
    {
        _test = test;
        super(source);
    }
}

void _WhereStream::_handleData(T inputEvent, _EventSink<T> sink) {
    bool satisfies;
    ;
    if (satisfies) {
        sink._add(inputEvent);
    }
}

_MapStream::_MapStream(Stream<S> source, FunctionType transform) {
    {
        this._transform = transform;
        super(source);
    }
}

void _MapStream::_handleData(S inputEvent, _EventSink<T> sink) {
    T outputEvent;
    ;
    sink._add(outputEvent);
}

_ExpandStream::_ExpandStream(FunctionType expand, Stream<S> source) {
    {
        this._expand = expand;
        super(source);
    }
}

void _ExpandStream::_handleData(S inputEvent, _EventSink<T> sink) {
    ;
}

_HandleErrorStream::_HandleErrorStream(FunctionType _onError, FunctionType _test, Stream<T> source) {
    {
        super(source);
    }
}

void _HandleErrorStream::_handleData(T data, _EventSink<T> sink) {
    sink._add(data);
}

void _HandleErrorStream::_handleError(Object error, _EventSink<T> sink, StackTrace stackTrace) {
    bool matches = true;
    auto test = _test;
    if (test != nullptr) {
        ;
    }
    if (matches) {
        ;
    } else {
        sink._addError(error, stackTrace);
    }
}

_TakeStream::_TakeStream(int count, Stream<T> source) {
    {
        this._count = count;
        super(source);
    }
}

StreamSubscription<T> _TakeStream::_createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    if (_count == 0) {
        _source.listen(nullptr).cancel();
        return <T>_DoneStreamSubscription(onDone);
    }
    return <int, T>_StateStreamSubscription(this, onData, onError, onDone, cancelOnError, _count);
}

void _TakeStream::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = (;
    int count = subscription._subState;
    if (count > 0) {
        sink._add(inputEvent);
        count = 1;
        subscription._subState = count;
        if (count == 0) {
            sink._close();
        }
    }
}

_StateStreamSubscription::_StateStreamSubscription(S _subState, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError, _ForwardingStream<T, T> stream) {
    {
        super(stream, onData, onError, onDone, cancelOnError);
    }
}

_TakeWhileStream::_TakeWhileStream(Stream<T> source, FunctionType test) {
    {
        this._test = test;
        super(source);
    }
}

void _TakeWhileStream::_handleData(T inputEvent, _EventSink<T> sink) {
    bool satisfies;
    ;
    if (satisfies) {
        sink._add(inputEvent);
    } else {
        sink._close();
    }
}

_SkipStream::_SkipStream(int count, Stream<T> source) {
    {
        this._count = count;
        super(source);
    }
    {
        RangeError.checkNotNegative(count, "count");
    }
}

StreamSubscription<T> _SkipStream::_createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return <int, T>_StateStreamSubscription(this, onData, onError, onDone, cancelOnError, _count);
}

void _SkipStream::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = (;
    int count = subscription._subState;
    if (count > 0) {
        subscription._subState = count - 1;
        return;
    }
    sink._add(inputEvent);
}

_SkipWhileStream::_SkipWhileStream(Stream<T> source, FunctionType test) {
    {
        this._test = test;
        super(source);
    }
}

StreamSubscription<T> _SkipWhileStream::_createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return <bool, T>_StateStreamSubscription(this, onData, onError, onDone, cancelOnError, false);
}

void _SkipWhileStream::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = (;
    bool hasFailed = subscription._subState;
    if (hasFailed) {
        sink._add(inputEvent);
        return;
    }
    bool satisfies;
    ;
    if (!satisfies) {
        subscription._subState = true;
        sink._add(inputEvent);
    }
}

_DistinctStream::_DistinctStream(FunctionType equals, Stream<T> source) {
    {
        _equals = equals;
        super(source);
    }
}

StreamSubscription<T> _DistinctStream::_createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return <Object, T>_StateStreamSubscription(this, onData, onError, onDone, cancelOnError, _SENTINEL);
}

void _DistinctStream::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = (;
    auto previous = subscription._subState;
    if (identical(previous, _SENTINEL)) {
        subscription._subState = inputEvent;
        sink._add(inputEvent);
    } else {
        T previousEvent = (;
        auto equals = _equals;
        bool isEqual;
        ;
        if (!isEqual) {
            sink._add(inputEvent);
            subscription._subState = inputEvent;
        }
    }
}
