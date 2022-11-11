#include "message_codecs.hpp"
ByteData BinaryCodecCls::decodeMessage(ByteData message) {
    return message;
}

ByteData BinaryCodecCls::encodeMessage(ByteData message) {
    return message;
}

String StringCodecCls::decodeMessage(ByteData message) {
    if (message == nullptr) {
        return nullptr;
    }
    return utf8->decoder->convert(message->buffer->asUint8List(message->offsetInBytes, message->lengthInBytes));
}

ByteData StringCodecCls::encodeMessage(String message) {
    if (message == nullptr) {
        return nullptr;
    }
    Uint8List encoded = utf8->encoder->convert(message);
    return encoded->buffer->asByteData();
}

ByteData JSONMessageCodecCls::encodeMessage(Object message) {
    if (message == nullptr) {
        return nullptr;
    }
    return make<StringCodecCls>()->encodeMessage(json->encode(message));
}

dynamic JSONMessageCodecCls::decodeMessage(ByteData message) {
    if (message == nullptr) {
        return message;
    }
    return json->decode(make<StringCodecCls>()->decodeMessage(message)!);
}

ByteData JSONMethodCodecCls::encodeMethodCall(MethodCall methodCall) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("method"), methodCall->method);map1.set(__s("args"), methodCall->arguments);return make<JSONMessageCodecCls>()->encodeMessage(list1)!;
}

MethodCall JSONMethodCodecCls::decodeMethodCall(ByteData methodCall) {
    Object decoded = make<JSONMessageCodecCls>()->decodeMessage(methodCall);
    if (!is<Map>(decoded)) {
        throw make<FormatExceptionCls>(__s("Expected method call Map, got $decoded"));
    }
    Object method = decoded[__s("method")];
    Object arguments = decoded[__s("args")];
    if (is<String>(method)) {
        return make<MethodCallCls>(as<StringCls>(method), arguments);
    }
    throw make<FormatExceptionCls>(__s("Invalid method call: $decoded"));
}

dynamic JSONMethodCodecCls::decodeEnvelope(ByteData envelope) {
    Object decoded = make<JSONMessageCodecCls>()->decodeMessage(envelope);
    if (!is<List>(decoded)) {
        throw make<FormatExceptionCls>(__s("Expected envelope List, got $decoded"));
    }
    if (decoded->length == 1) {
        return decoded[0];
    }
    if (decoded->length == 3 && is<String>(decoded[0]) && (decoded[1] == nullptr || is<String>(decoded[1]))) {
        throw make<PlatformExceptionCls>(as<String>(decoded[0]), as<String>(decoded[1]), decoded[2]);
    }
    if (decoded->length == 4 && is<String>(decoded[0]) && (decoded[1] == nullptr || is<String>(decoded[1])) && (decoded[3] == nullptr || is<String>(decoded[3]))) {
        throw make<PlatformExceptionCls>(as<String>(decoded[0]), as<String>(decoded[1]), decoded[2], as<String>(decoded[3]));
    }
    throw make<FormatExceptionCls>(__s("Invalid envelope: $decoded"));
}

ByteData JSONMethodCodecCls::encodeSuccessEnvelope(Object result) {
    return make<JSONMessageCodecCls>()->encodeMessage(makeList(ArrayItem))!;
}

ByteData JSONMethodCodecCls::encodeErrorEnvelope(String code, Object details, String message) {
    assert(code != nullptr);
    return make<JSONMessageCodecCls>()->encodeMessage(makeList(ArrayItem, ArrayItem, ArrayItem))!;
}

ByteData StandardMessageCodecCls::encodeMessage(Object message) {
    if (message == nullptr) {
        return nullptr;
    }
    WriteBuffer buffer = make<WriteBufferCls>(_writeBufferStartCapacity);
    writeValue(buffer, message);
    return buffer->done();
}

dynamic StandardMessageCodecCls::decodeMessage(ByteData message) {
    if (message == nullptr) {
        return nullptr;
    }
    ReadBuffer buffer = make<ReadBufferCls>(message);
    Object result = readValue(buffer);
    if (buffer->hasRemaining()) {
        throw make<FormatExceptionCls>(__s("Message corrupted"));
    }
    return result;
}

void StandardMessageCodecCls::writeValue(WriteBuffer buffer, Object value) {
    if (value == nullptr) {
        buffer->putUint8(_valueNull);
    } else     {
        if (is<bool>(value)) {
        buffer->putUint8(as<boolCls>(value)? _valueTrue : _valueFalse);
    } else     {
        if (is<double>(value)) {
        buffer->putUint8(_valueFloat64);
        buffer->putFloat64(as<doubleCls>(value));
    } else     {
        if (is<int>(value)) {
        if (-0x7fffffff - 1 <= as<intCls>(value) && as<intCls>(value) <= 0x7fffffff) {
            buffer->putUint8(_valueInt32);
            buffer->putInt32(value);
        } else {
            buffer->putUint8(_valueInt64);
            buffer->putInt64(value);
        }
    } else     {
        if (is<String>(value)) {
        buffer->putUint8(_valueString);
        Uint8List asciiBytes = make<Uint8ListCls>(as<StringCls>(value)->length());
        Uint8List utf8Bytes;
        int utf8Offset = 0;
        for (;  < as<StringCls>(value)->length(); i += 1) {
            int char = value->codeUnitAt(i);
            if (charValue <= 0x7f) {
                asciiBytes[i] = charValue;
            } else {
                utf8Bytes = utf8->encoder->convert(value->substring(i));
                utf8Offset = i;
                break;
            }
        }
        if (utf8Bytes != nullptr) {
            writeSize(buffer, utf8Offset + utf8Bytes->length);
            buffer->putUint8List(Uint8ListCls->sublistView(asciiBytes, 0, utf8Offset));
            buffer->putUint8List(utf8Bytes);
        } else {
            writeSize(buffer, asciiBytes->length);
            buffer->putUint8List(asciiBytes);
        }
    } else     {
        if (is<Uint8List>(value)) {
        buffer->putUint8(_valueUint8List);
        writeSize(buffer, as<Uint8ListCls>(value)->length);
        buffer->putUint8List(as<Uint8ListCls>(value));
    } else     {
        if (is<Int32List>(value)) {
        buffer->putUint8(_valueInt32List);
        writeSize(buffer, as<Int32ListCls>(value)->length);
        buffer->putInt32List(as<Int32ListCls>(value));
    } else     {
        if (is<Int64List>(value)) {
        buffer->putUint8(_valueInt64List);
        writeSize(buffer, as<Int64ListCls>(value)->length);
        buffer->putInt64List(as<Int64ListCls>(value));
    } else     {
        if (is<Float32List>(value)) {
        buffer->putUint8(_valueFloat32List);
        writeSize(buffer, as<Float32ListCls>(value)->length);
        buffer->putFloat32List(as<Float32ListCls>(value));
    } else     {
        if (is<Float64List>(value)) {
        buffer->putUint8(_valueFloat64List);
        writeSize(buffer, as<Float64ListCls>(value)->length);
        buffer->putFloat64List(as<Float64ListCls>(value));
    } else     {
        if (is<List>(value)) {
        buffer->putUint8(_valueList);
        writeSize(buffer, as<ListCls>(value)->length());
        for (Object item : as<ListCls>(value)) {
            writeValue(buffer, item);
        }
    } else     {
        if (is<Map>(value)) {
        buffer->putUint8(_valueMap);
        writeSize(buffer, as<MapCls>(value)->length());
        as<MapCls>(value)->forEach([=] (Object key,Object value) {
            writeValue(buffer, key);
            writeValue(buffer, value);
        });
    } else {
        throw ArgumentErrorCls->value(value);
    }
;
    };
    };
    };
    };
    };
    };
    };
    };
    };
    };
    }}

Object StandardMessageCodecCls::readValue(ReadBuffer buffer) {
    if (!buffer->hasRemaining()) {
        throw make<FormatExceptionCls>(__s("Message corrupted"));
    }
    int type = buffer->getUint8();
    return readValueOfType(type, buffer);
}

Object StandardMessageCodecCls::readValueOfType(int type, ReadBuffer buffer) {
    ;
}

void StandardMessageCodecCls::writeSize(WriteBuffer buffer, int value) {
    assert(0 <= value && value <= 0xffffffff);
    if ( < 254) {
        buffer->putUint8(value);
    } else     {
        if (value <= 0xffff) {
        buffer->putUint8(254);
        buffer->putUint16(value);
    } else {
        buffer->putUint8(255);
        buffer->putUint32(value);
    }
;
    }}

int StandardMessageCodecCls::readSize(ReadBuffer buffer) {
    int value = buffer->getUint8();
    ;
}

ByteData StandardMethodCodecCls::encodeMethodCall(MethodCall methodCall) {
    WriteBuffer buffer = make<WriteBufferCls>(_writeBufferStartCapacity);
    messageCodec->writeValue(buffer, methodCall->method);
    messageCodec->writeValue(buffer, methodCall->arguments);
    return buffer->done();
}

MethodCall StandardMethodCodecCls::decodeMethodCall(ByteData methodCall) {
    ReadBuffer buffer = make<ReadBufferCls>(methodCall!);
    Object method = messageCodec->readValue(buffer);
    Object arguments = messageCodec->readValue(buffer);
    if (is<String>(method) && !buffer->hasRemaining()) {
        return make<MethodCallCls>(method, arguments);
    } else {
        throw make<FormatExceptionCls>(__s("Invalid method call"));
    }
}

ByteData StandardMethodCodecCls::encodeSuccessEnvelope(Object result) {
    WriteBuffer buffer = make<WriteBufferCls>(_writeBufferStartCapacity);
    buffer->putUint8(0);
    messageCodec->writeValue(buffer, result);
    return buffer->done();
}

ByteData StandardMethodCodecCls::encodeErrorEnvelope(String code, Object details, String message) {
    WriteBuffer buffer = make<WriteBufferCls>(_writeBufferStartCapacity);
    buffer->putUint8(1);
    messageCodec->writeValue(buffer, code);
    messageCodec->writeValue(buffer, message);
    messageCodec->writeValue(buffer, details);
    return buffer->done();
}

dynamic StandardMethodCodecCls::decodeEnvelope(ByteData envelope) {
    if (envelope->lengthInBytes == 0) {
        throw make<FormatExceptionCls>(__s("Expected envelope, got nothing"));
    }
    ReadBuffer buffer = make<ReadBufferCls>(envelope);
    if (buffer->getUint8() == 0) {
        return messageCodec->readValue(buffer);
    }
    Object errorCode = messageCodec->readValue(buffer);
    Object errorMessage = messageCodec->readValue(buffer);
    Object errorDetails = messageCodec->readValue(buffer);
    String errorStacktrace = (buffer->hasRemaining())? as<String>(messageCodec->readValue(buffer)) : nullptr;
    if (is<String>(errorCode) && (errorMessage == nullptr || is<String>(errorMessage)) && !buffer->hasRemaining()) {
        throw make<PlatformExceptionCls>(errorCode, as<String>(errorMessage), errorDetails, errorStacktrace);
    } else {
        throw make<FormatExceptionCls>(__s("Invalid envelope"));
    }
}
