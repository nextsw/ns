#include "overrides.hpp"
IOOverrides IOOverridesCls::current() {
    return ZoneCls::current[_ioOverridesToken] or _global;
}

void IOOverridesCls::global(IOOverrides overrides) {
    _global = overrides;
}

template<typename R>
R IOOverridesCls::runZoned(std::function<R()> body, std::function<Directory(String )> createDirectory, std::function<File(String )> createFile, std::function<Link(String )> createLink, std::function<Stream<FileSystemEvent>(String , int , bool )> fsWatch, std::function<bool()> fsWatchIsSupported, std::function<Future<FileSystemEntityType>(String , bool )> fseGetType, std::function<FileSystemEntityType(String , bool )> fseGetTypeSync, std::function<Future<bool>(String , String )> fseIdentical, std::function<bool(String , String )> fseIdenticalSync, std::function<Directory()> getCurrentDirectory, std::function<Directory()> getSystemTempDirectory, std::function<Future<ServerSocket>(dynamic , int , int backlog, bool shared, bool v6Only)> serverSocketBind, std::function<void(String )> setCurrentDirectory, std::function<Future<Socket>(dynamic , int , dynamic sourceAddress, int sourcePort, Duration timeout)> socketConnect, std::function<Future<ConnectionTask<Socket>>(dynamic , int , dynamic sourceAddress, int sourcePort)> socketStartConnect, std::function<Future<FileStat>(String )> stat, std::function<FileStat(String )> statSync, std::function<Stdout()> stderr, std::function<Stdin()> stdin, std::function<Stdout()> stdout) {
    IOOverrides overrides = make<_IOOverridesScopeCls>(createDirectory, getCurrentDirectory, setCurrentDirectory, getSystemTempDirectory, createFile, stat, statSync, fseIdentical, fseIdenticalSync, fseGetType, fseGetTypeSync, fsWatch, fsWatchIsSupported, createLink, socketConnect, socketStartConnect, serverSocketBind, stdin, stdout, stderr);
    map1.set(_ioOverridesToken, overrides);return <R>_asyncRunZoned(bodylist1);
}

template<typename R>
R IOOverridesCls::runWithIOOverrides(std::function<R()> body, IOOverrides overrides) {
    map1.set(_ioOverridesToken, overrides);return <R>_asyncRunZoned(bodylist1);
}

Directory IOOverridesCls::createDirectory(String path) {
    return make<_DirectoryCls>(path);
}

Directory IOOverridesCls::getCurrentDirectory() {
    return _DirectoryCls::current;
}

void IOOverridesCls::setCurrentDirectory(String path) {
    _DirectoryCls::current = path;
}

Directory IOOverridesCls::getSystemTempDirectory() {
    return _DirectoryCls::systemTemp;
}

File IOOverridesCls::createFile(String path) {
    return make<_FileCls>(path);
}

Future<FileStat> IOOverridesCls::stat(String path) {
    return FileStatCls->_stat(path);
}

FileStat IOOverridesCls::statSync(String path) {
    return FileStatCls->_statSyncInternal(path);
}

Future<bool> IOOverridesCls::fseIdentical(String path1, String path2) {
    return FileSystemEntityCls->_identical(path1, path2);
}

bool IOOverridesCls::fseIdenticalSync(String path1, String path2) {
    return FileSystemEntityCls->_identicalSync(path1, path2);
}

Future<FileSystemEntityType> IOOverridesCls::fseGetType(bool followLinks, String path) {
    return FileSystemEntityCls->_getTypeRequest(utf8->encoder->convert(path), followLinks);
}

FileSystemEntityType IOOverridesCls::fseGetTypeSync(bool followLinks, String path) {
    return FileSystemEntityCls->_getTypeSyncHelper(utf8->encoder->convert(path), followLinks);
}

Stream<FileSystemEvent> IOOverridesCls::fsWatch(int events, String path, bool recursive) {
    return _FileSystemWatcherCls->_watch(path, events, recursive);
}

bool IOOverridesCls::fsWatchIsSupported() {
    return _FileSystemWatcherCls::isSupported;
}

Link IOOverridesCls::createLink(String path) {
    return make<_LinkCls>(path);
}

Future<Socket> IOOverridesCls::socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout) {
    return SocketCls->_connect(host, portsourceAddress, sourcePort, timeout);
}

Future<ConnectionTask<Socket>> IOOverridesCls::socketStartConnect(host , sourceAddress , int port, int sourcePort) {
    return SocketCls->_startConnect(host, portsourceAddress, sourcePort);
}

Future<ServerSocket> IOOverridesCls::serverSocketBind(address , int backlog, int port, bool shared, bool v6Only) {
    return ServerSocketCls->_bind(address, portbacklog, v6Only, shared);
}

Stdin IOOverridesCls::stdin() {
    return _stdin;
}

Stdout IOOverridesCls::stdout() {
    return _stdout;
}

Stdout IOOverridesCls::stderr() {
    return _stderr;
}

Directory _IOOverridesScopeCls::createDirectory(String path) {
    if (_createDirectory != nullptr)     {
        return _createDirectory!(path);
    }
    if (_previous != nullptr)     {
        return _previous!->createDirectory(path);
    }
    return super->createDirectory(path);
}

Directory _IOOverridesScopeCls::getCurrentDirectory() {
    if (_getCurrentDirectory != nullptr)     {
        return _getCurrentDirectory!();
    }
    if (_previous != nullptr)     {
        return _previous!->getCurrentDirectory();
    }
    return super->getCurrentDirectory();
}

void _IOOverridesScopeCls::setCurrentDirectory(String path) {
    if (_setCurrentDirectory != nullptr)     {
        _setCurrentDirectory!(path);
    } else     {
        if (_previous != nullptr)     {
        _previous!->setCurrentDirectory(path);
    } else     {
        super->setCurrentDirectory(path);
    }
;
    }}

Directory _IOOverridesScopeCls::getSystemTempDirectory() {
    if (_getSystemTempDirectory != nullptr)     {
        return _getSystemTempDirectory!();
    }
    if (_previous != nullptr)     {
        return _previous!->getSystemTempDirectory();
    }
    return super->getSystemTempDirectory();
}

File _IOOverridesScopeCls::createFile(String path) {
    if (_createFile != nullptr)     {
        return _createFile!(path);
    }
    if (_previous != nullptr)     {
        return _previous!->createFile(path);
    }
    return super->createFile(path);
}

Future<FileStat> _IOOverridesScopeCls::stat(String path) {
    if (_stat != nullptr)     {
        return _stat!(path);
    }
    if (_previous != nullptr)     {
        return _previous!->stat(path);
    }
    return super->stat(path);
}

FileStat _IOOverridesScopeCls::statSync(String path) {
    if (_stat != nullptr)     {
        return _statSync!(path);
    }
    if (_previous != nullptr)     {
        return _previous!->statSync(path);
    }
    return super->statSync(path);
}

Future<bool> _IOOverridesScopeCls::fseIdentical(String path1, String path2) {
    if (_fseIdentical != nullptr)     {
        return _fseIdentical!(path1, path2);
    }
    if (_previous != nullptr)     {
        return _previous!->fseIdentical(path1, path2);
    }
    return super->fseIdentical(path1, path2);
}

bool _IOOverridesScopeCls::fseIdenticalSync(String path1, String path2) {
    if (_fseIdenticalSync != nullptr)     {
        return _fseIdenticalSync!(path1, path2);
    }
    if (_previous != nullptr)     {
        return _previous!->fseIdenticalSync(path1, path2);
    }
    return super->fseIdenticalSync(path1, path2);
}

Future<FileSystemEntityType> _IOOverridesScopeCls::fseGetType(bool followLinks, String path) {
    if (_fseGetType != nullptr)     {
        return _fseGetType!(path, followLinks);
    }
    if (_previous != nullptr)     {
        return _previous!->fseGetType(path, followLinks);
    }
    return super->fseGetType(path, followLinks);
}

FileSystemEntityType _IOOverridesScopeCls::fseGetTypeSync(bool followLinks, String path) {
    if (_fseGetTypeSync != nullptr)     {
        return _fseGetTypeSync!(path, followLinks);
    }
    if (_previous != nullptr)     {
        return _previous!->fseGetTypeSync(path, followLinks);
    }
    return super->fseGetTypeSync(path, followLinks);
}

Stream<FileSystemEvent> _IOOverridesScopeCls::fsWatch(int events, String path, bool recursive) {
    if (_fsWatch != nullptr)     {
        return _fsWatch!(path, events, recursive);
    }
    if (_previous != nullptr)     {
        return _previous!->fsWatch(path, events, recursive);
    }
    return super->fsWatch(path, events, recursive);
}

bool _IOOverridesScopeCls::fsWatchIsSupported() {
    if (_fsWatchIsSupported != nullptr)     {
        return _fsWatchIsSupported!();
    }
    if (_previous != nullptr)     {
        return _previous!->fsWatchIsSupported();
    }
    return super->fsWatchIsSupported();
}

Link _IOOverridesScopeCls::createLink(String path) {
    if (_createLink != nullptr)     {
        return _createLink!(path);
    }
    if (_previous != nullptr)     {
        return _previous!->createLink(path);
    }
    return super->createLink(path);
}

Future<Socket> _IOOverridesScopeCls::socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout) {
    if (_socketConnect != nullptr) {
        return _socketConnect!(host, portsourceAddress, timeout);
    }
    if (_previous != nullptr) {
        return _previous!->socketConnect(host, portsourceAddress, sourcePort, timeout);
    }
    return super->socketConnect(host, portsourceAddress, sourcePort, timeout);
}

Future<ConnectionTask<Socket>> _IOOverridesScopeCls::socketStartConnect(host , sourceAddress , int port, int sourcePort) {
    if (_socketStartConnect != nullptr) {
        return _socketStartConnect!(host, portsourceAddress, sourcePort);
    }
    if (_previous != nullptr) {
        return _previous!->socketStartConnect(host, portsourceAddress, sourcePort);
    }
    return super->socketStartConnect(host, portsourceAddress, sourcePort);
}

Future<ServerSocket> _IOOverridesScopeCls::serverSocketBind(address , int backlog, int port, bool shared, bool v6Only) {
    if (_serverSocketBind != nullptr) {
        return _serverSocketBind!(address, portbacklog, v6Only, shared);
    }
    if (_previous != nullptr) {
        return _previous!->serverSocketBind(address, portbacklog, v6Only, shared);
    }
    return super->serverSocketBind(address, portbacklog, v6Only, shared);
}

Stdin _IOOverridesScopeCls::stdin() {
    return _stdin?->call() or _previous?->stdin or super->stdin;
}

Stdout _IOOverridesScopeCls::stdout() {
    return _stdout?->call() or _previous?->stdout or super->stdout;
}

Stdout _IOOverridesScopeCls::stderr() {
    return _stderr?->call() or _previous?->stderr or super->stderr;
}
