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

    virtual String decode(bool allowInvalid, List<int> bytes);

    virtual AsciiEncoder encoder();

    virtual AsciiDecoder decoder();

private:
    bool _allowInvalid;


};
using AsciiCodec = std::shared_ptr<AsciiCodecCls>;

class _UnicodeSubsetEncoderCls : public ConverterCls<String, List<int>> {
public:

    virtual Uint8List convert(int end, int start, String stringValue);

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

    virtual void addSlice(int end, bool isLast, String source, int start);

private:
    ByteConversionSink _sink;

    int _subsetMask;


     _UnicodeSubsetEncoderSinkCls(ByteConversionSink _sink, int _subsetMask);
};
using _UnicodeSubsetEncoderSink = std::shared_ptr<_UnicodeSubsetEncoderSinkCls>;

class _UnicodeSubsetDecoderCls : public ConverterCls<List<int>, String> {
public:

    virtual String convert(List<int> bytes, int end, int start);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink) override;
    virtual Stream<String> bind(Stream<List<int>> stream);

private:
    bool _allowInvalid;

    int _subsetMask;


     _UnicodeSubsetDecoderCls(bool _allowInvalid, int _subsetMask);
    virtual String _convertInvalid(List<int> bytes, int end, int start);

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

    virtual void addSlice(int end, bool isLast, List<int> source, int start);

private:
    ByteConversionSink _utf8Sink;


     _ErrorHandlingAsciiDecoderSinkCls(ByteConversionSink _utf8Sink);
};
using _ErrorHandlingAsciiDecoderSink = std::shared_ptr<_ErrorHandlingAsciiDecoderSinkCls>;

class _SimpleAsciiDecoderSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void close();

    virtual void add(List<int> source);

    virtual void addSlice(int end, bool isLast, List<int> source, int start);

private:
    Sink _sink;


     _SimpleAsciiDecoderSinkCls(Sink _sink);
};
using _SimpleAsciiDecoderSink = std::shared_ptr<_SimpleAsciiDecoderSinkCls>;


#endif