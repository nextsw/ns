#include "image_provider.hpp"
ImageConfiguration ImageConfigurationCls::copyWith(AssetBundle bundle, double devicePixelRatio, Locale locale, TargetPlatform platform, Size size, TextDirection textDirection) {
    return make<ImageConfigurationCls>(bundle | this->bundle, devicePixelRatio | this->devicePixelRatio, locale | this->locale, textDirection | this->textDirection, size | this->size, platform | this->platform);
}

bool ImageConfigurationCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ImageConfiguration>(other) && other->bundle == bundle && other->devicePixelRatio == devicePixelRatio && other->locale == locale && other->textDirection == textDirection && other->size == size && other->platform == platform;
}

int ImageConfigurationCls::hashCode() {
    return ObjectCls->hash(bundle, devicePixelRatio, locale, size, platform);
}

String ImageConfigurationCls::toString() {
    StringBuffer result = make<StringBufferCls>();
    result->write(__s("ImageConfiguration("));
    bool hasArguments = false;
    if (bundle != nullptr) {
        result->write(__sf("bundle: %s", bundle));
        hasArguments = true;
    }
    if (devicePixelRatio != nullptr) {
        if (hasArguments) {
            result->write(__s(", "));
        }
        result->write(__sf("devicePixelRatio: %s", devicePixelRatio!->toStringAsFixed(1)));
        hasArguments = true;
    }
    if (locale != nullptr) {
        if (hasArguments) {
            result->write(__s(", "));
        }
        result->write(__sf("locale: %s", locale));
        hasArguments = true;
    }
    if (textDirection != nullptr) {
        if (hasArguments) {
            result->write(__s(", "));
        }
        result->write(__sf("textDirection: %s", textDirection));
        hasArguments = true;
    }
    if (size != nullptr) {
        if (hasArguments) {
            result->write(__s(", "));
        }
        result->write(__sf("size: %s", size));
        hasArguments = true;
    }
    if (platform != nullptr) {
        if (hasArguments) {
            result->write(__s(", "));
        }
        result->write(__sf("platform: %s", platform!->name));
        hasArguments = true;
    }
    result->write(__s(")"));
    return result->toString();
}

template<typename T>
ImageStream ImageProviderCls<T>::resolve(ImageConfiguration configuration) {
    assert(configuration != nullptr);
    ImageStream stream = createStream(configuration);
    _createErrorHandlerAndKey(configuration, [=] (T key,ImageErrorListener errorHandler) {
        resolveStreamForKey(configuration, stream, key, errorHandler);
    }, [=] (T key,Object exception,StackTrace stack) {
        await nullptr;
        InformationCollector collector;
        assert([=] () {
            collector = [=] () {
                makeList(ArrayItem, ArrayItem, ArrayItem);
            };
            return true;
        }());
        if (stream->completer() == nullptr) {
            stream->setCompleter(make<_ErrorImageCompleterCls>());
        }
        stream->completer()!->reportError(exception, stack, make<ErrorDescriptionCls>(__s("while resolving an image")), true, collector);
    });
    return stream;
}

template<typename T>
ImageStream ImageProviderCls<T>::createStream(ImageConfiguration configuration) {
    return make<ImageStreamCls>();
}

template<typename T>
Future<ImageCacheStatus> ImageProviderCls<T>::obtainCacheStatus(ImageConfiguration configuration, ImageErrorListener handleError) {
    assert(configuration != nullptr);
    Completer<ImageCacheStatus> completer = <ImageCacheStatus>make<CompleterCls>();
    _createErrorHandlerAndKey(configuration, [=] (T key,ImageErrorListener innerHandleError) {
        completer->complete(PaintingBindingCls::instance->imageCache->statusForKey(key));
    }, [=] (T key,Object exception,StackTrace stack) {
        if (handleError != nullptr) {
            handleError(exception, stack);
        } else {
            InformationCollector collector;
            assert([=] () {
                collector = [=] () {
                    makeList(ArrayItem, ArrayItem, ArrayItem);
                };
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<ErrorDescriptionCls>(__s("while checking the cache location of an image")), collector, exception, stack));
            completer->complete(nullptr);
        }
    });
    return completer->future();
}

template<typename T>
void ImageProviderCls<T>::resolveStreamForKey(ImageConfiguration configuration, ImageStream stream, T key, ImageErrorListener handleError) {
    if (stream->completer() != nullptr) {
        ImageStreamCompleter completer = PaintingBindingCls::instance->imageCache->putIfAbsent(key, [=] () {
    stream->completer()!;
}, handleError);
        assert(identical(completer, stream->completer));
        return;
    }
    ImageStreamCompleter completer = PaintingBindingCls::instance->imageCache->putIfAbsent(key, [=] () {
    loadBuffer(key, PaintingBindingCls::instance->instantiateImageCodecFromBuffer);
}, handleError);
    if (completer != nullptr) {
        stream->setCompleter(completer);
    }
}

template<typename T>
Future<bool> ImageProviderCls<T>::evict(ImageCache cache, ImageConfiguration configuration) {
    cache |= imageCache;
    T key = await obtainKey(configuration);
    return cache->evict(key);
}

template<typename T>
ImageStreamCompleter ImageProviderCls<T>::load(T key, DecoderCallback decode) {
    throw make<UnsupportedErrorCls>(__s("Implement loadBuffer for faster image loading"));
}

template<typename T>
ImageStreamCompleter ImageProviderCls<T>::loadBuffer(T key, DecoderBufferCallback decode) {
    return load(key, PaintingBindingCls::instance->instantiateImageCodec);
}

template<typename T>
String ImageProviderCls<T>::toString() {
    return __sf("%s()", objectRuntimeType(this, __s("ImageConfiguration")));
}

template<typename T>
void ImageProviderCls<T>::_createErrorHandlerAndKey(ImageConfiguration configuration, _KeyAndErrorHandlerCallback<T> successCallback, _AsyncKeyErrorHandler<T> errorCallback) {
    T obtainedKey;
    bool didError = false;
    InlineMethod;
    Future<T> key;
    try {
        key = obtainKey(configuration);
    } catch (Unknown error) {
        handleError(error, stackTrace);
        return;
    };
    key-><void>then([=] (T key) {
        obtainedKey = key;
        try {
            successCallback(key, handleError);
        } catch (Unknown error) {
            handleError(error, stackTrace);
        };
    })->catchError(handleError);
}

AssetBundleImageKeyCls::AssetBundleImageKeyCls(AssetBundle bundle, String name, double scale) {
    {
        assert(bundle != nullptr);
        assert(name != nullptr);
        assert(scale != nullptr);
    }
}

bool AssetBundleImageKeyCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<AssetBundleImageKey>(other) && other->bundle == bundle && other->name == name && other->scale == scale;
}

int AssetBundleImageKeyCls::hashCode() {
    return ObjectCls->hash(bundle, name, scale);
}

String AssetBundleImageKeyCls::toString() {
    return __sf("%s(bundle: %s, name: "%s", scale: %s)", objectRuntimeType(this, __s("AssetBundleImageKey")), bundle, name, scale);
}

ImageStreamCompleter AssetBundleImageProviderCls::loadBuffer(AssetBundleImageKey key, DecoderBufferCallback decode) {
    InformationCollector collector;
    assert([=] () {
        collector = [=] () {
            makeList(ArrayItem, ArrayItem);
        };
        return true;
    }());
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(key, decode, nullptr), key->scale, key->name, collector);
}

ImageStreamCompleter AssetBundleImageProviderCls::load(AssetBundleImageKey key, DecoderCallback decode) {
    InformationCollector collector;
    assert([=] () {
        collector = [=] () {
            makeList(ArrayItem, ArrayItem);
        };
        return true;
    }());
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(key, nullptr, decode), key->scale, key->name, collector);
}

Future<Codec> AssetBundleImageProviderCls::_loadAsync(AssetBundleImageKey key, DecoderBufferCallback decode, DecoderCallback decodeDepreacted) {
    if (decode != nullptr) {
        ImmutableBuffer buffer;
        try {
            buffer = await key->bundle->loadBuffer(key->name);
        } catch (FlutterError null) {
            PaintingBindingCls::instance->imageCache->evict(key);
            throw;
        };
        if (buffer == nullptr) {
            PaintingBindingCls::instance->imageCache->evict(key);
            throw make<StateErrorCls>(__s("Unable to read data"));
        }
        return decode(buffer);
    }
    ByteData data;
    try {
        data = await key->bundle->load(key->name);
    } catch (FlutterError null) {
        PaintingBindingCls::instance->imageCache->evict(key);
        throw;
    };
    if (data == nullptr) {
        PaintingBindingCls::instance->imageCache->evict(key);
        throw make<StateErrorCls>(__s("Unable to read data"));
    }
    return decodeDepreacted!(data->buffer()->asUint8List());
}

bool ResizeImageKeyCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ResizeImageKey>(other) && other->_providerCacheKey == _providerCacheKey && other->_width == _width && other->_height == _height;
}

int ResizeImageKeyCls::hashCode() {
    return ObjectCls->hash(_providerCacheKey, _width, _height);
}

ResizeImageCls::ResizeImageCls(ImageProvider<any> imageProvider, bool allowUpscaling, int height, int width) {
    {
        assert(width != nullptr || height != nullptr);
        assert(allowUpscaling != nullptr);
    }
}

ImageProvider<Object> ResizeImageCls::resizeIfNeeded(int cacheWidth, int cacheHeight, ImageProvider<Object> provider) {
    if (cacheWidth != nullptr || cacheHeight != nullptr) {
        return make<ResizeImageCls>(provider, cacheWidth, cacheHeight);
    }
    return provider;
}

ImageStreamCompleter ResizeImageCls::load(ResizeImageKey key, DecoderCallback decode) {
    InlineMethod;
    ImageStreamCompleter completer = imageProvider->load(key->_providerCacheKey, decodeResize);
    if (!kReleaseMode) {
        completer->debugLabel = __sf("%s - Resized(%s×%s)", completer->debugLabel, key->_width, key->_height);
    }
    return completer;
}

ImageStreamCompleter ResizeImageCls::loadBuffer(ResizeImageKey key, DecoderBufferCallback decode) {
    InlineMethod;
    ImageStreamCompleter completer = imageProvider->loadBuffer(key->_providerCacheKey, decodeResize);
    if (!kReleaseMode) {
        completer->debugLabel = __sf("%s - Resized(%s×%s)", completer->debugLabel, key->_width, key->_height);
    }
    return completer;
}

Future<ResizeImageKey> ResizeImageCls::obtainKey(ImageConfiguration configuration) {
    Completer<ResizeImageKey> completer;
    SynchronousFuture<ResizeImageKey> result;
    imageProvider->obtainKey(configuration)->then([=] (Object key) {
        if (completer == nullptr) {
            result = <ResizeImageKey>make<SynchronousFutureCls>(ResizeImageKeyCls->_(key, width, height));
        } else {
            completer->complete(ResizeImageKeyCls->_(key, width, height));
        }
    });
    if (result != nullptr) {
        return result!;
    }
    completer = <ResizeImageKey>make<CompleterCls>();
    return completer->future();
}

FileImageCls::FileImageCls(File file, double scale) {
    {
        assert(file != nullptr);
        assert(scale != nullptr);
    }
}

Future<FileImage> FileImageCls::obtainKey(ImageConfiguration configuration) {
    return <FileImage>make<SynchronousFutureCls>(this);
}

ImageStreamCompleter FileImageCls::load(FileImage key, DecoderCallback decode) {
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(key, nullptr, decode), key->scale, key->file->path(), [=] () {
        makeList(ArrayItem);
    });
}

ImageStreamCompleter FileImageCls::loadBuffer(FileImage key, DecoderBufferCallback decode) {
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(key, decode, nullptr), key->scale, key->file->path(), [=] () {
        makeList(ArrayItem);
    });
}

bool FileImageCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<FileImage>(other) && other->file->path() == file->path() && other->scale == scale;
}

int FileImageCls::hashCode() {
    return ObjectCls->hash(file->path(), scale);
}

String FileImageCls::toString() {
    return __sf("%s("%s", scale: %s)", objectRuntimeType(this, __s("FileImage")), file->path(), scale);
}

Future<Codec> FileImageCls::_loadAsync(FileImage key, DecoderBufferCallback decode, DecoderCallback decodeDeprecated) {
    assert(key == this);
    Uint8List bytes = await file->readAsBytes();
    if (bytes->lengthInBytes == 0) {
        PaintingBindingCls::instance->imageCache->evict(key);
        throw make<StateErrorCls>(__sf("%s is empty and cannot be loaded as an image.", file));
    }
    if (decode != nullptr) {
        return decode(await ui->ImmutableBufferCls->fromUint8List(bytes));
    }
    return decodeDeprecated!(bytes);
}

MemoryImageCls::MemoryImageCls(Uint8List bytes, double scale) {
    {
        assert(bytes != nullptr);
        assert(scale != nullptr);
    }
}

Future<MemoryImage> MemoryImageCls::obtainKey(ImageConfiguration configuration) {
    return <MemoryImage>make<SynchronousFutureCls>(this);
}

ImageStreamCompleter MemoryImageCls::load(MemoryImage key, DecoderCallback decode) {
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(key, nullptr, decode), key->scale, __sf("MemoryImage(%s)", describeIdentity(key->bytes)));
}

ImageStreamCompleter MemoryImageCls::loadBuffer(MemoryImage key, DecoderBufferCallback decode) {
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(key, decode, nullptr), key->scale, __sf("MemoryImage(%s)", describeIdentity(key->bytes)));
}

bool MemoryImageCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<MemoryImage>(other) && other->bytes == bytes && other->scale == scale;
}

int MemoryImageCls::hashCode() {
    return ObjectCls->hash(bytes->hashCode, scale);
}

String MemoryImageCls::toString() {
    return __sf("%s(%s, scale: %s)", objectRuntimeType(this, __s("MemoryImage")), describeIdentity(bytes), scale);
}

Future<Codec> MemoryImageCls::_loadAsync(MemoryImage key, DecoderBufferCallback decode, DecoderCallback decodeDepreacted) {
    assert(key == this);
    if (decode != nullptr) {
        ImmutableBuffer buffer = await ui->ImmutableBufferCls->fromUint8List(bytes);
        return decode(buffer);
    }
    return decodeDepreacted!(bytes);
}

ExactAssetImageCls::ExactAssetImageCls(String assetName, AssetBundle bundle, String package, double scale) {
    {
        assert(assetName != nullptr);
        assert(scale != nullptr);
    }
}

String ExactAssetImageCls::keyName() {
    return package == nullptr? assetName : __sf("packages/%s/%s", package, assetName);
}

Future<AssetBundleImageKey> ExactAssetImageCls::obtainKey(ImageConfiguration configuration) {
    return <AssetBundleImageKey>make<SynchronousFutureCls>(make<AssetBundleImageKeyCls>(bundle | configuration->bundle | rootBundle, keyName(), scale));
}

bool ExactAssetImageCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ExactAssetImage>(other) && other->keyName == keyName() && other->scale == scale && other->bundle == bundle;
}

int ExactAssetImageCls::hashCode() {
    return ObjectCls->hash(keyName(), scale, bundle);
}

String ExactAssetImageCls::toString() {
    return __sf("%s(name: "%s", scale: %s, bundle: %s)", objectRuntimeType(this, __s("ExactAssetImage")), keyName(), scale, bundle);
}

NetworkImageLoadExceptionCls::NetworkImageLoadExceptionCls(int statusCode, Uri uri) {
    {
        assert(uri != nullptr);
        assert(statusCode != nullptr);
        _message = __sf("HTTP request failed, statusCode: %s, %s", statusCode, uri);
    }
}

String NetworkImageLoadExceptionCls::toString() {
    return _message;
}
