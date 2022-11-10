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
    if (errorCode == invalidParams)     {
        return;
    }
    if ((errorCode >= extensionErrorMin) && (errorCode <= extensionErrorMax)) {
        return;
    }
    ;
}

String ServiceExtensionResponseCls::_toString() {
    map1.set(__s("code"), errorCode!);map1.set(__s("message"), _errorCodeMessage(errorCode!));map1.set(__s("data"), map2.set(__s("details"), errorDetail!);list2);return result or json->encode(list1);
}

void registerExtension(ServiceExtensionHandler handler, String method) {
    checkNotNullable(method, __s("method"));
    if (!method->startsWith(__s("ext."))) {
        ;
    }
    if (_lookupExtension(method) != nullptr) {
        ;
    }
    checkNotNullable(handler, __s("handler"));
    _registerExtension(method, handler);
}

void postEvent(Map eventData, String eventKind) {
    if (!extensionStreamHasListener) {
        return;
    }
    checkNotNullable(eventKind, __s("eventKind"));
    checkNotNullable(eventData, __s("eventData"));
    String eventDataAsString = json->encode(eventData);
    _postEvent(eventKind, eventDataAsString);
}
