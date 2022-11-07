#include "banner.hpp"
BannerPainter::BannerPainter(Color color, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle) {
    {
        assert(message != nullptr);
        assert(textDirection != nullptr);
        assert(location != nullptr);
        assert(color != nullptr);
        assert(textStyle != nullptr);
        super(PaintingBinding.instance.systemFonts);
    }
}

void BannerPainter::paint(Canvas canvas, Size size) {
    if (!_prepared) {
        _prepare();
    }
    ;
    double width = _kOffset * 2.0;
    _textPainter.layout(width, width);
    _textPainter.paint(canvas, _kRect.topLeft + Offset(0.0, (_kRect.height - _textPainter.height) / 2.0));
}

bool BannerPainter::shouldRepaint(BannerPainter oldDelegate) {
    return message != oldDelegate.message || location != oldDelegate.location || color != oldDelegate.color || textStyle != oldDelegate.textStyle;
}

bool BannerPainter::hitTest(Offset position) {
    return false;
}

void BannerPainter::_prepare() {
    _paintShadow = _shadow.toPaint();
    _paintBanner = ;
    _textPainter = TextPainter(TextSpan(textStyle, message), TextAlign.center, textDirection);
    _prepared = true;
}

double BannerPainter::_translationX(double width) {
    assert(location != nullptr);
    assert(layoutDirection != nullptr);
    ;
}

double BannerPainter::_translationY(double height) {
    assert(location != nullptr);
    ;
}

double BannerPainter::_rotation() {
    assert(location != nullptr);
    assert(layoutDirection != nullptr);
    ;
}

Banner::Banner(Widget child, Color color, Unknown, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle) {
    {
        assert(message != nullptr);
        assert(location != nullptr);
        assert(color != nullptr);
        assert(textStyle != nullptr);
    }
}

Widget Banner::build(BuildContext context) {
    assert((textDirection != nullptr && layoutDirection != nullptr) || debugCheckHasDirectionality(context));
    return CustomPaint(BannerPainter(message, textDirection ?? Directionality.of(context), location, layoutDirection ?? Directionality.of(context), color, textStyle), child);
}

void Banner::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("message", messagefalse));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<BannerLocation>EnumProperty("location", location));
    properties.add(<TextDirection>EnumProperty("layoutDirection", layoutDirectionnullptr));
    properties.add(ColorProperty("color", colorfalse));
    textStyle.debugFillProperties(properties"text ");
}

Widget CheckedModeBanner::build(BuildContext context) {
    Widget result = child;
    assert(());
    return result;
}

void CheckedModeBanner::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    String message = "disabled";
    assert(());
    properties.add(DiagnosticsNode.message(message));
}
