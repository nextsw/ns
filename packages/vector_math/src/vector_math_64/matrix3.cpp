#include "matrix3.hpp"
Float64List Matrix3::storage() {
    return _m3storage;
}

void Matrix3::solve2(Matrix3 A, Vector2 b, Vector2 x) {
    Unknown a11 = A.entry(0, 0);
    Unknown a12 = A.entry(0, 1);
    Unknown a21 = A.entry(1, 0);
    Unknown a22 = A.entry(1, 1);
    Unknown bx = b.x - A.storage[6];
    Unknown by = b.y - A.storage[7];
    auto det = a11 * a22 - a12 * a21;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    ;
}

void Matrix3::solve(Matrix3 A, Vector3 b, Vector3 x) {
    Unknown A0x = A.entry(0, 0);
    Unknown A0y = A.entry(1, 0);
    Unknown A0z = A.entry(2, 0);
    Unknown A1x = A.entry(0, 1);
    Unknown A1y = A.entry(1, 1);
    Unknown A1z = A.entry(2, 1);
    Unknown A2x = A.entry(0, 2);
    Unknown A2y = A.entry(1, 2);
    Unknown A2z = A.entry(2, 2);
    double rx, ry, rz;
    double det;
    rx = A1y * A2z - A1z * A2y;
    ry = A1z * A2x - A1x * A2z;
    rz = A1x * A2y - A1y * A2x;
    det = A0x * rx + A0y * ry + A0z * rz;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    Unknown x_ = det * (b.x * rx + b.y * ry + b.z * rz);
    rx = -(A2y * b.z - A2z * b.y);
    ry = -(A2z * b.x - A2x * b.z);
    rz = -(A2x * b.y - A2y * b.x);
    Unknown y_ = det * (A0x * rx + A0y * ry + A0z * rz);
    rx = -(b.y * A1z - b.z * A1y);
    ry = -(b.z * A1x - b.x * A1z);
    rz = -(b.x * A1y - b.y * A1x);
    Unknown z_ = det * (A0x * rx + A0y * ry + A0z * rz);
    ;
}

int Matrix3::index(int col, int row) {
    return (col * 3) + row;
}

double Matrix3::entry(int col, int row) {
    assert((row >= 0) && ( < dimension));
    assert((col >= 0) && ( < dimension));
    return _m3storage[index(row, col)];
}

void Matrix3::setEntry(int col, int row, double v) {
    assert((row >= 0) && ( < dimension));
    assert((col >= 0) && ( < dimension));
    _m3storage[index(row, col)] = v;
}

Matrix3::Matrix3(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8) {
}

void Matrix3::fromList(List<double> values) {
    return ;
}

void Matrix3::zero()

void Matrix3::identity() {
    return ;
}

void Matrix3::copy(Matrix3 other) {
    return ;
}

void Matrix3::columns(Vector3 arg0, Vector3 arg1, Vector3 arg2) {
    return ;
}

void Matrix3::outer(Vector3 u, Vector3 v) {
    return ;
}

void Matrix3::rotationX(double radians) {
    return ;
}

void Matrix3::rotationY(double radians) {
    return ;
}

void Matrix3::rotationZ(double radians) {
    return ;
}

void Matrix3::setValues(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8) {
    _m3storage[8] = arg8;
    _m3storage[7] = arg7;
    _m3storage[6] = arg6;
    _m3storage[5] = arg5;
    _m3storage[4] = arg4;
    _m3storage[3] = arg3;
    _m3storage[2] = arg2;
    _m3storage[1] = arg1;
    _m3storage[0] = arg0;
}

void Matrix3::setColumns(Vector3 arg0, Vector3 arg1, Vector3 arg2) {
    Unknown arg0Storage = arg0._v3storage;
    Unknown arg1Storage = arg1._v3storage;
    Unknown arg2Storage = arg2._v3storage;
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

void Matrix3::setFrom(Matrix3 arg) {
    Unknown argStorage = arg._m3storage;
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

void Matrix3::setOuter(Vector3 u, Vector3 v) {
    Unknown uStorage = u._v3storage;
    Unknown vStorage = v._v3storage;
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

void Matrix3::splatDiagonal(double arg) {
    _m3storage[0] = arg;
    _m3storage[4] = arg;
    _m3storage[8] = arg;
}

void Matrix3::setDiagonal(Vector3 arg) {
    _m3storage[0] = arg.storage[0];
    _m3storage[4] = arg.storage[1];
    _m3storage[8] = arg.storage[2];
}

void Matrix3::setUpper2x2(Matrix2 arg) {
    Unknown argStorage = arg._m2storage;
    _m3storage[0] = argStorage[0];
    _m3storage[1] = argStorage[1];
    _m3storage[3] = argStorage[2];
    _m3storage[4] = argStorage[3];
}

String Matrix3::toString() {
    return "[0] ${getRow(0)}\n[1] ${getRow(1)}\n[2] ${getRow(2)}\n";
}

int Matrix3::dimension() {
    return 3;
}

double Matrix3::[](int i) {
    return _m3storage[i];
}

void Matrix3::[]=(int i, double v) {
    _m3storage[i] = v;
}

bool Matrix3::==(Object other) {
    return (other is Matrix3) && (_m3storage[0] == other._m3storage[0]) && (_m3storage[1] == other._m3storage[1]) && (_m3storage[2] == other._m3storage[2]) && (_m3storage[3] == other._m3storage[3]) && (_m3storage[4] == other._m3storage[4]) && (_m3storage[5] == other._m3storage[5]) && (_m3storage[6] == other._m3storage[6]) && (_m3storage[7] == other._m3storage[7]) && (_m3storage[8] == other._m3storage[8]);
}

int Matrix3::hashCode() {
    return Object.hashAll(_m3storage);
}

Vector3 Matrix3::row0() {
    return getRow(0);
}

Vector3 Matrix3::row1() {
    return getRow(1);
}

Vector3 Matrix3::row2() {
    return getRow(2);
}

void Matrix3::row0(Vector3 arg) {
    return setRow(0, arg);
}

void Matrix3::row1(Vector3 arg) {
    return setRow(1, arg);
}

void Matrix3::row2(Vector3 arg) {
    return setRow(2, arg);
}

void Matrix3::setRow(Vector3 arg, int row) {
    Unknown argStorage = arg._v3storage;
    _m3storage[index(row, 0)] = argStorage[0];
    _m3storage[index(row, 1)] = argStorage[1];
    _m3storage[index(row, 2)] = argStorage[2];
}

Vector3 Matrix3::getRow(int row) {
    Unknown r = Vector3.zero();
    Unknown rStorage = r._v3storage;
    rStorage[0] = _m3storage[index(row, 0)];
    rStorage[1] = _m3storage[index(row, 1)];
    rStorage[2] = _m3storage[index(row, 2)];
    return r;
}

void Matrix3::setColumn(Vector3 arg, int column) {
    Unknown argStorage = arg._v3storage;
    Unknown entry = column * 3;
    _m3storage[entry + 2] = argStorage[2];
    _m3storage[entry + 1] = argStorage[1];
    _m3storage[entry + 0] = argStorage[0];
}

Vector3 Matrix3::getColumn(int column) {
    Unknown r = Vector3.zero();
    Unknown rStorage = r._v3storage;
    Unknown entry = column * 3;
    rStorage[2] = _m3storage[entry + 2];
    rStorage[1] = _m3storage[entry + 1];
    rStorage[0] = _m3storage[entry + 0];
    return r;
}

Matrix3 Matrix3::clone() {
    return Matrix3.copy(this);
}

Matrix3 Matrix3::copyInto(Matrix3 arg) {
    Unknown argStorage = arg._m3storage;
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

dynamic Matrix3::*(dynamic arg) {
    if (arg is double) {
        return scaled(arg);
    }
    if (arg is Vector3) {
        return transformed(arg);
    }
    if (arg is Matrix3) {
        return multiplied(arg);
    }
    ;
}

Matrix3 Matrix3::+(Matrix3 arg) {
    return ;
}

Matrix3 Matrix3::-(Matrix3 arg) {
    return ;
}

Matrix3 Matrix3::-() {
    return ;
}

void Matrix3::setZero() {
    _m3storage[0] = 0.0;
    _m3storage[1] = 0.0;
    _m3storage[2] = 0.0;
    _m3storage[3] = 0.0;
    _m3storage[4] = 0.0;
    _m3storage[5] = 0.0;
    _m3storage[6] = 0.0;
    _m3storage[7] = 0.0;
    _m3storage[8] = 0.0;
}

void Matrix3::setIdentity() {
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

Matrix3 Matrix3::transposed() {
    return ;
}

void Matrix3::transpose() {
    double temp;
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

Matrix3 Matrix3::absolute() {
    Unknown r = Matrix3.zero();
    Unknown rStorage = r._m3storage;
    rStorage[0] = _m3storage[0].abs();
    rStorage[1] = _m3storage[1].abs();
    rStorage[2] = _m3storage[2].abs();
    rStorage[3] = _m3storage[3].abs();
    rStorage[4] = _m3storage[4].abs();
    rStorage[5] = _m3storage[5].abs();
    rStorage[6] = _m3storage[6].abs();
    rStorage[7] = _m3storage[7].abs();
    rStorage[8] = _m3storage[8].abs();
    return r;
}

double Matrix3::determinant() {
    Unknown x = _m3storage[0] * ((_m3storage[4] * _m3storage[8]) - (_m3storage[5] * _m3storage[7]));
    Unknown y = _m3storage[1] * ((_m3storage[3] * _m3storage[8]) - (_m3storage[5] * _m3storage[6]));
    Unknown z = _m3storage[2] * ((_m3storage[3] * _m3storage[7]) - (_m3storage[4] * _m3storage[6]));
    return x - y + z;
}

double Matrix3::dotRow(int i, Vector3 v) {
    Unknown vStorage = v._v3storage;
    return _m3storage[i] * vStorage[0] + _m3storage[3 + i] * vStorage[1] + _m3storage[6 + i] * vStorage[2];
}

double Matrix3::dotColumn(int j, Vector3 v) {
    Unknown vStorage = v._v3storage;
    return _m3storage[j * 3] * vStorage[0] + _m3storage[j * 3 + 1] * vStorage[1] + _m3storage[j * 3 + 2] * vStorage[2];
}

double Matrix3::trace() {
    auto t = 0.0;
    t = _m3storage[0];
    t = _m3storage[4];
    t = _m3storage[8];
    return t;
}

double Matrix3::infinityNorm() {
    auto norm = 0.0;
    {
        auto row_norm = 0.0;
        row_norm = _m3storage[0].abs();
        row_norm = _m3storage[1].abs();
        row_norm = _m3storage[2].abs();
        norm = row_norm > norm? row_norm : norm;
    }    {
        auto row_norm = 0.0;
        row_norm = _m3storage[3].abs();
        row_norm = _m3storage[4].abs();
        row_norm = _m3storage[5].abs();
        norm = row_norm > norm? row_norm : norm;
    }    {
        auto row_norm = 0.0;
        row_norm = _m3storage[6].abs();
        row_norm = _m3storage[7].abs();
        row_norm = _m3storage[8].abs();
        norm = row_norm > norm? row_norm : norm;
    }    return norm;
}

double Matrix3::relativeError(Matrix3 correct) {
    Unknown diff = correct - this;
    Unknown correct_norm = correct.infinityNorm();
    Unknown diff_norm = diff.infinityNorm();
    return diff_norm / correct_norm;
}

double Matrix3::absoluteError(Matrix3 correct) {
    Unknown this_norm = infinityNorm();
    Unknown correct_norm = correct.infinityNorm();
    Unknown diff_norm = (this_norm - correct_norm).abs();
    return diff_norm;
}

double Matrix3::invert() {
    return copyInverse(this);
}

double Matrix3::copyInverse(Matrix3 arg) {
    Unknown det = arg.determinant();
    if (det == 0.0) {
        setFrom(arg);
        return 0.0;
    }
    Unknown invDet = 1.0 / det;
    Unknown argStorage = arg._m3storage;
    Unknown ix = invDet * (argStorage[4] * argStorage[8] - argStorage[5] * argStorage[7]);
    Unknown iy = invDet * (argStorage[2] * argStorage[7] - argStorage[1] * argStorage[8]);
    Unknown iz = invDet * (argStorage[1] * argStorage[5] - argStorage[2] * argStorage[4]);
    Unknown jx = invDet * (argStorage[5] * argStorage[6] - argStorage[3] * argStorage[8]);
    Unknown jy = invDet * (argStorage[0] * argStorage[8] - argStorage[2] * argStorage[6]);
    Unknown jz = invDet * (argStorage[2] * argStorage[3] - argStorage[0] * argStorage[5]);
    Unknown kx = invDet * (argStorage[3] * argStorage[7] - argStorage[4] * argStorage[6]);
    Unknown ky = invDet * (argStorage[1] * argStorage[6] - argStorage[0] * argStorage[7]);
    Unknown kz = invDet * (argStorage[0] * argStorage[4] - argStorage[1] * argStorage[3]);
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

void Matrix3::copyNormalMatrix(Matrix4 arg) {
    copyInverse(arg.getRotation());
    transpose();
}

void Matrix3::setRotationX(double radians) {
    Unknown c = math.cos(radians);
    Unknown s = math.sin(radians);
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

void Matrix3::setRotationY(double radians) {
    Unknown c = math.cos(radians);
    Unknown s = math.sin(radians);
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

void Matrix3::setRotationZ(double radians) {
    Unknown c = math.cos(radians);
    Unknown s = math.sin(radians);
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

void Matrix3::scaleAdjoint(double scale) {
    Unknown m00 = _m3storage[0];
    Unknown m01 = _m3storage[3];
    Unknown m02 = _m3storage[6];
    Unknown m10 = _m3storage[1];
    Unknown m11 = _m3storage[4];
    Unknown m12 = _m3storage[7];
    Unknown m20 = _m3storage[2];
    Unknown m21 = _m3storage[5];
    Unknown m22 = _m3storage[8];
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

Vector3 Matrix3::absoluteRotate(Vector3 arg) {
    Unknown m00 = _m3storage[0].abs();
    Unknown m01 = _m3storage[3].abs();
    Unknown m02 = _m3storage[6].abs();
    Unknown m10 = _m3storage[1].abs();
    Unknown m11 = _m3storage[4].abs();
    Unknown m12 = _m3storage[7].abs();
    Unknown m20 = _m3storage[2].abs();
    Unknown m21 = _m3storage[5].abs();
    Unknown m22 = _m3storage[8].abs();
    Unknown argStorage = arg._v3storage;
    Unknown x = argStorage[0];
    Unknown y = argStorage[1];
    Unknown z = argStorage[2];
    argStorage[0] = x * m00 + y * m01 + z * m02;
    argStorage[1] = x * m10 + y * m11 + z * m12;
    argStorage[2] = x * m20 + y * m21 + z * m22;
    return arg;
}

Vector2 Matrix3::absoluteRotate2(Vector2 arg) {
    Unknown m00 = _m3storage[0].abs();
    Unknown m01 = _m3storage[3].abs();
    Unknown m10 = _m3storage[1].abs();
    Unknown m11 = _m3storage[4].abs();
    Unknown argStorage = arg._v2storage;
    Unknown x = argStorage[0];
    Unknown y = argStorage[1];
    argStorage[0] = x * m00 + y * m01;
    argStorage[1] = x * m10 + y * m11;
    return arg;
}

Vector2 Matrix3::transform2(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    Unknown x_ = (_m3storage[0] * argStorage[0]) + (_m3storage[3] * argStorage[1]) + _m3storage[6];
    Unknown y_ = (_m3storage[1] * argStorage[0]) + (_m3storage[4] * argStorage[1]) + _m3storage[7];
    argStorage[0] = x_;
    argStorage[1] = y_;
    return arg;
}

void Matrix3::scale(double scale) {
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

Matrix3 Matrix3::scaled(double scale) {
    return ;
}

void Matrix3::add(Matrix3 o) {
    Unknown oStorage = o._m3storage;
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

void Matrix3::sub(Matrix3 o) {
    Unknown oStorage = o._m3storage;
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

void Matrix3::negate() {
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

void Matrix3::multiply(Matrix3 arg) {
    Unknown m00 = _m3storage[0];
    Unknown m01 = _m3storage[3];
    Unknown m02 = _m3storage[6];
    Unknown m10 = _m3storage[1];
    Unknown m11 = _m3storage[4];
    Unknown m12 = _m3storage[7];
    Unknown m20 = _m3storage[2];
    Unknown m21 = _m3storage[5];
    Unknown m22 = _m3storage[8];
    Unknown argStorage = arg._m3storage;
    Unknown n00 = argStorage[0];
    Unknown n01 = argStorage[3];
    Unknown n02 = argStorage[6];
    Unknown n10 = argStorage[1];
    Unknown n11 = argStorage[4];
    Unknown n12 = argStorage[7];
    Unknown n20 = argStorage[2];
    Unknown n21 = argStorage[5];
    Unknown n22 = argStorage[8];
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

Matrix3 Matrix3::multiplied(Matrix3 arg) {
    return ;
}

void Matrix3::transposeMultiply(Matrix3 arg) {
    Unknown m00 = _m3storage[0];
    Unknown m01 = _m3storage[1];
    Unknown m02 = _m3storage[2];
    Unknown m10 = _m3storage[3];
    Unknown m11 = _m3storage[4];
    Unknown m12 = _m3storage[5];
    Unknown m20 = _m3storage[6];
    Unknown m21 = _m3storage[7];
    Unknown m22 = _m3storage[8];
    Unknown argStorage = arg._m3storage;
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

void Matrix3::multiplyTranspose(Matrix3 arg) {
    Unknown m00 = _m3storage[0];
    Unknown m01 = _m3storage[3];
    Unknown m02 = _m3storage[6];
    Unknown m10 = _m3storage[1];
    Unknown m11 = _m3storage[4];
    Unknown m12 = _m3storage[7];
    Unknown m20 = _m3storage[2];
    Unknown m21 = _m3storage[5];
    Unknown m22 = _m3storage[8];
    Unknown argStorage = arg._m3storage;
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

Vector3 Matrix3::transform(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    Unknown x_ = (_m3storage[0] * argStorage[0]) + (_m3storage[3] * argStorage[1]) + (_m3storage[6] * argStorage[2]);
    Unknown y_ = (_m3storage[1] * argStorage[0]) + (_m3storage[4] * argStorage[1]) + (_m3storage[7] * argStorage[2]);
    Unknown z_ = (_m3storage[2] * argStorage[0]) + (_m3storage[5] * argStorage[1]) + (_m3storage[8] * argStorage[2]);
    ;
    return arg;
}

Vector3 Matrix3::transformed(Vector3 arg, Vector3 out) {
    if (out == nullptr) {
        out = Vector3.copy(arg);
    } else {
        out.setFrom(arg);
    }
    return transform(out);
}

void Matrix3::copyIntoArray(List<num> array, int offset) {
    Unknown i = offset;
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

void Matrix3::copyFromArray(List<double> array, int offset) {
    Unknown i = offset;
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

List<double> Matrix3::applyToVector3Array(List<double> array, int offset) {
    for (;  < array.length; i = 3, j = 3) {
        Unknown v = ;
        array[j] = v.storage[0];
        array[j + 1] = v.storage[1];
        array[j + 2] = v.storage[2];
    }
    return array;
}

Vector3 Matrix3::right() {
    Unknown x = _m3storage[0];
    Unknown y = _m3storage[1];
    Unknown z = _m3storage[2];
    return Vector3(x, y, z);
}

Vector3 Matrix3::up() {
    Unknown x = _m3storage[3];
    Unknown y = _m3storage[4];
    Unknown z = _m3storage[5];
    return Vector3(x, y, z);
}

Vector3 Matrix3::forward() {
    Unknown x = _m3storage[6];
    Unknown y = _m3storage[7];
    Unknown z = _m3storage[8];
    return Vector3(x, y, z);
}

bool Matrix3::isIdentity() {
    return _m3storage[0] == 1.0 && _m3storage[1] == 0.0 && _m3storage[2] == 0.0 && _m3storage[3] == 0.0 && _m3storage[4] == 1.0 && _m3storage[5] == 0.0 && _m3storage[6] == 0.0 && _m3storage[7] == 0.0 && _m3storage[8] == 1.0;
}

bool Matrix3::isZero() {
    return _m3storage[0] == 0.0 && _m3storage[1] == 0.0 && _m3storage[2] == 0.0 && _m3storage[3] == 0.0 && _m3storage[4] == 0.0 && _m3storage[5] == 0.0 && _m3storage[6] == 0.0 && _m3storage[7] == 0.0 && _m3storage[8] == 0.0;
}
