#include "file_impl.hpp"
void _FileStreamCls::forStdin()

StreamSubscription<Uint8List> _FileStreamCls::listen(std::function<void(Uint8List event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    _controller = <Uint8List>make<StreamControllerCls>(true, _start, _readBlock, [=] () {
        _unsubscribed = true;
        return _closeFile();
    });
    return _controller->stream()->listen(onData, onError, onDone, cancelOnError);
}

_FileStreamCls::_FileStreamCls(String _path, int position, int _end) {
    {
        _position = position | 0;
    }
}

Future<any> _FileStreamCls::_closeFile() {
    if (_readInProgress || _closed) {
        return _closeCompleter->future();
    }
    _closed = true;
    InlineMethod;
    _openedFile->close()->catchError(_controller->addError)->whenComplete(done);
    return _closeCompleter->future();
}

void _FileStreamCls::_readBlock() {
    if (_readInProgress) {
        return;
    }
    if (_atEnd) {
        _closeFile();
        return;
    }
    _readInProgress = true;
    int readBytes = _blockSize;
    Unknown end = _end;
    if (end != nullptr) {
        readBytes = min(readBytes, end - _position);
        if ( < 0) {
            _readInProgress = false;
            if (!_unsubscribed) {
                _controller->addError(make<RangeErrorCls>(__s("Bad end position: %s)")));
                _closeFile();
                _unsubscribed = true;
            }
            return;
        }
    }
    _openedFile->read(readBytes)->then([=] (Unknown  block) {
        _readInProgress = false;
        if (_unsubscribed) {
            _closeFile();
            return;
        }
        _position += block->length;
        if (block->length < readBytes || (_end != nullptr && _position == _end)) {
            _atEnd = true;
        }
        if (!_atEnd && !_controller->isPaused()) {
            _readBlock();
        }
        _controller->add(block);
        if (_atEnd) {
            _closeFile();
        }
    })->catchError([=] (Unknown  e,Unknown  s) {
        if (!_unsubscribed) {
            _controller->addError(e, s);
            _closeFile();
            _unsubscribed = true;
        }
    });
}

void _FileStreamCls::_start() {
    if ( < 0) {
        _controller->addError(make<RangeErrorCls>(__s("Bad start position: %s)")));
        _controller->close();
        _closeCompleter->complete();
        return;
    }
    InlineMethod;
    InlineMethod;
    InlineMethod;
    Unknown path = _path;
    if (path != nullptr) {
        make<FileCls>(path)->open(FileModeCls::read)->then(onOpenFile, openFailed);
    } else {
        try {
            onOpenFile(_FileCls->_openStdioSync(0));
        } catch (Unknown e) {
            openFailed(e, s);
        };
    }
}

void _FileStreamConsumerCls::fromStdio(int fd)

Future<File> _FileStreamConsumerCls::addStream(Stream<List<int>> stream) {
    Completer<File> completer = <File>sync();
    _openFuture->then([=] (Unknown  openedFile) {
        StreamSubscription<List<int>> _subscription;
        InlineMethod;
        _subscription = stream->listen([=] (Unknown  d) {
            _subscription->pause();
            try {
                openedFile->writeFrom(d, 0, d->length)->then([=] (Unknown  _) {
                    _subscription->resume();
                }, error);
            } catch (Unknown e) {
                error(e, stackTrace);
            };
        }, [=] () {
            completer->complete(_file);
        }, error, true);
    })->catchError(completer->completeError);
    return completer->future();
}

Future<File> _FileStreamConsumerCls::close() {
    return _openFuture->then([=] (Unknown  openedFile) {
        openedFile->close();
    })->then([=] (Unknown  _) {
        _file;
    });
}

_FileStreamConsumerCls::_FileStreamConsumerCls(File file, FileMode mode) {
    {
        _file = file;
        _openFuture = file->open(mode);
    }
}

void _FileCls::fromRawPath(Uint8List rawPath)

String _FileCls::path() {
    return _path;
}

Future<bool> _FileCls::exists() {
    return _dispatchWithNamespace(_IOServiceCls::fileExists, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot check existence"), path());
        }
        return response;
    });
}

bool _FileCls::existsSync() {
    auto result = _exists(_NamespaceCls::_namespace, _rawPath);
    throwIfError(result, __s("Cannot check existence of file"), path());
    return result;
}

File _FileCls::absolute() {
    return make<FileCls>(_absolutePath());
}

Future<File> _FileCls::create(bool recursive) {
    auto result = recursive? parent()->create(true) : FutureCls->value(nullptr);
    return result->then([=] (Unknown  _) {
        _dispatchWithNamespace(_IOServiceCls::fileCreate, makeList(ArrayItem, ArrayItem));
    })->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot create file"), path());
        }
        return this;
    });
}

void _FileCls::createSync(bool recursive) {
    if (recursive) {
        parent()->createSync(true);
    }
    auto result = _create(_NamespaceCls::_namespace, _rawPath);
    throwIfError(result, __s("Cannot create file"), path());
}

Future<File> _FileCls::rename(String newPath) {
    return _dispatchWithNamespace(_IOServiceCls::fileRename, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot rename file to '%s,"), path());
        }
        return make<FileCls>(newPath);
    });
}

File _FileCls::renameSync(String newPath) {
    auto result = _rename(_NamespaceCls::_namespace, _rawPath, newPath);
    throwIfError(result, __s("Cannot rename file to '%s,"), path());
    return make<FileCls>(newPath);
}

Future<File> _FileCls::copy(String newPath) {
    return _dispatchWithNamespace(_IOServiceCls::fileCopy, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot copy file to '%s,"), path());
        }
        return make<FileCls>(newPath);
    });
}

File _FileCls::copySync(String newPath) {
    auto result = _copy(_NamespaceCls::_namespace, _rawPath, newPath);
    throwIfError(result, __s("Cannot copy file to '%s,"), path());
    return make<FileCls>(newPath);
}

Future<RandomAccessFile> _FileCls::open(FileMode mode) {
    if (mode != FileModeCls::read && mode != FileModeCls::write && mode != FileModeCls::append && mode != FileModeCls::writeOnly && mode != FileModeCls::writeOnlyAppend) {
        return FutureCls->error(make<ArgumentErrorCls>(__s("Invalid file mode for this operation")));
    }
    return _dispatchWithNamespace(_IOServiceCls::fileOpen, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot open file"), path());
        }
        return make<_RandomAccessFileCls>(response, path());
    });
}

Future<int> _FileCls::length() {
    return _dispatchWithNamespace(_IOServiceCls::fileLengthFromPath, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot retrieve length of file"), path());
        }
        return response;
    });
}

int _FileCls::lengthSync() {
    auto result = _lengthFromPath(_NamespaceCls::_namespace, _rawPath);
    throwIfError(result, __s("Cannot retrieve length of file"), path());
    return result;
}

Future<DateTime> _FileCls::lastAccessed() {
    return _dispatchWithNamespace(_IOServiceCls::fileLastAccessed, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot retrieve access time"), path());
        }
        return DateTimeCls->fromMillisecondsSinceEpoch(response);
    });
}

DateTime _FileCls::lastAccessedSync() {
    auto ms = _lastAccessed(_NamespaceCls::_namespace, _rawPath);
    throwIfError(ms, __s("Cannot retrieve access time"), path());
    return DateTimeCls->fromMillisecondsSinceEpoch(ms);
}

Future<any> _FileCls::setLastAccessed(DateTime time) {
    int millis = time->millisecondsSinceEpoch();
    return _dispatchWithNamespace(_IOServiceCls::fileSetLastAccessed, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot set access time"), path());
        }
        return nullptr;
    });
}

void _FileCls::setLastAccessedSync(DateTime time) {
    int millis = time->millisecondsSinceEpoch();
    auto result = _setLastAccessed(_NamespaceCls::_namespace, _rawPath, millis);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Failed to set file access time"), path(), as<OSErrorCls>(result));
    }
}

Future<DateTime> _FileCls::lastModified() {
    return _dispatchWithNamespace(_IOServiceCls::fileLastModified, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot retrieve modification time"), path());
        }
        return DateTimeCls->fromMillisecondsSinceEpoch(response);
    });
}

DateTime _FileCls::lastModifiedSync() {
    auto ms = _lastModified(_NamespaceCls::_namespace, _rawPath);
    throwIfError(ms, __s("Cannot retrieve modification time"), path());
    return DateTimeCls->fromMillisecondsSinceEpoch(ms);
}

Future<any> _FileCls::setLastModified(DateTime time) {
    int millis = time->millisecondsSinceEpoch();
    return _dispatchWithNamespace(_IOServiceCls::fileSetLastModified, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot set modification time"), path());
        }
        return nullptr;
    });
}

void _FileCls::setLastModifiedSync(DateTime time) {
    int millis = time->millisecondsSinceEpoch();
    auto result = _setLastModified(_NamespaceCls::_namespace, _rawPath, millis);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Failed to set file modification time"), path(), as<OSErrorCls>(result));
    }
}

RandomAccessFile _FileCls::openSync(FileMode mode) {
    if (mode != FileModeCls::read && mode != FileModeCls::write && mode != FileModeCls::append && mode != FileModeCls::writeOnly && mode != FileModeCls::writeOnlyAppend) {
        throw make<ArgumentErrorCls>(__s("Invalid file mode for this operation"));
    }
    auto id = _open(_NamespaceCls::_namespace, _rawPath, mode->_mode);
    throwIfError(id, __s("Cannot open file"), path());
    return make<_RandomAccessFileCls>(id, _path);
}

Stream<List<int>> _FileCls::openRead(int start, int end) {
    return make<_FileStreamCls>(path(), start, end);
}

IOSink _FileCls::openWrite(Encoding encoding, FileMode mode) {
    if (mode != FileModeCls::write && mode != FileModeCls::append && mode != FileModeCls::writeOnly && mode != FileModeCls::writeOnlyAppend) {
        throw make<ArgumentErrorCls>(__s("Invalid file mode for this operation"));
    }
    auto consumer = make<_FileStreamConsumerCls>(this, mode);
    return make<IOSinkCls>(consumer, encoding);
}

Future<Uint8List> _FileCls::readAsBytes() {
    InlineMethod;
    return open()->then([=] (Unknown  file) {
        return file->length()->then([=] (Unknown  length) {
            if (length == 0) {
                return readDataChunked(file);
            }
            return file->read(length);
        })->whenComplete(file->close);
    });
}

Uint8List _FileCls::readAsBytesSync() {
    auto opened = openSync();
    try {
        Uint8List data;
        auto length = opened->lengthSync();
        if (length == 0) {
            auto builder = make<BytesBuilderCls>(false);
            do {
                data = opened->readSync(_blockSize);
                if (data->length > 0) {
                    builder->add(data);
                }
            } while (data->length > 0);
            data = builder->takeBytes();
        } else {
            data = opened->readSync(length);
        }
        return data;
    } finally {
        opened->closeSync();
    };
}

Future<String> _FileCls::readAsString(Encoding encoding) {
    auto stack = StackTraceCls::current;
    return readAsBytes()->then([=] (Unknown  bytes) {
        try {
            return _tryDecode(bytes, encoding);
        } catch (Unknown e) {
            return FutureCls->error(e, stack);
        };
    });
}

String _FileCls::readAsStringSync(Encoding encoding) {
    return _tryDecode(readAsBytesSync(), encoding);
}

Future<List<String>> _FileCls::readAsLines(Encoding encoding) {
    return readAsString(encoding)->then(make<LineSplitterCls>()->convert);
}

List<String> _FileCls::readAsLinesSync(Encoding encoding) {
    return make<LineSplitterCls>()->convert(readAsStringSync(encoding));
}

Future<File> _FileCls::writeAsBytes(List<int> bytes, bool flush, FileMode mode) {
    return open(mode)->then([=] (Unknown  file) {
        return file->writeFrom(bytes, 0, bytes->length())-><File>then([=] (Unknown  _) {
            if (flush) {
                return file->flush()->then([=] (Unknown  _) {
                this;
            });
            }
            return this;
        })->whenComplete(file->close);
    });
}

void _FileCls::writeAsBytesSync(List<int> bytes, bool flush, FileMode mode) {
    RandomAccessFile opened = openSync(mode);
    try {
        opened->writeFromSync(bytes, 0, bytes->length());
        if (flush) {
            opened->flushSync();
        }
    } finally {
        opened->closeSync();
    };
}

Future<File> _FileCls::writeAsString(String contents, Encoding encoding, bool flush, FileMode mode) {
    try {
        return writeAsBytes(encoding->encode(contents), mode, flush);
    } catch (Unknown e) {
        return FutureCls->error(e);
    };
}

void _FileCls::writeAsStringSync(String contents, Encoding encoding, bool flush, FileMode mode) {
    writeAsBytesSync(encoding->encode(contents), mode, flush);
}

String _FileCls::toString() {
    return __s("File: '%s;");
}

void _FileCls::throwIfError(Object result, String msg, String path) {
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(msg, path, as<OSErrorCls>(result));
    }
}

_FileCls::_FileCls(String path) {
    {
        _path = _checkNotNull(path, __s("path"));
        _rawPath = FileSystemEntityCls->_toUtf8Array(path);
    }
}

int _FileCls::_namespacePointer() {
    return _NamespaceCls::_namespacePointer;
}

Future<any> _FileCls::_dispatchWithNamespace(int request, List<any> data) {
    data[0] = _namespacePointer();
    return _IOServiceCls->_dispatch(request, data);
}

Future<File> _FileCls::_delete(bool recursive) {
    if (recursive) {
        return make<DirectoryCls>(path())->delete(true)->then([=] (Unknown  _) {
            this;
        });
    }
    return _dispatchWithNamespace(_IOServiceCls::fileDelete, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot delete file"), path());
        }
        return this;
    });
}

void _FileCls::_deleteSync(bool recursive) {
    if (recursive) {
        return DirectoryCls->fromRawPath(_rawPath)->deleteSync(true);
    }
    auto result = _deleteNative(_NamespaceCls::_namespace, _rawPath);
    throwIfError(result, __s("Cannot delete file"), path());
}

RandomAccessFile _FileCls::_openStdioSync(int fd) {
    auto id = _openStdio(fd);
    if (id == 0) {
        throw make<FileSystemExceptionCls>(__s("Cannot open stdio file for: %s)"));
    }
    return make<_RandomAccessFileCls>(id, __s(""));
}

String _FileCls::_tryDecode(List<int> bytes, Encoding encoding) {
    try {
        return encoding->decode(bytes);
    } catch (Unknown _) {
        throw make<FileSystemExceptionCls>(__s("Failed to decode data using encoding '%s,"), path());
    };
}

template<typename T>
T _FileCls::_checkNotNull(T t, String name) {
    ArgumentErrorCls->checkNotNull(t, name);
    return t;
}

Future<void> _RandomAccessFileCls::close() {
    return _dispatch(_IOServiceCls::fileClose, makeList(ArrayItem), true)->then([=] (Unknown  result) {
        if (result == -1) {
            throw make<FileSystemExceptionCls>(__s("Cannot close file"), path);
        }
        closed = closed || (result == 0);
        _maybePerformCleanup();
    });
}

void _RandomAccessFileCls::closeSync() {
    _checkAvailable();
    auto id = _ops->close();
    if (id == -1) {
        throw make<FileSystemExceptionCls>(__s("Cannot close file"), path);
    }
    closed = closed || (id == 0);
    _maybePerformCleanup();
}

Future<int> _RandomAccessFileCls::readByte() {
    return _dispatch(_IOServiceCls::fileReadByte, makeList(ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("readByte failed"), path);
        }
        _resourceInfo->addRead(1);
        return response;
    });
}

int _RandomAccessFileCls::readByteSync() {
    _checkAvailable();
    auto result = _ops->readByte();
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("readByte failed"), path, as<OSErrorCls>(result));
    }
    _resourceInfo->addRead(1);
    return result;
}

Future<Uint8List> _RandomAccessFileCls::read(int bytes) {
    ArgumentErrorCls->checkNotNull(bytes, __s("bytes"));
    return _dispatch(_IOServiceCls::fileRead, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("read failed"), path);
        }
        _resourceInfo->addRead(response[1]->length);
        Uint8List result = response[1];
        return result;
    });
}

Uint8List _RandomAccessFileCls::readSync(int bytes) {
    ArgumentErrorCls->checkNotNull(bytes, __s("bytes"));
    _checkAvailable();
    auto result = _ops->read(bytes);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("readSync failed"), path, as<OSErrorCls>(result));
    }
    _resourceInfo->addRead(result->length);
    return result;
}

Future<int> _RandomAccessFileCls::readInto(List<int> buffer, int start, int end) {
    ArgumentErrorCls->checkNotNull(buffer, __s("buffer"));
    end = RangeErrorCls->checkValidRange(start, end, buffer->length());
    if (end == start) {
        return FutureCls->value(0);
    }
    int length = end - start;
    return _dispatch(_IOServiceCls::fileReadInto, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("readInto failed"), path);
        }
        int read = response[1];
        List<int> data = response[2];
        buffer->setRange(start, start + read, data);
        _resourceInfo->addRead(read);
        return read;
    });
}

int _RandomAccessFileCls::readIntoSync(List<int> buffer, int start, int end) {
    ArgumentErrorCls->checkNotNull(buffer, __s("buffer"));
    _checkAvailable();
    end = RangeErrorCls->checkValidRange(start, end, buffer->length());
    if (end == start) {
        return 0;
    }
    auto result = _ops->readInto(buffer, start, end);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("readInto failed"), path, as<OSErrorCls>(result));
    }
    _resourceInfo->addRead(result);
    return result;
}

Future<RandomAccessFile> _RandomAccessFileCls::writeByte(int value) {
    ArgumentErrorCls->checkNotNull(value, __s("value"));
    return _dispatch(_IOServiceCls::fileWriteByte, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("writeByte failed"), path);
        }
        _resourceInfo->addWrite(1);
        return this;
    });
}

int _RandomAccessFileCls::writeByteSync(int value) {
    _checkAvailable();
    ArgumentErrorCls->checkNotNull(value, __s("value"));
    auto result = _ops->writeByte(value);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("writeByte failed"), path, as<OSErrorCls>(result));
    }
    _resourceInfo->addWrite(1);
    return result;
}

Future<RandomAccessFile> _RandomAccessFileCls::writeFrom(List<int> buffer, int start, int end) {
    ArgumentErrorCls->checkNotNull(buffer, __s("buffer"));
    ArgumentErrorCls->checkNotNull(start, __s("start"));
    end = RangeErrorCls->checkValidRange(start, end, buffer->length());
    if (end == start) {
        return FutureCls->value(this);
    }
    _BufferAndStart result;
    try {
        result = _ensureFastAndSerializableByteData(buffer, start, end);
    } catch (Unknown e) {
        return FutureCls->error(e);
    };
    List<any> request = <dynamic>filled(4, nullptr);
    request[0] = nullptr;
    request[1] = result->buffer;
    request[2] = result->start;
    request[3] = end - (start - result->start);
    return _dispatch(_IOServiceCls::fileWriteFrom, request)->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("writeFrom failed"), path);
        }
        _resourceInfo->addWrite(end! - (start - result->start));
        return this;
    });
}

void _RandomAccessFileCls::writeFromSync(List<int> buffer, int start, int end) {
    _checkAvailable();
    ArgumentErrorCls->checkNotNull(buffer, __s("buffer"));
    ArgumentErrorCls->checkNotNull(start, __s("start"));
    end = RangeErrorCls->checkValidRange(start, end, buffer->length());
    if (end == start) {
        return;
    }
    _BufferAndStart bufferAndStart = _ensureFastAndSerializableByteData(buffer, start, end);
    auto result = _ops->writeFrom(bufferAndStart->buffer, bufferAndStart->start, end - (start - bufferAndStart->start));
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("writeFrom failed"), path, as<OSErrorCls>(result));
    }
    _resourceInfo->addWrite(end - (start - bufferAndStart->start));
}

Future<RandomAccessFile> _RandomAccessFileCls::writeString(String stringValue, Encoding encoding) {
    ArgumentErrorCls->checkNotNull(encoding, __s("encoding"));
    auto data = encoding->encode(stringValue);
    return writeFrom(data, 0, data->length);
}

void _RandomAccessFileCls::writeStringSync(String stringValue, Encoding encoding) {
    ArgumentErrorCls->checkNotNull(encoding, __s("encoding"));
    auto data = encoding->encode(stringValue);
    writeFromSync(data, 0, data->length);
}

Future<int> _RandomAccessFileCls::position() {
    return _dispatch(_IOServiceCls::filePosition, makeList(ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("position failed"), path);
        }
        return response;
    });
}

int _RandomAccessFileCls::positionSync() {
    _checkAvailable();
    auto result = _ops->position();
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("position failed"), path, as<OSErrorCls>(result));
    }
    return result;
}

Future<RandomAccessFile> _RandomAccessFileCls::setPosition(int position) {
    return _dispatch(_IOServiceCls::fileSetPosition, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("setPosition failed"), path);
        }
        return this;
    });
}

void _RandomAccessFileCls::setPositionSync(int position) {
    _checkAvailable();
    auto result = _ops->setPosition(position);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("setPosition failed"), path, as<OSErrorCls>(result));
    }
}

Future<RandomAccessFile> _RandomAccessFileCls::truncate(int length) {
    return _dispatch(_IOServiceCls::fileTruncate, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("truncate failed"), path);
        }
        return this;
    });
}

void _RandomAccessFileCls::truncateSync(int length) {
    _checkAvailable();
    auto result = _ops->truncate(length);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("truncate failed"), path, as<OSErrorCls>(result));
    }
}

Future<int> _RandomAccessFileCls::length() {
    return _dispatch(_IOServiceCls::fileLength, makeList(ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("length failed"), path);
        }
        return response;
    });
}

int _RandomAccessFileCls::lengthSync() {
    _checkAvailable();
    auto result = _ops->length();
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("length failed"), path, as<OSErrorCls>(result));
    }
    return result;
}

Future<RandomAccessFile> _RandomAccessFileCls::flush() {
    return _dispatch(_IOServiceCls::fileFlush, makeList(ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("flush failed"), path);
        }
        return this;
    });
}

void _RandomAccessFileCls::flushSync() {
    _checkAvailable();
    auto result = _ops->flush();
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("flush failed"), path, as<OSErrorCls>(result));
    }
}

Future<RandomAccessFile> _RandomAccessFileCls::lock(FileLock mode, int start, int end) {
    ArgumentErrorCls->checkNotNull(mode, __s("mode"));
    ArgumentErrorCls->checkNotNull(start, __s("start"));
    ArgumentErrorCls->checkNotNull(end, __s("end"));
    if (( < 0) || ( < -1) || ((end != -1) && (start >= end))) {
        throw make<ArgumentErrorCls>();
    }
    int lock = _fileLockValue(mode);
    return _dispatch(_IOServiceCls::fileLock, makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("lock failed"), path);
        }
        return this;
    });
}

Future<RandomAccessFile> _RandomAccessFileCls::unlock(int start, int end) {
    ArgumentErrorCls->checkNotNull(start, __s("start"));
    ArgumentErrorCls->checkNotNull(end, __s("end"));
    if (start == end) {
        throw make<ArgumentErrorCls>();
    }
    return _dispatch(_IOServiceCls::fileLock, makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("unlock failed"), path);
        }
        return this;
    });
}

void _RandomAccessFileCls::lockSync(FileLock mode, int start, int end) {
    _checkAvailable();
    ArgumentErrorCls->checkNotNull(mode, __s("mode"));
    ArgumentErrorCls->checkNotNull(start, __s("start"));
    ArgumentErrorCls->checkNotNull(end, __s("end"));
    if (( < 0) || ( < -1) || ((end != -1) && (start >= end))) {
        throw make<ArgumentErrorCls>();
    }
    int lock = _fileLockValue(mode);
    auto result = _ops->lock(lock, start, end);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("lock failed"), path, as<OSErrorCls>(result));
    }
}

void _RandomAccessFileCls::unlockSync(int start, int end) {
    _checkAvailable();
    ArgumentErrorCls->checkNotNull(start, __s("start"));
    ArgumentErrorCls->checkNotNull(end, __s("end"));
    if (start == end) {
        throw make<ArgumentErrorCls>();
    }
    auto result = _ops->lock(lockUnlock, start, end);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("unlock failed"), path, as<OSErrorCls>(result));
    }
}

int _RandomAccessFileCls::fd() {
    return _ops->fd();
}

_RandomAccessFileCls::_RandomAccessFileCls(int pointer, String path) {
    {
        _ops = make<_RandomAccessFileOpsCls>(pointer);
    }
    {
        _resourceInfo = make<_FileResourceInfoCls>(this);
        _maybeConnectHandler();
    }
}

void _RandomAccessFileCls::_maybePerformCleanup() {
    if (closed) {
        _FileResourceInfoCls->fileClosed(_resourceInfo);
    }
}

void _RandomAccessFileCls::_maybeConnectHandler() {
    if (!_connectedResourceHandler) {
        registerExtension(__s("ext.dart.io.getOpenFiles"), _FileResourceInfoCls::getOpenFiles);
        registerExtension(__s("ext.dart.io.getOpenFileById"), _FileResourceInfoCls::getOpenFileInfoMapByID);
        _connectedResourceHandler = true;
    }
}

int _RandomAccessFileCls::_fileLockValue(FileLock fl) {
    return fl->_type;
}

int _RandomAccessFileCls::_pointer() {
    return _ops->getPointer();
}

Future<any> _RandomAccessFileCls::_dispatch(int request, List<any> data, bool markClosed) {
    if (closed) {
        return FutureCls->error(make<FileSystemExceptionCls>(__s("File closed"), path));
    }
    if (_asyncDispatched) {
        auto msg = __s("An async operation is currently pending");
        return FutureCls->error(make<FileSystemExceptionCls>(msg, path));
    }
    if (markClosed) {
        closed = true;
    }
    _asyncDispatched = true;
    data[0] = _pointer();
    return _IOServiceCls->_dispatch(request, data)->whenComplete([=] () {
        _asyncDispatched = false;
    });
}

void _RandomAccessFileCls::_checkAvailable() {
    if (_asyncDispatched) {
        throw make<FileSystemExceptionCls>(__s("An async operation is currently pending"), path);
    }
    if (closed) {
        throw make<FileSystemExceptionCls>(__s("File closed"), path);
    }
}
