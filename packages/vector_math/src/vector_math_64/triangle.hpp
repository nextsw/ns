#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <memory>




class Triangle {
public:

    Vector3 point0();

    Vector3 point1();

    Vector3 point2();

     Triangle();

    void  copy(Triangle other);

    void  points(Vector3 point0, Vector3 point1, Vector3 point2);

    void copyFrom(Triangle other);

    void copyNormalInto(Vector3 normal);

    void transform(Matrix4 t);

    void translate(Vector3 offset);

private:
    Vector3 _point0;

    Vector3 _point1;

    Vector3 _point2;


};

#endif