#include "matrix_utils.hpp"
Offset MatrixUtilsCls::getAsTranslation(Matrix4 transform) {
    assert(transform != nullptr);
    Float64List values = transform->storage();
    if (values[0] == 1.0 && values[1] == 0.0 && values[2] == 0.0 && values[3] == 0.0 && values[4] == 0.0 && values[5] == 1.0 && values[6] == 0.0 && values[7] == 0.0 && values[8] == 0.0 && values[9] == 0.0 && values[10] == 1.0 && values[11] == 0.0 && values[14] == 0.0 && values[15] == 1.0) {
        return make<OffsetCls>(values[12], values[13]);
    }
    return nullptr;
}

double MatrixUtilsCls::getAsScale(Matrix4 transform) {
    assert(transform != nullptr);
    Float64List values = transform->storage();
    if (values[1] == 0.0 && values[2] == 0.0 && values[3] == 0.0 && values[4] == 0.0 && values[6] == 0.0 && values[7] == 0.0 && values[8] == 0.0 && values[9] == 0.0 && values[10] == 1.0 && values[11] == 0.0 && values[12] == 0.0 && values[13] == 0.0 && values[14] == 0.0 && values[15] == 1.0 && values[0] == values[5]) {
        return values[0];
    }
    return nullptr;
}

bool MatrixUtilsCls::matrixEquals(Matrix4 a, Matrix4 b) {
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
    return a->storage()[0] == b->storage()[0] && a->storage()[1] == b->storage()[1] && a->storage()[2] == b->storage()[2] && a->storage()[3] == b->storage()[3] && a->storage()[4] == b->storage()[4] && a->storage()[5] == b->storage()[5] && a->storage()[6] == b->storage()[6] && a->storage()[7] == b->storage()[7] && a->storage()[8] == b->storage()[8] && a->storage()[9] == b->storage()[9] && a->storage()[10] == b->storage()[10] && a->storage()[11] == b->storage()[11] && a->storage()[12] == b->storage()[12] && a->storage()[13] == b->storage()[13] && a->storage()[14] == b->storage()[14] && a->storage()[15] == b->storage()[15];
}

bool MatrixUtilsCls::isIdentity(Matrix4 a) {
    assert(a != nullptr);
    return a->storage()[0] == 1.0 && a->storage()[1] == 0.0 && a->storage()[2] == 0.0 && a->storage()[3] == 0.0 && a->storage()[4] == 0.0 && a->storage()[5] == 1.0 && a->storage()[6] == 0.0 && a->storage()[7] == 0.0 && a->storage()[8] == 0.0 && a->storage()[9] == 0.0 && a->storage()[10] == 1.0 && a->storage()[11] == 0.0 && a->storage()[12] == 0.0 && a->storage()[13] == 0.0 && a->storage()[14] == 0.0 && a->storage()[15] == 1.0;
}

Offset MatrixUtilsCls::transformPoint(Offset point, Matrix4 transform) {
    Float64List storage = transform->storage();
    double x = point->dx();
    double y = point->dy();
    double rx = storage[0] * x + storage[4] * y + storage[12];
    double ry = storage[1] * x + storage[5] * y + storage[13];
    double rw = storage[3] * x + storage[7] * y + storage[15];
    if (rw == 1.0) {
        return make<OffsetCls>(rx, ry);
    } else {
        return make<OffsetCls>(rx / rw, ry / rw);
    }
}

Rect MatrixUtilsCls::transformRect(Rect rect, Matrix4 transform) {
    Float64List storage = transform->storage();
    double x = rect->left;
    double y = rect->top;
    double w = rect->right - x;
    double h = rect->bottom - y;
    if (!w->isFinite || !h->isFinite) {
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
        return RectCls->fromLTRB(left, top, right, bottom);
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
        return RectCls->fromLTRB(_min4(ulx, urx, llx, lrx), _min4(uly, ury, lly, lry), _max4(ulx, urx, llx, lrx), _max4(uly, ury, lly, lry));
    }
}

Rect MatrixUtilsCls::inverseTransformRect(Rect rect, Matrix4 transform) {
    assert(rect != nullptr);
    if (isIdentity(transform)) {
        return rect;
    }
    auto _c1 = Matrix4Cls->copy(transform);_c1.invert();transform = _c1;
    return transformRect(transform, rect);
}

Matrix4 MatrixUtilsCls::createCylindricalProjectionTransform(double angle, Axis orientation, double perspective, double radius) {
    assert(radius != nullptr);
    assert(angle != nullptr);
    assert(perspective >= 0 && perspective <= 1.0);
    assert(orientation != nullptr);
    auto _c1 = Matrix4Cls->identity();_c1.auto _c2 = setEntry(3, 2, -perspective);_c2.auto _c3 = setEntry(2, 3, -radius);_c3.setEntry(3, 3, perspective * radius + 1.0);_c3;_c2;Matrix4 result = _c1;
    result = as<Matrix4>(result * ((orientation == AxisCls::horizontal? Matrix4Cls->rotationY(angle) : Matrix4Cls->rotationX(angle)) * Matrix4Cls->translationValues(0.0, 0.0, radius)));
    return result;
}

Matrix4 MatrixUtilsCls::forceToPoint(Offset offset) {
    auto _c1 = Matrix4Cls->identity();_c1.auto _c2 = setRow(0, make<Vector4Cls>(0, 0, 0, offset->dx()));_c2.setRow(1, make<Vector4Cls>(0, 0, 0, offset->dy()));_c2;return _c1;
}

Rect MatrixUtilsCls::_safeTransformRect(Rect rect, Matrix4 transform) {
    Float64List storage = transform->storage();
    bool isAffine = storage[3] == 0.0 && storage[7] == 0.0 && storage[15] == 1.0;
    _accumulate(storage, rect->left, rect->top, true, isAffine);
    _accumulate(storage, rect->right, rect->top, false, isAffine);
    _accumulate(storage, rect->left, rect->bottom, false, isAffine);
    _accumulate(storage, rect->right, rect->bottom, false, isAffine);
    return RectCls->fromLTRB(_minMax[0], _minMax[1], _minMax[2], _minMax[3]);
}

void MatrixUtilsCls::_accumulate(bool first, bool isAffine, Float64List m, double x, double y) {
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

double MatrixUtilsCls::_min4(double a, double b, double c, double d) {
    double e = ( < b)? a : b;
    double f = ( < d)? c : d;
    return ( < f)? e : f;
}

double MatrixUtilsCls::_max4(double a, double b, double c, double d) {
    double e = (a > b)? a : b;
    double f = (c > d)? c : d;
    return (e > f)? e : f;
}

List<String> debugDescribeTransform(Matrix4 transform) {
    if (transform == nullptr) {
        return makeList(ArrayItem);
    }
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
}

TransformPropertyCls::TransformPropertyCls(Unknown defaultValue, Unknown level, String name, Unknown showName, Unknown value) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
    }
}

String TransformPropertyCls::valueToString(TextTreeConfiguration parentConfiguration) {
    if (parentConfiguration != nullptr && !parentConfiguration->lineBreakProperties) {
        List<String> values = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
        return __s("[${values.join('; ')}]");
    }
    return debugDescribeTransform(value)->join(__s("\n"));
}
