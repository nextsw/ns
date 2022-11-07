#include "codec.hpp"
T Codec::encode(S input) {
    return encoder.convert(input);
}

S Codec::decode(T encoded) {
    return decoder.convert(encoded);
}

Codec<S, R> Codec::fuse<R>(Codec<T, R> other) {
    return <S, T, R>_FusedCodec(this, other);
}

Codec<T, S> Codec::inverted() {
    return <T, S>_InvertedCodec(this);
}

Converter<S, T> _FusedCodec::encoder() {
    return _first.encoder.<T>fuse(_second.encoder);
}

Converter<T, S> _FusedCodec::decoder() {
    return _second.decoder.<S>fuse(_first.decoder);
}

Converter<T, S> _InvertedCodec::encoder() {
    return _codec.decoder;
}

Converter<S, T> _InvertedCodec::decoder() {
    return _codec.encoder;
}

Codec<S, T> _InvertedCodec::inverted() {
    return _codec;
}

_InvertedCodec::_InvertedCodec(Codec<S, T> codec) {
    {
        _codec = codec;
    }
}
