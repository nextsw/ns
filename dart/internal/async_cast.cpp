#include "async_cast.hpp"
bool CastStream::isBroadcast() {
    return _source.isBroadcast;
}

StreamSubscription<T> CastStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return ;
}

Stream<R> CastStream::cast<R>() {
    return <S, R>CastStream(_source);
}

CastStreamSubscription::CastStreamSubscription(StreamSubscription<S> _source) {
    {
        _source.onData(_onData);
    }
}

Future CastStreamSubscription::cancel() {
    return _source.cancel();
}

void CastStreamSubscription::onData(FunctionType handleData) {
    _handleData = handleData == nullptr? nullptr : _zone.<dynamic, T>registerUnaryCallback(handleData);
}

void CastStreamSubscription::onError(FunctionType handleError) {
    _source.onError(handleError);
    if (handleError == nullptr) {
        _handleError = nullptr;
    } else     {
        if (handleError is FunctionType) {
        _handleError = _zone.<dynamic, Object, StackTrace>registerBinaryCallback(handleError);
    } else     {
        if (handleError is FunctionType) {
        _handleError = _zone.<dynamic, Object>registerUnaryCallback(handleError);
    } else {
        ;
    }
;
    };
    }}

void CastStreamSubscription::onDone(FunctionType handleDone) {
    _source.onDone(handleDone);
}

void CastStreamSubscription::pause(Future resumeSignal) {
    _source.pause(resumeSignal);
}

void CastStreamSubscription::resume() {
    _source.resume();
}

bool CastStreamSubscription::isPaused() {
    return _source.isPaused;
}

Future<E> CastStreamSubscription::asFuture<E>(E futureValue) {
    return _source.<E>asFuture(futureValue);
}

void CastStreamSubscription::_onData(S data) {
    if (_handleData == nullptr)     {
        return;
    }
    T targetData;
    ;
    _zone.runUnaryGuarded(_handleData!, targetData);
}

StreamTransformer<RS, RT> CastStreamTransformer::cast<RS, RT>() {
    return <SS, ST, RS, RT>CastStreamTransformer(_source);
}

Stream<TT> CastStreamTransformer::bind(Stream<TS> stream) {
    return _source.bind(stream.<SS>cast()).<TT>cast();
}

TT CastConverter::convert(TS input) {
    return (;
}

Stream<TT> CastConverter::bind(Stream<TS> stream) {
    return _source.bind(stream.<SS>cast()).<TT>cast();
}

Converter<RS, RT> CastConverter::cast<RS, RT>() {
    return <SS, ST, RS, RT>CastConverter(_source);
}
