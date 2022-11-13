#include "message_codec.hpp"
MethodCallCls::MethodCallCls(String method, dynamic arguments) {
    {
        assert(method != nullptr);
    }
}

String MethodCallCls::toString() {
    return __sf("%s(%s, %s)", objectRuntimeType(this, __s("MethodCall")), method, arguments);
}

PlatformExceptionCls::PlatformExceptionCls(String code, dynamic details, String message, String stacktrace) {
    {
        assert(code != nullptr);
    }
}

String PlatformExceptionCls::toString() {
    return __sf("PlatformException(%s, %s, %s, %s)", code, message, details, stacktrace);
}

String MissingPluginExceptionCls::toString() {
    return __sf("MissingPluginException(%s)", message);
}
