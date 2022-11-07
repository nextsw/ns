#include "serialization.hpp"
WriteBuffer::WriteBuffer(int startCapacity) {
    {
        assert(startCapacity > 0);
        ByteData eightBytes = ByteData(8);
        Uint8List eightBytesAsList = eightBytes.buffer.asUint8List();
        return WriteBuffer._(Uint8List(startCapacity), eightBytes, eightBytesAsList);
    }
}

void WriteBuffer::putUint8(int byte) {
    assert(!_isDone);
    _add(byte);
}

void WriteBuffer::putUint16(Endian endian, int value) {
    assert(!_isDone);
    _eightBytes.setUint16(0, value, endian ?? Endian.host);
    _addAll(_eightBytesAsList, 0, 2);
}

void WriteBuffer::putUint32(Endian endian, int value) {
    assert(!_isDone);
    _eightBytes.setUint32(0, value, endian ?? Endian.host);
    _addAll(_eightBytesAsList, 0, 4);
}

void WriteBuffer::putInt32(Endian endian, int value) {
    assert(!_isDone);
    _eightBytes.setInt32(0, value, endian ?? Endian.host);
    _addAll(_eightBytesAsList, 0, 4);
}

void WriteBuffer::putInt64(Endian endian, int value) {
    assert(!_isDone);
    _eightBytes.setInt64(0, value, endian ?? Endian.host);
    _addAll(_eightBytesAsList, 0, 8);
}

void WriteBuffer::putFloat64(Endian endian, double value) {
    assert(!_isDone);
    _alignTo(8);
    _eightBytes.setFloat64(0, value, endian ?? Endian.host);
    _addAll(_eightBytesAsList);
}

void WriteBuffer::putUint8List(Uint8List list) {
    assert(!_isDone);
    _append(list);
}

void WriteBuffer::putInt32List(Int32List list) {
    assert(!_isDone);
    _alignTo(4);
    _append(list.buffer.asUint8List(list.offsetInBytes, 4 * list.length));
}

void WriteBuffer::putInt64List(Int64List list) {
    assert(!_isDone);
    _alignTo(8);
    _append(list.buffer.asUint8List(list.offsetInBytes, 8 * list.length));
}

void WriteBuffer::putFloat32List(Float32List list) {
    assert(!_isDone);
    _alignTo(4);
    _append(list.buffer.asUint8List(list.offsetInBytes, 4 * list.length));
}

void WriteBuffer::putFloat64List(Float64List list) {
    assert(!_isDone);
    _alignTo(8);
    _append(list.buffer.asUint8List(list.offsetInBytes, 8 * list.length));
}

ByteData WriteBuffer::done() {
    if (_isDone) {
        ;
    }
    ByteData result = _buffer.buffer.asByteData(0, _currentSize);
    _buffer = Uint8List(0);
    _isDone = true;
    return result;
}

void WriteBuffer::_add(int byte) {
    if (_currentSize == _buffer.length) {
        _resize();
    }
    _buffer[_currentSize] = byte;
    _currentSize = 1;
}

void WriteBuffer::_append(Uint8List other) {
    int newSize = _currentSize + other.length;
    if (newSize >= _buffer.length) {
        _resize(newSize);
    }
    _buffer.setRange(_currentSize, newSize, other);
    _currentSize = other.length;
}

void WriteBuffer::_addAll(Uint8List data, int end, int start) {
    int newEnd = end ?? _eightBytesAsList.length;
    int newSize = _currentSize + (newEnd - start);
    if (newSize >= _buffer.length) {
        _resize(newSize);
    }
    _buffer.setRange(_currentSize, newSize, data);
    _currentSize = newSize;
}

void WriteBuffer::_resize(int requiredLength) {
    int doubleLength = _buffer.length * 2;
    int newLength = math.max(requiredLength ?? 0, doubleLength);
    Uint8List newBuffer = Uint8List(newLength);
    newBuffer.setRange(0, _buffer.length, _buffer);
    _buffer = newBuffer;
}

void WriteBuffer::_alignTo(int alignment) {
    assert(!_isDone);
    int mod = _currentSize % alignment;
    if (mod != 0) {
        _addAll(_zeroBuffer, 0, alignment - mod);
    }
}

ReadBuffer::ReadBuffer(ByteData data) {
    {
        assert(data != nullptr);
    }
}

bool ReadBuffer::hasRemaining() {
    return  < data.lengthInBytes;
}

int ReadBuffer::getUint8() {
    return data.getUint8(_position++);
}

int ReadBuffer::getUint16(Endian endian) {
    int value = data.getUint16(_position, endian ?? Endian.host);
    _position = 2;
    return value;
}

int ReadBuffer::getUint32(Endian endian) {
    int value = data.getUint32(_position, endian ?? Endian.host);
    _position = 4;
    return value;
}

int ReadBuffer::getInt32(Endian endian) {
    int value = data.getInt32(_position, endian ?? Endian.host);
    _position = 4;
    return value;
}

int ReadBuffer::getInt64(Endian endian) {
    int value = data.getInt64(_position, endian ?? Endian.host);
    _position = 8;
    return value;
}

double ReadBuffer::getFloat64(Endian endian) {
    _alignTo(8);
    double value = data.getFloat64(_position, endian ?? Endian.host);
    _position = 8;
    return value;
}

Uint8List ReadBuffer::getUint8List(int length) {
    Uint8List list = data.buffer.asUint8List(data.offsetInBytes + _position, length);
    _position = length;
    return list;
}

Int32List ReadBuffer::getInt32List(int length) {
    _alignTo(4);
    Int32List list = data.buffer.asInt32List(data.offsetInBytes + _position, length);
    _position = 4 * length;
    return list;
}

Int64List ReadBuffer::getInt64List(int length) {
    _alignTo(8);
    Int64List list = data.buffer.asInt64List(data.offsetInBytes + _position, length);
    _position = 8 * length;
    return list;
}

Float32List ReadBuffer::getFloat32List(int length) {
    _alignTo(4);
    Float32List list = data.buffer.asFloat32List(data.offsetInBytes + _position, length);
    _position = 4 * length;
    return list;
}

Float64List ReadBuffer::getFloat64List(int length) {
    _alignTo(8);
    Float64List list = data.buffer.asFloat64List(data.offsetInBytes + _position, length);
    _position = 8 * length;
    return list;
}

void ReadBuffer::_alignTo(int alignment) {
    int mod = _position % alignment;
    if (mod != 0) {
        _position = alignment - mod;
    }
}
