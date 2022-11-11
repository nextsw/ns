#ifndef DART_CONVERT_STRING_CONVERSION
#define DART_CONVERT_STRING_CONVERSION
#include <base.hpp>

#include <dart/core/core.hpp>


class StringConversionSinkCls : public ChunkedConversionSinkCls<String> {
public:

     StringConversionSinkCls();
    virtual void  withCallback(std::function<void(String accumulated)> callback) override;
    virtual void  from(Sink<String> sink);
    virtual void  fromStringSink(StringSink sink);
    virtual void addSlice(String chunk, int start, int end, bool isLast);
    virtual ByteConversionSink asUtf8Sink(bool allowMalformed);
    virtual ClosableStringSink asStringSink();
private:

};
using StringConversionSink = std::shared_ptr<StringConversionSinkCls>;

class ClosableStringSinkCls : public StringSinkCls {
public:

    virtual void  fromStringSink(StringSink sink, std::function<void()> onClose);
    virtual void close();
private:

};
using ClosableStringSink = std::shared_ptr<ClosableStringSinkCls>;

class _ClosableStringSinkCls : public ObjectCls {
public:

    virtual void close();

    virtual void writeCharCode(int charCode);

    virtual void write(Object o);

    virtual void writeln(Object o);

    virtual void writeAll(Iterable<any> objects, String separator);

private:
    std::function<void()> _callback;

    StringSink _sink;


     _ClosableStringSinkCls(StringSink _sink, std::function<void()> _callback);
};
using _ClosableStringSink = std::shared_ptr<_ClosableStringSinkCls>;

class _StringConversionSinkAsStringSinkAdapterCls : public ObjectCls {
public:

    virtual void close();

    virtual void writeCharCode(int charCode);

    virtual void write(Object o);

    virtual void writeln(Object o);

    virtual void writeAll(Iterable<any> objects, String separator);

private:
    static auto  _MIN_STRING_SIZE;

    StringBuffer _buffer;

    StringConversionSink _chunkedSink;


     _StringConversionSinkAsStringSinkAdapterCls(StringConversionSink _chunkedSink);

    virtual void _flush();

};
using _StringConversionSinkAsStringSinkAdapter = std::shared_ptr<_StringConversionSinkAsStringSinkAdapterCls>;

class StringConversionSinkBaseCls : public StringConversionSinkMixinCls {
public:

private:

};
using StringConversionSinkBase = std::shared_ptr<StringConversionSinkBaseCls>;

class StringConversionSinkMixinCls : public ObjectCls {
public:

    virtual void addSlice(String str, int start, int end, bool isLast);
    virtual void close();
    virtual void add(String str);

    virtual ByteConversionSink asUtf8Sink(bool allowMalformed);

    virtual ClosableStringSink asStringSink();

private:

};
using StringConversionSinkMixin = std::shared_ptr<StringConversionSinkMixinCls>;

template<typename TStringSink>
class _StringSinkConversionSinkCls : public StringConversionSinkBaseCls {
public:

    virtual void close();

    virtual void addSlice(String str, int start, int end, bool isLast);

    virtual void add(String str);

    virtual ByteConversionSink asUtf8Sink(bool allowMalformed);

    virtual ClosableStringSink asStringSink();

private:
    TStringSink _stringSink;


     _StringSinkConversionSinkCls(TStringSink _stringSink);
};
template<typename TStringSink>
using _StringSinkConversionSink = std::shared_ptr<_StringSinkConversionSinkCls<TStringSink>>;

class _StringCallbackSinkCls : public _StringSinkConversionSinkCls<StringBuffer> {
public:

    virtual void close();

    virtual ByteConversionSink asUtf8Sink(bool allowMalformed);

private:
    std::function<void(String )> _callback;


     _StringCallbackSinkCls(std::function<void(String )> _callback);

};
using _StringCallbackSink = std::shared_ptr<_StringCallbackSinkCls>;

class _StringAdapterSinkCls : public StringConversionSinkBaseCls {
public:

    virtual void add(String str);

    virtual void addSlice(String str, int start, int end, bool isLast);

    virtual void close();

private:
    Sink<String> _sink;


     _StringAdapterSinkCls(Sink<String> _sink);
};
using _StringAdapterSink = std::shared_ptr<_StringAdapterSinkCls>;

class _Utf8StringSinkAdapterCls : public ByteConversionSinkCls {
public:

    virtual void close();

    virtual void add(List<int> chunk);

    virtual void addSlice(List<int> codeUnits, int startIndex, int endIndex, bool isLast);

private:
    _Utf8Decoder _decoder;

    Sink<Object> _sink;

    StringSink _stringSink;


     _Utf8StringSinkAdapterCls(Sink<Object> _sink, StringSink _stringSink, bool allowMalformed);

};
using _Utf8StringSinkAdapter = std::shared_ptr<_Utf8StringSinkAdapterCls>;

class _Utf8ConversionSinkCls : public ByteConversionSinkCls {
public:

    virtual void close();

    virtual void add(List<int> chunk);

    virtual void addSlice(List<int> chunk, int startIndex, int endIndex, bool isLast);

private:
    _Utf8Decoder _decoder;

    StringConversionSink _chunkedSink;

    StringBuffer _buffer;


     _Utf8ConversionSinkCls(StringConversionSink sink, bool allowMalformed);

    virtual void  _(StringConversionSink _chunkedSink, StringBuffer stringBuffer, bool allowMalformed);

};
using _Utf8ConversionSink = std::shared_ptr<_Utf8ConversionSinkCls>;


#endif