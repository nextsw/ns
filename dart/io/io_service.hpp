#ifndef DART_IO_IO_SERVICE
#define DART_IO_IO_SERVICE
#include <base.hpp>

#include <dart/core/core.hpp>


class _IOServiceCls : public ObjectCls {
public:
    static int fileExists;

    static int fileCreate;

    static int fileDelete;

    static int fileRename;

    static int fileCopy;

    static int fileOpen;

    static int fileResolveSymbolicLinks;

    static int fileClose;

    static int filePosition;

    static int fileSetPosition;

    static int fileTruncate;

    static int fileLength;

    static int fileLengthFromPath;

    static int fileLastAccessed;

    static int fileSetLastAccessed;

    static int fileLastModified;

    static int fileSetLastModified;

    static int fileFlush;

    static int fileReadByte;

    static int fileWriteByte;

    static int fileRead;

    static int fileReadInto;

    static int fileWriteFrom;

    static int fileCreateLink;

    static int fileDeleteLink;

    static int fileRenameLink;

    static int fileLinkTarget;

    static int fileType;

    static int fileIdentical;

    static int fileStat;

    static int fileLock;

    static int socketLookup;

    static int socketListInterfaces;

    static int socketReverseLookup;

    static int directoryCreate;

    static int directoryDelete;

    static int directoryExists;

    static int directoryCreateTemp;

    static int directoryListStart;

    static int directoryListNext;

    static int directoryListStop;

    static int directoryRename;

    static int sslProcessFilter;


private:

    extern static Future _dispatch(List data, int request);
};
using _IOService = std::shared_ptr<_IOServiceCls>;


#endif