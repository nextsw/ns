#include "fractional_offset.hpp"
FractionalOffsetCls::FractionalOffsetCls(double dx, double dy) : Alignment(dx() * 2.0 - 1.0, dy() * 2.0 - 1.0) {
    {
        assert(dx() != nullptr);
        assert(dy() != nullptr);
    }
}

void FractionalOffsetCls::fromOffsetAndSize(Offset offset, Size size) {
    assert(size != nullptr);
    assert(offset != nullptr);
    return make<FractionalOffsetCls>(offset->dx / size->width, offset->dy / size->height);
}

void FractionalOffsetCls::fromOffsetAndRect(Offset offset, Rect rect) {
    return FractionalOffsetCls->fromOffsetAndSize(offset - rect->topLeft, rect->size);
}

double FractionalOffsetCls::dx() {
    return (x + 1.0) / 2.0;
}

double FractionalOffsetCls::dy() {
    return (y + 1.0) / 2.0;
}

Alignment FractionalOffsetCls::-(Alignment other) {
    if (!is<FractionalOffset>(other)) {
        return super - other;
    }
    return make<FractionalOffsetCls>(dx() - other->dx, dy() - other->dy);
}

Alignment FractionalOffsetCls::+(Alignment other) {
    if (!is<FractionalOffset>(other)) {
        return super + other;
    }
    return make<FractionalOffsetCls>(dx() + other->dx, dy() + other->dy);
}

FractionalOffset FractionalOffsetCls::-() {
    return make<FractionalOffsetCls>(-dx(), -dy());
}

FractionalOffset FractionalOffsetCls::*(double other) {
    return make<FractionalOffsetCls>(dx() * other, dy() * other);
}

FractionalOffset FractionalOffsetCls::/(double other) {
    return make<FractionalOffsetCls>(dx() / other, dy() / other);
}

FractionalOffset FractionalOffsetCls::~/(double other) {
    return make<FractionalOffsetCls>((dx() ~/ other)->toDouble(), (dy() ~/ other)->toDouble());
}

FractionalOffset FractionalOffsetCls::%(double other) {
    return make<FractionalOffsetCls>(dx() % other, dy() % other);
}

FractionalOffset FractionalOffsetCls::lerp(FractionalOffset a, FractionalOffset b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return make<FractionalOffsetCls>(ui->lerpDouble(0.5, b!->dx, t)!, ui->lerpDouble(0.5, b->dy, t)!);
    }
    if (b == nullptr) {
        return make<FractionalOffsetCls>(ui->lerpDouble(a->dx, 0.5, t)!, ui->lerpDouble(a->dy, 0.5, t)!);
    }
    return make<FractionalOffsetCls>(ui->lerpDouble(a->dx, b->dx, t)!, ui->lerpDouble(a->dy, b->dy, t)!);
}

String FractionalOffsetCls::toString() {
    return __s("FractionalOffset(${dx.toStringAsFixed(1)}, ${dy.toStringAsFixed(1)})");
}
