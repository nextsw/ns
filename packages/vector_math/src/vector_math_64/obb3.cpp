#include "obb3.hpp"
Vector3 Obb3::center() {
    return _center;
}

Vector3 Obb3::halfExtents() {
    return _halfExtents;
}

Vector3 Obb3::axis0() {
    return _axis0;
}

Vector3 Obb3::axis1() {
    return _axis1;
}

Vector3 Obb3::axis2() {
    return _axis2;
}

Obb3::Obb3() {
    {
        _center = Vector3.zero();
        _halfExtents = Vector3.zero();
        _axis0 = Vector3(1.0, 0.0, 0.0);
        _axis1 = Vector3(0.0, 1.0, 0.0);
        _axis2 = Vector3(0.0, 0.0, 1.0);
    }
}

void Obb3::copy(Obb3 other)

void Obb3::centerExtentsAxes(Vector3 axis0, Vector3 axis1, Vector3 axis2, Vector3 center, Vector3 halfExtents)

void Obb3::copyFrom(Obb3 other) {
    _center.setFrom(other._center);
    _halfExtents.setFrom(other._halfExtents);
    _axis0.setFrom(other._axis0);
    _axis1.setFrom(other._axis1);
    _axis2.setFrom(other._axis2);
}

void Obb3::copyInto(Obb3 other) {
    other._center.setFrom(_center);
    other._halfExtents.setFrom(_halfExtents);
    other._axis0.setFrom(_axis0);
    other._axis1.setFrom(_axis1);
    other._axis2.setFrom(_axis2);
}

void Obb3::resetRotation() {
    _axis0.setValues(1.0, 0.0, 0.0);
    _axis1.setValues(0.0, 1.0, 0.0);
    _axis2.setValues(0.0, 0.0, 1.0);
}

void Obb3::translate(Vector3 offset) {
    _center.add(offset);
}

void Obb3::rotate(Matrix3 t) {
    ;
    ;
}

void Obb3::transform(Matrix4 t) {
    ;
    ;
}

void Obb3::copyCorner(Vector3 corner, int cornerIndex) {
    assert(cornerIndex >= 0 ||  < 8);
    corner.setFrom(_center);
    ;
}

void Obb3::closestPointTo(Vector3 p, Vector3 q) {
    Unknown d = p - _center;
    q.setFrom(_center);
    auto dist = d.dot(_axis0);
    dist = dist.clamp(-_halfExtents.x, _halfExtents.x).toDouble();
    q.addScaled(_axis0, dist);
    dist = d.dot(_axis1);
    dist = dist.clamp(-_halfExtents.y, _halfExtents.y).toDouble();
    q.addScaled(_axis1, dist);
    dist = d.dot(_axis2);
    dist = dist.clamp(-_halfExtents.z, _halfExtents.z).toDouble();
    q.addScaled(_axis2, dist);
}

bool Obb3::intersectsWithObb3(double epsilon, Obb3 other) {
    ;
    ;
    _t.setValues(_t.dot(_axis0), _t.dot(_axis1), _t.dot(_axis2));
    for (;  < 3; i++) {
        for (;  < 3; j++) {
            _absR.setEntry(i, j, _r.entry(i, j).abs() + epsilon);
        }
    }
    double ra;
    double rb;
    for (;  < 3; i++) {
        ra = _halfExtents[i];
        rb = other._halfExtents[0] * _absR.entry(i, 0) + other._halfExtents[1] * _absR.entry(i, 1) + other._halfExtents[2] * _absR.entry(i, 2);
        if (_t[i].abs() > ra + rb) {
            return false;
        }
    }
    for (;  < 3; i++) {
        ra = _halfExtents[0] * _absR.entry(0, i) + _halfExtents[1] * _absR.entry(1, i) + _halfExtents[2] * _absR.entry(2, i);
        rb = other._halfExtents[i];
        if ((_t[0] * _r.entry(0, i) + _t[1] * _r.entry(1, i) + _t[2] * _r.entry(2, i)).abs() > ra + rb) {
            return false;
        }
    }
    ra = _halfExtents[1] * _absR.entry(2, 0) + _halfExtents[2] * _absR.entry(1, 0);
    rb = other._halfExtents[1] * _absR.entry(0, 2) + other._halfExtents[2] * _absR.entry(0, 1);
    if ((_t[2] * _r.entry(1, 0) - _t[1] * _r.entry(2, 0)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[1] * _absR.entry(2, 1) + _halfExtents[2] * _absR.entry(1, 1);
    rb = other._halfExtents[0] * _absR.entry(0, 2) + other._halfExtents[2] * _absR.entry(0, 0);
    if ((_t[2] * _r.entry(1, 1) - _t[1] * _r.entry(2, 1)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[1] * _absR.entry(2, 2) + _halfExtents[2] * _absR.entry(1, 2);
    rb = other._halfExtents[0] * _absR.entry(0, 1) + other._halfExtents[1] * _absR.entry(0, 0);
    if ((_t[2] * _r.entry(1, 2) - _t[1] * _r.entry(2, 2)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR.entry(2, 0) + _halfExtents[2] * _absR.entry(0, 0);
    rb = other._halfExtents[1] * _absR.entry(1, 2) + other._halfExtents[2] * _absR.entry(1, 1);
    if ((_t[0] * _r.entry(2, 0) - _t[2] * _r.entry(0, 0)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR.entry(2, 1) + _halfExtents[2] * _absR.entry(0, 1);
    rb = other._halfExtents[0] * _absR.entry(1, 2) + other._halfExtents[2] * _absR.entry(1, 0);
    if ((_t[0] * _r.entry(2, 1) - _t[2] * _r.entry(0, 1)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR.entry(2, 2) + _halfExtents[2] * _absR.entry(0, 2);
    rb = other._halfExtents[0] * _absR.entry(1, 1) + other._halfExtents[1] * _absR.entry(1, 0);
    if ((_t[0] * _r.entry(2, 2) - _t[2] * _r.entry(0, 2)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR.entry(1, 0) + _halfExtents[1] * _absR.entry(0, 0);
    rb = other._halfExtents[1] * _absR.entry(2, 2) + other._halfExtents[2] * _absR.entry(2, 1);
    if ((_t[1] * _r.entry(0, 0) - _t[0] * _r.entry(1, 0)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR.entry(1, 1) + _halfExtents[1] * _absR.entry(0, 1);
    rb = other._halfExtents[0] * _absR.entry(2, 2) + other._halfExtents[2] * _absR.entry(2, 0);
    if ((_t[1] * _r.entry(0, 1) - _t[0] * _r.entry(1, 1)).abs() > ra + rb) {
        return false;
    }
    ra = _halfExtents[0] * _absR.entry(1, 2) + _halfExtents[1] * _absR.entry(0, 2);
    rb = other._halfExtents[0] * _absR.entry(2, 1) + other._halfExtents[1] * _absR.entry(2, 0);
    if ((_t[1] * _r.entry(0, 2) - _t[0] * _r.entry(1, 2)).abs() > ra + rb) {
        return false;
    }
    return true;
}

bool Obb3::intersectsWithTriangle(Triangle other, IntersectionResult result) {
    _triangle.copyFrom(other);
    ;
    ;
    ;
    _aabb3.setCenterAndHalfExtents(_zeroVector, _halfExtents);
    return _aabb3.intersectsWithTriangle(_triangleresult);
}

bool Obb3::intersectsWithVector3(Vector3 other) {
    ;
    _aabb3.setCenterAndHalfExtents(_zeroVector, _halfExtents);
    return _aabb3.intersectsWithVector3(_vector);
}

bool Obb3::intersectsWithQuad(Quad other, IntersectionResult result) {
    other.copyTriangles(_quadTriangle0, _quadTriangle1);
    return intersectsWithTriangle(_quadTriangle0result) || intersectsWithTriangle(_quadTriangle1result);
}
