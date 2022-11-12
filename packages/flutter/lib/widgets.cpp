#include "widgets.hpp"
String toString() {
    String result = __s("TimeoutException");
    if (duration != nullptr) {
        result = __s("TimeoutException after %s;");
    }
    if (message != nullptr) {
        result = __s("%s$%s;");
    }
    return result;
}
