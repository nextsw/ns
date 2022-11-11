#include "curves.hpp"
template<typename T>
T ParametricCurveCls<T>::transform(double t) {
    assert(t != nullptr);
    assert(t >= 0.0 && t <= 1.0, __s("parametric value $t is outside of [0, 1] range."));
    return transformInternal(t);
}

template<typename T>
T ParametricCurveCls<T>::transformInternal(double t) {
    ;
}

template<typename T>
String ParametricCurveCls<T>::toString() {
    return objectRuntimeType(this, __s("ParametricCurve"));
}

double CurveCls::transform(double t) {
    if (t == 0.0 || t == 1.0) {
        return t;
    }
    return super->transform(t);
}

Curve CurveCls::flipped() {
    return make<FlippedCurveCls>(this);
}

double _LinearCls::transformInternal(double t) {
    return t;
}

SawToothCls::SawToothCls(int count) {
    {
        assert(count != nullptr);
    }
}

double SawToothCls::transformInternal(double t) {
    t = count;
    return t - t->truncateToDouble();
}

String SawToothCls::toString() {
    return __s("${objectRuntimeType(this, 'SawTooth')}($count)");
}

IntervalCls::IntervalCls(double begin, Curve curve, double end) {
    {
        assert(begin != nullptr);
        assert(end != nullptr);
        assert(curve != nullptr);
    }
}

double IntervalCls::transformInternal(double t) {
    assert(begin >= 0.0);
    assert(begin <= 1.0);
    assert(end >= 0.0);
    assert(end <= 1.0);
    assert(end >= begin);
    t = clampDouble((t - begin) / (end - begin), 0.0, 1.0);
    if (t == 0.0 || t == 1.0) {
        return t;
    }
    return curve->transform(t);
}

String IntervalCls::toString() {
    if (!is<_Linear>(curve)) {
        return __s("${objectRuntimeType(this, 'Interval')}($begin\u22EF$end)\u27A9$curve");
    }
    return __s("${objectRuntimeType(this, 'Interval')}($begin\u22EF$end)");
}

ThresholdCls::ThresholdCls(double threshold) {
    {
        assert(threshold != nullptr);
    }
}

double ThresholdCls::transformInternal(double t) {
    assert(threshold >= 0.0);
    assert(threshold <= 1.0);
    return  < threshold? 0.0 : 1.0;
}

CubicCls::CubicCls(double a, double b, double c, double d) {
    {
        assert(a != nullptr);
        assert(b != nullptr);
        assert(c != nullptr);
        assert(d != nullptr);
    }
}

double CubicCls::transformInternal(double t) {
    double start = 0.0;
    double end = 1.0;
    while (true) {
        double midpoint = (start + end) / 2;
        double estimate = _evaluateCubic(a, c, midpoint);
        if ((t - estimate)->abs() < _cubicErrorBound) {
            return _evaluateCubic(b, d, midpoint);
        }
        if ( < t) {
            start = midpoint;
        } else {
            end = midpoint;
        }
    }
}

String CubicCls::toString() {
    return __s("${objectRuntimeType(this, 'Cubic')}(${a.toStringAsFixed(2)}, ${b.toStringAsFixed(2)}, ${c.toStringAsFixed(2)}, ${d.toStringAsFixed(2)})");
}

double CubicCls::_evaluateCubic(double a, double b, double m) {
    return 3 * a * (1 - m) * (1 - m) * m + 3 * b * (1 - m) * m * m + m * m * m;
}

double ThreePointCubicCls::transformInternal(double t) {
    bool firstCurve =  < midpoint->dx();
    double scaleX = firstCurve? midpoint->dx() : 1.0 - midpoint->dx();
    double scaleY = firstCurve? midpoint->dy() : 1.0 - midpoint->dy();
    double scaledT = (t - (firstCurve? 0.0 : midpoint->dx())) / scaleX;
    if (firstCurve) {
        return make<CubicCls>(a1->dx() / scaleX, a1->dy() / scaleY, b1->dx() / scaleX, b1->dy() / scaleY)->transform(scaledT) * scaleY;
    } else {
        return make<CubicCls>((a2->dx() - midpoint->dx()) / scaleX, (a2->dy() - midpoint->dy()) / scaleY, (b2->dx() - midpoint->dx()) / scaleX, (b2->dy() - midpoint->dy()) / scaleY)->transform(scaledT) * scaleY + midpoint->dy();
    }
}

String ThreePointCubicCls::toString() {
    return __s("${objectRuntimeType(this, 'ThreePointCubic($a1, $b1, $midpoint, $a2, $b2)')} ");
}

Iterable<Curve2DSample> Curve2DCls::generateSamples(double end, double start, double tolerance) {
    assert(tolerance != nullptr);
    assert(start != nullptr);
    assert(end != nullptr);
    assert(end > start);
    Random rand = math->make<RandomCls>(samplingSeed());
    InlineMethod;
    Curve2DSample first = make<Curve2DSampleCls>(start, transform(start));
    Curve2DSample last = make<Curve2DSampleCls>(end, transform(end));
    List<Curve2DSample> samples = makeList(ArrayItem);
    InlineMethod;
    sample(first, last(first->value->dx() - last->value->dx())->abs() < tolerance && (first->value->dy() - last->value->dy())->abs() < tolerance);
    return samples;
}

int Curve2DCls::samplingSeed() {
    return 0;
}

double Curve2DCls::findInverse(double x) {
    assert(x != nullptr);
    double start = 0.0;
    double end = 1.0;
    double mid;
    InlineMethod;
    double errorLimit = 1e-6;
    int count = 100;
    double startValue = offsetToOrigin(start);
    while ((end - start) / 2.0 > errorLimit && count > 0) {
        mid = (end + start) / 2.0;
        double value = offsetToOrigin(mid);
        if (value->sign() == startValue->sign()) {
            start = mid;
        } else {
            end = mid;
        }
        count--;
    }
    return mid;
}

Curve2DSampleCls::Curve2DSampleCls(double t, Offset value) {
    {
        assert(t != nullptr);
        assert(value != nullptr);
    }
}

String Curve2DSampleCls::toString() {
    return __s("[(${value.dx.toStringAsFixed(2)}, ${value.dy.toStringAsFixed(2)}), ${t.toStringAsFixed(2)}]");
}

CatmullRomSplineCls::CatmullRomSplineCls(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension) {
    {
        assert(controlPoints != nullptr);
        assert(tension != nullptr);
        assert(tension <= 1.0, __s("tension $tension must not be greater than 1.0."));
        assert(tension >= 0.0, __s("tension $tension must not be negative."));
        assert(controlPoints->length() > 3, __s("There must be at least four control points to create a CatmullRomSpline."));
        _controlPoints = controlPoints;
        _startHandle = startHandle;
        _endHandle = endHandle;
        _tension = tension;
        _cubicSegments = makeList();
    }
}

void CatmullRomSplineCls::precompute(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension)

int CatmullRomSplineCls::samplingSeed() {
    _initializeIfNeeded();
    Offset seedPoint = _cubicSegments[0][1];
    return ((seedPoint->dx() + seedPoint->dy()) * 10000)->round();
}

Offset CatmullRomSplineCls::transformInternal(double t) {
    _initializeIfNeeded();
    double length = _cubicSegments->length()->toDouble();
    double position;
    double localT;
    int index;
    if ( < 1.0) {
        position = t * length;
        localT = position % 1.0;
        index = position->floor();
    } else {
        position = length;
        localT = 1.0;
        index = _cubicSegments->length - 1;
    }
    List<Offset> cubicControlPoints = _cubicSegments[index];
    double localT2 = localT * localT;
    return cubicControlPoints[0] * localT2 * localT + cubicControlPoints[1] * localT2 + cubicControlPoints[2] * localT + cubicControlPoints[3];
}

List<List<Offset>> CatmullRomSplineCls::_computeSegments(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension) {
    startHandle = controlPoints[0] * 2.0 - controlPoints[1];
    endHandle = controlPoints->last * 2.0 - controlPoints[controlPoints->length() - 2];
    List<Offset> list1 = make<ListCls<>>();list1.add(ArrayItem);for (auto _x1 : controlPoints) {{    list1.add(_x1);}list1.add(ArrayItem);List<Offset> allPoints = list1;
    double alpha = 0.5;
    double reverseTension = 1.0 - tension;
    List<List<Offset>> result = makeList();
    for (;  < allPoints->length() - 3; ++i) {
        List<Offset> curve = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
        Offset diffCurve10 = curve[1] - curve[0];
        Offset diffCurve21 = curve[2] - curve[1];
        Offset diffCurve32 = curve[3] - curve[2];
        double t01 = math->pow(diffCurve10->distance(), alpha)->toDouble();
        double t12 = math->pow(diffCurve21->distance(), alpha)->toDouble();
        double t23 = math->pow(diffCurve32->distance(), alpha)->toDouble();
        Offset m1 = (diffCurve21 + (diffCurve10 / t01 - (curve[2] - curve[0]) / (t01 + t12)) * t12) * reverseTension;
        Offset m2 = (diffCurve21 + (diffCurve32 / t23 - (curve[3] - curve[1]) / (t12 + t23)) * t12) * reverseTension;
        Offset sumM12 = m1 + m2;
        List<Offset> segment = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
        result->add(segment);
    }
    return result;
}

void CatmullRomSplineCls::_initializeIfNeeded() {
    if (_cubicSegments->isNotEmpty) {
        return;
    }
    _cubicSegments->addAll(_computeSegments(_controlPoints!, _tension!_startHandle, _endHandle));
}

CatmullRomCurveCls::CatmullRomCurveCls(List<Offset> controlPoints, double tension) {
    {
        assert(tension != nullptr);
        assert([=] () {
                    auto _c1 = _debugAssertReasons;        _c1.clear();return validateControlPoints(controlPointstension, _c1);
        }(), __s("control points $controlPoints could not be validated:\n  ${_debugAssertReasons.join('\n  ')}"));
        _precomputedSamples = makeList();
    }
}

void CatmullRomCurveCls::precompute(List<Offset> controlPoints, double tension)

bool CatmullRomCurveCls::validateControlPoints(List<Offset> controlPoints, List<String> reasons, double tension) {
    assert(tension != nullptr);
    if (controlPoints == nullptr) {
        assert([=] () {
            reasons?->add(__s("Supplied control points cannot be null"));
            return true;
        }());
        return false;
    }
    if (controlPoints->length() < 2) {
        assert([=] () {
            reasons?->add(__s("There must be at least two points supplied to create a valid curve."));
            return true;
        }());
        return false;
    }
    List<Offset> list1 = make<ListCls<>>();list1.add(ArrayItem);for (auto _x1 : controlPoints) {{    list1.add(_x1);}list1.add(ArrayItem);controlPoints = list1;
    Offset startHandle = controlPoints[0] * 2.0 - controlPoints[1];
    Offset endHandle = controlPoints->last * 2.0 - controlPoints[controlPoints->length() - 2];
    List<Offset> list2 = make<ListCls<>>();list2.add(ArrayItem);for (auto _x2 : controlPoints) {{    list2.add(_x2);}list2.add(ArrayItem);controlPoints = list2;
    double lastX = -double->infinity;
    for (;  < controlPoints->length(); ++i) {
        if (i > 1 &&  < controlPoints->length() - 2 && (controlPoints[i]->dx() <= 0.0 || controlPoints[i]->dx() >= 1.0)) {
            assert([=] () {
                reasons?->add(__s("Control points must have X values between 0.0 and 1.0, exclusive. Point $i has an x value (${controlPoints![i].dx}) which is outside the range."));
                return true;
            }());
            return false;
        }
        if (controlPoints[i]->dx() <= lastX) {
            assert([=] () {
                reasons?->add(__s("Each X coordinate must be greater than the preceding X coordinate (i.e. must be monotonically increasing in X). Point $i has an x value of ${controlPoints![i].dx}, which is not greater than $lastX"));
                return true;
            }());
            return false;
        }
        lastX = controlPoints[i]->dx();
    }
    bool success = true;
    lastX = -double->infinity;
    double tolerance = 1e-3;
    CatmullRomSpline testSpline = make<CatmullRomSplineCls>(controlPointstension);
    double start = testSpline->findInverse(0.0);
    double end = testSpline->findInverse(1.0);
    Iterable<Curve2DSample> samplePoints = testSpline->generateSamples(start, end);
    if (samplePoints->first()->value->dy->abs() > tolerance || (1.0 - samplePoints->last()->value->dy)->abs() > tolerance) {
        bool bail = true;
        success = false;
        assert([=] () {
            reasons?->add(__s("The curve has more than one Y value at X = ${samplePoints.first.value.dx}. Try moving some control points further away from this value of X, or increasing the tension."));
            bail = reasons == nullptr;
            return true;
        }());
        if (bail) {
            return false;
        }
    }
    for (Curve2DSample sample : samplePoints) {
        Offset point = sample->value;
        double t = sample->t;
        double x = point->dx();
        if (t >= start && t <= end && ( < -1e-3 || x > 1.0 + 1e-3)) {
            bool bail = true;
            success = false;
            assert([=] () {
                reasons?->add(__s("The resulting curve has an X value ($x) which is outside the range [0.0, 1.0], inclusive."));
                bail = reasons == nullptr;
                return true;
            }());
            if (bail) {
                return false;
            }
        }
        if ( < lastX) {
            bool bail = true;
            success = false;
            assert([=] () {
                reasons?->add(__s("The curve has more than one Y value at x = $x. Try moving some control points further apart in X, or increasing the tension."));
                bail = reasons == nullptr;
                return true;
            }());
            if (bail) {
                return false;
            }
        }
        lastX = x;
    }
    return success;
}

double CatmullRomCurveCls::transformInternal(double t) {
    if (_precomputedSamples->isEmpty) {
        _precomputedSamples->addAll(_computeSamples(controlPoints, tension));
    }
    int start = 0;
    int end = _precomputedSamples->length() - 1;
    int mid;
    Offset value;
    Offset startValue = _precomputedSamples[start]->value;
    Offset endValue = _precomputedSamples[end]->value;
    while (end - start > 1) {
        mid = (end + start) ~/ 2;
        value = _precomputedSamples[mid]->value;
        if (t >= value->dx()) {
            start = mid;
            startValue = value;
        } else {
            end = mid;
            endValue = value;
        }
    }
    double t2 = (t - startValue->dx()) / (endValue->dx() - startValue->dx());
    return lerpDouble(startValue->dy(), endValue->dy(), t2)!;
}

List<Curve2DSample> CatmullRomCurveCls::_computeSamples(List<Offset> controlPoints, double tension) {
    List<Offset> list1 = make<ListCls<>>();list1.add(ArrayItem);for (auto _x1 : controlPoints) {{    list1.add(_x1);}list1.add(ArrayItem);return CatmullRomSplineCls->precompute(list1tension)->generateSamples(1e-12)->toList();
}

FlippedCurveCls::FlippedCurveCls(Curve curve) {
    {
        assert(curve != nullptr);
    }
}

double FlippedCurveCls::transformInternal(double t) {
    return 1.0 - curve->transform(1.0 - t);
}

String FlippedCurveCls::toString() {
    return __s("${objectRuntimeType(this, 'FlippedCurve')}($curve)");
}

double _DecelerateCurveCls::transformInternal(double t) {
    t = 1.0 - t;
    return 1.0 - t * t;
}

double _bounce(double t) {
    if ( < 1.0 / 2.75) {
        return 7.5625 * t * t;
    } else     {
        if ( < 2 / 2.75) {
        t = 1.5 / 2.75;
        return 7.5625 * t * t + 0.75;
    } else     {
        if ( < 2.5 / 2.75) {
        t = 2.25 / 2.75;
        return 7.5625 * t * t + 0.9375;
    }
;
    };
    }    t = 2.625 / 2.75;
    return 7.5625 * t * t + 0.984375;
}

double _BounceInCurveCls::transformInternal(double t) {
    return 1.0 - _bounce(1.0 - t);
}

double _BounceOutCurveCls::transformInternal(double t) {
    return _bounce(t);
}

double _BounceInOutCurveCls::transformInternal(double t) {
    if ( < 0.5) {
        return (1.0 - _bounce(1.0 - t * 2.0)) * 0.5;
    } else {
        return _bounce(t * 2.0 - 1.0) * 0.5 + 0.5;
    }
}

double ElasticInCurveCls::transformInternal(double t) {
    double s = period / 4.0;
    t = t - 1.0;
    return -math->pow(2.0, 10.0 * t) * math->sin((t - s) * (math->pi * 2.0) / period);
}

String ElasticInCurveCls::toString() {
    return __s("${objectRuntimeType(this, 'ElasticInCurve')}($period)");
}

double ElasticOutCurveCls::transformInternal(double t) {
    double s = period / 4.0;
    return math->pow(2.0, -10 * t) * math->sin((t - s) * (math->pi * 2.0) / period) + 1.0;
}

String ElasticOutCurveCls::toString() {
    return __s("${objectRuntimeType(this, 'ElasticOutCurve')}($period)");
}

double ElasticInOutCurveCls::transformInternal(double t) {
    double s = period / 4.0;
    t = 2.0 * t - 1.0;
    if ( < 0.0) {
        return -0.5 * math->pow(2.0, 10.0 * t) * math->sin((t - s) * (math->pi * 2.0) / period);
    } else {
        return math->pow(2.0, -10.0 * t) * math->sin((t - s) * (math->pi * 2.0) / period) * 0.5 + 1.0;
    }
}

String ElasticInOutCurveCls::toString() {
    return __s("${objectRuntimeType(this, 'ElasticInOutCurve')}($period)");
}
