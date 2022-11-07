#include "beveled_rectangle_border.hpp"
BeveledRectangleBorder::BeveledRectangleBorder(BorderRadiusGeometry borderRadius, Unknown) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
    }
}

EdgeInsetsGeometry BeveledRectangleBorder::dimensions() {
    ;
}

ShapeBorder BeveledRectangleBorder::scale(double t) {
    return BeveledRectangleBorder(side.scale(t), borderRadius * t);
}

ShapeBorder BeveledRectangleBorder::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is BeveledRectangleBorder) {
        return BeveledRectangleBorder(BorderSide.lerp(a.side, side, t), BorderRadiusGeometry.lerp(a.borderRadius, borderRadius, t)!);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder BeveledRectangleBorder::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (b is BeveledRectangleBorder) {
        return BeveledRectangleBorder(BorderSide.lerp(side, b.side, t), BorderRadiusGeometry.lerp(borderRadius, b.borderRadius, t)!);
    }
    return super.lerpTo(b, t);
}

BeveledRectangleBorder BeveledRectangleBorder::copyWith(BorderRadiusGeometry borderRadius, BorderSide side) {
    return BeveledRectangleBorder(side ?? this.side, borderRadius ?? this.borderRadius);
}

Path BeveledRectangleBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = borderRadius.resolve(textDirection).toRRect(rect);
    RRect adjustedRect;
    ;
    return _getPath(adjustedRect);
}

Path BeveledRectangleBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return _getPath(borderRadius.resolve(textDirection).toRRect(rect));
}

void BeveledRectangleBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (rect.isEmpty) {
        return;
    }
    ;
}

bool BeveledRectangleBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is BeveledRectangleBorder && other.side == side && other.borderRadius == borderRadius;
}

int BeveledRectangleBorder::hashCode() {
    return Object.hash(side, borderRadius);
}

String BeveledRectangleBorder::toString() {
    return "${objectRuntimeType(this, 'BeveledRectangleBorder')}($side, $borderRadius)";
}

Path BeveledRectangleBorder::_getPath(RRect rrect) {
    Offset centerLeft = Offset(rrect.left, rrect.center.dy);
    Offset centerRight = Offset(rrect.right, rrect.center.dy);
    Offset centerTop = Offset(rrect.center.dx, rrect.top);
    Offset centerBottom = Offset(rrect.center.dx, rrect.bottom);
    double tlRadiusX = math.max(0.0, rrect.tlRadiusX);
    double tlRadiusY = math.max(0.0, rrect.tlRadiusY);
    double trRadiusX = math.max(0.0, rrect.trRadiusX);
    double trRadiusY = math.max(0.0, rrect.trRadiusY);
    double blRadiusX = math.max(0.0, rrect.blRadiusX);
    double blRadiusY = math.max(0.0, rrect.blRadiusY);
    double brRadiusX = math.max(0.0, rrect.brRadiusX);
    double brRadiusY = math.max(0.0, rrect.brRadiusY);
    List<Offset> vertices = ;
    return ;
}
