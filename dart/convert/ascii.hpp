#ifndef ASCII_H
#define ASCII_H
#include <memory>



const AsciiCodec ascii;

const int _asciiMask;


class AsciiCodec : Encoding {
public:

     AsciiCodec(bool allowInvalid);

    String name();

    Uint8List encode(String source);

    String decode(bool allowInvalid, List<int> bytes);

    AsciiEncoder encoder();

    AsciiDecoder decoder();

private:
    bool _allowInvalid;


};

class _UnicodeSubsetEncoder : Converter<String, List<int>> {
public:

    Uint8List convert(int end, int start, String string);

    StringConversionSink startChunkedConversion(Sink<List<int>> sink);

    Stream<List<int>> bind(Stream<String> stream);

private:
    int _subsetMask;


     _UnicodeSubsetEncoder(int _subsetMask);

};

class AsciiEncoder : _UnicodeSubsetEncoder {
public:

     AsciiEncoder();

private:

};

class _UnicodeSubsetEncoderSink : StringConversionSinkBase {
public:

    void close();

    void addSlice(int end, bool isLast, String source, int start);

private:
    ByteConversionSink _sink;

    int _subsetMask;


     _UnicodeSubsetEncoderSink(ByteConversionSink _sink, int _subsetMask);

};

class _UnicodeSubsetDecoder : Converter<List<int>, String> {
public:

    String convert(List<int> bytes, int end, int start);

    ByteConversionSink startChunkedConversion(Sink<String> sink);

    Stream<String> bind(Stream<List<int>> stream);

private:
    bool _allowInvalid;

    int _subsetMask;


     _UnicodeSubsetDecoder(bool _allowInvalid, int _subsetMask);

    String _convertInvalid(List<int> bytes, int end, int start);

};

class AsciiDecoder : _UnicodeSubsetDecoder {
public:

     AsciiDecoder(bool allowInvalid);

    ByteConversionSink startChunkedConversion(Sink<String> sink);

private:

};

class _ErrorHandlingAsciiDecoderSink : ByteConversionSinkBase {
public:

    void close();

    void add(List<int> source);

    void addSlice(int end, bool isLast, List<int> source, int start);

private:
    ByteConversionSink _utf8Sink;


     _ErrorHandlingAsciiDecoderSink(ByteConversionSink _utf8Sink);

};

class _SimpleAsciiDecoderSink : ByteConversionSinkBase {
public:

    void close();

    void add(List<int> source);

    void addSlice(int end, bool isLast, List<int> source, int start);

private:
    Sink _sink;


     _SimpleAsciiDecoderSink(Sink _sink);

};

#endif