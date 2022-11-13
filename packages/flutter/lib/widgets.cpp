#include "widgets.hpp"
String toString() {
    String result = __s("TimeoutException");
    if (duration != nullptr) {
        result = __sf("TimeoutException after %s", duration);
    }
    if (message != nullptr) {
        result = __sf("%s: %s", result, message);
    }
    return result;
}
