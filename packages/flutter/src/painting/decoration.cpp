#include "decoration.hpp"
String Decoration::toStringShort() {
    return objectRuntimeType(this, "Decoration");
}

bool Decoration::debugAssertIsValid() {
    return true;
}

EdgeInsetsGeometry Decoration::padding() {
    return EdgeInsets.zero;
}

bool Decoration::isComplex() {
    return false;
}

Decoration Decoration::lerpFrom(Decoration a, double t) {
    return nullptr;
}

Decoration Decoration::lerpTo(Decoration b, double t) {
    return nullptr;
}

Decoration Decoration::lerp(Decoration a, Decoration b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!.lerpFrom(nullptr, t) ?? b;
    }
    if (b == nullptr) {
        return a.lerpTo(nullptr, t) ?? a;
    }
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    return b.lerpFrom(a, t) ?? a.lerpTo(b, t) ?? ( < 0.5? (a.lerpTo(nullptr, t * 2.0) ?? a) : (b.lerpFrom(nullptr, (t - 0.5) * 2.0) ?? b));
}

bool Decoration::hitTest(Offset position, Size size, TextDirection textDirection) {
    return true;
}

Path Decoration::getClipPath(Rect rect, TextDirection textDirection) {
    ;
}

void BoxPainter::dispose() {
}
