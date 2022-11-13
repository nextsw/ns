#include "extension.hpp"
void ServiceExtensionResponseCls::result(String result) {
    checkNotNullable(result, __s("result"));
}

void ServiceExtensionResponseCls::error(int errorCode, String errorDetail) {
    _validateErrorCode(errorCode);
    checkNotNullable(errorDetail, __s("errorDetail"));
}

bool ServiceExtensionResponseCls::isError() {
    return (errorCode != nullptr) && (errorDetail != nullptr);
}

String ServiceExtensionResponseCls::_errorCodeMessage(int errorCode) {
    _validateErrorCode(errorCode);
    if (errorCode == invalidParams) {
        return __s("Invalid params");
    }
    return __s("Server error");
}

void ServiceExtensionResponseCls::_validateErrorCode(int errorCode) {
    checkNotNullable(errorCode, __s("errorCode"));
    if (errorCode == invalidParams) {
        return;
    }
    if ((errorCode >= extensionErrorMin) && (errorCode <= extensionErrorMax)) {
        return;
    }
    throw ArgumentErrorCls->value(errorCode, __s("errorCode"), __s("Out of range"));
}

String ServiceExtensionResponseCls::_toString() {
    map1.set(__s("code"), errorCode!);map1.set(__s("message"), _errorCodeMessage(errorCode!));map1.set(__s("data"), map2.set(__s("details"), errorDetail!);list2);return result | json->encode(list1);
}

void registerExtension(String method, ServiceExtensionHandler handler) {
    checkNotNullable(method, __s("method"));
    if (!method->startsWith(__s("ext."))) {
        throw ArgumentErrorCls->value(method, __s("method"), __s("Must begin with ext."));
    }
    if (_lookupExtension(method) != nullptr) {
        throw make<ArgumentErrorCls>(__sf("Extension already registered: %s", method));
    }
    checkNotNullable(handler, __s("handler"));
    _registerExtension(method, handler);
}

void postEvent(String eventKind, Map<any, any> eventData) {
    if (!extensionStreamHasListener) {
        return;
    }
    checkNotNullable(eventKind, __s("eventKind"));
    checkNotNullable(eventData, __s("eventData"));
    String eventDataAsString = json->encode(eventData);
    _postEvent(eventKind, eventDataAsString);
}
