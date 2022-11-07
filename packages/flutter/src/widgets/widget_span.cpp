#include "widget_span.hpp"
WidgetSpan::WidgetSpan(Unknown, Unknown, Widget child, Unknown) {
    {
        assert(child != nullptr);
        assert(baseline != nullptr || !(identical(alignment, ui.PlaceholderAlignment.aboveBaseline) || identical(alignment, ui.PlaceholderAlignment.belowBaseline) || identical(alignment, ui.PlaceholderAlignment.baseline)));
    }
}

void WidgetSpan::build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor) {
    assert(debugAssertIsValid());
    assert(dimensions != nullptr);
    bool hasStyle = style != nullptr;
    if (hasStyle) {
        builder.pushStyle(style!.getTextStyle(textScaleFactor));
    }
    assert(builder.placeholderCount < dimensions!.length);
    PlaceholderDimensions currentDimensions = dimensions![builder.placeholderCount];
    builder.addPlaceholder(currentDimensions.size.width, currentDimensions.size.height, alignmenttextScaleFactor, currentDimensions.baseline, currentDimensions.baselineOffset);
    if (hasStyle) {
        builder.pop();
    }
}

bool WidgetSpan::visitChildren(InlineSpanVisitor visitor) {
    return visitor(this);
}

InlineSpan WidgetSpan::getSpanForPositionVisitor(Accumulator offset, TextPosition position) {
    if (position.offset == offset.value) {
        return this;
    }
    offset.increment(1);
    return nullptr;
}

int WidgetSpan::codeUnitAtVisitor(int index, Accumulator offset) {
    offset.increment(1);
    return PlaceholderSpan.placeholderCodeUnit;
}

RenderComparison WidgetSpan::compareTo(InlineSpan other) {
    if (identical(this, other)) {
        return RenderComparison.identical;
    }
    if (other.runtimeType != runtimeType) {
        return RenderComparison.layout;
    }
    if ((style == nullptr) != (other.style == nullptr)) {
        return RenderComparison.layout;
    }
    WidgetSpan typedOther = (;
    if (child != typedOther.child || alignment != typedOther.alignment) {
        return RenderComparison.layout;
    }
    RenderComparison result = RenderComparison.identical;
    if (style != nullptr) {
        RenderComparison candidate = style!.compareTo(other.style!);
        if (candidate.index > result.index) {
            result = candidate;
        }
        if (result == RenderComparison.layout) {
            return result;
        }
    }
    return result;
}

bool WidgetSpan::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    if (super != other) {
        return false;
    }
    return other is WidgetSpan && other.child == child && other.alignment == alignment && other.baseline == baseline;
}

int WidgetSpan::hashCode() {
    return Object.hash(super.hashCode, child, alignment, baseline);
}

InlineSpan WidgetSpan::getSpanForPosition(TextPosition position) {
    assert(debugAssertIsValid());
    return nullptr;
}

bool WidgetSpan::debugAssertIsValid() {
    return true;
}
