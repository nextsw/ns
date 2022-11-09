#include "extension.hpp"
void ServiceExtensionResponseCls::result(String result) {
    checkNotNullable(result, "result");
}

void ServiceExtensionResponseCls::error(int errorCode, String errorDetail) {
    _validateErrorCode(errorCode);
    checkNotNullable(errorDetail, "errorDetail");
}

bool ServiceExtensionResponseCls::isError() {
    return (errorCode != nullptr) && (errorDetail != nullptr);
}

String ServiceExtensionResponseCls::_errorCodeMessage(int errorCode) {
    _validateErrorCode(errorCode);
    if (errorCode == invalidParams) {
        return "Invalid params";
    }
    return "Server error";
}

void ServiceExtensionResponseCls::_validateErrorCode(int errorCode) {
    checkNotNullable(errorCode, "errorCode");
    if (errorCode == invalidParams)     {
        return;
    }
    if ((errorCode >= extensionErrorMin) && (errorCode <= extensionErrorMax)) {
        return;
    }
    ;
}

String ServiceExtensionResponseCls::_toString() {
    map1.set("code", errorCode!);map1.set("message", _errorCodeMessage(errorCode!));map1.set("data", map2.set("details", errorDetail!);list2);return result ?? json->encode(list1);
}

void registerExtension(ServiceExtensionHandler handler, String method) {
    checkNotNullable(method, "method");
    if (!method->startsWith("ext.")) {
        ;
    }
    if (_lookupExtension(method) != nullptr) {
        ;
    }
    checkNotNullable(handler, "handler");
    _registerExtension(method, handler);
}

void postEvent(Map eventData, String eventKind) {
    if (!extensionStreamHasListener) {
        return;
    }
    checkNotNullable(eventKind, "eventKind");
    checkNotNullable(eventData, "eventData");
    String eventDataAsString = json->encode(eventData);
    _postEvent(eventKind, eventDataAsString);
}
