#include "annotations.hpp"
String DeprecatedCls::expires() {
    return message;
}

String DeprecatedCls::toString() {
    return "Deprecated feature: $message";
}

String ProvisionalCls::message() {
    return nullptr;
}
