#ifndef DART_ASYNC_STREAM
#define DART_ASYNC_STREAM
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class StreamCls : public ObjectCls {
public:

     StreamCls();
    virtual void  empty();
    virtual void  value(T value);

    virtual void  error(Object error, StackTrace stackTrace);

    virtual void  fromFuture(Future<T> future);

    virtual void  fromFutures(Iterable<Future<T>> futures);

    virtual void  fromIterable(Iterable<T> elements);

    virtual void  multi(std::function<void(MultiStreamController<T> )> onListen, bool isBroadcast);

    virtual void  periodic(Duration period, std::function<T(int computationCount)> computation);

    virtual void  eventTransformed(Stream<dynamic> source, std::function<EventSink<dynamic>(EventSink<T> sink)> mapSink);

    template<typename S, typename T>
 static Stream<T> castFrom(Stream<S> source);

    virtual bool isBroadcast();

    virtual Stream<T> asBroadcastStream(std::function<void(StreamSubscription<T> subscription)> onCancel, std::function<void(StreamSubscription<T> subscription)> onListen);

    virtual StreamSubscription<T> listen(std::function<void(T event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);
    virtual Stream<T> where(std::function<bool(T event)> test);

    template<typename S>
 virtual Stream<S> map(std::function<S(T event)> convert);

    template<typename E>
 virtual Stream<E> asyncMap(std::function<FutureOr<E>(T event)> convert);

    template<typename E>
 virtual Stream<E> asyncExpand(std::function<Stream<E>(T event)> convert);

    virtual Stream<T> handleError(std::function<void ()> onError, std::function<bool(error )> test);

    template<typename S>
 virtual Stream<S> expand(std::function<Iterable<S>(T element)> convert);

    virtual Future pipe(StreamConsumer<T> streamConsumer);

    template<typename S>
 virtual Stream<S> transform(StreamTransformer<T, S> streamTransformer);

    virtual Future<T> reduce(std::function<T(T previous, T element)> combine);

    template<typename S>
 virtual Future<S> fold(S initialValue, std::function<S(S previous, T element)> combine);

    virtual Future<String> join(String separator);

    virtual Future<bool> contains(Object needle);

    virtual Future forEach(std::function<void(T element)> action);

    virtual Future<bool> every(std::function<bool(T element)> test);

    virtual Future<bool> any(std::function<bool(T element)> test);

    virtual Future<int> length();

    virtual Future<bool> isEmpty();

    template<typename R>
 virtual Stream<R> cast();

    virtual Future<List<T>> toList();

    virtual Future<Set<T>> toSet();

    template<typename E>
 virtual Future<E> drain(E futureValue);

    virtual Stream<T> take(int count);

    virtual Stream<T> takeWhile(std::function<bool(T element)> test);

    virtual Stream<T> skip(int count);

    virtual Stream<T> skipWhile(std::function<bool(T element)> test);

    virtual Stream<T> distinct(std::function<bool(T previous, T next)> equals);

    virtual Future<T> first();

    virtual Future<T> last();

    virtual Future<T> single();

    virtual Future<T> firstWhere(std::function<bool(T element)> test, std::function<T()> orElse);

    virtual Future<T> lastWhere(std::function<bool(T element)> test, std::function<T()> orElse);

    virtual Future<T> singleWhere(std::function<bool(T element)> test, std::function<T()> orElse);

    virtual Future<T> elementAt(int index);

    virtual Stream<T> timeout(Duration timeLimit, std::function<void(EventSink<T> sink)> onTimeout);

private:

    virtual void  _internal();
};
template<typename T>
using Stream = std::shared_ptr<StreamCls<T>>;

template<typename T>
class StreamSubscriptionCls : public ObjectCls {
public:

    virtual Future<void> cancel();
    virtual void onData(std::function<void(T data)> handleData);
    virtual void onError(std::function<void ()> handleError);
    virtual void onDone(std::function<void()> handleDone);
    virtual void pause(Future<void> resumeSignal);
    virtual void resume();
    virtual bool isPaused();
    template<typename E>
 virtual Future<E> asFuture(E futureValue);
private:

};
template<typename T>
using StreamSubscription = std::shared_ptr<StreamSubscriptionCls<T>>;

template<typename T>
class EventSinkCls : public ObjectCls {
public:

    virtual void add(T event);
    virtual void addError(Object error, StackTrace stackTrace);
    virtual void close();
private:

};
template<typename T>
using EventSink = std::shared_ptr<EventSinkCls<T>>;

template<typename T>
class StreamViewCls : public StreamCls<T> {
public:

     StreamViewCls(Stream<T> stream);

    virtual bool isBroadcast();

    virtual Stream<T> asBroadcastStream(std::function<void(StreamSubscription<T> subscription)> onCancel, std::function<void(StreamSubscription<T> subscription)> onListen);

    virtual StreamSubscription<T> listen(std::function<void(T value)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

private:
    Stream<T> _stream;


};
template<typename T>
using StreamView = std::shared_ptr<StreamViewCls<T>>;

template<typename S>
class StreamConsumerCls : public ObjectCls {
public:

    virtual Future addStream(Stream<S> stream);
    virtual Future close();
private:

};
template<typename S>
using StreamConsumer = std::shared_ptr<StreamConsumerCls<S>>;

template<typename S>
class StreamSinkCls : public ObjectCls {
public:

    virtual Future close();
    virtual Future done();
private:

};
template<typename S>
using StreamSink = std::shared_ptr<StreamSinkCls<S>>;

template<typename S, typename T>
class StreamTransformerCls : public ObjectCls {
public:

     StreamTransformerCls(std::function<StreamSubscription<T>(Stream<S> stream, bool cancelOnError)> onListen);
    virtual void  fromHandlers(std::function<void(S data, EventSink<T> sink)> handleData, std::function<void(EventSink<T> sink)> handleDone, std::function<void(Object error, StackTrace stackTrace, EventSink<T> sink)> handleError);
    virtual void  fromBind(std::function<Stream<T>(Stream<S> )> bind);
    template<typename SS, typename ST, typename TS, typename TT>
 static StreamTransformer<TS, TT> castFrom(StreamTransformer<SS, ST> source);

    virtual Stream<T> bind(Stream<S> stream);
    template<typename RS, typename RT>
 virtual StreamTransformer<RS, RT> cast();
private:

};
template<typename S, typename T>
using StreamTransformer = std::shared_ptr<StreamTransformerCls<S, T>>;

template<typename S, typename T>
class StreamTransformerBaseCls : public ObjectCls {
public:

     StreamTransformerBaseCls();
    template<typename RS, typename RT>
 virtual StreamTransformer<RS, RT> cast();

private:

};
template<typename S, typename T>
using StreamTransformerBase = std::shared_ptr<StreamTransformerBaseCls<S, T>>;

template<typename T>
class StreamIteratorCls : public ObjectCls {
public:

     StreamIteratorCls(Stream<T> stream);

    virtual Future<bool> moveNext();
    virtual T current();
    virtual Future cancel();
private:

};
template<typename T>
using StreamIterator = std::shared_ptr<StreamIteratorCls<T>>;

template<typename T>
class _ControllerEventSinkWrapperCls : public ObjectCls {
public:

    virtual void add(T data);

    virtual void addError(error , StackTrace stackTrace);

    virtual void close();

private:
    EventSink _sink;


     _ControllerEventSinkWrapperCls(EventSink _sink);
    virtual EventSink _ensureSink();

};
template<typename T>
using _ControllerEventSinkWrapper = std::shared_ptr<_ControllerEventSinkWrapperCls<T>>;

template<typename T>
class MultiStreamControllerCls : public ObjectCls {
public:

    virtual void addSync(T value);
    virtual void addErrorSync(Object error, StackTrace stackTrace);
    virtual void closeSync();
private:

};
template<typename T>
using MultiStreamController = std::shared_ptr<MultiStreamControllerCls<T>>;


#endif