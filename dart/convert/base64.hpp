#ifndef BASE64_H
#define BASE64_H
#include <memory>



const Base64Codec base64;

const Base64Codec base64Url;

String base64Encode(List<int> bytes);

String base64UrlEncode(List<int> bytes);

Uint8List base64Decode(String source);

const int _paddingChar;


class Base64Codec : Codec<List<int>, String> {
public:

     Base64Codec();

    void  urlSafe();

    Base64Encoder encoder();

    Base64Decoder decoder();

    Uint8List decode(String encoded);

    String normalize(int end, String source, int start);

private:
    Base64Encoder _encoder;


    static void _checkPadding(int firstPadding, int length, int paddingCount, String source, int sourceEnd, int sourceIndex);

};

class Base64Encoder : Converter<List<int>, String> {
public:

     Base64Encoder();

    void  urlSafe();

    String convert(List<int> input);

    ByteConversionSink startChunkedConversion(Sink<String> sink);

private:
    bool _urlSafe;


};

class _Base64Encoder {
public:

    Uint8List createBuffer(int bufferLength);

    Uint8List encode(List<int> bytes, int end, bool isLast, int start);

    static int encodeChunk(String alphabet, List<int> bytes, int end, bool isLast, Uint8List output, int outputIndex, int start, int state);

    static void writeFinalChunk(String alphabet, int bits, int count, Uint8List output, int outputIndex);

private:
    static const String _base64Alphabet;

    static const String _base64UrlAlphabet;

    static const int _valueShift;

    static const int _countMask;

    static const int _sixBitMask;

    int _state;

    String _alphabet;


     _Base64Encoder(bool urlSafe);

    static int _encodeState(int bits, int count);

    static int _stateBits(int state);

    static int _stateCount(int state);

};

class _BufferCachingBase64Encoder : _Base64Encoder {
public:
    Uint8List bufferCache;


    Uint8List createBuffer(int bufferLength);

private:

     _BufferCachingBase64Encoder(bool urlSafe);

};

class _Base64EncoderSink : ByteConversionSinkBase {
public:

    void add(List<int> source);

    void close();

    void addSlice(int end, bool isLast, List<int> source, int start);

private:

    void _add(int end, bool isLast, List<int> source, int start);

};

class _AsciiBase64EncoderSink : _Base64EncoderSink {
public:

private:
    Sink<String> _sink;

    _Base64Encoder _encoder;


     _AsciiBase64EncoderSink(Sink<String> _sink, bool urlSafe);

    void _add(int end, bool isLast, List<int> source, int start);

};

class _Utf8Base64EncoderSink : _Base64EncoderSink {
public:

private:
    ByteConversionSink _sink;

    _Base64Encoder _encoder;


     _Utf8Base64EncoderSink(ByteConversionSink _sink, bool urlSafe);

    void _add(int end, bool isLast, List<int> source, int start);

};

class Base64Decoder : Converter<String, List<int>> {
public:

     Base64Decoder();

    Uint8List convert(int end, String input, int start);

    StringConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

};

class _Base64Decoder {
public:

    Uint8List decode(int end, String input, int start);

    void close(int end, String input);

    static int decodeChunk(int end, String input, int outIndex, Uint8List output, int start, int state);

private:
    static const int _valueShift;

    static const int _countMask;

    static const int _invalid;

    static const int _padding;

    static const int __;

    static const int _p;

    static List<int> _inverseAlphabet;

    static const int _char_percent;

    static const int _char_3;

    static const int _char_d;

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

class _Base64DecoderSink : StringConversionSinkBase {
public:

    void add(String string);

    void close();

    void addSlice(int end, bool isLast, int start, String string);

private:
    Sink<List<int>> _sink;

    _Base64Decoder _decoder;


     _Base64DecoderSink(Sink<List<int>> _sink);

};

#endif