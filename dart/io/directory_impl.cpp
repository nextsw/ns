#include "directory_impl.hpp"
void _DirectoryCls::fromRawPath(Uint8List rawPath)

String _DirectoryCls::path() {
    return _path;
}

Directory _DirectoryCls::current() {
    auto result = _current(_NamespaceCls::_namespace);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Getting current working directory failed"), __s(""), as<OSErrorCls>(result));
    }
    return make<_DirectoryCls>(result);
}

void _DirectoryCls::current(path ) {
    Uint8List _rawPath;
    if (is<_Directory>(path)) {
        _rawPath = as<_DirectoryCls>(path)->_rawPath;
    } else {
        if (is<Directory>(path)) {
        _rawPath = FileSystemEntityCls->_toUtf8Array(as<DirectoryCls>(path)->as<DirectoryCls>(path));
    } else {
        if (is<String>(path)) {
        _rawPath = FileSystemEntityCls->_toUtf8Array(as<StringCls>(path));
    } else {
        throw make<ArgumentErrorCls>(__sf("%s is not a String or Directory", ErrorCls->safeToString(path)));
    }
;
    };
    }    if (!_EmbedderConfigCls->_mayChdir) {
        throw make<UnsupportedErrorCls>(__s("This embedder disallows setting Directory.current"));
    }
    auto result = _setCurrent(_NamespaceCls::_namespace, _rawPath);
    if (is<ArgumentError>(result)) {
        throw as<ArgumentErrorCls>(result);
    }
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Setting current working directory failed"), path->toString(), as<OSErrorCls>(result));
    }
}

Uri _DirectoryCls::uri() {
    return UriCls->directory(path());
}

Future<bool> _DirectoryCls::exists() {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryExists, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionOrErrorFromResponse(response, __s("Exists failed"));
        }
        return response == 1;
    });
}

bool _DirectoryCls::existsSync() {
    auto result = _exists(_NamespaceCls::_namespace, _rawPath);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Exists failed"), path(), as<OSErrorCls>(result));
    }
    return (result == 1);
}

Directory _DirectoryCls::absolute() {
    return make<DirectoryCls>(_absolutePath());
}

Future<Directory> _DirectoryCls::create(bool recursive) {
    if (recursive) {
        return exists()->then([=] (Unknown  exists) {
            if (exists) {
                return this;
            }
            if (path() != parent()->path()) {
                return parent()->create(true)->then([=] (Unknown  _) {
                    return create();
                });
            } else {
                return create();
            }
        });
    } else {
        return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryCreate, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
            if (_isErrorResponse(response)) {
                throw _exceptionOrErrorFromResponse(response, __s("Creation failed"));
            }
            return this;
        });
    }
}

void _DirectoryCls::createSync(bool recursive) {
    if (recursive) {
        if (existsSync()) {
            return;
        }
        if (path() != parent()->path()) {
            parent()->createSync(true);
        }
    }
    auto result = _create(_NamespaceCls::_namespace, _rawPath);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Creation failed"), path(), as<OSErrorCls>(result));
    }
}

Directory _DirectoryCls::systemTemp() {
    return make<DirectoryCls>(_systemTemp(_NamespaceCls::_namespace));
}

Future<Directory> _DirectoryCls::createTemp(String prefix) {
    prefix |= __s("");
    if (path() == __s("")) {
        throw make<ArgumentErrorCls>(__s("Directory.createTemp called with an empty path. To use the system temp directory, use Directory.systemTemp"));
    }
    String fullPrefix;
    if (path()->endsWith(__s("/")) || (PlatformCls::isWindows && path()->endsWith(__s("\\")))) {
        fullPrefix = __sf("%s%s", path(), prefix);
    } else {
        fullPrefix = __sf("%s%s%s", path(), PlatformCls::pathSeparator, prefix);
    }
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryCreateTemp, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionOrErrorFromResponse(response, __s("Creation of temporary directory failed"));
        }
        return make<DirectoryCls>(response);
    });
}

Directory _DirectoryCls::createTempSync(String prefix) {
    prefix |= __s("");
    if (path() == __s("")) {
        throw make<ArgumentErrorCls>(__s("Directory.createTemp called with an empty path. To use the system temp directory, use Directory.systemTemp"));
    }
    String fullPrefix;
    if (path()->endsWith(__s("/")) || (PlatformCls::isWindows && path()->endsWith(__s("\\")))) {
        fullPrefix = __sf("%s%s", path(), prefix);
    } else {
        fullPrefix = __sf("%s%s%s", path(), PlatformCls::pathSeparator, prefix);
    }
    auto result = _createTemp(_NamespaceCls::_namespace, FileSystemEntityCls->_toUtf8Array(fullPrefix));
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Creation of temporary directory failed"), fullPrefix, as<OSErrorCls>(result));
    }
    return make<DirectoryCls>(result);
}

Future<Directory> _DirectoryCls::rename(String newPath) {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryRename, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionOrErrorFromResponse(response, __s("Rename failed"));
        }
        return make<DirectoryCls>(newPath);
    });
}

Directory _DirectoryCls::renameSync(String newPath) {
    ArgumentErrorCls->checkNotNull(newPath, __s("newPath"));
    auto result = _rename(_NamespaceCls::_namespace, _rawPath, newPath);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Rename failed"), path(), as<OSErrorCls>(result));
    }
    return make<DirectoryCls>(newPath);
}

Stream<FileSystemEntity> _DirectoryCls::list(bool followLinks, bool recursive) {
    return make<_AsyncDirectoryListerCls>(FileSystemEntityCls->_toUtf8Array(FileSystemEntityCls->_ensureTrailingPathSeparators(path())), recursive, followLinks)->stream;
}

List<FileSystemEntity> _DirectoryCls::listSync(bool followLinks, bool recursive) {
    ArgumentErrorCls->checkNotNull(recursive, __s("recursive"));
    ArgumentErrorCls->checkNotNull(followLinks, __s("followLinks"));
    auto result = makeList();
    _fillWithDirectoryListing(_NamespaceCls::_namespace, result, FileSystemEntityCls->_toUtf8Array(FileSystemEntityCls->_ensureTrailingPathSeparators(path())), recursive, followLinks);
    return result;
}

String _DirectoryCls::toString() {
    return __sf("Directory: '%s'", path());
}

_DirectoryCls::_DirectoryCls(String path) {
    {
        _path = _checkNotNull(path, __s("path"));
        _rawPath = FileSystemEntityCls->_toUtf8Array(path);
    }
}

Future<Directory> _DirectoryCls::_delete(bool recursive) {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryDelete, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionOrErrorFromResponse(response, __s("Deletion failed"));
        }
        return this;
    });
}

void _DirectoryCls::_deleteSync(bool recursive) {
    auto result = _deleteNative(_NamespaceCls::_namespace, _rawPath, recursive);
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(__s("Deletion failed"), path(), as<OSErrorCls>(result));
    }
}

bool _DirectoryCls::_isErrorResponse(response ) {
    return is<List<any>>(response) && response[0] != _successResponse;
}

void _DirectoryCls::_exceptionOrErrorFromResponse(response , String message) {
    assert(_isErrorResponse(response));
    ;
}

template<typename T>
T _DirectoryCls::_checkNotNull(T t, String name) {
    ArgumentErrorCls->checkNotNull(t, name);
    return t;
}

Stream<FileSystemEntity> _AsyncDirectoryListerCls::stream() {
    return controller->stream;
}

void _AsyncDirectoryListerCls::onListen() {
    _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryListStart, makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (is<int>(response)) {
            _ops = make<_AsyncDirectoryListerOpsCls>(as<intCls>(response));
            next();
        } else {
            if (is<Error>(response)) {
            controller->addError(as<ErrorCls>(response), as<ErrorCls>(response)->stackTrace());
            close();
        } else {
            error(response);
            close();
        }
;
        }    });
}

void _AsyncDirectoryListerCls::onResume() {
    if (!nextRunning) {
        next();
    }
}

Future<any> _AsyncDirectoryListerCls::onCancel() {
    canceled = true;
    if (!nextRunning) {
        close();
    }
    return closeCompleter->future();
}

void _AsyncDirectoryListerCls::next() {
    if (canceled) {
        close();
        return;
    }
    if (controller->isPaused || nextRunning) {
        return;
    }
    auto pointer = _pointer();
    if (pointer == nullptr) {
        return;
    }
    nextRunning = true;
    _IOServiceCls->_dispatch(_IOServiceCls::directoryListNext, makeList(ArrayItem))->then([=] (Unknown  result) {
        nextRunning = false;
        if (is<List<any>>(result)) {
            next();
            assert(as<ListCls>(result)->length() % 2 == 0);
            for (;  < as<ListCls>(result)->length(); i++) {
                assert(i % 2 == 0);
                ;
            }
        } else {
            controller->addError(make<FileSystemExceptionCls>(__s("Internal error")));
        }
    });
}

void _AsyncDirectoryListerCls::close() {
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
        _IOServiceCls->_dispatch(_IOServiceCls::directoryListStop, makeList(ArrayItem))->whenComplete(_cleanup);
    }
}

void _AsyncDirectoryListerCls::error(message ) {
    auto errorType = message[responseError][_errorResponseErrorType];
    if (errorType == _illegalArgumentResponse) {
        controller->addError(make<ArgumentErrorCls>());
    } else {
        if (errorType == _osErrorResponse) {
        auto responseErrorInfo = message[responseError];
        auto err = make<OSErrorCls>(responseErrorInfo[_osErrorResponseMessage], responseErrorInfo[_osErrorResponseErrorCode]);
        auto errorPath = message[responsePath];
        if (errorPath == nullptr) {
            errorPath = utf8->decode(rawPath, true);
        } else {
            if (is<Uint8List>(errorPath)) {
            as<Uint8ListCls>(errorPath) = utf8->decode(message[responsePath], true);
        }
;
        }        controller->addError(make<FileSystemExceptionCls>(__s("Directory listing failed"), errorPath, err));
    } else {
        controller->addError(make<FileSystemExceptionCls>(__s("Internal error")));
    }
;
    }}

_AsyncDirectoryListerCls::_AsyncDirectoryListerCls(Uint8List rawPath, bool recursive, bool followLinks) {
    {
            auto _c1 = controller;    _c1.onListen = auto _c2 = onListen;    _c2.onResume = auto _c3 = onResume;    _c3.onCancel = onCancel;    _c3;    _c2;_c1;
    }
}

int _AsyncDirectoryListerCls::_pointer() {
    return _ops?->getPointer();
}

void _AsyncDirectoryListerCls::_cleanup() {
    controller->close();
    closeCompleter->complete();
    _ops = nullptr;
}
