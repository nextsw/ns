#ifndef JSON_H
#define JSON_H
#include <memory>




class JsonUnsupportedObjectError : Error {
public:
    Object unsupportedObject;

    Object cause;

    String partialResult;


     JsonUnsupportedObjectError(Object cause, String partialResult, Object unsupportedObject);

    String toString();

private:

};

class JsonCyclicError : JsonUnsupportedObjectError {
public:

     JsonCyclicError(Object object);

    String toString();

private:

};
const JsonCodec json;

String jsonEncode(Object object, FunctionType toEncodable);

dynamic jsonDecode(FunctionType reviver, String source);


class JsonCodec : Codec<Object, String> {
public:

     JsonCodec(FunctionType reviver, FunctionType toEncodable);

    void  withReviver(FunctionType reviver);

    dynamic decode(FunctionType reviver, String source);

    String encode(FunctionType toEncodable, Object value);

    JsonEncoder encoder();

    JsonDecoder decoder();

private:
    FunctionType _reviver;

    FunctionType _toEncodable;


};

class JsonEncoder : Converter<Object, String> {
public:
    String indent;


     JsonEncoder(FunctionType toEncodable);

    void  withIndent(String indent, FunctionType toEncodable);

    String convert(Object object);

    ChunkedConversionSink<Object> startChunkedConversion(Sink<String> sink);

    Stream<String> bind(Stream<Object> stream);

    Converter<Object, T> fuse<T>(Converter<String, T> other);

private:
    FunctionType _toEncodable;


};

class JsonUtf8Encoder : Converter<Object, List<int>> {
public:
    static const int DEFAULT_BUFFER_SIZE;


     JsonUtf8Encoder(int bufferSize, String indent, FunctionType toEncodable);

    List<int> convert(Object object);

    ChunkedConversionSink<Object> startChunkedConversion(Sink<List<int>> sink);

    Stream<List<int>> bind(Stream<Object> stream);

private:
    static const int _defaultBufferSize;

    List<int> _indent;

    FunctionType _toEncodable;

    int _bufferSize;


    static List<int> _utf8Encode(String string);

};

class _JsonEncoderSink : ChunkedConversionSink<Object> {
public:

    void add(Object o);

    void close();

private:
    String _indent;

    FunctionType _toEncodable;

    StringConversionSink _sink;

    bool _isDone;


     _JsonEncoderSink(String _indent, StringConversionSink _sink, FunctionType _toEncodable);

};

class _JsonUtf8EncoderSink : ChunkedConversionSink<Object> {
public:

    void add(Object object);

    void close();

private:
    ByteConversionSink _sink;

    List<int> _indent;

    FunctionType _toEncodable;

    int _bufferSize;

    bool _isDone;


     _JsonUtf8EncoderSink(int _bufferSize, List<int> _indent, ByteConversionSink _sink, FunctionType _toEncodable);

    void _addChunk(Uint8List chunk, int end, int start);

};

class JsonDecoder : Converter<String, Object> {
public:

     JsonDecoder(FunctionType reviver);

    dynamic convert(String input);

    external StringConversionSink startChunkedConversion(Sink<Object> sink);

    Stream<Object> bind(Stream<String> stream);

private:
    FunctionType _reviver;


};
external dynamic _parseJson(reviver , String source);

dynamic _defaultToEncodable(dynamic object);


class _JsonStringifier {
public:
    static const int backspace;

    static const int tab;

    static const int newline;

    static const int carriageReturn;

    static const int formFeed;

    static const int quote;

    static const int char_0;

    static const int backslash;

    static const int char_b;

    static const int char_d;

    static const int char_f;

    static const int char_n;

    static const int char_r;

    static const int char_t;

    static const int char_u;

    static const int surrogateMin;

    static const int surrogateMask;

    static const int surrogateLead;

    static const int surrogateTrail;


    void writeString(String characters);

    void writeStringSlice(String characters, int end, int start);

    void writeCharCode(int charCode);

    void writeNumber(num number);

    static int hexDigit(int x);

    void writeStringContent(String s);

    void writeObject(Object object);

    bool writeJsonValue(Object object);

    void writeList(List<Object> list);

    bool writeMap(Map<Object, Object> map);

private:
    List _seen;

    FunctionType _toEncodable;


     _JsonStringifier(FunctionType toEncodable);

    String _partialResult();

    void _checkCycle(Object object);

    void _removeSeen(Object object);

};

class _JsonPrettyPrintMixin {
public:

    void writeIndentation(int indentLevel);

    void writeList(List<Object> list);

    bool writeMap(Map<Object, Object> map);

private:
    int _indentLevel;


};

class _JsonStringStringifier : _JsonStringifier {
public:

    static String stringify(String indent, Object object, FunctionType toEncodable);

    static void printOn(String indent, Object object, StringSink output, FunctionType toEncodable);

    void writeNumber(num number);

    void writeString(String string);

    void writeStringSlice(int end, int start, String string);

    void writeCharCode(int charCode);

private:
    StringSink _sink;


     _JsonStringStringifier(StringSink _sink, FunctionType _toEncodable);

    String _partialResult();

};

class _JsonStringStringifierPretty : _JsonStringStringifier {
public:

    void writeIndentation(int count);

private:
    String _indent;


     _JsonStringStringifierPretty(String _indent, StringSink sink, FunctionType toEncodable);

};

class _JsonUtf8Stringifier : _JsonStringifier {
public:
    int bufferSize;

    FunctionType addChunk;

    Uint8List buffer;

    int index;


    static void stringify(FunctionType addChunk, int bufferSize, List<int> indent, Object object, FunctionType toEncodable);

    void flush();

    void writeNumber(num number);

    void writeAsciiString(String string);

    void writeString(String string);

    void writeStringSlice(int end, int start, String string);

    void writeCharCode(int charCode);

    void writeMultiByteCharCode(int charCode);

    void writeFourByteCharCode(int charCode);

    void writeByte(int byte);

private:

     _JsonUtf8Stringifier(FunctionType addChunk, int bufferSize, FunctionType toEncodable);

    String _partialResult();

};

class _JsonUtf8StringifierPretty : _JsonUtf8Stringifier {
public:
    List<int> indent;


    void writeIndentation(int count);

private:

     _JsonUtf8StringifierPretty(FunctionType addChunk, int bufferSize, List<int> indent, FunctionType toEncodable);

};

#endif