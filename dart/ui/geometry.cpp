#include "geometry.hpp"
OffsetBaseCls::OffsetBaseCls(double _dx, double _dy) {
    {
        assert(_dx != nullptr);
        assert(_dy != nullptr);
    }
}

bool OffsetBaseCls::isInfinite() {
    return _dx >= double->infinity || _dy >= double->infinity;
}

bool OffsetBaseCls::isFinite() {
    return _dx->isFinite && _dy->isFinite;
}

bool OffsetBaseCls::<(OffsetBase other) {
    return  < other->_dx &&  < other->_dy;
}

bool OffsetBaseCls::<=(OffsetBase other) {
    return _dx <= other->_dx && _dy <= other->_dy;
}

bool OffsetBaseCls::>(OffsetBase other) {
    return _dx > other->_dx && _dy > other->_dy;
}

bool OffsetBaseCls::>=(OffsetBase other) {
    return _dx >= other->_dx && _dy >= other->_dy;
}

bool OffsetBaseCls::==(Object other) {
    return is<OffsetBase>(other) && other->_dx == _dx && other->_dy == _dy;
}

int OffsetBaseCls::hashCode() {
    return ObjectCls->hash(_dx, _dy);
}

String OffsetBaseCls::toString() {
    return __s("OffsetBase(${_dx.toStringAsFixed(1)}, ${_dy.toStringAsFixed(1)})");
}

OffsetCls::OffsetCls(double dx, double dy) : OffsetBase(dx, dy) {
}

void OffsetCls::fromDirection(double direction, double distance) {
    return make<OffsetCls>(distance * math->cos(direction), distance * math->sin(direction));
}

double OffsetCls::dx() {
    return _dx;
}

double OffsetCls::dy() {
    return _dy;
}

double OffsetCls::distance() {
    return math->sqrt(dx() * dx() + dy() * dy());
}

double OffsetCls::distanceSquared() {
    return dx() * dx() + dy() * dy();
}

double OffsetCls::direction() {
    return math->atan2(dy(), dx());
}

Offset OffsetCls::scale(double scaleX, double scaleY) {
    return make<OffsetCls>(dx() * scaleX, dy() * scaleY);
}

Offset OffsetCls::translate(double translateX, double translateY) {
    return make<OffsetCls>(dx() + translateX, dy() + translateY);
}

Offset OffsetCls::-() {
    return make<OffsetCls>(-dx(), -dy());
}

Offset OffsetCls::-(Offset other) {
    return make<OffsetCls>(dx() - other->dx(), dy() - other->dy());
}

Offset OffsetCls::+(Offset other) {
    return make<OffsetCls>(dx() + other->dx(), dy() + other->dy());
}

Offset OffsetCls::*(double operand) {
    return make<OffsetCls>(dx() * operand, dy() * operand);
}

Offset OffsetCls::/(double operand) {
    return make<OffsetCls>(dx() / operand, dy() / operand);
}

Offset OffsetCls::~/(double operand) {
    return make<OffsetCls>((dx() ~/ operand)->toDouble(), (dy() ~/ operand)->toDouble());
}

Offset OffsetCls::%(double operand) {
    return make<OffsetCls>(dx() % operand, dy() % operand);
}

Rect OffsetCls::&(Size other) {
    return RectCls->fromLTWH(dx(), dy(), other->width(), other->height());
}

Offset OffsetCls::lerp(Offset a, Offset b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            return a * (1.0 - t);
        }
    } else {
        if (a == nullptr) {
            return b * t;
        } else {
            return make<OffsetCls>(_lerpDouble(a->dx(), b->dx(), t), _lerpDouble(a->dy(), b->dy(), t));
        }
    }
}

bool OffsetCls::==(Object other) {
    return is<Offset>(other) && other->dx == dx() && other->dy == dy();
}

int OffsetCls::hashCode() {
    return ObjectCls->hash(dx(), dy());
}

String OffsetCls::toString() {
    return __s("Offset(${dx.toStringAsFixed(1)}, ${dy.toStringAsFixed(1)})");
}

SizeCls::SizeCls(double height, double width) : OffsetBase(width, height) {
}

void SizeCls::copy(Size source)

void SizeCls::square(double dimension)

void SizeCls::fromWidth(double width)

void SizeCls::fromHeight(double height)

void SizeCls::fromRadius(double radius)

double SizeCls::width() {
    return _dx;
}

double SizeCls::height() {
    return _dy;
}

double SizeCls::aspectRatio() {
    if (height() != 0.0)     {
        return width() / height();
    }
    if (width() > 0.0)     {
        return double->infinity;
    }
    if ( < 0.0)     {
        return double->negativeInfinity;
    }
    return 0.0;
}

bool SizeCls::isEmpty() {
    return width() <= 0.0 || height() <= 0.0;
}

OffsetBase SizeCls::-(OffsetBase other) {
    if (is<Size>(other))     {
        return make<OffsetCls>(width() - as<SizeCls>(other)->width(), height() - as<SizeCls>(other)->height());
    }
    if (is<Offset>(other))     {
        return make<SizeCls>(width() - as<OffsetCls>(other)->dx(), height() - as<OffsetCls>(other)->dy());
    }
    ;
}

Size SizeCls::+(Offset other) {
    return make<SizeCls>(width() + other->dx(), height() + other->dy());
}

Size SizeCls::*(double operand) {
    return make<SizeCls>(width() * operand, height() * operand);
}

Size SizeCls::/(double operand) {
    return make<SizeCls>(width() / operand, height() / operand);
}

Size SizeCls::~/(double operand) {
    return make<SizeCls>((width() ~/ operand)->toDouble(), (height() ~/ operand)->toDouble());
}

Size SizeCls::%(double operand) {
    return make<SizeCls>(width() % operand, height() % operand);
}

double SizeCls::shortestSide() {
    return math->min(width()->abs(), height()->abs());
}

double SizeCls::longestSide() {
    return math->max(width()->abs(), height()->abs());
}

Offset SizeCls::topLeft(Offset origin) {
    return origin;
}

Offset SizeCls::topCenter(Offset origin) {
    return make<OffsetCls>(origin->dx() + width() / 2.0, origin->dy());
}

Offset SizeCls::topRight(Offset origin) {
    return make<OffsetCls>(origin->dx() + width(), origin->dy());
}

Offset SizeCls::centerLeft(Offset origin) {
    return make<OffsetCls>(origin->dx(), origin->dy() + height() / 2.0);
}

Offset SizeCls::center(Offset origin) {
    return make<OffsetCls>(origin->dx() + width() / 2.0, origin->dy() + height() / 2.0);
}

Offset SizeCls::centerRight(Offset origin) {
    return make<OffsetCls>(origin->dx() + width(), origin->dy() + height() / 2.0);
}

Offset SizeCls::bottomLeft(Offset origin) {
    return make<OffsetCls>(origin->dx(), origin->dy() + height());
}

Offset SizeCls::bottomCenter(Offset origin) {
    return make<OffsetCls>(origin->dx() + width() / 2.0, origin->dy() + height());
}

Offset SizeCls::bottomRight(Offset origin) {
    return make<OffsetCls>(origin->dx() + width(), origin->dy() + height());
}

bool SizeCls::contains(Offset offset) {
    return offset->dx() >= 0.0 && offset->dx() < width() && offset->dy() >= 0.0 && offset->dy() < height();
}

Size SizeCls::flipped() {
    return make<SizeCls>(height(), width());
}

Size SizeCls::lerp(Size a, Size b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            return a * (1.0 - t);
        }
    } else {
        if (a == nullptr) {
            return b * t;
        } else {
            return make<SizeCls>(_lerpDouble(a->width(), b->width(), t), _lerpDouble(a->height(), b->height(), t));
        }
    }
}

bool SizeCls::==(Object other) {
    return is<Size>(other) && other->_dx == _dx && other->_dy == _dy;
}

int SizeCls::hashCode() {
    return ObjectCls->hash(_dx, _dy);
}

String SizeCls::toString() {
    return __s("Size(${width.toStringAsFixed(1)}, ${height.toStringAsFixed(1)})");
}

void RectCls::fromLTRB(double bottom, double left, double right, double top)

void RectCls::fromLTWH(double height, double left, double top, double width)

void RectCls::fromCircle(Offset center, double radius)

void RectCls::fromCenter(Offset center, double height, double width)

void RectCls::fromPoints(Offset a, Offset b)

double RectCls::width() {
    return right - left;
}

double RectCls::height() {
    return bottom - top;
}

Size RectCls::size() {
    return make<SizeCls>(width(), height());
}

bool RectCls::hasNaN() {
    return left->isNaN || top->isNaN || right->isNaN || bottom->isNaN;
}

bool RectCls::isInfinite() {
    return left >= double->infinity || top >= double->infinity || right >= double->infinity || bottom >= double->infinity;
}

bool RectCls::isFinite() {
    return left->isFinite && top->isFinite && right->isFinite && bottom->isFinite;
}

bool RectCls::isEmpty() {
    return left >= right || top >= bottom;
}

Rect RectCls::shift(Offset offset) {
    return RectCls->fromLTRB(left + offset->dx(), top + offset->dy(), right + offset->dx(), bottom + offset->dy());
}

Rect RectCls::translate(double translateX, double translateY) {
    return RectCls->fromLTRB(left + translateX, top + translateY, right + translateX, bottom + translateY);
}

Rect RectCls::inflate(double delta) {
    return RectCls->fromLTRB(left - delta, top - delta, right + delta, bottom + delta);
}

Rect RectCls::deflate(double delta) {
    return inflate(-delta);
}

Rect RectCls::intersect(Rect other) {
    return RectCls->fromLTRB(math->max(left, other->left), math->max(top, other->top), math->min(right, other->right), math->min(bottom, other->bottom));
}

Rect RectCls::expandToInclude(Rect other) {
    return RectCls->fromLTRB(math->min(left, other->left), math->min(top, other->top), math->max(right, other->right), math->max(bottom, other->bottom));
}

bool RectCls::overlaps(Rect other) {
    if (right <= other->left || other->right <= left)     {
        return false;
    }
    if (bottom <= other->top || other->bottom <= top)     {
        return false;
    }
    return true;
}

double RectCls::shortestSide() {
    return math->min(width()->abs(), height()->abs());
}

double RectCls::longestSide() {
    return math->max(width()->abs(), height()->abs());
}

Offset RectCls::topLeft() {
    return make<OffsetCls>(left, top);
}

Offset RectCls::topCenter() {
    return make<OffsetCls>(left + width() / 2.0, top);
}

Offset RectCls::topRight() {
    return make<OffsetCls>(right, top);
}

Offset RectCls::centerLeft() {
    return make<OffsetCls>(left, top + height() / 2.0);
}

Offset RectCls::center() {
    return make<OffsetCls>(left + width() / 2.0, top + height() / 2.0);
}

Offset RectCls::centerRight() {
    return make<OffsetCls>(right, top + height() / 2.0);
}

Offset RectCls::bottomLeft() {
    return make<OffsetCls>(left, bottom);
}

Offset RectCls::bottomCenter() {
    return make<OffsetCls>(left + width() / 2.0, bottom);
}

Offset RectCls::bottomRight() {
    return make<OffsetCls>(right, bottom);
}

bool RectCls::contains(Offset offset) {
    return offset->dx() >= left && offset->dx() < right && offset->dy() >= top && offset->dy() < bottom;
}

Rect RectCls::lerp(Rect a, Rect b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            double k = 1.0 - t;
            return RectCls->fromLTRB(a->left * k, a->top * k, a->right * k, a->bottom * k);
        }
    } else {
        if (a == nullptr) {
            return RectCls->fromLTRB(b->left * t, b->top * t, b->right * t, b->bottom * t);
        } else {
            return RectCls->fromLTRB(_lerpDouble(a->left, b->left, t), _lerpDouble(a->top, b->top, t), _lerpDouble(a->right, b->right, t), _lerpDouble(a->bottom, b->bottom, t));
        }
    }
}

bool RectCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (runtimeType != other->runtimeType())     {
        return false;
    }
    return is<Rect>(other) && other->left == left && other->top == top && other->right == right && other->bottom == bottom;
}

int RectCls::hashCode() {
    return ObjectCls->hash(left, top, right, bottom);
}

String RectCls::toString() {
    return __s("Rect.fromLTRB(${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)})");
}

Float32List RectCls::_getValue32() {
    Float32List result = make<Float32ListCls>(4);
    result[0] = left;
    result[1] = top;
    result[2] = right;
    result[3] = bottom;
    return result;
}

void RadiusCls::circular(double radius)

Radius RadiusCls::-() {
    return RadiusCls->elliptical(-x, -y);
}

Radius RadiusCls::-(Radius other) {
    return RadiusCls->elliptical(x - other->x, y - other->y);
}

Radius RadiusCls::+(Radius other) {
    return RadiusCls->elliptical(x + other->x, y + other->y);
}

Radius RadiusCls::*(double operand) {
    return RadiusCls->elliptical(x * operand, y * operand);
}

Radius RadiusCls::/(double operand) {
    return RadiusCls->elliptical(x / operand, y / operand);
}

Radius RadiusCls::~/(double operand) {
    return RadiusCls->elliptical((x ~/ operand)->toDouble(), (y ~/ operand)->toDouble());
}

Radius RadiusCls::%(double operand) {
    return RadiusCls->elliptical(x % operand, y % operand);
}

Radius RadiusCls::lerp(Radius a, Radius b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            double k = 1.0 - t;
            return RadiusCls->elliptical(a->x * k, a->y * k);
        }
    } else {
        if (a == nullptr) {
            return RadiusCls->elliptical(b->x * t, b->y * t);
        } else {
            return RadiusCls->elliptical(_lerpDouble(a->x, b->x, t), _lerpDouble(a->y, b->y, t));
        }
    }
}

bool RadiusCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (runtimeType != other->runtimeType())     {
        return false;
    }
    return is<Radius>(other) && other->x == x && other->y == y;
}

int RadiusCls::hashCode() {
    return ObjectCls->hash(x, y);
}

String RadiusCls::toString() {
    return x == y? __s("Radius.circular(${x.toStringAsFixed(1)})") : __s("Radius.elliptical(${x.toStringAsFixed(1)}, ${y.toStringAsFixed(1)})");
}

void RRectCls::fromLTRBXY(double bottom, double left, double radiusX, double radiusY, double right, double top)

void RRectCls::fromLTRBR(double bottom, double left, Radius radius, double right, double top)

void RRectCls::fromRectXY(double radiusX, double radiusY, Rect rect)

void RRectCls::fromRectAndRadius(Radius radius, Rect rect)

void RRectCls::fromLTRBAndCorners(double bottom, Radius bottomLeft, Radius bottomRight, double left, double right, double top, Radius topLeft, Radius topRight)

void RRectCls::fromRectAndCorners(Radius bottomLeft, Radius bottomRight, Rect rect, Radius topLeft, Radius topRight)

Radius RRectCls::tlRadius() {
    return RadiusCls->elliptical(tlRadiusX, tlRadiusY);
}

Radius RRectCls::trRadius() {
    return RadiusCls->elliptical(trRadiusX, trRadiusY);
}

Radius RRectCls::brRadius() {
    return RadiusCls->elliptical(brRadiusX, brRadiusY);
}

Radius RRectCls::blRadius() {
    return RadiusCls->elliptical(blRadiusX, blRadiusY);
}

RRect RRectCls::shift(Offset offset) {
    return RRectCls->_raw(left + offset->dx(), top + offset->dy(), right + offset->dx(), bottom + offset->dy(), tlRadiusX, tlRadiusY, trRadiusX, trRadiusY, blRadiusX, blRadiusY, brRadiusX, brRadiusY);
}

RRect RRectCls::inflate(double delta) {
    return RRectCls->_raw(left - delta, top - delta, right + delta, bottom + delta, tlRadiusX + delta, tlRadiusY + delta, trRadiusX + delta, trRadiusY + delta, blRadiusX + delta, blRadiusY + delta, brRadiusX + delta, brRadiusY + delta);
}

RRect RRectCls::deflate(double delta) {
    return inflate(-delta);
}

double RRectCls::width() {
    return right - left;
}

double RRectCls::height() {
    return bottom - top;
}

Rect RRectCls::outerRect() {
    return RectCls->fromLTRB(left, top, right, bottom);
}

Rect RRectCls::safeInnerRect() {
    double kInsetFactor = 0.29289321881;
    double leftRadius = math->max(blRadiusX, tlRadiusX);
    double topRadius = math->max(tlRadiusY, trRadiusY);
    double rightRadius = math->max(trRadiusX, brRadiusX);
    double bottomRadius = math->max(brRadiusY, blRadiusY);
    return RectCls->fromLTRB(left + leftRadius * kInsetFactor, top + topRadius * kInsetFactor, right - rightRadius * kInsetFactor, bottom - bottomRadius * kInsetFactor);
}

Rect RRectCls::middleRect() {
    double leftRadius = math->max(blRadiusX, tlRadiusX);
    double topRadius = math->max(tlRadiusY, trRadiusY);
    double rightRadius = math->max(trRadiusX, brRadiusX);
    double bottomRadius = math->max(brRadiusY, blRadiusY);
    return RectCls->fromLTRB(left + leftRadius, top + topRadius, right - rightRadius, bottom - bottomRadius);
}

Rect RRectCls::wideMiddleRect() {
    double topRadius = math->max(tlRadiusY, trRadiusY);
    double bottomRadius = math->max(brRadiusY, blRadiusY);
    return RectCls->fromLTRB(left, top + topRadius, right, bottom - bottomRadius);
}

Rect RRectCls::tallMiddleRect() {
    double leftRadius = math->max(blRadiusX, tlRadiusX);
    double rightRadius = math->max(trRadiusX, brRadiusX);
    return RectCls->fromLTRB(left + leftRadius, top, right - rightRadius, bottom);
}

bool RRectCls::isEmpty() {
    return left >= right || top >= bottom;
}

bool RRectCls::isFinite() {
    return left->isFinite && top->isFinite && right->isFinite && bottom->isFinite;
}

bool RRectCls::isRect() {
    return (tlRadiusX == 0.0 || tlRadiusY == 0.0) && (trRadiusX == 0.0 || trRadiusY == 0.0) && (blRadiusX == 0.0 || blRadiusY == 0.0) && (brRadiusX == 0.0 || brRadiusY == 0.0);
}

bool RRectCls::isStadium() {
    return tlRadius() == trRadius() && trRadius() == brRadius() && brRadius() == blRadius() && (width() <= 2.0 * tlRadiusX || height() <= 2.0 * tlRadiusY);
}

bool RRectCls::isEllipse() {
    return tlRadius() == trRadius() && trRadius() == brRadius() && brRadius() == blRadius() && width() <= 2.0 * tlRadiusX && height() <= 2.0 * tlRadiusY;
}

bool RRectCls::isCircle() {
    return width() == height() && isEllipse();
}

double RRectCls::shortestSide() {
    return math->min(width()->abs(), height()->abs());
}

double RRectCls::longestSide() {
    return math->max(width()->abs(), height()->abs());
}

bool RRectCls::hasNaN() {
    return left->isNaN || top->isNaN || right->isNaN || bottom->isNaN || trRadiusX->isNaN || trRadiusY->isNaN || tlRadiusX->isNaN || tlRadiusY->isNaN || brRadiusX->isNaN || brRadiusY->isNaN || blRadiusX->isNaN || blRadiusY->isNaN;
}

Offset RRectCls::center() {
    return make<OffsetCls>(left + width() / 2.0, top + height() / 2.0);
}

RRect RRectCls::scaleRadii() {
    double scale = 1.0;
    scale = _getMin(scale, blRadiusY, tlRadiusY, height());
    scale = _getMin(scale, tlRadiusX, trRadiusX, width());
    scale = _getMin(scale, trRadiusY, brRadiusY, height());
    scale = _getMin(scale, brRadiusX, blRadiusX, width());
    if ( < 1.0) {
        return RRectCls->_raw(top, left, right, bottom, tlRadiusX * scale, tlRadiusY * scale, trRadiusX * scale, trRadiusY * scale, blRadiusX * scale, blRadiusY * scale, brRadiusX * scale, brRadiusY * scale);
    }
    return RRectCls->_raw(top, left, right, bottom, tlRadiusX, tlRadiusY, trRadiusX, trRadiusY, blRadiusX, blRadiusY, brRadiusX, brRadiusY);
}

bool RRectCls::contains(Offset point) {
    if (point->dx() < left || point->dx() >= right || point->dy() < top || point->dy() >= bottom)     {
        return false;
    }
    RRect scaled = scaleRadii();
    double x;
    double y;
    double radiusX;
    double radiusY;
    if (point->dx() < left + scaled->tlRadiusX && point->dy() < top + scaled->tlRadiusY) {
        x = point->dx() - left - scaled->tlRadiusX;
        y = point->dy() - top - scaled->tlRadiusY;
        radiusX = scaled->tlRadiusX;
        radiusY = scaled->tlRadiusY;
    } else     {
        if (point->dx() > right - scaled->trRadiusX && point->dy() < top + scaled->trRadiusY) {
        x = point->dx() - right + scaled->trRadiusX;
        y = point->dy() - top - scaled->trRadiusY;
        radiusX = scaled->trRadiusX;
        radiusY = scaled->trRadiusY;
    } else     {
        if (point->dx() > right - scaled->brRadiusX && point->dy() > bottom - scaled->brRadiusY) {
        x = point->dx() - right + scaled->brRadiusX;
        y = point->dy() - bottom + scaled->brRadiusY;
        radiusX = scaled->brRadiusX;
        radiusY = scaled->brRadiusY;
    } else     {
        if (point->dx() < left + scaled->blRadiusX && point->dy() > bottom - scaled->blRadiusY) {
        x = point->dx() - left - scaled->blRadiusX;
        y = point->dy() - bottom + scaled->blRadiusY;
        radiusX = scaled->blRadiusX;
        radiusY = scaled->blRadiusY;
    } else {
        return true;
    }
;
    };
    };
    }    x = x / radiusX;
    y = y / radiusY;
    if (x * x + y * y > 1.0)     {
        return false;
    }
    return true;
}

RRect RRectCls::lerp(RRect a, RRect b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            double k = 1.0 - t;
            return RRectCls->_raw(a->left * k, a->top * k, a->right * k, a->bottom * k, a->tlRadiusX * k, a->tlRadiusY * k, a->trRadiusX * k, a->trRadiusY * k, a->brRadiusX * k, a->brRadiusY * k, a->blRadiusX * k, a->blRadiusY * k);
        }
    } else {
        if (a == nullptr) {
            return RRectCls->_raw(b->left * t, b->top * t, b->right * t, b->bottom * t, b->tlRadiusX * t, b->tlRadiusY * t, b->trRadiusX * t, b->trRadiusY * t, b->brRadiusX * t, b->brRadiusY * t, b->blRadiusX * t, b->blRadiusY * t);
        } else {
            return RRectCls->_raw(_lerpDouble(a->left, b->left, t), _lerpDouble(a->top, b->top, t), _lerpDouble(a->right, b->right, t), _lerpDouble(a->bottom, b->bottom, t), _lerpDouble(a->tlRadiusX, b->tlRadiusX, t), _lerpDouble(a->tlRadiusY, b->tlRadiusY, t), _lerpDouble(a->trRadiusX, b->trRadiusX, t), _lerpDouble(a->trRadiusY, b->trRadiusY, t), _lerpDouble(a->brRadiusX, b->brRadiusX, t), _lerpDouble(a->brRadiusY, b->brRadiusY, t), _lerpDouble(a->blRadiusX, b->blRadiusX, t), _lerpDouble(a->blRadiusY, b->blRadiusY, t));
        }
    }
}

bool RRectCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (runtimeType != other->runtimeType())     {
        return false;
    }
    return is<RRect>(other) && other->left == left && other->top == top && other->right == right && other->bottom == bottom && other->tlRadiusX == tlRadiusX && other->tlRadiusY == tlRadiusY && other->trRadiusX == trRadiusX && other->trRadiusY == trRadiusY && other->blRadiusX == blRadiusX && other->blRadiusY == blRadiusY && other->brRadiusX == brRadiusX && other->brRadiusY == brRadiusY;
}

int RRectCls::hashCode() {
    return ObjectCls->hash(left, top, right, bottom, tlRadiusX, tlRadiusY, trRadiusX, trRadiusY, blRadiusX, blRadiusY, brRadiusX, brRadiusY);
}

String RRectCls::toString() {
    String rect = __s("${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)}");
    if (tlRadius() == trRadius() && trRadius() == brRadius() && brRadius() == blRadius()) {
        if (tlRadius()->x == tlRadius()->y)         {
            return __s("RRect.fromLTRBR($rect, ${tlRadius.x.toStringAsFixed(1)})");
        }
        return __s("RRect.fromLTRBXY($rect, ${tlRadius.x.toStringAsFixed(1)}, ${tlRadius.y.toStringAsFixed(1)})");
    }
    return __s("RRect.fromLTRBAndCorners($rect, topLeft: $tlRadius, topRight: $trRadius, bottomRight: $brRadius, bottomLeft: $blRadius)");
}

void RRectCls::_raw(double blRadiusX, double blRadiusY, double bottom, double brRadiusX, double brRadiusY, double left, double right, double tlRadiusX, double tlRadiusY, double top, double trRadiusX, double trRadiusY)

Float32List RRectCls::_getValue32() {
    Float32List result = make<Float32ListCls>(12);
    result[0] = left;
    result[1] = top;
    result[2] = right;
    result[3] = bottom;
    result[4] = tlRadiusX;
    result[5] = tlRadiusY;
    result[6] = trRadiusX;
    result[7] = trRadiusY;
    result[8] = brRadiusX;
    result[9] = brRadiusY;
    result[10] = blRadiusX;
    result[11] = blRadiusY;
    return result;
}

double RRectCls::_getMin(double limit, double min, double radius1, double radius2) {
    double sum = radius1 + radius2;
    if (sum > limit && sum != 0.0)     {
        return math->min(min, limit / sum);
    }
    return min;
}

RSTransformCls::RSTransformCls(double scos, double ssin, double tx, double ty) {
    {
            auto _c1 = _value;    _c1[0] =auto _c2 = scos;    _c2[1] =auto _c3 = ssin;    _c3[2] =auto _c4 = tx;    _c4[3] =ty;    _c4;    _c3;    _c2;_c1;
    }
}

void RSTransformCls::fromComponents(double anchorX, double anchorY, double rotation, double scale, double translateX, double translateY) {
    double scos = math->cos(rotation) * scale;
    double ssin = math->sin(rotation) * scale;
    double tx = translateX + -scos * anchorX + ssin * anchorY;
    double ty = translateY + -ssin * anchorX - scos * anchorY;
    return make<RSTransformCls>(scos, ssin, tx, ty);
}

double RSTransformCls::scos() {
    return _value[0];
}

double RSTransformCls::ssin() {
    return _value[1];
}

double RSTransformCls::tx() {
    return _value[2];
}

double RSTransformCls::ty() {
    return _value[3];
}
