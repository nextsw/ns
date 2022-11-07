#include "restoration.hpp"
RestorationManager::RestorationManager() {
    {
        initChannels();
    }
}

void RestorationManager::initChannels() {
    SystemChannels.restoration.setMethodCallHandler(_methodHandler);
}

Future<RestorationBucket> RestorationManager::rootBucket() {
    if (_rootBucketIsValid) {
        return <RestorationBucket>SynchronousFuture(_rootBucket);
    }
    if (_pendingRootBucket == nullptr) {
        _pendingRootBucket = <RestorationBucket>Completer();
        _getRootBucketFromEngine();
    }
    return _pendingRootBucket!.future;
}

bool RestorationManager::isReplacing() {
    return _isReplacing;
}

void RestorationManager::handleRestorationUpdateFromEngine(Uint8List data, bool enabled) {
    assert(enabled != nullptr);
    assert(enabled || data == nullptr);
    _isReplacing = _rootBucketIsValid && enabled;
    if (_isReplacing) {
        SchedulerBinding.instance.addPostFrameCallback();
    }
    RestorationBucket oldRoot = _rootBucket;
    _rootBucket = enabled? RestorationBucket.root(this, _decodeRestorationData(data)) : nullptr;
    _rootBucketIsValid = true;
    assert(_pendingRootBucket == nullptr || !_pendingRootBucket!.isCompleted);
    _pendingRootBucket?.complete(_rootBucket);
    _pendingRootBucket = nullptr;
    if (_rootBucket != oldRoot) {
        notifyListeners();
        oldRoot?.dispose();
    }
}

Future<void> RestorationManager::sendToEngine(Uint8List encodedData) {
    assert(encodedData != nullptr);
    return SystemChannels.restoration.<void>invokeMethod("put", encodedData);
}

void RestorationManager::scheduleSerializationFor(RestorationBucket bucket) {
    assert(bucket != nullptr);
    assert(bucket._manager == this);
    assert(!_debugDoingUpdate);
    _bucketsNeedingSerialization.add(bucket);
    if (!_serializationScheduled) {
        _serializationScheduled = true;
        SchedulerBinding.instance.addPostFrameCallback();
    }
}

void RestorationManager::unscheduleSerializationFor(RestorationBucket bucket) {
    assert(bucket != nullptr);
    assert(bucket._manager == this);
    assert(!_debugDoingUpdate);
    _bucketsNeedingSerialization.remove(bucket);
}

void RestorationManager::flushData() {
    assert(!_debugDoingUpdate);
    if (SchedulerBinding.instance.hasScheduledFrame) {
        return;
    }
    _doSerialization();
    assert(!_serializationScheduled);
}

Future<void> RestorationManager::_getRootBucketFromEngine() {
    Map<Object, Object> config = await SystemChannels.restoration.<Map<Object, Object>>invokeMethod("get");
    if (_pendingRootBucket == nullptr) {
        return;
    }
    assert(_rootBucket == nullptr);
    _parseAndHandleRestorationUpdateFromEngine(config);
}

void RestorationManager::_parseAndHandleRestorationUpdateFromEngine(Map<Object, Object> update) {
    handleRestorationUpdateFromEngine(update != nullptr && (, update == nullptr? nullptr : ();
}

Future<void> RestorationManager::_methodHandler(MethodCall call) {
    ;
}

Map<Object, Object> RestorationManager::_decodeRestorationData(Uint8List data) {
    if (data == nullptr) {
        return nullptr;
    }
    ByteData encoded = data.buffer.asByteData(data.offsetInBytes, data.lengthInBytes);
    return const (;
}

Uint8List RestorationManager::_encodeRestorationData(Map<Object, Object> data) {
    ByteData encoded = const StandardMessageCodec().encodeMessage(data)!;
    return encoded.buffer.asUint8List(encoded.offsetInBytes, encoded.lengthInBytes);
}

void RestorationManager::_doSerialization() {
    if (!_serializationScheduled) {
        return;
    }
    assert(());
    _serializationScheduled = false;
    for (RestorationBucket bucket : _bucketsNeedingSerialization) {
        bucket.finalize();
    }
    _bucketsNeedingSerialization.clear();
    sendToEngine(_encodeRestorationData(_rootBucket!._rawData));
    assert(());
}

void RestorationBucket::empty(Object debugOwner, String restorationId) {
    assert(());
}

void RestorationBucket::root(RestorationManager manager, Map<Object, Object> rawData) {
    assert(());
}

void RestorationBucket::child(Object debugOwner, RestorationBucket parent, String restorationId) {
    assert(());
}

Object RestorationBucket::debugOwner() {
    assert(_debugAssertNotDisposed());
    return _debugOwner;
}

bool RestorationBucket::isReplacing() {
    return _manager?.isReplacing ?? false;
}

String RestorationBucket::restorationId() {
    assert(_debugAssertNotDisposed());
    return _restorationId;
}

P RestorationBucket::read<P>(String restorationId) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    return (;
}

void RestorationBucket::write<P>(String restorationId, P value) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    assert(debugIsSerializableForRestoration(value));
    if (_rawValues[restorationId] != value || !_rawValues.containsKey(restorationId)) {
        _rawValues[restorationId] = value;
        _markNeedsSerialization();
    }
}

P RestorationBucket::remove<P>(String restorationId) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    bool needsUpdate = _rawValues.containsKey(restorationId);
    P result = (;
    if (_rawValues.isEmpty) {
        _rawData.remove(_valuesMapKey);
    }
    if (needsUpdate) {
        _markNeedsSerialization();
    }
    return result;
}

bool RestorationBucket::contains(String restorationId) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    return _rawValues.containsKey(restorationId);
}

RestorationBucket RestorationBucket::claimChild(Object debugOwner, String restorationId) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    if (_claimedChildren.containsKey(restorationId) || !_rawChildren.containsKey(restorationId)) {
        RestorationBucket child = RestorationBucket.empty(debugOwner, restorationId);
        adoptChild(child);
        return child;
    }
    assert(_rawChildren[restorationId] != nullptr);
    RestorationBucket child = RestorationBucket.child(restorationId, this, debugOwner);
    _claimedChildren[restorationId] = child;
    return child;
}

void RestorationBucket::adoptChild(RestorationBucket child) {
    assert(_debugAssertNotDisposed());
    assert(child != nullptr);
    if (child._parent != this) {
        child._parent?._removeChildData(child);
        child._parent = this;
        _addChildData(child);
        if (child._manager != _manager) {
            _recursivelyUpdateManager(child);
        }
    }
    assert(child._parent == this);
    assert(child._manager == _manager);
}

void RestorationBucket::finalize() {
    assert(_debugAssertNotDisposed());
    assert(_needsSerialization);
    _needsSerialization = false;
    assert(_debugAssertIntegrity());
}

void RestorationBucket::rename(String newRestorationId) {
    assert(_debugAssertNotDisposed());
    assert(newRestorationId != nullptr);
    if (newRestorationId == restorationId) {
        return;
    }
    _parent?._removeChildData(this);
    _restorationId = newRestorationId;
    _parent?._addChildData(this);
}

void RestorationBucket::dispose() {
    assert(_debugAssertNotDisposed());
    _visitChildren(_dropChildtrue);
    _claimedChildren.clear();
    _childrenToAdd.clear();
    _parent?._removeChildData(this);
    _parent = nullptr;
    _updateManager(nullptr);
    _debugDisposed = true;
}

String RestorationBucket::toString() {
    return "${objectRuntimeType(this, 'RestorationBucket')}(restorationId: $restorationId, owner: $debugOwner)";
}

Map<Object, Object> RestorationBucket::_rawChildren() {
    return (;
}

Map<Object, Object> RestorationBucket::_rawValues() {
    return (;
}

void RestorationBucket::_dropChild(RestorationBucket child) {
    assert(child != nullptr);
    assert(child._parent == this);
    _removeChildData(child);
    child._parent = nullptr;
    if (child._manager != nullptr) {
        child._updateManager(nullptr);
        child._visitChildren(_recursivelyUpdateManager);
    }
}

void RestorationBucket::_markNeedsSerialization() {
    if (!_needsSerialization) {
        _needsSerialization = true;
        _manager?.scheduleSerializationFor(this);
    }
}

void RestorationBucket::_recursivelyUpdateManager(RestorationBucket bucket) {
    bucket._updateManager(_manager);
    bucket._visitChildren(_recursivelyUpdateManager);
}

void RestorationBucket::_updateManager(RestorationManager newManager) {
    if (_manager == newManager) {
        return;
    }
    if (_needsSerialization) {
        _manager?.unscheduleSerializationFor(this);
    }
    _manager = newManager;
    if (_needsSerialization && _manager != nullptr) {
        _needsSerialization = false;
        _markNeedsSerialization();
    }
}

bool RestorationBucket::_debugAssertIntegrity() {
    assert(());
    return true;
}

void RestorationBucket::_removeChildData(RestorationBucket child) {
    assert(child != nullptr);
    assert(child._parent == this);
    if (_claimedChildren.remove(child.restorationId) == child) {
        _rawChildren.remove(child.restorationId);
        List<RestorationBucket> pendingChildren = _childrenToAdd[child.restorationId];
        if (pendingChildren != nullptr) {
            RestorationBucket toAdd = pendingChildren.removeLast();
            _finalizeAddChildData(toAdd);
            if (pendingChildren.isEmpty) {
                _childrenToAdd.remove(child.restorationId);
            }
        }
        if (_rawChildren.isEmpty) {
            _rawData.remove(_childrenMapKey);
        }
        _markNeedsSerialization();
        return;
    }
    _childrenToAdd[child.restorationId]?.remove(child);
    if (_childrenToAdd[child.restorationId]?.isEmpty ?? false) {
        _childrenToAdd.remove(child.restorationId);
    }
}

void RestorationBucket::_addChildData(RestorationBucket child) {
    assert(child != nullptr);
    assert(child._parent == this);
    if (_claimedChildren.containsKey(child.restorationId)) {
        _childrenToAdd.putIfAbsent(child.restorationId, ).add(child);
        _markNeedsSerialization();
        return;
    }
    _finalizeAddChildData(child);
    _markNeedsSerialization();
}

void RestorationBucket::_finalizeAddChildData(RestorationBucket child) {
    assert(_claimedChildren[child.restorationId] == nullptr);
    assert(_rawChildren[child.restorationId] == nullptr);
    _claimedChildren[child.restorationId] = child;
    _rawChildren[child.restorationId] = child._rawData;
}

void RestorationBucket::_visitChildren(bool concurrentModification, _BucketVisitor visitor) {
    Iterable<RestorationBucket> children = _claimedChildren.values.followedBy(_childrenToAdd.values.expand());
    if (concurrentModification) {
        children = children.toList(false);
    }
    children.forEach(visitor);
}

bool RestorationBucket::_debugAssertNotDisposed() {
    assert(());
    return true;
}

bool debugIsSerializableForRestoration(Object object) {
    bool result = false;
    assert(());
    return result;
}
