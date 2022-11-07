#include "image_filter.hpp"
ImageFiltered::ImageFiltered(Unknown, bool enabled, ImageFilter imageFilter, Unknown) {
    {
        assert(imageFilter != nullptr);
    }
}

RenderObject ImageFiltered::createRenderObject(BuildContext context) {
    return _ImageFilterRenderObject(imageFilter, enabled);
}

void ImageFiltered::updateRenderObject(BuildContext context, RenderObject renderObject) {
    ;
}

void ImageFiltered::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ImageFilter>DiagnosticsProperty("imageFilter", imageFilter));
}

bool _ImageFilterRenderObject::enabled() {
    return _enabled;
}

void _ImageFilterRenderObject::enabled(bool value) {
    if (enabled == value) {
        return;
    }
    _enabled = value;
    markNeedsPaint();
}

ImageFilter _ImageFilterRenderObject::imageFilter() {
    return _imageFilter;
}

void _ImageFilterRenderObject::imageFilter(ImageFilter value) {
    assert(value != nullptr);
    if (value != _imageFilter) {
        _imageFilter = value;
        markNeedsPaint();
    }
}

bool _ImageFilterRenderObject::alwaysNeedsCompositing() {
    return child != nullptr && enabled;
}

void _ImageFilterRenderObject::paint(PaintingContext context, Offset offset) {
    assert(imageFilter != nullptr);
    if (!enabled) {
        layer = nullptr;
        return super.paint(context, offset);
    }
    if (layer == nullptr) {
        layer = ImageFilterLayer(imageFilter);
    } else {
        ImageFilterLayer filterLayer = (;
        filterLayer.imageFilter = imageFilter;
    }
    context.pushLayer(layer!, super.paint, offset);
    assert(());
}
