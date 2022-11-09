#include "async_error.hpp"
AsyncErrorCls::AsyncErrorCls(Object error, StackTrace stackTrace) {
    {
        error = checkNotNullable(error, "error");
        stackTrace = stackTrace ?? defaultStackTrace(error);
    }
}

StackTrace AsyncErrorCls::defaultStackTrace(Object error) {
    if (error is Error) {
        auto stackTrace = error->stackTrace;
        if (stackTrace != nullptr)         {
            return stackTrace;
        }
    }
    return StackTraceCls::empty;
}

String AsyncErrorCls::toString() {
    return "$error";
}
