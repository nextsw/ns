#ifndef VECTOR2_H
#define VECTOR2_H
#include <memory>




class Vector2 {
public:

    Float64List storage();

    static void min(Vector2 a, Vector2 b, Vector2 result);

    static void max(Vector2 a, Vector2 b, Vector2 result);

    static void mix(double a, Vector2 max, Vector2 min, Vector2 result);

     Vector2(double x, double y);

    void  array(List<double> array, int offset);

    void  zero();

    void  all(double value);

    void  copy(Vector2 other);

    void  fromFloat64List(Float64List _v2storage);

    void  fromBuffer(ByteBuffer buffer, int offset);

    void  random(Random rng);

    void setValues(double x_, double y_);

    void setZero();

    void setFrom(Vector2 other);

    void splat(double arg);

    String toString();

    bool ==(Object other);

    int hashCode();

    Vector2 -();

    Vector2 -(Vector2 other);

    Vector2 +(Vector2 other);

    Vector2 /(double scale);

    Vector2 *(double scale);

    double [](int i);

    void []=(int i, double v);

    void  length(double value);

    double length();

    double length2();

    double normalize();

    double normalizeLength();

    Vector2 normalized();

    Vector2 normalizeInto(Vector2 out);

    double distanceTo(Vector2 arg);

    double distanceToSquared(Vector2 arg);

    double angleTo(Vector2 other);

    double angleToSigned(Vector2 other);

    double dot(Vector2 other);

    void postmultiply(Matrix2 arg);

    double cross(Vector2 other);

    Vector2 scaleOrthogonalInto(Vector2 out, double scale);

    void reflect(Vector2 normal);

    Vector2 reflected(Vector2 normal);

    double relativeError(Vector2 correct);

    double absoluteError(Vector2 correct);

    bool isInfinite();

    bool isNaN();

    void add(Vector2 arg);

    void addScaled(Vector2 arg, double factor);

    void sub(Vector2 arg);

    void multiply(Vector2 arg);

    void divide(Vector2 arg);

    void scale(double arg);

    Vector2 scaled(double arg);

    void negate();

    void absolute();

    void clamp(Vector2 max, Vector2 min);

    void clampScalar(double max, double min);

    void floor();

    void ceil();

    void round();

    void roundToZero();

    Vector2 clone();

    Vector2 copyInto(Vector2 arg);

    void copyIntoArray(List<double> array, int offset);

    void copyFromArray(List<double> array, int offset);

    void  xy(Vector2 arg);

    void  yx(Vector2 arg);

    void  r(double arg);

    void  g(double arg);

    void  s(double arg);

    void  t(double arg);

    void  x(double arg);

    void  y(double arg);

    void  rg(Vector2 arg);

    void  gr(Vector2 arg);

    void  st(Vector2 arg);

    void  ts(Vector2 arg);

    Vector2 xx();

    Vector2 xy();

    Vector2 yx();

    Vector2 yy();

    Vector3 xxx();

    Vector3 xxy();

    Vector3 xyx();

    Vector3 xyy();

    Vector3 yxx();

    Vector3 yxy();

    Vector3 yyx();

    Vector3 yyy();

    Vector4 xxxx();

    Vector4 xxxy();

    Vector4 xxyx();

    Vector4 xxyy();

    Vector4 xyxx();

    Vector4 xyxy();

    Vector4 xyyx();

    Vector4 xyyy();

    Vector4 yxxx();

    Vector4 yxxy();

    Vector4 yxyx();

    Vector4 yxyy();

    Vector4 yyxx();

    Vector4 yyxy();

    Vector4 yyyx();

    Vector4 yyyy();

    double r();

    double g();

    double s();

    double t();

    double x();

    double y();

    Vector2 rr();

    Vector2 rg();

    Vector2 gr();

    Vector2 gg();

    Vector3 rrr();

    Vector3 rrg();

    Vector3 rgr();

    Vector3 rgg();

    Vector3 grr();

    Vector3 grg();

    Vector3 ggr();

    Vector3 ggg();

    Vector4 rrrr();

    Vector4 rrrg();

    Vector4 rrgr();

    Vector4 rrgg();

    Vector4 rgrr();

    Vector4 rgrg();

    Vector4 rggr();

    Vector4 rggg();

    Vector4 grrr();

    Vector4 grrg();

    Vector4 grgr();

    Vector4 grgg();

    Vector4 ggrr();

    Vector4 ggrg();

    Vector4 gggr();

    Vector4 gggg();

    Vector2 ss();

    Vector2 st();

    Vector2 ts();

    Vector2 tt();

    Vector3 sss();

    Vector3 sst();

    Vector3 sts();

    Vector3 stt();

    Vector3 tss();

    Vector3 tst();

    Vector3 tts();

    Vector3 ttt();

    Vector4 ssss();

    Vector4 ssst();

    Vector4 ssts();

    Vector4 sstt();

    Vector4 stss();

    Vector4 stst();

    Vector4 stts();

    Vector4 sttt();

    Vector4 tsss();

    Vector4 tsst();

    Vector4 tsts();

    Vector4 tstt();

    Vector4 ttss();

    Vector4 ttst();

    Vector4 ttts();

    Vector4 tttt();

private:
    Float64List _v2storage;


};

#endif