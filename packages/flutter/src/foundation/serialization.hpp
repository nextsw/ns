#ifndef SERIALIZATION_H
#define SERIALIZATION_H
#include <memory>
#include <typed_data.hpp>

#include <math/math.hpp>
#include <typed_data/typed_data.hpp>



class WriteBuffer {
public:

     WriteBuffer(int startCapacity);

    void putUint8(int byte);

    void putUint16(Endian endian, int value);

    void putUint32(Endian endian, int value);

    void putInt32(Endian endian, int value);

    void putInt64(Endian endian, int value);

    void putFloat64(Endian endian, double value);

    void putUint8List(Uint8List list);

    void putInt32List(Int32List list);

    void putInt64List(Int64List list);

    void putFloat32List(Float32List list);

    void putFloat64List(Float64List list);

    ByteData done();

private:
    Uint8List _buffer;

    int _currentSize;

    bool _isDone;

    ByteData _eightBytes;

    Uint8List _eightBytesAsList;

    static Uint8List _zeroBuffer;


    void  _(Uint8List _buffer, ByteData _eightBytes, Uint8List _eightBytesAsList);

    void _add(int byte);

    void _append(Uint8List other);

    void _addAll(Uint8List data, int end, int start);

    void _resize(int requiredLength);

    void _alignTo(int alignment);

};

class ReadBuffer {
public:
    ByteData data;


     ReadBuffer(ByteData data);

    bool hasRemaining();

    int getUint8();

    int getUint16(Endian endian);

    int getUint32(Endian endian);

    int getInt32(Endian endian);

    int getInt64(Endian endian);

    double getFloat64(Endian endian);

    Uint8List getUint8List(int length);

    Int32List getInt32List(int length);

    Int64List getInt64List(int length);

    Float32List getFloat32List(int length);

    Float64List getFloat64List(int length);

private:
    int _position;


    void _alignTo(int alignment);

};

#endif