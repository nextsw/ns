#include "vector2.hpp"
Float64List Vector2Cls::storage() {
    return _v2storage;
}

void Vector2Cls::min(Vector2 a, Vector2 b, Vector2 result) {
    auto _c1 = result;_c1.x = auto _c2 = math->min(a->x, b->x);_c2.y = math->min(a->y, b->y);_c2;_c1;
}

void Vector2Cls::max(Vector2 a, Vector2 b, Vector2 result) {
    auto _c1 = result;_c1.x = auto _c2 = math->max(a->x, b->x);_c2.y = math->max(a->y, b->y);_c2;_c1;
}

void Vector2Cls::mix(Vector2 min, Vector2 max, double a, Vector2 result) {
    auto _c1 = result;_c1.x = auto _c2 = min->x + a * (max->x - min->x);_c2.y = min->y + a * (max->y - min->y);_c2;_c1;
}

Vector2Cls::Vector2Cls(double x, double y) {
}

void Vector2Cls::array(List<double> array, int offset) {
    return _c1;
}

void Vector2Cls::zero()

void Vector2Cls::all(double value) {
    return _c1;
}

void Vector2Cls::copy(Vector2 other) {
    return _c1;
}

void Vector2Cls::fromBuffer(ByteBuffer buffer, int offset)

void Vector2Cls::random(Random rng) {
    auto _c1 = Vector2Cls->zero();_c1.copyFromArray(array, offset);auto _c1 = Vector2Cls->zero();_c1.splat(value);auto _c1 = Vector2Cls->zero();_c1.setFrom(other);rng |= math->make<RandomCls>();
    return make<Vector2Cls>(rng->nextDouble(), rng->nextDouble());
}

void Vector2Cls::setValues(double x_, double y_) {
    _v2storage[0] = x_;
    _v2storage[1] = y_;
}

void Vector2Cls::setZero() {
    _v2storage[0] = 0.0;
    _v2storage[1] = 0.0;
}

void Vector2Cls::setFrom(Vector2 other) {
    Unknown otherStorage = other->_v2storage;
    _v2storage[1] = otherStorage[1];
    _v2storage[0] = otherStorage[0];
}

void Vector2Cls::splat(double arg) {
    _v2storage[0] = arg;
    _v2storage[1] = arg;
}

String Vector2Cls::toString() {
    return __s("[%s$%s;");
}

bool Vector2Cls::==(Object other) {
    return (is<Vector2>(other)) && (_v2storage[0] == other->_v2storage[0]) && (_v2storage[1] == other->_v2storage[1]);
}

int Vector2Cls::hashCode() {
    return ObjectCls->hashAll(_v2storage);
}

Vector2 Vector2Cls::-() {
    return _c1;
}

Vector2 Vector2Cls::-(Vector2 other) {
    return _c1;
}

Vector2 Vector2Cls::+(Vector2 other) {
    return _c1;
}

Vector2 Vector2Cls::/(double scale) {
    return _c1;
}

Vector2 Vector2Cls::*(double scale) {
    return _c1;
}

double Vector2Cls::[](int i) {
    return _v2storage[i];
}

void Vector2Cls::[]=(int i, double v) {
    auto _c1 = clone();_c1.negate();auto _c1 = clone();_c1.sub(other);auto _c1 = clone();_c1.add(other);auto _c1 = clone();_c1.scale(1.0 / scale);auto _c1 = clone();_c1.scale(scale);_v2storage[i] = v;
}

void Vector2Cls::length(double value) {
    if (value == 0.0) {
        setZero();
    } else {
        auto l = length;
        if (l == 0.0) {
            return;
        }
        l = value / l;
        _v2storage[0] *= l;
        _v2storage[1] *= l;
    }
}

double Vector2Cls::length() {
    return math->sqrt(length2());
}

double Vector2Cls::length2() {
    double sum;
    sum = _v2storage[0] * _v2storage[0];
    sum += _v2storage[1] * _v2storage[1];
    return sum;
}

double Vector2Cls::normalize() {
    Unknown l = length;
    if (l == 0.0) {
        return 0.0;
    }
    Unknown d = 1.0 / l;
    _v2storage[0] *= d;
    _v2storage[1] *= d;
    return l;
}

double Vector2Cls::normalizeLength() {
    return normalize();
}

Vector2 Vector2Cls::normalized() {
    return _c1;
}

Vector2 Vector2Cls::normalizeInto(Vector2 out) {
    auto _c1 = clone();_c1.normalize();auto _c1 = out;_c1.auto _c2 = setFrom(this);_c2.normalize();_c2;_c1;
    return out;
}

double Vector2Cls::distanceTo(Vector2 arg) {
    return math->sqrt(distanceToSquared(arg));
}

double Vector2Cls::distanceToSquared(Vector2 arg) {
    Unknown dx = x - arg->x;
    Unknown dy = y - arg->y;
    return dx * dx + dy * dy;
}

double Vector2Cls::angleTo(Vector2 other) {
    Unknown otherStorage = other->_v2storage;
    if (_v2storage[0] == otherStorage[0] && _v2storage[1] == otherStorage[1]) {
        return 0.0;
    }
    Unknown d = dot(other) / (length * other->length);
    return math->acos(d->clamp(-1.0, 1.0));
}

double Vector2Cls::angleToSigned(Vector2 other) {
    Unknown otherStorage = other->_v2storage;
    if (_v2storage[0] == otherStorage[0] && _v2storage[1] == otherStorage[1]) {
        return 0.0;
    }
    Unknown s = cross(other);
    Unknown c = dot(other);
    return math->atan2(s, c);
}

double Vector2Cls::dot(Vector2 other) {
    Unknown otherStorage = other->_v2storage;
    double sum;
    sum = _v2storage[0] * otherStorage[0];
    sum += _v2storage[1] * otherStorage[1];
    return sum;
}

void Vector2Cls::postmultiply(Matrix2 arg) {
    Unknown argStorage = arg->storage();
    Unknown v0 = _v2storage[0];
    Unknown v1 = _v2storage[1];
    _v2storage[0] = v0 * argStorage[0] + v1 * argStorage[1];
    _v2storage[1] = v0 * argStorage[2] + v1 * argStorage[3];
}

double Vector2Cls::cross(Vector2 other) {
    Unknown otherStorage = other->_v2storage;
    return _v2storage[0] * otherStorage[1] - _v2storage[1] * otherStorage[0];
}

Vector2 Vector2Cls::scaleOrthogonalInto(double scale, Vector2 out) {
    out->setValues(-scale * _v2storage[1], scale * _v2storage[0]);
    return out;
}

void Vector2Cls::reflect(Vector2 normal) {
    sub(normal->scaled(2.0 * normal->dot(this)));
}

Vector2 Vector2Cls::reflected(Vector2 normal) {
    return _c1;
}

double Vector2Cls::relativeError(Vector2 correct) {
    auto _c1 = clone();_c1.reflect(normal);Unknown correct_norm = correct->length;
    Unknown diff_norm = (this - correct)->length;
    return diff_norm / correct_norm;
}

double Vector2Cls::absoluteError(Vector2 correct) {
    return (this - correct)->length;
}

bool Vector2Cls::isInfinite() {
    auto is_infinite = false;
    is_infinite = is_infinite || _v2storage[0]->isInfinite;
    is_infinite = is_infinite || _v2storage[1]->isInfinite;
    return is_infinite;
}

bool Vector2Cls::isNaN() {
    auto is_nan = false;
    is_nan = is_nan || _v2storage[0]->isNaN;
    is_nan = is_nan || _v2storage[1]->isNaN;
    return is_nan;
}

void Vector2Cls::add(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v2storage[0] = _v2storage[0] + argStorage[0];
    _v2storage[1] = _v2storage[1] + argStorage[1];
}

void Vector2Cls::addScaled(Vector2 arg, double factor) {
    Unknown argStorage = arg->_v2storage;
    _v2storage[0] = _v2storage[0] + argStorage[0] * factor;
    _v2storage[1] = _v2storage[1] + argStorage[1] * factor;
}

void Vector2Cls::sub(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v2storage[0] = _v2storage[0] - argStorage[0];
    _v2storage[1] = _v2storage[1] - argStorage[1];
}

void Vector2Cls::multiply(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v2storage[0] = _v2storage[0] * argStorage[0];
    _v2storage[1] = _v2storage[1] * argStorage[1];
}

void Vector2Cls::divide(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v2storage[0] = _v2storage[0] / argStorage[0];
    _v2storage[1] = _v2storage[1] / argStorage[1];
}

void Vector2Cls::scale(double arg) {
    _v2storage[1] = _v2storage[1] * arg;
    _v2storage[0] = _v2storage[0] * arg;
}

Vector2 Vector2Cls::scaled(double arg) {
    return _c1;
}

void Vector2Cls::negate() {
    auto _c1 = clone();_c1.scale(arg);_v2storage[1] = -_v2storage[1];
    _v2storage[0] = -_v2storage[0];
}

void Vector2Cls::absolute() {
    _v2storage[1] = _v2storage[1]->abs();
    _v2storage[0] = _v2storage[0]->abs();
}

void Vector2Cls::clamp(Vector2 min, Vector2 max) {
    Unknown minStorage = min->storage();
    Unknown maxStorage = max->storage();
    _v2storage[0] = _v2storage[0]->clamp(minStorage[0], maxStorage[0])->toDouble();
    _v2storage[1] = _v2storage[1]->clamp(minStorage[1], maxStorage[1])->toDouble();
}

void Vector2Cls::clampScalar(double min, double max) {
    _v2storage[0] = _v2storage[0]->clamp(min, max)->toDouble();
    _v2storage[1] = _v2storage[1]->clamp(min, max)->toDouble();
}

void Vector2Cls::floor() {
    _v2storage[0] = _v2storage[0]->floorToDouble();
    _v2storage[1] = _v2storage[1]->floorToDouble();
}

void Vector2Cls::ceil() {
    _v2storage[0] = _v2storage[0]->ceilToDouble();
    _v2storage[1] = _v2storage[1]->ceilToDouble();
}

void Vector2Cls::round() {
    _v2storage[0] = _v2storage[0]->roundToDouble();
    _v2storage[1] = _v2storage[1]->roundToDouble();
}

void Vector2Cls::roundToZero() {
    _v2storage[0] = _v2storage[0] < 0.0? _v2storage[0]->ceilToDouble() : _v2storage[0]->floorToDouble();
    _v2storage[1] = _v2storage[1] < 0.0? _v2storage[1]->ceilToDouble() : _v2storage[1]->floorToDouble();
}

Vector2 Vector2Cls::clone() {
    return Vector2Cls->copy(this);
}

Vector2 Vector2Cls::copyInto(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    argStorage[1] = _v2storage[1];
    argStorage[0] = _v2storage[0];
    return arg;
}

void Vector2Cls::copyIntoArray(List<double> array, int offset) {
    array[offset + 1] = _v2storage[1];
    array[offset + 0] = _v2storage[0];
}

void Vector2Cls::copyFromArray(List<double> array, int offset) {
    _v2storage[1] = array[offset + 1];
    _v2storage[0] = array[offset + 0];
}

void Vector2Cls::xy(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v2storage[0] = argStorage[0];
    _v2storage[1] = argStorage[1];
}

void Vector2Cls::yx(Vector2 arg) {
    Unknown argStorage = arg->_v2storage;
    _v2storage[1] = argStorage[0];
    _v2storage[0] = argStorage[1];
}

void Vector2Cls::r(double arg) {
    return x = arg;
}

void Vector2Cls::g(double arg) {
    return y = arg;
}

void Vector2Cls::s(double arg) {
    return x = arg;
}

void Vector2Cls::t(double arg) {
    return y = arg;
}

void Vector2Cls::x(double arg) {
    return _v2storage[0] = arg;
}

void Vector2Cls::y(double arg) {
    return _v2storage[1] = arg;
}

void Vector2Cls::rg(Vector2 arg) {
    return xy = arg;
}

void Vector2Cls::gr(Vector2 arg) {
    return yx = arg;
}

void Vector2Cls::st(Vector2 arg) {
    return xy = arg;
}

void Vector2Cls::ts(Vector2 arg) {
    return yx = arg;
}

Vector2 Vector2Cls::xx() {
    return make<Vector2Cls>(_v2storage[0], _v2storage[0]);
}

Vector2 Vector2Cls::xy() {
    return make<Vector2Cls>(_v2storage[0], _v2storage[1]);
}

Vector2 Vector2Cls::yx() {
    return make<Vector2Cls>(_v2storage[1], _v2storage[0]);
}

Vector2 Vector2Cls::yy() {
    return make<Vector2Cls>(_v2storage[1], _v2storage[1]);
}

Vector3 Vector2Cls::xxx() {
    return make<Vector3Cls>(_v2storage[0], _v2storage[0], _v2storage[0]);
}

Vector3 Vector2Cls::xxy() {
    return make<Vector3Cls>(_v2storage[0], _v2storage[0], _v2storage[1]);
}

Vector3 Vector2Cls::xyx() {
    return make<Vector3Cls>(_v2storage[0], _v2storage[1], _v2storage[0]);
}

Vector3 Vector2Cls::xyy() {
    return make<Vector3Cls>(_v2storage[0], _v2storage[1], _v2storage[1]);
}

Vector3 Vector2Cls::yxx() {
    return make<Vector3Cls>(_v2storage[1], _v2storage[0], _v2storage[0]);
}

Vector3 Vector2Cls::yxy() {
    return make<Vector3Cls>(_v2storage[1], _v2storage[0], _v2storage[1]);
}

Vector3 Vector2Cls::yyx() {
    return make<Vector3Cls>(_v2storage[1], _v2storage[1], _v2storage[0]);
}

Vector3 Vector2Cls::yyy() {
    return make<Vector3Cls>(_v2storage[1], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2Cls::xxxx() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[0], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2Cls::xxxy() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[0], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2Cls::xxyx() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[0], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2Cls::xxyy() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[0], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2Cls::xyxx() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[1], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2Cls::xyxy() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[1], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2Cls::xyyx() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[1], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2Cls::xyyy() {
    return make<Vector4Cls>(_v2storage[0], _v2storage[1], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2Cls::yxxx() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[0], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2Cls::yxxy() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[0], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2Cls::yxyx() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[0], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2Cls::yxyy() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[0], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2Cls::yyxx() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[1], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2Cls::yyxy() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[1], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2Cls::yyyx() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[1], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2Cls::yyyy() {
    return make<Vector4Cls>(_v2storage[1], _v2storage[1], _v2storage[1], _v2storage[1]);
}

double Vector2Cls::r() {
    return x;
}

double Vector2Cls::g() {
    return y;
}

double Vector2Cls::s() {
    return x;
}

double Vector2Cls::t() {
    return y;
}

double Vector2Cls::x() {
    return _v2storage[0];
}

double Vector2Cls::y() {
    return _v2storage[1];
}

Vector2 Vector2Cls::rr() {
    return xx();
}

Vector2 Vector2Cls::rg() {
    return xy;
}

Vector2 Vector2Cls::gr() {
    return yx;
}

Vector2 Vector2Cls::gg() {
    return yy();
}

Vector3 Vector2Cls::rrr() {
    return xxx();
}

Vector3 Vector2Cls::rrg() {
    return xxy();
}

Vector3 Vector2Cls::rgr() {
    return xyx();
}

Vector3 Vector2Cls::rgg() {
    return xyy();
}

Vector3 Vector2Cls::grr() {
    return yxx();
}

Vector3 Vector2Cls::grg() {
    return yxy();
}

Vector3 Vector2Cls::ggr() {
    return yyx();
}

Vector3 Vector2Cls::ggg() {
    return yyy();
}

Vector4 Vector2Cls::rrrr() {
    return xxxx();
}

Vector4 Vector2Cls::rrrg() {
    return xxxy();
}

Vector4 Vector2Cls::rrgr() {
    return xxyx();
}

Vector4 Vector2Cls::rrgg() {
    return xxyy();
}

Vector4 Vector2Cls::rgrr() {
    return xyxx();
}

Vector4 Vector2Cls::rgrg() {
    return xyxy();
}

Vector4 Vector2Cls::rggr() {
    return xyyx();
}

Vector4 Vector2Cls::rggg() {
    return xyyy();
}

Vector4 Vector2Cls::grrr() {
    return yxxx();
}

Vector4 Vector2Cls::grrg() {
    return yxxy();
}

Vector4 Vector2Cls::grgr() {
    return yxyx();
}

Vector4 Vector2Cls::grgg() {
    return yxyy();
}

Vector4 Vector2Cls::ggrr() {
    return yyxx();
}

Vector4 Vector2Cls::ggrg() {
    return yyxy();
}

Vector4 Vector2Cls::gggr() {
    return yyyx();
}

Vector4 Vector2Cls::gggg() {
    return yyyy();
}

Vector2 Vector2Cls::ss() {
    return xx();
}

Vector2 Vector2Cls::st() {
    return xy;
}

Vector2 Vector2Cls::ts() {
    return yx;
}

Vector2 Vector2Cls::tt() {
    return yy();
}

Vector3 Vector2Cls::sss() {
    return xxx();
}

Vector3 Vector2Cls::sst() {
    return xxy();
}

Vector3 Vector2Cls::sts() {
    return xyx();
}

Vector3 Vector2Cls::stt() {
    return xyy();
}

Vector3 Vector2Cls::tss() {
    return yxx();
}

Vector3 Vector2Cls::tst() {
    return yxy();
}

Vector3 Vector2Cls::tts() {
    return yyx();
}

Vector3 Vector2Cls::ttt() {
    return yyy();
}

Vector4 Vector2Cls::ssss() {
    return xxxx();
}

Vector4 Vector2Cls::ssst() {
    return xxxy();
}

Vector4 Vector2Cls::ssts() {
    return xxyx();
}

Vector4 Vector2Cls::sstt() {
    return xxyy();
}

Vector4 Vector2Cls::stss() {
    return xyxx();
}

Vector4 Vector2Cls::stst() {
    return xyxy();
}

Vector4 Vector2Cls::stts() {
    return xyyx();
}

Vector4 Vector2Cls::sttt() {
    return xyyy();
}

Vector4 Vector2Cls::tsss() {
    return yxxx();
}

Vector4 Vector2Cls::tsst() {
    return yxxy();
}

Vector4 Vector2Cls::tsts() {
    return yxyx();
}

Vector4 Vector2Cls::tstt() {
    return yxyy();
}

Vector4 Vector2Cls::ttss() {
    return yyxx();
}

Vector4 Vector2Cls::ttst() {
    return yyxy();
}

Vector4 Vector2Cls::ttts() {
    return yyyx();
}

Vector4 Vector2Cls::tttt() {
    return yyyy();
}
