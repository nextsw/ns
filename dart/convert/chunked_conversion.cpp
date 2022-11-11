#include "chunked_conversion.hpp"
template<typename T>
void _SimpleCallbackSinkCls<T>::add(T chunk) {
    _accumulated->add(chunk);
}

template<typename T>
void _SimpleCallbackSinkCls<T>::close() {
    _callback(_accumulated);
}

template<typename S, typename T>
void _ConverterStreamEventSinkCls<S, T>::add(S o) {
    _chunkedSink->add(o);
}

template<typename S, typename T>
void _ConverterStreamEventSinkCls<S, T>::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    _eventSink->addError(error, stackTrace);
}

template<typename S, typename T>
void _ConverterStreamEventSinkCls<S, T>::close() {
    _chunkedSink->close();
}

template<typename S, typename T>
_ConverterStreamEventSinkCls<S, T>::_ConverterStreamEventSinkCls(Converter<S, T> converter, EventSink<T> sink) {
    {
        _eventSink = sink;
        _chunkedSink = converter->startChunkedConversion(sink);
    }
}
