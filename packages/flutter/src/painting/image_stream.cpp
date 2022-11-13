#include "image_stream.hpp"
ImageInfoCls::ImageInfoCls(String debugLabel, Image image, double scale) {
    {
        assert(image != nullptr);
        assert(scale != nullptr);
    }
}

ImageInfo ImageInfoCls::clone() {
    return make<ImageInfoCls>(image->clone(), scale, debugLabel);
}

bool ImageInfoCls::isCloneOf(ImageInfo other) {
    return other->image->isCloneOf(image) && scale == scale && other->debugLabel == debugLabel;
}

int ImageInfoCls::sizeBytes() {
    return image->height * image->width * 4;
}

void ImageInfoCls::dispose() {
    assert((image->debugGetOpenHandleStackTraces()?->length | 1) > 0);
    image->dispose();
}

String ImageInfoCls::toString() {
    return __sf("%s", debugLabel != nullptr? __sf("%s ", debugLabel) : __sf("%s @ %sx", image, debugFormatDouble(scale)));
}

int ImageInfoCls::hashCode() {
    return ObjectCls->hash(image, scale, debugLabel);
}

bool ImageInfoCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ImageInfo>(other) && other->image == image && other->scale == scale && other->debugLabel == debugLabel;
}

ImageStreamListenerCls::ImageStreamListenerCls(ImageListener onImage, ImageChunkListener onChunk, ImageErrorListener onError) {
    {
        assert(onImage != nullptr);
    }
}

int ImageStreamListenerCls::hashCode() {
    return ObjectCls->hash(onImage, onChunk, onError);
}

bool ImageStreamListenerCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ImageStreamListener>(other) && other->onImage == onImage && other->onChunk == onChunk && other->onError == onError;
}

ImageChunkEventCls::ImageChunkEventCls(int cumulativeBytesLoaded, int expectedTotalBytes) {
    {
        assert(cumulativeBytesLoaded >= 0);
        assert(expectedTotalBytes == nullptr || expectedTotalBytes >= 0);
    }
}

void ImageChunkEventCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("cumulativeBytesLoaded"), cumulativeBytesLoaded));
    properties->add(make<IntPropertyCls>(__s("expectedTotalBytes"), expectedTotalBytes));
}

ImageStreamCompleter ImageStreamCls::completer() {
    return _completer;
}

void ImageStreamCls::setCompleter(ImageStreamCompleter value) {
    assert(_completer == nullptr);
    _completer = value;
    if (_listeners != nullptr) {
        List<ImageStreamListener> initialListeners = _listeners!;
        _listeners = nullptr;
        _completer!->_addingInitialListeners = true;
        initialListeners->forEach(_completer!->addListener);
        _completer!->_addingInitialListeners = false;
    }
}

void ImageStreamCls::addListener(ImageStreamListener listener) {
    if (_completer != nullptr) {
        return _completer!->addListener(listener);
    }
    _listeners |= makeList();
    _listeners!->add(listener);
}

void ImageStreamCls::removeListener(ImageStreamListener listener) {
    if (_completer != nullptr) {
        return _completer!->removeListener(listener);
    }
    assert(_listeners != nullptr);
    for (;  < _listeners!->length(); i += 1) {
        if (_listeners![i] == listener) {
            _listeners!->removeAt(i);
            break;
        }
    }
}

Object ImageStreamCls::key() {
    return _completer | this;
}

void ImageStreamCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ImageStreamCompleter>make<ObjectFlagPropertyCls>(__s("completer"), _completer, _completer?->toStringShort(), __s("unresolved")));
    properties->add(<List<ImageStreamListener>>make<ObjectFlagPropertyCls>(__s("listeners"), _listeners, __sf("%s listener%s", _listeners?->length(), _listeners?->length() == 1? __s("") : __s("s")), __s("no listeners"), _completer != nullptr? DiagnosticLevelCls::hidden : DiagnosticLevelCls::info));
    _completer?->debugFillProperties(properties);
}

void ImageStreamCompleterHandleCls::dispose() {
    assert(_completer != nullptr);
    assert(_completer!->_keepAliveHandles > 0);
    assert(!_completer!->_disposed);
    _completer!->_keepAliveHandles -= 1;
    _completer!->_maybeDispose();
    _completer = nullptr;
}

void ImageStreamCompleterHandleCls::_(ImageStreamCompleter _completer) {
    _completer!->_keepAliveHandles += 1;
}

bool ImageStreamCompleterCls::hasListeners() {
    return _listeners->isNotEmpty();
}

void ImageStreamCompleterCls::addListener(ImageStreamListener listener) {
    _checkDisposed();
    _hadAtLeastOneListener = true;
    _listeners->add(listener);
    if (_currentImage != nullptr) {
        try {
            listener->onImage(_currentImage!->clone(), !_addingInitialListeners);
        } catch (Unknown exception) {
            reportError(make<ErrorDescriptionCls>(__s("by a synchronously-called image listener")), exception, stack);
        };
    }
    if (_currentError != nullptr && listener->onError != nullptr) {
        try {
            listener->onError!(_currentError!->exception, _currentError!->stack);
        } catch (Unknown newException) {
            if (newException != _currentError!->exception) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(newException, __s("image resource service"), make<ErrorDescriptionCls>(__s("by a synchronously-called image error listener")), newStack));
            }
        };
    }
}

ImageStreamCompleterHandle ImageStreamCompleterCls::keepAlive() {
    _checkDisposed();
    return ImageStreamCompleterHandleCls->_(this);
}

void ImageStreamCompleterCls::removeListener(ImageStreamListener listener) {
    _checkDisposed();
    for (;  < _listeners->length(); i += 1) {
        if (_listeners[i] == listener) {
            _listeners->removeAt(i);
            break;
        }
    }
    if (_listeners->isEmpty()) {
        List<VoidCallback> callbacks = _onLastListenerRemovedCallbacks->toList();
        for (VoidCallback callback : callbacks) {
            callback();
        }
        _onLastListenerRemovedCallbacks->clear();
        _maybeDispose();
    }
}

void ImageStreamCompleterCls::addOnLastListenerRemovedCallback(VoidCallback callback) {
    assert(callback != nullptr);
    _checkDisposed();
    _onLastListenerRemovedCallbacks->add(callback);
}

void ImageStreamCompleterCls::removeOnLastListenerRemovedCallback(VoidCallback callback) {
    assert(callback != nullptr);
    _checkDisposed();
    _onLastListenerRemovedCallbacks->remove(callback);
}

void ImageStreamCompleterCls::setImage(ImageInfo image) {
    _checkDisposed();
    _currentImage?->dispose();
    _currentImage = image;
    if (_listeners->isEmpty()) {
        return;
    }
    List<ImageStreamListener> localListeners = <ImageStreamListener>of(_listeners);
    for (ImageStreamListener listener : localListeners) {
        try {
            listener->onImage(image->clone(), false);
        } catch (Unknown exception) {
            reportError(make<ErrorDescriptionCls>(__s("by an image listener")), exception, stack);
        };
    }
}

void ImageStreamCompleterCls::reportError(DiagnosticsNode context, Object exception, InformationCollector informationCollector, bool silent, StackTrace stack) {
    _currentError = make<FlutterErrorDetailsCls>(exception, stack, __s("image resource service"), context, informationCollector, silent);
    List<ImageErrorListener> localErrorListeners = _listeners-><ImageErrorListener>map([=] (ImageStreamListener listener) {
    listener->onError;
})-><ImageErrorListener>whereType()->toList();
    bool handled = false;
    for (ImageErrorListener errorListener : localErrorListeners) {
        try {
            errorListener(exception, stack);
            handled = true;
        } catch (Unknown newException) {
            if (newException != exception) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<ErrorDescriptionCls>(__s("when reporting an error to an image listener")), __s("image resource service"), newException, newStack));
            }
        };
    }
    if (!handled) {
        FlutterErrorCls->reportError(_currentError!);
    }
}

void ImageStreamCompleterCls::reportImageChunkEvent(ImageChunkEvent event) {
    _checkDisposed();
    if (hasListeners()) {
        List<ImageChunkListener> localListeners = _listeners-><ImageChunkListener>map([=] (ImageStreamListener listener) {
    listener->onChunk;
})-><ImageChunkListener>whereType()->toList();
        for (ImageChunkListener listener : localListeners) {
            listener(event);
        }
    }
}

void ImageStreamCompleterCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<ImageInfo>make<DiagnosticsPropertyCls>(__s("current"), _currentImage, __s("unresolved"), false));
    description->add(<List<ImageStreamListener>>make<ObjectFlagPropertyCls>(__s("listeners"), _listeners, __sf("%s listener%s", _listeners->length(), _listeners->length() == 1? __s("") : __s("s"))));
    description->add(make<FlagPropertyCls>(__s("disposed"), _disposed, __s("<disposed>")));
}

void ImageStreamCompleterCls::_maybeDispose() {
    if (!_hadAtLeastOneListener || _disposed || _listeners->isNotEmpty() || _keepAliveHandles != 0) {
        return;
    }
    _currentImage?->dispose();
    _currentImage = nullptr;
    _disposed = true;
}

void ImageStreamCompleterCls::_checkDisposed() {
    if (_disposed) {
        throw make<StateErrorCls>(__s("Stream has been disposed.\nAn ImageStream is considered disposed once at least one listener has been added and subsequently all listeners have been removed and no handles are outstanding from the keepAlive method.\nTo resolve this error, maintain at least one listener on the stream, or create an ImageStreamCompleterHandle from the keepAlive method, or create a new stream for the image."));
    }
}

OneFrameImageStreamCompleterCls::OneFrameImageStreamCompleterCls(Future<ImageInfo> image, InformationCollector informationCollector) {
    {
        assert(image != nullptr);
    }
    {
        image-><void>then(setImage, [=] (Object error,StackTrace stack) {
            reportError(make<ErrorDescriptionCls>(__s("resolving a single-frame image stream")), error, stack, informationCollector, true);
        });
    }
}

MultiFrameImageStreamCompleterCls::MultiFrameImageStreamCompleterCls(Stream<ImageChunkEvent> chunkEvents, Future<Codec> codec, String debugLabel, InformationCollector informationCollector, double scale) {
    {
        assert(codec != nullptr);
        _informationCollector = informationCollector;
        _scale = scale;
    }
    {
        this->debugLabel = debugLabel;
        codec-><void>then(_handleCodecReady, [=] (Object error,StackTrace stack) {
            reportError(make<ErrorDescriptionCls>(__s("resolving an image codec")), error, stack, informationCollector, true);
        });
        if (chunkEvents != nullptr) {
            _chunkSubscription = chunkEvents->listen(reportImageChunkEvent, [=] (Object error,StackTrace stack) {
                reportError(make<ErrorDescriptionCls>(__s("loading an image")), error, stack, informationCollector, true);
            });
        }
    }
}

void MultiFrameImageStreamCompleterCls::addListener(ImageStreamListener listener) {
    if (!hasListeners() && _codec != nullptr && (_currentImage == nullptr || _codec!->frameCount() > 1)) {
        _decodeNextFrameAndSchedule();
    }
    super->addListener(listener);
}

void MultiFrameImageStreamCompleterCls::removeListener(ImageStreamListener listener) {
    super->removeListener(listener);
    if (!hasListeners()) {
        _timer?->cancel();
        _timer = nullptr;
    }
}

void MultiFrameImageStreamCompleterCls::_handleCodecReady(Codec codec) {
    _codec = codec;
    assert(_codec != nullptr);
    if (hasListeners()) {
        _decodeNextFrameAndSchedule();
    }
}

void MultiFrameImageStreamCompleterCls::_handleAppFrame(Duration timestamp) {
    _frameCallbackScheduled = false;
    if (!hasListeners()) {
        return;
    }
    assert(_nextFrame != nullptr);
    if (_isFirstFrame() || _hasFrameDurationPassed(timestamp)) {
        _emitFrame(make<ImageInfoCls>(_nextFrame!->image->clone(), _scale, debugLabel));
        _shownTimestamp = timestamp;
        _frameDuration = _nextFrame!->duration;
        _nextFrame!->image->dispose();
        _nextFrame = nullptr;
        int completedCycles = _framesEmitted ~/ _codec!->frameCount();
        if (_codec!->repetitionCount() == -1 || completedCycles <= _codec!->repetitionCount()) {
            _decodeNextFrameAndSchedule();
        }
        return;
    }
    Duration delay = _frameDuration! - (timestamp - _shownTimestamp);
    _timer = make<TimerCls>(delay * timeDilation, [=] () {
        _scheduleAppFrame();
    });
}

bool MultiFrameImageStreamCompleterCls::_isFirstFrame() {
    return _frameDuration == nullptr;
}

bool MultiFrameImageStreamCompleterCls::_hasFrameDurationPassed(Duration timestamp) {
    return timestamp - _shownTimestamp >= _frameDuration!;
}

Future<void> MultiFrameImageStreamCompleterCls::_decodeNextFrameAndSchedule() {
    _nextFrame?->image->dispose();
    _nextFrame = nullptr;
    try {
        _nextFrame = await _codec!->getNextFrame();
    } catch (Unknown exception) {
        reportError(make<ErrorDescriptionCls>(__s("resolving an image frame")), exception, stack, _informationCollector, true);
        return;
    };
    if (_codec!->frameCount() == 1) {
        if (!hasListeners()) {
            return;
        }
        _emitFrame(make<ImageInfoCls>(_nextFrame!->image->clone(), _scale, debugLabel));
        _nextFrame!->image->dispose();
        _nextFrame = nullptr;
        return;
    }
    _scheduleAppFrame();
}

void MultiFrameImageStreamCompleterCls::_scheduleAppFrame() {
    if (_frameCallbackScheduled) {
        return;
    }
    _frameCallbackScheduled = true;
    SchedulerBindingCls::instance->scheduleFrameCallback(_handleAppFrame);
}

void MultiFrameImageStreamCompleterCls::_emitFrame(ImageInfo imageInfo) {
    setImage(imageInfo);
    _framesEmitted += 1;
}

void MultiFrameImageStreamCompleterCls::_maybeDispose() {
    super->_maybeDispose();
    if (_disposed) {
        _chunkSubscription?->onData(nullptr);
        _chunkSubscription?->cancel();
        _chunkSubscription = nullptr;
    }
}
