#include "curves.hpp"
T ParametricCurve::transform(double t) {
    assert(t != nullptr);
    assert(t >= 0.0 && t <= 1.0, "parametric value $t is outside of [0, 1] range.");
    return transformInternal(t);
}

T ParametricCurve::transformInternal(double t) {
    ;
}

String ParametricCurve::toString() {
    return objectRuntimeType(this, "ParametricCurve");
}

double Curve::transform(double t) {
    if (t == 0.0 || t == 1.0) {
        return t;
    }
    return super.transform(t);
}

Curve Curve::flipped() {
    return FlippedCurve(this);
}

double _Linear::transformInternal(double t) {
    return t;
}

SawTooth::SawTooth(int count) {
    {
        assert(count != nullptr);
    }
}

double SawTooth::transformInternal(double t) {
    t = count;
    return t - t.truncateToDouble();
}

String SawTooth::toString() {
    return "${objectRuntimeType(this, 'SawTooth')}($count)";
}

Interval::Interval(double begin, Curve curve, double end) {
    {
        assert(begin != nullptr);
        assert(end != nullptr);
        assert(curve != nullptr);
    }
}

double Interval::transformInternal(double t) {
    assert(begin >= 0.0);
    assert(begin <= 1.0);
    assert(end >= 0.0);
    assert(end <= 1.0);
    assert(end >= begin);
    t = clampDouble((t - begin) / (end - begin), 0.0, 1.0);
    if (t == 0.0 || t == 1.0) {
        return t;
    }
    return curve.transform(t);
}

String Interval::toString() {
    if (curve is! _Linear) {
        return "${objectRuntimeType(this, 'Interval')}($begin\u22EF$end)\u27A9$curve";
    }
    return "${objectRuntimeType(this, 'Interval')}($begin\u22EF$end)";
}

Threshold::Threshold(double threshold) {
    {
        assert(threshold != nullptr);
    }
}

double Threshold::transformInternal(double t) {
    assert(threshold >= 0.0);
    assert(threshold <= 1.0);
    return  < threshold? 0.0 : 1.0;
}

Cubic::Cubic(double a, double b, double c, double d) {
    {
        assert(a != nullptr);
        assert(b != nullptr);
        assert(c != nullptr);
        assert(d != nullptr);
    }
}

double Cubic::transformInternal(double t) {
    double start = 0.0;
    double end = 1.0;
    while (true) {
        double midpoint = (start + end) / 2;
        double estimate = _evaluateCubic(a, c, midpoint);
        if ((t - estimate).abs() < _cubicErrorBound) {
            return _evaluateCubic(b, d, midpoint);
        }
        if ( < t) {
            start = midpoint;
        } else {
            end = midpoint;
        }
    }
}

String Cubic::toString() {
    return "${objectRuntimeType(this, 'Cubic')}(${a.toStringAsFixed(2)}, ${b.toStringAsFixed(2)}, ${c.toStringAsFixed(2)}, ${d.toStringAsFixed(2)})";
}

double Cubic::_evaluateCubic(double a, double b, double m) {
    return 3 * a * (1 - m) * (1 - m) * m + 3 * b * (1 - m) * m * m + m * m * m;
}

double ThreePointCubic::transformInternal(double t) {
    bool firstCurve =  < midpoint.dx;
    double scaleX = firstCurve? midpoint.dx : 1.0 - midpoint.dx;
    double scaleY = firstCurve? midpoint.dy : 1.0 - midpoint.dy;
    double scaledT = (t - (firstCurve? 0.0 : midpoint.dx)) / scaleX;
    if (firstCurve) {
        return Cubic(a1.dx / scaleX, a1.dy / scaleY, b1.dx / scaleX, b1.dy / scaleY).transform(scaledT) * scaleY;
    } else {
        return Cubic((a2.dx - midpoint.dx) / scaleX, (a2.dy - midpoint.dy) / scaleY, (b2.dx - midpoint.dx) / scaleX, (b2.dy - midpoint.dy) / scaleY).transform(scaledT) * scaleY + midpoint.dy;
    }
}

String ThreePointCubic::toString() {
    return "${objectRuntimeType(this, 'ThreePointCubic($a1, $b1, $midpoint, $a2, $b2)')} ";
}

Iterable<Curve2DSample> Curve2D::generateSamples(double end, double start, double tolerance) {
    assert(tolerance != nullptr);
    assert(start != nullptr);
    assert(end != nullptr);
    assert(end > start);
    Random rand = math.Random(samplingSeed);
    ;
    Curve2DSample first = Curve2DSample(start, transform(start));
    Curve2DSample last = Curve2DSample(end, transform(end));
    List<Curve2DSample> samples = ;
    ;
    sample(first, last(first.value.dx - last.value.dx).abs() < tolerance && (first.value.dy - last.value.dy).abs() < tolerance);
    return samples;
}

int Curve2D::samplingSeed() {
    return 0;
}

double Curve2D::findInverse(double x) {
    assert(x != nullptr);
    double start = 0.0;
    double end = 1.0;
    double mid;
    ;
    double errorLimit = 1e-6;
    int count = 100;
    double startValue = offsetToOrigin(start);
    while ((end - start) / 2.0 > errorLimit && count > 0) {
        mid = (end + start) / 2.0;
        double value = offsetToOrigin(mid);
        if (value.sign == startValue.sign) {
            start = mid;
        } else {
            end = mid;
        }
        count--;
    }
    return mid;
}

Curve2DSample::Curve2DSample(double t, Offset value) {
    {
        assert(t != nullptr);
        assert(value != nullptr);
    }
}

String Curve2DSample::toString() {
    return "[(${value.dx.toStringAsFixed(2)}, ${value.dy.toStringAsFixed(2)}), ${t.toStringAsFixed(2)}]";
}

CatmullRomSpline::CatmullRomSpline(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension) {
    {
        assert(controlPoints != nullptr);
        assert(tension != nullptr);
        assert(tension <= 1.0, "tension $tension must not be greater than 1.0.");
        assert(tension >= 0.0, "tension $tension must not be negative.");
        assert(controlPoints.length > 3, "There must be at least four control points to create a CatmullRomSpline.");
        _controlPoints = controlPoints;
        _startHandle = startHandle;
        _endHandle = endHandle;
        _tension = tension;
        _cubicSegments = ;
    }
}

void CatmullRomSpline::precompute(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension)

int CatmullRomSpline::samplingSeed() {
    _initializeIfNeeded();
    Offset seedPoint = _cubicSegments[0][1];
    return ((seedPoint.dx + seedPoint.dy) * 10000).round();
}

Offset CatmullRomSpline::transformInternal(double t) {
    _initializeIfNeeded();
    double length = _cubicSegments.length.toDouble();
    double position;
    double localT;
    int index;
    if ( < 1.0) {
        position = t * length;
        localT = position % 1.0;
        index = position.floor();
    } else {
        position = length;
        localT = 1.0;
        index = _cubicSegments.length - 1;
    }
    List<Offset> cubicControlPoints = _cubicSegments[index];
    double localT2 = localT * localT;
    return cubicControlPoints[0] * localT2 * localT + cubicControlPoints[1] * localT2 + cubicControlPoints[2] * localT + cubicControlPoints[3];
}

List<List<Offset>> CatmullRomSpline::_computeSegments(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension) {
    startHandle = controlPoints[0] * 2.0 - controlPoints[1];
    endHandle = controlPoints.last * 2.0 - controlPoints[controlPoints.length - 2];
    List<Offset> allPoints = ;
    double alpha = 0.5;
    double reverseTension = 1.0 - tension;
    List<List<Offset>> result = ;
    for (;  < allPoints.length - 3; ++i) {
        List<Offset> curve = ;
        Offset diffCurve10 = curve[1] - curve[0];
        Offset diffCurve21 = curve[2] - curve[1];
        Offset diffCurve32 = curve[3] - curve[2];
        double t01 = math.pow(diffCurve10.distance, alpha).toDouble();
        double t12 = math.pow(diffCurve21.distance, alpha).toDouble();
        double t23 = math.pow(diffCurve32.distance, alpha).toDouble();
        Offset m1 = (diffCurve21 + (diffCurve10 / t01 - (curve[2] - curve[0]) / (t01 + t12)) * t12) * reverseTension;
        Offset m2 = (diffCurve21 + (diffCurve32 / t23 - (curve[3] - curve[1]) / (t12 + t23)) * t12) * reverseTension;
        Offset sumM12 = m1 + m2;
        List<Offset> segment = ;
        result.add(segment);
    }
    return result;
}

void CatmullRomSpline::_initializeIfNeeded() {
    if (_cubicSegments.isNotEmpty) {
        return;
    }
    _cubicSegments.addAll(_computeSegments(_controlPoints!, _tension!_startHandle, _endHandle));
}

CatmullRomCurve::CatmullRomCurve(List<Offset> controlPoints, double tension) {
    {
        assert(tension != nullptr);
        assert((), "control points $controlPoints could not be validated:\n  ${_debugAssertReasons.join('\n  ')}");
        _precomputedSamples = ;
    }
}

void CatmullRomCurve::precompute(List<Offset> controlPoints, double tension)

bool CatmullRomCurve::validateControlPoints(List<Offset> controlPoints, List<String> reasons, double tension) {
    assert(tension != nullptr);
    if (controlPoints == nullptr) {
        assert(());
        return false;
    }
    if (controlPoints.length < 2) {
        assert(());
        return false;
    }
    controlPoints = ;
    Offset startHandle = controlPoints[0] * 2.0 - controlPoints[1];
    Offset endHandle = controlPoints.last * 2.0 - controlPoints[controlPoints.length - 2];
    controlPoints = ;
    double lastX = -double.infinity;
    for (;  < controlPoints.length; ++i) {
        if (i > 1 &&  < controlPoints.length - 2 && (controlPoints[i].dx <= 0.0 || controlPoints[i].dx >= 1.0)) {
            assert(());
            return false;
        }
        if (controlPoints[i].dx <= lastX) {
            assert(());
            return false;
        }
        lastX = controlPoints[i].dx;
    }
    bool success = true;
    lastX = -double.infinity;
    double tolerance = 1e-3;
    CatmullRomSpline testSpline = CatmullRomSpline(controlPointstension);
    double start = testSpline.findInverse(0.0);
    double end = testSpline.findInverse(1.0);
    Iterable<Curve2DSample> samplePoints = testSpline.generateSamples(start, end);
    if (samplePoints.first.value.dy.abs() > tolerance || (1.0 - samplePoints.last.value.dy).abs() > tolerance) {
        bool bail = true;
        success = false;
        assert(());
        if (bail) {
            return false;
        }
    }
    for (Curve2DSample sample : samplePoints) {
        Offset point = sample.value;
        double t = sample.t;
        double x = point.dx;
        if (t >= start && t <= end && ( < -1e-3 || x > 1.0 + 1e-3)) {
            bool bail = true;
            success = false;
            assert(());
            if (bail) {
                return false;
            }
        }
        if ( < lastX) {
            bool bail = true;
            success = false;
            assert(());
            if (bail) {
                return false;
            }
        }
        lastX = x;
    }
    return success;
}

double CatmullRomCurve::transformInternal(double t) {
    if (_precomputedSamples.isEmpty) {
        _precomputedSamples.addAll(_computeSamples(controlPoints, tension));
    }
    int start = 0;
    int end = _precomputedSamples.length - 1;
    int mid;
    Offset value;
    Offset startValue = _precomputedSamples[start].value;
    Offset endValue = _precomputedSamples[end].value;
    while (end - start > 1) {
        mid = (end + start) ~/ 2;
        value = _precomputedSamples[mid].value;
        if (t >= value.dx) {
            start = mid;
            startValue = value;
        } else {
            end = mid;
            endValue = value;
        }
    }
    double t2 = (t - startValue.dx) / (endValue.dx - startValue.dx);
    return lerpDouble(startValue.dy, endValue.dy, t2)!;
}

List<Curve2DSample> CatmullRomCurve::_computeSamples(List<Offset> controlPoints, double tension) {
    return CatmullRomSpline.precompute(tension).generateSamples(1e-12).toList();
}

FlippedCurve::FlippedCurve(Curve curve) {
    {
        assert(curve != nullptr);
    }
}

double FlippedCurve::transformInternal(double t) {
    return 1.0 - curve.transform(1.0 - t);
}

String FlippedCurve::toString() {
    return "${objectRuntimeType(this, 'FlippedCurve')}($curve)";
}

double _DecelerateCurve::transformInternal(double t) {
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

double _BounceInCurve::transformInternal(double t) {
    return 1.0 - _bounce(1.0 - t);
}

double _BounceOutCurve::transformInternal(double t) {
    return _bounce(t);
}

double _BounceInOutCurve::transformInternal(double t) {
    if ( < 0.5) {
        return (1.0 - _bounce(1.0 - t * 2.0)) * 0.5;
    } else {
        return _bounce(t * 2.0 - 1.0) * 0.5 + 0.5;
    }
}

double ElasticInCurve::transformInternal(double t) {
    double s = period / 4.0;
    t = t - 1.0;
    return -math.pow(2.0, 10.0 * t) * math.sin((t - s) * (math.pi * 2.0) / period);
}

String ElasticInCurve::toString() {
    return "${objectRuntimeType(this, 'ElasticInCurve')}($period)";
}

double ElasticOutCurve::transformInternal(double t) {
    double s = period / 4.0;
    return math.pow(2.0, -10 * t) * math.sin((t - s) * (math.pi * 2.0) / period) + 1.0;
}

String ElasticOutCurve::toString() {
    return "${objectRuntimeType(this, 'ElasticOutCurve')}($period)";
}

double ElasticInOutCurve::transformInternal(double t) {
    double s = period / 4.0;
    t = 2.0 * t - 1.0;
    if ( < 0.0) {
        return -0.5 * math.pow(2.0, 10.0 * t) * math.sin((t - s) * (math.pi * 2.0) / period);
    } else {
        return math.pow(2.0, -10.0 * t) * math.sin((t - s) * (math.pi * 2.0) / period) * 0.5 + 1.0;
    }
}

String ElasticInOutCurve::toString() {
    return "${objectRuntimeType(this, 'ElasticInOutCurve')}($period)";
}
