#include "message_codec.hpp"
MethodCall::MethodCall(dynamic arguments, String method) {
    {
        assert(method != nullptr);
    }
}

String MethodCall::toString() {
    return "${objectRuntimeType(this, 'MethodCall')}($method, $arguments)";
}

PlatformException::PlatformException(String code, dynamic details, String message, String stacktrace) {
    {
        assert(code != nullptr);
    }
}

String PlatformException::toString() {
    return "PlatformException($code, $message, $details, $stacktrace)";
}

String MissingPluginException::toString() {
    return "MissingPluginException($message)";
}
