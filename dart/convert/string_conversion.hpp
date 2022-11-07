#ifndef STRING_CONVERSION_H
#define STRING_CONVERSION_H
#include <memory>




class StringConversionSink : ChunkedConversionSink<String> {
public:

     StringConversionSink();

    void  withCallback(FunctionType callback);

    void  from(Sink<String> sink);

    void  fromStringSink(StringSink sink);

    void addSlice(String chunk, int end, bool isLast, int start);

    ByteConversionSink asUtf8Sink(bool allowMalformed);

    ClosableStringSink asStringSink();

private:

};

class ClosableStringSink : StringSink {
public:

    void  fromStringSink(FunctionType onClose, StringSink sink);

    void close();

private:

};

class _ClosableStringSink {
public:

    void close();

    void writeCharCode(int charCode);

    void write(Object o);

    void writeln(Object o);

    void writeAll(Iterable objects, String separator);

private:
    FunctionType _callback;

    StringSink _sink;


     _ClosableStringSink(FunctionType _callback, StringSink _sink);

};

class _StringConversionSinkAsStringSinkAdapter {
public:

    void close();

    void writeCharCode(int charCode);

    void write(Object o);

    void writeln(Object o);

    void writeAll(Iterable objects, String separator);

private:
    static const auto  _MIN_STRING_SIZE;

    StringBuffer _buffer;

    StringConversionSink _chunkedSink;


     _StringConversionSinkAsStringSinkAdapter(StringConversionSink _chunkedSink);

    void _flush();

};

class StringConversionSinkBase : StringConversionSinkMixin {
public:

private:

};

class StringConversionSinkMixin {
public:

    void addSlice(int end, bool isLast, int start, String str);

    void close();

    void add(String str);

    ByteConversionSink asUtf8Sink(bool allowMalformed);

    ClosableStringSink asStringSink();

private:

};

class _StringSinkConversionSink<TStringSink extends StringSink> : StringConversionSinkBase {
public:

    void close();

    void addSlice(int end, bool isLast, int start, String str);

    void add(String str);

    ByteConversionSink asUtf8Sink(bool allowMalformed);

    ClosableStringSink asStringSink();

private:
    TStringSink _stringSink;


     _StringSinkConversionSink(TStringSink _stringSink);

};

class _StringCallbackSink : _StringSinkConversionSink<StringBuffer> {
public:

    void close();

    ByteConversionSink asUtf8Sink(bool allowMalformed);

private:
    FunctionType _callback;


     _StringCallbackSink(FunctionType _callback);

};

class _StringAdapterSink : StringConversionSinkBase {
public:

    void add(String str);

    void addSlice(int end, bool isLast, int start, String str);

    void close();

private:
    Sink<String> _sink;


     _StringAdapterSink(Sink<String> _sink);

};

class _Utf8StringSinkAdapter : ByteConversionSink {
public:

    void close();

    void add(List<int> chunk);

    void addSlice(List<int> codeUnits, int endIndex, bool isLast, int startIndex);

private:
    _Utf8Decoder _decoder;

    Sink<Object> _sink;

    StringSink _stringSink;


     _Utf8StringSinkAdapter(Sink<Object> _sink, StringSink _stringSink, bool allowMalformed);

};

class _Utf8ConversionSink : ByteConversionSink {
public:

    void close();

    void add(List<int> chunk);

    void addSlice(List<int> chunk, int endIndex, bool isLast, int startIndex);

private:
    _Utf8Decoder _decoder;

    StringConversionSink _chunkedSink;

    StringBuffer _buffer;


     _Utf8ConversionSink(bool allowMalformed, StringConversionSink sink);

    void  _(StringConversionSink _chunkedSink, bool allowMalformed, StringBuffer stringBuffer);

};

#endif