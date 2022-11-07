#include "fractional_offset.hpp"
FractionalOffset::FractionalOffset(double dx, double dy) {
    {
        assert(dx != nullptr);
        assert(dy != nullptr);
        super(dx * 2.0 - 1.0, dy * 2.0 - 1.0);
    }
}

void FractionalOffset::fromOffsetAndSize(Offset offset, Size size) {
    assert(size != nullptr);
    assert(offset != nullptr);
    return FractionalOffset(offset.dx / size.width, offset.dy / size.height);
}

void FractionalOffset::fromOffsetAndRect(Offset offset, Rect rect) {
    return FractionalOffset.fromOffsetAndSize(offset - rect.topLeft, rect.size);
}

double FractionalOffset::dx() {
    return (x + 1.0) / 2.0;
}

double FractionalOffset::dy() {
    return (y + 1.0) / 2.0;
}

Alignment FractionalOffset::-(Alignment other) {
    if (other is! FractionalOffset) {
        return super - other;
    }
    return FractionalOffset(dx - other.dx, dy - other.dy);
}

Alignment FractionalOffset::+(Alignment other) {
    if (other is! FractionalOffset) {
        return super + other;
    }
    return FractionalOffset(dx + other.dx, dy + other.dy);
}

FractionalOffset FractionalOffset::-() {
    return FractionalOffset(-dx, -dy);
}

FractionalOffset FractionalOffset::*(double other) {
    return FractionalOffset(dx * other, dy * other);
}

FractionalOffset FractionalOffset::/(double other) {
    return FractionalOffset(dx / other, dy / other);
}

FractionalOffset FractionalOffset::~/(double other) {
    return FractionalOffset((dx ~/ other).toDouble(), (dy ~/ other).toDouble());
}

FractionalOffset FractionalOffset::%(double other) {
    return FractionalOffset(dx % other, dy % other);
}

FractionalOffset FractionalOffset::lerp(FractionalOffset a, FractionalOffset b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return FractionalOffset(ui.lerpDouble(0.5, b!.dx, t)!, ui.lerpDouble(0.5, b.dy, t)!);
    }
    if (b == nullptr) {
        return FractionalOffset(ui.lerpDouble(a.dx, 0.5, t)!, ui.lerpDouble(a.dy, 0.5, t)!);
    }
    return FractionalOffset(ui.lerpDouble(a.dx, b.dx, t)!, ui.lerpDouble(a.dy, b.dy, t)!);
}

String FractionalOffset::toString() {
    return "FractionalOffset(${dx.toStringAsFixed(1)}, ${dy.toStringAsFixed(1)})";
}
