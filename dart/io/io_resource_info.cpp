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
            map1.set(__s("type"), __s("@$type"));    map1.set(__s("id"), id);    map1.set(__s("name"), name());id = _IOResourceInfoCls->getNextID();
    }
}

void _ReadWriteResourceInfoCls::addRead(int bytes) {
    readBytes += bytes;
    readCount++;
    lastReadTime = _IOResourceInfoCls::timestamp;
}

void _ReadWriteResourceInfoCls::didRead() {
    addRead(0);
}

void _ReadWriteResourceInfoCls::addWrite(int bytes) {
    writeBytes += bytes;
    writeCount++;
    lastWriteTime = _IOResourceInfoCls::timestamp;
}

Map<String, dynamic> _ReadWriteResourceInfoCls::fullValueMap() {
    return list1;
}

_ReadWriteResourceInfoCls::_ReadWriteResourceInfoCls(String type) : _IOResourceInfo(type) {
    {
            map1.set(__s("type"), type);    map1.set(__s("id"), id);    map1.set(__s("name"), name);    map1.set(__s("readBytes"), readBytes);    map1.set(__s("writeBytes"), writeBytes);    map1.set(__s("readCount"), readCount);    map1.set(__s("writeCount"), writeCount);    map1.set(__s("lastReadTime"), lastReadTime);    map1.set(__s("lastWriteTime"), lastWriteTime);readBytes = 0;
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
    assert(function == __s("ext.dart.io.getOpenFiles"));
    map1.set(__s("type"), __s("OpenFileList"));map1.set(__s("files"), getOpenFilesList());Unknown data = list1;
    Unknown jsonValue = json->encode(data);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

Map<String, dynamic> _FileResourceInfoCls::fileInfoMap() {
    return fullValueMap;
}

Future<ServiceExtensionResponse> _FileResourceInfoCls::getOpenFileInfoMapByID(function , params ) {
    Unknown id = intValue->parse(params[__s("id")]!);
    Unknown result = openFiles->containsKey(id)? openFiles[id]!->fileInfoMap : makeMap(makeList(), makeList();
    Unknown jsonValue = json->encode(result);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

String _FileResourceInfoCls::name() {
    return file->path;
}

_FileResourceInfoCls::_FileResourceInfoCls(Unknown file) : _ReadWriteResourceInfo(_type) {
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
    map1.set(__s("type"), type);map1.set(__s("id"), id);map1.set(__s("name"), name());map1.set(__s("pid"), process->pid);map1.set(__s("startedAt"), startedAt);map1.set(__s("arguments"), process->_arguments);map1.set(__s("workingDirectory"), process->_workingDirectory == nullptr? __s(".") : process->_workingDirectory);assert(!startedProcesses->containsKey(info->id));
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
    assert(function == __s("ext.dart.io.getSpawnedProcesses"));
    map1.set(__s("type"), __s("SpawnedProcessList"));map1.set(__s("processes"), getStartedProcessesList());Unknown data = list1;
    Unknown jsonValue = json->encode(data);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

Future<ServiceExtensionResponse> _SpawnedProcessResourceInfoCls::getProcessInfoMapById(String function, Map<String, String> params) {
    Unknown id = intValue->parse(params[__s("id")]!);
    Unknown result = startedProcesses->containsKey(id)? startedProcesses[id]!->fullValueMap : makeMap(makeList(), makeList();
    Unknown jsonValue = json->encode(result);
    return FutureCls->value(ServiceExtensionResponseCls->result(jsonValue));
}

_SpawnedProcessResourceInfoCls::_SpawnedProcessResourceInfoCls(Unknown process) : _IOResourceInfo(_type) {
    {
        startedAt = _IOResourceInfoCls::timestamp;
    }
    {
        processStarted(this);
    }
}
