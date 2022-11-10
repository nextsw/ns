#include "latin1.hpp"
Latin1CodecCls::Latin1CodecCls(bool allowInvalid) {
    {
        _allowInvalid = allowInvalid;
    }
}

String Latin1CodecCls::name() {
    return __s("iso-8859-1");
}

Uint8List Latin1CodecCls::encode(String source) {
    return encoder()->convert(source);
}

String Latin1CodecCls::decode(bool allowInvalid, List<int> bytes) {
    if (allowInvalid or _allowInvalid) {
        return make<Latin1DecoderCls>(true)->convert(bytes);
    } else {
        return make<Latin1DecoderCls>(false)->convert(bytes);
    }
}

Latin1Encoder Latin1CodecCls::encoder() {
    return make<Latin1EncoderCls>();
}

Latin1Decoder Latin1CodecCls::decoder() {
    return _allowInvalid? make<Latin1DecoderCls>(true) : make<Latin1DecoderCls>(false);
}

Latin1EncoderCls::Latin1EncoderCls() : _UnicodeSubsetEncoder(_latin1Mask) {
}

Latin1DecoderCls::Latin1DecoderCls(bool allowInvalid) : _UnicodeSubsetDecoder(allowInvalid, _latin1Mask) {
}

ByteConversionSink Latin1DecoderCls::startChunkedConversion(Sink<String> sink) {
    StringConversionSink stringSink;
    if (is<StringConversionSink>(sink)) {
        stringSink = sink;
    } else {
        stringSink = StringConversionSinkCls->from(sink);
    }
    if (!_allowInvalid)     {
        return make<_Latin1DecoderSinkCls>(stringSink);
    }
    return make<_Latin1AllowInvalidDecoderSinkCls>(stringSink);
}

void _Latin1DecoderSinkCls::close() {
    _sink!->close();
    _sink = nullptr;
}

void _Latin1DecoderSinkCls::add(List<int> source) {
    addSlice(source, 0, source->length, false);
}

void _Latin1DecoderSinkCls::addSlice(int end, bool isLast, List<int> source, int start) {
    RangeErrorCls->checkValidRange(start, end, source->length);
    if (start == end)     {
        return;
    }
    if (!is<Uint8List>(source)) {
        _checkValidLatin1(source, start, end);
    }
    _addSliceToSink(source, start, end, isLast);
}

void _Latin1DecoderSinkCls::_addSliceToSink(int end, bool isLast, List<int> source, int start) {
    _sink!->add(StringCls->fromCharCodes(source, start, end));
    if (isLast)     {
        close();
    }
}

void _Latin1DecoderSinkCls::_checkValidLatin1(int end, List<int> source, int start) {
    auto mask = 0;
    for (;  < end; i++) {
        mask = source[i];
    }
    if (mask >= 0 && mask <= _latin1Mask) {
        return;
    }
    _reportInvalidLatin1(source, start, end);
}

void _Latin1DecoderSinkCls::_reportInvalidLatin1(int end, List<int> source, int start) {
    for (;  < end; i++) {
        auto char = source[i];
        if ( < 0 || char > _latin1Mask) {
            ;
        }
    }
    assert(false);
}

void _Latin1AllowInvalidDecoderSinkCls::addSlice(int end, bool isLast, List<int> source, int start) {
    RangeErrorCls->checkValidRange(start, end, source->length);
    for (;  < end; i++) {
        auto char = source[i];
        if (char > _latin1Mask ||  < 0) {
            if (i > start)             {
                _addSliceToSink(source, start, i, false);
            }
            _addSliceToSink(makeList(ArrayItem), 0, 1, false);
            start = i + 1;
        }
    }
    if ( < end) {
        _addSliceToSink(source, start, end, isLast);
    }
    if (isLast) {
        close();
    }
}

_Latin1AllowInvalidDecoderSinkCls::_Latin1AllowInvalidDecoderSinkCls(StringConversionSink sink) : _Latin1DecoderSink(sink) {
}
