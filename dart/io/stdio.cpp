#include "stdio.hpp"
StreamSubscription<List<int>> _StdStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return _stream.listen(onDataonError, onDone, cancelOnError);
}

String Stdin::readLineSync(Encoding encoding, bool retainNewlines) {
    const CR = 13;
    const LF = 10;
    List<int> line = ;
    bool crIsNewline = Platform.isWindows && (stdioType(stdin) == StdioType.terminal) && !lineMode;
    if (retainNewlines) {
        int byte;
        do {
            byte = readByteSync();
            if ( < 0) {
                                break;
            }
            line.add(byte);
        } while (byte != LF && !(byte == CR && crIsNewline));
        if (line.isEmpty) {
            return nullptr;
        }
    } else     {
        if (crIsNewline) {
        while (true) {
            int byte = readByteSync();
            if ( < 0) {
                if (line.isEmpty)                 {
                    return nullptr;
                }
                                break;
            }
            if (byte == LF || byte == CR)             {
                            break;
            }
            line.add(byte);
        }
    } else {
        ;
        while (true) {
            int byte = readByteSync();
            if (byte == LF)             {
                            break;
            }
            if (byte == CR) {
                do {
                    byte = readByteSync();
                    if (byte == LF)                     {
                                            break outer;
                    }
                    line.add(CR);
                } while (byte == CR);
            }
            if ( < 0) {
                if (line.isEmpty)                 {
                    return nullptr;
                }
                                break;
            }
            line.add(byte);
        }
    }
;
    }    return encoding.decode(line);
}

bool Stdin::hasTerminal() {
    ;
}

void Stdin::_(int _fd, Stream<List<int>> stream)

bool Stdout::hasTerminal() {
    return _hasTerminal(_fd);
}

int Stdout::terminalColumns() {
    return _terminalColumns(_fd);
}

int Stdout::terminalLines() {
    return _terminalLines(_fd);
}

bool Stdout::supportsAnsiEscapes() {
    return _supportsAnsiEscapes(_fd);
}

IOSink Stdout::nonBlocking() {
    return _nonBlocking ??= IOSink(_FileStreamConsumer.fromStdio(_fd));
}

void Stdout::_(int _fd, IOSink sink)

String StdoutException::toString() {
    return "StdoutException: $message${osError == null ? "" : ", $osError"}";
}

String StdinException::toString() {
    return "StdinException: $message${osError == null ? "" : ", $osError"}";
}

Future _StdConsumer::addStream(Stream<List<int>> stream) {
    auto completer = Completer();
    auto sub;
    sub = stream.listen(completer.completeError, completer.complete, true);
    return completer.future;
}

Future _StdConsumer::close() {
    _file.closeSync();
    return Future.value();
}

_StdConsumer::_StdConsumer(int fd) {
    {
        _file = _File._openStdioSync(fd);
    }
}

Encoding _StdSink::encoding() {
    return _sink.encoding;
}

void _StdSink::encoding(Encoding encoding) {
    _sink.encoding = encoding;
}

void _StdSink::write(Object object) {
    _sink.write(object);
}

void _StdSink::writeln(Object object) {
    _sink.writeln(object);
}

void _StdSink::writeAll(Iterable objects, String sep) {
    _sink.writeAll(objects, sep);
}

void _StdSink::add(List<int> data) {
    _sink.add(data);
}

void _StdSink::addError(error , StackTrace stackTrace) {
    _sink.addError(error, stackTrace);
}

void _StdSink::writeCharCode(int charCode) {
    _sink.writeCharCode(charCode);
}

Future _StdSink::addStream(Stream<List<int>> stream) {
    return _sink.addStream(stream);
}

Future _StdSink::flush() {
    return _sink.flush();
}

Future _StdSink::close() {
    return _sink.close();
}

Future _StdSink::done() {
    return _sink.done;
}

String StdioType::toString() {
    return "StdioType: $name";
}

void _setStdioFDs(int stderr, int stdin, int stdout) {
    _stdinFD = stdin;
    _stdoutFD = stdout;
    _stderrFD = stderr;
}

Stdin stdin() {
    return IOOverrides.current?.stdin ?? _stdin;
}

Stdout stdout() {
    return IOOverrides.current?.stdout ?? _stdout;
}

Stdout stderr() {
    return IOOverrides.current?.stderr ?? _stderr;
}

StdioType stdioType(object ) {
    if (object is _StdStream) {
        object = object._stream;
    } else     {
        if (object == stdout || object == stderr) {
        int stdiofd = object == stdout? _stdoutFD : _stderrFD;
        Unknown type = _StdIOUtils._getStdioHandleType(stdiofd);
        if (type is OSError) {
            ;
        }
        ;
    }
;
    }    if (object is _FileStream) {
        return StdioType.file;
    }
    if (object is Socket) {
        int socketType = _StdIOUtils._socketType(object);
        if (socketType == nullptr)         {
            return StdioType.other;
        }
        ;
    }
    if (object is _IOSinkImpl) {
        ;
    }
    return StdioType.other;
}
