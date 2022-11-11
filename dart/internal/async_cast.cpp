#include "async_cast.hpp"
template<typename S, typename T>
bool CastStreamCls<S, T>::isBroadcast() {
    return _source->isBroadcast();
}

template<typename S, typename T>
StreamSubscription<T> CastStreamCls<S, T>::listen(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    auto _c1 = <S, T>make<CastStreamSubscriptionCls>(_source->listen(nullptronDone, cancelOnError));_c1.auto _c2 = onData(onData);_c2.onError(onError);_c2;return _c1;
}

template<typename S, typename T>
template<typename R>
Stream<R> CastStreamCls<S, T>::cast() {
    return <S, R>make<CastStreamCls>(_source);
}

template<typename S, typename T>
CastStreamSubscriptionCls<S, T>::CastStreamSubscriptionCls(StreamSubscription<S> _source) {
    {
        _source->onData(_onData);
    }
}

template<typename S, typename T>
Future CastStreamSubscriptionCls<S, T>::cancel() {
    return _source->cancel();
}

template<typename S, typename T>
void CastStreamSubscriptionCls<S, T>::onData(std::function<void(T data)> handleData) {
    _handleData = handleData == nullptr? nullptr : _zone-><dynamic, T>registerUnaryCallback(handleData);
}

template<typename S, typename T>
void CastStreamSubscriptionCls<S, T>::onError(std::function<void ()> handleError) {
    _source->onError(handleError);
    if (handleError == nullptr) {
        _handleError = nullptr;
    } else     {
        if (is<std::function<void(Object , StackTrace )>>(handleError)) {
        _handleError = _zone-><dynamic, Object, StackTrace>registerBinaryCallback(handleError);
    } else     {
        if (is<std::function<void(Object )>>(handleError)) {
        _handleError = _zone-><dynamic, Object>registerUnaryCallback(handleError);
    } else {
        throw make<ArgumentErrorCls>(__s("handleError callback must take either an Object (the error), or both an Object (the error) and a StackTrace."));
    }
;
    };
    }}

template<typename S, typename T>
void CastStreamSubscriptionCls<S, T>::onDone(std::function<void()> handleDone) {
    _source->onDone(handleDone);
}

template<typename S, typename T>
void CastStreamSubscriptionCls<S, T>::pause(Future resumeSignal) {
    _source->pause(resumeSignal);
}

template<typename S, typename T>
void CastStreamSubscriptionCls<S, T>::resume() {
    _source->resume();
}

template<typename S, typename T>
bool CastStreamSubscriptionCls<S, T>::isPaused() {
    return _source->isPaused();
}

template<typename S, typename T>
template<typename E>
Future<E> CastStreamSubscriptionCls<S, T>::asFuture(E futureValue) {
    return _source-><E>asFuture(futureValue);
}

template<typename S, typename T>
void CastStreamSubscriptionCls<S, T>::_onData(S data) {
    if (_handleData == nullptr)     {
        return;
    }
    T targetData;
    try {
        targetData = as<T>(data);
    } catch (Unknown error) {
        auto handleError = _handleError;
        if (handleError == nullptr) {
            _zone->handleUncaughtError(error, stack);
        } else         {
            if (is<std::function<void(Object , StackTrace )>>(handleError)) {
            _zone-><Object, StackTrace>runBinaryGuarded(handleError, error, stack);
        } else {
            _zone-><Object>runUnaryGuarded(as<std::function<void(Object )>>(handleError), error);
        }
;
        }        return;
    };
    _zone->runUnaryGuarded(_handleData!, targetData);
}

template<typename SS, typename ST, typename TS, typename TT>
template<typename RS, typename RT>
StreamTransformer<RS, RT> CastStreamTransformerCls<SS, ST, TS, TT>::cast() {
    return <SS, ST, RS, RT>make<CastStreamTransformerCls>(_source);
}

template<typename SS, typename ST, typename TS, typename TT>
Stream<TT> CastStreamTransformerCls<SS, ST, TS, TT>::bind(Stream<TS> stream) {
    return _source->bind(stream-><SS>cast())-><TT>cast();
}

template<typename SS, typename ST, typename TS, typename TT>
TT CastConverterCls<SS, ST, TS, TT>::convert(TS input) {
    return as<TT>(_source->convert(as<SS>(input)));
}

template<typename SS, typename ST, typename TS, typename TT>
Stream<TT> CastConverterCls<SS, ST, TS, TT>::bind(Stream<TS> stream) {
    return _source->bind(stream-><SS>cast())-><TT>cast();
}

template<typename SS, typename ST, typename TS, typename TT>
template<typename RS, typename RT>
Converter<RS, RT> CastConverterCls<SS, ST, TS, TT>::cast() {
    return <SS, ST, RS, RT>make<CastConverterCls>(_source);
}
