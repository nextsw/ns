#include "annotations.hpp"
String Deprecated::expires() {
    return message;
}

String Deprecated::toString() {
    return "Deprecated feature: $message";
}

String Provisional::message() {
    return nullptr;
}
