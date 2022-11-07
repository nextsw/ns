#include "frustum.hpp"
Plane Frustum::plane0() {
    return _plane0;
}

Plane Frustum::plane1() {
    return _plane1;
}

Plane Frustum::plane2() {
    return _plane2;
}

Plane Frustum::plane3() {
    return _plane3;
}

Plane Frustum::plane4() {
    return _plane4;
}

Plane Frustum::plane5() {
    return _plane5;
}

Frustum::Frustum() {
    {
        _plane0 = Plane();
        _plane1 = Plane();
        _plane2 = Plane();
        _plane3 = Plane();
        _plane4 = Plane();
        _plane5 = Plane();
    }
}

void Frustum::copy(Frustum other) {
    return ;
}

void Frustum::matrix(Matrix4 matrix) {
    return ;
}

void Frustum::copyFrom(Frustum other) {
    _plane0.copyFrom(other._plane0);
    _plane1.copyFrom(other._plane1);
    _plane2.copyFrom(other._plane2);
    _plane3.copyFrom(other._plane3);
    _plane4.copyFrom(other._plane4);
    _plane5.copyFrom(other._plane5);
}

void Frustum::setFromMatrix(Matrix4 matrix) {
    Unknown me = matrix.storage;
    Unknown me0 = me[0], me1 = me[1], me2 = me[2], me3 = me[3];
    Unknown me4 = me[4], me5 = me[5], me6 = me[6], me7 = me[7];
    Unknown me8 = me[8], me9 = me[9], me10 = me[10], me11 = me[11];
    Unknown me12 = me[12], me13 = me[13], me14 = me[14], me15 = me[15];
    ;
    ;
    ;
    ;
    ;
    ;
}

bool Frustum::containsVector3(Vector3 point) {
    if (_plane0.distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane1.distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane2.distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane3.distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane4.distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane5.distanceToVector3(point) < 0.0) {
        return false;
    }
    return true;
}

bool Frustum::intersectsWithAabb3(Aabb3 aabb) {
    if (_intersectsWithAabb3CheckPlane(aabb, _plane0)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane1)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane2)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane3)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane4)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane5)) {
        return false;
    }
    return true;
}

bool Frustum::intersectsWithSphere(Sphere sphere) {
    Unknown negativeRadius = -sphere.radius;
    Unknown center = sphere.center;
    if (_plane0.distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane1.distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane2.distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane3.distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane4.distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane5.distanceToVector3(center) < negativeRadius) {
        return false;
    }
    return true;
}

void Frustum::calculateCorners(Vector3 corner0, Vector3 corner1, Vector3 corner2, Vector3 corner3, Vector3 corner4, Vector3 corner5, Vector3 corner6, Vector3 corner7) {
    Plane.intersection(_plane0, _plane2, _plane4, corner0);
    Plane.intersection(_plane0, _plane3, _plane4, corner1);
    Plane.intersection(_plane0, _plane3, _plane5, corner2);
    Plane.intersection(_plane0, _plane2, _plane5, corner3);
    Plane.intersection(_plane1, _plane2, _plane4, corner4);
    Plane.intersection(_plane1, _plane3, _plane4, corner5);
    Plane.intersection(_plane1, _plane3, _plane5, corner6);
    Plane.intersection(_plane1, _plane2, _plane5, corner7);
}

bool Frustum::_intersectsWithAabb3CheckPlane(Aabb3 aabb, Plane plane) {
    double outPx, outPy, outPz, outNx, outNy, outNz;
    if (plane._normal.x < 0.0) {
        outPx = aabb.min.x;
        outNx = aabb.max.x;
    } else {
        outPx = aabb.max.x;
        outNx = aabb.min.x;
    }
    if (plane._normal.y < 0.0) {
        outPy = aabb.min.y;
        outNy = aabb.max.y;
    } else {
        outPy = aabb.max.y;
        outNy = aabb.min.y;
    }
    if (plane._normal.z < 0.0) {
        outPz = aabb.min.z;
        outNz = aabb.max.z;
    } else {
        outPz = aabb.max.z;
        outNz = aabb.min.z;
    }
    Unknown d1 = plane._normal.x * outPx + plane._normal.y * outPy + plane._normal.z * outPz + plane.constant;
    Unknown d2 = plane._normal.x * outNx + plane._normal.y * outNy + plane._normal.z * outNz + plane.constant;
    return  < 0 &&  < 0;
}
