#ifndef IO_RESOURCE_INFO_H
#define IO_RESOURCE_INFO_H
#include <memory>




class _IOResourceInfo {
public:
    String type;

    int id;


    String name();

    static int timestamp();

    Map<String, dynamic> fullValueMap();

    Map<String, dynamic> referenceValueMap();

    static int getNextID();

private:
    static int _count;

    static Stopwatch _sw;

    static auto  _startTime;


     _IOResourceInfo(String type);

};

class _ReadWriteResourceInfo : _IOResourceInfo {
public:
    int readBytes;

    int writeBytes;

    int readCount;

    int writeCount;

    int lastReadTime;

    int lastWriteTime;


    void addRead(int bytes);

    void didRead();

    void addWrite(int bytes);

    Map<String, dynamic> fullValueMap();

private:

     _ReadWriteResourceInfo(String type);

};

class _FileResourceInfo : _ReadWriteResourceInfo {
public:
    auto  file;

    static Map<int, _FileResourceInfo> openFiles;


    static void  fileOpened(_FileResourceInfo info);

    static void  fileClosed(_FileResourceInfo info);

    static Iterable<Map<String, dynamic>> getOpenFilesList();

    static Future<ServiceExtensionResponse> getOpenFiles(function , params );

    Map<String, dynamic> fileInfoMap();

    static Future<ServiceExtensionResponse> getOpenFileInfoMapByID(function , params );

    String name();

private:
    static const String _type;


     _FileResourceInfo(Unknown file);

};

class _SpawnedProcessResourceInfo : _IOResourceInfo {
public:
    auto  process;

    int startedAt;

    static Map<int, _SpawnedProcessResourceInfo> startedProcesses;


    String name();

    void stopped();

    Map<String, dynamic> fullValueMap();

    static void  processStarted(_SpawnedProcessResourceInfo info);

    static void  processStopped(_SpawnedProcessResourceInfo info);

    static Iterable<Map<String, dynamic>> getStartedProcessesList();

    static Future<ServiceExtensionResponse> getStartedProcesses(String function, Map<String, String> params);

    static Future<ServiceExtensionResponse> getProcessInfoMapById(String function, Map<String, String> params);

private:
    static const String _type;


     _SpawnedProcessResourceInfo(Unknown process);

};

#endif