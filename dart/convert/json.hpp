#ifndef DART_CONVERT_JSON
#define DART_CONVERT_JSON
#include <base.hpp>

#include <dart/core/core.hpp>


class JsonUnsupportedObjectErrorCls : public ErrorCls {
public:
    Object unsupportedObject;

    Object cause;

    String partialResult;


     JsonUnsupportedObjectErrorCls(Object unsupportedObject, Object cause, String partialResult);
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

String jsonEncode(Object object, std::function<Object(Object nonEncodable)> toEncodable);

Object jsonDecode(String source, std::function<Object(Object key, Object value)> reviver);


class JsonCodecCls : public CodecCls<Object, String> {
public:

     JsonCodecCls(std::function<Object(Object key, Object value)> reviver, std::function<Object(Object object)> toEncodable);

    virtual void  withReviver(std::function<Object(Object key, Object value)> reviver);

    virtual Object decode(String source, std::function<Object(Object key, Object value)> reviver);

    virtual String encode(Object value, std::function<Object(Object object)> toEncodable);

    virtual JsonEncoder encoder();

    virtual JsonDecoder decoder();

private:
    std::function<Object(Object key, Object value)> _reviver;

    std::function<Object(Object )> _toEncodable;


};
using JsonCodec = std::shared_ptr<JsonCodecCls>;

class JsonEncoderCls : public ConverterCls<Object, String> {
public:
    String indent;


     JsonEncoderCls(std::function<Object(Object object)> toEncodable);

    virtual void  withIndent(String indent, std::function<Object(Object object)> toEncodable);

    virtual String convert(Object object);

    virtual ChunkedConversionSink<Object> startChunkedConversion(Sink<String> sink);

    virtual Stream<String> bind(Stream<Object> stream);

    template<typename T>
 virtual Converter<Object, T> fuse(Converter<String, T> other);

private:
    std::function<Object(Object )> _toEncodable;


};
using JsonEncoder = std::shared_ptr<JsonEncoderCls>;

class JsonUtf8EncoderCls : public ConverterCls<Object, List<int>> {
public:
    static int DEFAULT_BUFFER_SIZE;


     JsonUtf8EncoderCls(String indent, std::function<Object(Object object)> toEncodable, int bufferSize);

    virtual List<int> convert(Object object);

    virtual ChunkedConversionSink<Object> startChunkedConversion(Sink<List<int>> sink);

    virtual Stream<List<int>> bind(Stream<Object> stream);

private:
    static int _defaultBufferSize;

    List<int> _indent;

    std::function<Object(Object )> _toEncodable;

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

    std::function<Object(Object )> _toEncodable;

    StringConversionSink _sink;

    bool _isDone;


     _JsonEncoderSinkCls(StringConversionSink _sink, std::function<Object(Object )> _toEncodable, String _indent);
};
using _JsonEncoderSink = std::shared_ptr<_JsonEncoderSinkCls>;

class _JsonUtf8EncoderSinkCls : public ChunkedConversionSinkCls<Object> {
public:

    virtual void add(Object object);

    virtual void close();

private:
    ByteConversionSink _sink;

    List<int> _indent;

    std::function<Object(Object )> _toEncodable;

    int _bufferSize;

    bool _isDone;


     _JsonUtf8EncoderSinkCls(ByteConversionSink _sink, std::function<Object(Object )> _toEncodable, List<int> _indent, int _bufferSize);
    virtual void _addChunk(Uint8List chunk, int start, int end);

};
using _JsonUtf8EncoderSink = std::shared_ptr<_JsonUtf8EncoderSinkCls>;

class JsonDecoderCls : public ConverterCls<String, Object> {
public:

     JsonDecoderCls(std::function<Object(Object key, Object value)> reviver);

    virtual Object convert(String input);

    StringConversionSink startChunkedConversion(Sink<Object> sink) override;
    virtual Stream<Object> bind(Stream<String> stream);

private:
    std::function<Object(Object key, Object value)> _reviver;


};
using JsonDecoder = std::shared_ptr<JsonDecoderCls>;
Object _parseJson(String source, reviver );
Object _defaultToEncodable(Object object);


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
    virtual void writeStringSlice(String characters, int start, int end);
    virtual void writeCharCode(int charCode);
    virtual void writeNumber(num number);
    static int hexDigit(int x);

    virtual void writeStringContent(String s);

    virtual void writeObject(Object object);

    virtual bool writeJsonValue(Object object);

    virtual void writeList(List<Object> list);

    virtual bool writeMap(Map<Object, Object> map);

private:
    List<any> _seen;

    std::function<void (Object )> _toEncodable;


     _JsonStringifierCls(std::function<Object(Object o)> toEncodable);

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

    static String stringify(Object object, std::function<Object(Object object)> toEncodable, String indent);

    static void printOn(Object object, StringSink output, std::function<Object(Object o)> toEncodable, String indent);

    virtual void writeNumber(num number);

    virtual void writeString(String stringValue);

    virtual void writeStringSlice(String stringValue, int start, int end);

    virtual void writeCharCode(int charCode);

private:
    StringSink _sink;


     _JsonStringStringifierCls(StringSink _sink, std::function<Object(Object object)> _toEncodable);

    virtual String _partialResult();

};
using _JsonStringStringifier = std::shared_ptr<_JsonStringStringifierCls>;

class _JsonStringStringifierPrettyCls : public _JsonStringStringifierCls {
public:

    virtual void writeIndentation(int count);

private:
    String _indent;


     _JsonStringStringifierPrettyCls(StringSink sink, std::function<Object(Object o)> toEncodable, String _indent);

};
using _JsonStringStringifierPretty = std::shared_ptr<_JsonStringStringifierPrettyCls>;

class _JsonUtf8StringifierCls : public _JsonStringifierCls {
public:
    int bufferSize;

    std::function<void(Uint8List list, int start, int end)> addChunk;

    Uint8List buffer;

    int index;


    static void stringify(Object object, List<int> indent, std::function<Object(Object o)> toEncodable, int bufferSize, std::function<void(Uint8List chunk, int start, int end)> addChunk);

    virtual void flush();

    virtual void writeNumber(num number);

    virtual void writeAsciiString(String stringValue);

    virtual void writeString(String stringValue);

    virtual void writeStringSlice(String stringValue, int start, int end);

    virtual void writeCharCode(int charCode);

    virtual void writeMultiByteCharCode(int charCode);

    virtual void writeFourByteCharCode(int charCode);

    virtual void writeByte(int byte);

private:

     _JsonUtf8StringifierCls(std::function<Object(Object o)> toEncodable, int bufferSize, std::function<void(Uint8List list, int start, int end)> addChunk);

    virtual String _partialResult();

};
using _JsonUtf8Stringifier = std::shared_ptr<_JsonUtf8StringifierCls>;

class _JsonUtf8StringifierPrettyCls : public _JsonUtf8StringifierCls {
public:
    List<int> indent;


    virtual void writeIndentation(int count);

private:

     _JsonUtf8StringifierPrettyCls(std::function<Object(Object o)> toEncodable, List<int> indent, int bufferSize, std::function<void(Uint8List buffer, int start, int end)> addChunk);

};
using _JsonUtf8StringifierPretty = std::shared_ptr<_JsonUtf8StringifierPrettyCls>;


#endif