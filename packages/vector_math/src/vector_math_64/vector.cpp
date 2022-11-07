#include "vector.hpp"
double dot2(Vector2 x, Vector2 y) {
    return x.dot(y);
}

double dot3(Vector3 x, Vector3 y) {
    return x.dot(y);
}

void cross3(Vector3 out, Vector3 x, Vector3 y) {
    x.crossInto(y, out);
}

double cross2(Vector2 x, Vector2 y) {
    return x.cross(y);
}

void cross2A(Vector2 out, double x, Vector2 y) {
    Unknown tempy = x * y.x;
    ;
}

void cross2B(Vector2 out, Vector2 x, double y) {
    Unknown tempy = -y * x.x;
    ;
}

void buildPlaneVectors(Vector3 planeNormal, Vector3 u, Vector3 v) {
    if (planeNormal.z.abs() > math.sqrt1_2) {
        Unknown a = planeNormal.y * planeNormal.y + planeNormal.z * planeNormal.z;
        Unknown k = 1.0 / math.sqrt(a);
        ;
        ;
    } else {
        Unknown a = planeNormal.x * planeNormal.x + planeNormal.y * planeNormal.y;
        Unknown k = 1.0 / math.sqrt(a);
        ;
        ;
    }
}
