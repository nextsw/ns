#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_SERIALIZATION
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_SERIALIZATION
#include <base.hpp>
#include <dart/typed_data/typed_data.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/typed_data/typed_data.hpp>


class WriteBufferCls : public ObjectCls {
public:

     WriteBufferCls(int startCapacity);

    virtual void putUint8(int byte);

    virtual void putUint16(int value, Endian endian);

    virtual void putUint32(int value, Endian endian);

    virtual void putInt32(int value, Endian endian);

    virtual void putInt64(int value, Endian endian);

    virtual void putFloat64(double value, Endian endian);

    virtual void putUint8List(Uint8List list);

    virtual void putInt32List(Int32List list);

    virtual void putInt64List(Int64List list);

    virtual void putFloat32List(Float32List list);

    virtual void putFloat64List(Float64List list);

    virtual ByteData done();

private:
    Uint8List _buffer;

    int _currentSize;

    bool _isDone;

    ByteData _eightBytes;

    Uint8List _eightBytesAsList;

    static Uint8List _zeroBuffer;


    virtual void  _(Uint8List _buffer, ByteData _eightBytes, Uint8List _eightBytesAsList);
    virtual void _add(int byte);

    virtual void _append(Uint8List other);

    virtual void _addAll(Uint8List data, int start, int end);

    virtual void _resize(int requiredLength);

    virtual void _alignTo(int alignment);

};
using WriteBuffer = std::shared_ptr<WriteBufferCls>;

class ReadBufferCls : public ObjectCls {
public:
    ByteData data;


     ReadBufferCls(ByteData data);

    virtual bool hasRemaining();

    virtual int getUint8();

    virtual int getUint16(Endian endian);

    virtual int getUint32(Endian endian);

    virtual int getInt32(Endian endian);

    virtual int getInt64(Endian endian);

    virtual double getFloat64(Endian endian);

    virtual Uint8List getUint8List(int length);

    virtual Int32List getInt32List(int length);

    virtual Int64List getInt64List(int length);

    virtual Float32List getFloat32List(int length);

    virtual Float64List getFloat64List(int length);

private:
    int _position;


    virtual void _alignTo(int alignment);

};
using ReadBuffer = std::shared_ptr<ReadBufferCls>;


#endif