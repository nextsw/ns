#include "base64.hpp"
String base64Encode(List<int> bytes) {
    return base64.encode(bytes);
}

String base64UrlEncode(List<int> bytes) {
    return base64Url.encode(bytes);
}

Uint8List base64Decode(String source) {
    return base64.decode(source);
}

Base64Codec::Base64Codec() {
    {
        _encoder = const Base64Encoder();
    }
}

void Base64Codec::urlSafe()

Base64Encoder Base64Codec::encoder() {
    return _encoder;
}

Base64Decoder Base64Codec::decoder() {
    return const Base64Decoder();
}

Uint8List Base64Codec::decode(String encoded) {
    return decoder.convert(encoded);
}

String Base64Codec::normalize(int end, String source, int start) {
    end = RangeError.checkValidRange(start, end, source.length);
    const percent = 0x25;
    const equals = 0x3d;
    StringBuffer buffer;
    auto sliceStart = start;
    auto alphabet = _Base64Encoder._base64Alphabet;
    auto inverseAlphabet = _Base64Decoder._inverseAlphabet;
    auto firstPadding = -1;
    auto firstPaddingSourceIndex = -1;
    auto paddingCount = 0;
    for (;  < end; ) {
        auto sliceEnd = i;
        auto char = source.codeUnitAt(i++);
        auto originalChar = char;
        if (char == percent) {
            if (i + 2 <= end) {
                char = parseHexByte(source, i);
                i = 2;
                if (char == percent)                 {
                    char = -1;
                }
            } else {
                char = -1;
            }
        }
        if (0 <= char && char <= 127) {
            auto value = inverseAlphabet[char];
            if (value >= 0) {
                char = alphabet.codeUnitAt(value);
                if (char == originalChar)                 {
                    continue;
                }
            } else             {
                if (value == _Base64Decoder._padding) {
                if ( < 0) {
                    firstPadding = (buffer?.length ?? 0) + (sliceEnd - sliceStart);
                    firstPaddingSourceIndex = sliceEnd;
                }
                paddingCount++;
                if (originalChar == equals)                 {
                    continue;
                }
            }
;
            }            if (value != _Base64Decoder._invalid) {
                ;
                sliceStart = i;
                continue;
            }
        }
        ;
    }
    if (buffer != nullptr) {
        buffer.write(source.substring(sliceStart, end));
        if (firstPadding >= 0) {
            _checkPadding(source, firstPaddingSourceIndex, end, firstPadding, paddingCount, buffer.length);
        } else {
            auto endLength = ((buffer.length - 1) % 4) + 1;
            if (endLength == 1) {
                ;
            }
            while ( < 4) {
                buffer.write("=");
                endLength++;
            }
        }
        return source.replaceRange(start, end, buffer.toString());
    }
    auto length = end - start;
    if (firstPadding >= 0) {
        _checkPadding(source, firstPaddingSourceIndex, end, firstPadding, paddingCount, length);
    } else {
        auto endLength = length % 4;
        if (endLength == 1) {
            ;
        }
        if (endLength > 1) {
            source = source.replaceRange(end, end, (endLength == 2)? "==" : "=");
        }
    }
    return source;
}

void Base64Codec::_checkPadding(int firstPadding, int length, int paddingCount, String source, int sourceEnd, int sourceIndex) {
    if (length % 4 != 0) {
        ;
    }
    if (firstPadding + paddingCount != length) {
        ;
    }
    if (paddingCount > 2) {
        ;
    }
}

Base64Encoder::Base64Encoder() {
    {
        _urlSafe = false;
    }
}

void Base64Encoder::urlSafe()

String Base64Encoder::convert(List<int> input) {
    if (input.isEmpty)     {
        return "";
    }
    auto encoder = _Base64Encoder(_urlSafe);
    auto buffer = encoder.encode(input, 0, input.length, true)!;
    return String.fromCharCodes(buffer);
}

ByteConversionSink Base64Encoder::startChunkedConversion(Sink<String> sink) {
    if (sink is StringConversionSink) {
        return _Utf8Base64EncoderSink(sink.asUtf8Sink(false), _urlSafe);
    }
    return _AsciiBase64EncoderSink(sink, _urlSafe);
}

Uint8List _Base64Encoder::createBuffer(int bufferLength) {
    return Uint8List(bufferLength);
}

Uint8List _Base64Encoder::encode(List<int> bytes, int end, bool isLast, int start) {
    assert(0 <= start);
    assert(start <= end);
    assert(end <= bytes.length);
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

int _Base64Encoder::encodeChunk(String alphabet, List<int> bytes, int end, bool isLast, Uint8List output, int outputIndex, int start, int state) {
    auto bits = _stateBits(state);
    auto expectedChars = 3 - _stateCount(state);
    auto byteOr = 0;
    for (;  < end; i++) {
        auto byte = bytes[i];
        byteOr = byte;
        bits = ((bits << 8) | byte) & 0xFFFFFF;
        expectedChars--;
        if (expectedChars == 0) {
            output[outputIndex++] = alphabet.codeUnitAt((bits >> 18) & _sixBitMask);
            output[outputIndex++] = alphabet.codeUnitAt((bits >> 12) & _sixBitMask);
            output[outputIndex++] = alphabet.codeUnitAt((bits >> 6) & _sixBitMask);
            output[outputIndex++] = alphabet.codeUnitAt(bits & _sixBitMask);
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
    ;
}

void _Base64Encoder::writeFinalChunk(String alphabet, int bits, int count, Uint8List output, int outputIndex) {
    assert(count > 0);
    if (count == 1) {
        output[outputIndex++] = alphabet.codeUnitAt((bits >> 2) & _sixBitMask);
        output[outputIndex++] = alphabet.codeUnitAt((bits << 4) & _sixBitMask);
        output[outputIndex++] = _paddingChar;
        output[outputIndex++] = _paddingChar;
    } else {
        assert(count == 2);
        output[outputIndex++] = alphabet.codeUnitAt((bits >> 10) & _sixBitMask);
        output[outputIndex++] = alphabet.codeUnitAt((bits >> 4) & _sixBitMask);
        output[outputIndex++] = alphabet.codeUnitAt((bits << 2) & _sixBitMask);
        output[outputIndex++] = _paddingChar;
    }
}

_Base64Encoder::_Base64Encoder(bool urlSafe) {
    {
        _alphabet = urlSafe? _base64UrlAlphabet : _base64Alphabet;
    }
}

int _Base64Encoder::_encodeState(int bits, int count) {
    assert(count <= _countMask);
    return bits << _valueShift | count;
}

int _Base64Encoder::_stateBits(int state) {
    return state >> _valueShift;
}

int _Base64Encoder::_stateCount(int state) {
    return state & _countMask;
}

Uint8List _BufferCachingBase64Encoder::createBuffer(int bufferLength) {
    Uint8List buffer = bufferCache;
    if (buffer == nullptr || buffer.length < bufferLength) {
        bufferCache = buffer = Uint8List(bufferLength);
    }
    return Uint8List.view(buffer.buffer, buffer.offsetInBytes, bufferLength);
}

_BufferCachingBase64Encoder::_BufferCachingBase64Encoder(bool urlSafe) {
    {
        super(urlSafe);
    }
}

void _Base64EncoderSink::add(List<int> source) {
    _add(source, 0, source.length, false);
}

void _Base64EncoderSink::close() {
    _add(const , 0, 0, true);
}

void _Base64EncoderSink::addSlice(int end, bool isLast, List<int> source, int start) {
    if (end == nullptr)     {
        ;
    }
    RangeError.checkValidRange(start, end, source.length);
    _add(source, start, end, isLast);
}

_AsciiBase64EncoderSink::_AsciiBase64EncoderSink(Sink<String> _sink, bool urlSafe) {
    {
        _encoder = _BufferCachingBase64Encoder(urlSafe);
    }
}

void _AsciiBase64EncoderSink::_add(int end, bool isLast, List<int> source, int start) {
    auto buffer = _encoder.encode(source, start, end, isLast);
    if (buffer != nullptr) {
        auto string = String.fromCharCodes(buffer);
        _sink.add(string);
    }
    if (isLast) {
        _sink.close();
    }
}

_Utf8Base64EncoderSink::_Utf8Base64EncoderSink(ByteConversionSink _sink, bool urlSafe) {
    {
        _encoder = _Base64Encoder(urlSafe);
    }
}

void _Utf8Base64EncoderSink::_add(int end, bool isLast, List<int> source, int start) {
    auto buffer = _encoder.encode(source, start, end, isLast);
    if (buffer != nullptr) {
        _sink.addSlice(buffer, 0, buffer.length, isLast);
    }
}

Uint8List Base64Decoder::convert(int end, String input, int start) {
    end = RangeError.checkValidRange(start, end, input.length);
    if (start == end)     {
        return Uint8List(0);
    }
    auto decoder = _Base64Decoder();
    auto buffer = decoder.decode(input, start, end)!;
    decoder.close(input, end);
    return buffer;
}

StringConversionSink Base64Decoder::startChunkedConversion(Sink<List<int>> sink) {
    return _Base64DecoderSink(sink);
}

Uint8List _Base64Decoder::decode(int end, String input, int start) {
    assert(0 <= start);
    assert(start <= end);
    assert(end <= input.length);
    if (_hasSeenPadding(_state)) {
        _state = _checkPadding(input, start, end, _state);
        return nullptr;
    }
    if (start == end)     {
        return Uint8List(0);
    }
    auto buffer = _allocateBuffer(input, start, end, _state);
    _state = decodeChunk(input, start, end, buffer, 0, _state);
    return buffer;
}

void _Base64Decoder::close(int end, String input) {
    if ( < _encodePaddingState(0)) {
        ;
    }
    if (_state > 0) {
        ;
    }
    _state = _encodePaddingState(0);
}

int _Base64Decoder::decodeChunk(int end, String input, int outIndex, Uint8List output, int start, int state) {
    assert(!_hasSeenPadding(state));
    const asciiMask = 127;
    const asciiMax = 127;
    const eightBitMask = 0xFF;
    const bitsPerCharacter = 6;
    auto bits = _stateBits(state);
    auto count = _stateCount(state);
    auto charOr = 0;
    Unknown inverseAlphabet = _Base64Decoder._inverseAlphabet;
    for (;  < end; i++) {
        auto char = input.codeUnitAt(i);
        charOr = char;
        auto code = inverseAlphabet[char & asciiMask];
        if (code >= 0) {
            bits = ((bits << bitsPerCharacter) | code) & 0xFFFFFF;
            count = (count + 1) & 3;
            if (count == 0) {
                assert(outIndex + 3 <= output.length);
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
                    ;
                }
                output[outIndex++] = bits >> 10;
                output[outIndex++] = bits >> 2;
            } else {
                if ((bits & 0x0F) != 0) {
                    ;
                }
                output[outIndex++] = bits >> 4;
            }
            auto expectedPadding = (3 - count) * 3;
            if (char == _char_percent)             {
                expectedPadding = 2;
            }
            state = _encodePaddingState(expectedPadding);
            return _checkPadding(input, i + 1, end, state);
        }
;
        }        ;
    }
    if (charOr >= 0 && charOr <= asciiMax) {
        return _encodeCharacterState(count, bits);
    }
    int i;
    for (i = start;  < end; i++) {
        auto char = input.codeUnitAt(i);
        if ( < 0 || char > asciiMax)         {
                    break;
        }
    }
    ;
}

int _Base64Decoder::_encodeCharacterState(int bits, int count) {
    assert(count == (count & _countMask));
    return (bits << _valueShift | count);
}

int _Base64Decoder::_stateCount(int state) {
    assert(state >= 0);
    return state & _countMask;
}

int _Base64Decoder::_stateBits(int state) {
    assert(state >= 0);
    return state >> _valueShift;
}

int _Base64Decoder::_encodePaddingState(int expectedPadding) {
    assert(expectedPadding >= 0);
    assert(expectedPadding <= 5);
    return -expectedPadding - 1;
}

int _Base64Decoder::_statePadding(int state) {
    assert( < 0);
    return -state - 1;
}

bool _Base64Decoder::_hasSeenPadding(int state) {
    return  < 0;
}

Uint8List _Base64Decoder::_allocateBuffer(int end, String input, int start, int state) {
    assert(state >= 0);
    auto paddingStart = _trimPaddingChars(input, start, end);
    auto length = _stateCount(state) + (paddingStart - start);
    auto bufferLength = (length >> 2) * 3;
    auto remainderLength = length & 3;
    if (remainderLength != 0 &&  < end) {
        bufferLength = remainderLength - 1;
    }
    if (bufferLength > 0)     {
        return Uint8List(bufferLength);
    }
    return _emptyBuffer;
}

int _Base64Decoder::_trimPaddingChars(int end, String input, int start) {
    auto padding = 0;
    auto index = end;
    auto newEnd = end;
    while (index > start &&  < 2) {
        index--;
        auto char = input.codeUnitAt(index);
        if (char == _paddingChar) {
            padding++;
            newEnd = index;
            continue;
        }
        if ((char | 0x20) == _char_d) {
            if (index == start)             {
                            break;
            }
            index--;
            char = input.codeUnitAt(index);
        }
        if (char == _char_3) {
            if (index == start)             {
                            break;
            }
            index--;
            char = input.codeUnitAt(index);
        }
        if (char == _char_percent) {
            padding++;
            newEnd = index;
            continue;
        }
                break;
    }
    return newEnd;
}

int _Base64Decoder::_checkPadding(int end, String input, int start, int state) {
    assert(_hasSeenPadding(state));
    if (start == end)     {
        return state;
    }
    auto expectedPadding = _statePadding(state);
    assert(expectedPadding >= 0);
    assert( < 6);
    while (expectedPadding > 0) {
        auto char = input.codeUnitAt(start);
        if (expectedPadding == 3) {
            if (char == _paddingChar) {
                expectedPadding = 3;
                start++;
                                break;
            }
            if (char == _char_percent) {
                expectedPadding--;
                start++;
                if (start == end)                 {
                                    break;
                }
                char = input.codeUnitAt(start);
            } else {
                                break;
            }
        }
        auto expectedPartialPadding = expectedPadding;
        if (expectedPartialPadding > 3)         {
            expectedPartialPadding = 3;
        }
        if (expectedPartialPadding == 2) {
            if (char != _char_3)             {
                            break;
            }
            start++;
            expectedPadding--;
            if (start == end)             {
                            break;
            }
            char = input.codeUnitAt(start);
        }
        if ((char | 0x20) != _char_d)         {
                    break;
        }
        start++;
        expectedPadding--;
        if (start == end)         {
                    break;
        }
    }
    if (start != end) {
        ;
    }
    return _encodePaddingState(expectedPadding);
}

void _Base64DecoderSink::add(String string) {
    if (string.isEmpty)     {
        return;
    }
    auto buffer = _decoder.decode(string, 0, string.length);
    if (buffer != nullptr)     {
        _sink.add(buffer);
    }
}

void _Base64DecoderSink::close() {
    _decoder.close(nullptr, nullptr);
    _sink.close();
}

void _Base64DecoderSink::addSlice(int end, bool isLast, int start, String string) {
    RangeError.checkValidRange(start, end, string.length);
    if (start == end)     {
        return;
    }
    auto buffer = _decoder.decode(string, start, end);
    if (buffer != nullptr)     {
        _sink.add(buffer);
    }
    if (isLast) {
        _decoder.close(string, end);
        _sink.close();
    }
}
