#include "extension.hpp"
void ServiceExtensionResponse::result(String result) {
    checkNotNullable(result, "result");
}

void ServiceExtensionResponse::error(int errorCode, String errorDetail) {
    _validateErrorCode(errorCode);
    checkNotNullable(errorDetail, "errorDetail");
}

bool ServiceExtensionResponse::isError() {
    return (errorCode != nullptr) && (errorDetail != nullptr);
}

String ServiceExtensionResponse::_errorCodeMessage(int errorCode) {
    _validateErrorCode(errorCode);
    if (errorCode == invalidParams) {
        return "Invalid params";
    }
    return "Server error";
}

void ServiceExtensionResponse::_validateErrorCode(int errorCode) {
    checkNotNullable(errorCode, "errorCode");
    if (errorCode == invalidParams)     {
        return;
    }
    if ((errorCode >= extensionErrorMin) && (errorCode <= extensionErrorMax)) {
        return;
    }
    ;
}

String ServiceExtensionResponse::_toString() {
    return result ?? json.encode();
}

void registerExtension(ServiceExtensionHandler handler, String method) {
    checkNotNullable(method, "method");
    if (!method.startsWith("ext.")) {
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
    String eventDataAsString = json.encode(eventData);
    _postEvent(eventKind, eventDataAsString);
}
