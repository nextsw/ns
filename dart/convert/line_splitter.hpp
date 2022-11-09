#ifndef DART_CONVERT_LINE_SPLITTER
#define DART_CONVERT_LINE_SPLITTER
#include <base.hpp>

#include <dart/core/core.hpp>

int _LF;

int _CR;


class LineSplitterCls : public StreamTransformerBaseCls<String, String> {
public:

     LineSplitterCls();
    static Iterable<String> split(int end, String lines, int start);

    virtual List<String> convert(String data);

    virtual StringConversionSink startChunkedConversion(Sink<String> sink);

    virtual Stream<String> bind(Stream<String> stream);

private:

};
using LineSplitter = std::shared_ptr<LineSplitterCls>;

class _LineSplitterSinkCls : public StringConversionSinkBaseCls {
public:

    virtual void addSlice(String chunk, int end, bool isLast, int start);

    virtual void close();

private:
    StringConversionSink _sink;

    String _carry;

    bool _skipLeadingLF;


     _LineSplitterSinkCls(StringConversionSink _sink);
    virtual void _addLines(int end, String lines, int start);

};
using _LineSplitterSink = std::shared_ptr<_LineSplitterSinkCls>;

class _LineSplitterEventSinkCls : public _LineSplitterSinkCls {
public:

    virtual void addError(Object o, StackTrace stackTrace);

private:
    EventSink<String> _eventSink;


     _LineSplitterEventSinkCls(EventSink<String> eventSink);

};
using _LineSplitterEventSink = std::shared_ptr<_LineSplitterEventSinkCls>;


#endif