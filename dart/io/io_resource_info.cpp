#include "io_resource_info.hpp"
int _IOResourceInfoCls::timestamp() {
    return _startTime + _sw->elapsedMicroseconds ~/ 1000;
}

Map<String, dynamic> _IOResourceInfoCls::referenceValueMap() {
    return list1;
}

int _IOResourceInfoCls::getNextID() {
    return _count++;
}

_IOResourceInfoCls::_IOResourceInfoCls(String type) {
    {
            map1.set("type", "@$type");    map1.set("id", id);    map1.set("name", name);id = _IOResourceInfoCls->getNextID();
    }
}

void _ReadWriteResourceInfoCls::addRead(int bytes) {
    readBytes = bytes;
    readCount++;
    lastReadTime = _IOResourceInfoCls::timestamp;
}

void _ReadWriteResourceInfoCls::didRead() {
    addRead(0);
}

void _ReadWriteResourceInfoCls::addWrite(int bytes) {
    writeBytes = bytes;
    writeCount++;
    lastWriteTime = _IOResourceInfoCls::timestamp;
}

Map<String, dynamic> _ReadWriteResourceInfoCls::fullValueMap() {
    return list1;
}

_ReadWriteResourceInfoCls::_ReadWriteResourceInfoCls(String type) {
    {
            map1.set("type", type);    map1.set("id", id);    map1.set("name", name);    map1.set("readBytes", readBytes);    map1.set("writeBytes", writeBytes);    map1.set("readCount", readCount);    map1.set("writeCount", writeCount);    map1.set("lastReadTime", lastReadTime);    map1.set("lastWriteTime", lastWriteTime);readBytes = 0;
        writeBytes = 0;
        readCount = 0;
        writeCount = 0;
        lastReadTime = 0;
        lastWriteTime = 0;
    }
}

void _FileResourceInfoCls::fileOpened(_FileResourceInfo info) {
    assert(!openFiles->containsKey(info->id));
    openFiles[info->id] = info;
}

void _FileResourceInfoCls::fileClosed(_FileResourceInfo info) {
    assert(openFiles->containsKey(info->id));
    openFiles->remove(info->id);
}

Iterable<Map<String, dynamic>> _FileResourceInfoCls::getOpenFilesList() {
    return ListCls->from(openFiles->values->map([=] (Unknown  e)     {
        e->referenceValueMap;
    }));
}

Future<ServiceExtensionResponse> _FileResourceInfoCls::getOpenFiles(function , params ) {
    assert(function == "ext.dart.io.getOpenFiles");
    map1.set("type", "OpenFileList");map1.set("files", getOpenFilesList());Unknown data = list1;
    Unknown jsonValue = json->encode(data);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

Map<String, dynamic> _FileResourceInfoCls::fileInfoMap() {
    return fullValueMap;
}

Future<ServiceExtensionResponse> _FileResourceInfoCls::getOpenFileInfoMapByID(function , params ) {
    Unknown id = intValue->parse(params["id"]!);
    Unknown result = openFiles->containsKey(id)? openFiles[id]!->fileInfoMap : makeMap(makeList(), makeList();
    Unknown jsonValue = json->encode(result);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

String _FileResourceInfoCls::name() {
    return file->path;
}

_FileResourceInfoCls::_FileResourceInfoCls(Unknown file) {
    {
        fileOpened(this);
    }
}

String _SpawnedProcessResourceInfoCls::name() {
    return process->_path;
}

void _SpawnedProcessResourceInfoCls::stopped() {
    return processStopped(this);
}

Map<String, dynamic> _SpawnedProcessResourceInfoCls::fullValueMap() {
    return list1;
}

void _SpawnedProcessResourceInfoCls::processStarted(_SpawnedProcessResourceInfo info) {
    map1.set("type", type);map1.set("id", id);map1.set("name", name);map1.set("pid", process->pid);map1.set("startedAt", startedAt);map1.set("arguments", process->_arguments);map1.set("workingDirectory", process->_workingDirectory == nullptr? "." : process->_workingDirectory);assert(!startedProcesses->containsKey(info->id));
    startedProcesses[info->id] = info;
}

void _SpawnedProcessResourceInfoCls::processStopped(_SpawnedProcessResourceInfo info) {
    assert(startedProcesses->containsKey(info->id));
    startedProcesses->remove(info->id);
}

Iterable<Map<String, dynamic>> _SpawnedProcessResourceInfoCls::getStartedProcessesList() {
    return ListCls->from(startedProcesses->values->map([=] (Unknown  e)     {
        e->referenceValueMap;
    }));
}

Future<ServiceExtensionResponse> _SpawnedProcessResourceInfoCls::getStartedProcesses(String function, Map<String, String> params) {
    assert(function == "ext.dart.io.getSpawnedProcesses");
    map1.set("type", "SpawnedProcessList");map1.set("processes", getStartedProcessesList());Unknown data = list1;
    Unknown jsonValue = json->encode(data);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

Future<ServiceExtensionResponse> _SpawnedProcessResourceInfoCls::getProcessInfoMapById(String function, Map<String, String> params) {
    Unknown id = intValue->parse(params["id"]!);
    Unknown result = startedProcesses->containsKey(id)? startedProcesses[id]!->fullValueMap : makeMap(makeList(), makeList();
    Unknown jsonValue = json->encode(result);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

_SpawnedProcessResourceInfoCls::_SpawnedProcessResourceInfoCls(Unknown process) {
    {
        startedAt = _IOResourceInfoCls::timestamp;
    }
    {
        processStarted(this);
    }
}
