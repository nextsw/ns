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
    return this? "true" : "false";
}
