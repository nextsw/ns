#include "utf.hpp"
Utf8CodecCls::Utf8CodecCls(bool allowMalformed) {
    {
        _allowMalformed = allowMalformed;
    }
}

String Utf8CodecCls::name() {
    return __s("utf-8");
}

String Utf8CodecCls::decode(List<int> codeUnits, bool allowMalformed) {
    Utf8Decoder decoder = allowMalformed | _allowMalformed? make<Utf8DecoderCls>(true) : make<Utf8DecoderCls>(false);
    return decoder->convert(codeUnits);
}

Utf8Encoder Utf8CodecCls::encoder() {
    return make<Utf8EncoderCls>();
}

Utf8Decoder Utf8CodecCls::decoder() {
    return _allowMalformed? make<Utf8DecoderCls>(true) : make<Utf8DecoderCls>(false);
}

Uint8List Utf8EncoderCls::convert(String stringValue, int start, int end) {
    auto stringLength = stringValue->length();
    end = RangeErrorCls->checkValidRange(start, end, stringLength);
    auto length = end - start;
    if (length == 0) {
        return make<Uint8ListCls>(0);
    }
    auto encoder = _Utf8EncoderCls->withBufferSize(length * 3);
    auto endPosition = encoder->_fillBuffer(stringValue, start, end);
    assert(endPosition >= end - 1);
    if (endPosition != end) {
        auto lastCodeUnit = stringValue->codeUnitAt(end - 1);
        assert(_isLeadSurrogate(lastCodeUnit));
        encoder->_writeReplacementCharacter();
    }
    return encoder->_buffer->sublist(0, encoder->_bufferIndex);
}

StringConversionSink Utf8EncoderCls::startChunkedConversion(Sink<List<int>> sink) {
    return make<_Utf8EncoderSinkCls>(is<ByteConversionSink>(sink)? sink : ByteConversionSinkCls->from(sink));
}

Stream<List<int>> Utf8EncoderCls::bind(Stream<String> stream) {
    return super->bind(stream);
}

void _Utf8EncoderCls::withBufferSize(int bufferSize)

_Utf8EncoderCls::_Utf8EncoderCls() {
    {
        this->withBufferSize(_DEFAULT_BYTE_BUFFER_SIZE);
    }
}

Uint8List _Utf8EncoderCls::_createBuffer(int size) {
    return make<Uint8ListCls>(size);
}

void _Utf8EncoderCls::_writeReplacementCharacter() {
    _buffer[_bufferIndex++] = 0xEF;
    _buffer[_bufferIndex++] = 0xBF;
    _buffer[_bufferIndex++] = 0xBD;
}

bool _Utf8EncoderCls::_writeSurrogate(int leadingSurrogate, int nextCodeUnit) {
    if (_isTailSurrogate(nextCodeUnit)) {
        auto rune = _combineSurrogatePair(leadingSurrogate, nextCodeUnit);
        assert(rune > _THREE_BYTE_LIMIT);
        assert(rune <= _FOUR_BYTE_LIMIT);
        _buffer[_bufferIndex++] = 0xF0 | (rune >> 18);
        _buffer[_bufferIndex++] = 0x80 | ((rune >> 12) & 0x3f);
        _buffer[_bufferIndex++] = 0x80 | ((rune >> 6) & 0x3f);
        _buffer[_bufferIndex++] = 0x80 | (rune & 0x3f);
        return true;
    } else {
        _writeReplacementCharacter();
        return false;
    }
}

int _Utf8EncoderCls::_fillBuffer(String str, int start, int end) {
    if (start != end && _isLeadSurrogate(str->codeUnitAt(end - 1))) {
        end--;
    }
    int stringIndex;
    for (stringIndex = start;  < end; stringIndex++) {
        auto codeUnit = str->codeUnitAt(stringIndex);
        if (codeUnit <= _ONE_BYTE_LIMIT) {
            if (_bufferIndex >= _buffer->length()) {
                break;
            }
            _buffer[_bufferIndex++] = codeUnit;
        } else {
            if (_isLeadSurrogate(codeUnit)) {
            if (_bufferIndex + 4 > _buffer->length()) {
                break;
            }
            auto nextCodeUnit = str->codeUnitAt(stringIndex + 1);
            auto wasCombined = _writeSurrogate(codeUnit, nextCodeUnit);
            if (wasCombined) {
                stringIndex++;
            }
        } else {
            if (_isTailSurrogate(codeUnit)) {
            if (_bufferIndex + 3 > _buffer->length()) {
                break;
            }
            _writeReplacementCharacter();
        } else {
            auto rune = codeUnit;
            if (rune <= _TWO_BYTE_LIMIT) {
                if (_bufferIndex + 1 >= _buffer->length()) {
                    break;
                }
                _buffer[_bufferIndex++] = 0xC0 | (rune >> 6);
                _buffer[_bufferIndex++] = 0x80 | (rune & 0x3f);
            } else {
                assert(rune <= _THREE_BYTE_LIMIT);
                if (_bufferIndex + 2 >= _buffer->length()) {
                    break;
                }
                _buffer[_bufferIndex++] = 0xE0 | (rune >> 12);
                _buffer[_bufferIndex++] = 0x80 | ((rune >> 6) & 0x3f);
                _buffer[_bufferIndex++] = 0x80 | (rune & 0x3f);
            }
        }
;
        };
        }    }
    return stringIndex;
}

void _Utf8EncoderSinkCls::close() {
    if (_carry != 0) {
        addSlice(__s(""), 0, 0, true);
        return;
    }
    _sink->close();
}

void _Utf8EncoderSinkCls::addSlice(String str, int start, int end, bool isLast) {
    _bufferIndex = 0;
    if (start == end && !isLast) {
        return;
    }
    if (_carry != 0) {
        auto nextCodeUnit = 0;
        if (start != end) {
            nextCodeUnit = str->codeUnitAt(start);
        } else {
            assert(isLast);
        }
        auto wasCombined = _writeSurrogate(_carry, nextCodeUnit);
        assert(!wasCombined || start != end);
        if (wasCombined) {
            start++;
        }
        _carry = 0;
    }
    do {
        start = _fillBuffer(str, start, end);
        auto isLastSlice = isLast && (start == end);
        if (start == end - 1 && _isLeadSurrogate(str->codeUnitAt(start))) {
            if (isLast &&  < _buffer->length() - 3) {
                _writeReplacementCharacter();
            } else {
                _carry = str->codeUnitAt(start);
            }
            start++;
        }
        _sink->addSlice(_buffer, 0, _bufferIndex, isLastSlice);
        _bufferIndex = 0;
    } while ( < end);
    if (isLast) {
        close();
    }
}

Utf8DecoderCls::Utf8DecoderCls(bool allowMalformed) {
    {
        _allowMalformed = allowMalformed;
    }
}

String Utf8DecoderCls::convert(List<int> codeUnits, int start, int end) {
    auto result = _convertIntercepted(_allowMalformed, codeUnits, start, end);
    if (result != nullptr) {
        return result;
    }
    return make<_Utf8DecoderCls>(_allowMalformed)->convertSingle(codeUnits, start, end);
}

ByteConversionSink Utf8DecoderCls::startChunkedConversion(Sink<String> sink) {
    StringConversionSink stringSink;
    if (is<StringConversionSink>(sink)) {
        stringSink = as<StringConversionSinkCls>(sink);
    } else {
        stringSink = StringConversionSinkCls->from(sink);
    }
    return stringSink->asUtf8Sink(_allowMalformed);
}

Stream<String> Utf8DecoderCls::bind(Stream<List<int>> stream) {
    return super->bind(stream);
}

bool _isLeadSurrogate(int codeUnit) {
    return (codeUnit & _SURROGATE_TAG_MASK) == _LEAD_SURROGATE_MIN;
}

bool _isTailSurrogate(int codeUnit) {
    return (codeUnit & _SURROGATE_TAG_MASK) == _TAIL_SURROGATE_MIN;
}

int _combineSurrogatePair(int lead, int tail) {
    return 0x10000 + ((lead & _SURROGATE_VALUE_MASK) << 10) | (tail & _SURROGATE_VALUE_MASK);
}
