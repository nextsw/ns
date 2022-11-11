#include "base64.hpp"
String base64Encode(List<int> bytes) {
    return base64->encode(bytes);
}

String base64UrlEncode(List<int> bytes) {
    return base64Url->encode(bytes);
}

Uint8List base64Decode(String source) {
    return base64->decode(source);
}

Base64CodecCls::Base64CodecCls() {
    {
        _encoder = make<Base64EncoderCls>();
    }
}

void Base64CodecCls::urlSafe()

Base64Encoder Base64CodecCls::encoder() {
    return _encoder;
}

Base64Decoder Base64CodecCls::decoder() {
    return make<Base64DecoderCls>();
}

Uint8List Base64CodecCls::decode(String encoded) {
    return decoder()->convert(encoded);
}

String Base64CodecCls::normalize(int end, String source, int start) {
    end = RangeErrorCls->checkValidRange(start, end, source->length());
    percent = 0x25;
    equals = 0x3d;
    StringBuffer buffer;
    auto sliceStart = start;
    auto alphabet = _Base64EncoderCls::_base64Alphabet;
    auto inverseAlphabet = _Base64DecoderCls::_inverseAlphabet;
    auto firstPadding = -1;
    auto firstPaddingSourceIndex = -1;
    auto paddingCount = 0;
    for (;  < end; ) {
        auto sliceEnd = i;
        auto char = source->codeUnitAt(i++);
        auto originalChar = charValue;
        if (charValue == percent) {
            if (i + 2 <= end) {
                charValue = parseHexByte(source, i);
                i = 2;
                if (charValue == percent)                 {
                    charValue = -1;
                }
            } else {
                charValue = -1;
            }
        }
        if (0 <= charValue && charValue <= 127) {
            auto value = inverseAlphabet[charValue];
            if (value >= 0) {
                charValue = alphabet->codeUnitAt(value);
                if (charValue == originalChar)                 {
                    continue;
                }
            } else             {
                if (value == _Base64DecoderCls::_padding) {
                if ( < 0) {
                    firstPadding = (buffer?->length() or 0) + (sliceEnd - sliceStart);
                    firstPaddingSourceIndex = sliceEnd;
                }
                paddingCount++;
                if (originalChar == equals)                 {
                    continue;
                }
            }
;
            }            if (value != _Base64DecoderCls::_invalid) {
                            auto _c1 = (buffer ??= make<StringBufferCls>());            _c1.auto _c2 = write(source->substring(sliceStart, sliceEnd));            _c2.writeCharCode(charValue);            _c2;_c1;
                sliceStart = i;
                continue;
            }
        }
        throw make<FormatExceptionCls>(__s("Invalid base64 data"), source, sliceEnd);
    }
    if (buffer != nullptr) {
        buffer->write(source->substring(sliceStart, end));
        if (firstPadding >= 0) {
            _checkPadding(source, firstPaddingSourceIndex, end, firstPadding, paddingCount, buffer->length());
        } else {
            auto endLength = ((buffer->length() - 1) % 4) + 1;
            if (endLength == 1) {
                throw make<FormatExceptionCls>(__s("Invalid base64 encoding length "), source, end);
            }
            while ( < 4) {
                buffer->write(__s("="));
                endLength++;
            }
        }
        return source->replaceRange(start, end, buffer->toString());
    }
    auto length = end - start;
    if (firstPadding >= 0) {
        _checkPadding(source, firstPaddingSourceIndex, end, firstPadding, paddingCount, length);
    } else {
        auto endLength = length % 4;
        if (endLength == 1) {
            throw make<FormatExceptionCls>(__s("Invalid base64 encoding length "), source, end);
        }
        if (endLength > 1) {
            source = source->replaceRange(end, end, (endLength == 2)? __s("==") : __s("="));
        }
    }
    return source;
}

void Base64CodecCls::_checkPadding(int firstPadding, int length, int paddingCount, String source, int sourceEnd, int sourceIndex) {
    if (length % 4 != 0) {
        throw make<FormatExceptionCls>(__s("Invalid base64 padding, padded length must be multiple of four, is $length"), source, sourceEnd);
    }
    if (firstPadding + paddingCount != length) {
        throw make<FormatExceptionCls>(__s("Invalid base64 padding, '=' not at the end"), source, sourceIndex);
    }
    if (paddingCount > 2) {
        throw make<FormatExceptionCls>(__s("Invalid base64 padding, more than two '=' characters"), source, sourceIndex);
    }
}

Base64EncoderCls::Base64EncoderCls() {
    {
        _urlSafe = false;
    }
}

void Base64EncoderCls::urlSafe()

String Base64EncoderCls::convert(List<int> input) {
    if (input->isEmpty)     {
        return __s("");
    }
    auto encoder = make<_Base64EncoderCls>(_urlSafe);
    auto buffer = encoder->encode(input, 0, input->length(), true)!;
    return StringCls->fromCharCodes(buffer);
}

ByteConversionSink Base64EncoderCls::startChunkedConversion(Sink<String> sink) {
    if (is<StringConversionSink>(sink)) {
        return make<_Utf8Base64EncoderSinkCls>(as<StringConversionSinkCls>(sink)->asUtf8Sink(false), _urlSafe);
    }
    return make<_AsciiBase64EncoderSinkCls>(sink, _urlSafe);
}

Uint8List _Base64EncoderCls::createBuffer(int bufferLength) {
    return make<Uint8ListCls>(bufferLength);
}

Uint8List _Base64EncoderCls::encode(List<int> bytes, int end, bool isLast, int start) {
    assert(0 <= start);
    assert(start <= end);
    assert(end <= bytes->length());
    auto length = end - start;
    auto count = _stateCount(_state);
    auto byteCount = (count + length);
    auto fullChunks = byteCount ~/ 3;
    auto partialChunkLength = byteCount - fullChunks * 3;
    auto bufferLength = fullChunks * 4;
    if (isLast && partialChunkLength > 0) {
        bufferLength = 4;
    }
    auto output = createBuffer(bufferLength);
    _state = encodeChunk(_alphabet, bytes, start, end, isLast, output, 0, _state);
    if (bufferLength > 0)     {
        return output;
    }
    return nullptr;
}

int _Base64EncoderCls::encodeChunk(String alphabet, List<int> bytes, int end, bool isLast, Uint8List output, int outputIndex, int start, int state) {
    auto bits = _stateBits(state);
    auto expectedChars = 3 - _stateCount(state);
    auto byteOr = 0;
    for (;  < end; i++) {
        auto byte = bytes[i];
        byteOr = byte;
        bits = ((bits << 8) | byte) & 0xFFFFFF;
        expectedChars--;
        if (expectedChars == 0) {
            output[outputIndex++] = alphabet->codeUnitAt((bits >> 18) & _sixBitMask);
            output[outputIndex++] = alphabet->codeUnitAt((bits >> 12) & _sixBitMask);
            output[outputIndex++] = alphabet->codeUnitAt((bits >> 6) & _sixBitMask);
            output[outputIndex++] = alphabet->codeUnitAt(bits & _sixBitMask);
            expectedChars = 3;
            bits = 0;
        }
    }
    if (byteOr >= 0 && byteOr <= 255) {
        if (isLast &&  < 3) {
            writeFinalChunk(alphabet, output, outputIndex, 3 - expectedChars, bits);
            return 0;
        }
        return _encodeState(3 - expectedChars, bits);
    }
    auto i = start;
    while ( < end) {
        auto byte = bytes[i];
        if ( < 0 || byte > 255)         {
            break;
        }
        i++;
    }
    throw ArgumentErrorCls->value(bytes, __s("Not a byte value at index $i: 0x${bytes[i].toRadixString(16)}"));
}

void _Base64EncoderCls::writeFinalChunk(String alphabet, int bits, int count, Uint8List output, int outputIndex) {
    assert(count > 0);
    if (count == 1) {
        output[outputIndex++] = alphabet->codeUnitAt((bits >> 2) & _sixBitMask);
        output[outputIndex++] = alphabet->codeUnitAt((bits << 4) & _sixBitMask);
        output[outputIndex++] = _paddingChar;
        output[outputIndex++] = _paddingChar;
    } else {
        assert(count == 2);
        output[outputIndex++] = alphabet->codeUnitAt((bits >> 10) & _sixBitMask);
        output[outputIndex++] = alphabet->codeUnitAt((bits >> 4) & _sixBitMask);
        output[outputIndex++] = alphabet->codeUnitAt((bits << 2) & _sixBitMask);
        output[outputIndex++] = _paddingChar;
    }
}

_Base64EncoderCls::_Base64EncoderCls(bool urlSafe) {
    {
        _alphabet = urlSafe? _base64UrlAlphabet : _base64Alphabet;
    }
}

int _Base64EncoderCls::_encodeState(int bits, int count) {
    assert(count <= _countMask);
    return bits << _valueShift | count;
}

int _Base64EncoderCls::_stateBits(int state) {
    return state >> _valueShift;
}

int _Base64EncoderCls::_stateCount(int state) {
    return state & _countMask;
}

Uint8List _BufferCachingBase64EncoderCls::createBuffer(int bufferLength) {
    Uint8List buffer = bufferCache;
    if (buffer == nullptr || buffer->length < bufferLength) {
        bufferCache = buffer = make<Uint8ListCls>(bufferLength);
    }
    return Uint8ListCls->view(buffer->buffer, buffer->offsetInBytes, bufferLength);
}

_BufferCachingBase64EncoderCls::_BufferCachingBase64EncoderCls(bool urlSafe) : _Base64Encoder(urlSafe) {
}

void _Base64EncoderSinkCls::add(List<int> source) {
    _add(source, 0, source->length(), false);
}

void _Base64EncoderSinkCls::close() {
    _add(makeList(), 0, 0, true);
}

void _Base64EncoderSinkCls::addSlice(int end, bool isLast, List<int> source, int start) {
    if (end == nullptr)     {
        throw ArgumentErrorCls->notNull(__s("end"));
    }
    RangeErrorCls->checkValidRange(start, end, source->length());
    _add(source, start, end, isLast);
}

_AsciiBase64EncoderSinkCls::_AsciiBase64EncoderSinkCls(Sink<String> _sink, bool urlSafe) {
    {
        _encoder = make<_BufferCachingBase64EncoderCls>(urlSafe);
    }
}

void _AsciiBase64EncoderSinkCls::_add(int end, bool isLast, List<int> source, int start) {
    auto buffer = _encoder->encode(source, start, end, isLast);
    if (buffer != nullptr) {
        auto string = StringCls->fromCharCodes(buffer);
        _sink->add(stringValue);
    }
    if (isLast) {
        _sink->close();
    }
}

_Utf8Base64EncoderSinkCls::_Utf8Base64EncoderSinkCls(ByteConversionSink _sink, bool urlSafe) {
    {
        _encoder = make<_Base64EncoderCls>(urlSafe);
    }
}

void _Utf8Base64EncoderSinkCls::_add(int end, bool isLast, List<int> source, int start) {
    auto buffer = _encoder->encode(source, start, end, isLast);
    if (buffer != nullptr) {
        _sink->addSlice(buffer, 0, buffer->length, isLast);
    }
}

Uint8List Base64DecoderCls::convert(int end, String input, int start) {
    end = RangeErrorCls->checkValidRange(start, end, input->length());
    if (start == end)     {
        return make<Uint8ListCls>(0);
    }
    auto decoder = make<_Base64DecoderCls>();
    auto buffer = decoder->decode(input, start, end)!;
    decoder->close(input, end);
    return buffer;
}

StringConversionSink Base64DecoderCls::startChunkedConversion(Sink<List<int>> sink) {
    return make<_Base64DecoderSinkCls>(sink);
}

Uint8List _Base64DecoderCls::decode(int end, String input, int start) {
    assert(0 <= start);
    assert(start <= end);
    assert(end <= input->length());
    if (_hasSeenPadding(_state)) {
        _state = _checkPadding(input, start, end, _state);
        return nullptr;
    }
    if (start == end)     {
        return make<Uint8ListCls>(0);
    }
    auto buffer = _allocateBuffer(input, start, end, _state);
    _state = decodeChunk(input, start, end, buffer, 0, _state);
    return buffer;
}

void _Base64DecoderCls::close(int end, String input) {
    if ( < _encodePaddingState(0)) {
        throw make<FormatExceptionCls>(__s("Missing padding character"), input, end);
    }
    if (_state > 0) {
        throw make<FormatExceptionCls>(__s("Invalid length, must be multiple of four"), input, end);
    }
    _state = _encodePaddingState(0);
}

int _Base64DecoderCls::decodeChunk(int end, String input, int outIndex, Uint8List output, int start, int state) {
    assert(!_hasSeenPadding(state));
    asciiMask = 127;
    asciiMax = 127;
    eightBitMask = 0xFF;
    bitsPerCharacter = 6;
    auto bits = _stateBits(state);
    auto count = _stateCount(state);
    auto charOr = 0;
    Unknown inverseAlphabet = _Base64DecoderCls::_inverseAlphabet;
    for (;  < end; i++) {
        auto char = input->codeUnitAt(i);
        charOr = charValue;
        auto code = inverseAlphabet[charValue & asciiMask];
        if (code >= 0) {
            bits = ((bits << bitsPerCharacter) | code) & 0xFFFFFF;
            count = (count + 1) & 3;
            if (count == 0) {
                assert(outIndex + 3 <= output->length);
                output[outIndex++] = (bits >> 16) & eightBitMask;
                output[outIndex++] = (bits >> 8) & eightBitMask;
                output[outIndex++] = bits & eightBitMask;
                bits = 0;
            }
            continue;
        } else         {
            if (code == _padding && count > 1) {
            if ( < 0 || charOr > asciiMax)             {
                break;
            }
            if (count == 3) {
                if ((bits & 0x03) != 0) {
                    throw make<FormatExceptionCls>(__s("Invalid encoding before padding"), input, i);
                }
                output[outIndex++] = bits >> 10;
                output[outIndex++] = bits >> 2;
            } else {
                if ((bits & 0x0F) != 0) {
                    throw make<FormatExceptionCls>(__s("Invalid encoding before padding"), input, i);
                }
                output[outIndex++] = bits >> 4;
            }
            auto expectedPadding = (3 - count) * 3;
            if (charValue == _char_percent)             {
                expectedPadding = 2;
            }
            state = _encodePaddingState(expectedPadding);
            return _checkPadding(input, i + 1, end, state);
        }
;
        }        throw make<FormatExceptionCls>(__s("Invalid character"), input, i);
    }
    if (charOr >= 0 && charOr <= asciiMax) {
        return _encodeCharacterState(count, bits);
    }
    int i;
    for (i = start;  < end; i++) {
        auto char = input->codeUnitAt(i);
        if ( < 0 || charValue > asciiMax)         {
            break;
        }
    }
    throw make<FormatExceptionCls>(__s("Invalid character"), input, i);
}

int _Base64DecoderCls::_encodeCharacterState(int bits, int count) {
    assert(count == (count & _countMask));
    return (bits << _valueShift | count);
}

int _Base64DecoderCls::_stateCount(int state) {
    assert(state >= 0);
    return state & _countMask;
}

int _Base64DecoderCls::_stateBits(int state) {
    assert(state >= 0);
    return state >> _valueShift;
}

int _Base64DecoderCls::_encodePaddingState(int expectedPadding) {
    assert(expectedPadding >= 0);
    assert(expectedPadding <= 5);
    return -expectedPadding - 1;
}

int _Base64DecoderCls::_statePadding(int state) {
    assert( < 0);
    return -state - 1;
}

bool _Base64DecoderCls::_hasSeenPadding(int state) {
    return  < 0;
}

Uint8List _Base64DecoderCls::_allocateBuffer(int end, String input, int start, int state) {
    assert(state >= 0);
    auto paddingStart = _trimPaddingChars(input, start, end);
    auto length = _stateCount(state) + (paddingStart - start);
    auto bufferLength = (length >> 2) * 3;
    auto remainderLength = length & 3;
    if (remainderLength != 0 &&  < end) {
        bufferLength = remainderLength - 1;
    }
    if (bufferLength > 0)     {
        return make<Uint8ListCls>(bufferLength);
    }
    return _emptyBuffer;
}

int _Base64DecoderCls::_trimPaddingChars(int end, String input, int start) {
    auto padding = 0;
    auto index = end;
    auto newEnd = end;
    while (index > start &&  < 2) {
        index--;
        auto char = input->codeUnitAt(index);
        if (charValue == _paddingChar) {
            padding++;
            newEnd = index;
            continue;
        }
        if ((charValue | 0x20) == _char_d) {
            if (index == start)             {
                break;
            }
            index--;
            charValue = input->codeUnitAt(index);
        }
        if (charValue == _char_3) {
            if (index == start)             {
                break;
            }
            index--;
            charValue = input->codeUnitAt(index);
        }
        if (charValue == _char_percent) {
            padding++;
            newEnd = index;
            continue;
        }
        break;
    }
    return newEnd;
}

int _Base64DecoderCls::_checkPadding(int end, String input, int start, int state) {
    assert(_hasSeenPadding(state));
    if (start == end)     {
        return state;
    }
    auto expectedPadding = _statePadding(state);
    assert(expectedPadding >= 0);
    assert( < 6);
    while (expectedPadding > 0) {
        auto char = input->codeUnitAt(start);
        if (expectedPadding == 3) {
            if (charValue == _paddingChar) {
                expectedPadding = 3;
                start++;
                break;
            }
            if (charValue == _char_percent) {
                expectedPadding--;
                start++;
                if (start == end)                 {
                    break;
                }
                charValue = input->codeUnitAt(start);
            } else {
                break;
            }
        }
        auto expectedPartialPadding = expectedPadding;
        if (expectedPartialPadding > 3)         {
            expectedPartialPadding = 3;
        }
        if (expectedPartialPadding == 2) {
            if (charValue != _char_3)             {
                break;
            }
            start++;
            expectedPadding--;
            if (start == end)             {
                break;
            }
            charValue = input->codeUnitAt(start);
        }
        if ((charValue | 0x20) != _char_d)         {
            break;
        }
        start++;
        expectedPadding--;
        if (start == end)         {
            break;
        }
    }
    if (start != end) {
        throw make<FormatExceptionCls>(__s("Invalid padding character"), input, start);
    }
    return _encodePaddingState(expectedPadding);
}

void _Base64DecoderSinkCls::add(String stringValue) {
    if (stringValue->isEmpty())     {
        return;
    }
    auto buffer = _decoder->decode(stringValue, 0, stringValue->length());
    if (buffer != nullptr)     {
        _sink->add(buffer);
    }
}

void _Base64DecoderSinkCls::close() {
    _decoder->close(nullptr, nullptr);
    _sink->close();
}

void _Base64DecoderSinkCls::addSlice(int end, bool isLast, int start, String stringValue) {
    RangeErrorCls->checkValidRange(start, end, stringValue->length());
    if (start == end)     {
        return;
    }
    auto buffer = _decoder->decode(stringValue, start, end);
    if (buffer != nullptr)     {
        _sink->add(buffer);
    }
    if (isLast) {
        _decoder->close(stringValue, end);
        _sink->close();
    }
}
