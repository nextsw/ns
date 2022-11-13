#ifndef PACKAGES_FLUTTER_SRC_SERVICES_MESSAGE_CODEC
#define PACKAGES_FLUTTER_SRC_SERVICES_MESSAGE_CODEC
#include <base.hpp>
#include <dart/typed_data/typed_data.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "platform_channel.hpp"


template<typename T>
class MessageCodecCls : public ObjectCls {
public:

    virtual ByteData encodeMessage(T message);
    virtual T decodeMessage(ByteData message);
private:

};
template<typename T>
using MessageCodec = std::shared_ptr<MessageCodecCls<T>>;

class MethodCallCls : public ObjectCls {
public:
    String method;

    Object arguments;


     MethodCallCls(String method, Object arguments);

    virtual String toString();

private:

};
using MethodCall = std::shared_ptr<MethodCallCls>;

class MethodCodecCls : public ObjectCls {
public:

    virtual ByteData encodeMethodCall(MethodCall methodCall);
    virtual MethodCall decodeMethodCall(ByteData methodCall);
    virtual Object decodeEnvelope(ByteData envelope);
    virtual ByteData encodeSuccessEnvelope(Object result);
    virtual ByteData encodeErrorEnvelope(String code, Object details, String message);
private:

};
using MethodCodec = std::shared_ptr<MethodCodecCls>;

class PlatformExceptionCls : public ObjectCls {
public:
    String code;

    String message;

    Object details;

    String stacktrace;


     PlatformExceptionCls(String code, Object details, String message, String stacktrace);

    virtual String toString();

private:

};
using PlatformException = std::shared_ptr<PlatformExceptionCls>;

class MissingPluginExceptionCls : public ObjectCls {
public:
    String message;


     MissingPluginExceptionCls(String message);
    virtual String toString();

private:

};
using MissingPluginException = std::shared_ptr<MissingPluginExceptionCls>;


#endif