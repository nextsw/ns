#ifndef DART_IO_DATA_TRANSFORMER
#define DART_IO_DATA_TRANSFORMER
#include <base.hpp>

#include <dart/core/core.hpp>


class ZLibOptionCls : public ObjectCls {
public:
    static int minWindowBits;

    static int maxWindowBits;

    static int defaultWindowBits;

    static int minLevel;

    static int maxLevel;

    static int defaultLevel;

    static int minMemLevel;

    static int maxMemLevel;

    static int defaultMemLevel;

    static int strategyFiltered;

    static int strategyHuffmanOnly;

    static int strategyRle;

    static int strategyFixed;

    static int strategyDefault;


private:

};
using ZLibOption = std::shared_ptr<ZLibOptionCls>;
ZLibCodec zlib;


class ZLibCodecCls : public CodecCls<List<int>, List<int>> {
public:
    bool gzip;

    int level;

    int memLevel;

    int strategy;

    int windowBits;

    bool raw;

    List<int> dictionary;


     ZLibCodecCls(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    virtual ZLibEncoder encoder();

    virtual ZLibDecoder decoder();

private:

    virtual void  _default();

};
using ZLibCodec = std::shared_ptr<ZLibCodecCls>;
GZipCodec gzip;


class GZipCodecCls : public CodecCls<List<int>, List<int>> {
public:
    bool gzip;

    int level;

    int memLevel;

    int strategy;

    int windowBits;

    List<int> dictionary;

    bool raw;


     GZipCodecCls(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    virtual ZLibEncoder encoder();

    virtual ZLibDecoder decoder();

private:

    virtual void  _default();

};
using GZipCodec = std::shared_ptr<GZipCodecCls>;

class ZLibEncoderCls : public ConverterCls<List<int>, List<int>> {
public:
    bool gzip;

    int level;

    int memLevel;

    int strategy;

    int windowBits;

    List<int> dictionary;

    bool raw;


     ZLibEncoderCls(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    virtual List<int> convert(List<int> bytes);

    virtual ByteConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

};
using ZLibEncoder = std::shared_ptr<ZLibEncoderCls>;

class ZLibDecoderCls : public ConverterCls<List<int>, List<int>> {
public:
    int windowBits;

    List<int> dictionary;

    bool raw;


     ZLibDecoderCls(List<int> dictionary, bool raw, int windowBits);

    virtual List<int> convert(List<int> bytes);

    virtual ByteConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

};
using ZLibDecoder = std::shared_ptr<ZLibDecoderCls>;

class RawZLibFilterCls : public ObjectCls {
public:

    virtual void  deflateFilter(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);

    virtual void  inflateFilter(List<int> dictionary, bool raw, int windowBits);

    virtual void process(List<int> data, int end, int start);
    virtual List<int> processed(bool end, bool flush);
private:

    static RawZLibFilter _makeZLibDeflateFilter(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, int strategy, int windowBits);
    static RawZLibFilter _makeZLibInflateFilter(List<int> dictionary, bool raw, int windowBits);
};
using RawZLibFilter = std::shared_ptr<RawZLibFilterCls>;

class _BufferSinkCls : public ByteConversionSinkCls {
public:
    BytesBuilder builder;


    virtual void add(List<int> chunk);

    virtual void addSlice(List<int> chunk, int end, bool isLast, int start);

    virtual void close();

private:

};
using _BufferSink = std::shared_ptr<_BufferSinkCls>;

class _ZLibEncoderSinkCls : public _FilterSinkCls {
public:

private:

    virtual void  _(List<int> dictionary, bool gzip, int level, int memLevel, bool raw, ByteConversionSink sink, int strategy, int windowBits);

};
using _ZLibEncoderSink = std::shared_ptr<_ZLibEncoderSinkCls>;

class _ZLibDecoderSinkCls : public _FilterSinkCls {
public:

private:

    virtual void  _(List<int> dictionary, bool raw, ByteConversionSink sink, int windowBits);

};
using _ZLibDecoderSink = std::shared_ptr<_ZLibDecoderSinkCls>;

class _FilterSinkCls : public ByteConversionSinkCls {
public:

    virtual void add(List<int> data);

    virtual void addSlice(List<int> data, int end, bool isLast, int start);

    virtual void close();

private:
    RawZLibFilter _filter;

    ByteConversionSink _sink;

    bool _closed;

    bool _empty;


     _FilterSinkCls(RawZLibFilter _filter, ByteConversionSink _sink);
};
using _FilterSink = std::shared_ptr<_FilterSinkCls>;
void _validateZLibWindowBits(int windowBits);

void _validateZLibeLevel(int level);

void _validateZLibMemLevel(int memLevel);

void _validateZLibStrategy(int strategy);



#endif