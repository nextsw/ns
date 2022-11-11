#ifndef DART_CONVERT_HTML_ESCAPE
#define DART_CONVERT_HTML_ESCAPE
#include <base.hpp>

#include <dart/core/core.hpp>

HtmlEscape htmlEscape;


class HtmlEscapeModeCls : public ObjectCls {
public:
    bool escapeLtGt;

    bool escapeQuot;

    bool escapeApos;

    bool escapeSlash;

    static HtmlEscapeMode unknown;

    static HtmlEscapeMode attribute;

    static HtmlEscapeMode sqAttribute;

    static HtmlEscapeMode element;


     HtmlEscapeModeCls(bool escapeApos, bool escapeLtGt, bool escapeQuot, bool escapeSlash, String name);

    virtual String toString();

private:
    String _name;


    virtual void  _(String _name, bool escapeLtGt, bool escapeQuot, bool escapeApos, bool escapeSlash);
};
using HtmlEscapeMode = std::shared_ptr<HtmlEscapeModeCls>;

class HtmlEscapeCls : public ConverterCls<String, String> {
public:
    HtmlEscapeMode mode;


     HtmlEscapeCls(HtmlEscapeMode mode);
    virtual String convert(String text);

    virtual StringConversionSink startChunkedConversion(Sink<String> sink);

private:

    virtual String _convert(String text, int start, int end);

};
using HtmlEscape = std::shared_ptr<HtmlEscapeCls>;

class _HtmlEscapeSinkCls : public StringConversionSinkBaseCls {
public:

    virtual void addSlice(String chunk, int start, int end, bool isLast);

    virtual void close();

private:
    HtmlEscape _escape;

    StringConversionSink _sink;


     _HtmlEscapeSinkCls(HtmlEscape _escape, StringConversionSink _sink);
};
using _HtmlEscapeSink = std::shared_ptr<_HtmlEscapeSinkCls>;


#endif