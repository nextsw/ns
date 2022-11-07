#include "image.hpp"
ImageConfiguration createLocalImageConfiguration(BuildContext context, Size size) {
    return ImageConfiguration(DefaultAssetBundle.of(context), MediaQuery.maybeOf(context)?.devicePixelRatio ?? 1.0, Localizations.maybeLocaleOf(context), Directionality.maybeOf(context), size, defaultTargetPlatform);
}

Future<void> precacheImage(BuildContext context, ImageErrorListener onError, ImageProvider provider, Size size) {
    ImageConfiguration config = createLocalImageConfiguration(contextsize);
    Completer<void> completer = <void>Completer();
    ImageStream stream = provider.resolve(config);
    ImageStreamListener listener;
    listener = ImageStreamListener();
    stream.addListener(listener);
    return completer.future;
}

Image::Image(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, ImageProvider image, bool isAntiAlias, Unknown, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, String semanticLabel, double width) {
    {
        assert(image != nullptr);
        assert(alignment != nullptr);
        assert(repeat != nullptr);
        assert(filterQuality != nullptr);
        assert(matchTextDirection != nullptr);
        assert(isAntiAlias != nullptr);
    }
}

void Image::network(AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, Map<String, String> headers, double height, bool isAntiAlias, Unknown, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, String src, double width)

void Image::file(AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, File file, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width)

void Image::asset(AlignmentGeometry alignment, AssetBundle bundle, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown, bool matchTextDirection, String name, Animation<double> opacity, String package, ImageRepeat repeat, double scale, String semanticLabel, double width)

void Image::memory(AlignmentGeometry alignment, Uint8List bytes, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width)

State<Image> Image::createState() {
    return _ImageState();
}

void Image::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ImageProvider>DiagnosticsProperty("image", image));
    properties.add(<FunctionType>DiagnosticsProperty("frameBuilder", frameBuilder));
    properties.add(<FunctionType>DiagnosticsProperty("loadingBuilder", loadingBuilder));
    properties.add(DoubleProperty("width", widthnullptr));
    properties.add(DoubleProperty("height", heightnullptr));
    properties.add(ColorProperty("color", colornullptr));
    properties.add(<Animation<double>>DiagnosticsProperty("opacity", opacitynullptr));
    properties.add(<BlendMode>EnumProperty("colorBlendMode", colorBlendModenullptr));
    properties.add(<BoxFit>EnumProperty("fit", fitnullptr));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignmentnullptr));
    properties.add(<ImageRepeat>EnumProperty("repeat", repeatImageRepeat.noRepeat));
    properties.add(<Rect>DiagnosticsProperty("centerSlice", centerSlicenullptr));
    properties.add(FlagProperty("matchTextDirection"matchTextDirection, "match text direction"));
    properties.add(StringProperty("semanticLabel", semanticLabelnullptr));
    properties.add(<bool>DiagnosticsProperty("this.excludeFromSemantics", excludeFromSemantics));
    properties.add(<FilterQuality>EnumProperty("filterQuality", filterQuality));
}

void _ImageState::initState() {
    super.initState();
    WidgetsBinding.instance.addObserver(this);
    _scrollAwareContext = <State<Image>>DisposableBuildContext(this);
}

void _ImageState::dispose() {
    assert(_imageStream != nullptr);
    WidgetsBinding.instance.removeObserver(this);
    _stopListeningToStream();
    _completerHandle?.dispose();
    _scrollAwareContext.dispose();
    _replaceImage(nullptr);
    super.dispose();
}

void _ImageState::didChangeDependencies() {
    _updateInvertColors();
    _resolveImage();
    if (TickerMode.of(context)) {
        _listenToStream();
    } else {
        _stopListeningToStream(true);
    }
    super.didChangeDependencies();
}

void _ImageState::didUpdateWidget(Image oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (_isListeningToStream && (widget.loadingBuilder == nullptr) != (oldWidget.loadingBuilder == nullptr)) {
        ImageStreamListener oldListener = _getListener();
        _imageStream!.addListener(_getListener(true));
        _imageStream!.removeListener(oldListener);
    }
    if (widget.image != oldWidget.image) {
        _resolveImage();
    }
}

void _ImageState::didChangeAccessibilityFeatures() {
    super.didChangeAccessibilityFeatures();
    setState();
}

void _ImageState::reassemble() {
    _resolveImage();
    super.reassemble();
}

Widget _ImageState::build(BuildContext context) {
    if (_lastException != nullptr) {
        if (widget.errorBuilder != nullptr) {
            return widget.errorBuilder!(context, _lastException!, _lastStack);
        }
        if (kDebugMode) {
            return _debugBuildErrorWidget(context, _lastException!);
        }
    }
    Widget result = RawImage(_imageInfo?.image, _imageInfo?.debugLabel, widget.width, widget.height, _imageInfo?.scale ?? 1.0, widget.color, widget.opacity, widget.colorBlendMode, widget.fit, widget.alignment, widget.repeat, widget.centerSlice, widget.matchTextDirection, _invertColors, widget.isAntiAlias, widget.filterQuality);
    if (!widget.excludeFromSemantics) {
        result = Semantics(widget.semanticLabel != nullptr, true, widget.semanticLabel ?? "", result);
    }
    if (widget.frameBuilder != nullptr) {
        result = widget.frameBuilder!(context, result, _frameNumber, _wasSynchronouslyLoaded);
    }
    if (widget.loadingBuilder != nullptr) {
        result = widget.loadingBuilder!(context, result, _loadingProgress);
    }
    return result;
}

void _ImageState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<ImageStream>DiagnosticsProperty("stream", _imageStream));
    description.add(<ImageInfo>DiagnosticsProperty("pixels", _imageInfo));
    description.add(<ImageChunkEvent>DiagnosticsProperty("loadingProgress", _loadingProgress));
    description.add(<int>DiagnosticsProperty("frameNumber", _frameNumber));
    description.add(<bool>DiagnosticsProperty("wasSynchronouslyLoaded", _wasSynchronouslyLoaded));
}

void _ImageState::_updateInvertColors() {
    _invertColors = MediaQuery.maybeOf(context)?.invertColors ?? SemanticsBinding.instance.accessibilityFeatures.invertColors;
}

void _ImageState::_resolveImage() {
    ScrollAwareImageProvider provider = <Object>ScrollAwareImageProvider(_scrollAwareContext, widget.image);
    ImageStream newStream = provider.resolve(createLocalImageConfiguration(contextwidget.width != nullptr && widget.height != nullptr? Size(widget.width!, widget.height!) : nullptr));
    assert(newStream != nullptr);
    _updateSourceStream(newStream);
}

ImageStreamListener _ImageState::_getListener(bool recreateListener) {
    if (_imageStreamListener == nullptr || recreateListener) {
        _lastException = nullptr;
        _lastStack = nullptr;
        _imageStreamListener = ImageStreamListener(_handleImageFramewidget.loadingBuilder == nullptr? nullptr : _handleImageChunk, widget.errorBuilder != nullptr || kDebugMode?  : nullptr);
    }
    return _imageStreamListener!;
}

void _ImageState::_handleImageFrame(ImageInfo imageInfo, bool synchronousCall) {
    setState();
}

void _ImageState::_handleImageChunk(ImageChunkEvent event) {
    assert(widget.loadingBuilder != nullptr);
    setState();
}

void _ImageState::_replaceImage(ImageInfo info) {
    _imageInfo?.dispose();
    _imageInfo = info;
}

void _ImageState::_updateSourceStream(ImageStream newStream) {
    if (_imageStream?.key == newStream.key) {
        return;
    }
    if (_isListeningToStream) {
        _imageStream!.removeListener(_getListener());
    }
    if (!widget.gaplessPlayback) {
        setState();
    }
    setState();
    _imageStream = newStream;
    if (_isListeningToStream) {
        _imageStream!.addListener(_getListener());
    }
}

void _ImageState::_listenToStream() {
    if (_isListeningToStream) {
        return;
    }
    _imageStream!.addListener(_getListener());
    _completerHandle?.dispose();
    _completerHandle = nullptr;
    _isListeningToStream = true;
}

void _ImageState::_stopListeningToStream(bool keepStreamAlive) {
    if (!_isListeningToStream) {
        return;
    }
    if (keepStreamAlive && _completerHandle == nullptr && _imageStream?.completer != nullptr) {
        _completerHandle = _imageStream!.completer!.keepAlive();
    }
    _imageStream!.removeListener(_getListener());
    _isListeningToStream = false;
}

Widget _ImageState::_debugBuildErrorWidget(BuildContext context, Object error) {
    return Stack(Alignment.center, );
}
