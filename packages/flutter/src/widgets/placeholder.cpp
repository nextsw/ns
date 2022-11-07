#include "placeholder.hpp"
void _PlaceholderPainter::paint(Canvas canvas, Size size) {
    Paint paint = ;
    Rect rect = Offset.zero & size;
    Path path = ;
    canvas.drawPath(path, paint);
}

bool _PlaceholderPainter::shouldRepaint(_PlaceholderPainter oldPainter) {
    return oldPainter.color != color || oldPainter.strokeWidth != strokeWidth;
}

bool _PlaceholderPainter::hitTest(Offset position) {
    return false;
}

Widget Placeholder::build(BuildContext context) {
    return LimitedBox(fallbackWidth, fallbackHeight, CustomPaint(Size.infinite, _PlaceholderPainter(color, strokeWidth), child));
}

void Placeholder::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(ColorProperty("color", colorconst Color(0xFF455A64)));
    properties.add(DoubleProperty("strokeWidth", strokeWidth2.0));
    properties.add(DoubleProperty("fallbackWidth", fallbackWidth400.0));
    properties.add(DoubleProperty("fallbackHeight", fallbackHeight400.0));
    properties.add(<Widget>DiagnosticsProperty("child", childnullptr));
}
