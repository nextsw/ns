#ifndef IO_SINK_H
#define IO_SINK_H
#include <memory>




class IOSink {
public:
    Encoding encoding;


     IOSink(Encoding encoding, StreamConsumer<List<int>> target);

    void add(List<int> data);

    void write(Object object);

    void writeAll(Iterable objects, String separator);

    void writeln(Object object);

    void writeCharCode(int charCode);

    void addError(error , StackTrace stackTrace);

    Future addStream(Stream<List<int>> stream);

    Future flush();

    Future close();

    Future done();

private:

};

class _StreamSinkImpl<T> {
public:

    void add(T data);

    void addError(error , StackTrace stackTrace);

    Future addStream(Stream<T> stream);

    Future flush();

    Future close();

    Future done();

private:
    StreamConsumer<T> _target;

    Completer _doneCompleter;

    StreamController<T> _controllerInstance;

    Completer _controllerCompleter;

    bool _isClosed;

    bool _isBound;

    bool _hasError;


     _StreamSinkImpl(StreamConsumer<T> _target);

    void _closeTarget();

    void _completeDoneValue(value );

    void _completeDoneError(error , StackTrace stackTrace);

    StreamController<T> _controller();

};

class _IOSinkImpl : _StreamSinkImpl<List<int>> {
public:

    Encoding encoding();

    void encoding(Encoding value);

    void write(Object obj);

    void writeAll(Iterable objects, String separator);

    void writeln(Object object);

    void writeCharCode(int charCode);

private:
    Encoding _encoding;

    bool _encodingMutable;


     _IOSinkImpl(Encoding _encoding, StreamConsumer<List<int>> target);

};

#endif