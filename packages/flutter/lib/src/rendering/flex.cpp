#include "flex.hpp"
String FlexParentDataCls::toString() {
    return __s("${super.toString()}; flex=$flex; fit=$fit");
}

bool _startIsTopLeft(Axis direction, TextDirection textDirection, VerticalDirection verticalDirection) {
    assert(direction != nullptr);
    ;
}

RenderFlexCls::RenderFlexCls(List<RenderBox> children, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection) {
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

Axis RenderFlexCls::direction() {
    return _direction;
}

void RenderFlexCls::direction(Axis value) {
    assert(value != nullptr);
    if (_direction != value) {
        _direction = value;
        markNeedsLayout();
    }
}

MainAxisAlignment RenderFlexCls::mainAxisAlignment() {
    return _mainAxisAlignment;
}

void RenderFlexCls::mainAxisAlignment(MainAxisAlignment value) {
    assert(value != nullptr);
    if (_mainAxisAlignment != value) {
        _mainAxisAlignment = value;
        markNeedsLayout();
    }
}

MainAxisSize RenderFlexCls::mainAxisSize() {
    return _mainAxisSize;
}

void RenderFlexCls::mainAxisSize(MainAxisSize value) {
    assert(value != nullptr);
    if (_mainAxisSize != value) {
        _mainAxisSize = value;
        markNeedsLayout();
    }
}

CrossAxisAlignment RenderFlexCls::crossAxisAlignment() {
    return _crossAxisAlignment;
}

void RenderFlexCls::crossAxisAlignment(CrossAxisAlignment value) {
    assert(value != nullptr);
    if (_crossAxisAlignment != value) {
        _crossAxisAlignment = value;
        markNeedsLayout();
    }
}

TextDirection RenderFlexCls::textDirection() {
    return _textDirection;
}

void RenderFlexCls::textDirection(TextDirection value) {
    if (_textDirection != value) {
        _textDirection = value;
        markNeedsLayout();
    }
}

VerticalDirection RenderFlexCls::verticalDirection() {
    return _verticalDirection;
}

void RenderFlexCls::verticalDirection(VerticalDirection value) {
    if (_verticalDirection != value) {
        _verticalDirection = value;
        markNeedsLayout();
    }
}

TextBaseline RenderFlexCls::textBaseline() {
    return _textBaseline;
}

void RenderFlexCls::textBaseline(TextBaseline value) {
    assert(_crossAxisAlignment != CrossAxisAlignmentCls::baseline || value != nullptr);
    if (_textBaseline != value) {
        _textBaseline = value;
        markNeedsLayout();
    }
}

Clip RenderFlexCls::clipBehavior() {
    return _clipBehavior;
}

void RenderFlexCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderFlexCls::setupParentData(RenderBox child) {
    if (!is<FlexParentData>(child->parentData)) {
        child->parentData = make<FlexParentDataCls>();
    }
}

double RenderFlexCls::computeMinIntrinsicWidth(double height) {
    return _getIntrinsicSize(AxisCls::horizontal, height, [=] (RenderBox child,double extent)     {
        child->getMinIntrinsicWidth(extent);
    });
}

double RenderFlexCls::computeMaxIntrinsicWidth(double height) {
    return _getIntrinsicSize(AxisCls::horizontal, height, [=] (RenderBox child,double extent)     {
        child->getMaxIntrinsicWidth(extent);
    });
}

double RenderFlexCls::computeMinIntrinsicHeight(double width) {
    return _getIntrinsicSize(AxisCls::vertical, width, [=] (RenderBox child,double extent)     {
        child->getMinIntrinsicHeight(extent);
    });
}

double RenderFlexCls::computeMaxIntrinsicHeight(double width) {
    return _getIntrinsicSize(AxisCls::vertical, width, [=] (RenderBox child,double extent)     {
        child->getMaxIntrinsicHeight(extent);
    });
}

double RenderFlexCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (_direction == AxisCls::horizontal) {
        return defaultComputeDistanceToHighestActualBaseline(baseline);
    }
    return defaultComputeDistanceToFirstActualBaseline(baseline);
}

Size RenderFlexCls::computeDryLayout(BoxConstraints constraints) {
    if (!_canComputeIntrinsics()) {
        assert(debugCannotComputeDryLayout(__s("Dry layout cannot be computed for CrossAxisAlignment.baseline, which requires a full layout.")));
        return SizeCls::zero;
    }
    FlutterError constraintsError;
    assert([=] () {
        constraintsError = _debugCheckConstraints(constraints, false);
        return true;
    }());
    if (constraintsError != nullptr) {
        assert(debugCannotComputeDryLayout(constraintsError));
        return SizeCls::zero;
    }
    _LayoutSizes sizes = _computeSizes(ChildLayoutHelperCls::dryLayoutChild, constraints);
    ;
}

void RenderFlexCls::performLayout() {
    assert(_debugHasNecessaryDirections());
    BoxConstraints constraints = this->constraints;
    assert([=] () {
        FlutterError constraintsError = _debugCheckConstraints(constraints, true);
        if (constraintsError != nullptr) {
            throw constraintsError;
        }
        return true;
    }());
    _LayoutSizes sizes = _computeSizes(ChildLayoutHelperCls::layoutChild, constraints);
    double allocatedSize = sizes->allocatedSize;
    double actualSize = sizes->mainSize;
    double crossSize = sizes->crossSize;
    double maxBaselineDistance = 0.0;
    if (crossAxisAlignment() == CrossAxisAlignmentCls::baseline) {
        RenderBox child = firstChild;
        double maxSizeAboveBaseline = 0;
        double maxSizeBelowBaseline = 0;
        while (child != nullptr) {
            assert([=] () {
                if (textBaseline() == nullptr) {
                    throw make<FlutterErrorCls>(__s("To use FlexAlignItems.baseline, you must also specify which baseline to use using the "baseline" argument."));
                }
                return true;
            }());
            double distance = child->getDistanceToBaseline(textBaseline()!true);
            if (distance != nullptr) {
                maxBaselineDistance = math->max(maxBaselineDistance, distance);
                maxSizeAboveBaseline = math->max(distance, maxSizeAboveBaseline);
                maxSizeBelowBaseline = math->max(child->size()->height() - distance, maxSizeBelowBaseline);
                crossSize = math->max(maxSizeAboveBaseline + maxSizeBelowBaseline, crossSize);
            }
            FlexParentData childParentData = as<FlexParentData>(child->parentData!);
            child = childParentData->nextSibling;
        }
    }
    ;
    double actualSizeDelta = actualSize - allocatedSize;
    _overflow = math->max(0.0, -actualSizeDelta);
    double remainingSpace = math->max(0.0, actualSizeDelta);
    double leadingSpace;
    double betweenSpace;
    bool flipMainAxis = !(_startIsTopLeft(direction(), textDirection(), verticalDirection()) | true);
    ;
    double childMainPosition = flipMainAxis? actualSize - leadingSpace : leadingSpace;
    RenderBox child = firstChild;
    while (child != nullptr) {
        FlexParentData childParentData = as<FlexParentData>(child->parentData!);
        double childCrossPosition;
        ;
        if (flipMainAxis) {
            childMainPosition -= _getMainSize(child->size());
        }
        ;
        if (flipMainAxis) {
            childMainPosition -= betweenSpace;
        } else {
            childMainPosition += _getMainSize(child->size()) + betweenSpace;
        }
        child = childParentData->nextSibling;
    }
}

bool RenderFlexCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    return defaultHitTestChildren(resultposition);
}

void RenderFlexCls::paint(PaintingContext context, Offset offset) {
    if (!_hasOverflow()) {
        defaultPaint(context, offset);
        return;
    }
    if (size->isEmpty) {
        return;
    }
    _clipRectLayer->layer() = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, defaultPaintclipBehavior(), _clipRectLayer->layer());
    assert([=] () {
        List<DiagnosticsNode> debugOverflowHints = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
        Rect overflowChildRect;
        ;
        paintOverflowIndicator(context, offset, OffsetCls::zero & size, overflowChildRectdebugOverflowHints);
        return true;
    }());
}

void RenderFlexCls::dispose() {
    _clipRectLayer->layer() = nullptr;
    super->dispose();
}

Rect RenderFlexCls::describeApproximatePaintClip(RenderObject child) {
    ;
}

String RenderFlexCls::toStringShort() {
    String header = super->toStringShort();
    if (!kReleaseMode) {
        if (_hasOverflow()) {
            header += __s(" OVERFLOWING");
        }
    }
    return header;
}

void RenderFlexCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Axis>make<EnumPropertyCls>(__s("direction"), direction()));
    properties->add(<MainAxisAlignment>make<EnumPropertyCls>(__s("mainAxisAlignment"), mainAxisAlignment()));
    properties->add(<MainAxisSize>make<EnumPropertyCls>(__s("mainAxisSize"), mainAxisSize()));
    properties->add(<CrossAxisAlignment>make<EnumPropertyCls>(__s("crossAxisAlignment"), crossAxisAlignment()));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection()nullptr));
    properties->add(<VerticalDirection>make<EnumPropertyCls>(__s("verticalDirection"), verticalDirection()nullptr));
    properties->add(<TextBaseline>make<EnumPropertyCls>(__s("textBaseline"), textBaseline()nullptr));
}

bool RenderFlexCls::_debugHasNecessaryDirections() {
    assert(direction() != nullptr);
    assert(crossAxisAlignment() != nullptr);
    if (firstChild != nullptr && lastChild != firstChild) {
        ;
    }
    if (mainAxisAlignment() == MainAxisAlignmentCls::start || mainAxisAlignment() == MainAxisAlignmentCls::end) {
        ;
    }
    if (crossAxisAlignment() == CrossAxisAlignmentCls::start || crossAxisAlignment() == CrossAxisAlignmentCls::end) {
        ;
    }
    return true;
}

bool RenderFlexCls::_hasOverflow() {
    return _overflow > precisionErrorTolerance;
}

bool RenderFlexCls::_canComputeIntrinsics() {
    return crossAxisAlignment() != CrossAxisAlignmentCls::baseline;
}

double RenderFlexCls::_getIntrinsicSize(_ChildSizingFunction childSize, double extent, Axis sizingDirection) {
    if (!_canComputeIntrinsics()) {
        assert(RenderObjectCls::debugCheckingIntrinsics, __s("Intrinsics are not available for CrossAxisAlignment.baseline."));
        return 0.0;
    }
    if (_direction == sizingDirection) {
        double totalFlex = 0.0;
        double inflexibleSpace = 0.0;
        double maxFlexFractionSoFar = 0.0;
        RenderBox child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            totalFlex += flex;
            if (flex > 0) {
                double flexFraction = childSize(child, extent) / _getFlex(child);
                maxFlexFractionSoFar = math->max(maxFlexFractionSoFar, flexFraction);
            } else {
                inflexibleSpace += childSize(child, extent);
            }
            FlexParentData childParentData = as<FlexParentData>(child->parentData!);
            child = childParentData->nextSibling;
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
            totalFlex += flex;
            double mainSize;
            double crossSize;
            if (flex == 0) {
                ;
                inflexibleSpace += mainSize;
                maxCrossSize = math->max(maxCrossSize, crossSize);
            }
            FlexParentData childParentData = as<FlexParentData>(child->parentData!);
            child = childParentData->nextSibling;
        }
        double spacePerFlex = math->max(0.0, (availableMainSpace - inflexibleSpace) / totalFlex);
        child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            if (flex > 0) {
                maxCrossSize = math->max(maxCrossSize, childSize(child, spacePerFlex * flex));
            }
            FlexParentData childParentData = as<FlexParentData>(child->parentData!);
            child = childParentData->nextSibling;
        }
        return maxCrossSize;
    }
}

int RenderFlexCls::_getFlex(RenderBox child) {
    FlexParentData childParentData = as<FlexParentData>(child->parentData!);
    return childParentData->flex | 0;
}

FlexFit RenderFlexCls::_getFit(RenderBox child) {
    FlexParentData childParentData = as<FlexParentData>(child->parentData!);
    return childParentData->fit | FlexFitCls::tight;
}

double RenderFlexCls::_getCrossSize(Size size) {
    ;
}

double RenderFlexCls::_getMainSize(Size size) {
    ;
}

FlutterError RenderFlexCls::_debugCheckConstraints(BoxConstraints constraints, bool reportParentConstraints) {
    FlutterError result;
    assert([=] () {
        double maxMainSize = _direction == AxisCls::horizontal? constraints->maxWidth : constraints->maxHeight;
        bool canFlex =  < double->infinity;
        RenderBox child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            if (flex > 0) {
                String identity = _direction == AxisCls::horizontal? __s("row") : __s("column");
                String axis = _direction == AxisCls::horizontal? __s("horizontal") : __s("vertical");
                String dimension = _direction == AxisCls::horizontal? __s("width") : __s("height");
                DiagnosticsNode error, message;
                List<DiagnosticsNode> addendum = makeList();
                if (!canFlex && (mainAxisSize() == MainAxisSizeCls::max || _getFit(child) == FlexFitCls::tight)) {
                    error = make<ErrorSummaryCls>(__s("RenderFlex children have non-zero flex but incoming $dimension constraints are unbounded."));
                    message = make<ErrorDescriptionCls>(__s("When a $identity is in a parent that does not provide a finite $dimension constraint, for example if it is in a $axis scrollable, it will try to shrink-wrap its children along the $axis axis. Setting a flex on a child (e.g. using Expanded) indicates that the child is to expand to fill the remaining space in the $axis direction."));
                    if (reportParentConstraints) {
                        RenderBox node = this;
                        ;
                        if (node != nullptr) {
                            addendum->add(node->describeForError(__s("The nearest ancestor providing an unbounded width constraint is")));
                        }
                    }
                    addendum->add(make<ErrorHintCls>(__s("See also: https://flutter.dev/layout/")));
                } else {
                    return true;
                }
                            List<DiagnosticsNode> list1 = make<ListCls<>>();            list1.add(ArrayItem);            list1.add(ArrayItem);            list1.add(ArrayItem);            list1.add(ArrayItem);            list1.add(ArrayItem);            list1.add(ArrayItem);            list1.add(ArrayItem);            for (auto _x1 : addendum) {            {                list1.add(_x1);            }list1.add(ArrayItem);result = FlutterErrorCls->fromParts(list1);
                return true;
            }
            child = childAfter(child);
        }
        return true;
    }());
    return result;
}

_LayoutSizes RenderFlexCls::_computeSizes(BoxConstraints constraints, ChildLayouter layoutChild) {
    assert(_debugHasNecessaryDirections());
    assert(constraints != nullptr);
    int totalFlex = 0;
    double maxMainSize = _direction == AxisCls::horizontal? constraints->maxWidth : constraints->maxHeight;
    bool canFlex =  < double->infinity;
    double crossSize = 0.0;
    double allocatedSize = 0.0;
    RenderBox child = firstChild;
    RenderBox lastFlexChild;
    while (child != nullptr) {
        FlexParentData childParentData = as<FlexParentData>(child->parentData!);
        int flex = _getFlex(child);
        if (flex > 0) {
            totalFlex += flex;
            lastFlexChild = child;
        } else {
            BoxConstraints innerConstraints;
            if (crossAxisAlignment() == CrossAxisAlignmentCls::stretch) {
                ;
            } else {
                ;
            }
            Size childSize = layoutChild(child, innerConstraints);
            allocatedSize += _getMainSize(childSize);
            crossSize = math->max(crossSize, _getCrossSize(childSize));
        }
        assert(child->parentData == childParentData);
        child = childParentData->nextSibling;
    }
    double freeSpace = math->max(0.0, (canFlex? maxMainSize : 0.0) - allocatedSize);
    double allocatedFlexSpace = 0.0;
    if (totalFlex > 0) {
        double spacePerFlex = canFlex? (freeSpace / totalFlex) : double->nan;
        child = firstChild;
        while (child != nullptr) {
            int flex = _getFlex(child);
            if (flex > 0) {
                double maxChildExtent = canFlex? (child == lastFlexChild? (freeSpace - allocatedFlexSpace) : spacePerFlex * flex) : double->infinity;
                double minChildExtent;
                ;
                assert(minChildExtent != nullptr);
                BoxConstraints innerConstraints;
                if (crossAxisAlignment() == CrossAxisAlignmentCls::stretch) {
                    ;
                } else {
                    ;
                }
                Size childSize = layoutChild(child, innerConstraints);
                double childMainSize = _getMainSize(childSize);
                assert(childMainSize <= maxChildExtent);
                allocatedSize += childMainSize;
                allocatedFlexSpace += maxChildExtent;
                crossSize = math->max(crossSize, _getCrossSize(childSize));
            }
            FlexParentData childParentData = as<FlexParentData>(child->parentData!);
            child = childParentData->nextSibling;
        }
    }
    double idealSize = canFlex && mainAxisSize() == MainAxisSizeCls::max? maxMainSize : allocatedSize;
    return make<_LayoutSizesCls>(idealSize, crossSize, allocatedSize);
}
