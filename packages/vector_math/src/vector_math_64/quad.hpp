#ifndef QUAD_H
#define QUAD_H
#include <memory>




class Quad {
public:

    Vector3 point0();

    Vector3 point1();

    Vector3 point2();

    Vector3 point3();

     Quad();

    void  copy(Quad other);

    void  points(Vector3 point0, Vector3 point1, Vector3 point2, Vector3 point3);

    void copyFrom(Quad other);

    void copyNormalInto(Vector3 normal);

    void copyTriangles(Triangle triangle0, Triangle triangle1);

    void transform(Matrix4 t);

    void translate(Vector3 offset);

private:
    Vector3 _point0;

    Vector3 _point1;

    Vector3 _point2;

    Vector3 _point3;


};

#endif