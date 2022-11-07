#include "box_shadow.hpp"
Paint BoxShadow::toPaint() {
    Paint result = ;
    assert(());
    return result;
}

BoxShadow BoxShadow::scale(double factor) {
    return BoxShadow(color, offset * factor, blurRadius * factor, spreadRadius * factor, blurStyle);
}

BoxShadow BoxShadow::lerp(BoxShadow a, BoxShadow b, double t) {
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
    return BoxShadow(Color.lerp(a.color, b.color, t)!, Offset.lerp(a.offset, b.offset, t)!, ui.lerpDouble(a.blurRadius, b.blurRadius, t)!, ui.lerpDouble(a.spreadRadius, b.spreadRadius, t)!, a.blurStyle == BlurStyle.normal? b.blurStyle : a.blurStyle);
}

List<BoxShadow> BoxShadow::lerpList(List<BoxShadow> a, List<BoxShadow> b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    a = ;
    b = ;
    int commonLength = math.min(a.length, b.length);
    return ;
}

bool BoxShadow::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is BoxShadow && other.color == color && other.offset == offset && other.blurRadius == blurRadius && other.spreadRadius == spreadRadius && other.blurStyle == blurStyle;
}

int BoxShadow::hashCode() {
    return Object.hash(color, offset, blurRadius, spreadRadius, blurStyle);
}

String BoxShadow::toString() {
    return "BoxShadow($color, $offset, ${debugFormatDouble(blurRadius)}, ${debugFormatDouble(spreadRadius)}, $blurStyle)";
}
