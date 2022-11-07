#include "aabb2.hpp"
Vector2 Aabb2::min() {
    return _min;
}

Vector2 Aabb2::max() {
    return _max;
}

Vector2 Aabb2::center() {
    return ;
}

Aabb2::Aabb2() {
    {
        _min = Vector2.zero();
        _max = Vector2.zero();
    }
}

void Aabb2::copy(Aabb2 other)

void Aabb2::minMax(Vector2 max, Vector2 min)

void Aabb2::centerAndHalfExtents(Vector2 center, Vector2 halfExtents) {
    return ;
}

void Aabb2::fromBuffer(ByteBuffer buffer, int offset)

void Aabb2::setCenterAndHalfExtents(Vector2 center, Vector2 halfExtents) {
    ;
    ;
}

void Aabb2::copyCenterAndHalfExtents(Vector2 center, Vector2 halfExtents) {
    ;
    ;
}

void Aabb2::copyFrom(Aabb2 other) {
    _min.setFrom(other._min);
    _max.setFrom(other._max);
}

void Aabb2::transform(Matrix3 t) {
    _updateCenterAndHalfExtents();
    ;
    ;
    ;
}

void Aabb2::rotate(Matrix3 t) {
    _updateCenterAndHalfExtents();
    t.absoluteRotate2(_halfExtents);
    ;
    ;
}

Aabb2 Aabb2::transformed(Aabb2 out, Matrix3 t) {
    return ;
}

Aabb2 Aabb2::rotated(Aabb2 out, Matrix3 t) {
    return ;
}

void Aabb2::hull(Aabb2 other) {
    Vector2.min(_min, other._min, _min);
    Vector2.max(_max, other._max, _max);
}

void Aabb2::hullPoint(Vector2 point) {
    Vector2.min(_min, point, _min);
    Vector2.max(_max, point, _max);
}

bool Aabb2::containsAabb2(Aabb2 other) {
    Unknown otherMax = other._max;
    Unknown otherMin = other._min;
    return (_min.x < otherMin.x) && (_min.y < otherMin.y) && (_max.y > otherMax.y) && (_max.x > otherMax.x);
}

bool Aabb2::containsVector2(Vector2 other) {
    return (_min.x < other.x) && (_min.y < other.y) && (_max.x > other.x) && (_max.y > other.y);
}

bool Aabb2::intersectsWithAabb2(Aabb2 other) {
    Unknown otherMax = other._max;
    Unknown otherMin = other._min;
    return (_min.x <= otherMax.x) && (_min.y <= otherMax.y) && (_max.x >= otherMin.x) && (_max.y >= otherMin.y);
}

bool Aabb2::intersectsWithVector2(Vector2 other) {
    return (_min.x <= other.x) && (_min.y <= other.y) && (_max.x >= other.x) && (_max.y >= other.y);
}

void Aabb2::_updateCenterAndHalfExtents() {
    return copyCenterAndHalfExtents(_center, _halfExtents);
}
