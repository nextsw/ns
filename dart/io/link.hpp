#ifndef LINK_H
#define LINK_H
#include <memory>




class Link {
public:

     Link(String path);

    void  fromRawPath(Uint8List rawPath);

    void  fromUri(Uri uri);

    Future<Link> create(bool recursive, String target);

    void createSync(bool recursive, String target);

    void updateSync(String target);

    Future<Link> update(String target);

    Future<String> resolveSymbolicLinks();

    String resolveSymbolicLinksSync();

    Future<Link> rename(String newPath);

    Link renameSync(String newPath);

    Link absolute();

    Future<String> target();

    String targetSync();

private:

};

class _Link : FileSystemEntity {
public:

    void  fromRawPath(Uint8List rawPath);

    String path();

    String toString();

    Future<bool> exists();

    bool existsSync();

    Link absolute();

    Future<Link> create(bool recursive, String target);

    void createSync(bool recursive, String target);

    void updateSync(String target);

    Future<Link> update(String target);

    Future<Link> rename(String newPath);

    Link renameSync(String newPath);

    Future<String> target();

    String targetSync();

    static void  throwIfError(String msg, String path, Object result);

private:
    String _path;

    Uint8List _rawPath;


     _Link(String path);

    Future<Link> _delete(bool recursive);

    void _deleteSync(bool recursive);

    bool _isErrorResponse(response );

    void  _exceptionFromResponse(response , String message, String path);

};

#endif