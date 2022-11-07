#ifndef FUTURE_IMPL_H
#define FUTURE_IMPL_H
#include <memory>




class _Completer<T> {
public:
    _Future<T> future;


    void complete(FutureOr<T> value);

    void completeError(Object error, StackTrace stackTrace);

    bool isCompleted();

private:

    void _completeError(Object error, StackTrace stackTrace);

};

class _AsyncCompleter<T> : _Completer<T> {
public:

    void complete(FutureOr<T> value);

private:

    void _completeError(Object error, StackTrace stackTrace);

};

class _SyncCompleter<T> : _Completer<T> {
public:

    void complete(FutureOr<T> value);

private:

    void _completeError(Object error, StackTrace stackTrace);

};

class _FutureListener<S, T> {
public:
    static const int maskValue;

    static const int maskError;

    static const int maskTestError;

    static const int maskWhenComplete;

    static const int stateChain;

    static const int stateThen;

    static const int stateThenOnerror;

    static const int stateCatchError;

    static const int stateCatchErrorTest;

    static const int stateWhenComplete;

    static const int maskType;

    _Future<T> result;

    int state;

    FunctionType callback;

    FunctionType errorCallback;


    void  then(FunctionType errorCallback, FunctionType onValue, _Future<T> result);

    void  thenAwait(FunctionType errorCallback, FunctionType onValue, _Future<T> result);

    void  catchError(FunctionType callback, FunctionType errorCallback, _Future<T> result);

    void  whenComplete(FunctionType callback, _Future<T> result);

    bool handlesValue();

    bool handlesError();

    bool hasErrorTest();

    bool handlesComplete();

    bool hasErrorCallback();

    FutureOr<T> handleValue(S sourceResult);

    bool matchesErrorTest(AsyncError asyncError);

    FutureOr<T> handleError(AsyncError asyncError);

    dynamic handleWhenComplete();

    bool shouldChain(Future<dynamic> value);

private:
    _FutureListener _nextListener;


    _Zone _zone();

    FunctionType _onValue();

    FunctionType _onError();

    FunctionType _errorTest();

    FunctionType _whenCompleteAction();

};

#endif