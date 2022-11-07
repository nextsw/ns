#include "aabb3.hpp"
Vector3 Aabb3::min() {
    return _min;
}

Vector3 Aabb3::max() {
    return _max;
}

Vector3 Aabb3::center() {
    return ;
}

Aabb3::Aabb3() {
    {
        _min = Vector3.zero();
        _max = Vector3.zero();
    }
}

void Aabb3::copy(Aabb3 other)

void Aabb3::minMax(Vector3 max, Vector3 min)

void Aabb3::fromSphere(Sphere sphere) {
    return ;
}

void Aabb3::fromTriangle(Triangle triangle) {
    return ;
}

void Aabb3::fromQuad(Quad quad) {
    return ;
}

void Aabb3::fromObb3(Obb3 obb) {
    return ;
}

void Aabb3::fromRay(double limitMax, double limitMin, Ray ray) {
    return ;
}

void Aabb3::centerAndHalfExtents(Vector3 center, Vector3 halfExtents) {
    return ;
}

void Aabb3::fromBuffer(ByteBuffer buffer, int offset)

void Aabb3::setCenterAndHalfExtents(Vector3 center, Vector3 halfExtents) {
    ;
    ;
}

void Aabb3::setSphere(Sphere sphere) {
    ;
    ;
}

void Aabb3::setTriangle(Triangle triangle) {
    _min.setValues(math.min(triangle._point0.x, math.min(triangle._point1.x, triangle._point2.x)), math.min(triangle._point0.y, math.min(triangle._point1.y, triangle._point2.y)), math.min(triangle._point0.z, math.min(triangle._point1.z, triangle._point2.z)));
    _max.setValues(math.max(triangle._point0.x, math.max(triangle._point1.x, triangle._point2.x)), math.max(triangle._point0.y, math.max(triangle._point1.y, triangle._point2.y)), math.max(triangle._point0.z, math.max(triangle._point1.z, triangle._point2.z)));
}

void Aabb3::setQuad(Quad quad) {
    _min.setValues(math.min(quad._point0.x, math.min(quad._point1.x, math.min(quad._point2.x, quad._point3.x))), math.min(quad._point0.y, math.min(quad._point1.y, math.min(quad._point2.y, quad._point3.y))), math.min(quad._point0.z, math.min(quad._point1.z, math.min(quad._point2.z, quad._point3.z))));
    _max.setValues(math.max(quad._point0.x, math.max(quad._point1.x, math.max(quad._point2.x, quad._point3.x))), math.max(quad._point0.y, math.max(quad._point1.y, math.max(quad._point2.y, quad._point3.y))), math.max(quad._point0.z, math.max(quad._point1.z, math.max(quad._point2.z, quad._point3.z))));
}

void Aabb3::setObb3(Obb3 obb) {
    Unknown corner = Vector3.zero();
    obb.copyCorner(0, corner);
    _min.setFrom(corner);
    _max.setFrom(corner);
    obb.copyCorner(1, corner);
    hullPoint(corner);
    obb.copyCorner(2, corner);
    hullPoint(corner);
    obb.copyCorner(3, corner);
    hullPoint(corner);
    obb.copyCorner(4, corner);
    hullPoint(corner);
    obb.copyCorner(5, corner);
    hullPoint(corner);
    obb.copyCorner(6, corner);
    hullPoint(corner);
    obb.copyCorner(7, corner);
    hullPoint(corner);
}

void Aabb3::setRay(double limitMax, double limitMin, Ray ray) {
    ;
    if (_max.x < _min.x) {
        Unknown temp = _max.x;
        _max.x = _min.x;
        _min.x = temp;
    }
    if (_max.y < _min.y) {
        Unknown temp = _max.y;
        _max.y = _min.y;
        _min.y = temp;
    }
    if (_max.z < _min.z) {
        Unknown temp = _max.z;
        _max.z = _min.z;
        _min.z = temp;
    }
}

void Aabb3::copyCenterAndHalfExtents(Vector3 center, Vector3 halfExtents) {
    ;
    ;
}

void Aabb3::copyCenter(Vector3 center) {
    ;
}

void Aabb3::copyFrom(Aabb3 other) {
    _min.setFrom(other._min);
    _max.setFrom(other._max);
}

void Aabb3::transform(Matrix4 t) {
    _updateCenterAndHalfExtents();
    ;
    ;
    ;
}

void Aabb3::rotate(Matrix4 t) {
    _updateCenterAndHalfExtents();
    t.absoluteRotate(_halfExtents);
    ;
    ;
}

Aabb3 Aabb3::transformed(Aabb3 out, Matrix4 t) {
    return ;
}

Aabb3 Aabb3::rotated(Aabb3 out, Matrix4 t) {
    return ;
}

void Aabb3::getPN(Vector3 outN, Vector3 outP, Vector3 planeNormal) {
    if (planeNormal.x < 0.0) {
        outP.x = _min.x;
        outN.x = _max.x;
    } else {
        outP.x = _max.x;
        outN.x = _min.x;
    }
    if (planeNormal.y < 0.0) {
        outP.y = _min.y;
        outN.y = _max.y;
    } else {
        outP.y = _max.y;
        outN.y = _min.y;
    }
    if (planeNormal.z < 0.0) {
        outP.z = _min.z;
        outN.z = _max.z;
    } else {
        outP.z = _max.z;
        outN.z = _min.z;
    }
}

void Aabb3::hull(Aabb3 other) {
    Vector3.min(_min, other._min, _min);
    Vector3.max(_max, other._max, _max);
}

void Aabb3::hullPoint(Vector3 point) {
    Vector3.min(_min, point, _min);
    Vector3.max(_max, point, _max);
}

bool Aabb3::containsAabb3(Aabb3 other) {
    Unknown otherMax = other._max;
    Unknown otherMin = other._min;
    return (_min.x < otherMin.x) && (_min.y < otherMin.y) && (_min.z < otherMin.z) && (_max.x > otherMax.x) && (_max.y > otherMax.y) && (_max.z > otherMax.z);
}

bool Aabb3::containsSphere(Sphere other) {
    Unknown boxExtends = Vector3.all(other.radius);
    Unknown sphereBox = Aabb3.centerAndHalfExtents(other._center, boxExtends);
    return containsAabb3(sphereBox);
}

bool Aabb3::containsVector3(Vector3 other) {
    return (_min.x < other.x) && (_min.y < other.y) && (_min.z < other.z) && (_max.x > other.x) && (_max.y > other.y) && (_max.z > other.z);
}

bool Aabb3::containsTriangle(Triangle other) {
    return containsVector3(other._point0) && containsVector3(other._point1) && containsVector3(other._point2);
}

bool Aabb3::intersectsWithAabb3(Aabb3 other) {
    Unknown otherMax = other._max;
    Unknown otherMin = other._min;
    return (_min.x <= otherMax.x) && (_min.y <= otherMax.y) && (_min.z <= otherMax.z) && (_max.x >= otherMin.x) && (_max.y >= otherMin.y) && (_max.z >= otherMin.z);
}

bool Aabb3::intersectsWithSphere(Sphere other) {
    Unknown center = other._center;
    Unknown radius = other.radius;
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

bool Aabb3::intersectsWithVector3(Vector3 other) {
    return (_min.x <= other.x) && (_min.y <= other.y) && (_min.z <= other.z) && (_max.x >= other.x) && (_max.y >= other.y) && (_max.z >= other.z);
}

bool Aabb3::intersectsWithTriangle(double epsilon, Triangle other, IntersectionResult result) {
    double p0, p1, p2, r, len;
    double a;
    copyCenterAndHalfExtents(_aabbCenter, _aabbHalfExtents);
    ;
    ;
    ;
    ;
    ;
    ;
    len = _f0.y * _f0.y + _f0.z * _f0.z;
    if (len > epsilon) {
        p0 = _v0.z * _f0.y - _v0.y * _f0.z;
        p2 = _v2.z * _f0.y - _v2.y * _f0.z;
        r = _aabbHalfExtents[1] * _f0.z.abs() + _aabbHalfExtents[2] * _f0.y.abs();
        if (math.max(-math.max(p0, p2), math.min(p0, p2)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p2) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u0.crossInto(_f0, result.axis);
        }
    }
    len = _f1.y * _f1.y + _f1.z * _f1.z;
    if (len > epsilon) {
        p0 = _v0.z * _f1.y - _v0.y * _f1.z;
        p1 = _v1.z * _f1.y - _v1.y * _f1.z;
        r = _aabbHalfExtents[1] * _f1.z.abs() + _aabbHalfExtents[2] * _f1.y.abs();
        if (math.max(-math.max(p0, p1), math.min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p1) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u0.crossInto(_f1, result.axis);
        }
    }
    len = _f2.y * _f2.y + _f2.z * _f2.z;
    if (len > epsilon) {
        p0 = _v0.z * _f2.y - _v0.y * _f2.z;
        p1 = _v1.z * _f2.y - _v1.y * _f2.z;
        r = _aabbHalfExtents[1] * _f2.z.abs() + _aabbHalfExtents[2] * _f2.y.abs();
        if (math.max(-math.max(p0, p1), math.min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p1) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u0.crossInto(_f2, result.axis);
        }
    }
    len = _f0.x * _f0.x + _f0.z * _f0.z;
    if (len > epsilon) {
        p0 = _v0.x * _f0.z - _v0.z * _f0.x;
        p2 = _v2.x * _f0.z - _v2.z * _f0.x;
        r = _aabbHalfExtents[0] * _f0.z.abs() + _aabbHalfExtents[2] * _f0.x.abs();
        if (math.max(-math.max(p0, p2), math.min(p0, p2)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p2) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u1.crossInto(_f0, result.axis);
        }
    }
    len = _f1.x * _f1.x + _f1.z * _f1.z;
    if (len > epsilon) {
        p0 = _v0.x * _f1.z - _v0.z * _f1.x;
        p1 = _v1.x * _f1.z - _v1.z * _f1.x;
        r = _aabbHalfExtents[0] * _f1.z.abs() + _aabbHalfExtents[2] * _f1.x.abs();
        if (math.max(-math.max(p0, p1), math.min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p1) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u1.crossInto(_f1, result.axis);
        }
    }
    len = _f2.x * _f2.x + _f2.z * _f2.z;
    if (len > epsilon) {
        p0 = _v0.x * _f2.z - _v0.z * _f2.x;
        p1 = _v1.x * _f2.z - _v1.z * _f2.x;
        r = _aabbHalfExtents[0] * _f2.z.abs() + _aabbHalfExtents[2] * _f2.x.abs();
        if (math.max(-math.max(p0, p1), math.min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p1) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u1.crossInto(_f2, result.axis);
        }
    }
    len = _f0.x * _f0.x + _f0.y * _f0.y;
    if (len > epsilon) {
        p0 = _v0.y * _f0.x - _v0.x * _f0.y;
        p2 = _v2.y * _f0.x - _v2.x * _f0.y;
        r = _aabbHalfExtents[0] * _f0.y.abs() + _aabbHalfExtents[1] * _f0.x.abs();
        if (math.max(-math.max(p0, p2), math.min(p0, p2)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p2) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u2.crossInto(_f0, result.axis);
        }
    }
    len = _f1.x * _f1.x + _f1.y * _f1.y;
    if (len > epsilon) {
        p0 = _v0.y * _f1.x - _v0.x * _f1.y;
        p1 = _v1.y * _f1.x - _v1.x * _f1.y;
        r = _aabbHalfExtents[0] * _f1.y.abs() + _aabbHalfExtents[1] * _f1.x.abs();
        if (math.max(-math.max(p0, p1), math.min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p1) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u2.crossInto(_f1, result.axis);
        }
    }
    len = _f2.x * _f2.x + _f2.y * _f2.y;
    if (len > epsilon) {
        p0 = _v0.y * _f2.x - _v0.x * _f2.y;
        p1 = _v1.y * _f2.x - _v1.x * _f2.y;
        r = _aabbHalfExtents[0] * _f2.y.abs() + _aabbHalfExtents[1] * _f2.x.abs();
        if (math.max(-math.max(p0, p1), math.min(p0, p1)) > r + epsilon) {
            return false;
        }
        a = math.min(p0, p1) - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            _u2.crossInto(_f2, result.axis);
        }
    }
    if (math.max(_v0.x, math.max(_v1.x, _v2.x)) < -_aabbHalfExtents[0] || math.min(_v0.x, math.min(_v1.x, _v2.x)) > _aabbHalfExtents[0]) {
        return false;
    }
    a = math.min(_v0.x, math.min(_v1.x, _v2.x)) - _aabbHalfExtents[0];
    if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
        result._depth = a;
        result.axis.setFrom(_u0);
    }
    if (math.max(_v0.y, math.max(_v1.y, _v2.y)) < -_aabbHalfExtents[1] || math.min(_v0.y, math.min(_v1.y, _v2.y)) > _aabbHalfExtents[1]) {
        return false;
    }
    a = math.min(_v0.y, math.min(_v1.y, _v2.y)) - _aabbHalfExtents[1];
    if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
        result._depth = a;
        result.axis.setFrom(_u1);
    }
    if (math.max(_v0.z, math.max(_v1.z, _v2.z)) < -_aabbHalfExtents[2] || math.min(_v0.z, math.min(_v1.z, _v2.z)) > _aabbHalfExtents[2]) {
        return false;
    }
    a = math.min(_v0.z, math.min(_v1.z, _v2.z)) - _aabbHalfExtents[2];
    if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
        result._depth = a;
        result.axis.setFrom(_u2);
    }
    _v0.add(_aabbCenter);
    _f0.crossInto(_f1, _trianglePlane.normal);
    _trianglePlane.constant = _trianglePlane.normal.dot(_v0);
    return intersectsWithPlane(_trianglePlaneresult);
}

bool Aabb3::intersectsWithPlane(Plane other, IntersectionResult result) {
    copyCenterAndHalfExtents(_aabbCenter, _aabbHalfExtents);
    Unknown r = _aabbHalfExtents[0] * other.normal[0].abs() + _aabbHalfExtents[1] * other.normal[1].abs() + _aabbHalfExtents[2] * other.normal[2].abs();
    Unknown s = other.normal.dot(_aabbCenter) - other.constant;
    if (s.abs() <= r) {
        Unknown a = s - r;
        if (result != nullptr && (result._depth == nullptr || (result._depth!) < a)) {
            result._depth = a;
            result.axis.setFrom(other.normal);
        }
        return true;
    }
    return false;
}

bool Aabb3::intersectsWithQuad(Quad other, IntersectionResult result) {
    other.copyTriangles(_quadTriangle0, _quadTriangle1);
    return intersectsWithTriangle(_quadTriangle0result) || intersectsWithTriangle(_quadTriangle1result);
}

void Aabb3::_updateCenterAndHalfExtents() {
    return copyCenterAndHalfExtents(_center, _halfExtents);
}
