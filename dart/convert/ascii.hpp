#ifndef DART_CONVERT_ASCII
#define DART_CONVERT_ASCII
#include <base.hpp>

#include <dart/core/core.hpp>

AsciiCodec ascii;

int _asciiMask;


class AsciiCodecCls : public EncodingCls {
public:

     AsciiCodecCls(bool allowInvalid);

    virtual String name();

    virtual Uint8List encode(String source);

    virtual String decode(List<int> bytes, bool allowInvalid);

    virtual AsciiEncoder encoder();

    virtual AsciiDecoder decoder();

private:
    bool _allowInvalid;


};
using AsciiCodec = std::shared_ptr<AsciiCodecCls>;

class _UnicodeSubsetEncoderCls : public ConverterCls<String, List<int>> {
public:

    virtual Uint8List convert(String stringValue, int start, int end);

    virtual StringConversionSink startChunkedConversion(Sink<List<int>> sink);

    virtual Stream<List<int>> bind(Stream<String> stream);

private:
    int _subsetMask;


     _UnicodeSubsetEncoderCls(int _subsetMask);
};
using _UnicodeSubsetEncoder = std::shared_ptr<_UnicodeSubsetEncoderCls>;

class AsciiEncoderCls : public _UnicodeSubsetEncoderCls {
public:

     AsciiEncoderCls();

private:

};
using AsciiEncoder = std::shared_ptr<AsciiEncoderCls>;

class _UnicodeSubsetEncoderSinkCls : public StringConversionSinkBaseCls {
public:

    virtual void close();

    virtual void addSlice(String source, int start, int end, bool isLast);

private:
    ByteConversionSink _sink;

    int _subsetMask;


     _UnicodeSubsetEncoderSinkCls(int _subsetMask, ByteConversionSink _sink);
};
using _UnicodeSubsetEncoderSink = std::shared_ptr<_UnicodeSubsetEncoderSinkCls>;

class _UnicodeSubsetDecoderCls : public ConverterCls<List<int>, String> {
public:

    virtual String convert(List<int> bytes, int start, int end);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink) override;
    virtual Stream<String> bind(Stream<List<int>> stream);

private:
    bool _allowInvalid;

    int _subsetMask;


     _UnicodeSubsetDecoderCls(bool _allowInvalid, int _subsetMask);
    virtual String _convertInvalid(List<int> bytes, int start, int end);

};
using _UnicodeSubsetDecoder = std::shared_ptr<_UnicodeSubsetDecoderCls>;

class AsciiDecoderCls : public _UnicodeSubsetDecoderCls {
public:

     AsciiDecoderCls(bool allowInvalid);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink);

private:

};
using AsciiDecoder = std::shared_ptr<AsciiDecoderCls>;

class _ErrorHandlingAsciiDecoderSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void close();

    virtual void add(List<int> source);

    virtual void addSlice(List<int> source, int start, int end, bool isLast);

private:
    ByteConversionSink _utf8Sink;


     _ErrorHandlingAsciiDecoderSinkCls(ByteConversionSink _utf8Sink);
};
using _ErrorHandlingAsciiDecoderSink = std::shared_ptr<_ErrorHandlingAsciiDecoderSinkCls>;

class _SimpleAsciiDecoderSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void close();

    virtual void add(List<int> source);

    virtual void addSlice(List<int> source, int start, int end, bool isLast);

private:
    Sink<any> _sink;


     _SimpleAsciiDecoderSinkCls(Sink<any> _sink);
};
using _SimpleAsciiDecoderSink = std::shared_ptr<_SimpleAsciiDecoderSinkCls>;


#endif