#include "bool.hpp"
bool boolCls::&(bool other) {
    return other && this;
}

bool boolCls::|(bool other) {
    return other || this;
}

bool boolCls::^(bool other) {
    return !other == this;
}

String boolCls::toString() {
    return this? __s("true") : __s("false");
}
