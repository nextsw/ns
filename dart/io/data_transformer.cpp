#include "data_transformer.hpp"
ZLibCodec::ZLibCodec(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    {
        _validateZLibeLevel(level);
        _validateZLibMemLevel(memLevel);
        _validateZLibStrategy(strategy);
        _validateZLibWindowBits(windowBits);
    }
}

ZLibEncoder ZLibCodec::encoder() {
    return ZLibEncoder(false, level, windowBits, memLevel, strategy, dictionary, raw);
}

ZLibDecoder ZLibCodec::decoder() {
    return ZLibDecoder(windowBits, dictionary, raw);
}

void ZLibCodec::_default()

GZipCodec::GZipCodec(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    {
        _validateZLibeLevel(level);
        _validateZLibMemLevel(memLevel);
        _validateZLibStrategy(strategy);
        _validateZLibWindowBits(windowBits);
    }
}

ZLibEncoder GZipCodec::encoder() {
    return ZLibEncoder(true, level, windowBits, memLevel, strategy, dictionary, raw);
}

ZLibDecoder GZipCodec::decoder() {
    return ZLibDecoder(windowBits, dictionary, raw);
}

void GZipCodec::_default()

ZLibEncoder::ZLibEncoder(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    {
        _validateZLibeLevel(level);
        _validateZLibMemLevel(memLevel);
        _validateZLibStrategy(strategy);
        _validateZLibWindowBits(windowBits);
    }
}

List<int> ZLibEncoder::convert(List<int> bytes) {
    _BufferSink sink = _BufferSink();
    ;
    return sink.builder.takeBytes();
}

ByteConversionSink ZLibEncoder::startChunkedConversion(Sink<List<int>> sink) {
    if (sink is! ByteConversionSink) {
        sink = ByteConversionSink.from(sink);
    }
    return _ZLibEncoderSink._(sink, gzip, level, windowBits, memLevel, strategy, dictionary, raw);
}

ZLibDecoder::ZLibDecoder(List<int> dictionary, bool raw, int windowBits) {
    {
        _validateZLibWindowBits(windowBits);
    }
}

List<int> ZLibDecoder::convert(List<int> bytes) {
    _BufferSink sink = _BufferSink();
    ;
    return sink.builder.takeBytes();
}

ByteConversionSink ZLibDecoder::startChunkedConversion(Sink<List<int>> sink) {
    if (sink is! ByteConversionSink) {
        sink = ByteConversionSink.from(sink);
    }
    return _ZLibDecoderSink._(sink, windowBits, dictionary, raw);
}

void RawZLibFilter::deflateFilter(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    return _makeZLibDeflateFilter(gzip, level, windowBits, memLevel, strategy, dictionary, raw);
}

void RawZLibFilter::inflateFilter(List<int> dictionary, bool raw, int windowBits) {
    return _makeZLibInflateFilter(windowBits, dictionary, raw);
}

void _BufferSink::add(List<int> chunk) {
    builder.add(chunk);
}

void _BufferSink::addSlice(List<int> chunk, int end, bool isLast, int start) {
    if (chunk is Uint8List) {
        Uint8List list = chunk;
        builder.add(Uint8List.view(list.buffer, list.offsetInBytes + start, end - start));
    } else {
        builder.add(chunk.sublist(start, end));
    }
}

void _BufferSink::close() {
}

void _ZLibEncoderSink::_(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, ByteConversionSink sink, int strategy, int windowBits)

void _ZLibDecoderSink::_(List<int> dictionary, bool raw, ByteConversionSink sink, int windowBits)

void _FilterSink::add(List<int> data) {
    addSlice(data, 0, data.length, false);
}

void _FilterSink::addSlice(List<int> data, int end, bool isLast, int start) {
    ArgumentError.checkNotNull(end, "end");
    if (_closed)     {
        return;
    }
    RangeError.checkValidRange(start, end, data.length);
    ;
    if (isLast)     {
        close();
    }
}

void _FilterSink::close() {
    if (_closed)     {
        return;
    }
    if (_empty)     {
        _filter.process(const , 0, 0);
    }
    ;
    _closed = true;
    _sink.close();
}

void _validateZLibWindowBits(int windowBits) {
    if (ZLibOption.minWindowBits > windowBits || ZLibOption.maxWindowBits < windowBits) {
        ;
    }
}

void _validateZLibeLevel(int level) {
    if (ZLibOption.minLevel > level || ZLibOption.maxLevel < level) {
        ;
    }
}

void _validateZLibMemLevel(int memLevel) {
    if (ZLibOption.minMemLevel > memLevel || ZLibOption.maxMemLevel < memLevel) {
        ;
    }
}

void _validateZLibStrategy(int strategy) {
    const strategies = const ;
    if (strategies.indexOf(strategy) == -1) {
        ;
    }
}
