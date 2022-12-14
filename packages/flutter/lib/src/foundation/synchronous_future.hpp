#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_SYNCHRONOUS_FUTURE
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_SYNCHRONOUS_FUTURE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>


template<typename T>
class SynchronousFutureCls : public ObjectCls {
public:

     SynchronousFutureCls(T _value);
    virtual Stream<T> asStream();

    virtual Future<T> catchError(std::function<void ()> onError, std::function<bool(Object error)> test);

    template<typename R>
 virtual Future<R> then(std::function<FutureOr<R>(T value)> onValue, std::function<void ()> onError);

    virtual Future<T> timeout(Duration timeLimit, std::function<FutureOr<T>()> onTimeout);

    virtual Future<T> whenComplete(std::function<FutureOr<Object>()> action);

private:
    T _value;


};
template<typename T>
using SynchronousFuture = std::shared_ptr<SynchronousFutureCls<T>>;


#endif