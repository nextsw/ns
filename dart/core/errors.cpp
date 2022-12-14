#include "errors.hpp"
String ErrorCls::safeToString(Object object) {
    if (is<num>(object) || is<bool>(object) || nullptr == object) {
            Map<String, T> map1 = make<MapCls<>>();    for (auto value : this) {            ;        }    {        map1.set(value->_name, value);    }return object->toString();
    }
    if (is<String>(object)) {
        return _stringToSafeString(as<StringCls>(object));
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
        return __sf("Assertion failed: %s", ErrorCls->safeToString(message));
    }
    return __s("Assertion failed");
}

String NullThrownErrorCls::toString() {
    return __s("Throw of null.");
}

ArgumentErrorCls::ArgumentErrorCls(Object message, String name) {
    {
        invalidValue = nullptr;
        _hasValue = false;
    }
}

void ArgumentErrorCls::value(value , String name, Object message)

void ArgumentErrorCls::notNull(String name)

template<typename T>
T ArgumentErrorCls::checkNotNull(T argument, String name) {
    if (argument == nullptr) {
        throw ArgumentErrorCls->notNull(name);
    }
    return argument;
}

String ArgumentErrorCls::toString() {
    String name = this->name;
    String nameString = (name == nullptr)? __s("") : __sf(" (%s)", name);
    Object message = this->message;
    auto messageString = (message == nullptr)? __s("") : __sf(": %s", message);
    String prefix = __sf("%s%s%s", _errorName(), nameString, messageString);
    if (!_hasValue) {
        return prefix;
    }
    String explanation = _errorExplanation();
    String errorValue = ErrorCls->safeToString(invalidValue);
    return __sf("%s%s: %s", prefix, explanation, errorValue);
}

String ArgumentErrorCls::_errorName() {
    return __sf("Invalid argument%s", !_hasValue? __s("(s)") : __s(""));
}

String ArgumentErrorCls::_errorExplanation() {
    return __s("");
}

RangeErrorCls::RangeErrorCls(auto message) : ArgumentError(message) {
    {
        start = nullptr;
        end = nullptr;
    }
}

void RangeErrorCls::value(num value, String name, String message)

void RangeErrorCls::range(num invalidValue, int minValue, int maxValue, String name, String message)

int RangeErrorCls::checkValueInInterval(int value, int minValue, int maxValue, String name, String message) {
    if ( < minValue || value > maxValue) {
        throw RangeErrorCls->range(value, minValue, maxValue, name, message);
    }
    return value;
}

int RangeErrorCls::checkValidIndex(int index, Object indexable, String name, int length, String message) {
    length |= (as<int>(indexable->length));
    if (0 > index || index >= length) {
        name |= __s("index");
        throw RangeErrorCls->index(index, indexable, name, message, length);
    }
    return index;
}

int RangeErrorCls::checkValidRange(int start, int end, int length, String startName, String endName, String message) {
    if (0 > start || start > length) {
        startName |= __s("start");
        throw RangeErrorCls->range(start, 0, length, startName, message);
    }
    if (end != nullptr) {
        if (start > end || end > length) {
            endName |= __s("end");
            throw RangeErrorCls->range(end, start, length, endName, message);
        }
        return end;
    }
    return length;
}

int RangeErrorCls::checkNotNegative(int value, String name, String message) {
    if ( < 0) {
        throw RangeErrorCls->range(value, 0, nullptr, name | __s("index"), message);
    }
    return value;
}

String RangeErrorCls::_errorName() {
    return __s("RangeError");
}

String RangeErrorCls::_errorExplanation() {
    assert(_hasValue);
    String explanation = __s("");
    num start = this->start;
    num end = this->end;
    if (start == nullptr) {
        if (end != nullptr) {
            explanation = __sf(": Not less than or equal to %s", end);
        }
    } else {
        if (end == nullptr) {
        explanation = __sf(": Not greater than or equal to %s", start);
    } else {
        if (end > start) {
        explanation = __sf(": Not in inclusive range %s..%s", start, end);
    } else {
        if ( < start) {
        explanation = __s(": Valid value range is empty");
    } else {
        explanation = __sf(": Only valid value is %s", start);
    }
;
    };
    };
    }    return explanation;
}

IndexErrorCls::IndexErrorCls(int invalidValue, Object indexable, String name, String message, int length) {
    {
        this->indexable = indexable;
        this->length = length | indexable->length;
        super->value(invalidValue, name, message | __s("Index out of range"));
    }
}

int IndexErrorCls::start() {
    return 0;
}

int IndexErrorCls::end() {
    return length - 1;
}

String IndexErrorCls::_errorName() {
    return __s("RangeError");
}

String IndexErrorCls::_errorExplanation() {
    assert(_hasValue);
    int invalidValue = this->invalidValue;
    if ( < 0) {
        return __s(": index must not be negative");
    }
    if (length == 0) {
        return __s(": no indices are valid");
    }
    return __sf(": index should be less than %s", length);
}

AbstractClassInstantiationErrorCls::AbstractClassInstantiationErrorCls(String className) {
    {
        _className = className;
    }
}

String UnsupportedErrorCls::toString() {
    return __sf("Unsupported operation: %s", message);
}

String UnimplementedErrorCls::toString() {
    auto message = this->message;
    return (message != nullptr)? __sf("UnimplementedError: %s", message) : __s("UnimplementedError");
}

String StateErrorCls::toString() {
    return __sf("Bad state: %s", message);
}

String ConcurrentModificationErrorCls::toString() {
    if (modifiedObject == nullptr) {
        return __s("Concurrent modification during iteration.");
    }
    return __sf("Concurrent modification during iteration: %s.", ErrorCls->safeToString(modifiedObject));
}

String OutOfMemoryErrorCls::toString() {
    return __s("Out of Memory");
}

StackTrace OutOfMemoryErrorCls::stackTrace() {
    return nullptr;
}

String StackOverflowErrorCls::toString() {
    return __s("Stack Overflow");
}

StackTrace StackOverflowErrorCls::stackTrace() {
    return nullptr;
}

String CyclicInitializationErrorCls::toString() {
    auto variableName = this->variableName;
    return variableName == nullptr? __s("Reading static variable during its initialization") : __sf("Reading static variable '%s' during its initialization", variableName);
}
