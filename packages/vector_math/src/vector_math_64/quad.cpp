#include "quad.hpp"
Vector3 QuadCls::point0() {
    return _point0;
}

Vector3 QuadCls::point1() {
    return _point1;
}

Vector3 QuadCls::point2() {
    return _point2;
}

Vector3 QuadCls::point3() {
    return _point3;
}

QuadCls::QuadCls() {
    {
        _point0 = Vector3Cls->zero();
        _point1 = Vector3Cls->zero();
        _point2 = Vector3Cls->zero();
        _point3 = Vector3Cls->zero();
    }
}

void QuadCls::copy(Quad other)

void QuadCls::points(Vector3 point0, Vector3 point1, Vector3 point2, Vector3 point3)

void QuadCls::copyFrom(Quad other) {
    _point0->setFrom(other->_point0);
    _point1->setFrom(other->_point1);
    _point2->setFrom(other->_point2);
    _point3->setFrom(other->_point3);
}

void QuadCls::copyNormalInto(Vector3 normal) {
    auto _c1 = _point0->clone();_c1.sub(_point1);auto v0 = _c1;
    auto _c2 = normal;_c2.auto _c3 = setFrom(_point2);_c3.auto _c4 = sub(_point1);_c4.auto _c5 = crossInto(v0, normal);_c5.normalize();_c5;_c4;_c3;_c2;
}

void QuadCls::copyTriangles(Triangle triangle0, Triangle triangle1) {
    triangle0->_point0->setFrom(_point0);
    triangle0->_point1->setFrom(_point1);
    triangle0->_point2->setFrom(_point2);
    triangle1->_point0->setFrom(_point0);
    triangle1->_point1->setFrom(_point3);
    triangle1->_point2->setFrom(_point2);
}

void QuadCls::transform(Matrix4 t) {
    auto _c1 = t;_c1.auto _c2 = transform3(_point0);_c2.auto _c3 = transform3(_point1);_c3.auto _c4 = transform3(_point2);_c4.transform3(_point3);_c4;_c3;_c2;_c1;
}

void QuadCls::translate(Vector3 offset) {
    _point0->add(offset);
    _point1->add(offset);
    _point2->add(offset);
    _point3->add(offset);
}
