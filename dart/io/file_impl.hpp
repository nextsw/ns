#ifndef DART_IO_FILE_IMPL
#define DART_IO_FILE_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>

int _blockSize;


class _FileStreamCls : public StreamCls<List<int>> {
public:

    virtual void  forStdin();

    virtual StreamSubscription<Uint8List> listen(std::function<void(Uint8List event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

private:
    StreamController<Uint8List> _controller;

    String _path;

    RandomAccessFile _openedFile;

    int _position;

    int _end;

    Completer<any> _closeCompleter;

    bool _unsubscribed;

    bool _readInProgress;

    bool _closed;

    bool _atEnd;


     _FileStreamCls(String _path, int position, int _end);

    virtual Future<any> _closeFile();

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

    virtual Future<any> setLastAccessed(DateTime time);

    virtual void setLastAccessedSync(DateTime time);

    virtual Future<DateTime> lastModified();

    virtual DateTime lastModifiedSync();

    virtual Future<any> setLastModified(DateTime time);

    virtual void setLastModifiedSync(DateTime time);

    virtual RandomAccessFile openSync(FileMode mode);

    virtual Stream<List<int>> openRead(int start, int end);

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

    static void  throwIfError(Object result, String msg, String path);

private:
    String _path;

    Uint8List _rawPath;


     _FileCls(String path);

    static int _namespacePointer();

    static Future<any> _dispatchWithNamespace(int request, List<any> data);

    static void  _exists(_Namespace namespace, Uint8List rawPath);
    static void  _create(_Namespace namespace, Uint8List rawPath);
    static void  _createLink(_Namespace namespace, Uint8List rawPath, String target);
    static void  _linkTarget(_Namespace namespace, Uint8List rawPath);
    virtual Future<File> _delete(bool recursive);

    static void  _deleteNative(_Namespace namespace, Uint8List rawPath);
    static void  _deleteLinkNative(_Namespace namespace, Uint8List rawPath);
    virtual void _deleteSync(bool recursive);

    static void  _rename(_Namespace namespace, Uint8List oldPath, String newPath);
    static void  _renameLink(_Namespace namespace, Uint8List oldPath, String newPath);
    static void  _copy(_Namespace namespace, Uint8List oldPath, String newPath);
    static void  _lengthFromPath(_Namespace namespace, Uint8List rawPath);
    static void  _lastAccessed(_Namespace namespace, Uint8List rawPath);
    static void  _setLastAccessed(_Namespace namespace, Uint8List rawPath, int millis);
    static void  _lastModified(_Namespace namespace, Uint8List rawPath);
    static void  _setLastModified(_Namespace namespace, Uint8List rawPath, int millis);
    static void  _open(_Namespace namespace, Uint8List rawPath, int mode);
    static int _openStdio(int fd);
    static RandomAccessFile _openStdioSync(int fd);

    virtual String _tryDecode(List<int> bytes, Encoding encoding);

    template<typename T>
 static T _checkNotNull(T t, String name);

};
using _File = std::shared_ptr<_FileCls>;

class _RandomAccessFileOpsCls : public ObjectCls {
public:

    virtual int getPointer();
    virtual int fd();
    virtual int close();
    virtual void  readByte();
    virtual void  read(int bytes);
    virtual void  readInto(List<int> buffer, int start, int end);
    virtual void  writeByte(int value);
    virtual void  writeFrom(List<int> buffer, int start, int end);
    virtual void  position();
    virtual void  setPosition(int position);
    virtual void  truncate(int length);
    virtual void  length();
    virtual void  flush();
    virtual void  lock(int lock, int start, int end);
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

    virtual Future<int> readInto(List<int> buffer, int start, int end);

    virtual int readIntoSync(List<int> buffer, int start, int end);

    virtual Future<RandomAccessFile> writeByte(int value);

    virtual int writeByteSync(int value);

    virtual Future<RandomAccessFile> writeFrom(List<int> buffer, int start, int end);

    virtual void writeFromSync(List<int> buffer, int start, int end);

    virtual Future<RandomAccessFile> writeString(String stringValue, Encoding encoding);

    virtual void writeStringSync(String stringValue, Encoding encoding);

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

    virtual Future<RandomAccessFile> lock(FileLock mode, int start, int end);

    virtual Future<RandomAccessFile> unlock(int start, int end);

    virtual void lockSync(FileLock mode, int start, int end);

    virtual void unlockSync(int start, int end);

    virtual int fd();

private:
    static bool _connectedResourceHandler;

    bool _asyncDispatched;

    _FileResourceInfo _resourceInfo;

    _RandomAccessFileOps _ops;


     _RandomAccessFileCls(int pointer, String path);

    virtual void _maybePerformCleanup();

    virtual void  _maybeConnectHandler();

    virtual int _fileLockValue(FileLock fl);

    virtual int _pointer();

    virtual Future<any> _dispatch(int request, List<any> data, bool markClosed);

    virtual void _checkAvailable();

};
using _RandomAccessFile = std::shared_ptr<_RandomAccessFileCls>;


#endif