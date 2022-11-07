#ifndef FILE_H
#define FILE_H
#include <memory>




class FileMode {
public:
    static const auto  read;

    static const auto  write;

    static const auto  append;

    static const auto  writeOnly;

    static const auto  writeOnlyAppend;


private:
    int _mode;


    void  _internal(int _mode);

};

class FileLock {
public:
    static const auto  shared;

    static const auto  exclusive;

    static const auto  blockingShared;

    static const auto  blockingExclusive;


private:
    int _type;


    void  _internal(int _type);

};

class File {
public:

     File(String path);

    void  fromUri(Uri uri);

    void  fromRawPath(Uint8List rawPath);

    Future<File> create(bool recursive);

    void createSync(bool recursive);

    Future<File> rename(String newPath);

    File renameSync(String newPath);

    Future<File> copy(String newPath);

    File copySync(String newPath);

    Future<int> length();

    int lengthSync();

    File absolute();

    Future<DateTime> lastAccessed();

    DateTime lastAccessedSync();

    Future setLastAccessed(DateTime time);

    void setLastAccessedSync(DateTime time);

    Future<DateTime> lastModified();

    DateTime lastModifiedSync();

    Future setLastModified(DateTime time);

    void setLastModifiedSync(DateTime time);

    Future<RandomAccessFile> open(FileMode mode);

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

    String path();

private:

};

class RandomAccessFile {
public:

    Future<void> close();

    void closeSync();

    Future<int> readByte();

    int readByteSync();

    Future<Uint8List> read(int count);

    Uint8List readSync(int count);

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

    void lockSync(int end, FileLock mode, int start);

    Future<RandomAccessFile> unlock(int end, int start);

    void unlockSync(int end, int start);

    String toString();

    String path();

private:

};

class FileSystemException {
public:
    String message;

    String path;

    OSError osError;


     FileSystemException(String message, OSError osError, String path);

    String toString();

private:

};

#endif