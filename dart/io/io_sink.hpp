#ifndef DART_IO_IO_SINK
#define DART_IO_IO_SINK
#include <base.hpp>

#include <dart/core/core.hpp>


class IOSinkCls : public ObjectCls {
public:
    Encoding encoding;


     IOSinkCls(Encoding encoding, StreamConsumer<List<int>> target);

    virtual void add(List<int> data);
    virtual void write(Object object);
    virtual void writeAll(Iterable objects, String separator);
    virtual void writeln(Object object);
    virtual void writeCharCode(int charCode);
    virtual void addError(error , StackTrace stackTrace);
    virtual Future addStream(Stream<List<int>> stream);
    virtual Future flush();
    virtual Future close();
    virtual Future done();
private:

};
using IOSink = std::shared_ptr<IOSinkCls>;

template<typename T> class _StreamSinkImplCls : public ObjectCls {
public:

    virtual void add(T data);

    virtual void addError(error , StackTrace stackTrace);

    virtual Future addStream(Stream<T> stream);

    virtual Future flush();

    virtual Future close();

    virtual Future done();

private:
    StreamConsumer<T> _target;

    Completer _doneCompleter;

    StreamController<T> _controllerInstance;

    Completer _controllerCompleter;

    bool _isClosed;

    bool _isBound;

    bool _hasError;


     _StreamSinkImplCls(StreamConsumer<T> _target);
    virtual void _closeTarget();

    virtual void _completeDoneValue(value );

    virtual void _completeDoneError(error , StackTrace stackTrace);

    virtual StreamController<T> _controller();

};
template<typename T> using _StreamSinkImpl = std::shared_ptr<_StreamSinkImplCls<T>>;

class _IOSinkImplCls : public _StreamSinkImplCls<List<int>> {
public:

    virtual Encoding encoding();

    virtual void encoding(Encoding value);

    virtual void write(Object obj);

    virtual void writeAll(Iterable objects, String separator);

    virtual void writeln(Object object);

    virtual void writeCharCode(int charCode);

private:
    Encoding _encoding;

    bool _encodingMutable;


     _IOSinkImplCls(Encoding _encoding, StreamConsumer<List<int>> target);

};
using _IOSinkImpl = std::shared_ptr<_IOSinkImplCls>;


#endif