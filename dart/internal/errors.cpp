#include "errors.hpp"
void LateError::fieldADI(String fieldName)

void LateError::localADI(String localName)

void LateError::fieldNI(String fieldName)

void LateError::localNI(String localName)

void LateError::fieldAI(String fieldName)

void LateError::localAI(String localName)

String LateError::toString() {
    auto message = _message;
    return (message != nullptr)? "LateInitializationError: $message" : "LateInitializationError";
}

String ReachabilityError::toString() {
    auto message = _message;
    return (message != nullptr)? "ReachabilityError: $message" : "ReachabilityError";
}
