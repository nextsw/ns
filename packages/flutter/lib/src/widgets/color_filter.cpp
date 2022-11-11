#include "color_filter.hpp"
ColorFilteredCls::ColorFilteredCls(Unknown child, ColorFilter colorFilter, Unknown key) {
    {
        assert(colorFilter != nullptr);
    }
}

RenderObject ColorFilteredCls::createRenderObject(BuildContext context) {
    return make<_ColorFilterRenderObjectCls>(colorFilter);
}

void ColorFilteredCls::updateRenderObject(BuildContext context, RenderObject renderObject) {
    (as<_ColorFilterRenderObject>(renderObject))->colorFilter = colorFilter;
}

void ColorFilteredCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ColorFilter>make<DiagnosticsPropertyCls>(__s("colorFilter"), colorFilter));
}

ColorFilter _ColorFilterRenderObjectCls::colorFilter() {
    return _colorFilter;
}

void _ColorFilterRenderObjectCls::colorFilter(ColorFilter value) {
    assert(value != nullptr);
    if (value != _colorFilter) {
        _colorFilter = value;
        markNeedsPaint();
    }
}

bool _ColorFilterRenderObjectCls::alwaysNeedsCompositing() {
    return child != nullptr;
}

void _ColorFilterRenderObjectCls::paint(PaintingContext context, Offset offset) {
    layer() = context->pushColorFilter(offset, colorFilter(), super->paint, as<ColorFilterLayer>(layer()));
    assert([=] () {
        layer()!->debugCreator = debugCreator;
        return true;
    }());
}
