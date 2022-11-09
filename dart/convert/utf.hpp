#ifndef DART_CONVERT_UTF
#define DART_CONVERT_UTF
#include <base.hpp>

#include <dart/core/core.hpp>

int unicodeReplacementCharacterRune;

int unicodeBomCharacterRune;

Utf8Codec utf8;


class Utf8CodecCls : public EncodingCls {
public:

     Utf8CodecCls(bool allowMalformed);

    virtual String name();

    virtual String decode(bool allowMalformed, List<int> codeUnits);

    virtual Utf8Encoder encoder();

    virtual Utf8Decoder decoder();

private:
    bool _allowMalformed;


};
using Utf8Codec = std::shared_ptr<Utf8CodecCls>;

class Utf8EncoderCls : public ConverterCls<String, List<int>> {
public:

     Utf8EncoderCls();
    virtual Uint8List convert(int end, int start, String stringValue);

    virtual StringConversionSink startChunkedConversion(Sink<List<int>> sink);

    virtual Stream<List<int>> bind(Stream<String> stream);

private:

};
using Utf8Encoder = std::shared_ptr<Utf8EncoderCls>;

class _Utf8EncoderCls : public ObjectCls {
public:

    virtual void  withBufferSize(int bufferSize);

private:
    int _carry;

    int _bufferIndex;

    Uint8List _buffer;

    static auto  _DEFAULT_BYTE_BUFFER_SIZE;


     _Utf8EncoderCls();

    static Uint8List _createBuffer(int size);

    virtual void _writeReplacementCharacter();

    virtual bool _writeSurrogate(int leadingSurrogate, int nextCodeUnit);

    virtual int _fillBuffer(int end, int start, String str);

};
using _Utf8Encoder = std::shared_ptr<_Utf8EncoderCls>;

class _Utf8EncoderSinkCls : public _Utf8EncoderCls {
public:

    virtual void close();

    virtual void addSlice(int end, bool isLast, int start, String str);

private:
    ByteConversionSink _sink;


     _Utf8EncoderSinkCls(ByteConversionSink _sink);
};
using _Utf8EncoderSink = std::shared_ptr<_Utf8EncoderSinkCls>;

class Utf8DecoderCls : public ConverterCls<List<int>, String> {
public:

     Utf8DecoderCls(bool allowMalformed);

    virtual String convert(List<int> codeUnits, int end, int start);

    virtual ByteConversionSink startChunkedConversion(Sink<String> sink);

    virtual Stream<String> bind(Stream<List<int>> stream);

    template<typename T>  extern Converter<List<int>, T> fuse(Converter<String, T> next) override;
private:
    bool _allowMalformed;


    extern static String _convertIntercepted(bool allowMalformed, List<int> codeUnits, int end, int start);
};
using Utf8Decoder = std::shared_ptr<Utf8DecoderCls>;
int _ONE_BYTE_LIMIT;

int _TWO_BYTE_LIMIT;

int _THREE_BYTE_LIMIT;

int _FOUR_BYTE_LIMIT;

int _SURROGATE_TAG_MASK;

int _SURROGATE_VALUE_MASK;

int _LEAD_SURROGATE_MIN;

int _TAIL_SURROGATE_MIN;

bool _isLeadSurrogate(int codeUnit);

bool _isTailSurrogate(int codeUnit);

int _combineSurrogatePair(int lead, int tail);


class _Utf8DecoderCls : public ObjectCls {
public:
    bool allowMalformed;

    static int typeMask;

    static int shiftedByteMask;

    static String typeTable;

    static int IA;

    static int BB;

    static int AB;

    static int X1;

    static int X2;

    static int X3;

    static int TO;

    static int TS;

    static int QO;

    static int QR;

    static int B1;

    static int B2;

    static int E1;

    static int E2;

    static int E3;

    static int E4;

    static int E5;

    static int E6;

    static int E7;

    static String transitionTable;

    static int initial;

    static int accept;

    static int beforeBom;

    static int afterBom;

    static int errorMissingExtension;

    static int errorUnexpectedExtension;

    static int errorInvalid;

    static int errorOverlong;

    static int errorOutOfRange;

    static int errorSurrogate;

    static int errorUnfinished;


    static bool isErrorState(int state);

    static String errorDescription(int state);

    extern String convertSingle(List<int> codeUnits, int maybeEnd, int start);
    extern String convertChunked(List<int> codeUnits, int maybeEnd, int start);
    virtual String convertGeneral(List<int> codeUnits, int maybeEnd, bool single, int start);

    virtual void flush(StringSink sink);

    virtual String decodeGeneral(Uint8List bytes, int end, bool single, int start);

private:
    int _state;

    int _charOrIndex;

    static String _IA;

    static String _BB;

    static String _AB;

    static String _X1;

    static String _X2;

    static String _X3;

    static String _TO;

    static String _TS;

    static String _QO;

    static String _QR;

    static String _B1;

    static String _B2;

    static String _E1;

    static String _E2;

    static String _E3;

    static String _E4;

    static String _E5;

    static String _E6;

    static String _E7;


    extern  _Utf8DecoderCls(bool allowMalformed);
    virtual String _convertRecursive(Uint8List bytes, int end, bool single, int start);

    static Uint8List _makeUint8List(List<int> codeUnits, int end, int start);

};
using _Utf8Decoder = std::shared_ptr<_Utf8DecoderCls>;


#endif