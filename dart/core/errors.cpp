#include "errors.hpp"
String Error::safeToString(Object object) {
    if (object is num || object is bool || nullptr == object) {
        return object.toString();
    }
    if (object is String) {
        return _stringToSafeString(object);
    }
    return _objectToString(object);
}

Never Error::throwWithStackTrace(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    checkNotNullable(stackTrace, "stackTrace");
    _throw(error, stackTrace);
}

String AssertionError::toString() {
    if (message != nullptr) {
        return "Assertion failed: ${Error.safeToString(message)}";
    }
    return "Assertion failed";
}

String NullThrownError::toString() {
    return "Throw of null.";
}
