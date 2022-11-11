#include "stdio.hpp"
StreamSubscription<List<int>> _StdStreamCls::listen(bool cancelOnError, std::function<void(List<int> event)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    return _stream->listen(onDataonError, onDone, cancelOnError);
}

String StdinCls::readLineSync(Encoding encoding, bool retainNewlines) {
    CRCls = 13;
    LFCls = 10;
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
        } while (byte != LFCls && !(byte == CRCls && crIsNewline));
        if (line->isEmpty) {
            return nullptr;
        }
    } else     {
        if (crIsNewline) {
        while (true) {
            int byte = readByteSync();
            if ( < 0) {
                if (line->isEmpty)                 {
                    return nullptr;
                }
                break;
            }
            if (byte == LFCls || byte == CRCls)             {
                break;
            }
            line->add(byte);
        }
    } else {
        outer:;
        while (true) {
            int byte = readByteSync();
            if (byte == LFCls)             {
                break;
            }
            if (byte == CRCls) {
                do {
                    byte = readByteSync();
                    if (byte == LFCls)                     {
                        break outer;
                    }
                    line->add(CRCls);
                } while (byte == CRCls);
            }
            if ( < 0) {
                if (line->isEmpty)                 {
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

void StdinCls::_(int _fd, Stream<List<int>> stream)

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

void StdoutCls::_(int _fd, IOSink sink)

String StdoutExceptionCls::toString() {
    return __s("StdoutException: $message${osError == null ? "" : ", $osError"}");
}

String StdinExceptionCls::toString() {
    return __s("StdinException: $message${osError == null ? "" : ", $osError"}");
}

Future _StdConsumerCls::addStream(Stream<List<int>> stream) {
    auto completer = make<CompleterCls>();
    auto sub;
    sub = stream->listen([=] (Unknown  data) {
        try {
            _file->writeFromSync(data);
        } catch (Unknown e) {
            sub->cancel();
            completer->completeError(e, s);
        };
    }completer->completeError, completer->complete, true);
    return completer->future;
}

Future _StdConsumerCls::close() {
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

void _StdSinkCls::writeAll(Iterable objects, String sep) {
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

Future _StdSinkCls::addStream(Stream<List<int>> stream) {
    return _sink->addStream(stream);
}

Future _StdSinkCls::flush() {
    return _sink->flush();
}

Future _StdSinkCls::close() {
    return _sink->close();
}

Future _StdSinkCls::done() {
    return _sink->done();
}

String StdioTypeCls::toString() {
    return __s("StdioType: $name");
}

void _setStdioFDs(int stderr, int stdin, int stdout) {
    _stdinFD = stdin;
    _stdoutFD = stdout;
    _stderrFD = stderr;
}

Stdin stdin() {
    return IOOverridesCls::current?->stdin or _stdin;
}

Stdout stdout() {
    return IOOverridesCls::current?->stdout or _stdout;
}

Stdout stderr() {
    return IOOverridesCls::current?->stderr or _stderr;
}

StdioType stdioType(object ) {
    if (is<_StdStream>(object)) {
        as<_StdStreamCls>(object) = as<_StdStreamCls>(object)->_stream;
    } else     {
        if (object == stdout || object == stderr) {
        int stdiofd = object == stdout? _stdoutFD : _stderrFD;
        Unknown type = _StdIOUtilsCls->_getStdioHandleType(stdiofd);
        if (is<OSError>(type)) {
            throw make<FileSystemExceptionCls>(__s("Failed to get type of stdio handle (fd $stdiofd)"), __s(""), as<OSErrorCls>(type));
        }
        ;
    }
;
    }    if (is<_FileStream>(object)) {
        return StdioTypeCls::file;
    }
    if (is<Socket>(object)) {
        int socketType = _StdIOUtilsCls->_socketType(as<SocketCls>(object));
        if (socketType == nullptr)         {
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
