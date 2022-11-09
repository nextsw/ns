#include "wrap.hpp"
RenderWrapCls::RenderWrapCls(WrapAlignment alignment, List<RenderBox> children, Clip clipBehavior, WrapCrossAlignment crossAxisAlignment, Axis direction, WrapAlignment runAlignment, double runSpacing, double spacing, TextDirection textDirection, VerticalDirection verticalDirection) {
    {
        assert(direction != nullptr);
        assert(alignment != nullptr);
        assert(spacing != nullptr);
        assert(runAlignment != nullptr);
        assert(runSpacing != nullptr);
        assert(crossAxisAlignment != nullptr);
        assert(clipBehavior != nullptr);
        _direction = direction;
        _alignment = alignment;
        _spacing = spacing;
        _runAlignment = runAlignment;
        _runSpacing = runSpacing;
        _crossAxisAlignment = crossAxisAlignment;
        _textDirection = textDirection;
        _verticalDirection = verticalDirection;
        _clipBehavior = clipBehavior;
    }
    {
        addAll(children);
    }
}

Axis RenderWrapCls::direction() {
    return _direction;
}

void RenderWrapCls::direction(Axis value) {
    assert(value != nullptr);
    if (_direction == value) {
        return;
    }
    _direction = value;
    markNeedsLayout();
}

WrapAlignment RenderWrapCls::alignment() {
    return _alignment;
}

void RenderWrapCls::alignment(WrapAlignment value) {
    assert(value != nullptr);
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    markNeedsLayout();
}

double RenderWrapCls::spacing() {
    return _spacing;
}

void RenderWrapCls::spacing(double value) {
    assert(value != nullptr);
    if (_spacing == value) {
        return;
    }
    _spacing = value;
    markNeedsLayout();
}

WrapAlignment RenderWrapCls::runAlignment() {
    return _runAlignment;
}

void RenderWrapCls::runAlignment(WrapAlignment value) {
    assert(value != nullptr);
    if (_runAlignment == value) {
        return;
    }
    _runAlignment = value;
    markNeedsLayout();
}

double RenderWrapCls::runSpacing() {
    return _runSpacing;
}

void RenderWrapCls::runSpacing(double value) {
    assert(value != nullptr);
    if (_runSpacing == value) {
        return;
    }
    _runSpacing = value;
    markNeedsLayout();
}

WrapCrossAlignment RenderWrapCls::crossAxisAlignment() {
    return _crossAxisAlignment;
}

void RenderWrapCls::crossAxisAlignment(WrapCrossAlignment value) {
    assert(value != nullptr);
    if (_crossAxisAlignment == value) {
        return;
    }
    _crossAxisAlignment = value;
    markNeedsLayout();
}

TextDirection RenderWrapCls::textDirection() {
    return _textDirection;
}

void RenderWrapCls::textDirection(TextDirection value) {
    if (_textDirection != value) {
        _textDirection = value;
        markNeedsLayout();
    }
}

VerticalDirection RenderWrapCls::verticalDirection() {
    return _verticalDirection;
}

void RenderWrapCls::verticalDirection(VerticalDirection value) {
    if (_verticalDirection != value) {
        _verticalDirection = value;
        markNeedsLayout();
    }
}

Clip RenderWrapCls::clipBehavior() {
    return _clipBehavior;
}

void RenderWrapCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderWrapCls::setupParentData(RenderBox child) {
    if (child->parentData is! WrapParentData) {
        child->parentData = make<WrapParentDataCls>();
    }
}

double RenderWrapCls::computeMinIntrinsicWidth(double height) {
    ;
}

double RenderWrapCls::computeMaxIntrinsicWidth(double height) {
    ;
}

double RenderWrapCls::computeMinIntrinsicHeight(double width) {
    ;
}

double RenderWrapCls::computeMaxIntrinsicHeight(double width) {
    ;
}

double RenderWrapCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    return defaultComputeDistanceToHighestActualBaseline(baseline);
}

Size RenderWrapCls::computeDryLayout(BoxConstraints constraints) {
    return _computeDryLayout(constraints);
}

void RenderWrapCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    assert(_debugHasNecessaryDirections);
    _hasVisualOverflow = false;
    RenderBox child = firstChild;
    if (child == nullptr) {
        size = constraints->smallest;
        return;
    }
    BoxConstraints childConstraints;
    double mainAxisLimit = 0.0;
    bool flipMainAxis = false;
    bool flipCrossAxis = false;
    ;
    assert(childConstraints != nullptr);
    assert(mainAxisLimit != nullptr);
    double spacing = this->spacing;
    double runSpacing = this->runSpacing;
    List<_RunMetrics> runMetrics = makeList();
    double mainAxisExtent = 0.0;
    double crossAxisExtent = 0.0;
    double runMainAxisExtent = 0.0;
    double runCrossAxisExtent = 0.0;
    int childCount = 0;
    while (child != nullptr) {
        child->layout(childConstraintstrue);
        double childMainAxisExtent = _getMainAxisExtent(child->size);
        double childCrossAxisExtent = _getCrossAxisExtent(child->size);
        if (childCount > 0 && runMainAxisExtent + spacing + childMainAxisExtent > mainAxisLimit) {
            mainAxisExtent = math->max(mainAxisExtent, runMainAxisExtent);
            crossAxisExtent = runCrossAxisExtent;
            if (runMetrics->isNotEmpty) {
                crossAxisExtent = runSpacing;
            }
            runMetrics->add(make<_RunMetricsCls>(runMainAxisExtent, runCrossAxisExtent, childCount));
            runMainAxisExtent = 0.0;
            runCrossAxisExtent = 0.0;
            childCount = 0;
        }
        runMainAxisExtent = childMainAxisExtent;
        if (childCount > 0) {
            runMainAxisExtent = spacing;
        }
        runCrossAxisExtent = math->max(runCrossAxisExtent, childCrossAxisExtent);
        childCount = 1;
        WrapParentData childParentData = ((WrapParentData)child->parentData!);
        childParentData->_runIndex = runMetrics->length;
        child = childParentData->nextSibling;
    }
    if (childCount > 0) {
        mainAxisExtent = math->max(mainAxisExtent, runMainAxisExtent);
        crossAxisExtent = runCrossAxisExtent;
        if (runMetrics->isNotEmpty) {
            crossAxisExtent = runSpacing;
        }
        runMetrics->add(make<_RunMetricsCls>(runMainAxisExtent, runCrossAxisExtent, childCount));
    }
    int runCount = runMetrics->length;
    assert(runCount > 0);
    double containerMainAxisExtent = 0.0;
    double containerCrossAxisExtent = 0.0;
    ;
    _hasVisualOverflow =  < mainAxisExtent ||  < crossAxisExtent;
    double crossAxisFreeSpace = math->max(0.0, containerCrossAxisExtent - crossAxisExtent);
    double runLeadingSpace = 0.0;
    double runBetweenSpace = 0.0;
    ;
    runBetweenSpace = runSpacing;
    double crossAxisOffset = flipCrossAxis? containerCrossAxisExtent - runLeadingSpace : runLeadingSpace;
    child = firstChild;
    for (;  < runCount; ++i) {
        _RunMetrics metrics = runMetrics[i];
        double runMainAxisExtent = metrics->mainAxisExtent;
        double runCrossAxisExtent = metrics->crossAxisExtent;
        int childCount = metrics->childCount;
        double mainAxisFreeSpace = math->max(0.0, containerMainAxisExtent - runMainAxisExtent);
        double childLeadingSpace = 0.0;
        double childBetweenSpace = 0.0;
        ;
        childBetweenSpace = spacing;
        double childMainPosition = flipMainAxis? containerMainAxisExtent - childLeadingSpace : childLeadingSpace;
        if (flipCrossAxis) {
            crossAxisOffset = runCrossAxisExtent;
        }
        while (child != nullptr) {
            WrapParentData childParentData = ((WrapParentData)child->parentData!);
            if (childParentData->_runIndex != i) {
                                break;
            }
            double childMainAxisExtent = _getMainAxisExtent(child->size);
            double childCrossAxisExtent = _getCrossAxisExtent(child->size);
            double childCrossAxisOffset = _getChildCrossAxisOffset(flipCrossAxis, runCrossAxisExtent, childCrossAxisExtent);
            if (flipMainAxis) {
                childMainPosition = childMainAxisExtent;
            }
            childParentData->offset = _getOffset(childMainPosition, crossAxisOffset + childCrossAxisOffset);
            if (flipMainAxis) {
                childMainPosition = childBetweenSpace;
            } else {
                childMainPosition = childMainAxisExtent + childBetweenSpace;
            }
            child = childParentData->nextSibling;
        }
        if (flipCrossAxis) {
            crossAxisOffset = runBetweenSpace;
        } else {
            crossAxisOffset = runCrossAxisExtent + runBetweenSpace;
        }
    }
}

bool RenderWrapCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

void RenderWrapCls::paint(PaintingContext context, Offset offset) {
    if (_hasVisualOverflow && clipBehavior != ClipCls::none) {
        _clipRectLayer->layer = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, defaultPaintclipBehavior, _clipRectLayer->layer);
    } else {
        _clipRectLayer->layer = nullptr;
        defaultPaint(context, offset);
    }
}

void RenderWrapCls::dispose() {
    _clipRectLayer->layer = nullptr;
    super->dispose();
}

void RenderWrapCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Axis>make<EnumPropertyCls>("direction", direction));
    properties->add(<WrapAlignment>make<EnumPropertyCls>("alignment", alignment));
    properties->add(make<DoublePropertyCls>("spacing", spacing));
    properties->add(<WrapAlignment>make<EnumPropertyCls>("runAlignment", runAlignment));
    properties->add(make<DoublePropertyCls>("runSpacing", runSpacing));
    properties->add(make<DoublePropertyCls>("crossAxisAlignment", runSpacing));
    properties->add(<TextDirection>make<EnumPropertyCls>("textDirection", textDirectionnullptr));
    properties->add(<VerticalDirection>make<EnumPropertyCls>("verticalDirection", verticalDirectionVerticalDirectionCls::down));
}

bool RenderWrapCls::_debugHasNecessaryDirections() {
    assert(direction != nullptr);
    assert(alignment != nullptr);
    assert(runAlignment != nullptr);
    assert(crossAxisAlignment != nullptr);
    if (firstChild != nullptr && lastChild != firstChild) {
        ;
    }
    if (alignment == WrapAlignmentCls::start || alignment == WrapAlignmentCls::end) {
        ;
    }
    if (runAlignment == WrapAlignmentCls::start || runAlignment == WrapAlignmentCls::end) {
        ;
    }
    if (crossAxisAlignment == WrapCrossAlignmentCls::start || crossAxisAlignment == WrapCrossAlignmentCls::end) {
        ;
    }
    return true;
}

double RenderWrapCls::_getMainAxisExtent(Size childSize) {
    ;
}

double RenderWrapCls::_getCrossAxisExtent(Size childSize) {
    ;
}

Offset RenderWrapCls::_getOffset(double crossAxisOffset, double mainAxisOffset) {
    ;
}

double RenderWrapCls::_getChildCrossAxisOffset(double childCrossAxisExtent, bool flipCrossAxis, double runCrossAxisExtent) {
    double freeSpace = runCrossAxisExtent - childCrossAxisExtent;
    ;
}

Size RenderWrapCls::_computeDryLayout(BoxConstraints constraints, ChildLayouter layoutChild) {
    BoxConstraints childConstraints;
    double mainAxisLimit = 0.0;
    ;
    double mainAxisExtent = 0.0;
    double crossAxisExtent = 0.0;
    double runMainAxisExtent = 0.0;
    double runCrossAxisExtent = 0.0;
    int childCount = 0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        Size childSize = layoutChild(child, childConstraints);
        double childMainAxisExtent = _getMainAxisExtent(childSize);
        double childCrossAxisExtent = _getCrossAxisExtent(childSize);
        if (childCount > 0 && runMainAxisExtent + childMainAxisExtent + spacing > mainAxisLimit) {
            mainAxisExtent = math->max(mainAxisExtent, runMainAxisExtent);
            crossAxisExtent = runCrossAxisExtent + runSpacing;
            runMainAxisExtent = 0.0;
            runCrossAxisExtent = 0.0;
            childCount = 0;
        }
        runMainAxisExtent = childMainAxisExtent;
        runCrossAxisExtent = math->max(runCrossAxisExtent, childCrossAxisExtent);
        if (childCount > 0) {
            runMainAxisExtent = spacing;
        }
        childCount = 1;
        child = childAfter(child);
    }
    crossAxisExtent = runCrossAxisExtent;
    mainAxisExtent = math->max(mainAxisExtent, runMainAxisExtent);
    ;
}
