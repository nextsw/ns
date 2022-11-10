#ifndef DART_IO_FILE_IMPL
#define DART_IO_FILE_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>

int _blockSize;


class _FileStreamCls : public StreamCls<List<int>> {
public:

    virtual void  forStdin();

    virtual StreamSubscription<Uint8List> listen(bool cancelOnError, void onData(Uint8List event) , void onDone() , void  onError() );

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


     _FileStreamCls(int _end, String _path, int position);

    virtual Future _closeFile();

    virtual void _readBlock();

    virtual void _start();

};
using _FileStream = std::shared_ptr<_FileStreamCls>;

class _FileStreamConsumerCls : public StreamConsumerCls<List<int>> {
public:

    virtual void  fromStdio(int fd);

    virtual Future<File> addStream(Stream<List<int>> stream);

    virtual Future<File> close();

private:
    File _file;

    Future<RandomAccessFile> _openFuture;


     _FileStreamConsumerCls(File file, FileMode mode);

};
using _FileStreamConsumer = std::shared_ptr<_FileStreamConsumerCls>;

class _FileCls : public FileSystemEntityCls {
public:

    virtual void  fromRawPath(Uint8List rawPath);

    virtual String path();

    virtual Future<bool> exists();

    virtual bool existsSync();

    virtual File absolute();

    virtual Future<File> create(bool recursive);

    virtual void createSync(bool recursive);

    virtual Future<File> rename(String newPath);

    virtual File renameSync(String newPath);

    virtual Future<File> copy(String newPath);

    virtual File copySync(String newPath);

    virtual Future<RandomAccessFile> open(FileMode mode);

    virtual Future<int> length();

    virtual int lengthSync();

    virtual Future<DateTime> lastAccessed();

    virtual DateTime lastAccessedSync();

    virtual Future setLastAccessed(DateTime time);

    virtual void setLastAccessedSync(DateTime time);

    virtual Future<DateTime> lastModified();

    virtual DateTime lastModifiedSync();

    virtual Future setLastModified(DateTime time);

    virtual void setLastModifiedSync(DateTime time);

    virtual RandomAccessFile openSync(FileMode mode);

    virtual Stream<List<int>> openRead(int end, int start);

    virtual IOSink openWrite(Encoding encoding, FileMode mode);

    virtual Future<Uint8List> readAsBytes();

    virtual Uint8List readAsBytesSync();

    virtual Future<String> readAsString(Encoding encoding);

    virtual String readAsStringSync(Encoding encoding);

    virtual Future<List<String>> readAsLines(Encoding encoding);

    virtual List<String> readAsLinesSync(Encoding encoding);

    virtual Future<File> writeAsBytes(List<int> bytes, bool flush, FileMode mode);

    virtual void writeAsBytesSync(List<int> bytes, bool flush, FileMode mode);

    virtual Future<File> writeAsString(String contents, Encoding encoding, bool flush, FileMode mode);

    virtual void writeAsStringSync(String contents, Encoding encoding, bool flush, FileMode mode);

    virtual String toString();

    static void  throwIfError(String msg, String path, Object result);

private:
    String _path;

    Uint8List _rawPath;


     _FileCls(String path);

    static int _namespacePointer();

    static Future _dispatchWithNamespace(List data, int request);

    static void  _exists(_Namespace namespace, Uint8List rawPath);
    static void  _create(_Namespace namespace, Uint8List rawPath);
    static void  _createLink(_Namespace namespace, Uint8List rawPath, String target);
    static void  _linkTarget(_Namespace namespace, Uint8List rawPath);
    virtual Future<File> _delete(bool recursive);

    static void  _deleteNative(_Namespace namespace, Uint8List rawPath);
    static void  _deleteLinkNative(_Namespace namespace, Uint8List rawPath);
    virtual void _deleteSync(bool recursive);

    static void  _rename(_Namespace namespace, String newPath, Uint8List oldPath);
    static void  _renameLink(_Namespace namespace, String newPath, Uint8List oldPath);
    static void  _copy(_Namespace namespace, String newPath, Uint8List oldPath);
    static void  _lengthFromPath(_Namespace namespace, Uint8List rawPath);
    static void  _lastAccessed(_Namespace namespace, Uint8List rawPath);
    static void  _setLastAccessed(int millis, _Namespace namespace, Uint8List rawPath);
    static void  _lastModified(_Namespace namespace, Uint8List rawPath);
    static void  _setLastModified(int millis, _Namespace namespace, Uint8List rawPath);
    static void  _open(int mode, _Namespace namespace, Uint8List rawPath);
    static int _openStdio(int fd);
    static RandomAccessFile _openStdioSync(int fd);

    virtual String _tryDecode(List<int> bytes, Encoding encoding);

    template<typename T>  static T _checkNotNull(String name, T t);

};
using _File = std::shared_ptr<_FileCls>;

class _RandomAccessFileOpsCls : public ObjectCls {
public:

    virtual int getPointer();
    virtual int fd();
    virtual int close();
    virtual void  readByte();
    virtual void  read(int bytes);
    virtual void  readInto(List<int> buffer, int end, int start);
    virtual void  writeByte(int value);
    virtual void  writeFrom(List<int> buffer, int end, int start);
    virtual void  position();
    virtual void  setPosition(int position);
    virtual void  truncate(int length);
    virtual void  length();
    virtual void  flush();
    virtual void  lock(int end, int lock, int start);
private:

     _RandomAccessFileOpsCls(int pointer);
};
using _RandomAccessFileOps = std::shared_ptr<_RandomAccessFileOpsCls>;

class _RandomAccessFileCls : public ObjectCls {
public:
    String path;

    static int lockUnlock;

    bool closed;


    virtual Future<void> close();

    virtual void closeSync();

    virtual Future<int> readByte();

    virtual int readByteSync();

    virtual Future<Uint8List> read(int bytes);

    virtual Uint8List readSync(int bytes);

    virtual Future<int> readInto(List<int> buffer, int end, int start);

    virtual int readIntoSync(List<int> buffer, int end, int start);

    virtual Future<RandomAccessFile> writeByte(int value);

    virtual int writeByteSync(int value);

    virtual Future<RandomAccessFile> writeFrom(List<int> buffer, int end, int start);

    virtual void writeFromSync(List<int> buffer, int end, int start);

    virtual Future<RandomAccessFile> writeString(Encoding encoding, String stringValue);

    virtual void writeStringSync(Encoding encoding, String stringValue);

    virtual Future<int> position();

    virtual int positionSync();

    virtual Future<RandomAccessFile> setPosition(int position);

    virtual void setPositionSync(int position);

    virtual Future<RandomAccessFile> truncate(int length);

    virtual void truncateSync(int length);

    virtual Future<int> length();

    virtual int lengthSync();

    virtual Future<RandomAccessFile> flush();

    virtual void flushSync();

    virtual Future<RandomAccessFile> lock(int end, FileLock mode, int start);

    virtual Future<RandomAccessFile> unlock(int end, int start);

    virtual void lockSync(int end, FileLock mode, int start);

    virtual void unlockSync(int end, int start);

    virtual int fd();

private:
    static bool _connectedResourceHandler;

    bool _asyncDispatched;

    _FileResourceInfo _resourceInfo;

    _RandomAccessFileOps _ops;


     _RandomAccessFileCls(String path, int pointer);

    virtual void _maybePerformCleanup();

    virtual void  _maybeConnectHandler();

    virtual int _fileLockValue(FileLock fl);

    virtual int _pointer();

    virtual Future _dispatch(List data, bool markClosed, int request);

    virtual void _checkAvailable();

};
using _RandomAccessFile = std::shared_ptr<_RandomAccessFileCls>;


#endif