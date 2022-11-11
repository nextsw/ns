#include "shifted_box.hpp"
RenderShiftedBoxCls::RenderShiftedBoxCls(RenderBox child) {
    {
        this->child = child;
    }
}

double RenderShiftedBoxCls::computeMinIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!->getMinIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderShiftedBoxCls::computeMaxIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!->getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderShiftedBoxCls::computeMinIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!->getMinIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderShiftedBoxCls::computeMaxIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!->getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderShiftedBoxCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    double result;
    if (child != nullptr) {
        assert(!debugNeedsLayout);
        result = child!->getDistanceToActualBaseline(baseline);
        BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
        if (result != nullptr) {
            result = childParentData->offset->dy;
        }
    } else {
        result = super->computeDistanceToActualBaseline(baseline);
    }
    return result;
}

void RenderShiftedBoxCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
        context->paintChild(child!, childParentData->offset + offset);
    }
}

bool RenderShiftedBoxCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (child != nullptr) {
        BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
        return result->addWithPaintOffset(childParentData->offset, position, [=] (BoxHitTestResult result,Offset transformed) {
            assert(transformed == position - childParentData->offset);
            return child!->hitTest(resulttransformed);
        });
    }
    return false;
}

RenderPaddingCls::RenderPaddingCls(RenderBox child, EdgeInsetsGeometry padding, TextDirection textDirection) : RenderShiftedBox(child) {
    {
        assert(padding != nullptr);
        assert(padding->isNonNegative());
        _textDirection = textDirection;
        _padding = padding;
    }
}

EdgeInsetsGeometry RenderPaddingCls::padding() {
    return _padding;
}

void RenderPaddingCls::padding(EdgeInsetsGeometry value) {
    assert(value != nullptr);
    assert(value->isNonNegative());
    if (_padding == value) {
        return;
    }
    _padding = value;
    _markNeedResolution();
}

TextDirection RenderPaddingCls::textDirection() {
    return _textDirection;
}

void RenderPaddingCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

double RenderPaddingCls::computeMinIntrinsicWidth(double height) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!->left + _resolvedPadding!->right;
    double totalVerticalPadding = _resolvedPadding!->top + _resolvedPadding!->bottom;
    if (child != nullptr) {
        return child!->getMinIntrinsicWidth(math->max(0.0, height - totalVerticalPadding)) + totalHorizontalPadding;
    }
    return totalHorizontalPadding;
}

double RenderPaddingCls::computeMaxIntrinsicWidth(double height) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!->left + _resolvedPadding!->right;
    double totalVerticalPadding = _resolvedPadding!->top + _resolvedPadding!->bottom;
    if (child != nullptr) {
        return child!->getMaxIntrinsicWidth(math->max(0.0, height - totalVerticalPadding)) + totalHorizontalPadding;
    }
    return totalHorizontalPadding;
}

double RenderPaddingCls::computeMinIntrinsicHeight(double width) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!->left + _resolvedPadding!->right;
    double totalVerticalPadding = _resolvedPadding!->top + _resolvedPadding!->bottom;
    if (child != nullptr) {
        return child!->getMinIntrinsicHeight(math->max(0.0, width - totalHorizontalPadding)) + totalVerticalPadding;
    }
    return totalVerticalPadding;
}

double RenderPaddingCls::computeMaxIntrinsicHeight(double width) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!->left + _resolvedPadding!->right;
    double totalVerticalPadding = _resolvedPadding!->top + _resolvedPadding!->bottom;
    if (child != nullptr) {
        return child!->getMaxIntrinsicHeight(math->max(0.0, width - totalHorizontalPadding)) + totalVerticalPadding;
    }
    return totalVerticalPadding;
}

Size RenderPaddingCls::computeDryLayout(BoxConstraints constraints) {
    _resolve();
    assert(_resolvedPadding != nullptr);
    if (child == nullptr) {
        return constraints->constrain(make<SizeCls>(_resolvedPadding!->left + _resolvedPadding!->right, _resolvedPadding!->top + _resolvedPadding!->bottom));
    }
    BoxConstraints innerConstraints = constraints->deflate(_resolvedPadding!);
    Size childSize = child!->getDryLayout(innerConstraints);
    return constraints->constrain(make<SizeCls>(_resolvedPadding!->left + childSize->width + _resolvedPadding!->right, _resolvedPadding!->top + childSize->height + _resolvedPadding!->bottom));
}

void RenderPaddingCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    _resolve();
    assert(_resolvedPadding != nullptr);
    if (child == nullptr) {
        size = constraints->constrain(make<SizeCls>(_resolvedPadding!->left + _resolvedPadding!->right, _resolvedPadding!->top + _resolvedPadding!->bottom));
        return;
    }
    BoxConstraints innerConstraints = constraints->deflate(_resolvedPadding!);
    child!->layout(innerConstraintstrue);
    BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
    childParentData->offset = make<OffsetCls>(_resolvedPadding!->left, _resolvedPadding!->top);
    size = constraints->constrain(make<SizeCls>(_resolvedPadding!->left + child!->size->width + _resolvedPadding!->right, _resolvedPadding!->top + child!->size->height + _resolvedPadding!->bottom));
}

void RenderPaddingCls::debugPaintSize(PaintingContext context, Offset offset) {
    super->debugPaintSize(context, offset);
    assert([=] () {
        Rect outerRect = offset & size;
        debugPaintPadding(context->canvas, outerRect, child != nullptr? _resolvedPadding!->deflateRect(outerRect) : nullptr);
        return true;
    }());
}

void RenderPaddingCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirectionnullptr));
}

void RenderPaddingCls::_resolve() {
    if (_resolvedPadding != nullptr) {
        return;
    }
    _resolvedPadding = padding->resolve(textDirection);
    assert(_resolvedPadding!->isNonNegative);
}

void RenderPaddingCls::_markNeedResolution() {
    _resolvedPadding = nullptr;
    markNeedsLayout();
}

RenderAligningShiftedBoxCls::RenderAligningShiftedBoxCls(AlignmentGeometry alignment, RenderBox child, TextDirection textDirection) : RenderShiftedBox(child) {
    {
        assert(alignment != nullptr);
        _alignment = alignment;
        _textDirection = textDirection;
    }
}

AlignmentGeometry RenderAligningShiftedBoxCls::alignment() {
    return _alignment;
}

void RenderAligningShiftedBoxCls::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    _markNeedResolution();
}

TextDirection RenderAligningShiftedBoxCls::textDirection() {
    return _textDirection;
}

void RenderAligningShiftedBoxCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

void RenderAligningShiftedBoxCls::alignChild() {
    _resolve();
    assert(child != nullptr);
    assert(!child!->debugNeedsLayout);
    assert(child!->hasSize());
    assert(hasSize);
    assert(_resolvedAlignment != nullptr);
    BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
    childParentData->offset = _resolvedAlignment!->alongOffset(as<Offset>(size - child!->size));
}

void RenderAligningShiftedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirectionnullptr));
}

void RenderAligningShiftedBoxCls::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment->resolve(textDirection);
}

void RenderAligningShiftedBoxCls::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsLayout();
}

RenderPositionedBoxCls::RenderPositionedBoxCls(Unknown alignment, Unknown child, double heightFactor, Unknown textDirection, double widthFactor) {
    {
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
        _widthFactor = widthFactor;
        _heightFactor = heightFactor;
    }
}

double RenderPositionedBoxCls::widthFactor() {
    return _widthFactor;
}

void RenderPositionedBoxCls::widthFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_widthFactor == value) {
        return;
    }
    _widthFactor = value;
    markNeedsLayout();
}

double RenderPositionedBoxCls::heightFactor() {
    return _heightFactor;
}

void RenderPositionedBoxCls::heightFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_heightFactor == value) {
        return;
    }
    _heightFactor = value;
    markNeedsLayout();
}

Size RenderPositionedBoxCls::computeDryLayout(BoxConstraints constraints) {
    bool shrinkWrapWidth = _widthFactor != nullptr || constraints->maxWidth == double->infinity;
    bool shrinkWrapHeight = _heightFactor != nullptr || constraints->maxHeight == double->infinity;
    if (child != nullptr) {
        Size childSize = child!->getDryLayout(constraints->loosen());
        return constraints->constrain(make<SizeCls>(shrinkWrapWidth? childSize->width * (_widthFactor or 1.0) : double->infinity, shrinkWrapHeight? childSize->height * (_heightFactor or 1.0) : double->infinity));
    }
    return constraints->constrain(make<SizeCls>(shrinkWrapWidth? 0.0 : double->infinity, shrinkWrapHeight? 0.0 : double->infinity));
}

void RenderPositionedBoxCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    bool shrinkWrapWidth = _widthFactor != nullptr || constraints->maxWidth == double->infinity;
    bool shrinkWrapHeight = _heightFactor != nullptr || constraints->maxHeight == double->infinity;
    if (child != nullptr) {
        child!->layout(constraints->loosen()true);
        size = constraints->constrain(make<SizeCls>(shrinkWrapWidth? child!->size->width * (_widthFactor or 1.0) : double->infinity, shrinkWrapHeight? child!->size->height * (_heightFactor or 1.0) : double->infinity));
        alignChild();
    } else {
        size = constraints->constrain(make<SizeCls>(shrinkWrapWidth? 0.0 : double->infinity, shrinkWrapHeight? 0.0 : double->infinity));
    }
}

void RenderPositionedBoxCls::debugPaintSize(PaintingContext context, Offset offset) {
    super->debugPaintSize(context, offset);
    assert([=] () {
        Paint paint;
        if (child != nullptr && !child!->size->isEmpty()) {
            Path path;
                    auto _c1 = make<PaintCls>();        _c1.style = auto _c2 = PaintingStyleCls::stroke;        _c2.strokeWidth = auto _c3 = 1.0;        _c3.color = make<ColorCls>(0xFFFFFF00);        _c3;        _c2;paint = _c1;
            path = make<PathCls>();
            BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
            if (childParentData->offset->dy > 0.0) {
                double headSize = math->min(childParentData->offset->dy * 0.2, 10.0);
                            auto _c4 = path;            _c4.auto _c5 = moveTo(offset->dx + size->width / 2.0, offset->dy);            _c5.auto _c6 = relativeLineTo(0.0, childParentData->offset->dy - headSize);            _c6.auto _c7 = relativeLineTo(headSize, 0.0);            _c7.auto _c8 = relativeLineTo(-headSize, headSize);            _c8.auto _c9 = relativeLineTo(-headSize, -headSize);            _c9.auto _c10 = relativeLineTo(headSize, 0.0);            _c10.auto _c11 = moveTo(offset->dx + size->width / 2.0, offset->dy + size->height);            _c11.auto _c12 = relativeLineTo(0.0, -childParentData->offset->dy + headSize);            _c12.auto _c13 = relativeLineTo(headSize, 0.0);            _c13.auto _c14 = relativeLineTo(-headSize, -headSize);            _c14.auto _c15 = relativeLineTo(-headSize, headSize);            _c15.relativeLineTo(headSize, 0.0);            _c15;            _c14;            _c13;            _c12;            _c11;            _c10;            _c9;            _c8;            _c7;            _c6;            _c5;_c4;
                context->canvas->drawPath(path, paint);
            }
            if (childParentData->offset->dx > 0.0) {
                double headSize = math->min(childParentData->offset->dx * 0.2, 10.0);
                            auto _c16 = path;            _c16.auto _c17 = moveTo(offset->dx, offset->dy + size->height / 2.0);            _c17.auto _c18 = relativeLineTo(childParentData->offset->dx - headSize, 0.0);            _c18.auto _c19 = relativeLineTo(0.0, headSize);            _c19.auto _c20 = relativeLineTo(headSize, -headSize);            _c20.auto _c21 = relativeLineTo(-headSize, -headSize);            _c21.auto _c22 = relativeLineTo(0.0, headSize);            _c22.auto _c23 = moveTo(offset->dx + size->width, offset->dy + size->height / 2.0);            _c23.auto _c24 = relativeLineTo(-childParentData->offset->dx + headSize, 0.0);            _c24.auto _c25 = relativeLineTo(0.0, headSize);            _c25.auto _c26 = relativeLineTo(-headSize, -headSize);            _c26.auto _c27 = relativeLineTo(headSize, -headSize);            _c27.relativeLineTo(0.0, headSize);            _c27;            _c26;            _c25;            _c24;            _c23;            _c22;            _c21;            _c20;            _c19;            _c18;            _c17;_c16;
                context->canvas->drawPath(path, paint);
            }
        } else {
                    auto _c28 = make<PaintCls>();        _c28.color = make<ColorCls>(0x90909090);paint = _c28;
            context->canvas->drawRect(offset & size, paint);
        }
        return true;
    }());
}

void RenderPositionedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("widthFactor"), _widthFactor__s("expand")));
    properties->add(make<DoublePropertyCls>(__s("heightFactor"), _heightFactor__s("expand")));
}

RenderConstrainedOverflowBoxCls::RenderConstrainedOverflowBoxCls(Unknown alignment, Unknown child, double maxHeight, double maxWidth, double minHeight, double minWidth, Unknown textDirection) {
    {
        _minWidth = minWidth;
        _maxWidth = maxWidth;
        _minHeight = minHeight;
        _maxHeight = maxHeight;
    }
}

double RenderConstrainedOverflowBoxCls::minWidth() {
    return _minWidth;
}

void RenderConstrainedOverflowBoxCls::minWidth(double value) {
    if (_minWidth == value) {
        return;
    }
    _minWidth = value;
    markNeedsLayout();
}

double RenderConstrainedOverflowBoxCls::maxWidth() {
    return _maxWidth;
}

void RenderConstrainedOverflowBoxCls::maxWidth(double value) {
    if (_maxWidth == value) {
        return;
    }
    _maxWidth = value;
    markNeedsLayout();
}

double RenderConstrainedOverflowBoxCls::minHeight() {
    return _minHeight;
}

void RenderConstrainedOverflowBoxCls::minHeight(double value) {
    if (_minHeight == value) {
        return;
    }
    _minHeight = value;
    markNeedsLayout();
}

double RenderConstrainedOverflowBoxCls::maxHeight() {
    return _maxHeight;
}

void RenderConstrainedOverflowBoxCls::maxHeight(double value) {
    if (_maxHeight == value) {
        return;
    }
    _maxHeight = value;
    markNeedsLayout();
}

bool RenderConstrainedOverflowBoxCls::sizedByParent() {
    return true;
}

Size RenderConstrainedOverflowBoxCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->biggest();
}

void RenderConstrainedOverflowBoxCls::performLayout() {
    if (child != nullptr) {
        child?->layout(_getInnerConstraints(constraints)true);
        alignChild();
    }
}

void RenderConstrainedOverflowBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("minWidth"), minWidth__s("use parent minWidth constraint")));
    properties->add(make<DoublePropertyCls>(__s("maxWidth"), maxWidth__s("use parent maxWidth constraint")));
    properties->add(make<DoublePropertyCls>(__s("minHeight"), minHeight__s("use parent minHeight constraint")));
    properties->add(make<DoublePropertyCls>(__s("maxHeight"), maxHeight__s("use parent maxHeight constraint")));
}

BoxConstraints RenderConstrainedOverflowBoxCls::_getInnerConstraints(BoxConstraints constraints) {
    return make<BoxConstraintsCls>(_minWidth or constraints->minWidth, _maxWidth or constraints->maxWidth, _minHeight or constraints->minHeight, _maxHeight or constraints->maxHeight);
}

RenderConstraintsTransformBoxCls::RenderConstraintsTransformBoxCls(Unknown alignment, Unknown child, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, Unknown textDirection) {
    {
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        assert(constraintsTransform != nullptr);
        _constraintsTransform = constraintsTransform;
        _clipBehavior = clipBehavior;
    }
}

BoxConstraintsTransform RenderConstraintsTransformBoxCls::constraintsTransform() {
    return _constraintsTransform;
}

void RenderConstraintsTransformBoxCls::constraintsTransform(BoxConstraintsTransform value) {
    if (_constraintsTransform == value) {
        return;
    }
    _constraintsTransform = value;
    bool needsLayout = _childConstraints == nullptr || _childConstraints != value(constraints);
    if (needsLayout) {
        markNeedsLayout();
    }
}

Clip RenderConstraintsTransformBoxCls::clipBehavior() {
    return _clipBehavior;
}

void RenderConstraintsTransformBoxCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

double RenderConstraintsTransformBoxCls::computeMinIntrinsicHeight(double width) {
    return super->computeMinIntrinsicHeight(constraintsTransform(make<BoxConstraintsCls>(width))->maxWidth);
}

double RenderConstraintsTransformBoxCls::computeMaxIntrinsicHeight(double width) {
    return super->computeMaxIntrinsicHeight(constraintsTransform(make<BoxConstraintsCls>(width))->maxWidth);
}

double RenderConstraintsTransformBoxCls::computeMinIntrinsicWidth(double height) {
    return super->computeMinIntrinsicWidth(constraintsTransform(make<BoxConstraintsCls>(height))->maxHeight);
}

double RenderConstraintsTransformBoxCls::computeMaxIntrinsicWidth(double height) {
    return super->computeMaxIntrinsicWidth(constraintsTransform(make<BoxConstraintsCls>(height))->maxHeight);
}

Size RenderConstraintsTransformBoxCls::computeDryLayout(BoxConstraints constraints) {
    Size childSize = child?->getDryLayout(constraintsTransform(constraints));
    return childSize == nullptr? constraints->smallest() : constraints->constrain(childSize);
}

void RenderConstraintsTransformBoxCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    RenderBox child = this->child;
    if (child != nullptr) {
        BoxConstraints childConstraints = constraintsTransform(constraints);
        assert(childConstraints != nullptr);
        assert(childConstraints->isNormalized(), __s("$childConstraints is not normalized"));
        _childConstraints = childConstraints;
        child->layout(childConstraintstrue);
        size = constraints->constrain(child->size);
        alignChild();
        BoxParentData childParentData = as<BoxParentData>(child->parentData!);
        _overflowContainerRect = OffsetCls::zero & size;
        _overflowChildRect = childParentData->offset & child->size;
    } else {
        size = constraints->smallest();
        _overflowContainerRect = RectCls::zero;
        _overflowChildRect = RectCls::zero;
    }
    _isOverflowing = RelativeRectCls->fromRect(_overflowContainerRect, _overflowChildRect)->hasInsets;
}

void RenderConstraintsTransformBoxCls::paint(PaintingContext context, Offset offset) {
    if (child == nullptr || size->isEmpty()) {
        return;
    }
    if (!_isOverflowing) {
        super->paint(context, offset);
        return;
    }
    _clipRectLayer->layer = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, super->paintclipBehavior, _clipRectLayer->layer);
    assert([=] () {
        paintOverflowIndicator(context, offset, _overflowContainerRect, _overflowChildRect);
        return true;
    }());
}

void RenderConstraintsTransformBoxCls::dispose() {
    _clipRectLayer->layer = nullptr;
    super->dispose();
}

Rect RenderConstraintsTransformBoxCls::describeApproximatePaintClip(RenderObject child) {
    ;
}

String RenderConstraintsTransformBoxCls::toStringShort() {
    String header = super->toStringShort();
    if (!kReleaseMode) {
        if (_isOverflowing) {
            header = __s(" OVERFLOWING");
        }
    }
    return header;
}

RenderUnconstrainedBoxCls::RenderUnconstrainedBoxCls(Unknown alignment, Unknown child, Unknown clipBehavior, Axis constrainedAxis, Unknown textDirection) : RenderConstraintsTransformBox(_convertAxis(constrainedAxis)) {
    {
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        _constrainedAxis = constrainedAxis;
    }
}

Axis RenderUnconstrainedBoxCls::constrainedAxis() {
    return _constrainedAxis;
}

void RenderUnconstrainedBoxCls::constrainedAxis(Axis value) {
    if (_constrainedAxis == value) {
        return;
    }
    _constrainedAxis = value;
    constraintsTransform = _convertAxis(constrainedAxis);
}

BoxConstraints RenderUnconstrainedBoxCls::_unconstrained(BoxConstraints constraints) {
    return make<BoxConstraintsCls>();
}

BoxConstraints RenderUnconstrainedBoxCls::_widthConstrained(BoxConstraints constraints) {
    return constraints->widthConstraints();
}

BoxConstraints RenderUnconstrainedBoxCls::_heightConstrained(BoxConstraints constraints) {
    return constraints->heightConstraints();
}

BoxConstraintsTransform RenderUnconstrainedBoxCls::_convertAxis(Axis constrainedAxis) {
    if (constrainedAxis == nullptr) {
        return _unconstrained;
    }
    ;
}

RenderSizedOverflowBoxCls::RenderSizedOverflowBoxCls(Unknown alignment, Unknown child, Size requestedSize, Unknown textDirection) {
    {
        assert(requestedSize != nullptr);
        _requestedSize = requestedSize;
    }
}

Size RenderSizedOverflowBoxCls::requestedSize() {
    return _requestedSize;
}

void RenderSizedOverflowBoxCls::requestedSize(Size value) {
    assert(value != nullptr);
    if (_requestedSize == value) {
        return;
    }
    _requestedSize = value;
    markNeedsLayout();
}

double RenderSizedOverflowBoxCls::computeMinIntrinsicWidth(double height) {
    return _requestedSize->width;
}

double RenderSizedOverflowBoxCls::computeMaxIntrinsicWidth(double height) {
    return _requestedSize->width;
}

double RenderSizedOverflowBoxCls::computeMinIntrinsicHeight(double width) {
    return _requestedSize->height;
}

double RenderSizedOverflowBoxCls::computeMaxIntrinsicHeight(double width) {
    return _requestedSize->height;
}

double RenderSizedOverflowBoxCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (child != nullptr) {
        return child!->getDistanceToActualBaseline(baseline);
    }
    return super->computeDistanceToActualBaseline(baseline);
}

Size RenderSizedOverflowBoxCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->constrain(_requestedSize);
}

void RenderSizedOverflowBoxCls::performLayout() {
    size = constraints->constrain(_requestedSize);
    if (child != nullptr) {
        child!->layout(constraintstrue);
        alignChild();
    }
}

RenderFractionallySizedOverflowBoxCls::RenderFractionallySizedOverflowBoxCls(Unknown alignment, Unknown child, double heightFactor, Unknown textDirection, double widthFactor) {
    {
        _widthFactor = widthFactor;
        _heightFactor = heightFactor;
    }
    {
        assert(_widthFactor == nullptr || _widthFactor! >= 0.0);
        assert(_heightFactor == nullptr || _heightFactor! >= 0.0);
    }
}

double RenderFractionallySizedOverflowBoxCls::widthFactor() {
    return _widthFactor;
}

void RenderFractionallySizedOverflowBoxCls::widthFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_widthFactor == value) {
        return;
    }
    _widthFactor = value;
    markNeedsLayout();
}

double RenderFractionallySizedOverflowBoxCls::heightFactor() {
    return _heightFactor;
}

void RenderFractionallySizedOverflowBoxCls::heightFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_heightFactor == value) {
        return;
    }
    _heightFactor = value;
    markNeedsLayout();
}

double RenderFractionallySizedOverflowBoxCls::computeMinIntrinsicWidth(double height) {
    double result;
    if (child == nullptr) {
        result = super->computeMinIntrinsicWidth(height);
    } else {
        result = child!->getMinIntrinsicWidth(height * (_heightFactor or 1.0));
    }
    assert(result->isFinite);
    return result / (_widthFactor or 1.0);
}

double RenderFractionallySizedOverflowBoxCls::computeMaxIntrinsicWidth(double height) {
    double result;
    if (child == nullptr) {
        result = super->computeMaxIntrinsicWidth(height);
    } else {
        result = child!->getMaxIntrinsicWidth(height * (_heightFactor or 1.0));
    }
    assert(result->isFinite);
    return result / (_widthFactor or 1.0);
}

double RenderFractionallySizedOverflowBoxCls::computeMinIntrinsicHeight(double width) {
    double result;
    if (child == nullptr) {
        result = super->computeMinIntrinsicHeight(width);
    } else {
        result = child!->getMinIntrinsicHeight(width * (_widthFactor or 1.0));
    }
    assert(result->isFinite);
    return result / (_heightFactor or 1.0);
}

double RenderFractionallySizedOverflowBoxCls::computeMaxIntrinsicHeight(double width) {
    double result;
    if (child == nullptr) {
        result = super->computeMaxIntrinsicHeight(width);
    } else {
        result = child!->getMaxIntrinsicHeight(width * (_widthFactor or 1.0));
    }
    assert(result->isFinite);
    return result / (_heightFactor or 1.0);
}

Size RenderFractionallySizedOverflowBoxCls::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        Size childSize = child!->getDryLayout(_getInnerConstraints(constraints));
        return constraints->constrain(childSize);
    }
    return constraints->constrain(_getInnerConstraints(constraints)->constrain(SizeCls::zero));
}

void RenderFractionallySizedOverflowBoxCls::performLayout() {
    if (child != nullptr) {
        child!->layout(_getInnerConstraints(constraints)true);
        size = constraints->constrain(child!->size);
        alignChild();
    } else {
        size = constraints->constrain(_getInnerConstraints(constraints)->constrain(SizeCls::zero));
    }
}

void RenderFractionallySizedOverflowBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("widthFactor"), _widthFactor__s("pass-through")));
    properties->add(make<DoublePropertyCls>(__s("heightFactor"), _heightFactor__s("pass-through")));
}

BoxConstraints RenderFractionallySizedOverflowBoxCls::_getInnerConstraints(BoxConstraints constraints) {
    double minWidth = constraints->minWidth;
    double maxWidth = constraints->maxWidth;
    if (_widthFactor != nullptr) {
        double width = maxWidth * _widthFactor!;
        minWidth = width;
        maxWidth = width;
    }
    double minHeight = constraints->minHeight;
    double maxHeight = constraints->maxHeight;
    if (_heightFactor != nullptr) {
        double height = maxHeight * _heightFactor!;
        minHeight = height;
        maxHeight = height;
    }
    return make<BoxConstraintsCls>(minWidth, maxWidth, minHeight, maxHeight);
}

SingleChildLayoutDelegateCls::SingleChildLayoutDelegateCls(Listenable relayout) {
    {
        _relayout = relayout;
    }
}

Size SingleChildLayoutDelegateCls::getSize(BoxConstraints constraints) {
    return constraints->biggest();
}

BoxConstraints SingleChildLayoutDelegateCls::getConstraintsForChild(BoxConstraints constraints) {
    return constraints;
}

Offset SingleChildLayoutDelegateCls::getPositionForChild(Size childSize, Size size) {
    return OffsetCls::zero;
}

RenderCustomSingleChildLayoutBoxCls::RenderCustomSingleChildLayoutBoxCls(RenderBox child, SingleChildLayoutDelegate delegate) : RenderShiftedBox(child) {
    {
        assert(delegate != nullptr);
        _delegate = delegate;
    }
}

SingleChildLayoutDelegate RenderCustomSingleChildLayoutBoxCls::delegate() {
    return _delegate;
}

void RenderCustomSingleChildLayoutBoxCls::delegate(SingleChildLayoutDelegate newDelegate) {
    assert(newDelegate != nullptr);
    if (_delegate == newDelegate) {
        return;
    }
    SingleChildLayoutDelegate oldDelegate = _delegate;
    if (newDelegate->runtimeType != oldDelegate->runtimeType || newDelegate->shouldRelayout(oldDelegate)) {
        markNeedsLayout();
    }
    _delegate = newDelegate;
    if (attached) {
        oldDelegate->_relayout?->removeListener(markNeedsLayout);
        newDelegate->_relayout?->addListener(markNeedsLayout);
    }
}

void RenderCustomSingleChildLayoutBoxCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _delegate->_relayout?->addListener(markNeedsLayout);
}

void RenderCustomSingleChildLayoutBoxCls::detach() {
    _delegate->_relayout?->removeListener(markNeedsLayout);
    super->detach();
}

double RenderCustomSingleChildLayoutBoxCls::computeMinIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraintsCls->tightForFinite(height))->width;
    if (width->isFinite) {
        return width;
    }
    return 0.0;
}

double RenderCustomSingleChildLayoutBoxCls::computeMaxIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraintsCls->tightForFinite(height))->width;
    if (width->isFinite) {
        return width;
    }
    return 0.0;
}

double RenderCustomSingleChildLayoutBoxCls::computeMinIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraintsCls->tightForFinite(width))->height;
    if (height->isFinite) {
        return height;
    }
    return 0.0;
}

double RenderCustomSingleChildLayoutBoxCls::computeMaxIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraintsCls->tightForFinite(width))->height;
    if (height->isFinite) {
        return height;
    }
    return 0.0;
}

Size RenderCustomSingleChildLayoutBoxCls::computeDryLayout(BoxConstraints constraints) {
    return _getSize(constraints);
}

void RenderCustomSingleChildLayoutBoxCls::performLayout() {
    size = _getSize(constraints);
    if (child != nullptr) {
        BoxConstraints childConstraints = delegate->getConstraintsForChild(constraints);
        assert(childConstraints->debugAssertIsValid(true));
        child!->layout(childConstraints!childConstraints->isTight());
        BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
        childParentData->offset = delegate->getPositionForChild(size, childConstraints->isTight()? childConstraints->smallest() : child!->size);
    }
}

Size RenderCustomSingleChildLayoutBoxCls::_getSize(BoxConstraints constraints) {
    return constraints->constrain(_delegate->getSize(constraints));
}

RenderBaselineCls::RenderBaselineCls(double baseline, TextBaseline baselineType, RenderBox child) : RenderShiftedBox(child) {
    {
        assert(baseline != nullptr);
        assert(baselineType != nullptr);
        _baseline = baseline;
        _baselineType = baselineType;
    }
}

double RenderBaselineCls::baseline() {
    return _baseline;
}

void RenderBaselineCls::baseline(double value) {
    assert(value != nullptr);
    if (_baseline == value) {
        return;
    }
    _baseline = value;
    markNeedsLayout();
}

TextBaseline RenderBaselineCls::baselineType() {
    return _baselineType;
}

void RenderBaselineCls::baselineType(TextBaseline value) {
    assert(value != nullptr);
    if (_baselineType == value) {
        return;
    }
    _baselineType = value;
    markNeedsLayout();
}

Size RenderBaselineCls::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        assert(debugCannotComputeDryLayout(__s("Baseline metrics are only available after a full layout.")));
        return SizeCls::zero;
    }
    return constraints->smallest();
}

void RenderBaselineCls::performLayout() {
    if (child != nullptr) {
        BoxConstraints constraints = this->constraints;
        child!->layout(constraints->loosen()true);
        double childBaseline = child!->getDistanceToBaseline(baselineType)!;
        double actualBaseline = baseline;
        double top = actualBaseline - childBaseline;
        BoxParentData childParentData = as<BoxParentData>(child!->parentData!);
        childParentData->offset = make<OffsetCls>(0.0, top);
        Size childSize = child!->size;
        size = constraints->constrain(make<SizeCls>(childSize->width, top + childSize->height));
    } else {
        size = constraints->smallest();
    }
}

void RenderBaselineCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("baseline"), baseline));
    properties->add(<TextBaseline>make<EnumPropertyCls>(__s("baselineType"), baselineType));
}
