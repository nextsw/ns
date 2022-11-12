#ifndef DART_ASYNC_FUTURE
#define DART_ASYNC_FUTURE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class FutureOrCls : public ObjectCls {
public:

private:

    virtual void  _();

};
template<typename T>
using FutureOr = std::shared_ptr<FutureOrCls<T>>;

template<typename T>
class FutureCls : public ObjectCls {
public:

     FutureCls(std::function<FutureOr<T>()> computation);

    virtual void  microtask(std::function<FutureOr<T>()> computation);

    virtual void  sync(std::function<FutureOr<T>()> computation);

    virtual void  value(FutureOr<T> value);

    virtual void  error(Object error, StackTrace stackTrace);

    virtual void  delayed(Duration duration, std::function<FutureOr<T>()> computation);

    template<typename T>
 static Future<List<T>> wait(Iterable<Future<T>> futures, std::function<void(T successValue)> cleanUp, bool eagerError);

    template<typename T>
 static Future<T> any(Iterable<Future<T>> futures);

    template<typename T>
 static Future<any> forEach(Iterable<T> elements, std::function<FutureOr<any>(T element)> action);

    static Future<any> doWhile(std::function<FutureOr<bool>()> action);

    template<typename R>
 virtual Future<R> then(std::function<FutureOr<R>(T value)> onValue, std::function<void ()> onError);
    virtual Future<T> catchError(std::function<void ()> onError, std::function<bool(Object error)> test);
    virtual Future<T> whenComplete(std::function<FutureOr<void>()> action);
    virtual Stream<T> asStream();
    virtual Future<T> timeout(Duration timeLimit, std::function<FutureOr<T>()> onTimeout);
private:
    static _Future<Null> _nullFuture;

    static _Future<bool> _falseFuture;


    static bool _kTrue(Object _);

};
template<typename T>
using Future = std::shared_ptr<FutureCls<T>>;
void unawaited(Future<void> future);


template<typename T>
class FutureExtensionsCls : public ObjectCls {
public:

    template<typename E>
 virtual Future<T> onError(std::function<FutureOr<T>(E error, StackTrace stackTrace)> handleError, std::function<bool(E error)> test);

    virtual void ignore();

private:

    static void _ignore(Object _, Object __);

};
template<typename T>
using FutureExtensions = std::shared_ptr<FutureExtensionsCls<T>>;

class TimeoutExceptionCls : public ObjectCls {
public:
    String message;

    Duration duration;


     TimeoutExceptionCls(String message, Duration duration);
    virtual String toString();

private:

};
using TimeoutException = std::shared_ptr<TimeoutExceptionCls>;

template<typename T>
class CompleterCls : public ObjectCls {
public:

     CompleterCls();

    virtual void  sync();

    virtual Future<T> future();
    virtual void complete(FutureOr<T> value);
    virtual void completeError(Object error, StackTrace stackTrace);
    virtual bool isCompleted();
private:

};
template<typename T>
using Completer = std::shared_ptr<CompleterCls<T>>;
void _completeWithErrorCallback(_Future<any> result, Object error, StackTrace stackTrace);

void _asyncCompleteWithErrorCallback(_Future<any> result, Object error, StackTrace stackTrace);



#endif