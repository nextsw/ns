#include "synchronous_future.hpp"
template<typename T> Stream<T> SynchronousFutureCls<T>::asStream() {
    StreamController<T> controller = <T>make<StreamControllerCls>();
    controller->add(_value);
    controller->close();
    return controller->stream;
}

template<typename T> Future<T> SynchronousFutureCls<T>::catchError(void  onError() , bool test(Object error) ) {
    return <T>make<CompleterCls>()->future;
}

template<typename T> Future<R> SynchronousFutureCls<T>::thentemplate<typename R> (void  onError() , FutureOr<R> onValue(T value) ) {
    dynamic result = onValue(_value);
    if (is<Future<R>>(result)) {
        return result;
    }
    return <R>make<SynchronousFutureCls>(as<R>(result));
}

template<typename T> Future<T> SynchronousFutureCls<T>::timeout(FutureOr<T> onTimeout() , Duration timeLimit) {
    return <T>value(_value)->timeout(timeLimitonTimeout);
}

template<typename T> Future<T> SynchronousFutureCls<T>::whenComplete(FutureOr<dynamic> action() ) {
    try {
        FutureOr<dynamic> result = action();
        if (is<Future>(result)) {
            return result-><T>then([=] (dynamic value)             {
                _value;
            });
        }
        return this;
    } catch (Unknown e) {
        return <T>error(e, stack);
    };
}
