#ifndef IO_SERVICE_H
#define IO_SERVICE_H
#include <memory>




class _IOService {
public:
    static const int fileExists;

    static const int fileCreate;

    static const int fileDelete;

    static const int fileRename;

    static const int fileCopy;

    static const int fileOpen;

    static const int fileResolveSymbolicLinks;

    static const int fileClose;

    static const int filePosition;

    static const int fileSetPosition;

    static const int fileTruncate;

    static const int fileLength;

    static const int fileLengthFromPath;

    static const int fileLastAccessed;

    static const int fileSetLastAccessed;

    static const int fileLastModified;

    static const int fileSetLastModified;

    static const int fileFlush;

    static const int fileReadByte;

    static const int fileWriteByte;

    static const int fileRead;

    static const int fileReadInto;

    static const int fileWriteFrom;

    static const int fileCreateLink;

    static const int fileDeleteLink;

    static const int fileRenameLink;

    static const int fileLinkTarget;

    static const int fileType;

    static const int fileIdentical;

    static const int fileStat;

    static const int fileLock;

    static const int socketLookup;

    static const int socketListInterfaces;

    static const int socketReverseLookup;

    static const int directoryCreate;

    static const int directoryDelete;

    static const int directoryExists;

    static const int directoryCreateTemp;

    static const int directoryListStart;

    static const int directoryListNext;

    static const int directoryListStop;

    static const int directoryRename;

    static const int sslProcessFilter;


private:

    external static Future _dispatch(List data, int request);

};

#endif