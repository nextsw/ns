#include "matrix2.hpp"
Float64List Matrix2Cls::storage() {
    return _m2storage;
}

void Matrix2Cls::solve(Matrix2 A, Vector2 b, Vector2 x) {
    Unknown a11 = ACls->entry(0, 0);
    Unknown a12 = ACls->entry(0, 1);
    Unknown a21 = ACls->entry(1, 0);
    Unknown a22 = ACls->entry(1, 1);
    Unknown bx = b->x;
    Unknown by = b->y;
    auto det = a11 * a22 - a12 * a21;
    if (det != 0.0) {
        det = 1.0 / det;
    }
    auto _c1 = x;_c1.x = auto _c2 = det * (a22 * bx - a12 * by);_c2.y = det * (a11 * by - a21 * bx);_c2;_c1;
}

int Matrix2Cls::index(int col, int row) {
    return (col * 2) + row;
}

double Matrix2Cls::entry(int col, int row) {
    assert((row >= 0) && ( < dimension));
    assert((col >= 0) && ( < dimension));
    return _m2storage[index(row, col)];
}

void Matrix2Cls::setEntry(int col, int row, double v) {
    assert((row >= 0) && ( < dimension));
    assert((col >= 0) && ( < dimension));
    _m2storage[index(row, col)] = v;
}

Matrix2Cls::Matrix2Cls(double arg0, double arg1, double arg2, double arg3) {
}

void Matrix2Cls::fromList(List<double> values) {
    return _c1;
}

void Matrix2Cls::zero()

void Matrix2Cls::identity() {
    return _c1;
}

void Matrix2Cls::copy(Matrix2 other) {
    return _c1;
}

void Matrix2Cls::columns(Vector2 arg0, Vector2 arg1) {
    return _c1;
}

void Matrix2Cls::outer(Vector2 u, Vector2 v) {
    return _c1;
}

void Matrix2Cls::rotation(double radians) {
    return _c1;
}

void Matrix2Cls::setValues(double arg0, double arg1, double arg2, double arg3) {
    auto _c1 = Matrix2Cls->zero();_c1.setValues(values[0], values[1], values[2], values[3]);auto _c1 = Matrix2Cls->zero();_c1.setIdentity();auto _c1 = Matrix2Cls->zero();_c1.setFrom(other);auto _c1 = Matrix2Cls->zero();_c1.setColumns(arg0, arg1);auto _c1 = Matrix2Cls->zero();_c1.setOuter(u, v);auto _c1 = Matrix2Cls->zero();_c1.setRotation(radians);_m2storage[3] = arg3;
    _m2storage[2] = arg2;
    _m2storage[1] = arg1;
    _m2storage[0] = arg0;
}

void Matrix2Cls::setColumns(Vector2 arg0, Vector2 arg1) {
    Unknown arg0Storage = arg0->_v2storage;
    Unknown arg1Storage = arg1->_v2storage;
    _m2storage[0] = arg0Storage[0];
    _m2storage[1] = arg0Storage[1];
    _m2storage[2] = arg1Storage[0];
    _m2storage[3] = arg1Storage[1];
}

void Matrix2Cls::setFrom(Matrix2 arg) {
    Unknown argStorage = arg->_m2storage;
    _m2storage[3] = argStorage[3];
    _m2storage[2] = argStorage[2];
    _m2storage[1] = argStorage[1];
    _m2storage[0] = argStorage[0];
}

void Matrix2Cls::setOuter(Vector2 u, Vector2 v) {
    Unknown uStorage = u->_v2storage;
    Unknown vStorage = v->_v2storage;
    _m2storage[0] = uStorage[0] * vStorage[0];
    _m2storage[1] = uStorage[0] * vStorage[1];
    _m2storage[2] = uStorage[1] * vStorage[0];
    _m2storage[3] = uStorage[1] * vStorage[1];
}

void Matrix2Cls::splatDiagonal(double arg) {
    _m2storage[0] = arg;
    _m2storage[3] = arg;
}

void Matrix2Cls::setDiagonal(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _m2storage[0] = argStorage[0];
    _m2storage[3] = argStorage[1];
}

String Matrix2Cls::toString() {
    return "[0] ${getRow(0)}\n[1] ${getRow(1)}\n";
}

int Matrix2Cls::dimension() {
    return 2;
}

double Matrix2Cls::[](int i) {
    return _m2storage[i];
}

void Matrix2Cls::[]=(int i, double v) {
    _m2storage[i] = v;
}

bool Matrix2Cls::==(Object other) {
    return (other is Matrix2) && (_m2storage[0] == other->_m2storage[0]) && (_m2storage[1] == other->_m2storage[1]) && (_m2storage[2] == other->_m2storage[2]) && (_m2storage[3] == other->_m2storage[3]);
}

int Matrix2Cls::hashCode() {
    return ObjectCls->hashAll(_m2storage);
}

Vector2 Matrix2Cls::row0() {
    return getRow(0);
}

Vector2 Matrix2Cls::row1() {
    return getRow(1);
}

void Matrix2Cls::row0(Vector2 arg) {
    return setRow(0, arg);
}

void Matrix2Cls::row1(Vector2 arg) {
    return setRow(1, arg);
}

void Matrix2Cls::setRow(Vector2 arg, int row) {
    Unknown argStorage = arg->_v2storage;
    _m2storage[index(row, 0)] = argStorage[0];
    _m2storage[index(row, 1)] = argStorage[1];
}

Vector2 Matrix2Cls::getRow(int row) {
    Unknown r = Vector2Cls->zero();
    Unknown rStorage = r->_v2storage;
    rStorage[0] = _m2storage[index(row, 0)];
    rStorage[1] = _m2storage[index(row, 1)];
    return r;
}

void Matrix2Cls::setColumn(Vector2 arg, int column) {
    Unknown argStorage = arg->_v2storage;
    Unknown entry = column * 2;
    _m2storage[entry + 1] = argStorage[1];
    _m2storage[entry + 0] = argStorage[0];
}

Vector2 Matrix2Cls::getColumn(int column) {
    Unknown r = Vector2Cls->zero();
    Unknown entry = column * 2;
    Unknown rStorage = r->_v2storage;
    rStorage[1] = _m2storage[entry + 1];
    rStorage[0] = _m2storage[entry + 0];
    return r;
}

Matrix2 Matrix2Cls::clone() {
    return Matrix2Cls->copy(this);
}

Matrix2 Matrix2Cls::copyInto(Matrix2 arg) {
    Unknown argStorage = arg->_m2storage;
    argStorage[0] = _m2storage[0];
    argStorage[1] = _m2storage[1];
    argStorage[2] = _m2storage[2];
    argStorage[3] = _m2storage[3];
    return arg;
}

dynamic Matrix2Cls::*(dynamic arg) {
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

Matrix2 Matrix2Cls::+(Matrix2 arg) {
    return _c1;
}

Matrix2 Matrix2Cls::-(Matrix2 arg) {
    return _c1;
}

Matrix2 Matrix2Cls::-() {
    return _c1;
}

void Matrix2Cls::setZero() {
    auto _c1 = clone();_c1.add(arg);auto _c1 = clone();_c1.sub(arg);auto _c1 = clone();_c1.negate();_m2storage[0] = 0.0;
    _m2storage[1] = 0.0;
    _m2storage[2] = 0.0;
    _m2storage[3] = 0.0;
}

void Matrix2Cls::setIdentity() {
    _m2storage[0] = 1.0;
    _m2storage[1] = 0.0;
    _m2storage[2] = 0.0;
    _m2storage[3] = 1.0;
}

Matrix2 Matrix2Cls::transposed() {
    return _c1;
}

void Matrix2Cls::transpose() {
    auto _c1 = clone();_c1.transpose();Unknown temp = _m2storage[2];
    _m2storage[2] = _m2storage[1];
    _m2storage[1] = temp;
}

Matrix2 Matrix2Cls::absolute() {
    Unknown r = Matrix2Cls->zero();
    Unknown rStorage = r->_m2storage;
    rStorage[0] = _m2storage[0]->abs();
    rStorage[1] = _m2storage[1]->abs();
    rStorage[2] = _m2storage[2]->abs();
    rStorage[3] = _m2storage[3]->abs();
    return r;
}

double Matrix2Cls::determinant() {
    return (_m2storage[0] * _m2storage[3]) - (_m2storage[1] * _m2storage[2]);
}

double Matrix2Cls::dotRow(int i, Vector2 v) {
    Unknown vStorage = v->_v2storage;
    return _m2storage[i] * vStorage[0] + _m2storage[2 + i] * vStorage[1];
}

double Matrix2Cls::dotColumn(int j, Vector2 v) {
    Unknown vStorage = v->_v2storage;
    return _m2storage[j * 2] * vStorage[0] + _m2storage[(j * 2) + 1] * vStorage[1];
}

double Matrix2Cls::trace() {
    auto t = 0.0;
    t = _m2storage[0];
    t = _m2storage[3];
    return t;
}

double Matrix2Cls::infinityNorm() {
    auto norm = 0.0;
    {
        auto rowNorm = 0.0;
        rowNorm = _m2storage[0]->abs();
        rowNorm = _m2storage[1]->abs();
        norm = rowNorm > norm? rowNorm : norm;
    }    {
        auto rowNorm = 0.0;
        rowNorm = _m2storage[2]->abs();
        rowNorm = _m2storage[3]->abs();
        norm = rowNorm > norm? rowNorm : norm;
    }    return norm;
}

double Matrix2Cls::relativeError(Matrix2 correct) {
    Unknown diff = correct - this;
    Unknown correctNorm = correct->infinityNorm();
    Unknown diff_norm = diff->infinityNorm();
    return diff_norm / correctNorm;
}

double Matrix2Cls::absoluteError(Matrix2 correct) {
    Unknown this_norm = infinityNorm();
    Unknown correct_norm = correct->infinityNorm();
    Unknown diff_norm = (this_norm - correct_norm)->abs();
    return diff_norm;
}

double Matrix2Cls::invert() {
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

double Matrix2Cls::copyInverse(Matrix2 arg) {
    Unknown det = arg->determinant();
    if (det == 0.0) {
        setFrom(arg);
        return 0.0;
    }
    Unknown invDet = 1.0 / det;
    Unknown argStorage = arg->_m2storage;
    _m2storage[0] = argStorage[3] * invDet;
    _m2storage[1] = -argStorage[1] * invDet;
    _m2storage[2] = -argStorage[2] * invDet;
    _m2storage[3] = argStorage[0] * invDet;
    return det;
}

void Matrix2Cls::setRotation(double radians) {
    Unknown c = math->cos(radians);
    Unknown s = math->sin(radians);
    _m2storage[0] = c;
    _m2storage[1] = s;
    _m2storage[2] = -s;
    _m2storage[3] = c;
}

void Matrix2Cls::scaleAdjoint(double scale) {
    Unknown temp = _m2storage[0];
    _m2storage[0] = _m2storage[3] * scale;
    _m2storage[2] = -_m2storage[2] * scale;
    _m2storage[1] = -_m2storage[1] * scale;
    _m2storage[3] = temp * scale;
}

void Matrix2Cls::scale(double scale) {
    _m2storage[0] = _m2storage[0] * scale;
    _m2storage[1] = _m2storage[1] * scale;
    _m2storage[2] = _m2storage[2] * scale;
    _m2storage[3] = _m2storage[3] * scale;
}

Matrix2 Matrix2Cls::scaled(double scale) {
    return _c1;
}

void Matrix2Cls::add(Matrix2 o) {
    auto _c1 = clone();_c1.scale(scale);Unknown oStorage = o->_m2storage;
    _m2storage[0] = _m2storage[0] + oStorage[0];
    _m2storage[1] = _m2storage[1] + oStorage[1];
    _m2storage[2] = _m2storage[2] + oStorage[2];
    _m2storage[3] = _m2storage[3] + oStorage[3];
}

void Matrix2Cls::sub(Matrix2 o) {
    Unknown oStorage = o->_m2storage;
    _m2storage[0] = _m2storage[0] - oStorage[0];
    _m2storage[1] = _m2storage[1] - oStorage[1];
    _m2storage[2] = _m2storage[2] - oStorage[2];
    _m2storage[3] = _m2storage[3] - oStorage[3];
}

void Matrix2Cls::negate() {
    _m2storage[0] = -_m2storage[0];
    _m2storage[1] = -_m2storage[1];
    _m2storage[2] = -_m2storage[2];
    _m2storage[3] = -_m2storage[3];
}

void Matrix2Cls::multiply(Matrix2 arg) {
    Unknown m00 = _m2storage[0];
    Unknown m01 = _m2storage[2];
    Unknown m10 = _m2storage[1];
    Unknown m11 = _m2storage[3];
    Unknown argStorage = arg->_m2storage;
    Unknown n00 = argStorage[0];
    Unknown n01 = argStorage[2];
    Unknown n10 = argStorage[1];
    Unknown n11 = argStorage[3];
    _m2storage[0] = (m00 * n00) + (m01 * n10);
    _m2storage[2] = (m00 * n01) + (m01 * n11);
    _m2storage[1] = (m10 * n00) + (m11 * n10);
    _m2storage[3] = (m10 * n01) + (m11 * n11);
}

Matrix2 Matrix2Cls::multiplied(Matrix2 arg) {
    return _c1;
}

void Matrix2Cls::transposeMultiply(Matrix2 arg) {
    auto _c1 = clone();_c1.multiply(arg);Unknown m00 = _m2storage[0];
    Unknown m01 = _m2storage[1];
    Unknown m10 = _m2storage[2];
    Unknown m11 = _m2storage[3];
    Unknown argStorage = arg->_m2storage;
    _m2storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[1]);
    _m2storage[2] = (m00 * argStorage[2]) + (m01 * argStorage[3]);
    _m2storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[1]);
    _m2storage[3] = (m10 * argStorage[2]) + (m11 * argStorage[3]);
}

void Matrix2Cls::multiplyTranspose(Matrix2 arg) {
    Unknown m00 = _m2storage[0];
    Unknown m01 = _m2storage[2];
    Unknown m10 = _m2storage[1];
    Unknown m11 = _m2storage[3];
    Unknown argStorage = arg->_m2storage;
    _m2storage[0] = (m00 * argStorage[0]) + (m01 * argStorage[2]);
    _m2storage[2] = (m00 * argStorage[1]) + (m01 * argStorage[3]);
    _m2storage[1] = (m10 * argStorage[0]) + (m11 * argStorage[2]);
    _m2storage[3] = (m10 * argStorage[1]) + (m11 * argStorage[3]);
}

Vector2 Matrix2Cls::transform(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    Unknown x = (_m2storage[0] * argStorage[0]) + (_m2storage[2] * argStorage[1]);
    Unknown y = (_m2storage[1] * argStorage[0]) + (_m2storage[3] * argStorage[1]);
    argStorage[0] = x;
    argStorage[1] = y;
    return arg;
}

Vector2 Matrix2Cls::transformed(Vector2 arg, Vector2 out) {
    if (out == nullptr) {
        out = Vector2Cls->copy(arg);
    } else {
        out->setFrom(arg);
    }
    return transform(out);
}

void Matrix2Cls::copyIntoArray(List<num> array, int offset) {
    Unknown i = offset;
    array[i + 3] = _m2storage[3];
    array[i + 2] = _m2storage[2];
    array[i + 1] = _m2storage[1];
    array[i + 0] = _m2storage[0];
}

void Matrix2Cls::copyFromArray(List<double> array, int offset) {
    Unknown i = offset;
    _m2storage[3] = array[i + 3];
    _m2storage[2] = array[i + 2];
    _m2storage[1] = array[i + 1];
    _m2storage[0] = array[i + 0];
}
