#include "vector2.hpp"
Float64List Vector2::storage() {
    return _v2storage;
}

void Vector2::min(Vector2 a, Vector2 b, Vector2 result) {
    ;
}

void Vector2::max(Vector2 a, Vector2 b, Vector2 result) {
    ;
}

void Vector2::mix(double a, Vector2 max, Vector2 min, Vector2 result) {
    ;
}

Vector2::Vector2(double x, double y) {
}

void Vector2::array(List<double> array, int offset) {
    return ;
}

void Vector2::zero()

void Vector2::all(double value) {
    return ;
}

void Vector2::copy(Vector2 other) {
    return ;
}

void Vector2::fromBuffer(ByteBuffer buffer, int offset)

void Vector2::random(Random rng) {
    rng = math.Random();
    return Vector2(rng.nextDouble(), rng.nextDouble());
}

void Vector2::setValues(double x_, double y_) {
    _v2storage[0] = x_;
    _v2storage[1] = y_;
}

void Vector2::setZero() {
    _v2storage[0] = 0.0;
    _v2storage[1] = 0.0;
}

void Vector2::setFrom(Vector2 other) {
    Unknown otherStorage = other._v2storage;
    _v2storage[1] = otherStorage[1];
    _v2storage[0] = otherStorage[0];
}

void Vector2::splat(double arg) {
    _v2storage[0] = arg;
    _v2storage[1] = arg;
}

String Vector2::toString() {
    return "[${_v2storage[0]},${_v2storage[1]}]";
}

bool Vector2::==(Object other) {
    return (other is Vector2) && (_v2storage[0] == other._v2storage[0]) && (_v2storage[1] == other._v2storage[1]);
}

int Vector2::hashCode() {
    return Object.hashAll(_v2storage);
}

Vector2 Vector2::-() {
    return ;
}

Vector2 Vector2::-(Vector2 other) {
    return ;
}

Vector2 Vector2::+(Vector2 other) {
    return ;
}

Vector2 Vector2::/(double scale) {
    return ;
}

Vector2 Vector2::*(double scale) {
    return ;
}

double Vector2::[](int i) {
    return _v2storage[i];
}

void Vector2::[]=(int i, double v) {
    _v2storage[i] = v;
}

void Vector2::length(double value) {
    if (value == 0.0) {
        setZero();
    } else {
        auto l = length;
        if (l == 0.0) {
            return;
        }
        l = value / l;
        _v2storage[0] = l;
        _v2storage[1] = l;
    }
}

double Vector2::length() {
    return math.sqrt(length2);
}

double Vector2::length2() {
    double sum;
    sum = _v2storage[0] * _v2storage[0];
    sum = _v2storage[1] * _v2storage[1];
    return sum;
}

double Vector2::normalize() {
    Unknown l = length;
    if (l == 0.0) {
        return 0.0;
    }
    Unknown d = 1.0 / l;
    _v2storage[0] = d;
    _v2storage[1] = d;
    return l;
}

double Vector2::normalizeLength() {
    return normalize();
}

Vector2 Vector2::normalized() {
    return ;
}

Vector2 Vector2::normalizeInto(Vector2 out) {
    ;
    return out;
}

double Vector2::distanceTo(Vector2 arg) {
    return math.sqrt(distanceToSquared(arg));
}

double Vector2::distanceToSquared(Vector2 arg) {
    Unknown dx = x - arg.x;
    Unknown dy = y - arg.y;
    return dx * dx + dy * dy;
}

double Vector2::angleTo(Vector2 other) {
    Unknown otherStorage = other._v2storage;
    if (_v2storage[0] == otherStorage[0] && _v2storage[1] == otherStorage[1]) {
        return 0.0;
    }
    Unknown d = dot(other) / (length * other.length);
    return math.acos(d.clamp(-1.0, 1.0));
}

double Vector2::angleToSigned(Vector2 other) {
    Unknown otherStorage = other._v2storage;
    if (_v2storage[0] == otherStorage[0] && _v2storage[1] == otherStorage[1]) {
        return 0.0;
    }
    Unknown s = cross(other);
    Unknown c = dot(other);
    return math.atan2(s, c);
}

double Vector2::dot(Vector2 other) {
    Unknown otherStorage = other._v2storage;
    double sum;
    sum = _v2storage[0] * otherStorage[0];
    sum = _v2storage[1] * otherStorage[1];
    return sum;
}

void Vector2::postmultiply(Matrix2 arg) {
    Unknown argStorage = arg.storage;
    Unknown v0 = _v2storage[0];
    Unknown v1 = _v2storage[1];
    _v2storage[0] = v0 * argStorage[0] + v1 * argStorage[1];
    _v2storage[1] = v0 * argStorage[2] + v1 * argStorage[3];
}

double Vector2::cross(Vector2 other) {
    Unknown otherStorage = other._v2storage;
    return _v2storage[0] * otherStorage[1] - _v2storage[1] * otherStorage[0];
}

Vector2 Vector2::scaleOrthogonalInto(Vector2 out, double scale) {
    out.setValues(-scale * _v2storage[1], scale * _v2storage[0]);
    return out;
}

void Vector2::reflect(Vector2 normal) {
    sub(normal.scaled(2.0 * normal.dot(this)));
}

Vector2 Vector2::reflected(Vector2 normal) {
    return ;
}

double Vector2::relativeError(Vector2 correct) {
    Unknown correct_norm = correct.length;
    Unknown diff_norm = (this - correct).length;
    return diff_norm / correct_norm;
}

double Vector2::absoluteError(Vector2 correct) {
    return (this - correct).length;
}

bool Vector2::isInfinite() {
    auto is_infinite = false;
    is_infinite = is_infinite || _v2storage[0].isInfinite;
    is_infinite = is_infinite || _v2storage[1].isInfinite;
    return is_infinite;
}

bool Vector2::isNaN() {
    auto is_nan = false;
    is_nan = is_nan || _v2storage[0].isNaN;
    is_nan = is_nan || _v2storage[1].isNaN;
    return is_nan;
}

void Vector2::add(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v2storage[0] = _v2storage[0] + argStorage[0];
    _v2storage[1] = _v2storage[1] + argStorage[1];
}

void Vector2::addScaled(Vector2 arg, double factor) {
    Unknown argStorage = arg._v2storage;
    _v2storage[0] = _v2storage[0] + argStorage[0] * factor;
    _v2storage[1] = _v2storage[1] + argStorage[1] * factor;
}

void Vector2::sub(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v2storage[0] = _v2storage[0] - argStorage[0];
    _v2storage[1] = _v2storage[1] - argStorage[1];
}

void Vector2::multiply(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v2storage[0] = _v2storage[0] * argStorage[0];
    _v2storage[1] = _v2storage[1] * argStorage[1];
}

void Vector2::divide(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v2storage[0] = _v2storage[0] / argStorage[0];
    _v2storage[1] = _v2storage[1] / argStorage[1];
}

void Vector2::scale(double arg) {
    _v2storage[1] = _v2storage[1] * arg;
    _v2storage[0] = _v2storage[0] * arg;
}

Vector2 Vector2::scaled(double arg) {
    return ;
}

void Vector2::negate() {
    _v2storage[1] = -_v2storage[1];
    _v2storage[0] = -_v2storage[0];
}

void Vector2::absolute() {
    _v2storage[1] = _v2storage[1].abs();
    _v2storage[0] = _v2storage[0].abs();
}

void Vector2::clamp(Vector2 max, Vector2 min) {
    Unknown minStorage = min.storage;
    Unknown maxStorage = max.storage;
    _v2storage[0] = _v2storage[0].clamp(minStorage[0], maxStorage[0]).toDouble();
    _v2storage[1] = _v2storage[1].clamp(minStorage[1], maxStorage[1]).toDouble();
}

void Vector2::clampScalar(double max, double min) {
    _v2storage[0] = _v2storage[0].clamp(min, max).toDouble();
    _v2storage[1] = _v2storage[1].clamp(min, max).toDouble();
}

void Vector2::floor() {
    _v2storage[0] = _v2storage[0].floorToDouble();
    _v2storage[1] = _v2storage[1].floorToDouble();
}

void Vector2::ceil() {
    _v2storage[0] = _v2storage[0].ceilToDouble();
    _v2storage[1] = _v2storage[1].ceilToDouble();
}

void Vector2::round() {
    _v2storage[0] = _v2storage[0].roundToDouble();
    _v2storage[1] = _v2storage[1].roundToDouble();
}

void Vector2::roundToZero() {
    _v2storage[0] = _v2storage[0] < 0.0? _v2storage[0].ceilToDouble() : _v2storage[0].floorToDouble();
    _v2storage[1] = _v2storage[1] < 0.0? _v2storage[1].ceilToDouble() : _v2storage[1].floorToDouble();
}

Vector2 Vector2::clone() {
    return Vector2.copy(this);
}

Vector2 Vector2::copyInto(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    argStorage[1] = _v2storage[1];
    argStorage[0] = _v2storage[0];
    return arg;
}

void Vector2::copyIntoArray(List<double> array, int offset) {
    array[offset + 1] = _v2storage[1];
    array[offset + 0] = _v2storage[0];
}

void Vector2::copyFromArray(List<double> array, int offset) {
    _v2storage[1] = array[offset + 1];
    _v2storage[0] = array[offset + 0];
}

void Vector2::xy(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v2storage[0] = argStorage[0];
    _v2storage[1] = argStorage[1];
}

void Vector2::yx(Vector2 arg) {
    Unknown argStorage = arg._v2storage;
    _v2storage[1] = argStorage[0];
    _v2storage[0] = argStorage[1];
}

void Vector2::r(double arg) {
    return x = arg;
}

void Vector2::g(double arg) {
    return y = arg;
}

void Vector2::s(double arg) {
    return x = arg;
}

void Vector2::t(double arg) {
    return y = arg;
}

void Vector2::x(double arg) {
    return _v2storage[0] = arg;
}

void Vector2::y(double arg) {
    return _v2storage[1] = arg;
}

void Vector2::rg(Vector2 arg) {
    return xy = arg;
}

void Vector2::gr(Vector2 arg) {
    return yx = arg;
}

void Vector2::st(Vector2 arg) {
    return xy = arg;
}

void Vector2::ts(Vector2 arg) {
    return yx = arg;
}

Vector2 Vector2::xx() {
    return Vector2(_v2storage[0], _v2storage[0]);
}

Vector2 Vector2::xy() {
    return Vector2(_v2storage[0], _v2storage[1]);
}

Vector2 Vector2::yx() {
    return Vector2(_v2storage[1], _v2storage[0]);
}

Vector2 Vector2::yy() {
    return Vector2(_v2storage[1], _v2storage[1]);
}

Vector3 Vector2::xxx() {
    return Vector3(_v2storage[0], _v2storage[0], _v2storage[0]);
}

Vector3 Vector2::xxy() {
    return Vector3(_v2storage[0], _v2storage[0], _v2storage[1]);
}

Vector3 Vector2::xyx() {
    return Vector3(_v2storage[0], _v2storage[1], _v2storage[0]);
}

Vector3 Vector2::xyy() {
    return Vector3(_v2storage[0], _v2storage[1], _v2storage[1]);
}

Vector3 Vector2::yxx() {
    return Vector3(_v2storage[1], _v2storage[0], _v2storage[0]);
}

Vector3 Vector2::yxy() {
    return Vector3(_v2storage[1], _v2storage[0], _v2storage[1]);
}

Vector3 Vector2::yyx() {
    return Vector3(_v2storage[1], _v2storage[1], _v2storage[0]);
}

Vector3 Vector2::yyy() {
    return Vector3(_v2storage[1], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2::xxxx() {
    return Vector4(_v2storage[0], _v2storage[0], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2::xxxy() {
    return Vector4(_v2storage[0], _v2storage[0], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2::xxyx() {
    return Vector4(_v2storage[0], _v2storage[0], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2::xxyy() {
    return Vector4(_v2storage[0], _v2storage[0], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2::xyxx() {
    return Vector4(_v2storage[0], _v2storage[1], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2::xyxy() {
    return Vector4(_v2storage[0], _v2storage[1], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2::xyyx() {
    return Vector4(_v2storage[0], _v2storage[1], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2::xyyy() {
    return Vector4(_v2storage[0], _v2storage[1], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2::yxxx() {
    return Vector4(_v2storage[1], _v2storage[0], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2::yxxy() {
    return Vector4(_v2storage[1], _v2storage[0], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2::yxyx() {
    return Vector4(_v2storage[1], _v2storage[0], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2::yxyy() {
    return Vector4(_v2storage[1], _v2storage[0], _v2storage[1], _v2storage[1]);
}

Vector4 Vector2::yyxx() {
    return Vector4(_v2storage[1], _v2storage[1], _v2storage[0], _v2storage[0]);
}

Vector4 Vector2::yyxy() {
    return Vector4(_v2storage[1], _v2storage[1], _v2storage[0], _v2storage[1]);
}

Vector4 Vector2::yyyx() {
    return Vector4(_v2storage[1], _v2storage[1], _v2storage[1], _v2storage[0]);
}

Vector4 Vector2::yyyy() {
    return Vector4(_v2storage[1], _v2storage[1], _v2storage[1], _v2storage[1]);
}

double Vector2::r() {
    return x;
}

double Vector2::g() {
    return y;
}

double Vector2::s() {
    return x;
}

double Vector2::t() {
    return y;
}

double Vector2::x() {
    return _v2storage[0];
}

double Vector2::y() {
    return _v2storage[1];
}

Vector2 Vector2::rr() {
    return xx;
}

Vector2 Vector2::rg() {
    return xy;
}

Vector2 Vector2::gr() {
    return yx;
}

Vector2 Vector2::gg() {
    return yy;
}

Vector3 Vector2::rrr() {
    return xxx;
}

Vector3 Vector2::rrg() {
    return xxy;
}

Vector3 Vector2::rgr() {
    return xyx;
}

Vector3 Vector2::rgg() {
    return xyy;
}

Vector3 Vector2::grr() {
    return yxx;
}

Vector3 Vector2::grg() {
    return yxy;
}

Vector3 Vector2::ggr() {
    return yyx;
}

Vector3 Vector2::ggg() {
    return yyy;
}

Vector4 Vector2::rrrr() {
    return xxxx;
}

Vector4 Vector2::rrrg() {
    return xxxy;
}

Vector4 Vector2::rrgr() {
    return xxyx;
}

Vector4 Vector2::rrgg() {
    return xxyy;
}

Vector4 Vector2::rgrr() {
    return xyxx;
}

Vector4 Vector2::rgrg() {
    return xyxy;
}

Vector4 Vector2::rggr() {
    return xyyx;
}

Vector4 Vector2::rggg() {
    return xyyy;
}

Vector4 Vector2::grrr() {
    return yxxx;
}

Vector4 Vector2::grrg() {
    return yxxy;
}

Vector4 Vector2::grgr() {
    return yxyx;
}

Vector4 Vector2::grgg() {
    return yxyy;
}

Vector4 Vector2::ggrr() {
    return yyxx;
}

Vector4 Vector2::ggrg() {
    return yyxy;
}

Vector4 Vector2::gggr() {
    return yyyx;
}

Vector4 Vector2::gggg() {
    return yyyy;
}

Vector2 Vector2::ss() {
    return xx;
}

Vector2 Vector2::st() {
    return xy;
}

Vector2 Vector2::ts() {
    return yx;
}

Vector2 Vector2::tt() {
    return yy;
}

Vector3 Vector2::sss() {
    return xxx;
}

Vector3 Vector2::sst() {
    return xxy;
}

Vector3 Vector2::sts() {
    return xyx;
}

Vector3 Vector2::stt() {
    return xyy;
}

Vector3 Vector2::tss() {
    return yxx;
}

Vector3 Vector2::tst() {
    return yxy;
}

Vector3 Vector2::tts() {
    return yyx;
}

Vector3 Vector2::ttt() {
    return yyy;
}

Vector4 Vector2::ssss() {
    return xxxx;
}

Vector4 Vector2::ssst() {
    return xxxy;
}

Vector4 Vector2::ssts() {
    return xxyx;
}

Vector4 Vector2::sstt() {
    return xxyy;
}

Vector4 Vector2::stss() {
    return xyxx;
}

Vector4 Vector2::stst() {
    return xyxy;
}

Vector4 Vector2::stts() {
    return xyyx;
}

Vector4 Vector2::sttt() {
    return xyyy;
}

Vector4 Vector2::tsss() {
    return yxxx;
}

Vector4 Vector2::tsst() {
    return yxxy;
}

Vector4 Vector2::tsts() {
    return yxyx;
}

Vector4 Vector2::tstt() {
    return yxyy;
}

Vector4 Vector2::ttss() {
    return yyxx;
}

Vector4 Vector2::ttst() {
    return yyxy;
}

Vector4 Vector2::ttts() {
    return yyyx;
}

Vector4 Vector2::tttt() {
    return yyyy;
}
