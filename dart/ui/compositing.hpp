#ifndef DART_UI_COMPOSITING
#define DART_UI_COMPOSITING
#include <base.hpp>

#include <dart/core/core.hpp>


class SceneCls : public NativeFieldWrapperClass1Cls {
public:

    virtual Future<Image> toImage(int height, int width);

    virtual void dispose();
private:

    virtual void  _();
    virtual String _toImage(_Callback<_Image> callback, int height, int width);
};
using Scene = std::shared_ptr<SceneCls>;

class _EngineLayerWrapperCls : public ObjectCls {
public:

    virtual void dispose();

private:
    EngineLayer _nativeLayer;

    List<_EngineLayerWrapper> _debugChildren;

    bool _debugWasUsedAsOldLayer;


    virtual void  _(EngineLayer nativeLayer);

    virtual bool _debugCheckNotUsedAsOldLayer();

};
using _EngineLayerWrapper = std::shared_ptr<_EngineLayerWrapperCls>;

class TransformEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using TransformEngineLayer = std::shared_ptr<TransformEngineLayerCls>;

class OffsetEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using OffsetEngineLayer = std::shared_ptr<OffsetEngineLayerCls>;

class ClipRectEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using ClipRectEngineLayer = std::shared_ptr<ClipRectEngineLayerCls>;

class ClipRRectEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using ClipRRectEngineLayer = std::shared_ptr<ClipRRectEngineLayerCls>;

class ClipPathEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using ClipPathEngineLayer = std::shared_ptr<ClipPathEngineLayerCls>;

class OpacityEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using OpacityEngineLayer = std::shared_ptr<OpacityEngineLayerCls>;

class ColorFilterEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using ColorFilterEngineLayer = std::shared_ptr<ColorFilterEngineLayerCls>;

class ImageFilterEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using ImageFilterEngineLayer = std::shared_ptr<ImageFilterEngineLayerCls>;

class BackdropFilterEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using BackdropFilterEngineLayer = std::shared_ptr<BackdropFilterEngineLayerCls>;

class ShaderMaskEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using ShaderMaskEngineLayer = std::shared_ptr<ShaderMaskEngineLayerCls>;

class PhysicalShapeEngineLayerCls : public _EngineLayerWrapperCls {
public:

private:

    virtual void  _(EngineLayer nativeLayer);

};
using PhysicalShapeEngineLayer = std::shared_ptr<PhysicalShapeEngineLayerCls>;

class SceneBuilderCls : public NativeFieldWrapperClass1Cls {
public:

     SceneBuilderCls();

    virtual TransformEngineLayer pushTransform(Float64List matrix4, TransformEngineLayer oldLayer);

    virtual OffsetEngineLayer pushOffset(double dx, double dy, OffsetEngineLayer oldLayer);

    virtual ClipRectEngineLayer pushClipRect(Clip clipBehavior, ClipRectEngineLayer oldLayer, Rect rect);

    virtual ClipRRectEngineLayer pushClipRRect(Clip clipBehavior, ClipRRectEngineLayer oldLayer, RRect rrect);

    virtual ClipPathEngineLayer pushClipPath(Clip clipBehavior, ClipPathEngineLayer oldLayer, Path path);

    virtual OpacityEngineLayer pushOpacity(int alpha, Offset offset, OpacityEngineLayer oldLayer);

    virtual ColorFilterEngineLayer pushColorFilter(ColorFilter filter, ColorFilterEngineLayer oldLayer);

    virtual ImageFilterEngineLayer pushImageFilter(ImageFilter filter, ImageFilterEngineLayer oldLayer);

    virtual BackdropFilterEngineLayer pushBackdropFilter(BlendMode blendMode, ImageFilter filter, BackdropFilterEngineLayer oldLayer);

    virtual ShaderMaskEngineLayer pushShaderMask(BlendMode blendMode, FilterQuality filterQuality, Rect maskRect, ShaderMaskEngineLayer oldLayer, Shader shader);

    virtual PhysicalShapeEngineLayer pushPhysicalShape(Clip clipBehavior, Color color, double elevation, PhysicalShapeEngineLayer oldLayer, Path path, Color shadowColor);

    virtual void pop();

    virtual void addRetained(EngineLayer retainedLayer);

    virtual void addPerformanceOverlay(Rect bounds, int enabledOptions);

    virtual void addPicture(bool isComplexHint, Offset offset, Picture picture, bool willChangeHint);

    virtual void addTexture(FilterQuality filterQuality, bool freeze, double height, Offset offset, int textureId, double width);

    virtual void addPlatformView(double height, Offset offset, int viewId, double width);

    virtual void setRasterizerTracingThreshold(int frameInterval);
    virtual void setCheckerboardRasterCacheImages(bool checkerboard);
    virtual void setCheckerboardOffscreenLayers(bool checkerboard);
    virtual Scene build();

private:
    Map<EngineLayer, String> _usedLayers;

    List<_EngineLayerWrapper> _layerStack;


    virtual void _constructor();
    virtual bool _debugCheckUsedOnce(EngineLayer layer, String usage);

    virtual bool _debugCheckCanBeUsedAsOldLayer(_EngineLayerWrapper layer, String methodName);

    virtual bool _debugPushLayer(_EngineLayerWrapper newLayer);

    virtual void _pushTransform(EngineLayer layer, Float64List matrix4, EngineLayer oldLayer);
    virtual void _pushOffset(double dx, double dy, EngineLayer layer, EngineLayer oldLayer);
    virtual void _pushClipRect(double bottom, int clipBehavior, double left, EngineLayer oldLayer, EngineLayer outEngineLayer, double right, double top);
    virtual void _pushClipRRect(int clipBehavior, EngineLayer layer, EngineLayer oldLayer, Float32List rrect);
    virtual void _pushClipPath(int clipBehavior, EngineLayer layer, EngineLayer oldLayer, Path path);
    virtual void _pushOpacity(int alpha, double dx, double dy, EngineLayer layer, EngineLayer oldLayer);
    virtual void _pushColorFilter(_ColorFilter filter, EngineLayer layer, EngineLayer oldLayer);
    virtual void _pushImageFilter(_ImageFilter filter, EngineLayer oldLayer, EngineLayer outEngineLayer);
    virtual void _pushBackdropFilter(int blendMode, _ImageFilter filter, EngineLayer oldLayer, EngineLayer outEngineLayer);
    virtual void _pushShaderMask(int blendMode, EngineLayer engineLayer, int filterQualityIndex, double maskRectBottom, double maskRectLeft, double maskRectRight, double maskRectTop, EngineLayer oldLayer, Shader shader);
    virtual void _pushPhysicalShape(int clipBehavior, int color, double elevation, EngineLayer oldLayer, EngineLayer outEngineLayer, Path path, int shadowColor);
    virtual void _pop();
    virtual void _addRetained(EngineLayer retainedLayer);
    virtual void _addPerformanceOverlay(double bottom, int enabledOptions, double left, double right, double top);
    virtual void _addPicture(double dx, double dy, int hints, Picture picture);
    virtual void _addTexture(double dx, double dy, int filterQuality, bool freeze, double height, int textureId, double width);
    virtual void _addPlatformView(double dx, double dy, double height, int viewId, double width);
    virtual void _build(Scene outScene);
};
using SceneBuilder = std::shared_ptr<SceneBuilderCls>;


#endif