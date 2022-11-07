#include "html_escape.hpp"
HtmlEscapeMode::HtmlEscapeMode(bool escapeApos, bool escapeLtGt, bool escapeQuot, bool escapeSlash, String name) {
    {
        _name = name;
    }
}

String HtmlEscapeMode::toString() {
    return _name;
}

String HtmlEscape::convert(String text) {
    auto val = _convert(text, 0, text.length);
    return val == nullptr? text : val;
}

StringConversionSink HtmlEscape::startChunkedConversion(Sink<String> sink) {
    return _HtmlEscapeSink(this, sink is StringConversionSink? sink : StringConversionSink.from(sink));
}

String HtmlEscape::_convert(int end, int start, String text) {
    StringBuffer result;
    for (;  < end; i++) {
        auto ch = text[i];
        String replacement;
        ;
        if (replacement != nullptr) {
            result = StringBuffer();
            if (i > start)             {
                result.write(text.substring(start, i));
            }
            result.write(replacement);
            start = i + 1;
        }
    }
    if (result == nullptr)     {
        return nullptr;
    }
    if (end > start)     {
        result.write(text.substring(start, end));
    }
    return result.toString();
}

void _HtmlEscapeSink::addSlice(String chunk, int end, bool isLast, int start) {
    auto val = _escape._convert(chunk, start, end);
    if (val == nullptr) {
        _sink.addSlice(chunk, start, end, isLast);
    } else {
        _sink.add(val);
        if (isLast)         {
            _sink.close();
        }
    }
}

void _HtmlEscapeSink::close() {
    _sink.close();
}
