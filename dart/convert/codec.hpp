#ifndef CODEC_H
#define CODEC_H
#include <memory>




class Codec<S, T> {
public:

     Codec();

    T encode(S input);

    S decode(T encoded);

    Converter<S, T> encoder();

    Converter<T, S> decoder();

    Codec<S, R> fuse<R>(Codec<T, R> other);

    Codec<T, S> inverted();

private:

};

class _FusedCodec<S, M, T> : Codec<S, T> {
public:

    Converter<S, T> encoder();

    Converter<T, S> decoder();

private:
    Codec<S, M> _first;

    Codec<M, T> _second;


     _FusedCodec(Codec<S, M> _first, Codec<M, T> _second);

};

class _InvertedCodec<T, S> : Codec<T, S> {
public:

    Converter<T, S> encoder();

    Converter<S, T> decoder();

    Codec<S, T> inverted();

private:
    Codec<S, T> _codec;


     _InvertedCodec(Codec<S, T> codec);

};

#endif