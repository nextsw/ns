#include "message_codec.hpp"
MethodCallCls::MethodCallCls(String method, dynamic arguments) {
    {
        assert(method != nullptr);
    }
}

String MethodCallCls::toString() {
    return __s("${objectRuntimeType(this, 'MethodCall')}($method, $arguments)");
}

PlatformExceptionCls::PlatformExceptionCls(String code, dynamic details, String message, String stacktrace) {
    {
        assert(code != nullptr);
    }
}

String PlatformExceptionCls::toString() {
    return __s("PlatformException($code, $message, $details, $stacktrace)");
}

String MissingPluginExceptionCls::toString() {
    return __s("MissingPluginException($message)");
}
