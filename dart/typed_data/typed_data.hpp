#ifndef TYPED_DATA_H
#define TYPED_DATA_H
#include <memory>
#include <_internal.hpp>

#include <internal/internal.hpp>

// Parts
#include "unmodifiable_typed_data.hpp"


class ByteBuffer {
public:

    int lengthInBytes();

    Uint8List asUint8List(int length, int offsetInBytes);

    Int8List asInt8List(int length, int offsetInBytes);

    Uint8ClampedList asUint8ClampedList(int length, int offsetInBytes);

    Uint16List asUint16List(int length, int offsetInBytes);

    Int16List asInt16List(int length, int offsetInBytes);

    Uint32List asUint32List(int length, int offsetInBytes);

    Int32List asInt32List(int length, int offsetInBytes);

    Uint64List asUint64List(int length, int offsetInBytes);

    Int64List asInt64List(int length, int offsetInBytes);

    Int32x4List asInt32x4List(int length, int offsetInBytes);

    Float32List asFloat32List(int length, int offsetInBytes);

    Float64List asFloat64List(int length, int offsetInBytes);

    Float32x4List asFloat32x4List(int length, int offsetInBytes);

    Float64x2List asFloat64x2List(int length, int offsetInBytes);

    ByteData asByteData(int length, int offsetInBytes);

private:

};

class TypedData {
public:

    int elementSizeInBytes();

    int offsetInBytes();

    int lengthInBytes();

    ByteBuffer buffer();

private:

};

class _TypedIntList : TypedData {
public:

    List<int> +(List<int> other);

private:

};

class _TypedFloatList : TypedData {
public:

    List<double> +(List<double> other);

private:

};

class Endian {
public:
    static const Endian big;

    static const Endian little;

    static Endian host;


private:
    bool _littleEndian;


    void  _(bool _littleEndian);

};

class ByteData {
public:

    external  ByteData(int length);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    int getInt8(int byteOffset);

    void setInt8(int byteOffset, int value);

    int getUint8(int byteOffset);

    void setUint8(int byteOffset, int value);

    int getInt16(int byteOffset, Endian endian);

    void setInt16(int byteOffset, Endian endian, int value);

    int getUint16(int byteOffset, Endian endian);

    void setUint16(int byteOffset, Endian endian, int value);

    int getInt32(int byteOffset, Endian endian);

    void setInt32(int byteOffset, Endian endian, int value);

    int getUint32(int byteOffset, Endian endian);

    void setUint32(int byteOffset, Endian endian, int value);

    int getInt64(int byteOffset, Endian endian);

    void setInt64(int byteOffset, Endian endian, int value);

    int getUint64(int byteOffset, Endian endian);

    void setUint64(int byteOffset, Endian endian, int value);

    double getFloat32(int byteOffset, Endian endian);

    void setFloat32(int byteOffset, Endian endian, double value);

    double getFloat64(int byteOffset, Endian endian);

    void setFloat64(int byteOffset, Endian endian, double value);

private:

};

class Int8List {
public:
    static const int bytesPerElement;


    external  Int8List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Int8List sublist(int end, int start);

private:

};

class Uint8List {
public:
    static const int bytesPerElement;


    external  Uint8List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    List<int> +(List<int> other);

    Uint8List sublist(int end, int start);

private:

};

class Uint8ClampedList {
public:
    static const int bytesPerElement;


    external  Uint8ClampedList(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Uint8ClampedList sublist(int end, int start);

private:

};

class Int16List {
public:
    static const int bytesPerElement;


    external  Int16List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Int16List sublist(int end, int start);

private:

};

class Uint16List {
public:
    static const int bytesPerElement;


    external  Uint16List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Uint16List sublist(int end, int start);

private:

};

class Int32List {
public:
    static const int bytesPerElement;


    external  Int32List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Int32List sublist(int end, int start);

private:

};

class Uint32List {
public:
    static const int bytesPerElement;


    external  Uint32List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Uint32List sublist(int end, int start);

private:

};

class Int64List {
public:
    static const int bytesPerElement;


    external  Int64List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Int64List sublist(int end, int start);

private:

};

class Uint64List {
public:
    static const int bytesPerElement;


    external  Uint64List(int length);

    external void  fromList(List<int> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Uint64List sublist(int end, int start);

private:

};

class Float32List {
public:
    static const int bytesPerElement;


    external  Float32List(int length);

    external void  fromList(List<double> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Float32List sublist(int end, int start);

private:

};

class Float64List {
public:
    static const int bytesPerElement;


    external  Float64List(int length);

    external void  fromList(List<double> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Float64List sublist(int end, int start);

private:

};

class Float32x4List {
public:
    static const int bytesPerElement;


    external  Float32x4List(int length);

    external void  fromList(List<Float32x4> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    List<Float32x4> +(List<Float32x4> other);

    Float32x4List sublist(int end, int start);

private:

};

class Int32x4List {
public:
    static const int bytesPerElement;


    external  Int32x4List(int length);

    external void  fromList(List<Int32x4> elements);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    List<Int32x4> +(List<Int32x4> other);

    Int32x4List sublist(int end, int start);

private:

};

class Float64x2List {
public:
    static const int bytesPerElement;


    external  Float64x2List(int length);

    external void  fromList(List<Float64x2> elements);

    List<Float64x2> +(List<Float64x2> other);

    void  view(ByteBuffer buffer, int length, int offsetInBytes);

    void  sublistView(TypedData data, int end, int start);

    Float64x2List sublist(int end, int start);

private:

};

class Float32x4 {
public:
    static const int xxxx;

    static const int xxxy;

    static const int xxxz;

    static const int xxxw;

    static const int xxyx;

    static const int xxyy;

    static const int xxyz;

    static const int xxyw;

    static const int xxzx;

    static const int xxzy;

    static const int xxzz;

    static const int xxzw;

    static const int xxwx;

    static const int xxwy;

    static const int xxwz;

    static const int xxww;

    static const int xyxx;

    static const int xyxy;

    static const int xyxz;

    static const int xyxw;

    static const int xyyx;

    static const int xyyy;

    static const int xyyz;

    static const int xyyw;

    static const int xyzx;

    static const int xyzy;

    static const int xyzz;

    static const int xyzw;

    static const int xywx;

    static const int xywy;

    static const int xywz;

    static const int xyww;

    static const int xzxx;

    static const int xzxy;

    static const int xzxz;

    static const int xzxw;

    static const int xzyx;

    static const int xzyy;

    static const int xzyz;

    static const int xzyw;

    static const int xzzx;

    static const int xzzy;

    static const int xzzz;

    static const int xzzw;

    static const int xzwx;

    static const int xzwy;

    static const int xzwz;

    static const int xzww;

    static const int xwxx;

    static const int xwxy;

    static const int xwxz;

    static const int xwxw;

    static const int xwyx;

    static const int xwyy;

    static const int xwyz;

    static const int xwyw;

    static const int xwzx;

    static const int xwzy;

    static const int xwzz;

    static const int xwzw;

    static const int xwwx;

    static const int xwwy;

    static const int xwwz;

    static const int xwww;

    static const int yxxx;

    static const int yxxy;

    static const int yxxz;

    static const int yxxw;

    static const int yxyx;

    static const int yxyy;

    static const int yxyz;

    static const int yxyw;

    static const int yxzx;

    static const int yxzy;

    static const int yxzz;

    static const int yxzw;

    static const int yxwx;

    static const int yxwy;

    static const int yxwz;

    static const int yxww;

    static const int yyxx;

    static const int yyxy;

    static const int yyxz;

    static const int yyxw;

    static const int yyyx;

    static const int yyyy;

    static const int yyyz;

    static const int yyyw;

    static const int yyzx;

    static const int yyzy;

    static const int yyzz;

    static const int yyzw;

    static const int yywx;

    static const int yywy;

    static const int yywz;

    static const int yyww;

    static const int yzxx;

    static const int yzxy;

    static const int yzxz;

    static const int yzxw;

    static const int yzyx;

    static const int yzyy;

    static const int yzyz;

    static const int yzyw;

    static const int yzzx;

    static const int yzzy;

    static const int yzzz;

    static const int yzzw;

    static const int yzwx;

    static const int yzwy;

    static const int yzwz;

    static const int yzww;

    static const int ywxx;

    static const int ywxy;

    static const int ywxz;

    static const int ywxw;

    static const int ywyx;

    static const int ywyy;

    static const int ywyz;

    static const int ywyw;

    static const int ywzx;

    static const int ywzy;

    static const int ywzz;

    static const int ywzw;

    static const int ywwx;

    static const int ywwy;

    static const int ywwz;

    static const int ywww;

    static const int zxxx;

    static const int zxxy;

    static const int zxxz;

    static const int zxxw;

    static const int zxyx;

    static const int zxyy;

    static const int zxyz;

    static const int zxyw;

    static const int zxzx;

    static const int zxzy;

    static const int zxzz;

    static const int zxzw;

    static const int zxwx;

    static const int zxwy;

    static const int zxwz;

    static const int zxww;

    static const int zyxx;

    static const int zyxy;

    static const int zyxz;

    static const int zyxw;

    static const int zyyx;

    static const int zyyy;

    static const int zyyz;

    static const int zyyw;

    static const int zyzx;

    static const int zyzy;

    static const int zyzz;

    static const int zyzw;

    static const int zywx;

    static const int zywy;

    static const int zywz;

    static const int zyww;

    static const int zzxx;

    static const int zzxy;

    static const int zzxz;

    static const int zzxw;

    static const int zzyx;

    static const int zzyy;

    static const int zzyz;

    static const int zzyw;

    static const int zzzx;

    static const int zzzy;

    static const int zzzz;

    static const int zzzw;

    static const int zzwx;

    static const int zzwy;

    static const int zzwz;

    static const int zzww;

    static const int zwxx;

    static const int zwxy;

    static const int zwxz;

    static const int zwxw;

    static const int zwyx;

    static const int zwyy;

    static const int zwyz;

    static const int zwyw;

    static const int zwzx;

    static const int zwzy;

    static const int zwzz;

    static const int zwzw;

    static const int zwwx;

    static const int zwwy;

    static const int zwwz;

    static const int zwww;

    static const int wxxx;

    static const int wxxy;

    static const int wxxz;

    static const int wxxw;

    static const int wxyx;

    static const int wxyy;

    static const int wxyz;

    static const int wxyw;

    static const int wxzx;

    static const int wxzy;

    static const int wxzz;

    static const int wxzw;

    static const int wxwx;

    static const int wxwy;

    static const int wxwz;

    static const int wxww;

    static const int wyxx;

    static const int wyxy;

    static const int wyxz;

    static const int wyxw;

    static const int wyyx;

    static const int wyyy;

    static const int wyyz;

    static const int wyyw;

    static const int wyzx;

    static const int wyzy;

    static const int wyzz;

    static const int wyzw;

    static const int wywx;

    static const int wywy;

    static const int wywz;

    static const int wyww;

    static const int wzxx;

    static const int wzxy;

    static const int wzxz;

    static const int wzxw;

    static const int wzyx;

    static const int wzyy;

    static const int wzyz;

    static const int wzyw;

    static const int wzzx;

    static const int wzzy;

    static const int wzzz;

    static const int wzzw;

    static const int wzwx;

    static const int wzwy;

    static const int wzwz;

    static const int wzww;

    static const int wwxx;

    static const int wwxy;

    static const int wwxz;

    static const int wwxw;

    static const int wwyx;

    static const int wwyy;

    static const int wwyz;

    static const int wwyw;

    static const int wwzx;

    static const int wwzy;

    static const int wwzz;

    static const int wwzw;

    static const int wwwx;

    static const int wwwy;

    static const int wwwz;

    static const int wwww;


    external  Float32x4(double w, double x, double y, double z);

    external void  splat(double v);

    external void  zero();

    external void  fromInt32x4Bits(Int32x4 x);

    external void  fromFloat64x2(Float64x2 v);

    Float32x4 +(Float32x4 other);

    Float32x4 -();

    Float32x4 -(Float32x4 other);

    Float32x4 *(Float32x4 other);

    Float32x4 /(Float32x4 other);

    Int32x4 lessThan(Float32x4 other);

    Int32x4 lessThanOrEqual(Float32x4 other);

    Int32x4 greaterThan(Float32x4 other);

    Int32x4 greaterThanOrEqual(Float32x4 other);

    Int32x4 equal(Float32x4 other);

    Int32x4 notEqual(Float32x4 other);

    Float32x4 scale(double s);

    Float32x4 abs();

    Float32x4 clamp(Float32x4 lowerLimit, Float32x4 upperLimit);

    double x();

    double y();

    double z();

    double w();

    int signMask();

    Float32x4 shuffle(int mask);

    Float32x4 shuffleMix(int mask, Float32x4 other);

    Float32x4 withX(double x);

    Float32x4 withY(double y);

    Float32x4 withZ(double z);

    Float32x4 withW(double w);

    Float32x4 min(Float32x4 other);

    Float32x4 max(Float32x4 other);

    Float32x4 sqrt();

    Float32x4 reciprocal();

    Float32x4 reciprocalSqrt();

private:

};

class Int32x4 {
public:
    static const int xxxx;

    static const int xxxy;

    static const int xxxz;

    static const int xxxw;

    static const int xxyx;

    static const int xxyy;

    static const int xxyz;

    static const int xxyw;

    static const int xxzx;

    static const int xxzy;

    static const int xxzz;

    static const int xxzw;

    static const int xxwx;

    static const int xxwy;

    static const int xxwz;

    static const int xxww;

    static const int xyxx;

    static const int xyxy;

    static const int xyxz;

    static const int xyxw;

    static const int xyyx;

    static const int xyyy;

    static const int xyyz;

    static const int xyyw;

    static const int xyzx;

    static const int xyzy;

    static const int xyzz;

    static const int xyzw;

    static const int xywx;

    static const int xywy;

    static const int xywz;

    static const int xyww;

    static const int xzxx;

    static const int xzxy;

    static const int xzxz;

    static const int xzxw;

    static const int xzyx;

    static const int xzyy;

    static const int xzyz;

    static const int xzyw;

    static const int xzzx;

    static const int xzzy;

    static const int xzzz;

    static const int xzzw;

    static const int xzwx;

    static const int xzwy;

    static const int xzwz;

    static const int xzww;

    static const int xwxx;

    static const int xwxy;

    static const int xwxz;

    static const int xwxw;

    static const int xwyx;

    static const int xwyy;

    static const int xwyz;

    static const int xwyw;

    static const int xwzx;

    static const int xwzy;

    static const int xwzz;

    static const int xwzw;

    static const int xwwx;

    static const int xwwy;

    static const int xwwz;

    static const int xwww;

    static const int yxxx;

    static const int yxxy;

    static const int yxxz;

    static const int yxxw;

    static const int yxyx;

    static const int yxyy;

    static const int yxyz;

    static const int yxyw;

    static const int yxzx;

    static const int yxzy;

    static const int yxzz;

    static const int yxzw;

    static const int yxwx;

    static const int yxwy;

    static const int yxwz;

    static const int yxww;

    static const int yyxx;

    static const int yyxy;

    static const int yyxz;

    static const int yyxw;

    static const int yyyx;

    static const int yyyy;

    static const int yyyz;

    static const int yyyw;

    static const int yyzx;

    static const int yyzy;

    static const int yyzz;

    static const int yyzw;

    static const int yywx;

    static const int yywy;

    static const int yywz;

    static const int yyww;

    static const int yzxx;

    static const int yzxy;

    static const int yzxz;

    static const int yzxw;

    static const int yzyx;

    static const int yzyy;

    static const int yzyz;

    static const int yzyw;

    static const int yzzx;

    static const int yzzy;

    static const int yzzz;

    static const int yzzw;

    static const int yzwx;

    static const int yzwy;

    static const int yzwz;

    static const int yzww;

    static const int ywxx;

    static const int ywxy;

    static const int ywxz;

    static const int ywxw;

    static const int ywyx;

    static const int ywyy;

    static const int ywyz;

    static const int ywyw;

    static const int ywzx;

    static const int ywzy;

    static const int ywzz;

    static const int ywzw;

    static const int ywwx;

    static const int ywwy;

    static const int ywwz;

    static const int ywww;

    static const int zxxx;

    static const int zxxy;

    static const int zxxz;

    static const int zxxw;

    static const int zxyx;

    static const int zxyy;

    static const int zxyz;

    static const int zxyw;

    static const int zxzx;

    static const int zxzy;

    static const int zxzz;

    static const int zxzw;

    static const int zxwx;

    static const int zxwy;

    static const int zxwz;

    static const int zxww;

    static const int zyxx;

    static const int zyxy;

    static const int zyxz;

    static const int zyxw;

    static const int zyyx;

    static const int zyyy;

    static const int zyyz;

    static const int zyyw;

    static const int zyzx;

    static const int zyzy;

    static const int zyzz;

    static const int zyzw;

    static const int zywx;

    static const int zywy;

    static const int zywz;

    static const int zyww;

    static const int zzxx;

    static const int zzxy;

    static const int zzxz;

    static const int zzxw;

    static const int zzyx;

    static const int zzyy;

    static const int zzyz;

    static const int zzyw;

    static const int zzzx;

    static const int zzzy;

    static const int zzzz;

    static const int zzzw;

    static const int zzwx;

    static const int zzwy;

    static const int zzwz;

    static const int zzww;

    static const int zwxx;

    static const int zwxy;

    static const int zwxz;

    static const int zwxw;

    static const int zwyx;

    static const int zwyy;

    static const int zwyz;

    static const int zwyw;

    static const int zwzx;

    static const int zwzy;

    static const int zwzz;

    static const int zwzw;

    static const int zwwx;

    static const int zwwy;

    static const int zwwz;

    static const int zwww;

    static const int wxxx;

    static const int wxxy;

    static const int wxxz;

    static const int wxxw;

    static const int wxyx;

    static const int wxyy;

    static const int wxyz;

    static const int wxyw;

    static const int wxzx;

    static const int wxzy;

    static const int wxzz;

    static const int wxzw;

    static const int wxwx;

    static const int wxwy;

    static const int wxwz;

    static const int wxww;

    static const int wyxx;

    static const int wyxy;

    static const int wyxz;

    static const int wyxw;

    static const int wyyx;

    static const int wyyy;

    static const int wyyz;

    static const int wyyw;

    static const int wyzx;

    static const int wyzy;

    static const int wyzz;

    static const int wyzw;

    static const int wywx;

    static const int wywy;

    static const int wywz;

    static const int wyww;

    static const int wzxx;

    static const int wzxy;

    static const int wzxz;

    static const int wzxw;

    static const int wzyx;

    static const int wzyy;

    static const int wzyz;

    static const int wzyw;

    static const int wzzx;

    static const int wzzy;

    static const int wzzz;

    static const int wzzw;

    static const int wzwx;

    static const int wzwy;

    static const int wzwz;

    static const int wzww;

    static const int wwxx;

    static const int wwxy;

    static const int wwxz;

    static const int wwxw;

    static const int wwyx;

    static const int wwyy;

    static const int wwyz;

    static const int wwyw;

    static const int wwzx;

    static const int wwzy;

    static const int wwzz;

    static const int wwzw;

    static const int wwwx;

    static const int wwwy;

    static const int wwwz;

    static const int wwww;


    external  Int32x4(int w, int x, int y, int z);

    external void  bool(bool w, bool x, bool y, bool z);

    external void  fromFloat32x4Bits(Float32x4 x);

    Int32x4 |(Int32x4 other);

    Int32x4 &(Int32x4 other);

    Int32x4 ^(Int32x4 other);

    Int32x4 +(Int32x4 other);

    Int32x4 -(Int32x4 other);

    int x();

    int y();

    int z();

    int w();

    int signMask();

    Int32x4 shuffle(int mask);

    Int32x4 shuffleMix(int mask, Int32x4 other);

    Int32x4 withX(int x);

    Int32x4 withY(int y);

    Int32x4 withZ(int z);

    Int32x4 withW(int w);

    bool flagX();

    bool flagY();

    bool flagZ();

    bool flagW();

    Int32x4 withFlagX(bool x);

    Int32x4 withFlagY(bool y);

    Int32x4 withFlagZ(bool z);

    Int32x4 withFlagW(bool w);

    Float32x4 select(Float32x4 falseValue, Float32x4 trueValue);

private:

};

class Float64x2 {
public:

    external  Float64x2(double x, double y);

    external void  splat(double v);

    external void  zero();

    external void  fromFloat32x4(Float32x4 v);

    Float64x2 +(Float64x2 other);

    Float64x2 -();

    Float64x2 -(Float64x2 other);

    Float64x2 *(Float64x2 other);

    Float64x2 /(Float64x2 other);

    Float64x2 scale(double s);

    Float64x2 abs();

    Float64x2 clamp(Float64x2 lowerLimit, Float64x2 upperLimit);

    double x();

    double y();

    int signMask();

    Float64x2 withX(double x);

    Float64x2 withY(double y);

    Float64x2 min(Float64x2 other);

    Float64x2 max(Float64x2 other);

    Float64x2 sqrt();

private:

};

#endif