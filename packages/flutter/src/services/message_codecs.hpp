#ifndef MESSAGE_CODECS_H
#define MESSAGE_CODECS_H
#include <memory>
#include <typed_data.hpp>
#include <flutter/foundation.hpp>
#include "message_codec.hpp"

#include <convert/convert.hpp>
#include <typed_data/typed_data.hpp>
#include <flutter/foundation.hpp>
#include "message_codec.hpp"


const int _writeBufferStartCapacity;


class BinaryCodec {
public:

     BinaryCodec();

    ByteData decodeMessage(ByteData message);

    ByteData encodeMessage(ByteData message);

private:

};

class StringCodec {
public:

     StringCodec();

    String decodeMessage(ByteData message);

    ByteData encodeMessage(String message);

private:

};

class JSONMessageCodec {
public:

     JSONMessageCodec();

    ByteData encodeMessage(Object message);

    dynamic decodeMessage(ByteData message);

private:

};

class JSONMethodCodec {
public:

     JSONMethodCodec();

    ByteData encodeMethodCall(MethodCall methodCall);

    MethodCall decodeMethodCall(ByteData methodCall);

    dynamic decodeEnvelope(ByteData envelope);

    ByteData encodeSuccessEnvelope(Object result);

    ByteData encodeErrorEnvelope(String code, Object details, String message);

private:

};

class StandardMessageCodec {
public:

     StandardMessageCodec();

    ByteData encodeMessage(Object message);

    dynamic decodeMessage(ByteData message);

    void writeValue(WriteBuffer buffer, Object value);

    Object readValue(ReadBuffer buffer);

    Object readValueOfType(ReadBuffer buffer, int type);

    void writeSize(WriteBuffer buffer, int value);

    int readSize(ReadBuffer buffer);

private:
    static const int _valueNull;

    static const int _valueTrue;

    static const int _valueFalse;

    static const int _valueInt32;

    static const int _valueInt64;

    static const int _valueLargeInt;

    static const int _valueFloat64;

    static const int _valueString;

    static const int _valueUint8List;

    static const int _valueInt32List;

    static const int _valueInt64List;

    static const int _valueFloat64List;

    static const int _valueList;

    static const int _valueMap;

    static const int _valueFloat32List;


};

class StandardMethodCodec {
public:
    StandardMessageCodec messageCodec;


     StandardMethodCodec(StandardMessageCodec messageCodec);

    ByteData encodeMethodCall(MethodCall methodCall);

    MethodCall decodeMethodCall(ByteData methodCall);

    ByteData encodeSuccessEnvelope(Object result);

    ByteData encodeErrorEnvelope(String code, Object details, String message);

    dynamic decodeEnvelope(ByteData envelope);

private:

};

#endif