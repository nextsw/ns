#include "vector3.hpp"
Float64List Vector3Cls::storage() {
    return _v3storage;
}

void Vector3Cls::min(Vector3 a, Vector3 b, Vector3 result) {
    auto _c1 = result;_c1.x = auto _c2 = math->min(a->x, b->x);_c2.y = auto _c3 = math->min(a->y, b->y);_c3.z = math->min(a->z, b->z);_c3;_c2;_c1;
}

void Vector3Cls::max(Vector3 a, Vector3 b, Vector3 result) {
    auto _c1 = result;_c1.x = auto _c2 = math->max(a->x, b->x);_c2.y = auto _c3 = math->max(a->y, b->y);_c3.z = math->max(a->z, b->z);_c3;_c2;_c1;
}

void Vector3Cls::mix(Vector3 min, Vector3 max, double a, Vector3 result) {
    auto _c1 = result;_c1.x = auto _c2 = min->x + a * (max->x - min->x);_c2.y = auto _c3 = min->y + a * (max->y - min->y);_c3.z = min->z + a * (max->z - min->z);_c3;_c2;_c1;
}

Vector3Cls::Vector3Cls(double x, double y, double z) {
}

void Vector3Cls::array(List<double> array, int offset) {
    return _c1;
}

void Vector3Cls::zero()

void Vector3Cls::all(double value) {
    return _c1;
}

void Vector3Cls::copy(Vector3 other) {
    return _c1;
}

void Vector3Cls::fromBuffer(ByteBuffer buffer, int offset)

void Vector3Cls::random(Random rng) {
    auto _c1 = Vector3Cls->zero();_c1.copyFromArray(array, offset);auto _c1 = Vector3Cls->zero();_c1.splat(value);auto _c1 = Vector3Cls->zero();_c1.setFrom(other);rng |= math->make<RandomCls>();
    return make<Vector3Cls>(rng->nextDouble(), rng->nextDouble(), rng->nextDouble());
}

void Vector3Cls::setValues(double x, double y, double z) {
    _v3storage[0] = x;
    _v3storage[1] = y;
    _v3storage[2] = z;
}

void Vector3Cls::setZero() {
    _v3storage[2] = 0.0;
    _v3storage[1] = 0.0;
    _v3storage[0] = 0.0;
}

void Vector3Cls::setFrom(Vector3 other) {
    Unknown otherStorage = other->_v3storage;
    _v3storage[0] = otherStorage[0];
    _v3storage[1] = otherStorage[1];
    _v3storage[2] = otherStorage[2];
}

void Vector3Cls::splat(double arg) {
    _v3storage[2] = arg;
    _v3storage[1] = arg;
    _v3storage[0] = arg;
}

String Vector3Cls::toString() {
    return __sf("[%s,%s,%s]", storage()[0], storage()[1], storage()[2]);
}

bool Vector3Cls::==(Object other) {
    return (is<Vector3>(other)) && (_v3storage[0] == other->_v3storage[0]) && (_v3storage[1] == other->_v3storage[1]) && (_v3storage[2] == other->_v3storage[2]);
}

int Vector3Cls::hashCode() {
    return ObjectCls->hashAll(_v3storage);
}

Vector3 Vector3Cls::-() {
    return _c1;
}

Vector3 Vector3Cls::-(Vector3 other) {
    return _c1;
}

Vector3 Vector3Cls::+(Vector3 other) {
    return _c1;
}

Vector3 Vector3Cls::/(double scale) {
    return scaled(1.0 / scale);
}

Vector3 Vector3Cls::*(double scale) {
    return scaled(scale);
}

double Vector3Cls::[](int i) {
    return _v3storage[i];
}

void Vector3Cls::[]=(int i, double v) {
    auto _c1 = clone();_c1.negate();auto _c1 = clone();_c1.sub(other);auto _c1 = clone();_c1.add(other);_v3storage[i] = v;
}

void Vector3Cls::length(double value) {
    if (value == 0.0) {
        setZero();
    } else {
        auto l = length;
        if (l == 0.0) {
            return;
        }
        l = value / l;
        _v3storage[0] *= l;
        _v3storage[1] *= l;
        _v3storage[2] *= l;
    }
}

double Vector3Cls::length() {
    return math->sqrt(length2());
}

double Vector3Cls::length2() {
    double sum;
    sum = _v3storage[0] * _v3storage[0];
    sum += _v3storage[1] * _v3storage[1];
    sum += _v3storage[2] * _v3storage[2];
    return sum;
}

double Vector3Cls::normalize() {
    Unknown l = length;
    if (l == 0.0) {
        return 0.0;
    }
    Unknown d = 1.0 / l;
    _v3storage[0] *= d;
    _v3storage[1] *= d;
    _v3storage[2] *= d;
    return l;
}

double Vector3Cls::normalizeLength() {
    return normalize();
}

Vector3 Vector3Cls::normalized() {
    return _c1;
}

Vector3 Vector3Cls::normalizeInto(Vector3 out) {
    auto _c1 = Vector3Cls->copy(this);_c1.normalize();auto _c1 = out;_c1.auto _c2 = setFrom(this);_c2.normalize();_c2;_c1;
    return out;
}

double Vector3Cls::distanceTo(Vector3 arg) {
    return math->sqrt(distanceToSquared(arg));
}

double Vector3Cls::distanceToSquared(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    Unknown dx = _v3storage[0] - argStorage[0];
    Unknown dy = _v3storage[1] - argStorage[1];
    Unknown dz = _v3storage[2] - argStorage[2];
    return dx * dx + dy * dy + dz * dz;
}

double Vector3Cls::angleTo(Vector3 other) {
    Unknown otherStorage = other->_v3storage;
    if (_v3storage[0] == otherStorage[0] && _v3storage[1] == otherStorage[1] && _v3storage[2] == otherStorage[2]) {
        return 0.0;
    }
    Unknown d = dot(other) / (length * other->length);
    return math->acos(d->clamp(-1.0, 1.0));
}

double Vector3Cls::angleToSigned(Vector3 other, Vector3 normal) {
    Unknown angle = angleTo(other);
    Unknown c = cross(other);
    Unknown d = c->dot(normal);
    return  < 0.0? -angle : angle;
}

double Vector3Cls::dot(Vector3 other) {
    Unknown otherStorage = other->_v3storage;
    double sum;
    sum = _v3storage[0] * otherStorage[0];
    sum += _v3storage[1] * otherStorage[1];
    sum += _v3storage[2] * otherStorage[2];
    return sum;
}

void Vector3Cls::postmultiply(Matrix3 arg) {
    Unknown argStorage = arg->storage();
    Unknown v0 = _v3storage[0];
    Unknown v1 = _v3storage[1];
    Unknown v2 = _v3storage[2];
    _v3storage[0] = v0 * argStorage[0] + v1 * argStorage[1] + v2 * argStorage[2];
    _v3storage[1] = v0 * argStorage[3] + v1 * argStorage[4] + v2 * argStorage[5];
    _v3storage[2] = v0 * argStorage[6] + v1 * argStorage[7] + v2 * argStorage[8];
}

Vector3 Vector3Cls::cross(Vector3 other) {
    Unknown _x = _v3storage[0];
    Unknown _y = _v3storage[1];
    Unknown _z = _v3storage[2];
    Unknown otherStorage = other->_v3storage;
    Unknown ox = otherStorage[0];
    Unknown oy = otherStorage[1];
    Unknown oz = otherStorage[2];
    return make<Vector3Cls>(_y * oz - _z * oy, _z * ox - _x * oz, _x * oy - _y * ox);
}

Vector3 Vector3Cls::crossInto(Vector3 other, Vector3 out) {
    Unknown x = _v3storage[0];
    Unknown y = _v3storage[1];
    Unknown z = _v3storage[2];
    Unknown otherStorage = other->_v3storage;
    Unknown ox = otherStorage[0];
    Unknown oy = otherStorage[1];
    Unknown oz = otherStorage[2];
    Unknown outStorage = out->_v3storage;
    outStorage[0] = y * oz - z * oy;
    outStorage[1] = z * ox - x * oz;
    outStorage[2] = x * oy - y * ox;
    return out;
}

void Vector3Cls::reflect(Vector3 normal) {
    sub(normal->scaled(2.0 * normal->dot(this)));
}

Vector3 Vector3Cls::reflected(Vector3 normal) {
    return _c1;
}

void Vector3Cls::applyProjection(Matrix4 arg) {
    auto _c1 = clone();_c1.reflect(normal);Unknown argStorage = arg->storage();
    Unknown x = _v3storage[0];
    Unknown y = _v3storage[1];
    Unknown z = _v3storage[2];
    Unknown d = 1.0 / (argStorage[3] * x + argStorage[7] * y + argStorage[11] * z + argStorage[15]);
    _v3storage[0] = (argStorage[0] * x + argStorage[4] * y + argStorage[8] * z + argStorage[12]) * d;
    _v3storage[1] = (argStorage[1] * x + argStorage[5] * y + argStorage[9] * z + argStorage[13]) * d;
    _v3storage[2] = (argStorage[2] * x + argStorage[6] * y + argStorage[10] * z + argStorage[14]) * d;
}

void Vector3Cls::applyAxisAngle(Vector3 axis, double angle) {
    applyQuaternion(QuaternionCls->axisAngle(axis, angle));
}

void Vector3Cls::applyQuaternion(Quaternion arg) {
    Unknown argStorage = arg->_qStorage;
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

void Vector3Cls::applyMatrix3(Matrix3 arg) {
    Unknown argStorage = arg->storage();
    Unknown v0 = _v3storage[0];
    Unknown v1 = _v3storage[1];
    Unknown v2 = _v3storage[2];
    _v3storage[0] = argStorage[0] * v0 + argStorage[3] * v1 + argStorage[6] * v2;
    _v3storage[1] = argStorage[1] * v0 + argStorage[4] * v1 + argStorage[7] * v2;
    _v3storage[2] = argStorage[2] * v0 + argStorage[5] * v1 + argStorage[8] * v2;
}

void Vector3Cls::applyMatrix4(Matrix4 arg) {
    Unknown argStorage = arg->storage();
    Unknown v0 = _v3storage[0];
    Unknown v1 = _v3storage[1];
    Unknown v2 = _v3storage[2];
    _v3storage[0] = argStorage[0] * v0 + argStorage[4] * v1 + argStorage[8] * v2 + argStorage[12];
    _v3storage[1] = argStorage[1] * v0 + argStorage[5] * v1 + argStorage[9] * v2 + argStorage[13];
    _v3storage[2] = argStorage[2] * v0 + argStorage[6] * v1 + argStorage[10] * v2 + argStorage[14];
}

double Vector3Cls::relativeError(Vector3 correct) {
    Unknown correct_norm = correct->length;
    Unknown diff_norm = (this - correct)->length;
    return diff_norm / correct_norm;
}

double Vector3Cls::absoluteError(Vector3 correct) {
    return (this - correct)->length;
}

bool Vector3Cls::isInfinite() {
    auto is_infinite = false;
    is_infinite = is_infinite || _v3storage[0]->isInfinite;
    is_infinite = is_infinite || _v3storage[1]->isInfinite;
    is_infinite = is_infinite || _v3storage[2]->isInfinite;
    return is_infinite;
}

bool Vector3Cls::isNaN() {
    auto isNan = false;
    isNan = isNan || _v3storage[0]->isNaN;
    isNan = isNan || _v3storage[1]->isNaN;
    isNan = isNan || _v3storage[2]->isNaN;
    return isNan;
}

void Vector3Cls::add(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[0] = _v3storage[0] + argStorage[0];
    _v3storage[1] = _v3storage[1] + argStorage[1];
    _v3storage[2] = _v3storage[2] + argStorage[2];
}

void Vector3Cls::addScaled(Vector3 arg, double factor) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[0] = _v3storage[0] + argStorage[0] * factor;
    _v3storage[1] = _v3storage[1] + argStorage[1] * factor;
    _v3storage[2] = _v3storage[2] + argStorage[2] * factor;
}

void Vector3Cls::sub(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[0] = _v3storage[0] - argStorage[0];
    _v3storage[1] = _v3storage[1] - argStorage[1];
    _v3storage[2] = _v3storage[2] - argStorage[2];
}

void Vector3Cls::multiply(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[0] = _v3storage[0] * argStorage[0];
    _v3storage[1] = _v3storage[1] * argStorage[1];
    _v3storage[2] = _v3storage[2] * argStorage[2];
}

void Vector3Cls::divide(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[0] = _v3storage[0] / argStorage[0];
    _v3storage[1] = _v3storage[1] / argStorage[1];
    _v3storage[2] = _v3storage[2] / argStorage[2];
}

void Vector3Cls::scale(double arg) {
    _v3storage[2] = _v3storage[2] * arg;
    _v3storage[1] = _v3storage[1] * arg;
    _v3storage[0] = _v3storage[0] * arg;
}

Vector3 Vector3Cls::scaled(double arg) {
    return _c1;
}

void Vector3Cls::negate() {
    auto _c1 = clone();_c1.scale(arg);_v3storage[2] = -_v3storage[2];
    _v3storage[1] = -_v3storage[1];
    _v3storage[0] = -_v3storage[0];
}

void Vector3Cls::absolute() {
    _v3storage[0] = _v3storage[0]->abs();
    _v3storage[1] = _v3storage[1]->abs();
    _v3storage[2] = _v3storage[2]->abs();
}

void Vector3Cls::clamp(Vector3 min, Vector3 max) {
    Unknown minStorage = min->storage();
    Unknown maxStorage = max->storage();
    _v3storage[0] = _v3storage[0]->clamp(minStorage[0], maxStorage[0])->toDouble();
    _v3storage[1] = _v3storage[1]->clamp(minStorage[1], maxStorage[1])->toDouble();
    _v3storage[2] = _v3storage[2]->clamp(minStorage[2], maxStorage[2])->toDouble();
}

void Vector3Cls::clampScalar(double min, double max) {
    _v3storage[0] = _v3storage[0]->clamp(min, max)->toDouble();
    _v3storage[1] = _v3storage[1]->clamp(min, max)->toDouble();
    _v3storage[2] = _v3storage[2]->clamp(min, max)->toDouble();
}

void Vector3Cls::floor() {
    _v3storage[0] = _v3storage[0]->floorToDouble();
    _v3storage[1] = _v3storage[1]->floorToDouble();
    _v3storage[2] = _v3storage[2]->floorToDouble();
}

void Vector3Cls::ceil() {
    _v3storage[0] = _v3storage[0]->ceilToDouble();
    _v3storage[1] = _v3storage[1]->ceilToDouble();
    _v3storage[2] = _v3storage[2]->ceilToDouble();
}

void Vector3Cls::round() {
    _v3storage[0] = _v3storage[0]->roundToDouble();
    _v3storage[1] = _v3storage[1]->roundToDouble();
    _v3storage[2] = _v3storage[2]->roundToDouble();
}

void Vector3Cls::roundToZero() {
    _v3storage[0] = _v3storage[0] < 0.0? _v3storage[0]->ceilToDouble() : _v3storage[0]->floorToDouble();
    _v3storage[1] = _v3storage[1] < 0.0? _v3storage[1]->ceilToDouble() : _v3storage[1]->floorToDouble();
    _v3storage[2] = _v3storage[2] < 0.0? _v3storage[2]->ceilToDouble() : _v3storage[2]->floorToDouble();
}

Vector3 Vector3Cls::clone() {
    return Vector3Cls->copy(this);
}

Vector3 Vector3Cls::copyInto(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    argStorage[0] = _v3storage[0];
    argStorage[1] = _v3storage[1];
    argStorage[2] = _v3storage[2];
    return arg;
}

void Vector3Cls::copyIntoArray(List<double> array, int offset) {
    array[offset + 2] = _v3storage[2];
    array[offset + 1] = _v3storage[1];
    array[offset + 0] = _v3storage[0];
}

void Vector3Cls::copyFromArray(List<double> array, int offset) {
    _v3storage[2] = array[offset + 2];
    _v3storage[1] = array[offset + 1];
    _v3storage[0] = array[offset + 0];
}

void Vector3Cls::xy(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v3storage[0] = argStorage[0];
    _v3storage[1] = argStorage[1];
}

void Vector3Cls::xz(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v3storage[0] = argStorage[0];
    _v3storage[2] = argStorage[1];
}

void Vector3Cls::yx(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v3storage[1] = argStorage[0];
    _v3storage[0] = argStorage[1];
}

void Vector3Cls::yz(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v3storage[1] = argStorage[0];
    _v3storage[2] = argStorage[1];
}

void Vector3Cls::zx(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v3storage[2] = argStorage[0];
    _v3storage[0] = argStorage[1];
}

void Vector3Cls::zy(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v3storage[2] = argStorage[0];
    _v3storage[1] = argStorage[1];
}

void Vector3Cls::xyz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[0] = argStorage[0];
    _v3storage[1] = argStorage[1];
    _v3storage[2] = argStorage[2];
}

void Vector3Cls::xzy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[0] = argStorage[0];
    _v3storage[2] = argStorage[1];
    _v3storage[1] = argStorage[2];
}

void Vector3Cls::yxz(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[1] = argStorage[0];
    _v3storage[0] = argStorage[1];
    _v3storage[2] = argStorage[2];
}

void Vector3Cls::yzx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[1] = argStorage[0];
    _v3storage[2] = argStorage[1];
    _v3storage[0] = argStorage[2];
}

void Vector3Cls::zxy(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[2] = argStorage[0];
    _v3storage[0] = argStorage[1];
    _v3storage[1] = argStorage[2];
}

void Vector3Cls::zyx(Vector3 arg) {
    Unknown argStorage = arg->_v3storage;
    _v3storage[2] = argStorage[0];
    _v3storage[1] = argStorage[1];
    _v3storage[0] = argStorage[2];
}

void Vector3Cls::r(double arg) {
    return x = arg;
}

void Vector3Cls::g(double arg) {
    return y = arg;
}

void Vector3Cls::b(double arg) {
    return z = arg;
}

void Vector3Cls::s(double arg) {
    return x = arg;
}

void Vector3Cls::t(double arg) {
    return y = arg;
}

void Vector3Cls::p(double arg) {
    return z = arg;
}

void Vector3Cls::x(double arg) {
    return _v3storage[0] = arg;
}

void Vector3Cls::y(double arg) {
    return _v3storage[1] = arg;
}

void Vector3Cls::z(double arg) {
    return _v3storage[2] = arg;
}

void Vector3Cls::rg(Vector2 arg) {
    return xy = arg;
}

void Vector3Cls::rb(Vector2 arg) {
    return xz = arg;
}

void Vector3Cls::gr(Vector2 arg) {
    return yx = arg;
}

void Vector3Cls::gb(Vector2 arg) {
    return yz = arg;
}

void Vector3Cls::br(Vector2 arg) {
    return zx = arg;
}

void Vector3Cls::bg(Vector2 arg) {
    return zy = arg;
}

void Vector3Cls::rgb(Vector3 arg) {
    return xyz = arg;
}

void Vector3Cls::rbg(Vector3 arg) {
    return xzy = arg;
}

void Vector3Cls::grb(Vector3 arg) {
    return yxz = arg;
}

void Vector3Cls::gbr(Vector3 arg) {
    return yzx = arg;
}

void Vector3Cls::brg(Vector3 arg) {
    return zxy = arg;
}

void Vector3Cls::bgr(Vector3 arg) {
    return zyx = arg;
}

void Vector3Cls::st(Vector2 arg) {
    return xy = arg;
}

void Vector3Cls::sp(Vector2 arg) {
    return xz = arg;
}

void Vector3Cls::ts(Vector2 arg) {
    return yx = arg;
}

void Vector3Cls::tp(Vector2 arg) {
    return yz = arg;
}

void Vector3Cls::ps(Vector2 arg) {
    return zx = arg;
}

void Vector3Cls::pt(Vector2 arg) {
    return zy = arg;
}

void Vector3Cls::stp(Vector3 arg) {
    return xyz = arg;
}

void Vector3Cls::spt(Vector3 arg) {
    return xzy = arg;
}

void Vector3Cls::tsp(Vector3 arg) {
    return yxz = arg;
}

void Vector3Cls::tps(Vector3 arg) {
    return yzx = arg;
}

void Vector3Cls::pst(Vector3 arg) {
    return zxy = arg;
}

void Vector3Cls::pts(Vector3 arg) {
    return zyx = arg;
}

Vector2 Vector3Cls::xx() {
    return make<Vector2Cls>(_v3storage[0], _v3storage[0]);
}

Vector2 Vector3Cls::xy() {
    return make<Vector2Cls>(_v3storage[0], _v3storage[1]);
}

Vector2 Vector3Cls::xz() {
    return make<Vector2Cls>(_v3storage[0], _v3storage[2]);
}

Vector2 Vector3Cls::yx() {
    return make<Vector2Cls>(_v3storage[1], _v3storage[0]);
}

Vector2 Vector3Cls::yy() {
    return make<Vector2Cls>(_v3storage[1], _v3storage[1]);
}

Vector2 Vector3Cls::yz() {
    return make<Vector2Cls>(_v3storage[1], _v3storage[2]);
}

Vector2 Vector3Cls::zx() {
    return make<Vector2Cls>(_v3storage[2], _v3storage[0]);
}

Vector2 Vector3Cls::zy() {
    return make<Vector2Cls>(_v3storage[2], _v3storage[1]);
}

Vector2 Vector3Cls::zz() {
    return make<Vector2Cls>(_v3storage[2], _v3storage[2]);
}

Vector3 Vector3Cls::xxx() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector3 Vector3Cls::xxy() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector3 Vector3Cls::xxz() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector3 Vector3Cls::xyx() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector3 Vector3Cls::xyy() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector3 Vector3Cls::xyz() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector3 Vector3Cls::xzx() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector3 Vector3Cls::xzy() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector3 Vector3Cls::xzz() {
    return make<Vector3Cls>(_v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector3 Vector3Cls::yxx() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector3 Vector3Cls::yxy() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector3 Vector3Cls::yxz() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector3 Vector3Cls::yyx() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector3 Vector3Cls::yyy() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector3 Vector3Cls::yyz() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector3 Vector3Cls::yzx() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector3 Vector3Cls::yzy() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector3 Vector3Cls::yzz() {
    return make<Vector3Cls>(_v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector3 Vector3Cls::zxx() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector3 Vector3Cls::zxy() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector3 Vector3Cls::zxz() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector3 Vector3Cls::zyx() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector3 Vector3Cls::zyy() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector3 Vector3Cls::zyz() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector3 Vector3Cls::zzx() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector3 Vector3Cls::zzy() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector3 Vector3Cls::zzz() {
    return make<Vector3Cls>(_v3storage[2], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::xxxx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::xxxy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::xxxz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::xxyx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::xxyy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::xxyz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::xxzx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::xxzy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::xxzz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::xyxx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::xyxy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::xyxz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::xyyx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::xyyy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::xyyz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::xyzx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::xyzy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::xyzz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::xzxx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::xzxy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::xzxz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::xzyx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::xzyy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::xzyz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::xzzx() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::xzzy() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::xzzz() {
    return make<Vector4Cls>(_v3storage[0], _v3storage[2], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::yxxx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::yxxy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::yxxz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::yxyx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::yxyy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::yxyz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::yxzx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::yxzy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::yxzz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::yyxx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::yyxy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::yyxz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::yyyx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::yyyy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::yyyz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::yyzx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::yyzy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::yyzz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::yzxx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::yzxy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::yzxz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::yzyx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::yzyy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::yzyz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::yzzx() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::yzzy() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::yzzz() {
    return make<Vector4Cls>(_v3storage[1], _v3storage[2], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::zxxx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::zxxy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::zxxz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::zxyx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::zxyy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::zxyz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::zxzx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::zxzy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::zxzz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[0], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::zyxx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::zyxy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::zyxz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::zyyx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::zyyy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::zyyz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::zyzx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::zyzy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::zyzz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[1], _v3storage[2], _v3storage[2]);
}

Vector4 Vector3Cls::zzxx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[0], _v3storage[0]);
}

Vector4 Vector3Cls::zzxy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[0], _v3storage[1]);
}

Vector4 Vector3Cls::zzxz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[0], _v3storage[2]);
}

Vector4 Vector3Cls::zzyx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[1], _v3storage[0]);
}

Vector4 Vector3Cls::zzyy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[1], _v3storage[1]);
}

Vector4 Vector3Cls::zzyz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[1], _v3storage[2]);
}

Vector4 Vector3Cls::zzzx() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[2], _v3storage[0]);
}

Vector4 Vector3Cls::zzzy() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[2], _v3storage[1]);
}

Vector4 Vector3Cls::zzzz() {
    return make<Vector4Cls>(_v3storage[2], _v3storage[2], _v3storage[2], _v3storage[2]);
}

double Vector3Cls::r() {
    return x;
}

double Vector3Cls::g() {
    return y;
}

double Vector3Cls::b() {
    return z;
}

double Vector3Cls::s() {
    return x;
}

double Vector3Cls::t() {
    return y;
}

double Vector3Cls::p() {
    return z;
}

double Vector3Cls::x() {
    return _v3storage[0];
}

double Vector3Cls::y() {
    return _v3storage[1];
}

double Vector3Cls::z() {
    return _v3storage[2];
}

Vector2 Vector3Cls::rr() {
    return xx();
}

Vector2 Vector3Cls::rg() {
    return xy;
}

Vector2 Vector3Cls::rb() {
    return xz;
}

Vector2 Vector3Cls::gr() {
    return yx;
}

Vector2 Vector3Cls::gg() {
    return yy();
}

Vector2 Vector3Cls::gb() {
    return yz;
}

Vector2 Vector3Cls::br() {
    return zx;
}

Vector2 Vector3Cls::bg() {
    return zy;
}

Vector2 Vector3Cls::bb() {
    return zz();
}

Vector3 Vector3Cls::rrr() {
    return xxx();
}

Vector3 Vector3Cls::rrg() {
    return xxy();
}

Vector3 Vector3Cls::rrb() {
    return xxz();
}

Vector3 Vector3Cls::rgr() {
    return xzx();
}

Vector3 Vector3Cls::rgg() {
    return xyy();
}

Vector3 Vector3Cls::rgb() {
    return xyz;
}

Vector3 Vector3Cls::rbr() {
    return xzx();
}

Vector3 Vector3Cls::rbg() {
    return xzy;
}

Vector3 Vector3Cls::rbb() {
    return xzz();
}

Vector3 Vector3Cls::grr() {
    return yxx();
}

Vector3 Vector3Cls::grg() {
    return yxy();
}

Vector3 Vector3Cls::grb() {
    return yxz;
}

Vector3 Vector3Cls::ggr() {
    return yyx();
}

Vector3 Vector3Cls::ggg() {
    return yyy();
}

Vector3 Vector3Cls::ggb() {
    return yyz();
}

Vector3 Vector3Cls::gbr() {
    return yxz;
}

Vector3 Vector3Cls::gbg() {
    return yzy();
}

Vector3 Vector3Cls::gbb() {
    return yzz();
}

Vector3 Vector3Cls::brr() {
    return zxx();
}

Vector3 Vector3Cls::brg() {
    return zxy;
}

Vector3 Vector3Cls::brb() {
    return zxz();
}

Vector3 Vector3Cls::bgr() {
    return zyx;
}

Vector3 Vector3Cls::bgg() {
    return zyy();
}

Vector3 Vector3Cls::bgb() {
    return zyz();
}

Vector3 Vector3Cls::bbr() {
    return zzx();
}

Vector3 Vector3Cls::bbg() {
    return zzy();
}

Vector3 Vector3Cls::bbb() {
    return zzz();
}

Vector4 Vector3Cls::rrrr() {
    return xxxx();
}

Vector4 Vector3Cls::rrrg() {
    return xxxy();
}

Vector4 Vector3Cls::rrrb() {
    return xxxz();
}

Vector4 Vector3Cls::rrgr() {
    return xxyx();
}

Vector4 Vector3Cls::rrgg() {
    return xxyy();
}

Vector4 Vector3Cls::rrgb() {
    return xxyz();
}

Vector4 Vector3Cls::rrbr() {
    return xxzx();
}

Vector4 Vector3Cls::rrbg() {
    return xxzy();
}

Vector4 Vector3Cls::rrbb() {
    return xxzz();
}

Vector4 Vector3Cls::rgrr() {
    return xyxx();
}

Vector4 Vector3Cls::rgrg() {
    return xyxy();
}

Vector4 Vector3Cls::rgrb() {
    return xyxz();
}

Vector4 Vector3Cls::rggr() {
    return xyyx();
}

Vector4 Vector3Cls::rggg() {
    return xyyy();
}

Vector4 Vector3Cls::rggb() {
    return xyyz();
}

Vector4 Vector3Cls::rgbr() {
    return xyzx();
}

Vector4 Vector3Cls::rgbg() {
    return xyzy();
}

Vector4 Vector3Cls::rgbb() {
    return xyzz();
}

Vector4 Vector3Cls::rbrr() {
    return xzxx();
}

Vector4 Vector3Cls::rbrg() {
    return xzxy();
}

Vector4 Vector3Cls::rbrb() {
    return xzxz();
}

Vector4 Vector3Cls::rbgr() {
    return xzyx();
}

Vector4 Vector3Cls::rbgg() {
    return xzyy();
}

Vector4 Vector3Cls::rbgb() {
    return xzyz();
}

Vector4 Vector3Cls::rbbr() {
    return xzzx();
}

Vector4 Vector3Cls::rbbg() {
    return xzzy();
}

Vector4 Vector3Cls::rbbb() {
    return xzzz();
}

Vector4 Vector3Cls::grrr() {
    return yxxx();
}

Vector4 Vector3Cls::grrg() {
    return yxxy();
}

Vector4 Vector3Cls::grrb() {
    return yxxz();
}

Vector4 Vector3Cls::grgr() {
    return yxyx();
}

Vector4 Vector3Cls::grgg() {
    return yxyy();
}

Vector4 Vector3Cls::grgb() {
    return yxyz();
}

Vector4 Vector3Cls::grbr() {
    return yxzx();
}

Vector4 Vector3Cls::grbg() {
    return yxzy();
}

Vector4 Vector3Cls::grbb() {
    return yxzz();
}

Vector4 Vector3Cls::ggrr() {
    return yyxx();
}

Vector4 Vector3Cls::ggrg() {
    return yyxy();
}

Vector4 Vector3Cls::ggrb() {
    return yyxz();
}

Vector4 Vector3Cls::gggr() {
    return yyyx();
}

Vector4 Vector3Cls::gggg() {
    return yyyy();
}

Vector4 Vector3Cls::gggb() {
    return yyyz();
}

Vector4 Vector3Cls::ggbr() {
    return yyzx();
}

Vector4 Vector3Cls::ggbg() {
    return yyzy();
}

Vector4 Vector3Cls::ggbb() {
    return yyzz();
}

Vector4 Vector3Cls::gbrr() {
    return yzxx();
}

Vector4 Vector3Cls::gbrg() {
    return yzxy();
}

Vector4 Vector3Cls::gbrb() {
    return yzxz();
}

Vector4 Vector3Cls::gbgr() {
    return yzyx();
}

Vector4 Vector3Cls::gbgg() {
    return yzyy();
}

Vector4 Vector3Cls::gbgb() {
    return yzyz();
}

Vector4 Vector3Cls::gbbr() {
    return yzzx();
}

Vector4 Vector3Cls::gbbg() {
    return yzzy();
}

Vector4 Vector3Cls::gbbb() {
    return yzzz();
}

Vector4 Vector3Cls::brrr() {
    return zxxx();
}

Vector4 Vector3Cls::brrg() {
    return zxxy();
}

Vector4 Vector3Cls::brrb() {
    return zxxz();
}

Vector4 Vector3Cls::brgr() {
    return zxyx();
}

Vector4 Vector3Cls::brgg() {
    return zxyy();
}

Vector4 Vector3Cls::brgb() {
    return zxyz();
}

Vector4 Vector3Cls::brbr() {
    return zxzx();
}

Vector4 Vector3Cls::brbg() {
    return zxzy();
}

Vector4 Vector3Cls::brbb() {
    return zxzz();
}

Vector4 Vector3Cls::bgrr() {
    return zyxx();
}

Vector4 Vector3Cls::bgrg() {
    return zyxy();
}

Vector4 Vector3Cls::bgrb() {
    return zyxz();
}

Vector4 Vector3Cls::bggr() {
    return zyyx();
}

Vector4 Vector3Cls::bggg() {
    return zyyy();
}

Vector4 Vector3Cls::bggb() {
    return zyyz();
}

Vector4 Vector3Cls::bgbr() {
    return zyzx();
}

Vector4 Vector3Cls::bgbg() {
    return zyzy();
}

Vector4 Vector3Cls::bgbb() {
    return zyzz();
}

Vector4 Vector3Cls::bbrr() {
    return zzxx();
}

Vector4 Vector3Cls::bbrg() {
    return zzxy();
}

Vector4 Vector3Cls::bbrb() {
    return zzxz();
}

Vector4 Vector3Cls::bbgr() {
    return zzyx();
}

Vector4 Vector3Cls::bbgg() {
    return zzyy();
}

Vector4 Vector3Cls::bbgb() {
    return zzyz();
}

Vector4 Vector3Cls::bbbr() {
    return zzzx();
}

Vector4 Vector3Cls::bbbg() {
    return zzzy();
}

Vector4 Vector3Cls::bbbb() {
    return zzzz();
}

Vector2 Vector3Cls::ss() {
    return xx();
}

Vector2 Vector3Cls::st() {
    return xy;
}

Vector2 Vector3Cls::sp() {
    return xz;
}

Vector2 Vector3Cls::ts() {
    return yx;
}

Vector2 Vector3Cls::tt() {
    return yy();
}

Vector2 Vector3Cls::tp() {
    return yz;
}

Vector2 Vector3Cls::ps() {
    return zx;
}

Vector2 Vector3Cls::pt() {
    return zy;
}

Vector2 Vector3Cls::pp() {
    return zz();
}

Vector3 Vector3Cls::sss() {
    return xxx();
}

Vector3 Vector3Cls::sst() {
    return xxy();
}

Vector3 Vector3Cls::ssp() {
    return xxz();
}

Vector3 Vector3Cls::sts() {
    return xyx();
}

Vector3 Vector3Cls::stt() {
    return xyy();
}

Vector3 Vector3Cls::stp() {
    return xyz;
}

Vector3 Vector3Cls::sps() {
    return xzx();
}

Vector3 Vector3Cls::spt() {
    return xzy;
}

Vector3 Vector3Cls::spp() {
    return xzz();
}

Vector3 Vector3Cls::tss() {
    return yxx();
}

Vector3 Vector3Cls::tst() {
    return yxy();
}

Vector3 Vector3Cls::tsp() {
    return yxz;
}

Vector3 Vector3Cls::tts() {
    return yyx();
}

Vector3 Vector3Cls::ttt() {
    return yyy();
}

Vector3 Vector3Cls::ttp() {
    return yyz();
}

Vector3 Vector3Cls::tps() {
    return yzx;
}

Vector3 Vector3Cls::tpt() {
    return yzy();
}

Vector3 Vector3Cls::tpp() {
    return yzz();
}

Vector3 Vector3Cls::pss() {
    return zxx();
}

Vector3 Vector3Cls::pst() {
    return zxy;
}

Vector3 Vector3Cls::psp() {
    return zxz();
}

Vector3 Vector3Cls::pts() {
    return zyx;
}

Vector3 Vector3Cls::ptt() {
    return zyy();
}

Vector3 Vector3Cls::ptp() {
    return zyz();
}

Vector3 Vector3Cls::pps() {
    return zzx();
}

Vector3 Vector3Cls::ppt() {
    return zzy();
}

Vector3 Vector3Cls::ppp() {
    return zzz();
}

Vector4 Vector3Cls::ssss() {
    return xxxx();
}

Vector4 Vector3Cls::ssst() {
    return xxxy();
}

Vector4 Vector3Cls::sssp() {
    return xxxz();
}

Vector4 Vector3Cls::ssts() {
    return xxyx();
}

Vector4 Vector3Cls::sstt() {
    return xxyy();
}

Vector4 Vector3Cls::sstp() {
    return xxyz();
}

Vector4 Vector3Cls::ssps() {
    return xxzx();
}

Vector4 Vector3Cls::sspt() {
    return xxzy();
}

Vector4 Vector3Cls::sspp() {
    return xxzz();
}

Vector4 Vector3Cls::stss() {
    return xyxx();
}

Vector4 Vector3Cls::stst() {
    return xyxy();
}

Vector4 Vector3Cls::stsp() {
    return xyxz();
}

Vector4 Vector3Cls::stts() {
    return xyyx();
}

Vector4 Vector3Cls::sttt() {
    return xyyy();
}

Vector4 Vector3Cls::sttp() {
    return xyyz();
}

Vector4 Vector3Cls::stps() {
    return xyzx();
}

Vector4 Vector3Cls::stpt() {
    return xyzy();
}

Vector4 Vector3Cls::stpp() {
    return xyzz();
}

Vector4 Vector3Cls::spss() {
    return xzxx();
}

Vector4 Vector3Cls::spst() {
    return xzxy();
}

Vector4 Vector3Cls::spsp() {
    return xzxz();
}

Vector4 Vector3Cls::spts() {
    return xzyx();
}

Vector4 Vector3Cls::sptt() {
    return xzyy();
}

Vector4 Vector3Cls::sptp() {
    return xzyz();
}

Vector4 Vector3Cls::spps() {
    return xzzx();
}

Vector4 Vector3Cls::sppt() {
    return xzzy();
}

Vector4 Vector3Cls::sppp() {
    return xzzz();
}

Vector4 Vector3Cls::tsss() {
    return yxxx();
}

Vector4 Vector3Cls::tsst() {
    return yxxy();
}

Vector4 Vector3Cls::tssp() {
    return yxxz();
}

Vector4 Vector3Cls::tsts() {
    return yxyx();
}

Vector4 Vector3Cls::tstt() {
    return yxyy();
}

Vector4 Vector3Cls::tstp() {
    return yxyz();
}

Vector4 Vector3Cls::tsps() {
    return yxzx();
}

Vector4 Vector3Cls::tspt() {
    return yxzy();
}

Vector4 Vector3Cls::tspp() {
    return yxzz();
}

Vector4 Vector3Cls::ttss() {
    return yyxx();
}

Vector4 Vector3Cls::ttst() {
    return yyxy();
}

Vector4 Vector3Cls::ttsp() {
    return yyxz();
}

Vector4 Vector3Cls::ttts() {
    return yyyx();
}

Vector4 Vector3Cls::tttt() {
    return yyyy();
}

Vector4 Vector3Cls::tttp() {
    return yyyz();
}

Vector4 Vector3Cls::ttps() {
    return yyzx();
}

Vector4 Vector3Cls::ttpt() {
    return yyzy();
}

Vector4 Vector3Cls::ttpp() {
    return yyzz();
}

Vector4 Vector3Cls::tpss() {
    return yzxx();
}

Vector4 Vector3Cls::tpst() {
    return yzxy();
}

Vector4 Vector3Cls::tpsp() {
    return yzxz();
}

Vector4 Vector3Cls::tpts() {
    return yzyx();
}

Vector4 Vector3Cls::tptt() {
    return yzyy();
}

Vector4 Vector3Cls::tptp() {
    return yzyz();
}

Vector4 Vector3Cls::tpps() {
    return yzzx();
}

Vector4 Vector3Cls::tppt() {
    return yzzy();
}

Vector4 Vector3Cls::tppp() {
    return yzzz();
}

Vector4 Vector3Cls::psss() {
    return zxxx();
}

Vector4 Vector3Cls::psst() {
    return zxxy();
}

Vector4 Vector3Cls::pssp() {
    return zxxz();
}

Vector4 Vector3Cls::psts() {
    return zxyx();
}

Vector4 Vector3Cls::pstt() {
    return zxyy();
}

Vector4 Vector3Cls::pstp() {
    return zxyz();
}

Vector4 Vector3Cls::psps() {
    return zxzx();
}

Vector4 Vector3Cls::pspt() {
    return zxzy();
}

Vector4 Vector3Cls::pspp() {
    return zxzz();
}

Vector4 Vector3Cls::ptss() {
    return zyxx();
}

Vector4 Vector3Cls::ptst() {
    return zyxy();
}

Vector4 Vector3Cls::ptsp() {
    return zyxz();
}

Vector4 Vector3Cls::ptts() {
    return zyyx();
}

Vector4 Vector3Cls::pttt() {
    return zyyy();
}

Vector4 Vector3Cls::pttp() {
    return zyyz();
}

Vector4 Vector3Cls::ptps() {
    return zyzx();
}

Vector4 Vector3Cls::ptpt() {
    return zyzy();
}

Vector4 Vector3Cls::ptpp() {
    return zyzz();
}

Vector4 Vector3Cls::ppss() {
    return zzxx();
}

Vector4 Vector3Cls::ppst() {
    return zzxy();
}

Vector4 Vector3Cls::ppsp() {
    return zzxz();
}

Vector4 Vector3Cls::ppts() {
    return zzyx();
}

Vector4 Vector3Cls::pptt() {
    return zzyy();
}

Vector4 Vector3Cls::pptp() {
    return zzyz();
}

Vector4 Vector3Cls::ppps() {
    return zzzx();
}

Vector4 Vector3Cls::pppt() {
    return zzzy();
}

Vector4 Vector3Cls::pppp() {
    return zzzz();
}
