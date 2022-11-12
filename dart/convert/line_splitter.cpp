#include "line_splitter.hpp"
Iterable<String> LineSplitterCls::split(String lines, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, lines->length());
    auto sliceStart = start;
    auto char = 0;
    for (;  < end; i++) {
        auto previousChar = charValue;
        charValue = lines->codeUnitAt(i);
        if (charValue != _CR) {
            if (charValue != _LF) {
                continue;
            }
            if (previousChar == _CR) {
                sliceStart = i + 1;
                continue;
            }
        }
        yield lines->substring(sliceStart, i);
        sliceStart = i + 1;
    }
    if ( < end) {
        yield lines->substring(sliceStart, end);
    }
}

List<String> LineSplitterCls::convert(String data) {
    auto lines = makeList();
    auto end = data->length();
    auto sliceStart = 0;
    auto char = 0;
    for (;  < end; i++) {
        auto previousChar = charValue;
        charValue = data->codeUnitAt(i);
        if (charValue != _CR) {
            if (charValue != _LF) {
                continue;
            }
            if (previousChar == _CR) {
                sliceStart = i + 1;
                continue;
            }
        }
        lines->add(data->substring(sliceStart, i));
        sliceStart = i + 1;
    }
    if ( < end) {
        lines->add(data->substring(sliceStart, end));
    }
    return lines;
}

StringConversionSink LineSplitterCls::startChunkedConversion(Sink<String> sink) {
    return make<_LineSplitterSinkCls>(is<StringConversionSink>(sink)? sink : StringConversionSinkCls->from(sink));
}

Stream<String> LineSplitterCls::bind(Stream<String> stream) {
    return <String>eventTransformed(stream, [=] (EventSink<String> sink) {
        make<_LineSplitterEventSinkCls>(sink);
    });
}

void _LineSplitterSinkCls::addSlice(String chunk, int start, int end, bool isLast) {
    end = RangeErrorCls->checkValidRange(start, end, chunk->length());
    if (start >= end) {
        if (isLast) {
            close();
        }
        return;
    }
    String carry = _carry;
    if (carry != nullptr) {
        assert(!_skipLeadingLF);
        chunk = carry + chunk->substring(start, end);
        start = 0;
        end = chunk->length();
        _carry = nullptr;
    } else {
        if (_skipLeadingLF) {
        if (chunk->codeUnitAt(start) == _LF) {
            start += 1;
        }
        _skipLeadingLF = false;
    }
;
    }    _addLines(chunk, start, end);
    if (isLast) {
        close();
    }
}

void _LineSplitterSinkCls::close() {
    if (_carry != nullptr) {
        _sink->add(_carry!);
        _carry = nullptr;
    }
    _sink->close();
}

void _LineSplitterSinkCls::_addLines(String lines, int start, int end) {
    auto sliceStart = start;
    auto char = 0;
    for (;  < end; i++) {
        auto previousChar = charValue;
        charValue = lines->codeUnitAt(i);
        if (charValue != _CR) {
            if (charValue != _LF) {
                continue;
            }
            if (previousChar == _CR) {
                sliceStart = i + 1;
                continue;
            }
        }
        _sink->add(lines->substring(sliceStart, i));
        sliceStart = i + 1;
    }
    if ( < end) {
        _carry = lines->substring(sliceStart, end);
    } else {
        _skipLeadingLF = (charValue == _CR);
    }
}

void _LineSplitterEventSinkCls::addError(Object o, StackTrace stackTrace) {
    _eventSink->addError(o, stackTrace);
}

_LineSplitterEventSinkCls::_LineSplitterEventSinkCls(EventSink<String> eventSink) : _LineSplitterSink(StringConversionSinkCls->from(eventSink)) {
    {
        _eventSink = eventSink;
    }
}
