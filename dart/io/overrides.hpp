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

    template<typename R>
 static R runZoned(std::function<R()> body, std::function<Directory(String )> createDirectory, std::function<File(String )> createFile, std::function<Link(String )> createLink, std::function<Stream<FileSystemEvent>(String , int , bool )> fsWatch, std::function<bool()> fsWatchIsSupported, std::function<Future<FileSystemEntityType>(String , bool )> fseGetType, std::function<FileSystemEntityType(String , bool )> fseGetTypeSync, std::function<Future<bool>(String , String )> fseIdentical, std::function<bool(String , String )> fseIdenticalSync, std::function<Directory()> getCurrentDirectory, std::function<Directory()> getSystemTempDirectory, std::function<Future<ServerSocket>(dynamic , int , int backlog, bool shared, bool v6Only)> serverSocketBind, std::function<void(String )> setCurrentDirectory, std::function<Future<Socket>(dynamic , int , dynamic sourceAddress, int sourcePort, Duration timeout)> socketConnect, std::function<Future<ConnectionTask<Socket>>(dynamic , int , dynamic sourceAddress, int sourcePort)> socketStartConnect, std::function<Future<FileStat>(String )> stat, std::function<FileStat(String )> statSync, std::function<Stdout()> stderr, std::function<Stdin()> stdin, std::function<Stdout()> stdout);

    template<typename R>
 static R runWithIOOverrides(std::function<R()> body, IOOverrides overrides);

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

    std::function<Directory(String )> _createDirectory;

    std::function<Directory()> _getCurrentDirectory;

    std::function<void(String )> _setCurrentDirectory;

    std::function<Directory()> _getSystemTempDirectory;

    std::function<File(String )> _createFile;

    std::function<Future<FileStat>(String )> _stat;

    std::function<FileStat(String )> _statSync;

    std::function<Future<bool>(String , String )> _fseIdentical;

    std::function<bool(String , String )> _fseIdenticalSync;

    std::function<Future<FileSystemEntityType>(String , bool )> _fseGetType;

    std::function<FileSystemEntityType(String , bool )> _fseGetTypeSync;

    std::function<Stream<FileSystemEvent>(String , int , bool )> _fsWatch;

    std::function<bool()> _fsWatchIsSupported;

    std::function<Link(String )> _createLink;

    std::function<Future<Socket>(dynamic , int , dynamic sourceAddress, int sourcePort, Duration timeout)> _socketConnect;

    std::function<Future<ConnectionTask<Socket>>(dynamic , int , dynamic sourceAddress, int sourcePort)> _socketStartConnect;

    std::function<Future<ServerSocket>(dynamic , int , int backlog, bool shared, bool v6Only)> _serverSocketBind;

    std::function<Stdin()> _stdin;

    std::function<Stdout()> _stdout;

    std::function<Stdout()> _stderr;


     _IOOverridesScopeCls(std::function<Directory(String )> _createDirectory, std::function<File(String )> _createFile, std::function<Link(String )> _createLink, std::function<Stream<FileSystemEvent>(String , int , bool )> _fsWatch, std::function<bool()> _fsWatchIsSupported, std::function<Future<FileSystemEntityType>(String , bool )> _fseGetType, std::function<FileSystemEntityType(String , bool )> _fseGetTypeSync, std::function<Future<bool>(String , String )> _fseIdentical, std::function<bool(String , String )> _fseIdenticalSync, std::function<Directory()> _getCurrentDirectory, std::function<Directory()> _getSystemTempDirectory, std::function<Future<ServerSocket>(dynamic , int , int backlog, bool shared, bool v6Only)> _serverSocketBind, std::function<void(String )> _setCurrentDirectory, std::function<Future<Socket>(dynamic , int , dynamic sourceAddress, int sourcePort, Duration timeout)> _socketConnect, std::function<Future<ConnectionTask<Socket>>(dynamic , int , dynamic sourceAddress, int sourcePort)> _socketStartConnect, std::function<Future<FileStat>(String )> _stat, std::function<FileStat(String )> _statSync, std::function<Stdout()> _stderr, std::function<Stdin()> _stdin, std::function<Stdout()> _stdout);
};
using _IOOverridesScope = std::shared_ptr<_IOOverridesScopeCls>;


#endif