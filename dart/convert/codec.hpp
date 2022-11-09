#ifndef DART_CONVERT_CODEC
#define DART_CONVERT_CODEC
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename S, typename T> class CodecCls : public ObjectCls {
public:

     CodecCls();
    virtual T encode(S input);

    virtual S decode(T encoded);

    virtual Converter<S, T> encoder();
    virtual Converter<T, S> decoder();
    template<typename R>  virtual Codec<S, R> fuse(Codec<T, R> other);

    virtual Codec<T, S> inverted();

private:

};
template<typename S, typename T> using Codec = std::shared_ptr<CodecCls<S, T>>;

template<typename S, typename M, typename T> class _FusedCodecCls : public CodecCls<S, T> {
public:

    virtual Converter<S, T> encoder();

    virtual Converter<T, S> decoder();

private:
    Codec<S, M> _first;

    Codec<M, T> _second;


     _FusedCodecCls(Codec<S, M> _first, Codec<M, T> _second);
};
template<typename S, typename M, typename T> using _FusedCodec = std::shared_ptr<_FusedCodecCls<S, M, T>>;

template<typename T, typename S> class _InvertedCodecCls : public CodecCls<T, S> {
public:

    virtual Converter<T, S> encoder();

    virtual Converter<S, T> decoder();

    virtual Codec<S, T> inverted();

private:
    Codec<S, T> _codec;


     _InvertedCodecCls(Codec<S, T> codec);

};
template<typename T, typename S> using _InvertedCodec = std::shared_ptr<_InvertedCodecCls<T, S>>;


#endif