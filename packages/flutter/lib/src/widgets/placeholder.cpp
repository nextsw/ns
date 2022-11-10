#include "placeholder.hpp"
void _PlaceholderPainterCls::paint(Canvas canvas, Size size) {
    auto _c1 = make<PaintCls>();_c1.color = auto _c2 = color;_c2.style = auto _c3 = PaintingStyleCls::stroke;_c3.strokeWidth = strokeWidth;_c3;_c2;Paint paint = _c1;
    Rect rect = OffsetCls::zero & size;
    auto _c4 = make<PathCls>();_c4.auto _c5 = addRect(rect);_c5.auto _c6 = addPolygon(makeList(ArrayItem, ArrayItem), false);_c6.addPolygon(makeList(ArrayItem, ArrayItem), false);_c6;_c5;Path path = _c4;
    canvas->drawPath(path, paint);
}

bool _PlaceholderPainterCls::shouldRepaint(_PlaceholderPainter oldPainter) {
    return oldPainter->color != color || oldPainter->strokeWidth != strokeWidth;
}

bool _PlaceholderPainterCls::hitTest(Offset position) {
    return false;
}

Widget PlaceholderCls::build(BuildContext context) {
    return make<LimitedBoxCls>(fallbackWidth, fallbackHeight, make<CustomPaintCls>(SizeCls::infinite, make<_PlaceholderPainterCls>(color, strokeWidth), child));
}

void PlaceholderCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<ColorPropertyCls>(__s("color"), colormake<ColorCls>(0xFF455A64)));
    properties->add(make<DoublePropertyCls>(__s("strokeWidth"), strokeWidth2.0));
    properties->add(make<DoublePropertyCls>(__s("fallbackWidth"), fallbackWidth400.0));
    properties->add(make<DoublePropertyCls>(__s("fallbackHeight"), fallbackHeight400.0));
    properties->add(<Widget>make<DiagnosticsPropertyCls>(__s("child"), childnullptr));
}
