#include "errors.hpp"
String ErrorCls::safeToString(Object object) {
    if (is<num>(object) || is<bool>(object) || nullptr == object) {
            Map<String, T> map1 = make<MapCls<>>();    for (auto value : this)     {            ;        }    {        map1.set(value->_name, value);    }return object->toString();
    }
    if (is<String>(object)) {
        return _stringToSafeString(object);
    }
    return _objectToString(object);
}

Never ErrorCls::throwWithStackTrace(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    checkNotNullable(stackTrace, __s("stackTrace"));
    _throw(error, stackTrace);
}

String AssertionErrorCls::toString() {
    if (message != nullptr) {
        return __s("Assertion failed: ${Error.safeToString(message)}");
    }
    return __s("Assertion failed");
}

String NullThrownErrorCls::toString() {
    return __s("Throw of null.");
}
