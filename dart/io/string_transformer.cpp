#include "string_transformer.hpp"
String SystemEncodingCls::name() {
    return __s("system");
}

List<int> SystemEncodingCls::encode(String input) {
    return encoder()->convert(input);
}

String SystemEncodingCls::decode(List<int> encoded) {
    return decoder()->convert(encoded);
}

Converter<String, List<int>> SystemEncodingCls::encoder() {
    if (PlatformCls::operatingSystem == __s("windows")) {
        return make<_WindowsCodePageEncoderCls>();
    } else {
        return make<Utf8EncoderCls>();
    }
}

Converter<List<int>, String> SystemEncodingCls::decoder() {
    if (PlatformCls::operatingSystem == __s("windows")) {
        return make<_WindowsCodePageDecoderCls>();
    } else {
        return make<Utf8DecoderCls>();
    }
}

List<int> _WindowsCodePageEncoderCls::convert(String input) {
    List<int> encoded = _encodeString(input);
    if (encoded == nullptr) {
        ;
    }
    return encoded;
}

StringConversionSink _WindowsCodePageEncoderCls::startChunkedConversion(Sink<List<int>> sink) {
    return make<_WindowsCodePageEncoderSinkCls>(sink);
}

void _WindowsCodePageEncoderSinkCls::close() {
    _sink->close();
}

void _WindowsCodePageEncoderSinkCls::add(String stringValue) {
    List<int> encoded = _WindowsCodePageEncoderCls->_encodeString(stringValue);
    if (encoded == nullptr) {
        ;
    }
    _sink->add(encoded);
}

void _WindowsCodePageEncoderSinkCls::addSlice(int end, bool isLast, String source, int start) {
    if (start != 0 || end != source->length()) {
        source = source->substring(start, end);
    }
    add(source);
    if (isLast)     {
        close();
    }
}

String _WindowsCodePageDecoderCls::convert(List<int> input) {
    return _decodeBytes(input);
}

ByteConversionSink _WindowsCodePageDecoderCls::startChunkedConversion(Sink<String> sink) {
    return make<_WindowsCodePageDecoderSinkCls>(sink);
}

void _WindowsCodePageDecoderSinkCls::close() {
    _sink->close();
}

void _WindowsCodePageDecoderSinkCls::add(List<int> bytes) {
    _sink->add(_WindowsCodePageDecoderCls->_decodeBytes(bytes));
}
