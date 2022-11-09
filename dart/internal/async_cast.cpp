#include "async_cast.hpp"
template<typename S, typename T> bool CastStreamCls<S, T>::isBroadcast() {
    return _source->isBroadcast;
}

template<typename S, typename T> StreamSubscription<T> CastStreamCls<S, T>::listen(bool cancelOnError, void onData(T data) , void onDone() , void  onError() ) {
    auto _c1 = <S, T>make<CastStreamSubscriptionCls>(_source->listen(nullptronDone, cancelOnError));_c1.auto _c2 = onData(onData);_c2.onError(onError);_c2;return _c1;
}

template<typename S, typename T> Stream<R> CastStreamCls<S, T>::casttemplate<typename R> () {
    return <S, R>make<CastStreamCls>(_source);
}

template<typename S, typename T> CastStreamSubscriptionCls<S, T>::CastStreamSubscriptionCls(StreamSubscription<S> _source) {
    {
        _source->onData(_onData);
    }
}

template<typename S, typename T> Future CastStreamSubscriptionCls<S, T>::cancel() {
    return _source->cancel();
}

template<typename S, typename T> void CastStreamSubscriptionCls<S, T>::onData(void handleData(T data) ) {
    _handleData = handleData == nullptr? nullptr : _zone-><dynamic, T>registerUnaryCallback(handleData);
}

template<typename S, typename T> void CastStreamSubscriptionCls<S, T>::onError(void  handleError() ) {
    _source->onError(handleError);
    if (handleError == nullptr) {
        _handleError = nullptr;
    } else     {
        if (handleError is void Function(Object , StackTrace )) {
        _handleError = _zone-><dynamic, Object, StackTrace>registerBinaryCallback(handleError);
    } else     {
        if (handleError is void Function(Object )) {
        _handleError = _zone-><dynamic, Object>registerUnaryCallback(handleError);
    } else {
        ;
    }
;
    };
    }}

template<typename S, typename T> void CastStreamSubscriptionCls<S, T>::onDone(void handleDone() ) {
    _source->onDone(handleDone);
}

template<typename S, typename T> void CastStreamSubscriptionCls<S, T>::pause(Future resumeSignal) {
    _source->pause(resumeSignal);
}

template<typename S, typename T> void CastStreamSubscriptionCls<S, T>::resume() {
    _source->resume();
}

template<typename S, typename T> bool CastStreamSubscriptionCls<S, T>::isPaused() {
    return _source->isPaused;
}

template<typename S, typename T> Future<E> CastStreamSubscriptionCls<S, T>::asFuturetemplate<typename E> (E futureValue) {
    return _source-><E>asFuture(futureValue);
}

template<typename S, typename T> void CastStreamSubscriptionCls<S, T>::_onData(S data) {
    if (_handleData == nullptr)     {
        return;
    }
    T targetData;
    try {
        targetData = ((T)data);
    } catch (Unknown error) {
        auto handleError = _handleError;
        if (handleError == nullptr) {
            _zone->handleUncaughtError(error, stack);
        } else         {
            if (handleError is void Function(Object , StackTrace )) {
            _zone-><Object, StackTrace>runBinaryGuarded(handleError, error, stack);
        } else {
            _zone-><Object>runUnaryGuarded(((void Function(Object ))handleError), error);
        }
;
        }        return;
    };
    _zone->runUnaryGuarded(_handleData!, targetData);
}

template<typename SS, typename ST, typename TS, typename TT> StreamTransformer<RS, RT> CastStreamTransformerCls<SS, ST, TS, TT>::casttemplate<typename RS, typename RT> () {
    return <SS, ST, RS, RT>make<CastStreamTransformerCls>(_source);
}

template<typename SS, typename ST, typename TS, typename TT> Stream<TT> CastStreamTransformerCls<SS, ST, TS, TT>::bind(Stream<TS> stream) {
    return _source->bind(stream-><SS>cast())-><TT>cast();
}

template<typename SS, typename ST, typename TS, typename TT> TT CastConverterCls<SS, ST, TS, TT>::convert(TS input) {
    return ((TT)_source->convert(((SS)input)));
}

template<typename SS, typename ST, typename TS, typename TT> Stream<TT> CastConverterCls<SS, ST, TS, TT>::bind(Stream<TS> stream) {
    return _source->bind(stream-><SS>cast())-><TT>cast();
}

template<typename SS, typename ST, typename TS, typename TT> Converter<RS, RT> CastConverterCls<SS, ST, TS, TT>::casttemplate<typename RS, typename RT> () {
    return <SS, ST, RS, RT>make<CastConverterCls>(_source);
}
