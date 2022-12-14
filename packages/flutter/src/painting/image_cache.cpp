#include "image_cache.hpp"
int ImageCacheCls::maximumSize() {
    return _maximumSize;
}

void ImageCacheCls::maximumSize(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == maximumSize()) {
        return;
    }
    TimelineTask timelineTask;
    if (!kReleaseMode) {
            auto _c1 = make<TimelineTaskCls>();    _c1.start(__s("ImageCache.setMaximumSize"), Map<String, Object> map2 = make<MapCls<>>();    map2.set(__s("value"), value);    list2);timelineTask = _c1;
    }
    _maximumSize = value;
    if (maximumSize() == 0) {
        clear();
    } else {
        _checkCacheSize(timelineTask);
    }
    if (!kReleaseMode) {
        timelineTask!->finish();
    }
}

int ImageCacheCls::currentSize() {
    return _cache->length();
}

int ImageCacheCls::maximumSizeBytes() {
    return _maximumSizeBytes;
}

void ImageCacheCls::maximumSizeBytes(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == _maximumSizeBytes) {
        return;
    }
    TimelineTask timelineTask;
    if (!kReleaseMode) {
            auto _c1 = make<TimelineTaskCls>();    _c1.start(__s("ImageCache.setMaximumSizeBytes"), Map<String, Object> map2 = make<MapCls<>>();    map2.set(__s("value"), value);    list2);timelineTask = _c1;
    }
    _maximumSizeBytes = value;
    if (_maximumSizeBytes == 0) {
        clear();
    } else {
        _checkCacheSize(timelineTask);
    }
    if (!kReleaseMode) {
        timelineTask!->finish();
    }
}

int ImageCacheCls::currentSizeBytes() {
    return _currentSizeBytes;
}

void ImageCacheCls::clear() {
    if (!kReleaseMode) {
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("pendingImages"), _pendingImages->length());    map1.set(__s("keepAliveImages"), _cache->length());    map1.set(__s("liveImages"), _liveImages->length());    map1.set(__s("currentSizeInBytes"), _currentSizeBytes);TimelineCls->instantSync(__s("ImageCache.clear"), list1);
    }
    for (_CachedImage image : _cache->values()) {
        image->dispose();
    }
    _cache->clear();
    for (_PendingImage pendingImage : _pendingImages->values()) {
        pendingImage->removeListener();
    }
    _pendingImages->clear();
    _currentSizeBytes = 0;
}

bool ImageCacheCls::evict(Object key, bool includeLive) {
    assert(includeLive != nullptr);
    if (includeLive) {
        _LiveImage image = _liveImages->remove(key);
        image?->dispose();
    }
    _PendingImage pendingImage = _pendingImages->remove(key);
    if (pendingImage != nullptr) {
        if (!kReleaseMode) {
                    Map<String, Object> map1 = make<MapCls<>>();        map1.set(__s("type"), __s("pending"));TimelineCls->instantSync(__s("ImageCache.evict"), list1);
        }
        pendingImage->removeListener();
        return true;
    }
    _CachedImage image = _cache->remove(key);
    if (image != nullptr) {
        if (!kReleaseMode) {
                    Map<String, Object> map2 = make<MapCls<>>();        map2.set(__s("type"), __s("keepAlive"));        map2.set(__s("sizeInBytes"), image->sizeBytes);TimelineCls->instantSync(__s("ImageCache.evict"), list2);
        }
        _currentSizeBytes -= image->sizeBytes!;
        image->dispose();
        return true;
    }
    if (!kReleaseMode) {
            Map<String, Object> map3 = make<MapCls<>>();    map3.set(__s("type"), __s("miss"));TimelineCls->instantSync(__s("ImageCache.evict"), list3);
    }
    return false;
}

ImageStreamCompleter ImageCacheCls::putIfAbsent(Object key, std::function<ImageStreamCompleter()> loader, ImageErrorListener onError) {
    assert(key != nullptr);
    assert(loader != nullptr);
    TimelineTask timelineTask;
    TimelineTask listenerTask;
    if (!kReleaseMode) {
            auto _c1 = make<TimelineTaskCls>();    _c1.start(__s("ImageCache.putIfAbsent"), Map<String, Object> map2 = make<MapCls<>>();    map2.set(__s("key"), key->toString());    list2);timelineTask = _c1;
    }
    ImageStreamCompleter result = _pendingImages[key]?->completer;
    if (result != nullptr) {
        if (!kReleaseMode) {
                    Map<String, Object> map3 = make<MapCls<>>();        map3.set(__s("result"), __s("pending"));timelineTask!->finish(list3);
        }
        return result;
    }
    _CachedImage image = _cache->remove(key);
    if (image != nullptr) {
        if (!kReleaseMode) {
                    Map<String, Object> map4 = make<MapCls<>>();        map4.set(__s("result"), __s("keepAlive"));timelineTask!->finish(list4);
        }
        _trackLiveImage(key, image->completer, image->sizeBytes);
        _cache[key] = image;
        return image->completer;
    }
    _LiveImage liveImage = _liveImages[key];
    if (liveImage != nullptr) {
        _touch(key, make<_CachedImageCls>(liveImage->completer, liveImage->sizeBytes), timelineTask);
        if (!kReleaseMode) {
                    Map<String, Object> map5 = make<MapCls<>>();        map5.set(__s("result"), __s("keepAlive"));timelineTask!->finish(list5);
        }
        return liveImage->completer;
    }
    try {
        result = loader();
        _trackLiveImage(key, result, nullptr);
    } catch (Unknown error) {
        if (!kReleaseMode) {
                    Map<String, Object> map6 = make<MapCls<>>();        map6.set(__s("result"), __s("error"));        map6.set(__s("error"), error->toString());        map6.set(__s("stackTrace"), stackTrace->toString());timelineTask!->finish(list6);
        }
        if (onError != nullptr) {
            onError(error, stackTrace);
            return nullptr;
        } else {
            throw;
        }
    };
    if (!kReleaseMode) {
            auto _c7 = make<TimelineTaskCls>(timelineTask);    _c7.start(__s("listener"));listenerTask = _c7;
    }
    bool listenedOnce = false;
    bool trackPendingImage = maximumSize() > 0 && maximumSizeBytes() > 0;
    _PendingImage pendingImage;
    InlineMethod;
    ImageStreamListener streamListener = make<ImageStreamListenerCls>(listener);
    pendingImage = make<_PendingImageCls>(result, streamListener);
    if (trackPendingImage) {
        _pendingImages[key] = pendingImage;
    }
    result->addListener(streamListener);
    return result;
}

ImageCacheStatus ImageCacheCls::statusForKey(Object key) {
    return ImageCacheStatusCls->_(_pendingImages->containsKey(key), _cache->containsKey(key), _liveImages->containsKey(key));
}

bool ImageCacheCls::containsKey(Object key) {
    return _pendingImages[key] != nullptr || _cache[key] != nullptr;
}

int ImageCacheCls::liveImageCount() {
    return _liveImages->length();
}

int ImageCacheCls::pendingImageCount() {
    return _pendingImages->length();
}

void ImageCacheCls::clearLiveImages() {
    for (_LiveImage image : _liveImages->values()) {
        image->dispose();
    }
    _liveImages->clear();
}

void ImageCacheCls::_touch(Object key, _CachedImage image, TimelineTask timelineTask) {
    assert(timelineTask != nullptr);
    if (image->sizeBytes != nullptr && image->sizeBytes! <= maximumSizeBytes() && maximumSize() > 0) {
        _currentSizeBytes += image->sizeBytes!;
        _cache[key] = image;
        _checkCacheSize(timelineTask);
    } else {
        image->dispose();
    }
}

void ImageCacheCls::_trackLiveImage(Object key, ImageStreamCompleter completer, int sizeBytes) {
    _liveImages->putIfAbsent(key, [=] () {
        return make<_LiveImageCls>(completer, [=] () {
            _liveImages->remove(key);
        });
    })->sizeBytes |= sizeBytes;
}

void ImageCacheCls::_checkCacheSize(TimelineTask timelineTask) {
    Map<String, Object> finishArgs = makeMap(makeList(), makeList();
    TimelineTask checkCacheTask;
    if (!kReleaseMode) {
            auto _c1 = make<TimelineTaskCls>(timelineTask);    _c1.start(__s("checkCacheSize"));checkCacheTask = _c1;
        finishArgs[__s("evictedKeys")] = makeList();
        finishArgs[__s("currentSize")] = currentSize();
        finishArgs[__s("currentSizeBytes")] = currentSizeBytes();
    }
    while (_currentSizeBytes > _maximumSizeBytes || _cache->length() > _maximumSize) {
        Object key = _cache->keys()->first();
        _CachedImage image = _cache[key]!;
        _currentSizeBytes -= image->sizeBytes!;
        image->dispose();
        _cache->remove(key);
        if (!kReleaseMode) {
            (as<List<String>>(finishArgs[__s("evictedKeys")]))->add(key->toString());
        }
    }
    if (!kReleaseMode) {
        finishArgs[__s("endSize")] = currentSize();
        finishArgs[__s("endSizeBytes")] = currentSizeBytes();
        checkCacheTask!->finish(finishArgs);
    }
    assert(_currentSizeBytes >= 0);
    assert(_cache->length() <= maximumSize());
    assert(_currentSizeBytes <= maximumSizeBytes());
}

bool ImageCacheStatusCls::tracked() {
    return pending || keepAlive || live;
}

bool ImageCacheStatusCls::untracked() {
    return !pending && !keepAlive && !live;
}

bool ImageCacheStatusCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ImageCacheStatus>(other) && other->pending == pending && other->keepAlive == keepAlive && other->live == live;
}

int ImageCacheStatusCls::hashCode() {
    return ObjectCls->hash(pending, keepAlive, live);
}

String ImageCacheStatusCls::toString() {
    return __sf("%s(pending: %s, live: %s, keepAlive: %s)", objectRuntimeType(this, __s("ImageCacheStatus")), pending, live, keepAlive);
}

void ImageCacheStatusCls::_(bool keepAlive, bool live, bool pending)

void _CachedImageBaseCls::dispose() {
    assert(handle != nullptr);
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
        assert(handle != nullptr);
        handle?->dispose();
        handle = nullptr;
    });
}

_CachedImageBaseCls::_CachedImageBaseCls(ImageStreamCompleter completer, int sizeBytes) {
    {
        assert(completer != nullptr);
        handle = completer->keepAlive();
    }
}

_CachedImageCls::_CachedImageCls(ImageStreamCompleter completer, int sizeBytes) : _CachedImageBase(completercompleter) {
}

void _LiveImageCls::dispose() {
    completer->removeOnLastListenerRemovedCallback(_handleRemove);
    super->dispose();
}

String _LiveImageCls::toString() {
    return describeIdentity(this);
}

_LiveImageCls::_LiveImageCls(ImageStreamCompleter completer, VoidCallback handleRemove, int sizeBytes) : _CachedImageBase(completersizeBytes) {
    {
        _handleRemove = [=] () {
            handleRemove();
            dispose();
        };
        completer->addOnLastListenerRemovedCallback(_handleRemove);
    }
}

void _PendingImageCls::removeListener() {
    completer->removeListener(listener);
}
