#ifndef DART_IO_DIRECTORY_IMPL
#define DART_IO_DIRECTORY_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>


class _DirectoryCls : public FileSystemEntityCls {
public:

    virtual void  fromRawPath(Uint8List rawPath);

    virtual String path();

    static Directory current();

    static void current(path );

    virtual Uri uri();

    virtual Future<bool> exists();

    virtual bool existsSync();

    virtual Directory absolute();

    virtual Future<Directory> create(bool recursive);

    virtual void createSync(bool recursive);

    static Directory systemTemp();

    virtual Future<Directory> createTemp(String prefix);

    virtual Directory createTempSync(String prefix);

    virtual Future<Directory> rename(String newPath);

    virtual Directory renameSync(String newPath);

    virtual Stream<FileSystemEntity> list(bool followLinks, bool recursive);

    virtual List<FileSystemEntity> listSync(bool followLinks, bool recursive);

    virtual String toString();

private:
    String _path;

    Uint8List _rawPath;


     _DirectoryCls(String path);

    static void  _current(_Namespace namespace);
    static void  _setCurrent(_Namespace namespace, Uint8List rawPath);
    static void  _createTemp(_Namespace namespace, Uint8List rawPath);
    static String _systemTemp(_Namespace namespace);
    static void  _exists(_Namespace namespace, Uint8List rawPath);
    static void  _create(_Namespace namespace, Uint8List rawPath);
    static void  _deleteNative(_Namespace namespace, Uint8List rawPath, bool recursive);
    static void  _rename(_Namespace namespace, Uint8List rawPath, String newPath);
    static void _fillWithDirectoryListing(_Namespace namespace, List<FileSystemEntity> list, Uint8List rawPath, bool recursive, bool followLinks);
    virtual Future<Directory> _delete(bool recursive);

    virtual void _deleteSync(bool recursive);

    virtual bool _isErrorResponse(response );

    virtual void  _exceptionOrErrorFromResponse(response , String message);

    template<typename T>
 static T _checkNotNull(T t, String name);

};
using _Directory = std::shared_ptr<_DirectoryCls>;

class _AsyncDirectoryListerOpsCls : public ObjectCls {
public:

    virtual int getPointer();
private:

     _AsyncDirectoryListerOpsCls(int pointer);
};
using _AsyncDirectoryListerOps = std::shared_ptr<_AsyncDirectoryListerOpsCls>;

class _AsyncDirectoryListerCls : public ObjectCls {
public:
    static int listFile;

    static int listDirectory;

    static int listLink;

    static int listError;

    static int listDone;

    static int responseType;

    static int responsePath;

    static int responseComplete;

    static int responseError;

    Uint8List rawPath;

    bool recursive;

    bool followLinks;

    auto  controller;

    bool canceled;

    bool nextRunning;

    bool closed;

    Completer closeCompleter;


    virtual Stream<FileSystemEntity> stream();

    virtual void onListen();

    virtual void onResume();

    virtual Future onCancel();

    virtual void next();

    virtual void close();

    virtual void error(message );

private:
    _AsyncDirectoryListerOps _ops;


     _AsyncDirectoryListerCls(Uint8List rawPath, bool recursive, bool followLinks);

    virtual int _pointer();

    virtual void _cleanup();

};
using _AsyncDirectoryLister = std::shared_ptr<_AsyncDirectoryListerCls>;


#endif