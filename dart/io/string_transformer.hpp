#ifndef STRING_TRANSFORMER_H
#define STRING_TRANSFORMER_H
#include <memory>



const SystemEncoding systemEncoding;


class SystemEncoding : Encoding {
public:

     SystemEncoding();

    String name();

    List<int> encode(String input);

    String decode(List<int> encoded);

    Converter<String, List<int>> encoder();

    Converter<List<int>, String> decoder();

private:

};

class _WindowsCodePageEncoder : Converter<String, List<int>> {
public:

    List<int> convert(String input);

    StringConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

     _WindowsCodePageEncoder();

    external static List<int> _encodeString(String string);

};

class _WindowsCodePageEncoderSink : StringConversionSinkBase {
public:

    void close();

    void add(String string);

    void addSlice(int end, bool isLast, String source, int start);

private:
    Sink<List<int>> _sink;


     _WindowsCodePageEncoderSink(Sink<List<int>> _sink);

};

class _WindowsCodePageDecoder : Converter<List<int>, String> {
public:

    String convert(List<int> input);

    ByteConversionSink startChunkedConversion(Sink<String> sink);

private:

     _WindowsCodePageDecoder();

    external static String _decodeBytes(List<int> bytes);

};

class _WindowsCodePageDecoderSink : ByteConversionSinkBase {
public:

    void close();

    void add(List<int> bytes);

private:
    Sink<String> _sink;


     _WindowsCodePageDecoderSink(Sink<String> _sink);

};

#endif