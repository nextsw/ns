#ifndef VECTOR_H
#define VECTOR_H
#include <memory>



double dot2(Vector2 x, Vector2 y);

double dot3(Vector3 x, Vector3 y);

void cross3(Vector3 out, Vector3 x, Vector3 y);

double cross2(Vector2 x, Vector2 y);

void cross2A(Vector2 out, double x, Vector2 y);

void cross2B(Vector2 out, Vector2 x, double y);

void buildPlaneVectors(Vector3 planeNormal, Vector3 u, Vector3 v);


class Vector {
public:

    List<double> storage();

private:

};

#endif