#include "continuous_rectangle_border.hpp"
ContinuousRectangleBorderCls::ContinuousRectangleBorderCls(BorderRadiusGeometry borderRadius, Unknown side) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
    }
}

EdgeInsetsGeometry ContinuousRectangleBorderCls::dimensions() {
    return EdgeInsetsCls->all(side->width);
}

ShapeBorder ContinuousRectangleBorderCls::scale(double t) {
    return make<ContinuousRectangleBorderCls>(side->scale(t), borderRadius * t);
}

ShapeBorder ContinuousRectangleBorderCls::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is ContinuousRectangleBorder) {
        return make<ContinuousRectangleBorderCls>(BorderSideCls->lerp(a->side, side, t), BorderRadiusGeometryCls->lerp(a->borderRadius, borderRadius, t)!);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder ContinuousRectangleBorderCls::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (b is ContinuousRectangleBorder) {
        return make<ContinuousRectangleBorderCls>(BorderSideCls->lerp(side, b->side, t), BorderRadiusGeometryCls->lerp(borderRadius, b->borderRadius, t)!);
    }
    return super->lerpTo(b, t);
}

Path ContinuousRectangleBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    return _getPath(borderRadius->resolve(textDirection)->toRRect(rect)->deflate(side->width));
}

Path ContinuousRectangleBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    return _getPath(borderRadius->resolve(textDirection)->toRRect(rect));
}

ContinuousRectangleBorder ContinuousRectangleBorderCls::copyWith(BorderRadiusGeometry borderRadius, BorderSide side) {
    return make<ContinuousRectangleBorderCls>(side ?? this->side, borderRadius ?? this->borderRadius);
}

void ContinuousRectangleBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (rect->isEmpty) {
        return;
    }
    ;
}

bool ContinuousRectangleBorderCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is ContinuousRectangleBorder && other->side == side && other->borderRadius == borderRadius;
}

int ContinuousRectangleBorderCls::hashCode() {
    return ObjectCls->hash(side, borderRadius);
}

String ContinuousRectangleBorderCls::toString() {
    return "${objectRuntimeType(this, 'ContinuousRectangleBorder')}($side, $borderRadius)";
}

double ContinuousRectangleBorderCls::_clampToShortest(RRect rrect, double value) {
    return value > rrect->shortestSide? rrect->shortestSide : value;
}

Path ContinuousRectangleBorderCls::_getPath(RRect rrect) {
    double left = rrect->left;
    double right = rrect->right;
    double top = rrect->top;
    double bottom = rrect->bottom;
    double tlRadiusX = math->max(0.0, _clampToShortest(rrect, rrect->tlRadiusX));
    double tlRadiusY = math->max(0.0, _clampToShortest(rrect, rrect->tlRadiusY));
    double trRadiusX = math->max(0.0, _clampToShortest(rrect, rrect->trRadiusX));
    double trRadiusY = math->max(0.0, _clampToShortest(rrect, rrect->trRadiusY));
    double blRadiusX = math->max(0.0, _clampToShortest(rrect, rrect->blRadiusX));
    double blRadiusY = math->max(0.0, _clampToShortest(rrect, rrect->blRadiusY));
    double brRadiusX = math->max(0.0, _clampToShortest(rrect, rrect->brRadiusX));
    double brRadiusY = math->max(0.0, _clampToShortest(rrect, rrect->brRadiusY));
    auto _c1 = make<PathCls>();_c1.auto _c2 = moveTo(left, top + tlRadiusX);_c2.auto _c3 = cubicTo(left, top, left, top, left + tlRadiusY, top);_c3.auto _c4 = lineTo(right - trRadiusX, top);_c4.auto _c5 = cubicTo(right, top, right, top, right, top + trRadiusY);_c5.auto _c6 = lineTo(right, bottom - brRadiusX);_c6.auto _c7 = cubicTo(right, bottom, right, bottom, right - brRadiusY, bottom);_c7.auto _c8 = lineTo(left + blRadiusX, bottom);_c8.auto _c9 = cubicTo(left, bottom, left, bottom, left, bottom - blRadiusY);_c9.close();_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;return _c1;
}
