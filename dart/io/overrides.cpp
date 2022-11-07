#include "overrides.hpp"
IOOverrides IOOverrides::current() {
    return Zone.current[_ioOverridesToken] ?? _global;
}

void IOOverrides::global(IOOverrides overrides) {
    _global = overrides;
}

R IOOverrides::runZoned<R>(FunctionType body, FunctionType createDirectory, FunctionType createFile, FunctionType createLink, FunctionType fsWatch, FunctionType fsWatchIsSupported, FunctionType fseGetType, FunctionType fseGetTypeSync, FunctionType fseIdentical, FunctionType fseIdenticalSync, FunctionType getCurrentDirectory, FunctionType getSystemTempDirectory, FunctionType serverSocketBind, FunctionType setCurrentDirectory, FunctionType socketConnect, FunctionType socketStartConnect, FunctionType stat, FunctionType statSync, FunctionType stderr, FunctionType stdin, FunctionType stdout) {
    IOOverrides overrides = _IOOverridesScope(createDirectory, getCurrentDirectory, setCurrentDirectory, getSystemTempDirectory, createFile, stat, statSync, fseIdentical, fseIdenticalSync, fseGetType, fseGetTypeSync, fsWatch, fsWatchIsSupported, createLink, socketConnect, socketStartConnect, serverSocketBind, stdin, stdout, stderr);
    return <R>_asyncRunZoned(body);
}

R IOOverrides::runWithIOOverrides<R>(FunctionType body, IOOverrides overrides) {
    return <R>_asyncRunZoned(body);
}

Directory IOOverrides::createDirectory(String path) {
    return _Directory(path);
}

Directory IOOverrides::getCurrentDirectory() {
    return _Directory.current;
}

void IOOverrides::setCurrentDirectory(String path) {
    _Directory.current = path;
}

Directory IOOverrides::getSystemTempDirectory() {
    return _Directory.systemTemp;
}

File IOOverrides::createFile(String path) {
    return _File(path);
}

Future<FileStat> IOOverrides::stat(String path) {
    return FileStat._stat(path);
}

FileStat IOOverrides::statSync(String path) {
    return FileStat._statSyncInternal(path);
}

Future<bool> IOOverrides::fseIdentical(String path1, String path2) {
    return FileSystemEntity._identical(path1, path2);
}

bool IOOverrides::fseIdenticalSync(String path1, String path2) {
    return FileSystemEntity._identicalSync(path1, path2);
}

Future<FileSystemEntityType> IOOverrides::fseGetType(bool followLinks, String path) {
    return FileSystemEntity._getTypeRequest(utf8.encoder.convert(path), followLinks);
}

FileSystemEntityType IOOverrides::fseGetTypeSync(bool followLinks, String path) {
    return FileSystemEntity._getTypeSyncHelper(utf8.encoder.convert(path), followLinks);
}

Stream<FileSystemEvent> IOOverrides::fsWatch(int events, String path, bool recursive) {
    return _FileSystemWatcher._watch(path, events, recursive);
}

bool IOOverrides::fsWatchIsSupported() {
    return _FileSystemWatcher.isSupported;
}

Link IOOverrides::createLink(String path) {
    return _Link(path);
}

Future<Socket> IOOverrides::socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout) {
    return Socket._connect(host, portsourceAddress, sourcePort, timeout);
}

Future<ConnectionTask<Socket>> IOOverrides::socketStartConnect(host , sourceAddress , int port, int sourcePort) {
    return Socket._startConnect(host, portsourceAddress, sourcePort);
}

Future<ServerSocket> IOOverrides::serverSocketBind(address , int backlog, int port, bool shared, bool v6Only) {
    return ServerSocket._bind(address, portbacklog, v6Only, shared);
}

Stdin IOOverrides::stdin() {
    return _stdin;
}

Stdout IOOverrides::stdout() {
    return _stdout;
}

Stdout IOOverrides::stderr() {
    return _stderr;
}

Directory _IOOverridesScope::createDirectory(String path) {
    if (_createDirectory != nullptr)     {
        return _createDirectory!(path);
    }
    if (_previous != nullptr)     {
        return _previous!.createDirectory(path);
    }
    return super.createDirectory(path);
}

Directory _IOOverridesScope::getCurrentDirectory() {
    if (_getCurrentDirectory != nullptr)     {
        return _getCurrentDirectory!();
    }
    if (_previous != nullptr)     {
        return _previous!.getCurrentDirectory();
    }
    return super.getCurrentDirectory();
}

void _IOOverridesScope::setCurrentDirectory(String path) {
    if (_setCurrentDirectory != nullptr)     {
        _setCurrentDirectory!(path);
    } else     {
        if (_previous != nullptr)     {
        _previous!.setCurrentDirectory(path);
    } else     {
        super.setCurrentDirectory(path);
    }
;
    }}

Directory _IOOverridesScope::getSystemTempDirectory() {
    if (_getSystemTempDirectory != nullptr)     {
        return _getSystemTempDirectory!();
    }
    if (_previous != nullptr)     {
        return _previous!.getSystemTempDirectory();
    }
    return super.getSystemTempDirectory();
}

File _IOOverridesScope::createFile(String path) {
    if (_createFile != nullptr)     {
        return _createFile!(path);
    }
    if (_previous != nullptr)     {
        return _previous!.createFile(path);
    }
    return super.createFile(path);
}

Future<FileStat> _IOOverridesScope::stat(String path) {
    if (_stat != nullptr)     {
        return _stat!(path);
    }
    if (_previous != nullptr)     {
        return _previous!.stat(path);
    }
    return super.stat(path);
}

FileStat _IOOverridesScope::statSync(String path) {
    if (_stat != nullptr)     {
        return _statSync!(path);
    }
    if (_previous != nullptr)     {
        return _previous!.statSync(path);
    }
    return super.statSync(path);
}

Future<bool> _IOOverridesScope::fseIdentical(String path1, String path2) {
    if (_fseIdentical != nullptr)     {
        return _fseIdentical!(path1, path2);
    }
    if (_previous != nullptr)     {
        return _previous!.fseIdentical(path1, path2);
    }
    return super.fseIdentical(path1, path2);
}

bool _IOOverridesScope::fseIdenticalSync(String path1, String path2) {
    if (_fseIdenticalSync != nullptr)     {
        return _fseIdenticalSync!(path1, path2);
    }
    if (_previous != nullptr)     {
        return _previous!.fseIdenticalSync(path1, path2);
    }
    return super.fseIdenticalSync(path1, path2);
}

Future<FileSystemEntityType> _IOOverridesScope::fseGetType(bool followLinks, String path) {
    if (_fseGetType != nullptr)     {
        return _fseGetType!(path, followLinks);
    }
    if (_previous != nullptr)     {
        return _previous!.fseGetType(path, followLinks);
    }
    return super.fseGetType(path, followLinks);
}

FileSystemEntityType _IOOverridesScope::fseGetTypeSync(bool followLinks, String path) {
    if (_fseGetTypeSync != nullptr)     {
        return _fseGetTypeSync!(path, followLinks);
    }
    if (_previous != nullptr)     {
        return _previous!.fseGetTypeSync(path, followLinks);
    }
    return super.fseGetTypeSync(path, followLinks);
}

Stream<FileSystemEvent> _IOOverridesScope::fsWatch(int events, String path, bool recursive) {
    if (_fsWatch != nullptr)     {
        return _fsWatch!(path, events, recursive);
    }
    if (_previous != nullptr)     {
        return _previous!.fsWatch(path, events, recursive);
    }
    return super.fsWatch(path, events, recursive);
}

bool _IOOverridesScope::fsWatchIsSupported() {
    if (_fsWatchIsSupported != nullptr)     {
        return _fsWatchIsSupported!();
    }
    if (_previous != nullptr)     {
        return _previous!.fsWatchIsSupported();
    }
    return super.fsWatchIsSupported();
}

Link _IOOverridesScope::createLink(String path) {
    if (_createLink != nullptr)     {
        return _createLink!(path);
    }
    if (_previous != nullptr)     {
        return _previous!.createLink(path);
    }
    return super.createLink(path);
}

Future<Socket> _IOOverridesScope::socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout) {
    if (_socketConnect != nullptr) {
        return _socketConnect!(host, portsourceAddress, timeout);
    }
    if (_previous != nullptr) {
        return _previous!.socketConnect(host, portsourceAddress, sourcePort, timeout);
    }
    return super.socketConnect(host, portsourceAddress, sourcePort, timeout);
}

Future<ConnectionTask<Socket>> _IOOverridesScope::socketStartConnect(host , sourceAddress , int port, int sourcePort) {
    if (_socketStartConnect != nullptr) {
        return _socketStartConnect!(host, portsourceAddress, sourcePort);
    }
    if (_previous != nullptr) {
        return _previous!.socketStartConnect(host, portsourceAddress, sourcePort);
    }
    return super.socketStartConnect(host, portsourceAddress, sourcePort);
}

Future<ServerSocket> _IOOverridesScope::serverSocketBind(address , int backlog, int port, bool shared, bool v6Only) {
    if (_serverSocketBind != nullptr) {
        return _serverSocketBind!(address, portbacklog, v6Only, shared);
    }
    if (_previous != nullptr) {
        return _previous!.serverSocketBind(address, portbacklog, v6Only, shared);
    }
    return super.serverSocketBind(address, portbacklog, v6Only, shared);
}

Stdin _IOOverridesScope::stdin() {
    return _stdin?.call() ?? _previous?.stdin ?? super.stdin;
}

Stdout _IOOverridesScope::stdout() {
    return _stdout?.call() ?? _previous?.stdout ?? super.stdout;
}

Stdout _IOOverridesScope::stderr() {
    return _stderr?.call() ?? _previous?.stderr ?? super.stderr;
}
