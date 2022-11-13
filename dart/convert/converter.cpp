#include "converter.hpp"
template<typename S, typename T>
template<typename SS, typename ST, typename TS, typename TT>
Converter<TS, TT> ConverterCls<S, T>::castFrom(Converter<SS, ST> source) {
    return <SS, ST, TS, TT>make<CastConverterCls>(source);
}

template<typename S, typename T>
template<typename TT>
Converter<S, TT> ConverterCls<S, T>::fuse(Converter<T, TT> other) {
    return <S, T, TT>make<_FusedConverterCls>(this, other);
}

template<typename S, typename T>
Sink<S> ConverterCls<S, T>::startChunkedConversion(Sink<T> sink) {
    throw make<UnsupportedErrorCls>(__sf("This converter does not support chunked conversions: %s", this));
}

template<typename S, typename T>
Stream<T> ConverterCls<S, T>::bind(Stream<S> stream) {
    return <T>eventTransformed(stream, [=] (EventSink<any> sink) {
        make<_ConverterStreamEventSinkCls>(this, sink);
    });
}

template<typename S, typename T>
template<typename RS, typename RT>
Converter<RS, RT> ConverterCls<S, T>::cast() {
    return ConverterCls-><S, T, RS, RT>castFrom(this);
}

template<typename S, typename M, typename T>
T _FusedConverterCls<S, M, T>::convert(S input) {
    return _second->convert(_first->convert(input));
}

template<typename S, typename M, typename T>
Sink<S> _FusedConverterCls<S, M, T>::startChunkedConversion(Sink<T> sink) {
    return _first->startChunkedConversion(_second->startChunkedConversion(sink));
}
