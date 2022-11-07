#include "overflow_bar.hpp"
OverflowBar::OverflowBar(MainAxisAlignment alignment, Unknown, Clip clipBehavior, Unknown, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection) {
    {
        assert(spacing != nullptr);
        assert(overflowSpacing != nullptr);
        assert(overflowAlignment != nullptr);
        assert(overflowDirection != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderObject OverflowBar::createRenderObject(BuildContext context) {
    return _RenderOverflowBar(spacing, alignment, overflowSpacing, overflowAlignment, overflowDirection, textDirection ?? Directionality.of(context), clipBehavior);
}

void OverflowBar::updateRenderObject(BuildContext context, RenderObject renderObject) {
    ;
}

void OverflowBar::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("spacing", spacing0));
    properties.add(<MainAxisAlignment>EnumProperty("alignment", alignmentnullptr));
    properties.add(DoubleProperty("overflowSpacing", overflowSpacing0));
    properties.add(<OverflowBarAlignment>EnumProperty("overflowAlignment", overflowAlignmentOverflowBarAlignment.start));
    properties.add(<VerticalDirection>EnumProperty("overflowDirection", overflowDirectionVerticalDirection.down));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
}

double _RenderOverflowBar::spacing() {
    return _spacing;
}

void _RenderOverflowBar::spacing(double value) {
    assert(value != nullptr);
    if (_spacing == value) {
        return;
    }
    _spacing = value;
    markNeedsLayout();
}

MainAxisAlignment _RenderOverflowBar::alignment() {
    return _alignment;
}

void _RenderOverflowBar::alignment(MainAxisAlignment value) {
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    markNeedsLayout();
}

double _RenderOverflowBar::overflowSpacing() {
    return _overflowSpacing;
}

void _RenderOverflowBar::overflowSpacing(double value) {
    assert(value != nullptr);
    if (_overflowSpacing == value) {
        return;
    }
    _overflowSpacing = value;
    markNeedsLayout();
}

OverflowBarAlignment _RenderOverflowBar::overflowAlignment() {
    return _overflowAlignment;
}

void _RenderOverflowBar::overflowAlignment(OverflowBarAlignment value) {
    assert(value != nullptr);
    if (_overflowAlignment == value) {
        return;
    }
    _overflowAlignment = value;
    markNeedsLayout();
}

VerticalDirection _RenderOverflowBar::overflowDirection() {
    return _overflowDirection;
}

void _RenderOverflowBar::overflowDirection(VerticalDirection value) {
    assert(value != nullptr);
    if (_overflowDirection == value) {
        return;
    }
    _overflowDirection = value;
    markNeedsLayout();
}

TextDirection _RenderOverflowBar::textDirection() {
    return _textDirection;
}

void _RenderOverflowBar::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsLayout();
}

Clip _RenderOverflowBar::clipBehavior() {
    return _clipBehavior;
}

void _RenderOverflowBar::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value == _clipBehavior) {
        return;
    }
    _clipBehavior = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void _RenderOverflowBar::setupParentData(RenderBox child) {
    if (child.parentData is! _OverflowBarParentData) {
        child.parentData = _OverflowBarParentData();
    }
}

double _RenderOverflowBar::computeMinIntrinsicHeight(double width) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double barWidth = 0.0;
    while (child != nullptr) {
        barWidth = child.getMinIntrinsicWidth(double.infinity);
        child = childAfter(child);
    }
    barWidth = spacing * (childCount - 1);
    double height = 0.0;
    if (barWidth > width) {
        child = firstChild;
        while (child != nullptr) {
            height = child.getMinIntrinsicHeight(width);
            child = childAfter(child);
        }
        return height + overflowSpacing * (childCount - 1);
    } else {
        child = firstChild;
        while (child != nullptr) {
            height = math.max(height, child.getMinIntrinsicHeight(width));
            child = childAfter(child);
        }
        return height;
    }
}

double _RenderOverflowBar::computeMaxIntrinsicHeight(double width) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double barWidth = 0.0;
    while (child != nullptr) {
        barWidth = child.getMinIntrinsicWidth(double.infinity);
        child = childAfter(child);
    }
    barWidth = spacing * (childCount - 1);
    double height = 0.0;
    if (barWidth > width) {
        child = firstChild;
        while (child != nullptr) {
            height = child.getMaxIntrinsicHeight(width);
            child = childAfter(child);
        }
        return height + overflowSpacing * (childCount - 1);
    } else {
        child = firstChild;
        while (child != nullptr) {
            height = math.max(height, child.getMaxIntrinsicHeight(width));
            child = childAfter(child);
        }
        return height;
    }
}

double _RenderOverflowBar::computeMinIntrinsicWidth(double height) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double width = 0.0;
    while (child != nullptr) {
        width = child.getMinIntrinsicWidth(double.infinity);
        child = childAfter(child);
    }
    return width + spacing * (childCount - 1);
}

double _RenderOverflowBar::computeMaxIntrinsicWidth(double height) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double width = 0.0;
    while (child != nullptr) {
        width = child.getMaxIntrinsicWidth(double.infinity);
        child = childAfter(child);
    }
    return width + spacing * (childCount - 1);
}

double _RenderOverflowBar::computeDistanceToActualBaseline(TextBaseline baseline) {
    return defaultComputeDistanceToHighestActualBaseline(baseline);
}

Size _RenderOverflowBar::computeDryLayout(BoxConstraints constraints) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return constraints.smallest;
    }
    BoxConstraints childConstraints = constraints.loosen();
    double childrenWidth = 0.0;
    double maxChildHeight = 0.0;
    double y = 0.0;
    while (child != nullptr) {
        Size childSize = child.getDryLayout(childConstraints);
        childrenWidth = childSize.width;
        maxChildHeight = math.max(maxChildHeight, childSize.height);
        y = childSize.height + overflowSpacing;
        child = childAfter(child);
    }
    double actualWidth = childrenWidth + spacing * (childCount - 1);
    if (actualWidth > constraints.maxWidth) {
        return constraints.constrain(Size(constraints.maxWidth, y - overflowSpacing));
    } else {
        double overallWidth = alignment == nullptr? actualWidth : constraints.maxWidth;
        return constraints.constrain(Size(overallWidth, maxChildHeight));
    }
}

void _RenderOverflowBar::performLayout() {
    RenderBox child = firstChild;
    if (child == nullptr) {
        size = constraints.smallest;
        return;
    }
    BoxConstraints childConstraints = constraints.loosen();
    double childrenWidth = 0;
    double maxChildHeight = 0;
    double maxChildWidth = 0;
    while (child != nullptr) {
        child.layout(childConstraintstrue);
        childrenWidth = child.size.width;
        maxChildHeight = math.max(maxChildHeight, child.size.height);
        maxChildWidth = math.max(maxChildWidth, child.size.width);
        child = childAfter(child);
    }
    bool rtl = textDirection == TextDirection.rtl;
    double actualWidth = childrenWidth + spacing * (childCount - 1);
    if (actualWidth > constraints.maxWidth) {
        child = overflowDirection == VerticalDirection.down? firstChild : lastChild;
        ;
        double y = 0;
        while (child != nullptr) {
            _OverflowBarParentData childParentData = (;
            double x = 0;
            ;
            assert(x != nullptr);
            childParentData.offset = Offset(x, y);
            y = child.size.height + overflowSpacing;
            child = nextChild();
        }
        size = constraints.constrain(Size(constraints.maxWidth, y - overflowSpacing));
    } else {
        child = firstChild;
        double firstChildWidth = child!.size.width;
        double overallWidth = alignment == nullptr? actualWidth : constraints.maxWidth;
        size = constraints.constrain(Size(overallWidth, maxChildHeight));
        double x;
        double layoutSpacing = spacing;
        ;
        while (child != nullptr) {
            _OverflowBarParentData childParentData = (;
            childParentData.offset = Offset(x, (maxChildHeight - child.size.height) / 2);
            if (!rtl) {
                x = child.size.width + layoutSpacing;
            }
            child = childAfter(child);
            if (rtl && child != nullptr) {
                x = child.size.width + layoutSpacing;
            }
        }
    }
}

bool _RenderOverflowBar::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

void _RenderOverflowBar::paint(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

void _RenderOverflowBar::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("spacing", spacing0));
    properties.add(DoubleProperty("overflowSpacing", overflowSpacing0));
    properties.add(<OverflowBarAlignment>EnumProperty("overflowAlignment", overflowAlignmentOverflowBarAlignment.start));
    properties.add(<VerticalDirection>EnumProperty("overflowDirection", overflowDirectionVerticalDirection.down));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
}

_RenderOverflowBar::_RenderOverflowBar(MainAxisAlignment alignment, List<RenderBox> children, Clip clipBehavior, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection) {
    {
        assert(spacing != nullptr);
        assert(overflowSpacing != nullptr);
        assert(overflowAlignment != nullptr);
        assert(textDirection != nullptr);
        assert(clipBehavior != nullptr);
        _spacing = spacing;
        _alignment = alignment;
        _overflowSpacing = overflowSpacing;
        _overflowAlignment = overflowAlignment;
        _overflowDirection = overflowDirection;
        _textDirection = textDirection;
        _clipBehavior = clipBehavior;
    }
    {
        addAll(children);
    }
}
