#include "restoration.hpp"
RestorationManagerCls::RestorationManagerCls() {
    {
        initChannels();
    }
}

void RestorationManagerCls::initChannels() {
    SystemChannelsCls::restoration->setMethodCallHandler(_methodHandler);
}

Future<RestorationBucket> RestorationManagerCls::rootBucket() {
    if (_rootBucketIsValid) {
        return <RestorationBucket>make<SynchronousFutureCls>(_rootBucket);
    }
    if (_pendingRootBucket == nullptr) {
        _pendingRootBucket = <RestorationBucket>make<CompleterCls>();
        _getRootBucketFromEngine();
    }
    return _pendingRootBucket!->future;
}

bool RestorationManagerCls::isReplacing() {
    return _isReplacing;
}

void RestorationManagerCls::handleRestorationUpdateFromEngine(Uint8List data, bool enabled) {
    assert(enabled != nullptr);
    assert(enabled || data == nullptr);
    _isReplacing = _rootBucketIsValid && enabled;
    if (_isReplacing) {
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration _) {
            _isReplacing = false;
        });
    }
    RestorationBucket oldRoot = _rootBucket;
    _rootBucket = enabled? RestorationBucketCls->root(this, _decodeRestorationData(data)) : nullptr;
    _rootBucketIsValid = true;
    assert(_pendingRootBucket == nullptr || !_pendingRootBucket!->isCompleted);
    _pendingRootBucket?->complete(_rootBucket);
    _pendingRootBucket = nullptr;
    if (_rootBucket != oldRoot) {
        notifyListeners();
        oldRoot?->dispose();
    }
}

Future<void> RestorationManagerCls::sendToEngine(Uint8List encodedData) {
    assert(encodedData != nullptr);
    return SystemChannelsCls::restoration-><void>invokeMethod(__s("put"), encodedData);
}

void RestorationManagerCls::scheduleSerializationFor(RestorationBucket bucket) {
    assert(bucket != nullptr);
    assert(bucket->_manager == this);
    assert(!_debugDoingUpdate);
    _bucketsNeedingSerialization->add(bucket);
    if (!_serializationScheduled) {
        _serializationScheduled = true;
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration _)         {
            _doSerialization();
        });
    }
}

void RestorationManagerCls::unscheduleSerializationFor(RestorationBucket bucket) {
    assert(bucket != nullptr);
    assert(bucket->_manager == this);
    assert(!_debugDoingUpdate);
    _bucketsNeedingSerialization->remove(bucket);
}

void RestorationManagerCls::flushData() {
    assert(!_debugDoingUpdate);
    if (SchedulerBindingCls::instance->hasScheduledFrame) {
        return;
    }
    _doSerialization();
    assert(!_serializationScheduled);
}

Future<void> RestorationManagerCls::_getRootBucketFromEngine() {
    Map<Object, Object> config = await SystemChannelsCls::restoration-><Map<Object, Object>>invokeMethod(__s("get"));
    if (_pendingRootBucket == nullptr) {
        return;
    }
    assert(_rootBucket == nullptr);
    _parseAndHandleRestorationUpdateFromEngine(config);
}

void RestorationManagerCls::_parseAndHandleRestorationUpdateFromEngine(Map<Object, Object> update) {
    handleRestorationUpdateFromEngine(update != nullptr && as<bool>(update[__s("enabled")]!), update == nullptr? nullptr : as<Uint8List>(update[__s("data")]));
}

Future<void> RestorationManagerCls::_methodHandler(MethodCall call) {
    ;
}

Map<Object, Object> RestorationManagerCls::_decodeRestorationData(Uint8List data) {
    if (data == nullptr) {
        return nullptr;
    }
    ByteData encoded = data->buffer->asByteData(data->offsetInBytes, data->lengthInBytes);
    return as<Map<Object, Object>>(make<StandardMessageCodecCls>()->decodeMessage(encoded));
}

Uint8List RestorationManagerCls::_encodeRestorationData(Map<Object, Object> data) {
    ByteData encoded = make<StandardMessageCodecCls>()->encodeMessage(data)!;
    return encoded->buffer->asUint8List(encoded->offsetInBytes, encoded->lengthInBytes);
}

void RestorationManagerCls::_doSerialization() {
    if (!_serializationScheduled) {
        return;
    }
    assert([=] () {
        _debugDoingUpdate = true;
        return true;
    }());
    _serializationScheduled = false;
    for (RestorationBucket bucket : _bucketsNeedingSerialization) {
        bucket->finalize();
    }
    _bucketsNeedingSerialization->clear();
    sendToEngine(_encodeRestorationData(_rootBucket!->_rawData));
    assert([=] () {
        _debugDoingUpdate = false;
        return true;
    }());
}

void RestorationBucketCls::empty(Object debugOwner, String restorationId) {
    assert([=] () {
        _debugOwner = debugOwner;
        return true;
    }());
}

void RestorationBucketCls::root(RestorationManager manager, Map<Object, Object> rawData) {
    assert([=] () {
        _debugOwner = manager;
        return true;
    }());
}

void RestorationBucketCls::child(Object debugOwner, RestorationBucket parent, String restorationId) {
    assert([=] () {
        _debugOwner = debugOwner;
        return true;
    }());
}

Object RestorationBucketCls::debugOwner() {
    assert(_debugAssertNotDisposed());
    return _debugOwner;
}

bool RestorationBucketCls::isReplacing() {
    return _manager?->isReplacing() | false;
}

String RestorationBucketCls::restorationId() {
    assert(_debugAssertNotDisposed());
    return _restorationId;
}

template<typename P>
P RestorationBucketCls::read(String restorationId) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    return as<P>(_rawValues()[restorationId]);
}

template<typename P>
void RestorationBucketCls::write(String restorationId, P value) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    assert(debugIsSerializableForRestoration(value));
    if (_rawValues()[restorationId] != value || !_rawValues()->containsKey(restorationId)) {
        _rawValues()[restorationId] = value;
        _markNeedsSerialization();
    }
}

template<typename P>
P RestorationBucketCls::remove(String restorationId) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    bool needsUpdate = _rawValues()->containsKey(restorationId);
    P result = as<P>(_rawValues()->remove(restorationId));
    if (_rawValues()->isEmpty()) {
        _rawData->remove(_valuesMapKey);
    }
    if (needsUpdate) {
        _markNeedsSerialization();
    }
    return result;
}

bool RestorationBucketCls::contains(String restorationId) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    return _rawValues()->containsKey(restorationId);
}

RestorationBucket RestorationBucketCls::claimChild(String restorationId, Object debugOwner) {
    assert(_debugAssertNotDisposed());
    assert(restorationId != nullptr);
    if (_claimedChildren->containsKey(restorationId) || !_rawChildren()->containsKey(restorationId)) {
        RestorationBucket child = RestorationBucketCls->empty(debugOwner, restorationId);
        adoptChild(child);
        return child;
    }
    assert(_rawChildren()[restorationId] != nullptr);
    RestorationBucket child = RestorationBucketCls->child(restorationId, this, debugOwner);
    _claimedChildren[restorationId] = child;
    return child;
}

void RestorationBucketCls::adoptChild(RestorationBucket child) {
    assert(_debugAssertNotDisposed());
    assert(child != nullptr);
    if (child->_parent != this) {
        child->_parent?->_removeChildData(child);
        child->_parent = this;
        _addChildData(child);
        if (child->_manager != _manager) {
            _recursivelyUpdateManager(child);
        }
    }
    assert(child->_parent == this);
    assert(child->_manager == _manager);
}

void RestorationBucketCls::finalize() {
    assert(_debugAssertNotDisposed());
    assert(_needsSerialization);
    _needsSerialization = false;
    assert(_debugAssertIntegrity());
}

void RestorationBucketCls::rename(String newRestorationId) {
    assert(_debugAssertNotDisposed());
    assert(newRestorationId != nullptr);
    if (newRestorationId == restorationId()) {
        return;
    }
    _parent?->_removeChildData(this);
    _restorationId = newRestorationId;
    _parent?->_addChildData(this);
}

void RestorationBucketCls::dispose() {
    assert(_debugAssertNotDisposed());
    _visitChildren(_dropChild, true);
    _claimedChildren->clear();
    _childrenToAdd->clear();
    _parent?->_removeChildData(this);
    _parent = nullptr;
    _updateManager(nullptr);
    _debugDisposed = true;
}

String RestorationBucketCls::toString() {
    return __s("${objectRuntimeType(this, 'RestorationBucket')}(restorationId: $restorationId, owner: $debugOwner)");
}

Map<Object, Object> RestorationBucketCls::_rawChildren() {
    return as<Map<Object, Object>>(_rawData->putIfAbsent(_childrenMapKey, [=] ()     {
        makeMap(makeList(), makeList();
    })!);
}

Map<Object, Object> RestorationBucketCls::_rawValues() {
    return as<Map<Object, Object>>(_rawData->putIfAbsent(_valuesMapKey, [=] ()     {
        makeMap(makeList(), makeList();
    })!);
}

void RestorationBucketCls::_dropChild(RestorationBucket child) {
    assert(child != nullptr);
    assert(child->_parent == this);
    _removeChildData(child);
    child->_parent = nullptr;
    if (child->_manager != nullptr) {
        child->_updateManager(nullptr);
        child->_visitChildren(_recursivelyUpdateManager);
    }
}

void RestorationBucketCls::_markNeedsSerialization() {
    if (!_needsSerialization) {
        _needsSerialization = true;
        _manager?->scheduleSerializationFor(this);
    }
}

void RestorationBucketCls::_recursivelyUpdateManager(RestorationBucket bucket) {
    bucket->_updateManager(_manager);
    bucket->_visitChildren(_recursivelyUpdateManager);
}

void RestorationBucketCls::_updateManager(RestorationManager newManager) {
    if (_manager == newManager) {
        return;
    }
    if (_needsSerialization) {
        _manager?->unscheduleSerializationFor(this);
    }
    _manager = newManager;
    if (_needsSerialization && _manager != nullptr) {
        _needsSerialization = false;
        _markNeedsSerialization();
    }
}

bool RestorationBucketCls::_debugAssertIntegrity() {
    assert([=] () {
        if (_childrenToAdd->isEmpty()) {
            return true;
        }
        List<DiagnosticsNode> error = makeList(ArrayItem, ArrayItem);
        for (MapEntry<String, List<RestorationBucket>> child : _childrenToAdd->entries()) {
            String id = child->key;
            List<RestorationBucket> buckets = child->value;
            assert(buckets->isNotEmpty);
            assert(_claimedChildren->containsKey(id));
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        for (auto _x1 : buckets->map([=] (RestorationBucket bucket)             {                        make<ErrorDescriptionCls>(__s("   * ${bucket.debugOwner}"));                    })) {        {            list1.add(_x1);        }list1.add(ArrayItem);error->addAll(list1);
        }
        throw FlutterErrorCls->fromParts(error);
    }());
    return true;
}

void RestorationBucketCls::_removeChildData(RestorationBucket child) {
    assert(child != nullptr);
    assert(child->_parent == this);
    if (_claimedChildren->remove(child->restorationId()) == child) {
        _rawChildren()->remove(child->restorationId());
        List<RestorationBucket> pendingChildren = _childrenToAdd[child->restorationId()];
        if (pendingChildren != nullptr) {
            RestorationBucket toAdd = pendingChildren->removeLast();
            _finalizeAddChildData(toAdd);
            if (pendingChildren->isEmpty) {
                _childrenToAdd->remove(child->restorationId());
            }
        }
        if (_rawChildren()->isEmpty()) {
            _rawData->remove(_childrenMapKey);
        }
        _markNeedsSerialization();
        return;
    }
    _childrenToAdd[child->restorationId()]?->remove(child);
    if (_childrenToAdd[child->restorationId()]?->isEmpty() | false) {
        _childrenToAdd->remove(child->restorationId());
    }
}

void RestorationBucketCls::_addChildData(RestorationBucket child) {
    assert(child != nullptr);
    assert(child->_parent == this);
    if (_claimedChildren->containsKey(child->restorationId())) {
        _childrenToAdd->putIfAbsent(child->restorationId(), [=] ()         {
            makeList();
        })->add(child);
        _markNeedsSerialization();
        return;
    }
    _finalizeAddChildData(child);
    _markNeedsSerialization();
}

void RestorationBucketCls::_finalizeAddChildData(RestorationBucket child) {
    assert(_claimedChildren[child->restorationId()] == nullptr);
    assert(_rawChildren()[child->restorationId()] == nullptr);
    _claimedChildren[child->restorationId()] = child;
    _rawChildren()[child->restorationId()] = child->_rawData;
}

void RestorationBucketCls::_visitChildren(_BucketVisitor visitor, bool concurrentModification) {
    Iterable<RestorationBucket> children = _claimedChildren->values()->followedBy(_childrenToAdd->values()->expand([=] (List<RestorationBucket> buckets) {
    buckets;
}));
    if (concurrentModification) {
        children = children->toList(false);
    }
    children->forEach(visitor);
}

bool RestorationBucketCls::_debugAssertNotDisposed() {
    assert([=] () {
        if (_debugDisposed) {
            throw make<FlutterErrorCls>(__s("A $runtimeType was used after being disposed.\nOnce you have called dispose() on a $runtimeType, it can no longer be used."));
        }
        return true;
    }());
    return true;
}

bool debugIsSerializableForRestoration(Object object) {
    bool result = false;
    assert([=] () {
        try {
            make<StandardMessageCodecCls>()->encodeMessage(object);
            result = true;
        } catch (Unknown error) {
            result = false;
        };
        return true;
    }());
    return result;
}
