#include "quad.hpp"
Vector3 Quad::point0() {
    return _point0;
}

Vector3 Quad::point1() {
    return _point1;
}

Vector3 Quad::point2() {
    return _point2;
}

Vector3 Quad::point3() {
    return _point3;
}

Quad::Quad() {
    {
        _point0 = Vector3.zero();
        _point1 = Vector3.zero();
        _point2 = Vector3.zero();
        _point3 = Vector3.zero();
    }
}

void Quad::copy(Quad other)

void Quad::points(Vector3 point0, Vector3 point1, Vector3 point2, Vector3 point3)

void Quad::copyFrom(Quad other) {
    _point0.setFrom(other._point0);
    _point1.setFrom(other._point1);
    _point2.setFrom(other._point2);
    _point3.setFrom(other._point3);
}

void Quad::copyNormalInto(Vector3 normal) {
    Unknown v0 = ;
    ;
}

void Quad::copyTriangles(Triangle triangle0, Triangle triangle1) {
    triangle0._point0.setFrom(_point0);
    triangle0._point1.setFrom(_point1);
    triangle0._point2.setFrom(_point2);
    triangle1._point0.setFrom(_point0);
    triangle1._point1.setFrom(_point3);
    triangle1._point2.setFrom(_point2);
}

void Quad::transform(Matrix4 t) {
    ;
}

void Quad::translate(Vector3 offset) {
    _point0.add(offset);
    _point1.add(offset);
    _point2.add(offset);
    _point3.add(offset);
}
