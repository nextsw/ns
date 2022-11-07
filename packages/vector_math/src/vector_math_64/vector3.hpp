#ifndef VECTOR3_H
#define VECTOR3_H
#include <memory>




class Vector3 {
public:

    Float64List storage();

    static void min(Vector3 a, Vector3 b, Vector3 result);

    static void max(Vector3 a, Vector3 b, Vector3 result);

    static void mix(double a, Vector3 max, Vector3 min, Vector3 result);

     Vector3(double x, double y, double z);

    void  array(List<double> array, int offset);

    void  zero();

    void  all(double value);

    void  copy(Vector3 other);

    void  fromFloat64List(Float64List _v3storage);

    void  fromBuffer(ByteBuffer buffer, int offset);

    void  random(Random rng);

    void setValues(double x, double y, double z);

    void setZero();

    void setFrom(Vector3 other);

    void splat(double arg);

    String toString();

    bool ==(Object other);

    int hashCode();

    Vector3 -();

    Vector3 -(Vector3 other);

    Vector3 +(Vector3 other);

    Vector3 /(double scale);

    Vector3 *(double scale);

    double [](int i);

    void []=(int i, double v);

    void  length(double value);

    double length();

    double length2();

    double normalize();

    double normalizeLength();

    Vector3 normalized();

    Vector3 normalizeInto(Vector3 out);

    double distanceTo(Vector3 arg);

    double distanceToSquared(Vector3 arg);

    double angleTo(Vector3 other);

    double angleToSigned(Vector3 normal, Vector3 other);

    double dot(Vector3 other);

    void postmultiply(Matrix3 arg);

    Vector3 cross(Vector3 other);

    Vector3 crossInto(Vector3 other, Vector3 out);

    void reflect(Vector3 normal);

    Vector3 reflected(Vector3 normal);

    void applyProjection(Matrix4 arg);

    void applyAxisAngle(double angle, Vector3 axis);

    void applyQuaternion(Quaternion arg);

    void applyMatrix3(Matrix3 arg);

    void applyMatrix4(Matrix4 arg);

    double relativeError(Vector3 correct);

    double absoluteError(Vector3 correct);

    bool isInfinite();

    bool isNaN();

    void add(Vector3 arg);

    void addScaled(Vector3 arg, double factor);

    void sub(Vector3 arg);

    void multiply(Vector3 arg);

    void divide(Vector3 arg);

    void scale(double arg);

    Vector3 scaled(double arg);

    void negate();

    void absolute();

    void clamp(Vector3 max, Vector3 min);

    void clampScalar(double max, double min);

    void floor();

    void ceil();

    void round();

    void roundToZero();

    Vector3 clone();

    Vector3 copyInto(Vector3 arg);

    void copyIntoArray(List<double> array, int offset);

    void copyFromArray(List<double> array, int offset);

    void  xy(Vector2 arg);

    void  xz(Vector2 arg);

    void  yx(Vector2 arg);

    void  yz(Vector2 arg);

    void  zx(Vector2 arg);

    void  zy(Vector2 arg);

    void  xyz(Vector3 arg);

    void  xzy(Vector3 arg);

    void  yxz(Vector3 arg);

    void  yzx(Vector3 arg);

    void  zxy(Vector3 arg);

    void  zyx(Vector3 arg);

    void  r(double arg);

    void  g(double arg);

    void  b(double arg);

    void  s(double arg);

    void  t(double arg);

    void  p(double arg);

    void  x(double arg);

    void  y(double arg);

    void  z(double arg);

    void  rg(Vector2 arg);

    void  rb(Vector2 arg);

    void  gr(Vector2 arg);

    void  gb(Vector2 arg);

    void  br(Vector2 arg);

    void  bg(Vector2 arg);

    void  rgb(Vector3 arg);

    void  rbg(Vector3 arg);

    void  grb(Vector3 arg);

    void  gbr(Vector3 arg);

    void  brg(Vector3 arg);

    void  bgr(Vector3 arg);

    void  st(Vector2 arg);

    void  sp(Vector2 arg);

    void  ts(Vector2 arg);

    void  tp(Vector2 arg);

    void  ps(Vector2 arg);

    void  pt(Vector2 arg);

    void  stp(Vector3 arg);

    void  spt(Vector3 arg);

    void  tsp(Vector3 arg);

    void  tps(Vector3 arg);

    void  pst(Vector3 arg);

    void  pts(Vector3 arg);

    Vector2 xx();

    Vector2 xy();

    Vector2 xz();

    Vector2 yx();

    Vector2 yy();

    Vector2 yz();

    Vector2 zx();

    Vector2 zy();

    Vector2 zz();

    Vector3 xxx();

    Vector3 xxy();

    Vector3 xxz();

    Vector3 xyx();

    Vector3 xyy();

    Vector3 xyz();

    Vector3 xzx();

    Vector3 xzy();

    Vector3 xzz();

    Vector3 yxx();

    Vector3 yxy();

    Vector3 yxz();

    Vector3 yyx();

    Vector3 yyy();

    Vector3 yyz();

    Vector3 yzx();

    Vector3 yzy();

    Vector3 yzz();

    Vector3 zxx();

    Vector3 zxy();

    Vector3 zxz();

    Vector3 zyx();

    Vector3 zyy();

    Vector3 zyz();

    Vector3 zzx();

    Vector3 zzy();

    Vector3 zzz();

    Vector4 xxxx();

    Vector4 xxxy();

    Vector4 xxxz();

    Vector4 xxyx();

    Vector4 xxyy();

    Vector4 xxyz();

    Vector4 xxzx();

    Vector4 xxzy();

    Vector4 xxzz();

    Vector4 xyxx();

    Vector4 xyxy();

    Vector4 xyxz();

    Vector4 xyyx();

    Vector4 xyyy();

    Vector4 xyyz();

    Vector4 xyzx();

    Vector4 xyzy();

    Vector4 xyzz();

    Vector4 xzxx();

    Vector4 xzxy();

    Vector4 xzxz();

    Vector4 xzyx();

    Vector4 xzyy();

    Vector4 xzyz();

    Vector4 xzzx();

    Vector4 xzzy();

    Vector4 xzzz();

    Vector4 yxxx();

    Vector4 yxxy();

    Vector4 yxxz();

    Vector4 yxyx();

    Vector4 yxyy();

    Vector4 yxyz();

    Vector4 yxzx();

    Vector4 yxzy();

    Vector4 yxzz();

    Vector4 yyxx();

    Vector4 yyxy();

    Vector4 yyxz();

    Vector4 yyyx();

    Vector4 yyyy();

    Vector4 yyyz();

    Vector4 yyzx();

    Vector4 yyzy();

    Vector4 yyzz();

    Vector4 yzxx();

    Vector4 yzxy();

    Vector4 yzxz();

    Vector4 yzyx();

    Vector4 yzyy();

    Vector4 yzyz();

    Vector4 yzzx();

    Vector4 yzzy();

    Vector4 yzzz();

    Vector4 zxxx();

    Vector4 zxxy();

    Vector4 zxxz();

    Vector4 zxyx();

    Vector4 zxyy();

    Vector4 zxyz();

    Vector4 zxzx();

    Vector4 zxzy();

    Vector4 zxzz();

    Vector4 zyxx();

    Vector4 zyxy();

    Vector4 zyxz();

    Vector4 zyyx();

    Vector4 zyyy();

    Vector4 zyyz();

    Vector4 zyzx();

    Vector4 zyzy();

    Vector4 zyzz();

    Vector4 zzxx();

    Vector4 zzxy();

    Vector4 zzxz();

    Vector4 zzyx();

    Vector4 zzyy();

    Vector4 zzyz();

    Vector4 zzzx();

    Vector4 zzzy();

    Vector4 zzzz();

    double r();

    double g();

    double b();

    double s();

    double t();

    double p();

    double x();

    double y();

    double z();

    Vector2 rr();

    Vector2 rg();

    Vector2 rb();

    Vector2 gr();

    Vector2 gg();

    Vector2 gb();

    Vector2 br();

    Vector2 bg();

    Vector2 bb();

    Vector3 rrr();

    Vector3 rrg();

    Vector3 rrb();

    Vector3 rgr();

    Vector3 rgg();

    Vector3 rgb();

    Vector3 rbr();

    Vector3 rbg();

    Vector3 rbb();

    Vector3 grr();

    Vector3 grg();

    Vector3 grb();

    Vector3 ggr();

    Vector3 ggg();

    Vector3 ggb();

    Vector3 gbr();

    Vector3 gbg();

    Vector3 gbb();

    Vector3 brr();

    Vector3 brg();

    Vector3 brb();

    Vector3 bgr();

    Vector3 bgg();

    Vector3 bgb();

    Vector3 bbr();

    Vector3 bbg();

    Vector3 bbb();

    Vector4 rrrr();

    Vector4 rrrg();

    Vector4 rrrb();

    Vector4 rrgr();

    Vector4 rrgg();

    Vector4 rrgb();

    Vector4 rrbr();

    Vector4 rrbg();

    Vector4 rrbb();

    Vector4 rgrr();

    Vector4 rgrg();

    Vector4 rgrb();

    Vector4 rggr();

    Vector4 rggg();

    Vector4 rggb();

    Vector4 rgbr();

    Vector4 rgbg();

    Vector4 rgbb();

    Vector4 rbrr();

    Vector4 rbrg();

    Vector4 rbrb();

    Vector4 rbgr();

    Vector4 rbgg();

    Vector4 rbgb();

    Vector4 rbbr();

    Vector4 rbbg();

    Vector4 rbbb();

    Vector4 grrr();

    Vector4 grrg();

    Vector4 grrb();

    Vector4 grgr();

    Vector4 grgg();

    Vector4 grgb();

    Vector4 grbr();

    Vector4 grbg();

    Vector4 grbb();

    Vector4 ggrr();

    Vector4 ggrg();

    Vector4 ggrb();

    Vector4 gggr();

    Vector4 gggg();

    Vector4 gggb();

    Vector4 ggbr();

    Vector4 ggbg();

    Vector4 ggbb();

    Vector4 gbrr();

    Vector4 gbrg();

    Vector4 gbrb();

    Vector4 gbgr();

    Vector4 gbgg();

    Vector4 gbgb();

    Vector4 gbbr();

    Vector4 gbbg();

    Vector4 gbbb();

    Vector4 brrr();

    Vector4 brrg();

    Vector4 brrb();

    Vector4 brgr();

    Vector4 brgg();

    Vector4 brgb();

    Vector4 brbr();

    Vector4 brbg();

    Vector4 brbb();

    Vector4 bgrr();

    Vector4 bgrg();

    Vector4 bgrb();

    Vector4 bggr();

    Vector4 bggg();

    Vector4 bggb();

    Vector4 bgbr();

    Vector4 bgbg();

    Vector4 bgbb();

    Vector4 bbrr();

    Vector4 bbrg();

    Vector4 bbrb();

    Vector4 bbgr();

    Vector4 bbgg();

    Vector4 bbgb();

    Vector4 bbbr();

    Vector4 bbbg();

    Vector4 bbbb();

    Vector2 ss();

    Vector2 st();

    Vector2 sp();

    Vector2 ts();

    Vector2 tt();

    Vector2 tp();

    Vector2 ps();

    Vector2 pt();

    Vector2 pp();

    Vector3 sss();

    Vector3 sst();

    Vector3 ssp();

    Vector3 sts();

    Vector3 stt();

    Vector3 stp();

    Vector3 sps();

    Vector3 spt();

    Vector3 spp();

    Vector3 tss();

    Vector3 tst();

    Vector3 tsp();

    Vector3 tts();

    Vector3 ttt();

    Vector3 ttp();

    Vector3 tps();

    Vector3 tpt();

    Vector3 tpp();

    Vector3 pss();

    Vector3 pst();

    Vector3 psp();

    Vector3 pts();

    Vector3 ptt();

    Vector3 ptp();

    Vector3 pps();

    Vector3 ppt();

    Vector3 ppp();

    Vector4 ssss();

    Vector4 ssst();

    Vector4 sssp();

    Vector4 ssts();

    Vector4 sstt();

    Vector4 sstp();

    Vector4 ssps();

    Vector4 sspt();

    Vector4 sspp();

    Vector4 stss();

    Vector4 stst();

    Vector4 stsp();

    Vector4 stts();

    Vector4 sttt();

    Vector4 sttp();

    Vector4 stps();

    Vector4 stpt();

    Vector4 stpp();

    Vector4 spss();

    Vector4 spst();

    Vector4 spsp();

    Vector4 spts();

    Vector4 sptt();

    Vector4 sptp();

    Vector4 spps();

    Vector4 sppt();

    Vector4 sppp();

    Vector4 tsss();

    Vector4 tsst();

    Vector4 tssp();

    Vector4 tsts();

    Vector4 tstt();

    Vector4 tstp();

    Vector4 tsps();

    Vector4 tspt();

    Vector4 tspp();

    Vector4 ttss();

    Vector4 ttst();

    Vector4 ttsp();

    Vector4 ttts();

    Vector4 tttt();

    Vector4 tttp();

    Vector4 ttps();

    Vector4 ttpt();

    Vector4 ttpp();

    Vector4 tpss();

    Vector4 tpst();

    Vector4 tpsp();

    Vector4 tpts();

    Vector4 tptt();

    Vector4 tptp();

    Vector4 tpps();

    Vector4 tppt();

    Vector4 tppp();

    Vector4 psss();

    Vector4 psst();

    Vector4 pssp();

    Vector4 psts();

    Vector4 pstt();

    Vector4 pstp();

    Vector4 psps();

    Vector4 pspt();

    Vector4 pspp();

    Vector4 ptss();

    Vector4 ptst();

    Vector4 ptsp();

    Vector4 ptts();

    Vector4 pttt();

    Vector4 pttp();

    Vector4 ptps();

    Vector4 ptpt();

    Vector4 ptpp();

    Vector4 ppss();

    Vector4 ppst();

    Vector4 ppsp();

    Vector4 ppts();

    Vector4 pptt();

    Vector4 pptp();

    Vector4 ppps();

    Vector4 pppt();

    Vector4 pppp();

private:
    Float64List _v3storage;


};

#endif