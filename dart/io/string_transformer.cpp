#include "string_transformer.hpp"
String SystemEncoding::name() {
    return "system";
}

List<int> SystemEncoding::encode(String input) {
    return encoder.convert(input);
}

String SystemEncoding::decode(List<int> encoded) {
    return decoder.convert(encoded);
}

Converter<String, List<int>> SystemEncoding::encoder() {
    if (Platform.operatingSystem == "windows") {
        return const _WindowsCodePageEncoder();
    } else {
        return const Utf8Encoder();
    }
}

Converter<List<int>, String> SystemEncoding::decoder() {
    if (Platform.operatingSystem == "windows") {
        return const _WindowsCodePageDecoder();
    } else {
        return const Utf8Decoder();
    }
}

List<int> _WindowsCodePageEncoder::convert(String input) {
    List<int> encoded = _encodeString(input);
    if (encoded == nullptr) {
        ;
    }
    return encoded;
}

StringConversionSink _WindowsCodePageEncoder::startChunkedConversion(Sink<List<int>> sink) {
    return _WindowsCodePageEncoderSink(sink);
}

void _WindowsCodePageEncoderSink::close() {
    _sink.close();
}

void _WindowsCodePageEncoderSink::add(String string) {
    List<int> encoded = _WindowsCodePageEncoder._encodeString(string);
    if (encoded == nullptr) {
        ;
    }
    _sink.add(encoded);
}

void _WindowsCodePageEncoderSink::addSlice(int end, bool isLast, String source, int start) {
    if (start != 0 || end != source.length) {
        source = source.substring(start, end);
    }
    add(source);
    if (isLast)     {
        close();
    }
}

String _WindowsCodePageDecoder::convert(List<int> input) {
    return _decodeBytes(input);
}

ByteConversionSink _WindowsCodePageDecoder::startChunkedConversion(Sink<String> sink) {
    return _WindowsCodePageDecoderSink(sink);
}

void _WindowsCodePageDecoderSink::close() {
    _sink.close();
}

void _WindowsCodePageDecoderSink::add(List<int> bytes) {
    _sink.add(_WindowsCodePageDecoder._decodeBytes(bytes));
}
