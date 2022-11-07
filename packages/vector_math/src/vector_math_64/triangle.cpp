#include "triangle.hpp"
Vector3 Triangle::point0() {
    return _point0;
}

Vector3 Triangle::point1() {
    return _point1;
}

Vector3 Triangle::point2() {
    return _point2;
}

Triangle::Triangle() {
    {
        _point0 = Vector3.zero();
        _point1 = Vector3.zero();
        _point2 = Vector3.zero();
    }
}

void Triangle::copy(Triangle other)

void Triangle::points(Vector3 point0, Vector3 point1, Vector3 point2)

void Triangle::copyFrom(Triangle other) {
    _point0.setFrom(other._point0);
    _point1.setFrom(other._point1);
    _point2.setFrom(other._point2);
}

void Triangle::copyNormalInto(Vector3 normal) {
    Unknown v0 = ;
    ;
}

void Triangle::transform(Matrix4 t) {
    ;
}

void Triangle::translate(Vector3 offset) {
    _point0.add(offset);
    _point1.add(offset);
    _point2.add(offset);
}
