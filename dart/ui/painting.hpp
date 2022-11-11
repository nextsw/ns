#ifndef DART_UI_PAINTING
#define DART_UI_PAINTING
#include <base.hpp>

#include <dart/core/core.hpp>

bool _rectIsValid(Rect rect);

bool _rrectIsValid(RRect rrect);

bool _offsetIsValid(Offset offset);

bool _matrix4IsValid(Float64List matrix4);

bool _radiusIsValid(Radius radius);

Color _scaleAlpha(Color a, double factor);


class ColorCls : public ObjectCls {
public:
    int value;


     ColorCls(int value);

    virtual void  fromARGB(int a, int b, int g, int r);

    virtual void  fromRGBO(int b, int g, double opacity, int r);

    virtual int alpha();

    virtual double opacity();

    virtual int red();

    virtual int green();

    virtual int blue();

    virtual Color withAlpha(int a);

    virtual Color withOpacity(double opacity);

    virtual Color withRed(int r);

    virtual Color withGreen(int g);

    virtual Color withBlue(int b);

    virtual double computeLuminance();

    static Color lerp(Color a, Color b, double t);

    static Color alphaBlend(Color background, Color foreground);

    static int getAlphaFromOpacity(double opacity);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    static double _linearizeColorComponent(double component);

};
using Color = std::shared_ptr<ColorCls>;

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

class PaintCls : public ObjectCls {
public:
    static bool enableDithering;


     PaintCls();

    virtual bool isAntiAlias();

    virtual void  isAntiAlias(bool value);

    virtual Color color();

    virtual void  color(Color value);

    virtual BlendMode blendMode();

    virtual void  blendMode(BlendMode value);

    virtual PaintingStyle style();

    virtual void  style(PaintingStyle value);

    virtual double strokeWidth();

    virtual void  strokeWidth(double value);

    virtual StrokeCap strokeCap();

    virtual void  strokeCap(StrokeCap value);

    virtual StrokeJoin strokeJoin();

    virtual void  strokeJoin(StrokeJoin value);

    virtual double strokeMiterLimit();

    virtual void  strokeMiterLimit(double value);

    virtual MaskFilter maskFilter();

    virtual void  maskFilter(MaskFilter value);

    virtual FilterQuality filterQuality();

    virtual void  filterQuality(FilterQuality value);

    virtual Shader shader();

    virtual void  shader(Shader value);

    virtual ColorFilter colorFilter();

    virtual void  colorFilter(ColorFilter value);

    virtual ImageFilter imageFilter();

    virtual void  imageFilter(ImageFilter value);

    virtual bool invertColors();

    virtual void  invertColors(bool value);

    virtual String toString();

private:
    ByteData _data;

    static int _kIsAntiAliasIndex;

    static int _kColorIndex;

    static int _kBlendModeIndex;

    static int _kStyleIndex;

    static int _kStrokeWidthIndex;

    static int _kStrokeCapIndex;

    static int _kStrokeJoinIndex;

    static int _kStrokeMiterLimitIndex;

    static int _kFilterQualityIndex;

    static int _kMaskFilterIndex;

    static int _kMaskFilterBlurStyleIndex;

    static int _kMaskFilterSigmaIndex;

    static int _kInvertColorIndex;

    static int _kDitherIndex;

    static int _kIsAntiAliasOffset;

    static int _kColorOffset;

    static int _kBlendModeOffset;

    static int _kStyleOffset;

    static int _kStrokeWidthOffset;

    static int _kStrokeCapOffset;

    static int _kStrokeJoinOffset;

    static int _kStrokeMiterLimitOffset;

    static int _kFilterQualityOffset;

    static int _kMaskFilterOffset;

    static int _kMaskFilterBlurStyleOffset;

    static int _kMaskFilterSigmaOffset;

    static int _kInvertColorOffset;

    static int _kDitherOffset;

    static int _kDataByteCount;

    List<Object> _objects;

    static int _kShaderIndex;

    static int _kColorFilterIndex;

    static int _kImageFilterIndex;

    static int _kObjectCount;

    static int _kColorDefault;

    static int _kBlendModeDefault;

    static double _kStrokeMiterLimitDefault;


    virtual List<Object> _ensureObjectsInitialized();

    virtual bool _dither();

    virtual void  _dither(bool value);

};
using Paint = std::shared_ptr<PaintCls>;

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

class ImageCls : public ObjectCls {
public:
    int width;

    int height;


    virtual void dispose();

    virtual bool debugDisposed();

    virtual Future<ByteData> toByteData(ImageByteFormat format);

    virtual List<StackTrace> debugGetOpenHandleStackTraces();

    virtual Image clone();

    virtual bool isCloneOf(Image other);

    virtual String toString();

private:
    _Image _image;

    StackTrace _debugStack;

    bool _disposed;


    virtual void  _(_Image _image, int height, int width);

};
using Image = std::shared_ptr<ImageCls>;

class _ImageCls : public NativeFieldWrapperClass1Cls {
public:

    virtual int width();
    virtual int height();
    virtual Future<ByteData> toByteData(ImageByteFormat format);

    virtual void dispose();

    virtual String toString();

private:
    bool _disposed;

    Set<Image> _handles;


    virtual void  _();
    virtual String _toByteData(_Callback<Uint8List> callback, int format);
    virtual void _dispose();
};
using _Image = std::shared_ptr<_ImageCls>;

class FrameInfoCls : public ObjectCls {
public:
    Duration duration;

    Image image;


private:

    virtual void  _(Duration duration, Image image);
};
using FrameInfo = std::shared_ptr<FrameInfoCls>;

class CodecCls : public NativeFieldWrapperClass1Cls {
public:

    virtual int frameCount();

    virtual int repetitionCount();

    virtual Future<FrameInfo> getNextFrame();

    virtual void dispose();
private:
    int _cachedFrameCount;

    int _cachedRepetitionCount;


    virtual void  _();
    virtual int _frameCount();
    virtual int _repetitionCount();
    virtual String _getNextFrame(std::function<void(_Image , int )> callback);
};
using Codec = std::shared_ptr<CodecCls>;
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

class EngineLayerCls : public NativeFieldWrapperClass1Cls {
public:

    virtual void dispose();
private:

    virtual void  _();
};
using EngineLayer = std::shared_ptr<EngineLayerCls>;

class PathCls : public NativeFieldWrapperClass1Cls {
public:

     PathCls();

    virtual void  from(Path source);

    virtual PathFillType fillType();

    virtual void  fillType(PathFillType value);

    virtual void moveTo(double x, double y);
    virtual void relativeMoveTo(double dx, double dy);
    virtual void lineTo(double x, double y);
    virtual void relativeLineTo(double dx, double dy);
    virtual void quadraticBezierTo(double x1, double x2, double y1, double y2);
    virtual void relativeQuadraticBezierTo(double x1, double x2, double y1, double y2);
    virtual void cubicTo(double x1, double x2, double x3, double y1, double y2, double y3);
    virtual void relativeCubicTo(double x1, double x2, double x3, double y1, double y2, double y3);
    virtual void conicTo(double w, double x1, double x2, double y1, double y2);
    virtual void relativeConicTo(double w, double x1, double x2, double y1, double y2);
    virtual void arcTo(bool forceMoveTo, Rect rect, double startAngle, double sweepAngle);

    virtual void arcToPoint(Offset arcEnd, bool clockwise, bool largeArc, Radius radius, double rotation);

    virtual void relativeArcToPoint(Offset arcEndDelta, bool clockwise, bool largeArc, Radius radius, double rotation);

    virtual void addRect(Rect rect);

    virtual void addOval(Rect oval);

    virtual void addArc(Rect oval, double startAngle, double sweepAngle);

    virtual void addPolygon(bool close, List<Offset> points);

    virtual void addRRect(RRect rrect);

    virtual void addPath(Float64List matrix4, Offset offset, Path path);

    virtual void extendWithPath(Float64List matrix4, Offset offset, Path path);

    virtual void close();
    virtual void reset();
    virtual bool contains(Offset point);

    virtual Path shift(Offset offset);

    virtual Path transform(Float64List matrix4);

    virtual Rect getBounds();

    static Path combine(PathOperation operation, Path path1, Path path2);

    virtual PathMetrics computeMetrics(bool forceClosed);

private:

    virtual void _constructor();
    virtual void  _();
    virtual void _clone(Path outPath);
    virtual int _getFillType();
    virtual void _setFillType(int fillType);
    virtual void _arcTo(double bottom, bool forceMoveTo, double left, double right, double startAngle, double sweepAngle, double top);
    virtual void _arcToPoint(double arcEndX, double arcEndY, bool clockwise, bool largeArc, double radiusX, double radiusY, double rotation);
    virtual void _relativeArcToPoint(double arcEndX, double arcEndY, bool clockwise, bool largeArc, double radiusX, double radiusY, double rotation);
    virtual void _addRect(double bottom, double left, double right, double top);
    virtual void _addOval(double bottom, double left, double right, double top);
    virtual void _addArc(double bottom, double left, double right, double startAngle, double sweepAngle, double top);
    virtual void _addPolygon(bool close, Float32List points);
    virtual void _addRRect(Float32List rrect);
    virtual void _addPath(double dx, double dy, Path path);
    virtual void _addPathWithMatrix(double dx, double dy, Float64List matrix, Path path);
    virtual void _extendWithPath(double dx, double dy, Path path);
    virtual void _extendWithPathAndMatrix(double dx, double dy, Float64List matrix, Path path);
    virtual bool _contains(double x, double y);
    virtual void _shift(double dx, double dy, Path outPath);
    virtual void _transform(Float64List matrix4, Path outPath);
    virtual Float32List _getBounds();
    virtual bool _op(int operation, Path path1, Path path2);
};
using Path = std::shared_ptr<PathCls>;

class TangentCls : public ObjectCls {
public:
    Offset position;

    Offset vector;


     TangentCls(Offset position, Offset vector);

    virtual void  fromAngle(double angle, Offset position);

    virtual double angle();

private:

};
using Tangent = std::shared_ptr<TangentCls>;

class PathMetricsCls : public IterableBaseCls<PathMetric> {
public:

    virtual Iterator<PathMetric> iterator();

private:
    Iterator<PathMetric> _iterator;


    virtual void  _(bool forceClosed, Path path);

};
using PathMetrics = std::shared_ptr<PathMetricsCls>;

class PathMetricIteratorCls : public ObjectCls {
public:

    virtual PathMetric current();

    virtual bool moveNext();

private:
    PathMetric _pathMetric;

    _PathMeasure _pathMeasure;


    virtual void  _(_PathMeasure _pathMeasure);

};
using PathMetricIterator = std::shared_ptr<PathMetricIteratorCls>;

class PathMetricCls : public ObjectCls {
public:
    double length;

    bool isClosed;

    int contourIndex;


    virtual Tangent getTangentForOffset(double distance);

    virtual Path extractPath(double end, double start, bool startWithMoveTo);

    virtual String toString();

private:
    _PathMeasure _measure;


    virtual void  _(_PathMeasure _measure);

};
using PathMetric = std::shared_ptr<PathMetricCls>;

class _PathMeasureCls : public NativeFieldWrapperClass1Cls {
public:
    int currentContourIndex;


    virtual double length(int contourIndex);

    virtual Tangent getTangentForOffset(int contourIndex, double distance);

    virtual Path extractPath(int contourIndex, double end, double start, bool startWithMoveTo);

    virtual bool isClosed(int contourIndex);

private:

     _PathMeasureCls(bool forceClosed, Path path);

    virtual void _constructor(bool forceClosed, Path path);
    virtual double _length(int contourIndex);
    virtual Float32List _getPosTan(int contourIndex, double distance);
    virtual void _extractPath(int contourIndex, double end, Path outPath, double start, bool startWithMoveTo);
    virtual bool _isClosed(int contourIndex);
    virtual bool _nextContour();

    virtual bool _nativeNextContour();
};
using _PathMeasure = std::shared_ptr<_PathMeasureCls>;

enum BlurStyle{
    normal,
    solid,
    outer,
    inner,
} // end BlurStyle

class MaskFilterCls : public ObjectCls {
public:

    virtual void  blur(double _sigma, BlurStyle _style);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    BlurStyle _style;

    double _sigma;

    static int _TypeNone;

    static int _TypeBlur;


};
using MaskFilter = std::shared_ptr<MaskFilterCls>;

class ColorFilterCls : public ObjectCls {
public:

    virtual void  mode(BlendMode blendMode, Color color);

    virtual void  matrix(List<double> matrix);

    virtual void  linearToSrgbGamma();

    virtual void  srgbToLinearGamma();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    Color _color;

    BlendMode _blendMode;

    List<double> _matrix;

    int _type;

    static int _kTypeMode;

    static int _kTypeMatrix;

    static int _kTypeLinearToSrgbGamma;

    static int _kTypeSrgbToLinearGamma;


    virtual _ImageFilter _toNativeImageFilter();

    virtual _ColorFilter _toNativeColorFilter();

    virtual String _shortDescription();

};
using ColorFilter = std::shared_ptr<ColorFilterCls>;

class _ColorFilterCls : public NativeFieldWrapperClass1Cls {
public:
    ColorFilter creator;


    virtual void  mode(ColorFilter creator);

    virtual void  matrix(ColorFilter creator);

    virtual void  linearToSrgbGamma(ColorFilter creator);

    virtual void  srgbToLinearGamma(ColorFilter creator);

private:

    virtual void _constructor();
    virtual void _initMode(int blendMode, int color);
    virtual void _initMatrix(Float32List matrix);
    virtual void _initLinearToSrgbGamma();
    virtual void _initSrgbToLinearGamma();
};
using _ColorFilter = std::shared_ptr<_ColorFilterCls>;

class ImageFilterCls : public ObjectCls {
public:

    virtual void  blur(double sigmaX, double sigmaY, TileMode tileMode);

    virtual void  dilate(double radiusX, double radiusY);

    virtual void  erode(double radiusX, double radiusY);

    virtual void  matrix(FilterQuality filterQuality, Float64List matrix4);

    virtual void  compose(ImageFilter inner, ImageFilter outer);

private:

    virtual _ImageFilter _toNativeImageFilter();
    virtual String _shortDescription();
};
using ImageFilter = std::shared_ptr<ImageFilterCls>;

class _MatrixImageFilterCls : public ObjectCls {
public:
    Float64List data;

    FilterQuality filterQuality;

    _ImageFilter nativeFilter;


    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _MatrixImageFilterCls(Float64List data, FilterQuality filterQuality);
    virtual _ImageFilter _toNativeImageFilter();

    virtual String _shortDescription();

};
using _MatrixImageFilter = std::shared_ptr<_MatrixImageFilterCls>;

class _GaussianBlurImageFilterCls : public ObjectCls {
public:
    double sigmaX;

    double sigmaY;

    TileMode tileMode;

    _ImageFilter nativeFilter;


    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _GaussianBlurImageFilterCls(double sigmaX, double sigmaY, TileMode tileMode);
    virtual _ImageFilter _toNativeImageFilter();

    virtual String _modeString();

    virtual String _shortDescription();

};
using _GaussianBlurImageFilter = std::shared_ptr<_GaussianBlurImageFilterCls>;

class _DilateImageFilterCls : public ObjectCls {
public:
    double radiusX;

    double radiusY;

    _ImageFilter nativeFilter;


    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _DilateImageFilterCls(double radiusX, double radiusY);
    virtual _ImageFilter _toNativeImageFilter();

    virtual String _shortDescription();

};
using _DilateImageFilter = std::shared_ptr<_DilateImageFilterCls>;

class _ErodeImageFilterCls : public ObjectCls {
public:
    double radiusX;

    double radiusY;

    _ImageFilter nativeFilter;


    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _ErodeImageFilterCls(double radiusX, double radiusY);
    virtual _ImageFilter _toNativeImageFilter();

    virtual String _shortDescription();

};
using _ErodeImageFilter = std::shared_ptr<_ErodeImageFilterCls>;

class _ComposeImageFilterCls : public ObjectCls {
public:
    ImageFilter innerFilter;

    ImageFilter outerFilter;

    _ImageFilter nativeFilter;


    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _ComposeImageFilterCls(ImageFilter innerFilter, ImageFilter outerFilter);
    virtual _ImageFilter _toNativeImageFilter();

    virtual String _shortDescription();

};
using _ComposeImageFilter = std::shared_ptr<_ComposeImageFilterCls>;

class _ImageFilterCls : public NativeFieldWrapperClass1Cls {
public:
    ImageFilter creator;


    virtual void  blur(_GaussianBlurImageFilter filter);

    virtual void  dilate(_DilateImageFilter filter);

    virtual void  erode(_ErodeImageFilter filter);

    virtual void  matrix(_MatrixImageFilter filter);

    virtual void  fromColorFilter(ColorFilter filter);

    virtual void  composed(_ComposeImageFilter filter);

private:

    virtual void _constructor();
    virtual void _initBlur(double sigmaX, double sigmaY, int tileMode);
    virtual void _initDilate(double radiusX, double radiusY);
    virtual void _initErode(double radiusX, double radiusY);
    virtual void _initMatrix(int filterQuality, Float64List matrix4);
    virtual void _initColorFilter(_ColorFilter colorFilter);
    virtual void _initComposed(_ImageFilter innerFilter, _ImageFilter outerFilter);
};
using _ImageFilter = std::shared_ptr<_ImageFilterCls>;

class ShaderCls : public NativeFieldWrapperClass1Cls {
public:

private:

    virtual void  _();
};
using Shader = std::shared_ptr<ShaderCls>;

enum TileMode{
    clamp,
    repeated,
    mirror,
    decal,
} // end TileMode
Int32List _encodeColorList(List<Color> colors);

Float32List _encodePointList(List<Offset> points);

Float32List _encodeTwoPoints(Offset pointA, Offset pointB);


class GradientCls : public ShaderCls {
public:

    virtual void  linear(List<double> colorStops, List<Color> colors, Offset from, Float64List matrix4, TileMode tileMode, Offset to);

    virtual void  radial(Offset center, List<double> colorStops, List<Color> colors, Offset focal, double focalRadius, Float64List matrix4, double radius, TileMode tileMode);

    virtual void  sweep(Offset center, List<double> colorStops, List<Color> colors, double endAngle, Float64List matrix4, double startAngle, TileMode tileMode);

private:

    virtual void _constructor();
    virtual void _initLinear(Float32List colorStops, Int32List colors, Float32List endPoints, Float64List matrix4, int tileMode);
    virtual void _initRadial(double centerX, double centerY, Float32List colorStops, Int32List colors, Float64List matrix4, double radius, int tileMode);
    virtual void _initConical(Float32List colorStops, Int32List colors, double endRadius, double endX, double endY, Float64List matrix4, double startRadius, double startX, double startY, int tileMode);
    virtual void _initSweep(double centerX, double centerY, Float32List colorStops, Int32List colors, double endAngle, Float64List matrix, double startAngle, int tileMode);
    static void _validateColorStops(List<double> colorStops, List<Color> colors);

};
using Gradient = std::shared_ptr<GradientCls>;

class ImageShaderCls : public ShaderCls {
public:

     ImageShaderCls(FilterQuality filterQuality, Image image, Float64List matrix4, TileMode tmx, TileMode tmy);

private:

    virtual void _constructor();
    virtual String _initWithImage(int filterQualityIndex, _Image image, Float64List matrix4, int tmx, int tmy);
};
using ImageShader = std::shared_ptr<ImageShaderCls>;

class FragmentProgramCls : public NativeFieldWrapperClass1Cls {
public:

    static Future<FragmentProgram> compile(bool debugPrint, ByteBuffer spirv);

    virtual Shader shader(Float32List floatUniforms, List<ImageShader> samplerUniforms);

private:
    int _uniformFloatCount;

    int _samplerCount;


    virtual void  _(bool debugPrint, ByteBuffer spirv);

    virtual void _constructor();
    virtual void _init(bool debugPrint, String sksl);
    virtual void _shader(Float32List floatUniforms, List<ImageShader> samplerUniforms, _FragmentShader shader);
};
using FragmentProgram = std::shared_ptr<FragmentProgramCls>;

class _FragmentShaderCls : public ShaderCls {
public:

    virtual bool operator==(Object other);

    virtual int hashCode();

private:
    FragmentProgram _builder;

    Float32List _floatUniforms;

    List<ImageShader> _samplerUniforms;


     _FragmentShaderCls(FragmentProgram _builder, Float32List _floatUniforms, List<ImageShader> _samplerUniforms);

};
using _FragmentShader = std::shared_ptr<_FragmentShaderCls>;

enum VertexMode{
    triangles,
    triangleStrip,
    triangleFan,
} // end VertexMode

class VerticesCls : public NativeFieldWrapperClass1Cls {
public:

     VerticesCls(List<Color> colors, List<int> indices, VertexMode mode, List<Offset> positions, List<Offset> textureCoordinates);

    virtual void  raw(Int32List colors, Uint16List indices, VertexMode mode, Float32List positions, Float32List textureCoordinates);

private:

    virtual bool _init(Int32List colors, Uint16List indices, int mode, Vertices outVertices, Float32List positions, Float32List textureCoordinates);
};
using Vertices = std::shared_ptr<VerticesCls>;

enum PointMode{
    points,
    lines,
    polygon,
} // end PointMode

enum ClipOp{
    difference,
    intersect,
} // end ClipOp

class CanvasCls : public NativeFieldWrapperClass1Cls {
public:

     CanvasCls(Rect cullRect, PictureRecorder recorder);

    virtual void save();
    virtual void saveLayer(Rect bounds, Paint paint);

    virtual void restore();
    virtual int getSaveCount();
    virtual void translate(double dx, double dy);
    virtual void scale(double sx, double sy);

    virtual void rotate(double radians);
    virtual void skew(double sx, double sy);
    virtual void transform(Float64List matrix4);

    virtual Float64List getTransform();

    virtual void clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect);

    virtual void clipRRect(bool doAntiAlias, RRect rrect);

    virtual void clipPath(bool doAntiAlias, Path path);

    virtual Rect getLocalClipBounds();

    virtual Rect getDestinationClipBounds();

    virtual void drawColor(BlendMode blendMode, Color color);

    virtual void drawLine(Offset p1, Offset p2, Paint paint);

    virtual void drawPaint(Paint paint);

    virtual void drawRect(Paint paint, Rect rect);

    virtual void drawRRect(Paint paint, RRect rrect);

    virtual void drawDRRect(RRect inner, RRect outer, Paint paint);

    virtual void drawOval(Paint paint, Rect rect);

    virtual void drawCircle(Offset c, Paint paint, double radius);

    virtual void drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter);

    virtual void drawPath(Paint paint, Path path);

    virtual void drawImage(Image image, Offset offset, Paint paint);

    virtual void drawImageRect(Rect dst, Image image, Paint paint, Rect src);

    virtual void drawImageNine(Rect center, Rect dst, Image image, Paint paint);

    virtual void drawPicture(Picture picture);

    virtual void drawParagraph(Offset offset, Paragraph paragraph);

    virtual void drawPoints(Paint paint, PointMode pointMode, List<Offset> points);

    virtual void drawRawPoints(Paint paint, PointMode pointMode, Float32List points);

    virtual void drawVertices(BlendMode blendMode, Paint paint, Vertices vertices);

    virtual void drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms);

    virtual void drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms);

    virtual void drawShadow(Color color, double elevation, Path path, bool transparentOccluder);

private:
    PictureRecorder _recorder;


    virtual void _constructor(double bottom, double left, PictureRecorder recorder, double right, double top);
    virtual void _saveLayerWithoutBounds(ByteData paintData, List<Object> paintObjects);
    virtual void _saveLayer(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double top);
    virtual void _scale(double sx, double sy);
    virtual void _transform(Float64List matrix4);
    virtual void _getTransform(Float64List matrix4);
    virtual void _clipRect(double bottom, int clipOp, bool doAntiAlias, double left, double right, double top);
    virtual void _clipRRect(bool doAntiAlias, Float32List rrect);
    virtual void _clipPath(bool doAntiAlias, Path path);
    virtual void _getLocalClipBounds(Float64List bounds);
    virtual void _getDestinationClipBounds(Float64List bounds);
    virtual void _drawColor(int blendMode, int color);
    virtual void _drawLine(ByteData paintData, List<Object> paintObjects, double x1, double x2, double y1, double y2);
    virtual void _drawPaint(ByteData paintData, List<Object> paintObjects);
    virtual void _drawRect(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double top);
    virtual void _drawRRect(ByteData paintData, List<Object> paintObjects, Float32List rrect);
    virtual void _drawDRRect(Float32List inner, Float32List outer, ByteData paintData, List<Object> paintObjects);
    virtual void _drawOval(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double top);
    virtual void _drawCircle(ByteData paintData, List<Object> paintObjects, double radius, double x, double y);
    virtual void _drawArc(double bottom, double left, ByteData paintData, List<Object> paintObjects, double right, double startAngle, double sweepAngle, double top, bool useCenter);
    virtual void _drawPath(ByteData paintData, List<Object> paintObjects, Path path);
    virtual String _drawImage(int filterQualityIndex, _Image image, ByteData paintData, List<Object> paintObjects, double x, double y);
    virtual String _drawImageRect(double dstBottom, double dstLeft, double dstRight, double dstTop, int filterQualityIndex, _Image image, ByteData paintData, List<Object> paintObjects, double srcBottom, double srcLeft, double srcRight, double srcTop);
    virtual String _drawImageNine(double centerBottom, double centerLeft, double centerRight, double centerTop, double dstBottom, double dstLeft, double dstRight, double dstTop, int filterQualityIndex, _Image image, ByteData paintData, List<Object> paintObjects);
    virtual void _drawPicture(Picture picture);
    virtual void _drawPoints(ByteData paintData, List<Object> paintObjects, int pointMode, Float32List points);
    virtual void _drawVertices(int blendMode, ByteData paintData, List<Object> paintObjects, Vertices vertices);
    virtual String _drawAtlas(_Image atlas, int blendMode, Int32List colors, Float32List cullRect, int filterQualityIndex, ByteData paintData, List<Object> paintObjects, Float32List rects, Float32List rstTransforms);
    virtual void _drawShadow(int color, double elevation, Path path, bool transparentOccluder);
};
using Canvas = std::shared_ptr<CanvasCls>;

class PictureCls : public NativeFieldWrapperClass1Cls {
public:

    virtual Future<Image> toImage(int height, int width);

    virtual void dispose();

    virtual bool debugDisposed();

    virtual int approximateBytesUsed();
private:
    bool _disposed;


    virtual void  _();
    virtual String _toImage(_Callback<_Image> callback, int height, int width);
    virtual void _dispose();
};
using Picture = std::shared_ptr<PictureCls>;

class PictureRecorderCls : public NativeFieldWrapperClass1Cls {
public:

     PictureRecorderCls();

    virtual bool isRecording();

    virtual Picture endRecording();

private:
    Canvas _canvas;


    virtual void _constructor();
    virtual void _endRecording(Picture outPicture);
};
using PictureRecorder = std::shared_ptr<PictureRecorderCls>;

class ShadowCls : public ObjectCls {
public:
    Color color;

    Offset offset;

    double blurRadius;


     ShadowCls(double blurRadius, Color color, Offset offset);

    static double convertRadiusToSigma(double radius);

    virtual double blurSigma();

    virtual Paint toPaint();

    virtual Shadow scale(double factor);

    static Shadow lerp(Shadow a, Shadow b, double t);

    static List<Shadow> lerpList(List<Shadow> a, List<Shadow> b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    static int _kColorDefault;

    static int _kBytesPerShadow;

    static int _kColorOffset;

    static int _kXOffset;

    static int _kYOffset;

    static int _kBlurOffset;


    static ByteData _encodeShadows(List<Shadow> shadows);

};
using Shadow = std::shared_ptr<ShadowCls>;

class ImmutableBufferCls : public NativeFieldWrapperClass1Cls {
public:

    static Future<ImmutableBuffer> fromUint8List(Uint8List list);

    static Future<ImmutableBuffer> fromAsset(String assetKey);

    virtual int length();

    virtual bool debugDisposed();

    virtual void dispose();

private:
    int _length;

    bool _debugDisposed;


    virtual void  _(int _length);
    virtual void _init(_Callback<void> callback, Uint8List list);
    virtual String _initFromAsset(String assetKey, _Callback<int> callback);
    virtual void _dispose();
};
using ImmutableBuffer = std::shared_ptr<ImmutableBufferCls>;

class ImageDescriptorCls : public NativeFieldWrapperClass1Cls {
public:

    static Future<ImageDescriptor> encoded(ImmutableBuffer buffer);

    virtual void  raw(ImmutableBuffer buffer, int height, PixelFormat pixelFormat, int rowBytes, int width);

    virtual int width();

    virtual int height();

    virtual int bytesPerPixel();

    virtual void dispose();
    virtual Future<Codec> instantiateCodec(int targetHeight, int targetWidth);

private:
    int _width;

    int _height;

    int _bytesPerPixel;


    virtual void  _();
    virtual String _initEncoded(ImmutableBuffer buffer, _Callback<void> callback);
    virtual void _initRaw(ImmutableBuffer buffer, int height, ImageDescriptor outDescriptor, int pixelFormat, int rowBytes, int width);
    virtual int _getWidth();
    virtual int _getHeight();
    virtual int _getBytesPerPixel();
    virtual void _instantiateCodec(Codec outCodec, int targetHeight, int targetWidth);
};
using ImageDescriptor = std::shared_ptr<ImageDescriptorCls>;
template<typename T>
 Future<T> _futurize(_Callbacker<T> callbacker);


class PictureRasterizationExceptionCls : public ObjectCls {
public:
    String message;

    StackTrace stack;


    virtual String toString();

private:

    virtual void  _(String message, StackTrace stack);
};
using PictureRasterizationException = std::shared_ptr<PictureRasterizationExceptionCls>;


#endif