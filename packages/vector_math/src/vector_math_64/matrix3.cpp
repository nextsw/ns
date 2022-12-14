#include "matrix3.hpp"
Float64List Matrix3Cls::storage() {
    return _m3storage;
}

void Matrix3Cls::solve2(Matrix3 A, Vector2 x, Vector2 b) {
    auto a11 = A->entry(0, 0);
    auto a12 = A->entry(0, 1);
    auto a21 = A->entry(1, 0);
    auto a22 = A->entry(1, 1);
    auto bx = b->x - A::storage()[6];
    auto by = b->y - A::storage()[7];
    auto det = a11 * a22 - a12 * a21;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    auto _c1 = x;_c1.x = auto _c2 = det * (a22 * bx - a12 * by);_c2.y = det * (a11 * by - a21 * bx);_c2;_c1;
}

void Matrix3Cls::solve(Matrix3 A, Vector3 x, Vector3 b) {
    auto A0x = A->entry(0, 0);
    auto A0y = A->entry(1, 0);
    auto A0z = A->entry(2, 0);
    auto A1x = A->entry(0, 1);
    auto A1y = A->entry(1, 1);
    auto A1z = A->entry(2, 1);
    auto A2x = A->entry(0, 2);
    auto A2y = A->entry(1, 2);
    auto A2z = A->entry(2, 2);
    double rx, ry, rz;
    double det;
    rx = A1yCls * A2zCls - A1zCls * A2yCls;
    ry = A1zCls * A2xCls - A1xCls * A2zCls;
    rz = A1xCls * A2yCls - A1yCls * A2xCls;
    det = A0xCls * rx + A0yCls * ry + A0zCls * rz;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    auto x_ = det * (b->x * rx + b->y * ry + b->z * rz);
    rx = -(A2yCls * b->z - A2zCls * b->y);
    ry = -(A2zCls * b->x - A2xCls * b->z);
    rz = -(A2xCls * b->y - A2yCls * b->x);
    auto y_ = det * (A0xCls * rx + A0yCls * ry + A0zCls * rz);
    rx = -(b->y * A1zCls - b->z * A1yCls);
    ry = -(b->z * A1xCls - b->x * A1zCls);
    rz = -(b->x * A1yCls - b->y * A1xCls);
    auto z_ = det * (A0xCls * rx + A0yCls * ry + A0zCls * rz);
    auto _c1 = x;_c1.x = auto _c2 = x_;_c2.y = auto _c3 = y_;_c3.z = z_;_c3;_c2;_c1;
}

int Matrix3Cls::index(int row, int col) {
    return (col * 3) + row;
}

double Matrix3Cls::entry(int row, int col) {
    assert((row >= 0) && ( < dimension()));
    assert((col >= 0) && ( < dimension()));
    return _m3storage[index(row, col)];
}

void Matrix3Cls::setEntry(int row, int col, double v) {
    assert((row >= 0) && ( < dimension()));
    assert((col >= 0) && ( < dimension()));
    _m3storage[index(row, col)] = v;
}

Matrix3Cls::Matrix3Cls(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8) {
}

void Matrix3Cls::fromList(List<double> values) {
    return _c1;
}

void Matrix3Cls::zero()

void Matrix3Cls::identity() {
    return _c1;
}

void Matrix3Cls::copy(Matrix3 other) {
    return _c1;
}

void Matrix3Cls::columns(Vector3 arg0, Vector3 arg1, Vector3 arg2) {
    return _c1;
}

void Matrix3Cls::outer(Vector3 u, Vector3 v) {
    return _c1;
}

void Matrix3Cls::rotationX(double radians) {
    return _c1;
}

void Matrix3Cls::rotationY(double radians) {
    return _c1;
}

void Matrix3Cls::rotationZ(double radians) {
    return _c1;
}

void Matrix3Cls::setValues(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8) {
    auto _c1 = Matrix3Cls->zero();_c1.setValues(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8]);auto _c1 = Matrix3Cls->zero();_c1.setIdentity();auto _c1 = Matrix3Cls->zero();_c1.setFrom(other);auto _c1 = Matrix3Cls->zero();_c1.setColumns(arg0, arg1, arg2);auto _c1 = Matrix3Cls->zero();_c1.setOuter(u, v);auto _c1 = Matrix3Cls->zero();_c1.setRotationX(radians);auto _c1 = Matrix3Cls->zero();_c1.setRotationY(radians);auto _c1 = Matrix3Cls->zero();_c1.setRotationZ(radians);_m3storage[8] = arg8;
    _m3storage[7] = arg7;
    _m3storage[6] = arg6;
    _m3storage[5] = arg5;
    _m3storage[4] = arg4;
    _m3storage[3] = arg3;
    _m3storage[2] = arg2;
    _m3storage[1] = arg1;
    _m3storage[0] = arg0;
}

void Matrix3Cls::setColumns(Vector3 arg0, Vector3 arg1, Vector3 arg2) {
    auto arg0Storage = arg0->_v3storage;
    auto arg1Storage = arg1->_v3storage;
    auto arg2Storage = arg2->_v3storage;
    _m3storage[0] = arg0Storage[0];
    _m3storage[1] = arg0Storage[1];
    _m3storage[2] = arg0Storage[2];
    _m3storage[3] = arg1Storage[0];
    _m3storage[4] = arg1Storage[1];
    _m3storage[5] = arg1Storage[2];
    _m3storage[6] = arg2Storage[0];
    _m3storage[7] = arg2Storage[1];
    _m3storage[8] = arg2Storage[2];
}

void Matrix3Cls::setFrom(Matrix3 arg) {
    auto argStorage = arg->_m3storage;
    _m3storage[8] = argStorage[8];
    _m3storage[7] = argStorage[7];
    _m3storage[6] = argStorage[6];
    _m3storage[5] = argStorage[5];
    _m3storage[4] = argStorage[4];
    _m3storage[3] = argStorage[3];
    _m3storage[2] = argStorage[2];
    _m3storage[1] = argStorage[1];
    _m3storage[0] = argStorage[0];
}

void Matrix3Cls::setOuter(Vector3 u, Vector3 v) {
    auto uStorage = u->_v3storage;
    auto vStorage = v->_v3storage;
    _m3storage[0] = uStorage[0] * vStorage[0];
    _m3storage[1] = uStorage[0] * vStorage[1];
    _m3storage[2] = uStorage[0] * vStorage[2];
    _m3storage[3] = uStorage[1] * vStorage[0];
    _m3storage[4] = uStorage[1] * vStorage[1];
    _m3storage[5] = uStorage[1] * vStorage[2];
    _m3storage[6] = uStorage[2] * vStorage[0];
    _m3storage[7] = uStorage[2] * vStorage[1];
    _m3storage[8] = uStorage[2] * vStorage[2];
}

void Matrix3Cls::splatDiagonal(double arg) {
    _m3storage[0] = arg;
    _m3storage[4] = arg;
    _m3storage[8] = arg;
}

void Matrix3Cls::setDiagonal(Vector3 arg) {
    _m3storage[0] = arg->storage()[0];
    _m3storage[4] = arg->storage()[1];
    _m3storage[8] = arg->storage()[2];
}

void Matrix3Cls::setUpper2x2(Matrix2 arg) {
    auto argStorage = arg->_m2storage;
    _m3storage[0] = argStorage[0];
    _m3storage[1] = argStorage[1];
    _m3storage[3] = argStorage[2];
    _m3storage[4] = argStorage[3];
}

String Matrix3Cls::toString() {
    return __sf("[0] %s\n[1] %s\n[2] %s\n", getRow(0), getRow(1), getRow(2));
}

int Matrix3Cls::dimension() {
    return 3;
}

double Matrix3Cls::[](int i) {
    return _m3storage[i];
}

void Matrix3Cls::[]=(int i, double v) {
    _m3storage[i] = v;
}

bool Matrix3Cls::==(Object other) {
    return (is<Matrix3>(other)) && (_m3storage[0] == other->_m3storage[0]) && (_m3storage[1] == other->_m3storage[1]) && (_m3storage[2] == other->_m3storage[2]) && (_m3storage[3] == other->_m3storage[3]) && (_m3storage[4] == other->_m3storage[4]) && (_m3storage[5] == other->_m3storage[5]) && (_m3storage[6] == other->_m3storage[6]) && (_m3storage[7] == other->_m3storage[7]) && (_m3storage[8] == other->_m3storage[8]);
}

int Matrix3Cls::hashCode() {
    return ObjectCls->hashAll(_m3storage);
}

Vector3 Matrix3Cls::row0() {
    return getRow(0);
}

Vector3 Matrix3Cls::row1() {
    return getRow(1);
}

Vector3 Matrix3Cls::row2() {
    return getRow(2);
}

void Matrix3Cls::row0(Vector3 arg) {
    return setRow(0, arg);
}

void Matrix3Cls::row1(Vector3 arg) {
    return setRow(1, arg);
}

void Matrix3Cls::row2(Vector3 arg) {
    return setRow(2, arg);
}

void Matrix3Cls::setRow(int row, Vector3 arg) {
    auto argStorage = arg->_v3storage;
    _m3storage[index(row, 0)] = argStorage[0];
    _m3storage[index(row, 1)] = argStorage[1];
    _m3storage[index(row, 2)] = argStorage[2];
}

Vector3 Matrix3Cls::getRow(int row) {
    auto r = Vector3Cls->zero();
    auto rStorage = r->_v3storage;
    rStorage[0] = _m3storage[index(row, 0)];
    rStorage[1] = _m3storage[index(row, 1)];
    rStorage[2] = _m3storage[index(row, 2)];
    return r;
}

void Matrix3Cls::setColumn(int column, Vector3 arg) {
    auto argStorage = arg->_v3storage;
    auto entry = column * 3;
    _m3storage[entry + 2] = argStorage[2];
    _m3storage[entry + 1] = argStorage[1];
    _m3storage[entry + 0] = argStorage[0];
}

Vector3 Matrix3Cls::getColumn(int column) {
    auto r = Vector3Cls->zero();
    auto rStorage = r->_v3storage;
    auto entry = column * 3;
    rStorage[2] = _m3storage[entry + 2];
    rStorage[1] = _m3storage[entry + 1];
    rStorage[0] = _m3storage[entry + 0];
    return r;
}

Matrix3 Matrix3Cls::clone() {
    return Matrix3Cls->copy(this);
}

Matrix3 Matrix3Cls::copyInto(Matrix3 arg) {
    auto argStorage = arg->_m3storage;
    argStorage[0] = _m3storage[0];
    argStorage[1] = _m3storage[1];
    argStorage[2] = _m3storage[2];
    argStorage[3] = _m3storage[3];
    argStorage[4] = _m3storage[4];
    argStorage[5] = _m3storage[5];
    argStorage[6] = _m3storage[6];
    argStorage[7] = _m3storage[7];
    argStorage[8] = _m3storage[8];
    return arg;
}

Object Matrix3Cls::*(Object arg) {
    if (is<double>(arg)) {
        return scaled(as<doubleCls>(arg));
    }
    if (is<Vector3>(arg)) {
        return transformed(as<Vector3Cls>(arg));
    }
    if (is<Matrix3>(arg)) {
        return multiplied(as<Matrix3Cls>(arg));
    }
    throw make<ArgumentErrorCls>(arg);
}

Matrix3 Matrix3Cls::+(Matrix3 arg) {
    return _c1;
}

Matrix3 Matrix3Cls::-(Matrix3 arg) {
    return _c1;
}

Matrix3 Matrix3Cls::-() {
    return _c1;
}

void Matrix3Cls::setZero() {
    auto _c1 = clone();_c1.add(arg);auto _c1 = clone();_c1.sub(arg);auto _c1 = clone();_c1.negate();_m3storage[0] = 0.0;
    _m3storage[1] = 0.0;
    _m3storage[2] = 0.0;
    _m3storage[3] = 0.0;
    _m3storage[4] = 0.0;
    _m3storage[5] = 0.0;
    _m3storage[6] = 0.0;
    _m3storage[7] = 0.0;
    _m3storage[8] = 0.0;
}

void Matrix3Cls::setIdentity() {
    _m3storage[0] = 1.0;
    _m3storage[1] = 0.0;
    _m3storage[2] = 0.0;
    _m3storage[3] = 0.0;
    _m3storage[4] = 1.0;
    _m3storage[5] = 0.0;
    _m3storage[6] = 0.0;
    _m3storage[7] = 0.0;
    _m3storage[8] = 1.0;
}

Matrix3 Matrix3Cls::transposed() {
    return _c1;
}

void Matrix3Cls::transpose() {
    auto _c1 = clone();_c1.transpose();double temp;
    temp = _m3storage[3];
    _m3storage[3] = _m3storage[1];
    _m3storage[1] = temp;
    temp = _m3storage[6];
    _m3storage[6] = _m3storage[2];
    _m3storage[2] = temp;
    temp = _m3storage[7];
    _m3storage[7] = _m3storage[5];
    _m3storage[5] = temp;
}

Matrix3 Matrix3Cls::absolute() {
    auto r = Matrix3Cls->zero();
    auto rStorage = r->_m3storage;
    rStorage[0] = _m3storage[0]->abs();
    rStorage[1] = _m3storage[1]->abs();
    rStorage[2] = _m3storage[2]->abs();
    rStorage[3] = _m3storage[3]->abs();
    rStorage[4] = _m3storage[4]->abs();
    rStorage[5] = _m3storage[5]->abs();
    rStorage[6] = _m3storage[6]->abs();
    rStorage[7] = _m3storage[7]->abs();
    rStorage[8] = _m3storage[8]->abs();
    return r;
}

double Matrix3Cls::determinant() {
    auto x = _m3storage[0] * ((_m3storage[4] * _m3storage[8]) - (_m3storage[5] * _m3storage[7]));
    auto y = _m3storage[1] * ((_m3storage[3] * _m3storage[8]) - (_m3storage[5] * _m3storage[6]));
    auto z = _m3storage[2] * ((_m3storage[3] * _m3storage[7]) - (_m3storage[4] * _m3storage[6]));
    return x - y + z;
}

double Matrix3Cls::dotRow(int i, Vector3 v) {
    auto vStorage = v->_v3storage;
    return _m3storage[i] * vStorage[0] + _m3storage[3 + i] * vStorage[1] + _m3storage[6 + i] * vStorage[2];
}

double Matrix3Cls::dotColumn(int j, Vector3 v) {
    auto vStorage = v->_v3storage;
    return _m3storage[j * 3] * vStorage[0] + _m3storage[j * 3 + 1] * vStorage[1] + _m3storage[j * 3 + 2] * vStorage[2];
}

double Matrix3Cls::trace() {
    auto t = 0.0;
    t += _m3storage[0];
    t += _m3storage[4];
    t += _m3storage[8];
    return t;
}

double Matrix3Cls::infinityNorm() {
    auto norm = 0.0;
    {
        auto row_norm = 0.0;
        row_norm += _m3storage[0]->abs();
        row_norm += _m3storage[1]->abs();
        row_norm += _m3storage[2]->abs();
        norm = row_norm > norm? row_norm : norm;
    }    {
        auto row_norm = 0.0;
        row_norm += _m3storage[3]->abs();
        row_norm += _m3storage[4]->abs();
        row_norm += _m3storage[5]->abs();
        norm = row_norm > norm? row_norm : norm;
    }    {
        auto row_norm = 0.0;
        row_norm += _m3storage[6]->abs();
        row_norm += _m3storage[7]->abs();
        row_norm += _m3storage[8]->abs();
        norm = row_norm > norm? row_norm : norm;
    }    return norm;
}

double Matrix3Cls::relativeError(Matrix3 correct) {
    auto diff = correct - this;
    auto correct_norm = correct->infinityNorm();
    auto diff_norm = diff->infinityNorm();
    return diff_norm / correct_norm;
}

double Matrix3Cls::absoluteError(Matrix3 correct) {
    auto this_norm = infinityNorm();
    auto correct_norm = correct->infinityNorm();
    auto diff_norm = (this_norm - correct_norm)->abs();
    return diff_norm;
}

double Matrix3Cls::invert() {
    return copyInverse(this);
}

double Matrix3Cls::copyInverse(Matrix3 arg) {
    auto det = arg->determinant();
    if (det == 0.0) {
        setFrom(arg);
        return 0.0;
    }
    auto invDet = 1.0 / det;
    auto argStorage = arg->_m3storage;
    auto ix = invDet * (argStorage[4] * argStorage[8] - argStorage[5] * argStorage[7]);
    auto iy = invDet * (argStorage[2] * argStorage[7] - argStorage[1] * argStorage[8]);
    auto iz = invDet * (argStorage[1] * argStorage[5] - argStorage[2] * argStorage[4]);
    auto jx = invDet * (argStorage[5] * argStorage[6] - argStorage[3] * argStorage[8]);
    auto jy = invDet * (argStorage[0] * argStorage[8] - argStorage[2] * argStorage[6]);
    auto jz = invDet * (argStorage[2] * argStorage[3] - argStorage[0] * argStorage[5]);
    auto kx = invDet * (argStorage[3] * argStorage[7] - argStorage[4] * argStorage[6]);
    auto ky = invDet * (argStorage[1] * argStorage[6] - argStorage[0] * argStorage[7]);
    auto kz = invDet * (argStorage[0] * argStorage[4] - argStorage[1] * argStorage[3]);
    _m3storage[0] = ix;
    _m3storage[1] = iy;
    _m3storage[2] = iz;
    _m3storage[3] = jx;
    _m3storage[4] = jy;
    _m3storage[5] = jz;
    _m3storage[6] = kx;
    _m3storage[7] = ky;
    _m3storage[8] = kz;
    return det;
}

void Matrix3Cls::copyNormalMatrix(Matrix4 arg) {
    copyInverse(arg->getRotation());
    transpose();
}

void Matrix3Cls::setRotationX(double radians) {
    auto c = math->cos(radians);
    auto s = math->sin(radians);
    _m3storage[0] = 1.0;
    _m3storage[1] = 0.0;
    _m3storage[2] = 0.0;
    _m3storage[3] = 0.0;
    _m3storage[4] = c;
    _m3storage[5] = s;
    _m3storage[6] = 0.0;
    _m3storage[7] = -s;
    _m3storage[8] = c;
}

void Matrix3Cls::setRotationY(double radians) {
    auto c = math->cos(radians);
    auto s = math->sin(radians);
    _m3storage[0] = c;
    _m3storage[1] = 0.0;
    _m3storage[2] = s;
    _m3storage[3] = 0.0;
    _m3storage[4] = 1.0;
    _m3storage[5] = 0.0;
    _m3storage[6] = -s;
    _m3storage[7] = 0.0;
    _m3storage[8] = c;
}

void Matrix3Cls::setRotationZ(double radians) {
    auto c = math->cos(radians);
    auto s = math->sin(radians);
    _m3storage[0] = c;
    _m3storage[1] = s;
    _m3storage[2] = 0.0;
    _m3storage[3] = -s;
    _m3storage[4] = c;
    _m3storage[5] = 0.0;
    _m3storage[6] = 0.0;
    _m3storage[7] = 0.0;
    _m3storage[8] = 1.0;
}

void Matrix3Cls::scaleAdjoint(double scale) {
    auto m00 = _m3storage[0];
    auto m01 = _m3storage[3];
    auto m02 = _m3storage[6];
    auto m10 = _m3storage[1];
    auto m11 = _m3storage[4];
    auto m12 = _m3storage[7];
    auto m20 = _m3storage[2];
    auto m21 = _m3storage[5];
    auto m22 = _m3storage[8];
    _m3storage[0] = (m11 * m22 - m12 * m21) * scale;
    _m3storage[1] = (m12 * m20 - m10 * m22) * scale;
    _m3storage[2] = (m10 * m21 - m11 * m20) * scale;
    _m3storage[3] = (m02 * m21 - m01 * m22) * scale;
    _m3storage[4] = (m00 * m22 - m02 * m20) * scale;
    _m3storage[5] = (m01 * m20 - m00 * m21) * scale;
    _m3storage[6] = (m01 * m12 - m02 * m11) * scale;
    _m3storage[7] = (m02 * m10 - m00 * m12) * scale;
    _m3storage[8] = (m00 * m11 - m01 * m10) * scale;
}

Vector3 Matrix3Cls::absoluteRotate(Vector3 arg) {
    auto m00 = _m3storage[0]->abs();
    auto m01 = _m3storage[3]->abs();
    auto m02 = _m3storage[6]->abs();
    auto m10 = _m3storage[1]->abs();
    auto m11 = _m3storage[4]->abs();
    auto m12 = _m3storage[7]->abs();
    auto m20 = _m3storage[2]->abs();
    auto m21 = _m3storage[5]->abs();
    auto m22 = _m3storage[8]->abs();
    auto argStorage = arg->_v3storage;
    auto x = argStorage[0];
    auto y = argStorage[1];
    auto z = argStorage[2];
    argStorage[0] = x * m00 + y * m01 + z * m02;
    argStorage[1] = x * m10 + y * m11 + z * m12;
    argStorage[2] = x * m20 + y * m21 + z * m22;
    return arg;
}

Vector2 Matrix3Cls::absoluteRotate2(Vector2 arg) {
    auto m00 = _m3storage[0]->abs();
    auto m01 = _m3storage[3]->abs();
    auto m10 = _m3storage[1]->abs();
    auto m11 = _m3storage[4]->abs();
    auto argStorage = arg->_v2storage;
    auto x = argStorage[0];
    auto y = argStorage[1];
    argStorage[0] = x * m00 + y * m01;
    argStorage[1] = x * m10 + y * m11;
    return arg;
}

Vector2 Matrix3Cls::transform2(Vector2 arg) {
    auto argStorage = arg->_v2storage;
    auto x_ = (_m3storage[0] * argStorage[0]) + (_m3storage[3] * argStorage[1]) + _m3storage[6];
    auto y_ = (_m3storage[1] * argStorage[0]) + (_m3storage[4] * argStorage[1]) + _m3storage[7];
    argStorage[0] = x_;
    argStorage[1] = y_;
    return arg;
}

void Matrix3Cls::scale(double scale) {
    _m3storage[0] = _m3storage[0] * scale;
    _m3storage[1] = _m3storage[1] * scale;
    _m3storage[2] = _m3storage[2] * scale;
    _m3storage[3] = _m3storage[3] * scale;
    _m3storage[4] = _m3storage[4] * scale;
    _m3storage[5] = _m3storage[5] * scale;
    _m3storage[6] = _m3storage[6] * scale;
    _m3storage[7] = _m3storage[7] * scale;
    _m3storage[8] = _m3storage[8] * scale;
}

Matrix3 Matrix3Cls::scaled(double scale) {
    return _c1;
}

void Matrix3Cls::add(Matrix3 o) {
    auto _c1 = clone();_c1.scale(scale);auto oStorage = o->_m3storage;
    _m3storage[0] = _m3storage[0] + oStorage[0];
    _m3storage[1] = _m3storage[1] + oStorage[1];
    _m3storage[2] = _m3storage[2] + oStorage[2];
    _m3storage[3] = _m3storage[3] + oStorage[3];
    _m3storage[4] = _m3storage[4] + oStorage[4];
    _m3storage[5] = _m3storage[5] + oStorage[5];
    _m3storage[6] = _m3storage[6] + oStorage[6];
    _m3storage[7] = _m3storage[7] + oStorage[7];
    _m3storage[8] = _m3storage[8] + oStorage[8];
}

void Matrix3Cls::sub(Matrix3 o) {
    auto oStorage = o->_m3storage;
    _m3storage[0] = _m3storage[0] - oStorage[0];
    _m3storage[1] = _m3storage[1] - oStorage[1];
    _m3storage[2] = _m3storage[2] - oStorage[2];
    _m3storage[3] = _m3storage[3] - oStorage[3];
    _m3storage[4] = _m3storage[4] - oStorage[4];
    _m3storage[5] = _m3storage[5] - oStorage[5];
    _m3storage[6] = _m3storage[6] - oStorage[6];
    _m3storage[7] = _m3storage[7] - oStorage[7];
    _m3storage[8] = _m3storage[8] - oStorage[8];
}

void Matrix3Cls::negate() {
    _m3storage[0] = -_m3storage[0];
    _m3storage[1] = -_m3storage[1];
    _m3storage[2] = -_m3storage[2];
    _m3storage[3] = -_m3storage[3];
    _m3storage[4] = -_m3storage[4];
    _m3storage[5] = -_m3storage[5];
    _m3storage[6] = -_m3storage[6];
    _m3storage[7] = -_m3storage[7];
    _m3storage[8] = -_m3storage[8];
}

void Matrix3Cls::multiply(Matrix3 arg) {
    auto m00 = _m3storage[0];
    auto m01 = _m3storage[3];
    auto m02 = _m3storage[6];
    auto m10 = _m3storage[1];
    auto m11 = _m3storage[4];
    auto m12 = _m3storage[7];
    auto m20 = _m3storage[2];
    auto m21 = _m3storage[5];
    auto m22 = _m3storage[8];
    auto argStorage = arg->_m3storage;
    auto n00 = argStorage[0];
    auto n01 = argStorage[3];
    auto n02 = argStorage[6];
    auto n10 = argStorage[1];
    auto n11 = argStorage[4];
    auto n12 = argStorage[7];
    auto n20 = argStorage[2];
    auto n21 = argStorage[5];
    auto n22 = argStorage[8];
    _m3storage[0] = (m00 * n00) + (m01 * n10) + (m02 * n20);
    _m3storage[3] = (m00 * n01) + (m01 * n11) + (m02 * n21);
    _m3storage[6] = (m00 * n02) + (m01 * n12) + (m02 * n22);
    _m3storage[1] = (m10 * n00) + (m11 * n10) + (m12 * n20);
    _m3storage[4] = (m10 * n01) + (m11 * n11) + (m12 * n21);
    _m3storage[7] = (m10 * n02) + (m11 * n12) + (m12 * n22);
    _m3storage[2] = (m20 * n00) + (m21 * n10) + (m22 * n20);
    _m3storage[5] = (m20 * n01) + (m21 * n11) + (m22 * n21);
    _m3storage[8] = (m20 * n02) + (m21 * n12) + (m22 * n22);
}

Matrix3 Matrix3Cls::multiplied(Matrix3 arg) {
    return _c1;
}

void Matrix3Cls::transposeMultiply(Matrix3 arg) {
    auto _c1 = clone();_c1.multiply(arg);auto m00 = _m3storage[0];
    auto m01 = _m3storage[1];
    auto m02 = _m3storage[2];
    auto m10 = _m3storage[3];
    auto m11 = _m3storage[4];
    auto m12 = _m3storage[5];
    auto m20 = _m3storage[6];
    auto m21 = _m3storage[7];
    auto m22 = _m3storage[8];
    auto argStorage = arg->_m3storage;
    _m3storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[1]) + (m02 * argStorage[2]);
    _m3storage[3] = (m00 * argStorage[3]) + (m01 * argStorage[4]) + (m02 * argStorage[5]);
    _m3storage[6] = (m00 * argStorage[6]) + (m01 * argStorage[7]) + (m02 * argStorage[8]);
    _m3storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[1]) + (m12 * argStorage[2]);
    _m3storage[4] = (m10 * argStorage[3]) + (m11 * argStorage[4]) + (m12 * argStorage[5]);
    _m3storage[7] = (m10 * argStorage[6]) + (m11 * argStorage[7]) + (m12 * argStorage[8]);
    _m3storage[2] = (m20 * argStorage[0]) + (m21 * argStorage[1]) + (m22 * argStorage[2]);
    _m3storage[5] = (m20 * argStorage[3]) + (m21 * argStorage[4]) + (m22 * argStorage[5]);
    _m3storage[8] = (m20 * argStorage[6]) + (m21 * argStorage[7]) + (m22 * argStorage[8]);
}

void Matrix3Cls::multiplyTranspose(Matrix3 arg) {
    auto m00 = _m3storage[0];
    auto m01 = _m3storage[3];
    auto m02 = _m3storage[6];
    auto m10 = _m3storage[1];
    auto m11 = _m3storage[4];
    auto m12 = _m3storage[7];
    auto m20 = _m3storage[2];
    auto m21 = _m3storage[5];
    auto m22 = _m3storage[8];
    auto argStorage = arg->_m3storage;
    _m3storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[3]) + (m02 * argStorage[6]);
    _m3storage[3] = (m00 * argStorage[1]) + (m01 * argStorage[4]) + (m02 * argStorage[7]);
    _m3storage[6] = (m00 * argStorage[2]) + (m01 * argStorage[5]) + (m02 * argStorage[8]);
    _m3storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[3]) + (m12 * argStorage[6]);
    _m3storage[4] = (m10 * argStorage[1]) + (m11 * argStorage[4]) + (m12 * argStorage[7]);
    _m3storage[7] = (m10 * argStorage[2]) + (m11 * argStorage[5]) + (m12 * argStorage[8]);
    _m3storage[2] = (m20 * argStorage[0]) + (m21 * argStorage[3]) + (m22 * argStorage[6]);
    _m3storage[5] = (m20 * argStorage[1]) + (m21 * argStorage[4]) + (m22 * argStorage[7]);
    _m3storage[8] = (m20 * argStorage[2]) + (m21 * argStorage[5]) + (m22 * argStorage[8]);
}

Vector3 Matrix3Cls::transform(Vector3 arg) {
    auto argStorage = arg->_v3storage;
    auto x_ = (_m3storage[0] * argStorage[0]) + (_m3storage[3] * argStorage[1]) + (_m3storage[6] * argStorage[2]);
    auto y_ = (_m3storage[1] * argStorage[0]) + (_m3storage[4] * argStorage[1]) + (_m3storage[7] * argStorage[2]);
    auto z_ = (_m3storage[2] * argStorage[0]) + (_m3storage[5] * argStorage[1]) + (_m3storage[8] * argStorage[2]);
    auto _c1 = arg;_c1.x = auto _c2 = x_;_c2.y = auto _c3 = y_;_c3.z = z_;_c3;_c2;_c1;
    return arg;
}

Vector3 Matrix3Cls::transformed(Vector3 arg, Vector3 out) {
    if (out == nullptr) {
        out = Vector3Cls->copy(arg);
    } else {
        out->setFrom(arg);
    }
    return transform(out);
}

void Matrix3Cls::copyIntoArray(List<num> array, int offset) {
    auto i = offset;
    array[i + 8] = _m3storage[8];
    array[i + 7] = _m3storage[7];
    array[i + 6] = _m3storage[6];
    array[i + 5] = _m3storage[5];
    array[i + 4] = _m3storage[4];
    array[i + 3] = _m3storage[3];
    array[i + 2] = _m3storage[2];
    array[i + 1] = _m3storage[1];
    array[i + 0] = _m3storage[0];
}

void Matrix3Cls::copyFromArray(List<double> array, int offset) {
    auto i = offset;
    _m3storage[8] = array[i + 8];
    _m3storage[7] = array[i + 7];
    _m3storage[6] = array[i + 6];
    _m3storage[5] = array[i + 5];
    _m3storage[4] = array[i + 4];
    _m3storage[3] = array[i + 3];
    _m3storage[2] = array[i + 2];
    _m3storage[1] = array[i + 1];
    _m3storage[0] = array[i + 0];
}

List<double> Matrix3Cls::applyToVector3Array(List<double> array, int offset) {
    for (;  < array->length(); i += 3, j += 3) {
            auto _c1 = Vector3Cls->array(array, j);    _c1.applyMatrix3(this);auto v = _c1;
        array[j] = v->storage[0];
        array[j + 1] = v->storage[1];
        array[j + 2] = v->storage[2];
    }
    return array;
}

Vector3 Matrix3Cls::right() {
    auto x = _m3storage[0];
    auto y = _m3storage[1];
    auto z = _m3storage[2];
    return make<Vector3Cls>(x, y, z);
}

Vector3 Matrix3Cls::up() {
    auto x = _m3storage[3];
    auto y = _m3storage[4];
    auto z = _m3storage[5];
    return make<Vector3Cls>(x, y, z);
}

Vector3 Matrix3Cls::forward() {
    auto x = _m3storage[6];
    auto y = _m3storage[7];
    auto z = _m3storage[8];
    return make<Vector3Cls>(x, y, z);
}

bool Matrix3Cls::isIdentity() {
    return _m3storage[0] == 1.0 && _m3storage[1] == 0.0 && _m3storage[2] == 0.0 && _m3storage[3] == 0.0 && _m3storage[4] == 1.0 && _m3storage[5] == 0.0 && _m3storage[6] == 0.0 && _m3storage[7] == 0.0 && _m3storage[8] == 1.0;
}

bool Matrix3Cls::isZero() {
    return _m3storage[0] == 0.0 && _m3storage[1] == 0.0 && _m3storage[2] == 0.0 && _m3storage[3] == 0.0 && _m3storage[4] == 0.0 && _m3storage[5] == 0.0 && _m3storage[6] == 0.0 && _m3storage[7] == 0.0 && _m3storage[8] == 0.0;
}
