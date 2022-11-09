#include "message_codec.hpp"
MethodCallCls::MethodCallCls(dynamic arguments, String method) {
    {
        assert(method != nullptr);
    }
}

String MethodCallCls::toString() {
    return "${objectRuntimeType(this, 'MethodCall')}($method, $arguments)";
}

PlatformExceptionCls::PlatformExceptionCls(String code, dynamic details, String message, String stacktrace) {
    {
        assert(code != nullptr);
    }
}

String PlatformExceptionCls::toString() {
    return "PlatformException($code, $message, $details, $stacktrace)";
}

String MissingPluginExceptionCls::toString() {
    return "MissingPluginException($message)";
}
