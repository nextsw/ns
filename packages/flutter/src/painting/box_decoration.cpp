#include "box_decoration.hpp"
BoxDecoration::BoxDecoration(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape) {
    {
        assert(shape != nullptr);
        assert(backgroundBlendMode == nullptr || color != nullptr || gradient != nullptr, "backgroundBlendMode applies to BoxDecoration's background color or gradient, but no color or gradient was provided.");
    }
}

BoxDecoration BoxDecoration::copyWith(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape) {
    return BoxDecoration(color ?? this.color, image ?? this.image, border ?? this.border, borderRadius ?? this.borderRadius, boxShadow ?? this.boxShadow, gradient ?? this.gradient, backgroundBlendMode ?? this.backgroundBlendMode, shape ?? this.shape);
}

bool BoxDecoration::debugAssertIsValid() {
    assert(shape != BoxShape.circle || borderRadius == nullptr);
    return super.debugAssertIsValid();
}

EdgeInsetsGeometry BoxDecoration::padding() {
    return border?.dimensions;
}

Path BoxDecoration::getClipPath(Rect rect, TextDirection textDirection) {
    ;
}

BoxDecoration BoxDecoration::scale(double factor) {
    return BoxDecoration(Color.lerp(nullptr, color, factor), image, BoxBorder.lerp(nullptr, border, factor), BorderRadiusGeometry.lerp(nullptr, borderRadius, factor), BoxShadow.lerpList(nullptr, boxShadow, factor), gradient?.scale(factor), shape);
}

bool BoxDecoration::isComplex() {
    return boxShadow != nullptr;
}

BoxDecoration BoxDecoration::lerpFrom(Decoration a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    if (a is BoxDecoration) {
        return BoxDecoration.lerp(a, this, t);
    }
    return (;
}

BoxDecoration BoxDecoration::lerpTo(Decoration b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    if (b is BoxDecoration) {
        return BoxDecoration.lerp(this, b, t);
    }
    return (;
}

BoxDecoration BoxDecoration::lerp(BoxDecoration a, BoxDecoration b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!.scale(t);
    }
    if (b == nullptr) {
        return a.scale(1.0 - t);
    }
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    return BoxDecoration(Color.lerp(a.color, b.color, t),  < 0.5? a.image : b.image, BoxBorder.lerp(a.border, b.border, t), BorderRadiusGeometry.lerp(a.borderRadius, b.borderRadius, t), BoxShadow.lerpList(a.boxShadow, b.boxShadow, t), Gradient.lerp(a.gradient, b.gradient, t),  < 0.5? a.shape : b.shape);
}

bool BoxDecoration::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is BoxDecoration && other.color == color && other.image == image && other.border == border && other.borderRadius == borderRadius && <BoxShadow>listEquals(other.boxShadow, boxShadow) && other.gradient == gradient && other.backgroundBlendMode == backgroundBlendMode && other.shape == shape;
}

int BoxDecoration::hashCode() {
    return Object.hash(color, image, border, borderRadius, boxShadow == nullptr? nullptr : Object.hashAll(boxShadow!), gradient, backgroundBlendMode, shape);
}

void BoxDecoration::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    ;
    properties.add(ColorProperty("color", colornullptr));
    properties.add(<DecorationImage>DiagnosticsProperty("image", imagenullptr));
    properties.add(<BoxBorder>DiagnosticsProperty("border", bordernullptr));
    properties.add(<BorderRadiusGeometry>DiagnosticsProperty("borderRadius", borderRadiusnullptr));
    properties.add(<BoxShadow>IterableProperty("boxShadow", boxShadownullptr, DiagnosticsTreeStyle.whitespace));
    properties.add(<Gradient>DiagnosticsProperty("gradient", gradientnullptr));
    properties.add(<BoxShape>EnumProperty("shape", shapeBoxShape.rectangle));
}

bool BoxDecoration::hitTest(Offset position, Size size, TextDirection textDirection) {
    assert(shape != nullptr);
    assert((Offset.zero & size).contains(position));
    ;
}

BoxPainter BoxDecoration::createBoxPainter(VoidCallback onChanged) {
    assert(onChanged != nullptr || image == nullptr);
    return _BoxDecorationPainter(this, onChanged);
}

void _BoxDecorationPainter::dispose() {
    _imagePainter?.dispose();
    super.dispose();
}

void _BoxDecorationPainter::paint(Canvas canvas, ImageConfiguration configuration, Offset offset) {
    assert(configuration != nullptr);
    assert(configuration.size != nullptr);
    Rect rect = offset & configuration.size!;
    TextDirection textDirection = configuration.textDirection;
    _paintShadows(canvas, rect, textDirection);
    _paintBackgroundColor(canvas, rect, textDirection);
    _paintBackgroundImage(canvas, rect, configuration);
    _decoration.border?.paint(canvas, rect_decoration.shape, _decoration.borderRadius?.resolve(textDirection), configuration.textDirection);
}

String _BoxDecorationPainter::toString() {
    return "BoxPainter for $_decoration";
}

_BoxDecorationPainter::_BoxDecorationPainter(BoxDecoration _decoration, VoidCallback onChanged) {
    {
        assert(_decoration != nullptr);
        super(onChanged);
    }
}

Paint _BoxDecorationPainter::_getBackgroundPaint(Rect rect, TextDirection textDirection) {
    assert(rect != nullptr);
    assert(_decoration.gradient != nullptr || _rectForCachedBackgroundPaint == nullptr);
    if (_cachedBackgroundPaint == nullptr || (_decoration.gradient != nullptr && _rectForCachedBackgroundPaint != rect)) {
        Paint paint = Paint();
        if (_decoration.backgroundBlendMode != nullptr) {
            paint.blendMode = _decoration.backgroundBlendMode!;
        }
        if (_decoration.color != nullptr) {
            paint.color = _decoration.color!;
        }
        if (_decoration.gradient != nullptr) {
            paint.shader = _decoration.gradient!.createShader(recttextDirection);
            _rectForCachedBackgroundPaint = rect;
        }
        _cachedBackgroundPaint = paint;
    }
    return _cachedBackgroundPaint!;
}

void _BoxDecorationPainter::_paintBox(Canvas canvas, Paint paint, Rect rect, TextDirection textDirection) {
    ;
}

void _BoxDecorationPainter::_paintShadows(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (_decoration.boxShadow == nullptr) {
        return;
    }
    for (BoxShadow boxShadow : _decoration.boxShadow!) {
        Paint paint = boxShadow.toPaint();
        Rect bounds = rect.shift(boxShadow.offset).inflate(boxShadow.spreadRadius);
        _paintBox(canvas, bounds, paint, textDirection);
    }
}

void _BoxDecorationPainter::_paintBackgroundColor(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (_decoration.color != nullptr || _decoration.gradient != nullptr) {
        _paintBox(canvas, rect, _getBackgroundPaint(rect, textDirection), textDirection);
    }
}

void _BoxDecorationPainter::_paintBackgroundImage(Canvas canvas, ImageConfiguration configuration, Rect rect) {
    if (_decoration.image == nullptr) {
        return;
    }
    _imagePainter = _decoration.image!.createPainter(onChanged!);
    Path clipPath;
    ;
    _imagePainter!.paint(canvas, rect, clipPath, configuration);
}
