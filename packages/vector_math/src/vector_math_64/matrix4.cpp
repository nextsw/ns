#include "matrix4.hpp"
Float64List Matrix4Cls::storage() {
    return _m4storage;
}

void Matrix4Cls::solve2(Matrix4 A, Vector2 x, Vector2 b) {
    Unknown a11 = A->entry(0, 0);
    Unknown a12 = A->entry(0, 1);
    Unknown a21 = A->entry(1, 0);
    Unknown a22 = A->entry(1, 1);
    Unknown bx = b->x - A::_m4storage[8];
    Unknown by = b->y - A::_m4storage[9];
    auto det = a11 * a22 - a12 * a21;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    auto _c1 = x;_c1.x = auto _c2 = det * (a22 * bx - a12 * by);_c2.y = det * (a11 * by - a21 * bx);_c2;_c1;
}

void Matrix4Cls::solve3(Matrix4 A, Vector3 x, Vector3 b) {
    Unknown A0x = A->entry(0, 0);
    Unknown A0y = A->entry(1, 0);
    Unknown A0z = A->entry(2, 0);
    Unknown A1x = A->entry(0, 1);
    Unknown A1y = A->entry(1, 1);
    Unknown A1z = A->entry(2, 1);
    Unknown A2x = A->entry(0, 2);
    Unknown A2y = A->entry(1, 2);
    Unknown A2z = A->entry(2, 2);
    Unknown bx = b->x - A::_m4storage[12];
    Unknown by = b->y - A::_m4storage[13];
    Unknown bz = b->z - A::_m4storage[14];
    double rx, ry, rz;
    double det;
    rx = A1yCls * A2zCls - A1zCls * A2yCls;
    ry = A1zCls * A2xCls - A1xCls * A2zCls;
    rz = A1xCls * A2yCls - A1yCls * A2xCls;
    det = A0xCls * rx + A0yCls * ry + A0zCls * rz;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    Unknown x_ = det * (bx * rx + by * ry + bz * rz);
    rx = -(A2yCls * bz - A2zCls * by);
    ry = -(A2zCls * bx - A2xCls * bz);
    rz = -(A2xCls * by - A2yCls * bx);
    Unknown y_ = det * (A0xCls * rx + A0yCls * ry + A0zCls * rz);
    rx = -(by * A1zCls - bz * A1yCls);
    ry = -(bz * A1xCls - bx * A1zCls);
    rz = -(bx * A1yCls - by * A1xCls);
    Unknown z_ = det * (A0xCls * rx + A0yCls * ry + A0zCls * rz);
    auto _c1 = x;_c1.x = auto _c2 = x_;_c2.y = auto _c3 = y_;_c3.z = z_;_c3;_c2;_c1;
}

void Matrix4Cls::solve(Matrix4 A, Vector4 x, Vector4 b) {
    Unknown a00 = A::_m4storage[0];
    Unknown a01 = A::_m4storage[1];
    Unknown a02 = A::_m4storage[2];
    Unknown a03 = A::_m4storage[3];
    Unknown a10 = A::_m4storage[4];
    Unknown a11 = A::_m4storage[5];
    Unknown a12 = A::_m4storage[6];
    Unknown a13 = A::_m4storage[7];
    Unknown a20 = A::_m4storage[8];
    Unknown a21 = A::_m4storage[9];
    Unknown a22 = A::_m4storage[10];
    Unknown a23 = A::_m4storage[11];
    Unknown a30 = A::_m4storage[12];
    Unknown a31 = A::_m4storage[13];
    Unknown a32 = A::_m4storage[14];
    Unknown a33 = A::_m4storage[15];
    Unknown b00 = a00 * a11 - a01 * a10;
    Unknown b01 = a00 * a12 - a02 * a10;
    Unknown b02 = a00 * a13 - a03 * a10;
    Unknown b03 = a01 * a12 - a02 * a11;
    Unknown b04 = a01 * a13 - a03 * a11;
    Unknown b05 = a02 * a13 - a03 * a12;
    Unknown b06 = a20 * a31 - a21 * a30;
    Unknown b07 = a20 * a32 - a22 * a30;
    Unknown b08 = a20 * a33 - a23 * a30;
    Unknown b09 = a21 * a32 - a22 * a31;
    Unknown b10 = a21 * a33 - a23 * a31;
    Unknown b11 = a22 * a33 - a23 * a32;
    Unknown bX = b->storage()[0];
    Unknown bY = b->storage()[1];
    Unknown bZ = b->storage()[2];
    Unknown bW = b->storage()[3];
    auto det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    auto _c1 = x;_c1.x = auto _c2 = det * ((a11 * b11 - a12 * b10 + a13 * b09) * bX - (a10 * b11 - a12 * b08 + a13 * b07) * bY + (a10 * b10 - a11 * b08 + a13 * b06) * bZ - (a10 * b09 - a11 * b07 + a12 * b06) * bW);_c2.y = auto _c3 = det * -((a01 * b11 - a02 * b10 + a03 * b09) * bX - (a00 * b11 - a02 * b08 + a03 * b07) * bY + (a00 * b10 - a01 * b08 + a03 * b06) * bZ - (a00 * b09 - a01 * b07 + a02 * b06) * bW);_c3.z = auto _c4 = det * ((a31 * b05 - a32 * b04 + a33 * b03) * bX - (a30 * b05 - a32 * b02 + a33 * b01) * bY + (a30 * b04 - a31 * b02 + a33 * b00) * bZ - (a30 * b03 - a31 * b01 + a32 * b00) * bW);_c4.w = det * -((a21 * b05 - a22 * b04 + a23 * b03) * bX - (a20 * b05 - a22 * b02 + a23 * b01) * bY + (a20 * b04 - a21 * b02 + a23 * b00) * bZ - (a20 * b03 - a21 * b01 + a22 * b00) * bW);_c4;_c3;_c2;_c1;
}

Matrix4 Matrix4Cls::tryInvert(Matrix4 other) {
    Unknown r = Matrix4Cls->zero();
    Unknown determinant = r->copyInverse(other);
    if (determinant == 0.0) {
        return nullptr;
    }
    return r;
}

int Matrix4Cls::index(int row, int col) {
    return (col * 4) + row;
}

double Matrix4Cls::entry(int row, int col) {
    assert((row >= 0) && ( < dimension()));
    assert((col >= 0) && ( < dimension()));
    return _m4storage[index(row, col)];
}

void Matrix4Cls::setEntry(int row, int col, double v) {
    assert((row >= 0) && ( < dimension()));
    assert((col >= 0) && ( < dimension()));
    _m4storage[index(row, col)] = v;
}

Matrix4Cls::Matrix4Cls(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8, double arg9, double arg10, double arg11, double arg12, double arg13, double arg14, double arg15) {
}

void Matrix4Cls::fromList(List<double> values) {
    return _c1;
}

void Matrix4Cls::zero()

void Matrix4Cls::identity() {
    return _c1;
}

void Matrix4Cls::copy(Matrix4 other) {
    return _c1;
}

void Matrix4Cls::inverted(Matrix4 other) {
    auto _c1 = Matrix4Cls->zero();_c1.setValues(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8], values[9], values[10], values[11], values[12], values[13], values[14], values[15]);auto _c1 = Matrix4Cls->zero();_c1.setIdentity();auto _c1 = Matrix4Cls->zero();_c1.setFrom(other);Unknown r = Matrix4Cls->zero();
    Unknown determinant = r->copyInverse(other);
    if (determinant == 0.0) {
        throw ArgumentErrorCls->value(other, __s("other"), __s("Matrix cannot be inverted"));
    }
    return r;
}

void Matrix4Cls::columns(Vector4 arg0, Vector4 arg1, Vector4 arg2, Vector4 arg3) {
    return _c1;
}

void Matrix4Cls::outer(Vector4 u, Vector4 v) {
    return _c1;
}

void Matrix4Cls::rotationX(double radians) {
    return _c1;
}

void Matrix4Cls::rotationY(double radians) {
    return _c1;
}

void Matrix4Cls::rotationZ(double radians) {
    return _c1;
}

void Matrix4Cls::translation(Vector3 translation) {
    return _c1;
}

void Matrix4Cls::translationValues(double x, double y, double z) {
    return _c1;
}

void Matrix4Cls::diagonal3(Vector3 scale) {
    auto _c1 = Matrix4Cls->zero();_c1.setColumns(arg0, arg1, arg2, arg3);auto _c1 = Matrix4Cls->zero();_c1.setOuter(u, v);auto _c1 = Matrix4Cls->zero();_c1[15] =auto _c2 = 1.0;_c2.setRotationX(radians);_c2;auto _c1 = Matrix4Cls->zero();_c1[15] =auto _c2 = 1.0;_c2.setRotationY(radians);_c2;auto _c1 = Matrix4Cls->zero();_c1[15] =auto _c2 = 1.0;_c2.setRotationZ(radians);_c2;auto _c1 = Matrix4Cls->zero();_c1.auto _c2 = setIdentity();_c2.setTranslation(translation);_c2;auto _c1 = Matrix4Cls->zero();_c1.auto _c2 = setIdentity();_c2.setTranslationRaw(x, y, z);_c2;Unknown m = Matrix4Cls->zero();
    Unknown mStorage = m->_m4storage;
    Unknown scaleStorage = scale->_v3storage;
    mStorage[15] = 1.0;
    mStorage[10] = scaleStorage[2];
    mStorage[5] = scaleStorage[1];
    mStorage[0] = scaleStorage[0];
    return m;
}

void Matrix4Cls::diagonal3Values(double x, double y, double z) {
    return _c1;
}

void Matrix4Cls::skewX(double alpha) {
    auto _c1 = Matrix4Cls->zero();_c1[15] =auto _c2 = 1.0;_c2[10] =auto _c3 = z;_c3[5] =auto _c4 = y;_c4[0] =x;_c4;_c3;_c2;Unknown m = Matrix4Cls->identity();
    m->_m4storage[4] = math->tan(alpha);
    return m;
}

void Matrix4Cls::skewY(double beta) {
    Unknown m = Matrix4Cls->identity();
    m->_m4storage[1] = math->tan(beta);
    return m;
}

void Matrix4Cls::skew(double alpha, double beta) {
    Unknown m = Matrix4Cls->identity();
    m->_m4storage[1] = math->tan(beta);
    m->_m4storage[4] = math->tan(alpha);
    return m;
}

void Matrix4Cls::fromBuffer(ByteBuffer buffer, int offset)

void Matrix4Cls::compose(Vector3 translation, Quaternion rotation, Vector3 scale) {
    return _c1;
}

void Matrix4Cls::splatDiagonal(double arg) {
    auto _c1 = Matrix4Cls->zero();_c1.setFromTranslationRotationScale(translation, rotation, scale);_m4storage[0] = arg;
    _m4storage[5] = arg;
    _m4storage[10] = arg;
    _m4storage[15] = arg;
}

void Matrix4Cls::setValues(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8, double arg9, double arg10, double arg11, double arg12, double arg13, double arg14, double arg15) {
    _m4storage[15] = arg15;
    _m4storage[14] = arg14;
    _m4storage[13] = arg13;
    _m4storage[12] = arg12;
    _m4storage[11] = arg11;
    _m4storage[10] = arg10;
    _m4storage[9] = arg9;
    _m4storage[8] = arg8;
    _m4storage[7] = arg7;
    _m4storage[6] = arg6;
    _m4storage[5] = arg5;
    _m4storage[4] = arg4;
    _m4storage[3] = arg3;
    _m4storage[2] = arg2;
    _m4storage[1] = arg1;
    _m4storage[0] = arg0;
}

void Matrix4Cls::setColumns(Vector4 arg0, Vector4 arg1, Vector4 arg2, Vector4 arg3) {
    Unknown arg0Storage = arg0->_v4storage;
    Unknown arg1Storage = arg1->_v4storage;
    Unknown arg2Storage = arg2->_v4storage;
    Unknown arg3Storage = arg3->_v4storage;
    _m4storage[0] = arg0Storage[0];
    _m4storage[1] = arg0Storage[1];
    _m4storage[2] = arg0Storage[2];
    _m4storage[3] = arg0Storage[3];
    _m4storage[4] = arg1Storage[0];
    _m4storage[5] = arg1Storage[1];
    _m4storage[6] = arg1Storage[2];
    _m4storage[7] = arg1Storage[3];
    _m4storage[8] = arg2Storage[0];
    _m4storage[9] = arg2Storage[1];
    _m4storage[10] = arg2Storage[2];
    _m4storage[11] = arg2Storage[3];
    _m4storage[12] = arg3Storage[0];
    _m4storage[13] = arg3Storage[1];
    _m4storage[14] = arg3Storage[2];
    _m4storage[15] = arg3Storage[3];
}

void Matrix4Cls::setFrom(Matrix4 arg) {
    Unknown argStorage = arg->_m4storage;
    _m4storage[15] = argStorage[15];
    _m4storage[14] = argStorage[14];
    _m4storage[13] = argStorage[13];
    _m4storage[12] = argStorage[12];
    _m4storage[11] = argStorage[11];
    _m4storage[10] = argStorage[10];
    _m4storage[9] = argStorage[9];
    _m4storage[8] = argStorage[8];
    _m4storage[7] = argStorage[7];
    _m4storage[6] = argStorage[6];
    _m4storage[5] = argStorage[5];
    _m4storage[4] = argStorage[4];
    _m4storage[3] = argStorage[3];
    _m4storage[2] = argStorage[2];
    _m4storage[1] = argStorage[1];
    _m4storage[0] = argStorage[0];
}

void Matrix4Cls::setFromTranslationRotation(Vector3 arg0, Quaternion arg1) {
    Unknown arg1Storage = arg1->_qStorage;
    Unknown x = arg1Storage[0];
    Unknown y = arg1Storage[1];
    Unknown z = arg1Storage[2];
    Unknown w = arg1Storage[3];
    Unknown x2 = x + x;
    Unknown y2 = y + y;
    Unknown z2 = z + z;
    Unknown xx = x * x2;
    Unknown xy = x * y2;
    Unknown xz = x * z2;
    Unknown yy = y * y2;
    Unknown yz = y * z2;
    Unknown zz = z * z2;
    Unknown wx = w * x2;
    Unknown wy = w * y2;
    Unknown wz = w * z2;
    Unknown arg0Storage = arg0->_v3storage;
    _m4storage[0] = 1.0 - (yy + zz);
    _m4storage[1] = xy + wz;
    _m4storage[2] = xz - wy;
    _m4storage[3] = 0.0;
    _m4storage[4] = xy - wz;
    _m4storage[5] = 1.0 - (xx + zz);
    _m4storage[6] = yz + wx;
    _m4storage[7] = 0.0;
    _m4storage[8] = xz + wy;
    _m4storage[9] = yz - wx;
    _m4storage[10] = 1.0 - (xx + yy);
    _m4storage[11] = 0.0;
    _m4storage[12] = arg0Storage[0];
    _m4storage[13] = arg0Storage[1];
    _m4storage[14] = arg0Storage[2];
    _m4storage[15] = 1.0;
}

void Matrix4Cls::setFromTranslationRotationScale(Vector3 translation, Quaternion rotation, Vector3 scale) {
    setFromTranslationRotation(translation, rotation);
    this->scale(scale);
}

void Matrix4Cls::setUpper2x2(Matrix2 arg) {
    Unknown argStorage = arg->_m2storage;
    _m4storage[0] = argStorage[0];
    _m4storage[1] = argStorage[1];
    _m4storage[4] = argStorage[2];
    _m4storage[5] = argStorage[3];
}

void Matrix4Cls::setDiagonal(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _m4storage[0] = argStorage[0];
    _m4storage[5] = argStorage[1];
    _m4storage[10] = argStorage[2];
    _m4storage[15] = argStorage[3];
}

void Matrix4Cls::setOuter(Vector4 u, Vector4 v) {
    Unknown uStorage = u->_v4storage;
    Unknown vStorage = v->_v4storage;
    _m4storage[0] = uStorage[0] * vStorage[0];
    _m4storage[1] = uStorage[0] * vStorage[1];
    _m4storage[2] = uStorage[0] * vStorage[2];
    _m4storage[3] = uStorage[0] * vStorage[3];
    _m4storage[4] = uStorage[1] * vStorage[0];
    _m4storage[5] = uStorage[1] * vStorage[1];
    _m4storage[6] = uStorage[1] * vStorage[2];
    _m4storage[7] = uStorage[1] * vStorage[3];
    _m4storage[8] = uStorage[2] * vStorage[0];
    _m4storage[9] = uStorage[2] * vStorage[1];
    _m4storage[10] = uStorage[2] * vStorage[2];
    _m4storage[11] = uStorage[2] * vStorage[3];
    _m4storage[12] = uStorage[3] * vStorage[0];
    _m4storage[13] = uStorage[3] * vStorage[1];
    _m4storage[14] = uStorage[3] * vStorage[2];
    _m4storage[15] = uStorage[3] * vStorage[3];
}

String Matrix4Cls::toString() {
    return __s("[0] ${getRow(0)}\n[1] ${getRow(1)}\n[2] ${getRow(2)}\n[3] ${getRow(3)}\n");
}

int Matrix4Cls::dimension() {
    return 4;
}

double Matrix4Cls::[](int i) {
    return _m4storage[i];
}

void Matrix4Cls::[]=(int i, double v) {
    _m4storage[i] = v;
}

bool Matrix4Cls::==(Object other) {
    return (is<Matrix4>(other)) && (_m4storage[0] == other->_m4storage[0]) && (_m4storage[1] == other->_m4storage[1]) && (_m4storage[2] == other->_m4storage[2]) && (_m4storage[3] == other->_m4storage[3]) && (_m4storage[4] == other->_m4storage[4]) && (_m4storage[5] == other->_m4storage[5]) && (_m4storage[6] == other->_m4storage[6]) && (_m4storage[7] == other->_m4storage[7]) && (_m4storage[8] == other->_m4storage[8]) && (_m4storage[9] == other->_m4storage[9]) && (_m4storage[10] == other->_m4storage[10]) && (_m4storage[11] == other->_m4storage[11]) && (_m4storage[12] == other->_m4storage[12]) && (_m4storage[13] == other->_m4storage[13]) && (_m4storage[14] == other->_m4storage[14]) && (_m4storage[15] == other->_m4storage[15]);
}

int Matrix4Cls::hashCode() {
    return ObjectCls->hashAll(_m4storage);
}

Vector4 Matrix4Cls::row0() {
    return getRow(0);
}

Vector4 Matrix4Cls::row1() {
    return getRow(1);
}

Vector4 Matrix4Cls::row2() {
    return getRow(2);
}

Vector4 Matrix4Cls::row3() {
    return getRow(3);
}

void Matrix4Cls::row0(Vector4 arg) {
    return setRow(0, arg);
}

void Matrix4Cls::row1(Vector4 arg) {
    return setRow(1, arg);
}

void Matrix4Cls::row2(Vector4 arg) {
    return setRow(2, arg);
}

void Matrix4Cls::row3(Vector4 arg) {
    return setRow(3, arg);
}

void Matrix4Cls::setRow(int row, Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _m4storage[index(row, 0)] = argStorage[0];
    _m4storage[index(row, 1)] = argStorage[1];
    _m4storage[index(row, 2)] = argStorage[2];
    _m4storage[index(row, 3)] = argStorage[3];
}

Vector4 Matrix4Cls::getRow(int row) {
    Unknown r = Vector4Cls->zero();
    Unknown rStorage = r->_v4storage;
    rStorage[0] = _m4storage[index(row, 0)];
    rStorage[1] = _m4storage[index(row, 1)];
    rStorage[2] = _m4storage[index(row, 2)];
    rStorage[3] = _m4storage[index(row, 3)];
    return r;
}

void Matrix4Cls::setColumn(int column, Vector4 arg) {
    Unknown entry = column * 4;
    Unknown argStorage = arg->_v4storage;
    _m4storage[entry + 3] = argStorage[3];
    _m4storage[entry + 2] = argStorage[2];
    _m4storage[entry + 1] = argStorage[1];
    _m4storage[entry + 0] = argStorage[0];
}

Vector4 Matrix4Cls::getColumn(int column) {
    Unknown r = Vector4Cls->zero();
    Unknown rStorage = r->_v4storage;
    Unknown entry = column * 4;
    rStorage[3] = _m4storage[entry + 3];
    rStorage[2] = _m4storage[entry + 2];
    rStorage[1] = _m4storage[entry + 1];
    rStorage[0] = _m4storage[entry + 0];
    return r;
}

Matrix4 Matrix4Cls::clone() {
    return Matrix4Cls->copy(this);
}

Matrix4 Matrix4Cls::copyInto(Matrix4 arg) {
    Unknown argStorage = arg->_m4storage;
    argStorage[0] = _m4storage[0];
    argStorage[1] = _m4storage[1];
    argStorage[2] = _m4storage[2];
    argStorage[3] = _m4storage[3];
    argStorage[4] = _m4storage[4];
    argStorage[5] = _m4storage[5];
    argStorage[6] = _m4storage[6];
    argStorage[7] = _m4storage[7];
    argStorage[8] = _m4storage[8];
    argStorage[9] = _m4storage[9];
    argStorage[10] = _m4storage[10];
    argStorage[11] = _m4storage[11];
    argStorage[12] = _m4storage[12];
    argStorage[13] = _m4storage[13];
    argStorage[14] = _m4storage[14];
    argStorage[15] = _m4storage[15];
    return arg;
}

Matrix4 Matrix4Cls::-() {
    return _c1;
}

dynamic Matrix4Cls::*(dynamic arg) {
    if (is<double>(arg)) {
            auto _c1 = clone();    _c1.negate();return scaled(as<doubleCls>(arg));
    }
    if (is<Vector4>(arg)) {
        return transformed(as<Vector4Cls>(arg));
    }
    if (is<Vector3>(arg)) {
        return transformed3(as<Vector3Cls>(arg));
    }
    if (is<Matrix4>(arg)) {
        return multiplied(as<Matrix4Cls>(arg));
    }
    throw make<ArgumentErrorCls>(arg);
}

Matrix4 Matrix4Cls::+(Matrix4 arg) {
    return _c1;
}

Matrix4 Matrix4Cls::-(Matrix4 arg) {
    return _c1;
}

void Matrix4Cls::translate(dynamic x, double y, double z) {
    auto _c1 = clone();_c1.add(arg);auto _c1 = clone();_c1.sub(arg);double tx;
    double ty;
    double tz;
    Unknown tw = is<Vector4>(x)? x->w : 1.0;
    if (is<Vector3>(x)) {
        tx = as<Vector3Cls>(x)->as<Vector3Cls>(x);
        ty = as<Vector3Cls>(x)->y;
        tz = as<Vector3Cls>(x)->z;
    } else     {
        if (is<Vector4>(x)) {
        tx = as<Vector4Cls>(x)->as<Vector4Cls>(x);
        ty = as<Vector4Cls>(x)->y;
        tz = as<Vector4Cls>(x)->z;
    } else     {
        if (is<double>(x)) {
        tx = as<doubleCls>(x);
        ty = y;
        tz = z;
    } else {
        throw make<UnimplementedErrorCls>();
    }
;
    };
    }    Unknown t1 = _m4storage[0] * tx + _m4storage[4] * ty + _m4storage[8] * tz + _m4storage[12] * tw;
    Unknown t2 = _m4storage[1] * tx + _m4storage[5] * ty + _m4storage[9] * tz + _m4storage[13] * tw;
    Unknown t3 = _m4storage[2] * tx + _m4storage[6] * ty + _m4storage[10] * tz + _m4storage[14] * tw;
    Unknown t4 = _m4storage[3] * tx + _m4storage[7] * ty + _m4storage[11] * tz + _m4storage[15] * tw;
    _m4storage[12] = t1;
    _m4storage[13] = t2;
    _m4storage[14] = t3;
    _m4storage[15] = t4;
}

void Matrix4Cls::leftTranslate(dynamic x, double y, double z) {
    double tx;
    double ty;
    double tz;
    Unknown tw = is<Vector4>(x)? x->w : 1.0;
    if (is<Vector3>(x)) {
        tx = as<Vector3Cls>(x)->as<Vector3Cls>(x);
        ty = as<Vector3Cls>(x)->y;
        tz = as<Vector3Cls>(x)->z;
    } else     {
        if (is<Vector4>(x)) {
        tx = as<Vector4Cls>(x)->as<Vector4Cls>(x);
        ty = as<Vector4Cls>(x)->y;
        tz = as<Vector4Cls>(x)->z;
    } else     {
        if (is<double>(x)) {
        tx = as<doubleCls>(x);
        ty = y;
        tz = z;
    } else {
        throw make<UnimplementedErrorCls>();
    }
;
    };
    }    _m4storage[0] += tx * _m4storage[3];
    _m4storage[1] += ty * _m4storage[3];
    _m4storage[2] += tz * _m4storage[3];
    _m4storage[3] = tw * _m4storage[3];
    _m4storage[4] += tx * _m4storage[7];
    _m4storage[5] += ty * _m4storage[7];
    _m4storage[6] += tz * _m4storage[7];
    _m4storage[7] = tw * _m4storage[7];
    _m4storage[8] += tx * _m4storage[11];
    _m4storage[9] += ty * _m4storage[11];
    _m4storage[10] += tz * _m4storage[11];
    _m4storage[11] = tw * _m4storage[11];
    _m4storage[12] += tx * _m4storage[15];
    _m4storage[13] += ty * _m4storage[15];
    _m4storage[14] += tz * _m4storage[15];
    _m4storage[15] = tw * _m4storage[15];
}

void Matrix4Cls::rotate(Vector3 axis, double angle) {
    Unknown len = axis->length;
    Unknown axisStorage = axis->_v3storage;
    Unknown x = axisStorage[0] / len;
    Unknown y = axisStorage[1] / len;
    Unknown z = axisStorage[2] / len;
    Unknown c = math->cos(angle);
    Unknown s = math->sin(angle);
    Unknown C = 1.0 - c;
    Unknown m11 = x * x * C + c;
    Unknown m12 = x * y * C - z * s;
    Unknown m13 = x * z * C + y * s;
    Unknown m21 = y * x * C + z * s;
    Unknown m22 = y * y * C + c;
    Unknown m23 = y * z * C - x * s;
    Unknown m31 = z * x * C - y * s;
    Unknown m32 = z * y * C + x * s;
    Unknown m33 = z * z * C + c;
    Unknown t1 = _m4storage[0] * m11 + _m4storage[4] * m21 + _m4storage[8] * m31;
    Unknown t2 = _m4storage[1] * m11 + _m4storage[5] * m21 + _m4storage[9] * m31;
    Unknown t3 = _m4storage[2] * m11 + _m4storage[6] * m21 + _m4storage[10] * m31;
    Unknown t4 = _m4storage[3] * m11 + _m4storage[7] * m21 + _m4storage[11] * m31;
    Unknown t5 = _m4storage[0] * m12 + _m4storage[4] * m22 + _m4storage[8] * m32;
    Unknown t6 = _m4storage[1] * m12 + _m4storage[5] * m22 + _m4storage[9] * m32;
    Unknown t7 = _m4storage[2] * m12 + _m4storage[6] * m22 + _m4storage[10] * m32;
    Unknown t8 = _m4storage[3] * m12 + _m4storage[7] * m22 + _m4storage[11] * m32;
    Unknown t9 = _m4storage[0] * m13 + _m4storage[4] * m23 + _m4storage[8] * m33;
    Unknown t10 = _m4storage[1] * m13 + _m4storage[5] * m23 + _m4storage[9] * m33;
    Unknown t11 = _m4storage[2] * m13 + _m4storage[6] * m23 + _m4storage[10] * m33;
    Unknown t12 = _m4storage[3] * m13 + _m4storage[7] * m23 + _m4storage[11] * m33;
    _m4storage[0] = t1;
    _m4storage[1] = t2;
    _m4storage[2] = t3;
    _m4storage[3] = t4;
    _m4storage[4] = t5;
    _m4storage[5] = t6;
    _m4storage[6] = t7;
    _m4storage[7] = t8;
    _m4storage[8] = t9;
    _m4storage[9] = t10;
    _m4storage[10] = t11;
    _m4storage[11] = t12;
}

void Matrix4Cls::rotateX(double angle) {
    Unknown cosAngle = math->cos(angle);
    Unknown sinAngle = math->sin(angle);
    Unknown t1 = _m4storage[4] * cosAngle + _m4storage[8] * sinAngle;
    Unknown t2 = _m4storage[5] * cosAngle + _m4storage[9] * sinAngle;
    Unknown t3 = _m4storage[6] * cosAngle + _m4storage[10] * sinAngle;
    Unknown t4 = _m4storage[7] * cosAngle + _m4storage[11] * sinAngle;
    Unknown t5 = _m4storage[4] * -sinAngle + _m4storage[8] * cosAngle;
    Unknown t6 = _m4storage[5] * -sinAngle + _m4storage[9] * cosAngle;
    Unknown t7 = _m4storage[6] * -sinAngle + _m4storage[10] * cosAngle;
    Unknown t8 = _m4storage[7] * -sinAngle + _m4storage[11] * cosAngle;
    _m4storage[4] = t1;
    _m4storage[5] = t2;
    _m4storage[6] = t3;
    _m4storage[7] = t4;
    _m4storage[8] = t5;
    _m4storage[9] = t6;
    _m4storage[10] = t7;
    _m4storage[11] = t8;
}

void Matrix4Cls::rotateY(double angle) {
    Unknown cosAngle = math->cos(angle);
    Unknown sinAngle = math->sin(angle);
    Unknown t1 = _m4storage[0] * cosAngle + _m4storage[8] * -sinAngle;
    Unknown t2 = _m4storage[1] * cosAngle + _m4storage[9] * -sinAngle;
    Unknown t3 = _m4storage[2] * cosAngle + _m4storage[10] * -sinAngle;
    Unknown t4 = _m4storage[3] * cosAngle + _m4storage[11] * -sinAngle;
    Unknown t5 = _m4storage[0] * sinAngle + _m4storage[8] * cosAngle;
    Unknown t6 = _m4storage[1] * sinAngle + _m4storage[9] * cosAngle;
    Unknown t7 = _m4storage[2] * sinAngle + _m4storage[10] * cosAngle;
    Unknown t8 = _m4storage[3] * sinAngle + _m4storage[11] * cosAngle;
    _m4storage[0] = t1;
    _m4storage[1] = t2;
    _m4storage[2] = t3;
    _m4storage[3] = t4;
    _m4storage[8] = t5;
    _m4storage[9] = t6;
    _m4storage[10] = t7;
    _m4storage[11] = t8;
}

void Matrix4Cls::rotateZ(double angle) {
    Unknown cosAngle = math->cos(angle);
    Unknown sinAngle = math->sin(angle);
    Unknown t1 = _m4storage[0] * cosAngle + _m4storage[4] * sinAngle;
    Unknown t2 = _m4storage[1] * cosAngle + _m4storage[5] * sinAngle;
    Unknown t3 = _m4storage[2] * cosAngle + _m4storage[6] * sinAngle;
    Unknown t4 = _m4storage[3] * cosAngle + _m4storage[7] * sinAngle;
    Unknown t5 = _m4storage[0] * -sinAngle + _m4storage[4] * cosAngle;
    Unknown t6 = _m4storage[1] * -sinAngle + _m4storage[5] * cosAngle;
    Unknown t7 = _m4storage[2] * -sinAngle + _m4storage[6] * cosAngle;
    Unknown t8 = _m4storage[3] * -sinAngle + _m4storage[7] * cosAngle;
    _m4storage[0] = t1;
    _m4storage[1] = t2;
    _m4storage[2] = t3;
    _m4storage[3] = t4;
    _m4storage[4] = t5;
    _m4storage[5] = t6;
    _m4storage[6] = t7;
    _m4storage[7] = t8;
}

void Matrix4Cls::scale(dynamic x, double y, double z) {
    double sx;
    double sy;
    double sz;
    Unknown sw = is<Vector4>(x)? x->w : 1.0;
    if (is<Vector3>(x)) {
        sx = as<Vector3Cls>(x)->as<Vector3Cls>(x);
        sy = as<Vector3Cls>(x)->y;
        sz = as<Vector3Cls>(x)->z;
    } else     {
        if (is<Vector4>(x)) {
        sx = as<Vector4Cls>(x)->as<Vector4Cls>(x);
        sy = as<Vector4Cls>(x)->y;
        sz = as<Vector4Cls>(x)->z;
    } else     {
        if (is<double>(x)) {
        sx = as<doubleCls>(x);
        sy = y | as<doubleCls>(x);
        sz = z | as<doubleCls>(x);
    } else {
        throw make<UnimplementedErrorCls>();
    }
;
    };
    }    _m4storage[0] *= sx;
    _m4storage[1] *= sx;
    _m4storage[2] *= sx;
    _m4storage[3] *= sx;
    _m4storage[4] *= sy;
    _m4storage[5] *= sy;
    _m4storage[6] *= sy;
    _m4storage[7] *= sy;
    _m4storage[8] *= sz;
    _m4storage[9] *= sz;
    _m4storage[10] *= sz;
    _m4storage[11] *= sz;
    _m4storage[12] *= sw;
    _m4storage[13] *= sw;
    _m4storage[14] *= sw;
    _m4storage[15] *= sw;
}

Matrix4 Matrix4Cls::scaled(dynamic x, double y, double z) {
    return _c1;
}

void Matrix4Cls::setZero() {
    auto _c1 = clone();_c1.scale(x, y, z);_m4storage[0] = 0.0;
    _m4storage[1] = 0.0;
    _m4storage[2] = 0.0;
    _m4storage[3] = 0.0;
    _m4storage[4] = 0.0;
    _m4storage[5] = 0.0;
    _m4storage[6] = 0.0;
    _m4storage[7] = 0.0;
    _m4storage[8] = 0.0;
    _m4storage[9] = 0.0;
    _m4storage[10] = 0.0;
    _m4storage[11] = 0.0;
    _m4storage[12] = 0.0;
    _m4storage[13] = 0.0;
    _m4storage[14] = 0.0;
    _m4storage[15] = 0.0;
}

void Matrix4Cls::setIdentity() {
    _m4storage[0] = 1.0;
    _m4storage[1] = 0.0;
    _m4storage[2] = 0.0;
    _m4storage[3] = 0.0;
    _m4storage[4] = 0.0;
    _m4storage[5] = 1.0;
    _m4storage[6] = 0.0;
    _m4storage[7] = 0.0;
    _m4storage[8] = 0.0;
    _m4storage[9] = 0.0;
    _m4storage[10] = 1.0;
    _m4storage[11] = 0.0;
    _m4storage[12] = 0.0;
    _m4storage[13] = 0.0;
    _m4storage[14] = 0.0;
    _m4storage[15] = 1.0;
}

Matrix4 Matrix4Cls::transposed() {
    return _c1;
}

void Matrix4Cls::transpose() {
    auto _c1 = clone();_c1.transpose();double temp;
    temp = _m4storage[4];
    _m4storage[4] = _m4storage[1];
    _m4storage[1] = temp;
    temp = _m4storage[8];
    _m4storage[8] = _m4storage[2];
    _m4storage[2] = temp;
    temp = _m4storage[12];
    _m4storage[12] = _m4storage[3];
    _m4storage[3] = temp;
    temp = _m4storage[9];
    _m4storage[9] = _m4storage[6];
    _m4storage[6] = temp;
    temp = _m4storage[13];
    _m4storage[13] = _m4storage[7];
    _m4storage[7] = temp;
    temp = _m4storage[14];
    _m4storage[14] = _m4storage[11];
    _m4storage[11] = temp;
}

Matrix4 Matrix4Cls::absolute() {
    Unknown r = Matrix4Cls->zero();
    Unknown rStorage = r->_m4storage;
    rStorage[0] = _m4storage[0]->abs();
    rStorage[1] = _m4storage[1]->abs();
    rStorage[2] = _m4storage[2]->abs();
    rStorage[3] = _m4storage[3]->abs();
    rStorage[4] = _m4storage[4]->abs();
    rStorage[5] = _m4storage[5]->abs();
    rStorage[6] = _m4storage[6]->abs();
    rStorage[7] = _m4storage[7]->abs();
    rStorage[8] = _m4storage[8]->abs();
    rStorage[9] = _m4storage[9]->abs();
    rStorage[10] = _m4storage[10]->abs();
    rStorage[11] = _m4storage[11]->abs();
    rStorage[12] = _m4storage[12]->abs();
    rStorage[13] = _m4storage[13]->abs();
    rStorage[14] = _m4storage[14]->abs();
    rStorage[15] = _m4storage[15]->abs();
    return r;
}

double Matrix4Cls::determinant() {
    Unknown det2_01_01 = _m4storage[0] * _m4storage[5] - _m4storage[1] * _m4storage[4];
    Unknown det2_01_02 = _m4storage[0] * _m4storage[6] - _m4storage[2] * _m4storage[4];
    Unknown det2_01_03 = _m4storage[0] * _m4storage[7] - _m4storage[3] * _m4storage[4];
    Unknown det2_01_12 = _m4storage[1] * _m4storage[6] - _m4storage[2] * _m4storage[5];
    Unknown det2_01_13 = _m4storage[1] * _m4storage[7] - _m4storage[3] * _m4storage[5];
    Unknown det2_01_23 = _m4storage[2] * _m4storage[7] - _m4storage[3] * _m4storage[6];
    Unknown det3_201_012 = _m4storage[8] * det2_01_12 - _m4storage[9] * det2_01_02 + _m4storage[10] * det2_01_01;
    Unknown det3_201_013 = _m4storage[8] * det2_01_13 - _m4storage[9] * det2_01_03 + _m4storage[11] * det2_01_01;
    Unknown det3_201_023 = _m4storage[8] * det2_01_23 - _m4storage[10] * det2_01_03 + _m4storage[11] * det2_01_02;
    Unknown det3_201_123 = _m4storage[9] * det2_01_23 - _m4storage[10] * det2_01_13 + _m4storage[11] * det2_01_12;
    return -det3_201_123 * _m4storage[12] + det3_201_023 * _m4storage[13] - det3_201_013 * _m4storage[14] + det3_201_012 * _m4storage[15];
}

double Matrix4Cls::dotRow(int i, Vector4 v) {
    Unknown vStorage = v->_v4storage;
    return _m4storage[i] * vStorage[0] + _m4storage[4 + i] * vStorage[1] + _m4storage[8 + i] * vStorage[2] + _m4storage[12 + i] * vStorage[3];
}

double Matrix4Cls::dotColumn(int j, Vector4 v) {
    Unknown vStorage = v->_v4storage;
    return _m4storage[j * 4] * vStorage[0] + _m4storage[j * 4 + 1] * vStorage[1] + _m4storage[j * 4 + 2] * vStorage[2] + _m4storage[j * 4 + 3] * vStorage[3];
}

double Matrix4Cls::trace() {
    auto t = 0.0;
    t += _m4storage[0];
    t += _m4storage[5];
    t += _m4storage[10];
    t += _m4storage[15];
    return t;
}

double Matrix4Cls::infinityNorm() {
    auto norm = 0.0;
    {
        auto row_norm = 0.0;
        row_norm += _m4storage[0]->abs();
        row_norm += _m4storage[1]->abs();
        row_norm += _m4storage[2]->abs();
        row_norm += _m4storage[3]->abs();
        norm = row_norm > norm? row_norm : norm;
    }    {
        auto row_norm = 0.0;
        row_norm += _m4storage[4]->abs();
        row_norm += _m4storage[5]->abs();
        row_norm += _m4storage[6]->abs();
        row_norm += _m4storage[7]->abs();
        norm = row_norm > norm? row_norm : norm;
    }    {
        auto row_norm = 0.0;
        row_norm += _m4storage[8]->abs();
        row_norm += _m4storage[9]->abs();
        row_norm += _m4storage[10]->abs();
        row_norm += _m4storage[11]->abs();
        norm = row_norm > norm? row_norm : norm;
    }    {
        auto row_norm = 0.0;
        row_norm += _m4storage[12]->abs();
        row_norm += _m4storage[13]->abs();
        row_norm += _m4storage[14]->abs();
        row_norm += _m4storage[15]->abs();
        norm = row_norm > norm? row_norm : norm;
    }    return norm;
}

double Matrix4Cls::relativeError(Matrix4 correct) {
    Unknown diff = correct - this;
    Unknown correct_norm = correct->infinityNorm();
    Unknown diff_norm = diff->infinityNorm();
    return diff_norm / correct_norm;
}

double Matrix4Cls::absoluteError(Matrix4 correct) {
    Unknown this_norm = infinityNorm();
    Unknown correct_norm = correct->infinityNorm();
    Unknown diff_norm = (this_norm - correct_norm)->abs();
    return diff_norm;
}

Vector3 Matrix4Cls::getTranslation() {
    Unknown z = _m4storage[14];
    Unknown y = _m4storage[13];
    Unknown x = _m4storage[12];
    return make<Vector3Cls>(x, y, z);
}

void Matrix4Cls::setTranslation(Vector3 t) {
    Unknown tStorage = t->_v3storage;
    Unknown z = tStorage[2];
    Unknown y = tStorage[1];
    Unknown x = tStorage[0];
    _m4storage[14] = z;
    _m4storage[13] = y;
    _m4storage[12] = x;
}

void Matrix4Cls::setTranslationRaw(double x, double y, double z) {
    _m4storage[14] = z;
    _m4storage[13] = y;
    _m4storage[12] = x;
}

Matrix3 Matrix4Cls::getRotation() {
    Unknown r = Matrix3Cls->zero();
    copyRotation(r);
    return r;
}

void Matrix4Cls::copyRotation(Matrix3 rotation) {
    Unknown rStorage = rotation->_m3storage;
    rStorage[0] = _m4storage[0];
    rStorage[1] = _m4storage[1];
    rStorage[2] = _m4storage[2];
    rStorage[3] = _m4storage[4];
    rStorage[4] = _m4storage[5];
    rStorage[5] = _m4storage[6];
    rStorage[6] = _m4storage[8];
    rStorage[7] = _m4storage[9];
    rStorage[8] = _m4storage[10];
}

void Matrix4Cls::setRotation(Matrix3 r) {
    Unknown rStorage = r->_m3storage;
    _m4storage[0] = rStorage[0];
    _m4storage[1] = rStorage[1];
    _m4storage[2] = rStorage[2];
    _m4storage[4] = rStorage[3];
    _m4storage[5] = rStorage[4];
    _m4storage[6] = rStorage[5];
    _m4storage[8] = rStorage[6];
    _m4storage[9] = rStorage[7];
    _m4storage[10] = rStorage[8];
}

Matrix3 Matrix4Cls::getNormalMatrix() {
    return _c1;
}

double Matrix4Cls::getMaxScaleOnAxis() {
    auto _c1 = Matrix3Cls->identity();_c1.copyNormalMatrix(this);Unknown scaleXSq = _m4storage[0] * _m4storage[0] + _m4storage[1] * _m4storage[1] + _m4storage[2] * _m4storage[2];
    Unknown scaleYSq = _m4storage[4] * _m4storage[4] + _m4storage[5] * _m4storage[5] + _m4storage[6] * _m4storage[6];
    Unknown scaleZSq = _m4storage[8] * _m4storage[8] + _m4storage[9] * _m4storage[9] + _m4storage[10] * _m4storage[10];
    return math->sqrt(math->max(scaleXSq, math->max(scaleYSq, scaleZSq)));
}

void Matrix4Cls::transposeRotation() {
    double temp;
    temp = _m4storage[1];
    _m4storage[1] = _m4storage[4];
    _m4storage[4] = temp;
    temp = _m4storage[2];
    _m4storage[2] = _m4storage[8];
    _m4storage[8] = temp;
    temp = _m4storage[4];
    _m4storage[4] = _m4storage[1];
    _m4storage[1] = temp;
    temp = _m4storage[6];
    _m4storage[6] = _m4storage[9];
    _m4storage[9] = temp;
    temp = _m4storage[8];
    _m4storage[8] = _m4storage[2];
    _m4storage[2] = temp;
    temp = _m4storage[9];
    _m4storage[9] = _m4storage[6];
    _m4storage[6] = temp;
}

double Matrix4Cls::invert() {
    return copyInverse(this);
}

double Matrix4Cls::copyInverse(Matrix4 arg) {
    Unknown argStorage = arg->_m4storage;
    Unknown a00 = argStorage[0];
    Unknown a01 = argStorage[1];
    Unknown a02 = argStorage[2];
    Unknown a03 = argStorage[3];
    Unknown a10 = argStorage[4];
    Unknown a11 = argStorage[5];
    Unknown a12 = argStorage[6];
    Unknown a13 = argStorage[7];
    Unknown a20 = argStorage[8];
    Unknown a21 = argStorage[9];
    Unknown a22 = argStorage[10];
    Unknown a23 = argStorage[11];
    Unknown a30 = argStorage[12];
    Unknown a31 = argStorage[13];
    Unknown a32 = argStorage[14];
    Unknown a33 = argStorage[15];
    Unknown b00 = a00 * a11 - a01 * a10;
    Unknown b01 = a00 * a12 - a02 * a10;
    Unknown b02 = a00 * a13 - a03 * a10;
    Unknown b03 = a01 * a12 - a02 * a11;
    Unknown b04 = a01 * a13 - a03 * a11;
    Unknown b05 = a02 * a13 - a03 * a12;
    Unknown b06 = a20 * a31 - a21 * a30;
    Unknown b07 = a20 * a32 - a22 * a30;
    Unknown b08 = a20 * a33 - a23 * a30;
    Unknown b09 = a21 * a32 - a22 * a31;
    Unknown b10 = a21 * a33 - a23 * a31;
    Unknown b11 = a22 * a33 - a23 * a32;
    Unknown det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    if (det == 0.0) {
        setFrom(arg);
        return 0.0;
    }
    Unknown invDet = 1.0 / det;
    _m4storage[0] = (a11 * b11 - a12 * b10 + a13 * b09) * invDet;
    _m4storage[1] = (-a01 * b11 + a02 * b10 - a03 * b09) * invDet;
    _m4storage[2] = (a31 * b05 - a32 * b04 + a33 * b03) * invDet;
    _m4storage[3] = (-a21 * b05 + a22 * b04 - a23 * b03) * invDet;
    _m4storage[4] = (-a10 * b11 + a12 * b08 - a13 * b07) * invDet;
    _m4storage[5] = (a00 * b11 - a02 * b08 + a03 * b07) * invDet;
    _m4storage[6] = (-a30 * b05 + a32 * b02 - a33 * b01) * invDet;
    _m4storage[7] = (a20 * b05 - a22 * b02 + a23 * b01) * invDet;
    _m4storage[8] = (a10 * b10 - a11 * b08 + a13 * b06) * invDet;
    _m4storage[9] = (-a00 * b10 + a01 * b08 - a03 * b06) * invDet;
    _m4storage[10] = (a30 * b04 - a31 * b02 + a33 * b00) * invDet;
    _m4storage[11] = (-a20 * b04 + a21 * b02 - a23 * b00) * invDet;
    _m4storage[12] = (-a10 * b09 + a11 * b07 - a12 * b06) * invDet;
    _m4storage[13] = (a00 * b09 - a01 * b07 + a02 * b06) * invDet;
    _m4storage[14] = (-a30 * b03 + a31 * b01 - a32 * b00) * invDet;
    _m4storage[15] = (a20 * b03 - a21 * b01 + a22 * b00) * invDet;
    return det;
}

double Matrix4Cls::invertRotation() {
    Unknown det = determinant();
    if (det == 0.0) {
        return 0.0;
    }
    Unknown invDet = 1.0 / det;
    double ix;
    double iy;
    double iz;
    double jx;
    double jy;
    double jz;
    double kx;
    double ky;
    double kz;
    ix = invDet * (_m4storage[5] * _m4storage[10] - _m4storage[6] * _m4storage[9]);
    iy = invDet * (_m4storage[2] * _m4storage[9] - _m4storage[1] * _m4storage[10]);
    iz = invDet * (_m4storage[1] * _m4storage[6] - _m4storage[2] * _m4storage[5]);
    jx = invDet * (_m4storage[6] * _m4storage[8] - _m4storage[4] * _m4storage[10]);
    jy = invDet * (_m4storage[0] * _m4storage[10] - _m4storage[2] * _m4storage[8]);
    jz = invDet * (_m4storage[2] * _m4storage[4] - _m4storage[0] * _m4storage[6]);
    kx = invDet * (_m4storage[4] * _m4storage[9] - _m4storage[5] * _m4storage[8]);
    ky = invDet * (_m4storage[1] * _m4storage[8] - _m4storage[0] * _m4storage[9]);
    kz = invDet * (_m4storage[0] * _m4storage[5] - _m4storage[1] * _m4storage[4]);
    _m4storage[0] = ix;
    _m4storage[1] = iy;
    _m4storage[2] = iz;
    _m4storage[4] = jx;
    _m4storage[5] = jy;
    _m4storage[6] = jz;
    _m4storage[8] = kx;
    _m4storage[9] = ky;
    _m4storage[10] = kz;
    return det;
}

void Matrix4Cls::setRotationX(double radians) {
    Unknown c = math->cos(radians);
    Unknown s = math->sin(radians);
    _m4storage[0] = 1.0;
    _m4storage[1] = 0.0;
    _m4storage[2] = 0.0;
    _m4storage[4] = 0.0;
    _m4storage[5] = c;
    _m4storage[6] = s;
    _m4storage[8] = 0.0;
    _m4storage[9] = -s;
    _m4storage[10] = c;
    _m4storage[3] = 0.0;
    _m4storage[7] = 0.0;
    _m4storage[11] = 0.0;
}

void Matrix4Cls::setRotationY(double radians) {
    Unknown c = math->cos(radians);
    Unknown s = math->sin(radians);
    _m4storage[0] = c;
    _m4storage[1] = 0.0;
    _m4storage[2] = -s;
    _m4storage[4] = 0.0;
    _m4storage[5] = 1.0;
    _m4storage[6] = 0.0;
    _m4storage[8] = s;
    _m4storage[9] = 0.0;
    _m4storage[10] = c;
    _m4storage[3] = 0.0;
    _m4storage[7] = 0.0;
    _m4storage[11] = 0.0;
}

void Matrix4Cls::setRotationZ(double radians) {
    Unknown c = math->cos(radians);
    Unknown s = math->sin(radians);
    _m4storage[0] = c;
    _m4storage[1] = s;
    _m4storage[2] = 0.0;
    _m4storage[4] = -s;
    _m4storage[5] = c;
    _m4storage[6] = 0.0;
    _m4storage[8] = 0.0;
    _m4storage[9] = 0.0;
    _m4storage[10] = 1.0;
    _m4storage[3] = 0.0;
    _m4storage[7] = 0.0;
    _m4storage[11] = 0.0;
}

void Matrix4Cls::scaleAdjoint(double scale) {
    Unknown a1 = _m4storage[0];
    Unknown b1 = _m4storage[4];
    Unknown c1 = _m4storage[8];
    Unknown d1 = _m4storage[12];
    Unknown a2 = _m4storage[1];
    Unknown b2 = _m4storage[5];
    Unknown c2 = _m4storage[9];
    Unknown d2 = _m4storage[13];
    Unknown a3 = _m4storage[2];
    Unknown b3 = _m4storage[6];
    Unknown c3 = _m4storage[10];
    Unknown d3 = _m4storage[14];
    Unknown a4 = _m4storage[3];
    Unknown b4 = _m4storage[7];
    Unknown c4 = _m4storage[11];
    Unknown d4 = _m4storage[15];
    _m4storage[0] = (b2 * (c3 * d4 - c4 * d3) - c2 * (b3 * d4 - b4 * d3) + d2 * (b3 * c4 - b4 * c3)) * scale;
    _m4storage[1] = -(a2 * (c3 * d4 - c4 * d3) - c2 * (a3 * d4 - a4 * d3) + d2 * (a3 * c4 - a4 * c3)) * scale;
    _m4storage[2] = (a2 * (b3 * d4 - b4 * d3) - b2 * (a3 * d4 - a4 * d3) + d2 * (a3 * b4 - a4 * b3)) * scale;
    _m4storage[3] = -(a2 * (b3 * c4 - b4 * c3) - b2 * (a3 * c4 - a4 * c3) + c2 * (a3 * b4 - a4 * b3)) * scale;
    _m4storage[4] = -(b1 * (c3 * d4 - c4 * d3) - c1 * (b3 * d4 - b4 * d3) + d1 * (b3 * c4 - b4 * c3)) * scale;
    _m4storage[5] = (a1 * (c3 * d4 - c4 * d3) - c1 * (a3 * d4 - a4 * d3) + d1 * (a3 * c4 - a4 * c3)) * scale;
    _m4storage[6] = -(a1 * (b3 * d4 - b4 * d3) - b1 * (a3 * d4 - a4 * d3) + d1 * (a3 * b4 - a4 * b3)) * scale;
    _m4storage[7] = (a1 * (b3 * c4 - b4 * c3) - b1 * (a3 * c4 - a4 * c3) + c1 * (a3 * b4 - a4 * b3)) * scale;
    _m4storage[8] = (b1 * (c2 * d4 - c4 * d2) - c1 * (b2 * d4 - b4 * d2) + d1 * (b2 * c4 - b4 * c2)) * scale;
    _m4storage[9] = -(a1 * (c2 * d4 - c4 * d2) - c1 * (a2 * d4 - a4 * d2) + d1 * (a2 * c4 - a4 * c2)) * scale;
    _m4storage[10] = (a1 * (b2 * d4 - b4 * d2) - b1 * (a2 * d4 - a4 * d2) + d1 * (a2 * b4 - a4 * b2)) * scale;
    _m4storage[11] = -(a1 * (b2 * c4 - b4 * c2) - b1 * (a2 * c4 - a4 * c2) + c1 * (a2 * b4 - a4 * b2)) * scale;
    _m4storage[12] = -(b1 * (c2 * d3 - c3 * d2) - c1 * (b2 * d3 - b3 * d2) + d1 * (b2 * c3 - b3 * c2)) * scale;
    _m4storage[13] = (a1 * (c2 * d3 - c3 * d2) - c1 * (a2 * d3 - a3 * d2) + d1 * (a2 * c3 - a3 * c2)) * scale;
    _m4storage[14] = -(a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) * scale;
    _m4storage[15] = (a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2)) * scale;
}

Vector3 Matrix4Cls::absoluteRotate(Vector3 arg) {
    Unknown m00 = _m4storage[0]->abs();
    Unknown m01 = _m4storage[4]->abs();
    Unknown m02 = _m4storage[8]->abs();
    Unknown m10 = _m4storage[1]->abs();
    Unknown m11 = _m4storage[5]->abs();
    Unknown m12 = _m4storage[9]->abs();
    Unknown m20 = _m4storage[2]->abs();
    Unknown m21 = _m4storage[6]->abs();
    Unknown m22 = _m4storage[10]->abs();
    Unknown argStorage = arg->_v3storage;
    Unknown x = argStorage[0];
    Unknown y = argStorage[1];
    Unknown z = argStorage[2];
    argStorage[0] = x * m00 + y * m01 + z * m02 + 0.0 * 0.0;
    argStorage[1] = x * m10 + y * m11 + z * m12 + 0.0 * 0.0;
    argStorage[2] = x * m20 + y * m21 + z * m22 + 0.0 * 0.0;
    return arg;
}

void Matrix4Cls::add(Matrix4 o) {
    Unknown oStorage = o->_m4storage;
    _m4storage[0] = _m4storage[0] + oStorage[0];
    _m4storage[1] = _m4storage[1] + oStorage[1];
    _m4storage[2] = _m4storage[2] + oStorage[2];
    _m4storage[3] = _m4storage[3] + oStorage[3];
    _m4storage[4] = _m4storage[4] + oStorage[4];
    _m4storage[5] = _m4storage[5] + oStorage[5];
    _m4storage[6] = _m4storage[6] + oStorage[6];
    _m4storage[7] = _m4storage[7] + oStorage[7];
    _m4storage[8] = _m4storage[8] + oStorage[8];
    _m4storage[9] = _m4storage[9] + oStorage[9];
    _m4storage[10] = _m4storage[10] + oStorage[10];
    _m4storage[11] = _m4storage[11] + oStorage[11];
    _m4storage[12] = _m4storage[12] + oStorage[12];
    _m4storage[13] = _m4storage[13] + oStorage[13];
    _m4storage[14] = _m4storage[14] + oStorage[14];
    _m4storage[15] = _m4storage[15] + oStorage[15];
}

void Matrix4Cls::sub(Matrix4 o) {
    Unknown oStorage = o->_m4storage;
    _m4storage[0] = _m4storage[0] - oStorage[0];
    _m4storage[1] = _m4storage[1] - oStorage[1];
    _m4storage[2] = _m4storage[2] - oStorage[2];
    _m4storage[3] = _m4storage[3] - oStorage[3];
    _m4storage[4] = _m4storage[4] - oStorage[4];
    _m4storage[5] = _m4storage[5] - oStorage[5];
    _m4storage[6] = _m4storage[6] - oStorage[6];
    _m4storage[7] = _m4storage[7] - oStorage[7];
    _m4storage[8] = _m4storage[8] - oStorage[8];
    _m4storage[9] = _m4storage[9] - oStorage[9];
    _m4storage[10] = _m4storage[10] - oStorage[10];
    _m4storage[11] = _m4storage[11] - oStorage[11];
    _m4storage[12] = _m4storage[12] - oStorage[12];
    _m4storage[13] = _m4storage[13] - oStorage[13];
    _m4storage[14] = _m4storage[14] - oStorage[14];
    _m4storage[15] = _m4storage[15] - oStorage[15];
}

void Matrix4Cls::negate() {
    _m4storage[0] = -_m4storage[0];
    _m4storage[1] = -_m4storage[1];
    _m4storage[2] = -_m4storage[2];
    _m4storage[3] = -_m4storage[3];
    _m4storage[4] = -_m4storage[4];
    _m4storage[5] = -_m4storage[5];
    _m4storage[6] = -_m4storage[6];
    _m4storage[7] = -_m4storage[7];
    _m4storage[8] = -_m4storage[8];
    _m4storage[9] = -_m4storage[9];
    _m4storage[10] = -_m4storage[10];
    _m4storage[11] = -_m4storage[11];
    _m4storage[12] = -_m4storage[12];
    _m4storage[13] = -_m4storage[13];
    _m4storage[14] = -_m4storage[14];
    _m4storage[15] = -_m4storage[15];
}

void Matrix4Cls::multiply(Matrix4 arg) {
    Unknown m00 = _m4storage[0];
    Unknown m01 = _m4storage[4];
    Unknown m02 = _m4storage[8];
    Unknown m03 = _m4storage[12];
    Unknown m10 = _m4storage[1];
    Unknown m11 = _m4storage[5];
    Unknown m12 = _m4storage[9];
    Unknown m13 = _m4storage[13];
    Unknown m20 = _m4storage[2];
    Unknown m21 = _m4storage[6];
    Unknown m22 = _m4storage[10];
    Unknown m23 = _m4storage[14];
    Unknown m30 = _m4storage[3];
    Unknown m31 = _m4storage[7];
    Unknown m32 = _m4storage[11];
    Unknown m33 = _m4storage[15];
    Unknown argStorage = arg->_m4storage;
    Unknown n00 = argStorage[0];
    Unknown n01 = argStorage[4];
    Unknown n02 = argStorage[8];
    Unknown n03 = argStorage[12];
    Unknown n10 = argStorage[1];
    Unknown n11 = argStorage[5];
    Unknown n12 = argStorage[9];
    Unknown n13 = argStorage[13];
    Unknown n20 = argStorage[2];
    Unknown n21 = argStorage[6];
    Unknown n22 = argStorage[10];
    Unknown n23 = argStorage[14];
    Unknown n30 = argStorage[3];
    Unknown n31 = argStorage[7];
    Unknown n32 = argStorage[11];
    Unknown n33 = argStorage[15];
    _m4storage[0] = (m00 * n00) + (m01 * n10) + (m02 * n20) + (m03 * n30);
    _m4storage[4] = (m00 * n01) + (m01 * n11) + (m02 * n21) + (m03 * n31);
    _m4storage[8] = (m00 * n02) + (m01 * n12) + (m02 * n22) + (m03 * n32);
    _m4storage[12] = (m00 * n03) + (m01 * n13) + (m02 * n23) + (m03 * n33);
    _m4storage[1] = (m10 * n00) + (m11 * n10) + (m12 * n20) + (m13 * n30);
    _m4storage[5] = (m10 * n01) + (m11 * n11) + (m12 * n21) + (m13 * n31);
    _m4storage[9] = (m10 * n02) + (m11 * n12) + (m12 * n22) + (m13 * n32);
    _m4storage[13] = (m10 * n03) + (m11 * n13) + (m12 * n23) + (m13 * n33);
    _m4storage[2] = (m20 * n00) + (m21 * n10) + (m22 * n20) + (m23 * n30);
    _m4storage[6] = (m20 * n01) + (m21 * n11) + (m22 * n21) + (m23 * n31);
    _m4storage[10] = (m20 * n02) + (m21 * n12) + (m22 * n22) + (m23 * n32);
    _m4storage[14] = (m20 * n03) + (m21 * n13) + (m22 * n23) + (m23 * n33);
    _m4storage[3] = (m30 * n00) + (m31 * n10) + (m32 * n20) + (m33 * n30);
    _m4storage[7] = (m30 * n01) + (m31 * n11) + (m32 * n21) + (m33 * n31);
    _m4storage[11] = (m30 * n02) + (m31 * n12) + (m32 * n22) + (m33 * n32);
    _m4storage[15] = (m30 * n03) + (m31 * n13) + (m32 * n23) + (m33 * n33);
}

Matrix4 Matrix4Cls::multiplied(Matrix4 arg) {
    return _c1;
}

void Matrix4Cls::transposeMultiply(Matrix4 arg) {
    auto _c1 = clone();_c1.multiply(arg);Unknown m00 = _m4storage[0];
    Unknown m01 = _m4storage[1];
    Unknown m02 = _m4storage[2];
    Unknown m03 = _m4storage[3];
    Unknown m10 = _m4storage[4];
    Unknown m11 = _m4storage[5];
    Unknown m12 = _m4storage[6];
    Unknown m13 = _m4storage[7];
    Unknown m20 = _m4storage[8];
    Unknown m21 = _m4storage[9];
    Unknown m22 = _m4storage[10];
    Unknown m23 = _m4storage[11];
    Unknown m30 = _m4storage[12];
    Unknown m31 = _m4storage[13];
    Unknown m32 = _m4storage[14];
    Unknown m33 = _m4storage[15];
    Unknown argStorage = arg->_m4storage;
    _m4storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[1]) + (m02 * argStorage[2]) + (m03 * argStorage[3]);
    _m4storage[4] = (m00 * argStorage[4]) + (m01 * argStorage[5]) + (m02 * argStorage[6]) + (m03 * argStorage[7]);
    _m4storage[8] = (m00 * argStorage[8]) + (m01 * argStorage[9]) + (m02 * argStorage[10]) + (m03 * argStorage[11]);
    _m4storage[12] = (m00 * argStorage[12]) + (m01 * argStorage[13]) + (m02 * argStorage[14]) + (m03 * argStorage[15]);
    _m4storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[1]) + (m12 * argStorage[2]) + (m13 * argStorage[3]);
    _m4storage[5] = (m10 * argStorage[4]) + (m11 * argStorage[5]) + (m12 * argStorage[6]) + (m13 * argStorage[7]);
    _m4storage[9] = (m10 * argStorage[8]) + (m11 * argStorage[9]) + (m12 * argStorage[10]) + (m13 * argStorage[11]);
    _m4storage[13] = (m10 * argStorage[12]) + (m11 * argStorage[13]) + (m12 * argStorage[14]) + (m13 * argStorage[15]);
    _m4storage[2] = (m20 * argStorage[0]) + (m21 * argStorage[1]) + (m22 * argStorage[2]) + (m23 * argStorage[3]);
    _m4storage[6] = (m20 * argStorage[4]) + (m21 * argStorage[5]) + (m22 * argStorage[6]) + (m23 * argStorage[7]);
    _m4storage[10] = (m20 * argStorage[8]) + (m21 * argStorage[9]) + (m22 * argStorage[10]) + (m23 * argStorage[11]);
    _m4storage[14] = (m20 * argStorage[12]) + (m21 * argStorage[13]) + (m22 * argStorage[14]) + (m23 * argStorage[15]);
    _m4storage[3] = (m30 * argStorage[0]) + (m31 * argStorage[1]) + (m32 * argStorage[2]) + (m33 * argStorage[3]);
    _m4storage[7] = (m30 * argStorage[4]) + (m31 * argStorage[5]) + (m32 * argStorage[6]) + (m33 * argStorage[7]);
    _m4storage[11] = (m30 * argStorage[8]) + (m31 * argStorage[9]) + (m32 * argStorage[10]) + (m33 * argStorage[11]);
    _m4storage[15] = (m30 * argStorage[12]) + (m31 * argStorage[13]) + (m32 * argStorage[14]) + (m33 * argStorage[15]);
}

void Matrix4Cls::multiplyTranspose(Matrix4 arg) {
    Unknown m00 = _m4storage[0];
    Unknown m01 = _m4storage[4];
    Unknown m02 = _m4storage[8];
    Unknown m03 = _m4storage[12];
    Unknown m10 = _m4storage[1];
    Unknown m11 = _m4storage[5];
    Unknown m12 = _m4storage[9];
    Unknown m13 = _m4storage[13];
    Unknown m20 = _m4storage[2];
    Unknown m21 = _m4storage[6];
    Unknown m22 = _m4storage[10];
    Unknown m23 = _m4storage[14];
    Unknown m30 = _m4storage[3];
    Unknown m31 = _m4storage[7];
    Unknown m32 = _m4storage[11];
    Unknown m33 = _m4storage[15];
    Unknown argStorage = arg->_m4storage;
    _m4storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[4]) + (m02 * argStorage[8]) + (m03 * argStorage[12]);
    _m4storage[4] = (m00 * argStorage[1]) + (m01 * argStorage[5]) + (m02 * argStorage[9]) + (m03 * argStorage[13]);
    _m4storage[8] = (m00 * argStorage[2]) + (m01 * argStorage[6]) + (m02 * argStorage[10]) + (m03 * argStorage[14]);
    _m4storage[12] = (m00 * argStorage[3]) + (m01 * argStorage[7]) + (m02 * argStorage[11]) + (m03 * argStorage[15]);
    _m4storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[4]) + (m12 * argStorage[8]) + (m13 * argStorage[12]);
    _m4storage[5] = (m10 * argStorage[1]) + (m11 * argStorage[5]) + (m12 * argStorage[9]) + (m13 * argStorage[13]);
    _m4storage[9] = (m10 * argStorage[2]) + (m11 * argStorage[6]) + (m12 * argStorage[10]) + (m13 * argStorage[14]);
    _m4storage[13] = (m10 * argStorage[3]) + (m11 * argStorage[7]) + (m12 * argStorage[11]) + (m13 * argStorage[15]);
    _m4storage[2] = (m20 * argStorage[0]) + (m21 * argStorage[4]) + (m22 * argStorage[8]) + (m23 * argStorage[12]);
    _m4storage[6] = (m20 * argStorage[1]) + (m21 * argStorage[5]) + (m22 * argStorage[9]) + (m23 * argStorage[13]);
    _m4storage[10] = (m20 * argStorage[2]) + (m21 * argStorage[6]) + (m22 * argStorage[10]) + (m23 * argStorage[14]);
    _m4storage[14] = (m20 * argStorage[3]) + (m21 * argStorage[7]) + (m22 * argStorage[11]) + (m23 * argStorage[15]);
    _m4storage[3] = (m30 * argStorage[0]) + (m31 * argStorage[4]) + (m32 * argStorage[8]) + (m33 * argStorage[12]);
    _m4storage[7] = (m30 * argStorage[1]) + (m31 * argStorage[5]) + (m32 * argStorage[9]) + (m33 * argStorage[13]);
    _m4storage[11] = (m30 * argStorage[2]) + (m31 * argStorage[6]) + (m32 * argStorage[10]) + (m33 * argStorage[14]);
    _m4storage[15] = (m30 * argStorage[3]) + (m31 * argStorage[7]) + (m32 * argStorage[11]) + (m33 * argStorage[15]);
}

void Matrix4Cls::decompose(Vector3 translation, Quaternion rotation, Vector3 scale) {
    Unknown v = _decomposeV ??= Vector3Cls->zero();
    auto _c1 = v;_c1.setValues(_m4storage[0], _m4storage[1], _m4storage[2]);auto _c2 = v;_c2.setValues(_m4storage[0], _m4storage[1], _m4storage[2]);auto sx = (_c2)->length;
    auto _c3 = v;_c3.setValues(_m4storage[4], _m4storage[5], _m4storage[6]);auto _c4 = v;_c4.setValues(_m4storage[4], _m4storage[5], _m4storage[6]);Unknown sy = (_c4)->length;
    auto _c5 = v;_c5.setValues(_m4storage[8], _m4storage[9], _m4storage[10]);auto _c6 = v;_c6.setValues(_m4storage[8], _m4storage[9], _m4storage[10]);Unknown sz = (_c6)->length;
    if (determinant() < 0) {
        sx = -sx;
    }
    translation->_v3storage[0] = _m4storage[12];
    translation->_v3storage[1] = _m4storage[13];
    translation->_v3storage[2] = _m4storage[14];
    Unknown invSX = 1.0 / sx;
    Unknown invSY = 1.0 / sy;
    Unknown invSZ = 1.0 / sz;
    Unknown m = _decomposeM ??= Matrix4Cls->zero();
    m->setFrom(this);
    m->_m4storage[0] *= invSX;
    m->_m4storage[1] *= invSX;
    m->_m4storage[2] *= invSX;
    m->_m4storage[4] *= invSY;
    m->_m4storage[5] *= invSY;
    m->_m4storage[6] *= invSY;
    m->_m4storage[8] *= invSZ;
    m->_m4storage[9] *= invSZ;
    m->_m4storage[10] *= invSZ;
    Unknown r = _decomposeR ??= Matrix3Cls->zero();
    m->copyRotation(r);
    rotation->setFromRotation(r);
    scale->_v3storage[0] = sx;
    scale->_v3storage[1] = sy;
    scale->_v3storage[2] = sz;
}

Vector3 Matrix4Cls::rotate3(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    Unknown x_ = (_m4storage[0] * argStorage[0]) + (_m4storage[4] * argStorage[1]) + (_m4storage[8] * argStorage[2]);
    Unknown y_ = (_m4storage[1] * argStorage[0]) + (_m4storage[5] * argStorage[1]) + (_m4storage[9] * argStorage[2]);
    Unknown z_ = (_m4storage[2] * argStorage[0]) + (_m4storage[6] * argStorage[1]) + (_m4storage[10] * argStorage[2]);
    argStorage[0] = x_;
    argStorage[1] = y_;
    argStorage[2] = z_;
    return arg;
}

Vector3 Matrix4Cls::rotated3(Vector3 arg, Vector3 out) {
    if (out == nullptr) {
        out = Vector3Cls->copy(arg);
    } else {
        out->setFrom(arg);
    }
    return rotate3(out);
}

Vector3 Matrix4Cls::transform3(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    Unknown x_ = (_m4storage[0] * argStorage[0]) + (_m4storage[4] * argStorage[1]) + (_m4storage[8] * argStorage[2]) + _m4storage[12];
    Unknown y_ = (_m4storage[1] * argStorage[0]) + (_m4storage[5] * argStorage[1]) + (_m4storage[9] * argStorage[2]) + _m4storage[13];
    Unknown z_ = (_m4storage[2] * argStorage[0]) + (_m4storage[6] * argStorage[1]) + (_m4storage[10] * argStorage[2]) + _m4storage[14];
    argStorage[0] = x_;
    argStorage[1] = y_;
    argStorage[2] = z_;
    return arg;
}

Vector3 Matrix4Cls::transformed3(Vector3 arg, Vector3 out) {
    if (out == nullptr) {
        out = Vector3Cls->copy(arg);
    } else {
        out->setFrom(arg);
    }
    return transform3(out);
}

Vector4 Matrix4Cls::transform(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    Unknown x_ = (_m4storage[0] * argStorage[0]) + (_m4storage[4] * argStorage[1]) + (_m4storage[8] * argStorage[2]) + (_m4storage[12] * argStorage[3]);
    Unknown y_ = (_m4storage[1] * argStorage[0]) + (_m4storage[5] * argStorage[1]) + (_m4storage[9] * argStorage[2]) + (_m4storage[13] * argStorage[3]);
    Unknown z_ = (_m4storage[2] * argStorage[0]) + (_m4storage[6] * argStorage[1]) + (_m4storage[10] * argStorage[2]) + (_m4storage[14] * argStorage[3]);
    Unknown w_ = (_m4storage[3] * argStorage[0]) + (_m4storage[7] * argStorage[1]) + (_m4storage[11] * argStorage[2]) + (_m4storage[15] * argStorage[3]);
    argStorage[0] = x_;
    argStorage[1] = y_;
    argStorage[2] = z_;
    argStorage[3] = w_;
    return arg;
}

Vector3 Matrix4Cls::perspectiveTransform(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    Unknown x_ = (_m4storage[0] * argStorage[0]) + (_m4storage[4] * argStorage[1]) + (_m4storage[8] * argStorage[2]) + _m4storage[12];
    Unknown y_ = (_m4storage[1] * argStorage[0]) + (_m4storage[5] * argStorage[1]) + (_m4storage[9] * argStorage[2]) + _m4storage[13];
    Unknown z_ = (_m4storage[2] * argStorage[0]) + (_m4storage[6] * argStorage[1]) + (_m4storage[10] * argStorage[2]) + _m4storage[14];
    Unknown w_ = 1.0 / ((_m4storage[3] * argStorage[0]) + (_m4storage[7] * argStorage[1]) + (_m4storage[11] * argStorage[2]) + _m4storage[15]);
    argStorage[0] = x_ * w_;
    argStorage[1] = y_ * w_;
    argStorage[2] = z_ * w_;
    return arg;
}

Vector4 Matrix4Cls::transformed(Vector4 arg, Vector4 out) {
    if (out == nullptr) {
        out = Vector4Cls->copy(arg);
    } else {
        out->setFrom(arg);
    }
    return transform(out);
}

void Matrix4Cls::copyIntoArray(List<num> array, int offset) {
    Unknown i = offset;
    array[i + 15] = _m4storage[15];
    array[i + 14] = _m4storage[14];
    array[i + 13] = _m4storage[13];
    array[i + 12] = _m4storage[12];
    array[i + 11] = _m4storage[11];
    array[i + 10] = _m4storage[10];
    array[i + 9] = _m4storage[9];
    array[i + 8] = _m4storage[8];
    array[i + 7] = _m4storage[7];
    array[i + 6] = _m4storage[6];
    array[i + 5] = _m4storage[5];
    array[i + 4] = _m4storage[4];
    array[i + 3] = _m4storage[3];
    array[i + 2] = _m4storage[2];
    array[i + 1] = _m4storage[1];
    array[i + 0] = _m4storage[0];
}

void Matrix4Cls::copyFromArray(List<double> array, int offset) {
    Unknown i = offset;
    _m4storage[15] = array[i + 15];
    _m4storage[14] = array[i + 14];
    _m4storage[13] = array[i + 13];
    _m4storage[12] = array[i + 12];
    _m4storage[11] = array[i + 11];
    _m4storage[10] = array[i + 10];
    _m4storage[9] = array[i + 9];
    _m4storage[8] = array[i + 8];
    _m4storage[7] = array[i + 7];
    _m4storage[6] = array[i + 6];
    _m4storage[5] = array[i + 5];
    _m4storage[4] = array[i + 4];
    _m4storage[3] = array[i + 3];
    _m4storage[2] = array[i + 2];
    _m4storage[1] = array[i + 1];
    _m4storage[0] = array[i + 0];
}

List<double> Matrix4Cls::applyToVector3Array(List<double> array, int offset) {
    for (;  < array->length(); i += 3, j += 3) {
            auto _c1 = Vector3Cls->array(array, j);    _c1.applyMatrix4(this);Unknown v = _c1;
        array[j] = v->storage[0];
        array[j + 1] = v->storage[1];
        array[j + 2] = v->storage[2];
    }
    return array;
}

Vector3 Matrix4Cls::right() {
    Unknown x = _m4storage[0];
    Unknown y = _m4storage[1];
    Unknown z = _m4storage[2];
    return make<Vector3Cls>(x, y, z);
}

Vector3 Matrix4Cls::up() {
    Unknown x = _m4storage[4];
    Unknown y = _m4storage[5];
    Unknown z = _m4storage[6];
    return make<Vector3Cls>(x, y, z);
}

Vector3 Matrix4Cls::forward() {
    Unknown x = _m4storage[8];
    Unknown y = _m4storage[9];
    Unknown z = _m4storage[10];
    return make<Vector3Cls>(x, y, z);
}

bool Matrix4Cls::isIdentity() {
    return _m4storage[0] == 1.0 && _m4storage[1] == 0.0 && _m4storage[2] == 0.0 && _m4storage[3] == 0.0 && _m4storage[4] == 0.0 && _m4storage[5] == 1.0 && _m4storage[6] == 0.0 && _m4storage[7] == 0.0 && _m4storage[8] == 0.0 && _m4storage[9] == 0.0 && _m4storage[10] == 1.0 && _m4storage[11] == 0.0 && _m4storage[12] == 0.0 && _m4storage[13] == 0.0 && _m4storage[14] == 0.0 && _m4storage[15] == 1.0;
}

bool Matrix4Cls::isZero() {
    return _m4storage[0] == 0.0 && _m4storage[1] == 0.0 && _m4storage[2] == 0.0 && _m4storage[3] == 0.0 && _m4storage[4] == 0.0 && _m4storage[5] == 0.0 && _m4storage[6] == 0.0 && _m4storage[7] == 0.0 && _m4storage[8] == 0.0 && _m4storage[9] == 0.0 && _m4storage[10] == 0.0 && _m4storage[11] == 0.0 && _m4storage[12] == 0.0 && _m4storage[13] == 0.0 && _m4storage[14] == 0.0 && _m4storage[15] == 0.0;
}
