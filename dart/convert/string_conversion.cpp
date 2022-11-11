#include "string_conversion.hpp"
void _ClosableStringSinkCls::close() {
    _callback();
}

void _ClosableStringSinkCls::writeCharCode(int charCode) {
    _sink->writeCharCode(charCode);
}

void _ClosableStringSinkCls::write(Object o) {
    _sink->write(o);
}

void _ClosableStringSinkCls::writeln(Object o) {
    _sink->writeln(o);
}

void _ClosableStringSinkCls::writeAll(Iterable objects, String separator) {
    _sink->writeAll(objects, separator);
}

void _StringConversionSinkAsStringSinkAdapterCls::close() {
    if (_buffer->isNotEmpty())     {
        _flush();
    }
    _chunkedSink->close();
}

void _StringConversionSinkAsStringSinkAdapterCls::writeCharCode(int charCode) {
    _buffer->writeCharCode(charCode);
    if (_buffer->length() > _MIN_STRING_SIZE)     {
        _flush();
    }
}

void _StringConversionSinkAsStringSinkAdapterCls::write(Object o) {
    if (_buffer->isNotEmpty())     {
        _flush();
    }
    _chunkedSink->add(o->toString());
}

void _StringConversionSinkAsStringSinkAdapterCls::writeln(Object o) {
    _buffer->writeln(o);
    if (_buffer->length() > _MIN_STRING_SIZE)     {
        _flush();
    }
}

void _StringConversionSinkAsStringSinkAdapterCls::writeAll(Iterable objects, String separator) {
    if (_buffer->isNotEmpty())     {
        _flush();
    }
    auto iterator = objects->iterator();
    if (!iterator->moveNext())     {
        return;
    }
    if (separator->isEmpty()) {
        do {
            _chunkedSink->add(iterator->current()->toString());
        } while (iterator->moveNext());
    } else {
        _chunkedSink->add(iterator->current()->toString());
        while (iterator->moveNext()) {
            write(separator);
            _chunkedSink->add(iterator->current()->toString());
        }
    }
}

_StringConversionSinkAsStringSinkAdapterCls::_StringConversionSinkAsStringSinkAdapterCls(StringConversionSink _chunkedSink) {
    {
        _buffer = make<StringBufferCls>();
    }
}

void _StringConversionSinkAsStringSinkAdapterCls::_flush() {
    auto accumulated = _buffer->toString();
    _buffer->clear();
    _chunkedSink->add(accumulated);
}

void StringConversionSinkMixinCls::add(String str) {
    addSlice(str, 0, str->length(), false);
}

ByteConversionSink StringConversionSinkMixinCls::asUtf8Sink(bool allowMalformed) {
    return make<_Utf8ConversionSinkCls>(this, allowMalformed);
}

ClosableStringSink StringConversionSinkMixinCls::asStringSink() {
    return make<_StringConversionSinkAsStringSinkAdapterCls>(this);
}

template<typename TStringSink>
void _StringSinkConversionSinkCls<TStringSink>::close() {
}

template<typename TStringSink>
void _StringSinkConversionSinkCls<TStringSink>::addSlice(int end, bool isLast, int start, String str) {
    if (start != 0 || end != str->length()) {
        for (;  < end; i++) {
            _stringSink->writeCharCode(str->codeUnitAt(i));
        }
    } else {
        _stringSink->write(str);
    }
    if (isLast)     {
        close();
    }
}

template<typename TStringSink>
void _StringSinkConversionSinkCls<TStringSink>::add(String str) {
    _stringSink->write(str);
}

template<typename TStringSink>
ByteConversionSink _StringSinkConversionSinkCls<TStringSink>::asUtf8Sink(bool allowMalformed) {
    return make<_Utf8StringSinkAdapterCls>(this, _stringSink, allowMalformed);
}

template<typename TStringSink>
ClosableStringSink _StringSinkConversionSinkCls<TStringSink>::asStringSink() {
    return ClosableStringSinkCls->fromStringSink(_stringSink, close);
}

void _StringCallbackSinkCls::close() {
    auto accumulated = _stringSink->toString();
    _stringSink->clear();
    _callback(accumulated);
}

ByteConversionSink _StringCallbackSinkCls::asUtf8Sink(bool allowMalformed) {
    return make<_Utf8StringSinkAdapterCls>(this, _stringSink, allowMalformed);
}

_StringCallbackSinkCls::_StringCallbackSinkCls(std::function<void(String )> _callback) : _StringSinkConversionSink<StringBuffer>(make<StringBufferCls>()) {
}

void _StringAdapterSinkCls::add(String str) {
    _sink->add(str);
}

void _StringAdapterSinkCls::addSlice(int end, bool isLast, int start, String str) {
    if (start == 0 && end == str->length()) {
        add(str);
    } else {
        add(str->substring(start, end));
    }
    if (isLast)     {
        close();
    }
}

void _StringAdapterSinkCls::close() {
    _sink->close();
}

void _Utf8StringSinkAdapterCls::close() {
    _decoder->flush(_stringSink);
    _sink->close();
}

void _Utf8StringSinkAdapterCls::add(List<int> chunk) {
    addSlice(chunk, 0, chunk->length(), false);
}

void _Utf8StringSinkAdapterCls::addSlice(List<int> codeUnits, int endIndex, bool isLast, int startIndex) {
    _stringSink->write(_decoder->convertChunked(codeUnits, startIndex, endIndex));
    if (isLast)     {
        close();
    }
}

_Utf8StringSinkAdapterCls::_Utf8StringSinkAdapterCls(Sink<Object> _sink, StringSink _stringSink, bool allowMalformed) {
    {
        _decoder = make<_Utf8DecoderCls>(allowMalformed);
    }
}

void _Utf8ConversionSinkCls::close() {
    _decoder->flush(_buffer);
    if (_buffer->isNotEmpty()) {
        auto accumulated = _buffer->toString();
        _buffer->clear();
        _chunkedSink->addSlice(accumulated, 0, accumulated->length(), true);
    } else {
        _chunkedSink->close();
    }
}

void _Utf8ConversionSinkCls::add(List<int> chunk) {
    addSlice(chunk, 0, chunk->length(), false);
}

void _Utf8ConversionSinkCls::addSlice(List<int> chunk, int endIndex, bool isLast, int startIndex) {
    _buffer->write(_decoder->convertChunked(chunk, startIndex, endIndex));
    if (_buffer->isNotEmpty()) {
        auto accumulated = _buffer->toString();
        _chunkedSink->addSlice(accumulated, 0, accumulated->length(), isLast);
        _buffer->clear();
        return;
    }
    if (isLast)     {
        close();
    }
}

_Utf8ConversionSinkCls::_Utf8ConversionSinkCls(bool allowMalformed, StringConversionSink sink) {
    {
        this->_(sink, make<StringBufferCls>(), allowMalformed);
    }
}

void _Utf8ConversionSinkCls::_(StringConversionSink _chunkedSink, bool allowMalformed, StringBuffer stringBuffer)
