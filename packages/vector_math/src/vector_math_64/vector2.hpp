#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR2
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR2
#include <base.hpp>

#include <dart/core/core.hpp>


class Vector2Cls : public ObjectCls {
public:

    virtual Float64List storage();

    static void min(Vector2 a, Vector2 b, Vector2 result);

    static void max(Vector2 a, Vector2 b, Vector2 result);

    static void mix(Vector2 min, Vector2 max, double a, Vector2 result);

     Vector2Cls(double x, double y);

    virtual void  array(List<double> array, int offset);

    virtual void  zero();

    virtual void  all(double value);

    virtual void  copy(Vector2 other);

    virtual void  fromFloat64List(Float64List _v2storage);
    virtual void  fromBuffer(ByteBuffer buffer, int offset);

    virtual void  random(Random rng);

    virtual void setValues(double x_, double y_);

    virtual void setZero();

    virtual void setFrom(Vector2 other);

    virtual void splat(double arg);

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Vector2 operator-();

    virtual Vector2 operator-(Vector2 other);

    virtual Vector2 operator+(Vector2 other);

    virtual Vector2 operator/(double scale);

    virtual Vector2 operator*(double scale);

    virtual double operator[](int i);

    virtual void operator[]=(int i, double v);

    virtual void  length(double value);

    virtual double length();

    virtual double length2();

    virtual double normalize();

    virtual double normalizeLength();

    virtual Vector2 normalized();

    virtual Vector2 normalizeInto(Vector2 out);

    virtual double distanceTo(Vector2 arg);

    virtual double distanceToSquared(Vector2 arg);

    virtual double angleTo(Vector2 other);

    virtual double angleToSigned(Vector2 other);

    virtual double dot(Vector2 other);

    virtual void postmultiply(Matrix2 arg);

    virtual double cross(Vector2 other);

    virtual Vector2 scaleOrthogonalInto(double scale, Vector2 out);

    virtual void reflect(Vector2 normal);

    virtual Vector2 reflected(Vector2 normal);

    virtual double relativeError(Vector2 correct);

    virtual double absoluteError(Vector2 correct);

    virtual bool isInfinite();

    virtual bool isNaN();

    virtual void add(Vector2 arg);

    virtual void addScaled(Vector2 arg, double factor);

    virtual void sub(Vector2 arg);

    virtual void multiply(Vector2 arg);

    virtual void divide(Vector2 arg);

    virtual void scale(double arg);

    virtual Vector2 scaled(double arg);

    virtual void negate();

    virtual void absolute();

    virtual void clamp(Vector2 min, Vector2 max);

    virtual void clampScalar(double min, double max);

    virtual void floor();

    virtual void ceil();

    virtual void round();

    virtual void roundToZero();

    virtual Vector2 clone();

    virtual Vector2 copyInto(Vector2 arg);

    virtual void copyIntoArray(List<double> array, int offset);

    virtual void copyFromArray(List<double> array, int offset);

    virtual void  xy(Vector2 arg);

    virtual void  yx(Vector2 arg);

    virtual void  r(double arg);

    virtual void  g(double arg);

    virtual void  s(double arg);

    virtual void  t(double arg);

    virtual void  x(double arg);

    virtual void  y(double arg);

    virtual void  rg(Vector2 arg);

    virtual void  gr(Vector2 arg);

    virtual void  st(Vector2 arg);

    virtual void  ts(Vector2 arg);

    virtual Vector2 xx();

    virtual Vector2 xy();

    virtual Vector2 yx();

    virtual Vector2 yy();

    virtual Vector3 xxx();

    virtual Vector3 xxy();

    virtual Vector3 xyx();

    virtual Vector3 xyy();

    virtual Vector3 yxx();

    virtual Vector3 yxy();

    virtual Vector3 yyx();

    virtual Vector3 yyy();

    virtual Vector4 xxxx();

    virtual Vector4 xxxy();

    virtual Vector4 xxyx();

    virtual Vector4 xxyy();

    virtual Vector4 xyxx();

    virtual Vector4 xyxy();

    virtual Vector4 xyyx();

    virtual Vector4 xyyy();

    virtual Vector4 yxxx();

    virtual Vector4 yxxy();

    virtual Vector4 yxyx();

    virtual Vector4 yxyy();

    virtual Vector4 yyxx();

    virtual Vector4 yyxy();

    virtual Vector4 yyyx();

    virtual Vector4 yyyy();

    virtual double r();

    virtual double g();

    virtual double s();

    virtual double t();

    virtual double x();

    virtual double y();

    virtual Vector2 rr();

    virtual Vector2 rg();

    virtual Vector2 gr();

    virtual Vector2 gg();

    virtual Vector3 rrr();

    virtual Vector3 rrg();

    virtual Vector3 rgr();

    virtual Vector3 rgg();

    virtual Vector3 grr();

    virtual Vector3 grg();

    virtual Vector3 ggr();

    virtual Vector3 ggg();

    virtual Vector4 rrrr();

    virtual Vector4 rrrg();

    virtual Vector4 rrgr();

    virtual Vector4 rrgg();

    virtual Vector4 rgrr();

    virtual Vector4 rgrg();

    virtual Vector4 rggr();

    virtual Vector4 rggg();

    virtual Vector4 grrr();

    virtual Vector4 grrg();

    virtual Vector4 grgr();

    virtual Vector4 grgg();

    virtual Vector4 ggrr();

    virtual Vector4 ggrg();

    virtual Vector4 gggr();

    virtual Vector4 gggg();

    virtual Vector2 ss();

    virtual Vector2 st();

    virtual Vector2 ts();

    virtual Vector2 tt();

    virtual Vector3 sss();

    virtual Vector3 sst();

    virtual Vector3 sts();

    virtual Vector3 stt();

    virtual Vector3 tss();

    virtual Vector3 tst();

    virtual Vector3 tts();

    virtual Vector3 ttt();

    virtual Vector4 ssss();

    virtual Vector4 ssst();

    virtual Vector4 ssts();

    virtual Vector4 sstt();

    virtual Vector4 stss();

    virtual Vector4 stst();

    virtual Vector4 stts();

    virtual Vector4 sttt();

    virtual Vector4 tsss();

    virtual Vector4 tsst();

    virtual Vector4 tsts();

    virtual Vector4 tstt();

    virtual Vector4 ttss();

    virtual Vector4 ttst();

    virtual Vector4 ttts();

    virtual Vector4 tttt();

private:
    Float64List _v2storage;


};
using Vector2 = std::shared_ptr<Vector2Cls>;


#endif