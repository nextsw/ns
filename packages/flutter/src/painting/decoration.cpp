#include "decoration.hpp"
String DecorationCls::toStringShort() {
    return objectRuntimeType(this, "Decoration");
}

bool DecorationCls::debugAssertIsValid() {
    return true;
}

EdgeInsetsGeometry DecorationCls::padding() {
    return EdgeInsetsCls::zero;
}

bool DecorationCls::isComplex() {
    return false;
}

Decoration DecorationCls::lerpFrom(Decoration a, double t) {
    return nullptr;
}

Decoration DecorationCls::lerpTo(Decoration b, double t) {
    return nullptr;
}

Decoration DecorationCls::lerp(Decoration a, Decoration b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->lerpFrom(nullptr, t) ?? b;
    }
    if (b == nullptr) {
        return a->lerpTo(nullptr, t) ?? a;
    }
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    return b->lerpFrom(a, t) ?? a->lerpTo(b, t) ?? ( < 0.5? (a->lerpTo(nullptr, t * 2.0) ?? a) : (b->lerpFrom(nullptr, (t - 0.5) * 2.0) ?? b));
}

bool DecorationCls::hitTest(Offset position, Size size, TextDirection textDirection) {
    return true;
}

Path DecorationCls::getClipPath(Rect rect, TextDirection textDirection) {
    ;
}

void BoxPainterCls::dispose() {
}
