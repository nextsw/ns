#include "file_system_entity.hpp"
String FileSystemEntityTypeCls::toString() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem)[_type];
}

FileSystemEntityType FileSystemEntityTypeCls::_lookup(int type) {
    return _typeList[type];
}

FileStat FileStatCls::statSync(String path) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _statSyncInternal(path);
    }
    return overrides->statSync(path);
}

Future<FileStat> FileStatCls::stat(String path) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _stat(path);
    }
    return overrides->stat(path);
}

String FileStatCls::toString() {
    return __s("""FileStat: type $type          changed $changed          modified $modified          accessed $accessed          mode ${modeString()}          size $size""");
}

String FileStatCls::modeString() {
    auto permissions = mode & 0xFFF;
    auto codes = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    auto result = makeList();
    if ((permissions & 0x800) != 0)     {
        result->add(__s("(suid) "));
    }
    if ((permissions & 0x400) != 0)     {
        result->add(__s("(guid) "));
    }
    if ((permissions & 0x200) != 0)     {
        result->add(__s("(sticky) "));
    }
    auto _c1 = result;_c1.auto _c2 = add(codes[(permissions >> 6) & 0x7]);_c2.auto _c3 = add(codes[(permissions >> 3) & 0x7]);_c3.add(codes[permissions & 0x7]);_c3;_c2;_c1;
    return result->join();
}

FileStat FileStatCls::_statSyncInternal(String path) {
    if (PlatformCls::isWindows) {
        path = FileSystemEntityCls->_trimTrailingPathSeparators(path);
    }
    auto data = _statSync(_NamespaceCls::_namespace, path);
    if (is<OSError>(data))     {
        return FileStatCls::_notFound;
    }
    return FileStatCls->_internal(DateTimeCls->fromMillisecondsSinceEpoch(data[_changedTime]), DateTimeCls->fromMillisecondsSinceEpoch(data[_modifiedTime]), DateTimeCls->fromMillisecondsSinceEpoch(data[_accessedTime]), FileSystemEntityTypeCls->_lookup(data[_type]), data[_mode], data[_size]);
}

Future<FileStat> FileStatCls::_stat(String path) {
    if (PlatformCls::isWindows) {
        path = FileSystemEntityCls->_trimTrailingPathSeparators(path);
    }
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileStat, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            return FileStatCls::_notFound;
        }
        List data = response[1];
        return FileStatCls->_internal(DateTimeCls->fromMillisecondsSinceEpoch(data[_changedTime]), DateTimeCls->fromMillisecondsSinceEpoch(data[_modifiedTime]), DateTimeCls->fromMillisecondsSinceEpoch(data[_accessedTime]), FileSystemEntityTypeCls->_lookup(data[_type]), data[_mode], data[_size]);
    });
}

Uri FileSystemEntityCls::uri() {
    return UriCls->file(path());
}

Future<String> FileSystemEntityCls::resolveSymbolicLinks() {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileResolveSymbolicLinks, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot resolve symbolic links"), path());
        }
        return response;
    });
}

String FileSystemEntityCls::resolveSymbolicLinksSync() {
    auto result = _resolveSymbolicLinks(_NamespaceCls::_namespace, _rawPath());
    _throwIfError(result, __s("Cannot resolve symbolic links"), path());
    return result;
}

Future<FileStat> FileSystemEntityCls::stat() {
    return FileStatCls->stat(path());
}

FileStat FileSystemEntityCls::statSync() {
    return FileStatCls->statSync(path());
}

Future<FileSystemEntity> FileSystemEntityCls::delete(bool recursive) {
    return _delete(recursive);
}

void FileSystemEntityCls::deleteSync(bool recursive) {
    return _deleteSync(recursive);
}

Stream<FileSystemEvent> FileSystemEntityCls::watch(int events, bool recursive) {
    String trimmedPath = _trimTrailingPathSeparators(path());
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _FileSystemWatcherCls->_watch(trimmedPath, events, recursive);
    }
    return overrides->fsWatch(trimmedPath, events, recursive);
}

Future<bool> FileSystemEntityCls::identical(String path1, String path2) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _identical(path1, path2);
    }
    return overrides->fseIdentical(path1, path2);
}

bool FileSystemEntityCls::isAbsolute() {
    return _isAbsolute(path());
}

bool FileSystemEntityCls::identicalSync(String path1, String path2) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _identicalSync(path1, path2);
    }
    return overrides->fseIdenticalSync(path1, path2);
}

bool FileSystemEntityCls::isWatchSupported() {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _FileSystemWatcherCls::isSupported;
    }
    return overrides->fsWatchIsSupported();
}

Future<FileSystemEntityType> FileSystemEntityCls::type(String path, bool followLinks) {
    return _getType(_toUtf8Array(path), followLinks);
}

FileSystemEntityType FileSystemEntityCls::typeSync(String path, bool followLinks) {
    return _getTypeSync(_toUtf8Array(path), followLinks);
}

Future<bool> FileSystemEntityCls::isLink(String path) {
    return _isLinkRaw(_toUtf8Array(path));
}

Future<bool> FileSystemEntityCls::isFile(String path) {
    return _getType(_toUtf8Array(path), true)->then([=] (Unknown  type)     {
        (type == FileSystemEntityTypeCls::file);
    });
}

Future<bool> FileSystemEntityCls::isDirectory(String path) {
    return _getType(_toUtf8Array(path), true)->then([=] (Unknown  type)     {
        (type == FileSystemEntityTypeCls::directory);
    });
}

bool FileSystemEntityCls::isLinkSync(String path) {
    return _isLinkRawSync(_toUtf8Array(path));
}

bool FileSystemEntityCls::isFileSync(String path) {
    return (_getTypeSync(_toUtf8Array(path), true) == FileSystemEntityTypeCls::file);
}

bool FileSystemEntityCls::isDirectorySync(String path) {
    return (_getTypeSync(_toUtf8Array(path), true) == FileSystemEntityTypeCls::directory);
}

String FileSystemEntityCls::parentOf(String path) {
    int rootEnd = -1;
    if (PlatformCls::isWindows) {
        if (path->startsWith(_absoluteWindowsPathPattern)) {
            rootEnd = path->indexOf(make<RegExpCls>(__s("[/\\]")), 2);
            if (rootEnd == -1)             {
                return path;
            }
        } else         {
            if (path->startsWith(__s("\\")) || path->startsWith(__s("/"))) {
            rootEnd = 0;
        }
;
        }    } else     {
        if (path->startsWith(__s("/"))) {
        rootEnd = 0;
    }
;
    }    int pos = path->lastIndexOf(_parentRegExp);
    if (pos > rootEnd) {
        return path->substring(0, pos + 1);
    } else     {
        if (rootEnd > -1) {
        return path->substring(0, rootEnd + 1);
    } else {
        return __s(".");
    }
;
    }}

Directory FileSystemEntityCls::parent() {
    return make<DirectoryCls>(parentOf(path()));
}

Future<bool> FileSystemEntityCls::_identical(String path1, String path2) {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileIdentical, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Error in FileSystemEntity.identical($path1, $path2)"), __s(""));
        }
        return response;
    });
}

bool FileSystemEntityCls::_isAbsolute(String path) {
    if (PlatformCls::isWindows) {
        return path->startsWith(_absoluteWindowsPathPattern);
    } else {
        return path->startsWith(__s("/"));
    }
}

String FileSystemEntityCls::_absolutePath() {
    if (isAbsolute())     {
        return path();
    }
    if (PlatformCls::isWindows)     {
        return _absoluteWindowsPath(path());
    }
    String current = DirectoryCls::current->path;
    if (current->endsWith(__s("/"))) {
        return __s("$current$path");
    } else {
        return __s("$current${Platform.pathSeparator}$path");
    }
}

int FileSystemEntityCls::_windowsDriveLetter(String path) {
    if (path->isEmpty() || !path->startsWith(__s(":"), 1))     {
        return -1;
    }
    auto first = path->codeUnitAt(0) & ~0x20;
    if (first >= 0x41 && first <= 0x5b)     {
        return first;
    }
    return -1;
}

String FileSystemEntityCls::_absoluteWindowsPath(String path) {
    assert(PlatformCls::isWindows);
    assert(!_isAbsolute(path));
    auto current = DirectoryCls::current->path;
    if (path->startsWith(__s("\"))) {
        assert(!path->startsWith(__s("\"), 1));
        auto currentDrive = _windowsDriveLetter(current);
        if (currentDrive >= 0) {
            return __s("${current[0]}:$path");
        }
        if (current->startsWith(__s("\\"))) {
            auto serverEnd = current->indexOf(__s("\"), 2);
            if (serverEnd >= 0) {
                auto shareEnd = current->indexOf(__s("\"), serverEnd + 1);
                if ( < 0)                 {
                    shareEnd = current->length();
                }
                return __s("${current.substring(0, shareEnd)}$path");
            }
        }
        return path;
    }
    auto entityDrive = _windowsDriveLetter(path);
    if (entityDrive >= 0) {
        if (entityDrive != _windowsDriveLetter(current)) {
            return __s("${path[0]}:\\$path");
        }
        path = path->substring(2);
        assert(!path->startsWith(__s("\\")));
    }
    if (current->endsWith(__s("\")) || current->endsWith(__s("/"))) {
        return __s("$current$path");
    }
    return __s("$current\\$path");
}

bool FileSystemEntityCls::_identicalSync(String path1, String path2) {
    auto result = _identicalNative(_NamespaceCls::_namespace, path1, path2);
    _throwIfError(result, __s("Error in FileSystemEntity.identicalSync"));
    return result;
}

Uint8List FileSystemEntityCls::_toUtf8Array(String s) {
    return _toNullTerminatedUtf8Array(utf8->encoder->convert(s));
}

Uint8List FileSystemEntityCls::_toNullTerminatedUtf8Array(Uint8List l) {
    if (l->isEmpty || (l->isNotEmpty && l->last != 0)) {
        Unknown tmp = make<Uint8ListCls>(l->length + 1);
        tmp->setRange(0, l->length, l);
        return tmp;
    } else {
        return l;
    }
}

String FileSystemEntityCls::_toStringFromUtf8Array(Uint8List l) {
    Uint8List nonNullTerminated = l;
    if (l->last == 0) {
        nonNullTerminated = Uint8ListCls->view(l->buffer, l->offsetInBytes, l->length - 1);
    }
    return utf8->decode(nonNullTerminated, true);
}

Future<bool> FileSystemEntityCls::_isLinkRaw(Uint8List rawPath) {
    return _getType(rawPath, false)->then([=] (Unknown  type)     {
        (type == FileSystemEntityTypeCls::link);
    });
}

bool FileSystemEntityCls::_isLinkRawSync(rawPath ) {
    return (_getTypeSync(rawPath, false) == FileSystemEntityTypeCls::link);
}

FileSystemEntityType FileSystemEntityCls::_getTypeSyncHelper(Uint8List rawPath, bool followLinks) {
    auto result = _getTypeNative(_NamespaceCls::_namespace, rawPath, followLinks);
    _throwIfError(result, __s("Error getting type of FileSystemEntity"));
    return FileSystemEntityTypeCls->_lookup(result);
}

FileSystemEntityType FileSystemEntityCls::_getTypeSync(Uint8List rawPath, bool followLinks) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _getTypeSyncHelper(rawPath, followLinks);
    }
    return overrides->fseGetTypeSync(_toStringFromUtf8Array(rawPath), followLinks);
}

Future<FileSystemEntityType> FileSystemEntityCls::_getTypeRequest(Uint8List rawPath, bool followLinks) {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileType, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Error getting type"), utf8->decode(rawPath, true));
        }
        return FileSystemEntityTypeCls->_lookup(response);
    });
}

Future<FileSystemEntityType> FileSystemEntityCls::_getType(Uint8List rawPath, bool followLinks) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _getTypeRequest(rawPath, followLinks);
    }
    return overrides->fseGetType(_toStringFromUtf8Array(rawPath), followLinks);
}

void FileSystemEntityCls::_throwIfError(Object result, String msg, String path) {
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(msg, path, as<OSErrorCls>(result));
    } else     {
        if (is<ArgumentError>(result)) {
        throw result;
    }
;
    }}

String FileSystemEntityCls::_trimTrailingPathSeparators(String path) {
    ArgumentErrorCls->checkNotNull(path, __s("path"));
    if (PlatformCls::isWindows) {
        while (path->length() > 1 && (path->endsWith(PlatformCls::pathSeparator) || path->endsWith(__s("/")))) {
            path = path->substring(0, path->length() - 1);
        }
    } else {
        while (path->length() > 1 && path->endsWith(PlatformCls::pathSeparator)) {
            path = path->substring(0, path->length() - 1);
        }
    }
    return path;
}

String FileSystemEntityCls::_ensureTrailingPathSeparators(String path) {
    if (path->isEmpty())     {
        path = __s(".");
    }
    if (PlatformCls::isWindows) {
        while (!path->endsWith(PlatformCls::pathSeparator) && !path->endsWith(__s("/"))) {
            path = __s("$path${Platform.pathSeparator}");
        }
    } else {
        while (!path->endsWith(PlatformCls::pathSeparator)) {
            path = __s("$path${Platform.pathSeparator}");
        }
    }
    return path;
}

String FileSystemCreateEventCls::toString() {
    return __s("FileSystemCreateEvent('$path')");
}

void FileSystemCreateEventCls::_(path , isDirectory )

String FileSystemModifyEventCls::toString() {
    return __s("FileSystemModifyEvent('$path', contentChanged=$contentChanged)");
}

void FileSystemModifyEventCls::_(path , isDirectory , bool contentChanged)

String FileSystemDeleteEventCls::toString() {
    return __s("FileSystemDeleteEvent('$path')");
}

void FileSystemDeleteEventCls::_(path , isDirectory )

String FileSystemMoveEventCls::toString() {
    auto buffer = make<StringBufferCls>();
    buffer->write(__s("FileSystemMoveEvent('$path'"));
    if (destination != nullptr)     {
        buffer->write(__s(", '$destination'"));
    }
    buffer->write(__s(")"));
    return buffer->toString();
}

void FileSystemMoveEventCls::_(path , isDirectory , String destination)
