#include "beveled_rectangle_border.hpp"
BeveledRectangleBorderCls::BeveledRectangleBorderCls(BorderRadiusGeometry borderRadius, Unknown side) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
    }
}

EdgeInsetsGeometry BeveledRectangleBorderCls::dimensions() {
    ;
}

ShapeBorder BeveledRectangleBorderCls::scale(double t) {
    return make<BeveledRectangleBorderCls>(side->scale(t), borderRadius * t);
}

ShapeBorder BeveledRectangleBorderCls::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (is<BeveledRectangleBorder>(a)) {
        return make<BeveledRectangleBorderCls>(BorderSideCls->lerp(as<BeveledRectangleBorderCls>(a)->side, side, t), BorderRadiusGeometryCls->lerp(as<BeveledRectangleBorderCls>(a)->borderRadius, borderRadius, t)!);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder BeveledRectangleBorderCls::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (is<BeveledRectangleBorder>(b)) {
        return make<BeveledRectangleBorderCls>(BorderSideCls->lerp(side, as<BeveledRectangleBorderCls>(b)->side, t), BorderRadiusGeometryCls->lerp(borderRadius, as<BeveledRectangleBorderCls>(b)->borderRadius, t)!);
    }
    return super->lerpTo(b, t);
}

BeveledRectangleBorder BeveledRectangleBorderCls::copyWith(BorderRadiusGeometry borderRadius, BorderSide side) {
    return make<BeveledRectangleBorderCls>(side or this->side, borderRadius or this->borderRadius);
}

Path BeveledRectangleBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = borderRadius->resolve(textDirection)->toRRect(rect);
    RRect adjustedRect;
    ;
    return _getPath(adjustedRect);
}

Path BeveledRectangleBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    return _getPath(borderRadius->resolve(textDirection)->toRRect(rect));
}

void BeveledRectangleBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (rect->isEmpty()) {
        return;
    }
    ;
}

bool BeveledRectangleBorderCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<BeveledRectangleBorder>(other) && other->side == side && other->borderRadius == borderRadius;
}

int BeveledRectangleBorderCls::hashCode() {
    return ObjectCls->hash(side, borderRadius);
}

String BeveledRectangleBorderCls::toString() {
    return __s("${objectRuntimeType(this, 'BeveledRectangleBorder')}($side, $borderRadius)");
}

Path BeveledRectangleBorderCls::_getPath(RRect rrect) {
    Offset centerLeft = make<OffsetCls>(rrect->left, rrect->center->dy);
    Offset centerRight = make<OffsetCls>(rrect->right, rrect->center->dy);
    Offset centerTop = make<OffsetCls>(rrect->center->dx, rrect->top);
    Offset centerBottom = make<OffsetCls>(rrect->center->dx, rrect->bottom);
    double tlRadiusX = math->max(0.0, rrect->tlRadiusX);
    double tlRadiusY = math->max(0.0, rrect->tlRadiusY);
    double trRadiusX = math->max(0.0, rrect->trRadiusX);
    double trRadiusY = math->max(0.0, rrect->trRadiusY);
    double blRadiusX = math->max(0.0, rrect->blRadiusX);
    double blRadiusY = math->max(0.0, rrect->blRadiusY);
    double brRadiusX = math->max(0.0, rrect->brRadiusX);
    double brRadiusY = math->max(0.0, rrect->brRadiusY);
    List<Offset> vertices = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    auto _c1 = make<PathCls>();_c1.addPolygon(vertices, true);return _c1;
}
