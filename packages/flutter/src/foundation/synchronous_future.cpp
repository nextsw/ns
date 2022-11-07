#include "synchronous_future.hpp"
Stream<T> SynchronousFuture::asStream() {
    StreamController<T> controller = <T>StreamController();
    controller.add(_value);
    controller.close();
    return controller.stream;
}

Future<T> SynchronousFuture::catchError(FunctionType onError, FunctionType test) {
    return <T>Completer().future;
}

Future<R> SynchronousFuture::then<R>(FunctionType onError, FunctionType onValue) {
    dynamic result = onValue(_value);
    if (result is Future<R>) {
        return result;
    }
    return <R>SynchronousFuture(();
}

Future<T> SynchronousFuture::timeout(FunctionType onTimeout, Duration timeLimit) {
    return <T>value(_value).timeout(timeLimitonTimeout);
}

Future<T> SynchronousFuture::whenComplete(FunctionType action) {
    ;
}
