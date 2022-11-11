#include "overflow_bar.hpp"
OverflowBarCls::OverflowBarCls(MainAxisAlignment alignment, Unknown children, Clip clipBehavior, Unknown key, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection) {
    {
        assert(spacing != nullptr);
        assert(overflowSpacing != nullptr);
        assert(overflowAlignment != nullptr);
        assert(overflowDirection != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderObject OverflowBarCls::createRenderObject(BuildContext context) {
    return make<_RenderOverflowBarCls>(spacing, alignment, overflowSpacing, overflowAlignment, overflowDirection, textDirection | DirectionalityCls->of(context), clipBehavior);
}

void OverflowBarCls::updateRenderObject(BuildContext context, RenderObject renderObject) {
    auto _c1 = (as<_RenderOverflowBar>(renderObject));_c1.spacing = auto _c2 = spacing;_c2.alignment = auto _c3 = alignment;_c3.overflowSpacing = auto _c4 = overflowSpacing;_c4.overflowAlignment = auto _c5 = overflowAlignment;_c5.overflowDirection = auto _c6 = overflowDirection;_c6.textDirection = auto _c7 = textDirection | DirectionalityCls->of(context);_c7.clipBehavior = clipBehavior;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

void OverflowBarCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("spacing"), spacing, 0));
    properties->add(<MainAxisAlignment>make<EnumPropertyCls>(__s("alignment"), alignment, nullptr));
    properties->add(make<DoublePropertyCls>(__s("overflowSpacing"), overflowSpacing, 0));
    properties->add(<OverflowBarAlignment>make<EnumPropertyCls>(__s("overflowAlignment"), overflowAlignment, OverflowBarAlignmentCls::start));
    properties->add(<VerticalDirection>make<EnumPropertyCls>(__s("overflowDirection"), overflowDirection, VerticalDirectionCls::down));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
}

double _RenderOverflowBarCls::spacing() {
    return _spacing;
}

void _RenderOverflowBarCls::spacing(double value) {
    assert(value != nullptr);
    if (_spacing == value) {
        return;
    }
    _spacing = value;
    markNeedsLayout();
}

MainAxisAlignment _RenderOverflowBarCls::alignment() {
    return _alignment;
}

void _RenderOverflowBarCls::alignment(MainAxisAlignment value) {
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    markNeedsLayout();
}

double _RenderOverflowBarCls::overflowSpacing() {
    return _overflowSpacing;
}

void _RenderOverflowBarCls::overflowSpacing(double value) {
    assert(value != nullptr);
    if (_overflowSpacing == value) {
        return;
    }
    _overflowSpacing = value;
    markNeedsLayout();
}

OverflowBarAlignment _RenderOverflowBarCls::overflowAlignment() {
    return _overflowAlignment;
}

void _RenderOverflowBarCls::overflowAlignment(OverflowBarAlignment value) {
    assert(value != nullptr);
    if (_overflowAlignment == value) {
        return;
    }
    _overflowAlignment = value;
    markNeedsLayout();
}

VerticalDirection _RenderOverflowBarCls::overflowDirection() {
    return _overflowDirection;
}

void _RenderOverflowBarCls::overflowDirection(VerticalDirection value) {
    assert(value != nullptr);
    if (_overflowDirection == value) {
        return;
    }
    _overflowDirection = value;
    markNeedsLayout();
}

TextDirection _RenderOverflowBarCls::textDirection() {
    return _textDirection;
}

void _RenderOverflowBarCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsLayout();
}

Clip _RenderOverflowBarCls::clipBehavior() {
    return _clipBehavior;
}

void _RenderOverflowBarCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value == _clipBehavior) {
        return;
    }
    _clipBehavior = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void _RenderOverflowBarCls::setupParentData(RenderBox child) {
    if (!is<_OverflowBarParentData>(child->parentData)) {
        child->parentData = make<_OverflowBarParentDataCls>();
    }
}

double _RenderOverflowBarCls::computeMinIntrinsicHeight(double width) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double barWidth = 0.0;
    while (child != nullptr) {
        barWidth += child->getMinIntrinsicWidth(double->infinity);
        child = childAfter(child);
    }
    barWidth += spacing() * (childCount - 1);
    double height = 0.0;
    if (barWidth > width) {
        child = firstChild;
        while (child != nullptr) {
            height += child->getMinIntrinsicHeight(width);
            child = childAfter(child);
        }
        return height + overflowSpacing() * (childCount - 1);
    } else {
        child = firstChild;
        while (child != nullptr) {
            height = math->max(height, child->getMinIntrinsicHeight(width));
            child = childAfter(child);
        }
        return height;
    }
}

double _RenderOverflowBarCls::computeMaxIntrinsicHeight(double width) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double barWidth = 0.0;
    while (child != nullptr) {
        barWidth += child->getMinIntrinsicWidth(double->infinity);
        child = childAfter(child);
    }
    barWidth += spacing() * (childCount - 1);
    double height = 0.0;
    if (barWidth > width) {
        child = firstChild;
        while (child != nullptr) {
            height += child->getMaxIntrinsicHeight(width);
            child = childAfter(child);
        }
        return height + overflowSpacing() * (childCount - 1);
    } else {
        child = firstChild;
        while (child != nullptr) {
            height = math->max(height, child->getMaxIntrinsicHeight(width));
            child = childAfter(child);
        }
        return height;
    }
}

double _RenderOverflowBarCls::computeMinIntrinsicWidth(double height) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double width = 0.0;
    while (child != nullptr) {
        width += child->getMinIntrinsicWidth(double->infinity);
        child = childAfter(child);
    }
    return width + spacing() * (childCount - 1);
}

double _RenderOverflowBarCls::computeMaxIntrinsicWidth(double height) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return 0;
    }
    double width = 0.0;
    while (child != nullptr) {
        width += child->getMaxIntrinsicWidth(double->infinity);
        child = childAfter(child);
    }
    return width + spacing() * (childCount - 1);
}

double _RenderOverflowBarCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    return defaultComputeDistanceToHighestActualBaseline(baseline);
}

Size _RenderOverflowBarCls::computeDryLayout(BoxConstraints constraints) {
    RenderBox child = firstChild;
    if (child == nullptr) {
        return constraints->smallest();
    }
    BoxConstraints childConstraints = constraints->loosen();
    double childrenWidth = 0.0;
    double maxChildHeight = 0.0;
    double y = 0.0;
    while (child != nullptr) {
        Size childSize = child->getDryLayout(childConstraints);
        childrenWidth += childSize->width();
        maxChildHeight = math->max(maxChildHeight, childSize->height());
        y += childSize->height() + overflowSpacing();
        child = childAfter(child);
    }
    double actualWidth = childrenWidth + spacing() * (childCount - 1);
    if (actualWidth > constraints->maxWidth) {
        return constraints->constrain(make<SizeCls>(constraints->maxWidth, y - overflowSpacing()));
    } else {
        double overallWidth = alignment() == nullptr? actualWidth : constraints->maxWidth;
        return constraints->constrain(make<SizeCls>(overallWidth, maxChildHeight));
    }
}

void _RenderOverflowBarCls::performLayout() {
    RenderBox child = firstChild;
    if (child == nullptr) {
        size() = constraints()->smallest();
        return;
    }
    BoxConstraints childConstraints = constraints()->loosen();
    double childrenWidth = 0;
    double maxChildHeight = 0;
    double maxChildWidth = 0;
    while (child != nullptr) {
        child->layout(childConstraints, true);
        childrenWidth += child->size()->width();
        maxChildHeight = math->max(maxChildHeight, child->size()->height());
        maxChildWidth = math->max(maxChildWidth, child->size()->width());
        child = childAfter(child);
    }
    bool rtl = textDirection() == TextDirectionCls::rtl;
    double actualWidth = childrenWidth + spacing() * (childCount - 1);
    if (actualWidth > constraints()->maxWidth) {
        child = overflowDirection() == VerticalDirectionCls::down? firstChild : lastChild;
        InlineMethod;
        double y = 0;
        while (child != nullptr) {
            _OverflowBarParentData childParentData = as<_OverflowBarParentData>(child->parentData!);
            double x = 0;
            ;
            assert(x != nullptr);
            childParentData->offset = make<OffsetCls>(x, y);
            y += child->size()->height() + overflowSpacing();
            child = nextChild();
        }
        size() = constraints()->constrain(make<SizeCls>(constraints()->maxWidth, y - overflowSpacing()));
    } else {
        child = firstChild;
        double firstChildWidth = child!->size()->width();
        double overallWidth = alignment() == nullptr? actualWidth : constraints()->maxWidth;
        size() = constraints()->constrain(make<SizeCls>(overallWidth, maxChildHeight));
        double x;
        double layoutSpacing = spacing();
        ;
        while (child != nullptr) {
            _OverflowBarParentData childParentData = as<_OverflowBarParentData>(child->parentData!);
            childParentData->offset = make<OffsetCls>(x, (maxChildHeight - child->size()->height()) / 2);
            if (!rtl) {
                x += child->size()->width() + layoutSpacing;
            }
            child = childAfter(child);
            if (rtl && child != nullptr) {
                x -= child->size()->width() + layoutSpacing;
            }
        }
    }
}

bool _RenderOverflowBarCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    return defaultHitTestChildren(result, position);
}

void _RenderOverflowBarCls::paint(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

void _RenderOverflowBarCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("spacing"), spacing(), 0));
    properties->add(make<DoublePropertyCls>(__s("overflowSpacing"), overflowSpacing(), 0));
    properties->add(<OverflowBarAlignment>make<EnumPropertyCls>(__s("overflowAlignment"), overflowAlignment(), OverflowBarAlignmentCls::start));
    properties->add(<VerticalDirection>make<EnumPropertyCls>(__s("overflowDirection"), overflowDirection(), VerticalDirectionCls::down));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection(), nullptr));
}

_RenderOverflowBarCls::_RenderOverflowBarCls(MainAxisAlignment alignment, List<RenderBox> children, Clip clipBehavior, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection) {
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
