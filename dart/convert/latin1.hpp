#ifndef LATIN1_H
#define LATIN1_H
#include <memory>



const Latin1Codec latin1;

const int _latin1Mask;


class Latin1Codec : Encoding {
public:

     Latin1Codec(bool allowInvalid);

    String name();

    Uint8List encode(String source);

    String decode(bool allowInvalid, List<int> bytes);

    Latin1Encoder encoder();

    Latin1Decoder decoder();

private:
    bool _allowInvalid;


};

class Latin1Encoder : _UnicodeSubsetEncoder {
public:

     Latin1Encoder();

private:

};

class Latin1Decoder : _UnicodeSubsetDecoder {
public:

     Latin1Decoder(bool allowInvalid);

    ByteConversionSink startChunkedConversion(Sink<String> sink);

private:

};

class _Latin1DecoderSink : ByteConversionSinkBase {
public:

    void close();

    void add(List<int> source);

    void addSlice(int end, bool isLast, List<int> source, int start);

private:
    StringConversionSink _sink;


     _Latin1DecoderSink(StringConversionSink _sink);

    void _addSliceToSink(int end, bool isLast, List<int> source, int start);

    static void _checkValidLatin1(int end, List<int> source, int start);

    static void _reportInvalidLatin1(int end, List<int> source, int start);

};

class _Latin1AllowInvalidDecoderSink : _Latin1DecoderSink {
public:

    void addSlice(int end, bool isLast, List<int> source, int start);

private:

     _Latin1AllowInvalidDecoderSink(StringConversionSink sink);

};

#endif