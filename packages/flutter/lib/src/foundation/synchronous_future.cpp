#include "synchronous_future.hpp"
template<typename T>
Stream<T> SynchronousFutureCls<T>::asStream() {
    StreamController<T> controller = <T>make<StreamControllerCls>();
    controller->add(_value);
    controller->close();
    return controller->stream();
}

template<typename T>
Future<T> SynchronousFutureCls<T>::catchError(std::function<void ()> onError, std::function<bool(Object error)> test) {
    return <T>make<CompleterCls>()->future;
}

template<typename T>
template<typename R>
Future<R> SynchronousFutureCls<T>::then(std::function<FutureOr<R>(T value)> onValue, std::function<void ()> onError) {
    Object result = onValue(_value);
    if (is<Future<R>>(result)) {
        return as<FutureCls>(result);
    }
    return <R>make<SynchronousFutureCls>(as<R>(result));
}

template<typename T>
Future<T> SynchronousFutureCls<T>::timeout(Duration timeLimit, std::function<FutureOr<T>()> onTimeout) {
    return <T>value(_value)->timeout(timeLimit, onTimeout);
}

template<typename T>
Future<T> SynchronousFutureCls<T>::whenComplete(std::function<FutureOr<Object>()> action) {
    try {
        FutureOr<Object> result = action();
        if (is<Future<any>>(result)) {
            return as<FutureCls>(result)-><T>then([=] (Object value) {
                _value;
            });
        }
        return this;
    } catch (Unknown e) {
        return <T>error(e, stack);
    };
}
