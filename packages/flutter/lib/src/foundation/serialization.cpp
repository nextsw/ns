#include "serialization.hpp"
WriteBufferCls::WriteBufferCls(int startCapacity) {
    {
        assert(startCapacity > 0);
        ByteData eightBytes = make<ByteDataCls>(8);
        Uint8List eightBytesAsList = eightBytes->buffer()->asUint8List();
        return WriteBufferCls->_(make<Uint8ListCls>(startCapacity), eightBytes, eightBytesAsList);
    }
}

void WriteBufferCls::putUint8(int byte) {
    assert(!_isDone);
    _add(byte);
}

void WriteBufferCls::putUint16(int value, Endian endian) {
    assert(!_isDone);
    _eightBytes->setUint16(0, value, endian | EndianCls::host);
    _addAll(_eightBytesAsList, 0, 2);
}

void WriteBufferCls::putUint32(int value, Endian endian) {
    assert(!_isDone);
    _eightBytes->setUint32(0, value, endian | EndianCls::host);
    _addAll(_eightBytesAsList, 0, 4);
}

void WriteBufferCls::putInt32(int value, Endian endian) {
    assert(!_isDone);
    _eightBytes->setInt32(0, value, endian | EndianCls::host);
    _addAll(_eightBytesAsList, 0, 4);
}

void WriteBufferCls::putInt64(int value, Endian endian) {
    assert(!_isDone);
    _eightBytes->setInt64(0, value, endian | EndianCls::host);
    _addAll(_eightBytesAsList, 0, 8);
}

void WriteBufferCls::putFloat64(double value, Endian endian) {
    assert(!_isDone);
    _alignTo(8);
    _eightBytes->setFloat64(0, value, endian | EndianCls::host);
    _addAll(_eightBytesAsList);
}

void WriteBufferCls::putUint8List(Uint8List list) {
    assert(!_isDone);
    _append(list);
}

void WriteBufferCls::putInt32List(Int32List list) {
    assert(!_isDone);
    _alignTo(4);
    _append(list->buffer->asUint8List(list->offsetInBytes, 4 * list->length()));
}

void WriteBufferCls::putInt64List(Int64List list) {
    assert(!_isDone);
    _alignTo(8);
    _append(list->buffer->asUint8List(list->offsetInBytes, 8 * list->length()));
}

void WriteBufferCls::putFloat32List(Float32List list) {
    assert(!_isDone);
    _alignTo(4);
    _append(list->buffer->asUint8List(list->offsetInBytes, 4 * list->length()));
}

void WriteBufferCls::putFloat64List(Float64List list) {
    assert(!_isDone);
    _alignTo(8);
    _append(list->buffer->asUint8List(list->offsetInBytes, 8 * list->length()));
}

ByteData WriteBufferCls::done() {
    if (_isDone) {
        throw make<StateErrorCls>(__sf("done() must not be called more than once on the same %s.", runtimeType));
    }
    ByteData result = _buffer->buffer->asByteData(0, _currentSize);
    _buffer = make<Uint8ListCls>(0);
    _isDone = true;
    return result;
}

void WriteBufferCls::_add(int byte) {
    if (_currentSize == _buffer->length()) {
        _resize();
    }
    _buffer[_currentSize] = byte;
    _currentSize += 1;
}

void WriteBufferCls::_append(Uint8List other) {
    int newSize = _currentSize + other->length();
    if (newSize >= _buffer->length()) {
        _resize(newSize);
    }
    _buffer->setRange(_currentSize, newSize, other);
    _currentSize += other->length();
}

void WriteBufferCls::_addAll(Uint8List data, int start, int end) {
    int newEnd = end | _eightBytesAsList->length();
    int newSize = _currentSize + (newEnd - start);
    if (newSize >= _buffer->length()) {
        _resize(newSize);
    }
    _buffer->setRange(_currentSize, newSize, data);
    _currentSize = newSize;
}

void WriteBufferCls::_resize(int requiredLength) {
    int doubleLength = _buffer->length() * 2;
    int newLength = math->max(requiredLength | 0, doubleLength);
    Uint8List newBuffer = make<Uint8ListCls>(newLength);
    newBuffer->setRange(0, _buffer->length(), _buffer);
    _buffer = newBuffer;
}

void WriteBufferCls::_alignTo(int alignment) {
    assert(!_isDone);
    int mod = _currentSize % alignment;
    if (mod != 0) {
        _addAll(_zeroBuffer, 0, alignment - mod);
    }
}

ReadBufferCls::ReadBufferCls(ByteData data) {
    {
        assert(data != nullptr);
    }
}

bool ReadBufferCls::hasRemaining() {
    return  < data->lengthInBytes();
}

int ReadBufferCls::getUint8() {
    return data->getUint8(_position++);
}

int ReadBufferCls::getUint16(Endian endian) {
    int value = data->getUint16(_position, endian | EndianCls::host);
    _position += 2;
    return value;
}

int ReadBufferCls::getUint32(Endian endian) {
    int value = data->getUint32(_position, endian | EndianCls::host);
    _position += 4;
    return value;
}

int ReadBufferCls::getInt32(Endian endian) {
    int value = data->getInt32(_position, endian | EndianCls::host);
    _position += 4;
    return value;
}

int ReadBufferCls::getInt64(Endian endian) {
    int value = data->getInt64(_position, endian | EndianCls::host);
    _position += 8;
    return value;
}

double ReadBufferCls::getFloat64(Endian endian) {
    _alignTo(8);
    double value = data->getFloat64(_position, endian | EndianCls::host);
    _position += 8;
    return value;
}

Uint8List ReadBufferCls::getUint8List(int length) {
    Uint8List list = data->buffer()->asUint8List(data->offsetInBytes() + _position, length);
    _position += length;
    return list;
}

Int32List ReadBufferCls::getInt32List(int length) {
    _alignTo(4);
    Int32List list = data->buffer()->asInt32List(data->offsetInBytes() + _position, length);
    _position += 4 * length;
    return list;
}

Int64List ReadBufferCls::getInt64List(int length) {
    _alignTo(8);
    Int64List list = data->buffer()->asInt64List(data->offsetInBytes() + _position, length);
    _position += 8 * length;
    return list;
}

Float32List ReadBufferCls::getFloat32List(int length) {
    _alignTo(4);
    Float32List list = data->buffer()->asFloat32List(data->offsetInBytes() + _position, length);
    _position += 4 * length;
    return list;
}

Float64List ReadBufferCls::getFloat64List(int length) {
    _alignTo(8);
    Float64List list = data->buffer()->asFloat64List(data->offsetInBytes() + _position, length);
    _position += 8 * length;
    return list;
}

void ReadBufferCls::_alignTo(int alignment) {
    int mod = _position % alignment;
    if (mod != 0) {
        _position += alignment - mod;
    }
}
