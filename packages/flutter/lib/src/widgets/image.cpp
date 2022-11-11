#include "image.hpp"
ImageConfiguration createLocalImageConfiguration(BuildContext context, Size size) {
    return make<ImageConfigurationCls>(DefaultAssetBundleCls->of(context), MediaQueryCls->maybeOf(context)?->devicePixelRatio or 1.0, LocalizationsCls->maybeLocaleOf(context), DirectionalityCls->maybeOf(context), size, defaultTargetPlatform);
}

Future<void> precacheImage(BuildContext context, ImageErrorListener onError, ImageProvider provider, Size size) {
    ImageConfiguration config = createLocalImageConfiguration(contextsize);
    Completer<void> completer = <void>make<CompleterCls>();
    ImageStream stream = provider->resolve(config);
    ImageStreamListener listener;
    listener = make<ImageStreamListenerCls>([=] (ImageInfo image,bool sync) {
        if (!completer->isCompleted) {
            completer->complete();
        }
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
            stream->removeListener(listener!);
        });
    }[=] (Object exception,StackTrace stackTrace) {
        if (!completer->isCompleted) {
            completer->complete();
        }
        stream->removeListener(listener!);
        if (onError != nullptr) {
            onError(exception, stackTrace);
        } else {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<ErrorDescriptionCls>(__s("image failed to precache")), __s("image resource service"), exception, stackTrace, true));
        }
    });
    stream->addListener(listener);
    return completer->future;
}

ImageCls::ImageCls(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, ImageProvider image, bool isAntiAlias, Unknown key, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, String semanticLabel, double width) {
    {
        assert(image != nullptr);
        assert(alignment != nullptr);
        assert(repeat != nullptr);
        assert(filterQuality != nullptr);
        assert(matchTextDirection != nullptr);
        assert(isAntiAlias != nullptr);
    }
}

void ImageCls::network(AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, Map<String, String> headers, double height, bool isAntiAlias, Unknown key, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, String src, double width)

void ImageCls::file(AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, File file, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown key, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width)

void ImageCls::asset(AlignmentGeometry alignment, AssetBundle bundle, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown key, bool matchTextDirection, String name, Animation<double> opacity, String package, ImageRepeat repeat, double scale, String semanticLabel, double width)

void ImageCls::memory(AlignmentGeometry alignment, Uint8List bytes, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown key, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width)

State<Image> ImageCls::createState() {
    return make<_ImageStateCls>();
}

void ImageCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ImageProvider>make<DiagnosticsPropertyCls>(__s("image"), image));
    properties->add(<std::function<void ()>>make<DiagnosticsPropertyCls>(__s("frameBuilder"), frameBuilder));
    properties->add(<std::function<void ()>>make<DiagnosticsPropertyCls>(__s("loadingBuilder"), loadingBuilder));
    properties->add(make<DoublePropertyCls>(__s("width"), widthnullptr));
    properties->add(make<DoublePropertyCls>(__s("height"), heightnullptr));
    properties->add(make<ColorPropertyCls>(__s("color"), colornullptr));
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("opacity"), opacitynullptr));
    properties->add(<BlendMode>make<EnumPropertyCls>(__s("colorBlendMode"), colorBlendModenullptr));
    properties->add(<BoxFit>make<EnumPropertyCls>(__s("fit"), fitnullptr));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignmentnullptr));
    properties->add(<ImageRepeat>make<EnumPropertyCls>(__s("repeat"), repeatImageRepeatCls::noRepeat));
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("centerSlice"), centerSlicenullptr));
    properties->add(make<FlagPropertyCls>(__s("matchTextDirection")matchTextDirection, __s("match text direction")));
    properties->add(make<StringPropertyCls>(__s("semanticLabel"), semanticLabelnullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("this.excludeFromSemantics"), excludeFromSemantics));
    properties->add(<FilterQuality>make<EnumPropertyCls>(__s("filterQuality"), filterQuality));
}

void _ImageStateCls::initState() {
    super->initState();
    WidgetsBindingCls::instance->addObserver(this);
    _scrollAwareContext = <State<Image>>make<DisposableBuildContextCls>(this);
}

void _ImageStateCls::dispose() {
    assert(_imageStream != nullptr);
    WidgetsBindingCls::instance->removeObserver(this);
    _stopListeningToStream();
    _completerHandle?->dispose();
    _scrollAwareContext->dispose();
    _replaceImage(nullptr);
    super->dispose();
}

void _ImageStateCls::didChangeDependencies() {
    _updateInvertColors();
    _resolveImage();
    if (TickerModeCls->of(context)) {
        _listenToStream();
    } else {
        _stopListeningToStream(true);
    }
    super->didChangeDependencies();
}

void _ImageStateCls::didUpdateWidget(Image oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (_isListeningToStream && (widget->loadingBuilder == nullptr) != (oldWidget->loadingBuilder == nullptr)) {
        ImageStreamListener oldListener = _getListener();
        _imageStream!->addListener(_getListener(true));
        _imageStream!->removeListener(oldListener);
    }
    if (widget->image != oldWidget->image) {
        _resolveImage();
    }
}

void _ImageStateCls::didChangeAccessibilityFeatures() {
    super->didChangeAccessibilityFeatures();
    setState([=] () {
        _updateInvertColors();
    });
}

void _ImageStateCls::reassemble() {
    _resolveImage();
    super->reassemble();
}

Widget _ImageStateCls::build(BuildContext context) {
    if (_lastException != nullptr) {
        if (widget->errorBuilder != nullptr) {
            return widget->errorBuilder!(context, _lastException!, _lastStack);
        }
        if (kDebugMode) {
            return _debugBuildErrorWidget(context, _lastException!);
        }
    }
    Widget result = make<RawImageCls>(_imageInfo?->image, _imageInfo?->debugLabel, widget->width, widget->height, _imageInfo?->scale or 1.0, widget->color, widget->opacity, widget->colorBlendMode, widget->fit, widget->alignment, widget->repeat, widget->centerSlice, widget->matchTextDirection, _invertColors, widget->isAntiAlias, widget->filterQuality);
    if (!widget->excludeFromSemantics) {
        result = make<SemanticsCls>(widget->semanticLabel != nullptr, true, widget->semanticLabel or __s(""), result);
    }
    if (widget->frameBuilder != nullptr) {
        result = widget->frameBuilder!(context, result, _frameNumber, _wasSynchronouslyLoaded);
    }
    if (widget->loadingBuilder != nullptr) {
        result = widget->loadingBuilder!(context, result, _loadingProgress);
    }
    return result;
}

void _ImageStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<ImageStream>make<DiagnosticsPropertyCls>(__s("stream"), _imageStream));
    description->add(<ImageInfo>make<DiagnosticsPropertyCls>(__s("pixels"), _imageInfo));
    description->add(<ImageChunkEvent>make<DiagnosticsPropertyCls>(__s("loadingProgress"), _loadingProgress));
    description->add(<int>make<DiagnosticsPropertyCls>(__s("frameNumber"), _frameNumber));
    description->add(<bool>make<DiagnosticsPropertyCls>(__s("wasSynchronouslyLoaded"), _wasSynchronouslyLoaded));
}

void _ImageStateCls::_updateInvertColors() {
    _invertColors = MediaQueryCls->maybeOf(context)?->invertColors or SemanticsBindingCls::instance->accessibilityFeatures->invertColors;
}

void _ImageStateCls::_resolveImage() {
    ScrollAwareImageProvider provider = <Object>make<ScrollAwareImageProviderCls>(_scrollAwareContext, widget->image);
    ImageStream newStream = provider->resolve(createLocalImageConfiguration(contextwidget->width != nullptr && widget->height != nullptr? make<SizeCls>(widget->width!, widget->height!) : nullptr));
    assert(newStream != nullptr);
    _updateSourceStream(newStream);
}

ImageStreamListener _ImageStateCls::_getListener(bool recreateListener) {
    if (_imageStreamListener == nullptr || recreateListener) {
        _lastException = nullptr;
        _lastStack = nullptr;
        _imageStreamListener = make<ImageStreamListenerCls>(_handleImageFramewidget->loadingBuilder == nullptr? nullptr : _handleImageChunk, widget->errorBuilder != nullptr || kDebugMode? [=] (Object error,StackTrace stackTrace) {
            setState([=] () {
                _lastException = error;
                _lastStack = stackTrace;
            });
            assert([=] () {
                if (widget->errorBuilder == nullptr) {
                    ;
                }
                return true;
            }());
        } : nullptr);
    }
    return _imageStreamListener!;
}

void _ImageStateCls::_handleImageFrame(ImageInfo imageInfo, bool synchronousCall) {
    setState([=] () {
        _replaceImage(imageInfo);
        _loadingProgress = nullptr;
        _lastException = nullptr;
        _lastStack = nullptr;
        _frameNumber = _frameNumber == nullptr? 0 : _frameNumber! + 1;
        _wasSynchronouslyLoaded = _wasSynchronouslyLoaded | synchronousCall;
    });
}

void _ImageStateCls::_handleImageChunk(ImageChunkEvent event) {
    assert(widget->loadingBuilder != nullptr);
    setState([=] () {
        _loadingProgress = event;
        _lastException = nullptr;
        _lastStack = nullptr;
    });
}

void _ImageStateCls::_replaceImage(ImageInfo info) {
    _imageInfo?->dispose();
    _imageInfo = info;
}

void _ImageStateCls::_updateSourceStream(ImageStream newStream) {
    if (_imageStream?->key() == newStream->key()) {
        return;
    }
    if (_isListeningToStream) {
        _imageStream!->removeListener(_getListener());
    }
    if (!widget->gaplessPlayback) {
        setState([=] () {
            _replaceImage(nullptr);
        });
    }
    setState([=] () {
        _loadingProgress = nullptr;
        _frameNumber = nullptr;
        _wasSynchronouslyLoaded = false;
    });
    _imageStream = newStream;
    if (_isListeningToStream) {
        _imageStream!->addListener(_getListener());
    }
}

void _ImageStateCls::_listenToStream() {
    if (_isListeningToStream) {
        return;
    }
    _imageStream!->addListener(_getListener());
    _completerHandle?->dispose();
    _completerHandle = nullptr;
    _isListeningToStream = true;
}

void _ImageStateCls::_stopListeningToStream(bool keepStreamAlive) {
    if (!_isListeningToStream) {
        return;
    }
    if (keepStreamAlive && _completerHandle == nullptr && _imageStream?->completer != nullptr) {
        _completerHandle = _imageStream!->completer()!->keepAlive();
    }
    _imageStream!->removeListener(_getListener());
    _isListeningToStream = false;
}

Widget _ImageStateCls::_debugBuildErrorWidget(BuildContext context, Object error) {
    return make<StackCls>(AlignmentCls::center, makeList(ArrayItem, ArrayItem));
}
