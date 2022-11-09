#ifndef PACKAGES_FLUTTER_SRC_SERVICES_MESSAGE_CODECS
#define PACKAGES_FLUTTER_SRC_SERVICES_MESSAGE_CODECS
#include <base.hpp>
#include <dart/typed_data/typed_data.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "message_codec.hpp"

#include <dart/core/core.hpp>
#include <dart/convert/convert.hpp>
#include <dart/typed_data/typed_data.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "message_codec.hpp"

int _writeBufferStartCapacity;


class BinaryCodecCls : public ObjectCls {
public:

     BinaryCodecCls();
    virtual ByteData decodeMessage(ByteData message);

    virtual ByteData encodeMessage(ByteData message);

private:

};
using BinaryCodec = std::shared_ptr<BinaryCodecCls>;

class StringCodecCls : public ObjectCls {
public:

     StringCodecCls();
    virtual String decodeMessage(ByteData message);

    virtual ByteData encodeMessage(String message);

private:

};
using StringCodec = std::shared_ptr<StringCodecCls>;

class JSONMessageCodecCls : public ObjectCls {
public:

     JSONMessageCodecCls();
    virtual ByteData encodeMessage(Object message);

    virtual dynamic decodeMessage(ByteData message);

private:

};
using JSONMessageCodec = std::shared_ptr<JSONMessageCodecCls>;

class JSONMethodCodecCls : public ObjectCls {
public:

     JSONMethodCodecCls();
    virtual ByteData encodeMethodCall(MethodCall methodCall);

    virtual MethodCall decodeMethodCall(ByteData methodCall);

    virtual dynamic decodeEnvelope(ByteData envelope);

    virtual ByteData encodeSuccessEnvelope(Object result);

    virtual ByteData encodeErrorEnvelope(String code, Object details, String message);

private:

};
using JSONMethodCodec = std::shared_ptr<JSONMethodCodecCls>;

class StandardMessageCodecCls : public ObjectCls {
public:

     StandardMessageCodecCls();
    virtual ByteData encodeMessage(Object message);

    virtual dynamic decodeMessage(ByteData message);

    virtual void writeValue(WriteBuffer buffer, Object value);

    virtual Object readValue(ReadBuffer buffer);

    virtual Object readValueOfType(ReadBuffer buffer, int type);

    virtual void writeSize(WriteBuffer buffer, int value);

    virtual int readSize(ReadBuffer buffer);

private:
    static int _valueNull;

    static int _valueTrue;

    static int _valueFalse;

    static int _valueInt32;

    static int _valueInt64;

    static int _valueLargeInt;

    static int _valueFloat64;

    static int _valueString;

    static int _valueUint8List;

    static int _valueInt32List;

    static int _valueInt64List;

    static int _valueFloat64List;

    static int _valueList;

    static int _valueMap;

    static int _valueFloat32List;


};
using StandardMessageCodec = std::shared_ptr<StandardMessageCodecCls>;

class StandardMethodCodecCls : public ObjectCls {
public:
    StandardMessageCodec messageCodec;


     StandardMethodCodecCls(StandardMessageCodec messageCodec);
    virtual ByteData encodeMethodCall(MethodCall methodCall);

    virtual MethodCall decodeMethodCall(ByteData methodCall);

    virtual ByteData encodeSuccessEnvelope(Object result);

    virtual ByteData encodeErrorEnvelope(String code, Object details, String message);

    virtual dynamic decodeEnvelope(ByteData envelope);

private:

};
using StandardMethodCodec = std::shared_ptr<StandardMethodCodecCls>;


#endif