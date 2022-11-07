#include "ascii.hpp"
AsciiCodec::AsciiCodec(bool allowInvalid) {
    {
        _allowInvalid = allowInvalid;
    }
}

String AsciiCodec::name() {
    return "us-ascii";
}

Uint8List AsciiCodec::encode(String source) {
    return encoder.convert(source);
}

String AsciiCodec::decode(bool allowInvalid, List<int> bytes) {
    if (allowInvalid ?? _allowInvalid) {
        return const AsciiDecoder(true).convert(bytes);
    } else {
        return const AsciiDecoder(false).convert(bytes);
    }
}

AsciiEncoder AsciiCodec::encoder() {
    return const AsciiEncoder();
}

AsciiDecoder AsciiCodec::decoder() {
    return _allowInvalid? const AsciiDecoder(true) : const AsciiDecoder(false);
}

Uint8List _UnicodeSubsetEncoder::convert(int end, int start, String string) {
    auto stringLength = string.length;
    end = RangeError.checkValidRange(start, end, stringLength);
    auto length = end - start;
    auto result = Uint8List(length);
    for (;  < length; i++) {
        auto codeUnit = string.codeUnitAt(start + i);
        if ((codeUnit & ~_subsetMask) != 0) {
            ;
        }
        result[i] = codeUnit;
    }
    return result;
}

StringConversionSink _UnicodeSubsetEncoder::startChunkedConversion(Sink<List<int>> sink) {
    return _UnicodeSubsetEncoderSink(_subsetMask, sink is ByteConversionSink? sink : ByteConversionSink.from(sink));
}

Stream<List<int>> _UnicodeSubsetEncoder::bind(Stream<String> stream) {
    return super.bind(stream);
}

AsciiEncoder::AsciiEncoder() {
    {
        super(_asciiMask);
    }
}

void _UnicodeSubsetEncoderSink::close() {
    _sink.close();
}

void _UnicodeSubsetEncoderSink::addSlice(int end, bool isLast, String source, int start) {
    RangeError.checkValidRange(start, end, source.length);
    for (;  < end; i++) {
        auto codeUnit = source.codeUnitAt(i);
        if ((codeUnit & ~_subsetMask) != 0) {
            ;
        }
    }
    _sink.add(source.codeUnits.sublist(start, end));
    if (isLast) {
        close();
    }
}

String _UnicodeSubsetDecoder::convert(List<int> bytes, int end, int start) {
    end = RangeError.checkValidRange(start, end, bytes.length);
    for (;  < end; i++) {
        auto byte = bytes[i];
        if ((byte & ~_subsetMask) != 0) {
            if (!_allowInvalid) {
                ;
            }
            return _convertInvalid(bytes, start, end);
        }
    }
    return String.fromCharCodes(bytes, start, end);
}

Stream<String> _UnicodeSubsetDecoder::bind(Stream<List<int>> stream) {
    return super.bind(stream);
}

String _UnicodeSubsetDecoder::_convertInvalid(List<int> bytes, int end, int start) {
    auto buffer = StringBuffer();
    for (;  < end; i++) {
        auto value = bytes[i];
        if ((value & ~_subsetMask) != 0)         {
            value = 0xFFFD;
        }
        buffer.writeCharCode(value);
    }
    return buffer.toString();
}

AsciiDecoder::AsciiDecoder(bool allowInvalid) {
    {
        super(allowInvalid, _asciiMask);
    }
}

ByteConversionSink AsciiDecoder::startChunkedConversion(Sink<String> sink) {
    StringConversionSink stringSink;
    if (sink is StringConversionSink) {
        stringSink = sink;
    } else {
        stringSink = StringConversionSink.from(sink);
    }
    if (_allowInvalid) {
        return _ErrorHandlingAsciiDecoderSink(stringSink.asUtf8Sink(false));
    } else {
        return _SimpleAsciiDecoderSink(stringSink);
    }
}

void _ErrorHandlingAsciiDecoderSink::close() {
    _utf8Sink.close();
}

void _ErrorHandlingAsciiDecoderSink::add(List<int> source) {
    addSlice(source, 0, source.length, false);
}

void _ErrorHandlingAsciiDecoderSink::addSlice(int end, bool isLast, List<int> source, int start) {
    RangeError.checkValidRange(start, end, source.length);
    for (;  < end; i++) {
        if ((source[i] & ~_asciiMask) != 0) {
            if (i > start)             {
                _utf8Sink.addSlice(source, start, i, false);
            }
            _utf8Sink.add(const );
            start = i + 1;
        }
    }
    if ( < end) {
        _utf8Sink.addSlice(source, start, end, isLast);
    } else     {
        if (isLast) {
        close();
    }
;
    }}

void _SimpleAsciiDecoderSink::close() {
    _sink.close();
}

void _SimpleAsciiDecoderSink::add(List<int> source) {
    for (;  < source.length; i++) {
        if ((source[i] & ~_asciiMask) != 0) {
            ;
        }
    }
    _sink.add(String.fromCharCodes(source));
}

void _SimpleAsciiDecoderSink::addSlice(int end, bool isLast, List<int> source, int start) {
    Unknown length = source.length;
    RangeError.checkValidRange(start, end, length);
    if ( < end) {
        if (start != 0 || end != length) {
            source = source.sublist(start, end);
        }
        add(source);
    }
    if (isLast)     {
        close();
    }
}
