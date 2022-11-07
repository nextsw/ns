#include "shifted_box.hpp"
RenderShiftedBox::RenderShiftedBox(RenderBox child) {
    {
        this.child = child;
    }
}

double RenderShiftedBox::computeMinIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!.getMinIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderShiftedBox::computeMaxIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!.getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderShiftedBox::computeMinIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!.getMinIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderShiftedBox::computeMaxIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!.getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderShiftedBox::computeDistanceToActualBaseline(TextBaseline baseline) {
    double result;
    if (child != nullptr) {
        assert(!debugNeedsLayout);
        result = child!.getDistanceToActualBaseline(baseline);
        BoxParentData childParentData = (;
        if (result != nullptr) {
            result = childParentData.offset.dy;
        }
    } else {
        result = super.computeDistanceToActualBaseline(baseline);
    }
    return result;
}

void RenderShiftedBox::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        BoxParentData childParentData = (;
        context.paintChild(child!, childParentData.offset + offset);
    }
}

bool RenderShiftedBox::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (child != nullptr) {
        BoxParentData childParentData = (;
        return result.addWithPaintOffset(childParentData.offset, position, );
    }
    return false;
}

RenderPadding::RenderPadding(RenderBox child, EdgeInsetsGeometry padding, TextDirection textDirection) {
    {
        assert(padding != nullptr);
        assert(padding.isNonNegative);
        _textDirection = textDirection;
        _padding = padding;
        super(child);
    }
}

EdgeInsetsGeometry RenderPadding::padding() {
    return _padding;
}

void RenderPadding::padding(EdgeInsetsGeometry value) {
    assert(value != nullptr);
    assert(value.isNonNegative);
    if (_padding == value) {
        return;
    }
    _padding = value;
    _markNeedResolution();
}

TextDirection RenderPadding::textDirection() {
    return _textDirection;
}

void RenderPadding::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

double RenderPadding::computeMinIntrinsicWidth(double height) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!.left + _resolvedPadding!.right;
    double totalVerticalPadding = _resolvedPadding!.top + _resolvedPadding!.bottom;
    if (child != nullptr) {
        return child!.getMinIntrinsicWidth(math.max(0.0, height - totalVerticalPadding)) + totalHorizontalPadding;
    }
    return totalHorizontalPadding;
}

double RenderPadding::computeMaxIntrinsicWidth(double height) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!.left + _resolvedPadding!.right;
    double totalVerticalPadding = _resolvedPadding!.top + _resolvedPadding!.bottom;
    if (child != nullptr) {
        return child!.getMaxIntrinsicWidth(math.max(0.0, height - totalVerticalPadding)) + totalHorizontalPadding;
    }
    return totalHorizontalPadding;
}

double RenderPadding::computeMinIntrinsicHeight(double width) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!.left + _resolvedPadding!.right;
    double totalVerticalPadding = _resolvedPadding!.top + _resolvedPadding!.bottom;
    if (child != nullptr) {
        return child!.getMinIntrinsicHeight(math.max(0.0, width - totalHorizontalPadding)) + totalVerticalPadding;
    }
    return totalVerticalPadding;
}

double RenderPadding::computeMaxIntrinsicHeight(double width) {
    _resolve();
    double totalHorizontalPadding = _resolvedPadding!.left + _resolvedPadding!.right;
    double totalVerticalPadding = _resolvedPadding!.top + _resolvedPadding!.bottom;
    if (child != nullptr) {
        return child!.getMaxIntrinsicHeight(math.max(0.0, width - totalHorizontalPadding)) + totalVerticalPadding;
    }
    return totalVerticalPadding;
}

Size RenderPadding::computeDryLayout(BoxConstraints constraints) {
    _resolve();
    assert(_resolvedPadding != nullptr);
    if (child == nullptr) {
        return constraints.constrain(Size(_resolvedPadding!.left + _resolvedPadding!.right, _resolvedPadding!.top + _resolvedPadding!.bottom));
    }
    BoxConstraints innerConstraints = constraints.deflate(_resolvedPadding!);
    Size childSize = child!.getDryLayout(innerConstraints);
    return constraints.constrain(Size(_resolvedPadding!.left + childSize.width + _resolvedPadding!.right, _resolvedPadding!.top + childSize.height + _resolvedPadding!.bottom));
}

void RenderPadding::performLayout() {
    BoxConstraints constraints = this.constraints;
    _resolve();
    assert(_resolvedPadding != nullptr);
    if (child == nullptr) {
        size = constraints.constrain(Size(_resolvedPadding!.left + _resolvedPadding!.right, _resolvedPadding!.top + _resolvedPadding!.bottom));
        return;
    }
    BoxConstraints innerConstraints = constraints.deflate(_resolvedPadding!);
    child!.layout(innerConstraintstrue);
    BoxParentData childParentData = (;
    childParentData.offset = Offset(_resolvedPadding!.left, _resolvedPadding!.top);
    size = constraints.constrain(Size(_resolvedPadding!.left + child!.size.width + _resolvedPadding!.right, _resolvedPadding!.top + child!.size.height + _resolvedPadding!.bottom));
}

void RenderPadding::debugPaintSize(PaintingContext context, Offset offset) {
    super.debugPaintSize(context, offset);
    assert(());
}

void RenderPadding::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", padding));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
}

void RenderPadding::_resolve() {
    if (_resolvedPadding != nullptr) {
        return;
    }
    _resolvedPadding = padding.resolve(textDirection);
    assert(_resolvedPadding!.isNonNegative);
}

void RenderPadding::_markNeedResolution() {
    _resolvedPadding = nullptr;
    markNeedsLayout();
}

RenderAligningShiftedBox::RenderAligningShiftedBox(AlignmentGeometry alignment, RenderBox child, TextDirection textDirection) {
    {
        assert(alignment != nullptr);
        _alignment = alignment;
        _textDirection = textDirection;
        super(child);
    }
}

AlignmentGeometry RenderAligningShiftedBox::alignment() {
    return _alignment;
}

void RenderAligningShiftedBox::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    _markNeedResolution();
}

TextDirection RenderAligningShiftedBox::textDirection() {
    return _textDirection;
}

void RenderAligningShiftedBox::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

void RenderAligningShiftedBox::alignChild() {
    _resolve();
    assert(child != nullptr);
    assert(!child!.debugNeedsLayout);
    assert(child!.hasSize);
    assert(hasSize);
    assert(_resolvedAlignment != nullptr);
    BoxParentData childParentData = (;
    childParentData.offset = _resolvedAlignment!.alongOffset(();
}

void RenderAligningShiftedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
}

void RenderAligningShiftedBox::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment.resolve(textDirection);
}

void RenderAligningShiftedBox::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsLayout();
}

RenderPositionedBox::RenderPositionedBox(Unknown, Unknown, double heightFactor, Unknown, double widthFactor) {
    {
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
        _widthFactor = widthFactor;
        _heightFactor = heightFactor;
    }
}

double RenderPositionedBox::widthFactor() {
    return _widthFactor;
}

void RenderPositionedBox::widthFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_widthFactor == value) {
        return;
    }
    _widthFactor = value;
    markNeedsLayout();
}

double RenderPositionedBox::heightFactor() {
    return _heightFactor;
}

void RenderPositionedBox::heightFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_heightFactor == value) {
        return;
    }
    _heightFactor = value;
    markNeedsLayout();
}

Size RenderPositionedBox::computeDryLayout(BoxConstraints constraints) {
    bool shrinkWrapWidth = _widthFactor != nullptr || constraints.maxWidth == double.infinity;
    bool shrinkWrapHeight = _heightFactor != nullptr || constraints.maxHeight == double.infinity;
    if (child != nullptr) {
        Size childSize = child!.getDryLayout(constraints.loosen());
        return constraints.constrain(Size(shrinkWrapWidth? childSize.width * (_widthFactor ?? 1.0) : double.infinity, shrinkWrapHeight? childSize.height * (_heightFactor ?? 1.0) : double.infinity));
    }
    return constraints.constrain(Size(shrinkWrapWidth? 0.0 : double.infinity, shrinkWrapHeight? 0.0 : double.infinity));
}

void RenderPositionedBox::performLayout() {
    BoxConstraints constraints = this.constraints;
    bool shrinkWrapWidth = _widthFactor != nullptr || constraints.maxWidth == double.infinity;
    bool shrinkWrapHeight = _heightFactor != nullptr || constraints.maxHeight == double.infinity;
    if (child != nullptr) {
        child!.layout(constraints.loosen()true);
        size = constraints.constrain(Size(shrinkWrapWidth? child!.size.width * (_widthFactor ?? 1.0) : double.infinity, shrinkWrapHeight? child!.size.height * (_heightFactor ?? 1.0) : double.infinity));
        alignChild();
    } else {
        size = constraints.constrain(Size(shrinkWrapWidth? 0.0 : double.infinity, shrinkWrapHeight? 0.0 : double.infinity));
    }
}

void RenderPositionedBox::debugPaintSize(PaintingContext context, Offset offset) {
    super.debugPaintSize(context, offset);
    assert(());
}

void RenderPositionedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("widthFactor", _widthFactor"expand"));
    properties.add(DoubleProperty("heightFactor", _heightFactor"expand"));
}

RenderConstrainedOverflowBox::RenderConstrainedOverflowBox(Unknown, Unknown, double maxHeight, double maxWidth, double minHeight, double minWidth, Unknown) {
    {
        _minWidth = minWidth;
        _maxWidth = maxWidth;
        _minHeight = minHeight;
        _maxHeight = maxHeight;
    }
}

double RenderConstrainedOverflowBox::minWidth() {
    return _minWidth;
}

void RenderConstrainedOverflowBox::minWidth(double value) {
    if (_minWidth == value) {
        return;
    }
    _minWidth = value;
    markNeedsLayout();
}

double RenderConstrainedOverflowBox::maxWidth() {
    return _maxWidth;
}

void RenderConstrainedOverflowBox::maxWidth(double value) {
    if (_maxWidth == value) {
        return;
    }
    _maxWidth = value;
    markNeedsLayout();
}

double RenderConstrainedOverflowBox::minHeight() {
    return _minHeight;
}

void RenderConstrainedOverflowBox::minHeight(double value) {
    if (_minHeight == value) {
        return;
    }
    _minHeight = value;
    markNeedsLayout();
}

double RenderConstrainedOverflowBox::maxHeight() {
    return _maxHeight;
}

void RenderConstrainedOverflowBox::maxHeight(double value) {
    if (_maxHeight == value) {
        return;
    }
    _maxHeight = value;
    markNeedsLayout();
}

bool RenderConstrainedOverflowBox::sizedByParent() {
    return true;
}

Size RenderConstrainedOverflowBox::computeDryLayout(BoxConstraints constraints) {
    return constraints.biggest;
}

void RenderConstrainedOverflowBox::performLayout() {
    if (child != nullptr) {
        child?.layout(_getInnerConstraints(constraints)true);
        alignChild();
    }
}

void RenderConstrainedOverflowBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("minWidth", minWidth"use parent minWidth constraint"));
    properties.add(DoubleProperty("maxWidth", maxWidth"use parent maxWidth constraint"));
    properties.add(DoubleProperty("minHeight", minHeight"use parent minHeight constraint"));
    properties.add(DoubleProperty("maxHeight", maxHeight"use parent maxHeight constraint"));
}

BoxConstraints RenderConstrainedOverflowBox::_getInnerConstraints(BoxConstraints constraints) {
    return BoxConstraints(_minWidth ?? constraints.minWidth, _maxWidth ?? constraints.maxWidth, _minHeight ?? constraints.minHeight, _maxHeight ?? constraints.maxHeight);
}

RenderConstraintsTransformBox::RenderConstraintsTransformBox(Unknown, Unknown, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, Unknown) {
    {
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        assert(constraintsTransform != nullptr);
        _constraintsTransform = constraintsTransform;
        _clipBehavior = clipBehavior;
    }
}

BoxConstraintsTransform RenderConstraintsTransformBox::constraintsTransform() {
    return _constraintsTransform;
}

void RenderConstraintsTransformBox::constraintsTransform(BoxConstraintsTransform value) {
    if (_constraintsTransform == value) {
        return;
    }
    _constraintsTransform = value;
    bool needsLayout = _childConstraints == nullptr || _childConstraints != value(constraints);
    if (needsLayout) {
        markNeedsLayout();
    }
}

Clip RenderConstraintsTransformBox::clipBehavior() {
    return _clipBehavior;
}

void RenderConstraintsTransformBox::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

double RenderConstraintsTransformBox::computeMinIntrinsicHeight(double width) {
    return super.computeMinIntrinsicHeight(constraintsTransform(BoxConstraints(width)).maxWidth);
}

double RenderConstraintsTransformBox::computeMaxIntrinsicHeight(double width) {
    return super.computeMaxIntrinsicHeight(constraintsTransform(BoxConstraints(width)).maxWidth);
}

double RenderConstraintsTransformBox::computeMinIntrinsicWidth(double height) {
    return super.computeMinIntrinsicWidth(constraintsTransform(BoxConstraints(height)).maxHeight);
}

double RenderConstraintsTransformBox::computeMaxIntrinsicWidth(double height) {
    return super.computeMaxIntrinsicWidth(constraintsTransform(BoxConstraints(height)).maxHeight);
}

Size RenderConstraintsTransformBox::computeDryLayout(BoxConstraints constraints) {
    Size childSize = child?.getDryLayout(constraintsTransform(constraints));
    return childSize == nullptr? constraints.smallest : constraints.constrain(childSize);
}

void RenderConstraintsTransformBox::performLayout() {
    BoxConstraints constraints = this.constraints;
    RenderBox child = this.child;
    if (child != nullptr) {
        BoxConstraints childConstraints = constraintsTransform(constraints);
        assert(childConstraints != nullptr);
        assert(childConstraints.isNormalized, "$childConstraints is not normalized");
        _childConstraints = childConstraints;
        child.layout(childConstraintstrue);
        size = constraints.constrain(child.size);
        alignChild();
        BoxParentData childParentData = (;
        _overflowContainerRect = Offset.zero & size;
        _overflowChildRect = childParentData.offset & child.size;
    } else {
        size = constraints.smallest;
        _overflowContainerRect = Rect.zero;
        _overflowChildRect = Rect.zero;
    }
    _isOverflowing = RelativeRect.fromRect(_overflowContainerRect, _overflowChildRect).hasInsets;
}

void RenderConstraintsTransformBox::paint(PaintingContext context, Offset offset) {
    if (child == nullptr || size.isEmpty) {
        return;
    }
    if (!_isOverflowing) {
        super.paint(context, offset);
        return;
    }
    _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, super.paintclipBehavior, _clipRectLayer.layer);
    assert(());
}

void RenderConstraintsTransformBox::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

Rect RenderConstraintsTransformBox::describeApproximatePaintClip(RenderObject child) {
    ;
}

String RenderConstraintsTransformBox::toStringShort() {
    String header = super.toStringShort();
    if (!kReleaseMode) {
        if (_isOverflowing) {
            header = " OVERFLOWING";
        }
    }
    return header;
}

RenderUnconstrainedBox::RenderUnconstrainedBox(Unknown, Unknown, Unknown, Axis constrainedAxis, Unknown) {
    {
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        _constrainedAxis = constrainedAxis;
        super(_convertAxis(constrainedAxis));
    }
}

Axis RenderUnconstrainedBox::constrainedAxis() {
    return _constrainedAxis;
}

void RenderUnconstrainedBox::constrainedAxis(Axis value) {
    if (_constrainedAxis == value) {
        return;
    }
    _constrainedAxis = value;
    constraintsTransform = _convertAxis(constrainedAxis);
}

BoxConstraints RenderUnconstrainedBox::_unconstrained(BoxConstraints constraints) {
    return const BoxConstraints();
}

BoxConstraints RenderUnconstrainedBox::_widthConstrained(BoxConstraints constraints) {
    return constraints.widthConstraints();
}

BoxConstraints RenderUnconstrainedBox::_heightConstrained(BoxConstraints constraints) {
    return constraints.heightConstraints();
}

BoxConstraintsTransform RenderUnconstrainedBox::_convertAxis(Axis constrainedAxis) {
    if (constrainedAxis == nullptr) {
        return _unconstrained;
    }
    ;
}

RenderSizedOverflowBox::RenderSizedOverflowBox(Unknown, Unknown, Size requestedSize, Unknown) {
    {
        assert(requestedSize != nullptr);
        _requestedSize = requestedSize;
    }
}

Size RenderSizedOverflowBox::requestedSize() {
    return _requestedSize;
}

void RenderSizedOverflowBox::requestedSize(Size value) {
    assert(value != nullptr);
    if (_requestedSize == value) {
        return;
    }
    _requestedSize = value;
    markNeedsLayout();
}

double RenderSizedOverflowBox::computeMinIntrinsicWidth(double height) {
    return _requestedSize.width;
}

double RenderSizedOverflowBox::computeMaxIntrinsicWidth(double height) {
    return _requestedSize.width;
}

double RenderSizedOverflowBox::computeMinIntrinsicHeight(double width) {
    return _requestedSize.height;
}

double RenderSizedOverflowBox::computeMaxIntrinsicHeight(double width) {
    return _requestedSize.height;
}

double RenderSizedOverflowBox::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (child != nullptr) {
        return child!.getDistanceToActualBaseline(baseline);
    }
    return super.computeDistanceToActualBaseline(baseline);
}

Size RenderSizedOverflowBox::computeDryLayout(BoxConstraints constraints) {
    return constraints.constrain(_requestedSize);
}

void RenderSizedOverflowBox::performLayout() {
    size = constraints.constrain(_requestedSize);
    if (child != nullptr) {
        child!.layout(constraintstrue);
        alignChild();
    }
}

RenderFractionallySizedOverflowBox::RenderFractionallySizedOverflowBox(Unknown, Unknown, double heightFactor, Unknown, double widthFactor) {
    {
        _widthFactor = widthFactor;
        _heightFactor = heightFactor;
    }
    {
        assert(_widthFactor == nullptr || _widthFactor! >= 0.0);
        assert(_heightFactor == nullptr || _heightFactor! >= 0.0);
    }
}

double RenderFractionallySizedOverflowBox::widthFactor() {
    return _widthFactor;
}

void RenderFractionallySizedOverflowBox::widthFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_widthFactor == value) {
        return;
    }
    _widthFactor = value;
    markNeedsLayout();
}

double RenderFractionallySizedOverflowBox::heightFactor() {
    return _heightFactor;
}

void RenderFractionallySizedOverflowBox::heightFactor(double value) {
    assert(value == nullptr || value >= 0.0);
    if (_heightFactor == value) {
        return;
    }
    _heightFactor = value;
    markNeedsLayout();
}

double RenderFractionallySizedOverflowBox::computeMinIntrinsicWidth(double height) {
    double result;
    if (child == nullptr) {
        result = super.computeMinIntrinsicWidth(height);
    } else {
        result = child!.getMinIntrinsicWidth(height * (_heightFactor ?? 1.0));
    }
    assert(result.isFinite);
    return result / (_widthFactor ?? 1.0);
}

double RenderFractionallySizedOverflowBox::computeMaxIntrinsicWidth(double height) {
    double result;
    if (child == nullptr) {
        result = super.computeMaxIntrinsicWidth(height);
    } else {
        result = child!.getMaxIntrinsicWidth(height * (_heightFactor ?? 1.0));
    }
    assert(result.isFinite);
    return result / (_widthFactor ?? 1.0);
}

double RenderFractionallySizedOverflowBox::computeMinIntrinsicHeight(double width) {
    double result;
    if (child == nullptr) {
        result = super.computeMinIntrinsicHeight(width);
    } else {
        result = child!.getMinIntrinsicHeight(width * (_widthFactor ?? 1.0));
    }
    assert(result.isFinite);
    return result / (_heightFactor ?? 1.0);
}

double RenderFractionallySizedOverflowBox::computeMaxIntrinsicHeight(double width) {
    double result;
    if (child == nullptr) {
        result = super.computeMaxIntrinsicHeight(width);
    } else {
        result = child!.getMaxIntrinsicHeight(width * (_widthFactor ?? 1.0));
    }
    assert(result.isFinite);
    return result / (_heightFactor ?? 1.0);
}

Size RenderFractionallySizedOverflowBox::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        Size childSize = child!.getDryLayout(_getInnerConstraints(constraints));
        return constraints.constrain(childSize);
    }
    return constraints.constrain(_getInnerConstraints(constraints).constrain(Size.zero));
}

void RenderFractionallySizedOverflowBox::performLayout() {
    if (child != nullptr) {
        child!.layout(_getInnerConstraints(constraints)true);
        size = constraints.constrain(child!.size);
        alignChild();
    } else {
        size = constraints.constrain(_getInnerConstraints(constraints).constrain(Size.zero));
    }
}

void RenderFractionallySizedOverflowBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("widthFactor", _widthFactor"pass-through"));
    properties.add(DoubleProperty("heightFactor", _heightFactor"pass-through"));
}

BoxConstraints RenderFractionallySizedOverflowBox::_getInnerConstraints(BoxConstraints constraints) {
    double minWidth = constraints.minWidth;
    double maxWidth = constraints.maxWidth;
    if (_widthFactor != nullptr) {
        double width = maxWidth * _widthFactor!;
        minWidth = width;
        maxWidth = width;
    }
    double minHeight = constraints.minHeight;
    double maxHeight = constraints.maxHeight;
    if (_heightFactor != nullptr) {
        double height = maxHeight * _heightFactor!;
        minHeight = height;
        maxHeight = height;
    }
    return BoxConstraints(minWidth, maxWidth, minHeight, maxHeight);
}

SingleChildLayoutDelegate::SingleChildLayoutDelegate(Listenable relayout) {
    {
        _relayout = relayout;
    }
}

Size SingleChildLayoutDelegate::getSize(BoxConstraints constraints) {
    return constraints.biggest;
}

BoxConstraints SingleChildLayoutDelegate::getConstraintsForChild(BoxConstraints constraints) {
    return constraints;
}

Offset SingleChildLayoutDelegate::getPositionForChild(Size childSize, Size size) {
    return Offset.zero;
}

RenderCustomSingleChildLayoutBox::RenderCustomSingleChildLayoutBox(RenderBox child, SingleChildLayoutDelegate delegate) {
    {
        assert(delegate != nullptr);
        _delegate = delegate;
        super(child);
    }
}

SingleChildLayoutDelegate RenderCustomSingleChildLayoutBox::delegate() {
    return _delegate;
}

void RenderCustomSingleChildLayoutBox::delegate(SingleChildLayoutDelegate newDelegate) {
    assert(newDelegate != nullptr);
    if (_delegate == newDelegate) {
        return;
    }
    SingleChildLayoutDelegate oldDelegate = _delegate;
    if (newDelegate.runtimeType != oldDelegate.runtimeType || newDelegate.shouldRelayout(oldDelegate)) {
        markNeedsLayout();
    }
    _delegate = newDelegate;
    if (attached) {
        oldDelegate._relayout?.removeListener(markNeedsLayout);
        newDelegate._relayout?.addListener(markNeedsLayout);
    }
}

void RenderCustomSingleChildLayoutBox::attach(PipelineOwner owner) {
    super.attach(owner);
    _delegate._relayout?.addListener(markNeedsLayout);
}

void RenderCustomSingleChildLayoutBox::detach() {
    _delegate._relayout?.removeListener(markNeedsLayout);
    super.detach();
}

double RenderCustomSingleChildLayoutBox::computeMinIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraints.tightForFinite(height)).width;
    if (width.isFinite) {
        return width;
    }
    return 0.0;
}

double RenderCustomSingleChildLayoutBox::computeMaxIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraints.tightForFinite(height)).width;
    if (width.isFinite) {
        return width;
    }
    return 0.0;
}

double RenderCustomSingleChildLayoutBox::computeMinIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraints.tightForFinite(width)).height;
    if (height.isFinite) {
        return height;
    }
    return 0.0;
}

double RenderCustomSingleChildLayoutBox::computeMaxIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraints.tightForFinite(width)).height;
    if (height.isFinite) {
        return height;
    }
    return 0.0;
}

Size RenderCustomSingleChildLayoutBox::computeDryLayout(BoxConstraints constraints) {
    return _getSize(constraints);
}

void RenderCustomSingleChildLayoutBox::performLayout() {
    size = _getSize(constraints);
    if (child != nullptr) {
        BoxConstraints childConstraints = delegate.getConstraintsForChild(constraints);
        assert(childConstraints.debugAssertIsValid(true));
        child!.layout(childConstraints!childConstraints.isTight);
        BoxParentData childParentData = (;
        childParentData.offset = delegate.getPositionForChild(size, childConstraints.isTight? childConstraints.smallest : child!.size);
    }
}

Size RenderCustomSingleChildLayoutBox::_getSize(BoxConstraints constraints) {
    return constraints.constrain(_delegate.getSize(constraints));
}

RenderBaseline::RenderBaseline(double baseline, TextBaseline baselineType, RenderBox child) {
    {
        assert(baseline != nullptr);
        assert(baselineType != nullptr);
        _baseline = baseline;
        _baselineType = baselineType;
        super(child);
    }
}

double RenderBaseline::baseline() {
    return _baseline;
}

void RenderBaseline::baseline(double value) {
    assert(value != nullptr);
    if (_baseline == value) {
        return;
    }
    _baseline = value;
    markNeedsLayout();
}

TextBaseline RenderBaseline::baselineType() {
    return _baselineType;
}

void RenderBaseline::baselineType(TextBaseline value) {
    assert(value != nullptr);
    if (_baselineType == value) {
        return;
    }
    _baselineType = value;
    markNeedsLayout();
}

Size RenderBaseline::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        assert(debugCannotComputeDryLayout("Baseline metrics are only available after a full layout."));
        return Size.zero;
    }
    return constraints.smallest;
}

void RenderBaseline::performLayout() {
    if (child != nullptr) {
        BoxConstraints constraints = this.constraints;
        child!.layout(constraints.loosen()true);
        double childBaseline = child!.getDistanceToBaseline(baselineType)!;
        double actualBaseline = baseline;
        double top = actualBaseline - childBaseline;
        BoxParentData childParentData = (;
        childParentData.offset = Offset(0.0, top);
        Size childSize = child!.size;
        size = constraints.constrain(Size(childSize.width, top + childSize.height));
    } else {
        size = constraints.smallest;
    }
}

void RenderBaseline::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("baseline", baseline));
    properties.add(<TextBaseline>EnumProperty("baselineType", baselineType));
}
