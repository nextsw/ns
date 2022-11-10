#include "sphere.hpp"
Vector3 SphereCls::center() {
    return _center;
}

SphereCls::SphereCls() {
    {
        _center = Vector3Cls->zero();
        radius = 0.0;
    }
}

void SphereCls::copy(Sphere other)

void SphereCls::centerRadius(Vector3 center, double radius)

void SphereCls::copyFrom(Sphere other) {
    _center->setFrom(other->_center);
    radius = other->radius;
}

bool SphereCls::containsVector3(Vector3 other) {
    return other->distanceToSquared(center()) < radius * radius;
}

bool SphereCls::intersectsWithVector3(Vector3 other) {
    return other->distanceToSquared(center()) <= radius * radius;
}

bool SphereCls::intersectsWithSphere(Sphere other) {
    Unknown radiusSum = radius + other->radius;
    return other->center->distanceToSquared(center()) <= (radiusSum * radiusSum);
}
