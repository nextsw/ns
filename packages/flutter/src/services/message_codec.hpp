#ifndef MESSAGE_CODEC_H
#define MESSAGE_CODEC_H
#include <memory>
#include <typed_data.hpp>

#include <flutter/foundation.hpp>
#include "platform_channel.hpp"



class MessageCodec<T> {
public:

    ByteData encodeMessage(T message);

    T decodeMessage(ByteData message);

private:

};

class MethodCall {
public:
    String method;

    dynamic arguments;


     MethodCall(dynamic arguments, String method);

    String toString();

private:

};

class MethodCodec {
public:

    ByteData encodeMethodCall(MethodCall methodCall);

    MethodCall decodeMethodCall(ByteData methodCall);

    dynamic decodeEnvelope(ByteData envelope);

    ByteData encodeSuccessEnvelope(Object result);

    ByteData encodeErrorEnvelope(String code, Object details, String message);

private:

};

class PlatformException {
public:
    String code;

    String message;

    dynamic details;

    String stacktrace;


     PlatformException(String code, dynamic details, String message, String stacktrace);

    String toString();

private:

};

class MissingPluginException {
public:
    String message;


     MissingPluginException(String message);

    String toString();

private:

};

#endif