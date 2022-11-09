#ifndef DART_CONVERT_CONVERTER
#define DART_CONVERT_CONVERTER
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename S, typename T> class ConverterCls : public StreamTransformerBaseCls<S, T> {
public:

     ConverterCls();
    template<typename SS, typename ST, typename TS, typename TT>  static Converter<TS, TT> castFrom(Converter<SS, ST> source);

    virtual T convert(S input);
    template<typename TT>  virtual Converter<S, TT> fuse(Converter<T, TT> other);

    virtual Sink<S> startChunkedConversion(Sink<T> sink);

    virtual Stream<T> bind(Stream<S> stream);

    template<typename RS, typename RT>  virtual Converter<RS, RT> cast();

private:

};
template<typename S, typename T> using Converter = std::shared_ptr<ConverterCls<S, T>>;

template<typename S, typename M, typename T> class _FusedConverterCls : public ConverterCls<S, T> {
public:

    virtual T convert(S input);

    virtual Sink<S> startChunkedConversion(Sink<T> sink);

private:
    Converter<S, M> _first;

    Converter<M, T> _second;


     _FusedConverterCls(Converter<S, M> _first, Converter<M, T> _second);
};
template<typename S, typename M, typename T> using _FusedConverter = std::shared_ptr<_FusedConverterCls<S, M, T>>;


#endif