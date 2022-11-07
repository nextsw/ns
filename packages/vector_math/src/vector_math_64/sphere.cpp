#include "sphere.hpp"
Vector3 Sphere::center() {
    return _center;
}

Sphere::Sphere() {
    {
        _center = Vector3.zero();
        radius = 0.0;
    }
}

void Sphere::copy(Sphere other)

void Sphere::centerRadius(Vector3 center, double radius)

void Sphere::copyFrom(Sphere other) {
    _center.setFrom(other._center);
    radius = other.radius;
}

bool Sphere::containsVector3(Vector3 other) {
    return other.distanceToSquared(center) < radius * radius;
}

bool Sphere::intersectsWithVector3(Vector3 other) {
    return other.distanceToSquared(center) <= radius * radius;
}

bool Sphere::intersectsWithSphere(Sphere other) {
    Unknown radiusSum = radius + other.radius;
    return other.center.distanceToSquared(center) <= (radiusSum * radiusSum);
}
