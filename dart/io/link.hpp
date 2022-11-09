#ifndef DART_IO_LINK
#define DART_IO_LINK
#include <base.hpp>

#include <dart/core/core.hpp>


class LinkCls : public ObjectCls {
public:

     LinkCls(String path);

    virtual void  fromRawPath(Uint8List rawPath);

    virtual void  fromUri(Uri uri);

    virtual Future<Link> create(bool recursive, String target);
    virtual void createSync(bool recursive, String target);
    virtual void updateSync(String target);
    virtual Future<Link> update(String target);
    virtual Future<String> resolveSymbolicLinks();
    virtual String resolveSymbolicLinksSync();
    virtual Future<Link> rename(String newPath);
    virtual Link renameSync(String newPath);
    virtual Link absolute();
    virtual Future<String> target();
    virtual String targetSync();
private:

};
using Link = std::shared_ptr<LinkCls>;

class _LinkCls : public FileSystemEntityCls {
public:

    virtual void  fromRawPath(Uint8List rawPath);

    virtual String path();

    virtual String toString();

    virtual Future<bool> exists();

    virtual bool existsSync();

    virtual Link absolute();

    virtual Future<Link> create(bool recursive, String target);

    virtual void createSync(bool recursive, String target);

    virtual void updateSync(String target);

    virtual Future<Link> update(String target);

    virtual Future<Link> rename(String newPath);

    virtual Link renameSync(String newPath);

    virtual Future<String> target();

    virtual String targetSync();

    static void  throwIfError(String msg, String path, Object result);

private:
    String _path;

    Uint8List _rawPath;


     _LinkCls(String path);

    virtual Future<Link> _delete(bool recursive);

    virtual void _deleteSync(bool recursive);

    virtual bool _isErrorResponse(response );

    virtual void  _exceptionFromResponse(response , String message, String path);

};
using _Link = std::shared_ptr<_LinkCls>;


#endif