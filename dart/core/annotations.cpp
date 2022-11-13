#include "annotations.hpp"
String DeprecatedCls::expires() {
    return message;
}

String DeprecatedCls::toString() {
    return __sf("Deprecated feature: %s", message);
}

String ProvisionalCls::message() {
    return nullptr;
}
