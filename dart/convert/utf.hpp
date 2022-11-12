#ifndef DART_CONVERT_UTF
#define DART_CONVERT_UTF
#include <base.hpp>

#include <dart/core/core.hpp>

int unicodeReplacementCharacterRune;

int unicodeBomCharacterRune;

Utf8Codec utf8;


class Utf8CodecCls : public EncodingCls {
public:

     Utf8CodecCls(bool allowMalformed);

    virtual String name();

    virtual String decode(List<int> codeUnits, bool allowMalformed);

    virtual Utf8Encoder encoder();

    virtual Utf8Decoder decoder();

private:
    bool _allowMalformed;


};
using Utf8Codec = std::shared_ptr<Utf8CodecCls>;

class Utf8EncoderCls : public ConverterCls<String, List<int>> {
public:

     Utf8EncoderCls();
    virtual Uint8List convert(String stringValue, int start, int end);

    virtual StringConversionSink startChunkedConversion(Sink<List<int>> sink);

    virtual Stream<List<int>> bind(Stream<String> stream);

private:

};
using Utf8Encoder = std::shared_ptr<Utf8EncoderCls>;

class _Utf8EncoderCls : public ObjectCls {
public:

    virtual void  withBufferSize(int bufferSize);

private:
    int _carry;

    int _bufferIndex;

    Uint8List _buffer;

    static auto  _DEFAULT_BYTE_BUFFER_SIZE;


     _Utf8EncoderCls();

    static Uint8List _createBuffer(int size);

    virtual void _writeReplacementCharacter();

    virtual bool _writeSurrogate(int leadingSurrogate, int nextCodeUnit);

    virtual int _fillBuffer(String str, int start, int end);

};
using _Utf8Encoder = std::shared_ptr<_Utf8EncoderCls>;

class _Utf8EncoderSinkCls : public _Utf8EncoderCls {
public:

    virtual void close();

    virtual void addSlice(String str, int start, int end, bool isLast);

private:
    ByteConversionSink _sink;


     _Utf8EncoderSinkCls(ByteConversionSink _sink);
};
using _Utf8EncoderSink = std::shared_ptr<_Utf8EncoderSinkCls>;

class Utf8DecoderCls : public ConverterCls<List<int>, String> {
public:

     Utf8DecoderCls(bool allowMalformed);

    virtual String convert(List<int> codeUnits, int start, int end);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink);

    virtual Stream<String> bind(Stream<List<int>> stream);

    template<typename T>
 Converter<List<int>, T> fuse(Converter<String, T> next) override;
private:
    bool _allowMalformed;


    static String _convertIntercepted(bool allowMalformed, List<int> codeUnits, int start, int end);
};
using Utf8Decoder = std::shared_ptr<Utf8DecoderCls>;
int _ONE_BYTE_LIMIT;

int _TWO_BYTE_LIMIT;

int _THREE_BYTE_LIMIT;

int _FOUR_BYTE_LIMIT;

int _SURROGATE_TAG_MASK;

int _SURROGATE_VALUE_MASK;

int _LEAD_SURROGATE_MIN;

int _TAIL_SURROGATE_MIN;

bool _isLeadSurrogate(int codeUnit);

bool _isTailSurrogate(int codeUnit);

int _combineSurrogatePair(int lead, int tail);



#endif