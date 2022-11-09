#ifndef DART_CONVERT_BASE64
#define DART_CONVERT_BASE64
#include <base.hpp>

#include <dart/core/core.hpp>

Base64Codec base64;

Base64Codec base64Url;

String base64Encode(List<int> bytes);

String base64UrlEncode(List<int> bytes);

Uint8List base64Decode(String source);

int _paddingChar;


class Base64CodecCls : public CodecCls<List<int>, String> {
public:

     Base64CodecCls();

    virtual void  urlSafe();

    virtual Base64Encoder encoder();

    virtual Base64Decoder decoder();

    virtual Uint8List decode(String encoded);

    virtual String normalize(int end, String source, int start);

private:
    Base64Encoder _encoder;


    static void _checkPadding(int firstPadding, int length, int paddingCount, String source, int sourceEnd, int sourceIndex);

};
using Base64Codec = std::shared_ptr<Base64CodecCls>;

class Base64EncoderCls : public ConverterCls<List<int>, String> {
public:

     Base64EncoderCls();

    virtual void  urlSafe();

    virtual String convert(List<int> input);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink);

private:
    bool _urlSafe;


};
using Base64Encoder = std::shared_ptr<Base64EncoderCls>;

class _Base64EncoderCls : public ObjectCls {
public:

    virtual Uint8List createBuffer(int bufferLength);

    virtual Uint8List encode(List<int> bytes, int end, bool isLast, int start);

    static int encodeChunk(String alphabet, List<int> bytes, int end, bool isLast, Uint8List output, int outputIndex, int start, int state);

    static void writeFinalChunk(String alphabet, int bits, int count, Uint8List output, int outputIndex);

private:
    static String _base64Alphabet;

    static String _base64UrlAlphabet;

    static int _valueShift;

    static int _countMask;

    static int _sixBitMask;

    int _state;

    String _alphabet;


     _Base64EncoderCls(bool urlSafe);

    static int _encodeState(int bits, int count);

    static int _stateBits(int state);

    static int _stateCount(int state);

};
using _Base64Encoder = std::shared_ptr<_Base64EncoderCls>;

class _BufferCachingBase64EncoderCls : public _Base64EncoderCls {
public:
    Uint8List bufferCache;


    virtual Uint8List createBuffer(int bufferLength);

private:

     _BufferCachingBase64EncoderCls(bool urlSafe);

};
using _BufferCachingBase64Encoder = std::shared_ptr<_BufferCachingBase64EncoderCls>;

class _Base64EncoderSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void add(List<int> source);

    virtual void close();

    virtual void addSlice(int end, bool isLast, List<int> source, int start);

private:

    virtual void _add(int end, bool isLast, List<int> source, int start);
};
using _Base64EncoderSink = std::shared_ptr<_Base64EncoderSinkCls>;

class _AsciiBase64EncoderSinkCls : public _Base64EncoderSinkCls {
public:

private:
    Sink<String> _sink;

    _Base64Encoder _encoder;


     _AsciiBase64EncoderSinkCls(Sink<String> _sink, bool urlSafe);

    virtual void _add(int end, bool isLast, List<int> source, int start);

};
using _AsciiBase64EncoderSink = std::shared_ptr<_AsciiBase64EncoderSinkCls>;

class _Utf8Base64EncoderSinkCls : public _Base64EncoderSinkCls {
public:

private:
    ByteConversionSink _sink;

    _Base64Encoder _encoder;


     _Utf8Base64EncoderSinkCls(ByteConversionSink _sink, bool urlSafe);

    virtual void _add(int end, bool isLast, List<int> source, int start);

};
using _Utf8Base64EncoderSink = std::shared_ptr<_Utf8Base64EncoderSinkCls>;

class Base64DecoderCls : public ConverterCls<String, List<int>> {
public:

     Base64DecoderCls();
    virtual Uint8List convert(int end, String input, int start);

    virtual StringConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

};
using Base64Decoder = std::shared_ptr<Base64DecoderCls>;

class _Base64DecoderCls : public ObjectCls {
public:

    virtual Uint8List decode(int end, String input, int start);

    virtual void close(int end, String input);

    static int decodeChunk(int end, String input, int outIndex, Uint8List output, int start, int state);

private:
    static int _valueShift;

    static int _countMask;

    static int _invalid;

    static int _padding;

    static int __;

    static int _p;

    static List<int> _inverseAlphabet;

    static int _char_percent;

    static int _char_3;

    static int _char_d;

    int _state;

    static Uint8List _emptyBuffer;


    static int _encodeCharacterState(int bits, int count);

    static int _stateCount(int state);

    static int _stateBits(int state);

    static int _encodePaddingState(int expectedPadding);

    static int _statePadding(int state);

    static bool _hasSeenPadding(int state);

    static Uint8List _allocateBuffer(int end, String input, int start, int state);

    static int _trimPaddingChars(int end, String input, int start);

    static int _checkPadding(int end, String input, int start, int state);

};
using _Base64Decoder = std::shared_ptr<_Base64DecoderCls>;

class _Base64DecoderSinkCls : public StringConversionSinkBaseCls {
public:

    virtual void add(String stringValue);

    virtual void close();

    virtual void addSlice(int end, bool isLast, int start, String stringValue);

private:
    Sink<List<int>> _sink;

    _Base64Decoder _decoder;


     _Base64DecoderSinkCls(Sink<List<int>> _sink);
};
using _Base64DecoderSink = std::shared_ptr<_Base64DecoderSinkCls>;


#endif