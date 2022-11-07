#include "painting.hpp"
bool _rectIsValid(Rect rect) {
    assert(rect != nullptr, "Rect argument was null.");
    assert(!rect.hasNaN, "Rect argument contained a NaN value.");
    return true;
}

bool _rrectIsValid(RRect rrect) {
    assert(rrect != nullptr, "RRect argument was null.");
    assert(!rrect.hasNaN, "RRect argument contained a NaN value.");
    return true;
}

bool _offsetIsValid(Offset offset) {
    assert(offset != nullptr, "Offset argument was null.");
    assert(!offset.dx.isNaN && !offset.dy.isNaN, "Offset argument contained a NaN value.");
    return true;
}

bool _matrix4IsValid(Float64List matrix4) {
    assert(matrix4 != nullptr, "Matrix4 argument was null.");
    assert(matrix4.length == 16, "Matrix4 must have 16 entries.");
    assert(matrix4.every(), "Matrix4 entries must be finite.");
    return true;
}

bool _radiusIsValid(Radius radius) {
    assert(radius != nullptr, "Radius argument was null.");
    assert(!radius.x.isNaN && !radius.y.isNaN, "Radius argument contained a NaN value.");
    return true;
}

Color _scaleAlpha(Color a, double factor) {
    return a.withAlpha((a.alpha * factor).round().clamp(0, 255));
}

Color::Color(int value) {
    {
        value = value & 0xFFFFFFFF;
    }
}

void Color::fromARGB(int a, int b, int g, int r)

void Color::fromRGBO(int b, int g, double opacity, int r)

int Color::alpha() {
    return (0xff000000 & value) >> 24;
}

double Color::opacity() {
    return alpha / 0xFF;
}

int Color::red() {
    return (0x00ff0000 & value) >> 16;
}

int Color::green() {
    return (0x0000ff00 & value) >> 8;
}

int Color::blue() {
    return (0x000000ff & value) >> 0;
}

Color Color::withAlpha(int a) {
    return Color.fromARGB(a, red, green, blue);
}

Color Color::withOpacity(double opacity) {
    assert(opacity >= 0.0 && opacity <= 1.0);
    return withAlpha((255.0 * opacity).round());
}

Color Color::withRed(int r) {
    return Color.fromARGB(alpha, r, green, blue);
}

Color Color::withGreen(int g) {
    return Color.fromARGB(alpha, red, g, blue);
}

Color Color::withBlue(int b) {
    return Color.fromARGB(alpha, red, green, b);
}

double Color::computeLuminance() {
    double R = _linearizeColorComponent(red / 0xFF);
    double G = _linearizeColorComponent(green / 0xFF);
    double B = _linearizeColorComponent(blue / 0xFF);
    return 0.2126 * R + 0.7152 * G + 0.0722 * B;
}

Color Color::lerp(Color a, Color b, double t) {
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
            return Color.fromARGB(_clampInt(_lerpInt(a.alpha, b.alpha, t).toInt(), 0, 255), _clampInt(_lerpInt(a.red, b.red, t).toInt(), 0, 255), _clampInt(_lerpInt(a.green, b.green, t).toInt(), 0, 255), _clampInt(_lerpInt(a.blue, b.blue, t).toInt(), 0, 255));
        }
    }
}

Color Color::alphaBlend(Color background, Color foreground) {
    int alpha = foreground.alpha;
    if (alpha == 0x00) {
        return background;
    }
    int invAlpha = 0xff - alpha;
    int backAlpha = background.alpha;
    if (backAlpha == 0xff) {
        return Color.fromARGB(0xff, (alpha * foreground.red + invAlpha * background.red) ~/ 0xff, (alpha * foreground.green + invAlpha * background.green) ~/ 0xff, (alpha * foreground.blue + invAlpha * background.blue) ~/ 0xff);
    } else {
        backAlpha = (backAlpha * invAlpha) ~/ 0xff;
        int outAlpha = alpha + backAlpha;
        assert(outAlpha != 0x00);
        return Color.fromARGB(outAlpha, (foreground.red * alpha + background.red * backAlpha) ~/ outAlpha, (foreground.green * alpha + background.green * backAlpha) ~/ outAlpha, (foreground.blue * alpha + background.blue * backAlpha) ~/ outAlpha);
    }
}

int Color::getAlphaFromOpacity(double opacity) {
    assert(opacity != nullptr);
    return (opacity.clamp(0.0, 1.0) * 255).round();
}

bool Color::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is Color && other.value == value;
}

int Color::hashCode() {
    return value.hashCode;
}

String Color::toString() {
    return "Color(0x${value.toRadixString(16).padLeft(8, '0')})";
}

double Color::_linearizeColorComponent(double component) {
    if (component <= 0.03928)     {
        return component / 12.92;
    }
    return (;
}

Paint::Paint() {
    {
        if (enableDithering) {
            _dither = true;
        }
    }
}

bool Paint::isAntiAlias() {
    return _data.getInt32(_kIsAntiAliasOffset, _kFakeHostEndian) == 0;
}

void Paint::isAntiAlias(bool value) {
    int encoded = value? 0 : 1;
    _data.setInt32(_kIsAntiAliasOffset, encoded, _kFakeHostEndian);
}

Color Paint::color() {
    int encoded = _data.getInt32(_kColorOffset, _kFakeHostEndian);
    return Color(encoded ^ _kColorDefault);
}

void Paint::color(Color value) {
    assert(value != nullptr);
    int encoded = value.value ^ _kColorDefault;
    _data.setInt32(_kColorOffset, encoded, _kFakeHostEndian);
}

BlendMode Paint::blendMode() {
    int encoded = _data.getInt32(_kBlendModeOffset, _kFakeHostEndian);
    return BlendMode.values[encoded ^ _kBlendModeDefault];
}

void Paint::blendMode(BlendMode value) {
    assert(value != nullptr);
    int encoded = value.index ^ _kBlendModeDefault;
    _data.setInt32(_kBlendModeOffset, encoded, _kFakeHostEndian);
}

PaintingStyle Paint::style() {
    return PaintingStyle.values[_data.getInt32(_kStyleOffset, _kFakeHostEndian)];
}

void Paint::style(PaintingStyle value) {
    assert(value != nullptr);
    int encoded = value.index;
    _data.setInt32(_kStyleOffset, encoded, _kFakeHostEndian);
}

double Paint::strokeWidth() {
    return _data.getFloat32(_kStrokeWidthOffset, _kFakeHostEndian);
}

void Paint::strokeWidth(double value) {
    assert(value != nullptr);
    double encoded = value;
    _data.setFloat32(_kStrokeWidthOffset, encoded, _kFakeHostEndian);
}

StrokeCap Paint::strokeCap() {
    return StrokeCap.values[_data.getInt32(_kStrokeCapOffset, _kFakeHostEndian)];
}

void Paint::strokeCap(StrokeCap value) {
    assert(value != nullptr);
    int encoded = value.index;
    _data.setInt32(_kStrokeCapOffset, encoded, _kFakeHostEndian);
}

StrokeJoin Paint::strokeJoin() {
    return StrokeJoin.values[_data.getInt32(_kStrokeJoinOffset, _kFakeHostEndian)];
}

void Paint::strokeJoin(StrokeJoin value) {
    assert(value != nullptr);
    int encoded = value.index;
    _data.setInt32(_kStrokeJoinOffset, encoded, _kFakeHostEndian);
}

double Paint::strokeMiterLimit() {
    return _data.getFloat32(_kStrokeMiterLimitOffset, _kFakeHostEndian);
}

void Paint::strokeMiterLimit(double value) {
    assert(value != nullptr);
    double encoded = value - _kStrokeMiterLimitDefault;
    _data.setFloat32(_kStrokeMiterLimitOffset, encoded, _kFakeHostEndian);
}

MaskFilter Paint::maskFilter() {
    ;
    return nullptr;
}

void Paint::maskFilter(MaskFilter value) {
    if (value == nullptr) {
        _data.setInt32(_kMaskFilterOffset, MaskFilter._TypeNone, _kFakeHostEndian);
        _data.setInt32(_kMaskFilterBlurStyleOffset, 0, _kFakeHostEndian);
        _data.setFloat32(_kMaskFilterSigmaOffset, 0.0, _kFakeHostEndian);
    } else {
        _data.setInt32(_kMaskFilterOffset, MaskFilter._TypeBlur, _kFakeHostEndian);
        _data.setInt32(_kMaskFilterBlurStyleOffset, value._style.index, _kFakeHostEndian);
        _data.setFloat32(_kMaskFilterSigmaOffset, value._sigma, _kFakeHostEndian);
    }
}

FilterQuality Paint::filterQuality() {
    return FilterQuality.values[_data.getInt32(_kFilterQualityOffset, _kFakeHostEndian)];
}

void Paint::filterQuality(FilterQuality value) {
    assert(value != nullptr);
    int encoded = value.index;
    _data.setInt32(_kFilterQualityOffset, encoded, _kFakeHostEndian);
}

Shader Paint::shader() {
    return (;
}

void Paint::shader(Shader value) {
    _ensureObjectsInitialized()[_kShaderIndex] = value;
}

ColorFilter Paint::colorFilter() {
    _ColorFilter nativeFilter = (;
    return nativeFilter?.creator;
}

void Paint::colorFilter(ColorFilter value) {
    _ColorFilter nativeFilter = value?._toNativeColorFilter();
    if (nativeFilter == nullptr) {
        if (_objects != nullptr) {
            _objects![_kColorFilterIndex] = nullptr;
        }
    } else {
        _ensureObjectsInitialized()[_kColorFilterIndex] = nativeFilter;
    }
}

ImageFilter Paint::imageFilter() {
    _ImageFilter nativeFilter = (;
    return nativeFilter?.creator;
}

void Paint::imageFilter(ImageFilter value) {
    if (value == nullptr) {
        if (_objects != nullptr) {
            _objects![_kImageFilterIndex] = nullptr;
        }
    } else {
        List<Object> objects = _ensureObjectsInitialized();
        _ImageFilter imageFilter = (;
        if (imageFilter?.creator != value) {
            objects[_kImageFilterIndex] = value._toNativeImageFilter();
        }
    }
}

bool Paint::invertColors() {
    return _data.getInt32(_kInvertColorOffset, _kFakeHostEndian) == 1;
}

void Paint::invertColors(bool value) {
    _data.setInt32(_kInvertColorOffset, value? 1 : 0, _kFakeHostEndian);
}

String Paint::toString() {
    if (const bool.fromEnvironment("dart.vm.product"false)) {
        return super.toString();
    }
    StringBuffer result = StringBuffer();
    String semicolon = "";
    result.write("Paint(");
    if (style == PaintingStyle.stroke) {
        result.write("$style");
        if (strokeWidth != 0.0)         {
            result.write(" ${strokeWidth.toStringAsFixed(1)}");
        } else         {
            result.write(" hairline");
        }
        if (strokeCap != StrokeCap.butt)         {
            result.write(" $strokeCap");
        }
        if (strokeJoin == StrokeJoin.miter) {
            if (strokeMiterLimit != _kStrokeMiterLimitDefault)             {
                result.write(" $strokeJoin up to ${strokeMiterLimit.toStringAsFixed(1)}");
            }
        } else {
            result.write(" $strokeJoin");
        }
        semicolon = "; ";
    }
    if (isAntiAlias != true) {
        result.write("${semicolon}antialias off");
        semicolon = "; ";
    }
    if (color != const Color(_kColorDefault)) {
        result.write("$semicolon$color");
        semicolon = "; ";
    }
    if (blendMode.index != _kBlendModeDefault) {
        result.write("$semicolon$blendMode");
        semicolon = "; ";
    }
    if (colorFilter != nullptr) {
        result.write("${semicolon}colorFilter: $colorFilter");
        semicolon = "; ";
    }
    if (maskFilter != nullptr) {
        result.write("${semicolon}maskFilter: $maskFilter");
        semicolon = "; ";
    }
    if (filterQuality != FilterQuality.none) {
        result.write("${semicolon}filterQuality: $filterQuality");
        semicolon = "; ";
    }
    if (shader != nullptr) {
        result.write("${semicolon}shader: $shader");
        semicolon = "; ";
    }
    if (imageFilter != nullptr) {
        result.write("${semicolon}imageFilter: $imageFilter");
        semicolon = "; ";
    }
    if (invertColors)     {
        result.write("${semicolon}invert: $invertColors");
    }
    if (_dither)     {
        result.write("${semicolon}dither: $_dither");
    }
    result.write(")");
    return result.toString();
}

List<Object> Paint::_ensureObjectsInitialized() {
    return _objects ??= <Object>filled(_kObjectCount, nullptrfalse);
}

bool Paint::_dither() {
    return _data.getInt32(_kDitherOffset, _kFakeHostEndian) == 1;
}

void Paint::_dither(bool value) {
    _data.setInt32(_kDitherOffset, value? 1 : 0, _kFakeHostEndian);
}

void Image::dispose() {
    assert(!_disposed && !_image._disposed);
    assert(_image._handles.contains(this));
    _disposed = true;
    bool removed = _image._handles.remove(this);
    assert(removed);
    if (_image._handles.isEmpty) {
        _image.dispose();
    }
}

bool Image::debugDisposed() {
    bool disposed;
    assert(());
    return disposed ?? ();
}

Future<ByteData> Image::toByteData(ImageByteFormat format) {
    assert(!_disposed && !_image._disposed);
    return _image.toByteData(format);
}

List<StackTrace> Image::debugGetOpenHandleStackTraces() {
    List<StackTrace> stacks;
    assert(());
    return stacks;
}

Image Image::clone() {
    if (_disposed) {
        ;
    }
    assert(!_image._disposed);
    return Image._(_image, width, height);
}

bool Image::isCloneOf(Image other) {
    return other._image == _image;
}

String Image::toString() {
    return _image.toString();
}

void Image::_(_Image _image, int height, int width) {
    assert(());
    _image._handles.add(this);
}

Future<ByteData> _Image::toByteData(ImageByteFormat format) {
    return _futurize();
}

void _Image::dispose() {
    assert(!_disposed);
    assert(_handles.isEmpty, "Attempted to dispose of an Image object that has ${_handles.length} open handles.\nIf you see this, it is a bug in dart:ui. Please file an issue at https://github.com/flutter/flutter/issues/new.");
    _disposed = true;
    _dispose();
}

String _Image::toString() {
    return "[$width\u00D7$height]";
}

int Codec::frameCount() {
    return _cachedFrameCount ??= _frameCount;
}

int Codec::repetitionCount() {
    return _cachedRepetitionCount ??= _repetitionCount;
}

Future<FrameInfo> Codec::getNextFrame() {
    Completer<FrameInfo> completer = <FrameInfo>sync();
    String error = _getNextFrame();
    if (error != nullptr) {
        ;
    }
    return completer.future;
}

Future<Codec> instantiateImageCodec(bool allowUpscaling, Uint8List list, int targetHeight, int targetWidth) {
    ImmutableBuffer buffer = await ImmutableBuffer.fromUint8List(list);
    return instantiateImageCodecFromBuffer(buffertargetWidth, targetHeight, allowUpscaling);
}

Future<Codec> instantiateImageCodecFromBuffer(bool allowUpscaling, ImmutableBuffer buffer, int targetHeight, int targetWidth) {
    ImageDescriptor descriptor = await ImageDescriptor.encoded(buffer);
    if (!allowUpscaling) {
        if (targetWidth != nullptr && targetWidth > descriptor.width) {
            targetWidth = descriptor.width;
        }
        if (targetHeight != nullptr && targetHeight > descriptor.height) {
            targetHeight = descriptor.height;
        }
    }
    buffer.dispose();
    return descriptor.instantiateCodec(targetWidth, targetHeight);
}

void decodeImageFromList(ImageDecoderCallback callback, Uint8List list) {
    _decodeImageFromListAsync(list, callback);
}

Future<void> _decodeImageFromListAsync(ImageDecoderCallback callback, Uint8List list) {
    Codec codec = await instantiateImageCodec(list);
    FrameInfo frameInfo = await codec.getNextFrame();
    callback(frameInfo.image);
}

void decodeImageFromPixels(bool allowUpscaling, ImageDecoderCallback callback, PixelFormat format, int height, Uint8List pixels, int rowBytes, int targetHeight, int targetWidth, int width) {
    if (targetWidth != nullptr) {
        assert(allowUpscaling || targetWidth <= width);
    }
    if (targetHeight != nullptr) {
        assert(allowUpscaling || targetHeight <= height);
    }
    ImmutableBuffer.fromUint8List(pixels).then();
}

Path::Path() {
    {
        _constructor();
    }
}

void Path::from(Path source) {
    Path clonedPath = Path._();
    source._clone(clonedPath);
    return clonedPath;
}

PathFillType Path::fillType() {
    return PathFillType.values[_getFillType()];
}

void Path::fillType(PathFillType value) {
    return _setFillType(value.index);
}

void Path::arcTo(bool forceMoveTo, Rect rect, double startAngle, double sweepAngle) {
    assert(_rectIsValid(rect));
    _arcTo(rect.left, rect.top, rect.right, rect.bottom, startAngle, sweepAngle, forceMoveTo);
}

void Path::arcToPoint(Offset arcEnd, bool clockwise, bool largeArc, Radius radius, double rotation) {
    assert(_offsetIsValid(arcEnd));
    assert(_radiusIsValid(radius));
    _arcToPoint(arcEnd.dx, arcEnd.dy, radius.x, radius.y, rotation, largeArc, clockwise);
}

void Path::relativeArcToPoint(Offset arcEndDelta, bool clockwise, bool largeArc, Radius radius, double rotation) {
    assert(_offsetIsValid(arcEndDelta));
    assert(_radiusIsValid(radius));
    _relativeArcToPoint(arcEndDelta.dx, arcEndDelta.dy, radius.x, radius.y, rotation, largeArc, clockwise);
}

void Path::addRect(Rect rect) {
    assert(_rectIsValid(rect));
    _addRect(rect.left, rect.top, rect.right, rect.bottom);
}

void Path::addOval(Rect oval) {
    assert(_rectIsValid(oval));
    _addOval(oval.left, oval.top, oval.right, oval.bottom);
}

void Path::addArc(Rect oval, double startAngle, double sweepAngle) {
    assert(_rectIsValid(oval));
    _addArc(oval.left, oval.top, oval.right, oval.bottom, startAngle, sweepAngle);
}

void Path::addPolygon(bool close, List<Offset> points) {
    assert(points != nullptr);
    _addPolygon(_encodePointList(points), close);
}

void Path::addRRect(RRect rrect) {
    assert(_rrectIsValid(rrect));
    _addRRect(rrect._getValue32());
}

void Path::addPath(Float64List matrix4, Offset offset, Path path) {
    assert(path != nullptr);
    assert(_offsetIsValid(offset));
    if (matrix4 != nullptr) {
        assert(_matrix4IsValid(matrix4));
        _addPathWithMatrix(path, offset.dx, offset.dy, matrix4);
    } else {
        _addPath(path, offset.dx, offset.dy);
    }
}

void Path::extendWithPath(Float64List matrix4, Offset offset, Path path) {
    assert(path != nullptr);
    assert(_offsetIsValid(offset));
    if (matrix4 != nullptr) {
        assert(_matrix4IsValid(matrix4));
        _extendWithPathAndMatrix(path, offset.dx, offset.dy, matrix4);
    } else {
        _extendWithPath(path, offset.dx, offset.dy);
    }
}

bool Path::contains(Offset point) {
    assert(_offsetIsValid(point));
    return _contains(point.dx, point.dy);
}

Path Path::shift(Offset offset) {
    assert(_offsetIsValid(offset));
    Path path = Path._();
    _shift(path, offset.dx, offset.dy);
    return path;
}

Path Path::transform(Float64List matrix4) {
    assert(_matrix4IsValid(matrix4));
    Path path = Path._();
    _transform(path, matrix4);
    return path;
}

Rect Path::getBounds() {
    Float32List rect = _getBounds();
    return Rect.fromLTRB(rect[0], rect[1], rect[2], rect[3]);
}

Path Path::combine(PathOperation operation, Path path1, Path path2) {
    assert(path1 != nullptr);
    assert(path2 != nullptr);
    Path path = Path();
    if (path._op(path1, path2, operation.index)) {
        return path;
    }
    ;
}

PathMetrics Path::computeMetrics(bool forceClosed) {
    return PathMetrics._(this, forceClosed);
}

Tangent::Tangent(Offset position, Offset vector) {
    {
        assert(position != nullptr);
        assert(vector != nullptr);
    }
}

void Tangent::fromAngle(double angle, Offset position) {
    return Tangent(position, Offset(math.cos(angle), math.sin(angle)));
}

double Tangent::angle() {
    return -math.atan2(vector.dy, vector.dx);
}

Iterator<PathMetric> PathMetrics::iterator() {
    return _iterator;
}

void PathMetrics::_(bool forceClosed, Path path)

PathMetric PathMetricIterator::current() {
    PathMetric currentMetric = _pathMetric;
    if (currentMetric == nullptr) {
        ;
    }
    return currentMetric;
}

bool PathMetricIterator::moveNext() {
    if (_pathMeasure._nextContour()) {
        _pathMetric = PathMetric._(_pathMeasure);
        return true;
    }
    _pathMetric = nullptr;
    return false;
}

void PathMetricIterator::_(_PathMeasure _pathMeasure)

Tangent PathMetric::getTangentForOffset(double distance) {
    return _measure.getTangentForOffset(contourIndex, distance);
}

Path PathMetric::extractPath(double end, double start, bool startWithMoveTo) {
    return _measure.extractPath(contourIndex, start, endstartWithMoveTo);
}

String PathMetric::toString() {
    return "$runtimeType{length: $length, isClosed: $isClosed, contourIndex:$contourIndex}";
}

void PathMetric::_(_PathMeasure _measure)

double _PathMeasure::length(int contourIndex) {
    assert(contourIndex <= currentContourIndex, "Iterator must be advanced before index $contourIndex can be used.");
    return _length(contourIndex);
}

Tangent _PathMeasure::getTangentForOffset(int contourIndex, double distance) {
    assert(contourIndex <= currentContourIndex, "Iterator must be advanced before index $contourIndex can be used.");
    Float32List posTan = _getPosTan(contourIndex, distance);
    if (posTan[0] == 0.0) {
        return nullptr;
    } else {
        return Tangent(Offset(posTan[1], posTan[2]), Offset(posTan[3], posTan[4]));
    }
}

Path _PathMeasure::extractPath(int contourIndex, double end, double start, bool startWithMoveTo) {
    assert(contourIndex <= currentContourIndex, "Iterator must be advanced before index $contourIndex can be used.");
    Path path = Path._();
    _extractPath(path, contourIndex, start, endstartWithMoveTo);
    return path;
}

bool _PathMeasure::isClosed(int contourIndex) {
    assert(contourIndex <= currentContourIndex, "Iterator must be advanced before index $contourIndex can be used.");
    return _isClosed(contourIndex);
}

_PathMeasure::_PathMeasure(bool forceClosed, Path path) {
    {
        _constructor(path, forceClosed);
    }
}

bool _PathMeasure::_nextContour() {
    bool next = _nativeNextContour();
    if (next) {
        currentContourIndex++;
    }
    return next;
}

void MaskFilter::blur(double _sigma, BlurStyle _style)

bool MaskFilter::==(Object other) {
    return other is MaskFilter && other._style == _style && other._sigma == _sigma;
}

int MaskFilter::hashCode() {
    return Object.hash(_style, _sigma);
}

String MaskFilter::toString() {
    return "MaskFilter.blur($_style, ${_sigma.toStringAsFixed(1)})";
}

void ColorFilter::mode(BlendMode blendMode, Color color)

void ColorFilter::matrix(List<double> matrix)

void ColorFilter::linearToSrgbGamma()

void ColorFilter::srgbToLinearGamma()

bool ColorFilter::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is ColorFilter && other._type == _type && <double>_listEquals(other._matrix, _matrix) && other._color == _color && other._blendMode == _blendMode;
}

int ColorFilter::hashCode() {
    return Object.hash(_color, _blendMode, _matrix == nullptr? nullptr : Object.hashAll(_matrix!), _type);
}

String ColorFilter::toString() {
    ;
}

_ImageFilter ColorFilter::_toNativeImageFilter() {
    return _ImageFilter.fromColorFilter(this);
}

_ColorFilter ColorFilter::_toNativeColorFilter() {
    ;
}

String ColorFilter::_shortDescription() {
    ;
}

void _ColorFilter::mode(ColorFilter creator) {
    _constructor();
    _initMode(creator._color!.value, creator._blendMode!.index);
}

void _ColorFilter::matrix(ColorFilter creator) {
    _constructor();
    _initMatrix(Float32List.fromList(creator._matrix!));
}

void _ColorFilter::linearToSrgbGamma(ColorFilter creator) {
    _constructor();
    _initLinearToSrgbGamma();
}

void _ColorFilter::srgbToLinearGamma(ColorFilter creator) {
    _constructor();
    _initSrgbToLinearGamma();
}

void ImageFilter::blur(double sigmaX, double sigmaY, TileMode tileMode) {
    assert(sigmaX != nullptr);
    assert(sigmaY != nullptr);
    assert(tileMode != nullptr);
    return _GaussianBlurImageFilter(sigmaX, sigmaY, tileMode);
}

void ImageFilter::dilate(double radiusX, double radiusY) {
    assert(radiusX != nullptr);
    assert(radiusY != nullptr);
    return _DilateImageFilter(radiusX, radiusY);
}

void ImageFilter::erode(double radiusX, double radiusY) {
    assert(radiusX != nullptr);
    assert(radiusY != nullptr);
    return _ErodeImageFilter(radiusX, radiusY);
}

void ImageFilter::matrix(FilterQuality filterQuality, Float64List matrix4) {
    assert(matrix4 != nullptr);
    assert(filterQuality != nullptr);
    if (matrix4.length != 16)     {
        ;
    }
    return _MatrixImageFilter(Float64List.fromList(matrix4), filterQuality);
}

void ImageFilter::compose(ImageFilter inner, ImageFilter outer) {
    assert(inner != nullptr && outer != nullptr);
    return _ComposeImageFilter(inner, outer);
}

String _MatrixImageFilter::toString() {
    return "ImageFilter.matrix($data, $filterQuality)";
}

bool _MatrixImageFilter::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is _MatrixImageFilter && other.filterQuality == filterQuality && <double>_listEquals(other.data, data);
}

int _MatrixImageFilter::hashCode() {
    return Object.hash(filterQuality, Object.hashAll(data));
}

_ImageFilter _MatrixImageFilter::_toNativeImageFilter() {
    return nativeFilter;
}

String _MatrixImageFilter::_shortDescription() {
    return "matrix($data, $filterQuality)";
}

String _GaussianBlurImageFilter::toString() {
    return "ImageFilter.blur($sigmaX, $sigmaY, $_modeString)";
}

bool _GaussianBlurImageFilter::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is _GaussianBlurImageFilter && other.sigmaX == sigmaX && other.sigmaY == sigmaY && other.tileMode == tileMode;
}

int _GaussianBlurImageFilter::hashCode() {
    return Object.hash(sigmaX, sigmaY);
}

_ImageFilter _GaussianBlurImageFilter::_toNativeImageFilter() {
    return nativeFilter;
}

String _GaussianBlurImageFilter::_modeString() {
    ;
}

String _GaussianBlurImageFilter::_shortDescription() {
    return "blur($sigmaX, $sigmaY, $_modeString)";
}

String _DilateImageFilter::toString() {
    return "ImageFilter.dilate($radiusX, $radiusY)";
}

bool _DilateImageFilter::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is _DilateImageFilter && other.radiusX == radiusX && other.radiusY == radiusY;
}

int _DilateImageFilter::hashCode() {
    return Object.hash(radiusX, radiusY);
}

_ImageFilter _DilateImageFilter::_toNativeImageFilter() {
    return nativeFilter;
}

String _DilateImageFilter::_shortDescription() {
    return "dilate($radiusX, $radiusY)";
}

String _ErodeImageFilter::toString() {
    return "ImageFilter.erode($radiusX, $radiusY)";
}

bool _ErodeImageFilter::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is _ErodeImageFilter && other.radiusX == radiusX && other.radiusY == radiusY;
}

int _ErodeImageFilter::hashCode() {
    return hashValues(radiusX, radiusY);
}

_ImageFilter _ErodeImageFilter::_toNativeImageFilter() {
    return nativeFilter;
}

String _ErodeImageFilter::_shortDescription() {
    return "erode($radiusX, $radiusY)";
}

String _ComposeImageFilter::toString() {
    return "ImageFilter.compose(source -> $_shortDescription -> result)";
}

bool _ComposeImageFilter::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is _ComposeImageFilter && other.innerFilter == innerFilter && other.outerFilter == outerFilter;
}

int _ComposeImageFilter::hashCode() {
    return Object.hash(innerFilter, outerFilter);
}

_ImageFilter _ComposeImageFilter::_toNativeImageFilter() {
    return nativeFilter;
}

String _ComposeImageFilter::_shortDescription() {
    return "${innerFilter._shortDescription} -> ${outerFilter._shortDescription}";
}

void _ImageFilter::blur(_GaussianBlurImageFilter filter) {
    _constructor();
    _initBlur(filter.sigmaX, filter.sigmaY, filter.tileMode.index);
}

void _ImageFilter::dilate(_DilateImageFilter filter) {
    _constructor();
    _initDilate(filter.radiusX, filter.radiusY);
}

void _ImageFilter::erode(_ErodeImageFilter filter) {
    _constructor();
    _initErode(filter.radiusX, filter.radiusY);
}

void _ImageFilter::matrix(_MatrixImageFilter filter) {
    if (filter.data.length != 16)     {
        ;
    }
    _constructor();
    _initMatrix(filter.data, filter.filterQuality.index);
}

void _ImageFilter::fromColorFilter(ColorFilter filter) {
    _constructor();
    _ColorFilter nativeFilter = filter._toNativeColorFilter();
    _initColorFilter(nativeFilter!);
}

void _ImageFilter::composed(_ComposeImageFilter filter) {
    _constructor();
    _ImageFilter nativeFilterInner = filter.innerFilter._toNativeImageFilter();
    _ImageFilter nativeFilterOuter = filter.outerFilter._toNativeImageFilter();
    _initComposed(nativeFilterOuter, nativeFilterInner);
}

Int32List _encodeColorList(List<Color> colors) {
    int colorCount = colors.length;
    Int32List result = Int32List(colorCount);
    for (;  < colorCount; ++i)     {
        result[i] = colors[i].value;
    }
    return result;
}

Float32List _encodePointList(List<Offset> points) {
    assert(points != nullptr);
    int pointCount = points.length;
    Float32List result = Float32List(pointCount * 2);
    for (;  < pointCount; ++i) {
        int xIndex = i * 2;
        int yIndex = xIndex + 1;
        Offset point = points[i];
        assert(_offsetIsValid(point));
        result[xIndex] = point.dx;
        result[yIndex] = point.dy;
    }
    return result;
}

Float32List _encodeTwoPoints(Offset pointA, Offset pointB) {
    assert(_offsetIsValid(pointA));
    assert(_offsetIsValid(pointB));
    Float32List result = Float32List(4);
    result[0] = pointA.dx;
    result[1] = pointA.dy;
    result[2] = pointB.dx;
    result[3] = pointB.dy;
    return result;
}

void Gradient::linear(List<double> colorStops, List<Color> colors, Offset from, Float64List matrix4, TileMode tileMode, Offset to) {
    _validateColorStops(colors, colorStops);
    Float32List endPointsBuffer = _encodeTwoPoints(from, to);
    Int32List colorsBuffer = _encodeColorList(colors);
    Float32List colorStopsBuffer = colorStops == nullptr? nullptr : Float32List.fromList(colorStops);
    _constructor();
    _initLinear(endPointsBuffer, colorsBuffer, colorStopsBuffer, tileMode.index, matrix4);
}

void Gradient::radial(Offset center, List<double> colorStops, List<Color> colors, Offset focal, double focalRadius, Float64List matrix4, double radius, TileMode tileMode) {
    _validateColorStops(colors, colorStops);
    Int32List colorsBuffer = _encodeColorList(colors);
    Float32List colorStopsBuffer = colorStops == nullptr? nullptr : Float32List.fromList(colorStops);
    if (focal == nullptr || (focal == center && focalRadius == 0.0)) {
        _constructor();
        _initRadial(center.dx, center.dy, radius, colorsBuffer, colorStopsBuffer, tileMode.index, matrix4);
    } else {
        assert(center != Offset.zero || focal != Offset.zero);
        _constructor();
        _initConical(focal.dx, focal.dy, focalRadius, center.dx, center.dy, radius, colorsBuffer, colorStopsBuffer, tileMode.index, matrix4);
    }
}

void Gradient::sweep(Offset center, List<double> colorStops, List<Color> colors, double endAngle, Float64List matrix4, double startAngle, TileMode tileMode) {
    _validateColorStops(colors, colorStops);
    Int32List colorsBuffer = _encodeColorList(colors);
    Float32List colorStopsBuffer = colorStops == nullptr? nullptr : Float32List.fromList(colorStops);
    _constructor();
    _initSweep(center.dx, center.dy, colorsBuffer, colorStopsBuffer, tileMode.index, startAngle, endAngle, matrix4);
}

void Gradient::_validateColorStops(List<double> colorStops, List<Color> colors) {
    if (colorStops == nullptr) {
        if (colors.length != 2)         {
            ;
        }
    } else {
        if (colors.length != colorStops.length)         {
            ;
        }
    }
}

ImageShader::ImageShader(FilterQuality filterQuality, Image image, Float64List matrix4, TileMode tmx, TileMode tmy) {
    {
        assert(image != nullptr);
        assert(tmx != nullptr);
        assert(tmy != nullptr);
        assert(matrix4 != nullptr);
        super._();
    }
    {
        if (matrix4.length != 16)         {
            ;
        }
        _constructor();
        String error = _initWithImage(image._image, tmx.index, tmy.index, filterQuality?.index ?? -1, matrix4);
        if (error != nullptr) {
            ;
        }
    }
}

Future<FragmentProgram> FragmentProgram::compile(bool debugPrint, ByteBuffer spirv) {
    return <FragmentProgram>microtask();
}

Shader FragmentProgram::shader(Float32List floatUniforms, List<ImageShader> samplerUniforms) {
    if (floatUniforms == nullptr) {
        floatUniforms = Float32List(_uniformFloatCount);
    }
    if (floatUniforms.length != _uniformFloatCount) {
        ;
    }
    if (_samplerCount > 0 && (samplerUniforms == nullptr || samplerUniforms.length != _samplerCount)) {
        ;
    }
    if (samplerUniforms == nullptr) {
        samplerUniforms = ;
    } else {
        samplerUniforms = ;
    }
    _FragmentShader shader = _FragmentShader(this, Float32List.fromList(floatUniforms), samplerUniforms);
    _shader(shader, floatUniforms, samplerUniforms);
    return shader;
}

void FragmentProgram::_(bool debugPrint, ByteBuffer spirv) {
    _constructor();
    TranspileResult result = spv.transpile(spirv, spv.TargetLanguage.sksl);
    _init(result.src, debugPrint);
    _uniformFloatCount = result.uniformFloatCount;
    _samplerCount = result.samplerCount;
}

bool _FragmentShader::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is _FragmentShader && other._builder == _builder && <double>_listEquals(other._floatUniforms, _floatUniforms) && <ImageShader>_listEquals(other._samplerUniforms, _samplerUniforms);
}

int _FragmentShader::hashCode() {
    return Object.hash(_builder, Object.hashAll(_floatUniforms), Object.hashAll(_samplerUniforms));
}

_FragmentShader::_FragmentShader(FragmentProgram _builder, Float32List _floatUniforms, List<ImageShader> _samplerUniforms) {
    {
        super._();
    }
}

Vertices::Vertices(List<Color> colors, List<int> indices, VertexMode mode, List<Offset> positions, List<Offset> textureCoordinates) {
    {
        assert(mode != nullptr);
        assert(positions != nullptr);
    }
    {
        if (textureCoordinates != nullptr && textureCoordinates.length != positions.length)         {
            ;
        }
        if (colors != nullptr && colors.length != positions.length)         {
            ;
        }
        if (indices != nullptr && indices.any())         {
            ;
        }
        Float32List encodedPositions = _encodePointList(positions);
        Float32List encodedTextureCoordinates = (textureCoordinates != nullptr)? _encodePointList(textureCoordinates) : nullptr;
        Int32List encodedColors = colors != nullptr? _encodeColorList(colors) : nullptr;
        Uint16List encodedIndices = indices != nullptr? Uint16List.fromList(indices) : nullptr;
        if (!_init(this, mode.index, encodedPositions, encodedTextureCoordinates, encodedColors, encodedIndices))         {
            ;
        }
    }
}

void Vertices::raw(Int32List colors, Uint16List indices, VertexMode mode, Float32List positions, Float32List textureCoordinates) {
    if (textureCoordinates != nullptr && textureCoordinates.length != positions.length)     {
        ;
    }
    if (colors != nullptr && colors.length * 2 != positions.length)     {
        ;
    }
    if (indices != nullptr && indices.any())     {
        ;
    }
    if (!_init(this, mode.index, positions, textureCoordinates, colors, indices))     {
        ;
    }
}

Canvas::Canvas(Rect cullRect, PictureRecorder recorder) {
    {
        assert(recorder != nullptr);
    }
    {
        if (recorder.isRecording)         {
            ;
        }
        _recorder = recorder;
        _recorder!._canvas = this;
        cullRect = Rect.largest;
        _constructor(recorder, cullRect.left, cullRect.top, cullRect.right, cullRect.bottom);
    }
}

void Canvas::saveLayer(Rect bounds, Paint paint) {
    assert(paint != nullptr);
    if (bounds == nullptr) {
        _saveLayerWithoutBounds(paint._objects, paint._data);
    } else {
        assert(_rectIsValid(bounds));
        _saveLayer(bounds.left, bounds.top, bounds.right, bounds.bottom, paint._objects, paint._data);
    }
}

void Canvas::scale(double sx, double sy) {
    return _scale(sx, sy ?? sx);
}

void Canvas::transform(Float64List matrix4) {
    assert(matrix4 != nullptr);
    if (matrix4.length != 16)     {
        ;
    }
    _transform(matrix4);
}

Float64List Canvas::getTransform() {
    Float64List matrix4 = Float64List(16);
    _getTransform(matrix4);
    return matrix4;
}

void Canvas::clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect) {
    assert(_rectIsValid(rect));
    assert(clipOp != nullptr);
    assert(doAntiAlias != nullptr);
    _clipRect(rect.left, rect.top, rect.right, rect.bottom, clipOp.index, doAntiAlias);
}

void Canvas::clipRRect(bool doAntiAlias, RRect rrect) {
    assert(_rrectIsValid(rrect));
    assert(doAntiAlias != nullptr);
    _clipRRect(rrect._getValue32(), doAntiAlias);
}

void Canvas::clipPath(bool doAntiAlias, Path path) {
    assert(path != nullptr);
    assert(doAntiAlias != nullptr);
    _clipPath(path, doAntiAlias);
}

Rect Canvas::getLocalClipBounds() {
    Float64List bounds = Float64List(4);
    _getLocalClipBounds(bounds);
    return Rect.fromLTRB(bounds[0], bounds[1], bounds[2], bounds[3]);
}

Rect Canvas::getDestinationClipBounds() {
    Float64List bounds = Float64List(4);
    _getDestinationClipBounds(bounds);
    return Rect.fromLTRB(bounds[0], bounds[1], bounds[2], bounds[3]);
}

void Canvas::drawColor(BlendMode blendMode, Color color) {
    assert(color != nullptr);
    assert(blendMode != nullptr);
    _drawColor(color.value, blendMode.index);
}

void Canvas::drawLine(Offset p1, Offset p2, Paint paint) {
    assert(_offsetIsValid(p1));
    assert(_offsetIsValid(p2));
    assert(paint != nullptr);
    _drawLine(p1.dx, p1.dy, p2.dx, p2.dy, paint._objects, paint._data);
}

void Canvas::drawPaint(Paint paint) {
    assert(paint != nullptr);
    _drawPaint(paint._objects, paint._data);
}

void Canvas::drawRect(Paint paint, Rect rect) {
    assert(_rectIsValid(rect));
    assert(paint != nullptr);
    _drawRect(rect.left, rect.top, rect.right, rect.bottom, paint._objects, paint._data);
}

void Canvas::drawRRect(Paint paint, RRect rrect) {
    assert(_rrectIsValid(rrect));
    assert(paint != nullptr);
    _drawRRect(rrect._getValue32(), paint._objects, paint._data);
}

void Canvas::drawDRRect(RRect inner, RRect outer, Paint paint) {
    assert(_rrectIsValid(outer));
    assert(_rrectIsValid(inner));
    assert(paint != nullptr);
    _drawDRRect(outer._getValue32(), inner._getValue32(), paint._objects, paint._data);
}

void Canvas::drawOval(Paint paint, Rect rect) {
    assert(_rectIsValid(rect));
    assert(paint != nullptr);
    _drawOval(rect.left, rect.top, rect.right, rect.bottom, paint._objects, paint._data);
}

void Canvas::drawCircle(Offset c, Paint paint, double radius) {
    assert(_offsetIsValid(c));
    assert(paint != nullptr);
    _drawCircle(c.dx, c.dy, radius, paint._objects, paint._data);
}

void Canvas::drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter) {
    assert(_rectIsValid(rect));
    assert(paint != nullptr);
    _drawArc(rect.left, rect.top, rect.right, rect.bottom, startAngle, sweepAngle, useCenter, paint._objects, paint._data);
}

void Canvas::drawPath(Paint paint, Path path) {
    assert(path != nullptr);
    assert(paint != nullptr);
    _drawPath(path, paint._objects, paint._data);
}

void Canvas::drawImage(Image image, Offset offset, Paint paint) {
    assert(image != nullptr);
    assert(_offsetIsValid(offset));
    assert(paint != nullptr);
    String error = _drawImage(image._image, offset.dx, offset.dy, paint._objects, paint._data, paint.filterQuality.index);
    if (error != nullptr) {
        ;
    }
}

void Canvas::drawImageRect(Rect dst, Image image, Paint paint, Rect src) {
    assert(image != nullptr);
    assert(_rectIsValid(src));
    assert(_rectIsValid(dst));
    assert(paint != nullptr);
    String error = _drawImageRect(image._image, src.left, src.top, src.right, src.bottom, dst.left, dst.top, dst.right, dst.bottom, paint._objects, paint._data, paint.filterQuality.index);
    if (error != nullptr) {
        ;
    }
}

void Canvas::drawImageNine(Rect center, Rect dst, Image image, Paint paint) {
    assert(image != nullptr);
    assert(_rectIsValid(center));
    assert(_rectIsValid(dst));
    assert(paint != nullptr);
    String error = _drawImageNine(image._image, center.left, center.top, center.right, center.bottom, dst.left, dst.top, dst.right, dst.bottom, paint._objects, paint._data, paint.filterQuality.index);
    if (error != nullptr) {
        ;
    }
}

void Canvas::drawPicture(Picture picture) {
    assert(picture != nullptr);
    _drawPicture(picture);
}

void Canvas::drawParagraph(Offset offset, Paragraph paragraph) {
    assert(paragraph != nullptr);
    assert(_offsetIsValid(offset));
    assert(!paragraph._needsLayout);
    paragraph._paint(this, offset.dx, offset.dy);
}

void Canvas::drawPoints(Paint paint, PointMode pointMode, List<Offset> points) {
    assert(pointMode != nullptr);
    assert(points != nullptr);
    assert(paint != nullptr);
    _drawPoints(paint._objects, paint._data, pointMode.index, _encodePointList(points));
}

void Canvas::drawRawPoints(Paint paint, PointMode pointMode, Float32List points) {
    assert(pointMode != nullptr);
    assert(points != nullptr);
    assert(paint != nullptr);
    if (points.length % 2 != 0)     {
        ;
    }
    _drawPoints(paint._objects, paint._data, pointMode.index, points);
}

void Canvas::drawVertices(BlendMode blendMode, Paint paint, Vertices vertices) {
    assert(vertices != nullptr);
    assert(paint != nullptr);
    assert(blendMode != nullptr);
    _drawVertices(vertices, blendMode.index, paint._objects, paint._data);
}

void Canvas::drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms) {
    assert(atlas != nullptr);
    assert(transforms != nullptr);
    assert(rects != nullptr);
    assert(colors == nullptr || colors.isEmpty || blendMode != nullptr);
    assert(paint != nullptr);
    int rectCount = rects.length;
    if (transforms.length != rectCount)     {
        ;
    }
    if (colors != nullptr && colors.isNotEmpty && colors.length != rectCount)     {
        ;
    }
    Float32List rstTransformBuffer = Float32List(rectCount * 4);
    Float32List rectBuffer = Float32List(rectCount * 4);
    for (;  < rectCount; ++i) {
        int index0 = i * 4;
        int index1 = index0 + 1;
        int index2 = index0 + 2;
        int index3 = index0 + 3;
        RSTransform rstTransform = transforms[i];
        Rect rect = rects[i];
        assert(_rectIsValid(rect));
        rstTransformBuffer[index0] = rstTransform.scos;
        rstTransformBuffer[index1] = rstTransform.ssin;
        rstTransformBuffer[index2] = rstTransform.tx;
        rstTransformBuffer[index3] = rstTransform.ty;
        rectBuffer[index0] = rect.left;
        rectBuffer[index1] = rect.top;
        rectBuffer[index2] = rect.right;
        rectBuffer[index3] = rect.bottom;
    }
    Int32List colorBuffer = (colors == nullptr || colors.isEmpty)? nullptr : _encodeColorList(colors);
    Float32List cullRectBuffer = cullRect?._getValue32();
    int qualityIndex = paint.filterQuality.index;
    String error = _drawAtlas(paint._objects, paint._data, qualityIndex, atlas._image, rstTransformBuffer, rectBuffer, colorBuffer, (blendMode ?? BlendMode.src).index, cullRectBuffer);
    if (error != nullptr) {
        ;
    }
}

void Canvas::drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms) {
    assert(atlas != nullptr);
    assert(rstTransforms != nullptr);
    assert(rects != nullptr);
    assert(colors == nullptr || blendMode != nullptr);
    assert(paint != nullptr);
    int rectCount = rects.length;
    if (rstTransforms.length != rectCount)     {
        ;
    }
    if (rectCount % 4 != 0)     {
        ;
    }
    if (colors != nullptr && colors.length * 4 != rectCount)     {
        ;
    }
    int qualityIndex = paint.filterQuality.index;
    String error = _drawAtlas(paint._objects, paint._data, qualityIndex, atlas._image, rstTransforms, rects, colors, (blendMode ?? BlendMode.src).index, cullRect?._getValue32());
    if (error != nullptr) {
        ;
    }
}

void Canvas::drawShadow(Color color, double elevation, Path path, bool transparentOccluder) {
    assert(path != nullptr);
    assert(color != nullptr);
    assert(transparentOccluder != nullptr);
    _drawShadow(path, color.value, elevation, transparentOccluder);
}

Future<Image> Picture::toImage(int height, int width) {
    assert(!_disposed);
    if (width <= 0 || height <= 0)     {
        ;
    }
    return _futurize();
}

void Picture::dispose() {
    assert(!_disposed);
    assert(());
    _dispose();
}

bool Picture::debugDisposed() {
    bool disposed;
    assert(());
    return disposed ?? ();
}

PictureRecorder::PictureRecorder() {
    {
        _constructor();
    }
}

bool PictureRecorder::isRecording() {
    return _canvas != nullptr;
}

Picture PictureRecorder::endRecording() {
    if (_canvas == nullptr)     {
        ;
    }
    Picture picture = Picture._();
    _endRecording(picture);
    _canvas!._recorder = nullptr;
    _canvas = nullptr;
    return picture;
}

Shadow::Shadow(double blurRadius, Color color, Offset offset) {
    {
        assert(color != nullptr, "Text shadow color was null.");
        assert(offset != nullptr, "Text shadow offset was null.");
        assert(blurRadius >= 0.0, "Text shadow blur radius should be non-negative.");
    }
}

double Shadow::convertRadiusToSigma(double radius) {
    return radius > 0? radius * 0.57735 + 0.5 : 0;
}

double Shadow::blurSigma() {
    return convertRadiusToSigma(blurRadius);
}

Paint Shadow::toPaint() {
    return ;
}

Shadow Shadow::scale(double factor) {
    return Shadow(color, offset * factor, blurRadius * factor);
}

Shadow Shadow::lerp(Shadow a, Shadow b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            return a.scale(1.0 - t);
        }
    } else {
        if (a == nullptr) {
            return b.scale(t);
        } else {
            return Shadow(Color.lerp(a.color, b.color, t)!, Offset.lerp(a.offset, b.offset, t)!, _lerpDouble(a.blurRadius, b.blurRadius, t));
        }
    }
}

List<Shadow> Shadow::lerpList(List<Shadow> a, List<Shadow> b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr)     {
        return nullptr;
    }
    a = ;
    b = ;
    List<Shadow> result = ;
    int commonLength = math.min(a.length, b.length);
    for (;  < commonLength; i = 1)     {
        result.add(Shadow.lerp(a[i], b[i], t)!);
    }
    for (;  < a.length; i = 1)     {
        result.add(a[i].scale(1.0 - t));
    }
    for (;  < b.length; i = 1)     {
        result.add(b[i].scale(t));
    }
    return result;
}

bool Shadow::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return other is Shadow && other.color == color && other.offset == offset && other.blurRadius == blurRadius;
}

int Shadow::hashCode() {
    return Object.hash(color, offset, blurRadius);
}

String Shadow::toString() {
    return "TextShadow($color, $offset, $blurRadius)";
}

ByteData Shadow::_encodeShadows(List<Shadow> shadows) {
    if (shadows == nullptr)     {
        return ByteData(0);
    }
    int byteCount = shadows.length * _kBytesPerShadow;
    ByteData shadowsData = ByteData(byteCount);
    int shadowOffset = 0;
    for (;  < shadows.length; ++shadowIndex) {
        Shadow shadow = shadows[shadowIndex];
        if (shadow != nullptr) {
            shadowOffset = shadowIndex * _kBytesPerShadow;
            shadowsData.setInt32(_kColorOffset + shadowOffset, shadow.color.value ^ Shadow._kColorDefault, _kFakeHostEndian);
            shadowsData.setFloat32(_kXOffset + shadowOffset, shadow.offset.dx, _kFakeHostEndian);
            shadowsData.setFloat32(_kYOffset + shadowOffset, shadow.offset.dy, _kFakeHostEndian);
            double blurSigma = Shadow.convertRadiusToSigma(shadow.blurRadius);
            shadowsData.setFloat32(_kBlurOffset + shadowOffset, blurSigma, _kFakeHostEndian);
        }
    }
    return shadowsData;
}

Future<ImmutableBuffer> ImmutableBuffer::fromUint8List(Uint8List list) {
    ImmutableBuffer instance = ImmutableBuffer._(list.length);
    return _futurize().then();
}

Future<ImmutableBuffer> ImmutableBuffer::fromAsset(String assetKey) {
    String encodedKey = Uri(Uri.encodeFull(assetKey)).path;
    ImmutableBuffer instance = ImmutableBuffer._(0);
    return _futurize().then();
}

int ImmutableBuffer::length() {
    return _length;
}

bool ImmutableBuffer::debugDisposed() {
    bool disposed;
    assert(());
    return disposed;
}

void ImmutableBuffer::dispose() {
    assert(());
    _dispose();
}

Future<ImageDescriptor> ImageDescriptor::encoded(ImmutableBuffer buffer) {
    ImageDescriptor descriptor = ImageDescriptor._();
    return _futurize().then();
}

void ImageDescriptor::raw(ImmutableBuffer buffer, int height, PixelFormat pixelFormat, int rowBytes, int width) {
    _width = width;
    _height = height;
    _bytesPerPixel = 4;
    _initRaw(this, buffer, width, height, rowBytes ?? -1, pixelFormat.index);
}

int ImageDescriptor::width() {
    return _width ??= _getWidth();
}

int ImageDescriptor::height() {
    return _height ??= _getHeight();
}

int ImageDescriptor::bytesPerPixel() {
    return _bytesPerPixel ??= _getBytesPerPixel();
}

Future<Codec> ImageDescriptor::instantiateCodec(int targetHeight, int targetWidth) {
    if (targetWidth != nullptr && targetWidth <= 0) {
        targetWidth = nullptr;
    }
    if (targetHeight != nullptr && targetHeight <= 0) {
        targetHeight = nullptr;
    }
    if (targetWidth == nullptr && targetHeight == nullptr) {
        targetWidth = width;
        targetHeight = height;
    } else     {
        if (targetWidth == nullptr && targetHeight != nullptr) {
        targetWidth = (targetHeight * (width / height)).round();
        targetHeight = targetHeight;
    } else     {
        if (targetHeight == nullptr && targetWidth != nullptr) {
        targetWidth = targetWidth;
        targetHeight = targetWidth ~/ (width / height);
    }
;
    };
    }    assert(targetWidth != nullptr);
    assert(targetHeight != nullptr);
    Codec codec = Codec._();
    _instantiateCodec(codec, targetWidth!, targetHeight!);
    return codec;
}

Future<T> _futurize<T>(_Callbacker<T> callbacker) {
    Completer<T> completer = <T>sync();
    bool sync = true;
    String error = callbacker();
    sync = false;
    if (error != nullptr)     {
        ;
    }
    return completer.future;
}

String PictureRasterizationException::toString() {
    StringBuffer buffer = StringBuffer("Failed to rasterize a picture: $message.");
    if (stack != nullptr) {
        buffer.writeln();
        buffer.writeln("The callstack when the image was created was:");
        buffer.writeln(stack!.toString());
    }
    return buffer.toString();
}
