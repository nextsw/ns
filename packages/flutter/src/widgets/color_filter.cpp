#include "color_filter.hpp"
ColorFiltered::ColorFiltered(Unknown, ColorFilter colorFilter, Unknown) {
    {
        assert(colorFilter != nullptr);
    }
}

RenderObject ColorFiltered::createRenderObject(BuildContext context) {
    return _ColorFilterRenderObject(colorFilter);
}

void ColorFiltered::updateRenderObject(BuildContext context, RenderObject renderObject) {
    (().colorFilter = colorFilter;
}

void ColorFiltered::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ColorFilter>DiagnosticsProperty("colorFilter", colorFilter));
}

ColorFilter _ColorFilterRenderObject::colorFilter() {
    return _colorFilter;
}

void _ColorFilterRenderObject::colorFilter(ColorFilter value) {
    assert(value != nullptr);
    if (value != _colorFilter) {
        _colorFilter = value;
        markNeedsPaint();
    }
}

bool _ColorFilterRenderObject::alwaysNeedsCompositing() {
    return child != nullptr;
}

void _ColorFilterRenderObject::paint(PaintingContext context, Offset offset) {
    layer = context.pushColorFilter(offset, colorFilter, super.paint();
    assert(());
}
