#include "flutter_logo.hpp"
FlutterLogoDecorationCls::FlutterLogoDecorationCls(EdgeInsets margin, FlutterLogoStyle style, Color textColor) {
    {
        assert(textColor != nullptr);
        assert(style != nullptr);
        assert(margin != nullptr);
        _position = identical(style, FlutterLogoStyleCls::markOnly)? 0.0 : identical(style, FlutterLogoStyleCls::horizontal)? 1.0 : -1.0;
        _opacity = 1.0;
    }
}

bool FlutterLogoDecorationCls::debugAssertIsValid() {
    assert(textColor != nullptr && style != nullptr && margin != nullptr && _position != nullptr && _position->isFinite && _opacity != nullptr && _opacity >= 0.0 && _opacity <= 1.0);
    return true;
}

bool FlutterLogoDecorationCls::isComplex() {
    return !_inTransition();
}

FlutterLogoDecoration FlutterLogoDecorationCls::lerp(FlutterLogoDecoration a, FlutterLogoDecoration b, double t) {
    assert(t != nullptr);
    assert(a == nullptr || a->debugAssertIsValid());
    assert(b == nullptr || b->debugAssertIsValid());
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return FlutterLogoDecorationCls->_(b!->textColor, b->style, b->margin * t, b->_position, b->_opacity * clampDouble(t, 0.0, 1.0));
    }
    if (b == nullptr) {
        return FlutterLogoDecorationCls->_(a->textColor, a->style, a->margin * t, a->_position, a->_opacity * clampDouble(1.0 - t, 0.0, 1.0));
    }
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    return FlutterLogoDecorationCls->_(ColorCls->lerp(a->textColor, b->textColor, t)!,  < 0.5? a->style : b->style, EdgeInsetsCls->lerp(a->margin, b->margin, t)!, a->_position + (b->_position - a->_position) * t, clampDouble(a->_opacity + (b->_opacity - a->_opacity) * t, 0.0, 1.0));
}

FlutterLogoDecoration FlutterLogoDecorationCls::lerpFrom(Decoration a, double t) {
    assert(debugAssertIsValid());
    if (a == nullptr || is<FlutterLogoDecoration>(a)) {
        assert(a == nullptr || a->debugAssertIsValid());
        return FlutterLogoDecorationCls->lerp(as<FlutterLogoDecoration>(a), this, t);
    }
    return as<FlutterLogoDecoration>(super->lerpFrom(a, t));
}

FlutterLogoDecoration FlutterLogoDecorationCls::lerpTo(Decoration b, double t) {
    assert(debugAssertIsValid());
    if (b == nullptr || is<FlutterLogoDecoration>(b)) {
        assert(b == nullptr || b->debugAssertIsValid());
        return FlutterLogoDecorationCls->lerp(this, as<FlutterLogoDecoration>(b), t);
    }
    return as<FlutterLogoDecoration>(super->lerpTo(b, t));
}

bool FlutterLogoDecorationCls::hitTest(Offset position, Size size, TextDirection textDirection) {
    return true;
}

BoxPainter FlutterLogoDecorationCls::createBoxPainter(VoidCallback onChanged) {
    assert(debugAssertIsValid());
    return make<_FlutterLogoPainterCls>(this);
}

Path FlutterLogoDecorationCls::getClipPath(Rect rect, TextDirection textDirection) {
    auto _c1 = make<PathCls>();_c1.addRect(rect);return _c1;
}

bool FlutterLogoDecorationCls::==(Object other) {
    assert(debugAssertIsValid());
    if (identical(this, other)) {
        return true;
    }
    return is<FlutterLogoDecoration>(other) && other->textColor == textColor && other->_position == _position && other->_opacity == _opacity;
}

int FlutterLogoDecorationCls::hashCode() {
    assert(debugAssertIsValid());
    return ObjectCls->hash(textColor, _position, _opacity);
}

void FlutterLogoDecorationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<ColorPropertyCls>(__s("textColor"), textColor));
    properties->add(<FlutterLogoStyle>make<EnumPropertyCls>(__s("style"), style));
    if (_inTransition()) {
        properties->add(DiagnosticsNodeCls->message(__s("transition ${debugFormatDouble(_position)}:${debugFormatDouble(_opacity)}")));
    }
}

bool FlutterLogoDecorationCls::_inTransition() {
    return _opacity != 1.0 || (_position != -1.0 && _position != 0.0 && _position != 1.0);
}

void _FlutterLogoPainterCls::paint(Canvas canvas, ImageConfiguration configuration, Offset offset) {
    offset = _config->margin->topLeft();
    Size canvasSize = _config->margin->deflateSize(configuration->size!);
    if (canvasSize->isEmpty()) {
        return;
    }
    Size logoSize;
    if (_config->_position > 0.0) {
        logoSize = make<SizeCls>(820.0, 232.0);
    } else     {
        if (_config->_position < 0.0) {
        logoSize = make<SizeCls>(252.0, 306.0);
    } else {
        logoSize = make<SizeCls>(202.0, 202.0);
    }
;
    }    FittedSizes fittedSize = applyBoxFit(BoxFitCls::contain, logoSize, canvasSize);
    assert(fittedSize->source == logoSize);
    Rect rect = AlignmentCls::center->inscribe(fittedSize->destination, offset & canvasSize);
    double centerSquareHeight = canvasSize->shortestSide();
    Rect centerSquare = RectCls->fromLTWH(offset->dx() + (canvasSize->width() - centerSquareHeight) / 2.0, offset->dy() + (canvasSize->height() - centerSquareHeight) / 2.0, centerSquareHeight, centerSquareHeight);
    Rect logoTargetSquare;
    if (_config->_position > 0.0) {
        logoTargetSquare = RectCls->fromLTWH(rect->left, rect->top, rect->height(), rect->height());
    } else     {
        if (_config->_position < 0.0) {
        double logoHeight = rect->height() * 191.0 / 306.0;
        logoTargetSquare = RectCls->fromLTWH(rect->left + (rect->width() - logoHeight) / 2.0, rect->top, logoHeight, logoHeight);
    } else {
        logoTargetSquare = centerSquare;
    }
;
    }    Rect logoSquare = RectCls->lerp(centerSquare, logoTargetSquare, _config->_position->abs())!;
    if (_config->_opacity < 1.0) {
            auto _c1 = make<PaintCls>();    _c1.colorFilter = ColorFilterCls->mode(make<ColorCls>(0xFFFFFFFF)->withOpacity(_config->_opacity), BlendModeCls::modulate);canvas->saveLayer(offset & canvasSize, _c1);
    }
    if (_config->_position != 0.0) {
        if (_config->_position > 0.0) {
            double fontSize = 2.0 / 3.0 * logoSquare->height() * (1 - (10.4 * 2.0) / 202.0);
            double scale = fontSize / 100.0;
            double finalLeftTextPosition = (256.4 / 820.0) * rect->width() - (32.0 / 350.0) * fontSize;
            double initialLeftTextPosition = rect->width() / 2.0 - _textBoundingRect->width() * scale;
            Offset textOffset = make<OffsetCls>(rect->left + ui->lerpDouble(initialLeftTextPosition, finalLeftTextPosition, _config->_position)!, rect->top + (rect->height() - _textBoundingRect->height() * scale) / 2.0);
            canvas->save();
            if (_config->_position < 1.0) {
                Offset center = logoSquare->center();
                            auto _c2 = make<PathCls>();            _c2.auto _c3 = moveTo(center->dx(), center->dy());            _c3.auto _c4 = lineTo(center->dx() + rect->width(), center->dy() - rect->width());            _c4.auto _c5 = lineTo(center->dx() + rect->width(), center->dy() + rect->width());            _c5.close();            _c5;            _c4;            _c3;Path path = _c2;
                canvas->clipPath(path);
            }
            canvas->translate(textOffset->dx(), textOffset->dy());
            canvas->scale(scale, scale);
            _textPainter->paint(canvas, OffsetCls::zero);
            canvas->restore();
        } else         {
            if (_config->_position < 0.0) {
            double fontSize = 0.35 * logoTargetSquare->height() * (1 - (10.4 * 2.0) / 202.0);
            double scale = fontSize / 100.0;
            if (_config->_position > -1.0) {
                canvas->saveLayer(_textBoundingRect, make<PaintCls>());
            } else {
                canvas->save();
            }
            canvas->translate(logoTargetSquare->center()->dx() - (_textBoundingRect->width() * scale / 2.0), logoTargetSquare->bottom);
            canvas->scale(scale, scale);
            _textPainter->paint(canvas, OffsetCls::zero);
            if (_config->_position > -1.0) {
                            auto _c6 = make<PaintCls>();            _c6.blendMode = auto _c7 = BlendModeCls::modulate;            _c7.shader = ui->GradientCls->linear(make<OffsetCls>(_textBoundingRect->width() * -0.5, 0.0), make<OffsetCls>(_textBoundingRect->width() * 1.5, 0.0), makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem), makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));            _c7;canvas->drawRect(_textBoundingRect->inflate(_textBoundingRect->width() * 0.5), _c6);
            }
            canvas->restore();
        }
;
        }    }
    _paintLogo(canvas, logoSquare);
    if (_config->_opacity < 1.0) {
        canvas->restore();
    }
}

_FlutterLogoPainterCls::_FlutterLogoPainterCls(FlutterLogoDecoration _config) : BoxPainter(nullptr) {
    {
        assert(_config != nullptr);
        assert(_config->debugAssertIsValid());
    }
    {
        _prepareText();
    }
}

void _FlutterLogoPainterCls::_prepareText() {
    String kLabel = __s("Flutter");
    _textPainter = make<TextPainterCls>(make<TextSpanCls>(kLabel, make<TextStyleCls>(_config->textColor, __s("Roboto"), 100.0 * 350.0 / 247.0, FontWeightCls::w300, TextBaselineCls::alphabetic)), TextDirectionCls::ltr);
    _textPainter->layout();
    TextBox textSize = _textPainter->getBoxesForSelection(make<TextSelectionCls>(0, kLabel->length()))->single;
    _textBoundingRect = RectCls->fromLTRB(textSize->left, textSize->top, textSize->right, textSize->bottom);
}

void _FlutterLogoPainterCls::_paintLogo(Canvas canvas, Rect rect) {
    canvas->save();
    canvas->translate(rect->left, rect->top);
    canvas->scale(rect->width() / 202.0, rect->height() / 202.0);
    canvas->translate((202.0 - 166.0) / 2.0, 0.0);
    auto _c1 = make<PaintCls>();_c1.color = make<ColorCls>(0xFF54C5F8);Paint lightPaint = _c1;
    auto _c2 = make<PaintCls>();_c2.color = make<ColorCls>(0xFF29B6F6);Paint mediumPaint = _c2;
    auto _c3 = make<PaintCls>();_c3.color = make<ColorCls>(0xFF01579B);Paint darkPaint = _c3;
    Gradient triangleGradient = ui->GradientCls->linear(make<OffsetCls>(87.2623 + 37.9092, 28.8384 + 123.4389), make<OffsetCls>(42.9205 + 37.9092, 35.0952 + 123.4389), makeList(ArrayItem, ArrayItem));
    auto _c4 = make<PaintCls>();_c4.shader = triangleGradient;Paint trianglePaint = _c4;
    auto _c5 = make<PathCls>();_c5.auto _c6 = moveTo(37.7, 128.9);_c6.auto _c7 = lineTo(9.8, 101.0);_c7.auto _c8 = lineTo(100.4, 10.4);_c8.lineTo(156.2, 10.4);_c8;_c7;_c6;Path topBeam = _c5;
    canvas->drawPath(topBeam, lightPaint);
    auto _c9 = make<PathCls>();_c9.auto _c10 = moveTo(156.2, 94.0);_c10.auto _c11 = lineTo(100.4, 94.0);_c11.auto _c12 = lineTo(78.5, 115.9);_c12.lineTo(106.4, 143.8);_c12;_c11;_c10;Path middleBeam = _c9;
    canvas->drawPath(middleBeam, lightPaint);
    auto _c13 = make<PathCls>();_c13.auto _c14 = moveTo(79.5, 170.7);_c14.auto _c15 = lineTo(100.4, 191.6);_c15.auto _c16 = lineTo(156.2, 191.6);_c16.lineTo(107.4, 142.8);_c16;_c15;_c14;Path bottomBeam = _c13;
    canvas->drawPath(bottomBeam, darkPaint);
    canvas->save();
    canvas->transform(Float64ListCls->fromList(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem)));
    canvas->drawRect(RectCls->fromLTWH(59.8, 123.1, 39.4, 39.4), mediumPaint);
    canvas->restore();
    auto _c17 = make<PathCls>();_c17.auto _c18 = moveTo(79.5, 170.7);_c18.auto _c19 = lineTo(120.9, 156.4);_c19.lineTo(107.4, 142.8);_c19;_c18;Path triangle = _c17;
    canvas->drawPath(triangle, trianglePaint);
    canvas->restore();
}
