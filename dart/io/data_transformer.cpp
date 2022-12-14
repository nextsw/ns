#include "data_transformer.hpp"
ZLibCodecCls::ZLibCodecCls(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    {
        _validateZLibeLevel(level);
        _validateZLibMemLevel(memLevel);
        _validateZLibStrategy(strategy);
        _validateZLibWindowBits(windowBits);
    }
}

ZLibEncoder ZLibCodecCls::encoder() {
    return make<ZLibEncoderCls>(false, level, windowBits, memLevel, strategy, dictionary, raw);
}

ZLibDecoder ZLibCodecCls::decoder() {
    return make<ZLibDecoderCls>(windowBits, dictionary, raw);
}

void ZLibCodecCls::_default()

GZipCodecCls::GZipCodecCls(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    {
        _validateZLibeLevel(level);
        _validateZLibMemLevel(memLevel);
        _validateZLibStrategy(strategy);
        _validateZLibWindowBits(windowBits);
    }
}

ZLibEncoder GZipCodecCls::encoder() {
    return make<ZLibEncoderCls>(true, level, windowBits, memLevel, strategy, dictionary, raw);
}

ZLibDecoder GZipCodecCls::decoder() {
    return make<ZLibDecoderCls>(windowBits, dictionary, raw);
}

void GZipCodecCls::_default()

ZLibEncoderCls::ZLibEncoderCls(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    {
        _validateZLibeLevel(level);
        _validateZLibMemLevel(memLevel);
        _validateZLibStrategy(strategy);
        _validateZLibWindowBits(windowBits);
    }
}

List<int> ZLibEncoderCls::convert(List<int> bytes) {
    _BufferSink sink = make<_BufferSinkCls>();
    auto _c1 = startChunkedConversion(sink);_c1.auto _c2 = add(bytes);_c2.close();_c2;_c1;
    return sink->builder->takeBytes();
}

ByteConversionSink ZLibEncoderCls::startChunkedConversion(Sink<List<int>> sink) {
    if (!is<ByteConversionSink>(sink)) {
        as<ByteConversionSinkCls>(sink) = ByteConversionSinkCls->from(as<ByteConversionSinkCls>(sink));
    }
    return _ZLibEncoderSinkCls->_(sink, gzip, level, windowBits, memLevel, strategy, dictionary, raw);
}

ZLibDecoderCls::ZLibDecoderCls(List<int> dictionary, bool raw, int windowBits) {
    {
        _validateZLibWindowBits(windowBits);
    }
}

List<int> ZLibDecoderCls::convert(List<int> bytes) {
    _BufferSink sink = make<_BufferSinkCls>();
    auto _c1 = startChunkedConversion(sink);_c1.auto _c2 = add(bytes);_c2.close();_c2;_c1;
    return sink->builder->takeBytes();
}

ByteConversionSink ZLibDecoderCls::startChunkedConversion(Sink<List<int>> sink) {
    if (!is<ByteConversionSink>(sink)) {
        as<ByteConversionSinkCls>(sink) = ByteConversionSinkCls->from(as<ByteConversionSinkCls>(sink));
    }
    return _ZLibDecoderSinkCls->_(sink, windowBits, dictionary, raw);
}

void RawZLibFilterCls::deflateFilter(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits) {
    return _makeZLibDeflateFilter(gzip, level, windowBits, memLevel, strategy, dictionary, raw);
}

void RawZLibFilterCls::inflateFilter(List<int> dictionary, bool raw, int windowBits) {
    return _makeZLibInflateFilter(windowBits, dictionary, raw);
}

void _BufferSinkCls::add(List<int> chunk) {
    builder->add(chunk);
}

void _BufferSinkCls::addSlice(List<int> chunk, int start, int end, bool isLast) {
    if (is<Uint8List>(chunk)) {
        Uint8List list = as<Uint8ListCls>(chunk);
        builder->add(Uint8ListCls->view(list->buffer, list->offsetInBytes + start, end - start));
    } else {
        builder->add(chunk->sublist(start, end));
    }
}

void _BufferSinkCls::close() {
}

void _ZLibEncoderSinkCls::_(ByteConversionSink sink, bool gzip, int level, int windowBits, int memLevel, int strategy, List<int> dictionary, bool raw)

void _ZLibDecoderSinkCls::_(ByteConversionSink sink, int windowBits, List<int> dictionary, bool raw)

void _FilterSinkCls::add(List<int> data) {
    addSlice(data, 0, data->length(), false);
}

void _FilterSinkCls::addSlice(List<int> data, int start, int end, bool isLast) {
    ArgumentErrorCls->checkNotNull(end, __s("end"));
    if (_closed) {
        return;
    }
    RangeErrorCls->checkValidRange(start, end, data->length());
    try {
        _empty = false;
        _BufferAndStart bufferAndStart = _ensureFastAndSerializableByteData(data, start, end);
        _filter->process(bufferAndStart->buffer, bufferAndStart->start, end - (start - bufferAndStart->start));
        List<int> out;
        while (true) {
            auto out = _filter->processed(false);
            if (out == nullptr) {
                break;
            }
            _sink->add(out);
        }
    } catch (Unknown e) {
        _closed = true;
        throw;
    };
    if (isLast) {
        close();
    }
}

void _FilterSinkCls::close() {
    if (_closed) {
        return;
    }
    if (_empty) {
        _filter->process(makeList(), 0, 0);
    }
    try {
        while (true) {
            auto out = _filter->processed(true);
            if (out == nullptr) {
                break;
            }
            _sink->add(out);
        }
    } catch (Unknown e) {
        _closed = true;
        throw e;
    };
    _closed = true;
    _sink->close();
}

void _validateZLibWindowBits(int windowBits) {
    if (ZLibOptionCls::minWindowBits > windowBits || ZLibOptionCls::maxWindowBits < windowBits) {
        throw RangeErrorCls->range(windowBits, ZLibOptionCls::minWindowBits, ZLibOptionCls::maxWindowBits);
    }
}

void _validateZLibeLevel(int level) {
    if (ZLibOptionCls::minLevel > level || ZLibOptionCls::maxLevel < level) {
        throw RangeErrorCls->range(level, ZLibOptionCls::minLevel, ZLibOptionCls::maxLevel);
    }
}

void _validateZLibMemLevel(int memLevel) {
    if (ZLibOptionCls::minMemLevel > memLevel || ZLibOptionCls::maxMemLevel < memLevel) {
        throw RangeErrorCls->range(memLevel, ZLibOptionCls::minMemLevel, ZLibOptionCls::maxMemLevel);
    }
}

void _validateZLibStrategy(int strategy) {
    strategies = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    if (strategies->indexOf(strategy) == -1) {
        throw make<ArgumentErrorCls>(__s("Unsupported 'strategy'"));
    }
}
