#ifndef DART_CONVERT_LATIN1
#define DART_CONVERT_LATIN1
#include <base.hpp>

#include <dart/core/core.hpp>

Latin1Codec latin1;

int _latin1Mask;


class Latin1CodecCls : public EncodingCls {
public:

     Latin1CodecCls(bool allowInvalid);

    virtual String name();

    virtual Uint8List encode(String source);

    virtual String decode(List<int> bytes, bool allowInvalid);

    virtual Latin1Encoder encoder();

    virtual Latin1Decoder decoder();

private:
    bool _allowInvalid;


};
using Latin1Codec = std::shared_ptr<Latin1CodecCls>;

class Latin1EncoderCls : public _UnicodeSubsetEncoderCls {
public:

     Latin1EncoderCls();

private:

};
using Latin1Encoder = std::shared_ptr<Latin1EncoderCls>;

class Latin1DecoderCls : public _UnicodeSubsetDecoderCls {
public:

     Latin1DecoderCls(bool allowInvalid);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink);

private:

};
using Latin1Decoder = std::shared_ptr<Latin1DecoderCls>;

class _Latin1DecoderSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void close();

    virtual void add(List<int> source);

    virtual void addSlice(List<int> source, int start, int end, bool isLast);

private:
    StringConversionSink _sink;


     _Latin1DecoderSinkCls(StringConversionSink _sink);
    virtual void _addSliceToSink(List<int> source, int start, int end, bool isLast);

    static void _checkValidLatin1(List<int> source, int start, int end);

    static void _reportInvalidLatin1(List<int> source, int start, int end);

};
using _Latin1DecoderSink = std::shared_ptr<_Latin1DecoderSinkCls>;

class _Latin1AllowInvalidDecoderSinkCls : public _Latin1DecoderSinkCls {
public:

    virtual void addSlice(List<int> source, int start, int end, bool isLast);

private:

     _Latin1AllowInvalidDecoderSinkCls(StringConversionSink sink);

};
using _Latin1AllowInvalidDecoderSink = std::shared_ptr<_Latin1AllowInvalidDecoderSinkCls>;


#endif