#ifndef FILE_SYSTEM_ENTITY_H
#define FILE_SYSTEM_ENTITY_H
#include <memory>




class FileSystemEntityType {
public:
    static const auto  file;

    static const auto  directory;

    static const auto  link;

    static const auto  unixDomainSock;

    static const auto  pipe;

    static const auto  notFound;

    static const auto  NOT_FOUND;


    String toString();

private:
    static const auto  _typeList;

    int _type;


    void  _internal(int _type);

    static FileSystemEntityType _lookup(int type);

};

class FileStat {
public:
    DateTime changed;

    DateTime modified;

    DateTime accessed;

    FileSystemEntityType type;

    int mode;

    int size;


    static FileStat statSync(String path);

    static Future<FileStat> stat(String path);

    String toString();

    String modeString();

private:
    static const auto  _type;

    static const auto  _changedTime;

    static const auto  _modifiedTime;

    static const auto  _accessedTime;

    static const auto  _mode;

    static const auto  _size;

    static auto  _epoch;

    static auto  _notFound;


    void  _internal(DateTime accessed, DateTime changed, int mode, DateTime modified, int size, FileSystemEntityType type);

    external static void  _statSync(_Namespace namespace, String path);

    static FileStat _statSyncInternal(String path);

    static Future<FileStat> _stat(String path);

};

class FileSystemEntity {
public:

    String path();

    Uri uri();

    Future<bool> exists();

    bool existsSync();

    Future<FileSystemEntity> rename(String newPath);

    FileSystemEntity renameSync(String newPath);

    Future<String> resolveSymbolicLinks();

    String resolveSymbolicLinksSync();

    Future<FileStat> stat();

    FileStat statSync();

    Future<FileSystemEntity> delete(bool recursive);

    void deleteSync(bool recursive);

    Stream<FileSystemEvent> watch(int events, bool recursive);

    static Future<bool> identical(String path1, String path2);

    bool isAbsolute();

    FileSystemEntity absolute();

    static bool identicalSync(String path1, String path2);

    static bool isWatchSupported();

    static Future<FileSystemEntityType> type(bool followLinks, String path);

    static FileSystemEntityType typeSync(bool followLinks, String path);

    static Future<bool> isLink(String path);

    static Future<bool> isFile(String path);

    static Future<bool> isDirectory(String path);

    static bool isLinkSync(String path);

    static bool isFileSync(String path);

    static bool isDirectorySync(String path);

    static String parentOf(String path);

    Directory parent();

private:
    static const auto  _backslashChar;

    static const auto  _slashChar;

    static const auto  _colonChar;

    static RegExp _absoluteWindowsPathPattern;

    static RegExp _parentRegExp;


    String _path();

    Uint8List _rawPath();

    Future<FileSystemEntity> _delete(bool recursive);

    void _deleteSync(bool recursive);

    static Future<bool> _identical(String path1, String path2);

    static bool _isAbsolute(String path);

    String _absolutePath();

    static int _windowsDriveLetter(String path);

    static String _absoluteWindowsPath(String path);

    static bool _identicalSync(String path1, String path2);

    static Uint8List _toUtf8Array(String s);

    static Uint8List _toNullTerminatedUtf8Array(Uint8List l);

    static String _toStringFromUtf8Array(Uint8List l);

    static Future<bool> _isLinkRaw(Uint8List rawPath);

    static bool _isLinkRawSync(rawPath );

    external static void  _getTypeNative(bool followLinks, _Namespace namespace, Uint8List rawPath);

    external static void  _identicalNative(_Namespace namespace, String path1, String path2);

    external static void  _resolveSymbolicLinks(_Namespace namespace, Uint8List path);

    static FileSystemEntityType _getTypeSyncHelper(bool followLinks, Uint8List rawPath);

    static FileSystemEntityType _getTypeSync(bool followLinks, Uint8List rawPath);

    static Future<FileSystemEntityType> _getTypeRequest(bool followLinks, Uint8List rawPath);

    static Future<FileSystemEntityType> _getType(bool followLinks, Uint8List rawPath);

    static void  _throwIfError(String msg, String path, Object result);

    static String _trimTrailingPathSeparators(String path);

    static String _ensureTrailingPathSeparators(String path);

};

class FileSystemEvent {
public:
    static const int create;

    static const int modify;

    static const int delete;

    static const int move;

    static const int all;

    int type;

    String path;

    bool isDirectory;


private:
    static const int _modifyAttributes;

    static const int _deleteSelf;

    static const int _isDir;


    void  _(bool isDirectory, String path, int type);

};

class FileSystemCreateEvent : FileSystemEvent {
public:

    String toString();

private:

    void  _(path , isDirectory );

};

class FileSystemModifyEvent : FileSystemEvent {
public:
    bool contentChanged;


    String toString();

private:

    void  _(path , isDirectory , bool contentChanged);

};

class FileSystemDeleteEvent : FileSystemEvent {
public:

    String toString();

private:

    void  _(path , isDirectory );

};

class FileSystemMoveEvent : FileSystemEvent {
public:
    String destination;


    String toString();

private:

    void  _(path , isDirectory , String destination);

};

class _FileSystemWatcher {
public:

    external static bool isSupported();

private:

    external static Stream<FileSystemEvent> _watch(int events, String path, bool recursive);

};

#endif