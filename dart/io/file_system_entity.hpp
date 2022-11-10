#ifndef DART_IO_FILE_SYSTEM_ENTITY
#define DART_IO_FILE_SYSTEM_ENTITY
#include <base.hpp>

#include <dart/core/core.hpp>


class FileSystemEntityTypeCls : public ObjectCls {
public:
    static auto  file;

    static auto  directory;

    static auto  link;

    static auto  unixDomainSock;

    static auto  pipe;

    static auto  notFound;

    static auto  NOT_FOUND;


    virtual String toString();

private:
    static auto  _typeList;

    int _type;


    virtual void  _internal(int _type);
    static FileSystemEntityType _lookup(int type);

};
using FileSystemEntityType = std::shared_ptr<FileSystemEntityTypeCls>;

class FileStatCls : public ObjectCls {
public:
    DateTime changed;

    DateTime modified;

    DateTime accessed;

    FileSystemEntityType type;

    int mode;

    int size;


    static FileStat statSync(String path);

    static Future<FileStat> stat(String path);

    virtual String toString();

    virtual String modeString();

private:
    static auto  _type;

    static auto  _changedTime;

    static auto  _modifiedTime;

    static auto  _accessedTime;

    static auto  _mode;

    static auto  _size;

    static auto  _epoch;

    static auto  _notFound;


    virtual void  _internal(DateTime accessed, DateTime changed, int mode, DateTime modified, int size, FileSystemEntityType type);
    static void  _statSync(_Namespace namespace, String path);
    static FileStat _statSyncInternal(String path);

    static Future<FileStat> _stat(String path);

};
using FileStat = std::shared_ptr<FileStatCls>;

class FileSystemEntityCls : public ObjectCls {
public:

    virtual String path();
    virtual Uri uri();

    virtual Future<bool> exists();
    virtual bool existsSync();
    virtual Future<FileSystemEntity> rename(String newPath);
    virtual FileSystemEntity renameSync(String newPath);
    virtual Future<String> resolveSymbolicLinks();

    virtual String resolveSymbolicLinksSync();

    virtual Future<FileStat> stat();

    virtual FileStat statSync();

    virtual Future<FileSystemEntity> delete(bool recursive);

    virtual void deleteSync(bool recursive);

    virtual Stream<FileSystemEvent> watch(int events, bool recursive);

    static Future<bool> identical(String path1, String path2);

    virtual bool isAbsolute();

    virtual FileSystemEntity absolute();
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

    virtual Directory parent();

private:
    static auto  _backslashChar;

    static auto  _slashChar;

    static auto  _colonChar;

    static RegExp _absoluteWindowsPathPattern;

    static RegExp _parentRegExp;


    virtual String _path();
    virtual Uint8List _rawPath();
    virtual Future<FileSystemEntity> _delete(bool recursive);
    virtual void _deleteSync(bool recursive);
    static Future<bool> _identical(String path1, String path2);

    static bool _isAbsolute(String path);

    virtual String _absolutePath();

    static int _windowsDriveLetter(String path);

    static String _absoluteWindowsPath(String path);

    static bool _identicalSync(String path1, String path2);

    static Uint8List _toUtf8Array(String s);

    static Uint8List _toNullTerminatedUtf8Array(Uint8List l);

    static String _toStringFromUtf8Array(Uint8List l);

    static Future<bool> _isLinkRaw(Uint8List rawPath);

    static bool _isLinkRawSync(rawPath );

    static void  _getTypeNative(bool followLinks, _Namespace namespace, Uint8List rawPath);
    static void  _identicalNative(_Namespace namespace, String path1, String path2);
    static void  _resolveSymbolicLinks(_Namespace namespace, Uint8List path);
    static FileSystemEntityType _getTypeSyncHelper(bool followLinks, Uint8List rawPath);

    static FileSystemEntityType _getTypeSync(bool followLinks, Uint8List rawPath);

    static Future<FileSystemEntityType> _getTypeRequest(bool followLinks, Uint8List rawPath);

    static Future<FileSystemEntityType> _getType(bool followLinks, Uint8List rawPath);

    static void  _throwIfError(String msg, String path, Object result);

    static String _trimTrailingPathSeparators(String path);

    static String _ensureTrailingPathSeparators(String path);

};
using FileSystemEntity = std::shared_ptr<FileSystemEntityCls>;

class FileSystemEventCls : public ObjectCls {
public:
    static int create;

    static int modify;

    static int delete;

    static int move;

    static int all;

    int type;

    String path;

    bool isDirectory;


private:
    static int _modifyAttributes;

    static int _deleteSelf;

    static int _isDir;


    virtual void  _(bool isDirectory, String path, int type);
};
using FileSystemEvent = std::shared_ptr<FileSystemEventCls>;

class FileSystemCreateEventCls : public FileSystemEventCls {
public:

    virtual String toString();

private:

    virtual void  _(path , isDirectory );

};
using FileSystemCreateEvent = std::shared_ptr<FileSystemCreateEventCls>;

class FileSystemModifyEventCls : public FileSystemEventCls {
public:
    bool contentChanged;


    virtual String toString();

private:

    virtual void  _(path , isDirectory , bool contentChanged);

};
using FileSystemModifyEvent = std::shared_ptr<FileSystemModifyEventCls>;

class FileSystemDeleteEventCls : public FileSystemEventCls {
public:

    virtual String toString();

private:

    virtual void  _(path , isDirectory );

};
using FileSystemDeleteEvent = std::shared_ptr<FileSystemDeleteEventCls>;

class FileSystemMoveEventCls : public FileSystemEventCls {
public:
    String destination;


    virtual String toString();

private:

    virtual void  _(path , isDirectory , String destination);

};
using FileSystemMoveEvent = std::shared_ptr<FileSystemMoveEventCls>;

class _FileSystemWatcherCls : public ObjectCls {
public:

    static bool isSupported();
private:

    static Stream<FileSystemEvent> _watch(int events, String path, bool recursive);
};
using _FileSystemWatcher = std::shared_ptr<_FileSystemWatcherCls>;


#endif