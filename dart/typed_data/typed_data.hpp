#ifndef DART_TYPED_DATA_TYPED_DATA
#define DART_TYPED_DATA_TYPED_DATA
#include <base.hpp>
#include <dart/internal/internal.hpp>

#include <dart/core/core.hpp>
#include <dart/internal/internal.hpp>


class ByteBufferCls : public ObjectCls {
public:

    virtual int lengthInBytes();
    virtual Uint8List asUint8List(int offsetInBytes, int length);
    virtual Int8List asInt8List(int offsetInBytes, int length);
    virtual Uint8ClampedList asUint8ClampedList(int offsetInBytes, int length);
    virtual Uint16List asUint16List(int offsetInBytes, int length);
    virtual Int16List asInt16List(int offsetInBytes, int length);
    virtual Uint32List asUint32List(int offsetInBytes, int length);
    virtual Int32List asInt32List(int offsetInBytes, int length);
    virtual Uint64List asUint64List(int offsetInBytes, int length);
    virtual Int64List asInt64List(int offsetInBytes, int length);
    virtual Int32x4List asInt32x4List(int offsetInBytes, int length);
    virtual Float32List asFloat32List(int offsetInBytes, int length);
    virtual Float64List asFloat64List(int offsetInBytes, int length);
    virtual Float32x4List asFloat32x4List(int offsetInBytes, int length);
    virtual Float64x2List asFloat64x2List(int offsetInBytes, int length);
    virtual ByteData asByteData(int offsetInBytes, int length);
private:

};
using ByteBuffer = std::shared_ptr<ByteBufferCls>;

class TypedDataCls : public ObjectCls {
public:

    virtual int elementSizeInBytes();
    virtual int offsetInBytes();
    virtual int lengthInBytes();
    virtual ByteBuffer buffer();
private:

};
using TypedData = std::shared_ptr<TypedDataCls>;

class _TypedIntListCls : public TypedDataCls {
public:

    virtual List<int> operator+(List<int> other);
private:

};
using _TypedIntList = std::shared_ptr<_TypedIntListCls>;

class _TypedFloatListCls : public TypedDataCls {
public:

    virtual List<double> operator+(List<double> other);
private:

};
using _TypedFloatList = std::shared_ptr<_TypedFloatListCls>;

class EndianCls : public ObjectCls {
public:
    static Endian big;

    static Endian little;

    static Endian host;


private:
    bool _littleEndian;


    virtual void  _(bool _littleEndian);
};
using Endian = std::shared_ptr<EndianCls>;

class ByteDataCls : public ObjectCls {
public:

     ByteDataCls(int length);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual int getInt8(int byteOffset);
    virtual void setInt8(int byteOffset, int value);
    virtual int getUint8(int byteOffset);
    virtual void setUint8(int byteOffset, int value);
    virtual int getInt16(int byteOffset, Endian endian);
    virtual void setInt16(int byteOffset, int value, Endian endian);
    virtual int getUint16(int byteOffset, Endian endian);
    virtual void setUint16(int byteOffset, int value, Endian endian);
    virtual int getInt32(int byteOffset, Endian endian);
    virtual void setInt32(int byteOffset, int value, Endian endian);
    virtual int getUint32(int byteOffset, Endian endian);
    virtual void setUint32(int byteOffset, int value, Endian endian);
    virtual int getInt64(int byteOffset, Endian endian);
    virtual void setInt64(int byteOffset, int value, Endian endian);
    virtual int getUint64(int byteOffset, Endian endian);
    virtual void setUint64(int byteOffset, int value, Endian endian);
    virtual double getFloat32(int byteOffset, Endian endian);
    virtual void setFloat32(int byteOffset, double value, Endian endian);
    virtual double getFloat64(int byteOffset, Endian endian);
    virtual void setFloat64(int byteOffset, double value, Endian endian);
private:

};
using ByteData = std::shared_ptr<ByteDataCls>;

class Int8ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Int8ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Int8List sublist(int start, int end);
private:

};
using Int8List = std::shared_ptr<Int8ListCls>;

class Uint8ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Uint8ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual List<int> operator+(List<int> other);
    virtual Uint8List sublist(int start, int end);
private:

};
using Uint8List = std::shared_ptr<Uint8ListCls>;

class Uint8ClampedListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Uint8ClampedListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Uint8ClampedList sublist(int start, int end);
private:

};
using Uint8ClampedList = std::shared_ptr<Uint8ClampedListCls>;

class Int16ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Int16ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Int16List sublist(int start, int end);
private:

};
using Int16List = std::shared_ptr<Int16ListCls>;

class Uint16ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Uint16ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Uint16List sublist(int start, int end);
private:

};
using Uint16List = std::shared_ptr<Uint16ListCls>;

class Int32ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Int32ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Int32List sublist(int start, int end);
private:

};
using Int32List = std::shared_ptr<Int32ListCls>;

class Uint32ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Uint32ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Uint32List sublist(int start, int end);
private:

};
using Uint32List = std::shared_ptr<Uint32ListCls>;

class Int64ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Int64ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Int64List sublist(int start, int end);
private:

};
using Int64List = std::shared_ptr<Int64ListCls>;

class Uint64ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Uint64ListCls(int length);
    void  fromList(List<int> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Uint64List sublist(int start, int end);
private:

};
using Uint64List = std::shared_ptr<Uint64ListCls>;

class Float32ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Float32ListCls(int length);
    void  fromList(List<double> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Float32List sublist(int start, int end);
private:

};
using Float32List = std::shared_ptr<Float32ListCls>;

class Float64ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Float64ListCls(int length);
    void  fromList(List<double> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Float64List sublist(int start, int end);
private:

};
using Float64List = std::shared_ptr<Float64ListCls>;

class Float32x4ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Float32x4ListCls(int length);
    void  fromList(List<Float32x4> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual List<Float32x4> operator+(List<Float32x4> other);
    virtual Float32x4List sublist(int start, int end);
private:

};
using Float32x4List = std::shared_ptr<Float32x4ListCls>;

class Int32x4ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Int32x4ListCls(int length);
    void  fromList(List<Int32x4> elements);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual List<Int32x4> operator+(List<Int32x4> other);
    virtual Int32x4List sublist(int start, int end);
private:

};
using Int32x4List = std::shared_ptr<Int32x4ListCls>;

class Float64x2ListCls : public ObjectCls {
public:
    static int bytesPerElement;


     Float64x2ListCls(int length);
    void  fromList(List<Float64x2> elements);
    virtual List<Float64x2> operator+(List<Float64x2> other);
    virtual void  view(ByteBuffer buffer, int offsetInBytes, int length);

    virtual void  sublistView(TypedData data, int start, int end);

    virtual Float64x2List sublist(int start, int end);
private:

};
using Float64x2List = std::shared_ptr<Float64x2ListCls>;

class Float32x4Cls : public ObjectCls {
public:
    static int xxxx;

    static int xxxy;

    static int xxxz;

    static int xxxw;

    static int xxyx;

    static int xxyy;

    static int xxyz;

    static int xxyw;

    static int xxzx;

    static int xxzy;

    static int xxzz;

    static int xxzw;

    static int xxwx;

    static int xxwy;

    static int xxwz;

    static int xxww;

    static int xyxx;

    static int xyxy;

    static int xyxz;

    static int xyxw;

    static int xyyx;

    static int xyyy;

    static int xyyz;

    static int xyyw;

    static int xyzx;

    static int xyzy;

    static int xyzz;

    static int xyzw;

    static int xywx;

    static int xywy;

    static int xywz;

    static int xyww;

    static int xzxx;

    static int xzxy;

    static int xzxz;

    static int xzxw;

    static int xzyx;

    static int xzyy;

    static int xzyz;

    static int xzyw;

    static int xzzx;

    static int xzzy;

    static int xzzz;

    static int xzzw;

    static int xzwx;

    static int xzwy;

    static int xzwz;

    static int xzww;

    static int xwxx;

    static int xwxy;

    static int xwxz;

    static int xwxw;

    static int xwyx;

    static int xwyy;

    static int xwyz;

    static int xwyw;

    static int xwzx;

    static int xwzy;

    static int xwzz;

    static int xwzw;

    static int xwwx;

    static int xwwy;

    static int xwwz;

    static int xwww;

    static int yxxx;

    static int yxxy;

    static int yxxz;

    static int yxxw;

    static int yxyx;

    static int yxyy;

    static int yxyz;

    static int yxyw;

    static int yxzx;

    static int yxzy;

    static int yxzz;

    static int yxzw;

    static int yxwx;

    static int yxwy;

    static int yxwz;

    static int yxww;

    static int yyxx;

    static int yyxy;

    static int yyxz;

    static int yyxw;

    static int yyyx;

    static int yyyy;

    static int yyyz;

    static int yyyw;

    static int yyzx;

    static int yyzy;

    static int yyzz;

    static int yyzw;

    static int yywx;

    static int yywy;

    static int yywz;

    static int yyww;

    static int yzxx;

    static int yzxy;

    static int yzxz;

    static int yzxw;

    static int yzyx;

    static int yzyy;

    static int yzyz;

    static int yzyw;

    static int yzzx;

    static int yzzy;

    static int yzzz;

    static int yzzw;

    static int yzwx;

    static int yzwy;

    static int yzwz;

    static int yzww;

    static int ywxx;

    static int ywxy;

    static int ywxz;

    static int ywxw;

    static int ywyx;

    static int ywyy;

    static int ywyz;

    static int ywyw;

    static int ywzx;

    static int ywzy;

    static int ywzz;

    static int ywzw;

    static int ywwx;

    static int ywwy;

    static int ywwz;

    static int ywww;

    static int zxxx;

    static int zxxy;

    static int zxxz;

    static int zxxw;

    static int zxyx;

    static int zxyy;

    static int zxyz;

    static int zxyw;

    static int zxzx;

    static int zxzy;

    static int zxzz;

    static int zxzw;

    static int zxwx;

    static int zxwy;

    static int zxwz;

    static int zxww;

    static int zyxx;

    static int zyxy;

    static int zyxz;

    static int zyxw;

    static int zyyx;

    static int zyyy;

    static int zyyz;

    static int zyyw;

    static int zyzx;

    static int zyzy;

    static int zyzz;

    static int zyzw;

    static int zywx;

    static int zywy;

    static int zywz;

    static int zyww;

    static int zzxx;

    static int zzxy;

    static int zzxz;

    static int zzxw;

    static int zzyx;

    static int zzyy;

    static int zzyz;

    static int zzyw;

    static int zzzx;

    static int zzzy;

    static int zzzz;

    static int zzzw;

    static int zzwx;

    static int zzwy;

    static int zzwz;

    static int zzww;

    static int zwxx;

    static int zwxy;

    static int zwxz;

    static int zwxw;

    static int zwyx;

    static int zwyy;

    static int zwyz;

    static int zwyw;

    static int zwzx;

    static int zwzy;

    static int zwzz;

    static int zwzw;

    static int zwwx;

    static int zwwy;

    static int zwwz;

    static int zwww;

    static int wxxx;

    static int wxxy;

    static int wxxz;

    static int wxxw;

    static int wxyx;

    static int wxyy;

    static int wxyz;

    static int wxyw;

    static int wxzx;

    static int wxzy;

    static int wxzz;

    static int wxzw;

    static int wxwx;

    static int wxwy;

    static int wxwz;

    static int wxww;

    static int wyxx;

    static int wyxy;

    static int wyxz;

    static int wyxw;

    static int wyyx;

    static int wyyy;

    static int wyyz;

    static int wyyw;

    static int wyzx;

    static int wyzy;

    static int wyzz;

    static int wyzw;

    static int wywx;

    static int wywy;

    static int wywz;

    static int wyww;

    static int wzxx;

    static int wzxy;

    static int wzxz;

    static int wzxw;

    static int wzyx;

    static int wzyy;

    static int wzyz;

    static int wzyw;

    static int wzzx;

    static int wzzy;

    static int wzzz;

    static int wzzw;

    static int wzwx;

    static int wzwy;

    static int wzwz;

    static int wzww;

    static int wwxx;

    static int wwxy;

    static int wwxz;

    static int wwxw;

    static int wwyx;

    static int wwyy;

    static int wwyz;

    static int wwyw;

    static int wwzx;

    static int wwzy;

    static int wwzz;

    static int wwzw;

    static int wwwx;

    static int wwwy;

    static int wwwz;

    static int wwww;


     Float32x4Cls(double x, double y, double z, double w);
    void  splat(double v);
    void  zero();
    void  fromInt32x4Bits(Int32x4 x);
    void  fromFloat64x2(Float64x2 v);
    virtual Float32x4 operator+(Float32x4 other);
    virtual Float32x4 operator-();
    virtual Float32x4 operator-(Float32x4 other);
    virtual Float32x4 operator*(Float32x4 other);
    virtual Float32x4 operator/(Float32x4 other);
    virtual Int32x4 lessThan(Float32x4 other);
    virtual Int32x4 lessThanOrEqual(Float32x4 other);
    virtual Int32x4 greaterThan(Float32x4 other);
    virtual Int32x4 greaterThanOrEqual(Float32x4 other);
    virtual Int32x4 equal(Float32x4 other);
    virtual Int32x4 notEqual(Float32x4 other);
    virtual Float32x4 scale(double s);
    virtual Float32x4 abs();
    virtual Float32x4 clamp(Float32x4 lowerLimit, Float32x4 upperLimit);
    virtual double x();
    virtual double y();
    virtual double z();
    virtual double w();
    virtual int signMask();
    virtual Float32x4 shuffle(int mask);
    virtual Float32x4 shuffleMix(Float32x4 other, int mask);
    virtual Float32x4 withX(double x);
    virtual Float32x4 withY(double y);
    virtual Float32x4 withZ(double z);
    virtual Float32x4 withW(double w);
    virtual Float32x4 min(Float32x4 other);
    virtual Float32x4 max(Float32x4 other);
    virtual Float32x4 sqrt();
    virtual Float32x4 reciprocal();
    virtual Float32x4 reciprocalSqrt();
private:

};
using Float32x4 = std::shared_ptr<Float32x4Cls>;

class Int32x4Cls : public ObjectCls {
public:
    static int xxxx;

    static int xxxy;

    static int xxxz;

    static int xxxw;

    static int xxyx;

    static int xxyy;

    static int xxyz;

    static int xxyw;

    static int xxzx;

    static int xxzy;

    static int xxzz;

    static int xxzw;

    static int xxwx;

    static int xxwy;

    static int xxwz;

    static int xxww;

    static int xyxx;

    static int xyxy;

    static int xyxz;

    static int xyxw;

    static int xyyx;

    static int xyyy;

    static int xyyz;

    static int xyyw;

    static int xyzx;

    static int xyzy;

    static int xyzz;

    static int xyzw;

    static int xywx;

    static int xywy;

    static int xywz;

    static int xyww;

    static int xzxx;

    static int xzxy;

    static int xzxz;

    static int xzxw;

    static int xzyx;

    static int xzyy;

    static int xzyz;

    static int xzyw;

    static int xzzx;

    static int xzzy;

    static int xzzz;

    static int xzzw;

    static int xzwx;

    static int xzwy;

    static int xzwz;

    static int xzww;

    static int xwxx;

    static int xwxy;

    static int xwxz;

    static int xwxw;

    static int xwyx;

    static int xwyy;

    static int xwyz;

    static int xwyw;

    static int xwzx;

    static int xwzy;

    static int xwzz;

    static int xwzw;

    static int xwwx;

    static int xwwy;

    static int xwwz;

    static int xwww;

    static int yxxx;

    static int yxxy;

    static int yxxz;

    static int yxxw;

    static int yxyx;

    static int yxyy;

    static int yxyz;

    static int yxyw;

    static int yxzx;

    static int yxzy;

    static int yxzz;

    static int yxzw;

    static int yxwx;

    static int yxwy;

    static int yxwz;

    static int yxww;

    static int yyxx;

    static int yyxy;

    static int yyxz;

    static int yyxw;

    static int yyyx;

    static int yyyy;

    static int yyyz;

    static int yyyw;

    static int yyzx;

    static int yyzy;

    static int yyzz;

    static int yyzw;

    static int yywx;

    static int yywy;

    static int yywz;

    static int yyww;

    static int yzxx;

    static int yzxy;

    static int yzxz;

    static int yzxw;

    static int yzyx;

    static int yzyy;

    static int yzyz;

    static int yzyw;

    static int yzzx;

    static int yzzy;

    static int yzzz;

    static int yzzw;

    static int yzwx;

    static int yzwy;

    static int yzwz;

    static int yzww;

    static int ywxx;

    static int ywxy;

    static int ywxz;

    static int ywxw;

    static int ywyx;

    static int ywyy;

    static int ywyz;

    static int ywyw;

    static int ywzx;

    static int ywzy;

    static int ywzz;

    static int ywzw;

    static int ywwx;

    static int ywwy;

    static int ywwz;

    static int ywww;

    static int zxxx;

    static int zxxy;

    static int zxxz;

    static int zxxw;

    static int zxyx;

    static int zxyy;

    static int zxyz;

    static int zxyw;

    static int zxzx;

    static int zxzy;

    static int zxzz;

    static int zxzw;

    static int zxwx;

    static int zxwy;

    static int zxwz;

    static int zxww;

    static int zyxx;

    static int zyxy;

    static int zyxz;

    static int zyxw;

    static int zyyx;

    static int zyyy;

    static int zyyz;

    static int zyyw;

    static int zyzx;

    static int zyzy;

    static int zyzz;

    static int zyzw;

    static int zywx;

    static int zywy;

    static int zywz;

    static int zyww;

    static int zzxx;

    static int zzxy;

    static int zzxz;

    static int zzxw;

    static int zzyx;

    static int zzyy;

    static int zzyz;

    static int zzyw;

    static int zzzx;

    static int zzzy;

    static int zzzz;

    static int zzzw;

    static int zzwx;

    static int zzwy;

    static int zzwz;

    static int zzww;

    static int zwxx;

    static int zwxy;

    static int zwxz;

    static int zwxw;

    static int zwyx;

    static int zwyy;

    static int zwyz;

    static int zwyw;

    static int zwzx;

    static int zwzy;

    static int zwzz;

    static int zwzw;

    static int zwwx;

    static int zwwy;

    static int zwwz;

    static int zwww;

    static int wxxx;

    static int wxxy;

    static int wxxz;

    static int wxxw;

    static int wxyx;

    static int wxyy;

    static int wxyz;

    static int wxyw;

    static int wxzx;

    static int wxzy;

    static int wxzz;

    static int wxzw;

    static int wxwx;

    static int wxwy;

    static int wxwz;

    static int wxww;

    static int wyxx;

    static int wyxy;

    static int wyxz;

    static int wyxw;

    static int wyyx;

    static int wyyy;

    static int wyyz;

    static int wyyw;

    static int wyzx;

    static int wyzy;

    static int wyzz;

    static int wyzw;

    static int wywx;

    static int wywy;

    static int wywz;

    static int wyww;

    static int wzxx;

    static int wzxy;

    static int wzxz;

    static int wzxw;

    static int wzyx;

    static int wzyy;

    static int wzyz;

    static int wzyw;

    static int wzzx;

    static int wzzy;

    static int wzzz;

    static int wzzw;

    static int wzwx;

    static int wzwy;

    static int wzwz;

    static int wzww;

    static int wwxx;

    static int wwxy;

    static int wwxz;

    static int wwxw;

    static int wwyx;

    static int wwyy;

    static int wwyz;

    static int wwyw;

    static int wwzx;

    static int wwzy;

    static int wwzz;

    static int wwzw;

    static int wwwx;

    static int wwwy;

    static int wwwz;

    static int wwww;


     Int32x4Cls(int x, int y, int z, int w);
    void  boolValue(bool x, bool y, bool z, bool w);
    void  fromFloat32x4Bits(Float32x4 x);
    virtual Int32x4 operator|(Int32x4 other);
    virtual Int32x4 operator&(Int32x4 other);
    virtual Int32x4 operator^(Int32x4 other);
    virtual Int32x4 operator+(Int32x4 other);
    virtual Int32x4 operator-(Int32x4 other);
    virtual int x();
    virtual int y();
    virtual int z();
    virtual int w();
    virtual int signMask();
    virtual Int32x4 shuffle(int mask);
    virtual Int32x4 shuffleMix(Int32x4 other, int mask);
    virtual Int32x4 withX(int x);
    virtual Int32x4 withY(int y);
    virtual Int32x4 withZ(int z);
    virtual Int32x4 withW(int w);
    virtual bool flagX();
    virtual bool flagY();
    virtual bool flagZ();
    virtual bool flagW();
    virtual Int32x4 withFlagX(bool x);
    virtual Int32x4 withFlagY(bool y);
    virtual Int32x4 withFlagZ(bool z);
    virtual Int32x4 withFlagW(bool w);
    virtual Float32x4 select(Float32x4 trueValue, Float32x4 falseValue);
private:

};
using Int32x4 = std::shared_ptr<Int32x4Cls>;

class Float64x2Cls : public ObjectCls {
public:

     Float64x2Cls(double x, double y);
    void  splat(double v);
    void  zero();
    void  fromFloat32x4(Float32x4 v);
    virtual Float64x2 operator+(Float64x2 other);
    virtual Float64x2 operator-();
    virtual Float64x2 operator-(Float64x2 other);
    virtual Float64x2 operator*(Float64x2 other);
    virtual Float64x2 operator/(Float64x2 other);
    virtual Float64x2 scale(double s);
    virtual Float64x2 abs();
    virtual Float64x2 clamp(Float64x2 lowerLimit, Float64x2 upperLimit);
    virtual double x();
    virtual double y();
    virtual int signMask();
    virtual Float64x2 withX(double x);
    virtual Float64x2 withY(double y);
    virtual Float64x2 min(Float64x2 other);
    virtual Float64x2 max(Float64x2 other);
    virtual Float64x2 sqrt();
private:

};
using Float64x2 = std::shared_ptr<Float64x2Cls>;

// Parts
#include "unmodifiable_typed_data.hpp"

#endif