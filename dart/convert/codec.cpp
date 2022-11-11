#include "codec.hpp"
template<typename S, typename T>
T CodecCls<S, T>::encode(S input) {
    return encoder()->convert(input);
}

template<typename S, typename T>
S CodecCls<S, T>::decode(T encoded) {
    return decoder()->convert(encoded);
}

template<typename S, typename T>
template<typename R>
Codec<S, R> CodecCls<S, T>::fuse(Codec<T, R> other) {
    return <S, T, R>make<_FusedCodecCls>(this, other);
}

template<typename S, typename T>
Codec<T, S> CodecCls<S, T>::inverted() {
    return <T, S>make<_InvertedCodecCls>(this);
}

template<typename S, typename M, typename T>
Converter<S, T> _FusedCodecCls<S, M, T>::encoder() {
    return _first->encoder-><T>fuse(_second->encoder);
}

template<typename S, typename M, typename T>
Converter<T, S> _FusedCodecCls<S, M, T>::decoder() {
    return _second->decoder-><S>fuse(_first->decoder);
}

template<typename T, typename S>
Converter<T, S> _InvertedCodecCls<T, S>::encoder() {
    return _codec->decoder;
}

template<typename T, typename S>
Converter<S, T> _InvertedCodecCls<T, S>::decoder() {
    return _codec->encoder;
}

template<typename T, typename S>
Codec<S, T> _InvertedCodecCls<T, S>::inverted() {
    return _codec;
}

template<typename T, typename S>
_InvertedCodecCls<T, S>::_InvertedCodecCls(Codec<S, T> codec) {
    {
        _codec = codec;
    }
}
