#ifndef DART_IO_OVERRIDES
#define DART_IO_OVERRIDES
#include <base.hpp>

#include <dart/core/core.hpp>

auto  _ioOverridesToken;

auto  _asyncRunZoned;


class IOOverridesCls : public ObjectCls {
public:

    static IOOverrides current();

    static void  global(IOOverrides overrides);

    template<typename R>  static R runZoned(R body() , Directory createDirectory(String ) , File createFile(String ) , Link createLink(String ) , Stream<FileSystemEvent> fsWatch(String , int , bool ) , bool fsWatchIsSupported() , Future<FileSystemEntityType> fseGetType(String , bool ) , FileSystemEntityType fseGetTypeSync(String , bool ) , Future<bool> fseIdentical(String , String ) , bool fseIdenticalSync(String , String ) , Directory getCurrentDirectory() , Directory getSystemTempDirectory() , Future<ServerSocket> serverSocketBind(dynamic , int , int backlog, bool shared, bool v6Only) , void setCurrentDirectory(String ) , Future<Socket> socketConnect(dynamic , int , dynamic sourceAddress, int sourcePort, Duration timeout) , Future<ConnectionTask<Socket>> socketStartConnect(dynamic , int , dynamic sourceAddress, int sourcePort) , Future<FileStat> stat(String ) , FileStat statSync(String ) , Stdout stderr() , Stdin stdin() , Stdout stdout() );

    template<typename R>  static R runWithIOOverrides(R body() , IOOverrides overrides);

    virtual Directory createDirectory(String path);

    virtual Directory getCurrentDirectory();

    virtual void setCurrentDirectory(String path);

    virtual Directory getSystemTempDirectory();

    virtual File createFile(String path);

    virtual Future<FileStat> stat(String path);

    virtual FileStat statSync(String path);

    virtual Future<bool> fseIdentical(String path1, String path2);

    virtual bool fseIdenticalSync(String path1, String path2);

    virtual Future<FileSystemEntityType> fseGetType(bool followLinks, String path);

    virtual FileSystemEntityType fseGetTypeSync(bool followLinks, String path);

    virtual Stream<FileSystemEvent> fsWatch(int events, String path, bool recursive);

    virtual bool fsWatchIsSupported();

    virtual Link createLink(String path);

    virtual Future<Socket> socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout);

    virtual Future<ConnectionTask<Socket>> socketStartConnect(host , sourceAddress , int port, int sourcePort);

    virtual Future<ServerSocket> serverSocketBind(address , int backlog, int port, bool shared, bool v6Only);

    virtual Stdin stdin();

    virtual Stdout stdout();

    virtual Stdout stderr();

private:
    static IOOverrides _global;


};
using IOOverrides = std::shared_ptr<IOOverridesCls>;

class _IOOverridesScopeCls : public IOOverridesCls {
public:

    virtual Directory createDirectory(String path);

    virtual Directory getCurrentDirectory();

    virtual void setCurrentDirectory(String path);

    virtual Directory getSystemTempDirectory();

    virtual File createFile(String path);

    virtual Future<FileStat> stat(String path);

    virtual FileStat statSync(String path);

    virtual Future<bool> fseIdentical(String path1, String path2);

    virtual bool fseIdenticalSync(String path1, String path2);

    virtual Future<FileSystemEntityType> fseGetType(bool followLinks, String path);

    virtual FileSystemEntityType fseGetTypeSync(bool followLinks, String path);

    virtual Stream<FileSystemEvent> fsWatch(int events, String path, bool recursive);

    virtual bool fsWatchIsSupported();

    virtual Link createLink(String path);

    virtual Future<Socket> socketConnect(host , sourceAddress , int port, int sourcePort, Duration timeout);

    virtual Future<ConnectionTask<Socket>> socketStartConnect(host , sourceAddress , int port, int sourcePort);

    virtual Future<ServerSocket> serverSocketBind(address , int backlog, int port, bool shared, bool v6Only);

    virtual Stdin stdin();

    virtual Stdout stdout();

    virtual Stdout stderr();

private:
    IOOverrides _previous;

    Directory Function(String ) _createDirectory;

    Directory Function() _getCurrentDirectory;

    void Function(String ) _setCurrentDirectory;

    Directory Function() _getSystemTempDirectory;

    File Function(String ) _createFile;

    Future<FileStat> Function(String ) _stat;

    FileStat Function(String ) _statSync;

    Future<bool> Function(String , String ) _fseIdentical;

    bool Function(String , String ) _fseIdenticalSync;

    Future<FileSystemEntityType> Function(String , bool ) _fseGetType;

    FileSystemEntityType Function(String , bool ) _fseGetTypeSync;

    Stream<FileSystemEvent> Function(String , int , bool ) _fsWatch;

    bool Function() _fsWatchIsSupported;

    Link Function(String ) _createLink;

    Future<Socket> Function(dynamic , int , dynamic sourceAddress, int sourcePort, Duration timeout) _socketConnect;

    Future<ConnectionTask<Socket>> Function(dynamic , int , dynamic sourceAddress, int sourcePort) _socketStartConnect;

    Future<ServerSocket> Function(dynamic , int , int backlog, bool shared, bool v6Only) _serverSocketBind;

    Stdin Function() _stdin;

    Stdout Function() _stdout;

    Stdout Function() _stderr;


     _IOOverridesScopeCls(Directory Function(String ) _createDirectory, File Function(String ) _createFile, Link Function(String ) _createLink, Stream<FileSystemEvent> Function(String , int , bool ) _fsWatch, bool Function() _fsWatchIsSupported, Future<FileSystemEntityType> Function(String , bool ) _fseGetType, FileSystemEntityType Function(String , bool ) _fseGetTypeSync, Future<bool> Function(String , String ) _fseIdentical, bool Function(String , String ) _fseIdenticalSync, Directory Function() _getCurrentDirectory, Directory Function() _getSystemTempDirectory, Future<ServerSocket> Function(dynamic , int , int backlog, bool shared, bool v6Only) _serverSocketBind, void Function(String ) _setCurrentDirectory, Future<Socket> Function(dynamic , int , dynamic sourceAddress, int sourcePort, Duration timeout) _socketConnect, Future<ConnectionTask<Socket>> Function(dynamic , int , dynamic sourceAddress, int sourcePort) _socketStartConnect, Future<FileStat> Function(String ) _stat, FileStat Function(String ) _statSync, Stdout Function() _stderr, Stdin Function() _stdin, Stdout Function() _stdout);
};
using _IOOverridesScope = std::shared_ptr<_IOOverridesScopeCls>;


#endif