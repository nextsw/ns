#include "converter.hpp"
Converter<TS, TT> Converter::castFrom<SS, ST, TS, TT>(Converter<SS, ST> source) {
    return <SS, ST, TS, TT>CastConverter(source);
}

Converter<S, TT> Converter::fuse<TT>(Converter<T, TT> other) {
    return <S, T, TT>_FusedConverter(this, other);
}

Sink<S> Converter::startChunkedConversion(Sink<T> sink) {
    ;
}

Stream<T> Converter::bind(Stream<S> stream) {
    return <T>eventTransformed(stream, );
}

Converter<RS, RT> Converter::cast<RS, RT>() {
    return Converter.<S, T, RS, RT>castFrom(this);
}

T _FusedConverter::convert(S input) {
    return _second.convert(_first.convert(input));
}

Sink<S> _FusedConverter::startChunkedConversion(Sink<T> sink) {
    return _first.startChunkedConversion(_second.startChunkedConversion(sink));
}
