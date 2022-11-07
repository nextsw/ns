#include "flutter_logo.hpp"
FlutterLogoDecoration::FlutterLogoDecoration(EdgeInsets margin, FlutterLogoStyle style, Color textColor) {
    {
        assert(textColor != nullptr);
        assert(style != nullptr);
        assert(margin != nullptr);
        _position = identical(style, FlutterLogoStyle.markOnly)? 0.0 : identical(style, FlutterLogoStyle.horizontal)? 1.0 : -1.0;
        _opacity = 1.0;
    }
}

bool FlutterLogoDecoration::debugAssertIsValid() {
    assert(textColor != nullptr && style != nullptr && margin != nullptr && _position != nullptr && _position.isFinite && _opacity != nullptr && _opacity >= 0.0 && _opacity <= 1.0);
    return true;
}

bool FlutterLogoDecoration::isComplex() {
    return !_inTransition;
}

FlutterLogoDecoration FlutterLogoDecoration::lerp(FlutterLogoDecoration a, FlutterLogoDecoration b, double t) {
    assert(t != nullptr);
    assert(a == nullptr || a.debugAssertIsValid());
    assert(b == nullptr || b.debugAssertIsValid());
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return FlutterLogoDecoration._(b!.textColor, b.style, b.margin * t, b._position, b._opacity * clampDouble(t, 0.0, 1.0));
    }
    if (b == nullptr) {
        return FlutterLogoDecoration._(a.textColor, a.style, a.margin * t, a._position, a._opacity * clampDouble(1.0 - t, 0.0, 1.0));
    }
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    return FlutterLogoDecoration._(Color.lerp(a.textColor, b.textColor, t)!,  < 0.5? a.style : b.style, EdgeInsets.lerp(a.margin, b.margin, t)!, a._position + (b._position - a._position) * t, clampDouble(a._opacity + (b._opacity - a._opacity) * t, 0.0, 1.0));
}

FlutterLogoDecoration FlutterLogoDecoration::lerpFrom(Decoration a, double t) {
    assert(debugAssertIsValid());
    if (a == nullptr || a is FlutterLogoDecoration) {
        assert(a == nullptr || a.debugAssertIsValid());
        return FlutterLogoDecoration.lerp((, this, t);
    }
    return (;
}

FlutterLogoDecoration FlutterLogoDecoration::lerpTo(Decoration b, double t) {
    assert(debugAssertIsValid());
    if (b == nullptr || b is FlutterLogoDecoration) {
        assert(b == nullptr || b.debugAssertIsValid());
        return FlutterLogoDecoration.lerp(this, (, t);
    }
    return (;
}

bool FlutterLogoDecoration::hitTest(Offset position, Size size, TextDirection textDirection) {
    return true;
}

BoxPainter FlutterLogoDecoration::createBoxPainter(VoidCallback onChanged) {
    assert(debugAssertIsValid());
    return _FlutterLogoPainter(this);
}

Path FlutterLogoDecoration::getClipPath(Rect rect, TextDirection textDirection) {
    return ;
}

bool FlutterLogoDecoration::==(Object other) {
    assert(debugAssertIsValid());
    if (identical(this, other)) {
        return true;
    }
    return other is FlutterLogoDecoration && other.textColor == textColor && other._position == _position && other._opacity == _opacity;
}

int FlutterLogoDecoration::hashCode() {
    assert(debugAssertIsValid());
    return Object.hash(textColor, _position, _opacity);
}

void FlutterLogoDecoration::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(ColorProperty("textColor", textColor));
    properties.add(<FlutterLogoStyle>EnumProperty("style", style));
    if (_inTransition) {
        properties.add(DiagnosticsNode.message("transition ${debugFormatDouble(_position)}:${debugFormatDouble(_opacity)}"));
    }
}

bool FlutterLogoDecoration::_inTransition() {
    return _opacity != 1.0 || (_position != -1.0 && _position != 0.0 && _position != 1.0);
}

void _FlutterLogoPainter::paint(Canvas canvas, ImageConfiguration configuration, Offset offset) {
    offset = _config.margin.topLeft;
    Size canvasSize = _config.margin.deflateSize(configuration.size!);
    if (canvasSize.isEmpty) {
        return;
    }
    Size logoSize;
    if (_config._position > 0.0) {
        logoSize = const Size(820.0, 232.0);
    } else     {
        if (_config._position < 0.0) {
        logoSize = const Size(252.0, 306.0);
    } else {
        logoSize = const Size(202.0, 202.0);
    }
;
    }    FittedSizes fittedSize = applyBoxFit(BoxFit.contain, logoSize, canvasSize);
    assert(fittedSize.source == logoSize);
    Rect rect = Alignment.center.inscribe(fittedSize.destination, offset & canvasSize);
    double centerSquareHeight = canvasSize.shortestSide;
    Rect centerSquare = Rect.fromLTWH(offset.dx + (canvasSize.width - centerSquareHeight) / 2.0, offset.dy + (canvasSize.height - centerSquareHeight) / 2.0, centerSquareHeight, centerSquareHeight);
    Rect logoTargetSquare;
    if (_config._position > 0.0) {
        logoTargetSquare = Rect.fromLTWH(rect.left, rect.top, rect.height, rect.height);
    } else     {
        if (_config._position < 0.0) {
        double logoHeight = rect.height * 191.0 / 306.0;
        logoTargetSquare = Rect.fromLTWH(rect.left + (rect.width - logoHeight) / 2.0, rect.top, logoHeight, logoHeight);
    } else {
        logoTargetSquare = centerSquare;
    }
;
    }    Rect logoSquare = Rect.lerp(centerSquare, logoTargetSquare, _config._position.abs())!;
    if (_config._opacity < 1.0) {
        canvas.saveLayer(offset & canvasSize, );
    }
    if (_config._position != 0.0) {
        if (_config._position > 0.0) {
            double fontSize = 2.0 / 3.0 * logoSquare.height * (1 - (10.4 * 2.0) / 202.0);
            double scale = fontSize / 100.0;
            double finalLeftTextPosition = (256.4 / 820.0) * rect.width - (32.0 / 350.0) * fontSize;
            double initialLeftTextPosition = rect.width / 2.0 - _textBoundingRect.width * scale;
            Offset textOffset = Offset(rect.left + ui.lerpDouble(initialLeftTextPosition, finalLeftTextPosition, _config._position)!, rect.top + (rect.height - _textBoundingRect.height * scale) / 2.0);
            canvas.save();
            if (_config._position < 1.0) {
                Offset center = logoSquare.center;
                Path path = ;
                canvas.clipPath(path);
            }
            canvas.translate(textOffset.dx, textOffset.dy);
            canvas.scale(scale, scale);
            _textPainter.paint(canvas, Offset.zero);
            canvas.restore();
        } else         {
            if (_config._position < 0.0) {
            double fontSize = 0.35 * logoTargetSquare.height * (1 - (10.4 * 2.0) / 202.0);
            double scale = fontSize / 100.0;
            if (_config._position > -1.0) {
                canvas.saveLayer(_textBoundingRect, Paint());
            } else {
                canvas.save();
            }
            canvas.translate(logoTargetSquare.center.dx - (_textBoundingRect.width * scale / 2.0), logoTargetSquare.bottom);
            canvas.scale(scale, scale);
            _textPainter.paint(canvas, Offset.zero);
            if (_config._position > -1.0) {
                canvas.drawRect(_textBoundingRect.inflate(_textBoundingRect.width * 0.5), );
            }
            canvas.restore();
        }
;
        }    }
    _paintLogo(canvas, logoSquare);
    if (_config._opacity < 1.0) {
        canvas.restore();
    }
}

_FlutterLogoPainter::_FlutterLogoPainter(FlutterLogoDecoration _config) {
    {
        assert(_config != nullptr);
        assert(_config.debugAssertIsValid());
        super(nullptr);
    }
    {
        _prepareText();
    }
}

void _FlutterLogoPainter::_prepareText() {
    String kLabel = "Flutter";
    _textPainter = TextPainter(TextSpan(kLabel, TextStyle(_config.textColor, "Roboto", 100.0 * 350.0 / 247.0, FontWeight.w300, TextBaseline.alphabetic)), TextDirection.ltr);
    _textPainter.layout();
    TextBox textSize = _textPainter.getBoxesForSelection(const TextSelection(0, kLabel.length)).single;
    _textBoundingRect = Rect.fromLTRB(textSize.left, textSize.top, textSize.right, textSize.bottom);
}

void _FlutterLogoPainter::_paintLogo(Canvas canvas, Rect rect) {
    canvas.save();
    canvas.translate(rect.left, rect.top);
    canvas.scale(rect.width / 202.0, rect.height / 202.0);
    canvas.translate((202.0 - 166.0) / 2.0, 0.0);
    Paint lightPaint = ;
    Paint mediumPaint = ;
    Paint darkPaint = ;
    Gradient triangleGradient = ui.Gradient.linear(const Offset(87.2623 + 37.9092, 28.8384 + 123.4389), const Offset(42.9205 + 37.9092, 35.0952 + 123.4389), );
    Paint trianglePaint = ;
    Path topBeam = ;
    canvas.drawPath(topBeam, lightPaint);
    Path middleBeam = ;
    canvas.drawPath(middleBeam, lightPaint);
    Path bottomBeam = ;
    canvas.drawPath(bottomBeam, darkPaint);
    canvas.save();
    canvas.transform(Float64List.fromList(const ));
    canvas.drawRect(const Rect.fromLTWH(59.8, 123.1, 39.4, 39.4), mediumPaint);
    canvas.restore();
    Path triangle = ;
    canvas.drawPath(triangle, trianglePaint);
    canvas.restore();
}
