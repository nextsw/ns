#include "painting.hpp"
bool _rectIsValid(Rect rect) {
    assert(rect != nullptr, __s("Rect argument was null."));
    assert(!rect->hasNaN(), __s("Rect argument contained a NaN value."));
    return true;
}

bool _rrectIsValid(RRect rrect) {
    assert(rrect != nullptr, __s("RRect argument was null."));
    assert(!rrect->hasNaN(), __s("RRect argument contained a NaN value."));
    return true;
}

bool _offsetIsValid(Offset offset) {
    assert(offset != nullptr, __s("Offset argument was null."));
    assert(!offset->dx()->isNaN && !offset->dy()->isNaN, __s("Offset argument contained a NaN value."));
    return true;
}

bool _matrix4IsValid(Float64List matrix4) {
    assert(matrix4 != nullptr, __s("Matrix4 argument was null."));
    assert(matrix4->length == 16, __s("Matrix4 must have 16 entries."));
    assert(matrix4->every([=] (double value)     {
        value->isFinite;
    }), __s("Matrix4 entries must be finite."));
    return true;
}

bool _radiusIsValid(Radius radius) {
    assert(radius != nullptr, __s("Radius argument was null."));
    assert(!radius->x->isNaN && !radius->y->isNaN, __s("Radius argument contained a NaN value."));
    return true;
}

Color _scaleAlpha(Color a, double factor) {
    return a->withAlpha((a->alpha() * factor)->round()->clamp(0, 255));
}

ColorCls::ColorCls(int value) {
    {
        value = value & 0xFFFFFFFF;
    }
}

void ColorCls::fromARGB(int a, int b, int g, int r)

void ColorCls::fromRGBO(int b, int g, double opacity, int r)

int ColorCls::alpha() {
    return (0xff000000 & value) >> 24;
}

double ColorCls::opacity() {
    return alpha() / 0xFF;
}

int ColorCls::red() {
    return (0x00ff0000 & value) >> 16;
}

int ColorCls::green() {
    return (0x0000ff00 & value) >> 8;
}

int ColorCls::blue() {
    return (0x000000ff & value) >> 0;
}

Color ColorCls::withAlpha(int a) {
    return ColorCls->fromARGB(a, red(), green(), blue());
}

Color ColorCls::withOpacity(double opacity) {
    assert(opacity >= 0.0 && opacity <= 1.0);
    return withAlpha((255.0 * opacity)->round());
}

Color ColorCls::withRed(int r) {
    return ColorCls->fromARGB(alpha(), r, green(), blue());
}

Color ColorCls::withGreen(int g) {
    return ColorCls->fromARGB(alpha(), red(), g, blue());
}

Color ColorCls::withBlue(int b) {
    return ColorCls->fromARGB(alpha(), red(), green(), b);
}

double ColorCls::computeLuminance() {
    double R = _linearizeColorComponent(red() / 0xFF);
    double G = _linearizeColorComponent(green() / 0xFF);
    double B = _linearizeColorComponent(blue() / 0xFF);
    return 0.2126 * RCls + 0.7152 * GCls + 0.0722 * BCls;
}

Color ColorCls::lerp(Color a, Color b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            return _scaleAlpha(a, 1.0 - t);
        }
    } else {
        if (a == nullptr) {
            return _scaleAlpha(b, t);
        } else {
            return ColorCls->fromARGB(_clampInt(_lerpInt(a->alpha(), b->alpha(), t)->toInt(), 0, 255), _clampInt(_lerpInt(a->red(), b->red(), t)->toInt(), 0, 255), _clampInt(_lerpInt(a->green(), b->green(), t)->toInt(), 0, 255), _clampInt(_lerpInt(a->blue(), b->blue(), t)->toInt(), 0, 255));
        }
    }
}

Color ColorCls::alphaBlend(Color background, Color foreground) {
    int alpha = foreground->alpha();
    if (alpha == 0x00) {
        return background;
    }
    int invAlpha = 0xff - alpha;
    int backAlpha = background->alpha;
    if (backAlpha == 0xff) {
        return ColorCls->fromARGB(0xff, (alpha * foreground->red() + invAlpha * background->red()) ~/ 0xff, (alpha * foreground->green() + invAlpha * background->green()) ~/ 0xff, (alpha * foreground->blue() + invAlpha * background->blue()) ~/ 0xff);
    } else {
        backAlpha = (backAlpha * invAlpha) ~/ 0xff;
        int outAlpha = alpha + backAlpha;
        assert(outAlpha != 0x00);
        return ColorCls->fromARGB(outAlpha, (foreground->red() * alpha + background->red() * backAlpha) ~/ outAlpha, (foreground->green() * alpha + background->green() * backAlpha) ~/ outAlpha, (foreground->blue() * alpha + background->blue() * backAlpha) ~/ outAlpha);
    }
}

int ColorCls::getAlphaFromOpacity(double opacity) {
    assert(opacity != nullptr);
    return (opacity->clamp(0.0, 1.0) * 255)->round();
}

bool ColorCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<Color>(other) && other->value == value;
}

int ColorCls::hashCode() {
    return value->hashCode;
}

String ColorCls::toString() {
    return __s("Color(0x${value.toRadixString(16).padLeft(8, '0')})");
}

double ColorCls::_linearizeColorComponent(double component) {
    if (component <= 0.03928)     {
        return component / 12.92;
    }
    return as<double>(math->pow((component + 0.055) / 1.055, 2.4));
}

PaintCls::PaintCls() {
    {
        if (enableDithering) {
            _dither() = true;
        }
    }
}

bool PaintCls::isAntiAlias() {
    return _data->getInt32(_kIsAntiAliasOffset, _kFakeHostEndian) == 0;
}

void PaintCls::isAntiAlias(bool value) {
    int encoded = value? 0 : 1;
    _data->setInt32(_kIsAntiAliasOffset, encoded, _kFakeHostEndian);
}

Color PaintCls::color() {
    int encoded = _data->getInt32(_kColorOffset, _kFakeHostEndian);
    return make<ColorCls>(encoded ^ _kColorDefault);
}

void PaintCls::color(Color value) {
    assert(value != nullptr);
    int encoded = value->value ^ _kColorDefault;
    _data->setInt32(_kColorOffset, encoded, _kFakeHostEndian);
}

BlendMode PaintCls::blendMode() {
    int encoded = _data->getInt32(_kBlendModeOffset, _kFakeHostEndian);
    return BlendModeCls::values[encoded ^ _kBlendModeDefault];
}

void PaintCls::blendMode(BlendMode value) {
    assert(value != nullptr);
    int encoded = value->index ^ _kBlendModeDefault;
    _data->setInt32(_kBlendModeOffset, encoded, _kFakeHostEndian);
}

PaintingStyle PaintCls::style() {
    return PaintingStyleCls::values[_data->getInt32(_kStyleOffset, _kFakeHostEndian)];
}

void PaintCls::style(PaintingStyle value) {
    assert(value != nullptr);
    int encoded = value->index;
    _data->setInt32(_kStyleOffset, encoded, _kFakeHostEndian);
}

double PaintCls::strokeWidth() {
    return _data->getFloat32(_kStrokeWidthOffset, _kFakeHostEndian);
}

void PaintCls::strokeWidth(double value) {
    assert(value != nullptr);
    double encoded = value;
    _data->setFloat32(_kStrokeWidthOffset, encoded, _kFakeHostEndian);
}

StrokeCap PaintCls::strokeCap() {
    return StrokeCapCls::values[_data->getInt32(_kStrokeCapOffset, _kFakeHostEndian)];
}

void PaintCls::strokeCap(StrokeCap value) {
    assert(value != nullptr);
    int encoded = value->index;
    _data->setInt32(_kStrokeCapOffset, encoded, _kFakeHostEndian);
}

StrokeJoin PaintCls::strokeJoin() {
    return StrokeJoinCls::values[_data->getInt32(_kStrokeJoinOffset, _kFakeHostEndian)];
}

void PaintCls::strokeJoin(StrokeJoin value) {
    assert(value != nullptr);
    int encoded = value->index;
    _data->setInt32(_kStrokeJoinOffset, encoded, _kFakeHostEndian);
}

double PaintCls::strokeMiterLimit() {
    return _data->getFloat32(_kStrokeMiterLimitOffset, _kFakeHostEndian);
}

void PaintCls::strokeMiterLimit(double value) {
    assert(value != nullptr);
    double encoded = value - _kStrokeMiterLimitDefault;
    _data->setFloat32(_kStrokeMiterLimitOffset, encoded, _kFakeHostEndian);
}

MaskFilter PaintCls::maskFilter() {
    ;
    return nullptr;
}

void PaintCls::maskFilter(MaskFilter value) {
    if (value == nullptr) {
        _data->setInt32(_kMaskFilterOffset, MaskFilterCls::_TypeNoneCls, _kFakeHostEndian);
        _data->setInt32(_kMaskFilterBlurStyleOffset, 0, _kFakeHostEndian);
        _data->setFloat32(_kMaskFilterSigmaOffset, 0.0, _kFakeHostEndian);
    } else {
        _data->setInt32(_kMaskFilterOffset, MaskFilterCls::_TypeBlurCls, _kFakeHostEndian);
        _data->setInt32(_kMaskFilterBlurStyleOffset, value->_style->index, _kFakeHostEndian);
        _data->setFloat32(_kMaskFilterSigmaOffset, value->_sigma, _kFakeHostEndian);
    }
}

FilterQuality PaintCls::filterQuality() {
    return FilterQualityCls::values[_data->getInt32(_kFilterQualityOffset, _kFakeHostEndian)];
}

void PaintCls::filterQuality(FilterQuality value) {
    assert(value != nullptr);
    int encoded = value->index;
    _data->setInt32(_kFilterQualityOffset, encoded, _kFakeHostEndian);
}

Shader PaintCls::shader() {
    return as<Shader>(_objects?[_kShaderIndex]);
}

void PaintCls::shader(Shader value) {
    _ensureObjectsInitialized()[_kShaderIndex] = value;
}

ColorFilter PaintCls::colorFilter() {
    _ColorFilter nativeFilter = as<_ColorFilter>(_objects?[_kColorFilterIndex]);
    return nativeFilter?->creator;
}

void PaintCls::colorFilter(ColorFilter value) {
    _ColorFilter nativeFilter = value?->_toNativeColorFilter();
    if (nativeFilter == nullptr) {
        if (_objects != nullptr) {
            _objects![_kColorFilterIndex] = nullptr;
        }
    } else {
        _ensureObjectsInitialized()[_kColorFilterIndex] = nativeFilter;
    }
}

ImageFilter PaintCls::imageFilter() {
    _ImageFilter nativeFilter = as<_ImageFilter>(_objects?[_kImageFilterIndex]);
    return nativeFilter?->creator;
}

void PaintCls::imageFilter(ImageFilter value) {
    if (value == nullptr) {
        if (_objects != nullptr) {
            _objects![_kImageFilterIndex] = nullptr;
        }
    } else {
        List<Object> objects = _ensureObjectsInitialized();
        _ImageFilter imageFilter = as<_ImageFilter>(objects[_kImageFilterIndex]);
        if (imageFilter?->creator != value) {
            objects[_kImageFilterIndex] = value->_toNativeImageFilter();
        }
    }
}

bool PaintCls::invertColors() {
    return _data->getInt32(_kInvertColorOffset, _kFakeHostEndian) == 1;
}

void PaintCls::invertColors(bool value) {
    _data->setInt32(_kInvertColorOffset, value? 1 : 0, _kFakeHostEndian);
}

String PaintCls::toString() {
    if (boolValue->fromEnvironment(__s("dart.vm.product")false)) {
        return super->toString();
    }
    StringBuffer result = make<StringBufferCls>();
    String semicolon = __s("");
    result->write(__s("Paint("));
    if (style() == PaintingStyleCls::stroke) {
        result->write(__s("$style"));
        if (strokeWidth() != 0.0)         {
            result->write(__s(" ${strokeWidth.toStringAsFixed(1)}"));
        } else         {
            result->write(__s(" hairline"));
        }
        if (strokeCap() != StrokeCapCls::butt)         {
            result->write(__s(" $strokeCap"));
        }
        if (strokeJoin() == StrokeJoinCls::miter) {
            if (strokeMiterLimit() != _kStrokeMiterLimitDefault)             {
                result->write(__s(" $strokeJoin up to ${strokeMiterLimit.toStringAsFixed(1)}"));
            }
        } else {
            result->write(__s(" $strokeJoin"));
        }
        semicolon = __s("; ");
    }
    if (isAntiAlias() != true) {
        result->write(__s("${semicolon}antialias off"));
        semicolon = __s("; ");
    }
    if (color() != make<ColorCls>(_kColorDefault)) {
        result->write(__s("$semicolon$color"));
        semicolon = __s("; ");
    }
    if (blendMode()->index != _kBlendModeDefault) {
        result->write(__s("$semicolon$blendMode"));
        semicolon = __s("; ");
    }
    if (colorFilter() != nullptr) {
        result->write(__s("${semicolon}colorFilter: $colorFilter"));
        semicolon = __s("; ");
    }
    if (maskFilter() != nullptr) {
        result->write(__s("${semicolon}maskFilter: $maskFilter"));
        semicolon = __s("; ");
    }
    if (filterQuality() != FilterQualityCls::none) {
        result->write(__s("${semicolon}filterQuality: $filterQuality"));
        semicolon = __s("; ");
    }
    if (shader() != nullptr) {
        result->write(__s("${semicolon}shader: $shader"));
        semicolon = __s("; ");
    }
    if (imageFilter() != nullptr) {
        result->write(__s("${semicolon}imageFilter: $imageFilter"));
        semicolon = __s("; ");
    }
    if (invertColors())     {
        result->write(__s("${semicolon}invert: $invertColors"));
    }
    if (_dither())     {
        result->write(__s("${semicolon}dither: $_dither"));
    }
    result->write(__s(")"));
    return result->toString();
}

List<Object> PaintCls::_ensureObjectsInitialized() {
    return _objects ??= <Object>filled(_kObjectCount, nullptrfalse);
}

bool PaintCls::_dither() {
    return _data->getInt32(_kDitherOffset, _kFakeHostEndian) == 1;
}

void PaintCls::_dither(bool value) {
    _data->setInt32(_kDitherOffset, value? 1 : 0, _kFakeHostEndian);
}

void ImageCls::dispose() {
    assert(!_disposed && !_image->_disposed);
    assert(_image->_handles->contains(this));
    _disposed = true;
    bool removed = _image->_handles->remove(this);
    assert(removed);
    if (_image->_handles->isEmpty) {
        _image->dispose();
    }
}

bool ImageCls::debugDisposed() {
    bool disposed;
    assert([=] () {
        disposed = _disposed;
        return true;
    }());
    return disposed or ();
}

Future<ByteData> ImageCls::toByteData(ImageByteFormat format) {
    assert(!_disposed && !_image->_disposed);
    return _image->toByteData(format);
}

List<StackTrace> ImageCls::debugGetOpenHandleStackTraces() {
    List<StackTrace> stacks;
    assert([=] () {
        stacks = _image->_handles->map([=] (Image handle)         {
            handle->_debugStack!;
        })->toList();
        return true;
    }());
    return stacks;
}

Image ImageCls::clone() {
    if (_disposed) {
        ;
    }
    assert(!_image->_disposed);
    return ImageCls->_(_image, width, height);
}

bool ImageCls::isCloneOf(Image other) {
    return other->_image == _image;
}

String ImageCls::toString() {
    return _image->toString();
}

void ImageCls::_(_Image _image, int height, int width) {
    assert([=] () {
        _debugStack = StackTraceCls::current;
        return true;
    }());
    _image->_handles->add(this);
}

Future<ByteData> _ImageCls::toByteData(ImageByteFormat format) {
    return _futurize([=] (_Callback<ByteData> callback) {
        return _toByteData(format->index, [=] (Uint8List encoded) {
            callback(encoded!->buffer->asByteData());
        });
    });
}

void _ImageCls::dispose() {
    assert(!_disposed);
    assert(_handles->isEmpty, __s("Attempted to dispose of an Image object that has ${_handles.length} open handles.\nIf you see this, it is a bug in dart:ui. Please file an issue at https://github.com/flutter/flutter/issues/new."));
    _disposed = true;
    _dispose();
}

String _ImageCls::toString() {
    return __s("[$width\u00D7$height]");
}

int CodecCls::frameCount() {
    return _cachedFrameCount ??= _frameCount();
}

int CodecCls::repetitionCount() {
    return _cachedRepetitionCount ??= _repetitionCount();
}

Future<FrameInfo> CodecCls::getNextFrame() {
    Completer<FrameInfo> completer = <FrameInfo>sync();
    String error = _getNextFrame([=] (_Image image,int durationMilliseconds) {
    if (image == nullptr) {
        completer->completeError(make<ExceptionCls>(__s("Codec failed to produce an image, possibly due to invalid image data.")));
    } else {
        completer->complete(FrameInfoCls->_(ImageCls->_(image, image->width, image->height), make<DurationCls>(durationMilliseconds)));
    }
});
    if (error != nullptr) {
        ;
    }
    return completer->future;
}

Future<Codec> instantiateImageCodec(bool allowUpscaling, Uint8List list, int targetHeight, int targetWidth) {
    ImmutableBuffer buffer = await ImmutableBufferCls->fromUint8List(list);
    return instantiateImageCodecFromBuffer(buffertargetWidth, targetHeight, allowUpscaling);
}

Future<Codec> instantiateImageCodecFromBuffer(bool allowUpscaling, ImmutableBuffer buffer, int targetHeight, int targetWidth) {
    ImageDescriptor descriptor = await ImageDescriptorCls->encoded(buffer);
    if (!allowUpscaling) {
        if (targetWidth != nullptr && targetWidth > descriptor->width()) {
            targetWidth = descriptor->width();
        }
        if (targetHeight != nullptr && targetHeight > descriptor->height()) {
            targetHeight = descriptor->height();
        }
    }
    buffer->dispose();
    return descriptor->instantiateCodec(targetWidth, targetHeight);
}

void decodeImageFromList(ImageDecoderCallback callback, Uint8List list) {
    _decodeImageFromListAsync(list, callback);
}

Future<void> _decodeImageFromListAsync(ImageDecoderCallback callback, Uint8List list) {
    Codec codec = await instantiateImageCodec(list);
    FrameInfo frameInfo = await codec->getNextFrame();
    callback(frameInfo->image);
}

void decodeImageFromPixels(bool allowUpscaling, ImageDecoderCallback callback, PixelFormat format, int height, Uint8List pixels, int rowBytes, int targetHeight, int targetWidth, int width) {
    if (targetWidth != nullptr) {
        assert(allowUpscaling || targetWidth <= width);
    }
    if (targetHeight != nullptr) {
        assert(allowUpscaling || targetHeight <= height);
    }
    ImmutableBufferCls->fromUint8List(pixels)->then([=] (ImmutableBuffer buffer) {
        ImageDescriptor descriptor = ImageDescriptorCls->raw(bufferwidth, height, rowBytes, format);
        if (!allowUpscaling) {
            if (targetWidth != nullptr && targetWidth! > descriptor->width) {
                targetWidth = descriptor->width;
            }
            if (targetHeight != nullptr && targetHeight! > descriptor->height) {
                targetHeight = descriptor->height;
            }
        }
        descriptor->instantiateCodec(targetWidth, targetHeight)->then([=] (Codec codec) {
            Future<FrameInfo> frameInfo = codec->getNextFrame();
            codec->dispose();
            return frameInfo;
        })->then([=] (FrameInfo frameInfo) {
            buffer->dispose();
            descriptor->dispose();
            return callback(frameInfo->image);
        });
    });
}

PathCls::PathCls() {
    {
        _constructor();
    }
}

void PathCls::from(Path source) {
    Path clonedPath = PathCls->_();
    source->_clone(clonedPath);
    return clonedPath;
}

PathFillType PathCls::fillType() {
    return PathFillTypeCls::values[_getFillType()];
}

void PathCls::fillType(PathFillType value) {
    return _setFillType(value->index);
}

void PathCls::arcTo(bool forceMoveTo, Rect rect, double startAngle, double sweepAngle) {
    assert(_rectIsValid(rect));
    _arcTo(rect->left, rect->top, rect->right, rect->bottom, startAngle, sweepAngle, forceMoveTo);
}

void PathCls::arcToPoint(Offset arcEnd, bool clockwise, bool largeArc, Radius radius, double rotation) {
    assert(_offsetIsValid(arcEnd));
    assert(_radiusIsValid(radius));
    _arcToPoint(arcEnd->dx(), arcEnd->dy(), radius->x, radius->y, rotation, largeArc, clockwise);
}

void PathCls::relativeArcToPoint(Offset arcEndDelta, bool clockwise, bool largeArc, Radius radius, double rotation) {
    assert(_offsetIsValid(arcEndDelta));
    assert(_radiusIsValid(radius));
    _relativeArcToPoint(arcEndDelta->dx(), arcEndDelta->dy(), radius->x, radius->y, rotation, largeArc, clockwise);
}

void PathCls::addRect(Rect rect) {
    assert(_rectIsValid(rect));
    _addRect(rect->left, rect->top, rect->right, rect->bottom);
}

void PathCls::addOval(Rect oval) {
    assert(_rectIsValid(oval));
    _addOval(oval->left, oval->top, oval->right, oval->bottom);
}

void PathCls::addArc(Rect oval, double startAngle, double sweepAngle) {
    assert(_rectIsValid(oval));
    _addArc(oval->left, oval->top, oval->right, oval->bottom, startAngle, sweepAngle);
}

void PathCls::addPolygon(bool close, List<Offset> points) {
    assert(points != nullptr);
    _addPolygon(_encodePointList(points), close);
}

void PathCls::addRRect(RRect rrect) {
    assert(_rrectIsValid(rrect));
    _addRRect(rrect->_getValue32());
}

void PathCls::addPath(Float64List matrix4, Offset offset, Path path) {
    assert(path != nullptr);
    assert(_offsetIsValid(offset));
    if (matrix4 != nullptr) {
        assert(_matrix4IsValid(matrix4));
        _addPathWithMatrix(path, offset->dx(), offset->dy(), matrix4);
    } else {
        _addPath(path, offset->dx(), offset->dy());
    }
}

void PathCls::extendWithPath(Float64List matrix4, Offset offset, Path path) {
    assert(path != nullptr);
    assert(_offsetIsValid(offset));
    if (matrix4 != nullptr) {
        assert(_matrix4IsValid(matrix4));
        _extendWithPathAndMatrix(path, offset->dx(), offset->dy(), matrix4);
    } else {
        _extendWithPath(path, offset->dx(), offset->dy());
    }
}

bool PathCls::contains(Offset point) {
    assert(_offsetIsValid(point));
    return _contains(point->dx(), point->dy());
}

Path PathCls::shift(Offset offset) {
    assert(_offsetIsValid(offset));
    Path path = PathCls->_();
    _shift(path, offset->dx(), offset->dy());
    return path;
}

Path PathCls::transform(Float64List matrix4) {
    assert(_matrix4IsValid(matrix4));
    Path path = PathCls->_();
    _transform(path, matrix4);
    return path;
}

Rect PathCls::getBounds() {
    Float32List rect = _getBounds();
    return RectCls->fromLTRB(rect[0], rect[1], rect[2], rect[3]);
}

Path PathCls::combine(PathOperation operation, Path path1, Path path2) {
    assert(path1 != nullptr);
    assert(path2 != nullptr);
    Path path = make<PathCls>();
    if (path->_op(path1, path2, operation->index)) {
        return path;
    }
    ;
}

PathMetrics PathCls::computeMetrics(bool forceClosed) {
    return PathMetricsCls->_(this, forceClosed);
}

TangentCls::TangentCls(Offset position, Offset vector) {
    {
        assert(position != nullptr);
        assert(vector != nullptr);
    }
}

void TangentCls::fromAngle(double angle, Offset position) {
    return make<TangentCls>(position, make<OffsetCls>(math->cos(angle), math->sin(angle)));
}

double TangentCls::angle() {
    return -math->atan2(vector->dy(), vector->dx());
}

Iterator<PathMetric> PathMetricsCls::iterator() {
    return _iterator;
}

void PathMetricsCls::_(bool forceClosed, Path path)

PathMetric PathMetricIteratorCls::current() {
    PathMetric currentMetric = _pathMetric;
    if (currentMetric == nullptr) {
        ;
    }
    return currentMetric;
}

bool PathMetricIteratorCls::moveNext() {
    if (_pathMeasure->_nextContour()) {
        _pathMetric = PathMetricCls->_(_pathMeasure);
        return true;
    }
    _pathMetric = nullptr;
    return false;
}

void PathMetricIteratorCls::_(_PathMeasure _pathMeasure)

Tangent PathMetricCls::getTangentForOffset(double distance) {
    return _measure->getTangentForOffset(contourIndex, distance);
}

Path PathMetricCls::extractPath(double end, double start, bool startWithMoveTo) {
    return _measure->extractPath(contourIndex, start, endstartWithMoveTo);
}

String PathMetricCls::toString() {
    return __s("$runtimeType{length: $length, isClosed: $isClosed, contourIndex:$contourIndex}");
}

void PathMetricCls::_(_PathMeasure _measure)

double _PathMeasureCls::length(int contourIndex) {
    assert(contourIndex <= currentContourIndex, __s("Iterator must be advanced before index $contourIndex can be used."));
    return _length(contourIndex);
}

Tangent _PathMeasureCls::getTangentForOffset(int contourIndex, double distance) {
    assert(contourIndex <= currentContourIndex, __s("Iterator must be advanced before index $contourIndex can be used."));
    Float32List posTan = _getPosTan(contourIndex, distance);
    if (posTan[0] == 0.0) {
        return nullptr;
    } else {
        return make<TangentCls>(make<OffsetCls>(posTan[1], posTan[2]), make<OffsetCls>(posTan[3], posTan[4]));
    }
}

Path _PathMeasureCls::extractPath(int contourIndex, double end, double start, bool startWithMoveTo) {
    assert(contourIndex <= currentContourIndex, __s("Iterator must be advanced before index $contourIndex can be used."));
    Path path = PathCls->_();
    _extractPath(path, contourIndex, start, endstartWithMoveTo);
    return path;
}

bool _PathMeasureCls::isClosed(int contourIndex) {
    assert(contourIndex <= currentContourIndex, __s("Iterator must be advanced before index $contourIndex can be used."));
    return _isClosed(contourIndex);
}

_PathMeasureCls::_PathMeasureCls(bool forceClosed, Path path) {
    {
        _constructor(path, forceClosed);
    }
}

bool _PathMeasureCls::_nextContour() {
    bool next = _nativeNextContour();
    if (next) {
        currentContourIndex++;
    }
    return next;
}

void MaskFilterCls::blur(double _sigma, BlurStyle _style)

bool MaskFilterCls::==(Object other) {
    return is<MaskFilter>(other) && other->_style == _style && other->_sigma == _sigma;
}

int MaskFilterCls::hashCode() {
    return ObjectCls->hash(_style, _sigma);
}

String MaskFilterCls::toString() {
    return __s("MaskFilter.blur($_style, ${_sigma.toStringAsFixed(1)})");
}

void ColorFilterCls::mode(BlendMode blendMode, Color color)

void ColorFilterCls::matrix(List<double> matrix)

void ColorFilterCls::linearToSrgbGamma()

void ColorFilterCls::srgbToLinearGamma()

bool ColorFilterCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<ColorFilter>(other) && other->_type == _type && <double>_listEquals(other->_matrix, _matrix) && other->_color == _color && other->_blendMode == _blendMode;
}

int ColorFilterCls::hashCode() {
    return ObjectCls->hash(_color, _blendMode, _matrix == nullptr? nullptr : ObjectCls->hashAll(_matrix!), _type);
}

String ColorFilterCls::toString() {
    ;
}

_ImageFilter ColorFilterCls::_toNativeImageFilter() {
    return _ImageFilterCls->fromColorFilter(this);
}

_ColorFilter ColorFilterCls::_toNativeColorFilter() {
    ;
}

String ColorFilterCls::_shortDescription() {
    ;
}

void _ColorFilterCls::mode(ColorFilter creator) {
    _constructor();
    _initMode(creator->_color!->value, creator->_blendMode!->index);
}

void _ColorFilterCls::matrix(ColorFilter creator) {
    _constructor();
    _initMatrix(Float32ListCls->fromList(creator->_matrix!));
}

void _ColorFilterCls::linearToSrgbGamma(ColorFilter creator) {
    _constructor();
    _initLinearToSrgbGamma();
}

void _ColorFilterCls::srgbToLinearGamma(ColorFilter creator) {
    _constructor();
    _initSrgbToLinearGamma();
}

void ImageFilterCls::blur(double sigmaX, double sigmaY, TileMode tileMode) {
    assert(sigmaX != nullptr);
    assert(sigmaY != nullptr);
    assert(tileMode != nullptr);
    return make<_GaussianBlurImageFilterCls>(sigmaX, sigmaY, tileMode);
}

void ImageFilterCls::dilate(double radiusX, double radiusY) {
    assert(radiusX != nullptr);
    assert(radiusY != nullptr);
    return make<_DilateImageFilterCls>(radiusX, radiusY);
}

void ImageFilterCls::erode(double radiusX, double radiusY) {
    assert(radiusX != nullptr);
    assert(radiusY != nullptr);
    return make<_ErodeImageFilterCls>(radiusX, radiusY);
}

void ImageFilterCls::matrix(FilterQuality filterQuality, Float64List matrix4) {
    assert(matrix4 != nullptr);
    assert(filterQuality != nullptr);
    if (matrix4->length != 16)     {
        ;
    }
    return make<_MatrixImageFilterCls>(Float64ListCls->fromList(matrix4), filterQuality);
}

void ImageFilterCls::compose(ImageFilter inner, ImageFilter outer) {
    assert(inner != nullptr && outer != nullptr);
    return make<_ComposeImageFilterCls>(inner, outer);
}

String _MatrixImageFilterCls::toString() {
    return __s("ImageFilter.matrix($data, $filterQuality)");
}

bool _MatrixImageFilterCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<_MatrixImageFilter>(other) && other->filterQuality == filterQuality && <double>_listEquals(other->data, data);
}

int _MatrixImageFilterCls::hashCode() {
    return ObjectCls->hash(filterQuality, ObjectCls->hashAll(data));
}

_ImageFilter _MatrixImageFilterCls::_toNativeImageFilter() {
    return nativeFilter;
}

String _MatrixImageFilterCls::_shortDescription() {
    return __s("matrix($data, $filterQuality)");
}

String _GaussianBlurImageFilterCls::toString() {
    return __s("ImageFilter.blur($sigmaX, $sigmaY, $_modeString)");
}

bool _GaussianBlurImageFilterCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<_GaussianBlurImageFilter>(other) && other->sigmaX == sigmaX && other->sigmaY == sigmaY && other->tileMode == tileMode;
}

int _GaussianBlurImageFilterCls::hashCode() {
    return ObjectCls->hash(sigmaX, sigmaY);
}

_ImageFilter _GaussianBlurImageFilterCls::_toNativeImageFilter() {
    return nativeFilter;
}

String _GaussianBlurImageFilterCls::_modeString() {
    ;
}

String _GaussianBlurImageFilterCls::_shortDescription() {
    return __s("blur($sigmaX, $sigmaY, $_modeString)");
}

String _DilateImageFilterCls::toString() {
    return __s("ImageFilter.dilate($radiusX, $radiusY)");
}

bool _DilateImageFilterCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<_DilateImageFilter>(other) && other->radiusX == radiusX && other->radiusY == radiusY;
}

int _DilateImageFilterCls::hashCode() {
    return ObjectCls->hash(radiusX, radiusY);
}

_ImageFilter _DilateImageFilterCls::_toNativeImageFilter() {
    return nativeFilter;
}

String _DilateImageFilterCls::_shortDescription() {
    return __s("dilate($radiusX, $radiusY)");
}

String _ErodeImageFilterCls::toString() {
    return __s("ImageFilter.erode($radiusX, $radiusY)");
}

bool _ErodeImageFilterCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<_ErodeImageFilter>(other) && other->radiusX == radiusX && other->radiusY == radiusY;
}

int _ErodeImageFilterCls::hashCode() {
    return hashValues(radiusX, radiusY);
}

_ImageFilter _ErodeImageFilterCls::_toNativeImageFilter() {
    return nativeFilter;
}

String _ErodeImageFilterCls::_shortDescription() {
    return __s("erode($radiusX, $radiusY)");
}

String _ComposeImageFilterCls::toString() {
    return __s("ImageFilter.compose(source -> $_shortDescription -> result)");
}

bool _ComposeImageFilterCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<_ComposeImageFilter>(other) && other->innerFilter == innerFilter && other->outerFilter == outerFilter;
}

int _ComposeImageFilterCls::hashCode() {
    return ObjectCls->hash(innerFilter, outerFilter);
}

_ImageFilter _ComposeImageFilterCls::_toNativeImageFilter() {
    return nativeFilter;
}

String _ComposeImageFilterCls::_shortDescription() {
    return __s("${innerFilter._shortDescription} -> ${outerFilter._shortDescription}");
}

void _ImageFilterCls::blur(_GaussianBlurImageFilter filter) {
    _constructor();
    _initBlur(filter->sigmaX, filter->sigmaY, filter->tileMode->index);
}

void _ImageFilterCls::dilate(_DilateImageFilter filter) {
    _constructor();
    _initDilate(filter->radiusX, filter->radiusY);
}

void _ImageFilterCls::erode(_ErodeImageFilter filter) {
    _constructor();
    _initErode(filter->radiusX, filter->radiusY);
}

void _ImageFilterCls::matrix(_MatrixImageFilter filter) {
    if (filter->data->length != 16)     {
        ;
    }
    _constructor();
    _initMatrix(filter->data, filter->filterQuality->index);
}

void _ImageFilterCls::fromColorFilter(ColorFilter filter) {
    _constructor();
    _ColorFilter nativeFilter = filter->_toNativeColorFilter();
    _initColorFilter(nativeFilter!);
}

void _ImageFilterCls::composed(_ComposeImageFilter filter) {
    _constructor();
    _ImageFilter nativeFilterInner = filter->innerFilter->_toNativeImageFilter();
    _ImageFilter nativeFilterOuter = filter->outerFilter->_toNativeImageFilter();
    _initComposed(nativeFilterOuter, nativeFilterInner);
}

Int32List _encodeColorList(List<Color> colors) {
    int colorCount = colors->length();
    Int32List result = make<Int32ListCls>(colorCount);
    for (;  < colorCount; ++i)     {
        result[i] = colors[i]->value;
    }
    return result;
}

Float32List _encodePointList(List<Offset> points) {
    assert(points != nullptr);
    int pointCount = points->length();
    Float32List result = make<Float32ListCls>(pointCount * 2);
    for (;  < pointCount; ++i) {
        int xIndex = i * 2;
        int yIndex = xIndex + 1;
        Offset point = points[i];
        assert(_offsetIsValid(point));
        result[xIndex] = point->dx();
        result[yIndex] = point->dy();
    }
    return result;
}

Float32List _encodeTwoPoints(Offset pointA, Offset pointB) {
    assert(_offsetIsValid(pointA));
    assert(_offsetIsValid(pointB));
    Float32List result = make<Float32ListCls>(4);
    result[0] = pointA->dx();
    result[1] = pointA->dy();
    result[2] = pointB->dx();
    result[3] = pointB->dy();
    return result;
}

void GradientCls::linear(List<double> colorStops, List<Color> colors, Offset from, Float64List matrix4, TileMode tileMode, Offset to) {
    _validateColorStops(colors, colorStops);
    Float32List endPointsBuffer = _encodeTwoPoints(from, to);
    Int32List colorsBuffer = _encodeColorList(colors);
    Float32List colorStopsBuffer = colorStops == nullptr? nullptr : Float32ListCls->fromList(colorStops);
    _constructor();
    _initLinear(endPointsBuffer, colorsBuffer, colorStopsBuffer, tileMode->index, matrix4);
}

void GradientCls::radial(Offset center, List<double> colorStops, List<Color> colors, Offset focal, double focalRadius, Float64List matrix4, double radius, TileMode tileMode) {
    _validateColorStops(colors, colorStops);
    Int32List colorsBuffer = _encodeColorList(colors);
    Float32List colorStopsBuffer = colorStops == nullptr? nullptr : Float32ListCls->fromList(colorStops);
    if (focal == nullptr || (focal == center && focalRadius == 0.0)) {
        _constructor();
        _initRadial(center->dx(), center->dy(), radius, colorsBuffer, colorStopsBuffer, tileMode->index, matrix4);
    } else {
        assert(center != OffsetCls::zero || focal != OffsetCls::zero);
        _constructor();
        _initConical(focal->dx(), focal->dy(), focalRadius, center->dx(), center->dy(), radius, colorsBuffer, colorStopsBuffer, tileMode->index, matrix4);
    }
}

void GradientCls::sweep(Offset center, List<double> colorStops, List<Color> colors, double endAngle, Float64List matrix4, double startAngle, TileMode tileMode) {
    _validateColorStops(colors, colorStops);
    Int32List colorsBuffer = _encodeColorList(colors);
    Float32List colorStopsBuffer = colorStops == nullptr? nullptr : Float32ListCls->fromList(colorStops);
    _constructor();
    _initSweep(center->dx(), center->dy(), colorsBuffer, colorStopsBuffer, tileMode->index, startAngle, endAngle, matrix4);
}

void GradientCls::_validateColorStops(List<double> colorStops, List<Color> colors) {
    if (colorStops == nullptr) {
        if (colors->length() != 2)         {
            ;
        }
    } else {
        if (colors->length() != colorStops->length())         {
            ;
        }
    }
}

ImageShaderCls::ImageShaderCls(FilterQuality filterQuality, Image image, Float64List matrix4, TileMode tmx, TileMode tmy) {
    {
        assert(image != nullptr);
        assert(tmx != nullptr);
        assert(tmy != nullptr);
        assert(matrix4 != nullptr);
        super->_();
    }
    {
        if (matrix4->length != 16)         {
            ;
        }
        _constructor();
        String error = _initWithImage(image->_image, tmx->index, tmy->index, filterQuality?->index or -1, matrix4);
        if (error != nullptr) {
            ;
        }
    }
}

Future<FragmentProgram> FragmentProgramCls::compile(bool debugPrint, ByteBuffer spirv) {
    return <FragmentProgram>microtask([=] ()     {
        FragmentProgramCls->_(spirv, debugPrint);
    });
}

Shader FragmentProgramCls::shader(Float32List floatUniforms, List<ImageShader> samplerUniforms) {
    if (floatUniforms == nullptr) {
        floatUniforms = make<Float32ListCls>(_uniformFloatCount);
    }
    if (floatUniforms->length != _uniformFloatCount) {
        ;
    }
    if (_samplerCount > 0 && (samplerUniforms == nullptr || samplerUniforms->length() != _samplerCount)) {
        ;
    }
    if (samplerUniforms == nullptr) {
        samplerUniforms = makeList();
    } else {
            List<ImageShader> list1 = make<ListCls<>>();    for (auto _x1 : samplerUniforms) {    {        list1.add(_x1);    }samplerUniforms = list1;
    }
    _FragmentShader shader = make<_FragmentShaderCls>(this, Float32ListCls->fromList(floatUniforms), samplerUniforms);
    _shader(shader, floatUniforms, samplerUniforms);
    return shader;
}

void FragmentProgramCls::_(bool debugPrint, ByteBuffer spirv) {
    _constructor();
    TranspileResult result = spv->transpile(spirv, spv->TargetLanguageCls::sksl);
    _init(result->src, debugPrint);
    _uniformFloatCount = result->uniformFloatCount;
    _samplerCount = result->samplerCount;
}

bool _FragmentShaderCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<_FragmentShader>(other) && other->_builder == _builder && <double>_listEquals(other->_floatUniforms, _floatUniforms) && <ImageShader>_listEquals(other->_samplerUniforms, _samplerUniforms);
}

int _FragmentShaderCls::hashCode() {
    return ObjectCls->hash(_builder, ObjectCls->hashAll(_floatUniforms), ObjectCls->hashAll(_samplerUniforms));
}

_FragmentShaderCls::_FragmentShaderCls(FragmentProgram _builder, Float32List _floatUniforms, List<ImageShader> _samplerUniforms) {
    {
        super->_();
    }
}

VerticesCls::VerticesCls(List<Color> colors, List<int> indices, VertexMode mode, List<Offset> positions, List<Offset> textureCoordinates) {
    {
        assert(mode != nullptr);
        assert(positions != nullptr);
    }
    {
        if (textureCoordinates != nullptr && textureCoordinates->length() != positions->length())         {
            ;
        }
        if (colors != nullptr && colors->length() != positions->length())         {
            ;
        }
        if (indices != nullptr && indices->any([=] (int i)         {
             < 0 || i >= positions->length();
        }))         {
            ;
        }
        Float32List encodedPositions = _encodePointList(positions);
        Float32List encodedTextureCoordinates = (textureCoordinates != nullptr)? _encodePointList(textureCoordinates) : nullptr;
        Int32List encodedColors = colors != nullptr? _encodeColorList(colors) : nullptr;
        Uint16List encodedIndices = indices != nullptr? Uint16ListCls->fromList(indices) : nullptr;
        if (!_init(this, mode->index, encodedPositions, encodedTextureCoordinates, encodedColors, encodedIndices))         {
            ;
        }
    }
}

void VerticesCls::raw(Int32List colors, Uint16List indices, VertexMode mode, Float32List positions, Float32List textureCoordinates) {
    if (textureCoordinates != nullptr && textureCoordinates->length != positions->length)     {
        ;
    }
    if (colors != nullptr && colors->length * 2 != positions->length)     {
        ;
    }
    if (indices != nullptr && indices->any([=] (int i)     {
         < 0 || i >= positions->length;
    }))     {
        ;
    }
    if (!_init(this, mode->index, positions, textureCoordinates, colors, indices))     {
        ;
    }
}

CanvasCls::CanvasCls(Rect cullRect, PictureRecorder recorder) {
    {
        assert(recorder != nullptr);
    }
    {
        if (recorder->isRecording())         {
            ;
        }
        _recorder = recorder;
        _recorder!->_canvas = this;
        cullRect = RectCls::largest;
        _constructor(recorder, cullRect->left, cullRect->top, cullRect->right, cullRect->bottom);
    }
}

void CanvasCls::saveLayer(Rect bounds, Paint paint) {
    assert(paint != nullptr);
    if (bounds == nullptr) {
        _saveLayerWithoutBounds(paint->_objects, paint->_data);
    } else {
        assert(_rectIsValid(bounds));
        _saveLayer(bounds->left, bounds->top, bounds->right, bounds->bottom, paint->_objects, paint->_data);
    }
}

void CanvasCls::scale(double sx, double sy) {
    return _scale(sx, sy or sx);
}

void CanvasCls::transform(Float64List matrix4) {
    assert(matrix4 != nullptr);
    if (matrix4->length != 16)     {
        ;
    }
    _transform(matrix4);
}

Float64List CanvasCls::getTransform() {
    Float64List matrix4 = make<Float64ListCls>(16);
    _getTransform(matrix4);
    return matrix4;
}

void CanvasCls::clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect) {
    assert(_rectIsValid(rect));
    assert(clipOp != nullptr);
    assert(doAntiAlias != nullptr);
    _clipRect(rect->left, rect->top, rect->right, rect->bottom, clipOp->index, doAntiAlias);
}

void CanvasCls::clipRRect(bool doAntiAlias, RRect rrect) {
    assert(_rrectIsValid(rrect));
    assert(doAntiAlias != nullptr);
    _clipRRect(rrect->_getValue32(), doAntiAlias);
}

void CanvasCls::clipPath(bool doAntiAlias, Path path) {
    assert(path != nullptr);
    assert(doAntiAlias != nullptr);
    _clipPath(path, doAntiAlias);
}

Rect CanvasCls::getLocalClipBounds() {
    Float64List bounds = make<Float64ListCls>(4);
    _getLocalClipBounds(bounds);
    return RectCls->fromLTRB(bounds[0], bounds[1], bounds[2], bounds[3]);
}

Rect CanvasCls::getDestinationClipBounds() {
    Float64List bounds = make<Float64ListCls>(4);
    _getDestinationClipBounds(bounds);
    return RectCls->fromLTRB(bounds[0], bounds[1], bounds[2], bounds[3]);
}

void CanvasCls::drawColor(BlendMode blendMode, Color color) {
    assert(color != nullptr);
    assert(blendMode != nullptr);
    _drawColor(color->value, blendMode->index);
}

void CanvasCls::drawLine(Offset p1, Offset p2, Paint paint) {
    assert(_offsetIsValid(p1));
    assert(_offsetIsValid(p2));
    assert(paint != nullptr);
    _drawLine(p1->dx(), p1->dy(), p2->dx(), p2->dy(), paint->_objects, paint->_data);
}

void CanvasCls::drawPaint(Paint paint) {
    assert(paint != nullptr);
    _drawPaint(paint->_objects, paint->_data);
}

void CanvasCls::drawRect(Paint paint, Rect rect) {
    assert(_rectIsValid(rect));
    assert(paint != nullptr);
    _drawRect(rect->left, rect->top, rect->right, rect->bottom, paint->_objects, paint->_data);
}

void CanvasCls::drawRRect(Paint paint, RRect rrect) {
    assert(_rrectIsValid(rrect));
    assert(paint != nullptr);
    _drawRRect(rrect->_getValue32(), paint->_objects, paint->_data);
}

void CanvasCls::drawDRRect(RRect inner, RRect outer, Paint paint) {
    assert(_rrectIsValid(outer));
    assert(_rrectIsValid(inner));
    assert(paint != nullptr);
    _drawDRRect(outer->_getValue32(), inner->_getValue32(), paint->_objects, paint->_data);
}

void CanvasCls::drawOval(Paint paint, Rect rect) {
    assert(_rectIsValid(rect));
    assert(paint != nullptr);
    _drawOval(rect->left, rect->top, rect->right, rect->bottom, paint->_objects, paint->_data);
}

void CanvasCls::drawCircle(Offset c, Paint paint, double radius) {
    assert(_offsetIsValid(c));
    assert(paint != nullptr);
    _drawCircle(c->dx(), c->dy(), radius, paint->_objects, paint->_data);
}

void CanvasCls::drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter) {
    assert(_rectIsValid(rect));
    assert(paint != nullptr);
    _drawArc(rect->left, rect->top, rect->right, rect->bottom, startAngle, sweepAngle, useCenter, paint->_objects, paint->_data);
}

void CanvasCls::drawPath(Paint paint, Path path) {
    assert(path != nullptr);
    assert(paint != nullptr);
    _drawPath(path, paint->_objects, paint->_data);
}

void CanvasCls::drawImage(Image image, Offset offset, Paint paint) {
    assert(image != nullptr);
    assert(_offsetIsValid(offset));
    assert(paint != nullptr);
    String error = _drawImage(image->_image, offset->dx(), offset->dy(), paint->_objects, paint->_data, paint->filterQuality()->index);
    if (error != nullptr) {
        ;
    }
}

void CanvasCls::drawImageRect(Rect dst, Image image, Paint paint, Rect src) {
    assert(image != nullptr);
    assert(_rectIsValid(src));
    assert(_rectIsValid(dst));
    assert(paint != nullptr);
    String error = _drawImageRect(image->_image, src->left, src->top, src->right, src->bottom, dst->left, dst->top, dst->right, dst->bottom, paint->_objects, paint->_data, paint->filterQuality()->index);
    if (error != nullptr) {
        ;
    }
}

void CanvasCls::drawImageNine(Rect center, Rect dst, Image image, Paint paint) {
    assert(image != nullptr);
    assert(_rectIsValid(center));
    assert(_rectIsValid(dst));
    assert(paint != nullptr);
    String error = _drawImageNine(image->_image, center->left, center->top, center->right, center->bottom, dst->left, dst->top, dst->right, dst->bottom, paint->_objects, paint->_data, paint->filterQuality()->index);
    if (error != nullptr) {
        ;
    }
}

void CanvasCls::drawPicture(Picture picture) {
    assert(picture != nullptr);
    _drawPicture(picture);
}

void CanvasCls::drawParagraph(Offset offset, Paragraph paragraph) {
    assert(paragraph != nullptr);
    assert(_offsetIsValid(offset));
    assert(!paragraph->_needsLayout);
    paragraph->_paint(this, offset->dx(), offset->dy());
}

void CanvasCls::drawPoints(Paint paint, PointMode pointMode, List<Offset> points) {
    assert(pointMode != nullptr);
    assert(points != nullptr);
    assert(paint != nullptr);
    _drawPoints(paint->_objects, paint->_data, pointMode->index, _encodePointList(points));
}

void CanvasCls::drawRawPoints(Paint paint, PointMode pointMode, Float32List points) {
    assert(pointMode != nullptr);
    assert(points != nullptr);
    assert(paint != nullptr);
    if (points->length % 2 != 0)     {
        ;
    }
    _drawPoints(paint->_objects, paint->_data, pointMode->index, points);
}

void CanvasCls::drawVertices(BlendMode blendMode, Paint paint, Vertices vertices) {
    assert(vertices != nullptr);
    assert(paint != nullptr);
    assert(blendMode != nullptr);
    _drawVertices(vertices, blendMode->index, paint->_objects, paint->_data);
}

void CanvasCls::drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms) {
    assert(atlas != nullptr);
    assert(transforms != nullptr);
    assert(rects != nullptr);
    assert(colors == nullptr || colors->isEmpty || blendMode != nullptr);
    assert(paint != nullptr);
    int rectCount = rects->length();
    if (transforms->length() != rectCount)     {
        ;
    }
    if (colors != nullptr && colors->isNotEmpty && colors->length() != rectCount)     {
        ;
    }
    Float32List rstTransformBuffer = make<Float32ListCls>(rectCount * 4);
    Float32List rectBuffer = make<Float32ListCls>(rectCount * 4);
    for (;  < rectCount; ++i) {
        int index0 = i * 4;
        int index1 = index0 + 1;
        int index2 = index0 + 2;
        int index3 = index0 + 3;
        RSTransform rstTransform = transforms[i];
        Rect rect = rects[i];
        assert(_rectIsValid(rect));
        rstTransformBuffer[index0] = rstTransform->scos();
        rstTransformBuffer[index1] = rstTransform->ssin();
        rstTransformBuffer[index2] = rstTransform->tx();
        rstTransformBuffer[index3] = rstTransform->ty();
        rectBuffer[index0] = rect->left;
        rectBuffer[index1] = rect->top;
        rectBuffer[index2] = rect->right;
        rectBuffer[index3] = rect->bottom;
    }
    Int32List colorBuffer = (colors == nullptr || colors->isEmpty)? nullptr : _encodeColorList(colors);
    Float32List cullRectBuffer = cullRect?->_getValue32();
    int qualityIndex = paint->filterQuality()->index;
    String error = _drawAtlas(paint->_objects, paint->_data, qualityIndex, atlas->_image, rstTransformBuffer, rectBuffer, colorBuffer, (blendMode or BlendModeCls::src)->index, cullRectBuffer);
    if (error != nullptr) {
        ;
    }
}

void CanvasCls::drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms) {
    assert(atlas != nullptr);
    assert(rstTransforms != nullptr);
    assert(rects != nullptr);
    assert(colors == nullptr || blendMode != nullptr);
    assert(paint != nullptr);
    int rectCount = rects->length;
    if (rstTransforms->length != rectCount)     {
        ;
    }
    if (rectCount % 4 != 0)     {
        ;
    }
    if (colors != nullptr && colors->length * 4 != rectCount)     {
        ;
    }
    int qualityIndex = paint->filterQuality()->index;
    String error = _drawAtlas(paint->_objects, paint->_data, qualityIndex, atlas->_image, rstTransforms, rects, colors, (blendMode or BlendModeCls::src)->index, cullRect?->_getValue32());
    if (error != nullptr) {
        ;
    }
}

void CanvasCls::drawShadow(Color color, double elevation, Path path, bool transparentOccluder) {
    assert(path != nullptr);
    assert(color != nullptr);
    assert(transparentOccluder != nullptr);
    _drawShadow(path, color->value, elevation, transparentOccluder);
}

Future<Image> PictureCls::toImage(int height, int width) {
    assert(!_disposed);
    if (width <= 0 || height <= 0)     {
        ;
    }
    return _futurize([=] (_Callback<Image> callback)     {
        _toImage(width, height, [=] (_Image image) {
        if (image == nullptr) {
            callback(nullptr);
        } else {
            callback(ImageCls->_(image, image->width, image->height));
        }
    });
    });
}

void PictureCls::dispose() {
    assert(!_disposed);
    assert([=] () {
        _disposed = true;
        return true;
    }());
    _dispose();
}

bool PictureCls::debugDisposed() {
    bool disposed;
    assert([=] () {
        disposed = _disposed;
        return true;
    }());
    return disposed or ();
}

PictureRecorderCls::PictureRecorderCls() {
    {
        _constructor();
    }
}

bool PictureRecorderCls::isRecording() {
    return _canvas != nullptr;
}

Picture PictureRecorderCls::endRecording() {
    if (_canvas == nullptr)     {
        ;
    }
    Picture picture = PictureCls->_();
    _endRecording(picture);
    _canvas!->_recorder = nullptr;
    _canvas = nullptr;
    return picture;
}

ShadowCls::ShadowCls(double blurRadius, Color color, Offset offset) {
    {
        assert(color != nullptr, __s("Text shadow color was null."));
        assert(offset != nullptr, __s("Text shadow offset was null."));
        assert(blurRadius >= 0.0, __s("Text shadow blur radius should be non-negative."));
    }
}

double ShadowCls::convertRadiusToSigma(double radius) {
    return radius > 0? radius * 0.57735 + 0.5 : 0;
}

double ShadowCls::blurSigma() {
    return convertRadiusToSigma(blurRadius);
}

Paint ShadowCls::toPaint() {
    auto _c1 = make<PaintCls>();_c1.color = auto _c2 = color;_c2.maskFilter = MaskFilterCls->blur(BlurStyleCls::normal, blurSigma());_c2;return _c1;
}

Shadow ShadowCls::scale(double factor) {
    return make<ShadowCls>(color, offset * factor, blurRadius * factor);
}

Shadow ShadowCls::lerp(Shadow a, Shadow b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            return a->scale(1.0 - t);
        }
    } else {
        if (a == nullptr) {
            return b->scale(t);
        } else {
            return make<ShadowCls>(ColorCls->lerp(a->color, b->color, t)!, OffsetCls->lerp(a->offset, b->offset, t)!, _lerpDouble(a->blurRadius, b->blurRadius, t));
        }
    }
}

List<Shadow> ShadowCls::lerpList(List<Shadow> a, List<Shadow> b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr)     {
        return nullptr;
    }
    a = makeList();
    b = makeList();
    List<Shadow> result = makeList();
    int commonLength = math->min(a->length(), b->length());
    for (;  < commonLength; i = 1)     {
        result->add(ShadowCls->lerp(a[i], b[i], t)!);
    }
    for (;  < a->length(); i = 1)     {
        result->add(a[i]->scale(1.0 - t));
    }
    for (;  < b->length(); i = 1)     {
        result->add(b[i]->scale(t));
    }
    return result;
}

bool ShadowCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return is<Shadow>(other) && other->color == color && other->offset == offset && other->blurRadius == blurRadius;
}

int ShadowCls::hashCode() {
    return ObjectCls->hash(color, offset, blurRadius);
}

String ShadowCls::toString() {
    return __s("TextShadow($color, $offset, $blurRadius)");
}

ByteData ShadowCls::_encodeShadows(List<Shadow> shadows) {
    if (shadows == nullptr)     {
        return make<ByteDataCls>(0);
    }
    int byteCount = shadows->length() * _kBytesPerShadow;
    ByteData shadowsData = make<ByteDataCls>(byteCount);
    int shadowOffset = 0;
    for (;  < shadows->length(); ++shadowIndex) {
        Shadow shadow = shadows[shadowIndex];
        if (shadow != nullptr) {
            shadowOffset = shadowIndex * _kBytesPerShadow;
            shadowsData->setInt32(_kColorOffset + shadowOffset, shadow->color->value ^ ShadowCls::_kColorDefault, _kFakeHostEndian);
            shadowsData->setFloat32(_kXOffset + shadowOffset, shadow->offset->dx(), _kFakeHostEndian);
            shadowsData->setFloat32(_kYOffset + shadowOffset, shadow->offset->dy(), _kFakeHostEndian);
            double blurSigma = ShadowCls->convertRadiusToSigma(shadow->blurRadius);
            shadowsData->setFloat32(_kBlurOffset + shadowOffset, blurSigma, _kFakeHostEndian);
        }
    }
    return shadowsData;
}

Future<ImmutableBuffer> ImmutableBufferCls::fromUint8List(Uint8List list) {
    ImmutableBuffer instance = ImmutableBufferCls->_(list->length);
    return _futurize([=] (_Callback<void> callback) {
        instance->_init(list, callback);
    })->then([=] ()     {
        instance;
    });
}

Future<ImmutableBuffer> ImmutableBufferCls::fromAsset(String assetKey) {
    String encodedKey = make<UriCls>(UriCls->encodeFull(assetKey))->path;
    ImmutableBuffer instance = ImmutableBufferCls->_(0);
    auto _c1 = instance;_c1._length = length;return _futurize([=] (_Callback<int> callback) {
        return instance->_initFromAsset(encodedKey, callback);
    })->then([=] (int length)     {
        _c1;
    });
}

int ImmutableBufferCls::length() {
    return _length;
}

bool ImmutableBufferCls::debugDisposed() {
    bool disposed;
    assert([=] () {
        disposed = _debugDisposed;
        return true;
    }());
    return disposed;
}

void ImmutableBufferCls::dispose() {
    assert([=] () {
        assert(!_debugDisposed);
        _debugDisposed = true;
        return true;
    }());
    _dispose();
}

Future<ImageDescriptor> ImageDescriptorCls::encoded(ImmutableBuffer buffer) {
    ImageDescriptor descriptor = ImageDescriptorCls->_();
    return _futurize([=] (_Callback<void> callback) {
        return descriptor->_initEncoded(buffer, callback);
    })->then([=] ()     {
        descriptor;
    });
}

void ImageDescriptorCls::raw(ImmutableBuffer buffer, int height, PixelFormat pixelFormat, int rowBytes, int width) {
    _width = width;
    _height = height;
    _bytesPerPixel = 4;
    _initRaw(this, buffer, width, height, rowBytes or -1, pixelFormat->index);
}

int ImageDescriptorCls::width() {
    return _width ??= _getWidth();
}

int ImageDescriptorCls::height() {
    return _height ??= _getHeight();
}

int ImageDescriptorCls::bytesPerPixel() {
    return _bytesPerPixel ??= _getBytesPerPixel();
}

Future<Codec> ImageDescriptorCls::instantiateCodec(int targetHeight, int targetWidth) {
    if (targetWidth != nullptr && targetWidth <= 0) {
        targetWidth = nullptr;
    }
    if (targetHeight != nullptr && targetHeight <= 0) {
        targetHeight = nullptr;
    }
    if (targetWidth == nullptr && targetHeight == nullptr) {
        targetWidth = width();
        targetHeight = height();
    } else     {
        if (targetWidth == nullptr && targetHeight != nullptr) {
        targetWidth = (targetHeight * (width() / height()))->round();
        targetHeight = targetHeight;
    } else     {
        if (targetHeight == nullptr && targetWidth != nullptr) {
        targetWidth = targetWidth;
        targetHeight = targetWidth ~/ (width() / height());
    }
;
    };
    }    assert(targetWidth != nullptr);
    assert(targetHeight != nullptr);
    Codec codec = CodecCls->_();
    _instantiateCodec(codec, targetWidth!, targetHeight!);
    return codec;
}

Future<T> _futurizetemplate<typename T> (_Callbacker<T> callbacker) {
    Completer<T> completer = <T>sync();
    bool sync = true;
    String error = callbacker([=] (T t) {
    if (t == nullptr) {
        if (sync) {
            ;
        } else {
            completer->completeError(make<ExceptionCls>(__s("operation failed")));
        }
    } else {
        completer->complete(t);
    }
});
    sync = false;
    if (error != nullptr)     {
        ;
    }
    return completer->future;
}

String PictureRasterizationExceptionCls::toString() {
    StringBuffer buffer = make<StringBufferCls>(__s("Failed to rasterize a picture: $message."));
    if (stack != nullptr) {
        buffer->writeln();
        buffer->writeln(__s("The callstack when the image was created was:"));
        buffer->writeln(stack!->toString());
    }
    return buffer->toString();
}
