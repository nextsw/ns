#ifndef DART_IO_IO_RESOURCE_INFO
#define DART_IO_IO_RESOURCE_INFO
#include <base.hpp>

#include <dart/core/core.hpp>


class _IOResourceInfoCls : public ObjectCls {
public:
    String type;

    int id;


    virtual String name();
    static int timestamp();

    virtual Map<String, Object> fullValueMap();
    virtual Map<String, Object> referenceValueMap();

    static int getNextID();

private:
    static int _count;

    static Stopwatch _sw;

    static auto  _startTime;


     _IOResourceInfoCls(String type);

};
using _IOResourceInfo = std::shared_ptr<_IOResourceInfoCls>;

class _ReadWriteResourceInfoCls : public _IOResourceInfoCls {
public:
    int readBytes;

    int writeBytes;

    int readCount;

    int writeCount;

    int lastReadTime;

    int lastWriteTime;


    virtual void addRead(int bytes);

    virtual void didRead();

    virtual void addWrite(int bytes);

    virtual Map<String, Object> fullValueMap();

private:

     _ReadWriteResourceInfoCls(String type);

};
using _ReadWriteResourceInfo = std::shared_ptr<_ReadWriteResourceInfoCls>;

class _FileResourceInfoCls : public _ReadWriteResourceInfoCls {
public:
    auto  file;

    static Map<int, _FileResourceInfo> openFiles;


    static void  fileOpened(_FileResourceInfo info);

    static void  fileClosed(_FileResourceInfo info);

    static Iterable<Map<String, Object>> getOpenFilesList();

    static Future<ServiceExtensionResponse> getOpenFiles(function , params );

    virtual Map<String, Object> fileInfoMap();

    static Future<ServiceExtensionResponse> getOpenFileInfoMapByID(function , params );

    virtual String name();

private:
    static String _type;


     _FileResourceInfoCls(Unknown file);

};
using _FileResourceInfo = std::shared_ptr<_FileResourceInfoCls>;

class _SpawnedProcessResourceInfoCls : public _IOResourceInfoCls {
public:
    auto  process;

    int startedAt;

    static Map<int, _SpawnedProcessResourceInfo> startedProcesses;


    virtual String name();

    virtual void stopped();

    virtual Map<String, Object> fullValueMap();

    static void  processStarted(_SpawnedProcessResourceInfo info);

    static void  processStopped(_SpawnedProcessResourceInfo info);

    static Iterable<Map<String, Object>> getStartedProcessesList();

    static Future<ServiceExtensionResponse> getStartedProcesses(String function, Map<String, String> params);

    static Future<ServiceExtensionResponse> getProcessInfoMapById(String function, Map<String, String> params);

private:
    static String _type;


     _SpawnedProcessResourceInfoCls(Unknown process);

};
using _SpawnedProcessResourceInfo = std::shared_ptr<_SpawnedProcessResourceInfoCls>;


#endif