#include "utf.hpp"
Utf8Codec::Utf8Codec(bool allowMalformed) {
    {
        _allowMalformed = allowMalformed;
    }
}

String Utf8Codec::name() {
    return "utf-8";
}

String Utf8Codec::decode(bool allowMalformed, List<int> codeUnits) {
    Utf8Decoder decoder = allowMalformed ?? _allowMalformed? const Utf8Decoder(true) : const Utf8Decoder(false);
    return decoder.convert(codeUnits);
}

Utf8Encoder Utf8Codec::encoder() {
    return const Utf8Encoder();
}

Utf8Decoder Utf8Codec::decoder() {
    return _allowMalformed? const Utf8Decoder(true) : const Utf8Decoder(false);
}

Uint8List Utf8Encoder::convert(int end, int start, String string) {
    auto stringLength = string.length;
    end = RangeError.checkValidRange(start, end, stringLength);
    auto length = end - start;
    if (length == 0)     {
        return Uint8List(0);
    }
    auto encoder = _Utf8Encoder.withBufferSize(length * 3);
    auto endPosition = encoder._fillBuffer(string, start, end);
    assert(endPosition >= end - 1);
    if (endPosition != end) {
        auto lastCodeUnit = string.codeUnitAt(end - 1);
        assert(_isLeadSurrogate(lastCodeUnit));
        encoder._writeReplacementCharacter();
    }
    return encoder._buffer.sublist(0, encoder._bufferIndex);
}

StringConversionSink Utf8Encoder::startChunkedConversion(Sink<List<int>> sink) {
    return _Utf8EncoderSink(sink is ByteConversionSink? sink : ByteConversionSink.from(sink));
}

Stream<List<int>> Utf8Encoder::bind(Stream<String> stream) {
    return super.bind(stream);
}

void _Utf8Encoder::withBufferSize(int bufferSize)

_Utf8Encoder::_Utf8Encoder() {
    {
        this.withBufferSize(_DEFAULT_BYTE_BUFFER_SIZE);
    }
}

Uint8List _Utf8Encoder::_createBuffer(int size) {
    return Uint8List(size);
}

void _Utf8Encoder::_writeReplacementCharacter() {
    _buffer[_bufferIndex++] = 0xEF;
    _buffer[_bufferIndex++] = 0xBF;
    _buffer[_bufferIndex++] = 0xBD;
}

bool _Utf8Encoder::_writeSurrogate(int leadingSurrogate, int nextCodeUnit) {
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

int _Utf8Encoder::_fillBuffer(int end, int start, String str) {
    if (start != end && _isLeadSurrogate(str.codeUnitAt(end - 1))) {
        end--;
    }
    int stringIndex;
    for (stringIndex = start;  < end; stringIndex++) {
        auto codeUnit = str.codeUnitAt(stringIndex);
        if (codeUnit <= _ONE_BYTE_LIMIT) {
            if (_bufferIndex >= _buffer.length)             {
                            break;
            }
            _buffer[_bufferIndex++] = codeUnit;
        } else         {
            if (_isLeadSurrogate(codeUnit)) {
            if (_bufferIndex + 4 > _buffer.length)             {
                            break;
            }
            auto nextCodeUnit = str.codeUnitAt(stringIndex + 1);
            auto wasCombined = _writeSurrogate(codeUnit, nextCodeUnit);
            if (wasCombined)             {
                stringIndex++;
            }
        } else         {
            if (_isTailSurrogate(codeUnit)) {
            if (_bufferIndex + 3 > _buffer.length)             {
                            break;
            }
            _writeReplacementCharacter();
        } else {
            auto rune = codeUnit;
            if (rune <= _TWO_BYTE_LIMIT) {
                if (_bufferIndex + 1 >= _buffer.length)                 {
                                    break;
                }
                _buffer[_bufferIndex++] = 0xC0 | (rune >> 6);
                _buffer[_bufferIndex++] = 0x80 | (rune & 0x3f);
            } else {
                assert(rune <= _THREE_BYTE_LIMIT);
                if (_bufferIndex + 2 >= _buffer.length)                 {
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

void _Utf8EncoderSink::close() {
    if (_carry != 0) {
        addSlice("", 0, 0, true);
        return;
    }
    _sink.close();
}

void _Utf8EncoderSink::addSlice(int end, bool isLast, int start, String str) {
    _bufferIndex = 0;
    if (start == end && !isLast) {
        return;
    }
    if (_carry != 0) {
        auto nextCodeUnit = 0;
        if (start != end) {
            nextCodeUnit = str.codeUnitAt(start);
        } else {
            assert(isLast);
        }
        auto wasCombined = _writeSurrogate(_carry, nextCodeUnit);
        assert(!wasCombined || start != end);
        if (wasCombined)         {
            start++;
        }
        _carry = 0;
    }
    do {
        start = _fillBuffer(str, start, end);
        auto isLastSlice = isLast && (start == end);
        if (start == end - 1 && _isLeadSurrogate(str.codeUnitAt(start))) {
            if (isLast &&  < _buffer.length - 3) {
                _writeReplacementCharacter();
            } else {
                _carry = str.codeUnitAt(start);
            }
            start++;
        }
        _sink.addSlice(_buffer, 0, _bufferIndex, isLastSlice);
        _bufferIndex = 0;
    } while ( < end);
    if (isLast)     {
        close();
    }
}

Utf8Decoder::Utf8Decoder(bool allowMalformed) {
    {
        _allowMalformed = allowMalformed;
    }
}

String Utf8Decoder::convert(List<int> codeUnits, int end, int start) {
    auto result = _convertIntercepted(_allowMalformed, codeUnits, start, end);
    if (result != nullptr) {
        return result;
    }
    return _Utf8Decoder(_allowMalformed).convertSingle(codeUnits, start, end);
}

ByteConversionSink Utf8Decoder::startChunkedConversion(Sink<String> sink) {
    StringConversionSink stringSink;
    if (sink is StringConversionSink) {
        stringSink = sink;
    } else {
        stringSink = StringConversionSink.from(sink);
    }
    return stringSink.asUtf8Sink(_allowMalformed);
}

Stream<String> Utf8Decoder::bind(Stream<List<int>> stream) {
    return super.bind(stream);
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

bool _Utf8Decoder::isErrorState(int state) {
    return (state & 1) != 0;
}

String _Utf8Decoder::errorDescription(int state) {
    ;
}

String _Utf8Decoder::convertGeneral(List<int> codeUnits, int maybeEnd, bool single, int start) {
    int end = RangeError.checkValidRange(start, maybeEnd, codeUnits.length);
    if (start == end)     {
        return "";
    }
    Uint8List bytes;
    int errorOffset;
    if (codeUnits is Uint8List) {
        bytes = codeUnits;
        errorOffset = 0;
    } else {
        bytes = _makeUint8List(codeUnits, start, end);
        errorOffset = start;
        end = start;
        start = 0;
    }
    String result = _convertRecursive(bytes, start, end, single);
    if (isErrorState(_state)) {
        String message = errorDescription(_state);
        _state = initial;
        ;
    }
    return result;
}

void _Utf8Decoder::flush(StringSink sink) {
    int state = _state;
    _state = initial;
    if (state <= afterBom) {
        return;
    }
    if (allowMalformed) {
        sink.writeCharCode(unicodeReplacementCharacterRune);
    } else {
        ;
    }
}

String _Utf8Decoder::decodeGeneral(Uint8List bytes, int end, bool single, int start) {
    String typeTable = _Utf8Decoder.typeTable;
    String transitionTable = _Utf8Decoder.transitionTable;
    int state = _state;
    int char = _charOrIndex;
    StringBuffer buffer = StringBuffer();
    int i = start;
    int byte = bytes[i++];
    ;
    while (true) {
        ;
        while (true) {
            int type = typeTable.codeUnitAt(byte) & typeMask;
            char = (state <= afterBom)? byte & (shiftedByteMask >> type) : (byte & 0x3F) | (char << 6);
            state = transitionTable.codeUnitAt(state + type);
            if (state == accept) {
                buffer.writeCharCode(char);
                if (i == end)                 {
                                    break loop;
                }
                                break multibyte;
            } else             {
                if (isErrorState(state)) {
                if (allowMalformed) {
                    ;
                    state = initial;
                } else {
                    _state = state;
                    _charOrIndex = i - 1;
                    return "";
                }
            }
;
            }            if (i == end)             {
                            break loop;
            }
            byte = bytes[i++];
        }
        int markStart = i;
        byte = bytes[i++];
        if ( < 128) {
            int markEnd = end;
            while ( < end) {
                byte = bytes[i++];
                if (byte >= 128) {
                    markEnd = i - 1;
                                        break;
                }
            }
            assert( < markEnd);
            if (markEnd -  < 20) {
                for (;  < markEnd; m++) {
                    buffer.writeCharCode(bytes[m]);
                }
            } else {
                buffer.write(String.fromCharCodes(bytes, markStart, markEnd));
            }
            if (markEnd == end)             {
                            break loop;
            }
        }
    }
    if (single && state > afterBom) {
        if (allowMalformed) {
            buffer.writeCharCode(unicodeReplacementCharacterRune);
        } else {
            _state = errorUnfinished;
            _charOrIndex = end;
            return "";
        }
    }
    _state = state;
    _charOrIndex = char;
    return buffer.toString();
}

String _Utf8Decoder::_convertRecursive(Uint8List bytes, int end, bool single, int start) {
    if (end - start > 1000) {
        int mid = (start + end) ~/ 2;
        String s1 = _convertRecursive(bytes, start, mid, false);
        if (isErrorState(_state))         {
            return s1;
        }
        String s2 = _convertRecursive(bytes, mid, end, single);
        return s1 + s2;
    }
    return decodeGeneral(bytes, start, end, single);
}

Uint8List _Utf8Decoder::_makeUint8List(List<int> codeUnits, int end, int start) {
    int length = end - start;
    Uint8List bytes = Uint8List(length);
    for (;  < length; i++) {
        int b = codeUnits[start + i];
        if ((b & ~0xFF) != 0) {
            b = 0xFF;
        }
        bytes[i] = b;
    }
    return bytes;
}
