#include "compositing.hpp"
Future<Image> SceneCls::toImage(int width, int height) {
    if (width <= 0 || height <= 0) {
        throw make<ExceptionCls>(__s("Invalid image dimensions."));
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

void _EngineLayerWrapperCls::dispose() {
    assert(_nativeLayer != nullptr, __s("Object disposed"));
    _nativeLayer!->dispose();
    assert([=] () {
        _nativeLayer = nullptr;
        return true;
    }());
}

void _EngineLayerWrapperCls::_(EngineLayer nativeLayer)

bool _EngineLayerWrapperCls::_debugCheckNotUsedAsOldLayer() {
    assert(!_debugWasUsedAsOldLayer, __s("Layer $runtimeType was previously used as oldLayer.\nOnce a layer is used as oldLayer, it may not be used again. Instead, after calling one of the SceneBuilder.push* methods and passing an oldLayer to it, use the layer returned by the method as oldLayer in subsequent frames."));
    return true;
}

void TransformEngineLayerCls::_(EngineLayer nativeLayer)

void OffsetEngineLayerCls::_(EngineLayer nativeLayer)

void ClipRectEngineLayerCls::_(EngineLayer nativeLayer)

void ClipRRectEngineLayerCls::_(EngineLayer nativeLayer)

void ClipPathEngineLayerCls::_(EngineLayer nativeLayer)

void OpacityEngineLayerCls::_(EngineLayer nativeLayer)

void ColorFilterEngineLayerCls::_(EngineLayer nativeLayer)

void ImageFilterEngineLayerCls::_(EngineLayer nativeLayer)

void BackdropFilterEngineLayerCls::_(EngineLayer nativeLayer)

void ShaderMaskEngineLayerCls::_(EngineLayer nativeLayer)

void PhysicalShapeEngineLayerCls::_(EngineLayer nativeLayer)

SceneBuilderCls::SceneBuilderCls() {
    {
        _constructor();
    }
}

TransformEngineLayer SceneBuilderCls::pushTransform(Float64List matrix4, TransformEngineLayer oldLayer) {
    assert(_matrix4IsValid(matrix4));
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushTransform")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushTransform(engineLayer, matrix4, oldLayer?->_nativeLayer);
    TransformEngineLayer layer = TransformEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

OffsetEngineLayer SceneBuilderCls::pushOffset(double dx, double dy, OffsetEngineLayer oldLayer) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushOffset")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushOffset(engineLayer, dx, dy, oldLayer?->_nativeLayer);
    OffsetEngineLayer layer = OffsetEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ClipRectEngineLayer SceneBuilderCls::pushClipRect(Rect rect, Clip clipBehavior, ClipRectEngineLayer oldLayer) {
    assert(clipBehavior != nullptr);
    assert(clipBehavior != ClipCls::none);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushClipRect")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushClipRect(engineLayer, rect->left, rect->right, rect->top, rect->bottom, clipBehavior->index, oldLayer?->_nativeLayer);
    ClipRectEngineLayer layer = ClipRectEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ClipRRectEngineLayer SceneBuilderCls::pushClipRRect(RRect rrect, Clip clipBehavior, ClipRRectEngineLayer oldLayer) {
    assert(clipBehavior != nullptr);
    assert(clipBehavior != ClipCls::none);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushClipRRect")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushClipRRect(engineLayer, rrect->_getValue32(), clipBehavior->index, oldLayer?->_nativeLayer);
    ClipRRectEngineLayer layer = ClipRRectEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ClipPathEngineLayer SceneBuilderCls::pushClipPath(Path path, Clip clipBehavior, ClipPathEngineLayer oldLayer) {
    assert(clipBehavior != nullptr);
    assert(clipBehavior != ClipCls::none);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushClipPath")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushClipPath(engineLayer, path, clipBehavior->index, oldLayer?->_nativeLayer);
    ClipPathEngineLayer layer = ClipPathEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

OpacityEngineLayer SceneBuilderCls::pushOpacity(int alpha, Offset offset, OpacityEngineLayer oldLayer) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushOpacity")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushOpacity(engineLayer, alpha, offset!->dx(), offset->dy(), oldLayer?->_nativeLayer);
    OpacityEngineLayer layer = OpacityEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ColorFilterEngineLayer SceneBuilderCls::pushColorFilter(ColorFilter filter, ColorFilterEngineLayer oldLayer) {
    assert(filter != nullptr);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushColorFilter")));
    _ColorFilter nativeFilter = filter->_toNativeColorFilter()!;
    assert(nativeFilter != nullptr);
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushColorFilter(engineLayer, nativeFilter, oldLayer?->_nativeLayer);
    ColorFilterEngineLayer layer = ColorFilterEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ImageFilterEngineLayer SceneBuilderCls::pushImageFilter(ImageFilter filter, ImageFilterEngineLayer oldLayer) {
    assert(filter != nullptr);
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushImageFilter")));
    _ImageFilter nativeFilter = filter->_toNativeImageFilter();
    assert(nativeFilter != nullptr);
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushImageFilter(engineLayer, nativeFilter, oldLayer?->_nativeLayer);
    ImageFilterEngineLayer layer = ImageFilterEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

BackdropFilterEngineLayer SceneBuilderCls::pushBackdropFilter(ImageFilter filter, BlendMode blendMode, BackdropFilterEngineLayer oldLayer) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushBackdropFilter")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushBackdropFilter(engineLayer, filter->_toNativeImageFilter(), blendMode->index, oldLayer?->_nativeLayer);
    BackdropFilterEngineLayer layer = BackdropFilterEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

ShaderMaskEngineLayer SceneBuilderCls::pushShaderMask(Shader shader, Rect maskRect, BlendMode blendMode, FilterQuality filterQuality, ShaderMaskEngineLayer oldLayer) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushShaderMask")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushShaderMask(engineLayer, shader, maskRect->left, maskRect->right, maskRect->top, maskRect->bottom, blendMode->index, filterQuality->index, oldLayer?->_nativeLayer);
    ShaderMaskEngineLayer layer = ShaderMaskEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

PhysicalShapeEngineLayer SceneBuilderCls::pushPhysicalShape(Clip clipBehavior, Color color, double elevation, PhysicalShapeEngineLayer oldLayer, Path path, Color shadowColor) {
    assert(_debugCheckCanBeUsedAsOldLayer(oldLayer, __s("pushPhysicalShape")));
    EngineLayer engineLayer = EngineLayerCls->_();
    _pushPhysicalShape(engineLayer, path, elevation, color->value, shadowColor?->value | 0xFF000000, clipBehavior->index, oldLayer?->_nativeLayer);
    PhysicalShapeEngineLayer layer = PhysicalShapeEngineLayerCls->_(engineLayer);
    assert(_debugPushLayer(layer));
    return layer;
}

void SceneBuilderCls::pop() {
    if (_layerStack->isNotEmpty) {
        _layerStack->removeLast();
    }
    _pop();
}

void SceneBuilderCls::addRetained(EngineLayer retainedLayer) {
    assert(is<_EngineLayerWrapper>(retainedLayer));
    assert([=] () {
        _EngineLayerWrapper layer = as<_EngineLayerWrapper>(retainedLayer);
        assert(layer->_nativeLayer != nullptr);
        InlineMethod;
        recursivelyCheckChildrenUsedOnce(layer);
        return true;
    }());
    _EngineLayerWrapper wrapper = as<_EngineLayerWrapper>(retainedLayer);
    _addRetained(wrapper->_nativeLayer!);
}

void SceneBuilderCls::addPerformanceOverlay(int enabledOptions, Rect bounds) {
    _addPerformanceOverlay(enabledOptions, bounds->left, bounds->right, bounds->top, bounds->bottom);
}

void SceneBuilderCls::addPicture(Offset offset, Picture picture, bool isComplexHint, bool willChangeHint) {
    assert(!picture->debugDisposed());
    int hints = (isComplexHint? 1 : 0) | (willChangeHint? 2 : 0);
    _addPicture(offset->dx(), offset->dy(), picture, hints);
}

void SceneBuilderCls::addTexture(int textureId, FilterQuality filterQuality, bool freeze, double height, Offset offset, double width) {
    assert(offset != nullptr, __s("Offset argument was null"));
    _addTexture(offset->dx(), offset->dy(), width, height, textureId, freeze, filterQuality->index);
}

void SceneBuilderCls::addPlatformView(int viewId, double height, Offset offset, double width) {
    assert(offset != nullptr, __s("Offset argument was null"));
    _addPlatformView(offset->dx(), offset->dy(), width, height, viewId);
}

Scene SceneBuilderCls::build() {
    Scene scene = SceneCls->_();
    _build(scene);
    return scene;
}

bool SceneBuilderCls::_debugCheckUsedOnce(EngineLayer layer, String usage) {
    assert([=] () {
        assert(!_usedLayers->containsKey(layer), __s("Layer ${layer.runtimeType} already used.\nThe layer is already being used as ${_usedLayers[layer]} in this scene.\nA layer may only be used once in a given scene."));
        _usedLayers[layer] = usage;
        return true;
    }());
    return true;
}

bool SceneBuilderCls::_debugCheckCanBeUsedAsOldLayer(_EngineLayerWrapper layer, String methodName) {
    assert([=] () {
        if (layer == nullptr) {
            return true;
        }
        assert(layer->_nativeLayer != nullptr, __s("Object disposed"));
        layer->_debugCheckNotUsedAsOldLayer();
        assert(_debugCheckUsedOnce(layer, __s("oldLayer in $methodName")));
        layer->_debugWasUsedAsOldLayer = true;
        return true;
    }());
    return true;
}

bool SceneBuilderCls::_debugPushLayer(_EngineLayerWrapper newLayer) {
    assert([=] () {
        if (_layerStack->isNotEmpty) {
            _EngineLayerWrapper currentLayer = _layerStack->last;
            currentLayer->_debugChildren |= makeList();
            currentLayer->_debugChildren!->add(newLayer);
        }
        _layerStack->add(newLayer);
        return true;
    }());
    return true;
}
