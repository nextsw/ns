#ifndef CONVERTER_H
#define CONVERTER_H
#include <memory>




class Converter<S, T> : StreamTransformerBase<S, T> {
public:

     Converter();

    static Converter<TS, TT> castFrom<SS, ST, TS, TT>(Converter<SS, ST> source);

    T convert(S input);

    Converter<S, TT> fuse<TT>(Converter<T, TT> other);

    Sink<S> startChunkedConversion(Sink<T> sink);

    Stream<T> bind(Stream<S> stream);

    Converter<RS, RT> cast<RS, RT>();

private:

};

class _FusedConverter<S, M, T> : Converter<S, T> {
public:

    T convert(S input);

    Sink<S> startChunkedConversion(Sink<T> sink);

private:
    Converter<S, M> _first;

    Converter<M, T> _second;


     _FusedConverter(Converter<S, M> _first, Converter<M, T> _second);

};

#endif