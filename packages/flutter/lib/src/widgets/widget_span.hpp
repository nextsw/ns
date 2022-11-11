#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_WIDGET_SPAN
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_WIDGET_SPAN
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"


class WidgetSpanCls : public PlaceholderSpanCls {
public:
    Widget child;


     WidgetSpanCls(Unknown alignment, Unknown baseline, Widget child, Unknown style);

    virtual void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);

    virtual bool visitChildren(InlineSpanVisitor visitor);

    virtual InlineSpan getSpanForPositionVisitor(TextPosition position, Accumulator offset);

    virtual int codeUnitAtVisitor(int index, Accumulator offset);

    virtual RenderComparison compareTo(InlineSpan other);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual InlineSpan getSpanForPosition(TextPosition position);

    virtual bool debugAssertIsValid();

private:

};
using WidgetSpan = std::shared_ptr<WidgetSpanCls>;


#endif