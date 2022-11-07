#ifndef UTF_H
#define UTF_H
#include <memory>



const int unicodeReplacementCharacterRune;

const int unicodeBomCharacterRune;

const Utf8Codec utf8;


class Utf8Codec : Encoding {
public:

     Utf8Codec(bool allowMalformed);

    String name();

    String decode(bool allowMalformed, List<int> codeUnits);

    Utf8Encoder encoder();

    Utf8Decoder decoder();

private:
    bool _allowMalformed;


};

class Utf8Encoder : Converter<String, List<int>> {
public:

     Utf8Encoder();

    Uint8List convert(int end, int start, String string);

    StringConversionSink startChunkedConversion(Sink<List<int>> sink);

    Stream<List<int>> bind(Stream<String> stream);

private:

};

class _Utf8Encoder {
public:

    void  withBufferSize(int bufferSize);

private:
    int _carry;

    int _bufferIndex;

    Uint8List _buffer;

    static const auto  _DEFAULT_BYTE_BUFFER_SIZE;


     _Utf8Encoder();

    static Uint8List _createBuffer(int size);

    void _writeReplacementCharacter();

    bool _writeSurrogate(int leadingSurrogate, int nextCodeUnit);

    int _fillBuffer(int end, int start, String str);

};

class _Utf8EncoderSink : _Utf8Encoder {
public:

    void close();

    void addSlice(int end, bool isLast, int start, String str);

private:
    ByteConversionSink _sink;


     _Utf8EncoderSink(ByteConversionSink _sink);

};

class Utf8Decoder : Converter<List<int>, String> {
public:

     Utf8Decoder(bool allowMalformed);

    String convert(List<int> codeUnits, int end, int start);

    ByteConversionSink startChunkedConversion(Sink<String> sink);

    Stream<String> bind(Stream<List<int>> stream);

    external Converter<List<int>, T> fuse<T>(Converter<String, T> next);

private:
    bool _allowMalformed;


    external static String _convertIntercepted(bool allowMalformed, List<int> codeUnits, int end, int start);

};
const int _ONE_BYTE_LIMIT;

const int _TWO_BYTE_LIMIT;

const int _THREE_BYTE_LIMIT;

const int _FOUR_BYTE_LIMIT;

const int _SURROGATE_TAG_MASK;

const int _SURROGATE_VALUE_MASK;

const int _LEAD_SURROGATE_MIN;

const int _TAIL_SURROGATE_MIN;

bool _isLeadSurrogate(int codeUnit);

bool _isTailSurrogate(int codeUnit);

int _combineSurrogatePair(int lead, int tail);


class _Utf8Decoder {
public:
    bool allowMalformed;

    static const int typeMask;

    static const int shiftedByteMask;

    static const String typeTable;

    static const int IA;

    static const int BB;

    static const int AB;

    static const int X1;

    static const int X2;

    static const int X3;

    static const int TO;

    static const int TS;

    static const int QO;

    static const int QR;

    static const int B1;

    static const int B2;

    static const int E1;

    static const int E2;

    static const int E3;

    static const int E4;

    static const int E5;

    static const int E6;

    static const int E7;

    static const String transitionTable;

    static const int initial;

    static const int accept;

    static const int beforeBom;

    static const int afterBom;

    static const int errorMissingExtension;

    static const int errorUnexpectedExtension;

    static const int errorInvalid;

    static const int errorOverlong;

    static const int errorOutOfRange;

    static const int errorSurrogate;

    static const int errorUnfinished;


    static bool isErrorState(int state);

    static String errorDescription(int state);

    external String convertSingle(List<int> codeUnits, int maybeEnd, int start);

    external String convertChunked(List<int> codeUnits, int maybeEnd, int start);

    String convertGeneral(List<int> codeUnits, int maybeEnd, bool single, int start);

    void flush(StringSink sink);

    String decodeGeneral(Uint8List bytes, int end, bool single, int start);

private:
    int _state;

    int _charOrIndex;

    static const String _IA;

    static const String _BB;

    static const String _AB;

    static const String _X1;

    static const String _X2;

    static const String _X3;

    static const String _TO;

    static const String _TS;

    static const String _QO;

    static const String _QR;

    static const String _B1;

    static const String _B2;

    static const String _E1;

    static const String _E2;

    static const String _E3;

    static const String _E4;

    static const String _E5;

    static const String _E6;

    static const String _E7;


    external  _Utf8Decoder(bool allowMalformed);

    String _convertRecursive(Uint8List bytes, int end, bool single, int start);

    static Uint8List _makeUint8List(List<int> codeUnits, int end, int start);

};

#endif