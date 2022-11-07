#include "compositing.hpp"
Future<Image> Scene::toImage(int height, int width) {
    if (width <= 0 || height <= 0) {
        ;
    }
    return _futurize();
}

void _EngineLayerWrapper::dispose() {
    assert(_nativeLayer != nullptr, "Object disposed");
    _nativeLayer!.dispose();
    assert(());
}

void _EngineLayerWrapper::_(EngineLayer nativeLayer)

bool _EngineLayerWrapper::_debugCheckNotUsedAsOldLayer() {
    assert(!_debugWasUsedAsOldLayer, "Layer $runtimeType was previously used as oldLayer.\nOnce a layer is used as oldLayer, it may not be used again. Instead, after calling one of the SceneBuilder.push* methods and passing an oldLayer to it, use the layer returned by the method as oldLayer in subsequent frames.");
    return true;
}

void TransformEngineLayer::_(EngineLayer nativeLayer)

void OffsetEngineLayer::_(EngineLayer nativeLayer)

void ClipRectEngineLayer::_(EngineLayer nativeLayer)

void ClipRRectEngineLayer::_(EngineLayer nativeLayer)

void ClipPathEngineLayer::_(EngineLayer nativeLayer)

void OpacityEngineLayer::_(EngineLayer nativeLayer)

void ColorFilterEngineLayer::_(EngineLayer nativeLayer)

void ImageFilterEngineLayer::_(EngineLayer nativeLayer)

void BackdropFilterEngineLayer::_(EngineLayer nativeLayer)

void ShaderMaskEngineLayer::_(EngineLayer nativeLayer)

void PhysicalShapeEngineLayer::_(EngineLayer nativeLayer)

SceneBuilder::SceneBuilder() {
    {
        _constructor();
    }
}

TransformEngineLayer SceneBuilder::pushTransform(Float64List matrix4, TransformEngineLayer oldLayer) {
    assert(_matrix4IsValid(matrix4));
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushTransform"));
    EngineLayer engineLayer = EngineLayer._();
    _pushTransform(engineLayer, matrix4, oldLayer?._nativeLayer);
    TransformEngineLayer layer = TransformEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

OffsetEngineLayer SceneBuilder::pushOffset(double dx, double dy, OffsetEngineLayer oldLayer) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushOffset"));
    EngineLayer engineLayer = EngineLayer._();
    _pushOffset(engineLayer, dx, dy, oldLayer?._nativeLayer);
    OffsetEngineLayer layer = OffsetEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ClipRectEngineLayer SceneBuilder::pushClipRect(Clip clipBehavior, ClipRectEngineLayer oldLayer, Rect rect) {
    assert(clipBehavior != nullptr);
    assert(clipBehavior != Clip.none);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushClipRect"));
    EngineLayer engineLayer = EngineLayer._();
    _pushClipRect(engineLayer, rect.left, rect.right, rect.top, rect.bottom, clipBehavior.index, oldLayer?._nativeLayer);
    ClipRectEngineLayer layer = ClipRectEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ClipRRectEngineLayer SceneBuilder::pushClipRRect(Clip clipBehavior, ClipRRectEngineLayer oldLayer, RRect rrect) {
    assert(clipBehavior != nullptr);
    assert(clipBehavior != Clip.none);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushClipRRect"));
    EngineLayer engineLayer = EngineLayer._();
    _pushClipRRect(engineLayer, rrect._getValue32(), clipBehavior.index, oldLayer?._nativeLayer);
    ClipRRectEngineLayer layer = ClipRRectEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ClipPathEngineLayer SceneBuilder::pushClipPath(Clip clipBehavior, ClipPathEngineLayer oldLayer, Path path) {
    assert(clipBehavior != nullptr);
    assert(clipBehavior != Clip.none);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushClipPath"));
    EngineLayer engineLayer = EngineLayer._();
    _pushClipPath(engineLayer, path, clipBehavior.index, oldLayer?._nativeLayer);
    ClipPathEngineLayer layer = ClipPathEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

OpacityEngineLayer SceneBuilder::pushOpacity(int alpha, Offset offset, OpacityEngineLayer oldLayer) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushOpacity"));
    EngineLayer engineLayer = EngineLayer._();
    _pushOpacity(engineLayer, alpha, offset!.dx, offset.dy, oldLayer?._nativeLayer);
    OpacityEngineLayer layer = OpacityEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ColorFilterEngineLayer SceneBuilder::pushColorFilter(ColorFilter filter, ColorFilterEngineLayer oldLayer) {
    assert(filter != nullptr);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushColorFilter"));
    _ColorFilter nativeFilter = filter._toNativeColorFilter()!;
    assert(nativeFilter != nullptr);
    EngineLayer engineLayer = EngineLayer._();
    _pushColorFilter(engineLayer, nativeFilter, oldLayer?._nativeLayer);
    ColorFilterEngineLayer layer = ColorFilterEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ImageFilterEngineLayer SceneBuilder::pushImageFilter(ImageFilter filter, ImageFilterEngineLayer oldLayer) {
    assert(filter != nullptr);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushImageFilter"));
    _ImageFilter nativeFilter = filter._toNativeImageFilter();
    assert(nativeFilter != nullptr);
    EngineLayer engineLayer = EngineLayer._();
    _pushImageFilter(engineLayer, nativeFilter, oldLayer?._nativeLayer);
    ImageFilterEngineLayer layer = ImageFilterEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

BackdropFilterEngineLayer SceneBuilder::pushBackdropFilter(BlendMode blendMode, ImageFilter filter, BackdropFilterEngineLayer oldLayer) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushBackdropFilter"));
    EngineLayer engineLayer = EngineLayer._();
    _pushBackdropFilter(engineLayer, filter._toNativeImageFilter(), blendMode.index, oldLayer?._nativeLayer);
    BackdropFilterEngineLayer layer = BackdropFilterEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ShaderMaskEngineLayer SceneBuilder::pushShaderMask(BlendMode blendMode, FilterQuality filterQuality, Rect maskRect, ShaderMaskEngineLayer oldLayer, Shader shader) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushShaderMask"));
    EngineLayer engineLayer = EngineLayer._();
    _pushShaderMask(engineLayer, shader, maskRect.left, maskRect.right, maskRect.top, maskRect.bottom, blendMode.index, filterQuality.index, oldLayer?._nativeLayer);
    ShaderMaskEngineLayer layer = ShaderMaskEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

PhysicalShapeEngineLayer SceneBuilder::pushPhysicalShape(Clip clipBehavior, Color color, double elevation, PhysicalShapeEngineLayer oldLayer, Path path, Color shadowColor) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, "pushPhysicalShape"));
    EngineLayer engineLayer = EngineLayer._();
    _pushPhysicalShape(engineLayer, path, elevation, color.value, shadowColor?.value ?? 0xFF000000, clipBehavior.index, oldLayer?._nativeLayer);
    PhysicalShapeEngineLayer layer = PhysicalShapeEngineLayer._(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

void SceneBuilder::pop() {
    if (_layerStack.isNotEmpty) {
        _layerStack.removeLast();
    }
    _pop();
}

void SceneBuilder::addRetained(EngineLayer retainedLayer) {
    assert(retainedLayer is _EngineLayerWrapper);
    assert(());
    _EngineLayerWrapper wrapper = (;
    _addRetained(wrapper._nativeLayer!);
}

void SceneBuilder::addPerformanceOverlay(Rect bounds, int enabledOptions) {
    _addPerformanceOverlay(enabledOptions, bounds.left, bounds.right, bounds.top, bounds.bottom);
}

void SceneBuilder::addPicture(bool isComplexHint, Offset offset, Picture picture, bool willChangeHint) {
    assert(!picture.debugDisposed);
    int hints = (isComplexHint? 1 : 0) | (willChangeHint? 2 : 0);
    _addPicture(offset.dx, offset.dy, picture, hints);
}

void SceneBuilder::addTexture(FilterQuality filterQuality, bool freeze, double height, Offset offset, int textureId, double width) {
    assert(offset != nullptr, "Offset argument was null");
    _addTexture(offset.dx, offset.dy, width, height, textureId, freeze, filterQuality.index);
}

void SceneBuilder::addPlatformView(double height, Offset offset, int viewId, double width) {
    assert(offset != nullptr, "Offset argument was null");
    _addPlatformView(offset.dx, offset.dy, width, height, viewId);
}

Scene SceneBuilder::build() {
    Scene scene = Scene._();
    _build(scene);
    return scene;
}

bool SceneBuilder::_debugCheckUsedOnce(EngineLayer layer, String usage) {
    assert(());
    return true;
}

bool SceneBuilder::_debugCheckCanBeUsedAsOldLayer(_EngineLayerWrapper layer, String methodName) {
    assert(());
    return true;
}

bool SceneBuilder::_debugPushLayer(_EngineLayerWrapper newLayer) {
    assert(());
    return true;
}
