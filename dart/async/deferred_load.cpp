#include "deferred_load.hpp"
DeferredLoadException::DeferredLoadException(String message) {
    {
        _s = message;
    }
}

String DeferredLoadException::toString() {
    return "DeferredLoadException: '$_s'";
}
