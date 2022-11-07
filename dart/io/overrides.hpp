#ifndef OVERRIDES_H
#define OVERRIDES_H
#include <memory>



auto  _ioOverridesToken;

const auto  _asyncRunZoned;


class IOOverrides {
public:

    static IOOverrides current();

    static void  global(IOOverrides overrides);

    static R runZoned<R>(FunctionType body, FunctionType createDirectory, FunctionType createFile, FunctionType createLink, FunctionType fsWatch, FunctionType fsWatchIsSupported, FunctionType fseGetType, FunctionType fseGetTypeSync, FunctionType fseIdentical, FunctionType fseIdenticalSync, FunctionType getCurrentDirectory, FunctionType getSystemTempDirectory, FunctionType serverSocketBind, FunctionType setCurrentDirectory, FunctionType socketConnect, FunctionType socketStartConnect, FunctionType stat, FunctionType statSync, FunctionType stderr, FunctionType stdin, FunctionType stdout);

    static R runWithIOOverrides<R>(FunctionType body, IOOverrides overrides);

    Directory createDirectory(String path);

    Directory getCurrentDirectory();

    void setCurrentDirectory(String path);

    Directory getSystemTempDirectory();

    File createFile(String path);

    Future<FileStat> stat(String path);

    FileStat statSync(String path);

    Future<bool> fseIdentical(String path1, String path2);

    bool fseIdenticalSync(String path1, String path2);

    Future<FileSystemEntityType> fseGetType(bool followLinks, String path);

    FileSystemEntityType fseGetTypeSync(bool followLinks, String path);

    Stream<FileSystemEvent> fsWatch(int events, String path, bool recursive);

    bool fsWatchIsSupported();

    Link createLink(String path);

    Future<Socket> socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout);

    Future<ConnectionTask<Socket>> socketStartConnect(host , sourceAddress , int port, int sourcePort);

    Future<ServerSocket> serverSocketBind(address , int backlog, int port, bool shared, bool v6Only);

    Stdin stdin();

    Stdout stdout();

    Stdout stderr();

private:
    static IOOverrides _global;


};

class _IOOverridesScope : IOOverrides {
public:

    Directory createDirectory(String path);

    Directory getCurrentDirectory();

    void setCurrentDirectory(String path);

    Directory getSystemTempDirectory();

    File createFile(String path);

    Future<FileStat> stat(String path);

    FileStat statSync(String path);

    Future<bool> fseIdentical(String path1, String path2);

    bool fseIdenticalSync(String path1, String path2);

    Future<FileSystemEntityType> fseGetType(bool followLinks, String path);

    FileSystemEntityType fseGetTypeSync(bool followLinks, String path);

    Stream<FileSystemEvent> fsWatch(int events, String path, bool recursive);

    bool fsWatchIsSupported();

    Link createLink(String path);

    Future<Socket> socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout);

    Future<ConnectionTask<Socket>> socketStartConnect(host , sourceAddress , int port, int sourcePort);

    Future<ServerSocket> serverSocketBind(address , int backlog, int port, bool shared, bool v6Only);

    Stdin stdin();

    Stdout stdout();

    Stdout stderr();

private:
    IOOverrides _previous;

    FunctionType _createDirectory;

    FunctionType _getCurrentDirectory;

    FunctionType _setCurrentDirectory;

    FunctionType _getSystemTempDirectory;

    FunctionType _createFile;

    FunctionType _stat;

    FunctionType _statSync;

    FunctionType _fseIdentical;

    FunctionType _fseIdenticalSync;

    FunctionType _fseGetType;

    FunctionType _fseGetTypeSync;

    FunctionType _fsWatch;

    FunctionType _fsWatchIsSupported;

    FunctionType _createLink;

    FunctionType _socketConnect;

    FunctionType _socketStartConnect;

    FunctionType _serverSocketBind;

    FunctionType _stdin;

    FunctionType _stdout;

    FunctionType _stderr;


     _IOOverridesScope(FunctionType _createDirectory, FunctionType _createFile, FunctionType _createLink, FunctionType _fsWatch, FunctionType _fsWatchIsSupported, FunctionType _fseGetType, FunctionType _fseGetTypeSync, FunctionType _fseIdentical, FunctionType _fseIdenticalSync, FunctionType _getCurrentDirectory, FunctionType _getSystemTempDirectory, FunctionType _serverSocketBind, FunctionType _setCurrentDirectory, FunctionType _socketConnect, FunctionType _socketStartConnect, FunctionType _stat, FunctionType _statSync, FunctionType _stderr, FunctionType _stdin, FunctionType _stdout);

};

#endif