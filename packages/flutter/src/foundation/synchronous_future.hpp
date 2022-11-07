#ifndef SYNCHRONOUS_FUTURE_H
#define SYNCHRONOUS_FUTURE_H
#include <memory>

#include <async/async.hpp>



class SynchronousFuture<T> {
public:

     SynchronousFuture(T _value);

    Stream<T> asStream();

    Future<T> catchError(FunctionType onError, FunctionType test);

    Future<R> then<R>(FunctionType onError, FunctionType onValue);

    Future<T> timeout(FunctionType onTimeout, Duration timeLimit);

    Future<T> whenComplete(FunctionType action);

private:
    T _value;


};

#endif