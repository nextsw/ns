#ifndef DART_IO_STRING_TRANSFORMER
#define DART_IO_STRING_TRANSFORMER
#include <base.hpp>

#include <dart/core/core.hpp>

SystemEncoding systemEncoding;


class SystemEncodingCls : public EncodingCls {
public:

     SystemEncodingCls();
    virtual String name();

    virtual List<int> encode(String input);

    virtual String decode(List<int> encoded);

    virtual Converter<String, List<int>> encoder();

    virtual Converter<List<int>, String> decoder();

private:

};
using SystemEncoding = std::shared_ptr<SystemEncodingCls>;

class _WindowsCodePageEncoderCls : public ConverterCls<String, List<int>> {
public:

    virtual List<int> convert(String input);

    virtual StringConversionSink startChunkedConversion(Sink<List<int>> sink);

private:

     _WindowsCodePageEncoderCls();
    static List<int> _encodeString(String stringValue);
};
using _WindowsCodePageEncoder = std::shared_ptr<_WindowsCodePageEncoderCls>;

class _WindowsCodePageEncoderSinkCls : public StringConversionSinkBaseCls {
public:

    virtual void close();

    virtual void add(String stringValue);

    virtual void addSlice(String source, int start, int end, bool isLast);

private:
    Sink<List<int>> _sink;


     _WindowsCodePageEncoderSinkCls(Sink<List<int>> _sink);
};
using _WindowsCodePageEncoderSink = std::shared_ptr<_WindowsCodePageEncoderSinkCls>;

class _WindowsCodePageDecoderCls : public ConverterCls<List<int>, String> {
public:

    virtual String convert(List<int> input);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink);

private:

     _WindowsCodePageDecoderCls();
    static String _decodeBytes(List<int> bytes);
};
using _WindowsCodePageDecoder = std::shared_ptr<_WindowsCodePageDecoderCls>;

class _WindowsCodePageDecoderSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void close();

    virtual void add(List<int> bytes);

private:
    Sink<String> _sink;


     _WindowsCodePageDecoderSinkCls(Sink<String> _sink);
};
using _WindowsCodePageDecoderSink = std::shared_ptr<_WindowsCodePageDecoderSinkCls>;


#endif