#ifndef PACKAGES_FLUTTER_SRC_ANIMATION_CURVES
#define PACKAGES_FLUTTER_SRC_ANIMATION_CURVES
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>


template<typename T>
class ParametricCurveCls : public ObjectCls {
public:

     ParametricCurveCls();
    virtual T transform(double t);

    virtual T transformInternal(double t);

    virtual String toString();

private:

};
template<typename T>
using ParametricCurve = std::shared_ptr<ParametricCurveCls<T>>;

class CurveCls : public ParametricCurveCls<double> {
public:

     CurveCls();
    virtual double transform(double t);

    virtual Curve flipped();

private:

};
using Curve = std::shared_ptr<CurveCls>;

class _LinearCls : public CurveCls {
public:

    virtual double transformInternal(double t);

private:

    virtual void  _();
};
using _Linear = std::shared_ptr<_LinearCls>;

class SawToothCls : public CurveCls {
public:
    int count;


     SawToothCls(int count);

    virtual double transformInternal(double t);

    virtual String toString();

private:

};
using SawTooth = std::shared_ptr<SawToothCls>;

class IntervalCls : public CurveCls {
public:
    double begin;

    double end;

    Curve curve;


     IntervalCls(double begin, double end, Curve curve);

    virtual double transformInternal(double t);

    virtual String toString();

private:

};
using Interval = std::shared_ptr<IntervalCls>;

class ThresholdCls : public CurveCls {
public:
    double threshold;


     ThresholdCls(double threshold);

    virtual double transformInternal(double t);

private:

};
using Threshold = std::shared_ptr<ThresholdCls>;

class CubicCls : public CurveCls {
public:
    double a;

    double b;

    double c;

    double d;


     CubicCls(double a, double b, double c, double d);

    virtual double transformInternal(double t);

    virtual String toString();

private:
    static double _cubicErrorBound;


    virtual double _evaluateCubic(double a, double b, double m);

};
using Cubic = std::shared_ptr<CubicCls>;

class ThreePointCubicCls : public CurveCls {
public:
    Offset a1;

    Offset b1;

    Offset midpoint;

    Offset a2;

    Offset b2;


     ThreePointCubicCls(Offset a1, Offset b1, Offset midpoint, Offset a2, Offset b2);
    virtual double transformInternal(double t);

    virtual String toString();

private:

};
using ThreePointCubic = std::shared_ptr<ThreePointCubicCls>;

class Curve2DCls : public ParametricCurveCls<Offset> {
public:

     Curve2DCls();
    virtual Iterable<Curve2DSample> generateSamples(double end, double start, double tolerance);

    virtual int samplingSeed();

    virtual double findInverse(double x);

private:

};
using Curve2D = std::shared_ptr<Curve2DCls>;

class Curve2DSampleCls : public ObjectCls {
public:
    double t;

    Offset value;


     Curve2DSampleCls(double t, Offset value);

    virtual String toString();

private:

};
using Curve2DSample = std::shared_ptr<Curve2DSampleCls>;

class CatmullRomSplineCls : public Curve2DCls {
public:

     CatmullRomSplineCls(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension);

    virtual void  precompute(List<Offset> controlPoints, Offset endHandle, Offset startHandle, double tension);

    virtual int samplingSeed();

    virtual Offset transformInternal(double t);

private:
    List<List<Offset>> _cubicSegments;

    List<Offset> _controlPoints;

    Offset _startHandle;

    Offset _endHandle;

    double _tension;


    static List<List<Offset>> _computeSegments(List<Offset> controlPoints, double tension, Offset endHandle, Offset startHandle);

    virtual void _initializeIfNeeded();

};
using CatmullRomSpline = std::shared_ptr<CatmullRomSplineCls>;

class CatmullRomCurveCls : public CurveCls {
public:
    List<Offset> controlPoints;

    double tension;


     CatmullRomCurveCls(List<Offset> controlPoints, double tension);

    virtual void  precompute(List<Offset> controlPoints, double tension);

    static bool validateControlPoints(List<Offset> controlPoints, List<String> reasons, double tension);

    virtual double transformInternal(double t);

private:
    static List<String> _debugAssertReasons;

    List<Curve2DSample> _precomputedSamples;


    static List<Curve2DSample> _computeSamples(List<Offset> controlPoints, double tension);

};
using CatmullRomCurve = std::shared_ptr<CatmullRomCurveCls>;

class FlippedCurveCls : public CurveCls {
public:
    Curve curve;


     FlippedCurveCls(Curve curve);

    virtual double transformInternal(double t);

    virtual String toString();

private:

};
using FlippedCurve = std::shared_ptr<FlippedCurveCls>;

class _DecelerateCurveCls : public CurveCls {
public:

    virtual double transformInternal(double t);

private:

    virtual void  _();
};
using _DecelerateCurve = std::shared_ptr<_DecelerateCurveCls>;
double _bounce(double t);


class _BounceInCurveCls : public CurveCls {
public:

    virtual double transformInternal(double t);

private:

    virtual void  _();
};
using _BounceInCurve = std::shared_ptr<_BounceInCurveCls>;

class _BounceOutCurveCls : public CurveCls {
public:

    virtual double transformInternal(double t);

private:

    virtual void  _();
};
using _BounceOutCurve = std::shared_ptr<_BounceOutCurveCls>;

class _BounceInOutCurveCls : public CurveCls {
public:

    virtual double transformInternal(double t);

private:

    virtual void  _();
};
using _BounceInOutCurve = std::shared_ptr<_BounceInOutCurveCls>;

class ElasticInCurveCls : public CurveCls {
public:
    double period;


     ElasticInCurveCls(double period);
    virtual double transformInternal(double t);

    virtual String toString();

private:

};
using ElasticInCurve = std::shared_ptr<ElasticInCurveCls>;

class ElasticOutCurveCls : public CurveCls {
public:
    double period;


     ElasticOutCurveCls(double period);
    virtual double transformInternal(double t);

    virtual String toString();

private:

};
using ElasticOutCurve = std::shared_ptr<ElasticOutCurveCls>;

class ElasticInOutCurveCls : public CurveCls {
public:
    double period;


     ElasticInOutCurveCls(double period);
    virtual double transformInternal(double t);

    virtual String toString();

private:

};
using ElasticInOutCurve = std::shared_ptr<ElasticInOutCurveCls>;

class CurvesCls : public ObjectCls {
public:
    static Curve linear;

    static Curve decelerate;

    static Cubic fastLinearToSlowEaseIn;

    static Cubic ease;

    static Cubic easeIn;

    static Cubic easeInToLinear;

    static Cubic easeInSine;

    static Cubic easeInQuad;

    static Cubic easeInCubic;

    static Cubic easeInQuart;

    static Cubic easeInQuint;

    static Cubic easeInExpo;

    static Cubic easeInCirc;

    static Cubic easeInBack;

    static Cubic easeOut;

    static Cubic linearToEaseOut;

    static Cubic easeOutSine;

    static Cubic easeOutQuad;

    static Cubic easeOutCubic;

    static Cubic easeOutQuart;

    static Cubic easeOutQuint;

    static Cubic easeOutExpo;

    static Cubic easeOutCirc;

    static Cubic easeOutBack;

    static Cubic easeInOut;

    static Cubic easeInOutSine;

    static Cubic easeInOutQuad;

    static Cubic easeInOutCubic;

    static ThreePointCubic easeInOutCubicEmphasized;

    static Cubic easeInOutQuart;

    static Cubic easeInOutQuint;

    static Cubic easeInOutExpo;

    static Cubic easeInOutCirc;

    static Cubic easeInOutBack;

    static Cubic fastOutSlowIn;

    static Cubic slowMiddle;

    static Curve bounceIn;

    static Curve bounceOut;

    static Curve bounceInOut;

    static ElasticInCurve elasticIn;

    static ElasticOutCurve elasticOut;

    static ElasticInOutCurve elasticInOut;


private:

    virtual void  _();
};
using Curves = std::shared_ptr<CurvesCls>;


#endif