#ifndef COMPOSITING_H
#define COMPOSITING_H
#include <memory>




class Scene : NativeFieldWrapperClass1 {
public:

    Future<Image> toImage(int height, int width);

    void dispose();

private:

    void  _();

    String _toImage(_Callback<_Image> callback, int height, int width);

};

class _EngineLayerWrapper {
public:

    void dispose();

private:
    EngineLayer _nativeLayer;

    List<_EngineLayerWrapper> _debugChildren;

    bool _debugWasUsedAsOldLayer;


    void  _(EngineLayer nativeLayer);

    bool _debugCheckNotUsedAsOldLayer();

};

class TransformEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class OffsetEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class ClipRectEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class ClipRRectEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class ClipPathEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class OpacityEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class ColorFilterEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class ImageFilterEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class BackdropFilterEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class ShaderMaskEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class PhysicalShapeEngineLayer : _EngineLayerWrapper {
public:

private:

    void  _(EngineLayer nativeLayer);

};

class SceneBuilder : NativeFieldWrapperClass1 {
public:

     SceneBuilder();

    TransformEngineLayer pushTransform(Float64List matrix4, TransformEngineLayer oldLayer);

    OffsetEngineLayer pushOffset(double dx, double dy, OffsetEngineLayer oldLayer);

    ClipRectEngineLayer pushClipRect(Clip clipBehavior, ClipRectEngineLayer oldLayer, Rect rect);

    ClipRRectEngineLayer pushClipRRect(Clip clipBehavior, ClipRRectEngineLayer oldLayer, RRect rrect);

    ClipPathEngineLayer pushClipPath(Clip clipBehavior, ClipPathEngineLayer oldLayer, Path path);

    OpacityEngineLayer pushOpacity(int alpha, Offset offset, OpacityEngineLayer oldLayer);

    ColorFilterEngineLayer pushColorFilter(ColorFilter filter, ColorFilterEngineLayer oldLayer);

    ImageFilterEngineLayer pushImageFilter(ImageFilter filter, ImageFilterEngineLayer oldLayer);

    BackdropFilterEngineLayer pushBackdropFilter(BlendMode blendMode, ImageFilter filter, BackdropFilterEngineLayer oldLayer);

    ShaderMaskEngineLayer pushShaderMask(BlendMode blendMode, FilterQuality filterQuality, Rect maskRect, ShaderMaskEngineLayer oldLayer, Shader shader);

    PhysicalShapeEngineLayer pushPhysicalShape(Clip clipBehavior, Color color, double elevation, PhysicalShapeEngineLayer oldLayer, Path path, Color shadowColor);

    void pop();

    void addRetained(EngineLayer retainedLayer);

    void addPerformanceOverlay(Rect bounds, int enabledOptions);

    void addPicture(bool isComplexHint, Offset offset, Picture picture, bool willChangeHint);

    void addTexture(FilterQuality filterQuality, bool freeze, double height, Offset offset, int textureId, double width);

    void addPlatformView(double height, Offset offset, int viewId, double width);

    void setRasterizerTracingThreshold(int frameInterval);

    void setCheckerboardRasterCacheImages(bool checkerboard);

    void setCheckerboardOffscreenLayers(bool checkerboard);

    Scene build();

private:
    Map<EngineLayer, String> _usedLayers;

    List<_EngineLayerWrapper> _layerStack;


    void _constructor();

    bool _debugCheckUsedOnce(EngineLayer layer, String usage);

    bool _debugCheckCanBeUsedAsOldLayer(_EngineLayerWrapper layer, String methodName);

    bool _debugPushLayer(_EngineLayerWrapper newLayer);

    void _pushTransform(EngineLayer layer, Float64List matrix4, EngineLayer oldLayer);

    void _pushOffset(double dx, double dy, EngineLayer layer, EngineLayer oldLayer);

    void _pushClipRect(double bottom, int clipBehavior, double left, EngineLayer oldLayer, EngineLayer outEngineLayer, double right, double top);

    void _pushClipRRect(int clipBehavior, EngineLayer layer, EngineLayer oldLayer, Float32List rrect);

    void _pushClipPath(int clipBehavior, EngineLayer layer, EngineLayer oldLayer, Path path);

    void _pushOpacity(int alpha, double dx, double dy, EngineLayer layer, EngineLayer oldLayer);

    void _pushColorFilter(_ColorFilter filter, EngineLayer layer, EngineLayer oldLayer);

    void _pushImageFilter(_ImageFilter filter, EngineLayer oldLayer, EngineLayer outEngineLayer);

    void _pushBackdropFilter(int blendMode, _ImageFilter filter, EngineLayer oldLayer, EngineLayer outEngineLayer);

    void _pushShaderMask(int blendMode, EngineLayer engineLayer, int filterQualityIndex, double maskRectBottom, double maskRectLeft, double maskRectRight, double maskRectTop, EngineLayer oldLayer, Shader shader);

    void _pushPhysicalShape(int clipBehavior, int color, double elevation, EngineLayer oldLayer, EngineLayer outEngineLayer, Path path, int shadowColor);

    void _pop();

    void _addRetained(EngineLayer retainedLayer);

    void _addPerformanceOverlay(double bottom, int enabledOptions, double left, double right, double top);

    void _addPicture(double dx, double dy, int hints, Picture picture);

    void _addTexture(double dx, double dy, int filterQuality, bool freeze, double height, int textureId, double width);

    void _addPlatformView(double dx, double dy, double height, int viewId, double width);

    void _build(Scene outScene);

};

#endif