#ifndef DART_CONVERT_CHUNKED_CONVERSION
#define DART_CONVERT_CHUNKED_CONVERSION
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class ChunkedConversionSinkCls : public ObjectCls {
public:

     ChunkedConversionSinkCls();
    virtual void  withCallback(std::function<void(List<T> accumulated)> callback);
    virtual void add(T chunk);
    virtual void close();
private:

};
template<typename T>
using ChunkedConversionSink = std::shared_ptr<ChunkedConversionSinkCls<T>>;

template<typename T>
class _SimpleCallbackSinkCls : public ChunkedConversionSinkCls<T> {
public:

    virtual void add(T chunk);

    virtual void close();

private:
    std::function<void(List<T> )> _callback;

    List<T> _accumulated;


     _SimpleCallbackSinkCls(std::function<void(List<T> )> _callback);
};
template<typename T>
using _SimpleCallbackSink = std::shared_ptr<_SimpleCallbackSinkCls<T>>;

template<typename S, typename T>
class _ConverterStreamEventSinkCls : public ObjectCls {
public:

    virtual void add(S o);

    virtual void addError(Object error, StackTrace stackTrace);

    virtual void close();

private:
    EventSink<T> _eventSink;

    Sink<S> _chunkedSink;


     _ConverterStreamEventSinkCls(Converter<S, T> converter, EventSink<T> sink);

};
template<typename S, typename T>
using _ConverterStreamEventSink = std::shared_ptr<_ConverterStreamEventSinkCls<S, T>>;


#endif