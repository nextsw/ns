#include "shape_decoration.hpp"
ShapeDecorationCls::ShapeDecorationCls(Color color, Gradient gradient, DecorationImage image, List<BoxShadow> shadows, ShapeBorder shape) {
    {
        assert(!(color != nullptr && gradient != nullptr));
        assert(shape != nullptr);
    }
}

void ShapeDecorationCls::fromBoxDecoration(BoxDecoration source) {
    ShapeBorder shape;
    assert(source->shape != nullptr);
    ;
    return make<ShapeDecorationCls>(source->color, source->image, source->gradient, source->boxShadow, shape);
}

Path ShapeDecorationCls::getClipPath(Rect rect, TextDirection textDirection) {
    return shape->getOuterPath(recttextDirection);
}

EdgeInsetsGeometry ShapeDecorationCls::padding() {
    return shape->dimensions();
}

bool ShapeDecorationCls::isComplex() {
    return shadows != nullptr;
}

ShapeDecoration ShapeDecorationCls::lerpFrom(Decoration a, double t) {
    if (is<BoxDecoration>(a)) {
        return ShapeDecorationCls->lerp(ShapeDecorationCls->fromBoxDecoration(as<BoxDecorationCls>(a)), this, t);
    } else     {
        if (a == nullptr || is<ShapeDecoration>(a)) {
        return ShapeDecorationCls->lerp(as<ShapeDecoration>(a), this, t);
    }
;
    }    return as<ShapeDecoration>(super->lerpFrom(a, t));
}

ShapeDecoration ShapeDecorationCls::lerpTo(Decoration b, double t) {
    if (is<BoxDecoration>(b)) {
        return ShapeDecorationCls->lerp(this, ShapeDecorationCls->fromBoxDecoration(as<BoxDecorationCls>(b)), t);
    } else     {
        if (b == nullptr || is<ShapeDecoration>(b)) {
        return ShapeDecorationCls->lerp(this, as<ShapeDecoration>(b), t);
    }
;
    }    return as<ShapeDecoration>(super->lerpTo(b, t));
}

ShapeDecoration ShapeDecorationCls::lerp(ShapeDecoration a, ShapeDecoration b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a != nullptr && b != nullptr) {
        if (t == 0.0) {
            return a;
        }
        if (t == 1.0) {
            return b;
        }
    }
    return make<ShapeDecorationCls>(ColorCls->lerp(a?->color, b?->color, t), GradientCls->lerp(a?->gradient, b?->gradient, t),  < 0.5? a!->image : b!->image, BoxShadowCls->lerpList(a?->shadows, b?->shadows, t), ShapeBorderCls->lerp(a?->shape, b?->shape, t)!);
}

bool ShapeDecorationCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ShapeDecoration>(other) && other->color == color && other->gradient == gradient && other->image == image && <BoxShadow>listEquals(other->shadows, shadows) && other->shape == shape;
}

int ShapeDecorationCls::hashCode() {
    return ObjectCls->hash(color, gradient, image, shape, shadows == nullptr? nullptr : ObjectCls->hashAll(shadows!));
}

void ShapeDecorationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->defaultDiagnosticsTreeStyle = DiagnosticsTreeStyleCls::whitespace;
    properties->add(make<ColorPropertyCls>(__s("color"), colornullptr));
    properties->add(<Gradient>make<DiagnosticsPropertyCls>(__s("gradient"), gradientnullptr));
    properties->add(<DecorationImage>make<DiagnosticsPropertyCls>(__s("image"), imagenullptr));
    properties->add(<BoxShadow>make<IterablePropertyCls>(__s("shadows"), shadowsnullptr, DiagnosticsTreeStyleCls::whitespace));
    properties->add(<ShapeBorder>make<DiagnosticsPropertyCls>(__s("shape"), shape));
}

bool ShapeDecorationCls::hitTest(Size size, Offset position, TextDirection textDirection) {
    return shape->getOuterPath(OffsetCls::zero & sizetextDirection)->contains(position);
}

BoxPainter ShapeDecorationCls::createBoxPainter(VoidCallback onChanged) {
    assert(onChanged != nullptr || image == nullptr);
    return make<_ShapeDecorationPainterCls>(this, onChanged!);
}

VoidCallback _ShapeDecorationPainterCls::onChanged() {
    return super->onChanged!;
}

void _ShapeDecorationPainterCls::dispose() {
    _imagePainter?->dispose();
    super->dispose();
}

void _ShapeDecorationPainterCls::paint(Canvas canvas, Offset offset, ImageConfiguration configuration) {
    assert(configuration != nullptr);
    assert(configuration->size != nullptr);
    Rect rect = offset & configuration->size!;
    TextDirection textDirection = configuration->textDirection;
    _precache(rect, textDirection);
    _paintShadows(canvas);
    _paintInterior(canvas);
    _paintImage(canvas, configuration);
    _decoration->shape->paint(canvas, recttextDirection);
}

_ShapeDecorationPainterCls::_ShapeDecorationPainterCls(ShapeDecoration _decoration, VoidCallback onChanged) : BoxPainter(onChanged) {
    {
        assert(_decoration != nullptr);
    }
}

void _ShapeDecorationPainterCls::_precache(Rect rect, TextDirection textDirection) {
    assert(rect != nullptr);
    if (rect == _lastRect && textDirection == _lastTextDirection) {
        return;
    }
    if (_interiorPaint == nullptr && (_decoration->color != nullptr || _decoration->gradient != nullptr)) {
        _interiorPaint = make<PaintCls>();
        if (_decoration->color != nullptr) {
            _interiorPaint!->color() = _decoration->color!;
        }
    }
    if (_decoration->gradient != nullptr) {
        _interiorPaint!->shader() = _decoration->gradient!->createShader(recttextDirection);
    }
    if (_decoration->shadows != nullptr) {
        if (_shadowCount == nullptr) {
            _shadowCount = _decoration->shadows!->length();
                    List<Paint> list1 = make<ListCls<>>();        for (auto _x1 : _decoration->shadows!->map([=] (BoxShadow shadow)             {                        shadow->toPaint();                    })) {        {            list1.add(_x1);        }_shadowPaints = list1;
        }
                    })) {    {        list2.add(_x2);    }_shadowPaths =         List<Path> list2 = make<ListCls<>>();        for (auto _x2 : _decoration->shadows!->map([=] (BoxShadow shadow) {                    return _decoration->shape->getOuterPath(rect->shift(shadow->offset)->inflate(shadow->spreadRadius)textDirection);list2;
    }
    if (_interiorPaint != nullptr || _shadowCount != nullptr) {
        _outerPath = _decoration->shape->getOuterPath(recttextDirection);
    }
    if (_decoration->image != nullptr) {
        _innerPath = _decoration->shape->getInnerPath(recttextDirection);
    }
    _lastRect = rect;
    _lastTextDirection = textDirection;
}

void _ShapeDecorationPainterCls::_paintShadows(Canvas canvas) {
    if (_shadowCount != nullptr) {
        for (;  < _shadowCount!; index += 1) {
            canvas->drawPath(_shadowPaths[index], _shadowPaints[index]);
        }
    }
}

void _ShapeDecorationPainterCls::_paintInterior(Canvas canvas) {
    if (_interiorPaint != nullptr) {
        canvas->drawPath(_outerPath, _interiorPaint!);
    }
}

void _ShapeDecorationPainterCls::_paintImage(Canvas canvas, ImageConfiguration configuration) {
    if (_decoration->image == nullptr) {
        return;
    }
    _imagePainter |= _decoration->image!->createPainter(onChanged());
    _imagePainter!->paint(canvas, _lastRect!, _innerPath, configuration);
}
