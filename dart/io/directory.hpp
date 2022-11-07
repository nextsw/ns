#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <memory>




class Directory {
public:

    String path();

     Directory(String path);

    void  fromRawPath(Uint8List path);

    void  fromUri(Uri uri);

    static Directory current();

    Uri uri();

    static void current(path );

    Future<Directory> create(bool recursive);

    void createSync(bool recursive);

    static Directory systemTemp();

    Future<Directory> createTemp(String prefix);

    Directory createTempSync(String prefix);

    Future<String> resolveSymbolicLinks();

    String resolveSymbolicLinksSync();

    Future<Directory> rename(String newPath);

    Directory renameSync(String newPath);

    Directory absolute();

    Stream<FileSystemEntity> list(bool followLinks, bool recursive);

    List<FileSystemEntity> listSync(bool followLinks, bool recursive);

    String toString();

private:

};

#endif