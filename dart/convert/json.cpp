#include "json.hpp"
String JsonUnsupportedObjectError::toString() {
    auto safeString = Error.safeToString(unsupportedObject);
    String prefix;
    if (cause != nullptr) {
        prefix = "Converting object to an encodable object failed:";
    } else {
        prefix = "Converting object did not return an encodable object:";
    }
    return "$prefix $safeString";
}

JsonCyclicError::JsonCyclicError(Object object) {
    {
        super(object);
    }
}

String JsonCyclicError::toString() {
    return "Cyclic error in JSON stringify";
}

String jsonEncode(Object object, FunctionType toEncodable) {
    return json.encode(objecttoEncodable);
}

dynamic jsonDecode(FunctionType reviver, String source) {
    return json.decode(sourcereviver);
}

JsonCodec::JsonCodec(FunctionType reviver, FunctionType toEncodable) {
    {
        _reviver = reviver;
        _toEncodable = toEncodable;
    }
}

void JsonCodec::withReviver(FunctionType reviver)

dynamic JsonCodec::decode(FunctionType reviver, String source) {
    reviver = _reviver;
    if (reviver == nullptr)     {
        return decoder.convert(source);
    }
    return JsonDecoder(reviver).convert(source);
}

String JsonCodec::encode(FunctionType toEncodable, Object value) {
    toEncodable = _toEncodable;
    if (toEncodable == nullptr)     {
        return encoder.convert(value);
    }
    return JsonEncoder(toEncodable).convert(value);
}

JsonEncoder JsonCodec::encoder() {
    if (_toEncodable == nullptr)     {
        return const JsonEncoder();
    }
    return JsonEncoder(_toEncodable);
}

JsonDecoder JsonCodec::decoder() {
    if (_reviver == nullptr)     {
        return const JsonDecoder();
    }
    return JsonDecoder(_reviver);
}

JsonEncoder::JsonEncoder(FunctionType toEncodable) {
    {
        indent = nullptr;
        _toEncodable = toEncodable;
    }
}

void JsonEncoder::withIndent(String indent, FunctionType toEncodable)

String JsonEncoder::convert(Object object) {
    return _JsonStringStringifier.stringify(object, _toEncodable, indent);
}

ChunkedConversionSink<Object> JsonEncoder::startChunkedConversion(Sink<String> sink) {
    if (sink is _Utf8EncoderSink) {
        return _JsonUtf8EncoderSink(sink._sink, _toEncodable, JsonUtf8Encoder._utf8Encode(indent), JsonUtf8Encoder._defaultBufferSize);
    }
    return _JsonEncoderSink(sink is StringConversionSink? sink : StringConversionSink.from(sink), _toEncodable, indent);
}

Stream<String> JsonEncoder::bind(Stream<Object> stream) {
    return super.bind(stream);
}

Converter<Object, T> JsonEncoder::fuse<T>(Converter<String, T> other) {
    if (other is Utf8Encoder) {
        return (;
    }
    return super.<T>fuse(other);
}

JsonUtf8Encoder::JsonUtf8Encoder(int bufferSize, String indent, FunctionType toEncodable) {
    {
        _indent = _utf8Encode(indent);
        _toEncodable = toEncodable;
        _bufferSize = bufferSize ?? _defaultBufferSize;
    }
}

List<int> JsonUtf8Encoder::convert(Object object) {
    auto bytes = ;
    ;
    _JsonUtf8Stringifier.stringify(object, _indent, _toEncodable, _bufferSize, addChunk);
    if (bytes.length == 1)     {
        return bytes[0];
    }
    auto length = 0;
    for (;  < bytes.length; i++) {
        length = bytes[i].length;
    }
    auto result = Uint8List(length);
    for (;  < bytes.length; i++) {
        auto byteList = bytes[i];
        int end = offset + byteList.length;
        result.setRange(offset, end, byteList);
        offset = end;
    }
    return result;
}

ChunkedConversionSink<Object> JsonUtf8Encoder::startChunkedConversion(Sink<List<int>> sink) {
    ByteConversionSink byteSink;
    if (sink is ByteConversionSink) {
        byteSink = sink;
    } else {
        byteSink = ByteConversionSink.from(sink);
    }
    return _JsonUtf8EncoderSink(byteSink, _toEncodable, _indent, _bufferSize);
}

Stream<List<int>> JsonUtf8Encoder::bind(Stream<Object> stream) {
    return super.bind(stream);
}

List<int> JsonUtf8Encoder::_utf8Encode(String string) {
    if (string == nullptr)     {
        return nullptr;
    }
    if (string.isEmpty)     {
        return Uint8List(0);
    }
    ;
    {
        for (;  < string.length; i++) {
            if (string.codeUnitAt(i) >= 0x80)             {
                            break checkAscii;
            }
        }
        return string.codeUnits;
    }    return utf8.encode(string);
}

void _JsonEncoderSink::add(Object o) {
    if (_isDone) {
        ;
    }
    _isDone = true;
    auto stringSink = _sink.asStringSink();
    _JsonStringStringifier.printOn(o, stringSink, _toEncodable, _indent);
    stringSink.close();
}

void _JsonEncoderSink::close() {
}

void _JsonUtf8EncoderSink::add(Object object) {
    if (_isDone) {
        ;
    }
    _isDone = true;
    _JsonUtf8Stringifier.stringify(object, _indent, _toEncodable, _bufferSize, _addChunk);
    _sink.close();
}

void _JsonUtf8EncoderSink::close() {
    if (!_isDone) {
        _isDone = true;
        _sink.close();
    }
}

void _JsonUtf8EncoderSink::_addChunk(Uint8List chunk, int end, int start) {
    _sink.addSlice(chunk, start, end, false);
}

JsonDecoder::JsonDecoder(FunctionType reviver) {
    {
        _reviver = reviver;
    }
}

dynamic JsonDecoder::convert(String input) {
    return _parseJson(input, _reviver);
}

Stream<Object> JsonDecoder::bind(Stream<String> stream) {
    return super.bind(stream);
}

dynamic _defaultToEncodable(dynamic object) {
    return object.toJson();
}

int _JsonStringifier::hexDigit(int x) {
    return  < 10? 48 + x : 87 + x;
}

void _JsonStringifier::writeStringContent(String s) {
    auto offset = 0;
    Unknown length = s.length;
    for (;  < length; i++) {
        auto charCode = s.codeUnitAt(i);
        if (charCode > backslash) {
            if (charCode >= surrogateMin) {
                if (((charCode & surrogateMask) == surrogateLead && !(i + 1 < length && (s.codeUnitAt(i + 1) & surrogateMask) == surrogateTrail)) || ((charCode & surrogateMask) == surrogateTrail && !(i - 1 >= 0 && (s.codeUnitAt(i - 1) & surrogateMask) == surrogateLead))) {
                    if (i > offset)                     {
                        writeStringSlice(s, offset, i);
                    }
                    offset = i + 1;
                    writeCharCode(backslash);
                    writeCharCode(char_u);
                    writeCharCode(char_d);
                    writeCharCode(hexDigit((charCode >> 8) & 0xf));
                    writeCharCode(hexDigit((charCode >> 4) & 0xf));
                    writeCharCode(hexDigit(charCode & 0xf));
                }
            }
            continue;
        }
        if ( < 32) {
            if (i > offset)             {
                writeStringSlice(s, offset, i);
            }
            offset = i + 1;
            writeCharCode(backslash);
            ;
        } else         {
            if (charCode == quote || charCode == backslash) {
            if (i > offset)             {
                writeStringSlice(s, offset, i);
            }
            offset = i + 1;
            writeCharCode(backslash);
            writeCharCode(charCode);
        }
;
        }    }
    if (offset == 0) {
        writeString(s);
    } else     {
        if ( < length) {
        writeStringSlice(s, offset, length);
    }
;
    }}

void _JsonStringifier::writeObject(Object object) {
    if (writeJsonValue(object))     {
        return;
    }
    _checkCycle(object);
    ;
}

bool _JsonStringifier::writeJsonValue(Object object) {
    if (object is num) {
        if (!object.isFinite)         {
            return false;
        }
        writeNumber(object);
        return true;
    } else     {
        if (identical(object, true)) {
        writeString("true");
        return true;
    } else     {
        if (identical(object, false)) {
        writeString("false");
        return true;
    } else     {
        if (object == nullptr) {
        writeString("null");
        return true;
    } else     {
        if (object is String) {
        writeString(""");
        writeStringContent(object);
        writeString(""");
        return true;
    } else     {
        if (object is List) {
        _checkCycle(object);
        writeList(object);
        _removeSeen(object);
        return true;
    } else     {
        if (object is Map) {
        _checkCycle(object);
        auto success = writeMap(object);
        _removeSeen(object);
        return success;
    } else {
        return false;
    }
;
    };
    };
    };
    };
    };
    }}

void _JsonStringifier::writeList(List<Object> list) {
    writeString("[");
    if (list.isNotEmpty) {
        writeObject(list[0]);
        for (;  < list.length; i++) {
            writeString(",");
            writeObject(list[i]);
        }
    }
    writeString("]");
}

bool _JsonStringifier::writeMap(Map<Object, Object> map) {
    if (map.isEmpty) {
        writeString("{}");
        return true;
    }
    auto keyValueList = <Object>filled(map.length * 2, nullptr);
    auto i = 0;
    auto allStringKeys = true;
    map.forEach();
    if (!allStringKeys)     {
        return false;
    }
    writeString("{");
    auto separator = """;
    for (;  < keyValueList.length; i = 2) {
        writeString(separator);
        separator = ","";
        writeStringContent(();
        writeString("":");
        writeObject(keyValueList[i + 1]);
    }
    writeString("}");
    return true;
}

_JsonStringifier::_JsonStringifier(FunctionType toEncodable) {
    {
        _toEncodable = toEncodable ?? _defaultToEncodable;
    }
}

void _JsonStringifier::_checkCycle(Object object) {
    for (;  < _seen.length; i++) {
        if (identical(object, _seen[i])) {
            ;
        }
    }
    _seen.add(object);
}

void _JsonStringifier::_removeSeen(Object object) {
    assert(_seen.isNotEmpty);
    assert(identical(_seen.last, object));
    _seen.removeLast();
}

void _JsonPrettyPrintMixin::writeList(List<Object> list) {
    if (list.isEmpty) {
        writeString("[]");
    } else {
        writeString("[\n");
        _indentLevel++;
        writeIndentation(_indentLevel);
        writeObject(list[0]);
        for (;  < list.length; i++) {
            writeString(",\n");
            writeIndentation(_indentLevel);
            writeObject(list[i]);
        }
        writeString("\n");
        _indentLevel--;
        writeIndentation(_indentLevel);
        writeString("]");
    }
}

bool _JsonPrettyPrintMixin::writeMap(Map<Object, Object> map) {
    if (map.isEmpty) {
        writeString("{}");
        return true;
    }
    auto keyValueList = <Object>filled(map.length * 2, nullptr);
    auto i = 0;
    auto allStringKeys = true;
    map.forEach();
    if (!allStringKeys)     {
        return false;
    }
    writeString("{\n");
    _indentLevel++;
    auto separator = "";
    for (;  < keyValueList.length; i = 2) {
        writeString(separator);
        separator = ",\n";
        writeIndentation(_indentLevel);
        writeString(""");
        writeStringContent(();
        writeString("": ");
        writeObject(keyValueList[i + 1]);
    }
    writeString("\n");
    _indentLevel--;
    writeIndentation(_indentLevel);
    writeString("}");
    return true;
}

String _JsonStringStringifier::stringify(String indent, Object object, FunctionType toEncodable) {
    auto output = StringBuffer();
    printOn(object, output, toEncodable, indent);
    return output.toString();
}

void _JsonStringStringifier::printOn(String indent, Object object, StringSink output, FunctionType toEncodable) {
    _JsonStringifier stringifier;
    if (indent == nullptr) {
        stringifier = _JsonStringStringifier(output, toEncodable);
    } else {
        stringifier = _JsonStringStringifierPretty(output, toEncodable, indent);
    }
    stringifier.writeObject(object);
}

void _JsonStringStringifier::writeNumber(num number) {
    _sink.write(number.toString());
}

void _JsonStringStringifier::writeString(String string) {
    _sink.write(string);
}

void _JsonStringStringifier::writeStringSlice(int end, int start, String string) {
    _sink.write(string.substring(start, end));
}

void _JsonStringStringifier::writeCharCode(int charCode) {
    _sink.writeCharCode(charCode);
}

_JsonStringStringifier::_JsonStringStringifier(StringSink _sink, FunctionType _toEncodable) {
    {
        super(_toEncodable);
    }
}

String _JsonStringStringifier::_partialResult() {
    return _sink is StringBuffer? _sink.toString() : nullptr;
}

void _JsonStringStringifierPretty::writeIndentation(int count) {
    for (;  < count; i++)     {
        writeString(_indent);
    }
}

_JsonStringStringifierPretty::_JsonStringStringifierPretty(String _indent, StringSink sink, FunctionType toEncodable) {
    {
        super(sink, toEncodable);
    }
}

void _JsonUtf8Stringifier::stringify(FunctionType addChunk, int bufferSize, List<int> indent, Object object, FunctionType toEncodable) {
    _JsonUtf8Stringifier stringifier;
    if (indent != nullptr) {
        stringifier = _JsonUtf8StringifierPretty(toEncodable, indent, bufferSize, addChunk);
    } else {
        stringifier = _JsonUtf8Stringifier(toEncodable, bufferSize, addChunk);
    }
    stringifier.writeObject(object);
    stringifier.flush();
}

void _JsonUtf8Stringifier::flush() {
    if (index > 0) {
        addChunk(buffer, 0, index);
    }
    buffer = Uint8List(0);
    index = 0;
}

void _JsonUtf8Stringifier::writeNumber(num number) {
    writeAsciiString(number.toString());
}

void _JsonUtf8Stringifier::writeAsciiString(String string) {
    for (;  < string.length; i++) {
        auto char = string.codeUnitAt(i);
        assert(char <= 0x7f);
        writeByte(char);
    }
}

void _JsonUtf8Stringifier::writeString(String string) {
    writeStringSlice(string, 0, string.length);
}

void _JsonUtf8Stringifier::writeStringSlice(int end, int start, String string) {
    for (;  < end; i++) {
        auto char = string.codeUnitAt(i);
        if (char <= 0x7f) {
            writeByte(char);
        } else {
            if ((char & 0xF800) == 0xD800) {
                if ( < 0xDC00 && i + 1 < end) {
                    auto nextChar = string.codeUnitAt(i + 1);
                    if ((nextChar & 0xFC00) == 0xDC00) {
                        char = 0x10000 + ((char & 0x3ff) << 10) + (nextChar & 0x3ff);
                        writeFourByteCharCode(char);
                        i++;
                        continue;
                    }
                }
                writeMultiByteCharCode(unicodeReplacementCharacterRune);
                continue;
            }
            writeMultiByteCharCode(char);
        }
    }
}

void _JsonUtf8Stringifier::writeCharCode(int charCode) {
    if (charCode <= 0x7f) {
        writeByte(charCode);
        return;
    }
    writeMultiByteCharCode(charCode);
}

void _JsonUtf8Stringifier::writeMultiByteCharCode(int charCode) {
    if (charCode <= 0x7ff) {
        writeByte(0xC0 | (charCode >> 6));
        writeByte(0x80 | (charCode & 0x3f));
        return;
    }
    if (charCode <= 0xffff) {
        writeByte(0xE0 | (charCode >> 12));
        writeByte(0x80 | ((charCode >> 6) & 0x3f));
        writeByte(0x80 | (charCode & 0x3f));
        return;
    }
    writeFourByteCharCode(charCode);
}

void _JsonUtf8Stringifier::writeFourByteCharCode(int charCode) {
    assert(charCode <= 0x10ffff);
    writeByte(0xF0 | (charCode >> 18));
    writeByte(0x80 | ((charCode >> 12) & 0x3f));
    writeByte(0x80 | ((charCode >> 6) & 0x3f));
    writeByte(0x80 | (charCode & 0x3f));
}

void _JsonUtf8Stringifier::writeByte(int byte) {
    assert(byte <= 0xff);
    if (index == buffer.length) {
        addChunk(buffer, 0, index);
        buffer = Uint8List(bufferSize);
        index = 0;
    }
    buffer[index++] = byte;
}

_JsonUtf8Stringifier::_JsonUtf8Stringifier(FunctionType addChunk, int bufferSize, FunctionType toEncodable) {
    {
        buffer = Uint8List(bufferSize);
        super(toEncodable);
    }
}

String _JsonUtf8Stringifier::_partialResult() {
    return nullptr;
}

void _JsonUtf8StringifierPretty::writeIndentation(int count) {
    auto indent = this.indent;
    auto indentLength = indent.length;
    if (indentLength == 1) {
        auto char = indent[0];
        while (count > 0) {
            writeByte(char);
            count = 1;
        }
        return;
    }
    while (count > 0) {
        count--;
        auto end = index + indentLength;
        if (end <= buffer.length) {
            buffer.setRange(index, end, indent);
            index = end;
        } else {
            for (;  < indentLength; i++) {
                writeByte(indent[i]);
            }
        }
    }
}

_JsonUtf8StringifierPretty::_JsonUtf8StringifierPretty(FunctionType addChunk, int bufferSize, List<int> indent, FunctionType toEncodable) {
    {
        super(toEncodable, bufferSize, addChunk);
    }
}
