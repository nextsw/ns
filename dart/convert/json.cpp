#include "json.hpp"
String JsonUnsupportedObjectErrorCls::toString() {
    auto safeString = ErrorCls->safeToString(unsupportedObject);
    String prefix;
    if (cause != nullptr) {
        prefix = __s("Converting object to an encodable object failed:");
    } else {
        prefix = __s("Converting object did not return an encodable object:");
    }
    return __sf("%s %s", prefix, safeString);
}

JsonCyclicErrorCls::JsonCyclicErrorCls(Object object) : JsonUnsupportedObjectError(object) {
}

String JsonCyclicErrorCls::toString() {
    return __s("Cyclic error in JSON stringify");
}

String jsonEncode(Object object, std::function<Object(Object nonEncodable)> toEncodable) {
    return json->encode(object, toEncodable);
}

dynamic jsonDecode(String source, std::function<Object(Object key, Object value)> reviver) {
    return json->decode(source, reviver);
}

JsonCodecCls::JsonCodecCls(std::function<Object(Object key, Object value)> reviver, std::function<Object(dynamic object)> toEncodable) {
    {
        _reviver = reviver;
        _toEncodable = toEncodable;
    }
}

void JsonCodecCls::withReviver(std::function<dynamic(Object key, Object value)> reviver)

dynamic JsonCodecCls::decode(String source, std::function<Object(Object key, Object value)> reviver) {
    reviver |= _reviver;
    if (reviver == nullptr) {
        return decoder()->convert(source);
    }
    return make<JsonDecoderCls>(reviver)->convert(source);
}

String JsonCodecCls::encode(Object value, std::function<Object(dynamic object)> toEncodable) {
    toEncodable |= _toEncodable;
    if (toEncodable == nullptr) {
        return encoder()->convert(value);
    }
    return make<JsonEncoderCls>(toEncodable)->convert(value);
}

JsonEncoder JsonCodecCls::encoder() {
    if (_toEncodable == nullptr) {
        return make<JsonEncoderCls>();
    }
    return make<JsonEncoderCls>(_toEncodable);
}

JsonDecoder JsonCodecCls::decoder() {
    if (_reviver == nullptr) {
        return make<JsonDecoderCls>();
    }
    return make<JsonDecoderCls>(_reviver);
}

JsonEncoderCls::JsonEncoderCls(std::function<Object(dynamic object)> toEncodable) {
    {
        indent = nullptr;
        _toEncodable = toEncodable;
    }
}

void JsonEncoderCls::withIndent(String indent, std::function<Object(dynamic object)> toEncodable)

String JsonEncoderCls::convert(Object object) {
    return _JsonStringStringifierCls->stringify(object, _toEncodable, indent);
}

ChunkedConversionSink<Object> JsonEncoderCls::startChunkedConversion(Sink<String> sink) {
    if (is<_Utf8EncoderSink>(sink)) {
        return make<_JsonUtf8EncoderSinkCls>(as<_Utf8EncoderSinkCls>(sink)->_sink, _toEncodable, JsonUtf8EncoderCls->_utf8Encode(indent), JsonUtf8EncoderCls::_defaultBufferSize);
    }
    return make<_JsonEncoderSinkCls>(is<StringConversionSink>(sink)? sink : StringConversionSinkCls->from(sink), _toEncodable, indent);
}

Stream<String> JsonEncoderCls::bind(Stream<Object> stream) {
    return super->bind(stream);
}

template<typename T>
Converter<Object, T> JsonEncoderCls::fuse(Converter<String, T> other) {
    if (is<Utf8Encoder>(other)) {
        return as<Converter<Object, T>>(make<JsonUtf8EncoderCls>(indent, _toEncodable));
    }
    return super-><T>fuse(other);
}

JsonUtf8EncoderCls::JsonUtf8EncoderCls(String indent, std::function<dynamic(dynamic object)> toEncodable, int bufferSize) {
    {
        _indent = _utf8Encode(indent);
        _toEncodable = toEncodable;
        _bufferSize = bufferSize | _defaultBufferSize;
    }
}

List<int> JsonUtf8EncoderCls::convert(Object object) {
    auto bytes = makeList();
    InlineMethod;
    _JsonUtf8StringifierCls->stringify(object, _indent, _toEncodable, _bufferSize, addChunk);
    if (bytes->length() == 1) {
        return bytes[0];
    }
    auto length = 0;
    for (;  < bytes->length; i++) {
        length += bytes[i]->length;
    }
    auto result = make<Uint8ListCls>(length);
    for (;  < bytes->length; i++) {
        auto byteList = bytes[i];
        int end = offset + byteList->length;
        result->setRange(offset, end, byteList);
        offset = end;
    }
    return result;
}

ChunkedConversionSink<Object> JsonUtf8EncoderCls::startChunkedConversion(Sink<List<int>> sink) {
    ByteConversionSink byteSink;
    if (is<ByteConversionSink>(sink)) {
        byteSink = as<ByteConversionSinkCls>(sink);
    } else {
        byteSink = ByteConversionSinkCls->from(sink);
    }
    return make<_JsonUtf8EncoderSinkCls>(byteSink, _toEncodable, _indent, _bufferSize);
}

Stream<List<int>> JsonUtf8EncoderCls::bind(Stream<Object> stream) {
    return super->bind(stream);
}

List<int> JsonUtf8EncoderCls::_utf8Encode(String stringValue) {
    if (stringValue == nullptr) {
        return nullptr;
    }
    if (stringValue->isEmpty()) {
        return make<Uint8ListCls>(0);
    }
    checkAscii:;
    {
        for (;  < stringValue->length(); i++) {
            if (stringValue->codeUnitAt(i) >= 0x80) {
                break checkAscii;
            }
        }
        return stringValue->codeUnits();
    }    return utf8->encode(stringValue);
}

void _JsonEncoderSinkCls::add(Object o) {
    if (_isDone) {
        throw make<StateErrorCls>(__s("Only one call to add allowed"));
    }
    _isDone = true;
    auto stringSink = _sink->asStringSink();
    _JsonStringStringifierCls->printOn(o, stringSink, _toEncodable, _indent);
    stringSink->close();
}

void _JsonEncoderSinkCls::close() {
}

void _JsonUtf8EncoderSinkCls::add(Object object) {
    if (_isDone) {
        throw make<StateErrorCls>(__s("Only one call to add allowed"));
    }
    _isDone = true;
    _JsonUtf8StringifierCls->stringify(object, _indent, _toEncodable, _bufferSize, _addChunk);
    _sink->close();
}

void _JsonUtf8EncoderSinkCls::close() {
    if (!_isDone) {
        _isDone = true;
        _sink->close();
    }
}

void _JsonUtf8EncoderSinkCls::_addChunk(Uint8List chunk, int start, int end) {
    _sink->addSlice(chunk, start, end, false);
}

JsonDecoderCls::JsonDecoderCls(std::function<Object(Object key, Object value)> reviver) {
    {
        _reviver = reviver;
    }
}

dynamic JsonDecoderCls::convert(String input) {
    return _parseJson(input, _reviver);
}

Stream<Object> JsonDecoderCls::bind(Stream<String> stream) {
    return super->bind(stream);
}

dynamic _defaultToEncodable(dynamic object) {
    return object->toJson();
}

int _JsonStringifierCls::hexDigit(int x) {
    return  < 10? 48 + x : 87 + x;
}

void _JsonStringifierCls::writeStringContent(String s) {
    auto offset = 0;
    Unknown length = s->length();
    for (;  < length; i++) {
        auto charCode = s->codeUnitAt(i);
        if (charCode > backslash) {
            if (charCode >= surrogateMin) {
                if (((charCode & surrogateMask) == surrogateLead && !(i + 1 < length && (s->codeUnitAt(i + 1) & surrogateMask) == surrogateTrail)) || ((charCode & surrogateMask) == surrogateTrail && !(i - 1 >= 0 && (s->codeUnitAt(i - 1) & surrogateMask) == surrogateLead))) {
                    if (i > offset) {
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
            if (i > offset) {
                writeStringSlice(s, offset, i);
            }
            offset = i + 1;
            writeCharCode(backslash);
            ;
        } else {
            if (charCode == quote || charCode == backslash) {
            if (i > offset) {
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
    } else {
        if ( < length) {
        writeStringSlice(s, offset, length);
    }
;
    }}

void _JsonStringifierCls::writeObject(Object object) {
    if (writeJsonValue(object)) {
        return;
    }
    _checkCycle(object);
    try {
        auto customJson = _toEncodable(object);
        if (!writeJsonValue(customJson)) {
            throw make<JsonUnsupportedObjectErrorCls>(object, _partialResult());
        }
        _removeSeen(object);
    } catch (Unknown e) {
        throw make<JsonUnsupportedObjectErrorCls>(object, e, _partialResult());
    };
}

bool _JsonStringifierCls::writeJsonValue(Object object) {
    if (is<num>(object)) {
        if (!as<numCls>(object)->isFinite()) {
            return false;
        }
        writeNumber(as<numCls>(object));
        return true;
    } else {
        if (identical(object, true)) {
        writeString(__s("true"));
        return true;
    } else {
        if (identical(object, false)) {
        writeString(__s("false"));
        return true;
    } else {
        if (object == nullptr) {
        writeString(__s("null"));
        return true;
    } else {
        if (is<String>(object)) {
        writeString(__s("""));
        writeStringContent(as<StringCls>(object));
        writeString(__s("""));
        return true;
    } else {
        if (is<List<any>>(object)) {
        _checkCycle(as<ListCls>(object));
        writeList(as<ListCls>(object));
        _removeSeen(as<ListCls>(object));
        return true;
    } else {
        if (is<Map<any, any>>(object)) {
        _checkCycle(as<MapCls>(object));
        auto success = writeMap(as<MapCls>(object));
        _removeSeen(as<MapCls>(object));
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

void _JsonStringifierCls::writeList(List<Object> list) {
    writeString(__s("["));
    if (list->isNotEmpty()) {
        writeObject(list[0]);
        for (;  < list->length(); i++) {
            writeString(__s(","));
            writeObject(list[i]);
        }
    }
    writeString(__s("]"));
}

bool _JsonStringifierCls::writeMap(Map<Object, Object> map) {
    if (map->isEmpty()) {
        writeString(__s("{}"));
        return true;
    }
    auto keyValueList = <Object>filled(map->length() * 2, nullptr);
    auto i = 0;
    auto allStringKeys = true;
    map->forEach([=] (Unknown  key,Unknown  value) {
        if (!is<String>(key)) {
            allStringKeys = false;
        }
        keyValueList[i++] = key;
        keyValueList[i++] = value;
    });
    if (!allStringKeys) {
        return false;
    }
    writeString(__s("{"));
    auto separator = __s(""");
    for (;  < keyValueList->length; i += 2) {
        writeString(separator);
        separator = __s(","");
        writeStringContent(as<String>(keyValueList[i]));
        writeString(__s("":"));
        writeObject(keyValueList[i + 1]);
    }
    writeString(__s("}"));
    return true;
}

_JsonStringifierCls::_JsonStringifierCls(std::function<dynamic(dynamic o)> toEncodable) {
    {
        _toEncodable = toEncodable | _defaultToEncodable;
    }
}

void _JsonStringifierCls::_checkCycle(Object object) {
    for (;  < _seen->length(); i++) {
        if (identical(object, _seen[i])) {
            throw make<JsonCyclicErrorCls>(object);
        }
    }
    _seen->add(object);
}

void _JsonStringifierCls::_removeSeen(Object object) {
    assert(_seen->isNotEmpty());
    assert(identical(_seen->last, object));
    _seen->removeLast();
}

void _JsonPrettyPrintMixinCls::writeList(List<Object> list) {
    if (list->isEmpty()) {
        writeString(__s("[]"));
    } else {
        writeString(__s("[\n"));
        _indentLevel++;
        writeIndentation(_indentLevel);
        writeObject(list[0]);
        for (;  < list->length(); i++) {
            writeString(__s(",\n"));
            writeIndentation(_indentLevel);
            writeObject(list[i]);
        }
        writeString(__s("\n"));
        _indentLevel--;
        writeIndentation(_indentLevel);
        writeString(__s("]"));
    }
}

bool _JsonPrettyPrintMixinCls::writeMap(Map<Object, Object> map) {
    if (map->isEmpty()) {
        writeString(__s("{}"));
        return true;
    }
    auto keyValueList = <Object>filled(map->length() * 2, nullptr);
    auto i = 0;
    auto allStringKeys = true;
    map->forEach([=] (Unknown  key,Unknown  value) {
        if (!is<String>(key)) {
            allStringKeys = false;
        }
        keyValueList[i++] = key;
        keyValueList[i++] = value;
    });
    if (!allStringKeys) {
        return false;
    }
    writeString(__s("{\n"));
    _indentLevel++;
    auto separator = __s("");
    for (;  < keyValueList->length; i += 2) {
        writeString(separator);
        separator = __s(",\n");
        writeIndentation(_indentLevel);
        writeString(__s("""));
        writeStringContent(as<String>(keyValueList[i]));
        writeString(__s("": "));
        writeObject(keyValueList[i + 1]);
    }
    writeString(__s("\n"));
    _indentLevel--;
    writeIndentation(_indentLevel);
    writeString(__s("}"));
    return true;
}

String _JsonStringStringifierCls::stringify(Object object, std::function<dynamic(dynamic object)> toEncodable, String indent) {
    auto output = make<StringBufferCls>();
    printOn(object, output, toEncodable, indent);
    return output->toString();
}

void _JsonStringStringifierCls::printOn(Object object, StringSink output, std::function<dynamic(dynamic o)> toEncodable, String indent) {
    _JsonStringifier stringifier;
    if (indent == nullptr) {
        stringifier = make<_JsonStringStringifierCls>(output, toEncodable);
    } else {
        stringifier = make<_JsonStringStringifierPrettyCls>(output, toEncodable, indent);
    }
    stringifier->writeObject(object);
}

void _JsonStringStringifierCls::writeNumber(num number) {
    _sink->write(number->toString());
}

void _JsonStringStringifierCls::writeString(String stringValue) {
    _sink->write(stringValue);
}

void _JsonStringStringifierCls::writeStringSlice(String stringValue, int start, int end) {
    _sink->write(stringValue->substring(start, end));
}

void _JsonStringStringifierCls::writeCharCode(int charCode) {
    _sink->writeCharCode(charCode);
}

_JsonStringStringifierCls::_JsonStringStringifierCls(StringSink _sink, std::function<dynamic(dynamic object)> _toEncodable) : _JsonStringifier(_toEncodable) {
}

String _JsonStringStringifierCls::_partialResult() {
    return is<StringBuffer>(_sink)? _sink->toString() : nullptr;
}

void _JsonStringStringifierPrettyCls::writeIndentation(int count) {
    for (;  < count; i++) {
        writeString(_indent);
    }
}

_JsonStringStringifierPrettyCls::_JsonStringStringifierPrettyCls(StringSink sink, std::function<dynamic(dynamic o)> toEncodable, String _indent) : _JsonStringStringifier(sink, toEncodable) {
}

void _JsonUtf8StringifierCls::stringify(Object object, List<int> indent, std::function<dynamic(dynamic o)> toEncodable, int bufferSize, std::function<void(Uint8List chunk, int start, int end)> addChunk) {
    _JsonUtf8Stringifier stringifier;
    if (indent != nullptr) {
        stringifier = make<_JsonUtf8StringifierPrettyCls>(toEncodable, indent, bufferSize, addChunk);
    } else {
        stringifier = make<_JsonUtf8StringifierCls>(toEncodable, bufferSize, addChunk);
    }
    stringifier->writeObject(object);
    stringifier->flush();
}

void _JsonUtf8StringifierCls::flush() {
    if (index > 0) {
        addChunk(buffer, 0, index);
    }
    buffer = make<Uint8ListCls>(0);
    index = 0;
}

void _JsonUtf8StringifierCls::writeNumber(num number) {
    writeAsciiString(number->toString());
}

void _JsonUtf8StringifierCls::writeAsciiString(String stringValue) {
    for (;  < stringValue->length(); i++) {
        auto char = stringValue->codeUnitAt(i);
        assert(charValue <= 0x7f);
        writeByte(charValue);
    }
}

void _JsonUtf8StringifierCls::writeString(String stringValue) {
    writeStringSlice(stringValue, 0, stringValue->length());
}

void _JsonUtf8StringifierCls::writeStringSlice(String stringValue, int start, int end) {
    for (;  < end; i++) {
        auto char = stringValue->codeUnitAt(i);
        if (charValue <= 0x7f) {
            writeByte(charValue);
        } else {
            if ((charValue & 0xF800) == 0xD800) {
                if ( < 0xDC00 && i + 1 < end) {
                    auto nextChar = stringValue->codeUnitAt(i + 1);
                    if ((nextChar & 0xFC00) == 0xDC00) {
                        charValue = 0x10000 + ((charValue & 0x3ff) << 10) + (nextChar & 0x3ff);
                        writeFourByteCharCode(charValue);
                        i++;
                        continue;
                    }
                }
                writeMultiByteCharCode(unicodeReplacementCharacterRune);
                continue;
            }
            writeMultiByteCharCode(charValue);
        }
    }
}

void _JsonUtf8StringifierCls::writeCharCode(int charCode) {
    if (charCode <= 0x7f) {
        writeByte(charCode);
        return;
    }
    writeMultiByteCharCode(charCode);
}

void _JsonUtf8StringifierCls::writeMultiByteCharCode(int charCode) {
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

void _JsonUtf8StringifierCls::writeFourByteCharCode(int charCode) {
    assert(charCode <= 0x10ffff);
    writeByte(0xF0 | (charCode >> 18));
    writeByte(0x80 | ((charCode >> 12) & 0x3f));
    writeByte(0x80 | ((charCode >> 6) & 0x3f));
    writeByte(0x80 | (charCode & 0x3f));
}

void _JsonUtf8StringifierCls::writeByte(int byte) {
    assert(byte <= 0xff);
    if (index == buffer->length()) {
        addChunk(buffer, 0, index);
        buffer = make<Uint8ListCls>(bufferSize);
        index = 0;
    }
    buffer[index++] = byte;
}

_JsonUtf8StringifierCls::_JsonUtf8StringifierCls(std::function<dynamic(dynamic o)> toEncodable, int bufferSize, std::function<void(Uint8List list, int start, int end)> addChunk) : _JsonStringifier(toEncodable) {
    {
        buffer = make<Uint8ListCls>(bufferSize);
    }
}

String _JsonUtf8StringifierCls::_partialResult() {
    return nullptr;
}

void _JsonUtf8StringifierPrettyCls::writeIndentation(int count) {
    auto indent = this->indent;
    auto indentLength = indent->length();
    if (indentLength == 1) {
        auto char = indent[0];
        while (count > 0) {
            writeByte(charValue);
            count -= 1;
        }
        return;
    }
    while (count > 0) {
        count--;
        auto end = index + indentLength;
        if (end <= buffer->length()) {
            buffer->setRange(index, end, indent);
            index = end;
        } else {
            for (;  < indentLength; i++) {
                writeByte(indent[i]);
            }
        }
    }
}

_JsonUtf8StringifierPrettyCls::_JsonUtf8StringifierPrettyCls(std::function<dynamic(dynamic o)> toEncodable, List<int> indent, int bufferSize, std::function<void(Uint8List buffer, int start, int end)> addChunk) : _JsonUtf8Stringifier(toEncodable, bufferSize, addChunk) {
}
