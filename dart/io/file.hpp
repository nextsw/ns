#ifndef DART_IO_FILE
#define DART_IO_FILE
#include <base.hpp>

#include <dart/core/core.hpp>


class FileModeCls : public ObjectCls {
public:
    static auto  read;

    static auto  write;

    static auto  append;

    static auto  writeOnly;

    static auto  writeOnlyAppend;


private:
    int _mode;


    virtual void  _internal(int _mode);
};
using FileMode = std::shared_ptr<FileModeCls>;

class FileLockCls : public ObjectCls {
public:
    static auto  shared;

    static auto  exclusive;

    static auto  blockingShared;

    static auto  blockingExclusive;


private:
    int _type;


    virtual void  _internal(int _type);
};
using FileLock = std::shared_ptr<FileLockCls>;

class FileCls : public ObjectCls {
public:

     FileCls(String path);

    virtual void  fromUri(Uri uri);

    virtual void  fromRawPath(Uint8List rawPath);

    virtual Future<File> create(bool recursive);
    virtual void createSync(bool recursive);
    virtual Future<File> rename(String newPath);
    virtual File renameSync(String newPath);
    virtual Future<File> copy(String newPath);
    virtual File copySync(String newPath);
    virtual Future<int> length();
    virtual int lengthSync();
    virtual File absolute();
    virtual Future<DateTime> lastAccessed();
    virtual DateTime lastAccessedSync();
    virtual Future<any> setLastAccessed(DateTime time);
    virtual void setLastAccessedSync(DateTime time);
    virtual Future<DateTime> lastModified();
    virtual DateTime lastModifiedSync();
    virtual Future<any> setLastModified(DateTime time);
    virtual void setLastModifiedSync(DateTime time);
    virtual Future<RandomAccessFile> open(FileMode mode);
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
    virtual String path();
private:

};
using File = std::shared_ptr<FileCls>;

class RandomAccessFileCls : public ObjectCls {
public:

    virtual Future<void> close();
    virtual void closeSync();
    virtual Future<int> readByte();
    virtual int readByteSync();
    virtual Future<Uint8List> read(int count);
    virtual Uint8List readSync(int count);
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
    virtual void lockSync(FileLock mode, int start, int end);
    virtual Future<RandomAccessFile> unlock(int start, int end);
    virtual void unlockSync(int start, int end);
    virtual String toString();
    virtual String path();
private:

};
using RandomAccessFile = std::shared_ptr<RandomAccessFileCls>;

class FileSystemExceptionCls : public ObjectCls {
public:
    String message;

    String path;

    OSError osError;


     FileSystemExceptionCls(String message, String path, OSError osError);
    virtual String toString();

private:

};
using FileSystemException = std::shared_ptr<FileSystemExceptionCls>;


#endif