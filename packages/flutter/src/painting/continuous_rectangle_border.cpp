#include "continuous_rectangle_border.hpp"
ContinuousRectangleBorder::ContinuousRectangleBorder(BorderRadiusGeometry borderRadius, Unknown) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
    }
}

EdgeInsetsGeometry ContinuousRectangleBorder::dimensions() {
    return EdgeInsets.all(side.width);
}

ShapeBorder ContinuousRectangleBorder::scale(double t) {
    return ContinuousRectangleBorder(side.scale(t), borderRadius * t);
}

ShapeBorder ContinuousRectangleBorder::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is ContinuousRectangleBorder) {
        return ContinuousRectangleBorder(BorderSide.lerp(a.side, side, t), BorderRadiusGeometry.lerp(a.borderRadius, borderRadius, t)!);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder ContinuousRectangleBorder::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (b is ContinuousRectangleBorder) {
        return ContinuousRectangleBorder(BorderSide.lerp(side, b.side, t), BorderRadiusGeometry.lerp(borderRadius, b.borderRadius, t)!);
    }
    return super.lerpTo(b, t);
}

Path ContinuousRectangleBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    return _getPath(borderRadius.resolve(textDirection).toRRect(rect).deflate(side.width));
}

Path ContinuousRectangleBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return _getPath(borderRadius.resolve(textDirection).toRRect(rect));
}

ContinuousRectangleBorder ContinuousRectangleBorder::copyWith(BorderRadiusGeometry borderRadius, BorderSide side) {
    return ContinuousRectangleBorder(side ?? this.side, borderRadius ?? this.borderRadius);
}

void ContinuousRectangleBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    if (rect.isEmpty) {
        return;
    }
    ;
}

bool ContinuousRectangleBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ContinuousRectangleBorder && other.side == side && other.borderRadius == borderRadius;
}

int ContinuousRectangleBorder::hashCode() {
    return Object.hash(side, borderRadius);
}

String ContinuousRectangleBorder::toString() {
    return "${objectRuntimeType(this, 'ContinuousRectangleBorder')}($side, $borderRadius)";
}

double ContinuousRectangleBorder::_clampToShortest(RRect rrect, double value) {
    return value > rrect.shortestSide? rrect.shortestSide : value;
}

Path ContinuousRectangleBorder::_getPath(RRect rrect) {
    double left = rrect.left;
    double right = rrect.right;
    double top = rrect.top;
    double bottom = rrect.bottom;
    double tlRadiusX = math.max(0.0, _clampToShortest(rrect, rrect.tlRadiusX));
    double tlRadiusY = math.max(0.0, _clampToShortest(rrect, rrect.tlRadiusY));
    double trRadiusX = math.max(0.0, _clampToShortest(rrect, rrect.trRadiusX));
    double trRadiusY = math.max(0.0, _clampToShortest(rrect, rrect.trRadiusY));
    double blRadiusX = math.max(0.0, _clampToShortest(rrect, rrect.blRadiusX));
    double blRadiusY = math.max(0.0, _clampToShortest(rrect, rrect.blRadiusY));
    double brRadiusX = math.max(0.0, _clampToShortest(rrect, rrect.brRadiusX));
    double brRadiusY = math.max(0.0, _clampToShortest(rrect, rrect.brRadiusY));
    return ;
}
