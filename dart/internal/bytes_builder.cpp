#include "bytes_builder.hpp"
BytesBuilderCls::BytesBuilderCls(bool copy) {
}

void _CopyingBytesBuilderCls::add(List<int> bytes) {
    int byteCount = bytes->length;
    if (byteCount == 0)     {
        return;
    }
    int required = _length + byteCount;
    if (_buffer->length < required) {
        _grow(required);
    }
    assert(_buffer->length >= required);
    if (bytes is Uint8List) {
        _buffer->setRange(_length, required, bytes);
    } else {
        for (;  < byteCount; i++) {
            _buffer[_length + i] = bytes[i];
        }
    }
    _length = required;
}

void _CopyingBytesBuilderCls::addByte(int byte) {
    if (_buffer->length == _length) {
        _grow(_length);
    }
    assert(_buffer->length > _length);
    _buffer[_length] = byte;
    _length++;
}

Uint8List _CopyingBytesBuilderCls::takeBytes() {
    if (_length == 0)     {
        return _emptyList;
    }
    auto buffer = Uint8ListCls->view(_buffer->buffer, _buffer->offsetInBytes, _length);
    _clear();
    return buffer;
}

Uint8List _CopyingBytesBuilderCls::toBytes() {
    if (_length == 0)     {
        return _emptyList;
    }
    return Uint8ListCls->fromList(Uint8ListCls->view(_buffer->buffer, _buffer->offsetInBytes, _length));
}

int _CopyingBytesBuilderCls::length() {
    return _length;
}

bool _CopyingBytesBuilderCls::isEmpty() {
    return _length == 0;
}

bool _CopyingBytesBuilderCls::isNotEmpty() {
    return _length != 0;
}

void _CopyingBytesBuilderCls::clear() {
    _clear();
}

_CopyingBytesBuilderCls::_CopyingBytesBuilderCls() {
    {
        _buffer = _emptyList;
    }
}

void _CopyingBytesBuilderCls::_grow(int required) {
    int newSize = required * 2;
    if ( < _initSize) {
        newSize = _initSize;
    } else {
        newSize = _pow2roundup(newSize);
    }
    auto newBuffer = make<Uint8ListCls>(newSize);
    newBuffer->setRange(0, _buffer->length, _buffer);
    _buffer = newBuffer;
}

void _CopyingBytesBuilderCls::_clear() {
    _length = 0;
    _buffer = _emptyList;
}

int _CopyingBytesBuilderCls::_pow2roundup(int x) {
    assert(x > 0);
    --x;
    x = x >> 1;
    x = x >> 2;
    x = x >> 4;
    x = x >> 8;
    x = x >> 16;
    return x + 1;
}

void _BytesBuilderCls::add(List<int> bytes) {
    Uint8List typedBytes;
    if (bytes is Uint8List) {
        typedBytes = bytes;
    } else {
        typedBytes = Uint8ListCls->fromList(bytes);
    }
    _chunks->add(typedBytes);
    _length = typedBytes->length;
}

void _BytesBuilderCls::addByte(int byte) {
    auto _c1 = make<Uint8ListCls>(1);_c1[0] =byte;_chunks->add(_c1);
    _length++;
}

Uint8List _BytesBuilderCls::takeBytes() {
    if (_length == 0)     {
        return _CopyingBytesBuilderCls::_emptyList;
    }
    if (_chunks->length == 1) {
        auto buffer = _chunks[0];
        _clear();
        return buffer;
    }
    auto buffer = make<Uint8ListCls>(_length);
    int offset = 0;
    for (auto chunk : _chunks) {
        buffer->setRange(offset, offset + chunk->length, chunk);
        offset = chunk->length;
    }
    _clear();
    return buffer;
}

Uint8List _BytesBuilderCls::toBytes() {
    if (_length == 0)     {
        return _CopyingBytesBuilderCls::_emptyList;
    }
    auto buffer = make<Uint8ListCls>(_length);
    int offset = 0;
    for (auto chunk : _chunks) {
        buffer->setRange(offset, offset + chunk->length, chunk);
        offset = chunk->length;
    }
    return buffer;
}

int _BytesBuilderCls::length() {
    return _length;
}

bool _BytesBuilderCls::isEmpty() {
    return _length == 0;
}

bool _BytesBuilderCls::isNotEmpty() {
    return _length != 0;
}

void _BytesBuilderCls::clear() {
    _clear();
}

void _BytesBuilderCls::_clear() {
    _length = 0;
    _chunks->clear();
}
