#include "alignment.hpp"
AlignmentGeometry AlignmentGeometryCls::add(AlignmentGeometry other) {
    return make<_MixedAlignmentCls>(_x() + other->_x(), _start() + other->_start(), _y() + other->_y());
}

AlignmentGeometry AlignmentGeometryCls::lerp(AlignmentGeometry a, AlignmentGeometry b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b! * t;
    }
    if (b == nullptr) {
        return a * (1.0 - t);
    }
    if (is<Alignment>(a) && is<Alignment>(b)) {
        return AlignmentCls->lerp(a, b, t);
    }
    if (is<AlignmentDirectional>(a) && is<AlignmentDirectional>(b)) {
        return AlignmentDirectionalCls->lerp(a, b, t);
    }
    return make<_MixedAlignmentCls>(ui->lerpDouble(a->_x(), b->_x(), t)!, ui->lerpDouble(a->_start(), b->_start(), t)!, ui->lerpDouble(a->_y(), b->_y(), t)!);
}

String AlignmentGeometryCls::toString() {
    if (_start() == 0.0) {
        return AlignmentCls->_stringify(_x(), _y());
    }
    if (_x() == 0.0) {
        return AlignmentDirectionalCls->_stringify(_start(), _y());
    }
    return __s("%s$%s;");
}

bool AlignmentGeometryCls::==(Object other) {
    return is<AlignmentGeometry>(other) && other->_x == _x() && other->_start == _start() && other->_y == _y();
}

int AlignmentGeometryCls::hashCode() {
    return ObjectCls->hash(_x(), _start(), _y());
}

AlignmentCls::AlignmentCls(double x, double y) {
    {
        assert(x != nullptr);
        assert(y != nullptr);
    }
}

AlignmentGeometry AlignmentCls::add(AlignmentGeometry other) {
    if (is<Alignment>(other)) {
        return this + as<AlignmentCls>(other);
    }
    return super->add(other);
}

Alignment AlignmentCls::-(Alignment other) {
    return make<AlignmentCls>(x - other->x, y - other->y);
}

Alignment AlignmentCls::+(Alignment other) {
    return make<AlignmentCls>(x + other->x, y + other->y);
}

Alignment AlignmentCls::-() {
    return make<AlignmentCls>(-x, -y);
}

Alignment AlignmentCls::*(double other) {
    return make<AlignmentCls>(x * other, y * other);
}

Alignment AlignmentCls::/(double other) {
    return make<AlignmentCls>(x / other, y / other);
}

Alignment AlignmentCls::~/(double other) {
    return make<AlignmentCls>((x ~/ other)->toDouble(), (y ~/ other)->toDouble());
}

Alignment AlignmentCls::%(double other) {
    return make<AlignmentCls>(x % other, y % other);
}

Offset AlignmentCls::alongOffset(Offset other) {
    double centerX = other->dx() / 2.0;
    double centerY = other->dy() / 2.0;
    return make<OffsetCls>(centerX + x * centerX, centerY + y * centerY);
}

Offset AlignmentCls::alongSize(Size other) {
    double centerX = other->width() / 2.0;
    double centerY = other->height() / 2.0;
    return make<OffsetCls>(centerX + x * centerX, centerY + y * centerY);
}

Offset AlignmentCls::withinRect(Rect rect) {
    double halfWidth = rect->width() / 2.0;
    double halfHeight = rect->height() / 2.0;
    return make<OffsetCls>(rect->left + halfWidth + x * halfWidth, rect->top + halfHeight + y * halfHeight);
}

Rect AlignmentCls::inscribe(Size size, Rect rect) {
    double halfWidthDelta = (rect->width() - size->width()) / 2.0;
    double halfHeightDelta = (rect->height() - size->height()) / 2.0;
    return RectCls->fromLTWH(rect->left + halfWidthDelta + x * halfWidthDelta, rect->top + halfHeightDelta + y * halfHeightDelta, size->width(), size->height());
}

Alignment AlignmentCls::lerp(Alignment a, Alignment b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return make<AlignmentCls>(ui->lerpDouble(0.0, b!->x, t)!, ui->lerpDouble(0.0, b->y, t)!);
    }
    if (b == nullptr) {
        return make<AlignmentCls>(ui->lerpDouble(a->x, 0.0, t)!, ui->lerpDouble(a->y, 0.0, t)!);
    }
    return make<AlignmentCls>(ui->lerpDouble(a->x, b->x, t)!, ui->lerpDouble(a->y, b->y, t)!);
}

Alignment AlignmentCls::resolve(TextDirection direction) {
    return this;
}

String AlignmentCls::toString() {
    return _stringify(x, y);
}

double AlignmentCls::_x() {
    return x;
}

double AlignmentCls::_start() {
    return 0.0;
}

double AlignmentCls::_y() {
    return y;
}

String AlignmentCls::_stringify(double x, double y) {
    if (x == -1.0 && y == -1.0) {
        return __s("Alignment.topLeft");
    }
    if (x == 0.0 && y == -1.0) {
        return __s("Alignment.topCenter");
    }
    if (x == 1.0 && y == -1.0) {
        return __s("Alignment.topRight");
    }
    if (x == -1.0 && y == 0.0) {
        return __s("Alignment.centerLeft");
    }
    if (x == 0.0 && y == 0.0) {
        return __s("Alignment.center");
    }
    if (x == 1.0 && y == 0.0) {
        return __s("Alignment.centerRight");
    }
    if (x == -1.0 && y == 1.0) {
        return __s("Alignment.bottomLeft");
    }
    if (x == 0.0 && y == 1.0) {
        return __s("Alignment.bottomCenter");
    }
    if (x == 1.0 && y == 1.0) {
        return __s("Alignment.bottomRight");
    }
    return __s("Alignment(%s$%s;");
}

AlignmentDirectionalCls::AlignmentDirectionalCls(double start, double y) {
    {
        assert(start != nullptr);
        assert(y != nullptr);
    }
}

AlignmentGeometry AlignmentDirectionalCls::add(AlignmentGeometry other) {
    if (is<AlignmentDirectional>(other)) {
        return this + as<AlignmentDirectionalCls>(other);
    }
    return super->add(other);
}

AlignmentDirectional AlignmentDirectionalCls::-(AlignmentDirectional other) {
    return make<AlignmentDirectionalCls>(start - other->start, y - other->y);
}

AlignmentDirectional AlignmentDirectionalCls::+(AlignmentDirectional other) {
    return make<AlignmentDirectionalCls>(start + other->start, y + other->y);
}

AlignmentDirectional AlignmentDirectionalCls::-() {
    return make<AlignmentDirectionalCls>(-start, -y);
}

AlignmentDirectional AlignmentDirectionalCls::*(double other) {
    return make<AlignmentDirectionalCls>(start * other, y * other);
}

AlignmentDirectional AlignmentDirectionalCls::/(double other) {
    return make<AlignmentDirectionalCls>(start / other, y / other);
}

AlignmentDirectional AlignmentDirectionalCls::~/(double other) {
    return make<AlignmentDirectionalCls>((start ~/ other)->toDouble(), (y ~/ other)->toDouble());
}

AlignmentDirectional AlignmentDirectionalCls::%(double other) {
    return make<AlignmentDirectionalCls>(start % other, y % other);
}

AlignmentDirectional AlignmentDirectionalCls::lerp(AlignmentDirectional a, AlignmentDirectional b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return make<AlignmentDirectionalCls>(ui->lerpDouble(0.0, b!->start, t)!, ui->lerpDouble(0.0, b->y, t)!);
    }
    if (b == nullptr) {
        return make<AlignmentDirectionalCls>(ui->lerpDouble(a->start, 0.0, t)!, ui->lerpDouble(a->y, 0.0, t)!);
    }
    return make<AlignmentDirectionalCls>(ui->lerpDouble(a->start, b->start, t)!, ui->lerpDouble(a->y, b->y, t)!);
}

Alignment AlignmentDirectionalCls::resolve(TextDirection direction) {
    assert(direction != nullptr, __s("Cannot resolve %s)"));
    ;
}

String AlignmentDirectionalCls::toString() {
    return _stringify(start, y);
}

double AlignmentDirectionalCls::_x() {
    return 0.0;
}

double AlignmentDirectionalCls::_start() {
    return start;
}

double AlignmentDirectionalCls::_y() {
    return y;
}

String AlignmentDirectionalCls::_stringify(double start, double y) {
    if (start == -1.0 && y == -1.0) {
        return __s("AlignmentDirectional.topStart");
    }
    if (start == 0.0 && y == -1.0) {
        return __s("AlignmentDirectional.topCenter");
    }
    if (start == 1.0 && y == -1.0) {
        return __s("AlignmentDirectional.topEnd");
    }
    if (start == -1.0 && y == 0.0) {
        return __s("AlignmentDirectional.centerStart");
    }
    if (start == 0.0 && y == 0.0) {
        return __s("AlignmentDirectional.center");
    }
    if (start == 1.0 && y == 0.0) {
        return __s("AlignmentDirectional.centerEnd");
    }
    if (start == -1.0 && y == 1.0) {
        return __s("AlignmentDirectional.bottomStart");
    }
    if (start == 0.0 && y == 1.0) {
        return __s("AlignmentDirectional.bottomCenter");
    }
    if (start == 1.0 && y == 1.0) {
        return __s("AlignmentDirectional.bottomEnd");
    }
    return __s("AlignmentDirectional(%s$%s;");
}

_MixedAlignment _MixedAlignmentCls::-() {
    return make<_MixedAlignmentCls>(-_x, -_start, -_y);
}

_MixedAlignment _MixedAlignmentCls::*(double other) {
    return make<_MixedAlignmentCls>(_x * other, _start * other, _y * other);
}

_MixedAlignment _MixedAlignmentCls::/(double other) {
    return make<_MixedAlignmentCls>(_x / other, _start / other, _y / other);
}

_MixedAlignment _MixedAlignmentCls::~/(double other) {
    return make<_MixedAlignmentCls>((_x ~/ other)->toDouble(), (_start ~/ other)->toDouble(), (_y ~/ other)->toDouble());
}

_MixedAlignment _MixedAlignmentCls::%(double other) {
    return make<_MixedAlignmentCls>(_x % other, _start % other, _y % other);
}

Alignment _MixedAlignmentCls::resolve(TextDirection direction) {
    assert(direction != nullptr, __s("Cannot resolve %s)"));
    ;
}

TextAlignVerticalCls::TextAlignVerticalCls(double y) {
    {
        assert(y != nullptr);
        assert(y >= -1.0 && y <= 1.0);
    }
}

String TextAlignVerticalCls::toString() {
    return __s("%s$%s;");
}
