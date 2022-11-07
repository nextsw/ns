#include "line_splitter.hpp"
Iterable<String> LineSplitter::split(int end, String lines, int start) {
    end = RangeError.checkValidRange(start, end, lines.length);
    auto sliceStart = start;
    auto char = 0;
    for (;  < end; i++) {
        auto previousChar = char;
        char = lines.codeUnitAt(i);
        if (char != _CR) {
            if (char != _LF)             {
                continue;
            }
            if (previousChar == _CR) {
                sliceStart = i + 1;
                continue;
            }
        }
        yield yield;
        lines.substring(sliceStart, i);
        sliceStart = i + 1;
    }
    if ( < end) {
        yield yield;
        lines.substring(sliceStart, end);
    }
}

List<String> LineSplitter::convert(String data) {
    auto lines = ;
    auto end = data.length;
    auto sliceStart = 0;
    auto char = 0;
    for (;  < end; i++) {
        auto previousChar = char;
        char = data.codeUnitAt(i);
        if (char != _CR) {
            if (char != _LF)             {
                continue;
            }
            if (previousChar == _CR) {
                sliceStart = i + 1;
                continue;
            }
        }
        lines.add(data.substring(sliceStart, i));
        sliceStart = i + 1;
    }
    if ( < end) {
        lines.add(data.substring(sliceStart, end));
    }
    return lines;
}

StringConversionSink LineSplitter::startChunkedConversion(Sink<String> sink) {
    return _LineSplitterSink(sink is StringConversionSink? sink : StringConversionSink.from(sink));
}

Stream<String> LineSplitter::bind(Stream<String> stream) {
    return <String>eventTransformed(stream, );
}

void _LineSplitterSink::addSlice(String chunk, int end, bool isLast, int start) {
    end = RangeError.checkValidRange(start, end, chunk.length);
    if (start >= end) {
        if (isLast)         {
            close();
        }
        return;
    }
    String carry = _carry;
    if (carry != nullptr) {
        assert(!_skipLeadingLF);
        chunk = carry + chunk.substring(start, end);
        start = 0;
        end = chunk.length;
        _carry = nullptr;
    } else     {
        if (_skipLeadingLF) {
        if (chunk.codeUnitAt(start) == _LF) {
            start = 1;
        }
        _skipLeadingLF = false;
    }
;
    }    _addLines(chunk, start, end);
    if (isLast)     {
        close();
    }
}

void _LineSplitterSink::close() {
    if (_carry != nullptr) {
        _sink.add(_carry!);
        _carry = nullptr;
    }
    _sink.close();
}

void _LineSplitterSink::_addLines(int end, String lines, int start) {
    auto sliceStart = start;
    auto char = 0;
    for (;  < end; i++) {
        auto previousChar = char;
        char = lines.codeUnitAt(i);
        if (char != _CR) {
            if (char != _LF)             {
                continue;
            }
            if (previousChar == _CR) {
                sliceStart = i + 1;
                continue;
            }
        }
        _sink.add(lines.substring(sliceStart, i));
        sliceStart = i + 1;
    }
    if ( < end) {
        _carry = lines.substring(sliceStart, end);
    } else {
        _skipLeadingLF = (char == _CR);
    }
}

void _LineSplitterEventSink::addError(Object o, StackTrace stackTrace) {
    _eventSink.addError(o, stackTrace);
}

_LineSplitterEventSink::_LineSplitterEventSink(EventSink<String> eventSink) {
    {
        _eventSink = eventSink;
        super(StringConversionSink.from(eventSink));
    }
}
