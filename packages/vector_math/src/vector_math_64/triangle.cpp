#include "triangle.hpp"
Vector3 TriangleCls::point0() {
    return _point0;
}

Vector3 TriangleCls::point1() {
    return _point1;
}

Vector3 TriangleCls::point2() {
    return _point2;
}

TriangleCls::TriangleCls() {
    {
        _point0 = Vector3Cls->zero();
        _point1 = Vector3Cls->zero();
        _point2 = Vector3Cls->zero();
    }
}

void TriangleCls::copy(Triangle other)

void TriangleCls::points(Vector3 point0, Vector3 point1, Vector3 point2)

void TriangleCls::copyFrom(Triangle other) {
    _point0->setFrom(other->_point0);
    _point1->setFrom(other->_point1);
    _point2->setFrom(other->_point2);
}

void TriangleCls::copyNormalInto(Vector3 normal) {
    auto _c1 = point0()->clone();_c1.sub(point1());Unknown v0 = _c1;
    auto _c2 = normal;_c2.auto _c3 = setFrom(point2());_c3.auto _c4 = sub(point1());_c4.auto _c5 = crossInto(v0, normal);_c5.normalize();_c5;_c4;_c3;_c2;
}

void TriangleCls::transform(Matrix4 t) {
    auto _c1 = t;_c1.auto _c2 = transform3(_point0);_c2.auto _c3 = transform3(_point1);_c3.transform3(_point2);_c3;_c2;_c1;
}

void TriangleCls::translate(Vector3 offset) {
    _point0->add(offset);
    _point1->add(offset);
    _point2->add(offset);
}
