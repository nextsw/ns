#ifndef WIDGET_SPAN_H
#define WIDGET_SPAN_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/painting.hpp>
#include "framework.hpp"



class WidgetSpan : PlaceholderSpan {
public:
    Widget child;


     WidgetSpan(Unknown, Unknown, Widget child, Unknown);

    void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);

    bool visitChildren(InlineSpanVisitor visitor);

    InlineSpan getSpanForPositionVisitor(Accumulator offset, TextPosition position);

    int codeUnitAtVisitor(int index, Accumulator offset);

    RenderComparison compareTo(InlineSpan other);

    bool ==(Object other);

    int hashCode();

    InlineSpan getSpanForPosition(TextPosition position);

    bool debugAssertIsValid();

private:

};

#endif