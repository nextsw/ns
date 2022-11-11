#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR3
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR3
#include <base.hpp>

#include <dart/core/core.hpp>


class Vector3Cls : public ObjectCls {
public:

    virtual Float64List storage();

    static void min(Vector3 a, Vector3 b, Vector3 result);

    static void max(Vector3 a, Vector3 b, Vector3 result);

    static void mix(Vector3 min, Vector3 max, double a, Vector3 result);

     Vector3Cls(double x, double y, double z);

    virtual void  array(List<double> array, int offset);

    virtual void  zero();

    virtual void  all(double value);

    virtual void  copy(Vector3 other);

    virtual void  fromFloat64List(Float64List _v3storage);
    virtual void  fromBuffer(ByteBuffer buffer, int offset);

    virtual void  random(Random rng);

    virtual void setValues(double x, double y, double z);

    virtual void setZero();

    virtual void setFrom(Vector3 other);

    virtual void splat(double arg);

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Vector3 operator-();

    virtual Vector3 operator-(Vector3 other);

    virtual Vector3 operator+(Vector3 other);

    virtual Vector3 operator/(double scale);

    virtual Vector3 operator*(double scale);

    virtual double operator[](int i);

    virtual void operator[]=(int i, double v);

    virtual void  length(double value);

    virtual double length();

    virtual double length2();

    virtual double normalize();

    virtual double normalizeLength();

    virtual Vector3 normalized();

    virtual Vector3 normalizeInto(Vector3 out);

    virtual double distanceTo(Vector3 arg);

    virtual double distanceToSquared(Vector3 arg);

    virtual double angleTo(Vector3 other);

    virtual double angleToSigned(Vector3 other, Vector3 normal);

    virtual double dot(Vector3 other);

    virtual void postmultiply(Matrix3 arg);

    virtual Vector3 cross(Vector3 other);

    virtual Vector3 crossInto(Vector3 other, Vector3 out);

    virtual void reflect(Vector3 normal);

    virtual Vector3 reflected(Vector3 normal);

    virtual void applyProjection(Matrix4 arg);

    virtual void applyAxisAngle(Vector3 axis, double angle);

    virtual void applyQuaternion(Quaternion arg);

    virtual void applyMatrix3(Matrix3 arg);

    virtual void applyMatrix4(Matrix4 arg);

    virtual double relativeError(Vector3 correct);

    virtual double absoluteError(Vector3 correct);

    virtual bool isInfinite();

    virtual bool isNaN();

    virtual void add(Vector3 arg);

    virtual void addScaled(Vector3 arg, double factor);

    virtual void sub(Vector3 arg);

    virtual void multiply(Vector3 arg);

    virtual void divide(Vector3 arg);

    virtual void scale(double arg);

    virtual Vector3 scaled(double arg);

    virtual void negate();

    virtual void absolute();

    virtual void clamp(Vector3 min, Vector3 max);

    virtual void clampScalar(double min, double max);

    virtual void floor();

    virtual void ceil();

    virtual void round();

    virtual void roundToZero();

    virtual Vector3 clone();

    virtual Vector3 copyInto(Vector3 arg);

    virtual void copyIntoArray(List<double> array, int offset);

    virtual void copyFromArray(List<double> array, int offset);

    virtual void  xy(Vector2 arg);

    virtual void  xz(Vector2 arg);

    virtual void  yx(Vector2 arg);

    virtual void  yz(Vector2 arg);

    virtual void  zx(Vector2 arg);

    virtual void  zy(Vector2 arg);

    virtual void  xyz(Vector3 arg);

    virtual void  xzy(Vector3 arg);

    virtual void  yxz(Vector3 arg);

    virtual void  yzx(Vector3 arg);

    virtual void  zxy(Vector3 arg);

    virtual void  zyx(Vector3 arg);

    virtual void  r(double arg);

    virtual void  g(double arg);

    virtual void  b(double arg);

    virtual void  s(double arg);

    virtual void  t(double arg);

    virtual void  p(double arg);

    virtual void  x(double arg);

    virtual void  y(double arg);

    virtual void  z(double arg);

    virtual void  rg(Vector2 arg);

    virtual void  rb(Vector2 arg);

    virtual void  gr(Vector2 arg);

    virtual void  gb(Vector2 arg);

    virtual void  br(Vector2 arg);

    virtual void  bg(Vector2 arg);

    virtual void  rgb(Vector3 arg);

    virtual void  rbg(Vector3 arg);

    virtual void  grb(Vector3 arg);

    virtual void  gbr(Vector3 arg);

    virtual void  brg(Vector3 arg);

    virtual void  bgr(Vector3 arg);

    virtual void  st(Vector2 arg);

    virtual void  sp(Vector2 arg);

    virtual void  ts(Vector2 arg);

    virtual void  tp(Vector2 arg);

    virtual void  ps(Vector2 arg);

    virtual void  pt(Vector2 arg);

    virtual void  stp(Vector3 arg);

    virtual void  spt(Vector3 arg);

    virtual void  tsp(Vector3 arg);

    virtual void  tps(Vector3 arg);

    virtual void  pst(Vector3 arg);

    virtual void  pts(Vector3 arg);

    virtual Vector2 xx();

    virtual Vector2 xy();

    virtual Vector2 xz();

    virtual Vector2 yx();

    virtual Vector2 yy();

    virtual Vector2 yz();

    virtual Vector2 zx();

    virtual Vector2 zy();

    virtual Vector2 zz();

    virtual Vector3 xxx();

    virtual Vector3 xxy();

    virtual Vector3 xxz();

    virtual Vector3 xyx();

    virtual Vector3 xyy();

    virtual Vector3 xyz();

    virtual Vector3 xzx();

    virtual Vector3 xzy();

    virtual Vector3 xzz();

    virtual Vector3 yxx();

    virtual Vector3 yxy();

    virtual Vector3 yxz();

    virtual Vector3 yyx();

    virtual Vector3 yyy();

    virtual Vector3 yyz();

    virtual Vector3 yzx();

    virtual Vector3 yzy();

    virtual Vector3 yzz();

    virtual Vector3 zxx();

    virtual Vector3 zxy();

    virtual Vector3 zxz();

    virtual Vector3 zyx();

    virtual Vector3 zyy();

    virtual Vector3 zyz();

    virtual Vector3 zzx();

    virtual Vector3 zzy();

    virtual Vector3 zzz();

    virtual Vector4 xxxx();

    virtual Vector4 xxxy();

    virtual Vector4 xxxz();

    virtual Vector4 xxyx();

    virtual Vector4 xxyy();

    virtual Vector4 xxyz();

    virtual Vector4 xxzx();

    virtual Vector4 xxzy();

    virtual Vector4 xxzz();

    virtual Vector4 xyxx();

    virtual Vector4 xyxy();

    virtual Vector4 xyxz();

    virtual Vector4 xyyx();

    virtual Vector4 xyyy();

    virtual Vector4 xyyz();

    virtual Vector4 xyzx();

    virtual Vector4 xyzy();

    virtual Vector4 xyzz();

    virtual Vector4 xzxx();

    virtual Vector4 xzxy();

    virtual Vector4 xzxz();

    virtual Vector4 xzyx();

    virtual Vector4 xzyy();

    virtual Vector4 xzyz();

    virtual Vector4 xzzx();

    virtual Vector4 xzzy();

    virtual Vector4 xzzz();

    virtual Vector4 yxxx();

    virtual Vector4 yxxy();

    virtual Vector4 yxxz();

    virtual Vector4 yxyx();

    virtual Vector4 yxyy();

    virtual Vector4 yxyz();

    virtual Vector4 yxzx();

    virtual Vector4 yxzy();

    virtual Vector4 yxzz();

    virtual Vector4 yyxx();

    virtual Vector4 yyxy();

    virtual Vector4 yyxz();

    virtual Vector4 yyyx();

    virtual Vector4 yyyy();

    virtual Vector4 yyyz();

    virtual Vector4 yyzx();

    virtual Vector4 yyzy();

    virtual Vector4 yyzz();

    virtual Vector4 yzxx();

    virtual Vector4 yzxy();

    virtual Vector4 yzxz();

    virtual Vector4 yzyx();

    virtual Vector4 yzyy();

    virtual Vector4 yzyz();

    virtual Vector4 yzzx();

    virtual Vector4 yzzy();

    virtual Vector4 yzzz();

    virtual Vector4 zxxx();

    virtual Vector4 zxxy();

    virtual Vector4 zxxz();

    virtual Vector4 zxyx();

    virtual Vector4 zxyy();

    virtual Vector4 zxyz();

    virtual Vector4 zxzx();

    virtual Vector4 zxzy();

    virtual Vector4 zxzz();

    virtual Vector4 zyxx();

    virtual Vector4 zyxy();

    virtual Vector4 zyxz();

    virtual Vector4 zyyx();

    virtual Vector4 zyyy();

    virtual Vector4 zyyz();

    virtual Vector4 zyzx();

    virtual Vector4 zyzy();

    virtual Vector4 zyzz();

    virtual Vector4 zzxx();

    virtual Vector4 zzxy();

    virtual Vector4 zzxz();

    virtual Vector4 zzyx();

    virtual Vector4 zzyy();

    virtual Vector4 zzyz();

    virtual Vector4 zzzx();

    virtual Vector4 zzzy();

    virtual Vector4 zzzz();

    virtual double r();

    virtual double g();

    virtual double b();

    virtual double s();

    virtual double t();

    virtual double p();

    virtual double x();

    virtual double y();

    virtual double z();

    virtual Vector2 rr();

    virtual Vector2 rg();

    virtual Vector2 rb();

    virtual Vector2 gr();

    virtual Vector2 gg();

    virtual Vector2 gb();

    virtual Vector2 br();

    virtual Vector2 bg();

    virtual Vector2 bb();

    virtual Vector3 rrr();

    virtual Vector3 rrg();

    virtual Vector3 rrb();

    virtual Vector3 rgr();

    virtual Vector3 rgg();

    virtual Vector3 rgb();

    virtual Vector3 rbr();

    virtual Vector3 rbg();

    virtual Vector3 rbb();

    virtual Vector3 grr();

    virtual Vector3 grg();

    virtual Vector3 grb();

    virtual Vector3 ggr();

    virtual Vector3 ggg();

    virtual Vector3 ggb();

    virtual Vector3 gbr();

    virtual Vector3 gbg();

    virtual Vector3 gbb();

    virtual Vector3 brr();

    virtual Vector3 brg();

    virtual Vector3 brb();

    virtual Vector3 bgr();

    virtual Vector3 bgg();

    virtual Vector3 bgb();

    virtual Vector3 bbr();

    virtual Vector3 bbg();

    virtual Vector3 bbb();

    virtual Vector4 rrrr();

    virtual Vector4 rrrg();

    virtual Vector4 rrrb();

    virtual Vector4 rrgr();

    virtual Vector4 rrgg();

    virtual Vector4 rrgb();

    virtual Vector4 rrbr();

    virtual Vector4 rrbg();

    virtual Vector4 rrbb();

    virtual Vector4 rgrr();

    virtual Vector4 rgrg();

    virtual Vector4 rgrb();

    virtual Vector4 rggr();

    virtual Vector4 rggg();

    virtual Vector4 rggb();

    virtual Vector4 rgbr();

    virtual Vector4 rgbg();

    virtual Vector4 rgbb();

    virtual Vector4 rbrr();

    virtual Vector4 rbrg();

    virtual Vector4 rbrb();

    virtual Vector4 rbgr();

    virtual Vector4 rbgg();

    virtual Vector4 rbgb();

    virtual Vector4 rbbr();

    virtual Vector4 rbbg();

    virtual Vector4 rbbb();

    virtual Vector4 grrr();

    virtual Vector4 grrg();

    virtual Vector4 grrb();

    virtual Vector4 grgr();

    virtual Vector4 grgg();

    virtual Vector4 grgb();

    virtual Vector4 grbr();

    virtual Vector4 grbg();

    virtual Vector4 grbb();

    virtual Vector4 ggrr();

    virtual Vector4 ggrg();

    virtual Vector4 ggrb();

    virtual Vector4 gggr();

    virtual Vector4 gggg();

    virtual Vector4 gggb();

    virtual Vector4 ggbr();

    virtual Vector4 ggbg();

    virtual Vector4 ggbb();

    virtual Vector4 gbrr();

    virtual Vector4 gbrg();

    virtual Vector4 gbrb();

    virtual Vector4 gbgr();

    virtual Vector4 gbgg();

    virtual Vector4 gbgb();

    virtual Vector4 gbbr();

    virtual Vector4 gbbg();

    virtual Vector4 gbbb();

    virtual Vector4 brrr();

    virtual Vector4 brrg();

    virtual Vector4 brrb();

    virtual Vector4 brgr();

    virtual Vector4 brgg();

    virtual Vector4 brgb();

    virtual Vector4 brbr();

    virtual Vector4 brbg();

    virtual Vector4 brbb();

    virtual Vector4 bgrr();

    virtual Vector4 bgrg();

    virtual Vector4 bgrb();

    virtual Vector4 bggr();

    virtual Vector4 bggg();

    virtual Vector4 bggb();

    virtual Vector4 bgbr();

    virtual Vector4 bgbg();

    virtual Vector4 bgbb();

    virtual Vector4 bbrr();

    virtual Vector4 bbrg();

    virtual Vector4 bbrb();

    virtual Vector4 bbgr();

    virtual Vector4 bbgg();

    virtual Vector4 bbgb();

    virtual Vector4 bbbr();

    virtual Vector4 bbbg();

    virtual Vector4 bbbb();

    virtual Vector2 ss();

    virtual Vector2 st();

    virtual Vector2 sp();

    virtual Vector2 ts();

    virtual Vector2 tt();

    virtual Vector2 tp();

    virtual Vector2 ps();

    virtual Vector2 pt();

    virtual Vector2 pp();

    virtual Vector3 sss();

    virtual Vector3 sst();

    virtual Vector3 ssp();

    virtual Vector3 sts();

    virtual Vector3 stt();

    virtual Vector3 stp();

    virtual Vector3 sps();

    virtual Vector3 spt();

    virtual Vector3 spp();

    virtual Vector3 tss();

    virtual Vector3 tst();

    virtual Vector3 tsp();

    virtual Vector3 tts();

    virtual Vector3 ttt();

    virtual Vector3 ttp();

    virtual Vector3 tps();

    virtual Vector3 tpt();

    virtual Vector3 tpp();

    virtual Vector3 pss();

    virtual Vector3 pst();

    virtual Vector3 psp();

    virtual Vector3 pts();

    virtual Vector3 ptt();

    virtual Vector3 ptp();

    virtual Vector3 pps();

    virtual Vector3 ppt();

    virtual Vector3 ppp();

    virtual Vector4 ssss();

    virtual Vector4 ssst();

    virtual Vector4 sssp();

    virtual Vector4 ssts();

    virtual Vector4 sstt();

    virtual Vector4 sstp();

    virtual Vector4 ssps();

    virtual Vector4 sspt();

    virtual Vector4 sspp();

    virtual Vector4 stss();

    virtual Vector4 stst();

    virtual Vector4 stsp();

    virtual Vector4 stts();

    virtual Vector4 sttt();

    virtual Vector4 sttp();

    virtual Vector4 stps();

    virtual Vector4 stpt();

    virtual Vector4 stpp();

    virtual Vector4 spss();

    virtual Vector4 spst();

    virtual Vector4 spsp();

    virtual Vector4 spts();

    virtual Vector4 sptt();

    virtual Vector4 sptp();

    virtual Vector4 spps();

    virtual Vector4 sppt();

    virtual Vector4 sppp();

    virtual Vector4 tsss();

    virtual Vector4 tsst();

    virtual Vector4 tssp();

    virtual Vector4 tsts();

    virtual Vector4 tstt();

    virtual Vector4 tstp();

    virtual Vector4 tsps();

    virtual Vector4 tspt();

    virtual Vector4 tspp();

    virtual Vector4 ttss();

    virtual Vector4 ttst();

    virtual Vector4 ttsp();

    virtual Vector4 ttts();

    virtual Vector4 tttt();

    virtual Vector4 tttp();

    virtual Vector4 ttps();

    virtual Vector4 ttpt();

    virtual Vector4 ttpp();

    virtual Vector4 tpss();

    virtual Vector4 tpst();

    virtual Vector4 tpsp();

    virtual Vector4 tpts();

    virtual Vector4 tptt();

    virtual Vector4 tptp();

    virtual Vector4 tpps();

    virtual Vector4 tppt();

    virtual Vector4 tppp();

    virtual Vector4 psss();

    virtual Vector4 psst();

    virtual Vector4 pssp();

    virtual Vector4 psts();

    virtual Vector4 pstt();

    virtual Vector4 pstp();

    virtual Vector4 psps();

    virtual Vector4 pspt();

    virtual Vector4 pspp();

    virtual Vector4 ptss();

    virtual Vector4 ptst();

    virtual Vector4 ptsp();

    virtual Vector4 ptts();

    virtual Vector4 pttt();

    virtual Vector4 pttp();

    virtual Vector4 ptps();

    virtual Vector4 ptpt();

    virtual Vector4 ptpp();

    virtual Vector4 ppss();

    virtual Vector4 ppst();

    virtual Vector4 ppsp();

    virtual Vector4 ppts();

    virtual Vector4 pptt();

    virtual Vector4 pptp();

    virtual Vector4 ppps();

    virtual Vector4 pppt();

    virtual Vector4 pppp();

private:
    Float64List _v3storage;


};
using Vector3 = std::shared_ptr<Vector3Cls>;


#endif