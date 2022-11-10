#ifndef DART_CONVERT_JSON
#define DART_CONVERT_JSON
#include <base.hpp>

#include <dart/core/core.hpp>


class JsonUnsupportedObjectErrorCls : public ErrorCls {
public:
    Object unsupportedObject;

    Object cause;

    String partialResult;


     JsonUnsupportedObjectErrorCls(Object cause, String partialResult, Object unsupportedObject);
    virtual String toString();

private:

};
using JsonUnsupportedObjectError = std::shared_ptr<JsonUnsupportedObjectErrorCls>;

class JsonCyclicErrorCls : public JsonUnsupportedObjectErrorCls {
public:

     JsonCyclicErrorCls(Object object);

    virtual String toString();

private:

};
using JsonCyclicError = std::shared_ptr<JsonCyclicErrorCls>;
JsonCodec json;

String jsonEncode(Object object, Object toEncodable(Object nonEncodable) );

dynamic jsonDecode(Object reviver(Object key, Object value) , String source);


class JsonCodecCls : public CodecCls<Object, String> {
public:

     JsonCodecCls(Object reviver(Object key, Object value) , Object toEncodable(dynamic object) );

    virtual void  withReviver(dynamic reviver(Object key, Object value) );

    virtual dynamic decode(Object reviver(Object key, Object value) , String source);

    virtual String encode(Object toEncodable(dynamic object) , Object value);

    virtual JsonEncoder encoder();

    virtual JsonDecoder decoder();

private:
    Object Function(Object key, Object value) _reviver;

    Object Function(dynamic ) _toEncodable;


};
using JsonCodec = std::shared_ptr<JsonCodecCls>;

class JsonEncoderCls : public ConverterCls<Object, String> {
public:
    String indent;


     JsonEncoderCls(Object toEncodable(dynamic object) );

    virtual void  withIndent(String indent, Object toEncodable(dynamic object) );

    virtual String convert(Object object);

    virtual ChunkedConversionSink<Object> startChunkedConversion(Sink<String> sink);

    virtual Stream<String> bind(Stream<Object> stream);

    template<typename T>  virtual Converter<Object, T> fuse(Converter<String, T> other);

private:
    Object Function(dynamic ) _toEncodable;


};
using JsonEncoder = std::shared_ptr<JsonEncoderCls>;

class JsonUtf8EncoderCls : public ConverterCls<Object, List<int>> {
public:
    static int DEFAULT_BUFFER_SIZE;


     JsonUtf8EncoderCls(int bufferSize, String indent, dynamic toEncodable(dynamic object) );

    virtual List<int> convert(Object object);

    virtual ChunkedConversionSink<Object> startChunkedConversion(Sink<List<int>> sink);

    virtual Stream<List<int>> bind(Stream<Object> stream);

private:
    static int _defaultBufferSize;

    List<int> _indent;

    Object Function(dynamic ) _toEncodable;

    int _bufferSize;


    static List<int> _utf8Encode(String stringValue);

};
using JsonUtf8Encoder = std::shared_ptr<JsonUtf8EncoderCls>;

class _JsonEncoderSinkCls : public ChunkedConversionSinkCls<Object> {
public:

    virtual void add(Object o);

    virtual void close();

private:
    String _indent;

    Object Function(dynamic ) _toEncodable;

    StringConversionSink _sink;

    bool _isDone;


     _JsonEncoderSinkCls(String _indent, StringConversionSink _sink, Object Function(dynamic ) _toEncodable);
};
using _JsonEncoderSink = std::shared_ptr<_JsonEncoderSinkCls>;

class _JsonUtf8EncoderSinkCls : public ChunkedConversionSinkCls<Object> {
public:

    virtual void add(Object object);

    virtual void close();

private:
    ByteConversionSink _sink;

    List<int> _indent;

    Object Function(dynamic ) _toEncodable;

    int _bufferSize;

    bool _isDone;


     _JsonUtf8EncoderSinkCls(int _bufferSize, List<int> _indent, ByteConversionSink _sink, Object Function(dynamic ) _toEncodable);
    virtual void _addChunk(Uint8List chunk, int end, int start);

};
using _JsonUtf8EncoderSink = std::shared_ptr<_JsonUtf8EncoderSinkCls>;

class JsonDecoderCls : public ConverterCls<String, Object> {
public:

     JsonDecoderCls(Object reviver(Object key, Object value) );

    virtual dynamic convert(String input);

    StringConversionSink startChunkedConversion(Sink<Object> sink) override;
    virtual Stream<Object> bind(Stream<String> stream);

private:
    Object Function(Object key, Object value) _reviver;


};
using JsonDecoder = std::shared_ptr<JsonDecoderCls>;
dynamic _parseJson(reviver , String source);
dynamic _defaultToEncodable(dynamic object);


class _JsonStringifierCls : public ObjectCls {
public:
    static int backspace;

    static int tab;

    static int newline;

    static int carriageReturn;

    static int formFeed;

    static int quote;

    static int char_0;

    static int backslash;

    static int char_b;

    static int char_d;

    static int char_f;

    static int char_n;

    static int char_r;

    static int char_t;

    static int char_u;

    static int surrogateMin;

    static int surrogateMask;

    static int surrogateLead;

    static int surrogateTrail;


    virtual void writeString(String characters);
    virtual void writeStringSlice(String characters, int end, int start);
    virtual void writeCharCode(int charCode);
    virtual void writeNumber(num number);
    static int hexDigit(int x);

    virtual void writeStringContent(String s);

    virtual void writeObject(Object object);

    virtual bool writeJsonValue(Object object);

    virtual void writeList(List<Object> list);

    virtual bool writeMap(Map<Object, Object> map);

private:
    List _seen;

    void  Function(dynamic ) _toEncodable;


     _JsonStringifierCls(dynamic toEncodable(dynamic o) );

    virtual String _partialResult();
    virtual void _checkCycle(Object object);

    virtual void _removeSeen(Object object);

};
using _JsonStringifier = std::shared_ptr<_JsonStringifierCls>;

class _JsonPrettyPrintMixinCls : public ObjectCls {
public:

    virtual void writeIndentation(int indentLevel);
    virtual void writeList(List<Object> list);

    virtual bool writeMap(Map<Object, Object> map);

private:
    int _indentLevel;


};
using _JsonPrettyPrintMixin = std::shared_ptr<_JsonPrettyPrintMixinCls>;

class _JsonStringStringifierCls : public _JsonStringifierCls {
public:

    static String stringify(String indent, Object object, dynamic toEncodable(dynamic object) );

    static void printOn(String indent, Object object, StringSink output, dynamic toEncodable(dynamic o) );

    virtual void writeNumber(num number);

    virtual void writeString(String stringValue);

    virtual void writeStringSlice(int end, int start, String stringValue);

    virtual void writeCharCode(int charCode);

private:
    StringSink _sink;


     _JsonStringStringifierCls(StringSink _sink, dynamic _toEncodable(dynamic object) );

    virtual String _partialResult();

};
using _JsonStringStringifier = std::shared_ptr<_JsonStringStringifierCls>;

class _JsonStringStringifierPrettyCls : public _JsonStringStringifierCls {
public:

    virtual void writeIndentation(int count);

private:
    String _indent;


     _JsonStringStringifierPrettyCls(String _indent, StringSink sink, dynamic toEncodable(dynamic o) );

};
using _JsonStringStringifierPretty = std::shared_ptr<_JsonStringStringifierPrettyCls>;

class _JsonUtf8StringifierCls : public _JsonStringifierCls {
public:
    int bufferSize;

    void Function(int end, Uint8List list, int start) addChunk;

    Uint8List buffer;

    int index;


    static void stringify(void addChunk(Uint8List chunk, int end, int start) , int bufferSize, List<int> indent, Object object, dynamic toEncodable(dynamic o) );

    virtual void flush();

    virtual void writeNumber(num number);

    virtual void writeAsciiString(String stringValue);

    virtual void writeString(String stringValue);

    virtual void writeStringSlice(int end, int start, String stringValue);

    virtual void writeCharCode(int charCode);

    virtual void writeMultiByteCharCode(int charCode);

    virtual void writeFourByteCharCode(int charCode);

    virtual void writeByte(int byte);

private:

     _JsonUtf8StringifierCls(void Function(int end, Uint8List list, int start) addChunk, int bufferSize, dynamic toEncodable(dynamic o) );

    virtual String _partialResult();

};
using _JsonUtf8Stringifier = std::shared_ptr<_JsonUtf8StringifierCls>;

class _JsonUtf8StringifierPrettyCls : public _JsonUtf8StringifierCls {
public:
    List<int> indent;


    virtual void writeIndentation(int count);

private:

     _JsonUtf8StringifierPrettyCls(void addChunk(Uint8List buffer, int end, int start) , int bufferSize, List<int> indent, dynamic toEncodable(dynamic o) );

};
using _JsonUtf8StringifierPretty = std::shared_ptr<_JsonUtf8StringifierPrettyCls>;


#endif