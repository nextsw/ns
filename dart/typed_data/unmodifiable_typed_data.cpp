#include "unmodifiable_typed_data.hpp"
UnmodifiableByteBufferViewCls::UnmodifiableByteBufferViewCls(ByteBuffer data) {
    {
        _data = data;
    }
}

int UnmodifiableByteBufferViewCls::lengthInBytes() {
    return _data->lengthInBytes();
}

Uint8List UnmodifiableByteBufferViewCls::asUint8List(int offsetInBytes, int length) {
    return make<UnmodifiableUint8ListViewCls>(_data->asUint8List(offsetInBytes, length));
}

Int8List UnmodifiableByteBufferViewCls::asInt8List(int offsetInBytes, int length) {
    return make<UnmodifiableInt8ListViewCls>(_data->asInt8List(offsetInBytes, length));
}

Uint8ClampedList UnmodifiableByteBufferViewCls::asUint8ClampedList(int offsetInBytes, int length) {
    return make<UnmodifiableUint8ClampedListViewCls>(_data->asUint8ClampedList(offsetInBytes, length));
}

Uint16List UnmodifiableByteBufferViewCls::asUint16List(int offsetInBytes, int length) {
    return make<UnmodifiableUint16ListViewCls>(_data->asUint16List(offsetInBytes, length));
}

Int16List UnmodifiableByteBufferViewCls::asInt16List(int offsetInBytes, int length) {
    return make<UnmodifiableInt16ListViewCls>(_data->asInt16List(offsetInBytes, length));
}

Uint32List UnmodifiableByteBufferViewCls::asUint32List(int offsetInBytes, int length) {
    return make<UnmodifiableUint32ListViewCls>(_data->asUint32List(offsetInBytes, length));
}

Int32List UnmodifiableByteBufferViewCls::asInt32List(int offsetInBytes, int length) {
    return make<UnmodifiableInt32ListViewCls>(_data->asInt32List(offsetInBytes, length));
}

Uint64List UnmodifiableByteBufferViewCls::asUint64List(int offsetInBytes, int length) {
    return make<UnmodifiableUint64ListViewCls>(_data->asUint64List(offsetInBytes, length));
}

Int64List UnmodifiableByteBufferViewCls::asInt64List(int offsetInBytes, int length) {
    return make<UnmodifiableInt64ListViewCls>(_data->asInt64List(offsetInBytes, length));
}

Int32x4List UnmodifiableByteBufferViewCls::asInt32x4List(int offsetInBytes, int length) {
    return make<UnmodifiableInt32x4ListViewCls>(_data->asInt32x4List(offsetInBytes, length));
}

Float32List UnmodifiableByteBufferViewCls::asFloat32List(int offsetInBytes, int length) {
    return make<UnmodifiableFloat32ListViewCls>(_data->asFloat32List(offsetInBytes, length));
}

Float64List UnmodifiableByteBufferViewCls::asFloat64List(int offsetInBytes, int length) {
    return make<UnmodifiableFloat64ListViewCls>(_data->asFloat64List(offsetInBytes, length));
}

Float32x4List UnmodifiableByteBufferViewCls::asFloat32x4List(int offsetInBytes, int length) {
    return make<UnmodifiableFloat32x4ListViewCls>(_data->asFloat32x4List(offsetInBytes, length));
}

Float64x2List UnmodifiableByteBufferViewCls::asFloat64x2List(int offsetInBytes, int length) {
    return make<UnmodifiableFloat64x2ListViewCls>(_data->asFloat64x2List(offsetInBytes, length));
}

ByteData UnmodifiableByteBufferViewCls::asByteData(int offsetInBytes, int length) {
    return make<UnmodifiableByteDataViewCls>(_data->asByteData(offsetInBytes, length));
}

UnmodifiableByteDataViewCls::UnmodifiableByteDataViewCls(ByteData data) {
    {
        _data = data;
    }
}

int UnmodifiableByteDataViewCls::getInt8(int byteOffset) {
    return _data->getInt8(byteOffset);
}

void UnmodifiableByteDataViewCls::setInt8(int byteOffset, int value) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::getUint8(int byteOffset) {
    return _data->getUint8(byteOffset);
}

void UnmodifiableByteDataViewCls::setUint8(int byteOffset, int value) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::getInt16(int byteOffset, Endian endian) {
    return _data->getInt16(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setInt16(int byteOffset, int value, Endian endian) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::getUint16(int byteOffset, Endian endian) {
    return _data->getUint16(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setUint16(int byteOffset, int value, Endian endian) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::getInt32(int byteOffset, Endian endian) {
    return _data->getInt32(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setInt32(int byteOffset, int value, Endian endian) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::getUint32(int byteOffset, Endian endian) {
    return _data->getUint32(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setUint32(int byteOffset, int value, Endian endian) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::getInt64(int byteOffset, Endian endian) {
    return _data->getInt64(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setInt64(int byteOffset, int value, Endian endian) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::getUint64(int byteOffset, Endian endian) {
    return _data->getUint64(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setUint64(int byteOffset, int value, Endian endian) {
    return _unsupported();
}

double UnmodifiableByteDataViewCls::getFloat32(int byteOffset, Endian endian) {
    return _data->getFloat32(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setFloat32(int byteOffset, double value, Endian endian) {
    return _unsupported();
}

double UnmodifiableByteDataViewCls::getFloat64(int byteOffset, Endian endian) {
    return _data->getFloat64(byteOffset, endian);
}

void UnmodifiableByteDataViewCls::setFloat64(int byteOffset, double value, Endian endian) {
    return _unsupported();
}

int UnmodifiableByteDataViewCls::elementSizeInBytes() {
    return _data->elementSizeInBytes;
}

int UnmodifiableByteDataViewCls::offsetInBytes() {
    return _data->offsetInBytes;
}

int UnmodifiableByteDataViewCls::lengthInBytes() {
    return _data->lengthInBytes;
}

ByteBuffer UnmodifiableByteDataViewCls::buffer() {
    return make<UnmodifiableByteBufferViewCls>(_data->buffer);
}

void UnmodifiableByteDataViewCls::_unsupported() {
    throw make<UnsupportedErrorCls>(__s("An UnmodifiableByteDataView may not be modified"));
}

template<typename N, typename L, typename TD>
int _UnmodifiableListMixinCls<N, L, TD>::length() {
    return _list()->length();
}

template<typename N, typename L, typename TD>
N _UnmodifiableListMixinCls<N, L, TD>::[](int index) {
    return _list()[index];
}

template<typename N, typename L, typename TD>
int _UnmodifiableListMixinCls<N, L, TD>::elementSizeInBytes() {
    return _data()->elementSizeInBytes();
}

template<typename N, typename L, typename TD>
int _UnmodifiableListMixinCls<N, L, TD>::offsetInBytes() {
    return _data()->offsetInBytes();
}

template<typename N, typename L, typename TD>
int _UnmodifiableListMixinCls<N, L, TD>::lengthInBytes() {
    return _data()->lengthInBytes();
}

template<typename N, typename L, typename TD>
ByteBuffer _UnmodifiableListMixinCls<N, L, TD>::buffer() {
    return make<UnmodifiableByteBufferViewCls>(_data()->buffer());
}

template<typename N, typename L, typename TD>
L _UnmodifiableListMixinCls<N, L, TD>::sublist(int start, int end) {
    int endIndex = RangeErrorCls->checkValidRange(start, end!, length());
    int sublistLength = endIndex - start;
    L result = _createList(sublistLength);
    result->setRange(0, sublistLength, _list(), start);
    return result;
}

template<typename N, typename L, typename TD>
TD _UnmodifiableListMixinCls<N, L, TD>::_data() {
    return (as<TD>(_list()));
}

UnmodifiableUint8ListViewCls::UnmodifiableUint8ListViewCls(Uint8List list) {
    {
        _list = list;
    }
}

Uint8List UnmodifiableUint8ListViewCls::_createList(int length) {
    return make<Uint8ListCls>(length);
}

UnmodifiableInt8ListViewCls::UnmodifiableInt8ListViewCls(Int8List list) {
    {
        _list = list;
    }
}

Int8List UnmodifiableInt8ListViewCls::_createList(int length) {
    return make<Int8ListCls>(length);
}

UnmodifiableUint8ClampedListViewCls::UnmodifiableUint8ClampedListViewCls(Uint8ClampedList list) {
    {
        _list = list;
    }
}

Uint8ClampedList UnmodifiableUint8ClampedListViewCls::_createList(int length) {
    return make<Uint8ClampedListCls>(length);
}

UnmodifiableUint16ListViewCls::UnmodifiableUint16ListViewCls(Uint16List list) {
    {
        _list = list;
    }
}

Uint16List UnmodifiableUint16ListViewCls::_createList(int length) {
    return make<Uint16ListCls>(length);
}

UnmodifiableInt16ListViewCls::UnmodifiableInt16ListViewCls(Int16List list) {
    {
        _list = list;
    }
}

Int16List UnmodifiableInt16ListViewCls::_createList(int length) {
    return make<Int16ListCls>(length);
}

UnmodifiableUint32ListViewCls::UnmodifiableUint32ListViewCls(Uint32List list) {
    {
        _list = list;
    }
}

Uint32List UnmodifiableUint32ListViewCls::_createList(int length) {
    return make<Uint32ListCls>(length);
}

UnmodifiableInt32ListViewCls::UnmodifiableInt32ListViewCls(Int32List list) {
    {
        _list = list;
    }
}

Int32List UnmodifiableInt32ListViewCls::_createList(int length) {
    return make<Int32ListCls>(length);
}

UnmodifiableUint64ListViewCls::UnmodifiableUint64ListViewCls(Uint64List list) {
    {
        _list = list;
    }
}

Uint64List UnmodifiableUint64ListViewCls::_createList(int length) {
    return make<Uint64ListCls>(length);
}

UnmodifiableInt64ListViewCls::UnmodifiableInt64ListViewCls(Int64List list) {
    {
        _list = list;
    }
}

Int64List UnmodifiableInt64ListViewCls::_createList(int length) {
    return make<Int64ListCls>(length);
}

UnmodifiableInt32x4ListViewCls::UnmodifiableInt32x4ListViewCls(Int32x4List list) {
    {
        _list = list;
    }
}

Int32x4List UnmodifiableInt32x4ListViewCls::_createList(int length) {
    return make<Int32x4ListCls>(length);
}

UnmodifiableFloat32x4ListViewCls::UnmodifiableFloat32x4ListViewCls(Float32x4List list) {
    {
        _list = list;
    }
}

Float32x4List UnmodifiableFloat32x4ListViewCls::_createList(int length) {
    return make<Float32x4ListCls>(length);
}

UnmodifiableFloat64x2ListViewCls::UnmodifiableFloat64x2ListViewCls(Float64x2List list) {
    {
        _list = list;
    }
}

Float64x2List UnmodifiableFloat64x2ListViewCls::_createList(int length) {
    return make<Float64x2ListCls>(length);
}

UnmodifiableFloat32ListViewCls::UnmodifiableFloat32ListViewCls(Float32List list) {
    {
        _list = list;
    }
}

Float32List UnmodifiableFloat32ListViewCls::_createList(int length) {
    return make<Float32ListCls>(length);
}

UnmodifiableFloat64ListViewCls::UnmodifiableFloat64ListViewCls(Float64List list) {
    {
        _list = list;
    }
}

Float64List UnmodifiableFloat64ListViewCls::_createList(int length) {
    return make<Float64ListCls>(length);
}
