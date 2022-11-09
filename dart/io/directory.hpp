#ifndef DART_IO_DIRECTORY
#define DART_IO_DIRECTORY
#include <base.hpp>

#include <dart/core/core.hpp>


class DirectoryCls : public ObjectCls {
public:

    virtual String path();
     DirectoryCls(String path);

    virtual void  fromRawPath(Uint8List path);

    virtual void  fromUri(Uri uri);

    static Directory current();

    virtual Uri uri();
    static void current(path );

    virtual Future<Directory> create(bool recursive);
    virtual void createSync(bool recursive);
    static Directory systemTemp();

    virtual Future<Directory> createTemp(String prefix);
    virtual Directory createTempSync(String prefix);
    virtual Future<String> resolveSymbolicLinks();
    virtual String resolveSymbolicLinksSync();
    virtual Future<Directory> rename(String newPath);
    virtual Directory renameSync(String newPath);
    virtual Directory absolute();
    virtual Stream<FileSystemEntity> list(bool followLinks, bool recursive);
    virtual List<FileSystemEntity> listSync(bool followLinks, bool recursive);
    virtual String toString();
private:

};
using Directory = std::shared_ptr<DirectoryCls>;


#endif