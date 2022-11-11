#ifndef PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_CACHE
#define PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_CACHE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/developer/developer.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "image_stream.hpp"

int _kDefaultSize;

int _kDefaultSizeBytes;


class ImageCacheCls : public ObjectCls {
public:

    virtual int maximumSize();

    virtual void  maximumSize(int value);

    virtual int currentSize();

    virtual int maximumSizeBytes();

    virtual void  maximumSizeBytes(int value);

    virtual int currentSizeBytes();

    virtual void clear();

    virtual bool evict(Object key, bool includeLive);

    virtual ImageStreamCompleter putIfAbsent(Object key, std::function<ImageStreamCompleter()> loader, ImageErrorListener onError);

    virtual ImageCacheStatus statusForKey(Object key);

    virtual bool containsKey(Object key);

    virtual int liveImageCount();

    virtual int pendingImageCount();

    virtual void clearLiveImages();

private:
    Map<Object, _PendingImage> _pendingImages;

    Map<Object, _CachedImage> _cache;

    Map<Object, _LiveImage> _liveImages;

    int _maximumSize;

    int _maximumSizeBytes;

    int _currentSizeBytes;


    virtual void _touch(Object key, _CachedImage image, TimelineTask timelineTask);

    virtual void _trackLiveImage(Object key, ImageStreamCompleter completer, int sizeBytes);

    virtual void _checkCacheSize(TimelineTask timelineTask);

};
using ImageCache = std::shared_ptr<ImageCacheCls>;

class ImageCacheStatusCls : public ObjectCls {
public:
    bool pending;

    bool keepAlive;

    bool live;


    virtual bool tracked();

    virtual bool untracked();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual void  _(bool keepAlive, bool live, bool pending);

};
using ImageCacheStatus = std::shared_ptr<ImageCacheStatusCls>;

class _CachedImageBaseCls : public ObjectCls {
public:
    ImageStreamCompleter completer;

    int sizeBytes;

    ImageStreamCompleterHandle handle;


    virtual void dispose();

private:

     _CachedImageBaseCls(ImageStreamCompleter completer, int sizeBytes);

};
using _CachedImageBase = std::shared_ptr<_CachedImageBaseCls>;

class _CachedImageCls : public _CachedImageBaseCls {
public:

private:

     _CachedImageCls(Unknown completer, Unknown sizeBytes);
};
using _CachedImage = std::shared_ptr<_CachedImageCls>;

class _LiveImageCls : public _CachedImageBaseCls {
public:

    virtual void dispose();

    virtual String toString();

private:
    VoidCallback _handleRemove;


     _LiveImageCls(ImageStreamCompleter completer, VoidCallback handleRemove, int sizeBytes);

};
using _LiveImage = std::shared_ptr<_LiveImageCls>;

class _PendingImageCls : public ObjectCls {
public:
    ImageStreamCompleter completer;

    ImageStreamListener listener;


    virtual void removeListener();

private:

     _PendingImageCls(ImageStreamCompleter completer, ImageStreamListener listener);
};
using _PendingImage = std::shared_ptr<_PendingImageCls>;


#endif