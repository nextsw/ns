#include "aabb3.hpp"
Vector3 Aabb3Cls::min() {
    return _min;
}

Vector3 Aabb3Cls::max() {
    return _max;
}

Vector3 Aabb3Cls::center() {
    return _c1;
}

Aabb3Cls::Aabb3Cls() {
    {
            auto _c1 = _min->clone();    _c1.auto _c2 = add(_max);    _c2.scale(0.5);    _c2;_min = Vector3Cls->zero();
        _max = Vector3Cls->zero();
    }
}

void Aabb3Cls::copy(Aabb3 other)

void Aabb3Cls::minMax(Vector3 max, Vector3 min)

void Aabb3Cls::fromSphere(Sphere sphere) {
    return _c1;
}

void Aabb3Cls::fromTriangle(Triangle triangle) {
    return _c1;
}

void Aabb3Cls::fromQuad(Quad quad) {
    return _c1;
}

void Aabb3Cls::fromObb3(Obb3 obb) {
    return _c1;
}

void Aabb3Cls::fromRay(double limitMax, double limitMin, Ray ray) {
    return _c1;
}

void Aabb3Cls::centerAndHalfExtents(Vector3 center, Vector3 halfExtents) {
    return _c1;
}

void Aabb3Cls::fromBuffer(ByteBuffer buffer, int offset)

void Aabb3Cls::setCenterAndHalfExtents(Vector3 center, Vector3 halfExtents) {
    auto _c1 = make<Aabb3Cls>();_c1.setSphere(sphere);auto _c1 = make<Aabb3Cls>();_c1.setTriangle(triangle);auto _c1 = make<Aabb3Cls>();_c1.setQuad(quad);auto _c1 = make<Aabb3Cls>();_c1.setObb3(obb);auto _c1 = make<Aabb3Cls>();_c1.setRay(ray, limitMin, limitMax);auto _c1 = make<Aabb3Cls>();_c1.setCenterAndHalfExtents(center, halfExtents);auto _c1 = _min;_c1.auto _c2 = setFrom(center);_c2.sub(halfExtents);_c2;_c1;
    auto _c3 = _max;_c3.auto _c4 = setFrom(center);_c4.add(halfExtents);_c4;_c3;
}

void Aabb3Cls::setSphere(Sphere sphere) {
    auto _c1 = _min;_c1.auto _c2 = splat(-sphere->radius);_c2.add(sphere->_center);_c2;_c1;
    auto _c3 = _max;_c3.auto _c4 = splat(sphere->radius);_c4.add(sphere->_center);_c4;_c3;
}

void Aabb3Cls::setTriangle(Triangle triangle) {
    _min->setValues(math->min(triangle->_point0->x, math->min(triangle->_point1->x, triangle->_point2->x)), math->min(triangle->_point0->y, math->min(triangle->_point1->y, triangle->_point2->y)), math->min(triangle->_point0->z, math->min(triangle->_point1->z, triangle->_point2->z)));
    _max->setValues(math->max(triangle->_point0->x, math->max(triangle->_point1->x, triangle->_point2->x)), math->max(triangle->_point0->y, math->max(triangle->_point1->y, triangle->_point2->y)), math->max(triangle->_point0->z, math->max(triangle->_point1->z, triangle->_point2->z)));
}

void Aabb3Cls::setQuad(Quad quad) {
    _min->setValues(math->min(quad->_point0->x, math->min(quad->_point1->x, math->min(quad->_point2->x, quad->_point3->x))), math->min(quad->_point0->y, math->min(quad->_point1->y, math->min(quad->_point2->y, quad->_point3->y))), math->min(quad->_point0->z, math->min(quad->_point1->z, math->min(quad->_point2->z, quad->_point3->z))));
    _max->setValues(math->max(quad->_point0->x, math->max(quad->_point1->x, math->max(quad->_point2->x, quad->_point3->x))), math->max(quad->_point0->y, math->max(quad->_point1->y, math->max(quad->_point2->y, quad->_point3->y))), math->max(quad->_point0->z, math->max(quad->_point1->z, math->max(quad->_point2->z, quad->_point3->z))));
}

void Aabb3Cls::setObb3(Obb3 obb) {
    Unknown corner = Vector3Cls->zero();
    obb->copyCorner(0, corner);
    _min->setFrom(corner);
    _max->setFrom(corner);
    obb->copyCorner(1, corner);
    hullPoint(corner);
    obb->copyCorner(2, corner);
    hullPoint(corner);
    obb->copyCorner(3, corner);
    hullPoint(corner);
    obb->copyCorner(4, corner);
    hullPoint(corner);
    obb->copyCorner(5, corner);
    hullPoint(corner);
    obb->copyCorner(6, corner);
    hullPoint(corner);
    obb->copyCorner(7, corner);
    hullPoint(corner);
}

void Aabb3Cls::setRay(double limitMax, double limitMin, Ray ray) {
    auto _c1 = ray;_c1.auto _c2 = copyAt(_min, limitMin);_c2.copyAt(_max, limitMax);_c2;_c1;
    if (_max->x < _min->x) {
        Unknown temp = _max->x;
        _max->x = _min->x;
        _min->x = temp;
    }
    if (_max->y < _min->y) {
        Unknown temp = _max->y;
        _max->y = _min->y;
        _min->y = temp;
    }
    if (_max->z < _min->z) {
        Unknown temp = _max->z;
        _max->z = _min->z;
        _min->z = temp;
    }
}

void Aabb3Cls::copyCenterAndHalfExtents(Vector3 center, Vector3 halfExtents) {
    auto _c1 = center;_c1.auto _c2 = setFrom(_min);_c2.auto _c3 = add(_max);_c3.scale(0.5);_c3;_c2;_c1;
    auto _c4 = halfExtents;_c4.auto _c5 = setFrom(_max);_c5.auto _c6 = sub(_min);_c6.scale(0.5);_c6;_c5;_c4;
}

void Aabb3Cls::copyCenter(Vector3 center) {
    auto _c1 = center;_c1.auto _c2 = setFrom(_min);_c2.auto _c3 = add(_max);_c3.scale(0.5);_c3;_c2;_c1;
}

void Aabb3Cls::copyFrom(Aabb3 other) {
    _min->setFrom(other->_min);
    _max->setFrom(other->_max);
}

void Aabb3Cls::transform(Matrix4 t) {
    _updateCenterAndHalfExtents();
    auto _c1 = t;_c1.auto _c2 = transform3(_center);_c2.absoluteRotate(_halfExtents);_c2;_c1;
    auto _c3 = _min;_c3.auto _c4 = setFrom(_center);_c4.sub(_halfExtents);_c4;_c3;
    auto _c5 = _max;_c5.auto _c6 = setFrom(_center);_c6.add(_halfExtents);_c6;_c5;
}

void Aabb3Cls::rotate(Matrix4 t) {
    _updateCenterAndHalfExtents();
    t->absoluteRotate(_halfExtents);
    auto _c1 = _min;_c1.auto _c2 = setFrom(_center);_c2.sub(_halfExtents);_c2;_c1;
    auto _c3 = _max;_c3.auto _c4 = setFrom(_center);_c4.add(_halfExtents);_c4;_c3;
}

Aabb3 Aabb3Cls::transformed(Aabb3 out, Matrix4 t) {
    return _c1;
}

Aabb3 Aabb3Cls::rotated(Aabb3 out, Matrix4 t) {
    return _c1;
}

void Aabb3Cls::getPN(Vector3 outN, Vector3 outP, Vector3 planeNormal) {
    if (planeNormal->x < 0.0) {
            auto _c1 = out;    _c1.auto _c2 = copyFrom(this);    _c2.transform(t);    _c2;    auto _c1 = out;    _c1.auto _c2 = copyFrom(this);    _c2.rotate(t);    _c2;outP->x = _min->x;
        outN->x = _max->x;
    } else {
        outP->x = _max->x;
        outN->x = _min->x;
    }
    if (planeNormal->y < 0.0) {
        outP->y = _min->y;
        outN->y = _max->y;
    } else {
        outP->y = _max->y;
        outN->y = _min->y;
    }
    if (planeNormal->z < 0.0) {
        outP->z = _min->z;
        outN->z = _max->z;
    } else {
        outP->z = _max->z;
        outN->z = _min->z;
    }
}

void Aabb3Cls::hull(Aabb3 other) {
    Vector3Cls->min(_min, other->_min, _min);
    Vector3Cls->max(_max, other->_max, _max);
}

void Aabb3Cls::hullPoint(Vector3 point) {
    Vector3Cls->min(_min, point, _min);
    Vector3Cls->max(_max, point, _max);
}

bool Aabb3Cls::containsAabb3(Aabb3 other) {
    Unknown otherMax = other->_max;
    Unknown otherMin = other->_min;
    return (_min->x < otherMin->x) && (_min->y < otherMin->y) && (_min->z < otherMin->z) && (_max->x > otherMax->x) && (_max->y > otherMax->y) && (_max->z > otherMax->z);
}

bool Aabb3Cls::containsSphere(Sphere other) {
    Unknown boxExtends = Vector3Cls->all(other->radius);
    Unknown sphereBox = Aabb3Cls->centerAndHalfExtents(other->_center, boxExtends);
    return containsAabb3(sphereBox);
}

bool Aabb3Cls::containsVector3(Vector3 other) {
    return (_min->x < other->x) && (_min->y < other->y) && (_min->z < other->z) && (_max->x > other->x) && (_max->y > other->y) && (_max->z > other->z);
}

bool Aabb3Cls::containsTriangle(Triangle other) {
    return containsVector3(other->_point0) && containsVector3(other->_point1) && containsVector3(other->_point2);
}

bool Aabb3Cls::intersectsWithAabb3(Aabb3 other) {
    Unknown otherMax = other->_max;
    Unknown otherMin = other->_min;
    return (_min->x <= otherMax->x) && (_min->y <= otherMax->y) && (_min->z <= otherMax->z) && (_max->x >= otherMin->x) && (_max->y >= otherMin->y) && (_max->z >= otherMin->z);
}

bool Aabb3Cls::intersectsWithSphere(Sphere other) {
    Unknown center = other->_center;
    Unknown radius = other->radius;
    auto d = 0.0;
    auto e = 0.0;
    for (;  < 3; ++i) {
        if ((e = center[i] - _min[i]) < 0.0) {
            if ( < -radius) {
                return false;
            }
            d = d + e * e;
        } else {
            if ((e = center[i] - _max[i]) > 0.0) {
                if (e > radius) {
                    return false;
                }
                d = d + e * e;
            }
        }
    }
    return d <= radius * radius;
}

bool Aabb3Cls::intersectsWithVector3(Vector3 other) {
    return (_min->x <= other->x) && (_min->y <= other->y) && (_min->z <= other->z) && (_max->x >= other->x) && (_max->y >= other->y) && (_max->z >= other->z);
}

bool Aabb3Cls::intersectsWithTriangle(double epsilon, Triangle other, IntersectionResult result) {
    double p0, p1, p2, r, len;
    double a;
    copyCenterAndHalfExtents(_aabbCenter, _aabbHalfExtents);
    auto _c1 = _v0;_c1.auto _c2 = setFrom(other->point0);_c2.sub(_aabbCenter);_c2;_c1;
    auto _c3 = _v1;_c3.auto _c4 = setFrom(other->point1);_c4.sub(_aabbCenter);_c4;_c3;
    auto _c5 = _v2;_c5.auto _c6 = setFrom(other->point2);_c6.sub(_aabbCenter);_c6;_c5;
    auto _c7 = _f0;_c7.auto _c8 = setFrom(_v1);_c8.sub(_v0);_c8;_c7;
    auto _c9 = _f1;_c9.auto _c10 = setFrom(_v2);_c10.sub(_v1);_c10;_c9;
    auto _c11 = _f2;_c11.auto _c12 = setFrom(_v0);_c12.sub(_v2);_c12;_c11;
    len = _f0->y * _f0->y + _f0->z * _f0->z;
    if (len > epsilon) {
        p0 = _v0->z * _f0->y - _v0->y * _f0->z;
        p2 = _v2->z * _f0->y - _v2->y * _f0->z;
        r = _aabbHalfExtents[1] * _f0->z->abs() + _aabbHalfExtents[2] * _f0->y->abs();
        if (math->max(-math->max(p0, p2), math->min(p0, p2)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p2) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u0->crossInto(_f0, result->axis);
        }
    }
    len = _f1->y * _f1->y + _f1->z * _f1->z;
    if (len > epsilon) {
        p0 = _v0->z * _f1->y - _v0->y * _f1->z;
        p1 = _v1->z * _f1->y - _v1->y * _f1->z;
        r = _aabbHalfExtents[1] * _f1->z->abs() + _aabbHalfExtents[2] * _f1->y->abs();
        if (math->max(-math->max(p0, p1), math->min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p1) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u0->crossInto(_f1, result->axis);
        }
    }
    len = _f2->y * _f2->y + _f2->z * _f2->z;
    if (len > epsilon) {
        p0 = _v0->z * _f2->y - _v0->y * _f2->z;
        p1 = _v1->z * _f2->y - _v1->y * _f2->z;
        r = _aabbHalfExtents[1] * _f2->z->abs() + _aabbHalfExtents[2] * _f2->y->abs();
        if (math->max(-math->max(p0, p1), math->min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p1) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u0->crossInto(_f2, result->axis);
        }
    }
    len = _f0->x * _f0->x + _f0->z * _f0->z;
    if (len > epsilon) {
        p0 = _v0->x * _f0->z - _v0->z * _f0->x;
        p2 = _v2->x * _f0->z - _v2->z * _f0->x;
        r = _aabbHalfExtents[0] * _f0->z->abs() + _aabbHalfExtents[2] * _f0->x->abs();
        if (math->max(-math->max(p0, p2), math->min(p0, p2)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p2) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u1->crossInto(_f0, result->axis);
        }
    }
    len = _f1->x * _f1->x + _f1->z * _f1->z;
    if (len > epsilon) {
        p0 = _v0->x * _f1->z - _v0->z * _f1->x;
        p1 = _v1->x * _f1->z - _v1->z * _f1->x;
        r = _aabbHalfExtents[0] * _f1->z->abs() + _aabbHalfExtents[2] * _f1->x->abs();
        if (math->max(-math->max(p0, p1), math->min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p1) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u1->crossInto(_f1, result->axis);
        }
    }
    len = _f2->x * _f2->x + _f2->z * _f2->z;
    if (len > epsilon) {
        p0 = _v0->x * _f2->z - _v0->z * _f2->x;
        p1 = _v1->x * _f2->z - _v1->z * _f2->x;
        r = _aabbHalfExtents[0] * _f2->z->abs() + _aabbHalfExtents[2] * _f2->x->abs();
        if (math->max(-math->max(p0, p1), math->min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p1) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u1->crossInto(_f2, result->axis);
        }
    }
    len = _f0->x * _f0->x + _f0->y * _f0->y;
    if (len > epsilon) {
        p0 = _v0->y * _f0->x - _v0->x * _f0->y;
        p2 = _v2->y * _f0->x - _v2->x * _f0->y;
        r = _aabbHalfExtents[0] * _f0->y->abs() + _aabbHalfExtents[1] * _f0->x->abs();
        if (math->max(-math->max(p0, p2), math->min(p0, p2)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p2) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u2->crossInto(_f0, result->axis);
        }
    }
    len = _f1->x * _f1->x + _f1->y * _f1->y;
    if (len > epsilon) {
        p0 = _v0->y * _f1->x - _v0->x * _f1->y;
        p1 = _v1->y * _f1->x - _v1->x * _f1->y;
        r = _aabbHalfExtents[0] * _f1->y->abs() + _aabbHalfExtents[1] * _f1->x->abs();
        if (math->max(-math->max(p0, p1), math->min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p1) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u2->crossInto(_f1, result->axis);
        }
    }
    len = _f2->x * _f2->x + _f2->y * _f2->y;
    if (len > epsilon) {
        p0 = _v0->y * _f2->x - _v0->x * _f2->y;
        p1 = _v1->y * _f2->x - _v1->x * _f2->y;
        r = _aabbHalfExtents[0] * _f2->y->abs() + _aabbHalfExtents[1] * _f2->x->abs();
        if (math->max(-math->max(p0, p1), math->min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math->min(p0, p1) - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            _u2->crossInto(_f2, result->axis);
        }
    }
    if (math->max(_v0->x, math->max(_v1->x, _v2->x)) < -_aabbHalfExtents[0] || math->min(_v0->x, math->min(_v1->x, _v2->x)) > _aabbHalfExtents[0]) {
        return false;
    }
    a = math->min(_v0->x, math->min(_v1->x, _v2->x)) - _aabbHalfExtents[0];
    if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
        result->_depth = a;
        result->axis->setFrom(_u0);
    }
    if (math->max(_v0->y, math->max(_v1->y, _v2->y)) < -_aabbHalfExtents[1] || math->min(_v0->y, math->min(_v1->y, _v2->y)) > _aabbHalfExtents[1]) {
        return false;
    }
    a = math->min(_v0->y, math->min(_v1->y, _v2->y)) - _aabbHalfExtents[1];
    if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
        result->_depth = a;
        result->axis->setFrom(_u1);
    }
    if (math->max(_v0->z, math->max(_v1->z, _v2->z)) < -_aabbHalfExtents[2] || math->min(_v0->z, math->min(_v1->z, _v2->z)) > _aabbHalfExtents[2]) {
        return false;
    }
    a = math->min(_v0->z, math->min(_v1->z, _v2->z)) - _aabbHalfExtents[2];
    if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
        result->_depth = a;
        result->axis->setFrom(_u2);
    }
    _v0->add(_aabbCenter);
    _f0->crossInto(_f1, _trianglePlane->normal);
    _trianglePlane->constant = _trianglePlane->normal->dot(_v0);
    return intersectsWithPlane(_trianglePlaneresult);
}

bool Aabb3Cls::intersectsWithPlane(Plane other, IntersectionResult result) {
    copyCenterAndHalfExtents(_aabbCenter, _aabbHalfExtents);
    Unknown r = _aabbHalfExtents[0] * other->normal[0]->abs() + _aabbHalfExtents[1] * other->normal[1]->abs() + _aabbHalfExtents[2] * other->normal[2]->abs();
    Unknown s = other->normal->dot(_aabbCenter) - other->constant;
    if (s->abs() <= r) {
        Unknown a = s - r;
        if (result != nullptr && (result->_depth == nullptr || (result->_depth!) < a)) {
            result->_depth = a;
            result->axis->setFrom(other->normal);
        }
        return true;
    }
    return false;
}

bool Aabb3Cls::intersectsWithQuad(Quad other, IntersectionResult result) {
    other->copyTriangles(_quadTriangle0, _quadTriangle1);
    return intersectsWithTriangle(_quadTriangle0result) || intersectsWithTriangle(_quadTriangle1result);
}

void Aabb3Cls::_updateCenterAndHalfExtents() {
    return copyCenterAndHalfExtents(_center, _halfExtents);
}
