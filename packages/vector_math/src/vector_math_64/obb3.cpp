#include "obb3.hpp"
Vector3 Obb3Cls::center() {
    return _center;
}

Vector3 Obb3Cls::halfExtents() {
    return _halfExtents;
}

Vector3 Obb3Cls::axis0() {
    return _axis0;
}

Vector3 Obb3Cls::axis1() {
    return _axis1;
}

Vector3 Obb3Cls::axis2() {
    return _axis2;
}

Obb3Cls::Obb3Cls() {
    {
        _center = Vector3Cls->zero();
        _halfExtents = Vector3Cls->zero();
        _axis0 = make<Vector3Cls>(1.0, 0.0, 0.0);
        _axis1 = make<Vector3Cls>(0.0, 1.0, 0.0);
        _axis2 = make<Vector3Cls>(0.0, 0.0, 1.0);
    }
}

void Obb3Cls::copy(Obb3 other)

void Obb3Cls::centerExtentsAxes(Vector3 center, Vector3 halfExtents, Vector3 axis0, Vector3 axis1, Vector3 axis2)

void Obb3Cls::copyFrom(Obb3 other) {
    _center->setFrom(other->_center);
    _halfExtents->setFrom(other->_halfExtents);
    _axis0->setFrom(other->_axis0);
    _axis1->setFrom(other->_axis1);
    _axis2->setFrom(other->_axis2);
}

void Obb3Cls::copyInto(Obb3 other) {
    other->_center->setFrom(_center);
    other->_halfExtents->setFrom(_halfExtents);
    other->_axis0->setFrom(_axis0);
    other->_axis1->setFrom(_axis1);
    other->_axis2->setFrom(_axis2);
}

void Obb3Cls::resetRotation() {
    _axis0->setValues(1.0, 0.0, 0.0);
    _axis1->setValues(0.0, 1.0, 0.0);
    _axis2->setValues(0.0, 0.0, 1.0);
}

void Obb3Cls::translate(Vector3 offset) {
    _center->add(offset);
}

void Obb3Cls::rotate(Matrix3 t) {
    auto _c1 = t;_c1.auto _c2 = transform(auto _c3 = _axis0;_c3.scale(_halfExtents->x);_c3);_c2.auto _c4 = transform(auto _c5 = _axis1;_c5.scale(_halfExtents->y);_c5);_c4.transform(auto _c6 = _axis2;_c6.scale(_halfExtents->z);_c6);_c4;_c2;_c1;
    auto _c7 = _halfExtents;_c7.x = auto _c8 = _axis0->normalize();_c8.y = auto _c9 = _axis1->normalize();_c9.z = _axis2->normalize();_c9;_c8;_c7;
}

void Obb3Cls::transform(Matrix4 t) {
    auto _c1 = t;_c1.auto _c2 = transform3(_center);_c2.auto _c3 = rotate3(auto _c4 = _axis0;_c4.scale(_halfExtents->x);_c4);_c3.auto _c5 = rotate3(auto _c6 = _axis1;_c6.scale(_halfExtents->y);_c6);_c5.rotate3(auto _c7 = _axis2;_c7.scale(_halfExtents->z);_c7);_c5;_c3;_c2;_c1;
    auto _c8 = _halfExtents;_c8.x = auto _c9 = _axis0->normalize();_c9.y = auto _c10 = _axis1->normalize();_c10.z = _axis2->normalize();_c10;_c9;_c8;
}

void Obb3Cls::copyCorner(int cornerIndex, Vector3 corner) {
    assert(cornerIndex >= 0 ||  < 8);
    corner->setFrom(_center);
    ;
}

void Obb3Cls::closestPointTo(Vector3 p, Vector3 q) {
    auto d = p - _center;
    q->setFrom(_center);
    auto dist = d->dot(_axis0);
    dist = dist->clamp(-_halfExtents->x, _halfExtents->x)->toDouble();
    q->addScaled(_axis0, dist);
    dist = d->dot(_axis1);
    dist = dist->clamp(-_halfExtents->y, _halfExtents->y)->toDouble();
    q->addScaled(_axis1, dist);
    dist = d->dot(_axis2);
    dist = dist->clamp(-_halfExtents->z, _halfExtents->z)->toDouble();
    q->addScaled(_axis2, dist);
}

bool Obb3Cls::intersectsWithObb3(Obb3 other, double epsilon) {
    auto _c1 = _r;_c1.auto _c2 = setEntry(0, 0, _axis0->dot(other->_axis0));_c2.auto _c3 = setEntry(1, 0, _axis1->dot(other->_axis0));_c3.auto _c4 = setEntry(2, 0, _axis2->dot(other->_axis0));_c4.auto _c5 = setEntry(0, 1, _axis0->dot(other->_axis1));_c5.auto _c6 = setEntry(1, 1, _axis1->dot(other->_axis1));_c6.auto _c7 = setEntry(2, 1, _axis2->dot(other->_axis1));_c7.auto _c8 = setEntry(0, 2, _axis0->dot(other->_axis2));_c8.auto _c9 = setEntry(1, 2, _axis1->dot(other->_axis2));_c9.setEntry(2, 2, _axis2->dot(other->_axis2));_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
    auto _c10 = _t;_c10.auto _c11 = setFrom(other->_center);_c11.sub(_center);_c11;_c10;
    _t->setValues(_t->dot(_axis0), _t->dot(_axis1), _t->dot(_axis2));
    for (;  < 3; i++) {
        for (;  < 3; j++) {
            _absR->setEntry(i, j, _r->entry(i, j)->abs() + epsilon);
        }
    }
    double ra;
    double rb;
    for (;  < 3; i++) {
        ra = _halfExtents[i];
        rb = other->_halfExtents[0] * _absR->entry(i, 0) + other->_halfExtents[1] * _absR->entry(i, 1) + other->_halfExtents[2] * _absR->entry(i, 2);
        if (_t[i]->abs() > ra + rb) {
            return false;
        }
    }
    for (;  < 3; i++) {
        ra = _halfExtents[0] * _absR->entry(0, i) + _halfExtents[1] * _absR->entry(1, i) + _halfExtents[2] * _absR->entry(2, i);
        rb = other->_halfExtents[i];
        if ((_t[0] * _r->entry(0, i) + _t[1] * _r->entry(1, i) + _t[2] * _r->entry(2, i))->abs() > ra + rb) {
            return false;
        }
    }
    ra = _halfExtents[1] * _absR->entry(2, 0) + _halfExtents[2] * _absR->entry(1, 0);
    rb = other->_halfExtents[1] * _absR->entry(0, 2) + other->_halfExtents[2] * _absR->entry(0, 1);
    if ((_t[2] * _r->entry(1, 0) - _t[1] * _r->entry(2, 0))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[1] * _absR->entry(2, 1) + _halfExtents[2] * _absR->entry(1, 1);
    rb = other->_halfExtents[0] * _absR->entry(0, 2) + other->_halfExtents[2] * _absR->entry(0, 0);
    if ((_t[2] * _r->entry(1, 1) - _t[1] * _r->entry(2, 1))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[1] * _absR->entry(2, 2) + _halfExtents[2] * _absR->entry(1, 2);
    rb = other->_halfExtents[0] * _absR->entry(0, 1) + other->_halfExtents[1] * _absR->entry(0, 0);
    if ((_t[2] * _r->entry(1, 2) - _t[1] * _r->entry(2, 2))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR->entry(2, 0) + _halfExtents[2] * _absR->entry(0, 0);
    rb = other->_halfExtents[1] * _absR->entry(1, 2) + other->_halfExtents[2] * _absR->entry(1, 1);
    if ((_t[0] * _r->entry(2, 0) - _t[2] * _r->entry(0, 0))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR->entry(2, 1) + _halfExtents[2] * _absR->entry(0, 1);
    rb = other->_halfExtents[0] * _absR->entry(1, 2) + other->_halfExtents[2] * _absR->entry(1, 0);
    if ((_t[0] * _r->entry(2, 1) - _t[2] * _r->entry(0, 1))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR->entry(2, 2) + _halfExtents[2] * _absR->entry(0, 2);
    rb = other->_halfExtents[0] * _absR->entry(1, 1) + other->_halfExtents[1] * _absR->entry(1, 0);
    if ((_t[0] * _r->entry(2, 2) - _t[2] * _r->entry(0, 2))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR->entry(1, 0) + _halfExtents[1] * _absR->entry(0, 0);
    rb = other->_halfExtents[1] * _absR->entry(2, 2) + other->_halfExtents[2] * _absR->entry(2, 1);
    if ((_t[1] * _r->entry(0, 0) - _t[0] * _r->entry(1, 0))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR->entry(1, 1) + _halfExtents[1] * _absR->entry(0, 1);
    rb = other->_halfExtents[0] * _absR->entry(2, 2) + other->_halfExtents[2] * _absR->entry(2, 0);
    if ((_t[1] * _r->entry(0, 1) - _t[0] * _r->entry(1, 1))->abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR->entry(1, 2) + _halfExtents[1] * _absR->entry(0, 2);
    rb = other->_halfExtents[0] * _absR->entry(2, 1) + other->_halfExtents[1] * _absR->entry(2, 0);
    if ((_t[1] * _r->entry(0, 2) - _t[0] * _r->entry(1, 2))->abs() > ra + rb) {
        return false;
    }
    return true;
}

bool Obb3Cls::intersectsWithTriangle(Triangle other, IntersectionResult result) {
    _triangle->copyFrom(other);
    auto _c1 = _triangle->point0;_c1.auto _c2 = sub(_center);_c2.setValues(_triangle->point0->dot(axis0()), _triangle->point0->dot(axis1()), _triangle->point0->dot(axis2()));_c2;_c1;
    auto _c3 = _triangle->point1;_c3.auto _c4 = sub(_center);_c4.setValues(_triangle->point1->dot(axis0()), _triangle->point1->dot(axis1()), _triangle->point1->dot(axis2()));_c4;_c3;
    auto _c5 = _triangle->point2;_c5.auto _c6 = sub(_center);_c6.setValues(_triangle->point2->dot(axis0()), _triangle->point2->dot(axis1()), _triangle->point2->dot(axis2()));_c6;_c5;
    _aabb3->setCenterAndHalfExtents(_zeroVector, _halfExtents);
    return _aabb3->intersectsWithTriangle(_triangle, result);
}

bool Obb3Cls::intersectsWithVector3(Vector3 other) {
    auto _c1 = _vector;_c1.auto _c2 = setFrom(other);_c2.auto _c3 = sub(_center);_c3.setValues(_vector->dot(axis0()), _vector->dot(axis1()), _vector->dot(axis2()));_c3;_c2;_c1;
    _aabb3->setCenterAndHalfExtents(_zeroVector, _halfExtents);
    return _aabb3->intersectsWithVector3(_vector);
}

bool Obb3Cls::intersectsWithQuad(Quad other, IntersectionResult result) {
    other->copyTriangles(_quadTriangle0, _quadTriangle1);
    return intersectsWithTriangle(_quadTriangle0, result) || intersectsWithTriangle(_quadTriangle1, result);
}
