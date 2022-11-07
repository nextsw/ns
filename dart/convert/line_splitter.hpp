#ifndef LINE_SPLITTER_H
#define LINE_SPLITTER_H
#include <memory>



const int _LF;

const int _CR;


class LineSplitter : StreamTransformerBase<String, String> {
public:

     LineSplitter();

    static Iterable<String> split(int end, String lines, int start);

    List<String> convert(String data);

    StringConversionSink startChunkedConversion(Sink<String> sink);

    Stream<String> bind(Stream<String> stream);

private:

};

class _LineSplitterSink : StringConversionSinkBase {
public:

    void addSlice(String chunk, int end, bool isLast, int start);

    void close();

private:
    StringConversionSink _sink;

    String _carry;

    bool _skipLeadingLF;


     _LineSplitterSink(StringConversionSink _sink);

    void _addLines(int end, String lines, int start);

};

class _LineSplitterEventSink : _LineSplitterSink {
public:

    void addError(Object o, StackTrace stackTrace);

private:
    EventSink<String> _eventSink;


     _LineSplitterEventSink(EventSink<String> eventSink);

};

#endif