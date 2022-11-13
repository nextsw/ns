#include "vector4.hpp"
void Vector4Cls::min(Vector4 a, Vector4 b, Vector4 result) {
    auto _c1 = result;_c1.x = auto _c2 = math->min(a->x, b->x);_c2.y = auto _c3 = math->min(a->y, b->y);_c3.z = auto _c4 = math->min(a->z, b->z);_c4.w = math->min(a->w, b->w);_c4;_c3;_c2;_c1;
}

void Vector4Cls::max(Vector4 a, Vector4 b, Vector4 result) {
    auto _c1 = result;_c1.x = auto _c2 = math->max(a->x, b->x);_c2.y = auto _c3 = math->max(a->y, b->y);_c3.z = auto _c4 = math->max(a->z, b->z);_c4.w = math->max(a->w, b->w);_c4;_c3;_c2;_c1;
}

void Vector4Cls::mix(Vector4 min, Vector4 max, double a, Vector4 result) {
    auto _c1 = result;_c1.x = auto _c2 = min->x + a * (max->x - min->x);_c2.y = auto _c3 = min->y + a * (max->y - min->y);_c3.z = auto _c4 = min->z + a * (max->z - min->z);_c4.w = min->w + a * (max->w - min->w);_c4;_c3;_c2;_c1;
}

Float64List Vector4Cls::storage() {
    return _v4storage;
}

Vector4Cls::Vector4Cls(double x, double y, double z, double w) {
}

void Vector4Cls::array(List<double> array, int offset) {
    return _c1;
}

void Vector4Cls::zero()

void Vector4Cls::identity() {
    return _c1;
}

void Vector4Cls::all(double value) {
    return _c1;
}

void Vector4Cls::copy(Vector4 other) {
    return _c1;
}

void Vector4Cls::fromBuffer(ByteBuffer buffer, int offset)

void Vector4Cls::random(Random rng) {
    auto _c1 = Vector4Cls->zero();_c1.copyFromArray(array, offset);auto _c1 = Vector4Cls->zero();_c1.setIdentity();auto _c1 = Vector4Cls->zero();_c1.splat(value);auto _c1 = Vector4Cls->zero();_c1.setFrom(other);rng |= math->make<RandomCls>();
    return make<Vector4Cls>(rng->nextDouble(), rng->nextDouble(), rng->nextDouble(), rng->nextDouble());
}

void Vector4Cls::setValues(double x_, double y_, double z_, double w_) {
    _v4storage[3] = w_;
    _v4storage[2] = z_;
    _v4storage[1] = y_;
    _v4storage[0] = x_;
}

void Vector4Cls::setZero() {
    _v4storage[0] = 0.0;
    _v4storage[1] = 0.0;
    _v4storage[2] = 0.0;
    _v4storage[3] = 0.0;
}

void Vector4Cls::setIdentity() {
    _v4storage[0] = 0.0;
    _v4storage[1] = 0.0;
    _v4storage[2] = 0.0;
    _v4storage[3] = 1.0;
}

void Vector4Cls::setFrom(Vector4 other) {
    Unknown otherStorage = other->_v4storage;
    _v4storage[3] = otherStorage[3];
    _v4storage[2] = otherStorage[2];
    _v4storage[1] = otherStorage[1];
    _v4storage[0] = otherStorage[0];
}

void Vector4Cls::splat(double arg) {
    _v4storage[3] = arg;
    _v4storage[2] = arg;
    _v4storage[1] = arg;
    _v4storage[0] = arg;
}

String Vector4Cls::toString() {
    return __sf("%s,%s,%s,%s", _v4storage[0], _v4storage[1], _v4storage[2], _v4storage[3]);
}

bool Vector4Cls::==(Object other) {
    return (is<Vector4>(other)) && (_v4storage[0] == other->_v4storage[0]) && (_v4storage[1] == other->_v4storage[1]) && (_v4storage[2] == other->_v4storage[2]) && (_v4storage[3] == other->_v4storage[3]);
}

int Vector4Cls::hashCode() {
    return ObjectCls->hashAll(_v4storage);
}

Vector4 Vector4Cls::-() {
    return _c1;
}

Vector4 Vector4Cls::-(Vector4 other) {
    return _c1;
}

Vector4 Vector4Cls::+(Vector4 other) {
    return _c1;
}

Vector4 Vector4Cls::/(double scale) {
    return _c1;
}

Vector4 Vector4Cls::*(double scale) {
    return _c1;
}

double Vector4Cls::[](int i) {
    return _v4storage[i];
}

void Vector4Cls::[]=(int i, double v) {
    auto _c1 = clone();_c1.negate();auto _c1 = clone();_c1.sub(other);auto _c1 = clone();_c1.add(other);auto _c1 = clone();_c1.scale(1.0 / scale);auto _c1 = clone();_c1.scale(scale);_v4storage[i] = v;
}

void Vector4Cls::length(double value) {
    if (value == 0.0) {
        setZero();
    } else {
        auto l = length;
        if (l == 0.0) {
            return;
        }
        l = value / l;
        _v4storage[0] *= l;
        _v4storage[1] *= l;
        _v4storage[2] *= l;
        _v4storage[3] *= l;
    }
}

double Vector4Cls::length() {
    return math->sqrt(length2());
}

double Vector4Cls::length2() {
    double sum;
    sum = _v4storage[0] * _v4storage[0];
    sum += _v4storage[1] * _v4storage[1];
    sum += _v4storage[2] * _v4storage[2];
    sum += _v4storage[3] * _v4storage[3];
    return sum;
}

double Vector4Cls::normalize() {
    Unknown l = length;
    if (l == 0.0) {
        return 0.0;
    }
    Unknown d = 1.0 / l;
    _v4storage[0] *= d;
    _v4storage[1] *= d;
    _v4storage[2] *= d;
    _v4storage[3] *= d;
    return l;
}

double Vector4Cls::normalizeLength() {
    return normalize();
}

Vector4 Vector4Cls::normalized() {
    return _c1;
}

Vector4 Vector4Cls::normalizeInto(Vector4 out) {
    auto _c1 = clone();_c1.normalize();auto _c1 = out;_c1.auto _c2 = setFrom(this);_c2.normalize();_c2;_c1;
    return out;
}

double Vector4Cls::distanceTo(Vector4 arg) {
    return math->sqrt(distanceToSquared(arg));
}

double Vector4Cls::distanceToSquared(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    Unknown dx = _v4storage[0] - argStorage[0];
    Unknown dy = _v4storage[1] - argStorage[1];
    Unknown dz = _v4storage[2] - argStorage[2];
    Unknown dw = _v4storage[3] - argStorage[3];
    return dx * dx + dy * dy + dz * dz + dw * dw;
}

double Vector4Cls::dot(Vector4 other) {
    Unknown otherStorage = other->_v4storage;
    double sum;
    sum = _v4storage[0] * otherStorage[0];
    sum += _v4storage[1] * otherStorage[1];
    sum += _v4storage[2] * otherStorage[2];
    sum += _v4storage[3] * otherStorage[3];
    return sum;
}

void Vector4Cls::applyMatrix4(Matrix4 arg) {
    Unknown v1 = _v4storage[0];
    Unknown v2 = _v4storage[1];
    Unknown v3 = _v4storage[2];
    Unknown v4 = _v4storage[3];
    Unknown argStorage = arg->storage();
    _v4storage[0] = argStorage[0] * v1 + argStorage[4] * v2 + argStorage[8] * v3 + argStorage[12] * v4;
    _v4storage[1] = argStorage[1] * v1 + argStorage[5] * v2 + argStorage[9] * v3 + argStorage[13] * v4;
    _v4storage[2] = argStorage[2] * v1 + argStorage[6] * v2 + argStorage[10] * v3 + argStorage[14] * v4;
    _v4storage[3] = argStorage[3] * v1 + argStorage[7] * v2 + argStorage[11] * v3 + argStorage[15] * v4;
}

double Vector4Cls::relativeError(Vector4 correct) {
    Unknown correct_norm = correct->length;
    Unknown diff_norm = (this - correct)->length;
    return diff_norm / correct_norm;
}

double Vector4Cls::absoluteError(Vector4 correct) {
    return (this - correct)->length;
}

bool Vector4Cls::isInfinite() {
    auto is_infinite = false;
    is_infinite = is_infinite || _v4storage[0]->isInfinite;
    is_infinite = is_infinite || _v4storage[1]->isInfinite;
    is_infinite = is_infinite || _v4storage[2]->isInfinite;
    is_infinite = is_infinite || _v4storage[3]->isInfinite;
    return is_infinite;
}

bool Vector4Cls::isNaN() {
    auto is_nan = false;
    is_nan = is_nan || _v4storage[0]->isNaN;
    is_nan = is_nan || _v4storage[1]->isNaN;
    is_nan = is_nan || _v4storage[2]->isNaN;
    is_nan = is_nan || _v4storage[3]->isNaN;
    return is_nan;
}

void Vector4Cls::add(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = _v4storage[0] + argStorage[0];
    _v4storage[1] = _v4storage[1] + argStorage[1];
    _v4storage[2] = _v4storage[2] + argStorage[2];
    _v4storage[3] = _v4storage[3] + argStorage[3];
}

void Vector4Cls::addScaled(Vector4 arg, double factor) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = _v4storage[0] + argStorage[0] * factor;
    _v4storage[1] = _v4storage[1] + argStorage[1] * factor;
    _v4storage[2] = _v4storage[2] + argStorage[2] * factor;
    _v4storage[3] = _v4storage[3] + argStorage[3] * factor;
}

void Vector4Cls::sub(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = _v4storage[0] - argStorage[0];
    _v4storage[1] = _v4storage[1] - argStorage[1];
    _v4storage[2] = _v4storage[2] - argStorage[2];
    _v4storage[3] = _v4storage[3] - argStorage[3];
}

void Vector4Cls::multiply(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = _v4storage[0] * argStorage[0];
    _v4storage[1] = _v4storage[1] * argStorage[1];
    _v4storage[2] = _v4storage[2] * argStorage[2];
    _v4storage[3] = _v4storage[3] * argStorage[3];
}

void Vector4Cls::div(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = _v4storage[0] / argStorage[0];
    _v4storage[1] = _v4storage[1] / argStorage[1];
    _v4storage[2] = _v4storage[2] / argStorage[2];
    _v4storage[3] = _v4storage[3] / argStorage[3];
}

void Vector4Cls::scale(double arg) {
    _v4storage[0] = _v4storage[0] * arg;
    _v4storage[1] = _v4storage[1] * arg;
    _v4storage[2] = _v4storage[2] * arg;
    _v4storage[3] = _v4storage[3] * arg;
}

Vector4 Vector4Cls::scaled(double arg) {
    return _c1;
}

void Vector4Cls::negate() {
    auto _c1 = clone();_c1.scale(arg);_v4storage[0] = -_v4storage[0];
    _v4storage[1] = -_v4storage[1];
    _v4storage[2] = -_v4storage[2];
    _v4storage[3] = -_v4storage[3];
}

void Vector4Cls::absolute() {
    _v4storage[3] = _v4storage[3]->abs();
    _v4storage[2] = _v4storage[2]->abs();
    _v4storage[1] = _v4storage[1]->abs();
    _v4storage[0] = _v4storage[0]->abs();
}

void Vector4Cls::clamp(Vector4 min, Vector4 max) {
    Unknown minStorage = min->storage();
    Unknown maxStorage = max->storage();
    _v4storage[0] = _v4storage[0]->clamp(minStorage[0], maxStorage[0])->toDouble();
    _v4storage[1] = _v4storage[1]->clamp(minStorage[1], maxStorage[1])->toDouble();
    _v4storage[2] = _v4storage[2]->clamp(minStorage[2], maxStorage[2])->toDouble();
    _v4storage[3] = _v4storage[3]->clamp(minStorage[3], maxStorage[3])->toDouble();
}

void Vector4Cls::clampScalar(double min, double max) {
    _v4storage[0] = _v4storage[0]->clamp(min, max)->toDouble();
    _v4storage[1] = _v4storage[1]->clamp(min, max)->toDouble();
    _v4storage[2] = _v4storage[2]->clamp(min, max)->toDouble();
    _v4storage[3] = _v4storage[3]->clamp(min, max)->toDouble();
}

void Vector4Cls::floor() {
    _v4storage[0] = _v4storage[0]->floorToDouble();
    _v4storage[1] = _v4storage[1]->floorToDouble();
    _v4storage[2] = _v4storage[2]->floorToDouble();
    _v4storage[3] = _v4storage[3]->floorToDouble();
}

void Vector4Cls::ceil() {
    _v4storage[0] = _v4storage[0]->ceilToDouble();
    _v4storage[1] = _v4storage[1]->ceilToDouble();
    _v4storage[2] = _v4storage[2]->ceilToDouble();
    _v4storage[3] = _v4storage[3]->ceilToDouble();
}

void Vector4Cls::round() {
    _v4storage[0] = _v4storage[0]->roundToDouble();
    _v4storage[1] = _v4storage[1]->roundToDouble();
    _v4storage[2] = _v4storage[2]->roundToDouble();
    _v4storage[3] = _v4storage[3]->roundToDouble();
}

void Vector4Cls::roundToZero() {
    _v4storage[0] = _v4storage[0] < 0.0? _v4storage[0]->ceilToDouble() : _v4storage[0]->floorToDouble();
    _v4storage[1] = _v4storage[1] < 0.0? _v4storage[1]->ceilToDouble() : _v4storage[1]->floorToDouble();
    _v4storage[2] = _v4storage[2] < 0.0? _v4storage[2]->ceilToDouble() : _v4storage[2]->floorToDouble();
    _v4storage[3] = _v4storage[3] < 0.0? _v4storage[3]->ceilToDouble() : _v4storage[3]->floorToDouble();
}

Vector4 Vector4Cls::clone() {
    return Vector4Cls->copy(this);
}

Vector4 Vector4Cls::copyInto(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    argStorage[0] = _v4storage[0];
    argStorage[1] = _v4storage[1];
    argStorage[2] = _v4storage[2];
    argStorage[3] = _v4storage[3];
    return arg;
}

void Vector4Cls::copyIntoArray(List<double> array, int offset) {
    array[offset + 0] = _v4storage[0];
    array[offset + 1] = _v4storage[1];
    array[offset + 2] = _v4storage[2];
    array[offset + 3] = _v4storage[3];
}

void Vector4Cls::copyFromArray(List<double> array, int offset) {
    _v4storage[0] = array[offset + 0];
    _v4storage[1] = array[offset + 1];
    _v4storage[2] = array[offset + 2];
    _v4storage[3] = array[offset + 3];
}

void Vector4Cls::xy(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
}

void Vector4Cls::xz(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
}

void Vector4Cls::xw(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
}

void Vector4Cls::yx(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
}

void Vector4Cls::yz(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
}

void Vector4Cls::yw(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
}

void Vector4Cls::zx(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
}

void Vector4Cls::zy(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
}

void Vector4Cls::zw(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
}

void Vector4Cls::wx(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
}

void Vector4Cls::wy(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
}

void Vector4Cls::wz(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
}

void Vector4Cls::xyz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4Cls::xyw(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4Cls::xzy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4Cls::xzw(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4Cls::xwy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4Cls::xwz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4Cls::yxz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4Cls::yxw(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4Cls::yzx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4Cls::yzw(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4Cls::ywx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4Cls::ywz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4Cls::zxy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4Cls::zxw(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4Cls::zyx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4Cls::zyw(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
}

void Vector4Cls::zwx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4Cls::zwy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4Cls::wxy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4Cls::wxz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4Cls::wyx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4Cls::wyz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
}

void Vector4Cls::wzx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
}

void Vector4Cls::wzy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
}

void Vector4Cls::xyzw(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4Cls::xywz(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4Cls::xzyw(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4Cls::xzwy(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4Cls::xwyz(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4Cls::xwzy(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[0] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4Cls::yxzw(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4Cls::yxwz(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4Cls::yzxw(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4Cls::yzwx(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4Cls::ywxz(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4Cls::ywzx(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[1] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4Cls::zxyw(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4Cls::zxwy(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4Cls::zyxw(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[3] = argStorage[3];
}

void Vector4Cls::zywx(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[3] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4Cls::zwxy(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4Cls::zwyx(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[2] = argStorage[0];
    _v4storage[3] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4Cls::wxyz(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4Cls::wxzy(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[0] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4Cls::wyxz(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[2] = argStorage[3];
}

void Vector4Cls::wyzx(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[1] = argStorage[1];
    _v4storage[2] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4Cls::wzxy(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[0] = argStorage[2];
    _v4storage[1] = argStorage[3];
}

void Vector4Cls::wzyx(Vector4 arg) {
    Unknown argStorage = arg->_v4storage;
    _v4storage[3] = argStorage[0];
    _v4storage[2] = argStorage[1];
    _v4storage[1] = argStorage[2];
    _v4storage[0] = argStorage[3];
}

void Vector4Cls::r(double arg) {
    return x = arg;
}

void Vector4Cls::g(double arg) {
    return y = arg;
}

void Vector4Cls::b(double arg) {
    return z = arg;
}

void Vector4Cls::a(double arg) {
    return w = arg;
}

void Vector4Cls::s(double arg) {
    return x = arg;
}

void Vector4Cls::t(double arg) {
    return y = arg;
}

void Vector4Cls::p(double arg) {
    return z = arg;
}

void Vector4Cls::q(double arg) {
    return w = arg;
}

void Vector4Cls::x(double arg) {
    return _v4storage[0] = arg;
}

void Vector4Cls::y(double arg) {
    return _v4storage[1] = arg;
}

void Vector4Cls::z(double arg) {
    return _v4storage[2] = arg;
}

void Vector4Cls::w(double arg) {
    return _v4storage[3] = arg;
}

void Vector4Cls::rg(Vector2 arg) {
    return xy = arg;
}

void Vector4Cls::rb(Vector2 arg) {
    return xz = arg;
}

void Vector4Cls::ra(Vector2 arg) {
    return xw = arg;
}

void Vector4Cls::gr(Vector2 arg) {
    return yx = arg;
}

void Vector4Cls::gb(Vector2 arg) {
    return yz = arg;
}

void Vector4Cls::ga(Vector2 arg) {
    return yw = arg;
}

void Vector4Cls::br(Vector2 arg) {
    return zx = arg;
}

void Vector4Cls::bg(Vector2 arg) {
    return zy = arg;
}

void Vector4Cls::ba(Vector2 arg) {
    return zw = arg;
}

void Vector4Cls::ar(Vector2 arg) {
    return wx = arg;
}

void Vector4Cls::ag(Vector2 arg) {
    return wy = arg;
}

void Vector4Cls::ab(Vector2 arg) {
    return wz = arg;
}

void Vector4Cls::rgb(Vector3 arg) {
    return xyz = arg;
}

void Vector4Cls::rga(Vector3 arg) {
    return xyw = arg;
}

void Vector4Cls::rbg(Vector3 arg) {
    return xzy = arg;
}

void Vector4Cls::rba(Vector3 arg) {
    return xzw = arg;
}

void Vector4Cls::rag(Vector3 arg) {
    return xwy = arg;
}

void Vector4Cls::rab(Vector3 arg) {
    return xwz = arg;
}

void Vector4Cls::grb(Vector3 arg) {
    return yxz = arg;
}

void Vector4Cls::gra(Vector3 arg) {
    return yxw = arg;
}

void Vector4Cls::gbr(Vector3 arg) {
    return yzx = arg;
}

void Vector4Cls::gba(Vector3 arg) {
    return yzw = arg;
}

void Vector4Cls::gar(Vector3 arg) {
    return ywx = arg;
}

void Vector4Cls::gab(Vector3 arg) {
    return ywz = arg;
}

void Vector4Cls::brg(Vector3 arg) {
    return zxy = arg;
}

void Vector4Cls::bra(Vector3 arg) {
    return zxw = arg;
}

void Vector4Cls::bgr(Vector3 arg) {
    return zyx = arg;
}

void Vector4Cls::bga(Vector3 arg) {
    return zyw = arg;
}

void Vector4Cls::bar(Vector3 arg) {
    return zwx = arg;
}

void Vector4Cls::bag(Vector3 arg) {
    return zwy = arg;
}

void Vector4Cls::arg(Vector3 arg) {
    return wxy = arg;
}

void Vector4Cls::arb(Vector3 arg) {
    return wxz = arg;
}

void Vector4Cls::agr(Vector3 arg) {
    return wyx = arg;
}

void Vector4Cls::agb(Vector3 arg) {
    return wyz = arg;
}

void Vector4Cls::abr(Vector3 arg) {
    return wzx = arg;
}

void Vector4Cls::abg(Vector3 arg) {
    return wzy = arg;
}

void Vector4Cls::rgba(Vector4 arg) {
    return xyzw = arg;
}

void Vector4Cls::rgab(Vector4 arg) {
    return xywz = arg;
}

void Vector4Cls::rbga(Vector4 arg) {
    return xzyw = arg;
}

void Vector4Cls::rbag(Vector4 arg) {
    return xzwy = arg;
}

void Vector4Cls::ragb(Vector4 arg) {
    return xwyz = arg;
}

void Vector4Cls::rabg(Vector4 arg) {
    return xwzy = arg;
}

void Vector4Cls::grba(Vector4 arg) {
    return yxzw = arg;
}

void Vector4Cls::grab(Vector4 arg) {
    return yxwz = arg;
}

void Vector4Cls::gbra(Vector4 arg) {
    return yzxw = arg;
}

void Vector4Cls::gbar(Vector4 arg) {
    return yzwx = arg;
}

void Vector4Cls::garb(Vector4 arg) {
    return ywxz = arg;
}

void Vector4Cls::gabr(Vector4 arg) {
    return ywzx = arg;
}

void Vector4Cls::brga(Vector4 arg) {
    return zxyw = arg;
}

void Vector4Cls::brag(Vector4 arg) {
    return zxwy = arg;
}

void Vector4Cls::bgra(Vector4 arg) {
    return zyxw = arg;
}

void Vector4Cls::bgar(Vector4 arg) {
    return zywx = arg;
}

void Vector4Cls::barg(Vector4 arg) {
    return zwxy = arg;
}

void Vector4Cls::bagr(Vector4 arg) {
    return zwyx = arg;
}

void Vector4Cls::argb(Vector4 arg) {
    return wxyz = arg;
}

void Vector4Cls::arbg(Vector4 arg) {
    return wxzy = arg;
}

void Vector4Cls::agrb(Vector4 arg) {
    return wyxz = arg;
}

void Vector4Cls::agbr(Vector4 arg) {
    return wyzx = arg;
}

void Vector4Cls::abrg(Vector4 arg) {
    return wzxy = arg;
}

void Vector4Cls::abgr(Vector4 arg) {
    return wzyx = arg;
}

void Vector4Cls::st(Vector2 arg) {
    return xy = arg;
}

void Vector4Cls::sp(Vector2 arg) {
    return xz = arg;
}

void Vector4Cls::sq(Vector2 arg) {
    return xw = arg;
}

void Vector4Cls::ts(Vector2 arg) {
    return yx = arg;
}

void Vector4Cls::tp(Vector2 arg) {
    return yz = arg;
}

void Vector4Cls::tq(Vector2 arg) {
    return yw = arg;
}

void Vector4Cls::ps(Vector2 arg) {
    return zx = arg;
}

void Vector4Cls::pt(Vector2 arg) {
    return zy = arg;
}

void Vector4Cls::pq(Vector2 arg) {
    return zw = arg;
}

void Vector4Cls::qs(Vector2 arg) {
    return wx = arg;
}

void Vector4Cls::qt(Vector2 arg) {
    return wy = arg;
}

void Vector4Cls::qp(Vector2 arg) {
    return wz = arg;
}

void Vector4Cls::stp(Vector3 arg) {
    return xyz = arg;
}

void Vector4Cls::stq(Vector3 arg) {
    return xyw = arg;
}

void Vector4Cls::spt(Vector3 arg) {
    return xzy = arg;
}

void Vector4Cls::spq(Vector3 arg) {
    return xzw = arg;
}

void Vector4Cls::sqt(Vector3 arg) {
    return xwy = arg;
}

void Vector4Cls::sqp(Vector3 arg) {
    return xwz = arg;
}

void Vector4Cls::tsp(Vector3 arg) {
    return yxz = arg;
}

void Vector4Cls::tsq(Vector3 arg) {
    return yxw = arg;
}

void Vector4Cls::tps(Vector3 arg) {
    return yzx = arg;
}

void Vector4Cls::tpq(Vector3 arg) {
    return yzw = arg;
}

void Vector4Cls::tqs(Vector3 arg) {
    return ywx = arg;
}

void Vector4Cls::tqp(Vector3 arg) {
    return ywz = arg;
}

void Vector4Cls::pst(Vector3 arg) {
    return zxy = arg;
}

void Vector4Cls::psq(Vector3 arg) {
    return zxw = arg;
}

void Vector4Cls::pts(Vector3 arg) {
    return zyx = arg;
}

void Vector4Cls::ptq(Vector3 arg) {
    return zyw = arg;
}

void Vector4Cls::pqs(Vector3 arg) {
    return zwx = arg;
}

void Vector4Cls::pqt(Vector3 arg) {
    return zwy = arg;
}

void Vector4Cls::qst(Vector3 arg) {
    return wxy = arg;
}

void Vector4Cls::qsp(Vector3 arg) {
    return wxz = arg;
}

void Vector4Cls::qts(Vector3 arg) {
    return wyx = arg;
}

void Vector4Cls::qtp(Vector3 arg) {
    return wyz = arg;
}

void Vector4Cls::qps(Vector3 arg) {
    return wzx = arg;
}

void Vector4Cls::qpt(Vector3 arg) {
    return wzy = arg;
}

void Vector4Cls::stpq(Vector4 arg) {
    return xyzw = arg;
}

void Vector4Cls::stqp(Vector4 arg) {
    return xywz = arg;
}

void Vector4Cls::sptq(Vector4 arg) {
    return xzyw = arg;
}

void Vector4Cls::spqt(Vector4 arg) {
    return xzwy = arg;
}

void Vector4Cls::sqtp(Vector4 arg) {
    return xwyz = arg;
}

void Vector4Cls::sqpt(Vector4 arg) {
    return xwzy = arg;
}

void Vector4Cls::tspq(Vector4 arg) {
    return yxzw = arg;
}

void Vector4Cls::tsqp(Vector4 arg) {
    return yxwz = arg;
}

void Vector4Cls::tpsq(Vector4 arg) {
    return yzxw = arg;
}

void Vector4Cls::tpqs(Vector4 arg) {
    return yzwx = arg;
}

void Vector4Cls::tqsp(Vector4 arg) {
    return ywxz = arg;
}

void Vector4Cls::tqps(Vector4 arg) {
    return ywzx = arg;
}

void Vector4Cls::pstq(Vector4 arg) {
    return zxyw = arg;
}

void Vector4Cls::psqt(Vector4 arg) {
    return zxwy = arg;
}

void Vector4Cls::ptsq(Vector4 arg) {
    return zyxw = arg;
}

void Vector4Cls::ptqs(Vector4 arg) {
    return zywx = arg;
}

void Vector4Cls::pqst(Vector4 arg) {
    return zwxy = arg;
}

void Vector4Cls::pqts(Vector4 arg) {
    return zwyx = arg;
}

void Vector4Cls::qstp(Vector4 arg) {
    return wxyz = arg;
}

void Vector4Cls::qspt(Vector4 arg) {
    return wxzy = arg;
}

void Vector4Cls::qtsp(Vector4 arg) {
    return wyxz = arg;
}

void Vector4Cls::qtps(Vector4 arg) {
    return wyzx = arg;
}

void Vector4Cls::qpst(Vector4 arg) {
    return wzxy = arg;
}

void Vector4Cls::qpts(Vector4 arg) {
    return wzyx = arg;
}

Vector2 Vector4Cls::xx() {
    return make<Vector2Cls>(_v4storage[0], _v4storage[0]);
}

Vector2 Vector4Cls::xy() {
    return make<Vector2Cls>(_v4storage[0], _v4storage[1]);
}

Vector2 Vector4Cls::xz() {
    return make<Vector2Cls>(_v4storage[0], _v4storage[2]);
}

Vector2 Vector4Cls::xw() {
    return make<Vector2Cls>(_v4storage[0], _v4storage[3]);
}

Vector2 Vector4Cls::yx() {
    return make<Vector2Cls>(_v4storage[1], _v4storage[0]);
}

Vector2 Vector4Cls::yy() {
    return make<Vector2Cls>(_v4storage[1], _v4storage[1]);
}

Vector2 Vector4Cls::yz() {
    return make<Vector2Cls>(_v4storage[1], _v4storage[2]);
}

Vector2 Vector4Cls::yw() {
    return make<Vector2Cls>(_v4storage[1], _v4storage[3]);
}

Vector2 Vector4Cls::zx() {
    return make<Vector2Cls>(_v4storage[2], _v4storage[0]);
}

Vector2 Vector4Cls::zy() {
    return make<Vector2Cls>(_v4storage[2], _v4storage[1]);
}

Vector2 Vector4Cls::zz() {
    return make<Vector2Cls>(_v4storage[2], _v4storage[2]);
}

Vector2 Vector4Cls::zw() {
    return make<Vector2Cls>(_v4storage[2], _v4storage[3]);
}

Vector2 Vector4Cls::wx() {
    return make<Vector2Cls>(_v4storage[3], _v4storage[0]);
}

Vector2 Vector4Cls::wy() {
    return make<Vector2Cls>(_v4storage[3], _v4storage[1]);
}

Vector2 Vector4Cls::wz() {
    return make<Vector2Cls>(_v4storage[3], _v4storage[2]);
}

Vector2 Vector4Cls::ww() {
    return make<Vector2Cls>(_v4storage[3], _v4storage[3]);
}

Vector3 Vector4Cls::xxx() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4Cls::xxy() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4Cls::xxz() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4Cls::xxw() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4Cls::xyx() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4Cls::xyy() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4Cls::xyz() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4Cls::xyw() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4Cls::xzx() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4Cls::xzy() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4Cls::xzz() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4Cls::xzw() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4Cls::xwx() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4Cls::xwy() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4Cls::xwz() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4Cls::xww() {
    return make<Vector3Cls>(_v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector3 Vector4Cls::yxx() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4Cls::yxy() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4Cls::yxz() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4Cls::yxw() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4Cls::yyx() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4Cls::yyy() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4Cls::yyz() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4Cls::yyw() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4Cls::yzx() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4Cls::yzy() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4Cls::yzz() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4Cls::yzw() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4Cls::ywx() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4Cls::ywy() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4Cls::ywz() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4Cls::yww() {
    return make<Vector3Cls>(_v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector3 Vector4Cls::zxx() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4Cls::zxy() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4Cls::zxz() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4Cls::zxw() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4Cls::zyx() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4Cls::zyy() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4Cls::zyz() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4Cls::zyw() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4Cls::zzx() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4Cls::zzy() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4Cls::zzz() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4Cls::zzw() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4Cls::zwx() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4Cls::zwy() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4Cls::zwz() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4Cls::zww() {
    return make<Vector3Cls>(_v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector3 Vector4Cls::wxx() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector3 Vector4Cls::wxy() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector3 Vector4Cls::wxz() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector3 Vector4Cls::wxw() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector3 Vector4Cls::wyx() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector3 Vector4Cls::wyy() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector3 Vector4Cls::wyz() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector3 Vector4Cls::wyw() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector3 Vector4Cls::wzx() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector3 Vector4Cls::wzy() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector3 Vector4Cls::wzz() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector3 Vector4Cls::wzw() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector3 Vector4Cls::wwx() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector3 Vector4Cls::wwy() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector3 Vector4Cls::wwz() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector3 Vector4Cls::www() {
    return make<Vector3Cls>(_v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::xxxx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::xxxy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::xxxz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::xxxw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::xxyx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::xxyy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::xxyz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::xxyw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::xxzx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::xxzy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::xxzz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::xxzw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::xxwx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::xxwy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::xxwz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::xxww() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::xyxx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::xyxy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::xyxz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::xyxw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::xyyx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::xyyy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::xyyz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::xyyw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::xyzx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::xyzy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::xyzz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::xyzw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::xywx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::xywy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::xywz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::xyww() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::xzxx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::xzxy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::xzxz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::xzxw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::xzyx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::xzyy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::xzyz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::xzyw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::xzzx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::xzzy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::xzzz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::xzzw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::xzwx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::xzwy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::xzwz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::xzww() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::xwxx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::xwxy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::xwxz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::xwxw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::xwyx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::xwyy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::xwyz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::xwyw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::xwzx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::xwzy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::xwzz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::xwzw() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::xwwx() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::xwwy() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::xwwz() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::xwww() {
    return make<Vector4Cls>(_v4storage[0], _v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::yxxx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::yxxy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::yxxz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::yxxw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::yxyx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::yxyy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::yxyz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::yxyw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::yxzx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::yxzy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::yxzz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::yxzw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::yxwx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::yxwy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::yxwz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::yxww() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::yyxx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::yyxy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::yyxz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::yyxw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::yyyx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::yyyy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::yyyz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::yyyw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::yyzx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::yyzy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::yyzz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::yyzw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::yywx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::yywy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::yywz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::yyww() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::yzxx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::yzxy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::yzxz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::yzxw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::yzyx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::yzyy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::yzyz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::yzyw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::yzzx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::yzzy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::yzzz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::yzzw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::yzwx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::yzwy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::yzwz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::yzww() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::ywxx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::ywxy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::ywxz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::ywxw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::ywyx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::ywyy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::ywyz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::ywyw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::ywzx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::ywzy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::ywzz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::ywzw() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::ywwx() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::ywwy() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::ywwz() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::ywww() {
    return make<Vector4Cls>(_v4storage[1], _v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::zxxx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::zxxy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::zxxz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::zxxw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::zxyx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::zxyy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::zxyz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::zxyw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::zxzx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::zxzy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::zxzz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::zxzw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::zxwx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::zxwy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::zxwz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::zxww() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::zyxx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::zyxy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::zyxz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::zyxw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::zyyx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::zyyy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::zyyz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::zyyw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::zyzx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::zyzy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::zyzz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::zyzw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::zywx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::zywy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::zywz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::zyww() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::zzxx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::zzxy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::zzxz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::zzxw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::zzyx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::zzyy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::zzyz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::zzyw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::zzzx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::zzzy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::zzzz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::zzzw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::zzwx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::zzwy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::zzwz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::zzww() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::zwxx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::zwxy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::zwxz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::zwxw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::zwyx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::zwyy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::zwyz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::zwyw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::zwzx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::zwzy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::zwzz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::zwzw() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::zwwx() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::zwwy() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::zwwz() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::zwww() {
    return make<Vector4Cls>(_v4storage[2], _v4storage[3], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::wxxx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::wxxy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::wxxz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::wxxw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::wxyx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::wxyy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::wxyz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::wxyw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::wxzx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::wxzy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::wxzz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::wxzw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::wxwx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::wxwy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::wxwz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::wxww() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[0], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::wyxx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::wyxy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::wyxz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::wyxw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::wyyx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::wyyy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::wyyz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::wyyw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::wyzx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::wyzy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::wyzz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::wyzw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::wywx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::wywy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::wywz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::wyww() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[1], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::wzxx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::wzxy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::wzxz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::wzxw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::wzyx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::wzyy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::wzyz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::wzyw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::wzzx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::wzzy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::wzzz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::wzzw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::wzwx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::wzwy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::wzwz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::wzww() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[2], _v4storage[3], _v4storage[3]);
}

Vector4 Vector4Cls::wwxx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[0]);
}

Vector4 Vector4Cls::wwxy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[1]);
}

Vector4 Vector4Cls::wwxz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[2]);
}

Vector4 Vector4Cls::wwxw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[0], _v4storage[3]);
}

Vector4 Vector4Cls::wwyx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[0]);
}

Vector4 Vector4Cls::wwyy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[1]);
}

Vector4 Vector4Cls::wwyz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[2]);
}

Vector4 Vector4Cls::wwyw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[1], _v4storage[3]);
}

Vector4 Vector4Cls::wwzx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[0]);
}

Vector4 Vector4Cls::wwzy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[1]);
}

Vector4 Vector4Cls::wwzz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[2]);
}

Vector4 Vector4Cls::wwzw() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[2], _v4storage[3]);
}

Vector4 Vector4Cls::wwwx() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[0]);
}

Vector4 Vector4Cls::wwwy() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[1]);
}

Vector4 Vector4Cls::wwwz() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[2]);
}

Vector4 Vector4Cls::wwww() {
    return make<Vector4Cls>(_v4storage[3], _v4storage[3], _v4storage[3], _v4storage[3]);
}

double Vector4Cls::r() {
    return x;
}

double Vector4Cls::g() {
    return y;
}

double Vector4Cls::b() {
    return z;
}

double Vector4Cls::a() {
    return w;
}

double Vector4Cls::s() {
    return x;
}

double Vector4Cls::t() {
    return y;
}

double Vector4Cls::p() {
    return z;
}

double Vector4Cls::q() {
    return w;
}

double Vector4Cls::x() {
    return _v4storage[0];
}

double Vector4Cls::y() {
    return _v4storage[1];
}

double Vector4Cls::z() {
    return _v4storage[2];
}

double Vector4Cls::w() {
    return _v4storage[3];
}

Vector2 Vector4Cls::rr() {
    return xx();
}

Vector2 Vector4Cls::rg() {
    return xy;
}

Vector2 Vector4Cls::rb() {
    return xz;
}

Vector2 Vector4Cls::ra() {
    return xw;
}

Vector2 Vector4Cls::gr() {
    return yx;
}

Vector2 Vector4Cls::gg() {
    return yy();
}

Vector2 Vector4Cls::gb() {
    return yz;
}

Vector2 Vector4Cls::ga() {
    return yw;
}

Vector2 Vector4Cls::br() {
    return zx;
}

Vector2 Vector4Cls::bg() {
    return zy;
}

Vector2 Vector4Cls::bb() {
    return zz();
}

Vector2 Vector4Cls::ba() {
    return zw;
}

Vector2 Vector4Cls::ar() {
    return wx;
}

Vector2 Vector4Cls::ag() {
    return wy;
}

Vector2 Vector4Cls::ab() {
    return wz;
}

Vector2 Vector4Cls::aa() {
    return ww();
}

Vector3 Vector4Cls::rrr() {
    return xxx();
}

Vector3 Vector4Cls::rrg() {
    return xxy();
}

Vector3 Vector4Cls::rrb() {
    return xxz();
}

Vector3 Vector4Cls::rra() {
    return xxw();
}

Vector3 Vector4Cls::rgr() {
    return xyx();
}

Vector3 Vector4Cls::rgg() {
    return xyy();
}

Vector3 Vector4Cls::rgb() {
    return xyz;
}

Vector3 Vector4Cls::rga() {
    return xyw;
}

Vector3 Vector4Cls::rbr() {
    return xzx();
}

Vector3 Vector4Cls::rbg() {
    return xzy;
}

Vector3 Vector4Cls::rbb() {
    return xzz();
}

Vector3 Vector4Cls::rba() {
    return xzw;
}

Vector3 Vector4Cls::rar() {
    return xwx();
}

Vector3 Vector4Cls::rag() {
    return xwy;
}

Vector3 Vector4Cls::rab() {
    return xwz;
}

Vector3 Vector4Cls::raa() {
    return xww();
}

Vector3 Vector4Cls::grr() {
    return yxx();
}

Vector3 Vector4Cls::grg() {
    return yxy();
}

Vector3 Vector4Cls::grb() {
    return yxz;
}

Vector3 Vector4Cls::gra() {
    return yxw;
}

Vector3 Vector4Cls::ggr() {
    return yyx();
}

Vector3 Vector4Cls::ggg() {
    return yyy();
}

Vector3 Vector4Cls::ggb() {
    return yyz();
}

Vector3 Vector4Cls::gga() {
    return yyw();
}

Vector3 Vector4Cls::gbr() {
    return yzx;
}

Vector3 Vector4Cls::gbg() {
    return yzy();
}

Vector3 Vector4Cls::gbb() {
    return yzz();
}

Vector3 Vector4Cls::gba() {
    return yzw;
}

Vector3 Vector4Cls::gar() {
    return ywx;
}

Vector3 Vector4Cls::gag() {
    return ywy();
}

Vector3 Vector4Cls::gab() {
    return ywz;
}

Vector3 Vector4Cls::gaa() {
    return yww();
}

Vector3 Vector4Cls::brr() {
    return zxx();
}

Vector3 Vector4Cls::brg() {
    return zxy;
}

Vector3 Vector4Cls::brb() {
    return zxz();
}

Vector3 Vector4Cls::bra() {
    return zxw;
}

Vector3 Vector4Cls::bgr() {
    return zyx;
}

Vector3 Vector4Cls::bgg() {
    return zyy();
}

Vector3 Vector4Cls::bgb() {
    return zyz();
}

Vector3 Vector4Cls::bga() {
    return zyw;
}

Vector3 Vector4Cls::bbr() {
    return zzx();
}

Vector3 Vector4Cls::bbg() {
    return zzy();
}

Vector3 Vector4Cls::bbb() {
    return zzz();
}

Vector3 Vector4Cls::bba() {
    return zzw();
}

Vector3 Vector4Cls::bar() {
    return zwx;
}

Vector3 Vector4Cls::bag() {
    return zwy;
}

Vector3 Vector4Cls::bab() {
    return zwz();
}

Vector3 Vector4Cls::baa() {
    return zww();
}

Vector3 Vector4Cls::arr() {
    return wxx();
}

Vector3 Vector4Cls::arg() {
    return wxy;
}

Vector3 Vector4Cls::arb() {
    return wxz;
}

Vector3 Vector4Cls::ara() {
    return wxw();
}

Vector3 Vector4Cls::agr() {
    return wyx;
}

Vector3 Vector4Cls::agg() {
    return wyy();
}

Vector3 Vector4Cls::agb() {
    return wyz;
}

Vector3 Vector4Cls::aga() {
    return wyw();
}

Vector3 Vector4Cls::abr() {
    return wzx;
}

Vector3 Vector4Cls::abg() {
    return wzy;
}

Vector3 Vector4Cls::abb() {
    return wzz();
}

Vector3 Vector4Cls::aba() {
    return wzw();
}

Vector3 Vector4Cls::aar() {
    return wwx();
}

Vector3 Vector4Cls::aag() {
    return wwy();
}

Vector3 Vector4Cls::aab() {
    return wwz();
}

Vector3 Vector4Cls::aaa() {
    return www();
}

Vector4 Vector4Cls::rrrr() {
    return xxxx();
}

Vector4 Vector4Cls::rrrg() {
    return xxxy();
}

Vector4 Vector4Cls::rrrb() {
    return xxxz();
}

Vector4 Vector4Cls::rrra() {
    return xxxw();
}

Vector4 Vector4Cls::rrgr() {
    return xxyx();
}

Vector4 Vector4Cls::rrgg() {
    return xxyy();
}

Vector4 Vector4Cls::rrgb() {
    return xxyz();
}

Vector4 Vector4Cls::rrga() {
    return xxyw();
}

Vector4 Vector4Cls::rrbr() {
    return xxzx();
}

Vector4 Vector4Cls::rrbg() {
    return xxzy();
}

Vector4 Vector4Cls::rrbb() {
    return xxzz();
}

Vector4 Vector4Cls::rrba() {
    return xxzw();
}

Vector4 Vector4Cls::rrar() {
    return xxwx();
}

Vector4 Vector4Cls::rrag() {
    return xxwy();
}

Vector4 Vector4Cls::rrab() {
    return xxwz();
}

Vector4 Vector4Cls::rraa() {
    return xxww();
}

Vector4 Vector4Cls::rgrr() {
    return xyxx();
}

Vector4 Vector4Cls::rgrg() {
    return xyxy();
}

Vector4 Vector4Cls::rgrb() {
    return xyxz();
}

Vector4 Vector4Cls::rgra() {
    return xyxw();
}

Vector4 Vector4Cls::rggr() {
    return xyyx();
}

Vector4 Vector4Cls::rggg() {
    return xyyy();
}

Vector4 Vector4Cls::rggb() {
    return xyyz();
}

Vector4 Vector4Cls::rgga() {
    return xyyw();
}

Vector4 Vector4Cls::rgbr() {
    return xyzx();
}

Vector4 Vector4Cls::rgbg() {
    return xyzy();
}

Vector4 Vector4Cls::rgbb() {
    return xyzz();
}

Vector4 Vector4Cls::rgba() {
    return xyzw;
}

Vector4 Vector4Cls::rgar() {
    return xywx();
}

Vector4 Vector4Cls::rgag() {
    return xywy();
}

Vector4 Vector4Cls::rgab() {
    return xywz;
}

Vector4 Vector4Cls::rgaa() {
    return xyww();
}

Vector4 Vector4Cls::rbrr() {
    return xzxx();
}

Vector4 Vector4Cls::rbrg() {
    return xzxy();
}

Vector4 Vector4Cls::rbrb() {
    return xzxz();
}

Vector4 Vector4Cls::rbra() {
    return xzxw();
}

Vector4 Vector4Cls::rbgr() {
    return xzyx();
}

Vector4 Vector4Cls::rbgg() {
    return xzyy();
}

Vector4 Vector4Cls::rbgb() {
    return xzyz();
}

Vector4 Vector4Cls::rbga() {
    return xzyw;
}

Vector4 Vector4Cls::rbbr() {
    return xzzx();
}

Vector4 Vector4Cls::rbbg() {
    return xzzy();
}

Vector4 Vector4Cls::rbbb() {
    return xzzz();
}

Vector4 Vector4Cls::rbba() {
    return xzzw();
}

Vector4 Vector4Cls::rbar() {
    return xzwx();
}

Vector4 Vector4Cls::rbag() {
    return xzwy;
}

Vector4 Vector4Cls::rbab() {
    return xzwz();
}

Vector4 Vector4Cls::rbaa() {
    return xzww();
}

Vector4 Vector4Cls::rarr() {
    return xwxx();
}

Vector4 Vector4Cls::rarg() {
    return xwxy();
}

Vector4 Vector4Cls::rarb() {
    return xwxz();
}

Vector4 Vector4Cls::rara() {
    return xwxw();
}

Vector4 Vector4Cls::ragr() {
    return xwyx();
}

Vector4 Vector4Cls::ragg() {
    return xwyy();
}

Vector4 Vector4Cls::ragb() {
    return xwyz;
}

Vector4 Vector4Cls::raga() {
    return xwyw();
}

Vector4 Vector4Cls::rabr() {
    return xwzx();
}

Vector4 Vector4Cls::rabg() {
    return xwzy;
}

Vector4 Vector4Cls::rabb() {
    return xwzz();
}

Vector4 Vector4Cls::raba() {
    return xwzw();
}

Vector4 Vector4Cls::raar() {
    return xwwx();
}

Vector4 Vector4Cls::raag() {
    return xwwy();
}

Vector4 Vector4Cls::raab() {
    return xwwz();
}

Vector4 Vector4Cls::raaa() {
    return xwww();
}

Vector4 Vector4Cls::grrr() {
    return yxxx();
}

Vector4 Vector4Cls::grrg() {
    return yxxy();
}

Vector4 Vector4Cls::grrb() {
    return yxxz();
}

Vector4 Vector4Cls::grra() {
    return yxxw();
}

Vector4 Vector4Cls::grgr() {
    return yxyx();
}

Vector4 Vector4Cls::grgg() {
    return yxyy();
}

Vector4 Vector4Cls::grgb() {
    return yxyz();
}

Vector4 Vector4Cls::grga() {
    return yxyw();
}

Vector4 Vector4Cls::grbr() {
    return yxzx();
}

Vector4 Vector4Cls::grbg() {
    return yxzy();
}

Vector4 Vector4Cls::grbb() {
    return yxzz();
}

Vector4 Vector4Cls::grba() {
    return yxzw;
}

Vector4 Vector4Cls::grar() {
    return yxwx();
}

Vector4 Vector4Cls::grag() {
    return yxwy();
}

Vector4 Vector4Cls::grab() {
    return yxwz;
}

Vector4 Vector4Cls::graa() {
    return yxww();
}

Vector4 Vector4Cls::ggrr() {
    return yyxx();
}

Vector4 Vector4Cls::ggrg() {
    return yyxy();
}

Vector4 Vector4Cls::ggrb() {
    return yyxz();
}

Vector4 Vector4Cls::ggra() {
    return yyxw();
}

Vector4 Vector4Cls::gggr() {
    return yyyx();
}

Vector4 Vector4Cls::gggg() {
    return yyyy();
}

Vector4 Vector4Cls::gggb() {
    return yyyz();
}

Vector4 Vector4Cls::ggga() {
    return yyyw();
}

Vector4 Vector4Cls::ggbr() {
    return yyzx();
}

Vector4 Vector4Cls::ggbg() {
    return yyzy();
}

Vector4 Vector4Cls::ggbb() {
    return yyzz();
}

Vector4 Vector4Cls::ggba() {
    return yyzw();
}

Vector4 Vector4Cls::ggar() {
    return yywx();
}

Vector4 Vector4Cls::ggag() {
    return yywy();
}

Vector4 Vector4Cls::ggab() {
    return yywz();
}

Vector4 Vector4Cls::ggaa() {
    return yyww();
}

Vector4 Vector4Cls::gbrr() {
    return yzxx();
}

Vector4 Vector4Cls::gbrg() {
    return yzxy();
}

Vector4 Vector4Cls::gbrb() {
    return yzxz();
}

Vector4 Vector4Cls::gbra() {
    return yzxw;
}

Vector4 Vector4Cls::gbgr() {
    return yzyx();
}

Vector4 Vector4Cls::gbgg() {
    return yzyy();
}

Vector4 Vector4Cls::gbgb() {
    return yzyz();
}

Vector4 Vector4Cls::gbga() {
    return yzyw();
}

Vector4 Vector4Cls::gbbr() {
    return yzzx();
}

Vector4 Vector4Cls::gbbg() {
    return yzzy();
}

Vector4 Vector4Cls::gbbb() {
    return yzzz();
}

Vector4 Vector4Cls::gbba() {
    return yzzw();
}

Vector4 Vector4Cls::gbar() {
    return yzwx;
}

Vector4 Vector4Cls::gbag() {
    return yzwy();
}

Vector4 Vector4Cls::gbab() {
    return yzwz();
}

Vector4 Vector4Cls::gbaa() {
    return yzww();
}

Vector4 Vector4Cls::garr() {
    return ywxx();
}

Vector4 Vector4Cls::garg() {
    return ywxy();
}

Vector4 Vector4Cls::garb() {
    return ywxz;
}

Vector4 Vector4Cls::gara() {
    return ywxw();
}

Vector4 Vector4Cls::gagr() {
    return ywyx();
}

Vector4 Vector4Cls::gagg() {
    return ywyy();
}

Vector4 Vector4Cls::gagb() {
    return ywyz();
}

Vector4 Vector4Cls::gaga() {
    return ywyw();
}

Vector4 Vector4Cls::gabr() {
    return ywzx;
}

Vector4 Vector4Cls::gabg() {
    return ywzy();
}

Vector4 Vector4Cls::gabb() {
    return ywzz();
}

Vector4 Vector4Cls::gaba() {
    return ywzw();
}

Vector4 Vector4Cls::gaar() {
    return ywwx();
}

Vector4 Vector4Cls::gaag() {
    return ywwy();
}

Vector4 Vector4Cls::gaab() {
    return ywwz();
}

Vector4 Vector4Cls::gaaa() {
    return ywww();
}

Vector4 Vector4Cls::brrr() {
    return zxxx();
}

Vector4 Vector4Cls::brrg() {
    return zxxy();
}

Vector4 Vector4Cls::brrb() {
    return zxxz();
}

Vector4 Vector4Cls::brra() {
    return zxxw();
}

Vector4 Vector4Cls::brgr() {
    return zxyx();
}

Vector4 Vector4Cls::brgg() {
    return zxyy();
}

Vector4 Vector4Cls::brgb() {
    return zxyz();
}

Vector4 Vector4Cls::brga() {
    return zxyw;
}

Vector4 Vector4Cls::brbr() {
    return zxzx();
}

Vector4 Vector4Cls::brbg() {
    return zxzy();
}

Vector4 Vector4Cls::brbb() {
    return zxzz();
}

Vector4 Vector4Cls::brba() {
    return zxzw();
}

Vector4 Vector4Cls::brar() {
    return zxwx();
}

Vector4 Vector4Cls::brag() {
    return zxwy;
}

Vector4 Vector4Cls::brab() {
    return zxwz();
}

Vector4 Vector4Cls::braa() {
    return zxww();
}

Vector4 Vector4Cls::bgrr() {
    return zyxx();
}

Vector4 Vector4Cls::bgrg() {
    return zyxy();
}

Vector4 Vector4Cls::bgrb() {
    return zyxz();
}

Vector4 Vector4Cls::bgra() {
    return zyxw;
}

Vector4 Vector4Cls::bggr() {
    return zyyx();
}

Vector4 Vector4Cls::bggg() {
    return zyyy();
}

Vector4 Vector4Cls::bggb() {
    return zyyz();
}

Vector4 Vector4Cls::bgga() {
    return zyyw();
}

Vector4 Vector4Cls::bgbr() {
    return zyzx();
}

Vector4 Vector4Cls::bgbg() {
    return zyzy();
}

Vector4 Vector4Cls::bgbb() {
    return zyzz();
}

Vector4 Vector4Cls::bgba() {
    return zyzw();
}

Vector4 Vector4Cls::bgar() {
    return zywx;
}

Vector4 Vector4Cls::bgag() {
    return zywy();
}

Vector4 Vector4Cls::bgab() {
    return zywz();
}

Vector4 Vector4Cls::bgaa() {
    return zyww();
}

Vector4 Vector4Cls::bbrr() {
    return zzxx();
}

Vector4 Vector4Cls::bbrg() {
    return zzxy();
}

Vector4 Vector4Cls::bbrb() {
    return zzxz();
}

Vector4 Vector4Cls::bbra() {
    return zzxw();
}

Vector4 Vector4Cls::bbgr() {
    return zzyx();
}

Vector4 Vector4Cls::bbgg() {
    return zzyy();
}

Vector4 Vector4Cls::bbgb() {
    return zzyz();
}

Vector4 Vector4Cls::bbga() {
    return zzyw();
}

Vector4 Vector4Cls::bbbr() {
    return zzzx();
}

Vector4 Vector4Cls::bbbg() {
    return zzzy();
}

Vector4 Vector4Cls::bbbb() {
    return zzzz();
}

Vector4 Vector4Cls::bbba() {
    return zzzw();
}

Vector4 Vector4Cls::bbar() {
    return zzwx();
}

Vector4 Vector4Cls::bbag() {
    return zzwy();
}

Vector4 Vector4Cls::bbab() {
    return zzwz();
}

Vector4 Vector4Cls::bbaa() {
    return zzww();
}

Vector4 Vector4Cls::barr() {
    return zwxx();
}

Vector4 Vector4Cls::barg() {
    return zwxy;
}

Vector4 Vector4Cls::barb() {
    return zwxz();
}

Vector4 Vector4Cls::bara() {
    return zwxw();
}

Vector4 Vector4Cls::bagr() {
    return zwyx;
}

Vector4 Vector4Cls::bagg() {
    return zwyy();
}

Vector4 Vector4Cls::bagb() {
    return zwyz();
}

Vector4 Vector4Cls::baga() {
    return zwyw();
}

Vector4 Vector4Cls::babr() {
    return zwzx();
}

Vector4 Vector4Cls::babg() {
    return zwzy();
}

Vector4 Vector4Cls::babb() {
    return zwzz();
}

Vector4 Vector4Cls::baba() {
    return zwzw();
}

Vector4 Vector4Cls::baar() {
    return zwwx();
}

Vector4 Vector4Cls::baag() {
    return zwwy();
}

Vector4 Vector4Cls::baab() {
    return zwwz();
}

Vector4 Vector4Cls::baaa() {
    return zwww();
}

Vector4 Vector4Cls::arrr() {
    return wxxx();
}

Vector4 Vector4Cls::arrg() {
    return wxxy();
}

Vector4 Vector4Cls::arrb() {
    return wxxz();
}

Vector4 Vector4Cls::arra() {
    return wxxw();
}

Vector4 Vector4Cls::argr() {
    return wxyx();
}

Vector4 Vector4Cls::argg() {
    return wxyy();
}

Vector4 Vector4Cls::argb() {
    return wxyz;
}

Vector4 Vector4Cls::arga() {
    return wxyw();
}

Vector4 Vector4Cls::arbr() {
    return wxzx();
}

Vector4 Vector4Cls::arbg() {
    return wxzy;
}

Vector4 Vector4Cls::arbb() {
    return wxzz();
}

Vector4 Vector4Cls::arba() {
    return wxzw();
}

Vector4 Vector4Cls::arar() {
    return wxwx();
}

Vector4 Vector4Cls::arag() {
    return wxwy();
}

Vector4 Vector4Cls::arab() {
    return wxwz();
}

Vector4 Vector4Cls::araa() {
    return wxww();
}

Vector4 Vector4Cls::agrr() {
    return wyxx();
}

Vector4 Vector4Cls::agrg() {
    return wyxy();
}

Vector4 Vector4Cls::agrb() {
    return wyxz;
}

Vector4 Vector4Cls::agra() {
    return wyxw();
}

Vector4 Vector4Cls::aggr() {
    return wyyx();
}

Vector4 Vector4Cls::aggg() {
    return wyyy();
}

Vector4 Vector4Cls::aggb() {
    return wyyz();
}

Vector4 Vector4Cls::agga() {
    return wyyw();
}

Vector4 Vector4Cls::agbr() {
    return wyzx;
}

Vector4 Vector4Cls::agbg() {
    return wyzy();
}

Vector4 Vector4Cls::agbb() {
    return wyzz();
}

Vector4 Vector4Cls::agba() {
    return wyzw();
}

Vector4 Vector4Cls::agar() {
    return wywx();
}

Vector4 Vector4Cls::agag() {
    return wywy();
}

Vector4 Vector4Cls::agab() {
    return wywz();
}

Vector4 Vector4Cls::agaa() {
    return wyww();
}

Vector4 Vector4Cls::abrr() {
    return wzxx();
}

Vector4 Vector4Cls::abrg() {
    return wzxy;
}

Vector4 Vector4Cls::abrb() {
    return wzxz();
}

Vector4 Vector4Cls::abra() {
    return wzxw();
}

Vector4 Vector4Cls::abgr() {
    return wzyx;
}

Vector4 Vector4Cls::abgg() {
    return wzyy();
}

Vector4 Vector4Cls::abgb() {
    return wzyz();
}

Vector4 Vector4Cls::abga() {
    return wzyw();
}

Vector4 Vector4Cls::abbr() {
    return wzzx();
}

Vector4 Vector4Cls::abbg() {
    return wzzy();
}

Vector4 Vector4Cls::abbb() {
    return wzzz();
}

Vector4 Vector4Cls::abba() {
    return wzzw();
}

Vector4 Vector4Cls::abar() {
    return wzwx();
}

Vector4 Vector4Cls::abag() {
    return wzwy();
}

Vector4 Vector4Cls::abab() {
    return wzwz();
}

Vector4 Vector4Cls::abaa() {
    return wzww();
}

Vector4 Vector4Cls::aarr() {
    return wwxx();
}

Vector4 Vector4Cls::aarg() {
    return wwxy();
}

Vector4 Vector4Cls::aarb() {
    return wwxz();
}

Vector4 Vector4Cls::aara() {
    return wwxw();
}

Vector4 Vector4Cls::aagr() {
    return wwyx();
}

Vector4 Vector4Cls::aagg() {
    return wwyy();
}

Vector4 Vector4Cls::aagb() {
    return wwyz();
}

Vector4 Vector4Cls::aaga() {
    return wwyw();
}

Vector4 Vector4Cls::aabr() {
    return wwzx();
}

Vector4 Vector4Cls::aabg() {
    return wwzy();
}

Vector4 Vector4Cls::aabb() {
    return wwzz();
}

Vector4 Vector4Cls::aaba() {
    return wwzw();
}

Vector4 Vector4Cls::aaar() {
    return wwwx();
}

Vector4 Vector4Cls::aaag() {
    return wwwy();
}

Vector4 Vector4Cls::aaab() {
    return wwwz();
}

Vector4 Vector4Cls::aaaa() {
    return wwww();
}

Vector2 Vector4Cls::ss() {
    return xx();
}

Vector2 Vector4Cls::st() {
    return xy;
}

Vector2 Vector4Cls::sp() {
    return xz;
}

Vector2 Vector4Cls::sq() {
    return xw;
}

Vector2 Vector4Cls::ts() {
    return yx;
}

Vector2 Vector4Cls::tt() {
    return yy();
}

Vector2 Vector4Cls::tp() {
    return yz;
}

Vector2 Vector4Cls::tq() {
    return yw;
}

Vector2 Vector4Cls::ps() {
    return zx;
}

Vector2 Vector4Cls::pt() {
    return zy;
}

Vector2 Vector4Cls::pp() {
    return zz();
}

Vector2 Vector4Cls::pq() {
    return zw;
}

Vector2 Vector4Cls::qs() {
    return wx;
}

Vector2 Vector4Cls::qt() {
    return wy;
}

Vector2 Vector4Cls::qp() {
    return wz;
}

Vector2 Vector4Cls::qq() {
    return ww();
}

Vector3 Vector4Cls::sss() {
    return xxx();
}

Vector3 Vector4Cls::sst() {
    return xxy();
}

Vector3 Vector4Cls::ssp() {
    return xxz();
}

Vector3 Vector4Cls::ssq() {
    return xxw();
}

Vector3 Vector4Cls::sts() {
    return xyx();
}

Vector3 Vector4Cls::stt() {
    return xyy();
}

Vector3 Vector4Cls::stp() {
    return xyz;
}

Vector3 Vector4Cls::stq() {
    return xyw;
}

Vector3 Vector4Cls::sps() {
    return xzx();
}

Vector3 Vector4Cls::spt() {
    return xzy;
}

Vector3 Vector4Cls::spp() {
    return xzz();
}

Vector3 Vector4Cls::spq() {
    return xzw;
}

Vector3 Vector4Cls::sqs() {
    return xwx();
}

Vector3 Vector4Cls::sqt() {
    return xwy;
}

Vector3 Vector4Cls::sqp() {
    return xwz;
}

Vector3 Vector4Cls::sqq() {
    return xww();
}

Vector3 Vector4Cls::tss() {
    return yxx();
}

Vector3 Vector4Cls::tst() {
    return yxy();
}

Vector3 Vector4Cls::tsp() {
    return yxz;
}

Vector3 Vector4Cls::tsq() {
    return yxw;
}

Vector3 Vector4Cls::tts() {
    return yyx();
}

Vector3 Vector4Cls::ttt() {
    return yyy();
}

Vector3 Vector4Cls::ttp() {
    return yyz();
}

Vector3 Vector4Cls::ttq() {
    return yyw();
}

Vector3 Vector4Cls::tps() {
    return yzx;
}

Vector3 Vector4Cls::tpt() {
    return yzy();
}

Vector3 Vector4Cls::tpp() {
    return yzz();
}

Vector3 Vector4Cls::tpq() {
    return yzw;
}

Vector3 Vector4Cls::tqs() {
    return ywx;
}

Vector3 Vector4Cls::tqt() {
    return ywy();
}

Vector3 Vector4Cls::tqp() {
    return ywz;
}

Vector3 Vector4Cls::tqq() {
    return yww();
}

Vector3 Vector4Cls::pss() {
    return zxx();
}

Vector3 Vector4Cls::pst() {
    return zxy;
}

Vector3 Vector4Cls::psp() {
    return zxz();
}

Vector3 Vector4Cls::psq() {
    return zxw;
}

Vector3 Vector4Cls::pts() {
    return zyx;
}

Vector3 Vector4Cls::ptt() {
    return zyy();
}

Vector3 Vector4Cls::ptp() {
    return zyz();
}

Vector3 Vector4Cls::ptq() {
    return zyw;
}

Vector3 Vector4Cls::pps() {
    return zzx();
}

Vector3 Vector4Cls::ppt() {
    return zzy();
}

Vector3 Vector4Cls::ppp() {
    return zzz();
}

Vector3 Vector4Cls::ppq() {
    return zzw();
}

Vector3 Vector4Cls::pqs() {
    return zwx;
}

Vector3 Vector4Cls::pqt() {
    return zwy;
}

Vector3 Vector4Cls::pqp() {
    return zwz();
}

Vector3 Vector4Cls::pqq() {
    return zww();
}

Vector3 Vector4Cls::qss() {
    return wxx();
}

Vector3 Vector4Cls::qst() {
    return wxy;
}

Vector3 Vector4Cls::qsp() {
    return wxz;
}

Vector3 Vector4Cls::qsq() {
    return wxw();
}

Vector3 Vector4Cls::qts() {
    return wyx;
}

Vector3 Vector4Cls::qtt() {
    return wyy();
}

Vector3 Vector4Cls::qtp() {
    return wyz;
}

Vector3 Vector4Cls::qtq() {
    return wyw();
}

Vector3 Vector4Cls::qps() {
    return wzx;
}

Vector3 Vector4Cls::qpt() {
    return wzy;
}

Vector3 Vector4Cls::qpp() {
    return wzz();
}

Vector3 Vector4Cls::qpq() {
    return wzw();
}

Vector3 Vector4Cls::qqs() {
    return wwx();
}

Vector3 Vector4Cls::qqt() {
    return wwy();
}

Vector3 Vector4Cls::qqp() {
    return wwz();
}

Vector3 Vector4Cls::qqq() {
    return www();
}

Vector4 Vector4Cls::ssss() {
    return xxxx();
}

Vector4 Vector4Cls::ssst() {
    return xxxy();
}

Vector4 Vector4Cls::sssp() {
    return xxxz();
}

Vector4 Vector4Cls::sssq() {
    return xxxw();
}

Vector4 Vector4Cls::ssts() {
    return xxyx();
}

Vector4 Vector4Cls::sstt() {
    return xxyy();
}

Vector4 Vector4Cls::sstp() {
    return xxyz();
}

Vector4 Vector4Cls::sstq() {
    return xxyw();
}

Vector4 Vector4Cls::ssps() {
    return xxzx();
}

Vector4 Vector4Cls::sspt() {
    return xxzy();
}

Vector4 Vector4Cls::sspp() {
    return xxzz();
}

Vector4 Vector4Cls::sspq() {
    return xxzw();
}

Vector4 Vector4Cls::ssqs() {
    return xxwx();
}

Vector4 Vector4Cls::ssqt() {
    return xxwy();
}

Vector4 Vector4Cls::ssqp() {
    return xxwz();
}

Vector4 Vector4Cls::ssqq() {
    return xxww();
}

Vector4 Vector4Cls::stss() {
    return xyxx();
}

Vector4 Vector4Cls::stst() {
    return xyxy();
}

Vector4 Vector4Cls::stsp() {
    return xyxz();
}

Vector4 Vector4Cls::stsq() {
    return xyxw();
}

Vector4 Vector4Cls::stts() {
    return xyyx();
}

Vector4 Vector4Cls::sttt() {
    return xyyy();
}

Vector4 Vector4Cls::sttp() {
    return xyyz();
}

Vector4 Vector4Cls::sttq() {
    return xyyw();
}

Vector4 Vector4Cls::stps() {
    return xyzx();
}

Vector4 Vector4Cls::stpt() {
    return xyzy();
}

Vector4 Vector4Cls::stpp() {
    return xyzz();
}

Vector4 Vector4Cls::stpq() {
    return xyzw;
}

Vector4 Vector4Cls::stqs() {
    return xywx();
}

Vector4 Vector4Cls::stqt() {
    return xywy();
}

Vector4 Vector4Cls::stqp() {
    return xywz;
}

Vector4 Vector4Cls::stqq() {
    return xyww();
}

Vector4 Vector4Cls::spss() {
    return xzxx();
}

Vector4 Vector4Cls::spst() {
    return xzxy();
}

Vector4 Vector4Cls::spsp() {
    return xzxz();
}

Vector4 Vector4Cls::spsq() {
    return xzxw();
}

Vector4 Vector4Cls::spts() {
    return xzyx();
}

Vector4 Vector4Cls::sptt() {
    return xzyy();
}

Vector4 Vector4Cls::sptp() {
    return xzyz();
}

Vector4 Vector4Cls::sptq() {
    return xzyw;
}

Vector4 Vector4Cls::spps() {
    return xzzx();
}

Vector4 Vector4Cls::sppt() {
    return xzzy();
}

Vector4 Vector4Cls::sppp() {
    return xzzz();
}

Vector4 Vector4Cls::sppq() {
    return xzzw();
}

Vector4 Vector4Cls::spqs() {
    return xzwx();
}

Vector4 Vector4Cls::spqt() {
    return xzwy;
}

Vector4 Vector4Cls::spqp() {
    return xzwz();
}

Vector4 Vector4Cls::spqq() {
    return xzww();
}

Vector4 Vector4Cls::sqss() {
    return xwxx();
}

Vector4 Vector4Cls::sqst() {
    return xwxy();
}

Vector4 Vector4Cls::sqsp() {
    return xwxz();
}

Vector4 Vector4Cls::sqsq() {
    return xwxw();
}

Vector4 Vector4Cls::sqts() {
    return xwyx();
}

Vector4 Vector4Cls::sqtt() {
    return xwyy();
}

Vector4 Vector4Cls::sqtp() {
    return xwyz;
}

Vector4 Vector4Cls::sqtq() {
    return xwyw();
}

Vector4 Vector4Cls::sqps() {
    return xwzx();
}

Vector4 Vector4Cls::sqpt() {
    return xwzy;
}

Vector4 Vector4Cls::sqpp() {
    return xwzz();
}

Vector4 Vector4Cls::sqpq() {
    return xwzw();
}

Vector4 Vector4Cls::sqqs() {
    return xwwx();
}

Vector4 Vector4Cls::sqqt() {
    return xwwy();
}

Vector4 Vector4Cls::sqqp() {
    return xwwz();
}

Vector4 Vector4Cls::sqqq() {
    return xwww();
}

Vector4 Vector4Cls::tsss() {
    return yxxx();
}

Vector4 Vector4Cls::tsst() {
    return yxxy();
}

Vector4 Vector4Cls::tssp() {
    return yxxz();
}

Vector4 Vector4Cls::tssq() {
    return yxxw();
}

Vector4 Vector4Cls::tsts() {
    return yxyx();
}

Vector4 Vector4Cls::tstt() {
    return yxyy();
}

Vector4 Vector4Cls::tstp() {
    return yxyz();
}

Vector4 Vector4Cls::tstq() {
    return yxyw();
}

Vector4 Vector4Cls::tsps() {
    return yxzx();
}

Vector4 Vector4Cls::tspt() {
    return yxzy();
}

Vector4 Vector4Cls::tspp() {
    return yxzz();
}

Vector4 Vector4Cls::tspq() {
    return yxzw;
}

Vector4 Vector4Cls::tsqs() {
    return yxwx();
}

Vector4 Vector4Cls::tsqt() {
    return yxwy();
}

Vector4 Vector4Cls::tsqp() {
    return yxwz;
}

Vector4 Vector4Cls::tsqq() {
    return yxww();
}

Vector4 Vector4Cls::ttss() {
    return yyxx();
}

Vector4 Vector4Cls::ttst() {
    return yyxy();
}

Vector4 Vector4Cls::ttsp() {
    return yyxz();
}

Vector4 Vector4Cls::ttsq() {
    return yyxw();
}

Vector4 Vector4Cls::ttts() {
    return yyyx();
}

Vector4 Vector4Cls::tttt() {
    return yyyy();
}

Vector4 Vector4Cls::tttp() {
    return yyyz();
}

Vector4 Vector4Cls::tttq() {
    return yyyw();
}

Vector4 Vector4Cls::ttps() {
    return yyzx();
}

Vector4 Vector4Cls::ttpt() {
    return yyzy();
}

Vector4 Vector4Cls::ttpp() {
    return yyzz();
}

Vector4 Vector4Cls::ttpq() {
    return yyzw();
}

Vector4 Vector4Cls::ttqs() {
    return yywx();
}

Vector4 Vector4Cls::ttqt() {
    return yywy();
}

Vector4 Vector4Cls::ttqp() {
    return yywz();
}

Vector4 Vector4Cls::ttqq() {
    return yyww();
}

Vector4 Vector4Cls::tpss() {
    return yzxx();
}

Vector4 Vector4Cls::tpst() {
    return yzxy();
}

Vector4 Vector4Cls::tpsp() {
    return yzxz();
}

Vector4 Vector4Cls::tpsq() {
    return yzxw;
}

Vector4 Vector4Cls::tpts() {
    return yzyx();
}

Vector4 Vector4Cls::tptt() {
    return yzyy();
}

Vector4 Vector4Cls::tptp() {
    return yzyz();
}

Vector4 Vector4Cls::tptq() {
    return yzyw();
}

Vector4 Vector4Cls::tpps() {
    return yzzx();
}

Vector4 Vector4Cls::tppt() {
    return yzzy();
}

Vector4 Vector4Cls::tppp() {
    return yzzz();
}

Vector4 Vector4Cls::tppq() {
    return yzzw();
}

Vector4 Vector4Cls::tpqs() {
    return yzwx;
}

Vector4 Vector4Cls::tpqt() {
    return yzwy();
}

Vector4 Vector4Cls::tpqp() {
    return yzwz();
}

Vector4 Vector4Cls::tpqq() {
    return yzww();
}

Vector4 Vector4Cls::tqss() {
    return ywxx();
}

Vector4 Vector4Cls::tqst() {
    return ywxy();
}

Vector4 Vector4Cls::tqsp() {
    return ywxz;
}

Vector4 Vector4Cls::tqsq() {
    return ywxw();
}

Vector4 Vector4Cls::tqts() {
    return ywyx();
}

Vector4 Vector4Cls::tqtt() {
    return ywyy();
}

Vector4 Vector4Cls::tqtp() {
    return ywyz();
}

Vector4 Vector4Cls::tqtq() {
    return ywyw();
}

Vector4 Vector4Cls::tqps() {
    return ywzx;
}

Vector4 Vector4Cls::tqpt() {
    return ywzy();
}

Vector4 Vector4Cls::tqpp() {
    return ywzz();
}

Vector4 Vector4Cls::tqpq() {
    return ywzw();
}

Vector4 Vector4Cls::tqqs() {
    return ywwx();
}

Vector4 Vector4Cls::tqqt() {
    return ywwy();
}

Vector4 Vector4Cls::tqqp() {
    return ywwz();
}

Vector4 Vector4Cls::tqqq() {
    return ywww();
}

Vector4 Vector4Cls::psss() {
    return zxxx();
}

Vector4 Vector4Cls::psst() {
    return zxxy();
}

Vector4 Vector4Cls::pssp() {
    return zxxz();
}

Vector4 Vector4Cls::pssq() {
    return zxxw();
}

Vector4 Vector4Cls::psts() {
    return zxyx();
}

Vector4 Vector4Cls::pstt() {
    return zxyy();
}

Vector4 Vector4Cls::pstp() {
    return zxyz();
}

Vector4 Vector4Cls::pstq() {
    return zxyw;
}

Vector4 Vector4Cls::psps() {
    return zxzx();
}

Vector4 Vector4Cls::pspt() {
    return zxzy();
}

Vector4 Vector4Cls::pspp() {
    return zxzz();
}

Vector4 Vector4Cls::pspq() {
    return zxzw();
}

Vector4 Vector4Cls::psqs() {
    return zxwx();
}

Vector4 Vector4Cls::psqt() {
    return zxwy;
}

Vector4 Vector4Cls::psqp() {
    return zxwz();
}

Vector4 Vector4Cls::psqq() {
    return zxww();
}

Vector4 Vector4Cls::ptss() {
    return zyxx();
}

Vector4 Vector4Cls::ptst() {
    return zyxy();
}

Vector4 Vector4Cls::ptsp() {
    return zyxz();
}

Vector4 Vector4Cls::ptsq() {
    return zyxw;
}

Vector4 Vector4Cls::ptts() {
    return zyyx();
}

Vector4 Vector4Cls::pttt() {
    return zyyy();
}

Vector4 Vector4Cls::pttp() {
    return zyyz();
}

Vector4 Vector4Cls::pttq() {
    return zyyw();
}

Vector4 Vector4Cls::ptps() {
    return zyzx();
}

Vector4 Vector4Cls::ptpt() {
    return zyzy();
}

Vector4 Vector4Cls::ptpp() {
    return zyzz();
}

Vector4 Vector4Cls::ptpq() {
    return zyzw();
}

Vector4 Vector4Cls::ptqs() {
    return zywx;
}

Vector4 Vector4Cls::ptqt() {
    return zywy();
}

Vector4 Vector4Cls::ptqp() {
    return zywz();
}

Vector4 Vector4Cls::ptqq() {
    return zyww();
}

Vector4 Vector4Cls::ppss() {
    return zzxx();
}

Vector4 Vector4Cls::ppst() {
    return zzxy();
}

Vector4 Vector4Cls::ppsp() {
    return zzxz();
}

Vector4 Vector4Cls::ppsq() {
    return zzxw();
}

Vector4 Vector4Cls::ppts() {
    return zzyx();
}

Vector4 Vector4Cls::pptt() {
    return zzyy();
}

Vector4 Vector4Cls::pptp() {
    return zzyz();
}

Vector4 Vector4Cls::pptq() {
    return zzyw();
}

Vector4 Vector4Cls::ppps() {
    return zzzx();
}

Vector4 Vector4Cls::pppt() {
    return zzzy();
}

Vector4 Vector4Cls::pppp() {
    return zzzz();
}

Vector4 Vector4Cls::pppq() {
    return zzzw();
}

Vector4 Vector4Cls::ppqs() {
    return zzwx();
}

Vector4 Vector4Cls::ppqt() {
    return zzwy();
}

Vector4 Vector4Cls::ppqp() {
    return zzwz();
}

Vector4 Vector4Cls::ppqq() {
    return zzww();
}

Vector4 Vector4Cls::pqss() {
    return zwxx();
}

Vector4 Vector4Cls::pqst() {
    return zwxy;
}

Vector4 Vector4Cls::pqsp() {
    return zwxz();
}

Vector4 Vector4Cls::pqsq() {
    return zwxw();
}

Vector4 Vector4Cls::pqts() {
    return zwyx;
}

Vector4 Vector4Cls::pqtt() {
    return zwyy();
}

Vector4 Vector4Cls::pqtp() {
    return zwyz();
}

Vector4 Vector4Cls::pqtq() {
    return zwyw();
}

Vector4 Vector4Cls::pqps() {
    return zwzx();
}

Vector4 Vector4Cls::pqpt() {
    return zwzy();
}

Vector4 Vector4Cls::pqpp() {
    return zwzz();
}

Vector4 Vector4Cls::pqpq() {
    return zwzw();
}

Vector4 Vector4Cls::pqqs() {
    return zwwx();
}

Vector4 Vector4Cls::pqqt() {
    return zwwy();
}

Vector4 Vector4Cls::pqqp() {
    return zwwz();
}

Vector4 Vector4Cls::pqqq() {
    return zwww();
}

Vector4 Vector4Cls::qsss() {
    return wxxx();
}

Vector4 Vector4Cls::qsst() {
    return wxxy();
}

Vector4 Vector4Cls::qssp() {
    return wxxz();
}

Vector4 Vector4Cls::qssq() {
    return wxxw();
}

Vector4 Vector4Cls::qsts() {
    return wxyx();
}

Vector4 Vector4Cls::qstt() {
    return wxyy();
}

Vector4 Vector4Cls::qstp() {
    return wxyz;
}

Vector4 Vector4Cls::qstq() {
    return wxyw();
}

Vector4 Vector4Cls::qsps() {
    return wxzx();
}

Vector4 Vector4Cls::qspt() {
    return wxzy;
}

Vector4 Vector4Cls::qspp() {
    return wxzz();
}

Vector4 Vector4Cls::qspq() {
    return wxzw();
}

Vector4 Vector4Cls::qsqs() {
    return wxwx();
}

Vector4 Vector4Cls::qsqt() {
    return wxwy();
}

Vector4 Vector4Cls::qsqp() {
    return wxwz();
}

Vector4 Vector4Cls::qsqq() {
    return wxww();
}

Vector4 Vector4Cls::qtss() {
    return wyxx();
}

Vector4 Vector4Cls::qtst() {
    return wyxy();
}

Vector4 Vector4Cls::qtsp() {
    return wyxz;
}

Vector4 Vector4Cls::qtsq() {
    return wyxw();
}

Vector4 Vector4Cls::qtts() {
    return wyyx();
}

Vector4 Vector4Cls::qttt() {
    return wyyy();
}

Vector4 Vector4Cls::qttp() {
    return wyyz();
}

Vector4 Vector4Cls::qttq() {
    return wyyw();
}

Vector4 Vector4Cls::qtps() {
    return wyzx;
}

Vector4 Vector4Cls::qtpt() {
    return wyzy();
}

Vector4 Vector4Cls::qtpp() {
    return wyzz();
}

Vector4 Vector4Cls::qtpq() {
    return wyzw();
}

Vector4 Vector4Cls::qtqs() {
    return wywx();
}

Vector4 Vector4Cls::qtqt() {
    return wywy();
}

Vector4 Vector4Cls::qtqp() {
    return wywz();
}

Vector4 Vector4Cls::qtqq() {
    return wyww();
}

Vector4 Vector4Cls::qpss() {
    return wzxx();
}

Vector4 Vector4Cls::qpst() {
    return wzxy;
}

Vector4 Vector4Cls::qpsp() {
    return wzxz();
}

Vector4 Vector4Cls::qpsq() {
    return wzxw();
}

Vector4 Vector4Cls::qpts() {
    return wzyx;
}

Vector4 Vector4Cls::qptt() {
    return wzyy();
}

Vector4 Vector4Cls::qptp() {
    return wzyz();
}

Vector4 Vector4Cls::qptq() {
    return wzyw();
}

Vector4 Vector4Cls::qpps() {
    return wzzx();
}

Vector4 Vector4Cls::qppt() {
    return wzzy();
}

Vector4 Vector4Cls::qppp() {
    return wzzz();
}

Vector4 Vector4Cls::qppq() {
    return wzzw();
}

Vector4 Vector4Cls::qpqs() {
    return wzwx();
}

Vector4 Vector4Cls::qpqt() {
    return wzwy();
}

Vector4 Vector4Cls::qpqp() {
    return wzwz();
}

Vector4 Vector4Cls::qpqq() {
    return wzww();
}

Vector4 Vector4Cls::qqss() {
    return wwxx();
}

Vector4 Vector4Cls::qqst() {
    return wwxy();
}

Vector4 Vector4Cls::qqsp() {
    return wwxz();
}

Vector4 Vector4Cls::qqsq() {
    return wwxw();
}

Vector4 Vector4Cls::qqts() {
    return wwyx();
}

Vector4 Vector4Cls::qqtt() {
    return wwyy();
}

Vector4 Vector4Cls::qqtp() {
    return wwyz();
}

Vector4 Vector4Cls::qqtq() {
    return wwyw();
}

Vector4 Vector4Cls::qqps() {
    return wwzx();
}

Vector4 Vector4Cls::qqpt() {
    return wwzy();
}

Vector4 Vector4Cls::qqpp() {
    return wwzz();
}

Vector4 Vector4Cls::qqpq() {
    return wwzw();
}

Vector4 Vector4Cls::qqqs() {
    return wwwx();
}

Vector4 Vector4Cls::qqqt() {
    return wwwy();
}

Vector4 Vector4Cls::qqqp() {
    return wwwz();
}

Vector4 Vector4Cls::qqqq() {
    return wwww();
}
