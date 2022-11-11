#include "box_decoration.hpp"
BoxDecorationCls::BoxDecorationCls(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape) {
    {
        assert(shape != nullptr);
        assert(backgroundBlendMode == nullptr || color != nullptr || gradient != nullptr, __s("backgroundBlendMode applies to BoxDecoration's background color or gradient, but no color or gradient was provided."));
    }
}

BoxDecoration BoxDecorationCls::copyWith(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape) {
    return make<BoxDecorationCls>(color | this->color, image | this->image, border | this->border, borderRadius | this->borderRadius, boxShadow | this->boxShadow, gradient | this->gradient, backgroundBlendMode | this->backgroundBlendMode, shape | this->shape);
}

bool BoxDecorationCls::debugAssertIsValid() {
    assert(shape != BoxShapeCls::circle || borderRadius == nullptr);
    return super->debugAssertIsValid();
}

EdgeInsetsGeometry BoxDecorationCls::padding() {
    return border?->dimensions;
}

Path BoxDecorationCls::getClipPath(Rect rect, TextDirection textDirection) {
    ;
}

BoxDecoration BoxDecorationCls::scale(double factor) {
    return make<BoxDecorationCls>(ColorCls->lerp(nullptr, color, factor), image, BoxBorderCls->lerp(nullptr, border, factor), BorderRadiusGeometryCls->lerp(nullptr, borderRadius, factor), BoxShadowCls->lerpList(nullptr, boxShadow, factor), gradient?->scale(factor), shape);
}

bool BoxDecorationCls::isComplex() {
    return boxShadow != nullptr;
}

BoxDecoration BoxDecorationCls::lerpFrom(Decoration a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    if (is<BoxDecoration>(a)) {
        return BoxDecorationCls->lerp(as<BoxDecorationCls>(a), this, t);
    }
    return as<BoxDecoration>(super->lerpFrom(a, t));
}

BoxDecoration BoxDecorationCls::lerpTo(Decoration b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    if (is<BoxDecoration>(b)) {
        return BoxDecorationCls->lerp(this, as<BoxDecorationCls>(b), t);
    }
    return as<BoxDecoration>(super->lerpTo(b, t));
}

BoxDecoration BoxDecorationCls::lerp(BoxDecoration a, BoxDecoration b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->scale(t);
    }
    if (b == nullptr) {
        return a->scale(1.0 - t);
    }
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    return make<BoxDecorationCls>(ColorCls->lerp(a->color, b->color, t),  < 0.5? a->image : b->image, BoxBorderCls->lerp(a->border, b->border, t), BorderRadiusGeometryCls->lerp(a->borderRadius, b->borderRadius, t), BoxShadowCls->lerpList(a->boxShadow, b->boxShadow, t), GradientCls->lerp(a->gradient, b->gradient, t),  < 0.5? a->shape : b->shape);
}

bool BoxDecorationCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<BoxDecoration>(other) && other->color == color && other->image == image && other->border == border && other->borderRadius == borderRadius && <BoxShadow>listEquals(other->boxShadow, boxShadow) && other->gradient == gradient && other->backgroundBlendMode == backgroundBlendMode && other->shape == shape;
}

int BoxDecorationCls::hashCode() {
    return ObjectCls->hash(color, image, border, borderRadius, boxShadow == nullptr? nullptr : ObjectCls->hashAll(boxShadow!), gradient, backgroundBlendMode, shape);
}

void BoxDecorationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    auto _c1 = properties;_c1.defaultDiagnosticsTreeStyle = auto _c2 = DiagnosticsTreeStyleCls::whitespace;_c2.emptyBodyDescription = __s("<no decorations specified>");_c2;_c1;
    properties->add(make<ColorPropertyCls>(__s("color"), colornullptr));
    properties->add(<DecorationImage>make<DiagnosticsPropertyCls>(__s("image"), imagenullptr));
    properties->add(<BoxBorder>make<DiagnosticsPropertyCls>(__s("border"), bordernullptr));
    properties->add(<BorderRadiusGeometry>make<DiagnosticsPropertyCls>(__s("borderRadius"), borderRadiusnullptr));
    properties->add(<BoxShadow>make<IterablePropertyCls>(__s("boxShadow"), boxShadownullptr, DiagnosticsTreeStyleCls::whitespace));
    properties->add(<Gradient>make<DiagnosticsPropertyCls>(__s("gradient"), gradientnullptr));
    properties->add(<BoxShape>make<EnumPropertyCls>(__s("shape"), shapeBoxShapeCls::rectangle));
}

bool BoxDecorationCls::hitTest(Size size, Offset position, TextDirection textDirection) {
    assert(shape != nullptr);
    assert((OffsetCls::zero & size)->contains(position));
    ;
}

BoxPainter BoxDecorationCls::createBoxPainter(VoidCallback onChanged) {
    assert(onChanged != nullptr || image == nullptr);
    return make<_BoxDecorationPainterCls>(this, onChanged);
}

void _BoxDecorationPainterCls::dispose() {
    _imagePainter?->dispose();
    super->dispose();
}

void _BoxDecorationPainterCls::paint(Canvas canvas, Offset offset, ImageConfiguration configuration) {
    assert(configuration != nullptr);
    assert(configuration->size != nullptr);
    Rect rect = offset & configuration->size!;
    TextDirection textDirection = configuration->textDirection;
    _paintShadows(canvas, rect, textDirection);
    _paintBackgroundColor(canvas, rect, textDirection);
    _paintBackgroundImage(canvas, rect, configuration);
    _decoration->border?->paint(canvas, rect_decoration->shape, _decoration->borderRadius?->resolve(textDirection), configuration->textDirection);
}

String _BoxDecorationPainterCls::toString() {
    return __s("BoxPainter for $_decoration");
}

_BoxDecorationPainterCls::_BoxDecorationPainterCls(BoxDecoration _decoration, VoidCallback onChanged) : BoxPainter(onChanged) {
    {
        assert(_decoration != nullptr);
    }
}

Paint _BoxDecorationPainterCls::_getBackgroundPaint(Rect rect, TextDirection textDirection) {
    assert(rect != nullptr);
    assert(_decoration->gradient != nullptr || _rectForCachedBackgroundPaint == nullptr);
    if (_cachedBackgroundPaint == nullptr || (_decoration->gradient != nullptr && _rectForCachedBackgroundPaint != rect)) {
        Paint paint = make<PaintCls>();
        if (_decoration->backgroundBlendMode != nullptr) {
            paint->blendMode() = _decoration->backgroundBlendMode!;
        }
        if (_decoration->color != nullptr) {
            paint->color() = _decoration->color!;
        }
        if (_decoration->gradient != nullptr) {
            paint->shader() = _decoration->gradient!->createShader(recttextDirection);
            _rectForCachedBackgroundPaint = rect;
        }
        _cachedBackgroundPaint = paint;
    }
    return _cachedBackgroundPaint!;
}

void _BoxDecorationPainterCls::_paintBox(Canvas canvas, Rect rect, Paint paint, TextDirection textDirection) {
    ;
}

void _BoxDecorationPainterCls::_paintShadows(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (_decoration->boxShadow == nullptr) {
        return;
    }
    for (BoxShadow boxShadow : _decoration->boxShadow!) {
        Paint paint = boxShadow->toPaint();
        Rect bounds = rect->shift(boxShadow->offset)->inflate(boxShadow->spreadRadius);
        _paintBox(canvas, bounds, paint, textDirection);
    }
}

void _BoxDecorationPainterCls::_paintBackgroundColor(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (_decoration->color != nullptr || _decoration->gradient != nullptr) {
        _paintBox(canvas, rect, _getBackgroundPaint(rect, textDirection), textDirection);
    }
}

void _BoxDecorationPainterCls::_paintBackgroundImage(Canvas canvas, Rect rect, ImageConfiguration configuration) {
    if (_decoration->image == nullptr) {
        return;
    }
    _imagePainter |= _decoration->image!->createPainter(onChanged!);
    Path clipPath;
    ;
    _imagePainter!->paint(canvas, rect, clipPath, configuration);
}
