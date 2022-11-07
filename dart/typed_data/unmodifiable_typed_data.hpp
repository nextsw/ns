#ifndef UNMODIFIABLE_TYPED_DATA_H
#define UNMODIFIABLE_TYPED_DATA_H
#include <memory>




class UnmodifiableByteBufferView {
public:

     UnmodifiableByteBufferView(ByteBuffer data);

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
    ByteBuffer _data;


};

class UnmodifiableByteDataView {
public:

     UnmodifiableByteDataView(ByteData data);

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

    int elementSizeInBytes();

    int offsetInBytes();

    int lengthInBytes();

    ByteBuffer buffer();

private:
    ByteData _data;


    void _unsupported();

};

class _UnmodifiableListMixin<N, L extends List<N>, TD extends TypedData> {
public:

    int length();

    N [](int index);

    int elementSizeInBytes();

    int offsetInBytes();

    int lengthInBytes();

    ByteBuffer buffer();

    L sublist(int end, int start);

private:

    L _list();

    TD _data();

    L _createList(int length);

};

class UnmodifiableUint8ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableUint8ListView(Uint8List list);

private:
    Uint8List _list;


    Uint8List _createList(int length);

};

class UnmodifiableInt8ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableInt8ListView(Int8List list);

private:
    Int8List _list;


    Int8List _createList(int length);

};

class UnmodifiableUint8ClampedListView : UnmodifiableListBase<int> {
public:

     UnmodifiableUint8ClampedListView(Uint8ClampedList list);

private:
    Uint8ClampedList _list;


    Uint8ClampedList _createList(int length);

};

class UnmodifiableUint16ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableUint16ListView(Uint16List list);

private:
    Uint16List _list;


    Uint16List _createList(int length);

};

class UnmodifiableInt16ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableInt16ListView(Int16List list);

private:
    Int16List _list;


    Int16List _createList(int length);

};

class UnmodifiableUint32ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableUint32ListView(Uint32List list);

private:
    Uint32List _list;


    Uint32List _createList(int length);

};

class UnmodifiableInt32ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableInt32ListView(Int32List list);

private:
    Int32List _list;


    Int32List _createList(int length);

};

class UnmodifiableUint64ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableUint64ListView(Uint64List list);

private:
    Uint64List _list;


    Uint64List _createList(int length);

};

class UnmodifiableInt64ListView : UnmodifiableListBase<int> {
public:

     UnmodifiableInt64ListView(Int64List list);

private:
    Int64List _list;


    Int64List _createList(int length);

};

class UnmodifiableInt32x4ListView : UnmodifiableListBase<Int32x4> {
public:

     UnmodifiableInt32x4ListView(Int32x4List list);

private:
    Int32x4List _list;


    Int32x4List _createList(int length);

};

class UnmodifiableFloat32x4ListView : UnmodifiableListBase<Float32x4> {
public:

     UnmodifiableFloat32x4ListView(Float32x4List list);

private:
    Float32x4List _list;


    Float32x4List _createList(int length);

};

class UnmodifiableFloat64x2ListView : UnmodifiableListBase<Float64x2> {
public:

     UnmodifiableFloat64x2ListView(Float64x2List list);

private:
    Float64x2List _list;


    Float64x2List _createList(int length);

};

class UnmodifiableFloat32ListView : UnmodifiableListBase<double> {
public:

     UnmodifiableFloat32ListView(Float32List list);

private:
    Float32List _list;


    Float32List _createList(int length);

};

class UnmodifiableFloat64ListView : UnmodifiableListBase<double> {
public:

     UnmodifiableFloat64ListView(Float64List list);

private:
    Float64List _list;


    Float64List _createList(int length);

};

#endif