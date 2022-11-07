#include "io_resource_info.hpp"
int _IOResourceInfo::timestamp() {
    return _startTime + _sw.elapsedMicroseconds ~/ 1000;
}

Map<String, dynamic> _IOResourceInfo::referenceValueMap() {
    return ;
}

int _IOResourceInfo::getNextID() {
    return _count++;
}

_IOResourceInfo::_IOResourceInfo(String type) {
    {
        id = _IOResourceInfo.getNextID();
    }
}

void _ReadWriteResourceInfo::addRead(int bytes) {
    readBytes = bytes;
    readCount++;
    lastReadTime = _IOResourceInfo.timestamp;
}

void _ReadWriteResourceInfo::didRead() {
    addRead(0);
}

void _ReadWriteResourceInfo::addWrite(int bytes) {
    writeBytes = bytes;
    writeCount++;
    lastWriteTime = _IOResourceInfo.timestamp;
}

Map<String, dynamic> _ReadWriteResourceInfo::fullValueMap() {
    return ;
}

_ReadWriteResourceInfo::_ReadWriteResourceInfo(String type) {
    {
        readBytes = 0;
        writeBytes = 0;
        readCount = 0;
        writeCount = 0;
        lastReadTime = 0;
        lastWriteTime = 0;
        super(type);
    }
}

void _FileResourceInfo::fileOpened(_FileResourceInfo info) {
    assert(!openFiles.containsKey(info.id));
    openFiles[info.id] = info;
}

void _FileResourceInfo::fileClosed(_FileResourceInfo info) {
    assert(openFiles.containsKey(info.id));
    openFiles.remove(info.id);
}

Iterable<Map<String, dynamic>> _FileResourceInfo::getOpenFilesList() {
    return List.from(openFiles.values.map());
}

Future<ServiceExtensionResponse> _FileResourceInfo::getOpenFiles(function , params ) {
    assert(function == "ext.dart.io.getOpenFiles");
    Unknown data = ;
    Unknown jsonValue = json.encode(data);
    return Future.value(ServiceExtensionResponse.result(jsonValue));
}

Map<String, dynamic> _FileResourceInfo::fileInfoMap() {
    return fullValueMap;
}

Future<ServiceExtensionResponse> _FileResourceInfo::getOpenFileInfoMapByID(function , params ) {
    Unknown id = int.parse(params["id"]!);
    Unknown result = openFiles.containsKey(id)? openFiles[id]!.fileInfoMap : ;
    Unknown jsonValue = json.encode(result);
    return Future.value(ServiceExtensionResponse.result(jsonValue));
}

String _FileResourceInfo::name() {
    return file.path;
}

_FileResourceInfo::_FileResourceInfo(Unknown file) {
    {
        super(_type);
    }
    {
        fileOpened(this);
    }
}

String _SpawnedProcessResourceInfo::name() {
    return process._path;
}

void _SpawnedProcessResourceInfo::stopped() {
    return processStopped(this);
}

Map<String, dynamic> _SpawnedProcessResourceInfo::fullValueMap() {
    return ;
}

void _SpawnedProcessResourceInfo::processStarted(_SpawnedProcessResourceInfo info) {
    assert(!startedProcesses.containsKey(info.id));
    startedProcesses[info.id] = info;
}

void _SpawnedProcessResourceInfo::processStopped(_SpawnedProcessResourceInfo info) {
    assert(startedProcesses.containsKey(info.id));
    startedProcesses.remove(info.id);
}

Iterable<Map<String, dynamic>> _SpawnedProcessResourceInfo::getStartedProcessesList() {
    return List.from(startedProcesses.values.map());
}

Future<ServiceExtensionResponse> _SpawnedProcessResourceInfo::getStartedProcesses(String function, Map<String, String> params) {
    assert(function == "ext.dart.io.getSpawnedProcesses");
    Unknown data = ;
    Unknown jsonValue = json.encode(data);
    return Future.value(ServiceExtensionResponse.result(jsonValue));
}

Future<ServiceExtensionResponse> _SpawnedProcessResourceInfo::getProcessInfoMapById(String function, Map<String, String> params) {
    Unknown id = int.parse(params["id"]!);
    Unknown result = startedProcesses.containsKey(id)? startedProcesses[id]!.fullValueMap : ;
    Unknown jsonValue = json.encode(result);
    return Future.value(ServiceExtensionResponse.result(jsonValue));
}

_SpawnedProcessResourceInfo::_SpawnedProcessResourceInfo(Unknown process) {
    {
        startedAt = _IOResourceInfo.timestamp;
        super(_type);
    }
    {
        processStarted(this);
    }
}
