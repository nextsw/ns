#include "vector4.hpp"
void Vector4::min(Vector4 a, Vector4 b, Vector4 result) {
    ;
}

void Vector4::max(Vector4 a, Vector4 b, Vector4 result) {
    ;
}

void Vector4::mix(double a, Vector4 max, Vector4 min, Vector4 result) {
    ;
}

Float64List Vector4::storage() {
    return _v4storage;
}

Vector4::Vector4(double w, double x, double y, double z) {
}

void Vector4::array(List<double> array, int offset) {
    return ;
}

void Vector4::zero()

void Vector4::identity() {
    return ;
}

void Vector4::all(double value) {
    return ;
}

void Vector4::copy(Vector4 other) {
    return ;
}

void Vector4::fromBuffer(ByteBuffer buffer, int offset)

void Vector4::random(Random rng) {
    rng = math.Random();
    return Vector4(rng.nextDouble(), rng.nextDouble(), rng.nextDouble(), rng.nextDouble());
}

void Vector4::setValues(double w_, double x_, double y_, double z_) {
    _v4storage[3] = w_;
    _v4storage[2] = z_;
    _v4storage[1] = y_;
    _v4storage[0] = x_;
}

void Vector4::setZero() {
    _v4storage[0] = 0.0;
    _v4storage[1] = 0.0;
    _v4storage[2] = 0.0;
    _v4storage[3] = 0.0;
}

void Vector4::setIdentity() {
    _v4storage[0] = 0.0;
    _v4storage[1] = 0.0;
    _v4storage[2] = 0.0;
    _v4storage[3] = 1.0;
}

void Vector4::setFrom(Vector4 other) {
    Unknown otherStorage = other._v4storage;
    _v4storage[3] = otherStorage[3];
    _v4storage[2] = otherStorage[2];
    _v4storage[1] = otherStorage[1];
    _v4storage[0] = otherStorage[0];
}

void Vector4::splat(double arg) {
    _v4storage[3] = arg;
    _v4storage[2] = arg;
    _v4storage[1] = arg;
    _v4storage[0] = arg;
}

String Vector4::toString() {
    return "${_v4storage[0]},${_v4storage[1]},${_v4storage[2]},${_v4storage[3]}";
}

bool Vector4::==(Object other) {
    return (other is Vector4) && (_v4storage[0] == other._v4storage[0]) && (_v4storage[1] == other._v4storage[1]) && (_v4storage[2] == other._v4storage[2]) && (_v4storage[3] == other._v4storage[3]);
}

int Vector4::hashCode() {
    return Object.hashAll(_v4storage);
}

Vector4 Vector4::-() {
    return ;
}

Vector4 Vector4::-(Vector4 other) {
    return ;
}

Vector4 Vector4::+(Vector4 other) {
    return ;
}

Vector4 Vector4::/(double scale) {
    return ;
}

Vector4 Vector4::*(double scale) {
    return ;
}

double Vector4::[](int i) {
    return _v4storage[i];
}

void Vector4::[]=(int i, double v) {
    _v4storage[i] = v;
}

void Vector4::length(double value) {
    if (value == 0.0) {
        setZero();
    } else {
        auto l = length;
        if (l == 0.0) {
            return;
        }
        l = value / l;
        _v4storage[0] = l;
        _v4storage[1] = l;
        _v4storage[2] = l;
        _v4storage[3] = l;
    }
}

double Vector4::length() {
    return math.sqrt(length2);
}

double Vector4::length2() {
    double sum;
    sum = _v4storage[0] * _v4storage[0];
    sum = _v4storage[1] * _v4storage[1];
    sum = _v4storage[2] * _v4storage[2];
    sum = _v4storage[3] * _v4storage[3];
    return sum;
}

double Vector4::normalize() {
    Unknown l = length;
    if (l == 0.0) {
        return 0.0;
    }
    Unknown d = 1.0 / l;
    _v4storage[0] = d;
    _v4storage[1] = d;
    _v4storage[2] = d;
    _v4storage[3] = d;
    return l;
}

double Vector4::normalizeLength() {
    return normalize();
}

Vector4 Vector4::normalized() {
    return ;
}

Vector4 Vector4::normalizeInto(Vector4 out) {
    ;
    return out;
}

double Vector4::distanceTo(Vector4 arg) {
    return math.sqrt(distanceToSquared(arg));
}

double Vector4::distanceToSquared(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    Unknown dx = _v4storage[0] - argStorage[0];
    Unknown dy = _v4storage[1] - argStorage[1];
    Unknown dz = _v4storage[2] - argStorage[2];
    Unknown dw = _v4storage[3] - argStorage[3];
    return dx * dx + dy * dy + dz * dz + dw * dw;
}

double Vector4::dot(Vector4 other) {
    Unknown otherStorage = other._v4storage;
    double sum;
    sum = _v4storage[0] * otherStorage[0];
    sum = _v4storage[1] * otherStorage[1];
    sum = _v4storage[2] * otherStorage[2];
    sum = _v4storage[3] * otherStorage[3];
    return sum;
}

void Vector4::applyMatrix4(Matrix4 arg) {
    Unknown v1 = _v4storage[0];
    Unknown v2 = _v4storage[1];
    Unknown v3 = _v4storage[2];
    Unknown v4 = _v4storage[3];
    Unknown argStorage = arg.storage;
    _v4storage[0] = argStorage[0] * v1 + argStorage[4] * v2 + argStorage[8] * v3 + argStorage[12] * v4;
    _v4storage[1] = argStorage[1] * v1 + argStorage[5] * v2 + argStorage[9] * v3 + argStorage[13] * v4;
    _v4storage[2] = argStorage[2] * v1 + argStorage[6] * v2 + argStorage[10] * v3 + argStorage[14] * v4;
    _v4storage[3] = argStorage[3] * v1 + argStorage[7] * v2 + argStorage[11] * v3 + argStorage[15] * v4;
}

double Vector4::relativeError(Vector4 correct) {
    Unknown correct_norm = correct.length;
    Unknown diff_norm = (this - correct).length;
    return diff_norm / correct_norm;
}

double Vector4::absoluteError(Vector4 correct) {
    return (this - correct).length;
}

bool Vector4::isInfinite() {
    auto is_infinite = false;
    is_infinite = is_infinite || _v4storage[0].isInfinite;
    is_infinite = is_infinite || _v4storage[1].isInfinite;
    is_infinite = is_infinite || _v4storage[2].isInfinite;
    is_infinite = is_infinite || _v4storage[3].isInfinite;
    return is_infinite;
}

bool Vector4::isNaN() {
    auto is_nan = false;
    is_nan = is_nan || _v4storage[0].isNaN;
    is_nan = is_nan || _v4storage[1].isNaN;
    is_nan = is_nan || _v4storage[2].isNaN;
    is_nan = is_nan || _v4storage[3].isNaN;
    return is_nan;
}

void Vector4::add(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = _v4storage[0] + argStorage[0];
    _v4storage[1] = _v4storage[1] + argStorage[1];
    _v4storage[2] = _v4storage[2] + argStorage[2];
    _v4storage[3] = _v4storage[3] + argStorage[3];
}

void Vector4::addScaled(Vector4 arg, double factor) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = _v4storage[0] + argStorage[0] * factor;
    _v4storage[1] = _v4storage[1] + argStorage[1] * factor;
    _v4storage[2] = _v4storage[2] + argStorage[2] * factor;
    _v4storage[3] = _v4storage[3] + argStorage[3] * factor;
}

void Vector4::sub(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = _v4storage[0] - argStorage[0];
    _v4storage[1] = _v4storage[1] - argStorage[1];
    _v4storage[2] = _v4storage[2] - argStorage[2];
    _v4storage[3] = _v4storage[3] - argStorage[3];
}

void Vector4::multiply(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = _v4storage[0] * argStorage[0];
    _v4storage[1] = _v4storage[1] * argStorage[1];
    _v4storage[2] = _v4storage[2] * argStorage[2];
    _v4storage[3] = _v4storage[3] * argStorage[3];
}

void Vector4::div(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = _v4storage[0] / argStorage[0];
    _v4storage[1] = _v4storage[1] / argStorage[1];
    _v4storage[2] = _v4storage[2] / argStorage[2];
    _v4storage[3] = _v4storage[3] / argStorage[3];
}

void Vector4::scale(double arg) {
    _v4storage[0] = _v4storage[0] * arg;
    _v4storage[1] = _v4storage[1] * arg;
    _v4storage[2] = _v4storage[2] * arg;
    _v4storage[3] = _v4storage[3] * arg;
}

Vector4 Vector4::scaled(double arg) {
    return ;
}

void Vector4::negate() {
    _v4storage[0] = -_v4storage[0];
    _v4storage[1] = -_v4storage[1];
    _v4storage[2] = -_v4storage[2];
    _v4storage[3] = -_v4storage[3];
}

void Vector4::absolute() {
    _v4storage[3] = _v4storage[3].abs();
    _v4storage[2] = _v4storage[2].abs();
    _v4storage[1] = _v4storage[1].abs();
    _v4storage[0] = _v4storage[0].abs();
}

void Vector4::clamp(Vector4 max, Vector4 min) {
    Unknown minStorage = min.storage;
    Unknown maxStorage = max.storage;
    _v4storage[0] = _v4storage[0].clamp(minStorage[0], maxStorage[0]).toDouble();
    _v4storage[1] = _v4storage[1].clamp(minStorage[1], maxStorage[1]).toDouble();
    _v4storage[2] = _v4storage[2].clamp(minStorage[2], maxStorage[2]).toDouble();
    _v4storage[3] = _v4storage[3].clamp(minStorage[3], maxStorage[3]).toDouble();
}

void Vector4::clampScalar(double max, double min) {
    _v4storage[0] = _v4storage[0].clamp(min, max).toDouble();
    _v4storage[1] = _v4storage[1].clamp(min, max).toDouble();
    _v4storage[2] = _v4storage[2].clamp(min, max).toDouble();
    _v4storage[3] = _v4storage[3].clamp(min, max).toDouble();
}

void Vector4::floor() {
    _v4storage[0] = _v4storage[0].floorToDouble();
    _v4storage[1] = _v4storage[1].floorToDouble();
    _v4storage[2] = _v4storage[2].floorToDouble();
    _v4storage[3] = _v4storage[3].floorToDouble();
}

void Vector4::ceil() {
    _v4storage[0] = _v4storage[0].ceilToDouble();
    _v4storage[1] = _v4storage[1].ceilToDouble();
    _v4storage[2] = _v4storage[2].ceilToDouble();
    _v4storage[3] = _v4storage[3].ceilToDouble();
}

void Vector4::round() {
    _v4storage[0] = _v4storage[0].roundToDouble();
    _v4storage[1] = _v4storage[1].roundToDouble();
    _v4storage[2] = _v4storage[2].roundToDouble();
    _v4storage[3] = _v4storage[3].roundToDouble();
}

void Vector4::roundToZero() {
    _v4storage[0] = _v4storage[0] < 0.0? _v4storage[0].ceilToDouble() : _v4storage[0].floorToDouble();
    _v4storage[1] = _v4storage[1] < 0.0? _v4storage[1].ceilToDouble() : _v4storage[1].floorToDouble();
    _v4storage[2] = _v4storage[2] < 0.0? _v4storage[2].ceilToDouble() : _v4storage[2].floorToDouble();
    _v4storage[3] = _v4storage[3] < 0.0? _v4storage[3].ceilToDouble() : _v4storage[3].floorToDouble();
}

Vector4 Vector4::clone() {
    return Vector4.copy(this);
}

Vector4 Vector4::copyInto(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    argStorage[0] = _v4storage[0];
    argStorage[1] = _v4storage[1];
    argStorage[2] = _v4storage[2];
    argStorage[3] = _v4storage[3];
    return arg;
}

void Vector4::copyIntoArray(List<double> array, int offset) {
    array[offset + 0] = _v4storage[0];
    array[offset + 1] = _v4storage[1];
    array[offset + 2] = _v4storage[2];
    array[offset + 3] = _v4storage[3];
}

void Vector4::copyFromArray(List<double> array, int offset) {
    _v4storage[0] = array[offset + 0];
    _v4storage[1] = array[offset + 1];
    _v4storage[2] = array[offset + 2];
    _v4storage[3] = array[offset + 3];
}

void Vector4::xy(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
}

void Vector4::xz(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
}

void Vector4::xw(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
}

void Vector4::yx(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
}

void Vector4::yz(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
}

void Vector4::yw(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
}

void Vector4::zx(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
}

void Vector4::zy(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
}

void Vector4::zw(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
}

void Vector4::wx(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
}

void Vector4::wy(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
}

void Vector4::wz(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
}

void Vector4::xyz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4::xyw(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4::xzy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4::xzw(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4::xwy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4::xwz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4::yxz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4::yxw(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4::yzx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4::yzw(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4::ywx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4::ywz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4::zxy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4::zxw(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4::zyx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4::zyw(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4::zwx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4::zwy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4::wxy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4::wxz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4::wyx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4::wyz(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4::wzx(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4::wzy(Vector3 arg) {
    Unknown argStorage = arg._v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4::xyzw(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4::xywz(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4::xzyw(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4::xzwy(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4::xwyz(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4::xwzy(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4::yxzw(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4::yxwz(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4::yzxw(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4::yzwx(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4::ywxz(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4::ywzx(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4::zxyw(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4::zxwy(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4::zyxw(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4::zywx(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4::zwxy(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4::zwyx(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4::wxyz(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4::wxzy(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4::wyxz(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4::wyzx(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4::wzxy(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4::wzyx(Vector4 arg) {
    Unknown argStorage = arg._v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4::r(double arg) {
    return x = arg;
}

void Vector4::g(double arg) {
    return y = arg;
}

void Vector4::b(double arg) {
    return z = arg;
}

void Vector4::a(double arg) {
    return w = arg;
}

void Vector4::s(double arg) {
    return x = arg;
}

void Vector4::t(double arg) {
    return y = arg;
}

void Vector4::p(double arg) {
    return z = arg;
}

void Vector4::q(double arg) {
    return w = arg;
}

void Vector4::x(double arg) {
    return _v4storage[0] = arg;
}

void Vector4::y(double arg) {
    return _v4storage[1] = arg;
}

void Vector4::z(double arg) {
    return _v4storage[2] = arg;
}

void Vector4::w(double arg) {
    return _v4storage[3] = arg;
}

void Vector4::rg(Vector2 arg) {
    return xy = arg;
}

void Vector4::rb(Vector2 arg) {
    return xz = arg;
}

void Vector4::ra(Vector2 arg) {
    return xw = arg;
}

void Vector4::gr(Vector2 arg) {
    return yx = arg;
}

void Vector4::gb(Vector2 arg) {
    return yz = arg;
}

void Vector4::ga(Vector2 arg) {
    return yw = arg;
}

void Vector4::br(Vector2 arg) {
    return zx = arg;
}

void Vector4::bg(Vector2 arg) {
    return zy = arg;
}

void Vector4::ba(Vector2 arg) {
    return zw = arg;
}

void Vector4::ar(Vector2 arg) {
    return wx = arg;
}

void Vector4::ag(Vector2 arg) {
    return wy = arg;
}

void Vector4::ab(Vector2 arg) {
    return wz = arg;
}

void Vector4::rgb(Vector3 arg) {
    return xyz = arg;
}

void Vector4::rga(Vector3 arg) {
    return xyw = arg;
}

void Vector4::rbg(Vector3 arg) {
    return xzy = arg;
}

void Vector4::rba(Vector3 arg) {
    return xzw = arg;
}

void Vector4::rag(Vector3 arg) {
    return xwy = arg;
}

void Vector4::rab(Vector3 arg) {
    return xwz = arg;
}

void Vector4::grb(Vector3 arg) {
    return yxz = arg;
}

void Vector4::gra(Vector3 arg) {
    return yxw = arg;
}

void Vector4::gbr(Vector3 arg) {
    return yzx = arg;
}

void Vector4::gba(Vector3 arg) {
    return yzw = arg;
}

void Vector4::gar(Vector3 arg) {
    return ywx = arg;
}

void Vector4::gab(Vector3 arg) {
    return ywz = arg;
}

void Vector4::brg(Vector3 arg) {
    return zxy = arg;
}

void Vector4::bra(Vector3 arg) {
    return zxw = arg;
}

void Vector4::bgr(Vector3 arg) {
    return zyx = arg;
}

void Vector4::bga(Vector3 arg) {
    return zyw = arg;
}

void Vector4::bar(Vector3 arg) {
    return zwx = arg;
}

void Vector4::bag(Vector3 arg) {
    return zwy = arg;
}

void Vector4::arg(Vector3 arg) {
    return wxy = arg;
}

void Vector4::arb(Vector3 arg) {
    return wxz = arg;
}

void Vector4::agr(Vector3 arg) {
    return wyx = arg;
}

void Vector4::agb(Vector3 arg) {
    return wyz = arg;
}

void Vector4::abr(Vector3 arg) {
    return wzx = arg;
}

void Vector4::abg(Vector3 arg) {
    return wzy = arg;
}

void Vector4::rgba(Vector4 arg) {
    return xyzw = arg;
}

void Vector4::rgab(Vector4 arg) {
    return xywz = arg;
}

void Vector4::rbga(Vector4 arg) {
    return xzyw = arg;
}

void Vector4::rbag(Vector4 arg) {
    return xzwy = arg;
}

void Vector4::ragb(Vector4 arg) {
    return xwyz = arg;
}

void Vector4::rabg(Vector4 arg) {
    return xwzy = arg;
}

void Vector4::grba(Vector4 arg) {
    return yxzw = arg;
}

void Vector4::grab(Vector4 arg) {
    return yxwz = arg;
}

void Vector4::gbra(Vector4 arg) {
    return yzxw = arg;
}

void Vector4::gbar(Vector4 arg) {
    return yzwx = arg;
}

void Vector4::garb(Vector4 arg) {
    return ywxz = arg;
}

void Vector4::gabr(Vector4 arg) {
    return ywzx = arg;
}

void Vector4::brga(Vector4 arg) {
    return zxyw = arg;
}

void Vector4::brag(Vector4 arg) {
    return zxwy = arg;
}

void Vector4::bgra(Vector4 arg) {
    return zyxw = arg;
}

void Vector4::bgar(Vector4 arg) {
    return zywx = arg;
}

void Vector4::barg(Vector4 arg) {
    return zwxy = arg;
}

void Vector4::bagr(Vector4 arg) {
    return zwyx = arg;
}

void Vector4::argb(Vector4 arg) {
    return wxyz = arg;
}

void Vector4::arbg(Vector4 arg) {
    return wxzy = arg;
}

void Vector4::agrb(Vector4 arg) {
    return wyxz = arg;
}

void Vector4::agbr(Vector4 arg) {
    return wyzx = arg;
}

void Vector4::abrg(Vector4 arg) {
    return wzxy = arg;
}

void Vector4::abgr(Vector4 arg) {
    return wzyx = arg;
}

void Vector4::st(Vector2 arg) {
    return xy = arg;
}

void Vector4::sp(Vector2 arg) {
    return xz = arg;
}

void Vector4::sq(Vector2 arg) {
    return xw = arg;
}

void Vector4::ts(Vector2 arg) {
    return yx = arg;
}

void Vector4::tp(Vector2 arg) {
    return yz = arg;
}

void Vector4::tq(Vector2 arg) {
    return yw = arg;
}

void Vector4::ps(Vector2 arg) {
    return zx = arg;
}

void Vector4::pt(Vector2 arg) {
    return zy = arg;
}

void Vector4::pq(Vector2 arg) {
    return zw = arg;
}

void Vector4::qs(Vector2 arg) {
    return wx = arg;
}

void Vector4::qt(Vector2 arg) {
    return wy = arg;
}

void Vector4::qp(Vector2 arg) {
    return wz = arg;
}

void Vector4::stp(Vector3 arg) {
    return xyz = arg;
}

void Vector4::stq(Vector3 arg) {
    return xyw = arg;
}

void Vector4::spt(Vector3 arg) {
    return xzy = arg;
}

void Vector4::spq(Vector3 arg) {
    return xzw = arg;
}

void Vector4::sqt(Vector3 arg) {
    return xwy = arg;
}

void Vector4::sqp(Vector3 arg) {
    return xwz = arg;
}

void Vector4::tsp(Vector3 arg) {
    return yxz = arg;
}

void Vector4::tsq(Vector3 arg) {
    return yxw = arg;
}

void Vector4::tps(Vector3 arg) {
    return yzx = arg;
}

void Vector4::tpq(Vector3 arg) {
    return yzw = arg;
}

void Vector4::tqs(Vector3 arg) {
    return ywx = arg;
}

void Vector4::tqp(Vector3 arg) {
    return ywz = arg;
}

void Vector4::pst(Vector3 arg) {
    return zxy = arg;
}

void Vector4::psq(Vector3 arg) {
    return zxw = arg;
}

void Vector4::pts(Vector3 arg) {
    return zyx = arg;
}

void Vector4::ptq(Vector3 arg) {
    return zyw = arg;
}

void Vector4::pqs(Vector3 arg) {
    return zwx = arg;
}

void Vector4::pqt(Vector3 arg) {
    return zwy = arg;
}

void Vector4::qst(Vector3 arg) {
    return wxy = arg;
}

void Vector4::qsp(Vector3 arg) {
    return wxz = arg;
}

void Vector4::qts(Vector3 arg) {
    return wyx = arg;
}

void Vector4::qtp(Vector3 arg) {
    return wyz = arg;
}

void Vector4::qps(Vector3 arg) {
    return wzx = arg;
}

void Vector4::qpt(Vector3 arg) {
    return wzy = arg;
}

void Vector4::stpq(Vector4 arg) {
    return xyzw = arg;
}

void Vector4::stqp(Vector4 arg) {
    return xywz = arg;
}

void Vector4::sptq(Vector4 arg) {
    return xzyw = arg;
}

void Vector4::spqt(Vector4 arg) {
    return xzwy = arg;
}

void Vector4::sqtp(Vector4 arg) {
    return xwyz = arg;
}

void Vector4::sqpt(Vector4 arg) {
    return xwzy = arg;
}

void Vector4::tspq(Vector4 arg) {
    return yxzw = arg;
}

void Vector4::tsqp(Vector4 arg) {
    return yxwz = arg;
}

void Vector4::tpsq(Vector4 arg) {
    return yzxw = arg;
}

void Vector4::tpqs(Vector4 arg) {
    return yzwx = arg;
}

void Vector4::tqsp(Vector4 arg) {
    return ywxz = arg;
}

void Vector4::tqps(Vector4 arg) {
    return ywzx = arg;
}

void Vector4::pstq(Vector4 arg) {
    return zxyw = arg;
}

void Vector4::psqt(Vector4 arg) {
    return zxwy = arg;
}

void Vector4::ptsq(Vector4 arg) {
    return zyxw = arg;
}

void Vector4::ptqs(Vector4 arg) {
    return zywx = arg;
}

void Vector4::pqst(Vector4 arg) {
    return zwxy = arg;
}

void Vector4::pqts(Vector4 arg) {
    return zwyx = arg;
}

void Vector4::qstp(Vector4 arg) {
    return wxyz = arg;
}

void Vector4::qspt(Vector4 arg) {
    return wxzy = arg;
}

void Vector4::qtsp(Vector4 arg) {
    return wyxz = arg;
}

void Vector4::qtps(Vector4 arg) {
    return wyzx = arg;
}

void Vector4::qpst(Vector4 arg) {
    return wzxy = arg;
}

void Vector4::qpts(Vector4 arg) {
    return wzyx = arg;
}

Vector2 Vector4::xx() {
    return Vector2(_v4storage[0], _v4storage[0]);
}

Vector2 Vector4::xy() {
    return Vector2(_v4storage[0], _v4storage[1]);
}

Vector2 Vector4::xz() {
    return Vector2(_v4storage[0], _v4storage[2]);
}

Vector2 Vector4::xw() {
    return Vector2(_v4storage[0], _v4storage[3]);
}

Vector2 Vector4::yx() {
    return Vector2(_v4storage[1], _v4storage[0]);
}

Vector2 Vector4::yy() {
    return Vector2(_v4storage[1], _v4storage[1]);
}

Vector2 Vector4::yz() {
    return Vector2(_v4storage[1], _v4storage[2]);
}

Vector2 Vector4::yw() {
    return Vector2(_v4storage[1], _v4storage[3]);
}

Vector2 Vector4::zx() {
    return Vector2(_v4storage[2], _v4storage[0]);
}

Vector2 Vector4::zy() {
    return Vector2(_v4storage[2], _v4storage[1]);
}

Vector2 Vector4::zz() {
    return Vector2(_v4storage[2], _v4storage[2]);
}

Vector2 Vector4::zw() {
    return Vector2(_v4storage[2], _v4storage[3]);
}

Vector2 Vector4::wx() {
    return Vector2(_v4storage[3], _v4storage[0]);
}

Vector2 Vector4::wy() {
    return Vector2(_v4storage[3], _v4storage[1]);
}

Vector2 Vector4::wz() {
    return Vector2(_v4storage[3], _v4storage[2]);
}

Vector2 Vector4::ww() {
    return Vector2(_v4storage[3], _v4storage[3]);
}

Vector3 Vector4::xxx() {
    return Vector3(_v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4::xxy() {
    return Vector3(_v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4::xxz() {
    return Vector3(_v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4::xxw() {
    return Vector3(_v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4::xyx() {
    return Vector3(_v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4::xyy() {
    return Vector3(_v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4::xyz() {
    return Vector3(_v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4::xyw() {
    return Vector3(_v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4::xzx() {
    return Vector3(_v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4::xzy() {
    return Vector3(_v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4::xzz() {
    return Vector3(_v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4::xzw() {
    return Vector3(_v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4::xwx() {
    return Vector3(_v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4::xwy() {
    return Vector3(_v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4::xwz() {
    return Vector3(_v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4::xww() {
    return Vector3(_v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector3 Vector4::yxx() {
    return Vector3(_v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4::yxy() {
    return Vector3(_v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4::yxz() {
    return Vector3(_v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4::yxw() {
    return Vector3(_v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4::yyx() {
    return Vector3(_v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4::yyy() {
    return Vector3(_v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4::yyz() {
    return Vector3(_v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4::yyw() {
    return Vector3(_v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4::yzx() {
    return Vector3(_v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4::yzy() {
    return Vector3(_v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4::yzz() {
    return Vector3(_v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4::yzw() {
    return Vector3(_v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4::ywx() {
    return Vector3(_v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4::ywy() {
    return Vector3(_v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4::ywz() {
    return Vector3(_v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4::yww() {
    return Vector3(_v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector3 Vector4::zxx() {
    return Vector3(_v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4::zxy() {
    return Vector3(_v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4::zxz() {
    return Vector3(_v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4::zxw() {
    return Vector3(_v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4::zyx() {
    return Vector3(_v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4::zyy() {
    return Vector3(_v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4::zyz() {
    return Vector3(_v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4::zyw() {
    return Vector3(_v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4::zzx() {
    return Vector3(_v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4::zzy() {
    return Vector3(_v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4::zzz() {
    return Vector3(_v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4::zzw() {
    return Vector3(_v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4::zwx() {
    return Vector3(_v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4::zwy() {
    return Vector3(_v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4::zwz() {
    return Vector3(_v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4::zww() {
    return Vector3(_v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector3 Vector4::wxx() {
    return Vector3(_v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4::wxy() {
    return Vector3(_v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4::wxz() {
    return Vector3(_v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4::wxw() {
    return Vector3(_v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4::wyx() {
    return Vector3(_v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4::wyy() {
    return Vector3(_v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4::wyz() {
    return Vector3(_v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4::wyw() {
    return Vector3(_v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4::wzx() {
    return Vector3(_v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4::wzy() {
    return Vector3(_v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4::wzz() {
    return Vector3(_v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4::wzw() {
    return Vector3(_v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4::wwx() {
    return Vector3(_v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4::wwy() {
    return Vector3(_v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4::wwz() {
    return Vector3(_v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4::www() {
    return Vector3(_v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::xxxx() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::xxxy() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::xxxz() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::xxxw() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::xxyx() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::xxyy() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::xxyz() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::xxyw() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::xxzx() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::xxzy() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::xxzz() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::xxzw() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::xxwx() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::xxwy() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::xxwz() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::xxww() {
    return Vector4(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::xyxx() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::xyxy() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::xyxz() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::xyxw() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::xyyx() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::xyyy() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::xyyz() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::xyyw() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::xyzx() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::xyzy() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::xyzz() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::xyzw() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::xywx() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::xywy() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::xywz() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::xyww() {
    return Vector4(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::xzxx() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::xzxy() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::xzxz() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::xzxw() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::xzyx() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::xzyy() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::xzyz() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::xzyw() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::xzzx() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::xzzy() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::xzzz() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::xzzw() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::xzwx() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::xzwy() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::xzwz() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::xzww() {
    return Vector4(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::xwxx() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::xwxy() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::xwxz() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::xwxw() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::xwyx() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::xwyy() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::xwyz() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::xwyw() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::xwzx() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::xwzy() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::xwzz() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::xwzw() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::xwwx() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::xwwy() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::xwwz() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::xwww() {
    return Vector4(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::yxxx() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::yxxy() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::yxxz() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::yxxw() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::yxyx() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::yxyy() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::yxyz() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::yxyw() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::yxzx() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::yxzy() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::yxzz() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::yxzw() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::yxwx() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::yxwy() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::yxwz() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::yxww() {
    return Vector4(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::yyxx() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::yyxy() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::yyxz() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::yyxw() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::yyyx() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::yyyy() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::yyyz() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::yyyw() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::yyzx() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::yyzy() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::yyzz() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::yyzw() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::yywx() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::yywy() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::yywz() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::yyww() {
    return Vector4(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::yzxx() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::yzxy() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::yzxz() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::yzxw() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::yzyx() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::yzyy() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::yzyz() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::yzyw() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::yzzx() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::yzzy() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::yzzz() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::yzzw() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::yzwx() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::yzwy() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::yzwz() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::yzww() {
    return Vector4(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::ywxx() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::ywxy() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::ywxz() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::ywxw() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::ywyx() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::ywyy() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::ywyz() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::ywyw() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::ywzx() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::ywzy() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::ywzz() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::ywzw() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::ywwx() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::ywwy() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::ywwz() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::ywww() {
    return Vector4(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::zxxx() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::zxxy() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::zxxz() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::zxxw() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::zxyx() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::zxyy() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::zxyz() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::zxyw() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::zxzx() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::zxzy() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::zxzz() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::zxzw() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::zxwx() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::zxwy() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::zxwz() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::zxww() {
    return Vector4(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::zyxx() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::zyxy() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::zyxz() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::zyxw() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::zyyx() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::zyyy() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::zyyz() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::zyyw() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::zyzx() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::zyzy() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::zyzz() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::zyzw() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::zywx() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::zywy() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::zywz() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::zyww() {
    return Vector4(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::zzxx() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::zzxy() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::zzxz() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::zzxw() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::zzyx() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::zzyy() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::zzyz() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::zzyw() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::zzzx() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::zzzy() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::zzzz() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::zzzw() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::zzwx() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::zzwy() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::zzwz() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::zzww() {
    return Vector4(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::zwxx() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::zwxy() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::zwxz() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::zwxw() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::zwyx() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::zwyy() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::zwyz() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::zwyw() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::zwzx() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::zwzy() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::zwzz() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::zwzw() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::zwwx() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::zwwy() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::zwwz() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::zwww() {
    return Vector4(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::wxxx() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::wxxy() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::wxxz() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::wxxw() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::wxyx() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::wxyy() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::wxyz() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::wxyw() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::wxzx() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::wxzy() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::wxzz() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::wxzw() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::wxwx() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::wxwy() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::wxwz() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::wxww() {
    return Vector4(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::wyxx() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::wyxy() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::wyxz() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::wyxw() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::wyyx() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::wyyy() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::wyyz() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::wyyw() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::wyzx() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::wyzy() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::wyzz() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::wyzw() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::wywx() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::wywy() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::wywz() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::wyww() {
    return Vector4(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::wzxx() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::wzxy() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::wzxz() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::wzxw() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::wzyx() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::wzyy() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::wzyz() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::wzyw() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::wzzx() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::wzzy() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::wzzz() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::wzzw() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::wzwx() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::wzwy() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::wzwz() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::wzww() {
    return Vector4(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4::wwxx() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4::wwxy() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4::wwxz() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4::wwxw() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4::wwyx() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4::wwyy() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4::wwyz() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4::wwyw() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4::wwzx() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4::wwzy() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4::wwzz() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4::wwzw() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4::wwwx() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4::wwwy() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4::wwwz() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4::wwww() {
    return Vector4(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[3]);
}

double Vector4::r() {
    return x;
}

double Vector4::g() {
    return y;
}

double Vector4::b() {
    return z;
}

double Vector4::a() {
    return w;
}

double Vector4::s() {
    return x;
}

double Vector4::t() {
    return y;
}

double Vector4::p() {
    return z;
}

double Vector4::q() {
    return w;
}

double Vector4::x() {
    return _v4storage[0];
}

double Vector4::y() {
    return _v4storage[1];
}

double Vector4::z() {
    return _v4storage[2];
}

double Vector4::w() {
    return _v4storage[3];
}

Vector2 Vector4::rr() {
    return xx;
}

Vector2 Vector4::rg() {
    return xy;
}

Vector2 Vector4::rb() {
    return xz;
}

Vector2 Vector4::ra() {
    return xw;
}

Vector2 Vector4::gr() {
    return yx;
}

Vector2 Vector4::gg() {
    return yy;
}

Vector2 Vector4::gb() {
    return yz;
}

Vector2 Vector4::ga() {
    return yw;
}

Vector2 Vector4::br() {
    return zx;
}

Vector2 Vector4::bg() {
    return zy;
}

Vector2 Vector4::bb() {
    return zz;
}

Vector2 Vector4::ba() {
    return zw;
}

Vector2 Vector4::ar() {
    return wx;
}

Vector2 Vector4::ag() {
    return wy;
}

Vector2 Vector4::ab() {
    return wz;
}

Vector2 Vector4::aa() {
    return ww;
}

Vector3 Vector4::rrr() {
    return xxx;
}

Vector3 Vector4::rrg() {
    return xxy;
}

Vector3 Vector4::rrb() {
    return xxz;
}

Vector3 Vector4::rra() {
    return xxw;
}

Vector3 Vector4::rgr() {
    return xyx;
}

Vector3 Vector4::rgg() {
    return xyy;
}

Vector3 Vector4::rgb() {
    return xyz;
}

Vector3 Vector4::rga() {
    return xyw;
}

Vector3 Vector4::rbr() {
    return xzx;
}

Vector3 Vector4::rbg() {
    return xzy;
}

Vector3 Vector4::rbb() {
    return xzz;
}

Vector3 Vector4::rba() {
    return xzw;
}

Vector3 Vector4::rar() {
    return xwx;
}

Vector3 Vector4::rag() {
    return xwy;
}

Vector3 Vector4::rab() {
    return xwz;
}

Vector3 Vector4::raa() {
    return xww;
}

Vector3 Vector4::grr() {
    return yxx;
}

Vector3 Vector4::grg() {
    return yxy;
}

Vector3 Vector4::grb() {
    return yxz;
}

Vector3 Vector4::gra() {
    return yxw;
}

Vector3 Vector4::ggr() {
    return yyx;
}

Vector3 Vector4::ggg() {
    return yyy;
}

Vector3 Vector4::ggb() {
    return yyz;
}

Vector3 Vector4::gga() {
    return yyw;
}

Vector3 Vector4::gbr() {
    return yzx;
}

Vector3 Vector4::gbg() {
    return yzy;
}

Vector3 Vector4::gbb() {
    return yzz;
}

Vector3 Vector4::gba() {
    return yzw;
}

Vector3 Vector4::gar() {
    return ywx;
}

Vector3 Vector4::gag() {
    return ywy;
}

Vector3 Vector4::gab() {
    return ywz;
}

Vector3 Vector4::gaa() {
    return yww;
}

Vector3 Vector4::brr() {
    return zxx;
}

Vector3 Vector4::brg() {
    return zxy;
}

Vector3 Vector4::brb() {
    return zxz;
}

Vector3 Vector4::bra() {
    return zxw;
}

Vector3 Vector4::bgr() {
    return zyx;
}

Vector3 Vector4::bgg() {
    return zyy;
}

Vector3 Vector4::bgb() {
    return zyz;
}

Vector3 Vector4::bga() {
    return zyw;
}

Vector3 Vector4::bbr() {
    return zzx;
}

Vector3 Vector4::bbg() {
    return zzy;
}

Vector3 Vector4::bbb() {
    return zzz;
}

Vector3 Vector4::bba() {
    return zzw;
}

Vector3 Vector4::bar() {
    return zwx;
}

Vector3 Vector4::bag() {
    return zwy;
}

Vector3 Vector4::bab() {
    return zwz;
}

Vector3 Vector4::baa() {
    return zww;
}

Vector3 Vector4::arr() {
    return wxx;
}

Vector3 Vector4::arg() {
    return wxy;
}

Vector3 Vector4::arb() {
    return wxz;
}

Vector3 Vector4::ara() {
    return wxw;
}

Vector3 Vector4::agr() {
    return wyx;
}

Vector3 Vector4::agg() {
    return wyy;
}

Vector3 Vector4::agb() {
    return wyz;
}

Vector3 Vector4::aga() {
    return wyw;
}

Vector3 Vector4::abr() {
    return wzx;
}

Vector3 Vector4::abg() {
    return wzy;
}

Vector3 Vector4::abb() {
    return wzz;
}

Vector3 Vector4::aba() {
    return wzw;
}

Vector3 Vector4::aar() {
    return wwx;
}

Vector3 Vector4::aag() {
    return wwy;
}

Vector3 Vector4::aab() {
    return wwz;
}

Vector3 Vector4::aaa() {
    return www;
}

Vector4 Vector4::rrrr() {
    return xxxx;
}

Vector4 Vector4::rrrg() {
    return xxxy;
}

Vector4 Vector4::rrrb() {
    return xxxz;
}

Vector4 Vector4::rrra() {
    return xxxw;
}

Vector4 Vector4::rrgr() {
    return xxyx;
}

Vector4 Vector4::rrgg() {
    return xxyy;
}

Vector4 Vector4::rrgb() {
    return xxyz;
}

Vector4 Vector4::rrga() {
    return xxyw;
}

Vector4 Vector4::rrbr() {
    return xxzx;
}

Vector4 Vector4::rrbg() {
    return xxzy;
}

Vector4 Vector4::rrbb() {
    return xxzz;
}

Vector4 Vector4::rrba() {
    return xxzw;
}

Vector4 Vector4::rrar() {
    return xxwx;
}

Vector4 Vector4::rrag() {
    return xxwy;
}

Vector4 Vector4::rrab() {
    return xxwz;
}

Vector4 Vector4::rraa() {
    return xxww;
}

Vector4 Vector4::rgrr() {
    return xyxx;
}

Vector4 Vector4::rgrg() {
    return xyxy;
}

Vector4 Vector4::rgrb() {
    return xyxz;
}

Vector4 Vector4::rgra() {
    return xyxw;
}

Vector4 Vector4::rggr() {
    return xyyx;
}

Vector4 Vector4::rggg() {
    return xyyy;
}

Vector4 Vector4::rggb() {
    return xyyz;
}

Vector4 Vector4::rgga() {
    return xyyw;
}

Vector4 Vector4::rgbr() {
    return xyzx;
}

Vector4 Vector4::rgbg() {
    return xyzy;
}

Vector4 Vector4::rgbb() {
    return xyzz;
}

Vector4 Vector4::rgba() {
    return xyzw;
}

Vector4 Vector4::rgar() {
    return xywx;
}

Vector4 Vector4::rgag() {
    return xywy;
}

Vector4 Vector4::rgab() {
    return xywz;
}

Vector4 Vector4::rgaa() {
    return xyww;
}

Vector4 Vector4::rbrr() {
    return xzxx;
}

Vector4 Vector4::rbrg() {
    return xzxy;
}

Vector4 Vector4::rbrb() {
    return xzxz;
}

Vector4 Vector4::rbra() {
    return xzxw;
}

Vector4 Vector4::rbgr() {
    return xzyx;
}

Vector4 Vector4::rbgg() {
    return xzyy;
}

Vector4 Vector4::rbgb() {
    return xzyz;
}

Vector4 Vector4::rbga() {
    return xzyw;
}

Vector4 Vector4::rbbr() {
    return xzzx;
}

Vector4 Vector4::rbbg() {
    return xzzy;
}

Vector4 Vector4::rbbb() {
    return xzzz;
}

Vector4 Vector4::rbba() {
    return xzzw;
}

Vector4 Vector4::rbar() {
    return xzwx;
}

Vector4 Vector4::rbag() {
    return xzwy;
}

Vector4 Vector4::rbab() {
    return xzwz;
}

Vector4 Vector4::rbaa() {
    return xzww;
}

Vector4 Vector4::rarr() {
    return xwxx;
}

Vector4 Vector4::rarg() {
    return xwxy;
}

Vector4 Vector4::rarb() {
    return xwxz;
}

Vector4 Vector4::rara() {
    return xwxw;
}

Vector4 Vector4::ragr() {
    return xwyx;
}

Vector4 Vector4::ragg() {
    return xwyy;
}

Vector4 Vector4::ragb() {
    return xwyz;
}

Vector4 Vector4::raga() {
    return xwyw;
}

Vector4 Vector4::rabr() {
    return xwzx;
}

Vector4 Vector4::rabg() {
    return xwzy;
}

Vector4 Vector4::rabb() {
    return xwzz;
}

Vector4 Vector4::raba() {
    return xwzw;
}

Vector4 Vector4::raar() {
    return xwwx;
}

Vector4 Vector4::raag() {
    return xwwy;
}

Vector4 Vector4::raab() {
    return xwwz;
}

Vector4 Vector4::raaa() {
    return xwww;
}

Vector4 Vector4::grrr() {
    return yxxx;
}

Vector4 Vector4::grrg() {
    return yxxy;
}

Vector4 Vector4::grrb() {
    return yxxz;
}

Vector4 Vector4::grra() {
    return yxxw;
}

Vector4 Vector4::grgr() {
    return yxyx;
}

Vector4 Vector4::grgg() {
    return yxyy;
}

Vector4 Vector4::grgb() {
    return yxyz;
}

Vector4 Vector4::grga() {
    return yxyw;
}

Vector4 Vector4::grbr() {
    return yxzx;
}

Vector4 Vector4::grbg() {
    return yxzy;
}

Vector4 Vector4::grbb() {
    return yxzz;
}

Vector4 Vector4::grba() {
    return yxzw;
}

Vector4 Vector4::grar() {
    return yxwx;
}

Vector4 Vector4::grag() {
    return yxwy;
}

Vector4 Vector4::grab() {
    return yxwz;
}

Vector4 Vector4::graa() {
    return yxww;
}

Vector4 Vector4::ggrr() {
    return yyxx;
}

Vector4 Vector4::ggrg() {
    return yyxy;
}

Vector4 Vector4::ggrb() {
    return yyxz;
}

Vector4 Vector4::ggra() {
    return yyxw;
}

Vector4 Vector4::gggr() {
    return yyyx;
}

Vector4 Vector4::gggg() {
    return yyyy;
}

Vector4 Vector4::gggb() {
    return yyyz;
}

Vector4 Vector4::ggga() {
    return yyyw;
}

Vector4 Vector4::ggbr() {
    return yyzx;
}

Vector4 Vector4::ggbg() {
    return yyzy;
}

Vector4 Vector4::ggbb() {
    return yyzz;
}

Vector4 Vector4::ggba() {
    return yyzw;
}

Vector4 Vector4::ggar() {
    return yywx;
}

Vector4 Vector4::ggag() {
    return yywy;
}

Vector4 Vector4::ggab() {
    return yywz;
}

Vector4 Vector4::ggaa() {
    return yyww;
}

Vector4 Vector4::gbrr() {
    return yzxx;
}

Vector4 Vector4::gbrg() {
    return yzxy;
}

Vector4 Vector4::gbrb() {
    return yzxz;
}

Vector4 Vector4::gbra() {
    return yzxw;
}

Vector4 Vector4::gbgr() {
    return yzyx;
}

Vector4 Vector4::gbgg() {
    return yzyy;
}

Vector4 Vector4::gbgb() {
    return yzyz;
}

Vector4 Vector4::gbga() {
    return yzyw;
}

Vector4 Vector4::gbbr() {
    return yzzx;
}

Vector4 Vector4::gbbg() {
    return yzzy;
}

Vector4 Vector4::gbbb() {
    return yzzz;
}

Vector4 Vector4::gbba() {
    return yzzw;
}

Vector4 Vector4::gbar() {
    return yzwx;
}

Vector4 Vector4::gbag() {
    return yzwy;
}

Vector4 Vector4::gbab() {
    return yzwz;
}

Vector4 Vector4::gbaa() {
    return yzww;
}

Vector4 Vector4::garr() {
    return ywxx;
}

Vector4 Vector4::garg() {
    return ywxy;
}

Vector4 Vector4::garb() {
    return ywxz;
}

Vector4 Vector4::gara() {
    return ywxw;
}

Vector4 Vector4::gagr() {
    return ywyx;
}

Vector4 Vector4::gagg() {
    return ywyy;
}

Vector4 Vector4::gagb() {
    return ywyz;
}

Vector4 Vector4::gaga() {
    return ywyw;
}

Vector4 Vector4::gabr() {
    return ywzx;
}

Vector4 Vector4::gabg() {
    return ywzy;
}

Vector4 Vector4::gabb() {
    return ywzz;
}

Vector4 Vector4::gaba() {
    return ywzw;
}

Vector4 Vector4::gaar() {
    return ywwx;
}

Vector4 Vector4::gaag() {
    return ywwy;
}

Vector4 Vector4::gaab() {
    return ywwz;
}

Vector4 Vector4::gaaa() {
    return ywww;
}

Vector4 Vector4::brrr() {
    return zxxx;
}

Vector4 Vector4::brrg() {
    return zxxy;
}

Vector4 Vector4::brrb() {
    return zxxz;
}

Vector4 Vector4::brra() {
    return zxxw;
}

Vector4 Vector4::brgr() {
    return zxyx;
}

Vector4 Vector4::brgg() {
    return zxyy;
}

Vector4 Vector4::brgb() {
    return zxyz;
}

Vector4 Vector4::brga() {
    return zxyw;
}

Vector4 Vector4::brbr() {
    return zxzx;
}

Vector4 Vector4::brbg() {
    return zxzy;
}

Vector4 Vector4::brbb() {
    return zxzz;
}

Vector4 Vector4::brba() {
    return zxzw;
}

Vector4 Vector4::brar() {
    return zxwx;
}

Vector4 Vector4::brag() {
    return zxwy;
}

Vector4 Vector4::brab() {
    return zxwz;
}

Vector4 Vector4::braa() {
    return zxww;
}

Vector4 Vector4::bgrr() {
    return zyxx;
}

Vector4 Vector4::bgrg() {
    return zyxy;
}

Vector4 Vector4::bgrb() {
    return zyxz;
}

Vector4 Vector4::bgra() {
    return zyxw;
}

Vector4 Vector4::bggr() {
    return zyyx;
}

Vector4 Vector4::bggg() {
    return zyyy;
}

Vector4 Vector4::bggb() {
    return zyyz;
}

Vector4 Vector4::bgga() {
    return zyyw;
}

Vector4 Vector4::bgbr() {
    return zyzx;
}

Vector4 Vector4::bgbg() {
    return zyzy;
}

Vector4 Vector4::bgbb() {
    return zyzz;
}

Vector4 Vector4::bgba() {
    return zyzw;
}

Vector4 Vector4::bgar() {
    return zywx;
}

Vector4 Vector4::bgag() {
    return zywy;
}

Vector4 Vector4::bgab() {
    return zywz;
}

Vector4 Vector4::bgaa() {
    return zyww;
}

Vector4 Vector4::bbrr() {
    return zzxx;
}

Vector4 Vector4::bbrg() {
    return zzxy;
}

Vector4 Vector4::bbrb() {
    return zzxz;
}

Vector4 Vector4::bbra() {
    return zzxw;
}

Vector4 Vector4::bbgr() {
    return zzyx;
}

Vector4 Vector4::bbgg() {
    return zzyy;
}

Vector4 Vector4::bbgb() {
    return zzyz;
}

Vector4 Vector4::bbga() {
    return zzyw;
}

Vector4 Vector4::bbbr() {
    return zzzx;
}

Vector4 Vector4::bbbg() {
    return zzzy;
}

Vector4 Vector4::bbbb() {
    return zzzz;
}

Vector4 Vector4::bbba() {
    return zzzw;
}

Vector4 Vector4::bbar() {
    return zzwx;
}

Vector4 Vector4::bbag() {
    return zzwy;
}

Vector4 Vector4::bbab() {
    return zzwz;
}

Vector4 Vector4::bbaa() {
    return zzww;
}

Vector4 Vector4::barr() {
    return zwxx;
}

Vector4 Vector4::barg() {
    return zwxy;
}

Vector4 Vector4::barb() {
    return zwxz;
}

Vector4 Vector4::bara() {
    return zwxw;
}

Vector4 Vector4::bagr() {
    return zwyx;
}

Vector4 Vector4::bagg() {
    return zwyy;
}

Vector4 Vector4::bagb() {
    return zwyz;
}

Vector4 Vector4::baga() {
    return zwyw;
}

Vector4 Vector4::babr() {
    return zwzx;
}

Vector4 Vector4::babg() {
    return zwzy;
}

Vector4 Vector4::babb() {
    return zwzz;
}

Vector4 Vector4::baba() {
    return zwzw;
}

Vector4 Vector4::baar() {
    return zwwx;
}

Vector4 Vector4::baag() {
    return zwwy;
}

Vector4 Vector4::baab() {
    return zwwz;
}

Vector4 Vector4::baaa() {
    return zwww;
}

Vector4 Vector4::arrr() {
    return wxxx;
}

Vector4 Vector4::arrg() {
    return wxxy;
}

Vector4 Vector4::arrb() {
    return wxxz;
}

Vector4 Vector4::arra() {
    return wxxw;
}

Vector4 Vector4::argr() {
    return wxyx;
}

Vector4 Vector4::argg() {
    return wxyy;
}

Vector4 Vector4::argb() {
    return wxyz;
}

Vector4 Vector4::arga() {
    return wxyw;
}

Vector4 Vector4::arbr() {
    return wxzx;
}

Vector4 Vector4::arbg() {
    return wxzy;
}

Vector4 Vector4::arbb() {
    return wxzz;
}

Vector4 Vector4::arba() {
    return wxzw;
}

Vector4 Vector4::arar() {
    return wxwx;
}

Vector4 Vector4::arag() {
    return wxwy;
}

Vector4 Vector4::arab() {
    return wxwz;
}

Vector4 Vector4::araa() {
    return wxww;
}

Vector4 Vector4::agrr() {
    return wyxx;
}

Vector4 Vector4::agrg() {
    return wyxy;
}

Vector4 Vector4::agrb() {
    return wyxz;
}

Vector4 Vector4::agra() {
    return wyxw;
}

Vector4 Vector4::aggr() {
    return wyyx;
}

Vector4 Vector4::aggg() {
    return wyyy;
}

Vector4 Vector4::aggb() {
    return wyyz;
}

Vector4 Vector4::agga() {
    return wyyw;
}

Vector4 Vector4::agbr() {
    return wyzx;
}

Vector4 Vector4::agbg() {
    return wyzy;
}

Vector4 Vector4::agbb() {
    return wyzz;
}

Vector4 Vector4::agba() {
    return wyzw;
}

Vector4 Vector4::agar() {
    return wywx;
}

Vector4 Vector4::agag() {
    return wywy;
}

Vector4 Vector4::agab() {
    return wywz;
}

Vector4 Vector4::agaa() {
    return wyww;
}

Vector4 Vector4::abrr() {
    return wzxx;
}

Vector4 Vector4::abrg() {
    return wzxy;
}

Vector4 Vector4::abrb() {
    return wzxz;
}

Vector4 Vector4::abra() {
    return wzxw;
}

Vector4 Vector4::abgr() {
    return wzyx;
}

Vector4 Vector4::abgg() {
    return wzyy;
}

Vector4 Vector4::abgb() {
    return wzyz;
}

Vector4 Vector4::abga() {
    return wzyw;
}

Vector4 Vector4::abbr() {
    return wzzx;
}

Vector4 Vector4::abbg() {
    return wzzy;
}

Vector4 Vector4::abbb() {
    return wzzz;
}

Vector4 Vector4::abba() {
    return wzzw;
}

Vector4 Vector4::abar() {
    return wzwx;
}

Vector4 Vector4::abag() {
    return wzwy;
}

Vector4 Vector4::abab() {
    return wzwz;
}

Vector4 Vector4::abaa() {
    return wzww;
}

Vector4 Vector4::aarr() {
    return wwxx;
}

Vector4 Vector4::aarg() {
    return wwxy;
}

Vector4 Vector4::aarb() {
    return wwxz;
}

Vector4 Vector4::aara() {
    return wwxw;
}

Vector4 Vector4::aagr() {
    return wwyx;
}

Vector4 Vector4::aagg() {
    return wwyy;
}

Vector4 Vector4::aagb() {
    return wwyz;
}

Vector4 Vector4::aaga() {
    return wwyw;
}

Vector4 Vector4::aabr() {
    return wwzx;
}

Vector4 Vector4::aabg() {
    return wwzy;
}

Vector4 Vector4::aabb() {
    return wwzz;
}

Vector4 Vector4::aaba() {
    return wwzw;
}

Vector4 Vector4::aaar() {
    return wwwx;
}

Vector4 Vector4::aaag() {
    return wwwy;
}

Vector4 Vector4::aaab() {
    return wwwz;
}

Vector4 Vector4::aaaa() {
    return wwww;
}

Vector2 Vector4::ss() {
    return xx;
}

Vector2 Vector4::st() {
    return xy;
}

Vector2 Vector4::sp() {
    return xz;
}

Vector2 Vector4::sq() {
    return xw;
}

Vector2 Vector4::ts() {
    return yx;
}

Vector2 Vector4::tt() {
    return yy;
}

Vector2 Vector4::tp() {
    return yz;
}

Vector2 Vector4::tq() {
    return yw;
}

Vector2 Vector4::ps() {
    return zx;
}

Vector2 Vector4::pt() {
    return zy;
}

Vector2 Vector4::pp() {
    return zz;
}

Vector2 Vector4::pq() {
    return zw;
}

Vector2 Vector4::qs() {
    return wx;
}

Vector2 Vector4::qt() {
    return wy;
}

Vector2 Vector4::qp() {
    return wz;
}

Vector2 Vector4::qq() {
    return ww;
}

Vector3 Vector4::sss() {
    return xxx;
}

Vector3 Vector4::sst() {
    return xxy;
}

Vector3 Vector4::ssp() {
    return xxz;
}

Vector3 Vector4::ssq() {
    return xxw;
}

Vector3 Vector4::sts() {
    return xyx;
}

Vector3 Vector4::stt() {
    return xyy;
}

Vector3 Vector4::stp() {
    return xyz;
}

Vector3 Vector4::stq() {
    return xyw;
}

Vector3 Vector4::sps() {
    return xzx;
}

Vector3 Vector4::spt() {
    return xzy;
}

Vector3 Vector4::spp() {
    return xzz;
}

Vector3 Vector4::spq() {
    return xzw;
}

Vector3 Vector4::sqs() {
    return xwx;
}

Vector3 Vector4::sqt() {
    return xwy;
}

Vector3 Vector4::sqp() {
    return xwz;
}

Vector3 Vector4::sqq() {
    return xww;
}

Vector3 Vector4::tss() {
    return yxx;
}

Vector3 Vector4::tst() {
    return yxy;
}

Vector3 Vector4::tsp() {
    return yxz;
}

Vector3 Vector4::tsq() {
    return yxw;
}

Vector3 Vector4::tts() {
    return yyx;
}

Vector3 Vector4::ttt() {
    return yyy;
}

Vector3 Vector4::ttp() {
    return yyz;
}

Vector3 Vector4::ttq() {
    return yyw;
}

Vector3 Vector4::tps() {
    return yzx;
}

Vector3 Vector4::tpt() {
    return yzy;
}

Vector3 Vector4::tpp() {
    return yzz;
}

Vector3 Vector4::tpq() {
    return yzw;
}

Vector3 Vector4::tqs() {
    return ywx;
}

Vector3 Vector4::tqt() {
    return ywy;
}

Vector3 Vector4::tqp() {
    return ywz;
}

Vector3 Vector4::tqq() {
    return yww;
}

Vector3 Vector4::pss() {
    return zxx;
}

Vector3 Vector4::pst() {
    return zxy;
}

Vector3 Vector4::psp() {
    return zxz;
}

Vector3 Vector4::psq() {
    return zxw;
}

Vector3 Vector4::pts() {
    return zyx;
}

Vector3 Vector4::ptt() {
    return zyy;
}

Vector3 Vector4::ptp() {
    return zyz;
}

Vector3 Vector4::ptq() {
    return zyw;
}

Vector3 Vector4::pps() {
    return zzx;
}

Vector3 Vector4::ppt() {
    return zzy;
}

Vector3 Vector4::ppp() {
    return zzz;
}

Vector3 Vector4::ppq() {
    return zzw;
}

Vector3 Vector4::pqs() {
    return zwx;
}

Vector3 Vector4::pqt() {
    return zwy;
}

Vector3 Vector4::pqp() {
    return zwz;
}

Vector3 Vector4::pqq() {
    return zww;
}

Vector3 Vector4::qss() {
    return wxx;
}

Vector3 Vector4::qst() {
    return wxy;
}

Vector3 Vector4::qsp() {
    return wxz;
}

Vector3 Vector4::qsq() {
    return wxw;
}

Vector3 Vector4::qts() {
    return wyx;
}

Vector3 Vector4::qtt() {
    return wyy;
}

Vector3 Vector4::qtp() {
    return wyz;
}

Vector3 Vector4::qtq() {
    return wyw;
}

Vector3 Vector4::qps() {
    return wzx;
}

Vector3 Vector4::qpt() {
    return wzy;
}

Vector3 Vector4::qpp() {
    return wzz;
}

Vector3 Vector4::qpq() {
    return wzw;
}

Vector3 Vector4::qqs() {
    return wwx;
}

Vector3 Vector4::qqt() {
    return wwy;
}

Vector3 Vector4::qqp() {
    return wwz;
}

Vector3 Vector4::qqq() {
    return www;
}

Vector4 Vector4::ssss() {
    return xxxx;
}

Vector4 Vector4::ssst() {
    return xxxy;
}

Vector4 Vector4::sssp() {
    return xxxz;
}

Vector4 Vector4::sssq() {
    return xxxw;
}

Vector4 Vector4::ssts() {
    return xxyx;
}

Vector4 Vector4::sstt() {
    return xxyy;
}

Vector4 Vector4::sstp() {
    return xxyz;
}

Vector4 Vector4::sstq() {
    return xxyw;
}

Vector4 Vector4::ssps() {
    return xxzx;
}

Vector4 Vector4::sspt() {
    return xxzy;
}

Vector4 Vector4::sspp() {
    return xxzz;
}

Vector4 Vector4::sspq() {
    return xxzw;
}

Vector4 Vector4::ssqs() {
    return xxwx;
}

Vector4 Vector4::ssqt() {
    return xxwy;
}

Vector4 Vector4::ssqp() {
    return xxwz;
}

Vector4 Vector4::ssqq() {
    return xxww;
}

Vector4 Vector4::stss() {
    return xyxx;
}

Vector4 Vector4::stst() {
    return xyxy;
}

Vector4 Vector4::stsp() {
    return xyxz;
}

Vector4 Vector4::stsq() {
    return xyxw;
}

Vector4 Vector4::stts() {
    return xyyx;
}

Vector4 Vector4::sttt() {
    return xyyy;
}

Vector4 Vector4::sttp() {
    return xyyz;
}

Vector4 Vector4::sttq() {
    return xyyw;
}

Vector4 Vector4::stps() {
    return xyzx;
}

Vector4 Vector4::stpt() {
    return xyzy;
}

Vector4 Vector4::stpp() {
    return xyzz;
}

Vector4 Vector4::stpq() {
    return xyzw;
}

Vector4 Vector4::stqs() {
    return xywx;
}

Vector4 Vector4::stqt() {
    return xywy;
}

Vector4 Vector4::stqp() {
    return xywz;
}

Vector4 Vector4::stqq() {
    return xyww;
}

Vector4 Vector4::spss() {
    return xzxx;
}

Vector4 Vector4::spst() {
    return xzxy;
}

Vector4 Vector4::spsp() {
    return xzxz;
}

Vector4 Vector4::spsq() {
    return xzxw;
}

Vector4 Vector4::spts() {
    return xzyx;
}

Vector4 Vector4::sptt() {
    return xzyy;
}

Vector4 Vector4::sptp() {
    return xzyz;
}

Vector4 Vector4::sptq() {
    return xzyw;
}

Vector4 Vector4::spps() {
    return xzzx;
}

Vector4 Vector4::sppt() {
    return xzzy;
}

Vector4 Vector4::sppp() {
    return xzzz;
}

Vector4 Vector4::sppq() {
    return xzzw;
}

Vector4 Vector4::spqs() {
    return xzwx;
}

Vector4 Vector4::spqt() {
    return xzwy;
}

Vector4 Vector4::spqp() {
    return xzwz;
}

Vector4 Vector4::spqq() {
    return xzww;
}

Vector4 Vector4::sqss() {
    return xwxx;
}

Vector4 Vector4::sqst() {
    return xwxy;
}

Vector4 Vector4::sqsp() {
    return xwxz;
}

Vector4 Vector4::sqsq() {
    return xwxw;
}

Vector4 Vector4::sqts() {
    return xwyx;
}

Vector4 Vector4::sqtt() {
    return xwyy;
}

Vector4 Vector4::sqtp() {
    return xwyz;
}

Vector4 Vector4::sqtq() {
    return xwyw;
}

Vector4 Vector4::sqps() {
    return xwzx;
}

Vector4 Vector4::sqpt() {
    return xwzy;
}

Vector4 Vector4::sqpp() {
    return xwzz;
}

Vector4 Vector4::sqpq() {
    return xwzw;
}

Vector4 Vector4::sqqs() {
    return xwwx;
}

Vector4 Vector4::sqqt() {
    return xwwy;
}

Vector4 Vector4::sqqp() {
    return xwwz;
}

Vector4 Vector4::sqqq() {
    return xwww;
}

Vector4 Vector4::tsss() {
    return yxxx;
}

Vector4 Vector4::tsst() {
    return yxxy;
}

Vector4 Vector4::tssp() {
    return yxxz;
}

Vector4 Vector4::tssq() {
    return yxxw;
}

Vector4 Vector4::tsts() {
    return yxyx;
}

Vector4 Vector4::tstt() {
    return yxyy;
}

Vector4 Vector4::tstp() {
    return yxyz;
}

Vector4 Vector4::tstq() {
    return yxyw;
}

Vector4 Vector4::tsps() {
    return yxzx;
}

Vector4 Vector4::tspt() {
    return yxzy;
}

Vector4 Vector4::tspp() {
    return yxzz;
}

Vector4 Vector4::tspq() {
    return yxzw;
}

Vector4 Vector4::tsqs() {
    return yxwx;
}

Vector4 Vector4::tsqt() {
    return yxwy;
}

Vector4 Vector4::tsqp() {
    return yxwz;
}

Vector4 Vector4::tsqq() {
    return yxww;
}

Vector4 Vector4::ttss() {
    return yyxx;
}

Vector4 Vector4::ttst() {
    return yyxy;
}

Vector4 Vector4::ttsp() {
    return yyxz;
}

Vector4 Vector4::ttsq() {
    return yyxw;
}

Vector4 Vector4::ttts() {
    return yyyx;
}

Vector4 Vector4::tttt() {
    return yyyy;
}

Vector4 Vector4::tttp() {
    return yyyz;
}

Vector4 Vector4::tttq() {
    return yyyw;
}

Vector4 Vector4::ttps() {
    return yyzx;
}

Vector4 Vector4::ttpt() {
    return yyzy;
}

Vector4 Vector4::ttpp() {
    return yyzz;
}

Vector4 Vector4::ttpq() {
    return yyzw;
}

Vector4 Vector4::ttqs() {
    return yywx;
}

Vector4 Vector4::ttqt() {
    return yywy;
}

Vector4 Vector4::ttqp() {
    return yywz;
}

Vector4 Vector4::ttqq() {
    return yyww;
}

Vector4 Vector4::tpss() {
    return yzxx;
}

Vector4 Vector4::tpst() {
    return yzxy;
}

Vector4 Vector4::tpsp() {
    return yzxz;
}

Vector4 Vector4::tpsq() {
    return yzxw;
}

Vector4 Vector4::tpts() {
    return yzyx;
}

Vector4 Vector4::tptt() {
    return yzyy;
}

Vector4 Vector4::tptp() {
    return yzyz;
}

Vector4 Vector4::tptq() {
    return yzyw;
}

Vector4 Vector4::tpps() {
    return yzzx;
}

Vector4 Vector4::tppt() {
    return yzzy;
}

Vector4 Vector4::tppp() {
    return yzzz;
}

Vector4 Vector4::tppq() {
    return yzzw;
}

Vector4 Vector4::tpqs() {
    return yzwx;
}

Vector4 Vector4::tpqt() {
    return yzwy;
}

Vector4 Vector4::tpqp() {
    return yzwz;
}

Vector4 Vector4::tpqq() {
    return yzww;
}

Vector4 Vector4::tqss() {
    return ywxx;
}

Vector4 Vector4::tqst() {
    return ywxy;
}

Vector4 Vector4::tqsp() {
    return ywxz;
}

Vector4 Vector4::tqsq() {
    return ywxw;
}

Vector4 Vector4::tqts() {
    return ywyx;
}

Vector4 Vector4::tqtt() {
    return ywyy;
}

Vector4 Vector4::tqtp() {
    return ywyz;
}

Vector4 Vector4::tqtq() {
    return ywyw;
}

Vector4 Vector4::tqps() {
    return ywzx;
}

Vector4 Vector4::tqpt() {
    return ywzy;
}

Vector4 Vector4::tqpp() {
    return ywzz;
}

Vector4 Vector4::tqpq() {
    return ywzw;
}

Vector4 Vector4::tqqs() {
    return ywwx;
}

Vector4 Vector4::tqqt() {
    return ywwy;
}

Vector4 Vector4::tqqp() {
    return ywwz;
}

Vector4 Vector4::tqqq() {
    return ywww;
}

Vector4 Vector4::psss() {
    return zxxx;
}

Vector4 Vector4::psst() {
    return zxxy;
}

Vector4 Vector4::pssp() {
    return zxxz;
}

Vector4 Vector4::pssq() {
    return zxxw;
}

Vector4 Vector4::psts() {
    return zxyx;
}

Vector4 Vector4::pstt() {
    return zxyy;
}

Vector4 Vector4::pstp() {
    return zxyz;
}

Vector4 Vector4::pstq() {
    return zxyw;
}

Vector4 Vector4::psps() {
    return zxzx;
}

Vector4 Vector4::pspt() {
    return zxzy;
}

Vector4 Vector4::pspp() {
    return zxzz;
}

Vector4 Vector4::pspq() {
    return zxzw;
}

Vector4 Vector4::psqs() {
    return zxwx;
}

Vector4 Vector4::psqt() {
    return zxwy;
}

Vector4 Vector4::psqp() {
    return zxwz;
}

Vector4 Vector4::psqq() {
    return zxww;
}

Vector4 Vector4::ptss() {
    return zyxx;
}

Vector4 Vector4::ptst() {
    return zyxy;
}

Vector4 Vector4::ptsp() {
    return zyxz;
}

Vector4 Vector4::ptsq() {
    return zyxw;
}

Vector4 Vector4::ptts() {
    return zyyx;
}

Vector4 Vector4::pttt() {
    return zyyy;
}

Vector4 Vector4::pttp() {
    return zyyz;
}

Vector4 Vector4::pttq() {
    return zyyw;
}

Vector4 Vector4::ptps() {
    return zyzx;
}

Vector4 Vector4::ptpt() {
    return zyzy;
}

Vector4 Vector4::ptpp() {
    return zyzz;
}

Vector4 Vector4::ptpq() {
    return zyzw;
}

Vector4 Vector4::ptqs() {
    return zywx;
}

Vector4 Vector4::ptqt() {
    return zywy;
}

Vector4 Vector4::ptqp() {
    return zywz;
}

Vector4 Vector4::ptqq() {
    return zyww;
}

Vector4 Vector4::ppss() {
    return zzxx;
}

Vector4 Vector4::ppst() {
    return zzxy;
}

Vector4 Vector4::ppsp() {
    return zzxz;
}

Vector4 Vector4::ppsq() {
    return zzxw;
}

Vector4 Vector4::ppts() {
    return zzyx;
}

Vector4 Vector4::pptt() {
    return zzyy;
}

Vector4 Vector4::pptp() {
    return zzyz;
}

Vector4 Vector4::pptq() {
    return zzyw;
}

Vector4 Vector4::ppps() {
    return zzzx;
}

Vector4 Vector4::pppt() {
    return zzzy;
}

Vector4 Vector4::pppp() {
    return zzzz;
}

Vector4 Vector4::pppq() {
    return zzzw;
}

Vector4 Vector4::ppqs() {
    return zzwx;
}

Vector4 Vector4::ppqt() {
    return zzwy;
}

Vector4 Vector4::ppqp() {
    return zzwz;
}

Vector4 Vector4::ppqq() {
    return zzww;
}

Vector4 Vector4::pqss() {
    return zwxx;
}

Vector4 Vector4::pqst() {
    return zwxy;
}

Vector4 Vector4::pqsp() {
    return zwxz;
}

Vector4 Vector4::pqsq() {
    return zwxw;
}

Vector4 Vector4::pqts() {
    return zwyx;
}

Vector4 Vector4::pqtt() {
    return zwyy;
}

Vector4 Vector4::pqtp() {
    return zwyz;
}

Vector4 Vector4::pqtq() {
    return zwyw;
}

Vector4 Vector4::pqps() {
    return zwzx;
}

Vector4 Vector4::pqpt() {
    return zwzy;
}

Vector4 Vector4::pqpp() {
    return zwzz;
}

Vector4 Vector4::pqpq() {
    return zwzw;
}

Vector4 Vector4::pqqs() {
    return zwwx;
}

Vector4 Vector4::pqqt() {
    return zwwy;
}

Vector4 Vector4::pqqp() {
    return zwwz;
}

Vector4 Vector4::pqqq() {
    return zwww;
}

Vector4 Vector4::qsss() {
    return wxxx;
}

Vector4 Vector4::qsst() {
    return wxxy;
}

Vector4 Vector4::qssp() {
    return wxxz;
}

Vector4 Vector4::qssq() {
    return wxxw;
}

Vector4 Vector4::qsts() {
    return wxyx;
}

Vector4 Vector4::qstt() {
    return wxyy;
}

Vector4 Vector4::qstp() {
    return wxyz;
}

Vector4 Vector4::qstq() {
    return wxyw;
}

Vector4 Vector4::qsps() {
    return wxzx;
}

Vector4 Vector4::qspt() {
    return wxzy;
}

Vector4 Vector4::qspp() {
    return wxzz;
}

Vector4 Vector4::qspq() {
    return wxzw;
}

Vector4 Vector4::qsqs() {
    return wxwx;
}

Vector4 Vector4::qsqt() {
    return wxwy;
}

Vector4 Vector4::qsqp() {
    return wxwz;
}

Vector4 Vector4::qsqq() {
    return wxww;
}

Vector4 Vector4::qtss() {
    return wyxx;
}

Vector4 Vector4::qtst() {
    return wyxy;
}

Vector4 Vector4::qtsp() {
    return wyxz;
}

Vector4 Vector4::qtsq() {
    return wyxw;
}

Vector4 Vector4::qtts() {
    return wyyx;
}

Vector4 Vector4::qttt() {
    return wyyy;
}

Vector4 Vector4::qttp() {
    return wyyz;
}

Vector4 Vector4::qttq() {
    return wyyw;
}

Vector4 Vector4::qtps() {
    return wyzx;
}

Vector4 Vector4::qtpt() {
    return wyzy;
}

Vector4 Vector4::qtpp() {
    return wyzz;
}

Vector4 Vector4::qtpq() {
    return wyzw;
}

Vector4 Vector4::qtqs() {
    return wywx;
}

Vector4 Vector4::qtqt() {
    return wywy;
}

Vector4 Vector4::qtqp() {
    return wywz;
}

Vector4 Vector4::qtqq() {
    return wyww;
}

Vector4 Vector4::qpss() {
    return wzxx;
}

Vector4 Vector4::qpst() {
    return wzxy;
}

Vector4 Vector4::qpsp() {
    return wzxz;
}

Vector4 Vector4::qpsq() {
    return wzxw;
}

Vector4 Vector4::qpts() {
    return wzyx;
}

Vector4 Vector4::qptt() {
    return wzyy;
}

Vector4 Vector4::qptp() {
    return wzyz;
}

Vector4 Vector4::qptq() {
    return wzyw;
}

Vector4 Vector4::qpps() {
    return wzzx;
}

Vector4 Vector4::qppt() {
    return wzzy;
}

Vector4 Vector4::qppp() {
    return wzzz;
}

Vector4 Vector4::qppq() {
    return wzzw;
}

Vector4 Vector4::qpqs() {
    return wzwx;
}

Vector4 Vector4::qpqt() {
    return wzwy;
}

Vector4 Vector4::qpqp() {
    return wzwz;
}

Vector4 Vector4::qpqq() {
    return wzww;
}

Vector4 Vector4::qqss() {
    return wwxx;
}

Vector4 Vector4::qqst() {
    return wwxy;
}

Vector4 Vector4::qqsp() {
    return wwxz;
}

Vector4 Vector4::qqsq() {
    return wwxw;
}

Vector4 Vector4::qqts() {
    return wwyx;
}

Vector4 Vector4::qqtt() {
    return wwyy;
}

Vector4 Vector4::qqtp() {
    return wwyz;
}

Vector4 Vector4::qqtq() {
    return wwyw;
}

Vector4 Vector4::qqps() {
    return wwzx;
}

Vector4 Vector4::qqpt() {
    return wwzy;
}

Vector4 Vector4::qqpp() {
    return wwzz;
}

Vector4 Vector4::qqpq() {
    return wwzw;
}

Vector4 Vector4::qqqs() {
    return wwwx;
}

Vector4 Vector4::qqqt() {
    return wwwy;
}

Vector4 Vector4::qqqp() {
    return wwwz;
}

Vector4 Vector4::qqqq() {
    return wwww;
}
