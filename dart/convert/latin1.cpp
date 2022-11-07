#include "latin1.hpp"
Latin1Codec::Latin1Codec(bool allowInvalid) {
    {
        _allowInvalid = allowInvalid;
    }
}

String Latin1Codec::name() {
    return "iso-8859-1";
}

Uint8List Latin1Codec::encode(String source) {
    return encoder.convert(source);
}

String Latin1Codec::decode(bool allowInvalid, List<int> bytes) {
    if (allowInvalid ?? _allowInvalid) {
        return const Latin1Decoder(true).convert(bytes);
    } else {
        return const Latin1Decoder(false).convert(bytes);
    }
}

Latin1Encoder Latin1Codec::encoder() {
    return const Latin1Encoder();
}

Latin1Decoder Latin1Codec::decoder() {
    return _allowInvalid? const Latin1Decoder(true) : const Latin1Decoder(false);
}

Latin1Encoder::Latin1Encoder() {
    {
        super(_latin1Mask);
    }
}

Latin1Decoder::Latin1Decoder(bool allowInvalid) {
    {
        super(allowInvalid, _latin1Mask);
    }
}

ByteConversionSink Latin1Decoder::startChunkedConversion(Sink<String> sink) {
    StringConversionSink stringSink;
    if (sink is StringConversionSink) {
        stringSink = sink;
    } else {
        stringSink = StringConversionSink.from(sink);
    }
    if (!_allowInvalid)     {
        return _Latin1DecoderSink(stringSink);
    }
    return _Latin1AllowInvalidDecoderSink(stringSink);
}

void _Latin1DecoderSink::close() {
    _sink!.close();
    _sink = nullptr;
}

void _Latin1DecoderSink::add(List<int> source) {
    addSlice(source, 0, source.length, false);
}

void _Latin1DecoderSink::addSlice(int end, bool isLast, List<int> source, int start) {
    RangeError.checkValidRange(start, end, source.length);
    if (start == end)     {
        return;
    }
    if (source is! Uint8List) {
        _checkValidLatin1(source, start, end);
    }
    _addSliceToSink(source, start, end, isLast);
}

void _Latin1DecoderSink::_addSliceToSink(int end, bool isLast, List<int> source, int start) {
    _sink!.add(String.fromCharCodes(source, start, end));
    if (isLast)     {
        close();
    }
}

void _Latin1DecoderSink::_checkValidLatin1(int end, List<int> source, int start) {
    auto mask = 0;
    for (;  < end; i++) {
        mask = source[i];
    }
    if (mask >= 0 && mask <= _latin1Mask) {
        return;
    }
    _reportInvalidLatin1(source, start, end);
}

void _Latin1DecoderSink::_reportInvalidLatin1(int end, List<int> source, int start) {
    for (;  < end; i++) {
        auto char = source[i];
        if ( < 0 || char > _latin1Mask) {
            ;
        }
    }
    assert(false);
}

void _Latin1AllowInvalidDecoderSink::addSlice(int end, bool isLast, List<int> source, int start) {
    RangeError.checkValidRange(start, end, source.length);
    for (;  < end; i++) {
        auto char = source[i];
        if (char > _latin1Mask ||  < 0) {
            if (i > start)             {
                _addSliceToSink(source, start, i, false);
            }
            _addSliceToSink(const , 0, 1, false);
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

_Latin1AllowInvalidDecoderSink::_Latin1AllowInvalidDecoderSink(StringConversionSink sink) {
    {
        super(sink);
    }
}
