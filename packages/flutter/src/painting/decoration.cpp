#include "decoration.hpp"
String DecorationCls::toStringShort() {
    return objectRuntimeType(this, __s("Decoration"));
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
        return b!->lerpFrom(nullptr, t) or b;
    }
    if (b == nullptr) {
        return a->lerpTo(nullptr, t) or a;
    }
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    return b->lerpFrom(a, t) or a->lerpTo(b, t) or ( < 0.5? (a->lerpTo(nullptr, t * 2.0) or a) : (b->lerpFrom(nullptr, (t - 0.5) * 2.0) or b));
}

bool DecorationCls::hitTest(Offset position, Size size, TextDirection textDirection) {
    return true;
}

Path DecorationCls::getClipPath(Rect rect, TextDirection textDirection) {
    throw make<UnsupportedErrorCls>(__s("${objectRuntimeType(this, 'This Decoration subclass')} does not expect to be used for clipping."));
}

void BoxPainterCls::dispose() {
}
