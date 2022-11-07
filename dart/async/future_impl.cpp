#include "future_impl.hpp"
void _Completer::completeError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    if (!future._mayComplete)     {
        ;
    }
    AsyncError replacement = Zone.current.errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement.error;
        stackTrace = replacement.stackTrace;
    } else {
        stackTrace = AsyncError.defaultStackTrace(error);
    }
    _completeError(error, stackTrace);
}

bool _Completer::isCompleted() {
    return !future._mayComplete;
}

void _AsyncCompleter::complete(FutureOr<T> value) {
    if (!future._mayComplete)     {
        ;
    }
    future._asyncComplete(value == nullptr? ( : value);
}

void _AsyncCompleter::_completeError(Object error, StackTrace stackTrace) {
    future._asyncCompleteError(error, stackTrace);
}

void _SyncCompleter::complete(FutureOr<T> value) {
    if (!future._mayComplete)     {
        ;
    }
    future._complete(value == nullptr? ( : value);
}

void _SyncCompleter::_completeError(Object error, StackTrace stackTrace) {
    future._completeError(error, stackTrace);
}

void _FutureListener::then(FunctionType errorCallback, FunctionType onValue, _Future<T> result)

void _FutureListener::thenAwait(FunctionType errorCallback, FunctionType onValue, _Future<T> result)

void _FutureListener::catchError(FunctionType callback, FunctionType errorCallback, _Future<T> result)

void _FutureListener::whenComplete(FunctionType callback, _Future<T> result)

bool _FutureListener::handlesValue() {
    return (state & maskValue != 0);
}

bool _FutureListener::handlesError() {
    return (state & maskError != 0);
}

bool _FutureListener::hasErrorTest() {
    return (state & maskType == stateCatchErrorTest);
}

bool _FutureListener::handlesComplete() {
    return (state & maskType == stateWhenComplete);
}

bool _FutureListener::hasErrorCallback() {
    assert(handlesError);
    return _onError != nullptr;
}

FutureOr<T> _FutureListener::handleValue(S sourceResult) {
    return _zone.<FutureOr<T>, S>runUnary(_onValue, sourceResult);
}

bool _FutureListener::matchesErrorTest(AsyncError asyncError) {
    if (!hasErrorTest)     {
        return true;
    }
    return _zone.<bool, Object>runUnary(_errorTest, asyncError.error);
}

FutureOr<T> _FutureListener::handleError(AsyncError asyncError) {
    assert(handlesError && hasErrorCallback);
    auto errorCallback = this.errorCallback;
    dynamic result;
    if (errorCallback is FunctionType) {
        result = _zone.<dynamic, Object, StackTrace>runBinary(errorCallback, asyncError.error, asyncError.stackTrace);
    } else {
        result = _zone.<dynamic, Object>runUnary((, asyncError.error);
    }
    ;
}

dynamic _FutureListener::handleWhenComplete() {
    assert(!handlesError);
    return _zone.run(_whenCompleteAction);
}

bool _FutureListener::shouldChain(Future<dynamic> value) {
    return value is Future<T> || value is! T;
}

_Zone _FutureListener::_zone() {
    return result._zone;
}

FunctionType _FutureListener::_onValue() {
    assert(handlesValue);
    return <FunctionType>unsafeCast(callback);
}

FunctionType _FutureListener::_onError() {
    return errorCallback;
}

FunctionType _FutureListener::_errorTest() {
    assert(hasErrorTest);
    return <FunctionType>unsafeCast(callback);
}

FunctionType _FutureListener::_whenCompleteAction() {
    assert(handlesComplete);
    return <FunctionType>unsafeCast(callback);
}
