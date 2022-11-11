#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR4
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR4
#include <base.hpp>

#include <dart/core/core.hpp>


class Vector4Cls : public ObjectCls {
public:

    static void min(Vector4 a, Vector4 b, Vector4 result);

    static void max(Vector4 a, Vector4 b, Vector4 result);

    static void mix(Vector4 min, Vector4 max, double a, Vector4 result);

    virtual Float64List storage();

     Vector4Cls(double x, double y, double z, double w);

    virtual void  array(List<double> array, int offset);

    virtual void  zero();

    virtual void  identity();

    virtual void  all(double value);

    virtual void  copy(Vector4 other);

    virtual void  fromFloat64List(Float64List _v4storage);
    virtual void  fromBuffer(ByteBuffer buffer, int offset);

    virtual void  random(Random rng);

    virtual void setValues(double x_, double y_, double z_, double w_);

    virtual void setZero();

    virtual void setIdentity();

    virtual void setFrom(Vector4 other);

    virtual void splat(double arg);

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Vector4 operator-();

    virtual Vector4 operator-(Vector4 other);

    virtual Vector4 operator+(Vector4 other);

    virtual Vector4 operator/(double scale);

    virtual Vector4 operator*(double scale);

    virtual double operator[](int i);

    virtual void operator[]=(int i, double v);

    virtual void  length(double value);

    virtual double length();

    virtual double length2();

    virtual double normalize();

    virtual double normalizeLength();

    virtual Vector4 normalized();

    virtual Vector4 normalizeInto(Vector4 out);

    virtual double distanceTo(Vector4 arg);

    virtual double distanceToSquared(Vector4 arg);

    virtual double dot(Vector4 other);

    virtual void applyMatrix4(Matrix4 arg);

    virtual double relativeError(Vector4 correct);

    virtual double absoluteError(Vector4 correct);

    virtual bool isInfinite();

    virtual bool isNaN();

    virtual void add(Vector4 arg);

    virtual void addScaled(Vector4 arg, double factor);

    virtual void sub(Vector4 arg);

    virtual void multiply(Vector4 arg);

    virtual void div(Vector4 arg);

    virtual void scale(double arg);

    virtual Vector4 scaled(double arg);

    virtual void negate();

    virtual void absolute();

    virtual void clamp(Vector4 min, Vector4 max);

    virtual void clampScalar(double min, double max);

    virtual void floor();

    virtual void ceil();

    virtual void round();

    virtual void roundToZero();

    virtual Vector4 clone();

    virtual Vector4 copyInto(Vector4 arg);

    virtual void copyIntoArray(List<double> array, int offset);

    virtual void copyFromArray(List<double> array, int offset);

    virtual void  xy(Vector2 arg);

    virtual void  xz(Vector2 arg);

    virtual void  xw(Vector2 arg);

    virtual void  yx(Vector2 arg);

    virtual void  yz(Vector2 arg);

    virtual void  yw(Vector2 arg);

    virtual void  zx(Vector2 arg);

    virtual void  zy(Vector2 arg);

    virtual void  zw(Vector2 arg);

    virtual void  wx(Vector2 arg);

    virtual void  wy(Vector2 arg);

    virtual void  wz(Vector2 arg);

    virtual void  xyz(Vector3 arg);

    virtual void  xyw(Vector3 arg);

    virtual void  xzy(Vector3 arg);

    virtual void  xzw(Vector3 arg);

    virtual void  xwy(Vector3 arg);

    virtual void  xwz(Vector3 arg);

    virtual void  yxz(Vector3 arg);

    virtual void  yxw(Vector3 arg);

    virtual void  yzx(Vector3 arg);

    virtual void  yzw(Vector3 arg);

    virtual void  ywx(Vector3 arg);

    virtual void  ywz(Vector3 arg);

    virtual void  zxy(Vector3 arg);

    virtual void  zxw(Vector3 arg);

    virtual void  zyx(Vector3 arg);

    virtual void  zyw(Vector3 arg);

    virtual void  zwx(Vector3 arg);

    virtual void  zwy(Vector3 arg);

    virtual void  wxy(Vector3 arg);

    virtual void  wxz(Vector3 arg);

    virtual void  wyx(Vector3 arg);

    virtual void  wyz(Vector3 arg);

    virtual void  wzx(Vector3 arg);

    virtual void  wzy(Vector3 arg);

    virtual void  xyzw(Vector4 arg);

    virtual void  xywz(Vector4 arg);

    virtual void  xzyw(Vector4 arg);

    virtual void  xzwy(Vector4 arg);

    virtual void  xwyz(Vector4 arg);

    virtual void  xwzy(Vector4 arg);

    virtual void  yxzw(Vector4 arg);

    virtual void  yxwz(Vector4 arg);

    virtual void  yzxw(Vector4 arg);

    virtual void  yzwx(Vector4 arg);

    virtual void  ywxz(Vector4 arg);

    virtual void  ywzx(Vector4 arg);

    virtual void  zxyw(Vector4 arg);

    virtual void  zxwy(Vector4 arg);

    virtual void  zyxw(Vector4 arg);

    virtual void  zywx(Vector4 arg);

    virtual void  zwxy(Vector4 arg);

    virtual void  zwyx(Vector4 arg);

    virtual void  wxyz(Vector4 arg);

    virtual void  wxzy(Vector4 arg);

    virtual void  wyxz(Vector4 arg);

    virtual void  wyzx(Vector4 arg);

    virtual void  wzxy(Vector4 arg);

    virtual void  wzyx(Vector4 arg);

    virtual void  r(double arg);

    virtual void  g(double arg);

    virtual void  b(double arg);

    virtual void  a(double arg);

    virtual void  s(double arg);

    virtual void  t(double arg);

    virtual void  p(double arg);

    virtual void  q(double arg);

    virtual void  x(double arg);

    virtual void  y(double arg);

    virtual void  z(double arg);

    virtual void  w(double arg);

    virtual void  rg(Vector2 arg);

    virtual void  rb(Vector2 arg);

    virtual void  ra(Vector2 arg);

    virtual void  gr(Vector2 arg);

    virtual void  gb(Vector2 arg);

    virtual void  ga(Vector2 arg);

    virtual void  br(Vector2 arg);

    virtual void  bg(Vector2 arg);

    virtual void  ba(Vector2 arg);

    virtual void  ar(Vector2 arg);

    virtual void  ag(Vector2 arg);

    virtual void  ab(Vector2 arg);

    virtual void  rgb(Vector3 arg);

    virtual void  rga(Vector3 arg);

    virtual void  rbg(Vector3 arg);

    virtual void  rba(Vector3 arg);

    virtual void  rag(Vector3 arg);

    virtual void  rab(Vector3 arg);

    virtual void  grb(Vector3 arg);

    virtual void  gra(Vector3 arg);

    virtual void  gbr(Vector3 arg);

    virtual void  gba(Vector3 arg);

    virtual void  gar(Vector3 arg);

    virtual void  gab(Vector3 arg);

    virtual void  brg(Vector3 arg);

    virtual void  bra(Vector3 arg);

    virtual void  bgr(Vector3 arg);

    virtual void  bga(Vector3 arg);

    virtual void  bar(Vector3 arg);

    virtual void  bag(Vector3 arg);

    virtual void  arg(Vector3 arg);

    virtual void  arb(Vector3 arg);

    virtual void  agr(Vector3 arg);

    virtual void  agb(Vector3 arg);

    virtual void  abr(Vector3 arg);

    virtual void  abg(Vector3 arg);

    virtual void  rgba(Vector4 arg);

    virtual void  rgab(Vector4 arg);

    virtual void  rbga(Vector4 arg);

    virtual void  rbag(Vector4 arg);

    virtual void  ragb(Vector4 arg);

    virtual void  rabg(Vector4 arg);

    virtual void  grba(Vector4 arg);

    virtual void  grab(Vector4 arg);

    virtual void  gbra(Vector4 arg);

    virtual void  gbar(Vector4 arg);

    virtual void  garb(Vector4 arg);

    virtual void  gabr(Vector4 arg);

    virtual void  brga(Vector4 arg);

    virtual void  brag(Vector4 arg);

    virtual void  bgra(Vector4 arg);

    virtual void  bgar(Vector4 arg);

    virtual void  barg(Vector4 arg);

    virtual void  bagr(Vector4 arg);

    virtual void  argb(Vector4 arg);

    virtual void  arbg(Vector4 arg);

    virtual void  agrb(Vector4 arg);

    virtual void  agbr(Vector4 arg);

    virtual void  abrg(Vector4 arg);

    virtual void  abgr(Vector4 arg);

    virtual void  st(Vector2 arg);

    virtual void  sp(Vector2 arg);

    virtual void  sq(Vector2 arg);

    virtual void  ts(Vector2 arg);

    virtual void  tp(Vector2 arg);

    virtual void  tq(Vector2 arg);

    virtual void  ps(Vector2 arg);

    virtual void  pt(Vector2 arg);

    virtual void  pq(Vector2 arg);

    virtual void  qs(Vector2 arg);

    virtual void  qt(Vector2 arg);

    virtual void  qp(Vector2 arg);

    virtual void  stp(Vector3 arg);

    virtual void  stq(Vector3 arg);

    virtual void  spt(Vector3 arg);

    virtual void  spq(Vector3 arg);

    virtual void  sqt(Vector3 arg);

    virtual void  sqp(Vector3 arg);

    virtual void  tsp(Vector3 arg);

    virtual void  tsq(Vector3 arg);

    virtual void  tps(Vector3 arg);

    virtual void  tpq(Vector3 arg);

    virtual void  tqs(Vector3 arg);

    virtual void  tqp(Vector3 arg);

    virtual void  pst(Vector3 arg);

    virtual void  psq(Vector3 arg);

    virtual void  pts(Vector3 arg);

    virtual void  ptq(Vector3 arg);

    virtual void  pqs(Vector3 arg);

    virtual void  pqt(Vector3 arg);

    virtual void  qst(Vector3 arg);

    virtual void  qsp(Vector3 arg);

    virtual void  qts(Vector3 arg);

    virtual void  qtp(Vector3 arg);

    virtual void  qps(Vector3 arg);

    virtual void  qpt(Vector3 arg);

    virtual void  stpq(Vector4 arg);

    virtual void  stqp(Vector4 arg);

    virtual void  sptq(Vector4 arg);

    virtual void  spqt(Vector4 arg);

    virtual void  sqtp(Vector4 arg);

    virtual void  sqpt(Vector4 arg);

    virtual void  tspq(Vector4 arg);

    virtual void  tsqp(Vector4 arg);

    virtual void  tpsq(Vector4 arg);

    virtual void  tpqs(Vector4 arg);

    virtual void  tqsp(Vector4 arg);

    virtual void  tqps(Vector4 arg);

    virtual void  pstq(Vector4 arg);

    virtual void  psqt(Vector4 arg);

    virtual void  ptsq(Vector4 arg);

    virtual void  ptqs(Vector4 arg);

    virtual void  pqst(Vector4 arg);

    virtual void  pqts(Vector4 arg);

    virtual void  qstp(Vector4 arg);

    virtual void  qspt(Vector4 arg);

    virtual void  qtsp(Vector4 arg);

    virtual void  qtps(Vector4 arg);

    virtual void  qpst(Vector4 arg);

    virtual void  qpts(Vector4 arg);

    virtual Vector2 xx();

    virtual Vector2 xy();

    virtual Vector2 xz();

    virtual Vector2 xw();

    virtual Vector2 yx();

    virtual Vector2 yy();

    virtual Vector2 yz();

    virtual Vector2 yw();

    virtual Vector2 zx();

    virtual Vector2 zy();

    virtual Vector2 zz();

    virtual Vector2 zw();

    virtual Vector2 wx();

    virtual Vector2 wy();

    virtual Vector2 wz();

    virtual Vector2 ww();

    virtual Vector3 xxx();

    virtual Vector3 xxy();

    virtual Vector3 xxz();

    virtual Vector3 xxw();

    virtual Vector3 xyx();

    virtual Vector3 xyy();

    virtual Vector3 xyz();

    virtual Vector3 xyw();

    virtual Vector3 xzx();

    virtual Vector3 xzy();

    virtual Vector3 xzz();

    virtual Vector3 xzw();

    virtual Vector3 xwx();

    virtual Vector3 xwy();

    virtual Vector3 xwz();

    virtual Vector3 xww();

    virtual Vector3 yxx();

    virtual Vector3 yxy();

    virtual Vector3 yxz();

    virtual Vector3 yxw();

    virtual Vector3 yyx();

    virtual Vector3 yyy();

    virtual Vector3 yyz();

    virtual Vector3 yyw();

    virtual Vector3 yzx();

    virtual Vector3 yzy();

    virtual Vector3 yzz();

    virtual Vector3 yzw();

    virtual Vector3 ywx();

    virtual Vector3 ywy();

    virtual Vector3 ywz();

    virtual Vector3 yww();

    virtual Vector3 zxx();

    virtual Vector3 zxy();

    virtual Vector3 zxz();

    virtual Vector3 zxw();

    virtual Vector3 zyx();

    virtual Vector3 zyy();

    virtual Vector3 zyz();

    virtual Vector3 zyw();

    virtual Vector3 zzx();

    virtual Vector3 zzy();

    virtual Vector3 zzz();

    virtual Vector3 zzw();

    virtual Vector3 zwx();

    virtual Vector3 zwy();

    virtual Vector3 zwz();

    virtual Vector3 zww();

    virtual Vector3 wxx();

    virtual Vector3 wxy();

    virtual Vector3 wxz();

    virtual Vector3 wxw();

    virtual Vector3 wyx();

    virtual Vector3 wyy();

    virtual Vector3 wyz();

    virtual Vector3 wyw();

    virtual Vector3 wzx();

    virtual Vector3 wzy();

    virtual Vector3 wzz();

    virtual Vector3 wzw();

    virtual Vector3 wwx();

    virtual Vector3 wwy();

    virtual Vector3 wwz();

    virtual Vector3 www();

    virtual Vector4 xxxx();

    virtual Vector4 xxxy();

    virtual Vector4 xxxz();

    virtual Vector4 xxxw();

    virtual Vector4 xxyx();

    virtual Vector4 xxyy();

    virtual Vector4 xxyz();

    virtual Vector4 xxyw();

    virtual Vector4 xxzx();

    virtual Vector4 xxzy();

    virtual Vector4 xxzz();

    virtual Vector4 xxzw();

    virtual Vector4 xxwx();

    virtual Vector4 xxwy();

    virtual Vector4 xxwz();

    virtual Vector4 xxww();

    virtual Vector4 xyxx();

    virtual Vector4 xyxy();

    virtual Vector4 xyxz();

    virtual Vector4 xyxw();

    virtual Vector4 xyyx();

    virtual Vector4 xyyy();

    virtual Vector4 xyyz();

    virtual Vector4 xyyw();

    virtual Vector4 xyzx();

    virtual Vector4 xyzy();

    virtual Vector4 xyzz();

    virtual Vector4 xyzw();

    virtual Vector4 xywx();

    virtual Vector4 xywy();

    virtual Vector4 xywz();

    virtual Vector4 xyww();

    virtual Vector4 xzxx();

    virtual Vector4 xzxy();

    virtual Vector4 xzxz();

    virtual Vector4 xzxw();

    virtual Vector4 xzyx();

    virtual Vector4 xzyy();

    virtual Vector4 xzyz();

    virtual Vector4 xzyw();

    virtual Vector4 xzzx();

    virtual Vector4 xzzy();

    virtual Vector4 xzzz();

    virtual Vector4 xzzw();

    virtual Vector4 xzwx();

    virtual Vector4 xzwy();

    virtual Vector4 xzwz();

    virtual Vector4 xzww();

    virtual Vector4 xwxx();

    virtual Vector4 xwxy();

    virtual Vector4 xwxz();

    virtual Vector4 xwxw();

    virtual Vector4 xwyx();

    virtual Vector4 xwyy();

    virtual Vector4 xwyz();

    virtual Vector4 xwyw();

    virtual Vector4 xwzx();

    virtual Vector4 xwzy();

    virtual Vector4 xwzz();

    virtual Vector4 xwzw();

    virtual Vector4 xwwx();

    virtual Vector4 xwwy();

    virtual Vector4 xwwz();

    virtual Vector4 xwww();

    virtual Vector4 yxxx();

    virtual Vector4 yxxy();

    virtual Vector4 yxxz();

    virtual Vector4 yxxw();

    virtual Vector4 yxyx();

    virtual Vector4 yxyy();

    virtual Vector4 yxyz();

    virtual Vector4 yxyw();

    virtual Vector4 yxzx();

    virtual Vector4 yxzy();

    virtual Vector4 yxzz();

    virtual Vector4 yxzw();

    virtual Vector4 yxwx();

    virtual Vector4 yxwy();

    virtual Vector4 yxwz();

    virtual Vector4 yxww();

    virtual Vector4 yyxx();

    virtual Vector4 yyxy();

    virtual Vector4 yyxz();

    virtual Vector4 yyxw();

    virtual Vector4 yyyx();

    virtual Vector4 yyyy();

    virtual Vector4 yyyz();

    virtual Vector4 yyyw();

    virtual Vector4 yyzx();

    virtual Vector4 yyzy();

    virtual Vector4 yyzz();

    virtual Vector4 yyzw();

    virtual Vector4 yywx();

    virtual Vector4 yywy();

    virtual Vector4 yywz();

    virtual Vector4 yyww();

    virtual Vector4 yzxx();

    virtual Vector4 yzxy();

    virtual Vector4 yzxz();

    virtual Vector4 yzxw();

    virtual Vector4 yzyx();

    virtual Vector4 yzyy();

    virtual Vector4 yzyz();

    virtual Vector4 yzyw();

    virtual Vector4 yzzx();

    virtual Vector4 yzzy();

    virtual Vector4 yzzz();

    virtual Vector4 yzzw();

    virtual Vector4 yzwx();

    virtual Vector4 yzwy();

    virtual Vector4 yzwz();

    virtual Vector4 yzww();

    virtual Vector4 ywxx();

    virtual Vector4 ywxy();

    virtual Vector4 ywxz();

    virtual Vector4 ywxw();

    virtual Vector4 ywyx();

    virtual Vector4 ywyy();

    virtual Vector4 ywyz();

    virtual Vector4 ywyw();

    virtual Vector4 ywzx();

    virtual Vector4 ywzy();

    virtual Vector4 ywzz();

    virtual Vector4 ywzw();

    virtual Vector4 ywwx();

    virtual Vector4 ywwy();

    virtual Vector4 ywwz();

    virtual Vector4 ywww();

    virtual Vector4 zxxx();

    virtual Vector4 zxxy();

    virtual Vector4 zxxz();

    virtual Vector4 zxxw();

    virtual Vector4 zxyx();

    virtual Vector4 zxyy();

    virtual Vector4 zxyz();

    virtual Vector4 zxyw();

    virtual Vector4 zxzx();

    virtual Vector4 zxzy();

    virtual Vector4 zxzz();

    virtual Vector4 zxzw();

    virtual Vector4 zxwx();

    virtual Vector4 zxwy();

    virtual Vector4 zxwz();

    virtual Vector4 zxww();

    virtual Vector4 zyxx();

    virtual Vector4 zyxy();

    virtual Vector4 zyxz();

    virtual Vector4 zyxw();

    virtual Vector4 zyyx();

    virtual Vector4 zyyy();

    virtual Vector4 zyyz();

    virtual Vector4 zyyw();

    virtual Vector4 zyzx();

    virtual Vector4 zyzy();

    virtual Vector4 zyzz();

    virtual Vector4 zyzw();

    virtual Vector4 zywx();

    virtual Vector4 zywy();

    virtual Vector4 zywz();

    virtual Vector4 zyww();

    virtual Vector4 zzxx();

    virtual Vector4 zzxy();

    virtual Vector4 zzxz();

    virtual Vector4 zzxw();

    virtual Vector4 zzyx();

    virtual Vector4 zzyy();

    virtual Vector4 zzyz();

    virtual Vector4 zzyw();

    virtual Vector4 zzzx();

    virtual Vector4 zzzy();

    virtual Vector4 zzzz();

    virtual Vector4 zzzw();

    virtual Vector4 zzwx();

    virtual Vector4 zzwy();

    virtual Vector4 zzwz();

    virtual Vector4 zzww();

    virtual Vector4 zwxx();

    virtual Vector4 zwxy();

    virtual Vector4 zwxz();

    virtual Vector4 zwxw();

    virtual Vector4 zwyx();

    virtual Vector4 zwyy();

    virtual Vector4 zwyz();

    virtual Vector4 zwyw();

    virtual Vector4 zwzx();

    virtual Vector4 zwzy();

    virtual Vector4 zwzz();

    virtual Vector4 zwzw();

    virtual Vector4 zwwx();

    virtual Vector4 zwwy();

    virtual Vector4 zwwz();

    virtual Vector4 zwww();

    virtual Vector4 wxxx();

    virtual Vector4 wxxy();

    virtual Vector4 wxxz();

    virtual Vector4 wxxw();

    virtual Vector4 wxyx();

    virtual Vector4 wxyy();

    virtual Vector4 wxyz();

    virtual Vector4 wxyw();

    virtual Vector4 wxzx();

    virtual Vector4 wxzy();

    virtual Vector4 wxzz();

    virtual Vector4 wxzw();

    virtual Vector4 wxwx();

    virtual Vector4 wxwy();

    virtual Vector4 wxwz();

    virtual Vector4 wxww();

    virtual Vector4 wyxx();

    virtual Vector4 wyxy();

    virtual Vector4 wyxz();

    virtual Vector4 wyxw();

    virtual Vector4 wyyx();

    virtual Vector4 wyyy();

    virtual Vector4 wyyz();

    virtual Vector4 wyyw();

    virtual Vector4 wyzx();

    virtual Vector4 wyzy();

    virtual Vector4 wyzz();

    virtual Vector4 wyzw();

    virtual Vector4 wywx();

    virtual Vector4 wywy();

    virtual Vector4 wywz();

    virtual Vector4 wyww();

    virtual Vector4 wzxx();

    virtual Vector4 wzxy();

    virtual Vector4 wzxz();

    virtual Vector4 wzxw();

    virtual Vector4 wzyx();

    virtual Vector4 wzyy();

    virtual Vector4 wzyz();

    virtual Vector4 wzyw();

    virtual Vector4 wzzx();

    virtual Vector4 wzzy();

    virtual Vector4 wzzz();

    virtual Vector4 wzzw();

    virtual Vector4 wzwx();

    virtual Vector4 wzwy();

    virtual Vector4 wzwz();

    virtual Vector4 wzww();

    virtual Vector4 wwxx();

    virtual Vector4 wwxy();

    virtual Vector4 wwxz();

    virtual Vector4 wwxw();

    virtual Vector4 wwyx();

    virtual Vector4 wwyy();

    virtual Vector4 wwyz();

    virtual Vector4 wwyw();

    virtual Vector4 wwzx();

    virtual Vector4 wwzy();

    virtual Vector4 wwzz();

    virtual Vector4 wwzw();

    virtual Vector4 wwwx();

    virtual Vector4 wwwy();

    virtual Vector4 wwwz();

    virtual Vector4 wwww();

    virtual double r();

    virtual double g();

    virtual double b();

    virtual double a();

    virtual double s();

    virtual double t();

    virtual double p();

    virtual double q();

    virtual double x();

    virtual double y();

    virtual double z();

    virtual double w();

    virtual Vector2 rr();

    virtual Vector2 rg();

    virtual Vector2 rb();

    virtual Vector2 ra();

    virtual Vector2 gr();

    virtual Vector2 gg();

    virtual Vector2 gb();

    virtual Vector2 ga();

    virtual Vector2 br();

    virtual Vector2 bg();

    virtual Vector2 bb();

    virtual Vector2 ba();

    virtual Vector2 ar();

    virtual Vector2 ag();

    virtual Vector2 ab();

    virtual Vector2 aa();

    virtual Vector3 rrr();

    virtual Vector3 rrg();

    virtual Vector3 rrb();

    virtual Vector3 rra();

    virtual Vector3 rgr();

    virtual Vector3 rgg();

    virtual Vector3 rgb();

    virtual Vector3 rga();

    virtual Vector3 rbr();

    virtual Vector3 rbg();

    virtual Vector3 rbb();

    virtual Vector3 rba();

    virtual Vector3 rar();

    virtual Vector3 rag();

    virtual Vector3 rab();

    virtual Vector3 raa();

    virtual Vector3 grr();

    virtual Vector3 grg();

    virtual Vector3 grb();

    virtual Vector3 gra();

    virtual Vector3 ggr();

    virtual Vector3 ggg();

    virtual Vector3 ggb();

    virtual Vector3 gga();

    virtual Vector3 gbr();

    virtual Vector3 gbg();

    virtual Vector3 gbb();

    virtual Vector3 gba();

    virtual Vector3 gar();

    virtual Vector3 gag();

    virtual Vector3 gab();

    virtual Vector3 gaa();

    virtual Vector3 brr();

    virtual Vector3 brg();

    virtual Vector3 brb();

    virtual Vector3 bra();

    virtual Vector3 bgr();

    virtual Vector3 bgg();

    virtual Vector3 bgb();

    virtual Vector3 bga();

    virtual Vector3 bbr();

    virtual Vector3 bbg();

    virtual Vector3 bbb();

    virtual Vector3 bba();

    virtual Vector3 bar();

    virtual Vector3 bag();

    virtual Vector3 bab();

    virtual Vector3 baa();

    virtual Vector3 arr();

    virtual Vector3 arg();

    virtual Vector3 arb();

    virtual Vector3 ara();

    virtual Vector3 agr();

    virtual Vector3 agg();

    virtual Vector3 agb();

    virtual Vector3 aga();

    virtual Vector3 abr();

    virtual Vector3 abg();

    virtual Vector3 abb();

    virtual Vector3 aba();

    virtual Vector3 aar();

    virtual Vector3 aag();

    virtual Vector3 aab();

    virtual Vector3 aaa();

    virtual Vector4 rrrr();

    virtual Vector4 rrrg();

    virtual Vector4 rrrb();

    virtual Vector4 rrra();

    virtual Vector4 rrgr();

    virtual Vector4 rrgg();

    virtual Vector4 rrgb();

    virtual Vector4 rrga();

    virtual Vector4 rrbr();

    virtual Vector4 rrbg();

    virtual Vector4 rrbb();

    virtual Vector4 rrba();

    virtual Vector4 rrar();

    virtual Vector4 rrag();

    virtual Vector4 rrab();

    virtual Vector4 rraa();

    virtual Vector4 rgrr();

    virtual Vector4 rgrg();

    virtual Vector4 rgrb();

    virtual Vector4 rgra();

    virtual Vector4 rggr();

    virtual Vector4 rggg();

    virtual Vector4 rggb();

    virtual Vector4 rgga();

    virtual Vector4 rgbr();

    virtual Vector4 rgbg();

    virtual Vector4 rgbb();

    virtual Vector4 rgba();

    virtual Vector4 rgar();

    virtual Vector4 rgag();

    virtual Vector4 rgab();

    virtual Vector4 rgaa();

    virtual Vector4 rbrr();

    virtual Vector4 rbrg();

    virtual Vector4 rbrb();

    virtual Vector4 rbra();

    virtual Vector4 rbgr();

    virtual Vector4 rbgg();

    virtual Vector4 rbgb();

    virtual Vector4 rbga();

    virtual Vector4 rbbr();

    virtual Vector4 rbbg();

    virtual Vector4 rbbb();

    virtual Vector4 rbba();

    virtual Vector4 rbar();

    virtual Vector4 rbag();

    virtual Vector4 rbab();

    virtual Vector4 rbaa();

    virtual Vector4 rarr();

    virtual Vector4 rarg();

    virtual Vector4 rarb();

    virtual Vector4 rara();

    virtual Vector4 ragr();

    virtual Vector4 ragg();

    virtual Vector4 ragb();

    virtual Vector4 raga();

    virtual Vector4 rabr();

    virtual Vector4 rabg();

    virtual Vector4 rabb();

    virtual Vector4 raba();

    virtual Vector4 raar();

    virtual Vector4 raag();

    virtual Vector4 raab();

    virtual Vector4 raaa();

    virtual Vector4 grrr();

    virtual Vector4 grrg();

    virtual Vector4 grrb();

    virtual Vector4 grra();

    virtual Vector4 grgr();

    virtual Vector4 grgg();

    virtual Vector4 grgb();

    virtual Vector4 grga();

    virtual Vector4 grbr();

    virtual Vector4 grbg();

    virtual Vector4 grbb();

    virtual Vector4 grba();

    virtual Vector4 grar();

    virtual Vector4 grag();

    virtual Vector4 grab();

    virtual Vector4 graa();

    virtual Vector4 ggrr();

    virtual Vector4 ggrg();

    virtual Vector4 ggrb();

    virtual Vector4 ggra();

    virtual Vector4 gggr();

    virtual Vector4 gggg();

    virtual Vector4 gggb();

    virtual Vector4 ggga();

    virtual Vector4 ggbr();

    virtual Vector4 ggbg();

    virtual Vector4 ggbb();

    virtual Vector4 ggba();

    virtual Vector4 ggar();

    virtual Vector4 ggag();

    virtual Vector4 ggab();

    virtual Vector4 ggaa();

    virtual Vector4 gbrr();

    virtual Vector4 gbrg();

    virtual Vector4 gbrb();

    virtual Vector4 gbra();

    virtual Vector4 gbgr();

    virtual Vector4 gbgg();

    virtual Vector4 gbgb();

    virtual Vector4 gbga();

    virtual Vector4 gbbr();

    virtual Vector4 gbbg();

    virtual Vector4 gbbb();

    virtual Vector4 gbba();

    virtual Vector4 gbar();

    virtual Vector4 gbag();

    virtual Vector4 gbab();

    virtual Vector4 gbaa();

    virtual Vector4 garr();

    virtual Vector4 garg();

    virtual Vector4 garb();

    virtual Vector4 gara();

    virtual Vector4 gagr();

    virtual Vector4 gagg();

    virtual Vector4 gagb();

    virtual Vector4 gaga();

    virtual Vector4 gabr();

    virtual Vector4 gabg();

    virtual Vector4 gabb();

    virtual Vector4 gaba();

    virtual Vector4 gaar();

    virtual Vector4 gaag();

    virtual Vector4 gaab();

    virtual Vector4 gaaa();

    virtual Vector4 brrr();

    virtual Vector4 brrg();

    virtual Vector4 brrb();

    virtual Vector4 brra();

    virtual Vector4 brgr();

    virtual Vector4 brgg();

    virtual Vector4 brgb();

    virtual Vector4 brga();

    virtual Vector4 brbr();

    virtual Vector4 brbg();

    virtual Vector4 brbb();

    virtual Vector4 brba();

    virtual Vector4 brar();

    virtual Vector4 brag();

    virtual Vector4 brab();

    virtual Vector4 braa();

    virtual Vector4 bgrr();

    virtual Vector4 bgrg();

    virtual Vector4 bgrb();

    virtual Vector4 bgra();

    virtual Vector4 bggr();

    virtual Vector4 bggg();

    virtual Vector4 bggb();

    virtual Vector4 bgga();

    virtual Vector4 bgbr();

    virtual Vector4 bgbg();

    virtual Vector4 bgbb();

    virtual Vector4 bgba();

    virtual Vector4 bgar();

    virtual Vector4 bgag();

    virtual Vector4 bgab();

    virtual Vector4 bgaa();

    virtual Vector4 bbrr();

    virtual Vector4 bbrg();

    virtual Vector4 bbrb();

    virtual Vector4 bbra();

    virtual Vector4 bbgr();

    virtual Vector4 bbgg();

    virtual Vector4 bbgb();

    virtual Vector4 bbga();

    virtual Vector4 bbbr();

    virtual Vector4 bbbg();

    virtual Vector4 bbbb();

    virtual Vector4 bbba();

    virtual Vector4 bbar();

    virtual Vector4 bbag();

    virtual Vector4 bbab();

    virtual Vector4 bbaa();

    virtual Vector4 barr();

    virtual Vector4 barg();

    virtual Vector4 barb();

    virtual Vector4 bara();

    virtual Vector4 bagr();

    virtual Vector4 bagg();

    virtual Vector4 bagb();

    virtual Vector4 baga();

    virtual Vector4 babr();

    virtual Vector4 babg();

    virtual Vector4 babb();

    virtual Vector4 baba();

    virtual Vector4 baar();

    virtual Vector4 baag();

    virtual Vector4 baab();

    virtual Vector4 baaa();

    virtual Vector4 arrr();

    virtual Vector4 arrg();

    virtual Vector4 arrb();

    virtual Vector4 arra();

    virtual Vector4 argr();

    virtual Vector4 argg();

    virtual Vector4 argb();

    virtual Vector4 arga();

    virtual Vector4 arbr();

    virtual Vector4 arbg();

    virtual Vector4 arbb();

    virtual Vector4 arba();

    virtual Vector4 arar();

    virtual Vector4 arag();

    virtual Vector4 arab();

    virtual Vector4 araa();

    virtual Vector4 agrr();

    virtual Vector4 agrg();

    virtual Vector4 agrb();

    virtual Vector4 agra();

    virtual Vector4 aggr();

    virtual Vector4 aggg();

    virtual Vector4 aggb();

    virtual Vector4 agga();

    virtual Vector4 agbr();

    virtual Vector4 agbg();

    virtual Vector4 agbb();

    virtual Vector4 agba();

    virtual Vector4 agar();

    virtual Vector4 agag();

    virtual Vector4 agab();

    virtual Vector4 agaa();

    virtual Vector4 abrr();

    virtual Vector4 abrg();

    virtual Vector4 abrb();

    virtual Vector4 abra();

    virtual Vector4 abgr();

    virtual Vector4 abgg();

    virtual Vector4 abgb();

    virtual Vector4 abga();

    virtual Vector4 abbr();

    virtual Vector4 abbg();

    virtual Vector4 abbb();

    virtual Vector4 abba();

    virtual Vector4 abar();

    virtual Vector4 abag();

    virtual Vector4 abab();

    virtual Vector4 abaa();

    virtual Vector4 aarr();

    virtual Vector4 aarg();

    virtual Vector4 aarb();

    virtual Vector4 aara();

    virtual Vector4 aagr();

    virtual Vector4 aagg();

    virtual Vector4 aagb();

    virtual Vector4 aaga();

    virtual Vector4 aabr();

    virtual Vector4 aabg();

    virtual Vector4 aabb();

    virtual Vector4 aaba();

    virtual Vector4 aaar();

    virtual Vector4 aaag();

    virtual Vector4 aaab();

    virtual Vector4 aaaa();

    virtual Vector2 ss();

    virtual Vector2 st();

    virtual Vector2 sp();

    virtual Vector2 sq();

    virtual Vector2 ts();

    virtual Vector2 tt();

    virtual Vector2 tp();

    virtual Vector2 tq();

    virtual Vector2 ps();

    virtual Vector2 pt();

    virtual Vector2 pp();

    virtual Vector2 pq();

    virtual Vector2 qs();

    virtual Vector2 qt();

    virtual Vector2 qp();

    virtual Vector2 qq();

    virtual Vector3 sss();

    virtual Vector3 sst();

    virtual Vector3 ssp();

    virtual Vector3 ssq();

    virtual Vector3 sts();

    virtual Vector3 stt();

    virtual Vector3 stp();

    virtual Vector3 stq();

    virtual Vector3 sps();

    virtual Vector3 spt();

    virtual Vector3 spp();

    virtual Vector3 spq();

    virtual Vector3 sqs();

    virtual Vector3 sqt();

    virtual Vector3 sqp();

    virtual Vector3 sqq();

    virtual Vector3 tss();

    virtual Vector3 tst();

    virtual Vector3 tsp();

    virtual Vector3 tsq();

    virtual Vector3 tts();

    virtual Vector3 ttt();

    virtual Vector3 ttp();

    virtual Vector3 ttq();

    virtual Vector3 tps();

    virtual Vector3 tpt();

    virtual Vector3 tpp();

    virtual Vector3 tpq();

    virtual Vector3 tqs();

    virtual Vector3 tqt();

    virtual Vector3 tqp();

    virtual Vector3 tqq();

    virtual Vector3 pss();

    virtual Vector3 pst();

    virtual Vector3 psp();

    virtual Vector3 psq();

    virtual Vector3 pts();

    virtual Vector3 ptt();

    virtual Vector3 ptp();

    virtual Vector3 ptq();

    virtual Vector3 pps();

    virtual Vector3 ppt();

    virtual Vector3 ppp();

    virtual Vector3 ppq();

    virtual Vector3 pqs();

    virtual Vector3 pqt();

    virtual Vector3 pqp();

    virtual Vector3 pqq();

    virtual Vector3 qss();

    virtual Vector3 qst();

    virtual Vector3 qsp();

    virtual Vector3 qsq();

    virtual Vector3 qts();

    virtual Vector3 qtt();

    virtual Vector3 qtp();

    virtual Vector3 qtq();

    virtual Vector3 qps();

    virtual Vector3 qpt();

    virtual Vector3 qpp();

    virtual Vector3 qpq();

    virtual Vector3 qqs();

    virtual Vector3 qqt();

    virtual Vector3 qqp();

    virtual Vector3 qqq();

    virtual Vector4 ssss();

    virtual Vector4 ssst();

    virtual Vector4 sssp();

    virtual Vector4 sssq();

    virtual Vector4 ssts();

    virtual Vector4 sstt();

    virtual Vector4 sstp();

    virtual Vector4 sstq();

    virtual Vector4 ssps();

    virtual Vector4 sspt();

    virtual Vector4 sspp();

    virtual Vector4 sspq();

    virtual Vector4 ssqs();

    virtual Vector4 ssqt();

    virtual Vector4 ssqp();

    virtual Vector4 ssqq();

    virtual Vector4 stss();

    virtual Vector4 stst();

    virtual Vector4 stsp();

    virtual Vector4 stsq();

    virtual Vector4 stts();

    virtual Vector4 sttt();

    virtual Vector4 sttp();

    virtual Vector4 sttq();

    virtual Vector4 stps();

    virtual Vector4 stpt();

    virtual Vector4 stpp();

    virtual Vector4 stpq();

    virtual Vector4 stqs();

    virtual Vector4 stqt();

    virtual Vector4 stqp();

    virtual Vector4 stqq();

    virtual Vector4 spss();

    virtual Vector4 spst();

    virtual Vector4 spsp();

    virtual Vector4 spsq();

    virtual Vector4 spts();

    virtual Vector4 sptt();

    virtual Vector4 sptp();

    virtual Vector4 sptq();

    virtual Vector4 spps();

    virtual Vector4 sppt();

    virtual Vector4 sppp();

    virtual Vector4 sppq();

    virtual Vector4 spqs();

    virtual Vector4 spqt();

    virtual Vector4 spqp();

    virtual Vector4 spqq();

    virtual Vector4 sqss();

    virtual Vector4 sqst();

    virtual Vector4 sqsp();

    virtual Vector4 sqsq();

    virtual Vector4 sqts();

    virtual Vector4 sqtt();

    virtual Vector4 sqtp();

    virtual Vector4 sqtq();

    virtual Vector4 sqps();

    virtual Vector4 sqpt();

    virtual Vector4 sqpp();

    virtual Vector4 sqpq();

    virtual Vector4 sqqs();

    virtual Vector4 sqqt();

    virtual Vector4 sqqp();

    virtual Vector4 sqqq();

    virtual Vector4 tsss();

    virtual Vector4 tsst();

    virtual Vector4 tssp();

    virtual Vector4 tssq();

    virtual Vector4 tsts();

    virtual Vector4 tstt();

    virtual Vector4 tstp();

    virtual Vector4 tstq();

    virtual Vector4 tsps();

    virtual Vector4 tspt();

    virtual Vector4 tspp();

    virtual Vector4 tspq();

    virtual Vector4 tsqs();

    virtual Vector4 tsqt();

    virtual Vector4 tsqp();

    virtual Vector4 tsqq();

    virtual Vector4 ttss();

    virtual Vector4 ttst();

    virtual Vector4 ttsp();

    virtual Vector4 ttsq();

    virtual Vector4 ttts();

    virtual Vector4 tttt();

    virtual Vector4 tttp();

    virtual Vector4 tttq();

    virtual Vector4 ttps();

    virtual Vector4 ttpt();

    virtual Vector4 ttpp();

    virtual Vector4 ttpq();

    virtual Vector4 ttqs();

    virtual Vector4 ttqt();

    virtual Vector4 ttqp();

    virtual Vector4 ttqq();

    virtual Vector4 tpss();

    virtual Vector4 tpst();

    virtual Vector4 tpsp();

    virtual Vector4 tpsq();

    virtual Vector4 tpts();

    virtual Vector4 tptt();

    virtual Vector4 tptp();

    virtual Vector4 tptq();

    virtual Vector4 tpps();

    virtual Vector4 tppt();

    virtual Vector4 tppp();

    virtual Vector4 tppq();

    virtual Vector4 tpqs();

    virtual Vector4 tpqt();

    virtual Vector4 tpqp();

    virtual Vector4 tpqq();

    virtual Vector4 tqss();

    virtual Vector4 tqst();

    virtual Vector4 tqsp();

    virtual Vector4 tqsq();

    virtual Vector4 tqts();

    virtual Vector4 tqtt();

    virtual Vector4 tqtp();

    virtual Vector4 tqtq();

    virtual Vector4 tqps();

    virtual Vector4 tqpt();

    virtual Vector4 tqpp();

    virtual Vector4 tqpq();

    virtual Vector4 tqqs();

    virtual Vector4 tqqt();

    virtual Vector4 tqqp();

    virtual Vector4 tqqq();

    virtual Vector4 psss();

    virtual Vector4 psst();

    virtual Vector4 pssp();

    virtual Vector4 pssq();

    virtual Vector4 psts();

    virtual Vector4 pstt();

    virtual Vector4 pstp();

    virtual Vector4 pstq();

    virtual Vector4 psps();

    virtual Vector4 pspt();

    virtual Vector4 pspp();

    virtual Vector4 pspq();

    virtual Vector4 psqs();

    virtual Vector4 psqt();

    virtual Vector4 psqp();

    virtual Vector4 psqq();

    virtual Vector4 ptss();

    virtual Vector4 ptst();

    virtual Vector4 ptsp();

    virtual Vector4 ptsq();

    virtual Vector4 ptts();

    virtual Vector4 pttt();

    virtual Vector4 pttp();

    virtual Vector4 pttq();

    virtual Vector4 ptps();

    virtual Vector4 ptpt();

    virtual Vector4 ptpp();

    virtual Vector4 ptpq();

    virtual Vector4 ptqs();

    virtual Vector4 ptqt();

    virtual Vector4 ptqp();

    virtual Vector4 ptqq();

    virtual Vector4 ppss();

    virtual Vector4 ppst();

    virtual Vector4 ppsp();

    virtual Vector4 ppsq();

    virtual Vector4 ppts();

    virtual Vector4 pptt();

    virtual Vector4 pptp();

    virtual Vector4 pptq();

    virtual Vector4 ppps();

    virtual Vector4 pppt();

    virtual Vector4 pppp();

    virtual Vector4 pppq();

    virtual Vector4 ppqs();

    virtual Vector4 ppqt();

    virtual Vector4 ppqp();

    virtual Vector4 ppqq();

    virtual Vector4 pqss();

    virtual Vector4 pqst();

    virtual Vector4 pqsp();

    virtual Vector4 pqsq();

    virtual Vector4 pqts();

    virtual Vector4 pqtt();

    virtual Vector4 pqtp();

    virtual Vector4 pqtq();

    virtual Vector4 pqps();

    virtual Vector4 pqpt();

    virtual Vector4 pqpp();

    virtual Vector4 pqpq();

    virtual Vector4 pqqs();

    virtual Vector4 pqqt();

    virtual Vector4 pqqp();

    virtual Vector4 pqqq();

    virtual Vector4 qsss();

    virtual Vector4 qsst();

    virtual Vector4 qssp();

    virtual Vector4 qssq();

    virtual Vector4 qsts();

    virtual Vector4 qstt();

    virtual Vector4 qstp();

    virtual Vector4 qstq();

    virtual Vector4 qsps();

    virtual Vector4 qspt();

    virtual Vector4 qspp();

    virtual Vector4 qspq();

    virtual Vector4 qsqs();

    virtual Vector4 qsqt();

    virtual Vector4 qsqp();

    virtual Vector4 qsqq();

    virtual Vector4 qtss();

    virtual Vector4 qtst();

    virtual Vector4 qtsp();

    virtual Vector4 qtsq();

    virtual Vector4 qtts();

    virtual Vector4 qttt();

    virtual Vector4 qttp();

    virtual Vector4 qttq();

    virtual Vector4 qtps();

    virtual Vector4 qtpt();

    virtual Vector4 qtpp();

    virtual Vector4 qtpq();

    virtual Vector4 qtqs();

    virtual Vector4 qtqt();

    virtual Vector4 qtqp();

    virtual Vector4 qtqq();

    virtual Vector4 qpss();

    virtual Vector4 qpst();

    virtual Vector4 qpsp();

    virtual Vector4 qpsq();

    virtual Vector4 qpts();

    virtual Vector4 qptt();

    virtual Vector4 qptp();

    virtual Vector4 qptq();

    virtual Vector4 qpps();

    virtual Vector4 qppt();

    virtual Vector4 qppp();

    virtual Vector4 qppq();

    virtual Vector4 qpqs();

    virtual Vector4 qpqt();

    virtual Vector4 qpqp();

    virtual Vector4 qpqq();

    virtual Vector4 qqss();

    virtual Vector4 qqst();

    virtual Vector4 qqsp();

    virtual Vector4 qqsq();

    virtual Vector4 qqts();

    virtual Vector4 qqtt();

    virtual Vector4 qqtp();

    virtual Vector4 qqtq();

    virtual Vector4 qqps();

    virtual Vector4 qqpt();

    virtual Vector4 qqpp();

    virtual Vector4 qqpq();

    virtual Vector4 qqqs();

    virtual Vector4 qqqt();

    virtual Vector4 qqqp();

    virtual Vector4 qqqq();

private:
    Float64List _v4storage;


};
using Vector4 = std::shared_ptr<Vector4Cls>;


#endif