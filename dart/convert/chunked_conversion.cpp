#include "chunked_conversion.hpp"
void _SimpleCallbackSink::add(T chunk) {
    _accumulated.add(chunk);
}

void _SimpleCallbackSink::close() {
    _callback(_accumulated);
}

void _ConverterStreamEventSink::add(S o) {
    _chunkedSink.add(o);
}

void _ConverterStreamEventSink::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    _eventSink.addError(error, stackTrace);
}

void _ConverterStreamEventSink::close() {
    _chunkedSink.close();
}

_ConverterStreamEventSink::_ConverterStreamEventSink(Converter<S, T> converter, EventSink<T> sink) {
    {
        _eventSink = sink;
        _chunkedSink = converter.startChunkedConversion(sink);
    }
}
