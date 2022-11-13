#include "stdio.hpp"
StreamSubscription<List<int>> _StdStreamCls::listen(std::function<void(List<int> event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    return _stream->listen(onData, onError, onDone, cancelOnError);
}

String StdinCls::readLineSync(Encoding encoding, bool retainNewlines) {
    CR = 13;
    LF = 10;
    List<int> line = makeList();
    bool crIsNewline = PlatformCls::isWindows && (stdioType(stdin) == StdioTypeCls::terminal) && !lineMode();
    if (retainNewlines) {
        int byte;
        do {
            byte = readByteSync();
            if ( < 0) {
                break;
            }
            line->add(byte);
        } while (byte != LF && !(byte == CR && crIsNewline));
        if (line->isEmpty()) {
            return nullptr;
        }
    } else {
        if (crIsNewline) {
        while (true) {
            int byte = readByteSync();
            if ( < 0) {
                if (line->isEmpty()) {
                    return nullptr;
                }
                break;
            }
            if (byte == LF || byte == CR) {
                break;
            }
            line->add(byte);
        }
    } else {
        outer:;
        while (true) {
            int byte = readByteSync();
            if (byte == LF) {
                break;
            }
            if (byte == CR) {
                do {
                    byte = readByteSync();
                    if (byte == LF) {
                        break outer;
                    }
                    line->add(CR);
                } while (byte == CR);
            }
            if ( < 0) {
                if (line->isEmpty()) {
                    return nullptr;
                }
                break;
            }
            line->add(byte);
        }
    }
;
    }    return encoding->decode(line);
}

bool StdinCls::hasTerminal() {
    try {
        return stdioType(this) == StdioTypeCls::terminal;
    } catch (FileSystemException _) {
        return false;
    };
}

void StdinCls::_(Stream<List<int>> stream, int _fd)

bool StdoutCls::hasTerminal() {
    return _hasTerminal(_fd);
}

int StdoutCls::terminalColumns() {
    return _terminalColumns(_fd);
}

int StdoutCls::terminalLines() {
    return _terminalLines(_fd);
}

bool StdoutCls::supportsAnsiEscapes() {
    return _supportsAnsiEscapes(_fd);
}

IOSink StdoutCls::nonBlocking() {
    return _nonBlocking ??= make<IOSinkCls>(_FileStreamConsumerCls->fromStdio(_fd));
}

void StdoutCls::_(IOSink sink, int _fd)

String StdoutExceptionCls::toString() {
    return __sf("StdoutException: %s%s", message, osError == nullptr? __s("") : __sf(", %s", osError));
}

String StdinExceptionCls::toString() {
    return __sf("StdinException: %s%s", message, osError == nullptr? __s("") : __sf(", %s", osError));
}

Future<any> _StdConsumerCls::addStream(Stream<List<int>> stream) {
    auto completer = make<CompleterCls>();
    auto sub;
    sub = stream->listen([=] (Unknown  data) {
        try {
            _file->writeFromSync(data);
        } catch (Unknown e) {
            sub->cancel();
            completer->completeError(e, s);
        };
    }, completer->completeError, completer->complete, true);
    return completer->future;
}

Future<any> _StdConsumerCls::close() {
    _file->closeSync();
    return FutureCls->value();
}

_StdConsumerCls::_StdConsumerCls(int fd) {
    {
        _file = _FileCls->_openStdioSync(fd);
    }
}

Encoding _StdSinkCls::encoding() {
    return _sink->encoding;
}

void _StdSinkCls::encoding(Encoding encoding) {
    _sink->encoding = encoding;
}

void _StdSinkCls::write(Object object) {
    _sink->write(object);
}

void _StdSinkCls::writeln(Object object) {
    _sink->writeln(object);
}

void _StdSinkCls::writeAll(Iterable<any> objects, String sep) {
    _sink->writeAll(objects, sep);
}

void _StdSinkCls::add(List<int> data) {
    _sink->add(data);
}

void _StdSinkCls::addError(error , StackTrace stackTrace) {
    _sink->addError(error, stackTrace);
}

void _StdSinkCls::writeCharCode(int charCode) {
    _sink->writeCharCode(charCode);
}

Future<any> _StdSinkCls::addStream(Stream<List<int>> stream) {
    return _sink->addStream(stream);
}

Future<any> _StdSinkCls::flush() {
    return _sink->flush();
}

Future<any> _StdSinkCls::close() {
    return _sink->close();
}

Future<any> _StdSinkCls::done() {
    return _sink->done();
}

String StdioTypeCls::toString() {
    return __sf("StdioType: %s", name);
}

void _setStdioFDs(int stdin, int stdout, int stderr) {
    _stdinFD = stdin;
    _stdoutFD = stdout;
    _stderrFD = stderr;
}

Stdin stdin() {
    return IOOverridesCls::current?->stdin | _stdin;
}

Stdout stdout() {
    return IOOverridesCls::current?->stdout | _stdout;
}

Stdout stderr() {
    return IOOverridesCls::current?->stderr | _stderr;
}

StdioType stdioType(object ) {
    if (is<_StdStream>(object)) {
        as<_StdStreamCls>(object) = as<_StdStreamCls>(object)->_stream;
    } else {
        if (object == stdout || object == stderr) {
        int stdiofd = object == stdout? _stdoutFD : _stderrFD;
        auto type = _StdIOUtilsCls->_getStdioHandleType(stdiofd);
        if (is<OSError>(type)) {
            throw make<FileSystemExceptionCls>(__sf("Failed to get type of stdio handle (fd %s)", stdiofd), __s(""), as<OSErrorCls>(type));
        }
        ;
    }
;
    }    if (is<_FileStream>(object)) {
        return StdioTypeCls::file;
    }
    if (is<Socket>(object)) {
        int socketType = _StdIOUtilsCls->_socketType(as<SocketCls>(object));
        if (socketType == nullptr) {
            return StdioTypeCls::other;
        }
        ;
    }
    if (is<_IOSinkImpl>(object)) {
        try {
            if (is<_FileStreamConsumer>(object->_target)) {
                return StdioTypeCls::file;
            }
        } catch (Unknown e) {
        };
    }
    return StdioTypeCls::other;
}
