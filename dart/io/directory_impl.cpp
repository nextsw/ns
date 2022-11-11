#include "directory_impl.hpp"
void _DirectoryCls::fromRawPath(Uint8List rawPath)

String _DirectoryCls::path() {
    return _path;
}

Directory _DirectoryCls::current() {
    auto result = _current(_NamespaceCls::_namespace);
    if (is<OSError>(result)) {
        ;
    }
    return make<_DirectoryCls>(result);
}

void _DirectoryCls::current(path ) {
    Uint8List _rawPath;
    if (is<_Directory>(path)) {
        _rawPath = as<_DirectoryCls>(path)->_rawPath;
    } else     {
        if (is<Directory>(path)) {
        _rawPath = FileSystemEntityCls->_toUtf8Array(as<DirectoryCls>(path)->as<DirectoryCls>(path));
    } else     {
        if (is<String>(path)) {
        _rawPath = FileSystemEntityCls->_toUtf8Array(as<StringCls>(path));
    } else {
        ;
    }
;
    };
    }    if (!_EmbedderConfigCls->_mayChdir) {
        ;
    }
    auto result = _setCurrent(_NamespaceCls::_namespace, _rawPath);
    if (is<ArgumentError>(result))     {
        ;
    }
    if (is<OSError>(result)) {
        ;
    }
}

Uri _DirectoryCls::uri() {
    return UriCls->directory(path());
}

Future<bool> _DirectoryCls::exists() {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryExists, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            ;
        }
        return response == 1;
    });
}

bool _DirectoryCls::existsSync() {
    auto result = _exists(_NamespaceCls::_namespace, _rawPath);
    if (is<OSError>(result)) {
        ;
    }
    return (result == 1);
}

Directory _DirectoryCls::absolute() {
    return make<DirectoryCls>(_absolutePath);
}

Future<Directory> _DirectoryCls::create(bool recursive) {
    if (recursive) {
        return exists()->then([=] (Unknown  exists) {
            if (exists)             {
                return this;
            }
            if (path() != parent->path) {
                return parent->create(true)->then([=] () {
                    return create();
                });
            } else {
                return create();
            }
        });
    } else {
        return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryCreate, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
            if (_isErrorResponse(response)) {
                ;
            }
            return this;
        });
    }
}

void _DirectoryCls::createSync(bool recursive) {
    if (recursive) {
        if (existsSync())         {
            return;
        }
        if (path() != parent->path) {
            parent->createSync(true);
        }
    }
    auto result = _create(_NamespaceCls::_namespace, _rawPath);
    if (is<OSError>(result)) {
        ;
    }
}

Directory _DirectoryCls::systemTemp() {
    return make<DirectoryCls>(_systemTemp(_NamespaceCls::_namespace));
}

Future<Directory> _DirectoryCls::createTemp(String prefix) {
    prefix = __s("");
    if (path() == __s("")) {
        ;
    }
    String fullPrefix;
    if (path()->endsWith(__s("/")) || (PlatformCls::isWindows && path()->endsWith(__s("\\")))) {
        fullPrefix = __s("$path$prefix");
    } else {
        fullPrefix = __s("$path${Platform.pathSeparator}$prefix");
    }
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryCreateTemp, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            ;
        }
        return make<DirectoryCls>(response);
    });
}

Directory _DirectoryCls::createTempSync(String prefix) {
    prefix = __s("");
    if (path() == __s("")) {
        ;
    }
    String fullPrefix;
    if (path()->endsWith(__s("/")) || (PlatformCls::isWindows && path()->endsWith(__s("\\")))) {
        fullPrefix = __s("$path$prefix");
    } else {
        fullPrefix = __s("$path${Platform.pathSeparator}$prefix");
    }
    auto result = _createTemp(_NamespaceCls::_namespace, FileSystemEntityCls->_toUtf8Array(fullPrefix));
    if (is<OSError>(result)) {
        ;
    }
    return make<DirectoryCls>(result);
}

Future<Directory> _DirectoryCls::rename(String newPath) {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::directoryRename, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            ;
        }
        return make<DirectoryCls>(newPath);
    });
}

Directory _DirectoryCls::renameSync(String newPath) {
    ArgumentErrorCls->checkNotNull(newPath, __s("newPath"));
    auto result = _rename(_NamespaceCls::_namespace, _rawPath, newPath);
    if (is<OSError>(result)) {
        ;
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
    return __s("Directory: '$path'");
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
            ;
        }
        return this;
    });
}

void _DirectoryCls::_deleteSync(bool recursive) {
    auto result = _deleteNative(_NamespaceCls::_namespace, _rawPath, recursive);
    if (is<OSError>(result)) {
        ;
    }
}

bool _DirectoryCls::_isErrorResponse(response ) {
    return is<List>(response) && response[0] != _successResponse;
}

void _DirectoryCls::_exceptionOrErrorFromResponse(response , String message) {
    assert(_isErrorResponse(response));
    ;
}

T _DirectoryCls::_checkNotNulltemplate<typename T> (String name, T t) {
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
        } else         {
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

Future _AsyncDirectoryListerCls::onCancel() {
    canceled = true;
    if (!nextRunning) {
        close();
    }
    return closeCompleter->future;
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
        if (is<List>(result)) {
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
    } else     {
        if (errorType == _osErrorResponse) {
        auto responseErrorInfo = message[responseError];
        auto err = make<OSErrorCls>(responseErrorInfo[_osErrorResponseMessage], responseErrorInfo[_osErrorResponseErrorCode]);
        auto errorPath = message[responsePath];
        if (errorPath == nullptr) {
            errorPath = utf8->decode(rawPathtrue);
        } else         {
            if (is<Uint8List>(errorPath)) {
            as<Uint8ListCls>(errorPath) = utf8->decode(message[responsePath]true);
        }
;
        }        controller->addError(make<FileSystemExceptionCls>(__s("Directory listing failed"), errorPath, err));
    } else {
        controller->addError(make<FileSystemExceptionCls>(__s("Internal error")));
    }
;
    }}

_AsyncDirectoryListerCls::_AsyncDirectoryListerCls(bool followLinks, Uint8List rawPath, bool recursive) {
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
