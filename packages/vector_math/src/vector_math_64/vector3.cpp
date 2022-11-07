#include "vector3.hpp"
Float64List Vector3::storage() {
    return _v3storage;
}

void Vector3::min(Vector3 a, Vector3 b, Vector3 result) {
    ;
}

void Vector3::max(Vector3 a, Vector3 b, Vector3 result) {
    ;
}

void Vector3::mix(double a, Vector3 max, Vector3 min, Vector3 result) {
    ;
}

Vector3::Vector3(double x, double y, double z) {
}

void Vector3::array(List<double> array, int offset) {
    return ;
}

void Vector3::zero()

void Vector3::all(double value) {
    return ;
}

void Vector3::copy(Vector3 other) {
    return ;
}

void Vector3::fromBuffer(ByteBuffer buffer, int offset)

void Vector3::random(Random rng) {
    rng = math.Random();
    return Vector3(rng.nextDouble(), rng.nextDouble(), rng.nextDouble());
}

void Vector3::setValues(double x, double y, double z) {
    _v3storage[0] = x;
    _v3storage[1] = y;
    _v3storage[2] = z;
}

void Vector3::setZero() {
    _v3storage[2] = 0.0;
    _v3storage[1] = 0.0;
    _v3storage[0] = 0.0;
}

void Vector3::setFrom(Vector3 other) {
    Unknown otherStorage = other._v3storage;
    _v3storage[0] = otherStorage[0];
    _v3storage[1] = otherStorage[1];
    _v3storage[2] = otherStorage[2];
}

void Vector3::splat(double arg) {
    _v3storage[2] = arg;
    _v3storage[1] = arg;
    _v3storage[0] = arg;
}

String Vector3::toString() {
    return "[${storage[0]},${storage[1]},${storage[2]}]";
}

bool Vector3::==(Object other) {
    return (other is Vector3) && (_v3storage[0] == other._v3storage[0]) && (_v3storage[1] == other._v3storage[1]) && (_v3storage[2] == other._v3storage[2]);
}

int Vector3::hashCode() {
    return Object.hashAll(_v3storage);
}

Vector3 Vector3::-() {
    return ;
}

Vector3 Vector3::-(Vector3 other) {
    return ;
}

Vector3 Vector3::+(Vector3 other) {
    return ;
}

Vector3 Vector3::/(double scale) {
    return scaled(1.0 / scale);
}

Vector3 Vector3::*(double scale) {
    return scaled(scale);
}

double Vector3::[](int i) {
    return _v3storage[i];
}

void Vector3::[]=(int i, double v) {
    _v3storage[i] = v;
}

void Vector3::length(double value) {
    if (value == 0.0) {
        setZero();
    } else {
        auto l = length;
        if (l == 0.0) {
            return;
        }
        l = value / l;
        _v3storage[0] = l;
        _v3storage[1] = l;
        _v3storage[2] = l;
    }
}

double Vector3::length() {
    return math.sqrt(length2);
}

double Vector3::length2() {
    double sum;
    sum = _v3storage[0] * _v3storage[0];
    sum = _v3storage[1] * _v3storage[1];
    sum = _v3storage[2] * _v3storage[2];
    return sum;
}

double Vector3::normalize() {
    Unknown l = length;
    if (l == 0.0) {
        return 0.0;
    }
    Unknown d = 1.0 / l;
    _v3storage[0] = d;
    _v3storage[1] = d;
    _v3storage[2] = d;
    return l;
}

double Vector3::normalizeLength() {
    return normalize();
}

Vector3 Vector3::normalized() {
    return ;
}

Vector3 Vector3::normalizeInto(Vector3 out) {
    ;
    return out;
}

double Vector3::distanceTo(Vector3 arg) {
    return math.sqrt(distanceToSquared(arg));
}

double Vector3::distanceToSquared(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    Unknown dx = _v3storage[0] - argStorage[0];
    Unknown dy = _v3storage[1] - argStorage[1];
    Unknown dz = _v3storage[2] - argStorage[2];
    return dx * dx + dy * dy + dz * dz;
}

double Vector3::angleTo(Vector3 other) {
    Unknown otherStorage = other._v3storage;
    if (_v3storage[0] == otherStorage[0] && _v3storage[1] == otherStorage[1] && _v3storage[2] == otherStorage[2]) {
        return 0.0;
    }
    Unknown d = dot(other) / (length * other.length);
    return math.acos(d.clamp(-1.0, 1.0));
}

double Vector3::angleToSigned(Vector3 normal, Vector3 other) {
    Unknown angle = angleTo(other);
    Unknown c = cross(other);
    Unknown d = c.dot(normal);
    return  < 0.0? -angle : angle;
}

double Vector3::dot(Vector3 other) {
    Unknown otherStorage = other._v3storage;
    double sum;
    sum = _v3storage[0] * otherStorage[0];
    sum = _v3storage[1] * otherStorage[1];
    sum = _v3storage[2] * otherStorage[2];
    return sum;
}

void Vector3::postmultiply(Matrix3 arg) {
    Unknown argStorage = arg.storage;
    Unknown v0 = _v3storage[0];
    Unknown v1 = _v3storage[1];
    Unknown v2 = _v3storage[2];
    _v3storage[0] = v0 * argStorage[0] + v1 * argStorage[1] + v2 * argStorage[2];
    _v3storage[1] = v0 * argStorage[3] + v1 * argStorage[4] + v2 * argStorage[5];
    _v3storage[2] = v0 * argStorage[6] + v1 * argStorage[7] + v2 * argStorage[8];
}

Vector3 Vector3::cross(Vector3 other) {
    Unknown _x = _v3storage[0];
    Unknown _y = _v3storage[1];
    Unknown _z = _v3storage[2];
    Unknown otherStorage = other._v3storage;
    Unknown ox = otherStorage[0];
    Unknown oy = otherStorage[1];
    Unknown oz = otherStorage[2];
    return Vector3(_y * oz - _z * oy, _z * ox - _x * oz, _x * oy - _y * ox);
}

Vector3 Vector3::crossInto(Vector3 other, Vector3 out) {
    Unknown x = _v3storage[0];
    Unknown y = _v3storage[1];
    Unknown z = _v3storage[2];
    Unknown otherStorage = other._v3storage;
    Unknown ox = otherStorage[0];
    Unknown oy = otherStorage[1];
    Unknown oz = otherStorage[2];
    Unknown outStorage = out._v3storage;
    outStorage[0] = y * oz - z * oy;
    outStorage[1] = z * ox - x * oz;
    outStorage[2] = x * oy - y * ox;
    return out;
}

void Vector3::reflect(Vector3 normal) {
    sub(normal.scaled(2.0 * normal.dot(this)));
}

Vector3 Vector3::reflected(Vector3 normal) {
    return ;
}

void Vector3::applyProjection(Matrix4 arg) {
    Unknown argStorage = arg.storage;
    Unknown x = _v3storage[0];
    Unknown y = _v3storage[1];
    Unknown z = _v3storage[2];
    Unknown d = 1.0 / (argStorage[3] * x + argStorage[7] * y + argStorage[11] * z + argStorage[15]);
    _v3storage[0] = (argStorage[0] * x + argStorage[4] * y + argStorage[8] * z + argStorage[12]) * d;
    _v3storage[1] = (argStorage[1] * x + argStorage[5] * y + argStorage[9] * z + argStorage[13]) * d;
    _v3storage[2] = (argStorage[2] * x + argStorage[6] * y + argStorage[10] * z + argStorage[14]) * d;
}

void Vector3::applyAxisAngle(double angle, Vector3 axis) {
    applyQuaternion(Quaternion.axisAngle(axis, angle));
}

void Vector3::applyQuaternion(Quaternion arg) {
    Unknown argStorage = arg._qStorage;
    Unknown v0 = _v3storage[0];
    Unknown v1 = _v3storage[1];
    Unknown v2 = _v3storage[2];
    Unknown qx = argStorage[0];
    Unknown qy = argStorage[1];
    Unknown qz = argStorage[2];
    Unknown qw = argStorage[3];
    Unknown ix = qw * v0 + qy * v2 - qz * v1;
    Unknown iy = qw * v1 + qz * v0 - qx * v2;
    Unknown iz = qw * v2 + qx * v1 - qy * v0;
    Unknown iw = -qx * v0 - qy * v1 - qz * v2;
    _v3storage[0] = ix * qw + iw * -qx + iy * -qz - iz * -qy;
    _v3storage[1] = iy * qw + iw * -qy + iz * -qx - ix * -qz;
    _v3storage[2] = iz * qw + iw * -qz + ix * -qy - iy * -qx;
}

void Vector3::applyMatrix3(Matrix3 arg) {
    Unknown argStorage = arg.storage;
    Unknown v0 = _v3storage[0];
    Unknown v1 = _v3storage[1];
    Unknown v2 = _v3storage[2];
    _v3storage[0] = argStorage[0] * v0 + argStorage[3] * v1 + argStorage[6] * v2;
    _v3storage[1] = argStorage[1] * v0 + argStorage[4] * v1 + argStorage[7] * v2;
    _v3storage[2] = argStorage[2] * v0 + argStorage[5] * v1 + argStorage[8] * v2;
}

void Vector3::applyMatrix4(Matrix4 arg) {
    Unknown argStorage = arg.storage;
    Unknown v0 = _v3storage[0];
    Unknown v1 = _v3storage[1];
    Unknown v2 = _v3storage[2];
    _v3storage[0] = argStorage[0] * v0 + argStorage[4] * v1 + argStorage[8] * v2 + argStorage[12];
    _v3storage[1] = argStorage[1] * v0 + argStorage[5] * v1 + argStorage[9] * v2 + argStorage[13];
    _v3storage[2] = argStorage[2] * v0 + argStorage[6] * v1 + argStorage[10] * v2 + argStorage[14];
}

double Vector3::relativeError(Vector3 correct) {
    Unknown correct_norm = correct.length;
    Unknown diff_norm = (this - correct).length;
    return diff_norm / correct_norm;
}

double Vector3::absoluteError(Vector3 correct) {
    return (this - correct).length;
}

bool Vector3::isInfinite() {
    auto is_infinite = false;
    is_infinite = is_infinite || _v3storage[0].isInfinite;
    is_infinite = is_infinite || _v3storage[1].isInfinite;
    is_infinite = is_infinite || _v3storage[2].isInfinite;
    return is_infinite;
}

bool Vector3::isNaN() {
    auto isNan = false;
    isNan = isNan || _v3storage[0].isNaN;
    isNan = isNan || _v3storage[1].isNaN;
    isNan = isNan || _v3storage[2].isNaN;
    return isNan;
}

void Vector3::add(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[0] = _v3storage[0] + argStorage[0];
    _v3storage[1] = _v3storage[1] + argStorage[1];
    _v3storage[2] = _v3storage[2] + argStorage[2];
}

void Vector3::addScaled(Vector3 arg, double factor) {
    Unknown argStorage = arg._v3storage;
    _v3storage[0] = _v3storage[0] + argStorage[0] * factor;
    _v3storage[1] = _v3storage[1] + argStorage[1] * factor;
    _v3storage[2] = _v3storage[2] + argStorage[2] * factor;
}

void Vector3::sub(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[0] = _v3storage[0] - argStorage[0];
    _v3storage[1] = _v3storage[1] - argStorage[1];
    _v3storage[2] = _v3storage[2] - argStorage[2];
}

void Vector3::multiply(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[0] = _v3storage[0] * argStorage[0];
    _v3storage[1] = _v3storage[1] * argStorage[1];
    _v3storage[2] = _v3storage[2] * argStorage[2];
}

void Vector3::divide(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[0] = _v3storage[0] / argStorage[0];
    _v3storage[1] = _v3storage[1] / argStorage[1];
    _v3storage[2] = _v3storage[2] / argStorage[2];
}

void Vector3::scale(double arg) {
    _v3storage[2] = _v3storage[2] * arg;
    _v3storage[1] = _v3storage[1] * arg;
    _v3storage[0] = _v3storage[0] * arg;
}

Vector3 Vector3::scaled(double arg) {
    return ;
}

void Vector3::negate() {
    _v3storage[2] = -_v3storage[2];
    _v3storage[1] = -_v3storage[1];
    _v3storage[0] = -_v3storage[0];
}

void Vector3::absolute() {
    _v3storage[0] = _v3storage[0].abs();
    _v3storage[1] = _v3storage[1].abs();
    _v3storage[2] = _v3storage[2].abs();
}

void Vector3::clamp(Vector3 max, Vector3 min) {
    Unknown minStorage = min.storage;
    Unknown maxStorage = max.storage;
    _v3storage[0] = _v3storage[0].clamp(minStorage[0], maxStorage[0]).toDouble();
    _v3storage[1] = _v3storage[1].clamp(minStorage[1], maxStorage[1]).toDouble();
    _v3storage[2] = _v3storage[2].clamp(minStorage[2], maxStorage[2]).toDouble();
}

void Vector3::clampScalar(double max, double min) {
    _v3storage[0] = _v3storage[0].clamp(min, max).toDouble();
    _v3storage[1] = _v3storage[1].clamp(min, max).toDouble();
    _v3storage[2] = _v3storage[2].clamp(min, max).toDouble();
}

void Vector3::floor() {
    _v3storage[0] = _v3storage[0].floorToDouble();
    _v3storage[1] = _v3storage[1].floorToDouble();
    _v3storage[2] = _v3storage[2].floorToDouble();
}

void Vector3::ceil() {
    _v3storage[0] = _v3storage[0].ceilToDouble();
    _v3storage[1] = _v3storage[1].ceilToDouble();
    _v3storage[2] = _v3storage[2].ceilToDouble();
}

void Vector3::round() {
    _v3storage[0] = _v3storage[0].roundToDouble();
    _v3storage[1] = _v3storage[1].roundToDouble();
    _v3storage[2] = _v3storage[2].roundToDouble();
}

void Vector3::roundToZero() {
    _v3storage[0] = _v3storage[0] < 0.0? _v3storage[0].ceilToDouble() : _v3storage[0].floorToDouble();
    _v3storage[1] = _v3storage[1] < 0.0? _v3storage[1].ceilToDouble() : _v3storage[1].floorToDouble();
    _v3storage[2] = _v3storage[2] < 0.0? _v3storage[2].ceilToDouble() : _v3storage[2].floorToDouble();
}

Vector3 Vector3::clone() {
    return Vector3.copy(this);
}

Vector3 Vector3::copyInto(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    argStorage[0] = _v3storage[0];
    argStorage[1] = _v3storage[1];
    argStorage[2] = _v3storage[2];
    return arg;
}

void Vector3::copyIntoArray(List<double> array, int offset) {
    array[offset + 2] = _v3storage[2];
    array[offset + 1] = _v3storage[1];
    array[offset + 0] = _v3storage[0];
}

void Vector3::copyFromArray(List<double> array, int offset) {
    _v3storage[2] = array[offset + 2];
    _v3storage[1] = array[offset + 1];
    _v3storage[0] = array[offset + 0];
}

void Vector3::xy(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v3storage[0] = argStorage[0];
    _v3storage[1] = argStorage[1];
}

void Vector3::xz(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v3storage[0] = argStorage[0];
    _v3storage[2] = argStorage[1];
}

void Vector3::yx(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v3storage[1] = argStorage[0];
    _v3storage[0] = argStorage[1];
}

void Vector3::yz(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v3storage[1] = argStorage[0];
    _v3storage[2] = argStorage[1];
}

void Vector3::zx(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v3storage[2] = argStorage[0];
    _v3storage[0] = argStorage[1];
}

void Vector3::zy(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v3storage[2] = argStorage[0];
    _v3storage[1] = argStorage[1];
}

void Vector3::xyz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[0] = argStorage[0];
    _v3storage[1] = argStorage[1];
    _v3storage[2] = argStorage[2];
}

void Vector3::xzy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[0] = argStorage[0];
    _v3storage[2] = argStorage[1];
    _v3storage[1] = argStorage[2];
}

void Vector3::yxz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[1] = argStorage[0];
    _v3storage[0] = argStorage[1];
    _v3storage[2] = argStorage[2];
}

void Vector3::yzx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[1] = argStorage[0];
    _v3storage[2] = argStorage[1];
    _v3storage[0] = argStorage[2];
}

void Vector3::zxy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[2] = argStorage[0];
    _v3storage[0] = argStorage[1];
    _v3storage[1] = argStorage[2];
}

void Vector3::zyx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v3storage[2] = argStorage[0];
    _v3storage[1] = argStorage[1];
    _v3storage[0] = argStorage[2];
}

void Vector3::r(double arg) {
    return x = arg;
}

void Vector3::g(double arg) {
    return y = arg;
}

void Vector3::b(double arg) {
    return z = arg;
}

void Vector3::s(double arg) {
    return x = arg;
}

void Vector3::t(double arg) {
    return y = arg;
}

void Vector3::p(double arg) {
    return z = arg;
}

void Vector3::x(double arg) {
    return _v3storage[0] = arg;
}

void Vector3::y(double arg) {
    return _v3storage[1] = arg;
}

void Vector3::z(double arg) {
    return _v3storage[2] = arg;
}

void Vector3::rg(Vector2 arg) {
    return xy = arg;
}

void Vector3::rb(Vector2 arg) {
    return xz = arg;
}

void Vector3::gr(Vector2 arg) {
    return yx = arg;
}

void Vector3::gb(Vector2 arg) {
    return yz = arg;
}

void Vector3::br(Vector2 arg) {
    return zx = arg;
}

void Vector3::bg(Vector2 arg) {
    return zy = arg;
}

void Vector3::rgb(Vector3 arg) {
    return xyz = arg;
}

void Vector3::rbg(Vector3 arg) {
    return xzy = arg;
}

void Vector3::grb(Vector3 arg) {
    return yxz = arg;
}

void Vector3::gbr(Vector3 arg) {
    return yzx = arg;
}

void Vector3::brg(Vector3 arg) {
    return zxy = arg;
}

void Vector3::bgr(Vector3 arg) {
    return zyx = arg;
}

void Vector3::st(Vector2 arg) {
    return xy = arg;
}

void Vector3::sp(Vector2 arg) {
    return xz = arg;
}

void Vector3::ts(Vector2 arg) {
    return yx = arg;
}

void Vector3::tp(Vector2 arg) {
    return yz = arg;
}

void Vector3::ps(Vector2 arg) {
    return zx = arg;
}

void Vector3::pt(Vector2 arg) {
    return zy = arg;
}

void Vector3::stp(Vector3 arg) {
    return xyz = arg;
}

void Vector3::spt(Vector3 arg) {
    return xzy = arg;
}

void Vector3::tsp(Vector3 arg) {
    return yxz = arg;
}

void Vector3::tps(Vector3 arg) {
    return yzx = arg;
}

void Vector3::pst(Vector3 arg) {
    return zxy = arg;
}

void Vector3::pts(Vector3 arg) {
    return zyx = arg;
}

Vector2 Vector3::xx() {
    return Vector2(_v3storage[0], _v3storage[0]);
}

Vector2 Vector3::xy() {
    return Vector2(_v3storage[0], _v3storage[1]);
}

Vector2 Vector3::xz() {
    return Vector2(_v3storage[0], _v3storage[2]);
}

Vector2 Vector3::yx() {
    return Vector2(_v3storage[1], _v3storage[0]);
}

Vector2 Vector3::yy() {
    return Vector2(_v3storage[1], _v3storage[1]);
}

Vector2 Vector3::yz() {
    return Vector2(_v3storage[1], _v3storage[2]);
}

Vector2 Vector3::zx() {
    return Vector2(_v3storage[2], _v3storage[0]);
}

Vector2 Vector3::zy() {
    return Vector2(_v3storage[2], _v3storage[1]);
}

Vector2 Vector3::zz() {
    return Vector2(_v3storage[2], _v3storage[2]);
}

Vector3 Vector3::xxx() {
    return Vector3(_v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector3 Vector3::xxy() {
    return Vector3(_v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector3 Vector3::xxz() {
    return Vector3(_v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector3 Vector3::xyx() {
    return Vector3(_v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector3 Vector3::xyy() {
    return Vector3(_v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector3 Vector3::xyz() {
    return Vector3(_v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector3 Vector3::xzx() {
    return Vector3(_v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector3 Vector3::xzy() {
    return Vector3(_v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector3 Vector3::xzz() {
    return Vector3(_v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector3 Vector3::yxx() {
    return Vector3(_v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector3 Vector3::yxy() {
    return Vector3(_v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector3 Vector3::yxz() {
    return Vector3(_v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector3 Vector3::yyx() {
    return Vector3(_v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector3 Vector3::yyy() {
    return Vector3(_v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector3 Vector3::yyz() {
    return Vector3(_v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector3 Vector3::yzx() {
    return Vector3(_v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector3 Vector3::yzy() {
    return Vector3(_v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector3 Vector3::yzz() {
    return Vector3(_v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector3 Vector3::zxx() {
    return Vector3(_v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector3 Vector3::zxy() {
    return Vector3(_v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector3 Vector3::zxz() {
    return Vector3(_v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector3 Vector3::zyx() {
    return Vector3(_v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector3 Vector3::zyy() {
    return Vector3(_v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector3 Vector3::zyz() {
    return Vector3(_v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector3 Vector3::zzx() {
    return Vector3(_v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector3 Vector3::zzy() {
    return Vector3(_v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector3 Vector3::zzz() {
    return Vector3(_v3storage[2], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::xxxx() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::xxxy() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::xxxz() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::xxyx() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::xxyy() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::xxyz() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::xxzx() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::xxzy() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::xxzz() {
    return Vector4(_v3storage[0], _v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::xyxx() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::xyxy() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::xyxz() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::xyyx() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::xyyy() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::xyyz() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::xyzx() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::xyzy() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::xyzz() {
    return Vector4(_v3storage[0], _v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::xzxx() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::xzxy() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::xzxz() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::xzyx() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::xzyy() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::xzyz() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::xzzx() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::xzzy() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::xzzz() {
    return Vector4(_v3storage[0], _v3storage[2], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::yxxx() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::yxxy() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::yxxz() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::yxyx() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::yxyy() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::yxyz() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::yxzx() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::yxzy() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::yxzz() {
    return Vector4(_v3storage[1], _v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::yyxx() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::yyxy() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::yyxz() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::yyyx() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::yyyy() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::yyyz() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::yyzx() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::yyzy() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::yyzz() {
    return Vector4(_v3storage[1], _v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::yzxx() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::yzxy() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::yzxz() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::yzyx() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::yzyy() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::yzyz() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::yzzx() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::yzzy() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::yzzz() {
    return Vector4(_v3storage[1], _v3storage[2], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::zxxx() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::zxxy() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::zxxz() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::zxyx() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::zxyy() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::zxyz() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::zxzx() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::zxzy() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::zxzz() {
    return Vector4(_v3storage[2], _v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::zyxx() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::zyxy() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::zyxz() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::zyyx() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::zyyy() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::zyyz() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::zyzx() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::zyzy() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::zyzz() {
    return Vector4(_v3storage[2], _v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3::zzxx() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3::zzxy() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3::zzxz() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3::zzyx() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3::zzyy() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3::zzyz() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3::zzzx() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3::zzzy() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3::zzzz() {
    return Vector4(_v3storage[2], _v3storage[2], _v3storage[2], _v3storage[2]);
}

double Vector3::r() {
    return x;
}

double Vector3::g() {
    return y;
}

double Vector3::b() {
    return z;
}

double Vector3::s() {
    return x;
}

double Vector3::t() {
    return y;
}

double Vector3::p() {
    return z;
}

double Vector3::x() {
    return _v3storage[0];
}

double Vector3::y() {
    return _v3storage[1];
}

double Vector3::z() {
    return _v3storage[2];
}

Vector2 Vector3::rr() {
    return xx;
}

Vector2 Vector3::rg() {
    return xy;
}

Vector2 Vector3::rb() {
    return xz;
}

Vector2 Vector3::gr() {
    return yx;
}

Vector2 Vector3::gg() {
    return yy;
}

Vector2 Vector3::gb() {
    return yz;
}

Vector2 Vector3::br() {
    return zx;
}

Vector2 Vector3::bg() {
    return zy;
}

Vector2 Vector3::bb() {
    return zz;
}

Vector3 Vector3::rrr() {
    return xxx;
}

Vector3 Vector3::rrg() {
    return xxy;
}

Vector3 Vector3::rrb() {
    return xxz;
}

Vector3 Vector3::rgr() {
    return xzx;
}

Vector3 Vector3::rgg() {
    return xyy;
}

Vector3 Vector3::rgb() {
    return xyz;
}

Vector3 Vector3::rbr() {
    return xzx;
}

Vector3 Vector3::rbg() {
    return xzy;
}

Vector3 Vector3::rbb() {
    return xzz;
}

Vector3 Vector3::grr() {
    return yxx;
}

Vector3 Vector3::grg() {
    return yxy;
}

Vector3 Vector3::grb() {
    return yxz;
}

Vector3 Vector3::ggr() {
    return yyx;
}

Vector3 Vector3::ggg() {
    return yyy;
}

Vector3 Vector3::ggb() {
    return yyz;
}

Vector3 Vector3::gbr() {
    return yxz;
}

Vector3 Vector3::gbg() {
    return yzy;
}

Vector3 Vector3::gbb() {
    return yzz;
}

Vector3 Vector3::brr() {
    return zxx;
}

Vector3 Vector3::brg() {
    return zxy;
}

Vector3 Vector3::brb() {
    return zxz;
}

Vector3 Vector3::bgr() {
    return zyx;
}

Vector3 Vector3::bgg() {
    return zyy;
}

Vector3 Vector3::bgb() {
    return zyz;
}

Vector3 Vector3::bbr() {
    return zzx;
}

Vector3 Vector3::bbg() {
    return zzy;
}

Vector3 Vector3::bbb() {
    return zzz;
}

Vector4 Vector3::rrrr() {
    return xxxx;
}

Vector4 Vector3::rrrg() {
    return xxxy;
}

Vector4 Vector3::rrrb() {
    return xxxz;
}

Vector4 Vector3::rrgr() {
    return xxyx;
}

Vector4 Vector3::rrgg() {
    return xxyy;
}

Vector4 Vector3::rrgb() {
    return xxyz;
}

Vector4 Vector3::rrbr() {
    return xxzx;
}

Vector4 Vector3::rrbg() {
    return xxzy;
}

Vector4 Vector3::rrbb() {
    return xxzz;
}

Vector4 Vector3::rgrr() {
    return xyxx;
}

Vector4 Vector3::rgrg() {
    return xyxy;
}

Vector4 Vector3::rgrb() {
    return xyxz;
}

Vector4 Vector3::rggr() {
    return xyyx;
}

Vector4 Vector3::rggg() {
    return xyyy;
}

Vector4 Vector3::rggb() {
    return xyyz;
}

Vector4 Vector3::rgbr() {
    return xyzx;
}

Vector4 Vector3::rgbg() {
    return xyzy;
}

Vector4 Vector3::rgbb() {
    return xyzz;
}

Vector4 Vector3::rbrr() {
    return xzxx;
}

Vector4 Vector3::rbrg() {
    return xzxy;
}

Vector4 Vector3::rbrb() {
    return xzxz;
}

Vector4 Vector3::rbgr() {
    return xzyx;
}

Vector4 Vector3::rbgg() {
    return xzyy;
}

Vector4 Vector3::rbgb() {
    return xzyz;
}

Vector4 Vector3::rbbr() {
    return xzzx;
}

Vector4 Vector3::rbbg() {
    return xzzy;
}

Vector4 Vector3::rbbb() {
    return xzzz;
}

Vector4 Vector3::grrr() {
    return yxxx;
}

Vector4 Vector3::grrg() {
    return yxxy;
}

Vector4 Vector3::grrb() {
    return yxxz;
}

Vector4 Vector3::grgr() {
    return yxyx;
}

Vector4 Vector3::grgg() {
    return yxyy;
}

Vector4 Vector3::grgb() {
    return yxyz;
}

Vector4 Vector3::grbr() {
    return yxzx;
}

Vector4 Vector3::grbg() {
    return yxzy;
}

Vector4 Vector3::grbb() {
    return yxzz;
}

Vector4 Vector3::ggrr() {
    return yyxx;
}

Vector4 Vector3::ggrg() {
    return yyxy;
}

Vector4 Vector3::ggrb() {
    return yyxz;
}

Vector4 Vector3::gggr() {
    return yyyx;
}

Vector4 Vector3::gggg() {
    return yyyy;
}

Vector4 Vector3::gggb() {
    return yyyz;
}

Vector4 Vector3::ggbr() {
    return yyzx;
}

Vector4 Vector3::ggbg() {
    return yyzy;
}

Vector4 Vector3::ggbb() {
    return yyzz;
}

Vector4 Vector3::gbrr() {
    return yzxx;
}

Vector4 Vector3::gbrg() {
    return yzxy;
}

Vector4 Vector3::gbrb() {
    return yzxz;
}

Vector4 Vector3::gbgr() {
    return yzyx;
}

Vector4 Vector3::gbgg() {
    return yzyy;
}

Vector4 Vector3::gbgb() {
    return yzyz;
}

Vector4 Vector3::gbbr() {
    return yzzx;
}

Vector4 Vector3::gbbg() {
    return yzzy;
}

Vector4 Vector3::gbbb() {
    return yzzz;
}

Vector4 Vector3::brrr() {
    return zxxx;
}

Vector4 Vector3::brrg() {
    return zxxy;
}

Vector4 Vector3::brrb() {
    return zxxz;
}

Vector4 Vector3::brgr() {
    return zxyx;
}

Vector4 Vector3::brgg() {
    return zxyy;
}

Vector4 Vector3::brgb() {
    return zxyz;
}

Vector4 Vector3::brbr() {
    return zxzx;
}

Vector4 Vector3::brbg() {
    return zxzy;
}

Vector4 Vector3::brbb() {
    return zxzz;
}

Vector4 Vector3::bgrr() {
    return zyxx;
}

Vector4 Vector3::bgrg() {
    return zyxy;
}

Vector4 Vector3::bgrb() {
    return zyxz;
}

Vector4 Vector3::bggr() {
    return zyyx;
}

Vector4 Vector3::bggg() {
    return zyyy;
}

Vector4 Vector3::bggb() {
    return zyyz;
}

Vector4 Vector3::bgbr() {
    return zyzx;
}

Vector4 Vector3::bgbg() {
    return zyzy;
}

Vector4 Vector3::bgbb() {
    return zyzz;
}

Vector4 Vector3::bbrr() {
    return zzxx;
}

Vector4 Vector3::bbrg() {
    return zzxy;
}

Vector4 Vector3::bbrb() {
    return zzxz;
}

Vector4 Vector3::bbgr() {
    return zzyx;
}

Vector4 Vector3::bbgg() {
    return zzyy;
}

Vector4 Vector3::bbgb() {
    return zzyz;
}

Vector4 Vector3::bbbr() {
    return zzzx;
}

Vector4 Vector3::bbbg() {
    return zzzy;
}

Vector4 Vector3::bbbb() {
    return zzzz;
}

Vector2 Vector3::ss() {
    return xx;
}

Vector2 Vector3::st() {
    return xy;
}

Vector2 Vector3::sp() {
    return xz;
}

Vector2 Vector3::ts() {
    return yx;
}

Vector2 Vector3::tt() {
    return yy;
}

Vector2 Vector3::tp() {
    return yz;
}

Vector2 Vector3::ps() {
    return zx;
}

Vector2 Vector3::pt() {
    return zy;
}

Vector2 Vector3::pp() {
    return zz;
}

Vector3 Vector3::sss() {
    return xxx;
}

Vector3 Vector3::sst() {
    return xxy;
}

Vector3 Vector3::ssp() {
    return xxz;
}

Vector3 Vector3::sts() {
    return xyx;
}

Vector3 Vector3::stt() {
    return xyy;
}

Vector3 Vector3::stp() {
    return xyz;
}

Vector3 Vector3::sps() {
    return xzx;
}

Vector3 Vector3::spt() {
    return xzy;
}

Vector3 Vector3::spp() {
    return xzz;
}

Vector3 Vector3::tss() {
    return yxx;
}

Vector3 Vector3::tst() {
    return yxy;
}

Vector3 Vector3::tsp() {
    return yxz;
}

Vector3 Vector3::tts() {
    return yyx;
}

Vector3 Vector3::ttt() {
    return yyy;
}

Vector3 Vector3::ttp() {
    return yyz;
}

Vector3 Vector3::tps() {
    return yzx;
}

Vector3 Vector3::tpt() {
    return yzy;
}

Vector3 Vector3::tpp() {
    return yzz;
}

Vector3 Vector3::pss() {
    return zxx;
}

Vector3 Vector3::pst() {
    return zxy;
}

Vector3 Vector3::psp() {
    return zxz;
}

Vector3 Vector3::pts() {
    return zyx;
}

Vector3 Vector3::ptt() {
    return zyy;
}

Vector3 Vector3::ptp() {
    return zyz;
}

Vector3 Vector3::pps() {
    return zzx;
}

Vector3 Vector3::ppt() {
    return zzy;
}

Vector3 Vector3::ppp() {
    return zzz;
}

Vector4 Vector3::ssss() {
    return xxxx;
}

Vector4 Vector3::ssst() {
    return xxxy;
}

Vector4 Vector3::sssp() {
    return xxxz;
}

Vector4 Vector3::ssts() {
    return xxyx;
}

Vector4 Vector3::sstt() {
    return xxyy;
}

Vector4 Vector3::sstp() {
    return xxyz;
}

Vector4 Vector3::ssps() {
    return xxzx;
}

Vector4 Vector3::sspt() {
    return xxzy;
}

Vector4 Vector3::sspp() {
    return xxzz;
}

Vector4 Vector3::stss() {
    return xyxx;
}

Vector4 Vector3::stst() {
    return xyxy;
}

Vector4 Vector3::stsp() {
    return xyxz;
}

Vector4 Vector3::stts() {
    return xyyx;
}

Vector4 Vector3::sttt() {
    return xyyy;
}

Vector4 Vector3::sttp() {
    return xyyz;
}

Vector4 Vector3::stps() {
    return xyzx;
}

Vector4 Vector3::stpt() {
    return xyzy;
}

Vector4 Vector3::stpp() {
    return xyzz;
}

Vector4 Vector3::spss() {
    return xzxx;
}

Vector4 Vector3::spst() {
    return xzxy;
}

Vector4 Vector3::spsp() {
    return xzxz;
}

Vector4 Vector3::spts() {
    return xzyx;
}

Vector4 Vector3::sptt() {
    return xzyy;
}

Vector4 Vector3::sptp() {
    return xzyz;
}

Vector4 Vector3::spps() {
    return xzzx;
}

Vector4 Vector3::sppt() {
    return xzzy;
}

Vector4 Vector3::sppp() {
    return xzzz;
}

Vector4 Vector3::tsss() {
    return yxxx;
}

Vector4 Vector3::tsst() {
    return yxxy;
}

Vector4 Vector3::tssp() {
    return yxxz;
}

Vector4 Vector3::tsts() {
    return yxyx;
}

Vector4 Vector3::tstt() {
    return yxyy;
}

Vector4 Vector3::tstp() {
    return yxyz;
}

Vector4 Vector3::tsps() {
    return yxzx;
}

Vector4 Vector3::tspt() {
    return yxzy;
}

Vector4 Vector3::tspp() {
    return yxzz;
}

Vector4 Vector3::ttss() {
    return yyxx;
}

Vector4 Vector3::ttst() {
    return yyxy;
}

Vector4 Vector3::ttsp() {
    return yyxz;
}

Vector4 Vector3::ttts() {
    return yyyx;
}

Vector4 Vector3::tttt() {
    return yyyy;
}

Vector4 Vector3::tttp() {
    return yyyz;
}

Vector4 Vector3::ttps() {
    return yyzx;
}

Vector4 Vector3::ttpt() {
    return yyzy;
}

Vector4 Vector3::ttpp() {
    return yyzz;
}

Vector4 Vector3::tpss() {
    return yzxx;
}

Vector4 Vector3::tpst() {
    return yzxy;
}

Vector4 Vector3::tpsp() {
    return yzxz;
}

Vector4 Vector3::tpts() {
    return yzyx;
}

Vector4 Vector3::tptt() {
    return yzyy;
}

Vector4 Vector3::tptp() {
    return yzyz;
}

Vector4 Vector3::tpps() {
    return yzzx;
}

Vector4 Vector3::tppt() {
    return yzzy;
}

Vector4 Vector3::tppp() {
    return yzzz;
}

Vector4 Vector3::psss() {
    return zxxx;
}

Vector4 Vector3::psst() {
    return zxxy;
}

Vector4 Vector3::pssp() {
    return zxxz;
}

Vector4 Vector3::psts() {
    return zxyx;
}

Vector4 Vector3::pstt() {
    return zxyy;
}

Vector4 Vector3::pstp() {
    return zxyz;
}

Vector4 Vector3::psps() {
    return zxzx;
}

Vector4 Vector3::pspt() {
    return zxzy;
}

Vector4 Vector3::pspp() {
    return zxzz;
}

Vector4 Vector3::ptss() {
    return zyxx;
}

Vector4 Vector3::ptst() {
    return zyxy;
}

Vector4 Vector3::ptsp() {
    return zyxz;
}

Vector4 Vector3::ptts() {
    return zyyx;
}

Vector4 Vector3::pttt() {
    return zyyy;
}

Vector4 Vector3::pttp() {
    return zyyz;
}

Vector4 Vector3::ptps() {
    return zyzx;
}

Vector4 Vector3::ptpt() {
    return zyzy;
}

Vector4 Vector3::ptpp() {
    return zyzz;
}

Vector4 Vector3::ppss() {
    return zzxx;
}

Vector4 Vector3::ppst() {
    return zzxy;
}

Vector4 Vector3::ppsp() {
    return zzxz;
}

Vector4 Vector3::ppts() {
    return zzyx;
}

Vector4 Vector3::pptt() {
    return zzyy;
}

Vector4 Vector3::pptp() {
    return zzyz;
}

Vector4 Vector3::ppps() {
    return zzzx;
}

Vector4 Vector3::pppt() {
    return zzzy;
}

Vector4 Vector3::pppp() {
    return zzzz;
}
