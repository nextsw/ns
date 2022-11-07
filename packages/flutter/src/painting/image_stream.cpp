#include "image_stream.hpp"
ImageInfo::ImageInfo(String debugLabel, Image image, double scale) {
    {
        assert(image != nullptr);
        assert(scale != nullptr);
    }
}

ImageInfo ImageInfo::clone() {
    return ImageInfo(image.clone(), scale, debugLabel);
}

bool ImageInfo::isCloneOf(ImageInfo other) {
    return other.image.isCloneOf(image) && scale == scale && other.debugLabel == debugLabel;
}

int ImageInfo::sizeBytes() {
    return image.height * image.width * 4;
}

void ImageInfo::dispose() {
    assert((image.debugGetOpenHandleStackTraces()?.length ?? 1) > 0);
    image.dispose();
}

String ImageInfo::toString() {
    return "${debugLabel != null ? '$debugLabel ' : ''}$image @ ${debugFormatDouble(scale)}x";
}

int ImageInfo::hashCode() {
    return Object.hash(image, scale, debugLabel);
}

bool ImageInfo::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ImageInfo && other.image == image && other.scale == scale && other.debugLabel == debugLabel;
}

ImageStreamListener::ImageStreamListener(ImageChunkListener onChunk, ImageErrorListener onError, ImageListener onImage) {
    {
        assert(onImage != nullptr);
    }
}

int ImageStreamListener::hashCode() {
    return Object.hash(onImage, onChunk, onError);
}

bool ImageStreamListener::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ImageStreamListener && other.onImage == onImage && other.onChunk == onChunk && other.onError == onError;
}

ImageChunkEvent::ImageChunkEvent(int cumulativeBytesLoaded, int expectedTotalBytes) {
    {
        assert(cumulativeBytesLoaded >= 0);
        assert(expectedTotalBytes == nullptr || expectedTotalBytes >= 0);
    }
}

void ImageChunkEvent::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("cumulativeBytesLoaded", cumulativeBytesLoaded));
    properties.add(IntProperty("expectedTotalBytes", expectedTotalBytes));
}

ImageStreamCompleter ImageStream::completer() {
    return _completer;
}

void ImageStream::setCompleter(ImageStreamCompleter value) {
    assert(_completer == nullptr);
    _completer = value;
    if (_listeners != nullptr) {
        List<ImageStreamListener> initialListeners = _listeners!;
        _listeners = nullptr;
        _completer!._addingInitialListeners = true;
        initialListeners.forEach(_completer!.addListener);
        _completer!._addingInitialListeners = false;
    }
}

void ImageStream::addListener(ImageStreamListener listener) {
    if (_completer != nullptr) {
        return _completer!.addListener(listener);
    }
    _listeners = ;
    _listeners!.add(listener);
}

void ImageStream::removeListener(ImageStreamListener listener) {
    if (_completer != nullptr) {
        return _completer!.removeListener(listener);
    }
    assert(_listeners != nullptr);
    for (;  < _listeners!.length; i = 1) {
        if (_listeners![i] == listener) {
            _listeners!.removeAt(i);
                        break;
        }
    }
}

Object ImageStream::key() {
    return _completer ?? this;
}

void ImageStream::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ImageStreamCompleter>ObjectFlagProperty("completer", _completer_completer?.toStringShort(), "unresolved"));
    properties.add(<List<ImageStreamListener>>ObjectFlagProperty("listeners", _listeners"${_listeners?.length} listener${_listeners?.length == 1 ? "" : "s" }", "no listeners", _completer != nullptr? DiagnosticLevel.hidden : DiagnosticLevel.info));
    _completer?.debugFillProperties(properties);
}

void ImageStreamCompleterHandle::dispose() {
    assert(_completer != nullptr);
    assert(_completer!._keepAliveHandles > 0);
    assert(!_completer!._disposed);
    _completer!._keepAliveHandles = 1;
    _completer!._maybeDispose();
    _completer = nullptr;
}

void ImageStreamCompleterHandle::_(ImageStreamCompleter _completer) {
    _completer!._keepAliveHandles = 1;
}

bool ImageStreamCompleter::hasListeners() {
    return _listeners.isNotEmpty;
}

void ImageStreamCompleter::addListener(ImageStreamListener listener) {
    _checkDisposed();
    _hadAtLeastOneListener = true;
    _listeners.add(listener);
    if (_currentImage != nullptr) {
        ;
    }
    if (_currentError != nullptr && listener.onError != nullptr) {
        ;
    }
}

ImageStreamCompleterHandle ImageStreamCompleter::keepAlive() {
    _checkDisposed();
    return ImageStreamCompleterHandle._(this);
}

void ImageStreamCompleter::removeListener(ImageStreamListener listener) {
    _checkDisposed();
    for (;  < _listeners.length; i = 1) {
        if (_listeners[i] == listener) {
            _listeners.removeAt(i);
                        break;
        }
    }
    if (_listeners.isEmpty) {
        List<VoidCallback> callbacks = _onLastListenerRemovedCallbacks.toList();
        for (VoidCallback callback : callbacks) {
            callback();
        }
        _onLastListenerRemovedCallbacks.clear();
        _maybeDispose();
    }
}

void ImageStreamCompleter::addOnLastListenerRemovedCallback(VoidCallback callback) {
    assert(callback != nullptr);
    _checkDisposed();
    _onLastListenerRemovedCallbacks.add(callback);
}

void ImageStreamCompleter::removeOnLastListenerRemovedCallback(VoidCallback callback) {
    assert(callback != nullptr);
    _checkDisposed();
    _onLastListenerRemovedCallbacks.remove(callback);
}

void ImageStreamCompleter::setImage(ImageInfo image) {
    _checkDisposed();
    _currentImage?.dispose();
    _currentImage = image;
    if (_listeners.isEmpty) {
        return;
    }
    List<ImageStreamListener> localListeners = <ImageStreamListener>of(_listeners);
    for (ImageStreamListener listener : localListeners) {
        ;
    }
}

void ImageStreamCompleter::reportError(DiagnosticsNode context, Object exception, InformationCollector informationCollector, bool silent, StackTrace stack) {
    _currentError = FlutterErrorDetails(exception, stack, "image resource service", context, informationCollector, silent);
    List<ImageErrorListener> localErrorListeners = _listeners.<ImageErrorListener>map().<ImageErrorListener>whereType().toList();
    bool handled = false;
    for (ImageErrorListener errorListener : localErrorListeners) {
        ;
    }
    if (!handled) {
        FlutterError.reportError(_currentError!);
    }
}

void ImageStreamCompleter::reportImageChunkEvent(ImageChunkEvent event) {
    _checkDisposed();
    if (hasListeners) {
        List<ImageChunkListener> localListeners = _listeners.<ImageChunkListener>map().<ImageChunkListener>whereType().toList();
        for (ImageChunkListener listener : localListeners) {
            listener(event);
        }
    }
}

void ImageStreamCompleter::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<ImageInfo>DiagnosticsProperty("current", _currentImage"unresolved", false));
    description.add(<List<ImageStreamListener>>ObjectFlagProperty("listeners", _listeners"${_listeners.length} listener${_listeners.length == 1 ? "" : "s" }"));
    description.add(FlagProperty("disposed"_disposed, "<disposed>"));
}

void ImageStreamCompleter::_maybeDispose() {
    if (!_hadAtLeastOneListener || _disposed || _listeners.isNotEmpty || _keepAliveHandles != 0) {
        return;
    }
    _currentImage?.dispose();
    _currentImage = nullptr;
    _disposed = true;
}

void ImageStreamCompleter::_checkDisposed() {
    if (_disposed) {
        ;
    }
}

OneFrameImageStreamCompleter::OneFrameImageStreamCompleter(Future<ImageInfo> image, InformationCollector informationCollector) {
    {
        assert(image != nullptr);
    }
    {
        image.<void>then(setImage);
    }
}

MultiFrameImageStreamCompleter::MultiFrameImageStreamCompleter(Stream<ImageChunkEvent> chunkEvents, Future<Codec> codec, String debugLabel, InformationCollector informationCollector, double scale) {
    {
        assert(codec != nullptr);
        _informationCollector = informationCollector;
        _scale = scale;
    }
    {
        this.debugLabel = debugLabel;
        codec.<void>then(_handleCodecReady);
        if (chunkEvents != nullptr) {
            _chunkSubscription = chunkEvents.listen(reportImageChunkEvent);
        }
    }
}

void MultiFrameImageStreamCompleter::addListener(ImageStreamListener listener) {
    if (!hasListeners && _codec != nullptr && (_currentImage == nullptr || _codec!.frameCount > 1)) {
        _decodeNextFrameAndSchedule();
    }
    super.addListener(listener);
}

void MultiFrameImageStreamCompleter::removeListener(ImageStreamListener listener) {
    super.removeListener(listener);
    if (!hasListeners) {
        _timer?.cancel();
        _timer = nullptr;
    }
}

void MultiFrameImageStreamCompleter::_handleCodecReady(Codec codec) {
    _codec = codec;
    assert(_codec != nullptr);
    if (hasListeners) {
        _decodeNextFrameAndSchedule();
    }
}

void MultiFrameImageStreamCompleter::_handleAppFrame(Duration timestamp) {
    _frameCallbackScheduled = false;
    if (!hasListeners) {
        return;
    }
    assert(_nextFrame != nullptr);
    if (_isFirstFrame() || _hasFrameDurationPassed(timestamp)) {
        _emitFrame(ImageInfo(_nextFrame!.image.clone(), _scale, debugLabel));
        _shownTimestamp = timestamp;
        _frameDuration = _nextFrame!.duration;
        _nextFrame!.image.dispose();
        _nextFrame = nullptr;
        int completedCycles = _framesEmitted ~/ _codec!.frameCount;
        if (_codec!.repetitionCount == -1 || completedCycles <= _codec!.repetitionCount) {
            _decodeNextFrameAndSchedule();
        }
        return;
    }
    Duration delay = _frameDuration! - (timestamp - _shownTimestamp);
    _timer = Timer(delay * timeDilation, );
}

bool MultiFrameImageStreamCompleter::_isFirstFrame() {
    return _frameDuration == nullptr;
}

bool MultiFrameImageStreamCompleter::_hasFrameDurationPassed(Duration timestamp) {
    return timestamp - _shownTimestamp >= _frameDuration!;
}

Future<void> MultiFrameImageStreamCompleter::_decodeNextFrameAndSchedule() {
    _nextFrame?.image.dispose();
    _nextFrame = nullptr;
    ;
    if (_codec!.frameCount == 1) {
        if (!hasListeners) {
            return;
        }
        _emitFrame(ImageInfo(_nextFrame!.image.clone(), _scale, debugLabel));
        _nextFrame!.image.dispose();
        _nextFrame = nullptr;
        return;
    }
    _scheduleAppFrame();
}

void MultiFrameImageStreamCompleter::_scheduleAppFrame() {
    if (_frameCallbackScheduled) {
        return;
    }
    _frameCallbackScheduled = true;
    SchedulerBinding.instance.scheduleFrameCallback(_handleAppFrame);
}

void MultiFrameImageStreamCompleter::_emitFrame(ImageInfo imageInfo) {
    setImage(imageInfo);
    _framesEmitted = 1;
}

void MultiFrameImageStreamCompleter::_maybeDispose() {
    super._maybeDispose();
    if (_disposed) {
        _chunkSubscription?.onData(nullptr);
        _chunkSubscription?.cancel();
        _chunkSubscription = nullptr;
    }
}
