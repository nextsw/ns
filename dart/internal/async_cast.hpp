#ifndef DART_INTERNAL_ASYNC_CAST
#define DART_INTERNAL_ASYNC_CAST
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename S, typename T>
class CastStreamCls : public StreamCls<T> {
public:

     CastStreamCls(Stream<S> _source);
    virtual bool isBroadcast();

    virtual StreamSubscription<T> listen(std::function<void(T data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

    template<typename R>
 virtual Stream<R> cast();

private:
    Stream<S> _source;


};
template<typename S, typename T>
using CastStream = std::shared_ptr<CastStreamCls<S, T>>;

template<typename S, typename T>
class CastStreamSubscriptionCls : public ObjectCls {
public:

     CastStreamSubscriptionCls(StreamSubscription<S> _source);

    virtual Future<any> cancel();

    virtual void onData(std::function<void(T data)> handleData);

    virtual void onError(std::function<void ()> handleError);

    virtual void onDone(std::function<void()> handleDone);

    virtual void pause(Future<any> resumeSignal);

    virtual void resume();

    virtual bool isPaused();

    template<typename E>
 virtual Future<E> asFuture(E futureValue);

private:
    StreamSubscription<S> _source;

    Zone _zone;

    std::function<void(T )> _handleData;

    std::function<void ()> _handleError;


    virtual void _onData(S data);

};
template<typename S, typename T>
using CastStreamSubscription = std::shared_ptr<CastStreamSubscriptionCls<S, T>>;

template<typename SS, typename ST, typename TS, typename TT>
class CastStreamTransformerCls : public StreamTransformerBaseCls<TS, TT> {
public:

     CastStreamTransformerCls(StreamTransformer<SS, ST> _source);
    template<typename RS, typename RT>
 virtual StreamTransformer<RS, RT> cast();

    virtual Stream<TT> bind(Stream<TS> stream);

private:
    StreamTransformer<SS, ST> _source;


};
template<typename SS, typename ST, typename TS, typename TT>
using CastStreamTransformer = std::shared_ptr<CastStreamTransformerCls<SS, ST, TS, TT>>;

template<typename SS, typename ST, typename TS, typename TT>
class CastConverterCls : public ConverterCls<TS, TT> {
public:

     CastConverterCls(Converter<SS, ST> _source);
    virtual TT convert(TS input);

    virtual Stream<TT> bind(Stream<TS> stream);

    template<typename RS, typename RT>
 virtual Converter<RS, RT> cast();

private:
    Converter<SS, ST> _source;


};
template<typename SS, typename ST, typename TS, typename TT>
using CastConverter = std::shared_ptr<CastConverterCls<SS, ST, TS, TT>>;


#endif