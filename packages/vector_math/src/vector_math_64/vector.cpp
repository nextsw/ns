#include "vector.hpp"
double dot2(Vector2 x, Vector2 y) {
    return x->dot(y);
}

double dot3(Vector3 x, Vector3 y) {
    return x->dot(y);
}

void cross3(Vector3 out, Vector3 x, Vector3 y) {
    x->crossInto(y, out);
}

double cross2(Vector2 x, Vector2 y) {
    return x->cross(y);
}

void cross2A(Vector2 out, double x, Vector2 y) {
    Unknown tempy = x * y->x;
    auto _c1 = out;_c1.x = auto _c2 = -x * y->y;_c2.y = tempy;_c2;_c1;
}

void cross2B(Vector2 out, Vector2 x, double y) {
    Unknown tempy = -y * x->x;
    auto _c1 = out;_c1.x = auto _c2 = y * x->y;_c2.y = tempy;_c2;_c1;
}

void buildPlaneVectors(Vector3 planeNormal, Vector3 u, Vector3 v) {
    if (planeNormal->z->abs() > math->sqrt1_2) {
        Unknown a = planeNormal->y * planeNormal->y + planeNormal->z * planeNormal->z;
        Unknown k = 1.0 / math->sqrt(a);
            auto _c1 = u;    _c1.x = auto _c2 = 0.0;    _c2.y = auto _c3 = -planeNormal->z * k;    _c3.z = planeNormal->y * k;    _c3;    _c2;_c1;
            auto _c4 = v;    _c4.x = auto _c5 = a * k;    _c5.y = auto _c6 = -planeNormal[0] * (planeNormal[1] * k);    _c6.z = planeNormal[0] * (-planeNormal[2] * k);    _c6;    _c5;_c4;
    } else {
        Unknown a = planeNormal->x * planeNormal->x + planeNormal->y * planeNormal->y;
        Unknown k = 1.0 / math->sqrt(a);
            auto _c7 = u;    _c7.x = auto _c8 = -planeNormal[1] * k;    _c8.y = auto _c9 = planeNormal[0] * k;    _c9.z = 0.0;    _c9;    _c8;_c7;
            auto _c10 = v;    _c10.x = auto _c11 = -planeNormal[2] * (planeNormal[0] * k);    _c11.y = auto _c12 = planeNormal[2] * (-planeNormal[1] * k);    _c12.z = a * k;    _c12;    _c11;_c10;
    }
}
