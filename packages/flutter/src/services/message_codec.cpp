#include "message_codec.hpp"
MethodCallCls::MethodCallCls(String method, dynamic arguments) {
    {
        assert(method != nullptr);
    }
}

String MethodCallCls::toString() {
    return __s("%s$%s$%s;");
}

PlatformExceptionCls::PlatformExceptionCls(String code, dynamic details, String message, String stacktrace) {
    {
        assert(code != nullptr);
    }
}

String PlatformExceptionCls::toString() {
    return __s("PlatformException(%s$%s$%s$%s;");
}

String MissingPluginExceptionCls::toString() {
    return __s("MissingPluginException(%s;");
}
