#ifndef DART_ASYNC_FUTURE
#define DART_ASYNC_FUTURE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T> class FutureOrCls : public ObjectCls {
public:

private:

    virtual void  _();

};
template<typename T> using FutureOr = std::shared_ptr<FutureOrCls<T>>;


#endif