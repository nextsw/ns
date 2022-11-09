#include "image_filter.hpp"
ImageFilteredCls::ImageFilteredCls(Unknown child, bool enabled, ImageFilter imageFilter, Unknown key) {
    {
        assert(imageFilter != nullptr);
    }
}

RenderObject ImageFilteredCls::createRenderObject(BuildContext context) {
    return make<_ImageFilterRenderObjectCls>(imageFilter, enabled);
}

void ImageFilteredCls::updateRenderObject(BuildContext context, RenderObject renderObject) {
    auto _c1 = (((_ImageFilterRenderObject)renderObject));_c1.enabled = auto _c2 = enabled;_c2.imageFilter = imageFilter;_c2;_c1;
}

void ImageFilteredCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ImageFilter>make<DiagnosticsPropertyCls>("imageFilter", imageFilter));
}

bool _ImageFilterRenderObjectCls::enabled() {
    return _enabled;
}

void _ImageFilterRenderObjectCls::enabled(bool value) {
    if (enabled == value) {
        return;
    }
    _enabled = value;
    markNeedsPaint();
}

ImageFilter _ImageFilterRenderObjectCls::imageFilter() {
    return _imageFilter;
}

void _ImageFilterRenderObjectCls::imageFilter(ImageFilter value) {
    assert(value != nullptr);
    if (value != _imageFilter) {
        _imageFilter = value;
        markNeedsPaint();
    }
}

bool _ImageFilterRenderObjectCls::alwaysNeedsCompositing() {
    return child != nullptr && enabled;
}

void _ImageFilterRenderObjectCls::paint(PaintingContext context, Offset offset) {
    assert(imageFilter != nullptr);
    if (!enabled) {
        layer = nullptr;
        return super->paint(context, offset);
    }
    if (layer == nullptr) {
        layer = make<ImageFilterLayerCls>(imageFilter);
    } else {
        ImageFilterLayer filterLayer = ((ImageFilterLayer)layer!);
        filterLayer->imageFilter = imageFilter;
    }
    context->pushLayer(layer!, super->paint, offset);
    assert([=] () {
        layer!->debugCreator = debugCreator;
        return true;
    }());
}
