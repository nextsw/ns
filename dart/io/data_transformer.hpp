#ifndef DATA_TRANSFORMER_H
#define DATA_TRANSFORMER_H
#include <memory>




class ZLibOption {
public:
    static const int minWindowBits;

    static const int maxWindowBits;

    static const int defaultWindowBits;

    static const int minLevel;

    static const int maxLevel;

    static const int defaultLevel;

    static const int minMemLevel;

    static const int maxMemLevel;

    static const int defaultMemLevel;

    static const int strategyFiltered;

    static const int strategyHuffmanOnly;

    static const int strategyRle;

    static const int strategyFixed;

    static const int strategyDefault;


private:

};
const ZLibCodec zlib;


class ZLibCodec : Codec<List<int>, List<int>> {
public:
    bool gzip;

    int level;

    int memLevel;

    int strategy;

    int windowBits;

    bool raw;

    List<int> dictionary;


     ZLibCodec(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    ZLibEncoder encoder();

    ZLibDecoder decoder();

private:

    void  _default();

};
const GZipCodec gzip;


class GZipCodec : Codec<List<int>, List<int>> {
public:
    bool gzip;

    int level;

    int memLevel;

    int strategy;

    int windowBits;

    List<int> dictionary;

    bool raw;


     GZipCodec(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    ZLibEncoder encoder();

    ZLibDecoder decoder();

private:

    void  _default();

};

class ZLibEncoder : Converter<List<int>, List<int>> {
public:
    bool gzip;

    int level;

    int memLevel;

    int strategy;

    int windowBits;

    List<int> dictionary;

    bool raw;


     ZLibEncoder(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    List<int> convert(List<int> bytes);

    ByteConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

};

class ZLibDecoder : Converter<List<int>, List<int>> {
public:
    int windowBits;

    List<int> dictionary;

    bool raw;


     ZLibDecoder(List<int> dictionary, bool raw, int windowBits);

    List<int> convert(List<int> bytes);

    ByteConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

};

class RawZLibFilter {
public:

    void  deflateFilter(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    void  inflateFilter(List<int> dictionary, bool raw, int windowBits);

    void process(List<int> data, int end, int start);

    List<int> processed(bool end, bool flush);

private:

    external static RawZLibFilter _makeZLibDeflateFilter(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    external static RawZLibFilter _makeZLibInflateFilter(List<int> dictionary, bool raw, int windowBits);

};

class _BufferSink : ByteConversionSink {
public:
    BytesBuilder builder;


    void add(List<int> chunk);

    void addSlice(List<int> chunk, int end, bool isLast, int start);

    void close();

private:

};

class _ZLibEncoderSink : _FilterSink {
public:

private:

    void  _(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, ByteConversionSink sink, int strategy, int windowBits);

};

class _ZLibDecoderSink : _FilterSink {
public:

private:

    void  _(List<int> dictionary, bool raw, ByteConversionSink sink, int windowBits);

};

class _FilterSink : ByteConversionSink {
public:

    void add(List<int> data);

    void addSlice(List<int> data, int end, bool isLast, int start);

    void close();

private:
    RawZLibFilter _filter;

    ByteConversionSink _sink;

    bool _closed;

    bool _empty;


     _FilterSink(RawZLibFilter _filter, ByteConversionSink _sink);

};
void _validateZLibWindowBits(int windowBits);

void _validateZLibeLevel(int level);

void _validateZLibMemLevel(int memLevel);

void _validateZLibStrategy(int strategy);


#endif