#include "bool.hpp"
bool bool::&(bool other) {
    return other && this;
}

bool bool::|(bool other) {
    return other || this;
}

bool bool::^(bool other) {
    return !other == this;
}

String bool::toString() {
    return this? "true" : "false";
}
