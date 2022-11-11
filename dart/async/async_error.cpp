#include "async_error.hpp"
AsyncErrorCls::AsyncErrorCls(Object error, StackTrace stackTrace) {
    {
        error = checkNotNullable(error, __s("error"));
        stackTrace = stackTrace or defaultStackTrace(error);
    }
}

StackTrace AsyncErrorCls::defaultStackTrace(Object error) {
    if (is<Error>(error)) {
        auto stackTrace = as<ErrorCls>(error)->stackTrace;
        if (stackTrace != nullptr)         {
            return stackTrace;
        }
    }
    return StackTraceCls::empty;
}

String AsyncErrorCls::toString() {
    return __s("$error");
}
