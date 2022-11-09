#include "deferred_load.hpp"
DeferredLoadExceptionCls::DeferredLoadExceptionCls(String message) {
    {
        _s = message;
    }
}

String DeferredLoadExceptionCls::toString() {
    return "DeferredLoadException: '$_s'";
}
