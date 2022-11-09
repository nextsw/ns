#include "errors.hpp"
String ErrorCls::safeToString(Object object) {
    if (object is num || object is bool || nullptr == object) {
            Map<String, T> map1 = make<MapCls<>>();    for (auto value : this)     {            ;        }    {        map1.set(value->_name, value);    }return object->toString();
    }
    if (object is String) {
        return _stringToSafeString(object);
    }
    return _objectToString(object);
}

Never ErrorCls::throwWithStackTrace(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    checkNotNullable(stackTrace, "stackTrace");
    _throw(error, stackTrace);
}

String AssertionErrorCls::toString() {
    if (message != nullptr) {
        return "Assertion failed: ${Error.safeToString(message)}";
    }
    return "Assertion failed";
}

String NullThrownErrorCls::toString() {
    return "Throw of null.";
}
