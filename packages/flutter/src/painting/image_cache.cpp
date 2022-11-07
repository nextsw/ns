#include "image_cache.hpp"
int ImageCache::maximumSize() {
    return _maximumSize;
}

void ImageCache::maximumSize(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == maximumSize) {
        return;
    }
    TimelineTask timelineTask;
    if (!kReleaseMode) {
        timelineTask = ;
    }
    _maximumSize = value;
    if (maximumSize == 0) {
        clear();
    } else {
        _checkCacheSize(timelineTask);
    }
    if (!kReleaseMode) {
        timelineTask!.finish();
    }
}

int ImageCache::currentSize() {
    return _cache.length;
}

int ImageCache::maximumSizeBytes() {
    return _maximumSizeBytes;
}

void ImageCache::maximumSizeBytes(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == _maximumSizeBytes) {
        return;
    }
    TimelineTask timelineTask;
    if (!kReleaseMode) {
        timelineTask = ;
    }
    _maximumSizeBytes = value;
    if (_maximumSizeBytes == 0) {
        clear();
    } else {
        _checkCacheSize(timelineTask);
    }
    if (!kReleaseMode) {
        timelineTask!.finish();
    }
}

int ImageCache::currentSizeBytes() {
    return _currentSizeBytes;
}

void ImageCache::clear() {
    if (!kReleaseMode) {
        Timeline.instantSync("ImageCache.clear");
    }
    for (_CachedImage image : _cache.values) {
        image.dispose();
    }
    _cache.clear();
    for (_PendingImage pendingImage : _pendingImages.values) {
        pendingImage.removeListener();
    }
    _pendingImages.clear();
    _currentSizeBytes = 0;
}

bool ImageCache::evict(bool includeLive, Object key) {
    assert(includeLive != nullptr);
    if (includeLive) {
        _LiveImage image = _liveImages.remove(key);
        image?.dispose();
    }
    _PendingImage pendingImage = _pendingImages.remove(key);
    if (pendingImage != nullptr) {
        if (!kReleaseMode) {
            Timeline.instantSync("ImageCache.evict");
        }
        pendingImage.removeListener();
        return true;
    }
    _CachedImage image = _cache.remove(key);
    if (image != nullptr) {
        if (!kReleaseMode) {
            Timeline.instantSync("ImageCache.evict");
        }
        _currentSizeBytes = image.sizeBytes!;
        image.dispose();
        return true;
    }
    if (!kReleaseMode) {
        Timeline.instantSync("ImageCache.evict");
    }
    return false;
}

ImageStreamCompleter ImageCache::putIfAbsent(Object key, FunctionType loader, ImageErrorListener onError) {
    assert(key != nullptr);
    assert(loader != nullptr);
    TimelineTask timelineTask;
    TimelineTask listenerTask;
    if (!kReleaseMode) {
        timelineTask = ;
    }
    ImageStreamCompleter result = _pendingImages[key]?.completer;
    if (result != nullptr) {
        if (!kReleaseMode) {
            timelineTask!.finish();
        }
        return result;
    }
    _CachedImage image = _cache.remove(key);
    if (image != nullptr) {
        if (!kReleaseMode) {
            timelineTask!.finish();
        }
        _trackLiveImage(key, image.completer, image.sizeBytes);
        _cache[key] = image;
        return image.completer;
    }
    _LiveImage liveImage = _liveImages[key];
    if (liveImage != nullptr) {
        _touch(key, _CachedImage(liveImage.completerliveImage.sizeBytes), timelineTask);
        if (!kReleaseMode) {
            timelineTask!.finish();
        }
        return liveImage.completer;
    }
    ;
    if (!kReleaseMode) {
        listenerTask = ;
    }
    bool listenedOnce = false;
    bool trackPendingImage = maximumSize > 0 && maximumSizeBytes > 0;
    _PendingImage pendingImage;
    ;
    ImageStreamListener streamListener = ImageStreamListener(listener);
    pendingImage = _PendingImage(result, streamListener);
    if (trackPendingImage) {
        _pendingImages[key] = pendingImage;
    }
    result.addListener(streamListener);
    return result;
}

ImageCacheStatus ImageCache::statusForKey(Object key) {
    return ImageCacheStatus._(_pendingImages.containsKey(key), _cache.containsKey(key), _liveImages.containsKey(key));
}

bool ImageCache::containsKey(Object key) {
    return _pendingImages[key] != nullptr || _cache[key] != nullptr;
}

int ImageCache::liveImageCount() {
    return _liveImages.length;
}

int ImageCache::pendingImageCount() {
    return _pendingImages.length;
}

void ImageCache::clearLiveImages() {
    for (_LiveImage image : _liveImages.values) {
        image.dispose();
    }
    _liveImages.clear();
}

void ImageCache::_touch(_CachedImage image, Object key, TimelineTask timelineTask) {
    assert(timelineTask != nullptr);
    if (image.sizeBytes != nullptr && image.sizeBytes! <= maximumSizeBytes && maximumSize > 0) {
        _currentSizeBytes = image.sizeBytes!;
        _cache[key] = image;
        _checkCacheSize(timelineTask);
    } else {
        image.dispose();
    }
}

void ImageCache::_trackLiveImage(ImageStreamCompleter completer, Object key, int sizeBytes) {
    _liveImages.putIfAbsent(key, ).sizeBytes = sizeBytes;
}

void ImageCache::_checkCacheSize(TimelineTask timelineTask) {
    Map<String, dynamic> finishArgs = ;
    TimelineTask checkCacheTask;
    if (!kReleaseMode) {
        checkCacheTask = ;
        finishArgs["evictedKeys"] = ;
        finishArgs["currentSize"] = currentSize;
        finishArgs["currentSizeBytes"] = currentSizeBytes;
    }
    while (_currentSizeBytes > _maximumSizeBytes || _cache.length > _maximumSize) {
        Object key = _cache.keys.first;
        _CachedImage image = _cache[key]!;
        _currentSizeBytes = image.sizeBytes!;
        image.dispose();
        _cache.remove(key);
        if (!kReleaseMode) {
            (().add(key.toString());
        }
    }
    if (!kReleaseMode) {
        finishArgs["endSize"] = currentSize;
        finishArgs["endSizeBytes"] = currentSizeBytes;
        checkCacheTask!.finish(finishArgs);
    }
    assert(_currentSizeBytes >= 0);
    assert(_cache.length <= maximumSize);
    assert(_currentSizeBytes <= maximumSizeBytes);
}

bool ImageCacheStatus::tracked() {
    return pending || keepAlive || live;
}

bool ImageCacheStatus::untracked() {
    return !pending && !keepAlive && !live;
}

bool ImageCacheStatus::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ImageCacheStatus && other.pending == pending && other.keepAlive == keepAlive && other.live == live;
}

int ImageCacheStatus::hashCode() {
    return Object.hash(pending, keepAlive, live);
}

String ImageCacheStatus::toString() {
    return "${objectRuntimeType(this, 'ImageCacheStatus')}(pending: $pending, live: $live, keepAlive: $keepAlive)";
}

void ImageCacheStatus::_(bool keepAlive, bool live, bool pending)

void _CachedImageBase::dispose() {
    assert(handle != nullptr);
    SchedulerBinding.instance.addPostFrameCallback();
}

_CachedImageBase::_CachedImageBase(ImageStreamCompleter completer, int sizeBytes) {
    {
        assert(completer != nullptr);
        handle = completer.keepAlive();
    }
}

void _LiveImage::dispose() {
    completer.removeOnLastListenerRemovedCallback(_handleRemove);
    super.dispose();
}

String _LiveImage::toString() {
    return describeIdentity(this);
}

_LiveImage::_LiveImage(ImageStreamCompleter completer, VoidCallback handleRemove, int sizeBytes) {
    {
        super(completersizeBytes);
    }
    {
        _handleRemove = ;
        completer.addOnLastListenerRemovedCallback(_handleRemove);
    }
}

void _PendingImage::removeListener() {
    completer.removeListener(listener);
}
