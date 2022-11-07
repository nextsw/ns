#include "directory_impl.hpp"
void _Directory::fromRawPath(Uint8List rawPath)

String _Directory::path() {
    return _path;
}

Directory _Directory::current() {
    auto result = _current(_Namespace._namespace);
    if (result is OSError) {
        ;
    }
    return _Directory(result);
}

void _Directory::current(path ) {
    Uint8List _rawPath;
    if (path is _Directory) {
        _rawPath = path._rawPath;
    } else     {
        if (path is Directory) {
        _rawPath = FileSystemEntity._toUtf8Array(path.path);
    } else     {
        if (path is String) {
        _rawPath = FileSystemEntity._toUtf8Array(path);
    } else {
        ;
    }
;
    };
    }    if (!_EmbedderConfig._mayChdir) {
        ;
    }
    auto result = _setCurrent(_Namespace._namespace, _rawPath);
    if (result is ArgumentError)     {
        ;
    }
    if (result is OSError) {
        ;
    }
}

Uri _Directory::uri() {
    return Uri.directory(path);
}

Future<bool> _Directory::exists() {
    return _File._dispatchWithNamespace(_IOService.directoryExists, ).then();
}

bool _Directory::existsSync() {
    auto result = _exists(_Namespace._namespace, _rawPath);
    if (result is OSError) {
        ;
    }
    return (result == 1);
}

Directory _Directory::absolute() {
    return Directory(_absolutePath);
}

Future<Directory> _Directory::create(bool recursive) {
    if (recursive) {
        return exists().then();
    } else {
        return _File._dispatchWithNamespace(_IOService.directoryCreate, ).then();
    }
}

void _Directory::createSync(bool recursive) {
    if (recursive) {
        if (existsSync())         {
            return;
        }
        if (path != parent.path) {
            parent.createSync(true);
        }
    }
    auto result = _create(_Namespace._namespace, _rawPath);
    if (result is OSError) {
        ;
    }
}

Directory _Directory::systemTemp() {
    return Directory(_systemTemp(_Namespace._namespace));
}

Future<Directory> _Directory::createTemp(String prefix) {
    prefix = "";
    if (path == "") {
        ;
    }
    String fullPrefix;
    if (path.endsWith("/") || (Platform.isWindows && path.endsWith("\\"))) {
        fullPrefix = "$path$prefix";
    } else {
        fullPrefix = "$path${Platform.pathSeparator}$prefix";
    }
    return _File._dispatchWithNamespace(_IOService.directoryCreateTemp, ).then();
}

Directory _Directory::createTempSync(String prefix) {
    prefix = "";
    if (path == "") {
        ;
    }
    String fullPrefix;
    if (path.endsWith("/") || (Platform.isWindows && path.endsWith("\\"))) {
        fullPrefix = "$path$prefix";
    } else {
        fullPrefix = "$path${Platform.pathSeparator}$prefix";
    }
    auto result = _createTemp(_Namespace._namespace, FileSystemEntity._toUtf8Array(fullPrefix));
    if (result is OSError) {
        ;
    }
    return Directory(result);
}

Future<Directory> _Directory::rename(String newPath) {
    return _File._dispatchWithNamespace(_IOService.directoryRename, ).then();
}

Directory _Directory::renameSync(String newPath) {
    ArgumentError.checkNotNull(newPath, "newPath");
    auto result = _rename(_Namespace._namespace, _rawPath, newPath);
    if (result is OSError) {
        ;
    }
    return Directory(newPath);
}

Stream<FileSystemEntity> _Directory::list(bool followLinks, bool recursive) {
    return _AsyncDirectoryLister(FileSystemEntity._toUtf8Array(FileSystemEntity._ensureTrailingPathSeparators(path)), recursive, followLinks).stream;
}

List<FileSystemEntity> _Directory::listSync(bool followLinks, bool recursive) {
    ArgumentError.checkNotNull(recursive, "recursive");
    ArgumentError.checkNotNull(followLinks, "followLinks");
    auto result = ;
    _fillWithDirectoryListing(_Namespace._namespace, result, FileSystemEntity._toUtf8Array(FileSystemEntity._ensureTrailingPathSeparators(path)), recursive, followLinks);
    return result;
}

String _Directory::toString() {
    return "Directory: '$path'";
}

_Directory::_Directory(String path) {
    {
        _path = _checkNotNull(path, "path");
        _rawPath = FileSystemEntity._toUtf8Array(path);
    }
}

Future<Directory> _Directory::_delete(bool recursive) {
    return _File._dispatchWithNamespace(_IOService.directoryDelete, ).then();
}

void _Directory::_deleteSync(bool recursive) {
    auto result = _deleteNative(_Namespace._namespace, _rawPath, recursive);
    if (result is OSError) {
        ;
    }
}

bool _Directory::_isErrorResponse(response ) {
    return response is List && response[0] != _successResponse;
}

void _Directory::_exceptionOrErrorFromResponse(response , String message) {
    assert(_isErrorResponse(response));
    ;
}

T _Directory::_checkNotNull<T>(String name, T t) {
    ArgumentError.checkNotNull(t, name);
    return t;
}

Stream<FileSystemEntity> _AsyncDirectoryLister::stream() {
    return controller.stream;
}

void _AsyncDirectoryLister::onListen() {
    _File._dispatchWithNamespace(_IOService.directoryListStart, ).then();
}

void _AsyncDirectoryLister::onResume() {
    if (!nextRunning) {
        next();
    }
}

Future _AsyncDirectoryLister::onCancel() {
    canceled = true;
    if (!nextRunning) {
        close();
    }
    return closeCompleter.future;
}

void _AsyncDirectoryLister::next() {
    if (canceled) {
        close();
        return;
    }
    if (controller.isPaused || nextRunning) {
        return;
    }
    auto pointer = _pointer();
    if (pointer == nullptr) {
        return;
    }
    nextRunning = true;
    _IOService._dispatch(_IOService.directoryListNext, ).then();
}

void _AsyncDirectoryLister::close() {
    if (closed) {
        return;
    }
    if (nextRunning) {
        return;
    }
    closed = true;
    auto pointer = _pointer();
    if (pointer == nullptr) {
        _cleanup();
    } else {
        _IOService._dispatch(_IOService.directoryListStop, ).whenComplete(_cleanup);
    }
}

void _AsyncDirectoryLister::error(message ) {
    auto errorType = message[responseError][_errorResponseErrorType];
    if (errorType == _illegalArgumentResponse) {
        controller.addError(ArgumentError());
    } else     {
        if (errorType == _osErrorResponse) {
        auto responseErrorInfo = message[responseError];
        auto err = OSError(responseErrorInfo[_osErrorResponseMessage], responseErrorInfo[_osErrorResponseErrorCode]);
        auto errorPath = message[responsePath];
        if (errorPath == nullptr) {
            errorPath = utf8.decode(rawPathtrue);
        } else         {
            if (errorPath is Uint8List) {
            errorPath = utf8.decode(message[responsePath]true);
        }
;
        }        controller.addError(FileSystemException("Directory listing failed", errorPath, err));
    } else {
        controller.addError(FileSystemException("Internal error"));
    }
;
    }}

_AsyncDirectoryLister::_AsyncDirectoryLister(bool followLinks, Uint8List rawPath, bool recursive) {
    {
        ;
    }
}

int _AsyncDirectoryLister::_pointer() {
    return _ops?.getPointer();
}

void _AsyncDirectoryLister::_cleanup() {
    controller.close();
    closeCompleter.complete();
    _ops = nullptr;
}
