#include "string_conversion.hpp"
void _ClosableStringSink::close() {
    _callback();
}

void _ClosableStringSink::writeCharCode(int charCode) {
    _sink.writeCharCode(charCode);
}

void _ClosableStringSink::write(Object o) {
    _sink.write(o);
}

void _ClosableStringSink::writeln(Object o) {
    _sink.writeln(o);
}

void _ClosableStringSink::writeAll(Iterable objects, String separator) {
    _sink.writeAll(objects, separator);
}

void _StringConversionSinkAsStringSinkAdapter::close() {
    if (_buffer.isNotEmpty)     {
        _flush();
    }
    _chunkedSink.close();
}

void _StringConversionSinkAsStringSinkAdapter::writeCharCode(int charCode) {
    _buffer.writeCharCode(charCode);
    if (_buffer.length > _MIN_STRING_SIZE)     {
        _flush();
    }
}

void _StringConversionSinkAsStringSinkAdapter::write(Object o) {
    if (_buffer.isNotEmpty)     {
        _flush();
    }
    _chunkedSink.add(o.toString());
}

void _StringConversionSinkAsStringSinkAdapter::writeln(Object o) {
    _buffer.writeln(o);
    if (_buffer.length > _MIN_STRING_SIZE)     {
        _flush();
    }
}

void _StringConversionSinkAsStringSinkAdapter::writeAll(Iterable objects, String separator) {
    if (_buffer.isNotEmpty)     {
        _flush();
    }
    auto iterator = objects.iterator;
    if (!iterator.moveNext())     {
        return;
    }
    if (separator.isEmpty) {
        do {
            _chunkedSink.add(iterator.current.toString());
        } while (iterator.moveNext());
    } else {
        _chunkedSink.add(iterator.current.toString());
        while (iterator.moveNext()) {
            write(separator);
            _chunkedSink.add(iterator.current.toString());
        }
    }
}

_StringConversionSinkAsStringSinkAdapter::_StringConversionSinkAsStringSinkAdapter(StringConversionSink _chunkedSink) {
    {
        _buffer = StringBuffer();
    }
}

void _StringConversionSinkAsStringSinkAdapter::_flush() {
    auto accumulated = _buffer.toString();
    _buffer.clear();
    _chunkedSink.add(accumulated);
}

void StringConversionSinkMixin::add(String str) {
    addSlice(str, 0, str.length, false);
}

ByteConversionSink StringConversionSinkMixin::asUtf8Sink(bool allowMalformed) {
    return _Utf8ConversionSink(this, allowMalformed);
}

ClosableStringSink StringConversionSinkMixin::asStringSink() {
    return _StringConversionSinkAsStringSinkAdapter(this);
}

void _StringSinkConversionSink::close() {
}

void _StringSinkConversionSink::addSlice(int end, bool isLast, int start, String str) {
    if (start != 0 || end != str.length) {
        for (;  < end; i++) {
            _stringSink.writeCharCode(str.codeUnitAt(i));
        }
    } else {
        _stringSink.write(str);
    }
    if (isLast)     {
        close();
    }
}

void _StringSinkConversionSink::add(String str) {
    _stringSink.write(str);
}

ByteConversionSink _StringSinkConversionSink::asUtf8Sink(bool allowMalformed) {
    return _Utf8StringSinkAdapter(this, _stringSink, allowMalformed);
}

ClosableStringSink _StringSinkConversionSink::asStringSink() {
    return ClosableStringSink.fromStringSink(_stringSink, close);
}

void _StringCallbackSink::close() {
    auto accumulated = _stringSink.toString();
    _stringSink.clear();
    _callback(accumulated);
}

ByteConversionSink _StringCallbackSink::asUtf8Sink(bool allowMalformed) {
    return _Utf8StringSinkAdapter(this, _stringSink, allowMalformed);
}

_StringCallbackSink::_StringCallbackSink(FunctionType _callback) {
    {
        super(StringBuffer());
    }
}

void _StringAdapterSink::add(String str) {
    _sink.add(str);
}

void _StringAdapterSink::addSlice(int end, bool isLast, int start, String str) {
    if (start == 0 && end == str.length) {
        add(str);
    } else {
        add(str.substring(start, end));
    }
    if (isLast)     {
        close();
    }
}

void _StringAdapterSink::close() {
    _sink.close();
}

void _Utf8StringSinkAdapter::close() {
    _decoder.flush(_stringSink);
    _sink.close();
}

void _Utf8StringSinkAdapter::add(List<int> chunk) {
    addSlice(chunk, 0, chunk.length, false);
}

void _Utf8StringSinkAdapter::addSlice(List<int> codeUnits, int endIndex, bool isLast, int startIndex) {
    _stringSink.write(_decoder.convertChunked(codeUnits, startIndex, endIndex));
    if (isLast)     {
        close();
    }
}

_Utf8StringSinkAdapter::_Utf8StringSinkAdapter(Sink<Object> _sink, StringSink _stringSink, bool allowMalformed) {
    {
        _decoder = _Utf8Decoder(allowMalformed);
    }
}

void _Utf8ConversionSink::close() {
    _decoder.flush(_buffer);
    if (_buffer.isNotEmpty) {
        auto accumulated = _buffer.toString();
        _buffer.clear();
        _chunkedSink.addSlice(accumulated, 0, accumulated.length, true);
    } else {
        _chunkedSink.close();
    }
}

void _Utf8ConversionSink::add(List<int> chunk) {
    addSlice(chunk, 0, chunk.length, false);
}

void _Utf8ConversionSink::addSlice(List<int> chunk, int endIndex, bool isLast, int startIndex) {
    _buffer.write(_decoder.convertChunked(chunk, startIndex, endIndex));
    if (_buffer.isNotEmpty) {
        auto accumulated = _buffer.toString();
        _chunkedSink.addSlice(accumulated, 0, accumulated.length, isLast);
        _buffer.clear();
        return;
    }
    if (isLast)     {
        close();
    }
}

_Utf8ConversionSink::_Utf8ConversionSink(bool allowMalformed, StringConversionSink sink) {
    {
        this._(sink, StringBuffer(), allowMalformed);
    }
}

void _Utf8ConversionSink::_(StringConversionSink _chunkedSink, bool allowMalformed, StringBuffer stringBuffer)
