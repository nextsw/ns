#include "file_impl.hpp"
void _FileStream::forStdin()

StreamSubscription<Uint8List> _FileStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    _controller = <Uint8List>StreamController(true, _start, _readBlock, );
    return _controller.stream.listen(onDataonError, onDone, cancelOnError);
}

_FileStream::_FileStream(int _end, String _path, int position) {
    {
        _position = position ?? 0;
    }
}

Future _FileStream::_closeFile() {
    if (_readInProgress || _closed) {
        return _closeCompleter.future;
    }
    _closed = true;
    ;
    _openedFile.close().catchError(_controller.addError).whenComplete(done);
    return _closeCompleter.future;
}

void _FileStream::_readBlock() {
    if (_readInProgress)     {
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
                _controller.addError(RangeError("Bad end position: $end"));
                _closeFile();
                _unsubscribed = true;
            }
            return;
        }
    }
    _openedFile.read(readBytes).then().catchError();
}

void _FileStream::_start() {
    if ( < 0) {
        _controller.addError(RangeError("Bad start position: $_position"));
        _controller.close();
        _closeCompleter.complete();
        return;
    }
    ;
    ;
    ;
    Unknown path = _path;
    if (path != nullptr) {
        File(path).open(FileMode.read).then(onOpenFileopenFailed);
    } else {
        ;
    }
}

void _FileStreamConsumer::fromStdio(int fd)

Future<File> _FileStreamConsumer::addStream(Stream<List<int>> stream) {
    Completer<File> completer = <File>sync();
    _openFuture.then().catchError(completer.completeError);
    return completer.future;
}

Future<File> _FileStreamConsumer::close() {
    return _openFuture.then().then();
}

_FileStreamConsumer::_FileStreamConsumer(File file, FileMode mode) {
    {
        _file = file;
        _openFuture = file.open(mode);
    }
}

void _File::fromRawPath(Uint8List rawPath)

String _File::path() {
    return _path;
}

Future<bool> _File::exists() {
    return _dispatchWithNamespace(_IOService.fileExists, ).then();
}

bool _File::existsSync() {
    auto result = _exists(_Namespace._namespace, _rawPath);
    throwIfError(result, "Cannot check existence of file", path);
    return result;
}

File _File::absolute() {
    return File(_absolutePath);
}

Future<File> _File::create(bool recursive) {
    auto result = recursive? parent.create(true) : Future.value(nullptr);
    return result.then().then();
}

void _File::createSync(bool recursive) {
    if (recursive) {
        parent.createSync(true);
    }
    auto result = _create(_Namespace._namespace, _rawPath);
    throwIfError(result, "Cannot create file", path);
}

Future<File> _File::rename(String newPath) {
    return _dispatchWithNamespace(_IOService.fileRename, ).then();
}

File _File::renameSync(String newPath) {
    auto result = _rename(_Namespace._namespace, _rawPath, newPath);
    throwIfError(result, "Cannot rename file to '$newPath'", path);
    return File(newPath);
}

Future<File> _File::copy(String newPath) {
    return _dispatchWithNamespace(_IOService.fileCopy, ).then();
}

File _File::copySync(String newPath) {
    auto result = _copy(_Namespace._namespace, _rawPath, newPath);
    throwIfError(result, "Cannot copy file to '$newPath'", path);
    return File(newPath);
}

Future<RandomAccessFile> _File::open(FileMode mode) {
    if (mode != FileMode.read && mode != FileMode.write && mode != FileMode.append && mode != FileMode.writeOnly && mode != FileMode.writeOnlyAppend) {
        return Future.error(ArgumentError("Invalid file mode for this operation"));
    }
    return _dispatchWithNamespace(_IOService.fileOpen, ).then();
}

Future<int> _File::length() {
    return _dispatchWithNamespace(_IOService.fileLengthFromPath, ).then();
}

int _File::lengthSync() {
    auto result = _lengthFromPath(_Namespace._namespace, _rawPath);
    throwIfError(result, "Cannot retrieve length of file", path);
    return result;
}

Future<DateTime> _File::lastAccessed() {
    return _dispatchWithNamespace(_IOService.fileLastAccessed, ).then();
}

DateTime _File::lastAccessedSync() {
    auto ms = _lastAccessed(_Namespace._namespace, _rawPath);
    throwIfError(ms, "Cannot retrieve access time", path);
    return DateTime.fromMillisecondsSinceEpoch(ms);
}

Future _File::setLastAccessed(DateTime time) {
    int millis = time.millisecondsSinceEpoch;
    return _dispatchWithNamespace(_IOService.fileSetLastAccessed, ).then();
}

void _File::setLastAccessedSync(DateTime time) {
    int millis = time.millisecondsSinceEpoch;
    auto result = _setLastAccessed(_Namespace._namespace, _rawPath, millis);
    if (result is OSError) {
        ;
    }
}

Future<DateTime> _File::lastModified() {
    return _dispatchWithNamespace(_IOService.fileLastModified, ).then();
}

DateTime _File::lastModifiedSync() {
    auto ms = _lastModified(_Namespace._namespace, _rawPath);
    throwIfError(ms, "Cannot retrieve modification time", path);
    return DateTime.fromMillisecondsSinceEpoch(ms);
}

Future _File::setLastModified(DateTime time) {
    int millis = time.millisecondsSinceEpoch;
    return _dispatchWithNamespace(_IOService.fileSetLastModified, ).then();
}

void _File::setLastModifiedSync(DateTime time) {
    int millis = time.millisecondsSinceEpoch;
    auto result = _setLastModified(_Namespace._namespace, _rawPath, millis);
    if (result is OSError) {
        ;
    }
}

RandomAccessFile _File::openSync(FileMode mode) {
    if (mode != FileMode.read && mode != FileMode.write && mode != FileMode.append && mode != FileMode.writeOnly && mode != FileMode.writeOnlyAppend) {
        ;
    }
    auto id = _open(_Namespace._namespace, _rawPath, mode._mode);
    throwIfError(id, "Cannot open file", path);
    return _RandomAccessFile(id, _path);
}

Stream<List<int>> _File::openRead(int end, int start) {
    return _FileStream(path, start, end);
}

IOSink _File::openWrite(Encoding encoding, FileMode mode) {
    if (mode != FileMode.write && mode != FileMode.append && mode != FileMode.writeOnly && mode != FileMode.writeOnlyAppend) {
        ;
    }
    auto consumer = _FileStreamConsumer(this, mode);
    return IOSink(consumerencoding);
}

Future<Uint8List> _File::readAsBytes() {
    ;
    return open().then();
}

Uint8List _File::readAsBytesSync() {
    auto opened = openSync();
    ;
}

Future<String> _File::readAsString(Encoding encoding) {
    auto stack = StackTrace.current;
    return readAsBytes().then();
}

String _File::readAsStringSync(Encoding encoding) {
    return _tryDecode(readAsBytesSync(), encoding);
}

Future<List<String>> _File::readAsLines(Encoding encoding) {
    return readAsString(encoding).then(const LineSplitter().convert);
}

List<String> _File::readAsLinesSync(Encoding encoding) {
    return const LineSplitter().convert(readAsStringSync(encoding));
}

Future<File> _File::writeAsBytes(List<int> bytes, bool flush, FileMode mode) {
    return open(mode).then();
}

void _File::writeAsBytesSync(List<int> bytes, bool flush, FileMode mode) {
    RandomAccessFile opened = openSync(mode);
    ;
}

Future<File> _File::writeAsString(String contents, Encoding encoding, bool flush, FileMode mode) {
    ;
}

void _File::writeAsStringSync(String contents, Encoding encoding, bool flush, FileMode mode) {
    writeAsBytesSync(encoding.encode(contents)mode, flush);
}

String _File::toString() {
    return "File: '$path'";
}

void _File::throwIfError(String msg, String path, Object result) {
    if (result is OSError) {
        ;
    }
}

_File::_File(String path) {
    {
        _path = _checkNotNull(path, "path");
        _rawPath = FileSystemEntity._toUtf8Array(path);
    }
}

int _File::_namespacePointer() {
    return _Namespace._namespacePointer;
}

Future _File::_dispatchWithNamespace(List data, int request) {
    data[0] = _namespacePointer();
    return _IOService._dispatch(request, data);
}

Future<File> _File::_delete(bool recursive) {
    if (recursive) {
        return Directory(path).delete(true).then();
    }
    return _dispatchWithNamespace(_IOService.fileDelete, ).then();
}

void _File::_deleteSync(bool recursive) {
    if (recursive) {
        return Directory.fromRawPath(_rawPath).deleteSync(true);
    }
    auto result = _deleteNative(_Namespace._namespace, _rawPath);
    throwIfError(result, "Cannot delete file", path);
}

RandomAccessFile _File::_openStdioSync(int fd) {
    auto id = _openStdio(fd);
    if (id == 0) {
        ;
    }
    return _RandomAccessFile(id, "");
}

String _File::_tryDecode(List<int> bytes, Encoding encoding) {
    ;
}

T _File::_checkNotNull<T>(String name, T t) {
    ArgumentError.checkNotNull(t, name);
    return t;
}

Future<void> _RandomAccessFile::close() {
    return _dispatch(_IOService.fileClose, true).then();
}

void _RandomAccessFile::closeSync() {
    _checkAvailable();
    auto id = _ops.close();
    if (id == -1) {
        ;
    }
    closed = closed || (id == 0);
    _maybePerformCleanup();
}

Future<int> _RandomAccessFile::readByte() {
    return _dispatch(_IOService.fileReadByte, ).then();
}

int _RandomAccessFile::readByteSync() {
    _checkAvailable();
    auto result = _ops.readByte();
    if (result is OSError) {
        ;
    }
    _resourceInfo.addRead(1);
    return result;
}

Future<Uint8List> _RandomAccessFile::read(int bytes) {
    ArgumentError.checkNotNull(bytes, "bytes");
    return _dispatch(_IOService.fileRead, ).then();
}

Uint8List _RandomAccessFile::readSync(int bytes) {
    ArgumentError.checkNotNull(bytes, "bytes");
    _checkAvailable();
    auto result = _ops.read(bytes);
    if (result is OSError) {
        ;
    }
    _resourceInfo.addRead(result.length);
    return result;
}

Future<int> _RandomAccessFile::readInto(List<int> buffer, int end, int start) {
    ArgumentError.checkNotNull(buffer, "buffer");
    end = RangeError.checkValidRange(start, end, buffer.length);
    if (end == start) {
        return Future.value(0);
    }
    int length = end - start;
    return _dispatch(_IOService.fileReadInto, ).then();
}

int _RandomAccessFile::readIntoSync(List<int> buffer, int end, int start) {
    ArgumentError.checkNotNull(buffer, "buffer");
    _checkAvailable();
    end = RangeError.checkValidRange(start, end, buffer.length);
    if (end == start) {
        return 0;
    }
    auto result = _ops.readInto(buffer, start, end);
    if (result is OSError) {
        ;
    }
    _resourceInfo.addRead(result);
    return result;
}

Future<RandomAccessFile> _RandomAccessFile::writeByte(int value) {
    ArgumentError.checkNotNull(value, "value");
    return _dispatch(_IOService.fileWriteByte, ).then();
}

int _RandomAccessFile::writeByteSync(int value) {
    _checkAvailable();
    ArgumentError.checkNotNull(value, "value");
    auto result = _ops.writeByte(value);
    if (result is OSError) {
        ;
    }
    _resourceInfo.addWrite(1);
    return result;
}

Future<RandomAccessFile> _RandomAccessFile::writeFrom(List<int> buffer, int end, int start) {
    ArgumentError.checkNotNull(buffer, "buffer");
    ArgumentError.checkNotNull(start, "start");
    end = RangeError.checkValidRange(start, end, buffer.length);
    if (end == start) {
        return Future.value(this);
    }
    _BufferAndStart result;
    ;
    List request = <dynamic>filled(4, nullptr);
    request[0] = nullptr;
    request[1] = result.buffer;
    request[2] = result.start;
    request[3] = end - (start - result.start);
    return _dispatch(_IOService.fileWriteFrom, request).then();
}

void _RandomAccessFile::writeFromSync(List<int> buffer, int end, int start) {
    _checkAvailable();
    ArgumentError.checkNotNull(buffer, "buffer");
    ArgumentError.checkNotNull(start, "start");
    end = RangeError.checkValidRange(start, end, buffer.length);
    if (end == start) {
        return;
    }
    _BufferAndStart bufferAndStart = _ensureFastAndSerializableByteData(buffer, start, end);
    auto result = _ops.writeFrom(bufferAndStart.buffer, bufferAndStart.start, end - (start - bufferAndStart.start));
    if (result is OSError) {
        ;
    }
    _resourceInfo.addWrite(end - (start - bufferAndStart.start));
}

Future<RandomAccessFile> _RandomAccessFile::writeString(Encoding encoding, String string) {
    ArgumentError.checkNotNull(encoding, "encoding");
    auto data = encoding.encode(string);
    return writeFrom(data, 0, data.length);
}

void _RandomAccessFile::writeStringSync(Encoding encoding, String string) {
    ArgumentError.checkNotNull(encoding, "encoding");
    auto data = encoding.encode(string);
    writeFromSync(data, 0, data.length);
}

Future<int> _RandomAccessFile::position() {
    return _dispatch(_IOService.filePosition, ).then();
}

int _RandomAccessFile::positionSync() {
    _checkAvailable();
    auto result = _ops.position();
    if (result is OSError) {
        ;
    }
    return result;
}

Future<RandomAccessFile> _RandomAccessFile::setPosition(int position) {
    return _dispatch(_IOService.fileSetPosition, ).then();
}

void _RandomAccessFile::setPositionSync(int position) {
    _checkAvailable();
    auto result = _ops.setPosition(position);
    if (result is OSError) {
        ;
    }
}

Future<RandomAccessFile> _RandomAccessFile::truncate(int length) {
    return _dispatch(_IOService.fileTruncate, ).then();
}

void _RandomAccessFile::truncateSync(int length) {
    _checkAvailable();
    auto result = _ops.truncate(length);
    if (result is OSError) {
        ;
    }
}

Future<int> _RandomAccessFile::length() {
    return _dispatch(_IOService.fileLength, ).then();
}

int _RandomAccessFile::lengthSync() {
    _checkAvailable();
    auto result = _ops.length();
    if (result is OSError) {
        ;
    }
    return result;
}

Future<RandomAccessFile> _RandomAccessFile::flush() {
    return _dispatch(_IOService.fileFlush, ).then();
}

void _RandomAccessFile::flushSync() {
    _checkAvailable();
    auto result = _ops.flush();
    if (result is OSError) {
        ;
    }
}

Future<RandomAccessFile> _RandomAccessFile::lock(int end, FileLock mode, int start) {
    ArgumentError.checkNotNull(mode, "mode");
    ArgumentError.checkNotNull(start, "start");
    ArgumentError.checkNotNull(end, "end");
    if (( < 0) || ( < -1) || ((end != -1) && (start >= end))) {
        ;
    }
    int lock = _fileLockValue(mode);
    return _dispatch(_IOService.fileLock, ).then();
}

Future<RandomAccessFile> _RandomAccessFile::unlock(int end, int start) {
    ArgumentError.checkNotNull(start, "start");
    ArgumentError.checkNotNull(end, "end");
    if (start == end) {
        ;
    }
    return _dispatch(_IOService.fileLock, ).then();
}

void _RandomAccessFile::lockSync(int end, FileLock mode, int start) {
    _checkAvailable();
    ArgumentError.checkNotNull(mode, "mode");
    ArgumentError.checkNotNull(start, "start");
    ArgumentError.checkNotNull(end, "end");
    if (( < 0) || ( < -1) || ((end != -1) && (start >= end))) {
        ;
    }
    int lock = _fileLockValue(mode);
    auto result = _ops.lock(lock, start, end);
    if (result is OSError) {
        ;
    }
}

void _RandomAccessFile::unlockSync(int end, int start) {
    _checkAvailable();
    ArgumentError.checkNotNull(start, "start");
    ArgumentError.checkNotNull(end, "end");
    if (start == end) {
        ;
    }
    auto result = _ops.lock(lockUnlock, start, end);
    if (result is OSError) {
        ;
    }
}

int _RandomAccessFile::fd() {
    return _ops.fd;
}

_RandomAccessFile::_RandomAccessFile(String path, int pointer) {
    {
        _ops = _RandomAccessFileOps(pointer);
    }
    {
        _resourceInfo = _FileResourceInfo(this);
        _maybeConnectHandler();
    }
}

void _RandomAccessFile::_maybePerformCleanup() {
    if (closed) {
        _FileResourceInfo.fileClosed(_resourceInfo);
    }
}

void _RandomAccessFile::_maybeConnectHandler() {
    if (!_connectedResourceHandler) {
        registerExtension("ext.dart.io.getOpenFiles", _FileResourceInfo.getOpenFiles);
        registerExtension("ext.dart.io.getOpenFileById", _FileResourceInfo.getOpenFileInfoMapByID);
        _connectedResourceHandler = true;
    }
}

int _RandomAccessFile::_fileLockValue(FileLock fl) {
    return fl._type;
}

int _RandomAccessFile::_pointer() {
    return _ops.getPointer();
}

Future _RandomAccessFile::_dispatch(List data, bool markClosed, int request) {
    if (closed) {
        return Future.error(FileSystemException("File closed", path));
    }
    if (_asyncDispatched) {
        auto msg = "An async operation is currently pending";
        return Future.error(FileSystemException(msg, path));
    }
    if (markClosed) {
        closed = true;
    }
    _asyncDispatched = true;
    data[0] = _pointer();
    return _IOService._dispatch(request, data).whenComplete();
}

void _RandomAccessFile::_checkAvailable() {
    if (_asyncDispatched) {
        ;
    }
    if (closed) {
        ;
    }
}
