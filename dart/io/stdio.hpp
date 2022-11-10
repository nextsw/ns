#ifndef DART_IO_STDIO
#define DART_IO_STDIO
#include <base.hpp>

#include <dart/core/core.hpp>

int _stdioHandleTypeTerminal;

int _stdioHandleTypePipe;

int _stdioHandleTypeFile;

int _stdioHandleTypeSocket;

int _stdioHandleTypeOther;

int _stdioHandleTypeError;


class _StdStreamCls : public StreamCls<List<int>> {
public:

    virtual StreamSubscription<List<int>> listen(bool cancelOnError, void onData(List<int> event) , void onDone() , void  onError() );

private:
    Stream<List<int>> _stream;


     _StdStreamCls(Stream<List<int>> _stream);
};
using _StdStream = std::shared_ptr<_StdStreamCls>;

class StdinCls : public _StdStreamCls {
public:

    virtual String readLineSync(Encoding encoding, bool retainNewlines);

    bool echoMode();
    void  echoMode(bool echoMode);
    bool echoNewlineMode();
    void  echoNewlineMode(bool echoNewlineMode);
    bool lineMode();
    void  lineMode(bool lineMode);
    bool supportsAnsiEscapes();
    int readByteSync();
    virtual bool hasTerminal();

private:
    int _fd;


    virtual void  _(int _fd, Stream<List<int>> stream);

};
using Stdin = std::shared_ptr<StdinCls>;

class StdoutCls : public _StdSinkCls {
public:

    virtual bool hasTerminal();

    virtual int terminalColumns();

    virtual int terminalLines();

    virtual bool supportsAnsiEscapes();

    virtual IOSink nonBlocking();

private:
    int _fd;

    IOSink _nonBlocking;


    virtual void  _(int _fd, IOSink sink);

    bool _hasTerminal(int fd);
    int _terminalColumns(int fd);
    int _terminalLines(int fd);
    static bool _supportsAnsiEscapes(int fd);
};
using Stdout = std::shared_ptr<StdoutCls>;

class StdoutExceptionCls : public ObjectCls {
public:
    String message;

    OSError osError;


     StdoutExceptionCls(String message, OSError osError);
    virtual String toString();

private:

};
using StdoutException = std::shared_ptr<StdoutExceptionCls>;

class StdinExceptionCls : public ObjectCls {
public:
    String message;

    OSError osError;


     StdinExceptionCls(String message, OSError osError);
    virtual String toString();

private:

};
using StdinException = std::shared_ptr<StdinExceptionCls>;

class _StdConsumerCls : public ObjectCls {
public:

    virtual Future addStream(Stream<List<int>> stream);

    virtual Future close();

private:
    auto  _file;


     _StdConsumerCls(int fd);

};
using _StdConsumer = std::shared_ptr<_StdConsumerCls>;

class _StdSinkCls : public ObjectCls {
public:

    virtual Encoding encoding();

    virtual void encoding(Encoding encoding);

    virtual void write(Object object);

    virtual void writeln(Object object);

    virtual void writeAll(Iterable objects, String sep);

    virtual void add(List<int> data);

    virtual void addError(error , StackTrace stackTrace);

    virtual void writeCharCode(int charCode);

    virtual Future addStream(Stream<List<int>> stream);

    virtual Future flush();

    virtual Future close();

    virtual Future done();

private:
    IOSink _sink;


     _StdSinkCls(IOSink _sink);
};
using _StdSink = std::shared_ptr<_StdSinkCls>;

class StdioTypeCls : public ObjectCls {
public:
    static StdioType terminal;

    static StdioType pipe;

    static StdioType file;

    static StdioType other;

    String name;


    virtual String toString();

private:

    virtual void  _(String name);
};
using StdioType = std::shared_ptr<StdioTypeCls>;
Stdin _stdin;

Stdout _stdout;

Stdout _stderr;

int _stdinFD;

int _stdoutFD;

int _stderrFD;

void _setStdioFDs(int stderr, int stdin, int stdout);

Stdin stdin();

Stdout stdout();

Stdout stderr();

StdioType stdioType(object );


class _StdIOUtilsCls : public ObjectCls {
public:

private:

    static void  _getStdioOutputStream(int fd);
    static Stdin _getStdioInputStream(int fd);
    static int _socketType(Socket socket);
    static void  _getStdioHandleType(int fd);
};
using _StdIOUtils = std::shared_ptr<_StdIOUtilsCls>;


#endif