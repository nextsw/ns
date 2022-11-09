#include "converter.hpp"
template<typename S, typename T> Converter<TS, TT> ConverterCls<S, T>::castFromtemplate<typename SS, typename ST, typename TS, typename TT> (Converter<SS, ST> source) {
    return <SS, ST, TS, TT>make<CastConverterCls>(source);
}

template<typename S, typename T> Converter<S, TT> ConverterCls<S, T>::fusetemplate<typename TT> (Converter<T, TT> other) {
    return <S, T, TT>make<_FusedConverterCls>(this, other);
}

template<typename S, typename T> Sink<S> ConverterCls<S, T>::startChunkedConversion(Sink<T> sink) {
    ;
}

template<typename S, typename T> Stream<T> ConverterCls<S, T>::bind(Stream<S> stream) {
    return <T>eventTransformed(stream, [=] (EventSink sink)     {
        make<_ConverterStreamEventSinkCls>(this, sink);
    });
}

template<typename S, typename T> Converter<RS, RT> ConverterCls<S, T>::casttemplate<typename RS, typename RT> () {
    return ConverterCls-><S, T, RS, RT>castFrom(this);
}

template<typename S, typename M, typename T> T _FusedConverterCls<S, M, T>::convert(S input) {
    return _second->convert(_first->convert(input));
}

template<typename S, typename M, typename T> Sink<S> _FusedConverterCls<S, M, T>::startChunkedConversion(Sink<T> sink) {
    return _first->startChunkedConversion(_second->startChunkedConversion(sink));
}
