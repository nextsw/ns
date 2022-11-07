#ifndef STDIO_H
#define STDIO_H
#include <memory>



const int _stdioHandleTypeTerminal;

const int _stdioHandleTypePipe;

const int _stdioHandleTypeFile;

const int _stdioHandleTypeSocket;

const int _stdioHandleTypeOther;

const int _stdioHandleTypeError;


class _StdStream : Stream<List<int>> {
public:

    StreamSubscription<List<int>> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:
    Stream<List<int>> _stream;


     _StdStream(Stream<List<int>> _stream);

};

class Stdin : _StdStream {
public:

    String readLineSync(Encoding encoding, bool retainNewlines);

    external bool echoMode();

    external void  echoMode(bool echoMode);

    external bool echoNewlineMode();

    external void  echoNewlineMode(bool echoNewlineMode);

    external bool lineMode();

    external void  lineMode(bool lineMode);

    external bool supportsAnsiEscapes();

    external int readByteSync();

    bool hasTerminal();

private:
    int _fd;


    void  _(int _fd, Stream<List<int>> stream);

};

class Stdout : _StdSink {
public:

    bool hasTerminal();

    int terminalColumns();

    int terminalLines();

    bool supportsAnsiEscapes();

    IOSink nonBlocking();

private:
    int _fd;

    IOSink _nonBlocking;


    void  _(int _fd, IOSink sink);

    external bool _hasTerminal(int fd);

    external int _terminalColumns(int fd);

    external int _terminalLines(int fd);

    external static bool _supportsAnsiEscapes(int fd);

};

class StdoutException {
public:
    String message;

    OSError osError;


     StdoutException(String message, OSError osError);

    String toString();

private:

};

class StdinException {
public:
    String message;

    OSError osError;


     StdinException(String message, OSError osError);

    String toString();

private:

};

class _StdConsumer {
public:

    Future addStream(Stream<List<int>> stream);

    Future close();

private:
    auto  _file;


     _StdConsumer(int fd);

};

class _StdSink {
public:

    Encoding encoding();

    void encoding(Encoding encoding);

    void write(Object object);

    void writeln(Object object);

    void writeAll(Iterable objects, String sep);

    void add(List<int> data);

    void addError(error , StackTrace stackTrace);

    void writeCharCode(int charCode);

    Future addStream(Stream<List<int>> stream);

    Future flush();

    Future close();

    Future done();

private:
    IOSink _sink;


     _StdSink(IOSink _sink);

};

class StdioType {
public:
    static const StdioType terminal;

    static const StdioType pipe;

    static const StdioType file;

    static const StdioType other;

    String name;


    String toString();

private:

    void  _(String name);

};
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


class _StdIOUtils {
public:

private:

    external static void  _getStdioOutputStream(int fd);

    external static Stdin _getStdioInputStream(int fd);

    external static int _socketType(Socket socket);

    external static void  _getStdioHandleType(int fd);

};

#endif