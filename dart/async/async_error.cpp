#include "async_error.hpp"
AsyncError::AsyncError(Object error, StackTrace stackTrace) {
    {
        error = checkNotNullable(error, "error");
        stackTrace = stackTrace ?? defaultStackTrace(error);
    }
}

StackTrace AsyncError::defaultStackTrace(Object error) {
    if (error is Error) {
        auto stackTrace = error.stackTrace;
        if (stackTrace != nullptr)         {
            return stackTrace;
        }
    }
    return StackTrace.empty;
}

String AsyncError::toString() {
    return "$error";
}
