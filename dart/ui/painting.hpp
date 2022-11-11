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

    virtual void  fromARGB(int a, int r, int g, int b);

    virtual void  fromRGBO(int r, int g, int b, double opacity);

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

    static Color alphaBlend(Color foreground, Color background);

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


    virtual void  _(_Image _image, int width, int height);

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
    virtual String _toByteData(int format, _Callback<Uint8List> callback);
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
Future<Codec> instantiateImageCodec(Uint8List list, bool allowUpscaling, int targetHeight, int targetWidth);

Future<Codec> instantiateImageCodecFromBuffer(ImmutableBuffer buffer, bool allowUpscaling, int targetHeight, int targetWidth);

void decodeImageFromList(Uint8List list, ImageDecoderCallback callback);

Future<void> _decodeImageFromListAsync(Uint8List list, ImageDecoderCallback callback);

void decodeImageFromPixels(Uint8List pixels, int width, int height, PixelFormat format, ImageDecoderCallback callback, bool allowUpscaling, int rowBytes, int targetHeight, int targetWidth);


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
    virtual void quadraticBezierTo(double x1, double y1, double x2, double y2);
    virtual void relativeQuadraticBezierTo(double x1, double y1, double x2, double y2);
    virtual void cubicTo(double x1, double y1, double x2, double y2, double x3, double y3);
    virtual void relativeCubicTo(double x1, double y1, double x2, double y2, double x3, double y3);
    virtual void conicTo(double x1, double y1, double x2, double y2, double w);
    virtual void relativeConicTo(double x1, double y1, double x2, double y2, double w);
    virtual void arcTo(Rect rect, double startAngle, double sweepAngle, bool forceMoveTo);

    virtual void arcToPoint(Offset arcEnd, bool clockwise, bool largeArc, Radius radius, double rotation);

    virtual void relativeArcToPoint(Offset arcEndDelta, bool clockwise, bool largeArc, Radius radius, double rotation);

    virtual void addRect(Rect rect);

    virtual void addOval(Rect oval);

    virtual void addArc(Rect oval, double startAngle, double sweepAngle);

    virtual void addPolygon(List<Offset> points, bool close);

    virtual void addRRect(RRect rrect);

    virtual void addPath(Path path, Offset offset, Float64List matrix4);

    virtual void extendWithPath(Path path, Offset offset, Float64List matrix4);

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
    virtual void _arcTo(double left, double top, double right, double bottom, double startAngle, double sweepAngle, bool forceMoveTo);
    virtual void _arcToPoint(double arcEndX, double arcEndY, double radiusX, double radiusY, double rotation, bool largeArc, bool clockwise);
    virtual void _relativeArcToPoint(double arcEndX, double arcEndY, double radiusX, double radiusY, double rotation, bool largeArc, bool clockwise);
    virtual void _addRect(double left, double top, double right, double bottom);
    virtual void _addOval(double left, double top, double right, double bottom);
    virtual void _addArc(double left, double top, double right, double bottom, double startAngle, double sweepAngle);
    virtual void _addPolygon(Float32List points, bool close);
    virtual void _addRRect(Float32List rrect);
    virtual void _addPath(Path path, double dx, double dy);
    virtual void _addPathWithMatrix(Path path, double dx, double dy, Float64List matrix);
    virtual void _extendWithPath(Path path, double dx, double dy);
    virtual void _extendWithPathAndMatrix(Path path, double dx, double dy, Float64List matrix);
    virtual bool _contains(double x, double y);
    virtual void _shift(Path outPath, double dx, double dy);
    virtual void _transform(Path outPath, Float64List matrix4);
    virtual Float32List _getBounds();
    virtual bool _op(Path path1, Path path2, int operation);
};
using Path = std::shared_ptr<PathCls>;

class TangentCls : public ObjectCls {
public:
    Offset position;

    Offset vector;


     TangentCls(Offset position, Offset vector);

    virtual void  fromAngle(Offset position, double angle);

    virtual double angle();

private:

};
using Tangent = std::shared_ptr<TangentCls>;

class PathMetricsCls : public IterableBaseCls<PathMetric> {
public:

    virtual Iterator<PathMetric> iterator();

private:
    Iterator<PathMetric> _iterator;


    virtual void  _(Path path, bool forceClosed);

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

    virtual Path extractPath(double start, double end, bool startWithMoveTo);

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

    virtual Path extractPath(int contourIndex, double start, double end, bool startWithMoveTo);

    virtual bool isClosed(int contourIndex);

private:

     _PathMeasureCls(Path path, bool forceClosed);

    virtual void _constructor(Path path, bool forceClosed);
    virtual double _length(int contourIndex);
    virtual Float32List _getPosTan(int contourIndex, double distance);
    virtual void _extractPath(Path outPath, int contourIndex, double start, double end, bool startWithMoveTo);
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

    virtual void  blur(BlurStyle _style, double _sigma);

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

    virtual void  mode(Color color, BlendMode blendMode);

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
    virtual void _initMode(int color, int blendMode);
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

    virtual void  matrix(Float64List matrix4, FilterQuality filterQuality);

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
    virtual void _initMatrix(Float64List matrix4, int filterQuality);
    virtual void _initColorFilter(_ColorFilter colorFilter);
    virtual void _initComposed(_ImageFilter outerFilter, _ImageFilter innerFilter);
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

    virtual void  linear(Offset from, Offset to, List<Color> colors, List<double> colorStops, TileMode tileMode, Float64List matrix4);

    virtual void  radial(Offset center, double radius, List<Color> colors, List<double> colorStops, TileMode tileMode, Float64List matrix4, Offset focal, double focalRadius);

    virtual void  sweep(Offset center, List<Color> colors, List<double> colorStops, TileMode tileMode, double startAngle, double endAngle, Float64List matrix4);

private:

    virtual void _constructor();
    virtual void _initLinear(Float32List endPoints, Int32List colors, Float32List colorStops, int tileMode, Float64List matrix4);
    virtual void _initRadial(double centerX, double centerY, double radius, Int32List colors, Float32List colorStops, int tileMode, Float64List matrix4);
    virtual void _initConical(double startX, double startY, double startRadius, double endX, double endY, double endRadius, Int32List colors, Float32List colorStops, int tileMode, Float64List matrix4);
    virtual void _initSweep(double centerX, double centerY, Int32List colors, Float32List colorStops, int tileMode, double startAngle, double endAngle, Float64List matrix);
    static void _validateColorStops(List<Color> colors, List<double> colorStops);

};
using Gradient = std::shared_ptr<GradientCls>;

class ImageShaderCls : public ShaderCls {
public:

     ImageShaderCls(Image image, TileMode tmx, TileMode tmy, Float64List matrix4, FilterQuality filterQuality);

private:

    virtual void _constructor();
    virtual String _initWithImage(_Image image, int tmx, int tmy, int filterQualityIndex, Float64List matrix4);
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
    virtual void _init(String sksl, bool debugPrint);
    virtual void _shader(_FragmentShader shader, Float32List floatUniforms, List<ImageShader> samplerUniforms);
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

     VerticesCls(VertexMode mode, List<Offset> positions, List<Color> colors, List<int> indices, List<Offset> textureCoordinates);

    virtual void  raw(VertexMode mode, Float32List positions, Int32List colors, Uint16List indices, Float32List textureCoordinates);

private:

    virtual bool _init(Vertices outVertices, int mode, Float32List positions, Float32List textureCoordinates, Int32List colors, Uint16List indices);
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

     CanvasCls(PictureRecorder recorder, Rect cullRect);

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

    virtual void clipRect(Rect rect, ClipOp clipOp, bool doAntiAlias);

    virtual void clipRRect(RRect rrect, bool doAntiAlias);

    virtual void clipPath(Path path, bool doAntiAlias);

    virtual Rect getLocalClipBounds();

    virtual Rect getDestinationClipBounds();

    virtual void drawColor(Color color, BlendMode blendMode);

    virtual void drawLine(Offset p1, Offset p2, Paint paint);

    virtual void drawPaint(Paint paint);

    virtual void drawRect(Rect rect, Paint paint);

    virtual void drawRRect(RRect rrect, Paint paint);

    virtual void drawDRRect(RRect outer, RRect inner, Paint paint);

    virtual void drawOval(Rect rect, Paint paint);

    virtual void drawCircle(Offset c, double radius, Paint paint);

    virtual void drawArc(Rect rect, double startAngle, double sweepAngle, bool useCenter, Paint paint);

    virtual void drawPath(Path path, Paint paint);

    virtual void drawImage(Image image, Offset offset, Paint paint);

    virtual void drawImageRect(Image image, Rect src, Rect dst, Paint paint);

    virtual void drawImageNine(Image image, Rect center, Rect dst, Paint paint);

    virtual void drawPicture(Picture picture);

    virtual void drawParagraph(Paragraph paragraph, Offset offset);

    virtual void drawPoints(PointMode pointMode, List<Offset> points, Paint paint);

    virtual void drawRawPoints(PointMode pointMode, Float32List points, Paint paint);

    virtual void drawVertices(Vertices vertices, BlendMode blendMode, Paint paint);

    virtual void drawAtlas(Image atlas, List<RSTransform> transforms, List<Rect> rects, List<Color> colors, BlendMode blendMode, Rect cullRect, Paint paint);

    virtual void drawRawAtlas(Image atlas, Float32List rstTransforms, Float32List rects, Int32List colors, BlendMode blendMode, Rect cullRect, Paint paint);

    virtual void drawShadow(Path path, Color color, double elevation, bool transparentOccluder);

private:
    PictureRecorder _recorder;


    virtual void _constructor(PictureRecorder recorder, double left, double top, double right, double bottom);
    virtual void _saveLayerWithoutBounds(List<Object> paintObjects, ByteData paintData);
    virtual void _saveLayer(double left, double top, double right, double bottom, List<Object> paintObjects, ByteData paintData);
    virtual void _scale(double sx, double sy);
    virtual void _transform(Float64List matrix4);
    virtual void _getTransform(Float64List matrix4);
    virtual void _clipRect(double left, double top, double right, double bottom, int clipOp, bool doAntiAlias);
    virtual void _clipRRect(Float32List rrect, bool doAntiAlias);
    virtual void _clipPath(Path path, bool doAntiAlias);
    virtual void _getLocalClipBounds(Float64List bounds);
    virtual void _getDestinationClipBounds(Float64List bounds);
    virtual void _drawColor(int color, int blendMode);
    virtual void _drawLine(double x1, double y1, double x2, double y2, List<Object> paintObjects, ByteData paintData);
    virtual void _drawPaint(List<Object> paintObjects, ByteData paintData);
    virtual void _drawRect(double left, double top, double right, double bottom, List<Object> paintObjects, ByteData paintData);
    virtual void _drawRRect(Float32List rrect, List<Object> paintObjects, ByteData paintData);
    virtual void _drawDRRect(Float32List outer, Float32List inner, List<Object> paintObjects, ByteData paintData);
    virtual void _drawOval(double left, double top, double right, double bottom, List<Object> paintObjects, ByteData paintData);
    virtual void _drawCircle(double x, double y, double radius, List<Object> paintObjects, ByteData paintData);
    virtual void _drawArc(double left, double top, double right, double bottom, double startAngle, double sweepAngle, bool useCenter, List<Object> paintObjects, ByteData paintData);
    virtual void _drawPath(Path path, List<Object> paintObjects, ByteData paintData);
    virtual String _drawImage(_Image image, double x, double y, List<Object> paintObjects, ByteData paintData, int filterQualityIndex);
    virtual String _drawImageRect(_Image image, double srcLeft, double srcTop, double srcRight, double srcBottom, double dstLeft, double dstTop, double dstRight, double dstBottom, List<Object> paintObjects, ByteData paintData, int filterQualityIndex);
    virtual String _drawImageNine(_Image image, double centerLeft, double centerTop, double centerRight, double centerBottom, double dstLeft, double dstTop, double dstRight, double dstBottom, List<Object> paintObjects, ByteData paintData, int filterQualityIndex);
    virtual void _drawPicture(Picture picture);
    virtual void _drawPoints(List<Object> paintObjects, ByteData paintData, int pointMode, Float32List points);
    virtual void _drawVertices(Vertices vertices, int blendMode, List<Object> paintObjects, ByteData paintData);
    virtual String _drawAtlas(List<Object> paintObjects, ByteData paintData, int filterQualityIndex, _Image atlas, Float32List rstTransforms, Float32List rects, Int32List colors, int blendMode, Float32List cullRect);
    virtual void _drawShadow(Path path, int color, double elevation, bool transparentOccluder);
};
using Canvas = std::shared_ptr<CanvasCls>;

class PictureCls : public NativeFieldWrapperClass1Cls {
public:

    virtual Future<Image> toImage(int width, int height);

    virtual void dispose();

    virtual bool debugDisposed();

    virtual int approximateBytesUsed();
private:
    bool _disposed;


    virtual void  _();
    virtual String _toImage(int width, int height, _Callback<_Image> callback);
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
    virtual void _init(Uint8List list, _Callback<void> callback);
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
    virtual void _initRaw(ImageDescriptor outDescriptor, ImmutableBuffer buffer, int width, int height, int rowBytes, int pixelFormat);
    virtual int _getWidth();
    virtual int _getHeight();
    virtual int _getBytesPerPixel();
    virtual void _instantiateCodec(Codec outCodec, int targetWidth, int targetHeight);
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