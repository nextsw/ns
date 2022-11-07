#ifndef EXTENSION_H
#define EXTENSION_H
#include <memory>




class ServiceExtensionResponse {
public:
    String result;

    int errorCode;

    String errorDetail;

    static const auto  kInvalidParams;

    static const auto  kExtensionError;

    static const auto  kExtensionErrorMax;

    static const auto  kExtensionErrorMin;

    static const auto  invalidParams;

    static const auto  extensionError;

    static const auto  extensionErrorMax;

    static const auto  extensionErrorMin;


    void  result(String result);

    void  error(int errorCode, String errorDetail);

    bool isError();

private:

    static String _errorCodeMessage(int errorCode);

    static void  _validateErrorCode(int errorCode);

    String _toString();

};
void registerExtension(ServiceExtensionHandler handler, String method);

external bool extensionStreamHasListener();

void postEvent(Map eventData, String eventKind);

external void _postEvent(String eventData, String eventKind);

external ServiceExtensionHandler _lookupExtension(String method);

external void  _registerExtension(ServiceExtensionHandler handler, String method);


#endif