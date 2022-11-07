#ifndef DIRECTORY_IMPL_H
#define DIRECTORY_IMPL_H
#include <memory>




class _Directory : FileSystemEntity {
public:

    void  fromRawPath(Uint8List rawPath);

    String path();

    static Directory current();

    static void current(path );

    Uri uri();

    Future<bool> exists();

    bool existsSync();

    Directory absolute();

    Future<Directory> create(bool recursive);

    void createSync(bool recursive);

    static Directory systemTemp();

    Future<Directory> createTemp(String prefix);

    Directory createTempSync(String prefix);

    Future<Directory> rename(String newPath);

    Directory renameSync(String newPath);

    Stream<FileSystemEntity> list(bool followLinks, bool recursive);

    List<FileSystemEntity> listSync(bool followLinks, bool recursive);

    String toString();

private:
    String _path;

    Uint8List _rawPath;


     _Directory(String path);

    external static void  _current(_Namespace namespace);

    external static void  _setCurrent(_Namespace namespace, Uint8List rawPath);

    external static void  _createTemp(_Namespace namespace, Uint8List rawPath);

    external static String _systemTemp(_Namespace namespace);

    external static void  _exists(_Namespace namespace, Uint8List rawPath);

    external static void  _create(_Namespace namespace, Uint8List rawPath);

    external static void  _deleteNative(_Namespace namespace, Uint8List rawPath, bool recursive);

    external static void  _rename(_Namespace namespace, String newPath, Uint8List rawPath);

    external static void _fillWithDirectoryListing(bool followLinks, List<FileSystemEntity> list, _Namespace namespace, Uint8List rawPath, bool recursive);

    Future<Directory> _delete(bool recursive);

    void _deleteSync(bool recursive);

    bool _isErrorResponse(response );

    void  _exceptionOrErrorFromResponse(response , String message);

    static T _checkNotNull<T>(String name, T t);

};

class _AsyncDirectoryListerOps {
public:

    int getPointer();

private:

    external  _AsyncDirectoryListerOps(int pointer);

};

class _AsyncDirectoryLister {
public:
    static const int listFile;

    static const int listDirectory;

    static const int listLink;

    static const int listError;

    static const int listDone;

    static const int responseType;

    static const int responsePath;

    static const int responseComplete;

    static const int responseError;

    Uint8List rawPath;

    bool recursive;

    bool followLinks;

    auto  controller;

    bool canceled;

    bool nextRunning;

    bool closed;

    Completer closeCompleter;


    Stream<FileSystemEntity> stream();

    void onListen();

    void onResume();

    Future onCancel();

    void next();

    void close();

    void error(message );

private:
    _AsyncDirectoryListerOps _ops;


     _AsyncDirectoryLister(bool followLinks, Uint8List rawPath, bool recursive);

    int _pointer();

    void _cleanup();

};

#endif