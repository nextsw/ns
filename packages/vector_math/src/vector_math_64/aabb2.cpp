#include "aabb2.hpp"
Vector2 Aabb2Cls::min() {
    return _min;
}

Vector2 Aabb2Cls::max() {
    return _max;
}

Vector2 Aabb2Cls::center() {
    return _c1;
}

Aabb2Cls::Aabb2Cls() {
    {
            auto _c1 = _min->clone();    _c1.auto _c2 = add(_max);    _c2.scale(0.5);    _c2;_min = Vector2Cls->zero();
        _max = Vector2Cls->zero();
    }
}

void Aabb2Cls::copy(Aabb2 other)

void Aabb2Cls::minMax(Vector2 min, Vector2 max)

void Aabb2Cls::centerAndHalfExtents(Vector2 center, Vector2 halfExtents) {
    return _c1;
}

void Aabb2Cls::fromBuffer(ByteBuffer buffer, int offset)

void Aabb2Cls::setCenterAndHalfExtents(Vector2 center, Vector2 halfExtents) {
    auto _c1 = make<Aabb2Cls>();_c1.setCenterAndHalfExtents(center, halfExtents);auto _c1 = _min;_c1.auto _c2 = setFrom(center);_c2.sub(halfExtents);_c2;_c1;
    auto _c3 = _max;_c3.auto _c4 = setFrom(center);_c4.add(halfExtents);_c4;_c3;
}

void Aabb2Cls::copyCenterAndHalfExtents(Vector2 center, Vector2 halfExtents) {
    auto _c1 = center;_c1.auto _c2 = setFrom(_min);_c2.auto _c3 = add(_max);_c3.scale(0.5);_c3;_c2;_c1;
    auto _c4 = halfExtents;_c4.auto _c5 = setFrom(_max);_c5.auto _c6 = sub(_min);_c6.scale(0.5);_c6;_c5;_c4;
}

void Aabb2Cls::copyFrom(Aabb2 other) {
    _min->setFrom(other->_min);
    _max->setFrom(other->_max);
}

void Aabb2Cls::transform(Matrix3 t) {
    _updateCenterAndHalfExtents();
    auto _c1 = t;_c1.auto _c2 = transform2(_center);_c2.absoluteRotate2(_halfExtents);_c2;_c1;
    auto _c3 = _min;_c3.auto _c4 = setFrom(_center);_c4.sub(_halfExtents);_c4;_c3;
    auto _c5 = _max;_c5.auto _c6 = setFrom(_center);_c6.add(_halfExtents);_c6;_c5;
}

void Aabb2Cls::rotate(Matrix3 t) {
    _updateCenterAndHalfExtents();
    t->absoluteRotate2(_halfExtents);
    auto _c1 = _min;_c1.auto _c2 = setFrom(_center);_c2.sub(_halfExtents);_c2;_c1;
    auto _c3 = _max;_c3.auto _c4 = setFrom(_center);_c4.add(_halfExtents);_c4;_c3;
}

Aabb2 Aabb2Cls::transformed(Matrix3 t, Aabb2 out) {
    return _c1;
}

Aabb2 Aabb2Cls::rotated(Matrix3 t, Aabb2 out) {
    return _c1;
}

void Aabb2Cls::hull(Aabb2 other) {
    auto _c1 = out;_c1.auto _c2 = copyFrom(this);_c2.transform(t);_c2;auto _c1 = out;_c1.auto _c2 = copyFrom(this);_c2.rotate(t);_c2;Vector2Cls->min(_min, other->_min, _min);
    Vector2Cls->max(_max, other->_max, _max);
}

void Aabb2Cls::hullPoint(Vector2 point) {
    Vector2Cls->min(_min, point, _min);
    Vector2Cls->max(_max, point, _max);
}

bool Aabb2Cls::containsAabb2(Aabb2 other) {
    Unknown otherMax = other->_max;
    Unknown otherMin = other->_min;
    return (_min->x < otherMin->x) && (_min->y < otherMin->y) && (_max->y > otherMax->y) && (_max->x > otherMax->x);
}

bool Aabb2Cls::containsVector2(Vector2 other) {
    return (_min->x < other->x) && (_min->y < other->y) && (_max->x > other->x) && (_max->y > other->y);
}

bool Aabb2Cls::intersectsWithAabb2(Aabb2 other) {
    Unknown otherMax = other->_max;
    Unknown otherMin = other->_min;
    return (_min->x <= otherMax->x) && (_min->y <= otherMax->y) && (_max->x >= otherMin->x) && (_max->y >= otherMin->y);
}

bool Aabb2Cls::intersectsWithVector2(Vector2 other) {
    return (_min->x <= other->x) && (_min->y <= other->y) && (_max->x >= other->x) && (_max->y >= other->y);
}

void Aabb2Cls::_updateCenterAndHalfExtents() {
    return copyCenterAndHalfExtents(_center, _halfExtents);
}
