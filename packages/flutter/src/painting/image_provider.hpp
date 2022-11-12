#ifndef PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_PROVIDER
#define PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_PROVIDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "_network_image_io.hpp"
#include "binding.hpp"
#include "image_cache.hpp"
#include "image_stream.hpp"


class ImageConfigurationCls : public ObjectCls {
public:
    AssetBundle bundle;

    double devicePixelRatio;

    Locale locale;

    TextDirection textDirection;

    Size size;

    TargetPlatform platform;

    static ImageConfiguration empty;


     ImageConfigurationCls(AssetBundle bundle, double devicePixelRatio, Locale locale, TargetPlatform platform, Size size, TextDirection textDirection);
    virtual ImageConfiguration copyWith(AssetBundle bundle, double devicePixelRatio, Locale locale, TargetPlatform platform, Size size, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using ImageConfiguration = std::shared_ptr<ImageConfigurationCls>;

template<typename T>
class ImageProviderCls : public ObjectCls {
public:

     ImageProviderCls();
    virtual ImageStream resolve(ImageConfiguration configuration);

    virtual ImageStream createStream(ImageConfiguration configuration);

    virtual Future<ImageCacheStatus> obtainCacheStatus(ImageConfiguration configuration, ImageErrorListener handleError);

    virtual void resolveStreamForKey(ImageConfiguration configuration, ImageStream stream, T key, ImageErrorListener handleError);

    virtual Future<bool> evict(ImageCache cache, ImageConfiguration configuration);

    virtual Future<T> obtainKey(ImageConfiguration configuration);
    virtual ImageStreamCompleter load(T key, DecoderCallback decode);

    virtual ImageStreamCompleter loadBuffer(T key, DecoderBufferCallback decode);

    virtual String toString();

private:

    virtual void _createErrorHandlerAndKey(ImageConfiguration configuration, _KeyAndErrorHandlerCallback<T> successCallback, _AsyncKeyErrorHandler<T> errorCallback);

};
template<typename T>
using ImageProvider = std::shared_ptr<ImageProviderCls<T>>;

class AssetBundleImageKeyCls : public ObjectCls {
public:
    AssetBundle bundle;

    String name;

    double scale;


     AssetBundleImageKeyCls(AssetBundle bundle, String name, double scale);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using AssetBundleImageKey = std::shared_ptr<AssetBundleImageKeyCls>;

class AssetBundleImageProviderCls : public ImageProviderCls<AssetBundleImageKey> {
public:

     AssetBundleImageProviderCls();
    virtual ImageStreamCompleter loadBuffer(AssetBundleImageKey key, DecoderBufferCallback decode);

    virtual ImageStreamCompleter load(AssetBundleImageKey key, DecoderCallback decode);

private:

    virtual Future<Codec> _loadAsync(AssetBundleImageKey key, DecoderBufferCallback decode, DecoderCallback decodeDepreacted);

};
using AssetBundleImageProvider = std::shared_ptr<AssetBundleImageProviderCls>;

class ResizeImageKeyCls : public ObjectCls {
public:

    virtual bool operator==(Object other);

    virtual int hashCode();

private:
    Object _providerCacheKey;

    int _width;

    int _height;


    virtual void  _(Object _providerCacheKey, int _width, int _height);
};
using ResizeImageKey = std::shared_ptr<ResizeImageKeyCls>;

class ResizeImageCls : public ImageProviderCls<ResizeImageKey> {
public:
    ImageProvider<any> imageProvider;

    int width;

    int height;

    bool allowUpscaling;


     ResizeImageCls(ImageProvider<any> imageProvider, bool allowUpscaling, int height, int width);

    static ImageProvider<Object> resizeIfNeeded(int cacheWidth, int cacheHeight, ImageProvider<Object> provider);

    virtual ImageStreamCompleter load(ResizeImageKey key, DecoderCallback decode);

    virtual ImageStreamCompleter loadBuffer(ResizeImageKey key, DecoderBufferCallback decode);

    virtual Future<ResizeImageKey> obtainKey(ImageConfiguration configuration);

private:

};
using ResizeImage = std::shared_ptr<ResizeImageCls>;

class NetworkImageCls : public ImageProviderCls<NetworkImage> {
public:

     NetworkImageCls(String url, Map<String, String> headers, double scale);
    virtual String url();
    virtual double scale();
    virtual Map<String, String> headers();
    virtual ImageStreamCompleter load(NetworkImage key, DecoderCallback decode) override;
    virtual ImageStreamCompleter loadBuffer(NetworkImage key, DecoderBufferCallback decode) override;
private:

};
using NetworkImage = std::shared_ptr<NetworkImageCls>;

class FileImageCls : public ImageProviderCls<FileImage> {
public:
    File file;

    double scale;


     FileImageCls(File file, double scale);

    virtual Future<FileImage> obtainKey(ImageConfiguration configuration);

    virtual ImageStreamCompleter load(FileImage key, DecoderCallback decode);

    virtual ImageStreamCompleter loadBuffer(FileImage key, DecoderBufferCallback decode);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual Future<Codec> _loadAsync(FileImage key, DecoderBufferCallback decode, DecoderCallback decodeDeprecated);

};
using FileImage = std::shared_ptr<FileImageCls>;

class MemoryImageCls : public ImageProviderCls<MemoryImage> {
public:
    Uint8List bytes;

    double scale;


     MemoryImageCls(Uint8List bytes, double scale);

    virtual Future<MemoryImage> obtainKey(ImageConfiguration configuration);

    virtual ImageStreamCompleter load(MemoryImage key, DecoderCallback decode);

    virtual ImageStreamCompleter loadBuffer(MemoryImage key, DecoderBufferCallback decode);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual Future<Codec> _loadAsync(MemoryImage key, DecoderBufferCallback decode, DecoderCallback decodeDepreacted);

};
using MemoryImage = std::shared_ptr<MemoryImageCls>;

class ExactAssetImageCls : public AssetBundleImageProviderCls {
public:
    String assetName;

    double scale;

    AssetBundle bundle;

    String package;


     ExactAssetImageCls(String assetName, AssetBundle bundle, String package, double scale);

    virtual String keyName();

    virtual Future<AssetBundleImageKey> obtainKey(ImageConfiguration configuration);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using ExactAssetImage = std::shared_ptr<ExactAssetImageCls>;

class _ErrorImageCompleterCls : public ImageStreamCompleterCls {
public:

private:

};
using _ErrorImageCompleter = std::shared_ptr<_ErrorImageCompleterCls>;

class NetworkImageLoadExceptionCls : public ObjectCls {
public:
    int statusCode;

    Uri uri;


     NetworkImageLoadExceptionCls(int statusCode, Uri uri);

    virtual String toString();

private:
    String _message;


};
using NetworkImageLoadException = std::shared_ptr<NetworkImageLoadExceptionCls>;


#endif