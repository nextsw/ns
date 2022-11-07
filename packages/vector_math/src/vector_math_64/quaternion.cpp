#include "quaternion.hpp"
Float64List Quaternion::storage() {
    return _qStorage;
}

double Quaternion::x() {
    return _qStorage[0];
}

void Quaternion::x(double x) {
    _qStorage[0] = x;
}

double Quaternion::y() {
    return _qStorage[1];
}

void Quaternion::y(double y) {
    _qStorage[1] = y;
}

double Quaternion::z() {
    return _qStorage[2];
}

void Quaternion::z(double z) {
    _qStorage[2] = z;
}

double Quaternion::w() {
    return _qStorage[3];
}

void Quaternion::w(double w) {
    _qStorage[3] = w;
}

Quaternion::Quaternion(double w, double x, double y, double z) {
}

void Quaternion::fromRotation(Matrix3 rotationMatrix) {
    return ;
}

void Quaternion::axisAngle(double angle, Vector3 axis) {
    return ;
}

void Quaternion::fromTwoVectors(Vector3 a, Vector3 b) {
    return ;
}

void Quaternion::copy(Quaternion original) {
    return ;
}

void Quaternion::random(Random rn) {
    return ;
}

void Quaternion::identity() {
    return ;
}

void Quaternion::dq(Vector3 omega, Quaternion q) {
    return ;
}

void Quaternion::euler(double pitch, double roll, double yaw) {
    return ;
}

void Quaternion::fromBuffer(ByteBuffer buffer, int offset)

Quaternion Quaternion::clone() {
    return Quaternion.copy(this);
}

void Quaternion::setFrom(Quaternion source) {
    Unknown sourceStorage = source._qStorage;
    _qStorage[0] = sourceStorage[0];
    _qStorage[1] = sourceStorage[1];
    _qStorage[2] = sourceStorage[2];
    _qStorage[3] = sourceStorage[3];
}

void Quaternion::setValues(double w, double x, double y, double z) {
    _qStorage[0] = x;
    _qStorage[1] = y;
    _qStorage[2] = z;
    _qStorage[3] = w;
}

void Quaternion::setAxisAngle(Vector3 axis, double radians) {
    Unknown len = axis.length;
    if (len == 0.0) {
        return;
    }
    Unknown halfSin = math.sin(radians * 0.5) / len;
    Unknown axisStorage = axis.storage;
    _qStorage[0] = axisStorage[0] * halfSin;
    _qStorage[1] = axisStorage[1] * halfSin;
    _qStorage[2] = axisStorage[2] * halfSin;
    _qStorage[3] = math.cos(radians * 0.5);
}

void Quaternion::setFromRotation(Matrix3 rotationMatrix) {
    Unknown rotationMatrixStorage = rotationMatrix.storage;
    Unknown trace = rotationMatrix.trace();
    if (trace > 0.0) {
        auto s = math.sqrt(trace + 1.0);
        _qStorage[3] = s * 0.5;
        s = 0.5 / s;
        _qStorage[0] = (rotationMatrixStorage[5] - rotationMatrixStorage[7]) * s;
        _qStorage[1] = (rotationMatrixStorage[6] - rotationMatrixStorage[2]) * s;
        _qStorage[2] = (rotationMatrixStorage[1] - rotationMatrixStorage[3]) * s;
    } else {
        Unknown i = rotationMatrixStorage[0] < rotationMatrixStorage[4]? (rotationMatrixStorage[4] < rotationMatrixStorage[8]? 2 : 1) : (rotationMatrixStorage[0] < rotationMatrixStorage[8]? 2 : 0);
        Unknown j = (i + 1) % 3;
        Unknown k = (i + 2) % 3;
        auto s = math.sqrt(rotationMatrixStorage[rotationMatrix.index(i, i)] - rotationMatrixStorage[rotationMatrix.index(j, j)] - rotationMatrixStorage[rotationMatrix.index(k, k)] + 1.0);
        _qStorage[i] = s * 0.5;
        s = 0.5 / s;
        _qStorage[3] = (rotationMatrixStorage[rotationMatrix.index(k, j)] - rotationMatrixStorage[rotationMatrix.index(j, k)]) * s;
        _qStorage[j] = (rotationMatrixStorage[rotationMatrix.index(j, i)] + rotationMatrixStorage[rotationMatrix.index(i, j)]) * s;
        _qStorage[k] = (rotationMatrixStorage[rotationMatrix.index(k, i)] + rotationMatrixStorage[rotationMatrix.index(i, k)]) * s;
    }
}

void Quaternion::setFromTwoVectors(Vector3 a, Vector3 b) {
    Unknown v1 = a.normalized();
    Unknown v2 = b.normalized();
    Unknown c = v1.dot(v2);
    auto angle = math.acos(c);
    auto axis = v1.cross(v2);
    if ((1.0 + c).abs() < 0.0005) {
        angle = math.pi;
        if (v1.x > v1.y && v1.x > v1.z) {
            axis = v1.cross(Vector3(0.0, 1.0, 0.0));
        } else {
            axis = v1.cross(Vector3(1.0, 0.0, 0.0));
        }
    } else     {
        if ((1.0 - c).abs() < 0.0005) {
        angle = 0.0;
        axis = Vector3(1.0, 0.0, 0.0);
    }
;
    }    setAxisAngle(axis.normalized(), angle);
}

void Quaternion::setRandom(Random rn) {
    Unknown x0 = rn.nextDouble();
    Unknown r1 = math.sqrt(1.0 - x0);
    Unknown r2 = math.sqrt(x0);
    Unknown t1 = math.pi * 2.0 * rn.nextDouble();
    Unknown t2 = math.pi * 2.0 * rn.nextDouble();
    Unknown c1 = math.cos(t1);
    Unknown s1 = math.sin(t1);
    Unknown c2 = math.cos(t2);
    Unknown s2 = math.sin(t2);
    _qStorage[0] = s1 * r1;
    _qStorage[1] = c1 * r1;
    _qStorage[2] = s2 * r2;
    _qStorage[3] = c2 * r2;
}

void Quaternion::setDQ(Vector3 omega, Quaternion q) {
    Unknown qStorage = q._qStorage;
    Unknown omegaStorage = omega.storage;
    Unknown qx = qStorage[0];
    Unknown qy = qStorage[1];
    Unknown qz = qStorage[2];
    Unknown qw = qStorage[3];
    Unknown ox = omegaStorage[0];
    Unknown oy = omegaStorage[1];
    Unknown oz = omegaStorage[2];
    Unknown _x = ox * qw + oy * qz - oz * qy;
    Unknown _y = oy * qw + oz * qx - ox * qz;
    Unknown _z = oz * qw + ox * qy - oy * qx;
    Unknown _w = -ox * qx - oy * qy - oz * qz;
    _qStorage[0] = _x * 0.5;
    _qStorage[1] = _y * 0.5;
    _qStorage[2] = _z * 0.5;
    _qStorage[3] = _w * 0.5;
}

void Quaternion::setEuler(double pitch, double roll, double yaw) {
    Unknown halfYaw = yaw * 0.5;
    Unknown halfPitch = pitch * 0.5;
    Unknown halfRoll = roll * 0.5;
    Unknown cosYaw = math.cos(halfYaw);
    Unknown sinYaw = math.sin(halfYaw);
    Unknown cosPitch = math.cos(halfPitch);
    Unknown sinPitch = math.sin(halfPitch);
    Unknown cosRoll = math.cos(halfRoll);
    Unknown sinRoll = math.sin(halfRoll);
    _qStorage[0] = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
    _qStorage[1] = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
    _qStorage[2] = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
    _qStorage[3] = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
}

double Quaternion::normalize() {
    Unknown l = length;
    if (l == 0.0) {
        return 0.0;
    }
    Unknown d = 1.0 / l;
    _qStorage[0] = d;
    _qStorage[1] = d;
    _qStorage[2] = d;
    _qStorage[3] = d;
    return l;
}

void Quaternion::conjugate() {
    _qStorage[2] = -_qStorage[2];
    _qStorage[1] = -_qStorage[1];
    _qStorage[0] = -_qStorage[0];
}

void Quaternion::inverse() {
    Unknown l = 1.0 / length2;
    _qStorage[3] = _qStorage[3] * l;
    _qStorage[2] = -_qStorage[2] * l;
    _qStorage[1] = -_qStorage[1] * l;
    _qStorage[0] = -_qStorage[0] * l;
}

Quaternion Quaternion::normalized() {
    return ;
}

Quaternion Quaternion::conjugated() {
    return ;
}

Quaternion Quaternion::inverted() {
    return ;
}

double Quaternion::radians() {
    return 2.0 * math.acos(_qStorage[3]);
}

Vector3 Quaternion::axis() {
    Unknown den = 1.0 - (_qStorage[3] * _qStorage[3]);
    if ( < 0.0005) {
        return Vector3.zero();
    }
    Unknown scale = 1.0 / math.sqrt(den);
    return Vector3(_qStorage[0] * scale, _qStorage[1] * scale, _qStorage[2] * scale);
}

double Quaternion::length2() {
    Unknown x = _qStorage[0];
    Unknown y = _qStorage[1];
    Unknown z = _qStorage[2];
    Unknown w = _qStorage[3];
    return (x * x) + (y * y) + (z * z) + (w * w);
}

double Quaternion::length() {
    return math.sqrt(length2);
}

Vector3 Quaternion::rotated(Vector3 v) {
    Unknown out = v.clone();
    rotate(out);
    return out;
}

Vector3 Quaternion::rotate(Vector3 v) {
    Unknown _w = _qStorage[3];
    Unknown _z = _qStorage[2];
    Unknown _y = _qStorage[1];
    Unknown _x = _qStorage[0];
    Unknown tiw = _w;
    Unknown tiz = -_z;
    Unknown tiy = -_y;
    Unknown tix = -_x;
    Unknown tx = tiw * v.x + tix * 0.0 + tiy * v.z - tiz * v.y;
    Unknown ty = tiw * v.y + tiy * 0.0 + tiz * v.x - tix * v.z;
    Unknown tz = tiw * v.z + tiz * 0.0 + tix * v.y - tiy * v.x;
    Unknown tw = tiw * 0.0 - tix * v.x - tiy * v.y - tiz * v.z;
    Unknown result_x = tw * _x + tx * _w + ty * _z - tz * _y;
    Unknown result_y = tw * _y + ty * _w + tz * _x - tx * _z;
    Unknown result_z = tw * _z + tz * _w + tx * _y - ty * _x;
    Unknown vStorage = v.storage;
    vStorage[2] = result_z;
    vStorage[1] = result_y;
    vStorage[0] = result_x;
    return v;
}

void Quaternion::add(Quaternion arg) {
    Unknown argStorage = arg._qStorage;
    _qStorage[0] = _qStorage[0] + argStorage[0];
    _qStorage[1] = _qStorage[1] + argStorage[1];
    _qStorage[2] = _qStorage[2] + argStorage[2];
    _qStorage[3] = _qStorage[3] + argStorage[3];
}

void Quaternion::sub(Quaternion arg) {
    Unknown argStorage = arg._qStorage;
    _qStorage[0] = _qStorage[0] - argStorage[0];
    _qStorage[1] = _qStorage[1] - argStorage[1];
    _qStorage[2] = _qStorage[2] - argStorage[2];
    _qStorage[3] = _qStorage[3] - argStorage[3];
}

void Quaternion::scale(double scale) {
    _qStorage[3] = _qStorage[3] * scale;
    _qStorage[2] = _qStorage[2] * scale;
    _qStorage[1] = _qStorage[1] * scale;
    _qStorage[0] = _qStorage[0] * scale;
}

Quaternion Quaternion::scaled(double scale) {
    return ;
}

Quaternion Quaternion::*(Quaternion other) {
    Unknown _w = _qStorage[3];
    Unknown _z = _qStorage[2];
    Unknown _y = _qStorage[1];
    Unknown _x = _qStorage[0];
    Unknown otherStorage = other._qStorage;
    Unknown ow = otherStorage[3];
    Unknown oz = otherStorage[2];
    Unknown oy = otherStorage[1];
    Unknown ox = otherStorage[0];
    return Quaternion(_w * ox + _x * ow + _y * oz - _z * oy, _w * oy + _y * ow + _z * ox - _x * oz, _w * oz + _z * ow + _x * oy - _y * ox, _w * ow - _x * ox - _y * oy - _z * oz);
}

Quaternion Quaternion::+(Quaternion other) {
    return ;
}

Quaternion Quaternion::-(Quaternion other) {
    return ;
}

Quaternion Quaternion::-() {
    return conjugated();
}

double Quaternion::[](int i) {
    return _qStorage[i];
}

void Quaternion::[]=(double arg, int i) {
    _qStorage[i] = arg;
}

Matrix3 Quaternion::asRotationMatrix() {
    return copyRotationInto(Matrix3.zero());
}

Matrix3 Quaternion::copyRotationInto(Matrix3 rotationMatrix) {
    Unknown d = length2;
    assert(d != 0.0);
    Unknown s = 2.0 / d;
    Unknown _x = _qStorage[0];
    Unknown _y = _qStorage[1];
    Unknown _z = _qStorage[2];
    Unknown _w = _qStorage[3];
    Unknown xs = _x * s;
    Unknown ys = _y * s;
    Unknown zs = _z * s;
    Unknown wx = _w * xs;
    Unknown wy = _w * ys;
    Unknown wz = _w * zs;
    Unknown xx = _x * xs;
    Unknown xy = _x * ys;
    Unknown xz = _x * zs;
    Unknown yy = _y * ys;
    Unknown yz = _y * zs;
    Unknown zz = _z * zs;
    Unknown rotationMatrixStorage = rotationMatrix.storage;
    rotationMatrixStorage[0] = 1.0 - (yy + zz);
    rotationMatrixStorage[1] = xy + wz;
    rotationMatrixStorage[2] = xz - wy;
    rotationMatrixStorage[3] = xy - wz;
    rotationMatrixStorage[4] = 1.0 - (xx + zz);
    rotationMatrixStorage[5] = yz + wx;
    rotationMatrixStorage[6] = xz + wy;
    rotationMatrixStorage[7] = yz - wx;
    rotationMatrixStorage[8] = 1.0 - (xx + yy);
    return rotationMatrix;
}

String Quaternion::toString() {
    return "${_qStorage[0]}, ${_qStorage[1]}, ${_qStorage[2]} @ ${_qStorage[3]}";
}

double Quaternion::relativeError(Quaternion correct) {
    Unknown diff = correct - this;
    Unknown norm_diff = diff.length;
    Unknown correct_norm = correct.length;
    return norm_diff / correct_norm;
}

double Quaternion::absoluteError(Quaternion correct) {
    Unknown this_norm = length;
    Unknown correct_norm = correct.length;
    Unknown norm_diff = (this_norm - correct_norm).abs();
    return norm_diff;
}

void Quaternion::_()
