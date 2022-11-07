#include "matrix_utils.hpp"
Offset MatrixUtils::getAsTranslation(Matrix4 transform) {
    assert(transform != nullptr);
    Float64List values = transform.storage;
    if (values[0] == 1.0 && values[1] == 0.0 && values[2] == 0.0 && values[3] == 0.0 && values[4] == 0.0 && values[5] == 1.0 && values[6] == 0.0 && values[7] == 0.0 && values[8] == 0.0 && values[9] == 0.0 && values[10] == 1.0 && values[11] == 0.0 && values[14] == 0.0 && values[15] == 1.0) {
        return Offset(values[12], values[13]);
    }
    return nullptr;
}

double MatrixUtils::getAsScale(Matrix4 transform) {
    assert(transform != nullptr);
    Float64List values = transform.storage;
    if (values[1] == 0.0 && values[2] == 0.0 && values[3] == 0.0 && values[4] == 0.0 && values[6] == 0.0 && values[7] == 0.0 && values[8] == 0.0 && values[9] == 0.0 && values[10] == 1.0 && values[11] == 0.0 && values[12] == 0.0 && values[13] == 0.0 && values[14] == 0.0 && values[15] == 1.0 && values[0] == values[5]) {
        return values[0];
    }
    return nullptr;
}

bool MatrixUtils::matrixEquals(Matrix4 a, Matrix4 b) {
    if (identical(a, b)) {
        return true;
    }
    assert(a != nullptr || b != nullptr);
    if (a == nullptr) {
        return isIdentity(b!);
    }
    if (b == nullptr) {
        return isIdentity(a);
    }
    assert(a != nullptr && b != nullptr);
    return a.storage[0] == b.storage[0] && a.storage[1] == b.storage[1] && a.storage[2] == b.storage[2] && a.storage[3] == b.storage[3] && a.storage[4] == b.storage[4] && a.storage[5] == b.storage[5] && a.storage[6] == b.storage[6] && a.storage[7] == b.storage[7] && a.storage[8] == b.storage[8] && a.storage[9] == b.storage[9] && a.storage[10] == b.storage[10] && a.storage[11] == b.storage[11] && a.storage[12] == b.storage[12] && a.storage[13] == b.storage[13] && a.storage[14] == b.storage[14] && a.storage[15] == b.storage[15];
}

bool MatrixUtils::isIdentity(Matrix4 a) {
    assert(a != nullptr);
    return a.storage[0] == 1.0 && a.storage[1] == 0.0 && a.storage[2] == 0.0 && a.storage[3] == 0.0 && a.storage[4] == 0.0 && a.storage[5] == 1.0 && a.storage[6] == 0.0 && a.storage[7] == 0.0 && a.storage[8] == 0.0 && a.storage[9] == 0.0 && a.storage[10] == 1.0 && a.storage[11] == 0.0 && a.storage[12] == 0.0 && a.storage[13] == 0.0 && a.storage[14] == 0.0 && a.storage[15] == 1.0;
}

Offset MatrixUtils::transformPoint(Offset point, Matrix4 transform) {
    Float64List storage = transform.storage;
    double x = point.dx;
    double y = point.dy;
    double rx = storage[0] * x + storage[4] * y + storage[12];
    double ry = storage[1] * x + storage[5] * y + storage[13];
    double rw = storage[3] * x + storage[7] * y + storage[15];
    if (rw == 1.0) {
        return Offset(rx, ry);
    } else {
        return Offset(rx / rw, ry / rw);
    }
}

Rect MatrixUtils::transformRect(Rect rect, Matrix4 transform) {
    Float64List storage = transform.storage;
    double x = rect.left;
    double y = rect.top;
    double w = rect.right - x;
    double h = rect.bottom - y;
    if (!w.isFinite || !h.isFinite) {
        return _safeTransformRect(transform, rect);
    }
    double wx = storage[0] * w;
    double hx = storage[4] * h;
    double rx = storage[0] * x + storage[4] * y + storage[12];
    double wy = storage[1] * w;
    double hy = storage[5] * h;
    double ry = storage[1] * x + storage[5] * y + storage[13];
    if (storage[3] == 0.0 && storage[7] == 0.0 && storage[15] == 1.0) {
        double left = rx;
        double right = rx;
        if ( < 0) {
            left = wx;
        } else {
            right = wx;
        }
        if ( < 0) {
            left = hx;
        } else {
            right = hx;
        }
        double top = ry;
        double bottom = ry;
        if ( < 0) {
            top = wy;
        } else {
            bottom = wy;
        }
        if ( < 0) {
            top = hy;
        } else {
            bottom = hy;
        }
        return Rect.fromLTRB(left, top, right, bottom);
    } else {
        double ww = storage[3] * w;
        double hw = storage[7] * h;
        double rw = storage[3] * x + storage[7] * y + storage[15];
        double ulx = rx / rw;
        double uly = ry / rw;
        double urx = (rx + wx) / (rw + ww);
        double ury = (ry + wy) / (rw + ww);
        double llx = (rx + hx) / (rw + hw);
        double lly = (ry + hy) / (rw + hw);
        double lrx = (rx + wx + hx) / (rw + ww + hw);
        double lry = (ry + wy + hy) / (rw + ww + hw);
        return Rect.fromLTRB(_min4(ulx, urx, llx, lrx), _min4(uly, ury, lly, lry), _max4(ulx, urx, llx, lrx), _max4(uly, ury, lly, lry));
    }
}

Rect MatrixUtils::inverseTransformRect(Rect rect, Matrix4 transform) {
    assert(rect != nullptr);
    if (isIdentity(transform)) {
        return rect;
    }
    transform = ;
    return transformRect(transform, rect);
}

Matrix4 MatrixUtils::createCylindricalProjectionTransform(double angle, Axis orientation, double perspective, double radius) {
    assert(radius != nullptr);
    assert(angle != nullptr);
    assert(perspective >= 0 && perspective <= 1.0);
    assert(orientation != nullptr);
    Matrix4 result = ;
    result = (;
    return result;
}

Matrix4 MatrixUtils::forceToPoint(Offset offset) {
    return ;
}

Rect MatrixUtils::_safeTransformRect(Rect rect, Matrix4 transform) {
    Float64List storage = transform.storage;
    bool isAffine = storage[3] == 0.0 && storage[7] == 0.0 && storage[15] == 1.0;
    _accumulate(storage, rect.left, rect.top, true, isAffine);
    _accumulate(storage, rect.right, rect.top, false, isAffine);
    _accumulate(storage, rect.left, rect.bottom, false, isAffine);
    _accumulate(storage, rect.right, rect.bottom, false, isAffine);
    return Rect.fromLTRB(_minMax[0], _minMax[1], _minMax[2], _minMax[3]);
}

void MatrixUtils::_accumulate(bool first, bool isAffine, Float64List m, double x, double y) {
    double w = isAffine? 1.0 : 1.0 / (m[3] * x + m[7] * y + m[15]);
    double tx = (m[0] * x + m[4] * y + m[12]) * w;
    double ty = (m[1] * x + m[5] * y + m[13]) * w;
    if (first) {
        _minMax[0] = _minMax[2] = tx;
        _minMax[1] = _minMax[3] = ty;
    } else {
        if ( < _minMax[0]) {
            _minMax[0] = tx;
        }
        if ( < _minMax[1]) {
            _minMax[1] = ty;
        }
        if (tx > _minMax[2]) {
            _minMax[2] = tx;
        }
        if (ty > _minMax[3]) {
            _minMax[3] = ty;
        }
    }
}

double MatrixUtils::_min4(double a, double b, double c, double d) {
    double e = ( < b)? a : b;
    double f = ( < d)? c : d;
    return ( < f)? e : f;
}

double MatrixUtils::_max4(double a, double b, double c, double d) {
    double e = (a > b)? a : b;
    double f = (c > d)? c : d;
    return (e > f)? e : f;
}

List<String> debugDescribeTransform(Matrix4 transform) {
    if (transform == nullptr) {
        return const ;
    }
    return ;
}

TransformProperty::TransformProperty(Unknown, Unknown, String name, Unknown, Unknown) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
    }
}

String TransformProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (parentConfiguration != nullptr && !parentConfiguration.lineBreakProperties) {
        List<String> values = ;
        return "[${values.join('; ')}]";
    }
    return debugDescribeTransform(value).join("\n");
}
