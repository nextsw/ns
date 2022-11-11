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

    virtual Future<T> catchError(void  onError() , bool test(Object error) );

    template<typename R>
 virtual Future<R> then(void  onError() , FutureOr<R> onValue(T value) );

    virtual Future<T> timeout(FutureOr<T> onTimeout() , Duration timeLimit);

    virtual Future<T> whenComplete(FutureOr<dynamic> action() );

private:
    T _value;


};
template<typename T>
using SynchronousFuture = std::shared_ptr<SynchronousFutureCls<T>>;


#endif