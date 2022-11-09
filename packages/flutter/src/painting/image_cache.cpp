#include "image_cache.hpp"
int ImageCacheCls::maximumSize() {
    return _maximumSize;
}

void ImageCacheCls::maximumSize(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == maximumSize) {
        return;
    }
    TimelineTask timelineTask;
    if (!kReleaseMode) {
            auto _c1 = make<TimelineTaskCls>();    _c1.start("ImageCache.setMaximumSize"Map<String, dynamic> map2 = make<MapCls<>>();    map2.set("value", value);    list2);timelineTask = _c1;
    }
    _maximumSize = value;
    if (maximumSize == 0) {
        clear();
    } else {
        _checkCacheSize(timelineTask);
    }
    if (!kReleaseMode) {
        timelineTask!->finish();
    }
}

int ImageCacheCls::currentSize() {
    return _cache->length;
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
            auto _c1 = make<TimelineTaskCls>();    _c1.start("ImageCache.setMaximumSizeBytes"Map<String, dynamic> map2 = make<MapCls<>>();    map2.set("value", value);    list2);timelineTask = _c1;
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
            Map<String, dynamic> map1 = make<MapCls<>>();    map1.set("pendingImages", _pendingImages->length);    map1.set("keepAliveImages", _cache->length);    map1.set("liveImages", _liveImages->length);    map1.set("currentSizeInBytes", _currentSizeBytes);TimelineCls->instantSync("ImageCache.clear"list1);
    }
    for (_CachedImage image : _cache->values) {
        image->dispose();
    }
    _cache->clear();
    for (_PendingImage pendingImage : _pendingImages->values) {
        pendingImage->removeListener();
    }
    _pendingImages->clear();
    _currentSizeBytes = 0;
}

bool ImageCacheCls::evict(bool includeLive, Object key) {
    assert(includeLive != nullptr);
    if (includeLive) {
        _LiveImage image = _liveImages->remove(key);
        image?->dispose();
    }
    _PendingImage pendingImage = _pendingImages->remove(key);
    if (pendingImage != nullptr) {
        if (!kReleaseMode) {
                    Map<String, dynamic> map1 = make<MapCls<>>();        map1.set("type", "pending");TimelineCls->instantSync("ImageCache.evict"list1);
        }
        pendingImage->removeListener();
        return true;
    }
    _CachedImage image = _cache->remove(key);
    if (image != nullptr) {
        if (!kReleaseMode) {
                    Map<String, dynamic> map2 = make<MapCls<>>();        map2.set("type", "keepAlive");        map2.set("sizeInBytes", image->sizeBytes);TimelineCls->instantSync("ImageCache.evict"list2);
        }
        _currentSizeBytes = image->sizeBytes!;
        image->dispose();
        return true;
    }
    if (!kReleaseMode) {
            Map<String, dynamic> map3 = make<MapCls<>>();    map3.set("type", "miss");TimelineCls->instantSync("ImageCache.evict"list3);
    }
    return false;
}

ImageStreamCompleter ImageCacheCls::putIfAbsent(Object key, ImageStreamCompleter loader() , ImageErrorListener onError) {
    assert(key != nullptr);
    assert(loader != nullptr);
    TimelineTask timelineTask;
    TimelineTask listenerTask;
    if (!kReleaseMode) {
            auto _c1 = make<TimelineTaskCls>();    _c1.start("ImageCache.putIfAbsent"Map<String, dynamic> map2 = make<MapCls<>>();    map2.set("key", key->toString());    list2);timelineTask = _c1;
    }
    ImageStreamCompleter result = _pendingImages[key]?->completer;
    if (result != nullptr) {
        if (!kReleaseMode) {
                    Map<String, dynamic> map3 = make<MapCls<>>();        map3.set("result", "pending");timelineTask!->finish(list3);
        }
        return result;
    }
    _CachedImage image = _cache->remove(key);
    if (image != nullptr) {
        if (!kReleaseMode) {
                    Map<String, dynamic> map4 = make<MapCls<>>();        map4.set("result", "keepAlive");timelineTask!->finish(list4);
        }
        _trackLiveImage(key, image->completer, image->sizeBytes);
        _cache[key] = image;
        return image->completer;
    }
    _LiveImage liveImage = _liveImages[key];
    if (liveImage != nullptr) {
        _touch(key, make<_CachedImageCls>(liveImage->completerliveImage->sizeBytes), timelineTask);
        if (!kReleaseMode) {
                    Map<String, dynamic> map5 = make<MapCls<>>();        map5.set("result", "keepAlive");timelineTask!->finish(list5);
        }
        return liveImage->completer;
    }
    try {
        result = loader();
        _trackLiveImage(key, result, nullptr);
    } catch (Unknown error) {
        if (!kReleaseMode) {
                    Map<String, dynamic> map6 = make<MapCls<>>();        map6.set("result", "error");        map6.set("error", error->toString());        map6.set("stackTrace", stackTrace->toString());timelineTask!->finish(list6);
        }
        if (onError != nullptr) {
            onError(error, stackTrace);
            return nullptr;
        } else {
            throw;
        }
    };
    if (!kReleaseMode) {
            auto _c7 = make<TimelineTaskCls>(timelineTask);    _c7.start("listener");listenerTask = _c7;
    }
    bool listenedOnce = false;
    bool trackPendingImage = maximumSize > 0 && maximumSizeBytes > 0;
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
    return _liveImages->length;
}

int ImageCacheCls::pendingImageCount() {
    return _pendingImages->length;
}

void ImageCacheCls::clearLiveImages() {
    for (_LiveImage image : _liveImages->values) {
        image->dispose();
    }
    _liveImages->clear();
}

void ImageCacheCls::_touch(_CachedImage image, Object key, TimelineTask timelineTask) {
    assert(timelineTask != nullptr);
    if (image->sizeBytes != nullptr && image->sizeBytes! <= maximumSizeBytes && maximumSize > 0) {
        _currentSizeBytes = image->sizeBytes!;
        _cache[key] = image;
        _checkCacheSize(timelineTask);
    } else {
        image->dispose();
    }
}

void ImageCacheCls::_trackLiveImage(ImageStreamCompleter completer, Object key, int sizeBytes) {
    _liveImages->putIfAbsent(key, [=] () {
        return make<_LiveImageCls>(completer, [=] () {
            _liveImages->remove(key);
        });
    })->sizeBytes = sizeBytes;
}

void ImageCacheCls::_checkCacheSize(TimelineTask timelineTask) {
    Map<String, dynamic> finishArgs = makeMap(makeList(), makeList();
    TimelineTask checkCacheTask;
    if (!kReleaseMode) {
            auto _c1 = make<TimelineTaskCls>(timelineTask);    _c1.start("checkCacheSize");checkCacheTask = _c1;
        finishArgs["evictedKeys"] = makeList();
        finishArgs["currentSize"] = currentSize;
        finishArgs["currentSizeBytes"] = currentSizeBytes;
    }
    while (_currentSizeBytes > _maximumSizeBytes || _cache->length > _maximumSize) {
        Object key = _cache->keys->first;
        _CachedImage image = _cache[key]!;
        _currentSizeBytes = image->sizeBytes!;
        image->dispose();
        _cache->remove(key);
        if (!kReleaseMode) {
            (((List<String>)finishArgs["evictedKeys"]))->add(key->toString());
        }
    }
    if (!kReleaseMode) {
        finishArgs["endSize"] = currentSize;
        finishArgs["endSizeBytes"] = currentSizeBytes;
        checkCacheTask!->finish(finishArgs);
    }
    assert(_currentSizeBytes >= 0);
    assert(_cache->length <= maximumSize);
    assert(_currentSizeBytes <= maximumSizeBytes);
}

bool ImageCacheStatusCls::tracked() {
    return pending || keepAlive || live;
}

bool ImageCacheStatusCls::untracked() {
    return !pending && !keepAlive && !live;
}

bool ImageCacheStatusCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is ImageCacheStatus && other->pending == pending && other->keepAlive == keepAlive && other->live == live;
}

int ImageCacheStatusCls::hashCode() {
    return ObjectCls->hash(pending, keepAlive, live);
}

String ImageCacheStatusCls::toString() {
    return "${objectRuntimeType(this, 'ImageCacheStatus')}(pending: $pending, live: $live, keepAlive: $keepAlive)";
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

void _LiveImageCls::dispose() {
    completer->removeOnLastListenerRemovedCallback(_handleRemove);
    super->dispose();
}

String _LiveImageCls::toString() {
    return describeIdentity(this);
}

_LiveImageCls::_LiveImageCls(ImageStreamCompleter completer, VoidCallback handleRemove, int sizeBytes) {
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
