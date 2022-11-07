#ifndef FRUSTUM_H
#define FRUSTUM_H
#include <memory>




class Frustum {
public:

    Plane plane0();

    Plane plane1();

    Plane plane2();

    Plane plane3();

    Plane plane4();

    Plane plane5();

     Frustum();

    void  copy(Frustum other);

    void  matrix(Matrix4 matrix);

    void copyFrom(Frustum other);

    void setFromMatrix(Matrix4 matrix);

    bool containsVector3(Vector3 point);

    bool intersectsWithAabb3(Aabb3 aabb);

    bool intersectsWithSphere(Sphere sphere);

    void calculateCorners(Vector3 corner0, Vector3 corner1, Vector3 corner2, Vector3 corner3, Vector3 corner4, Vector3 corner5, Vector3 corner6, Vector3 corner7);

private:
    Plane _plane0;

    Plane _plane1;

    Plane _plane2;

    Plane _plane3;

    Plane _plane4;

    Plane _plane5;


    bool _intersectsWithAabb3CheckPlane(Aabb3 aabb, Plane plane);

};

#endif