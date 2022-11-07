#ifndef PAINTING_H
#define PAINTING_H
#include <memory>



bool _rectIsValid(Rect rect);

bool _rrectIsValid(RRect rrect);

bool _offsetIsValid(Offset offset);

bool _matrix4IsValid(Float64List matrix4);

bool _radiusIsValid(Radius radius);

Color _scaleAlpha(Color a, double factor);


class Color {
public:
    int value;


     Color(int value);

    void  fromARGB(int a, int b, int g, int r);

    void  fromRGBO(int b, int g, double opacity, int r);

    int alpha();

    double opacity();

    int red();

    int green();

    int blue();

    Color withAlpha(int a);

    Color withOpacity(double opacity);

    Color withRed(int r);

    Color withGreen(int g);

    Color withBlue(int b);

    double computeLuminance();

    static Color lerp(Color a, Color b, double t);

    static Color alphaBlend(Color background, Color foreground);

    static int getAlphaFromOpacity(double opacity);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    static double _linearizeColorComponent(double component);

};

enum BlendMode{
    clear,
    src,
    dst,
    srcOver,
    dstOver,
    srcIn,
    dstIn,
    srcOut,
    dstOut,
    srcATop,
    dstATop,
    xor,
    plus,
    modulate,
    screen,
    overlay,
    darken,
    lighten,
    colorDodge,
    colorBurn,
    hardLight,
    softLight,
    difference,
    exclusion,
    multiply,
    hue,
    saturation,
    color,
    luminosity,
} // end BlendMode

enum FilterQuality{
    none,
    low,
    medium,
    high,
} // end FilterQuality

enum StrokeCap{
    butt,
    round,
    square,
} // end StrokeCap

enum StrokeJoin{
    miter,
    round,
    bevel,
} // end StrokeJoin

enum PaintingStyle{
    fill,
    stroke,
} // end PaintingStyle

enum Clip{
    none,
    hardEdge,
    antiAlias,
    antiAliasWithSaveLayer,
} // end Clip

class Paint {
public:
    static bool enableDithering;


     Paint();

    bool isAntiAlias();

    void  isAntiAlias(bool value);

    Color color();

    void  color(Color value);

    BlendMode blendMode();

    void  blendMode(BlendMode value);

    PaintingStyle style();

    void  style(PaintingStyle value);

    double strokeWidth();

    void  strokeWidth(double value);

    StrokeCap strokeCap();

    void  strokeCap(StrokeCap value);

    StrokeJoin strokeJoin();

    void  strokeJoin(StrokeJoin value);

    double strokeMiterLimit();

    void  strokeMiterLimit(double value);

    MaskFilter maskFilter();

    void  maskFilter(MaskFilter value);

    FilterQuality filterQuality();

    void  filterQuality(FilterQuality value);

    Shader shader();

    void  shader(Shader value);

    ColorFilter colorFilter();

    void  colorFilter(ColorFilter value);

    ImageFilter imageFilter();

    void  imageFilter(ImageFilter value);

    bool invertColors();

    void  invertColors(bool value);

    String toString();

private:
    ByteData _data;

    static const int _kIsAntiAliasIndex;

    static const int _kColorIndex;

    static const int _kBlendModeIndex;

    static const int _kStyleIndex;

    static const int _kStrokeWidthIndex;

    static const int _kStrokeCapIndex;

    static const int _kStrokeJoinIndex;

    static const int _kStrokeMiterLimitIndex;

    static const int _kFilterQualityIndex;

    static const int _kMaskFilterIndex;

    static const int _kMaskFilterBlurStyleIndex;

    static const int _kMaskFilterSigmaIndex;

    static const int _kInvertColorIndex;

    static const int _kDitherIndex;

    static const int _kIsAntiAliasOffset;

    static const int _kColorOffset;

    static const int _kBlendModeOffset;

    static const int _kStyleOffset;

    static const int _kStrokeWidthOffset;

    static const int _kStrokeCapOffset;

    static const int _kStrokeJoinOffset;

    static const int _kStrokeMiterLimitOffset;

    static const int _kFilterQualityOffset;

    static const int _kMaskFilterOffset;

    static const int _kMaskFilterBlurStyleOffset;

    static const int _kMaskFilterSigmaOffset;

    static const int _kInvertColorOffset;

    static const int _kDitherOffset;

    static const int _kDataByteCount;

    List<Object> _objects;

    static const int _kShaderIndex;

    static const int _kColorFilterIndex;

    static const int _kImageFilterIndex;

    static const int _kObjectCount;

    static const int _kColorDefault;

    static int _kBlendModeDefault;

    static const double _kStrokeMiterLimitDefault;


    List<Object> _ensureObjectsInitialized();

    bool _dither();

    void  _dither(bool value);

};

enum ImageByteFormat{
    rawRgba,
    rawStraightRgba,
    rawUnmodified,
    png,
} // end ImageByteFormat

enum PixelFormat{
    rgba8888,
    bgra8888,
} // end PixelFormat

class Image {
public:
    int width;

    int height;


    void dispose();

    bool debugDisposed();

    Future<ByteData> toByteData(ImageByteFormat format);

    List<StackTrace> debugGetOpenHandleStackTraces();

    Image clone();

    bool isCloneOf(Image other);

    String toString();

private:
    _Image _image;

    StackTrace _debugStack;

    bool _disposed;


    void  _(_Image _image, int height, int width);

};

class _Image : NativeFieldWrapperClass1 {
public:

    int width();

    int height();

    Future<ByteData> toByteData(ImageByteFormat format);

    void dispose();

    String toString();

private:
    bool _disposed;

    Set<Image> _handles;


    void  _();

    String _toByteData(_Callback<Uint8List> callback, int format);

    void _dispose();

};

class FrameInfo {
public:
    Duration duration;

    Image image;


private:

    void  _(Duration duration, Image image);

};

class Codec : NativeFieldWrapperClass1 {
public:

    int frameCount();

    int repetitionCount();

    Future<FrameInfo> getNextFrame();

    void dispose();

private:
    int _cachedFrameCount;

    int _cachedRepetitionCount;


    void  _();

    int _frameCount();

    int _repetitionCount();

    String _getNextFrame(FunctionType callback);

};
Future<Codec> instantiateImageCodec(bool allowUpscaling, Uint8List list, int targetHeight, int targetWidth);

Future<Codec> instantiateImageCodecFromBuffer(bool allowUpscaling, ImmutableBuffer buffer, int targetHeight, int targetWidth);

void decodeImageFromList(ImageDecoderCallback callback, Uint8List list);

Future<void> _decodeImageFromListAsync(ImageDecoderCallback callback, Uint8List list);

void decodeImageFromPixels(bool allowUpscaling, ImageDecoderCallback callback, PixelFormat format, int height, Uint8List pixels, int rowBytes, int targetHeight, int targetWidth, int width);


enum PathFillType{
    nonZero,
    evenOdd,
} // end PathFillType

enum PathOperation{
    difference,
    intersect,
    union,
    xor,
    reverseDifference,
} // end PathOperation

class EngineLayer : NativeFieldWrapperClass1 {
public:

    void dispose();

private:

    void  _();

};

class Path : NativeFieldWrapperClass1 {
public:

     Path();

    void  from(Path source);

    PathFillType fillType();

    void  fillType(PathFillType value);

    void moveTo(double x, double y);

    void relativeMoveTo(double dx, double dy);

    void lineTo(double x, double y);

    void relativeLineTo(double dx, double dy);

    void quadraticBezierTo(double x1, double x2, double y1, double y2);

    void relativeQuadraticBezierTo(double x1, double x2, double y1, double y2);

    void cubicTo(double x1, double x2, double x3, double y1, double y2, double y3);

    void relativeCubicTo(double x1, double x2, double x3, double y1, double y2, double y3);

    void conicTo(double w, double x1, double x2, double y1, double y2);

    void relativeConicTo(double w, double x1, double x2, double y1, double y2);

    void arcTo(bool forceMoveTo, Rect rect, double startAngle, double sweepAngle);

    void arcToPoint(Offset arcEnd, bool clockwise, bool largeArc, Radius radius, double rotation);

    void relativeArcToPoint(Offset arcEndDelta, bool clockwise, bool largeArc, Radius radius, double rotation);

    void addRect(Rect rect);

    void addOval(Rect oval);

    void addArc(Rect oval, double startAngle, double sweepAngle);

    void addPolygon(bool close, List<Offset> points);

    void addRRect(RRect rrect);

    void addPath(Float64List matrix4, Offset offset, Path path);

    void extendWithPath(Float64List matrix4, Offset offset, Path path);

    void close();

    void reset();

    bool contains(Offset point);

    Path shift(Offset offset);

    Path transform(Float64List matrix4);

    Rect getBounds();

    static Path combine(PathOperation operation, Path path1, Path path2);

    PathMetrics computeMetrics(bool forceClosed);

private:

    void _constructor();

    void  _();

    void _clone(Path outPath);

    int _getFillType();

    void _setFillType(int fillType);

    void _arcTo(double bottom, bool forceMoveTo, double left, double right, double startAngle, double sweepAngle, double top);

    void _arcToPoint(double arcEndX, double arcEndY, bool clockwise, bool largeArc, double radiusX, double radiusY, double rotation);

    void _relativeArcToPoint(double arcEndX, double arcEndY, bool clockwise, bool largeArc, double radiusX, double radiusY, double rotation);

    void _addRect(double bottom, double left, double right, double top);

    void _addOval(double bottom, double left, double right, double top);

    void _addArc(double bottom, double left, double right, double startAngle, double sweepAngle, double top);

    void _addPolygon(bool close, Float32List points);

    void _addRRect(Float32List rrect);

    void _addPath(double dx, double dy, Path path);

    void _addPathWithMatrix(double dx, double dy, Float64List matrix, Path path);

    void _extendWithPath(double dx, double dy, Path path);

    void _extendWithPathAndMatrix(double dx, double dy, Float64List matrix, Path path);

    bool _contains(double x, double y);

    void _shift(double dx, double dy, Path outPath);

    void _transform(Float64List matrix4, Path outPath);

    Float32List _getBounds();

    bool _op(int operation, Path path1, Path path2);

};

class Tangent {
public:
    Offset position;

    Offset vector;


     Tangent(Offset position, Offset vector);

    void  fromAngle(double angle, Offset position);

    double angle();

private:

};

class PathMetrics : IterableBase<PathMetric> {
public:

    Iterator<PathMetric> iterator();

private:
    Iterator<PathMetric> _iterator;


    void  _(bool forceClosed, Path path);

};

class PathMetricIterator {
public:

    PathMetric current();

    bool moveNext();

private:
    PathMetric _pathMetric;

    _PathMeasure _pathMeasure;


    void  _(_PathMeasure _pathMeasure);

};

class PathMetric {
public:
    double length;

    bool isClosed;

    int contourIndex;


    Tangent getTangentForOffset(double distance);

    Path extractPath(double end, double start, bool startWithMoveTo);

    String toString();

private:
    _PathMeasure _measure;


    void  _(_PathMeasure _measure);

};

class _PathMeasure : NativeFieldWrapperClass1 {
public:
    int currentContourIndex;


    double length(int contourIndex);

    Tangent getTangentForOffset(int contourIndex, double distance);

    Path extractPath(int contourIndex, double end, double start, bool startWithMoveTo);

    bool isClosed(int contourIndex);

private:

     _PathMeasure(bool forceClosed, Path path);

    void _constructor(bool forceClosed, Path path);

    double _length(int contourIndex);

    Float32List _getPosTan(int contourIndex, double distance);

    void _extractPath(int contourIndex, double end, Path outPath, double start, bool startWithMoveTo);

    bool _isClosed(int contourIndex);

    bool _nextContour();

    bool _nativeNextContour();

};

enum BlurStyle{
    normal,
    solid,
    outer,
    inner,
} // end BlurStyle

class MaskFilter {
public:

    void  blur(double _sigma, BlurStyle _style);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    BlurStyle _style;

    double _sigma;

    static const int _TypeNone;

    static const int _TypeBlur;


};

class ColorFilter {
public:

    void  mode(BlendMode blendMode, Color color);

    void  matrix(List<double> matrix);

    void  linearToSrgbGamma();

    void  srgbToLinearGamma();

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    Color _color;

    BlendMode _blendMode;

    List<double> _matrix;

    int _type;

    static const int _kTypeMode;

    static const int _kTypeMatrix;

    static const int _kTypeLinearToSrgbGamma;

    static const int _kTypeSrgbToLinearGamma;


    _ImageFilter _toNativeImageFilter();

    _ColorFilter _toNativeColorFilter();

    String _shortDescription();

};

class _ColorFilter : NativeFieldWrapperClass1 {
public:
    ColorFilter creator;


    void  mode(ColorFilter creator);

    void  matrix(ColorFilter creator);

    void  linearToSrgbGamma(ColorFilter creator);

    void  srgbToLinearGamma(ColorFilter creator);

private:

    void _constructor();

    void _initMode(int blendMode, int color);

    void _initMatrix(Float32List matrix);

    void _initLinearToSrgbGamma();

    void _initSrgbToLinearGamma();

};

class ImageFilter {
public:

    void  blur(double sigmaX, double sigmaY, TileMode tileMode);

    void  dilate(double radiusX, double radiusY);

    void  erode(double radiusX, double radiusY);

    void  matrix(FilterQuality filterQuality, Float64List matrix4);

    void  compose(ImageFilter inner, ImageFilter outer);

private:

    _ImageFilter _toNativeImageFilter();

    String _shortDescription();

};

class _MatrixImageFilter {
public:
    Float64List data;

    FilterQuality filterQuality;

    _ImageFilter nativeFilter;


    String toString();

    bool ==(Object other);

    int hashCode();

private:

     _MatrixImageFilter(Float64List data, FilterQuality filterQuality);

    _ImageFilter _toNativeImageFilter();

    String _shortDescription();

};

class _GaussianBlurImageFilter {
public:
    double sigmaX;

    double sigmaY;

    TileMode tileMode;

    _ImageFilter nativeFilter;


    String toString();

    bool ==(Object other);

    int hashCode();

private:

     _GaussianBlurImageFilter(double sigmaX, double sigmaY, TileMode tileMode);

    _ImageFilter _toNativeImageFilter();

    String _modeString();

    String _shortDescription();

};

class _DilateImageFilter {
public:
    double radiusX;

    double radiusY;

    _ImageFilter nativeFilter;


    String toString();

    bool ==(Object other);

    int hashCode();

private:

     _DilateImageFilter(double radiusX, double radiusY);

    _ImageFilter _toNativeImageFilter();

    String _shortDescription();

};

class _ErodeImageFilter {
public:
    double radiusX;

    double radiusY;

    _ImageFilter nativeFilter;


    String toString();

    bool ==(Object other);

    int hashCode();

private:

     _ErodeImageFilter(double radiusX, double radiusY);

    _ImageFilter _toNativeImageFilter();

    String _shortDescription();

};

class _ComposeImageFilter {
public:
    ImageFilter innerFilter;

    ImageFilter outerFilter;

    _ImageFilter nativeFilter;


    String toString();

    bool ==(Object other);

    int hashCode();

private:

     _ComposeImageFilter(ImageFilter innerFilter, ImageFilter outerFilter);

    _ImageFilter _toNativeImageFilter();

    String _shortDescription();

};

class _ImageFilter : NativeFieldWrapperClass1 {
public:
    ImageFilter creator;


    void  blur(_GaussianBlurImageFilter filter);

    void  dilate(_DilateImageFilter filter);

    void  erode(_ErodeImageFilter filter);

    void  matrix(_MatrixImageFilter filter);

    void  fromColorFilter(ColorFilter filter);

    void  composed(_ComposeImageFilter filter);

private:

    void _constructor();

    void _initBlur(double sigmaX, double sigmaY, int tileMode);

    void _initDilate(double radiusX, double radiusY);

    void _initErode(double radiusX, double radiusY);

    void _initMatrix(int filterQuality, Float64List matrix4);

    void _initColorFilter(_ColorFilter colorFilter);

    void _initComposed(_ImageFilter innerFilter, _ImageFilter outerFilter);

};

class Shader : NativeFieldWrapperClass1 {
public:

private:

    void  _();

};

enum TileMode{
    clamp,
    repeated,
    mirror,
    decal,
} // end TileMode
Int32List _encodeColorList(List<Color> colors);

Float32List _encodePointList(List<Offset> points);

Float32List _encodeTwoPoints(Offset pointA, Offset pointB);


class Gradient : Shader {
public:

    void  linear(List<double> colorStops, List<Color> colors, Offset from, Float64List matrix4, TileMode tileMode, Offset to);

    void  radial(Offset center, List<double> colorStops, List<Color> colors, Offset focal, double focalRadius, Float64List matrix4, double radius, TileMode tileMode);

    void  sweep(Offset center, List<double> colorStops, List<Color> colors, double endAngle, Float64List matrix4, double startAngle, TileMode tileMode);

private:

    void _constructor();

    void _initLinear(Float32List colorStops, Int32List colors, Float32List endPoints, Float64List matrix4, int tileMode);

    void _initRadial(double centerX, double centerY, Float32List colorStops, Int32List colors, Float64List matrix4, double radius, int tileMode);

    void _initConical(Float32List colorStops, Int32List colors, double endRadius, double endX, double endY, Float64List matrix4, double startRadius, double startX, double startY, int tileMode);

    void _initSweep(double centerX, double centerY, Float32List colorStops, Int32List colors, double endAngle, Float64List matrix, double startAngle, int tileMode);

    static void _validateColorStops(List<double> colorStops, List<Color> colors);

};

class ImageShader : Shader {
public:

     ImageShader(FilterQuality filterQuality, Image image, Float64List matrix4, TileMode tmx, TileMode tmy);

private:

    void _constructor();

    String _initWithImage(int filterQualityIndex, _Image image, Float64List matrix4, int tmx, int tmy);

};

class FragmentProgram : NativeFieldWrapperClass1 {
public:

    static Future<FragmentProgram> compile(bool debugPrint, ByteBuffer spirv);

    Shader shader(Float32List floatUniforms, List<ImageShader> samplerUniforms);

private:
    int _uniformFloatCount;

    int _samplerCount;


    void  _(bool debugPrint, ByteBuffer spirv);

    void _constructor();

    void _init(bool debugPrint, String sksl);

    void _shader(Float32List floatUniforms, List<ImageShader> samplerUniforms, _FragmentShader shader);

};

class _FragmentShader : Shader {
public:

    bool ==(Object other);

    int hashCode();

private:
    FragmentProgram _builder;

    Float32List _floatUniforms;

    List<ImageShader> _samplerUniforms;


     _FragmentShader(FragmentProgram _builder, Float32List _floatUniforms, List<ImageShader> _samplerUniforms);

};

enum VertexMode{
    triangles,
    triangleStrip,
    triangleFan,
} // end VertexMode

class Vertices : NativeFieldWrapperClass1 {
public:

     Vertices(List<Color> colors, List<int> indices, VertexMode mode, List<Offset> positions, List<Offset> textureCoordinates);

    void  raw(Int32List colors, Uint16List indices, VertexMode mode, Float32List positions, Float32List textureCoordinates);

private:

    bool _init(Int32List colors, Uint16List indices, int mode, Vertices outVertices, Float32List positions, Float32List textureCoordinates);

};

enum PointMode{
    points,
    lines,
    polygon,
} // end PointMode

enum ClipOp{
    difference,
    intersect,
} // end ClipOp

class Canvas : NativeFieldWrapperClass1 {
public:

     Canvas(Rect cullRect, PictureRecorder recorder);

    void save();

    void saveLayer(Rect bounds, Paint paint);

    void restore();

    int getSaveCount();

    void translate(double dx, double dy);

    void scale(double sx, double sy);

    void rotate(double radians);

    void skew(double sx, double sy);

    void transform(Float64List matrix4);

    Float64List getTransform();

    void clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect);

    void clipRRect(bool doAntiAlias, RRect rrect);

    void clipPath(bool doAntiAlias, Path path);

    Rect getLocalClipBounds();

    Rect getDestinationClipBounds();

    void drawColor(BlendMode blendMode, Color color);

    void drawLine(Offset p1, Offset p2, Paint paint);

    void drawPaint(Paint paint);

    void drawRect(Paint paint, Rect rect);

    void drawRRect(Paint paint, RRect rrect);

    void drawDRRect(RRect inner, RRect outer, Paint paint);

    void drawOval(Paint paint, Rect rect);

    void drawCircle(Offset c, Paint paint, double radius);

    void drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter);

    void drawPath(Paint paint, Path path);

    void drawImage(Image image, Offset offset, Paint paint);

    void drawImageRect(Rect dst, Image image, Paint paint, Rect src);

    void drawImageNine(Rect center, Rect dst, Image image, Paint paint);

    void drawPicture(Picture picture);

    void drawParagraph(Offset offset, Paragraph paragraph);

    void drawPoints(Paint paint, PointMode pointMode, List<Offset> points);

    void drawRawPoints(Paint paint, PointMode pointMode, Float32List points);

    void drawVertices(BlendMode blendMode, Paint paint, Vertices vertices);

    void drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms);

    void drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms);

    void drawShadow(Color color, double elevation, Path path, bool transparentOccluder);

private:
    PictureRecorder _recorder;


    void _constructor(double bottom, double left, PictureRecorder recorder, double right, double top);

    void _saveLayerWithoutBounds(ByteData paintData, List<Object> paintObjects);

    void _saveLayer(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double top);

    void _scale(double sx, double sy);

    void _transform(Float64List matrix4);

    void _getTransform(Float64List matrix4);

    void _clipRect(double bottom, int clipOp, bool doAntiAlias, double left, double right, double top);

    void _clipRRect(bool doAntiAlias, Float32List rrect);

    void _clipPath(bool doAntiAlias, Path path);

    void _getLocalClipBounds(Float64List bounds);

    void _getDestinationClipBounds(Float64List bounds);

    void _drawColor(int blendMode, int color);

    void _drawLine(ByteData paintData, List<Object> paintObjects, double x1, double x2, double y1, double y2);

    void _drawPaint(ByteData paintData, List<Object> paintObjects);

    void _drawRect(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double top);

    void _drawRRect(ByteData paintData, List<Object> paintObjects, Float32List rrect);

    void _drawDRRect(Float32List inner, Float32List outer, ByteData paintData, List<Object> paintObjects);

    void _drawOval(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double top);

    void _drawCircle(ByteData paintData, List<Object> paintObjects, double radius, double x, double y);

    void _drawArc(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double startAngle, double sweepAngle, double top, bool useCenter);

    void _drawPath(ByteData paintData, List<Object> paintObjects, Path path);

    String _drawImage(int filterQualityIndex, _Image image, ByteData paintData, List<Object> paintObjects, double x, double y);

    String _drawImageRect(double dstBottom, double dstLeft, double dstRight, double dstTop, int filterQualityIndex, _Image image, ByteData paintData, List<Object> paintObjects, double srcBottom, double srcLeft, double srcRight, double srcTop);

    String _drawImageNine(double centerBottom, double centerLeft, double centerRight, double centerTop, double dstBottom, double dstLeft, double dstRight, double dstTop, int filterQualityIndex, _Image image, ByteData paintData, List<Object> paintObjects);

    void _drawPicture(Picture picture);

    void _drawPoints(ByteData paintData, List<Object> paintObjects, int pointMode, Float32List points);

    void _drawVertices(int blendMode, ByteData paintData, List<Object> paintObjects, Vertices vertices);

    String _drawAtlas(_Image atlas, int blendMode, Int32List colors, Float32List cullRect, int filterQualityIndex, ByteData paintData, List<Object> paintObjects, Float32List rects, Float32List rstTransforms);

    void _drawShadow(int color, double elevation, Path path, bool transparentOccluder);

};

class Picture : NativeFieldWrapperClass1 {
public:

    Future<Image> toImage(int height, int width);

    void dispose();

    bool debugDisposed();

    int approximateBytesUsed();

private:
    bool _disposed;


    void  _();

    String _toImage(_Callback<_Image> callback, int height, int width);

    void _dispose();

};

class PictureRecorder : NativeFieldWrapperClass1 {
public:

     PictureRecorder();

    bool isRecording();

    Picture endRecording();

private:
    Canvas _canvas;


    void _constructor();

    void _endRecording(Picture outPicture);

};

class Shadow {
public:
    Color color;

    Offset offset;

    double blurRadius;


     Shadow(double blurRadius, Color color, Offset offset);

    static double convertRadiusToSigma(double radius);

    double blurSigma();

    Paint toPaint();

    Shadow scale(double factor);

    static Shadow lerp(Shadow a, Shadow b, double t);

    static List<Shadow> lerpList(List<Shadow> a, List<Shadow> b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    static const int _kColorDefault;

    static const int _kBytesPerShadow;

    static const int _kColorOffset;

    static const int _kXOffset;

    static const int _kYOffset;

    static const int _kBlurOffset;


    static ByteData _encodeShadows(List<Shadow> shadows);

};

class ImmutableBuffer : NativeFieldWrapperClass1 {
public:

    static Future<ImmutableBuffer> fromUint8List(Uint8List list);

    static Future<ImmutableBuffer> fromAsset(String assetKey);

    int length();

    bool debugDisposed();

    void dispose();

private:
    int _length;

    bool _debugDisposed;


    void  _(int _length);

    void _init(_Callback<void> callback, Uint8List list);

    String _initFromAsset(String assetKey, _Callback<int> callback);

    void _dispose();

};

class ImageDescriptor : NativeFieldWrapperClass1 {
public:

    static Future<ImageDescriptor> encoded(ImmutableBuffer buffer);

    void  raw(ImmutableBuffer buffer, int height, PixelFormat pixelFormat, int rowBytes, int width);

    int width();

    int height();

    int bytesPerPixel();

    void dispose();

    Future<Codec> instantiateCodec(int targetHeight, int targetWidth);

private:
    int _width;

    int _height;

    int _bytesPerPixel;


    void  _();

    String _initEncoded(ImmutableBuffer buffer, _Callback<void> callback);

    void _initRaw(ImmutableBuffer buffer, int height, ImageDescriptor outDescriptor, int pixelFormat, int rowBytes, int width);

    int _getWidth();

    int _getHeight();

    int _getBytesPerPixel();

    void _instantiateCodec(Codec outCodec, int targetHeight, int targetWidth);

};
Future<T> _futurize<T>(_Callbacker<T> callbacker);


class PictureRasterizationException {
public:
    String message;

    StackTrace stack;


    String toString();

private:

    void  _(String message, StackTrace stack);

};

#endif