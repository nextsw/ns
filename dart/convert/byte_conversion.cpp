#include "byte_conversion.hpp"
void ByteConversionSinkBaseCls::addSlice(List<int> chunk, int end, bool isLast, int start) {
    add(chunk->sublist(start, end));
    if (isLast)     {
        close();
    }
}

void _ByteAdapterSinkCls::add(List<int> chunk) {
    _sink->add(chunk);
}

void _ByteAdapterSinkCls::close() {
    _sink->close();
}

void _ByteCallbackSinkCls::add(Iterable<int> chunk) {
    auto freeCount = _buffer->length() - _bufferIndex;
    if (chunk->length() > freeCount) {
        auto oldLength = _buffer->length();
        auto newLength = _roundToPowerOf2(chunk->length() + oldLength) * 2;
        auto grown = make<Uint8ListCls>(newLength);
        grown->setRange(0, _buffer->length(), _buffer);
        _buffer = grown;
    }
    _buffer->setRange(_bufferIndex, _bufferIndex + chunk->length(), chunk);
    _bufferIndex = chunk->length();
}

void _ByteCallbackSinkCls::close() {
    _callback(_buffer->sublist(0, _bufferIndex));
}

_ByteCallbackSinkCls::_ByteCallbackSinkCls(std::function<void(List<int> accumulated)> callback) {
    {
        _callback = callback;
    }
}

int _ByteCallbackSinkCls::_roundToPowerOf2(int v) {
    assert(v > 0);
    v--;
    v = v >> 1;
    v = v >> 2;
    v = v >> 4;
    v = v >> 8;
    v = v >> 16;
    v++;
    return v;
}
