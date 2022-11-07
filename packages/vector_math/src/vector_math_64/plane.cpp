#include "plane.hpp"
void Plane::intersection(Plane a, Plane b, Plane c, Vector3 result) {
    Unknown cross = Vector3.zero();
    b.normal.crossInto(c.normal, cross);
    Unknown f = -a.normal.dot(cross);
    Unknown v1 = cross.scaled(a.constant);
    c.normal.crossInto(a.normal, cross);
    Unknown v2 = cross.scaled(b.constant);
    a.normal.crossInto(b.normal, cross);
    Unknown v3 = cross.scaled(c.constant);
    ;
}

Vector3 Plane::normal() {
    return _normal;
}

Plane::Plane() {
    {
        _normal = Vector3.zero();
        constant = 0.0;
    }
}

void Plane::copy(Plane other)

void Plane::components(double constant, double x, double y, double z)

void Plane::normalconstant(double constant, Vector3 normal_)

void Plane::copyFrom(Plane o) {
    _normal.setFrom(o._normal);
    constant = o.constant;
}

void Plane::setFromComponents(double w, double x, double y, double z) {
    _normal.setValues(x, y, z);
    constant = w;
}

void Plane::normalize() {
    Unknown inverseLength = 1.0 / normal.length;
    _normal.scale(inverseLength);
    constant = inverseLength;
}

double Plane::distanceToVector3(Vector3 point) {
    return _normal.dot(point) + constant;
}
