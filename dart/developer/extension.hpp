#ifndef DART_DEVELOPER_EXTENSION
#define DART_DEVELOPER_EXTENSION
#include <base.hpp>

#include <dart/core/core.hpp>


class ServiceExtensionResponseCls : public ObjectCls {
public:
    String result;

    int errorCode;

    String errorDetail;

    static auto  kInvalidParams;

    static auto  kExtensionError;

    static auto  kExtensionErrorMax;

    static auto  kExtensionErrorMin;

    static auto  invalidParams;

    static auto  extensionError;

    static auto  extensionErrorMax;

    static auto  extensionErrorMin;


    virtual void  result(String result);

    virtual void  error(int errorCode, String errorDetail);

    virtual bool isError();

private:

    static String _errorCodeMessage(int errorCode);

    static void  _validateErrorCode(int errorCode);

    virtual String _toString();

};
using ServiceExtensionResponse = std::shared_ptr<ServiceExtensionResponseCls>;
void registerExtension(String method, ServiceExtensionHandler handler);

bool extensionStreamHasListener();
void postEvent(String eventKind, Map<any, any> eventData);

void _postEvent(String eventKind, String eventData);
ServiceExtensionHandler _lookupExtension(String method);
void  _registerExtension(String method, ServiceExtensionHandler handler);


#endif