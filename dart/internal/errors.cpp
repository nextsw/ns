#include "errors.hpp"
void LateErrorCls::fieldADI(String fieldName)

void LateErrorCls::localADI(String localName)

void LateErrorCls::fieldNI(String fieldName)

void LateErrorCls::localNI(String localName)

void LateErrorCls::fieldAI(String fieldName)

void LateErrorCls::localAI(String localName)

String LateErrorCls::toString() {
    auto message = _message;
    return (message != nullptr)? __sf("LateInitializationError: %s", message) : __s("LateInitializationError");
}

String ReachabilityErrorCls::toString() {
    auto message = _message;
    return (message != nullptr)? __sf("ReachabilityError: %s", message) : __s("ReachabilityError");
}
