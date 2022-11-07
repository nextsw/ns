#ifndef FILE_IMPL_H
#define FILE_IMPL_H
#include <memory>



const int _blockSize;


class _FileStream : Stream<List<int>> {
public:

    void  forStdin();

    StreamSubscription<Uint8List> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:
    StreamController<Uint8List> _controller;

    String _path;

    RandomAccessFile _openedFile;

    int _position;

    int _end;

    Completer _closeCompleter;

    bool _unsubscribed;

    bool _readInProgress;

    bool _closed;

    bool _atEnd;


     _FileStream(int _end, String _path, int position);

    Future _closeFile();

    void _readBlock();

    void _start();

};

class _FileStreamConsumer : StreamConsumer<List<int>> {
public:

    void  fromStdio(int fd);

    Future<File> addStream(Stream<List<int>> stream);

    Future<File> close();

private:
    File _file;

    Future<RandomAccessFile> _openFuture;


     _FileStreamConsumer(File file, FileMode mode);

};

class _File : FileSystemEntity {
public:

    void  fromRawPath(Uint8List rawPath);

    String path();

    Future<bool> exists();

    bool existsSync();

    File absolute();

    Future<File> create(bool recursive);

    void createSync(bool recursive);

    Future<File> rename(String newPath);

    File renameSync(String newPath);

    Future<File> copy(String newPath);

    File copySync(String newPath);

    Future<RandomAccessFile> open(FileMode mode);

    Future<int> length();

    int lengthSync();

    Future<DateTime> lastAccessed();

    DateTime lastAccessedSync();

    Future setLastAccessed(DateTime time);

    void setLastAccessedSync(DateTime time);

    Future<DateTime> lastModified();

    DateTime lastModifiedSync();

    Future setLastModified(DateTime time);

    void setLastModifiedSync(DateTime time);

    RandomAccessFile openSync(FileMode mode);

    Stream<List<int>> openRead(int end, int start);

    IOSink openWrite(Encoding encoding, FileMode mode);

    Future<Uint8List> readAsBytes();

    Uint8List readAsBytesSync();

    Future<String> readAsString(Encoding encoding);

    String readAsStringSync(Encoding encoding);

    Future<List<String>> readAsLines(Encoding encoding);

    List<String> readAsLinesSync(Encoding encoding);

    Future<File> writeAsBytes(List<int> bytes, bool flush, FileMode mode);

    void writeAsBytesSync(List<int> bytes, bool flush, FileMode mode);

    Future<File> writeAsString(String contents, Encoding encoding, bool flush, FileMode mode);

    void writeAsStringSync(String contents, Encoding encoding, bool flush, FileMode mode);

    String toString();

    static void  throwIfError(String msg, String path, Object result);

private:
    String _path;

    Uint8List _rawPath;


     _File(String path);

    static int _namespacePointer();

    static Future _dispatchWithNamespace(List data, int request);

    external static void  _exists(_Namespace namespace, Uint8List rawPath);

    external static void  _create(_Namespace namespace, Uint8List rawPath);

    external static void  _createLink(_Namespace namespace, Uint8List rawPath, String target);

    external static void  _linkTarget(_Namespace namespace, Uint8List rawPath);

    Future<File> _delete(bool recursive);

    external static void  _deleteNative(_Namespace namespace, Uint8List rawPath);

    external static void  _deleteLinkNative(_Namespace namespace, Uint8List rawPath);

    void _deleteSync(bool recursive);

    external static void  _rename(_Namespace namespace, String newPath, Uint8List oldPath);

    external static void  _renameLink(_Namespace namespace, String newPath, Uint8List oldPath);

    external static void  _copy(_Namespace namespace, String newPath, Uint8List oldPath);

    external static void  _lengthFromPath(_Namespace namespace, Uint8List rawPath);

    external static void  _lastAccessed(_Namespace namespace, Uint8List rawPath);

    external static void  _setLastAccessed(int millis, _Namespace namespace, Uint8List rawPath);

    external static void  _lastModified(_Namespace namespace, Uint8List rawPath);

    external static void  _setLastModified(int millis, _Namespace namespace, Uint8List rawPath);

    external static void  _open(int mode, _Namespace namespace, Uint8List rawPath);

    external static int _openStdio(int fd);

    static RandomAccessFile _openStdioSync(int fd);

    String _tryDecode(List<int> bytes, Encoding encoding);

    static T _checkNotNull<T>(String name, T t);

};

class _RandomAccessFileOps {
public:

    int getPointer();

    int fd();

    int close();

    void  readByte();

    void  read(int bytes);

    void  readInto(List<int> buffer, int end, int start);

    void  writeByte(int value);

    void  writeFrom(List<int> buffer, int end, int start);

    void  position();

    void  setPosition(int position);

    void  truncate(int length);

    void  length();

    void  flush();

    void  lock(int end, int lock, int start);

private:

    external  _RandomAccessFileOps(int pointer);

};

class _RandomAccessFile {
public:
    String path;

    static const int lockUnlock;

    bool closed;


    Future<void> close();

    void closeSync();

    Future<int> readByte();

    int readByteSync();

    Future<Uint8List> read(int bytes);

    Uint8List readSync(int bytes);

    Future<int> readInto(List<int> buffer, int end, int start);

    int readIntoSync(List<int> buffer, int end, int start);

    Future<RandomAccessFile> writeByte(int value);

    int writeByteSync(int value);

    Future<RandomAccessFile> writeFrom(List<int> buffer, int end, int start);

    void writeFromSync(List<int> buffer, int end, int start);

    Future<RandomAccessFile> writeString(Encoding encoding, String string);

    void writeStringSync(Encoding encoding, String string);

    Future<int> position();

    int positionSync();

    Future<RandomAccessFile> setPosition(int position);

    void setPositionSync(int position);

    Future<RandomAccessFile> truncate(int length);

    void truncateSync(int length);

    Future<int> length();

    int lengthSync();

    Future<RandomAccessFile> flush();

    void flushSync();

    Future<RandomAccessFile> lock(int end, FileLock mode, int start);

    Future<RandomAccessFile> unlock(int end, int start);

    void lockSync(int end, FileLock mode, int start);

    void unlockSync(int end, int start);

    int fd();

private:
    static bool _connectedResourceHandler;

    bool _asyncDispatched;

    _FileResourceInfo _resourceInfo;

    _RandomAccessFileOps _ops;


     _RandomAccessFile(String path, int pointer);

    void _maybePerformCleanup();

    void  _maybeConnectHandler();

    int _fileLockValue(FileLock fl);

    int _pointer();

    Future _dispatch(List data, bool markClosed, int request);

    void _checkAvailable();

};

#endif