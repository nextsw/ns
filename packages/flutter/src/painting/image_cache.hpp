#ifndef IMAGE_CACHE_H
#define IMAGE_CACHE_H
#include <memory>

#include <developer/developer.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include "image_stream.hpp"


const int _kDefaultSize;

const int _kDefaultSizeBytes;


class ImageCache {
public:

    int maximumSize();

    void  maximumSize(int value);

    int currentSize();

    int maximumSizeBytes();

    void  maximumSizeBytes(int value);

    int currentSizeBytes();

    void clear();

    bool evict(bool includeLive, Object key);

    ImageStreamCompleter putIfAbsent(Object key, FunctionType loader, ImageErrorListener onError);

    ImageCacheStatus statusForKey(Object key);

    bool containsKey(Object key);

    int liveImageCount();

    int pendingImageCount();

    void clearLiveImages();

private:
    Map<Object, _PendingImage> _pendingImages;

    Map<Object, _CachedImage> _cache;

    Map<Object, _LiveImage> _liveImages;

    int _maximumSize;

    int _maximumSizeBytes;

    int _currentSizeBytes;


    void _touch(_CachedImage image, Object key, TimelineTask timelineTask);

    void _trackLiveImage(ImageStreamCompleter completer, Object key, int sizeBytes);

    void _checkCacheSize(TimelineTask timelineTask);

};

class ImageCacheStatus {
public:
    bool pending;

    bool keepAlive;

    bool live;


    bool tracked();

    bool untracked();

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    void  _(bool keepAlive, bool live, bool pending);

};

class _CachedImageBase {
public:
    ImageStreamCompleter completer;

    int sizeBytes;

    ImageStreamCompleterHandle handle;


    void dispose();

private:

     _CachedImageBase(ImageStreamCompleter completer, int sizeBytes);

};

class _CachedImage : _CachedImageBase {
public:

private:

     _CachedImage(Unknown, Unknown);

};

class _LiveImage : _CachedImageBase {
public:

    void dispose();

    String toString();

private:
    VoidCallback _handleRemove;


     _LiveImage(ImageStreamCompleter completer, VoidCallback handleRemove, int sizeBytes);

};

class _PendingImage {
public:
    ImageStreamCompleter completer;

    ImageStreamListener listener;


    void removeListener();

private:

     _PendingImage(ImageStreamCompleter completer, ImageStreamListener listener);

};

#endif