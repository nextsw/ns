#include "bytes_builder.hpp"
BytesBuilder::BytesBuilder(bool copy) {
}

void _CopyingBytesBuilder::add(List<int> bytes) {
    int byteCount = bytes.length;
    if (byteCount == 0)     {
        return;
    }
    int required = _length + byteCount;
    if (_buffer.length < required) {
        _grow(required);
    }
    assert(_buffer.length >= required);
    if (bytes is Uint8List) {
        _buffer.setRange(_length, required, bytes);
    } else {
        for (;  < byteCount; i++) {
            _buffer[_length + i] = bytes[i];
        }
    }
    _length = required;
}

void _CopyingBytesBuilder::addByte(int byte) {
    if (_buffer.length == _length) {
        _grow(_length);
    }
    assert(_buffer.length > _length);
    _buffer[_length] = byte;
    _length++;
}

Uint8List _CopyingBytesBuilder::takeBytes() {
    if (_length == 0)     {
        return _emptyList;
    }
    auto buffer = Uint8List.view(_buffer.buffer, _buffer.offsetInBytes, _length);
    _clear();
    return buffer;
}

Uint8List _CopyingBytesBuilder::toBytes() {
    if (_length == 0)     {
        return _emptyList;
    }
    return Uint8List.fromList(Uint8List.view(_buffer.buffer, _buffer.offsetInBytes, _length));
}

int _CopyingBytesBuilder::length() {
    return _length;
}

bool _CopyingBytesBuilder::isEmpty() {
    return _length == 0;
}

bool _CopyingBytesBuilder::isNotEmpty() {
    return _length != 0;
}

void _CopyingBytesBuilder::clear() {
    _clear();
}

_CopyingBytesBuilder::_CopyingBytesBuilder() {
    {
        _buffer = _emptyList;
    }
}

void _CopyingBytesBuilder::_grow(int required) {
    int newSize = required * 2;
    if ( < _initSize) {
        newSize = _initSize;
    } else {
        newSize = _pow2roundup(newSize);
    }
    auto newBuffer = Uint8List(newSize);
    newBuffer.setRange(0, _buffer.length, _buffer);
    _buffer = newBuffer;
}

void _CopyingBytesBuilder::_clear() {
    _length = 0;
    _buffer = _emptyList;
}

int _CopyingBytesBuilder::_pow2roundup(int x) {
    assert(x > 0);
    --x;
    x = x >> 1;
    x = x >> 2;
    x = x >> 4;
    x = x >> 8;
    x = x >> 16;
    return x + 1;
}

void _BytesBuilder::add(List<int> bytes) {
    Uint8List typedBytes;
    if (bytes is Uint8List) {
        typedBytes = bytes;
    } else {
        typedBytes = Uint8List.fromList(bytes);
    }
    _chunks.add(typedBytes);
    _length = typedBytes.length;
}

void _BytesBuilder::addByte(int byte) {
    _chunks.add();
    _length++;
}

Uint8List _BytesBuilder::takeBytes() {
    if (_length == 0)     {
        return _CopyingBytesBuilder._emptyList;
    }
    if (_chunks.length == 1) {
        auto buffer = _chunks[0];
        _clear();
        return buffer;
    }
    auto buffer = Uint8List(_length);
    int offset = 0;
    for (auto chunk : _chunks) {
        buffer.setRange(offset, offset + chunk.length, chunk);
        offset = chunk.length;
    }
    _clear();
    return buffer;
}

Uint8List _BytesBuilder::toBytes() {
    if (_length == 0)     {
        return _CopyingBytesBuilder._emptyList;
    }
    auto buffer = Uint8List(_length);
    int offset = 0;
    for (auto chunk : _chunks) {
        buffer.setRange(offset, offset + chunk.length, chunk);
        offset = chunk.length;
    }
    return buffer;
}

int _BytesBuilder::length() {
    return _length;
}

bool _BytesBuilder::isEmpty() {
    return _length == 0;
}

bool _BytesBuilder::isNotEmpty() {
    return _length != 0;
}

void _BytesBuilder::clear() {
    _clear();
}

void _BytesBuilder::_clear() {
    _length = 0;
    _chunks.clear();
}
