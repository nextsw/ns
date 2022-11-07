#include "matrix2.hpp"
Float64List Matrix2::storage() {
    return _m2storage;
}

void Matrix2::solve(Matrix2 A, Vector2 b, Vector2 x) {
    Unknown a11 = A.entry(0, 0);
    Unknown a12 = A.entry(0, 1);
    Unknown a21 = A.entry(1, 0);
    Unknown a22 = A.entry(1, 1);
    Unknown bx = b.x;
    Unknown by = b.y;
    auto det = a11 * a22 - a12 * a21;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    ;
}

int Matrix2::index(int col, int row) {
    return (col * 2) + row;
}

double Matrix2::entry(int col, int row) {
    assert((row >= 0) && ( < dimension));
    assert((col >= 0) && ( < dimension));
    return _m2storage[index(row, col)];
}

void Matrix2::setEntry(int col, int row, double v) {
    assert((row >= 0) && ( < dimension));
    assert((col >= 0) && ( < dimension));
    _m2storage[index(row, col)] = v;
}

Matrix2::Matrix2(double arg0, double arg1, double arg2, double arg3) {
}

void Matrix2::fromList(List<double> values) {
    return ;
}

void Matrix2::zero()

void Matrix2::identity() {
    return ;
}

void Matrix2::copy(Matrix2 other) {
    return ;
}

void Matrix2::columns(Vector2 arg0, Vector2 arg1) {
    return ;
}

void Matrix2::outer(Vector2 u, Vector2 v) {
    return ;
}

void Matrix2::rotation(double radians) {
    return ;
}

void Matrix2::setValues(double arg0, double arg1, double arg2, double arg3) {
    _m2storage[3] = arg3;
    _m2storage[2] = arg2;
    _m2storage[1] = arg1;
    _m2storage[0] = arg0;
}

void Matrix2::setColumns(Vector2 arg0, Vector2 arg1) {
    Unknown arg0Storage = arg0._v2storage;
    Unknown arg1Storage = arg1._v2storage;
    _m2storage[0] = arg0Storage[0];
    _m2storage[1] = arg0Storage[1];
    _m2storage[2] = arg1Storage[0];
    _m2storage[3] = arg1Storage[1];
}

void Matrix2::setFrom(Matrix2 arg) {
    Unknown argStorage = arg._m2storage;
    _m2storage[3] = argStorage[3];
    _m2storage[2] = argStorage[2];
    _m2storage[1] = argStorage[1];
    _m2storage[0] = argStorage[0];
}

void Matrix2::setOuter(Vector2 u, Vector2 v) {
    Unknown uStorage = u._v2storage;
    Unknown vStorage = v._v2storage;
    _m2storage[0] = uStorage[0] * vStorage[0];
    _m2storage[1] = uStorage[0] * vStorage[1];
    _m2storage[2] = uStorage[1] * vStorage[0];
    _m2storage[3] = uStorage[1] * vStorage[1];
}

void Matrix2::splatDiagonal(double arg) {
    _m2storage[0] = arg;
    _m2storage[3] = arg;
}

void Matrix2::setDiagonal(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _m2storage[0] = argStorage[0];
    _m2storage[3] = argStorage[1];
}

String Matrix2::toString() {
    return "[0] ${getRow(0)}\n[1] ${getRow(1)}\n";
}

int Matrix2::dimension() {
    return 2;
}

double Matrix2::[](int i) {
    return _m2storage[i];
}

void Matrix2::[]=(int i, double v) {
    _m2storage[i] = v;
}

bool Matrix2::==(Object other) {
    return (other is Matrix2) && (_m2storage[0] == other._m2storage[0]) && (_m2storage[1] == other._m2storage[1]) && (_m2storage[2] == other._m2storage[2]) && (_m2storage[3] == other._m2storage[3]);
}

int Matrix2::hashCode() {
    return Object.hashAll(_m2storage);
}

Vector2 Matrix2::row0() {
    return getRow(0);
}

Vector2 Matrix2::row1() {
    return getRow(1);
}

void Matrix2::row0(Vector2 arg) {
    return setRow(0, arg);
}

void Matrix2::row1(Vector2 arg) {
    return setRow(1, arg);
}

void Matrix2::setRow(Vector2 arg, int row) {
    Unknown argStorage = arg._v2storage;
    _m2storage[index(row, 0)] = argStorage[0];
    _m2storage[index(row, 1)] = argStorage[1];
}

Vector2 Matrix2::getRow(int row) {
    Unknown r = Vector2.zero();
    Unknown rStorage = r._v2storage;
    rStorage[0] = _m2storage[index(row, 0)];
    rStorage[1] = _m2storage[index(row, 1)];
    return r;
}

void Matrix2::setColumn(Vector2 arg, int column) {
    Unknown argStorage = arg._v2storage;
    Unknown entry = column * 2;
    _m2storage[entry + 1] = argStorage[1];
    _m2storage[entry + 0] = argStorage[0];
}

Vector2 Matrix2::getColumn(int column) {
    Unknown r = Vector2.zero();
    Unknown entry = column * 2;
    Unknown rStorage = r._v2storage;
    rStorage[1] = _m2storage[entry + 1];
    rStorage[0] = _m2storage[entry + 0];
    return r;
}

Matrix2 Matrix2::clone() {
    return Matrix2.copy(this);
}

Matrix2 Matrix2::copyInto(Matrix2 arg) {
    Unknown argStorage = arg._m2storage;
    argStorage[0] = _m2storage[0];
    argStorage[1] = _m2storage[1];
    argStorage[2] = _m2storage[2];
    argStorage[3] = _m2storage[3];
    return arg;
}

dynamic Matrix2::*(dynamic arg) {
    if (arg is double) {
        return scaled(arg);
    }
    if (arg is Vector2) {
        return transformed(arg);
    }
    if (arg is Matrix2) {
        return multiplied(arg);
    }
    ;
}

Matrix2 Matrix2::+(Matrix2 arg) {
    return ;
}

Matrix2 Matrix2::-(Matrix2 arg) {
    return ;
}

Matrix2 Matrix2::-() {
    return ;
}

void Matrix2::setZero() {
    _m2storage[0] = 0.0;
    _m2storage[1] = 0.0;
    _m2storage[2] = 0.0;
    _m2storage[3] = 0.0;
}

void Matrix2::setIdentity() {
    _m2storage[0] = 1.0;
    _m2storage[1] = 0.0;
    _m2storage[2] = 0.0;
    _m2storage[3] = 1.0;
}

Matrix2 Matrix2::transposed() {
    return ;
}

void Matrix2::transpose() {
    Unknown temp = _m2storage[2];
    _m2storage[2] = _m2storage[1];
    _m2storage[1] = temp;
}

Matrix2 Matrix2::absolute() {
    Unknown r = Matrix2.zero();
    Unknown rStorage = r._m2storage;
    rStorage[0] = _m2storage[0].abs();
    rStorage[1] = _m2storage[1].abs();
    rStorage[2] = _m2storage[2].abs();
    rStorage[3] = _m2storage[3].abs();
    return r;
}

double Matrix2::determinant() {
    return (_m2storage[0] * _m2storage[3]) - (_m2storage[1] * _m2storage[2]);
}

double Matrix2::dotRow(int i, Vector2 v) {
    Unknown vStorage = v._v2storage;
    return _m2storage[i] * vStorage[0] + _m2storage[2 + i] * vStorage[1];
}

double Matrix2::dotColumn(int j, Vector2 v) {
    Unknown vStorage = v._v2storage;
    return _m2storage[j * 2] * vStorage[0] + _m2storage[(j * 2) + 1] * vStorage[1];
}

double Matrix2::trace() {
    auto t = 0.0;
    t = _m2storage[0];
    t = _m2storage[3];
    return t;
}

double Matrix2::infinityNorm() {
    auto norm = 0.0;
    {
        auto rowNorm = 0.0;
        rowNorm = _m2storage[0].abs();
        rowNorm = _m2storage[1].abs();
        norm = rowNorm > norm? rowNorm : norm;
    }    {
        auto rowNorm = 0.0;
        rowNorm = _m2storage[2].abs();
        rowNorm = _m2storage[3].abs();
        norm = rowNorm > norm? rowNorm : norm;
    }    return norm;
}

double Matrix2::relativeError(Matrix2 correct) {
    Unknown diff = correct - this;
    Unknown correctNorm = correct.infinityNorm();
    Unknown diff_norm = diff.infinityNorm();
    return diff_norm / correctNorm;
}

double Matrix2::absoluteError(Matrix2 correct) {
    Unknown this_norm = infinityNorm();
    Unknown correct_norm = correct.infinityNorm();
    Unknown diff_norm = (this_norm - correct_norm).abs();
    return diff_norm;
}

double Matrix2::invert() {
    Unknown det = determinant();
    if (det == 0.0) {
        return 0.0;
    }
    Unknown invDet = 1.0 / det;
    Unknown temp = _m2storage[0];
    _m2storage[0] = _m2storage[3] * invDet;
    _m2storage[1] = -_m2storage[1] * invDet;
    _m2storage[2] = -_m2storage[2] * invDet;
    _m2storage[3] = temp * invDet;
    return det;
}

double Matrix2::copyInverse(Matrix2 arg) {
    Unknown det = arg.determinant();
    if (det == 0.0) {
        setFrom(arg);
        return 0.0;
    }
    Unknown invDet = 1.0 / det;
    Unknown argStorage = arg._m2storage;
    _m2storage[0] = argStorage[3] * invDet;
    _m2storage[1] = -argStorage[1] * invDet;
    _m2storage[2] = -argStorage[2] * invDet;
    _m2storage[3] = argStorage[0] * invDet;
    return det;
}

void Matrix2::setRotation(double radians) {
    Unknown c = math.cos(radians);
    Unknown s = math.sin(radians);
    _m2storage[0] = c;
    _m2storage[1] = s;
    _m2storage[2] = -s;
    _m2storage[3] = c;
}

void Matrix2::scaleAdjoint(double scale) {
    Unknown temp = _m2storage[0];
    _m2storage[0] = _m2storage[3] * scale;
    _m2storage[2] = -_m2storage[2] * scale;
    _m2storage[1] = -_m2storage[1] * scale;
    _m2storage[3] = temp * scale;
}

void Matrix2::scale(double scale) {
    _m2storage[0] = _m2storage[0] * scale;
    _m2storage[1] = _m2storage[1] * scale;
    _m2storage[2] = _m2storage[2] * scale;
    _m2storage[3] = _m2storage[3] * scale;
}

Matrix2 Matrix2::scaled(double scale) {
    return ;
}

void Matrix2::add(Matrix2 o) {
    Unknown oStorage = o._m2storage;
    _m2storage[0] = _m2storage[0] + oStorage[0];
    _m2storage[1] = _m2storage[1] + oStorage[1];
    _m2storage[2] = _m2storage[2] + oStorage[2];
    _m2storage[3] = _m2storage[3] + oStorage[3];
}

void Matrix2::sub(Matrix2 o) {
    Unknown oStorage = o._m2storage;
    _m2storage[0] = _m2storage[0] - oStorage[0];
    _m2storage[1] = _m2storage[1] - oStorage[1];
    _m2storage[2] = _m2storage[2] - oStorage[2];
    _m2storage[3] = _m2storage[3] - oStorage[3];
}

void Matrix2::negate() {
    _m2storage[0] = -_m2storage[0];
    _m2storage[1] = -_m2storage[1];
    _m2storage[2] = -_m2storage[2];
    _m2storage[3] = -_m2storage[3];
}

void Matrix2::multiply(Matrix2 arg) {
    Unknown m00 = _m2storage[0];
    Unknown m01 = _m2storage[2];
    Unknown m10 = _m2storage[1];
    Unknown m11 = _m2storage[3];
    Unknown argStorage = arg._m2storage;
    Unknown n00 = argStorage[0];
    Unknown n01 = argStorage[2];
    Unknown n10 = argStorage[1];
    Unknown n11 = argStorage[3];
    _m2storage[0] = (m00 * n00) + (m01 * n10);
    _m2storage[2] = (m00 * n01) + (m01 * n11);
    _m2storage[1] = (m10 * n00) + (m11 * n10);
    _m2storage[3] = (m10 * n01) + (m11 * n11);
}

Matrix2 Matrix2::multiplied(Matrix2 arg) {
    return ;
}

void Matrix2::transposeMultiply(Matrix2 arg) {
    Unknown m00 = _m2storage[0];
    Unknown m01 = _m2storage[1];
    Unknown m10 = _m2storage[2];
    Unknown m11 = _m2storage[3];
    Unknown argStorage = arg._m2storage;
    _m2storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[1]);
    _m2storage[2] = (m00 * argStorage[2]) + (m01 * argStorage[3]);
    _m2storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[1]);
    _m2storage[3] = (m10 * argStorage[2]) + (m11 * argStorage[3]);
}

void Matrix2::multiplyTranspose(Matrix2 arg) {
    Unknown m00 = _m2storage[0];
    Unknown m01 = _m2storage[2];
    Unknown m10 = _m2storage[1];
    Unknown m11 = _m2storage[3];
    Unknown argStorage = arg._m2storage;
    _m2storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[2]);
    _m2storage[2] = (m00 * argStorage[1]) + (m01 * argStorage[3]);
    _m2storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[2]);
    _m2storage[3] = (m10 * argStorage[1]) + (m11 * argStorage[3]);
}

Vector2 Matrix2::transform(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    Unknown x = (_m2storage[0] * argStorage[0]) + (_m2storage[2] * argStorage[1]);
    Unknown y = (_m2storage[1] * argStorage[0]) + (_m2storage[3] * argStorage[1]);
    argStorage[0] = x;
    argStorage[1] = y;
    return arg;
}

Vector2 Matrix2::transformed(Vector2 arg, Vector2 out) {
    if (out == nullptr) {
        out = Vector2.copy(arg);
    } else {
        out.setFrom(arg);
    }
    return transform(out);
}

void Matrix2::copyIntoArray(List<num> array, int offset) {
    Unknown i = offset;
    array[i + 3] = _m2storage[3];
    array[i + 2] = _m2storage[2];
    array[i + 1] = _m2storage[1];
    array[i + 0] = _m2storage[0];
}

void Matrix2::copyFromArray(List<double> array, int offset) {
    Unknown i = offset;
    _m2storage[3] = array[i + 3];
    _m2storage[2] = array[i + 2];
    _m2storage[1] = array[i + 1];
    _m2storage[0] = array[i + 0];
}
