#include "widget_span.hpp"
WidgetSpanCls::WidgetSpanCls(Unknown alignment, Unknown baseline, Widget child, Unknown style) {
    {
        assert(child != nullptr);
        assert(baseline != nullptr || !(identical(alignment, ui->PlaceholderAlignmentCls::aboveBaseline) || identical(alignment, ui->PlaceholderAlignmentCls::belowBaseline) || identical(alignment, ui->PlaceholderAlignmentCls::baseline)));
    }
}

void WidgetSpanCls::build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor) {
    assert(debugAssertIsValid());
    assert(dimensions != nullptr);
    bool hasStyle = style != nullptr;
    if (hasStyle) {
        builder->pushStyle(style!->getTextStyle(textScaleFactor));
    }
    assert(builder->placeholderCount() < dimensions!->length);
    PlaceholderDimensions currentDimensions = dimensions![builder->placeholderCount()];
    builder->addPlaceholder(currentDimensions->size->width, currentDimensions->size->height, alignmenttextScaleFactor, currentDimensions->baseline, currentDimensions->baselineOffset);
    if (hasStyle) {
        builder->pop();
    }
}

bool WidgetSpanCls::visitChildren(InlineSpanVisitor visitor) {
    return visitor(this);
}

InlineSpan WidgetSpanCls::getSpanForPositionVisitor(Accumulator offset, TextPosition position) {
    if (position->offset == offset->value) {
        return this;
    }
    offset->increment(1);
    return nullptr;
}

int WidgetSpanCls::codeUnitAtVisitor(int index, Accumulator offset) {
    offset->increment(1);
    return PlaceholderSpanCls::placeholderCodeUnit;
}

RenderComparison WidgetSpanCls::compareTo(InlineSpan other) {
    if (identical(this, other)) {
        return RenderComparisonCls::identical;
    }
    if (other->runtimeType != runtimeType) {
        return RenderComparisonCls::layout;
    }
    if ((style == nullptr) != (other->style == nullptr)) {
        return RenderComparisonCls::layout;
    }
    WidgetSpan typedOther = as<WidgetSpan>(other);
    if (child != typedOther->child || alignment != typedOther->alignment) {
        return RenderComparisonCls::layout;
    }
    RenderComparison result = RenderComparisonCls::identical;
    if (style != nullptr) {
        RenderComparison candidate = style!->compareTo(other->style!);
        if (candidate->index > result->index) {
            result = candidate;
        }
        if (result == RenderComparisonCls::layout) {
            return result;
        }
    }
    return result;
}

bool WidgetSpanCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    if (super != other) {
        return false;
    }
    return is<WidgetSpan>(other) && other->child == child && other->alignment == alignment && other->baseline == baseline;
}

int WidgetSpanCls::hashCode() {
    return ObjectCls->hash(super->hashCode, child, alignment, baseline);
}

InlineSpan WidgetSpanCls::getSpanForPosition(TextPosition position) {
    assert(debugAssertIsValid());
    return nullptr;
}

bool WidgetSpanCls::debugAssertIsValid() {
    return true;
}
