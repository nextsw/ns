#ifndef DART_UI_COMPOSITING
#define DART_UI_COMPOSITING
#include <base.hpp>

#include <dart/core/core.hpp>


class SceneCls : public NativeFieldWrapperClass1Cls {
public:

    virtual Future<Image> toImage(int width, int height);

    virtual void dispose();
private:

    virtual void  _();
    virtual String _toImage(int width, int height, _Callback<_Image> callback);
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

    virtual ClipRectEngineLayer pushClipRect(Rect rect, Clip clipBehavior, ClipRectEngineLayer oldLayer);

    virtual ClipRRectEngineLayer pushClipRRect(RRect rrect, Clip clipBehavior, ClipRRectEngineLayer oldLayer);

    virtual ClipPathEngineLayer pushClipPath(Path path, Clip clipBehavior, ClipPathEngineLayer oldLayer);

    virtual OpacityEngineLayer pushOpacity(int alpha, Offset offset, OpacityEngineLayer oldLayer);

    virtual ColorFilterEngineLayer pushColorFilter(ColorFilter filter, ColorFilterEngineLayer oldLayer);

    virtual ImageFilterEngineLayer pushImageFilter(ImageFilter filter, ImageFilterEngineLayer oldLayer);

    virtual BackdropFilterEngineLayer pushBackdropFilter(ImageFilter filter, BlendMode blendMode, BackdropFilterEngineLayer oldLayer);

    virtual ShaderMaskEngineLayer pushShaderMask(Shader shader, Rect maskRect, BlendMode blendMode, FilterQuality filterQuality, ShaderMaskEngineLayer oldLayer);

    virtual PhysicalShapeEngineLayer pushPhysicalShape(Clip clipBehavior, Color color, double elevation, PhysicalShapeEngineLayer oldLayer, Path path, Color shadowColor);

    virtual void pop();

    virtual void addRetained(EngineLayer retainedLayer);

    virtual void addPerformanceOverlay(int enabledOptions, Rect bounds);

    virtual void addPicture(Offset offset, Picture picture, bool isComplexHint, bool willChangeHint);

    virtual void addTexture(int textureId, FilterQuality filterQuality, bool freeze, double height, Offset offset, double width);

    virtual void addPlatformView(int viewId, double height, Offset offset, double width);

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
    virtual void _pushOffset(EngineLayer layer, double dx, double dy, EngineLayer oldLayer);
    virtual void _pushClipRect(EngineLayer outEngineLayer, double left, double right, double top, double bottom, int clipBehavior, EngineLayer oldLayer);
    virtual void _pushClipRRect(EngineLayer layer, Float32List rrect, int clipBehavior, EngineLayer oldLayer);
    virtual void _pushClipPath(EngineLayer layer, Path path, int clipBehavior, EngineLayer oldLayer);
    virtual void _pushOpacity(EngineLayer layer, int alpha, double dx, double dy, EngineLayer oldLayer);
    virtual void _pushColorFilter(EngineLayer layer, _ColorFilter filter, EngineLayer oldLayer);
    virtual void _pushImageFilter(EngineLayer outEngineLayer, _ImageFilter filter, EngineLayer oldLayer);
    virtual void _pushBackdropFilter(EngineLayer outEngineLayer, _ImageFilter filter, int blendMode, EngineLayer oldLayer);
    virtual void _pushShaderMask(EngineLayer engineLayer, Shader shader, double maskRectLeft, double maskRectRight, double maskRectTop, double maskRectBottom, int blendMode, int filterQualityIndex, EngineLayer oldLayer);
    virtual void _pushPhysicalShape(EngineLayer outEngineLayer, Path path, double elevation, int color, int shadowColor, int clipBehavior, EngineLayer oldLayer);
    virtual void _pop();
    virtual void _addRetained(EngineLayer retainedLayer);
    virtual void _addPerformanceOverlay(int enabledOptions, double left, double right, double top, double bottom);
    virtual void _addPicture(double dx, double dy, Picture picture, int hints);
    virtual void _addTexture(double dx, double dy, double width, double height, int textureId, bool freeze, int filterQuality);
    virtual void _addPlatformView(double dx, double dy, double width, double height, int viewId);
    virtual void _build(Scene outScene);
};
using SceneBuilder = std::shared_ptr<SceneBuilderCls>;


#endif