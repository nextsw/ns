#ifndef DART_TYPED_DATA_UNMODIFIABLE_TYPED_DATA
#define DART_TYPED_DATA_UNMODIFIABLE_TYPED_DATA
#include <base.hpp>

#include <dart/core/core.hpp>


class UnmodifiableByteBufferViewCls : public ObjectCls {
public:

     UnmodifiableByteBufferViewCls(ByteBuffer data);

    virtual int lengthInBytes();

    virtual Uint8List asUint8List(int length, int offsetInBytes);

    virtual Int8List asInt8List(int length, int offsetInBytes);

    virtual Uint8ClampedList asUint8ClampedList(int length, int offsetInBytes);

    virtual Uint16List asUint16List(int length, int offsetInBytes);

    virtual Int16List asInt16List(int length, int offsetInBytes);

    virtual Uint32List asUint32List(int length, int offsetInBytes);

    virtual Int32List asInt32List(int length, int offsetInBytes);

    virtual Uint64List asUint64List(int length, int offsetInBytes);

    virtual Int64List asInt64List(int length, int offsetInBytes);

    virtual Int32x4List asInt32x4List(int length, int offsetInBytes);

    virtual Float32List asFloat32List(int length, int offsetInBytes);

    virtual Float64List asFloat64List(int length, int offsetInBytes);

    virtual Float32x4List asFloat32x4List(int length, int offsetInBytes);

    virtual Float64x2List asFloat64x2List(int length, int offsetInBytes);

    virtual ByteData asByteData(int length, int offsetInBytes);

private:
    ByteBuffer _data;


};
using UnmodifiableByteBufferView = std::shared_ptr<UnmodifiableByteBufferViewCls>;

class UnmodifiableByteDataViewCls : public ObjectCls {
public:

     UnmodifiableByteDataViewCls(ByteData data);

    virtual int getInt8(int byteOffset);

    virtual void setInt8(int byteOffset, int value);

    virtual int getUint8(int byteOffset);

    virtual void setUint8(int byteOffset, int value);

    virtual int getInt16(int byteOffset, Endian endian);

    virtual void setInt16(int byteOffset, Endian endian, int value);

    virtual int getUint16(int byteOffset, Endian endian);

    virtual void setUint16(int byteOffset, Endian endian, int value);

    virtual int getInt32(int byteOffset, Endian endian);

    virtual void setInt32(int byteOffset, Endian endian, int value);

    virtual int getUint32(int byteOffset, Endian endian);

    virtual void setUint32(int byteOffset, Endian endian, int value);

    virtual int getInt64(int byteOffset, Endian endian);

    virtual void setInt64(int byteOffset, Endian endian, int value);

    virtual int getUint64(int byteOffset, Endian endian);

    virtual void setUint64(int byteOffset, Endian endian, int value);

    virtual double getFloat32(int byteOffset, Endian endian);

    virtual void setFloat32(int byteOffset, Endian endian, double value);

    virtual double getFloat64(int byteOffset, Endian endian);

    virtual void setFloat64(int byteOffset, Endian endian, double value);

    virtual int elementSizeInBytes();

    virtual int offsetInBytes();

    virtual int lengthInBytes();

    virtual ByteBuffer buffer();

private:
    ByteData _data;


    virtual void _unsupported();

};
using UnmodifiableByteDataView = std::shared_ptr<UnmodifiableByteDataViewCls>;

template<typename N, typename L : List<N>, typename TD : TypedData> class _UnmodifiableListMixinCls : public ObjectCls {
public:

    virtual int length();

    virtual N operator[](int index);

    virtual int elementSizeInBytes();

    virtual int offsetInBytes();

    virtual int lengthInBytes();

    virtual ByteBuffer buffer();

    virtual L sublist(int end, int start);

private:

    virtual L _list();
    virtual TD _data();

    virtual L _createList(int length);
};
template<typename N, typename L : List<N>, typename TD : TypedData> using _UnmodifiableListMixin = std::shared_ptr<_UnmodifiableListMixinCls<N, L : List<N>, TD : TypedData>>;

class UnmodifiableUint8ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableUint8ListViewCls(Uint8List list);

private:
    Uint8List _list;


    virtual Uint8List _createList(int length);

};
using UnmodifiableUint8ListView = std::shared_ptr<UnmodifiableUint8ListViewCls>;

class UnmodifiableInt8ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableInt8ListViewCls(Int8List list);

private:
    Int8List _list;


    virtual Int8List _createList(int length);

};
using UnmodifiableInt8ListView = std::shared_ptr<UnmodifiableInt8ListViewCls>;

class UnmodifiableUint8ClampedListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableUint8ClampedListViewCls(Uint8ClampedList list);

private:
    Uint8ClampedList _list;


    virtual Uint8ClampedList _createList(int length);

};
using UnmodifiableUint8ClampedListView = std::shared_ptr<UnmodifiableUint8ClampedListViewCls>;

class UnmodifiableUint16ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableUint16ListViewCls(Uint16List list);

private:
    Uint16List _list;


    virtual Uint16List _createList(int length);

};
using UnmodifiableUint16ListView = std::shared_ptr<UnmodifiableUint16ListViewCls>;

class UnmodifiableInt16ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableInt16ListViewCls(Int16List list);

private:
    Int16List _list;


    virtual Int16List _createList(int length);

};
using UnmodifiableInt16ListView = std::shared_ptr<UnmodifiableInt16ListViewCls>;

class UnmodifiableUint32ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableUint32ListViewCls(Uint32List list);

private:
    Uint32List _list;


    virtual Uint32List _createList(int length);

};
using UnmodifiableUint32ListView = std::shared_ptr<UnmodifiableUint32ListViewCls>;

class UnmodifiableInt32ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableInt32ListViewCls(Int32List list);

private:
    Int32List _list;


    virtual Int32List _createList(int length);

};
using UnmodifiableInt32ListView = std::shared_ptr<UnmodifiableInt32ListViewCls>;

class UnmodifiableUint64ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableUint64ListViewCls(Uint64List list);

private:
    Uint64List _list;


    virtual Uint64List _createList(int length);

};
using UnmodifiableUint64ListView = std::shared_ptr<UnmodifiableUint64ListViewCls>;

class UnmodifiableInt64ListViewCls : public UnmodifiableListBaseCls<int> {
public:

     UnmodifiableInt64ListViewCls(Int64List list);

private:
    Int64List _list;


    virtual Int64List _createList(int length);

};
using UnmodifiableInt64ListView = std::shared_ptr<UnmodifiableInt64ListViewCls>;

class UnmodifiableInt32x4ListViewCls : public UnmodifiableListBaseCls<Int32x4> {
public:

     UnmodifiableInt32x4ListViewCls(Int32x4List list);

private:
    Int32x4List _list;


    virtual Int32x4List _createList(int length);

};
using UnmodifiableInt32x4ListView = std::shared_ptr<UnmodifiableInt32x4ListViewCls>;

class UnmodifiableFloat32x4ListViewCls : public UnmodifiableListBaseCls<Float32x4> {
public:

     UnmodifiableFloat32x4ListViewCls(Float32x4List list);

private:
    Float32x4List _list;


    virtual Float32x4List _createList(int length);

};
using UnmodifiableFloat32x4ListView = std::shared_ptr<UnmodifiableFloat32x4ListViewCls>;

class UnmodifiableFloat64x2ListViewCls : public UnmodifiableListBaseCls<Float64x2> {
public:

     UnmodifiableFloat64x2ListViewCls(Float64x2List list);

private:
    Float64x2List _list;


    virtual Float64x2List _createList(int length);

};
using UnmodifiableFloat64x2ListView = std::shared_ptr<UnmodifiableFloat64x2ListViewCls>;

class UnmodifiableFloat32ListViewCls : public UnmodifiableListBaseCls<double> {
public:

     UnmodifiableFloat32ListViewCls(Float32List list);

private:
    Float32List _list;


    virtual Float32List _createList(int length);

};
using UnmodifiableFloat32ListView = std::shared_ptr<UnmodifiableFloat32ListViewCls>;

class UnmodifiableFloat64ListViewCls : public UnmodifiableListBaseCls<double> {
public:

     UnmodifiableFloat64ListViewCls(Float64List list);

private:
    Float64List _list;


    virtual Float64List _createList(int length);

};
using UnmodifiableFloat64ListView = std::shared_ptr<UnmodifiableFloat64ListViewCls>;


#endif