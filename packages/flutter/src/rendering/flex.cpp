#include "flex.hpp"
String FlexParentData::toString() {
    return "${super.toString()}; flex=$flex; fit=$fit";
}

bool _startIsTopLeft(Axis direction, TextDirection textDirection, VerticalDirection verticalDirection) {
    assert(direction != nullptr);
    ;
}

RenderFlex::RenderFlex(List<RenderBox> children, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection) {
    {
        assert(direction != nullptr);
        assert(mainAxisAlignment != nullptr);
        assert(mainAxisSize != nullptr);
        assert(crossAxisAlignment != nullptr);
        assert(clipBehavior != nullptr);
        _direction = direction;
        _mainAxisAlignment = mainAxisAlignment;
        _mainAxisSize = mainAxisSize;
        _crossAxisAlignment = crossAxisAlignment;
        _textDirection = textDirection;
        _verticalDirection = verticalDirection;
        _textBaseline = textBaseline;
        _clipBehavior = clipBehavior;
    }
    {
        addAll(children);
    }
}

Axis RenderFlex::direction() {
    return _direction;
}

void RenderFlex::direction(Axis value) {
    assert(value != nullptr);
    if (_direction != value) {
        _direction = value;
        markNeedsLayout();
    }
}

MainAxisAlignment RenderFlex::mainAxisAlignment() {
    return _mainAxisAlignment;
}

void RenderFlex::mainAxisAlignment(MainAxisAlignment value) {
    assert(value != nullptr);
    if (_mainAxisAlignment != value) {
        _mainAxisAlignment = value;
        markNeedsLayout();
    }
}

MainAxisSize RenderFlex::mainAxisSize() {
    return _mainAxisSize;
}

void RenderFlex::mainAxisSize(MainAxisSize value) {
    assert(value != nullptr);
    if (_mainAxisSize != value) {
        _mainAxisSize = value;
        markNeedsLayout();
    }
}

CrossAxisAlignment RenderFlex::crossAxisAlignment() {
    return _crossAxisAlignment;
}

void RenderFlex::crossAxisAlignment(CrossAxisAlignment value) {
    assert(value != nullptr);
    if (_crossAxisAlignment != value) {
        _crossAxisAlignment = value;
        markNeedsLayout();
    }
}

TextDirection RenderFlex::textDirection() {
    return _textDirection;
}

void RenderFlex::textDirection(TextDirection value) {
    if (_textDirection != value) {
        _textDirection = value;
        markNeedsLayout();
    }
}

VerticalDirection RenderFlex::verticalDirection() {
    return _verticalDirection;
}

void RenderFlex::verticalDirection(VerticalDirection value) {
    if (_verticalDirection != value) {
        _verticalDirection = value;
        markNeedsLayout();
    }
}

TextBaseline RenderFlex::textBaseline() {
    return _textBaseline;
}

void RenderFlex::textBaseline(TextBaseline value) {
    assert(_crossAxisAlignment != CrossAxisAlignment.baseline || value != nullptr);
    if (_textBaseline != value) {
        _textBaseline = value;
        markNeedsLayout();
    }
}

Clip RenderFlex::clipBehavior() {
    return _clipBehavior;
}

void RenderFlex::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderFlex::setupParentData(RenderBox child) {
    if (child.parentData is! FlexParentData) {
        child.parentData = FlexParentData();
    }
}

double RenderFlex::computeMinIntrinsicWidth(double height) {
    return _getIntrinsicSize(Axis.horizontal, height, );
}

double RenderFlex::computeMaxIntrinsicWidth(double height) {
    return _getIntrinsicSize(Axis.horizontal, height, );
}

double RenderFlex::computeMinIntrinsicHeight(double width) {
    return _getIntrinsicSize(Axis.vertical, width, );
}

double RenderFlex::computeMaxIntrinsicHeight(double width) {
    return _getIntrinsicSize(Axis.vertical, width, );
}

double RenderFlex::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (_direction == Axis.horizontal) {
        return defaultComputeDistanceToHighestActualBaseline(baseline);
    }
    return defaultComputeDistanceToFirstActualBaseline(baseline);
}

Size RenderFlex::computeDryLayout(BoxConstraints constraints) {
    if (!_canComputeIntrinsics) {
        assert(debugCannotComputeDryLayout("Dry layout cannot be computed for CrossAxisAlignment.baseline, which requires a full layout."));
        return Size.zero;
    }
    FlutterError constraintsError;
    assert(());
    if (constraintsError != nullptr) {
        assert(debugCannotComputeDryLayout(constraintsError));
        return Size.zero;
    }
    _LayoutSizes sizes = _computeSizes(ChildLayoutHelper.dryLayoutChild, constraints);
    ;
}

void RenderFlex::performLayout() {
    assert(_debugHasNecessaryDirections);
    BoxConstraints constraints = this.constraints;
    assert(());
    _LayoutSizes sizes = _computeSizes(ChildLayoutHelper.layoutChild, constraints);
    double allocatedSize = sizes.allocatedSize;
    double actualSize = sizes.mainSize;
    double crossSize = sizes.crossSize;
    double maxBaselineDistance = 0.0;
    if (crossAxisAlignment == CrossAxisAlignment.baseline) {
        RenderBox child = firstChild;
        double maxSizeAboveBaseline = 0;
        double maxSizeBelowBaseline = 0;
        while (child != nullptr) {
            assert(());
            double distance = child.getDistanceToBaseline(textBaseline!true);
            if (distance != nullptr) {
                maxBaselineDistance = math.max(maxBaselineDistance, distance);
                maxSizeAboveBaseline = math.max(distance, maxSizeAboveBaseline);
                maxSizeBelowBaseline = math.max(child.size.height - distance, maxSizeBelowBaseline);
                crossSize = math.max(maxSizeAboveBaseline + maxSizeBelowBaseline, crossSize);
            }
            FlexParentData childParentData = (;
            child = childParentData.nextSibling;
        }
    }
    ;
    double actualSizeDelta = actualSize - allocatedSize;
    _overflow = math.max(0.0, -actualSizeDelta);
    double remainingSpace = math.max(0.0, actualSizeDelta);
    double leadingSpace;
    double betweenSpace;
    bool flipMainAxis = !(_startIsTopLeft(direction, textDirection, verticalDirection) ?? true);
    ;
    double childMainPosition = flipMainAxis? actualSize - leadingSpace : leadingSpace;
    RenderBox child = firstChild;
    while (child != nullptr) {
        FlexParentData childParentData = (;
        double childCrossPosition;
        ;
        if (flipMainAxis) {
            childMainPosition = _getMainSize(child.size);
        }
        ;
        if (flipMainAxis) {
            childMainPosition = betweenSpace;
        } else {
            childMainPosition = _getMainSize(child.size) + betweenSpace;
        }
        child = childParentData.nextSibling;
    }
}

bool RenderFlex::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

void RenderFlex::paint(PaintingContext context, Offset offset) {
    if (!_hasOverflow) {
        defaultPaint(context, offset);
        return;
    }
    if (size.isEmpty) {
        return;
    }
    _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, defaultPaintclipBehavior, _clipRectLayer.layer);
    assert(());
}

void RenderFlex::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

Rect RenderFlex::describeApproximatePaintClip(RenderObject child) {
    ;
}

String RenderFlex::toStringShort() {
    String header = super.toStringShort();
    if (!kReleaseMode) {
        if (_hasOverflow) {
            header = " OVERFLOWING";
        }
    }
    return header;
}

void RenderFlex::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Axis>EnumProperty("direction", direction));
    properties.add(<MainAxisAlignment>EnumProperty("mainAxisAlignment", mainAxisAlignment));
    properties.add(<MainAxisSize>EnumProperty("mainAxisSize", mainAxisSize));
    properties.add(<CrossAxisAlignment>EnumProperty("crossAxisAlignment", crossAxisAlignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<VerticalDirection>EnumProperty("verticalDirection", verticalDirectionnullptr));
    properties.add(<TextBaseline>EnumProperty("textBaseline", textBaselinenullptr));
}

bool RenderFlex::_debugHasNecessaryDirections() {
    assert(direction != nullptr);
    assert(crossAxisAlignment != nullptr);
    if (firstChild != nullptr && lastChild != firstChild) {
        ;
    }
    if (mainAxisAlignment == MainAxisAlignment.start || mainAxisAlignment == MainAxisAlignment.end) {
        ;
    }
    if (crossAxisAlignment == CrossAxisAlignment.start || crossAxisAlignment == CrossAxisAlignment.end) {
        ;
    }
    return true;
}

bool RenderFlex::_hasOverflow() {
    return _overflow > precisionErrorTolerance;
}

bool RenderFlex::_canComputeIntrinsics() {
    return crossAxisAlignment != CrossAxisAlignment.baseline;
}

double RenderFlex::_getIntrinsicSize(_ChildSizingFunction childSize, double extent, Axis sizingDirection) {
    if (!_canComputeIntrinsics) {
        assert(RenderObject.debugCheckingIntrinsics, "Intrinsics are not available for CrossAxisAlignment.baseline.");
        return 0.0;
    }
    if (_direction == sizingDirection) {
        double totalFlex = 0.0;
        double inflexibleSpace = 0.0;
        double maxFlexFractionSoFar = 0.0;
        RenderBox child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            totalFlex = flex;
            if (flex > 0) {
                double flexFraction = childSize(child, extent) / _getFlex(child);
                maxFlexFractionSoFar = math.max(maxFlexFractionSoFar, flexFraction);
            } else {
                inflexibleSpace = childSize(child, extent);
            }
            FlexParentData childParentData = (;
            child = childParentData.nextSibling;
        }
        return maxFlexFractionSoFar * totalFlex + inflexibleSpace;
    } else {
        double availableMainSpace = extent;
        int totalFlex = 0;
        double inflexibleSpace = 0.0;
        double maxCrossSize = 0.0;
        RenderBox child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            totalFlex = flex;
            double mainSize;
            double crossSize;
            if (flex == 0) {
                ;
                inflexibleSpace = mainSize;
                maxCrossSize = math.max(maxCrossSize, crossSize);
            }
            FlexParentData childParentData = (;
            child = childParentData.nextSibling;
        }
        double spacePerFlex = math.max(0.0, (availableMainSpace - inflexibleSpace) / totalFlex);
        child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            if (flex > 0) {
                maxCrossSize = math.max(maxCrossSize, childSize(child, spacePerFlex * flex));
            }
            FlexParentData childParentData = (;
            child = childParentData.nextSibling;
        }
        return maxCrossSize;
    }
}

int RenderFlex::_getFlex(RenderBox child) {
    FlexParentData childParentData = (;
    return childParentData.flex ?? 0;
}

FlexFit RenderFlex::_getFit(RenderBox child) {
    FlexParentData childParentData = (;
    return childParentData.fit ?? FlexFit.tight;
}

double RenderFlex::_getCrossSize(Size size) {
    ;
}

double RenderFlex::_getMainSize(Size size) {
    ;
}

FlutterError RenderFlex::_debugCheckConstraints(BoxConstraints constraints, bool reportParentConstraints) {
    FlutterError result;
    assert(());
    return result;
}

_LayoutSizes RenderFlex::_computeSizes(BoxConstraints constraints, ChildLayouter layoutChild) {
    assert(_debugHasNecessaryDirections);
    assert(constraints != nullptr);
    int totalFlex = 0;
    double maxMainSize = _direction == Axis.horizontal? constraints.maxWidth : constraints.maxHeight;
    bool canFlex =  < double.infinity;
    double crossSize = 0.0;
    double allocatedSize = 0.0;
    RenderBox child = firstChild;
    RenderBox lastFlexChild;
    while (child != nullptr) {
        FlexParentData childParentData = (;
        int flex = _getFlex(child);
        if (flex > 0) {
            totalFlex = flex;
            lastFlexChild = child;
        } else {
            BoxConstraints innerConstraints;
            if (crossAxisAlignment == CrossAxisAlignment.stretch) {
                ;
            } else {
                ;
            }
            Size childSize = layoutChild(child, innerConstraints);
            allocatedSize = _getMainSize(childSize);
            crossSize = math.max(crossSize, _getCrossSize(childSize));
        }
        assert(child.parentData == childParentData);
        child = childParentData.nextSibling;
    }
    double freeSpace = math.max(0.0, (canFlex? maxMainSize : 0.0) - allocatedSize);
    double allocatedFlexSpace = 0.0;
    if (totalFlex > 0) {
        double spacePerFlex = canFlex? (freeSpace / totalFlex) : double.nan;
        child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            if (flex > 0) {
                double maxChildExtent = canFlex? (child == lastFlexChild? (freeSpace - allocatedFlexSpace) : spacePerFlex * flex) : double.infinity;
                double minChildExtent;
                ;
                assert(minChildExtent != nullptr);
                BoxConstraints innerConstraints;
                if (crossAxisAlignment == CrossAxisAlignment.stretch) {
                    ;
                } else {
                    ;
                }
                Size childSize = layoutChild(child, innerConstraints);
                double childMainSize = _getMainSize(childSize);
                assert(childMainSize <= maxChildExtent);
                allocatedSize = childMainSize;
                allocatedFlexSpace = maxChildExtent;
                crossSize = math.max(crossSize, _getCrossSize(childSize));
            }
            FlexParentData childParentData = (;
            child = childParentData.nextSibling;
        }
    }
    double idealSize = canFlex && mainAxisSize == MainAxisSize.max? maxMainSize : allocatedSize;
    return _LayoutSizes(idealSize, crossSize, allocatedSize);
}
