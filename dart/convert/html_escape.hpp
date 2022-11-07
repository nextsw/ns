#ifndef HTML_ESCAPE_H
#define HTML_ESCAPE_H
#include <memory>



const HtmlEscape htmlEscape;


class HtmlEscapeMode {
public:
    bool escapeLtGt;

    bool escapeQuot;

    bool escapeApos;

    bool escapeSlash;

    static const HtmlEscapeMode unknown;

    static const HtmlEscapeMode attribute;

    static const HtmlEscapeMode sqAttribute;

    static const HtmlEscapeMode element;


     HtmlEscapeMode(bool escapeApos, bool escapeLtGt, bool escapeQuot, bool escapeSlash, String name);

    String toString();

private:
    String _name;


    void  _(String _name, bool escapeApos, bool escapeLtGt, bool escapeQuot, bool escapeSlash);

};

class HtmlEscape : Converter<String, String> {
public:
    HtmlEscapeMode mode;


     HtmlEscape(HtmlEscapeMode mode);

    String convert(String text);

    StringConversionSink startChunkedConversion(Sink<String> sink);

private:

    String _convert(int end, int start, String text);

};

class _HtmlEscapeSink : StringConversionSinkBase {
public:

    void addSlice(String chunk, int end, bool isLast, int start);

    void close();

private:
    HtmlEscape _escape;

    StringConversionSink _sink;


     _HtmlEscapeSink(HtmlEscape _escape, StringConversionSink _sink);

};

#endif