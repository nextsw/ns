#include "box_shadow.hpp"
Paint BoxShadowCls::toPaint() {
    auto _c1 = make<PaintCls>();_c1.color = auto _c2 = color;_c2.maskFilter = MaskFilterCls->blur(blurStyle, blurSigma());_c2;Paint result = _c1;
    assert([=] () {
        if (debugDisableShadows) {
            result->maskFilter() = nullptr;
        }
        return true;
    }());
    return result;
}

BoxShadow BoxShadowCls::scale(double factor) {
    return make<BoxShadowCls>(color, offset * factor, blurRadius * factor, spreadRadius * factor, blurStyle);
}

BoxShadow BoxShadowCls::lerp(BoxShadow a, BoxShadow b, double t) {
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
    return make<BoxShadowCls>(ColorCls->lerp(a->color, b->color, t)!, OffsetCls->lerp(a->offset, b->offset, t)!, ui->lerpDouble(a->blurRadius, b->blurRadius, t)!, ui->lerpDouble(a->spreadRadius, b->spreadRadius, t)!, a->blurStyle == BlurStyleCls::normal? b->blurStyle : a->blurStyle);
}

List<BoxShadow> BoxShadowCls::lerpList(List<BoxShadow> a, List<BoxShadow> b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    a |= makeList();
    b |= makeList();
    int commonLength = math->min(a->length(), b->length());
    List<BoxShadow> list1 = make<ListCls<>>();for (;  < commonLength; i += 1) {        ;    }{    list1.add(ArrayItem);}for (;  < a->length(); i += 1) {        ;    }{    list1.add(ArrayItem);}for (;  < b->length(); i += 1) {        ;    }{    list1.add(ArrayItem);}return list1;
}

bool BoxShadowCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<BoxShadow>(other) && other->color == color && other->offset == offset && other->blurRadius == blurRadius && other->spreadRadius == spreadRadius && other->blurStyle == blurStyle;
}

int BoxShadowCls::hashCode() {
    return ObjectCls->hash(color, offset, blurRadius, spreadRadius, blurStyle);
}

String BoxShadowCls::toString() {
    return __s("BoxShadow(%s$%s$%s$%s$%s;");
}
