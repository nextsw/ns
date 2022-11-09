#ifndef DART_ASYNC_ASYNC_ERROR
#define DART_ASYNC_ASYNC_ERROR
#include <base.hpp>

#include <dart/core/core.hpp>


class AsyncErrorCls : public ObjectCls {
public:
    Object error;

    StackTrace stackTrace;


     AsyncErrorCls(Object error, StackTrace stackTrace);

    static StackTrace defaultStackTrace(Object error);

    virtual String toString();

private:

};
using AsyncError = std::shared_ptr<AsyncErrorCls>;


#endif