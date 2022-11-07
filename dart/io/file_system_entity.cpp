#include "file_system_entity.hpp"
String FileSystemEntityType::toString() {
    return const [_type];
}

FileSystemEntityType FileSystemEntityType::_lookup(int type) {
    return _typeList[type];
}

FileStat FileStat::statSync(String path) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _statSyncInternal(path);
    }
    return overrides.statSync(path);
}

Future<FileStat> FileStat::stat(String path) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _stat(path);
    }
    return overrides.stat(path);
}

String FileStat::toString() {
    return """FileStat: type $type          changed $changed          modified $modified          accessed $accessed          mode ${modeString()}          size $size""";
}

String FileStat::modeString() {
    auto permissions = mode & 0xFFF;
    auto codes = const ;
    auto result = ;
    if ((permissions & 0x800) != 0)     {
        result.add("(suid) ");
    }
    if ((permissions & 0x400) != 0)     {
        result.add("(guid) ");
    }
    if ((permissions & 0x200) != 0)     {
        result.add("(sticky) ");
    }
    ;
    return result.join();
}

FileStat FileStat::_statSyncInternal(String path) {
    if (Platform.isWindows) {
        path = FileSystemEntity._trimTrailingPathSeparators(path);
    }
    auto data = _statSync(_Namespace._namespace, path);
    if (data is OSError)     {
        return FileStat._notFound;
    }
    return FileStat._internal(DateTime.fromMillisecondsSinceEpoch(data[_changedTime]), DateTime.fromMillisecondsSinceEpoch(data[_modifiedTime]), DateTime.fromMillisecondsSinceEpoch(data[_accessedTime]), FileSystemEntityType._lookup(data[_type]), data[_mode], data[_size]);
}

Future<FileStat> FileStat::_stat(String path) {
    if (Platform.isWindows) {
        path = FileSystemEntity._trimTrailingPathSeparators(path);
    }
    return _File._dispatchWithNamespace(_IOService.fileStat, ).then();
}

Uri FileSystemEntity::uri() {
    return Uri.file(path);
}

Future<String> FileSystemEntity::resolveSymbolicLinks() {
    return _File._dispatchWithNamespace(_IOService.fileResolveSymbolicLinks, ).then();
}

String FileSystemEntity::resolveSymbolicLinksSync() {
    auto result = _resolveSymbolicLinks(_Namespace._namespace, _rawPath);
    _throwIfError(result, "Cannot resolve symbolic links", path);
    return result;
}

Future<FileStat> FileSystemEntity::stat() {
    return FileStat.stat(path);
}

FileStat FileSystemEntity::statSync() {
    return FileStat.statSync(path);
}

Future<FileSystemEntity> FileSystemEntity::delete(bool recursive) {
    return _delete(recursive);
}

void FileSystemEntity::deleteSync(bool recursive) {
    return _deleteSync(recursive);
}

Stream<FileSystemEvent> FileSystemEntity::watch(int events, bool recursive) {
    String trimmedPath = _trimTrailingPathSeparators(path);
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _FileSystemWatcher._watch(trimmedPath, events, recursive);
    }
    return overrides.fsWatch(trimmedPath, events, recursive);
}

Future<bool> FileSystemEntity::identical(String path1, String path2) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _identical(path1, path2);
    }
    return overrides.fseIdentical(path1, path2);
}

bool FileSystemEntity::isAbsolute() {
    return _isAbsolute(path);
}

bool FileSystemEntity::identicalSync(String path1, String path2) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _identicalSync(path1, path2);
    }
    return overrides.fseIdenticalSync(path1, path2);
}

bool FileSystemEntity::isWatchSupported() {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _FileSystemWatcher.isSupported;
    }
    return overrides.fsWatchIsSupported();
}

Future<FileSystemEntityType> FileSystemEntity::type(bool followLinks, String path) {
    return _getType(_toUtf8Array(path), followLinks);
}

FileSystemEntityType FileSystemEntity::typeSync(bool followLinks, String path) {
    return _getTypeSync(_toUtf8Array(path), followLinks);
}

Future<bool> FileSystemEntity::isLink(String path) {
    return _isLinkRaw(_toUtf8Array(path));
}

Future<bool> FileSystemEntity::isFile(String path) {
    return _getType(_toUtf8Array(path), true).then();
}

Future<bool> FileSystemEntity::isDirectory(String path) {
    return _getType(_toUtf8Array(path), true).then();
}

bool FileSystemEntity::isLinkSync(String path) {
    return _isLinkRawSync(_toUtf8Array(path));
}

bool FileSystemEntity::isFileSync(String path) {
    return (_getTypeSync(_toUtf8Array(path), true) == FileSystemEntityType.file);
}

bool FileSystemEntity::isDirectorySync(String path) {
    return (_getTypeSync(_toUtf8Array(path), true) == FileSystemEntityType.directory);
}

String FileSystemEntity::parentOf(String path) {
    int rootEnd = -1;
    if (Platform.isWindows) {
        if (path.startsWith(_absoluteWindowsPathPattern)) {
            rootEnd = path.indexOf(RegExp("[/\\]"), 2);
            if (rootEnd == -1)             {
                return path;
            }
        } else         {
            if (path.startsWith("\\") || path.startsWith("/")) {
            rootEnd = 0;
        }
;
        }    } else     {
        if (path.startsWith("/")) {
        rootEnd = 0;
    }
;
    }    int pos = path.lastIndexOf(_parentRegExp);
    if (pos > rootEnd) {
        return path.substring(0, pos + 1);
    } else     {
        if (rootEnd > -1) {
        return path.substring(0, rootEnd + 1);
    } else {
        return ".";
    }
;
    }}

Directory FileSystemEntity::parent() {
    return Directory(parentOf(path));
}

Future<bool> FileSystemEntity::_identical(String path1, String path2) {
    return _File._dispatchWithNamespace(_IOService.fileIdentical, ).then();
}

bool FileSystemEntity::_isAbsolute(String path) {
    if (Platform.isWindows) {
        return path.startsWith(_absoluteWindowsPathPattern);
    } else {
        return path.startsWith("/");
    }
}

String FileSystemEntity::_absolutePath() {
    if (isAbsolute)     {
        return path;
    }
    if (Platform.isWindows)     {
        return _absoluteWindowsPath(path);
    }
    String current = Directory.current.path;
    if (current.endsWith("/")) {
        return "$current$path";
    } else {
        return "$current${Platform.pathSeparator}$path";
    }
}

int FileSystemEntity::_windowsDriveLetter(String path) {
    if (path.isEmpty || !path.startsWith(":", 1))     {
        return -1;
    }
    auto first = path.codeUnitAt(0) & ~0x20;
    if (first >= 0x41 && first <= 0x5b)     {
        return first;
    }
    return -1;
}

String FileSystemEntity::_absoluteWindowsPath(String path) {
    assert(Platform.isWindows);
    assert(!_isAbsolute(path));
    auto current = Directory.current.path;
    if (path.startsWith("\")) {
        assert(!path.startsWith("\", 1));
        auto currentDrive = _windowsDriveLetter(current);
        if (currentDrive >= 0) {
            return "${current[0]}:$path";
        }
        if (current.startsWith("\\")) {
            auto serverEnd = current.indexOf("\", 2);
            if (serverEnd >= 0) {
                auto shareEnd = current.indexOf("\", serverEnd + 1);
                if ( < 0)                 {
                    shareEnd = current.length;
                }
                return "${current.substring(0, shareEnd)}$path";
            }
        }
        return path;
    }
    auto entityDrive = _windowsDriveLetter(path);
    if (entityDrive >= 0) {
        if (entityDrive != _windowsDriveLetter(current)) {
            return "${path[0]}:\\$path";
        }
        path = path.substring(2);
        assert(!path.startsWith("\\"));
    }
    if (current.endsWith("\") || current.endsWith("/")) {
        return "$current$path";
    }
    return "$current\\$path";
}

bool FileSystemEntity::_identicalSync(String path1, String path2) {
    auto result = _identicalNative(_Namespace._namespace, path1, path2);
    _throwIfError(result, "Error in FileSystemEntity.identicalSync");
    return result;
}

Uint8List FileSystemEntity::_toUtf8Array(String s) {
    return _toNullTerminatedUtf8Array(utf8.encoder.convert(s));
}

Uint8List FileSystemEntity::_toNullTerminatedUtf8Array(Uint8List l) {
    if (l.isEmpty || (l.isNotEmpty && l.last != 0)) {
        Unknown tmp = Uint8List(l.length + 1);
        tmp.setRange(0, l.length, l);
        return tmp;
    } else {
        return l;
    }
}

String FileSystemEntity::_toStringFromUtf8Array(Uint8List l) {
    Uint8List nonNullTerminated = l;
    if (l.last == 0) {
        nonNullTerminated = Uint8List.view(l.buffer, l.offsetInBytes, l.length - 1);
    }
    return utf8.decode(nonNullTerminatedtrue);
}

Future<bool> FileSystemEntity::_isLinkRaw(Uint8List rawPath) {
    return _getType(rawPath, false).then();
}

bool FileSystemEntity::_isLinkRawSync(rawPath ) {
    return (_getTypeSync(rawPath, false) == FileSystemEntityType.link);
}

FileSystemEntityType FileSystemEntity::_getTypeSyncHelper(bool followLinks, Uint8List rawPath) {
    auto result = _getTypeNative(_Namespace._namespace, rawPath, followLinks);
    _throwIfError(result, "Error getting type of FileSystemEntity");
    return FileSystemEntityType._lookup(result);
}

FileSystemEntityType FileSystemEntity::_getTypeSync(bool followLinks, Uint8List rawPath) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _getTypeSyncHelper(rawPath, followLinks);
    }
    return overrides.fseGetTypeSync(_toStringFromUtf8Array(rawPath), followLinks);
}

Future<FileSystemEntityType> FileSystemEntity::_getTypeRequest(bool followLinks, Uint8List rawPath) {
    return _File._dispatchWithNamespace(_IOService.fileType, ).then();
}

Future<FileSystemEntityType> FileSystemEntity::_getType(bool followLinks, Uint8List rawPath) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _getTypeRequest(rawPath, followLinks);
    }
    return overrides.fseGetType(_toStringFromUtf8Array(rawPath), followLinks);
}

void FileSystemEntity::_throwIfError(String msg, String path, Object result) {
    if (result is OSError) {
        ;
    } else     {
        if (result is ArgumentError) {
        ;
    }
;
    }}

String FileSystemEntity::_trimTrailingPathSeparators(String path) {
    ArgumentError.checkNotNull(path, "path");
    if (Platform.isWindows) {
        while (path.length > 1 && (path.endsWith(Platform.pathSeparator) || path.endsWith("/"))) {
            path = path.substring(0, path.length - 1);
        }
    } else {
        while (path.length > 1 && path.endsWith(Platform.pathSeparator)) {
            path = path.substring(0, path.length - 1);
        }
    }
    return path;
}

String FileSystemEntity::_ensureTrailingPathSeparators(String path) {
    if (path.isEmpty)     {
        path = ".";
    }
    if (Platform.isWindows) {
        while (!path.endsWith(Platform.pathSeparator) && !path.endsWith("/")) {
            path = "$path${Platform.pathSeparator}";
        }
    } else {
        while (!path.endsWith(Platform.pathSeparator)) {
            path = "$path${Platform.pathSeparator}";
        }
    }
    return path;
}

String FileSystemCreateEvent::toString() {
    return "FileSystemCreateEvent('$path')";
}

void FileSystemCreateEvent::_(path , isDirectory )

String FileSystemModifyEvent::toString() {
    return "FileSystemModifyEvent('$path', contentChanged=$contentChanged)";
}

void FileSystemModifyEvent::_(path , isDirectory , bool contentChanged)

String FileSystemDeleteEvent::toString() {
    return "FileSystemDeleteEvent('$path')";
}

void FileSystemDeleteEvent::_(path , isDirectory )

String FileSystemMoveEvent::toString() {
    auto buffer = StringBuffer();
    buffer.write("FileSystemMoveEvent('$path'");
    if (destination != nullptr)     {
        buffer.write(", '$destination'");
    }
    buffer.write(")");
    return buffer.toString();
}

void FileSystemMoveEvent::_(path , isDirectory , String destination)
