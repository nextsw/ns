#include "banner.hpp"
BannerPainterCls::BannerPainterCls(Color color, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle) : CustomPainter(PaintingBindingCls::instance->systemFonts) {
    {
        assert(message != nullptr);
        assert(textDirection != nullptr);
        assert(location != nullptr);
        assert(color != nullptr);
        assert(textStyle != nullptr);
    }
}

void BannerPainterCls::paint(Canvas canvas, Size size) {
    if (!_prepared) {
        _prepare();
    }
    auto _c1 = canvas;_c1.auto _c2 = translate(_translationX(size->width()), _translationY(size->height()));_c2.auto _c3 = rotate(_rotation());_c3.auto _c4 = drawRect(_kRect, _paintShadow);_c4.drawRect(_kRect, _paintBanner);_c4;_c3;_c2;_c1;
    double width = _kOffset * 2.0;
    _textPainter->layout(width, width);
    _textPainter->paint(canvas, _kRect->topLeft + make<OffsetCls>(0.0, (_kRect->height - _textPainter->height()) / 2.0));
}

bool BannerPainterCls::shouldRepaint(BannerPainter oldDelegate) {
    return message != oldDelegate->message || location != oldDelegate->location || color != oldDelegate->color || textStyle != oldDelegate->textStyle;
}

bool BannerPainterCls::hitTest(Offset position) {
    return false;
}

void BannerPainterCls::_prepare() {
    _paintShadow = _shadow->toPaint();
    auto _c1 = make<PaintCls>();_c1.color = color;_paintBanner = _c1;
    _textPainter = make<TextPainterCls>(make<TextSpanCls>(textStyle, message), TextAlignCls::center, textDirection);
    _prepared = true;
}

double BannerPainterCls::_translationX(double width) {
    assert(location != nullptr);
    assert(layoutDirection != nullptr);
    ;
}

double BannerPainterCls::_translationY(double height) {
    assert(location != nullptr);
    ;
}

double BannerPainterCls::_rotation() {
    assert(location != nullptr);
    assert(layoutDirection != nullptr);
    ;
}

BannerCls::BannerCls(Widget child, Color color, Unknown key, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle) {
    {
        assert(message != nullptr);
        assert(location != nullptr);
        assert(color != nullptr);
        assert(textStyle != nullptr);
    }
}

Widget BannerCls::build(BuildContext context) {
    assert((textDirection != nullptr && layoutDirection != nullptr) || debugCheckHasDirectionality(context));
    return make<CustomPaintCls>(make<BannerPainterCls>(message, textDirection | DirectionalityCls->of(context), location, layoutDirection | DirectionalityCls->of(context), color, textStyle), child);
}

void BannerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("message"), messagefalse));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirectionnullptr));
    properties->add(<BannerLocation>make<EnumPropertyCls>(__s("location"), location));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("layoutDirection"), layoutDirectionnullptr));
    properties->add(make<ColorPropertyCls>(__s("color"), colorfalse));
    textStyle->debugFillProperties(properties__s("text "));
}

Widget CheckedModeBannerCls::build(BuildContext context) {
    Widget result = child;
    assert([=] () {
        result = make<BannerCls>(__s("DEBUG"), TextDirectionCls::ltr, BannerLocationCls::topEnd, result);
        return true;
    }());
    return result;
}

void CheckedModeBannerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    String message = __s("disabled");
    assert([=] () {
        message = __s(""DEBUG"");
        return true;
    }());
    properties->add(DiagnosticsNodeCls->message(message));
}
