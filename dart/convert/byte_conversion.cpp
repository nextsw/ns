#include "byte_conversion.hpp"
void ByteConversionSinkBase::addSlice(List<int> chunk, int end, bool isLast, int start) {
    add(chunk.sublist(start, end));
    if (isLast)     {
        close();
    }
}

void _ByteAdapterSink::add(List<int> chunk) {
    _sink.add(chunk);
}

void _ByteAdapterSink::close() {
    _sink.close();
}

void _ByteCallbackSink::add(Iterable<int> chunk) {
    auto freeCount = _buffer.length - _bufferIndex;
    if (chunk.length > freeCount) {
        auto oldLength = _buffer.length;
        auto newLength = _roundToPowerOf2(chunk.length + oldLength) * 2;
        auto grown = Uint8List(newLength);
        grown.setRange(0, _buffer.length, _buffer);
        _buffer = grown;
    }
    _buffer.setRange(_bufferIndex, _bufferIndex + chunk.length, chunk);
    _bufferIndex = chunk.length;
}

void _ByteCallbackSink::close() {
    _callback(_buffer.sublist(0, _bufferIndex));
}

_ByteCallbackSink::_ByteCallbackSink(FunctionType callback) {
    {
        _callback = callback;
    }
}

int _ByteCallbackSink::_roundToPowerOf2(int v) {
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
