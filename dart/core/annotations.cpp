#include "annotations.hpp"
String DeprecatedCls::expires() {
    return message;
}

String DeprecatedCls::toString() {
    return __s("Deprecated feature: %s;");
}

String ProvisionalCls::message() {
    return nullptr;
}
