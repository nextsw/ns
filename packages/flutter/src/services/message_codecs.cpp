#include "message_codecs.hpp"
ByteData BinaryCodec::decodeMessage(ByteData message) {
    return message;
}

ByteData BinaryCodec::encodeMessage(ByteData message) {
    return message;
}

String StringCodec::decodeMessage(ByteData message) {
    if (message == nullptr) {
        return nullptr;
    }
    return utf8.decoder.convert(message.buffer.asUint8List(message.offsetInBytes, message.lengthInBytes));
}

ByteData StringCodec::encodeMessage(String message) {
    if (message == nullptr) {
        return nullptr;
    }
    Uint8List encoded = utf8.encoder.convert(message);
    return encoded.buffer.asByteData();
}

ByteData JSONMessageCodec::encodeMessage(Object message) {
    if (message == nullptr) {
        return nullptr;
    }
    return const StringCodec().encodeMessage(json.encode(message));
}

dynamic JSONMessageCodec::decodeMessage(ByteData message) {
    if (message == nullptr) {
        return message;
    }
    return json.decode(const StringCodec().decodeMessage(message)!);
}

ByteData JSONMethodCodec::encodeMethodCall(MethodCall methodCall) {
    return const JSONMessageCodec().encodeMessage()!;
}

MethodCall JSONMethodCodec::decodeMethodCall(ByteData methodCall) {
    Object decoded = const JSONMessageCodec().decodeMessage(methodCall);
    if (decoded is! Map) {
        ;
    }
    Object method = decoded["method"];
    Object arguments = decoded["args"];
    if (method is String) {
        return MethodCall(method, arguments);
    }
    ;
}

dynamic JSONMethodCodec::decodeEnvelope(ByteData envelope) {
    Object decoded = const JSONMessageCodec().decodeMessage(envelope);
    if (decoded is! List) {
        ;
    }
    if (decoded.length == 1) {
        return decoded[0];
    }
    if (decoded.length == 3 && decoded[0] is String && (decoded[1] == nullptr || decoded[1] is String)) {
        ;
    }
    if (decoded.length == 4 && decoded[0] is String && (decoded[1] == nullptr || decoded[1] is String) && (decoded[3] == nullptr || decoded[3] is String)) {
        ;
    }
    ;
}

ByteData JSONMethodCodec::encodeSuccessEnvelope(Object result) {
    return const JSONMessageCodec().encodeMessage()!;
}

ByteData JSONMethodCodec::encodeErrorEnvelope(String code, Object details, String message) {
    assert(code != nullptr);
    return const JSONMessageCodec().encodeMessage()!;
}

ByteData StandardMessageCodec::encodeMessage(Object message) {
    if (message == nullptr) {
        return nullptr;
    }
    WriteBuffer buffer = WriteBuffer(_writeBufferStartCapacity);
    writeValue(buffer, message);
    return buffer.done();
}

dynamic StandardMessageCodec::decodeMessage(ByteData message) {
    if (message == nullptr) {
        return nullptr;
    }
    ReadBuffer buffer = ReadBuffer(message);
    Object result = readValue(buffer);
    if (buffer.hasRemaining) {
        ;
    }
    return result;
}

void StandardMessageCodec::writeValue(WriteBuffer buffer, Object value) {
    if (value == nullptr) {
        buffer.putUint8(_valueNull);
    } else     {
        if (value is bool) {
        buffer.putUint8(value? _valueTrue : _valueFalse);
    } else     {
        if (value is double) {
        buffer.putUint8(_valueFloat64);
        buffer.putFloat64(value);
    } else     {
        if (value is int) {
        if (-0x7fffffff - 1 <= value && value <= 0x7fffffff) {
            buffer.putUint8(_valueInt32);
            buffer.putInt32(value);
        } else {
            buffer.putUint8(_valueInt64);
            buffer.putInt64(value);
        }
    } else     {
        if (value is String) {
        buffer.putUint8(_valueString);
        Uint8List asciiBytes = Uint8List(value.length);
        Uint8List utf8Bytes;
        int utf8Offset = 0;
        for (;  < value.length; i = 1) {
            int char = value.codeUnitAt(i);
            if (char <= 0x7f) {
                asciiBytes[i] = char;
            } else {
                utf8Bytes = utf8.encoder.convert(value.substring(i));
                utf8Offset = i;
                                break;
            }
        }
        if (utf8Bytes != nullptr) {
            writeSize(buffer, utf8Offset + utf8Bytes.length);
            buffer.putUint8List(Uint8List.sublistView(asciiBytes, 0, utf8Offset));
            buffer.putUint8List(utf8Bytes);
        } else {
            writeSize(buffer, asciiBytes.length);
            buffer.putUint8List(asciiBytes);
        }
    } else     {
        if (value is Uint8List) {
        buffer.putUint8(_valueUint8List);
        writeSize(buffer, value.length);
        buffer.putUint8List(value);
    } else     {
        if (value is Int32List) {
        buffer.putUint8(_valueInt32List);
        writeSize(buffer, value.length);
        buffer.putInt32List(value);
    } else     {
        if (value is Int64List) {
        buffer.putUint8(_valueInt64List);
        writeSize(buffer, value.length);
        buffer.putInt64List(value);
    } else     {
        if (value is Float32List) {
        buffer.putUint8(_valueFloat32List);
        writeSize(buffer, value.length);
        buffer.putFloat32List(value);
    } else     {
        if (value is Float64List) {
        buffer.putUint8(_valueFloat64List);
        writeSize(buffer, value.length);
        buffer.putFloat64List(value);
    } else     {
        if (value is List) {
        buffer.putUint8(_valueList);
        writeSize(buffer, value.length);
        for (Object item : value) {
            writeValue(buffer, item);
        }
    } else     {
        if (value is Map) {
        buffer.putUint8(_valueMap);
        writeSize(buffer, value.length);
        value.forEach();
    } else {
        ;
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

Object StandardMessageCodec::readValue(ReadBuffer buffer) {
    if (!buffer.hasRemaining) {
        ;
    }
    int type = buffer.getUint8();
    return readValueOfType(type, buffer);
}

Object StandardMessageCodec::readValueOfType(ReadBuffer buffer, int type) {
    ;
}

void StandardMessageCodec::writeSize(WriteBuffer buffer, int value) {
    assert(0 <= value && value <= 0xffffffff);
    if ( < 254) {
        buffer.putUint8(value);
    } else     {
        if (value <= 0xffff) {
        buffer.putUint8(254);
        buffer.putUint16(value);
    } else {
        buffer.putUint8(255);
        buffer.putUint32(value);
    }
;
    }}

int StandardMessageCodec::readSize(ReadBuffer buffer) {
    int value = buffer.getUint8();
    ;
}

ByteData StandardMethodCodec::encodeMethodCall(MethodCall methodCall) {
    WriteBuffer buffer = WriteBuffer(_writeBufferStartCapacity);
    messageCodec.writeValue(buffer, methodCall.method);
    messageCodec.writeValue(buffer, methodCall.arguments);
    return buffer.done();
}

MethodCall StandardMethodCodec::decodeMethodCall(ByteData methodCall) {
    ReadBuffer buffer = ReadBuffer(methodCall!);
    Object method = messageCodec.readValue(buffer);
    Object arguments = messageCodec.readValue(buffer);
    if (method is String && !buffer.hasRemaining) {
        return MethodCall(method, arguments);
    } else {
        ;
    }
}

ByteData StandardMethodCodec::encodeSuccessEnvelope(Object result) {
    WriteBuffer buffer = WriteBuffer(_writeBufferStartCapacity);
    buffer.putUint8(0);
    messageCodec.writeValue(buffer, result);
    return buffer.done();
}

ByteData StandardMethodCodec::encodeErrorEnvelope(String code, Object details, String message) {
    WriteBuffer buffer = WriteBuffer(_writeBufferStartCapacity);
    buffer.putUint8(1);
    messageCodec.writeValue(buffer, code);
    messageCodec.writeValue(buffer, message);
    messageCodec.writeValue(buffer, details);
    return buffer.done();
}

dynamic StandardMethodCodec::decodeEnvelope(ByteData envelope) {
    if (envelope.lengthInBytes == 0) {
        ;
    }
    ReadBuffer buffer = ReadBuffer(envelope);
    if (buffer.getUint8() == 0) {
        return messageCodec.readValue(buffer);
    }
    Object errorCode = messageCodec.readValue(buffer);
    Object errorMessage = messageCodec.readValue(buffer);
    Object errorDetails = messageCodec.readValue(buffer);
    String errorStacktrace = (buffer.hasRemaining)? ( : nullptr;
    if (errorCode is String && (errorMessage == nullptr || errorMessage is String) && !buffer.hasRemaining) {
        ;
    } else {
        ;
    }
}
