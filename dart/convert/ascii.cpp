#include "ascii.hpp"
AsciiCodecCls::AsciiCodecCls(bool allowInvalid) {
    {
        _allowInvalid = allowInvalid;
    }
}

String AsciiCodecCls::name() {
    return __s("us-ascii");
}

Uint8List AsciiCodecCls::encode(String source) {
    return encoder()->convert(source);
}

String AsciiCodecCls::decode(bool allowInvalid, List<int> bytes) {
    if (allowInvalid or _allowInvalid) {
        return make<AsciiDecoderCls>(true)->convert(bytes);
    } else {
        return make<AsciiDecoderCls>(false)->convert(bytes);
    }
}

AsciiEncoder AsciiCodecCls::encoder() {
    return make<AsciiEncoderCls>();
}

AsciiDecoder AsciiCodecCls::decoder() {
    return _allowInvalid? make<AsciiDecoderCls>(true) : make<AsciiDecoderCls>(false);
}

Uint8List _UnicodeSubsetEncoderCls::convert(int end, int start, String stringValue) {
    auto stringLength = stringValue->length;
    end = RangeErrorCls->checkValidRange(start, end, stringLength);
    auto length = end - start;
    auto result = make<Uint8ListCls>(length);
    for (;  < length; i++) {
        auto codeUnit = stringValue->codeUnitAt(start + i);
        if ((codeUnit & ~_subsetMask) != 0) {
            ;
        }
        result[i] = codeUnit;
    }
    return result;
}

StringConversionSink _UnicodeSubsetEncoderCls::startChunkedConversion(Sink<List<int>> sink) {
    return make<_UnicodeSubsetEncoderSinkCls>(_subsetMask, is<ByteConversionSink>(sink)? sink : ByteConversionSinkCls->from(sink));
}

Stream<List<int>> _UnicodeSubsetEncoderCls::bind(Stream<String> stream) {
    return super->bind(stream);
}

AsciiEncoderCls::AsciiEncoderCls() : _UnicodeSubsetEncoder(_asciiMask) {
}

void _UnicodeSubsetEncoderSinkCls::close() {
    _sink->close();
}

void _UnicodeSubsetEncoderSinkCls::addSlice(int end, bool isLast, String source, int start) {
    RangeErrorCls->checkValidRange(start, end, source->length);
    for (;  < end; i++) {
        auto codeUnit = source->codeUnitAt(i);
        if ((codeUnit & ~_subsetMask) != 0) {
            ;
        }
    }
    _sink->add(source->codeUnits->sublist(start, end));
    if (isLast) {
        close();
    }
}

String _UnicodeSubsetDecoderCls::convert(List<int> bytes, int end, int start) {
    end = RangeErrorCls->checkValidRange(start, end, bytes->length);
    for (;  < end; i++) {
        auto byte = bytes[i];
        if ((byte & ~_subsetMask) != 0) {
            if (!_allowInvalid) {
                ;
            }
            return _convertInvalid(bytes, start, end);
        }
    }
    return StringCls->fromCharCodes(bytes, start, end);
}

Stream<String> _UnicodeSubsetDecoderCls::bind(Stream<List<int>> stream) {
    return super->bind(stream);
}

String _UnicodeSubsetDecoderCls::_convertInvalid(List<int> bytes, int end, int start) {
    auto buffer = make<StringBufferCls>();
    for (;  < end; i++) {
        auto value = bytes[i];
        if ((value & ~_subsetMask) != 0)         {
            value = 0xFFFD;
        }
        buffer->writeCharCode(value);
    }
    return buffer->toString();
}

AsciiDecoderCls::AsciiDecoderCls(bool allowInvalid) : _UnicodeSubsetDecoder(allowInvalid, _asciiMask) {
}

ByteConversionSink AsciiDecoderCls::startChunkedConversion(Sink<String> sink) {
    StringConversionSink stringSink;
    if (is<StringConversionSink>(sink)) {
        stringSink = sink;
    } else {
        stringSink = StringConversionSinkCls->from(sink);
    }
    if (_allowInvalid) {
        return make<_ErrorHandlingAsciiDecoderSinkCls>(stringSink->asUtf8Sink(false));
    } else {
        return make<_SimpleAsciiDecoderSinkCls>(stringSink);
    }
}

void _ErrorHandlingAsciiDecoderSinkCls::close() {
    _utf8Sink->close();
}

void _ErrorHandlingAsciiDecoderSinkCls::add(List<int> source) {
    addSlice(source, 0, source->length, false);
}

void _ErrorHandlingAsciiDecoderSinkCls::addSlice(int end, bool isLast, List<int> source, int start) {
    RangeErrorCls->checkValidRange(start, end, source->length);
    for (;  < end; i++) {
        if ((source[i] & ~_asciiMask) != 0) {
            if (i > start)             {
                _utf8Sink->addSlice(source, start, i, false);
            }
            _utf8Sink->add(makeList(ArrayItem, ArrayItem, ArrayItem));
            start = i + 1;
        }
    }
    if ( < end) {
        _utf8Sink->addSlice(source, start, end, isLast);
    } else     {
        if (isLast) {
        close();
    }
;
    }}

void _SimpleAsciiDecoderSinkCls::close() {
    _sink->close();
}

void _SimpleAsciiDecoderSinkCls::add(List<int> source) {
    for (;  < source->length; i++) {
        if ((source[i] & ~_asciiMask) != 0) {
            ;
        }
    }
    _sink->add(StringCls->fromCharCodes(source));
}

void _SimpleAsciiDecoderSinkCls::addSlice(int end, bool isLast, List<int> source, int start) {
    Unknown length = source->length;
    RangeErrorCls->checkValidRange(start, end, length);
    if ( < end) {
        if (start != 0 || end != length) {
            source = source->sublist(start, end);
        }
        add(source);
    }
    if (isLast)     {
        close();
    }
}
