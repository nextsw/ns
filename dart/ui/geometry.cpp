#include "geometry.hpp"
OffsetBase::OffsetBase(double _dx, double _dy) {
    {
        assert(_dx != nullptr);
        assert(_dy != nullptr);
    }
}

bool OffsetBase::isInfinite() {
    return _dx >= double.infinity || _dy >= double.infinity;
}

bool OffsetBase::isFinite() {
    return _dx.isFinite && _dy.isFinite;
}

bool OffsetBase::<(OffsetBase other) {
    return  < other._dx &&  < other._dy;
}

bool OffsetBase::<=(OffsetBase other) {
    return _dx <= other._dx && _dy <= other._dy;
}

bool OffsetBase::>(OffsetBase other) {
    return _dx > other._dx && _dy > other._dy;
}

bool OffsetBase::>=(OffsetBase other) {
    return _dx >= other._dx && _dy >= other._dy;
}

bool OffsetBase::==(Object other) {
    return other is OffsetBase && other._dx == _dx && other._dy == _dy;
}

int OffsetBase::hashCode() {
    return Object.hash(_dx, _dy);
}

String OffsetBase::toString() {
    return "OffsetBase(${_dx.toStringAsFixed(1)}, ${_dy.toStringAsFixed(1)})";
}

Offset::Offset(double dx, double dy) {
    {
        super(dx, dy);
    }
}

void Offset::fromDirection(double direction, double distance) {
    return Offset(distance * math.cos(direction), distance * math.sin(direction));
}

double Offset::dx() {
    return _dx;
}

double Offset::dy() {
    return _dy;
}

double Offset::distance() {
    return math.sqrt(dx * dx + dy * dy);
}

double Offset::distanceSquared() {
    return dx * dx + dy * dy;
}

double Offset::direction() {
    return math.atan2(dy, dx);
}

Offset Offset::scale(double scaleX, double scaleY) {
    return Offset(dx * scaleX, dy * scaleY);
}

Offset Offset::translate(double translateX, double translateY) {
    return Offset(dx + translateX, dy + translateY);
}

Offset Offset::-() {
    return Offset(-dx, -dy);
}

Offset Offset::-(Offset other) {
    return Offset(dx - other.dx, dy - other.dy);
}

Offset Offset::+(Offset other) {
    return Offset(dx + other.dx, dy + other.dy);
}

Offset Offset::*(double operand) {
    return Offset(dx * operand, dy * operand);
}

Offset Offset::/(double operand) {
    return Offset(dx / operand, dy / operand);
}

Offset Offset::~/(double operand) {
    return Offset((dx ~/ operand).toDouble(), (dy ~/ operand).toDouble());
}

Offset Offset::%(double operand) {
    return Offset(dx % operand, dy % operand);
}

Rect Offset::&(Size other) {
    return Rect.fromLTWH(dx, dy, other.width, other.height);
}

Offset Offset::lerp(Offset a, Offset b, double t) {
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
            return Offset(_lerpDouble(a.dx, b.dx, t), _lerpDouble(a.dy, b.dy, t));
        }
    }
}

bool Offset::==(Object other) {
    return other is Offset && other.dx == dx && other.dy == dy;
}

int Offset::hashCode() {
    return Object.hash(dx, dy);
}

String Offset::toString() {
    return "Offset(${dx.toStringAsFixed(1)}, ${dy.toStringAsFixed(1)})";
}

Size::Size(double height, double width) {
    {
        super(width, height);
    }
}

void Size::copy(Size source)

void Size::square(double dimension)

void Size::fromWidth(double width)

void Size::fromHeight(double height)

void Size::fromRadius(double radius)

double Size::width() {
    return _dx;
}

double Size::height() {
    return _dy;
}

double Size::aspectRatio() {
    if (height != 0.0)     {
        return width / height;
    }
    if (width > 0.0)     {
        return double.infinity;
    }
    if ( < 0.0)     {
        return double.negativeInfinity;
    }
    return 0.0;
}

bool Size::isEmpty() {
    return width <= 0.0 || height <= 0.0;
}

OffsetBase Size::-(OffsetBase other) {
    if (other is Size)     {
        return Offset(width - other.width, height - other.height);
    }
    if (other is Offset)     {
        return Size(width - other.dx, height - other.dy);
    }
    ;
}

Size Size::+(Offset other) {
    return Size(width + other.dx, height + other.dy);
}

Size Size::*(double operand) {
    return Size(width * operand, height * operand);
}

Size Size::/(double operand) {
    return Size(width / operand, height / operand);
}

Size Size::~/(double operand) {
    return Size((width ~/ operand).toDouble(), (height ~/ operand).toDouble());
}

Size Size::%(double operand) {
    return Size(width % operand, height % operand);
}

double Size::shortestSide() {
    return math.min(width.abs(), height.abs());
}

double Size::longestSide() {
    return math.max(width.abs(), height.abs());
}

Offset Size::topLeft(Offset origin) {
    return origin;
}

Offset Size::topCenter(Offset origin) {
    return Offset(origin.dx + width / 2.0, origin.dy);
}

Offset Size::topRight(Offset origin) {
    return Offset(origin.dx + width, origin.dy);
}

Offset Size::centerLeft(Offset origin) {
    return Offset(origin.dx, origin.dy + height / 2.0);
}

Offset Size::center(Offset origin) {
    return Offset(origin.dx + width / 2.0, origin.dy + height / 2.0);
}

Offset Size::centerRight(Offset origin) {
    return Offset(origin.dx + width, origin.dy + height / 2.0);
}

Offset Size::bottomLeft(Offset origin) {
    return Offset(origin.dx, origin.dy + height);
}

Offset Size::bottomCenter(Offset origin) {
    return Offset(origin.dx + width / 2.0, origin.dy + height);
}

Offset Size::bottomRight(Offset origin) {
    return Offset(origin.dx + width, origin.dy + height);
}

bool Size::contains(Offset offset) {
    return offset.dx >= 0.0 && offset.dx < width && offset.dy >= 0.0 && offset.dy < height;
}

Size Size::flipped() {
    return Size(height, width);
}

Size Size::lerp(Size a, Size b, double t) {
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
            return Size(_lerpDouble(a.width, b.width, t), _lerpDouble(a.height, b.height, t));
        }
    }
}

bool Size::==(Object other) {
    return other is Size && other._dx == _dx && other._dy == _dy;
}

int Size::hashCode() {
    return Object.hash(_dx, _dy);
}

String Size::toString() {
    return "Size(${width.toStringAsFixed(1)}, ${height.toStringAsFixed(1)})";
}

void Rect::fromLTRB(double bottom, double left, double right, double top)

void Rect::fromLTWH(double height, double left, double top, double width)

void Rect::fromCircle(Offset center, double radius)

void Rect::fromCenter(Offset center, double height, double width)

void Rect::fromPoints(Offset a, Offset b)

double Rect::width() {
    return right - left;
}

double Rect::height() {
    return bottom - top;
}

Size Rect::size() {
    return Size(width, height);
}

bool Rect::hasNaN() {
    return left.isNaN || top.isNaN || right.isNaN || bottom.isNaN;
}

bool Rect::isInfinite() {
    return left >= double.infinity || top >= double.infinity || right >= double.infinity || bottom >= double.infinity;
}

bool Rect::isFinite() {
    return left.isFinite && top.isFinite && right.isFinite && bottom.isFinite;
}

bool Rect::isEmpty() {
    return left >= right || top >= bottom;
}

Rect Rect::shift(Offset offset) {
    return Rect.fromLTRB(left + offset.dx, top + offset.dy, right + offset.dx, bottom + offset.dy);
}

Rect Rect::translate(double translateX, double translateY) {
    return Rect.fromLTRB(left + translateX, top + translateY, right + translateX, bottom + translateY);
}

Rect Rect::inflate(double delta) {
    return Rect.fromLTRB(left - delta, top - delta, right + delta, bottom + delta);
}

Rect Rect::deflate(double delta) {
    return inflate(-delta);
}

Rect Rect::intersect(Rect other) {
    return Rect.fromLTRB(math.max(left, other.left), math.max(top, other.top), math.min(right, other.right), math.min(bottom, other.bottom));
}

Rect Rect::expandToInclude(Rect other) {
    return Rect.fromLTRB(math.min(left, other.left), math.min(top, other.top), math.max(right, other.right), math.max(bottom, other.bottom));
}

bool Rect::overlaps(Rect other) {
    if (right <= other.left || other.right <= left)     {
        return false;
    }
    if (bottom <= other.top || other.bottom <= top)     {
        return false;
    }
    return true;
}

double Rect::shortestSide() {
    return math.min(width.abs(), height.abs());
}

double Rect::longestSide() {
    return math.max(width.abs(), height.abs());
}

Offset Rect::topLeft() {
    return Offset(left, top);
}

Offset Rect::topCenter() {
    return Offset(left + width / 2.0, top);
}

Offset Rect::topRight() {
    return Offset(right, top);
}

Offset Rect::centerLeft() {
    return Offset(left, top + height / 2.0);
}

Offset Rect::center() {
    return Offset(left + width / 2.0, top + height / 2.0);
}

Offset Rect::centerRight() {
    return Offset(right, top + height / 2.0);
}

Offset Rect::bottomLeft() {
    return Offset(left, bottom);
}

Offset Rect::bottomCenter() {
    return Offset(left + width / 2.0, bottom);
}

Offset Rect::bottomRight() {
    return Offset(right, bottom);
}

bool Rect::contains(Offset offset) {
    return offset.dx >= left && offset.dx < right && offset.dy >= top && offset.dy < bottom;
}

Rect Rect::lerp(Rect a, Rect b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            double k = 1.0 - t;
            return Rect.fromLTRB(a.left * k, a.top * k, a.right * k, a.bottom * k);
        }
    } else {
        if (a == nullptr) {
            return Rect.fromLTRB(b.left * t, b.top * t, b.right * t, b.bottom * t);
        } else {
            return Rect.fromLTRB(_lerpDouble(a.left, b.left, t), _lerpDouble(a.top, b.top, t), _lerpDouble(a.right, b.right, t), _lerpDouble(a.bottom, b.bottom, t));
        }
    }
}

bool Rect::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (runtimeType != other.runtimeType)     {
        return false;
    }
    return other is Rect && other.left == left && other.top == top && other.right == right && other.bottom == bottom;
}

int Rect::hashCode() {
    return Object.hash(left, top, right, bottom);
}

String Rect::toString() {
    return "Rect.fromLTRB(${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)})";
}

Float32List Rect::_getValue32() {
    Float32List result = Float32List(4);
    result[0] = left;
    result[1] = top;
    result[2] = right;
    result[3] = bottom;
    return result;
}

void Radius::circular(double radius)

Radius Radius::-() {
    return Radius.elliptical(-x, -y);
}

Radius Radius::-(Radius other) {
    return Radius.elliptical(x - other.x, y - other.y);
}

Radius Radius::+(Radius other) {
    return Radius.elliptical(x + other.x, y + other.y);
}

Radius Radius::*(double operand) {
    return Radius.elliptical(x * operand, y * operand);
}

Radius Radius::/(double operand) {
    return Radius.elliptical(x / operand, y / operand);
}

Radius Radius::~/(double operand) {
    return Radius.elliptical((x ~/ operand).toDouble(), (y ~/ operand).toDouble());
}

Radius Radius::%(double operand) {
    return Radius.elliptical(x % operand, y % operand);
}

Radius Radius::lerp(Radius a, Radius b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            double k = 1.0 - t;
            return Radius.elliptical(a.x * k, a.y * k);
        }
    } else {
        if (a == nullptr) {
            return Radius.elliptical(b.x * t, b.y * t);
        } else {
            return Radius.elliptical(_lerpDouble(a.x, b.x, t), _lerpDouble(a.y, b.y, t));
        }
    }
}

bool Radius::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (runtimeType != other.runtimeType)     {
        return false;
    }
    return other is Radius && other.x == x && other.y == y;
}

int Radius::hashCode() {
    return Object.hash(x, y);
}

String Radius::toString() {
    return x == y? "Radius.circular(${x.toStringAsFixed(1)})" : "Radius.elliptical(${x.toStringAsFixed(1)}, ${y.toStringAsFixed(1)})";
}

void RRect::fromLTRBXY(double bottom, double left, double radiusX, double radiusY, double right, double top)

void RRect::fromLTRBR(double bottom, double left, Radius radius, double right, double top)

void RRect::fromRectXY(double radiusX, double radiusY, Rect rect)

void RRect::fromRectAndRadius(Radius radius, Rect rect)

void RRect::fromLTRBAndCorners(double bottom, Radius bottomLeft, Radius bottomRight, double left, double right, double top, Radius topLeft, Radius topRight)

void RRect::fromRectAndCorners(Radius bottomLeft, Radius bottomRight, Rect rect, Radius topLeft, Radius topRight)

Radius RRect::tlRadius() {
    return Radius.elliptical(tlRadiusX, tlRadiusY);
}

Radius RRect::trRadius() {
    return Radius.elliptical(trRadiusX, trRadiusY);
}

Radius RRect::brRadius() {
    return Radius.elliptical(brRadiusX, brRadiusY);
}

Radius RRect::blRadius() {
    return Radius.elliptical(blRadiusX, blRadiusY);
}

RRect RRect::shift(Offset offset) {
    return RRect._raw(left + offset.dx, top + offset.dy, right + offset.dx, bottom + offset.dy, tlRadiusX, tlRadiusY, trRadiusX, trRadiusY, blRadiusX, blRadiusY, brRadiusX, brRadiusY);
}

RRect RRect::inflate(double delta) {
    return RRect._raw(left - delta, top - delta, right + delta, bottom + delta, tlRadiusX + delta, tlRadiusY + delta, trRadiusX + delta, trRadiusY + delta, blRadiusX + delta, blRadiusY + delta, brRadiusX + delta, brRadiusY + delta);
}

RRect RRect::deflate(double delta) {
    return inflate(-delta);
}

double RRect::width() {
    return right - left;
}

double RRect::height() {
    return bottom - top;
}

Rect RRect::outerRect() {
    return Rect.fromLTRB(left, top, right, bottom);
}

Rect RRect::safeInnerRect() {
    double kInsetFactor = 0.29289321881;
    double leftRadius = math.max(blRadiusX, tlRadiusX);
    double topRadius = math.max(tlRadiusY, trRadiusY);
    double rightRadius = math.max(trRadiusX, brRadiusX);
    double bottomRadius = math.max(brRadiusY, blRadiusY);
    return Rect.fromLTRB(left + leftRadius * kInsetFactor, top + topRadius * kInsetFactor, right - rightRadius * kInsetFactor, bottom - bottomRadius * kInsetFactor);
}

Rect RRect::middleRect() {
    double leftRadius = math.max(blRadiusX, tlRadiusX);
    double topRadius = math.max(tlRadiusY, trRadiusY);
    double rightRadius = math.max(trRadiusX, brRadiusX);
    double bottomRadius = math.max(brRadiusY, blRadiusY);
    return Rect.fromLTRB(left + leftRadius, top + topRadius, right - rightRadius, bottom - bottomRadius);
}

Rect RRect::wideMiddleRect() {
    double topRadius = math.max(tlRadiusY, trRadiusY);
    double bottomRadius = math.max(brRadiusY, blRadiusY);
    return Rect.fromLTRB(left, top + topRadius, right, bottom - bottomRadius);
}

Rect RRect::tallMiddleRect() {
    double leftRadius = math.max(blRadiusX, tlRadiusX);
    double rightRadius = math.max(trRadiusX, brRadiusX);
    return Rect.fromLTRB(left + leftRadius, top, right - rightRadius, bottom);
}

bool RRect::isEmpty() {
    return left >= right || top >= bottom;
}

bool RRect::isFinite() {
    return left.isFinite && top.isFinite && right.isFinite && bottom.isFinite;
}

bool RRect::isRect() {
    return (tlRadiusX == 0.0 || tlRadiusY == 0.0) && (trRadiusX == 0.0 || trRadiusY == 0.0) && (blRadiusX == 0.0 || blRadiusY == 0.0) && (brRadiusX == 0.0 || brRadiusY == 0.0);
}

bool RRect::isStadium() {
    return tlRadius == trRadius && trRadius == brRadius && brRadius == blRadius && (width <= 2.0 * tlRadiusX || height <= 2.0 * tlRadiusY);
}

bool RRect::isEllipse() {
    return tlRadius == trRadius && trRadius == brRadius && brRadius == blRadius && width <= 2.0 * tlRadiusX && height <= 2.0 * tlRadiusY;
}

bool RRect::isCircle() {
    return width == height && isEllipse;
}

double RRect::shortestSide() {
    return math.min(width.abs(), height.abs());
}

double RRect::longestSide() {
    return math.max(width.abs(), height.abs());
}

bool RRect::hasNaN() {
    return left.isNaN || top.isNaN || right.isNaN || bottom.isNaN || trRadiusX.isNaN || trRadiusY.isNaN || tlRadiusX.isNaN || tlRadiusY.isNaN || brRadiusX.isNaN || brRadiusY.isNaN || blRadiusX.isNaN || blRadiusY.isNaN;
}

Offset RRect::center() {
    return Offset(left + width / 2.0, top + height / 2.0);
}

RRect RRect::scaleRadii() {
    double scale = 1.0;
    scale = _getMin(scale, blRadiusY, tlRadiusY, height);
    scale = _getMin(scale, tlRadiusX, trRadiusX, width);
    scale = _getMin(scale, trRadiusY, brRadiusY, height);
    scale = _getMin(scale, brRadiusX, blRadiusX, width);
    if ( < 1.0) {
        return RRect._raw(top, left, right, bottom, tlRadiusX * scale, tlRadiusY * scale, trRadiusX * scale, trRadiusY * scale, blRadiusX * scale, blRadiusY * scale, brRadiusX * scale, brRadiusY * scale);
    }
    return RRect._raw(top, left, right, bottom, tlRadiusX, tlRadiusY, trRadiusX, trRadiusY, blRadiusX, blRadiusY, brRadiusX, brRadiusY);
}

bool RRect::contains(Offset point) {
    if (point.dx < left || point.dx >= right || point.dy < top || point.dy >= bottom)     {
        return false;
    }
    RRect scaled = scaleRadii();
    double x;
    double y;
    double radiusX;
    double radiusY;
    if (point.dx < left + scaled.tlRadiusX && point.dy < top + scaled.tlRadiusY) {
        x = point.dx - left - scaled.tlRadiusX;
        y = point.dy - top - scaled.tlRadiusY;
        radiusX = scaled.tlRadiusX;
        radiusY = scaled.tlRadiusY;
    } else     {
        if (point.dx > right - scaled.trRadiusX && point.dy < top + scaled.trRadiusY) {
        x = point.dx - right + scaled.trRadiusX;
        y = point.dy - top - scaled.trRadiusY;
        radiusX = scaled.trRadiusX;
        radiusY = scaled.trRadiusY;
    } else     {
        if (point.dx > right - scaled.brRadiusX && point.dy > bottom - scaled.brRadiusY) {
        x = point.dx - right + scaled.brRadiusX;
        y = point.dy - bottom + scaled.brRadiusY;
        radiusX = scaled.brRadiusX;
        radiusY = scaled.brRadiusY;
    } else     {
        if (point.dx < left + scaled.blRadiusX && point.dy > bottom - scaled.blRadiusY) {
        x = point.dx - left - scaled.blRadiusX;
        y = point.dy - bottom + scaled.blRadiusY;
        radiusX = scaled.blRadiusX;
        radiusY = scaled.blRadiusY;
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

RRect RRect::lerp(RRect a, RRect b, double t) {
    assert(t != nullptr);
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            double k = 1.0 - t;
            return RRect._raw(a.left * k, a.top * k, a.right * k, a.bottom * k, a.tlRadiusX * k, a.tlRadiusY * k, a.trRadiusX * k, a.trRadiusY * k, a.brRadiusX * k, a.brRadiusY * k, a.blRadiusX * k, a.blRadiusY * k);
        }
    } else {
        if (a == nullptr) {
            return RRect._raw(b.left * t, b.top * t, b.right * t, b.bottom * t, b.tlRadiusX * t, b.tlRadiusY * t, b.trRadiusX * t, b.trRadiusY * t, b.brRadiusX * t, b.brRadiusY * t, b.blRadiusX * t, b.blRadiusY * t);
        } else {
            return RRect._raw(_lerpDouble(a.left, b.left, t), _lerpDouble(a.top, b.top, t), _lerpDouble(a.right, b.right, t), _lerpDouble(a.bottom, b.bottom, t), _lerpDouble(a.tlRadiusX, b.tlRadiusX, t), _lerpDouble(a.tlRadiusY, b.tlRadiusY, t), _lerpDouble(a.trRadiusX, b.trRadiusX, t), _lerpDouble(a.trRadiusY, b.trRadiusY, t), _lerpDouble(a.brRadiusX, b.brRadiusX, t), _lerpDouble(a.brRadiusY, b.brRadiusY, t), _lerpDouble(a.blRadiusX, b.blRadiusX, t), _lerpDouble(a.blRadiusY, b.blRadiusY, t));
        }
    }
}

bool RRect::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (runtimeType != other.runtimeType)     {
        return false;
    }
    return other is RRect && other.left == left && other.top == top && other.right == right && other.bottom == bottom && other.tlRadiusX == tlRadiusX && other.tlRadiusY == tlRadiusY && other.trRadiusX == trRadiusX && other.trRadiusY == trRadiusY && other.blRadiusX == blRadiusX && other.blRadiusY == blRadiusY && other.brRadiusX == brRadiusX && other.brRadiusY == brRadiusY;
}

int RRect::hashCode() {
    return Object.hash(left, top, right, bottom, tlRadiusX, tlRadiusY, trRadiusX, trRadiusY, blRadiusX, blRadiusY, brRadiusX, brRadiusY);
}

String RRect::toString() {
    String rect = "${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)}";
    if (tlRadius == trRadius && trRadius == brRadius && brRadius == blRadius) {
        if (tlRadius.x == tlRadius.y)         {
            return "RRect.fromLTRBR($rect, ${tlRadius.x.toStringAsFixed(1)})";
        }
        return "RRect.fromLTRBXY($rect, ${tlRadius.x.toStringAsFixed(1)}, ${tlRadius.y.toStringAsFixed(1)})";
    }
    return "RRect.fromLTRBAndCorners($rect, topLeft: $tlRadius, topRight: $trRadius, bottomRight: $brRadius, bottomLeft: $blRadius)";
}

void RRect::_raw(double blRadiusX, double blRadiusY, double bottom, double brRadiusX, double brRadiusY, double left, double right, double tlRadiusX, double tlRadiusY, double top, double trRadiusX, double trRadiusY)

Float32List RRect::_getValue32() {
    Float32List result = Float32List(12);
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

double RRect::_getMin(double limit, double min, double radius1, double radius2) {
    double sum = radius1 + radius2;
    if (sum > limit && sum != 0.0)     {
        return math.min(min, limit / sum);
    }
    return min;
}

RSTransform::RSTransform(double scos, double ssin, double tx, double ty) {
    {
        ;
    }
}

void RSTransform::fromComponents(double anchorX, double anchorY, double rotation, double scale, double translateX, double translateY) {
    double scos = math.cos(rotation) * scale;
    double ssin = math.sin(rotation) * scale;
    double tx = translateX + -scos * anchorX + ssin * anchorY;
    double ty = translateY + -ssin * anchorX - scos * anchorY;
    return RSTransform(scos, ssin, tx, ty);
}

double RSTransform::scos() {
    return _value[0];
}

double RSTransform::ssin() {
    return _value[1];
}

double RSTransform::tx() {
    return _value[2];
}

double RSTransform::ty() {
    return _value[3];
}
