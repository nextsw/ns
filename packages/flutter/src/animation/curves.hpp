#ifndef CURVES_H
#define CURVES_H
#include <memory>
#include <ui.hpp>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>



class ParametricCurve<T> {
public:

     ParametricCurve();

    T transform(double t);

    T transformInternal(double t);

    String toString();

private:

};

class Curve : ParametricCurve<double> {
public:

     Curve();

    double transform(double t);

    Curve flipped();

private:

};

class _Linear : Curve {
public:

    double transformInternal(double t);

private:

    void  _();

};

class SawTooth : Curve {
public:
    int count;


     SawTooth(int count);

    double transformInternal(double t);

    String toString();

private:

};

class Interval : Curve {
public:
    double begin;

    double end;

    Curve curve;


     Interval(double begin, Curve curve, double end);

    double transformInternal(double t);

    String toString();

private:

};

class Threshold : Curve {
public:
    double threshold;


     Threshold(double threshold);

    double transformInternal(double t);

private:

};

class Cubic : Curve {
public:
    double a;

    double b;

    double c;

    double d;


     Cubic(double a, double b, double c, double d);

    double transformInternal(double t);

    String toString();

private:
    static const double _cubicErrorBound;


    double _evaluateCubic(double a, double b, double m);

};

class ThreePointCubic : Curve {
public:
    Offset a1;

    Offset b1;

    Offset midpoint;

    Offset a2;

    Offset b2;


     ThreePointCubic(Offset a1, Offset a2, Offset b1, Offset b2, Offset midpoint);

    double transformInternal(double t);

    String toString();

private:

};

class Curve2D : ParametricCurve<Offset> {
public:

     Curve2D();

    Iterable<Curve2DSample> generateSamples(double end, double start, double tolerance);

    int samplingSeed();

    double findInverse(double x);

private:

};

class Curve2DSample {
public:
    double t;

    Offset value;


     Curve2DSample(double t, Offset value);

    String toString();

private:

};

class CatmullRomSpline : Curve2D {
public:

     CatmullRomSpline(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension);

    void  precompute(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension);

    int samplingSeed();

    Offset transformInternal(double t);

private:
    List<List<Offset>> _cubicSegments;

    List<Offset> _controlPoints;

    Offset _startHandle;

    Offset _endHandle;

    double _tension;


    static List<List<Offset>> _computeSegments(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension);

    void _initializeIfNeeded();

};

class CatmullRomCurve : Curve {
public:
    List<Offset> controlPoints;

    double tension;


     CatmullRomCurve(List<Offset> controlPoints, double tension);

    void  precompute(List<Offset> controlPoints, double tension);

    static bool validateControlPoints(List<Offset> controlPoints, List<String> reasons, double tension);

    double transformInternal(double t);

private:
    static List<String> _debugAssertReasons;

    List<Curve2DSample> _precomputedSamples;


    static List<Curve2DSample> _computeSamples(List<Offset> controlPoints, double tension);

};

class FlippedCurve : Curve {
public:
    Curve curve;


     FlippedCurve(Curve curve);

    double transformInternal(double t);

    String toString();

private:

};

class _DecelerateCurve : Curve {
public:

    double transformInternal(double t);

private:

    void  _();

};
double _bounce(double t);


class _BounceInCurve : Curve {
public:

    double transformInternal(double t);

private:

    void  _();

};

class _BounceOutCurve : Curve {
public:

    double transformInternal(double t);

private:

    void  _();

};

class _BounceInOutCurve : Curve {
public:

    double transformInternal(double t);

private:

    void  _();

};

class ElasticInCurve : Curve {
public:
    double period;


     ElasticInCurve(double period);

    double transformInternal(double t);

    String toString();

private:

};

class ElasticOutCurve : Curve {
public:
    double period;


     ElasticOutCurve(double period);

    double transformInternal(double t);

    String toString();

private:

};

class ElasticInOutCurve : Curve {
public:
    double period;


     ElasticInOutCurve(double period);

    double transformInternal(double t);

    String toString();

private:

};

class Curves {
public:
    static const Curve linear;

    static const Curve decelerate;

    static const Cubic fastLinearToSlowEaseIn;

    static const Cubic ease;

    static const Cubic easeIn;

    static const Cubic easeInToLinear;

    static const Cubic easeInSine;

    static const Cubic easeInQuad;

    static const Cubic easeInCubic;

    static const Cubic easeInQuart;

    static const Cubic easeInQuint;

    static const Cubic easeInExpo;

    static const Cubic easeInCirc;

    static const Cubic easeInBack;

    static const Cubic easeOut;

    static const Cubic linearToEaseOut;

    static const Cubic easeOutSine;

    static const Cubic easeOutQuad;

    static const Cubic easeOutCubic;

    static const Cubic easeOutQuart;

    static const Cubic easeOutQuint;

    static const Cubic easeOutExpo;

    static const Cubic easeOutCirc;

    static const Cubic easeOutBack;

    static const Cubic easeInOut;

    static const Cubic easeInOutSine;

    static const Cubic easeInOutQuad;

    static const Cubic easeInOutCubic;

    static const ThreePointCubic easeInOutCubicEmphasized;

    static const Cubic easeInOutQuart;

    static const Cubic easeInOutQuint;

    static const Cubic easeInOutExpo;

    static const Cubic easeInOutCirc;

    static const Cubic easeInOutBack;

    static const Cubic fastOutSlowIn;

    static const Cubic slowMiddle;

    static const Curve bounceIn;

    static const Curve bounceOut;

    static const Curve bounceInOut;

    static const ElasticInCurve elasticIn;

    static const ElasticOutCurve elasticOut;

    static const ElasticInOutCurve elasticInOut;


private:

    void  _();

};

#endif