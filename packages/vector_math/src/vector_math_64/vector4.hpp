#ifndef VECTOR4_H
#define VECTOR4_H
#include <memory>




class Vector4 {
public:

    static void min(Vector4 a, Vector4 b, Vector4 result);

    static void max(Vector4 a, Vector4 b, Vector4 result);

    static void mix(double a, Vector4 max, Vector4 min, Vector4 result);

    Float64List storage();

     Vector4(double w, double x, double y, double z);

    void  array(List<double> array, int offset);

    void  zero();

    void  identity();

    void  all(double value);

    void  copy(Vector4 other);

    void  fromFloat64List(Float64List _v4storage);

    void  fromBuffer(ByteBuffer buffer, int offset);

    void  random(Random rng);

    void setValues(double w_, double x_, double y_, double z_);

    void setZero();

    void setIdentity();

    void setFrom(Vector4 other);

    void splat(double arg);

    String toString();

    bool ==(Object other);

    int hashCode();

    Vector4 -();

    Vector4 -(Vector4 other);

    Vector4 +(Vector4 other);

    Vector4 /(double scale);

    Vector4 *(double scale);

    double [](int i);

    void []=(int i, double v);

    void  length(double value);

    double length();

    double length2();

    double normalize();

    double normalizeLength();

    Vector4 normalized();

    Vector4 normalizeInto(Vector4 out);

    double distanceTo(Vector4 arg);

    double distanceToSquared(Vector4 arg);

    double dot(Vector4 other);

    void applyMatrix4(Matrix4 arg);

    double relativeError(Vector4 correct);

    double absoluteError(Vector4 correct);

    bool isInfinite();

    bool isNaN();

    void add(Vector4 arg);

    void addScaled(Vector4 arg, double factor);

    void sub(Vector4 arg);

    void multiply(Vector4 arg);

    void div(Vector4 arg);

    void scale(double arg);

    Vector4 scaled(double arg);

    void negate();

    void absolute();

    void clamp(Vector4 max, Vector4 min);

    void clampScalar(double max, double min);

    void floor();

    void ceil();

    void round();

    void roundToZero();

    Vector4 clone();

    Vector4 copyInto(Vector4 arg);

    void copyIntoArray(List<double> array, int offset);

    void copyFromArray(List<double> array, int offset);

    void  xy(Vector2 arg);

    void  xz(Vector2 arg);

    void  xw(Vector2 arg);

    void  yx(Vector2 arg);

    void  yz(Vector2 arg);

    void  yw(Vector2 arg);

    void  zx(Vector2 arg);

    void  zy(Vector2 arg);

    void  zw(Vector2 arg);

    void  wx(Vector2 arg);

    void  wy(Vector2 arg);

    void  wz(Vector2 arg);

    void  xyz(Vector3 arg);

    void  xyw(Vector3 arg);

    void  xzy(Vector3 arg);

    void  xzw(Vector3 arg);

    void  xwy(Vector3 arg);

    void  xwz(Vector3 arg);

    void  yxz(Vector3 arg);

    void  yxw(Vector3 arg);

    void  yzx(Vector3 arg);

    void  yzw(Vector3 arg);

    void  ywx(Vector3 arg);

    void  ywz(Vector3 arg);

    void  zxy(Vector3 arg);

    void  zxw(Vector3 arg);

    void  zyx(Vector3 arg);

    void  zyw(Vector3 arg);

    void  zwx(Vector3 arg);

    void  zwy(Vector3 arg);

    void  wxy(Vector3 arg);

    void  wxz(Vector3 arg);

    void  wyx(Vector3 arg);

    void  wyz(Vector3 arg);

    void  wzx(Vector3 arg);

    void  wzy(Vector3 arg);

    void  xyzw(Vector4 arg);

    void  xywz(Vector4 arg);

    void  xzyw(Vector4 arg);

    void  xzwy(Vector4 arg);

    void  xwyz(Vector4 arg);

    void  xwzy(Vector4 arg);

    void  yxzw(Vector4 arg);

    void  yxwz(Vector4 arg);

    void  yzxw(Vector4 arg);

    void  yzwx(Vector4 arg);

    void  ywxz(Vector4 arg);

    void  ywzx(Vector4 arg);

    void  zxyw(Vector4 arg);

    void  zxwy(Vector4 arg);

    void  zyxw(Vector4 arg);

    void  zywx(Vector4 arg);

    void  zwxy(Vector4 arg);

    void  zwyx(Vector4 arg);

    void  wxyz(Vector4 arg);

    void  wxzy(Vector4 arg);

    void  wyxz(Vector4 arg);

    void  wyzx(Vector4 arg);

    void  wzxy(Vector4 arg);

    void  wzyx(Vector4 arg);

    void  r(double arg);

    void  g(double arg);

    void  b(double arg);

    void  a(double arg);

    void  s(double arg);

    void  t(double arg);

    void  p(double arg);

    void  q(double arg);

    void  x(double arg);

    void  y(double arg);

    void  z(double arg);

    void  w(double arg);

    void  rg(Vector2 arg);

    void  rb(Vector2 arg);

    void  ra(Vector2 arg);

    void  gr(Vector2 arg);

    void  gb(Vector2 arg);

    void  ga(Vector2 arg);

    void  br(Vector2 arg);

    void  bg(Vector2 arg);

    void  ba(Vector2 arg);

    void  ar(Vector2 arg);

    void  ag(Vector2 arg);

    void  ab(Vector2 arg);

    void  rgb(Vector3 arg);

    void  rga(Vector3 arg);

    void  rbg(Vector3 arg);

    void  rba(Vector3 arg);

    void  rag(Vector3 arg);

    void  rab(Vector3 arg);

    void  grb(Vector3 arg);

    void  gra(Vector3 arg);

    void  gbr(Vector3 arg);

    void  gba(Vector3 arg);

    void  gar(Vector3 arg);

    void  gab(Vector3 arg);

    void  brg(Vector3 arg);

    void  bra(Vector3 arg);

    void  bgr(Vector3 arg);

    void  bga(Vector3 arg);

    void  bar(Vector3 arg);

    void  bag(Vector3 arg);

    void  arg(Vector3 arg);

    void  arb(Vector3 arg);

    void  agr(Vector3 arg);

    void  agb(Vector3 arg);

    void  abr(Vector3 arg);

    void  abg(Vector3 arg);

    void  rgba(Vector4 arg);

    void  rgab(Vector4 arg);

    void  rbga(Vector4 arg);

    void  rbag(Vector4 arg);

    void  ragb(Vector4 arg);

    void  rabg(Vector4 arg);

    void  grba(Vector4 arg);

    void  grab(Vector4 arg);

    void  gbra(Vector4 arg);

    void  gbar(Vector4 arg);

    void  garb(Vector4 arg);

    void  gabr(Vector4 arg);

    void  brga(Vector4 arg);

    void  brag(Vector4 arg);

    void  bgra(Vector4 arg);

    void  bgar(Vector4 arg);

    void  barg(Vector4 arg);

    void  bagr(Vector4 arg);

    void  argb(Vector4 arg);

    void  arbg(Vector4 arg);

    void  agrb(Vector4 arg);

    void  agbr(Vector4 arg);

    void  abrg(Vector4 arg);

    void  abgr(Vector4 arg);

    void  st(Vector2 arg);

    void  sp(Vector2 arg);

    void  sq(Vector2 arg);

    void  ts(Vector2 arg);

    void  tp(Vector2 arg);

    void  tq(Vector2 arg);

    void  ps(Vector2 arg);

    void  pt(Vector2 arg);

    void  pq(Vector2 arg);

    void  qs(Vector2 arg);

    void  qt(Vector2 arg);

    void  qp(Vector2 arg);

    void  stp(Vector3 arg);

    void  stq(Vector3 arg);

    void  spt(Vector3 arg);

    void  spq(Vector3 arg);

    void  sqt(Vector3 arg);

    void  sqp(Vector3 arg);

    void  tsp(Vector3 arg);

    void  tsq(Vector3 arg);

    void  tps(Vector3 arg);

    void  tpq(Vector3 arg);

    void  tqs(Vector3 arg);

    void  tqp(Vector3 arg);

    void  pst(Vector3 arg);

    void  psq(Vector3 arg);

    void  pts(Vector3 arg);

    void  ptq(Vector3 arg);

    void  pqs(Vector3 arg);

    void  pqt(Vector3 arg);

    void  qst(Vector3 arg);

    void  qsp(Vector3 arg);

    void  qts(Vector3 arg);

    void  qtp(Vector3 arg);

    void  qps(Vector3 arg);

    void  qpt(Vector3 arg);

    void  stpq(Vector4 arg);

    void  stqp(Vector4 arg);

    void  sptq(Vector4 arg);

    void  spqt(Vector4 arg);

    void  sqtp(Vector4 arg);

    void  sqpt(Vector4 arg);

    void  tspq(Vector4 arg);

    void  tsqp(Vector4 arg);

    void  tpsq(Vector4 arg);

    void  tpqs(Vector4 arg);

    void  tqsp(Vector4 arg);

    void  tqps(Vector4 arg);

    void  pstq(Vector4 arg);

    void  psqt(Vector4 arg);

    void  ptsq(Vector4 arg);

    void  ptqs(Vector4 arg);

    void  pqst(Vector4 arg);

    void  pqts(Vector4 arg);

    void  qstp(Vector4 arg);

    void  qspt(Vector4 arg);

    void  qtsp(Vector4 arg);

    void  qtps(Vector4 arg);

    void  qpst(Vector4 arg);

    void  qpts(Vector4 arg);

    Vector2 xx();

    Vector2 xy();

    Vector2 xz();

    Vector2 xw();

    Vector2 yx();

    Vector2 yy();

    Vector2 yz();

    Vector2 yw();

    Vector2 zx();

    Vector2 zy();

    Vector2 zz();

    Vector2 zw();

    Vector2 wx();

    Vector2 wy();

    Vector2 wz();

    Vector2 ww();

    Vector3 xxx();

    Vector3 xxy();

    Vector3 xxz();

    Vector3 xxw();

    Vector3 xyx();

    Vector3 xyy();

    Vector3 xyz();

    Vector3 xyw();

    Vector3 xzx();

    Vector3 xzy();

    Vector3 xzz();

    Vector3 xzw();

    Vector3 xwx();

    Vector3 xwy();

    Vector3 xwz();

    Vector3 xww();

    Vector3 yxx();

    Vector3 yxy();

    Vector3 yxz();

    Vector3 yxw();

    Vector3 yyx();

    Vector3 yyy();

    Vector3 yyz();

    Vector3 yyw();

    Vector3 yzx();

    Vector3 yzy();

    Vector3 yzz();

    Vector3 yzw();

    Vector3 ywx();

    Vector3 ywy();

    Vector3 ywz();

    Vector3 yww();

    Vector3 zxx();

    Vector3 zxy();

    Vector3 zxz();

    Vector3 zxw();

    Vector3 zyx();

    Vector3 zyy();

    Vector3 zyz();

    Vector3 zyw();

    Vector3 zzx();

    Vector3 zzy();

    Vector3 zzz();

    Vector3 zzw();

    Vector3 zwx();

    Vector3 zwy();

    Vector3 zwz();

    Vector3 zww();

    Vector3 wxx();

    Vector3 wxy();

    Vector3 wxz();

    Vector3 wxw();

    Vector3 wyx();

    Vector3 wyy();

    Vector3 wyz();

    Vector3 wyw();

    Vector3 wzx();

    Vector3 wzy();

    Vector3 wzz();

    Vector3 wzw();

    Vector3 wwx();

    Vector3 wwy();

    Vector3 wwz();

    Vector3 www();

    Vector4 xxxx();

    Vector4 xxxy();

    Vector4 xxxz();

    Vector4 xxxw();

    Vector4 xxyx();

    Vector4 xxyy();

    Vector4 xxyz();

    Vector4 xxyw();

    Vector4 xxzx();

    Vector4 xxzy();

    Vector4 xxzz();

    Vector4 xxzw();

    Vector4 xxwx();

    Vector4 xxwy();

    Vector4 xxwz();

    Vector4 xxww();

    Vector4 xyxx();

    Vector4 xyxy();

    Vector4 xyxz();

    Vector4 xyxw();

    Vector4 xyyx();

    Vector4 xyyy();

    Vector4 xyyz();

    Vector4 xyyw();

    Vector4 xyzx();

    Vector4 xyzy();

    Vector4 xyzz();

    Vector4 xyzw();

    Vector4 xywx();

    Vector4 xywy();

    Vector4 xywz();

    Vector4 xyww();

    Vector4 xzxx();

    Vector4 xzxy();

    Vector4 xzxz();

    Vector4 xzxw();

    Vector4 xzyx();

    Vector4 xzyy();

    Vector4 xzyz();

    Vector4 xzyw();

    Vector4 xzzx();

    Vector4 xzzy();

    Vector4 xzzz();

    Vector4 xzzw();

    Vector4 xzwx();

    Vector4 xzwy();

    Vector4 xzwz();

    Vector4 xzww();

    Vector4 xwxx();

    Vector4 xwxy();

    Vector4 xwxz();

    Vector4 xwxw();

    Vector4 xwyx();

    Vector4 xwyy();

    Vector4 xwyz();

    Vector4 xwyw();

    Vector4 xwzx();

    Vector4 xwzy();

    Vector4 xwzz();

    Vector4 xwzw();

    Vector4 xwwx();

    Vector4 xwwy();

    Vector4 xwwz();

    Vector4 xwww();

    Vector4 yxxx();

    Vector4 yxxy();

    Vector4 yxxz();

    Vector4 yxxw();

    Vector4 yxyx();

    Vector4 yxyy();

    Vector4 yxyz();

    Vector4 yxyw();

    Vector4 yxzx();

    Vector4 yxzy();

    Vector4 yxzz();

    Vector4 yxzw();

    Vector4 yxwx();

    Vector4 yxwy();

    Vector4 yxwz();

    Vector4 yxww();

    Vector4 yyxx();

    Vector4 yyxy();

    Vector4 yyxz();

    Vector4 yyxw();

    Vector4 yyyx();

    Vector4 yyyy();

    Vector4 yyyz();

    Vector4 yyyw();

    Vector4 yyzx();

    Vector4 yyzy();

    Vector4 yyzz();

    Vector4 yyzw();

    Vector4 yywx();

    Vector4 yywy();

    Vector4 yywz();

    Vector4 yyww();

    Vector4 yzxx();

    Vector4 yzxy();

    Vector4 yzxz();

    Vector4 yzxw();

    Vector4 yzyx();

    Vector4 yzyy();

    Vector4 yzyz();

    Vector4 yzyw();

    Vector4 yzzx();

    Vector4 yzzy();

    Vector4 yzzz();

    Vector4 yzzw();

    Vector4 yzwx();

    Vector4 yzwy();

    Vector4 yzwz();

    Vector4 yzww();

    Vector4 ywxx();

    Vector4 ywxy();

    Vector4 ywxz();

    Vector4 ywxw();

    Vector4 ywyx();

    Vector4 ywyy();

    Vector4 ywyz();

    Vector4 ywyw();

    Vector4 ywzx();

    Vector4 ywzy();

    Vector4 ywzz();

    Vector4 ywzw();

    Vector4 ywwx();

    Vector4 ywwy();

    Vector4 ywwz();

    Vector4 ywww();

    Vector4 zxxx();

    Vector4 zxxy();

    Vector4 zxxz();

    Vector4 zxxw();

    Vector4 zxyx();

    Vector4 zxyy();

    Vector4 zxyz();

    Vector4 zxyw();

    Vector4 zxzx();

    Vector4 zxzy();

    Vector4 zxzz();

    Vector4 zxzw();

    Vector4 zxwx();

    Vector4 zxwy();

    Vector4 zxwz();

    Vector4 zxww();

    Vector4 zyxx();

    Vector4 zyxy();

    Vector4 zyxz();

    Vector4 zyxw();

    Vector4 zyyx();

    Vector4 zyyy();

    Vector4 zyyz();

    Vector4 zyyw();

    Vector4 zyzx();

    Vector4 zyzy();

    Vector4 zyzz();

    Vector4 zyzw();

    Vector4 zywx();

    Vector4 zywy();

    Vector4 zywz();

    Vector4 zyww();

    Vector4 zzxx();

    Vector4 zzxy();

    Vector4 zzxz();

    Vector4 zzxw();

    Vector4 zzyx();

    Vector4 zzyy();

    Vector4 zzyz();

    Vector4 zzyw();

    Vector4 zzzx();

    Vector4 zzzy();

    Vector4 zzzz();

    Vector4 zzzw();

    Vector4 zzwx();

    Vector4 zzwy();

    Vector4 zzwz();

    Vector4 zzww();

    Vector4 zwxx();

    Vector4 zwxy();

    Vector4 zwxz();

    Vector4 zwxw();

    Vector4 zwyx();

    Vector4 zwyy();

    Vector4 zwyz();

    Vector4 zwyw();

    Vector4 zwzx();

    Vector4 zwzy();

    Vector4 zwzz();

    Vector4 zwzw();

    Vector4 zwwx();

    Vector4 zwwy();

    Vector4 zwwz();

    Vector4 zwww();

    Vector4 wxxx();

    Vector4 wxxy();

    Vector4 wxxz();

    Vector4 wxxw();

    Vector4 wxyx();

    Vector4 wxyy();

    Vector4 wxyz();

    Vector4 wxyw();

    Vector4 wxzx();

    Vector4 wxzy();

    Vector4 wxzz();

    Vector4 wxzw();

    Vector4 wxwx();

    Vector4 wxwy();

    Vector4 wxwz();

    Vector4 wxww();

    Vector4 wyxx();

    Vector4 wyxy();

    Vector4 wyxz();

    Vector4 wyxw();

    Vector4 wyyx();

    Vector4 wyyy();

    Vector4 wyyz();

    Vector4 wyyw();

    Vector4 wyzx();

    Vector4 wyzy();

    Vector4 wyzz();

    Vector4 wyzw();

    Vector4 wywx();

    Vector4 wywy();

    Vector4 wywz();

    Vector4 wyww();

    Vector4 wzxx();

    Vector4 wzxy();

    Vector4 wzxz();

    Vector4 wzxw();

    Vector4 wzyx();

    Vector4 wzyy();

    Vector4 wzyz();

    Vector4 wzyw();

    Vector4 wzzx();

    Vector4 wzzy();

    Vector4 wzzz();

    Vector4 wzzw();

    Vector4 wzwx();

    Vector4 wzwy();

    Vector4 wzwz();

    Vector4 wzww();

    Vector4 wwxx();

    Vector4 wwxy();

    Vector4 wwxz();

    Vector4 wwxw();

    Vector4 wwyx();

    Vector4 wwyy();

    Vector4 wwyz();

    Vector4 wwyw();

    Vector4 wwzx();

    Vector4 wwzy();

    Vector4 wwzz();

    Vector4 wwzw();

    Vector4 wwwx();

    Vector4 wwwy();

    Vector4 wwwz();

    Vector4 wwww();

    double r();

    double g();

    double b();

    double a();

    double s();

    double t();

    double p();

    double q();

    double x();

    double y();

    double z();

    double w();

    Vector2 rr();

    Vector2 rg();

    Vector2 rb();

    Vector2 ra();

    Vector2 gr();

    Vector2 gg();

    Vector2 gb();

    Vector2 ga();

    Vector2 br();

    Vector2 bg();

    Vector2 bb();

    Vector2 ba();

    Vector2 ar();

    Vector2 ag();

    Vector2 ab();

    Vector2 aa();

    Vector3 rrr();

    Vector3 rrg();

    Vector3 rrb();

    Vector3 rra();

    Vector3 rgr();

    Vector3 rgg();

    Vector3 rgb();

    Vector3 rga();

    Vector3 rbr();

    Vector3 rbg();

    Vector3 rbb();

    Vector3 rba();

    Vector3 rar();

    Vector3 rag();

    Vector3 rab();

    Vector3 raa();

    Vector3 grr();

    Vector3 grg();

    Vector3 grb();

    Vector3 gra();

    Vector3 ggr();

    Vector3 ggg();

    Vector3 ggb();

    Vector3 gga();

    Vector3 gbr();

    Vector3 gbg();

    Vector3 gbb();

    Vector3 gba();

    Vector3 gar();

    Vector3 gag();

    Vector3 gab();

    Vector3 gaa();

    Vector3 brr();

    Vector3 brg();

    Vector3 brb();

    Vector3 bra();

    Vector3 bgr();

    Vector3 bgg();

    Vector3 bgb();

    Vector3 bga();

    Vector3 bbr();

    Vector3 bbg();

    Vector3 bbb();

    Vector3 bba();

    Vector3 bar();

    Vector3 bag();

    Vector3 bab();

    Vector3 baa();

    Vector3 arr();

    Vector3 arg();

    Vector3 arb();

    Vector3 ara();

    Vector3 agr();

    Vector3 agg();

    Vector3 agb();

    Vector3 aga();

    Vector3 abr();

    Vector3 abg();

    Vector3 abb();

    Vector3 aba();

    Vector3 aar();

    Vector3 aag();

    Vector3 aab();

    Vector3 aaa();

    Vector4 rrrr();

    Vector4 rrrg();

    Vector4 rrrb();

    Vector4 rrra();

    Vector4 rrgr();

    Vector4 rrgg();

    Vector4 rrgb();

    Vector4 rrga();

    Vector4 rrbr();

    Vector4 rrbg();

    Vector4 rrbb();

    Vector4 rrba();

    Vector4 rrar();

    Vector4 rrag();

    Vector4 rrab();

    Vector4 rraa();

    Vector4 rgrr();

    Vector4 rgrg();

    Vector4 rgrb();

    Vector4 rgra();

    Vector4 rggr();

    Vector4 rggg();

    Vector4 rggb();

    Vector4 rgga();

    Vector4 rgbr();

    Vector4 rgbg();

    Vector4 rgbb();

    Vector4 rgba();

    Vector4 rgar();

    Vector4 rgag();

    Vector4 rgab();

    Vector4 rgaa();

    Vector4 rbrr();

    Vector4 rbrg();

    Vector4 rbrb();

    Vector4 rbra();

    Vector4 rbgr();

    Vector4 rbgg();

    Vector4 rbgb();

    Vector4 rbga();

    Vector4 rbbr();

    Vector4 rbbg();

    Vector4 rbbb();

    Vector4 rbba();

    Vector4 rbar();

    Vector4 rbag();

    Vector4 rbab();

    Vector4 rbaa();

    Vector4 rarr();

    Vector4 rarg();

    Vector4 rarb();

    Vector4 rara();

    Vector4 ragr();

    Vector4 ragg();

    Vector4 ragb();

    Vector4 raga();

    Vector4 rabr();

    Vector4 rabg();

    Vector4 rabb();

    Vector4 raba();

    Vector4 raar();

    Vector4 raag();

    Vector4 raab();

    Vector4 raaa();

    Vector4 grrr();

    Vector4 grrg();

    Vector4 grrb();

    Vector4 grra();

    Vector4 grgr();

    Vector4 grgg();

    Vector4 grgb();

    Vector4 grga();

    Vector4 grbr();

    Vector4 grbg();

    Vector4 grbb();

    Vector4 grba();

    Vector4 grar();

    Vector4 grag();

    Vector4 grab();

    Vector4 graa();

    Vector4 ggrr();

    Vector4 ggrg();

    Vector4 ggrb();

    Vector4 ggra();

    Vector4 gggr();

    Vector4 gggg();

    Vector4 gggb();

    Vector4 ggga();

    Vector4 ggbr();

    Vector4 ggbg();

    Vector4 ggbb();

    Vector4 ggba();

    Vector4 ggar();

    Vector4 ggag();

    Vector4 ggab();

    Vector4 ggaa();

    Vector4 gbrr();

    Vector4 gbrg();

    Vector4 gbrb();

    Vector4 gbra();

    Vector4 gbgr();

    Vector4 gbgg();

    Vector4 gbgb();

    Vector4 gbga();

    Vector4 gbbr();

    Vector4 gbbg();

    Vector4 gbbb();

    Vector4 gbba();

    Vector4 gbar();

    Vector4 gbag();

    Vector4 gbab();

    Vector4 gbaa();

    Vector4 garr();

    Vector4 garg();

    Vector4 garb();

    Vector4 gara();

    Vector4 gagr();

    Vector4 gagg();

    Vector4 gagb();

    Vector4 gaga();

    Vector4 gabr();

    Vector4 gabg();

    Vector4 gabb();

    Vector4 gaba();

    Vector4 gaar();

    Vector4 gaag();

    Vector4 gaab();

    Vector4 gaaa();

    Vector4 brrr();

    Vector4 brrg();

    Vector4 brrb();

    Vector4 brra();

    Vector4 brgr();

    Vector4 brgg();

    Vector4 brgb();

    Vector4 brga();

    Vector4 brbr();

    Vector4 brbg();

    Vector4 brbb();

    Vector4 brba();

    Vector4 brar();

    Vector4 brag();

    Vector4 brab();

    Vector4 braa();

    Vector4 bgrr();

    Vector4 bgrg();

    Vector4 bgrb();

    Vector4 bgra();

    Vector4 bggr();

    Vector4 bggg();

    Vector4 bggb();

    Vector4 bgga();

    Vector4 bgbr();

    Vector4 bgbg();

    Vector4 bgbb();

    Vector4 bgba();

    Vector4 bgar();

    Vector4 bgag();

    Vector4 bgab();

    Vector4 bgaa();

    Vector4 bbrr();

    Vector4 bbrg();

    Vector4 bbrb();

    Vector4 bbra();

    Vector4 bbgr();

    Vector4 bbgg();

    Vector4 bbgb();

    Vector4 bbga();

    Vector4 bbbr();

    Vector4 bbbg();

    Vector4 bbbb();

    Vector4 bbba();

    Vector4 bbar();

    Vector4 bbag();

    Vector4 bbab();

    Vector4 bbaa();

    Vector4 barr();

    Vector4 barg();

    Vector4 barb();

    Vector4 bara();

    Vector4 bagr();

    Vector4 bagg();

    Vector4 bagb();

    Vector4 baga();

    Vector4 babr();

    Vector4 babg();

    Vector4 babb();

    Vector4 baba();

    Vector4 baar();

    Vector4 baag();

    Vector4 baab();

    Vector4 baaa();

    Vector4 arrr();

    Vector4 arrg();

    Vector4 arrb();

    Vector4 arra();

    Vector4 argr();

    Vector4 argg();

    Vector4 argb();

    Vector4 arga();

    Vector4 arbr();

    Vector4 arbg();

    Vector4 arbb();

    Vector4 arba();

    Vector4 arar();

    Vector4 arag();

    Vector4 arab();

    Vector4 araa();

    Vector4 agrr();

    Vector4 agrg();

    Vector4 agrb();

    Vector4 agra();

    Vector4 aggr();

    Vector4 aggg();

    Vector4 aggb();

    Vector4 agga();

    Vector4 agbr();

    Vector4 agbg();

    Vector4 agbb();

    Vector4 agba();

    Vector4 agar();

    Vector4 agag();

    Vector4 agab();

    Vector4 agaa();

    Vector4 abrr();

    Vector4 abrg();

    Vector4 abrb();

    Vector4 abra();

    Vector4 abgr();

    Vector4 abgg();

    Vector4 abgb();

    Vector4 abga();

    Vector4 abbr();

    Vector4 abbg();

    Vector4 abbb();

    Vector4 abba();

    Vector4 abar();

    Vector4 abag();

    Vector4 abab();

    Vector4 abaa();

    Vector4 aarr();

    Vector4 aarg();

    Vector4 aarb();

    Vector4 aara();

    Vector4 aagr();

    Vector4 aagg();

    Vector4 aagb();

    Vector4 aaga();

    Vector4 aabr();

    Vector4 aabg();

    Vector4 aabb();

    Vector4 aaba();

    Vector4 aaar();

    Vector4 aaag();

    Vector4 aaab();

    Vector4 aaaa();

    Vector2 ss();

    Vector2 st();

    Vector2 sp();

    Vector2 sq();

    Vector2 ts();

    Vector2 tt();

    Vector2 tp();

    Vector2 tq();

    Vector2 ps();

    Vector2 pt();

    Vector2 pp();

    Vector2 pq();

    Vector2 qs();

    Vector2 qt();

    Vector2 qp();

    Vector2 qq();

    Vector3 sss();

    Vector3 sst();

    Vector3 ssp();

    Vector3 ssq();

    Vector3 sts();

    Vector3 stt();

    Vector3 stp();

    Vector3 stq();

    Vector3 sps();

    Vector3 spt();

    Vector3 spp();

    Vector3 spq();

    Vector3 sqs();

    Vector3 sqt();

    Vector3 sqp();

    Vector3 sqq();

    Vector3 tss();

    Vector3 tst();

    Vector3 tsp();

    Vector3 tsq();

    Vector3 tts();

    Vector3 ttt();

    Vector3 ttp();

    Vector3 ttq();

    Vector3 tps();

    Vector3 tpt();

    Vector3 tpp();

    Vector3 tpq();

    Vector3 tqs();

    Vector3 tqt();

    Vector3 tqp();

    Vector3 tqq();

    Vector3 pss();

    Vector3 pst();

    Vector3 psp();

    Vector3 psq();

    Vector3 pts();

    Vector3 ptt();

    Vector3 ptp();

    Vector3 ptq();

    Vector3 pps();

    Vector3 ppt();

    Vector3 ppp();

    Vector3 ppq();

    Vector3 pqs();

    Vector3 pqt();

    Vector3 pqp();

    Vector3 pqq();

    Vector3 qss();

    Vector3 qst();

    Vector3 qsp();

    Vector3 qsq();

    Vector3 qts();

    Vector3 qtt();

    Vector3 qtp();

    Vector3 qtq();

    Vector3 qps();

    Vector3 qpt();

    Vector3 qpp();

    Vector3 qpq();

    Vector3 qqs();

    Vector3 qqt();

    Vector3 qqp();

    Vector3 qqq();

    Vector4 ssss();

    Vector4 ssst();

    Vector4 sssp();

    Vector4 sssq();

    Vector4 ssts();

    Vector4 sstt();

    Vector4 sstp();

    Vector4 sstq();

    Vector4 ssps();

    Vector4 sspt();

    Vector4 sspp();

    Vector4 sspq();

    Vector4 ssqs();

    Vector4 ssqt();

    Vector4 ssqp();

    Vector4 ssqq();

    Vector4 stss();

    Vector4 stst();

    Vector4 stsp();

    Vector4 stsq();

    Vector4 stts();

    Vector4 sttt();

    Vector4 sttp();

    Vector4 sttq();

    Vector4 stps();

    Vector4 stpt();

    Vector4 stpp();

    Vector4 stpq();

    Vector4 stqs();

    Vector4 stqt();

    Vector4 stqp();

    Vector4 stqq();

    Vector4 spss();

    Vector4 spst();

    Vector4 spsp();

    Vector4 spsq();

    Vector4 spts();

    Vector4 sptt();

    Vector4 sptp();

    Vector4 sptq();

    Vector4 spps();

    Vector4 sppt();

    Vector4 sppp();

    Vector4 sppq();

    Vector4 spqs();

    Vector4 spqt();

    Vector4 spqp();

    Vector4 spqq();

    Vector4 sqss();

    Vector4 sqst();

    Vector4 sqsp();

    Vector4 sqsq();

    Vector4 sqts();

    Vector4 sqtt();

    Vector4 sqtp();

    Vector4 sqtq();

    Vector4 sqps();

    Vector4 sqpt();

    Vector4 sqpp();

    Vector4 sqpq();

    Vector4 sqqs();

    Vector4 sqqt();

    Vector4 sqqp();

    Vector4 sqqq();

    Vector4 tsss();

    Vector4 tsst();

    Vector4 tssp();

    Vector4 tssq();

    Vector4 tsts();

    Vector4 tstt();

    Vector4 tstp();

    Vector4 tstq();

    Vector4 tsps();

    Vector4 tspt();

    Vector4 tspp();

    Vector4 tspq();

    Vector4 tsqs();

    Vector4 tsqt();

    Vector4 tsqp();

    Vector4 tsqq();

    Vector4 ttss();

    Vector4 ttst();

    Vector4 ttsp();

    Vector4 ttsq();

    Vector4 ttts();

    Vector4 tttt();

    Vector4 tttp();

    Vector4 tttq();

    Vector4 ttps();

    Vector4 ttpt();

    Vector4 ttpp();

    Vector4 ttpq();

    Vector4 ttqs();

    Vector4 ttqt();

    Vector4 ttqp();

    Vector4 ttqq();

    Vector4 tpss();

    Vector4 tpst();

    Vector4 tpsp();

    Vector4 tpsq();

    Vector4 tpts();

    Vector4 tptt();

    Vector4 tptp();

    Vector4 tptq();

    Vector4 tpps();

    Vector4 tppt();

    Vector4 tppp();

    Vector4 tppq();

    Vector4 tpqs();

    Vector4 tpqt();

    Vector4 tpqp();

    Vector4 tpqq();

    Vector4 tqss();

    Vector4 tqst();

    Vector4 tqsp();

    Vector4 tqsq();

    Vector4 tqts();

    Vector4 tqtt();

    Vector4 tqtp();

    Vector4 tqtq();

    Vector4 tqps();

    Vector4 tqpt();

    Vector4 tqpp();

    Vector4 tqpq();

    Vector4 tqqs();

    Vector4 tqqt();

    Vector4 tqqp();

    Vector4 tqqq();

    Vector4 psss();

    Vector4 psst();

    Vector4 pssp();

    Vector4 pssq();

    Vector4 psts();

    Vector4 pstt();

    Vector4 pstp();

    Vector4 pstq();

    Vector4 psps();

    Vector4 pspt();

    Vector4 pspp();

    Vector4 pspq();

    Vector4 psqs();

    Vector4 psqt();

    Vector4 psqp();

    Vector4 psqq();

    Vector4 ptss();

    Vector4 ptst();

    Vector4 ptsp();

    Vector4 ptsq();

    Vector4 ptts();

    Vector4 pttt();

    Vector4 pttp();

    Vector4 pttq();

    Vector4 ptps();

    Vector4 ptpt();

    Vector4 ptpp();

    Vector4 ptpq();

    Vector4 ptqs();

    Vector4 ptqt();

    Vector4 ptqp();

    Vector4 ptqq();

    Vector4 ppss();

    Vector4 ppst();

    Vector4 ppsp();

    Vector4 ppsq();

    Vector4 ppts();

    Vector4 pptt();

    Vector4 pptp();

    Vector4 pptq();

    Vector4 ppps();

    Vector4 pppt();

    Vector4 pppp();

    Vector4 pppq();

    Vector4 ppqs();

    Vector4 ppqt();

    Vector4 ppqp();

    Vector4 ppqq();

    Vector4 pqss();

    Vector4 pqst();

    Vector4 pqsp();

    Vector4 pqsq();

    Vector4 pqts();

    Vector4 pqtt();

    Vector4 pqtp();

    Vector4 pqtq();

    Vector4 pqps();

    Vector4 pqpt();

    Vector4 pqpp();

    Vector4 pqpq();

    Vector4 pqqs();

    Vector4 pqqt();

    Vector4 pqqp();

    Vector4 pqqq();

    Vector4 qsss();

    Vector4 qsst();

    Vector4 qssp();

    Vector4 qssq();

    Vector4 qsts();

    Vector4 qstt();

    Vector4 qstp();

    Vector4 qstq();

    Vector4 qsps();

    Vector4 qspt();

    Vector4 qspp();

    Vector4 qspq();

    Vector4 qsqs();

    Vector4 qsqt();

    Vector4 qsqp();

    Vector4 qsqq();

    Vector4 qtss();

    Vector4 qtst();

    Vector4 qtsp();

    Vector4 qtsq();

    Vector4 qtts();

    Vector4 qttt();

    Vector4 qttp();

    Vector4 qttq();

    Vector4 qtps();

    Vector4 qtpt();

    Vector4 qtpp();

    Vector4 qtpq();

    Vector4 qtqs();

    Vector4 qtqt();

    Vector4 qtqp();

    Vector4 qtqq();

    Vector4 qpss();

    Vector4 qpst();

    Vector4 qpsp();

    Vector4 qpsq();

    Vector4 qpts();

    Vector4 qptt();

    Vector4 qptp();

    Vector4 qptq();

    Vector4 qpps();

    Vector4 qppt();

    Vector4 qppp();

    Vector4 qppq();

    Vector4 qpqs();

    Vector4 qpqt();

    Vector4 qpqp();

    Vector4 qpqq();

    Vector4 qqss();

    Vector4 qqst();

    Vector4 qqsp();

    Vector4 qqsq();

    Vector4 qqts();

    Vector4 qqtt();

    Vector4 qqtp();

    Vector4 qqtq();

    Vector4 qqps();

    Vector4 qqpt();

    Vector4 qqpp();

    Vector4 qqpq();

    Vector4 qqqs();

    Vector4 qqqt();

    Vector4 qqqp();

    Vector4 qqqq();

private:
    Float64List _v4storage;


};

#endif