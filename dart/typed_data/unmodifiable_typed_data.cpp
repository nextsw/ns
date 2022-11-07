#include "unmodifiable_typed_data.hpp"
UnmodifiableByteBufferView::UnmodifiableByteBufferView(ByteBuffer data) {
    {
        _data = data;
    }
}

int UnmodifiableByteBufferView::lengthInBytes() {
    return _data.lengthInBytes;
}

Uint8List UnmodifiableByteBufferView::asUint8List(int length, int offsetInBytes) {
    return UnmodifiableUint8ListView(_data.asUint8List(offsetInBytes, length));
}

Int8List UnmodifiableByteBufferView::asInt8List(int length, int offsetInBytes) {
    return UnmodifiableInt8ListView(_data.asInt8List(offsetInBytes, length));
}

Uint8ClampedList UnmodifiableByteBufferView::asUint8ClampedList(int length, int offsetInBytes) {
    return UnmodifiableUint8ClampedListView(_data.asUint8ClampedList(offsetInBytes, length));
}

Uint16List UnmodifiableByteBufferView::asUint16List(int length, int offsetInBytes) {
    return UnmodifiableUint16ListView(_data.asUint16List(offsetInBytes, length));
}

Int16List UnmodifiableByteBufferView::asInt16List(int length, int offsetInBytes) {
    return UnmodifiableInt16ListView(_data.asInt16List(offsetInBytes, length));
}

Uint32List UnmodifiableByteBufferView::asUint32List(int length, int offsetInBytes) {
    return UnmodifiableUint32ListView(_data.asUint32List(offsetInBytes, length));
}

Int32List UnmodifiableByteBufferView::asInt32List(int length, int offsetInBytes) {
    return UnmodifiableInt32ListView(_data.asInt32List(offsetInBytes, length));
}

Uint64List UnmodifiableByteBufferView::asUint64List(int length, int offsetInBytes) {
    return UnmodifiableUint64ListView(_data.asUint64List(offsetInBytes, length));
}

Int64List UnmodifiableByteBufferView::asInt64List(int length, int offsetInBytes) {
    return UnmodifiableInt64ListView(_data.asInt64List(offsetInBytes, length));
}

Int32x4List UnmodifiableByteBufferView::asInt32x4List(int length, int offsetInBytes) {
    return UnmodifiableInt32x4ListView(_data.asInt32x4List(offsetInBytes, length));
}

Float32List UnmodifiableByteBufferView::asFloat32List(int length, int offsetInBytes) {
    return UnmodifiableFloat32ListView(_data.asFloat32List(offsetInBytes, length));
}

Float64List UnmodifiableByteBufferView::asFloat64List(int length, int offsetInBytes) {
    return UnmodifiableFloat64ListView(_data.asFloat64List(offsetInBytes, length));
}

Float32x4List UnmodifiableByteBufferView::asFloat32x4List(int length, int offsetInBytes) {
    return UnmodifiableFloat32x4ListView(_data.asFloat32x4List(offsetInBytes, length));
}

Float64x2List UnmodifiableByteBufferView::asFloat64x2List(int length, int offsetInBytes) {
    return UnmodifiableFloat64x2ListView(_data.asFloat64x2List(offsetInBytes, length));
}

ByteData UnmodifiableByteBufferView::asByteData(int length, int offsetInBytes) {
    return UnmodifiableByteDataView(_data.asByteData(offsetInBytes, length));
}

UnmodifiableByteDataView::UnmodifiableByteDataView(ByteData data) {
    {
        _data = data;
    }
}

int UnmodifiableByteDataView::getInt8(int byteOffset) {
    return _data.getInt8(byteOffset);
}

void UnmodifiableByteDataView::setInt8(int byteOffset, int value) {
    return _unsupported();
}

int UnmodifiableByteDataView::getUint8(int byteOffset) {
    return _data.getUint8(byteOffset);
}

void UnmodifiableByteDataView::setUint8(int byteOffset, int value) {
    return _unsupported();
}

int UnmodifiableByteDataView::getInt16(int byteOffset, Endian endian) {
    return _data.getInt16(byteOffset, endian);
}

void UnmodifiableByteDataView::setInt16(int byteOffset, Endian endian, int value) {
    return _unsupported();
}

int UnmodifiableByteDataView::getUint16(int byteOffset, Endian endian) {
    return _data.getUint16(byteOffset, endian);
}

void UnmodifiableByteDataView::setUint16(int byteOffset, Endian endian, int value) {
    return _unsupported();
}

int UnmodifiableByteDataView::getInt32(int byteOffset, Endian endian) {
    return _data.getInt32(byteOffset, endian);
}

void UnmodifiableByteDataView::setInt32(int byteOffset, Endian endian, int value) {
    return _unsupported();
}

int UnmodifiableByteDataView::getUint32(int byteOffset, Endian endian) {
    return _data.getUint32(byteOffset, endian);
}

void UnmodifiableByteDataView::setUint32(int byteOffset, Endian endian, int value) {
    return _unsupported();
}

int UnmodifiableByteDataView::getInt64(int byteOffset, Endian endian) {
    return _data.getInt64(byteOffset, endian);
}

void UnmodifiableByteDataView::setInt64(int byteOffset, Endian endian, int value) {
    return _unsupported();
}

int UnmodifiableByteDataView::getUint64(int byteOffset, Endian endian) {
    return _data.getUint64(byteOffset, endian);
}

void UnmodifiableByteDataView::setUint64(int byteOffset, Endian endian, int value) {
    return _unsupported();
}

double UnmodifiableByteDataView::getFloat32(int byteOffset, Endian endian) {
    return _data.getFloat32(byteOffset, endian);
}

void UnmodifiableByteDataView::setFloat32(int byteOffset, Endian endian, double value) {
    return _unsupported();
}

double UnmodifiableByteDataView::getFloat64(int byteOffset, Endian endian) {
    return _data.getFloat64(byteOffset, endian);
}

void UnmodifiableByteDataView::setFloat64(int byteOffset, Endian endian, double value) {
    return _unsupported();
}

int UnmodifiableByteDataView::elementSizeInBytes() {
    return _data.elementSizeInBytes;
}

int UnmodifiableByteDataView::offsetInBytes() {
    return _data.offsetInBytes;
}

int UnmodifiableByteDataView::lengthInBytes() {
    return _data.lengthInBytes;
}

ByteBuffer UnmodifiableByteDataView::buffer() {
    return UnmodifiableByteBufferView(_data.buffer);
}

void UnmodifiableByteDataView::_unsupported() {
    ;
}

int _UnmodifiableListMixin::length() {
    return _list.length;
}

N _UnmodifiableListMixin::[](int index) {
    return _list[index];
}

int _UnmodifiableListMixin::elementSizeInBytes() {
    return _data.elementSizeInBytes;
}

int _UnmodifiableListMixin::offsetInBytes() {
    return _data.offsetInBytes;
}

int _UnmodifiableListMixin::lengthInBytes() {
    return _data.lengthInBytes;
}

ByteBuffer _UnmodifiableListMixin::buffer() {
    return UnmodifiableByteBufferView(_data.buffer);
}

L _UnmodifiableListMixin::sublist(int end, int start) {
    int endIndex = RangeError.checkValidRange(start, end!, length);
    int sublistLength = endIndex - start;
    L result = _createList(sublistLength);
    result.setRange(0, sublistLength, _list, start);
    return result;
}

TD _UnmodifiableListMixin::_data() {
    return (();
}

UnmodifiableUint8ListView::UnmodifiableUint8ListView(Uint8List list) {
    {
        _list = list;
    }
}

Uint8List UnmodifiableUint8ListView::_createList(int length) {
    return Uint8List(length);
}

UnmodifiableInt8ListView::UnmodifiableInt8ListView(Int8List list) {
    {
        _list = list;
    }
}

Int8List UnmodifiableInt8ListView::_createList(int length) {
    return Int8List(length);
}

UnmodifiableUint8ClampedListView::UnmodifiableUint8ClampedListView(Uint8ClampedList list) {
    {
        _list = list;
    }
}

Uint8ClampedList UnmodifiableUint8ClampedListView::_createList(int length) {
    return Uint8ClampedList(length);
}

UnmodifiableUint16ListView::UnmodifiableUint16ListView(Uint16List list) {
    {
        _list = list;
    }
}

Uint16List UnmodifiableUint16ListView::_createList(int length) {
    return Uint16List(length);
}

UnmodifiableInt16ListView::UnmodifiableInt16ListView(Int16List list) {
    {
        _list = list;
    }
}

Int16List UnmodifiableInt16ListView::_createList(int length) {
    return Int16List(length);
}

UnmodifiableUint32ListView::UnmodifiableUint32ListView(Uint32List list) {
    {
        _list = list;
    }
}

Uint32List UnmodifiableUint32ListView::_createList(int length) {
    return Uint32List(length);
}

UnmodifiableInt32ListView::UnmodifiableInt32ListView(Int32List list) {
    {
        _list = list;
    }
}

Int32List UnmodifiableInt32ListView::_createList(int length) {
    return Int32List(length);
}

UnmodifiableUint64ListView::UnmodifiableUint64ListView(Uint64List list) {
    {
        _list = list;
    }
}

Uint64List UnmodifiableUint64ListView::_createList(int length) {
    return Uint64List(length);
}

UnmodifiableInt64ListView::UnmodifiableInt64ListView(Int64List list) {
    {
        _list = list;
    }
}

Int64List UnmodifiableInt64ListView::_createList(int length) {
    return Int64List(length);
}

UnmodifiableInt32x4ListView::UnmodifiableInt32x4ListView(Int32x4List list) {
    {
        _list = list;
    }
}

Int32x4List UnmodifiableInt32x4ListView::_createList(int length) {
    return Int32x4List(length);
}

UnmodifiableFloat32x4ListView::UnmodifiableFloat32x4ListView(Float32x4List list) {
    {
        _list = list;
    }
}

Float32x4List UnmodifiableFloat32x4ListView::_createList(int length) {
    return Float32x4List(length);
}

UnmodifiableFloat64x2ListView::UnmodifiableFloat64x2ListView(Float64x2List list) {
    {
        _list = list;
    }
}

Float64x2List UnmodifiableFloat64x2ListView::_createList(int length) {
    return Float64x2List(length);
}

UnmodifiableFloat32ListView::UnmodifiableFloat32ListView(Float32List list) {
    {
        _list = list;
    }
}

Float32List UnmodifiableFloat32ListView::_createList(int length) {
    return Float32List(length);
}

UnmodifiableFloat64ListView::UnmodifiableFloat64ListView(Float64List list) {
    {
        _list = list;
    }
}

Float64List UnmodifiableFloat64ListView::_createList(int length) {
    return Float64List(length);
}
