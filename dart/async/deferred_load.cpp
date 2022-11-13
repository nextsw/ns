#include "deferred_load.hpp"
DeferredLoadExceptionCls::DeferredLoadExceptionCls(String message) {
    {
        _s = message;
    }
}

String DeferredLoadExceptionCls::toString() {
    return __sf("DeferredLoadException: '%s'", _s);
}
