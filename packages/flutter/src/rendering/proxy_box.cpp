#include "proxy_box.hpp"
RenderProxyBox::RenderProxyBox(RenderBox child) {
    {
        this.child = child;
    }
}

void RenderProxyBoxMixin::setupParentData(RenderObject child) {
    if (child.parentData is! ParentData) {
        child.parentData = ParentData();
    }
}

double RenderProxyBoxMixin::computeMinIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!.getMinIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderProxyBoxMixin::computeMaxIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!.getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderProxyBoxMixin::computeMinIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!.getMinIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderProxyBoxMixin::computeMaxIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!.getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderProxyBoxMixin::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (child != nullptr) {
        return child!.getDistanceToActualBaseline(baseline);
    }
    return super.computeDistanceToActualBaseline(baseline);
}

Size RenderProxyBoxMixin::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        return child!.getDryLayout(constraints);
    }
    return computeSizeForNoChild(constraints);
}

void RenderProxyBoxMixin::performLayout() {
    if (child != nullptr) {
        child!.layout(constraintstrue);
        size = child!.size;
    } else {
        size = computeSizeForNoChild(constraints);
    }
}

Size RenderProxyBoxMixin::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints.smallest;
}

bool RenderProxyBoxMixin::hitTestChildren(Offset position, BoxHitTestResult result) {
    return child?.hitTest(resultposition) ?? false;
}

void RenderProxyBoxMixin::applyPaintTransform(RenderObject child, Matrix4 transform) {
}

void RenderProxyBoxMixin::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context.paintChild(child!, offset);
    }
}

RenderProxyBoxWithHitTestBehavior::RenderProxyBoxWithHitTestBehavior(HitTestBehavior behavior, RenderBox child) {
    {
        super(child);
    }
}

bool RenderProxyBoxWithHitTestBehavior::hitTest(Offset position, BoxHitTestResult result) {
    bool hitTarget = false;
    if (size.contains(position)) {
        hitTarget = hitTestChildren(resultposition) || hitTestSelf(position);
        if (hitTarget || behavior == HitTestBehavior.translucent) {
            result.add(BoxHitTestEntry(this, position));
        }
    }
    return hitTarget;
}

bool RenderProxyBoxWithHitTestBehavior::hitTestSelf(Offset position) {
    return behavior == HitTestBehavior.opaque;
}

void RenderProxyBoxWithHitTestBehavior::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<HitTestBehavior>EnumProperty("behavior", behaviornullptr));
}

RenderConstrainedBox::RenderConstrainedBox(BoxConstraints additionalConstraints, RenderBox child) {
    {
        assert(additionalConstraints != nullptr);
        assert(additionalConstraints.debugAssertIsValid());
        _additionalConstraints = additionalConstraints;
        super(child);
    }
}

BoxConstraints RenderConstrainedBox::additionalConstraints() {
    return _additionalConstraints;
}

void RenderConstrainedBox::additionalConstraints(BoxConstraints value) {
    assert(value != nullptr);
    assert(value.debugAssertIsValid());
    if (_additionalConstraints == value) {
        return;
    }
    _additionalConstraints = value;
    markNeedsLayout();
}

double RenderConstrainedBox::computeMinIntrinsicWidth(double height) {
    if (_additionalConstraints.hasBoundedWidth && _additionalConstraints.hasTightWidth) {
        return _additionalConstraints.minWidth;
    }
    double width = super.computeMinIntrinsicWidth(height);
    assert(width.isFinite);
    if (!_additionalConstraints.hasInfiniteWidth) {
        return _additionalConstraints.constrainWidth(width);
    }
    return width;
}

double RenderConstrainedBox::computeMaxIntrinsicWidth(double height) {
    if (_additionalConstraints.hasBoundedWidth && _additionalConstraints.hasTightWidth) {
        return _additionalConstraints.minWidth;
    }
    double width = super.computeMaxIntrinsicWidth(height);
    assert(width.isFinite);
    if (!_additionalConstraints.hasInfiniteWidth) {
        return _additionalConstraints.constrainWidth(width);
    }
    return width;
}

double RenderConstrainedBox::computeMinIntrinsicHeight(double width) {
    if (_additionalConstraints.hasBoundedHeight && _additionalConstraints.hasTightHeight) {
        return _additionalConstraints.minHeight;
    }
    double height = super.computeMinIntrinsicHeight(width);
    assert(height.isFinite);
    if (!_additionalConstraints.hasInfiniteHeight) {
        return _additionalConstraints.constrainHeight(height);
    }
    return height;
}

double RenderConstrainedBox::computeMaxIntrinsicHeight(double width) {
    if (_additionalConstraints.hasBoundedHeight && _additionalConstraints.hasTightHeight) {
        return _additionalConstraints.minHeight;
    }
    double height = super.computeMaxIntrinsicHeight(width);
    assert(height.isFinite);
    if (!_additionalConstraints.hasInfiniteHeight) {
        return _additionalConstraints.constrainHeight(height);
    }
    return height;
}

void RenderConstrainedBox::performLayout() {
    BoxConstraints constraints = this.constraints;
    if (child != nullptr) {
        child!.layout(_additionalConstraints.enforce(constraints)true);
        size = child!.size;
    } else {
        size = _additionalConstraints.enforce(constraints).constrain(Size.zero);
    }
}

Size RenderConstrainedBox::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        return child!.getDryLayout(_additionalConstraints.enforce(constraints));
    } else {
        return _additionalConstraints.enforce(constraints).constrain(Size.zero);
    }
}

void RenderConstrainedBox::debugPaintSize(PaintingContext context, Offset offset) {
    super.debugPaintSize(context, offset);
    assert(());
}

void RenderConstrainedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BoxConstraints>DiagnosticsProperty("additionalConstraints", additionalConstraints));
}

RenderLimitedBox::RenderLimitedBox(RenderBox child, double maxHeight, double maxWidth) {
    {
        assert(maxWidth != nullptr && maxWidth >= 0.0);
        assert(maxHeight != nullptr && maxHeight >= 0.0);
        _maxWidth = maxWidth;
        _maxHeight = maxHeight;
        super(child);
    }
}

double RenderLimitedBox::maxWidth() {
    return _maxWidth;
}

void RenderLimitedBox::maxWidth(double value) {
    assert(value != nullptr && value >= 0.0);
    if (_maxWidth == value) {
        return;
    }
    _maxWidth = value;
    markNeedsLayout();
}

double RenderLimitedBox::maxHeight() {
    return _maxHeight;
}

void RenderLimitedBox::maxHeight(double value) {
    assert(value != nullptr && value >= 0.0);
    if (_maxHeight == value) {
        return;
    }
    _maxHeight = value;
    markNeedsLayout();
}

Size RenderLimitedBox::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(constraints, ChildLayoutHelper.dryLayoutChild);
}

void RenderLimitedBox::performLayout() {
    size = _computeSize(constraints, ChildLayoutHelper.layoutChild);
}

void RenderLimitedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("maxWidth", maxWidthdouble.infinity));
    properties.add(DoubleProperty("maxHeight", maxHeightdouble.infinity));
}

BoxConstraints RenderLimitedBox::_limitConstraints(BoxConstraints constraints) {
    return BoxConstraints(constraints.minWidth, constraints.hasBoundedWidth? constraints.maxWidth : constraints.constrainWidth(maxWidth), constraints.minHeight, constraints.hasBoundedHeight? constraints.maxHeight : constraints.constrainHeight(maxHeight));
}

Size RenderLimitedBox::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    if (child != nullptr) {
        Size childSize = layoutChild(child!, _limitConstraints(constraints));
        return constraints.constrain(childSize);
    }
    return _limitConstraints(constraints).constrain(Size.zero);
}

RenderAspectRatio::RenderAspectRatio(double aspectRatio, RenderBox child) {
    {
        assert(aspectRatio != nullptr);
        assert(aspectRatio > 0.0);
        assert(aspectRatio.isFinite);
        _aspectRatio = aspectRatio;
        super(child);
    }
}

double RenderAspectRatio::aspectRatio() {
    return _aspectRatio;
}

void RenderAspectRatio::aspectRatio(double value) {
    assert(value != nullptr);
    assert(value > 0.0);
    assert(value.isFinite);
    if (_aspectRatio == value) {
        return;
    }
    _aspectRatio = value;
    markNeedsLayout();
}

double RenderAspectRatio::computeMinIntrinsicWidth(double height) {
    if (height.isFinite) {
        return height * _aspectRatio;
    }
    if (child != nullptr) {
        return child!.getMinIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderAspectRatio::computeMaxIntrinsicWidth(double height) {
    if (height.isFinite) {
        return height * _aspectRatio;
    }
    if (child != nullptr) {
        return child!.getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderAspectRatio::computeMinIntrinsicHeight(double width) {
    if (width.isFinite) {
        return width / _aspectRatio;
    }
    if (child != nullptr) {
        return child!.getMinIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderAspectRatio::computeMaxIntrinsicHeight(double width) {
    if (width.isFinite) {
        return width / _aspectRatio;
    }
    if (child != nullptr) {
        return child!.getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

Size RenderAspectRatio::computeDryLayout(BoxConstraints constraints) {
    return _applyAspectRatio(constraints);
}

void RenderAspectRatio::performLayout() {
    size = computeDryLayout(constraints);
    if (child != nullptr) {
        child!.layout(BoxConstraints.tight(size));
    }
}

void RenderAspectRatio::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("aspectRatio", aspectRatio));
}

Size RenderAspectRatio::_applyAspectRatio(BoxConstraints constraints) {
    assert(constraints.debugAssertIsValid());
    assert(());
    if (constraints.isTight) {
        return constraints.smallest;
    }
    double width = constraints.maxWidth;
    double height;
    if (width.isFinite) {
        height = width / _aspectRatio;
    } else {
        height = constraints.maxHeight;
        width = height * _aspectRatio;
    }
    if (width > constraints.maxWidth) {
        width = constraints.maxWidth;
        height = width / _aspectRatio;
    }
    if (height > constraints.maxHeight) {
        height = constraints.maxHeight;
        width = height * _aspectRatio;
    }
    if ( < constraints.minWidth) {
        width = constraints.minWidth;
        height = width / _aspectRatio;
    }
    if ( < constraints.minHeight) {
        height = constraints.minHeight;
        width = height * _aspectRatio;
    }
    return constraints.constrain(Size(width, height));
}

RenderIntrinsicWidth::RenderIntrinsicWidth(RenderBox child, double stepHeight, double stepWidth) {
    {
        assert(stepWidth == nullptr || stepWidth > 0.0);
        assert(stepHeight == nullptr || stepHeight > 0.0);
        _stepWidth = stepWidth;
        _stepHeight = stepHeight;
        super(child);
    }
}

double RenderIntrinsicWidth::stepWidth() {
    return _stepWidth;
}

void RenderIntrinsicWidth::stepWidth(double value) {
    assert(value == nullptr || value > 0.0);
    if (value == _stepWidth) {
        return;
    }
    _stepWidth = value;
    markNeedsLayout();
}

double RenderIntrinsicWidth::stepHeight() {
    return _stepHeight;
}

void RenderIntrinsicWidth::stepHeight(double value) {
    assert(value == nullptr || value > 0.0);
    if (value == _stepHeight) {
        return;
    }
    _stepHeight = value;
    markNeedsLayout();
}

double RenderIntrinsicWidth::computeMinIntrinsicWidth(double height) {
    return computeMaxIntrinsicWidth(height);
}

double RenderIntrinsicWidth::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    double width = child!.getMaxIntrinsicWidth(height);
    return _applyStep(width, _stepWidth);
}

double RenderIntrinsicWidth::computeMinIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!width.isFinite) {
        width = computeMaxIntrinsicWidth(double.infinity);
    }
    assert(width.isFinite);
    double height = child!.getMinIntrinsicHeight(width);
    return _applyStep(height, _stepHeight);
}

double RenderIntrinsicWidth::computeMaxIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!width.isFinite) {
        width = computeMaxIntrinsicWidth(double.infinity);
    }
    assert(width.isFinite);
    double height = child!.getMaxIntrinsicHeight(width);
    return _applyStep(height, _stepHeight);
}

Size RenderIntrinsicWidth::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(ChildLayoutHelper.dryLayoutChild, constraints);
}

void RenderIntrinsicWidth::performLayout() {
    size = _computeSize(ChildLayoutHelper.layoutChild, constraints);
}

void RenderIntrinsicWidth::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("stepWidth", stepWidth));
    properties.add(DoubleProperty("stepHeight", stepHeight));
}

double RenderIntrinsicWidth::_applyStep(double input, double step) {
    assert(input.isFinite);
    if (step == nullptr) {
        return input;
    }
    return (input / step).ceil() * step;
}

Size RenderIntrinsicWidth::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    if (child != nullptr) {
        if (!constraints.hasTightWidth) {
            double width = child!.getMaxIntrinsicWidth(constraints.maxHeight);
            assert(width.isFinite);
            constraints = constraints.tighten(_applyStep(width, _stepWidth));
        }
        if (_stepHeight != nullptr) {
            double height = child!.getMaxIntrinsicHeight(constraints.maxWidth);
            assert(height.isFinite);
            constraints = constraints.tighten(_applyStep(height, _stepHeight));
        }
        return layoutChild(child!, constraints);
    } else {
        return constraints.smallest;
    }
}

RenderIntrinsicHeight::RenderIntrinsicHeight(RenderBox child) {
    {
        super(child);
    }
}

double RenderIntrinsicHeight::computeMinIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!height.isFinite) {
        height = child!.getMaxIntrinsicHeight(double.infinity);
    }
    assert(height.isFinite);
    return child!.getMinIntrinsicWidth(height);
}

double RenderIntrinsicHeight::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!height.isFinite) {
        height = child!.getMaxIntrinsicHeight(double.infinity);
    }
    assert(height.isFinite);
    return child!.getMaxIntrinsicWidth(height);
}

double RenderIntrinsicHeight::computeMinIntrinsicHeight(double width) {
    return computeMaxIntrinsicHeight(width);
}

Size RenderIntrinsicHeight::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(ChildLayoutHelper.dryLayoutChild, constraints);
}

void RenderIntrinsicHeight::performLayout() {
    size = _computeSize(ChildLayoutHelper.layoutChild, constraints);
}

Size RenderIntrinsicHeight::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    if (child != nullptr) {
        if (!constraints.hasTightHeight) {
            double height = child!.getMaxIntrinsicHeight(constraints.maxWidth);
            assert(height.isFinite);
            constraints = constraints.tighten(height);
        }
        return layoutChild(child!, constraints);
    } else {
        return constraints.smallest;
    }
}

RenderOpacity::RenderOpacity(bool alwaysIncludeSemantics, RenderBox child, double opacity) {
    {
        assert(opacity != nullptr);
        assert(opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
        _opacity = opacity;
        _alwaysIncludeSemantics = alwaysIncludeSemantics;
        _alpha = ui.Color.getAlphaFromOpacity(opacity);
        super(child);
    }
}

bool RenderOpacity::alwaysNeedsCompositing() {
    return child != nullptr && _alpha > 0;
}

double RenderOpacity::opacity() {
    return _opacity;
}

void RenderOpacity::opacity(double value) {
    assert(value != nullptr);
    assert(value >= 0.0 && value <= 1.0);
    if (_opacity == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing;
    bool wasVisible = _alpha != 0;
    _opacity = value;
    _alpha = ui.Color.getAlphaFromOpacity(_opacity);
    if (didNeedCompositing != alwaysNeedsCompositing) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
    if (wasVisible != (_alpha != 0) && !alwaysIncludeSemantics) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderOpacity::alwaysIncludeSemantics() {
    return _alwaysIncludeSemantics;
}

void RenderOpacity::alwaysIncludeSemantics(bool value) {
    if (value == _alwaysIncludeSemantics) {
        return;
    }
    _alwaysIncludeSemantics = value;
    markNeedsSemanticsUpdate();
}

bool RenderOpacity::paintsChild(RenderBox child) {
    assert(child.parent == this);
    return _alpha > 0;
}

void RenderOpacity::paint(PaintingContext context, Offset offset) {
    if (child == nullptr) {
        return;
    }
    if (_alpha == 0) {
        layer = nullptr;
        return;
    }
    assert(needsCompositing);
    layer = context.pushOpacity(offset, _alpha, super.paint();
    assert(());
}

void RenderOpacity::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && (_alpha != 0 || alwaysIncludeSemantics)) {
        visitor(child!);
    }
}

void RenderOpacity::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("opacity", opacity));
    properties.add(FlagProperty("alwaysIncludeSemantics"alwaysIncludeSemantics, "alwaysIncludeSemantics"));
}

bool RenderAnimatedOpacityMixin::isRepaintBoundary() {
    return child != nullptr && _currentlyIsRepaintBoundary!;
}

OffsetLayer RenderAnimatedOpacityMixin::updateCompositedLayer(OpacityLayer oldLayer) {
    OpacityLayer updatedLayer = oldLayer ?? OpacityLayer();
    updatedLayer.alpha = _alpha;
    return updatedLayer;
}

Animation<double> RenderAnimatedOpacityMixin::opacity() {
    return _opacity!;
}

void RenderAnimatedOpacityMixin::opacity(Animation<double> value) {
    assert(value != nullptr);
    if (_opacity == value) {
        return;
    }
    if (attached && _opacity != nullptr) {
        opacity.removeListener(_updateOpacity);
    }
    _opacity = value;
    if (attached) {
        opacity.addListener(_updateOpacity);
    }
    _updateOpacity();
}

bool RenderAnimatedOpacityMixin::alwaysIncludeSemantics() {
    return _alwaysIncludeSemantics!;
}

void RenderAnimatedOpacityMixin::alwaysIncludeSemantics(bool value) {
    if (value == _alwaysIncludeSemantics) {
        return;
    }
    _alwaysIncludeSemantics = value;
    markNeedsSemanticsUpdate();
}

void RenderAnimatedOpacityMixin::attach(PipelineOwner owner) {
    super.attach(owner);
    opacity.addListener(_updateOpacity);
    _updateOpacity();
}

void RenderAnimatedOpacityMixin::detach() {
    opacity.removeListener(_updateOpacity);
    super.detach();
}

bool RenderAnimatedOpacityMixin::paintsChild(RenderObject child) {
    assert(child.parent == this);
    return opacity.value > 0;
}

void RenderAnimatedOpacityMixin::paint(PaintingContext context, Offset offset) {
    if (_alpha == 0) {
        return;
    }
    super.paint(context, offset);
}

void RenderAnimatedOpacityMixin::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && (_alpha != 0 || alwaysIncludeSemantics)) {
        visitor(child!);
    }
}

void RenderAnimatedOpacityMixin::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Animation<double>>DiagnosticsProperty("opacity", opacity));
    properties.add(FlagProperty("alwaysIncludeSemantics"alwaysIncludeSemantics, "alwaysIncludeSemantics"));
}

void RenderAnimatedOpacityMixin::_updateOpacity() {
    int oldAlpha = _alpha;
    _alpha = ui.Color.getAlphaFromOpacity(opacity.value);
    if (oldAlpha != _alpha) {
        bool wasRepaintBoundary = _currentlyIsRepaintBoundary;
        _currentlyIsRepaintBoundary = _alpha! > 0;
        if (child != nullptr && wasRepaintBoundary != _currentlyIsRepaintBoundary) {
            markNeedsCompositingBitsUpdate();
        }
        markNeedsCompositedLayerUpdate();
        if (oldAlpha == 0 || _alpha == 0) {
            markNeedsSemanticsUpdate();
        }
    }
}

RenderAnimatedOpacity::RenderAnimatedOpacity(bool alwaysIncludeSemantics, RenderBox child, Animation<double> opacity) {
    {
        assert(opacity != nullptr);
        assert(alwaysIncludeSemantics != nullptr);
        super(child);
    }
    {
        this.opacity = opacity;
        this.alwaysIncludeSemantics = alwaysIncludeSemantics;
    }
}

RenderShaderMask::RenderShaderMask(BlendMode blendMode, RenderBox child, ShaderCallback shaderCallback) {
    {
        assert(shaderCallback != nullptr);
        assert(blendMode != nullptr);
        _shaderCallback = shaderCallback;
        _blendMode = blendMode;
        super(child);
    }
}

ShaderMaskLayer RenderShaderMask::layer() {
    return (;
}

ShaderCallback RenderShaderMask::shaderCallback() {
    return _shaderCallback;
}

void RenderShaderMask::shaderCallback(ShaderCallback value) {
    assert(value != nullptr);
    if (_shaderCallback == value) {
        return;
    }
    _shaderCallback = value;
    markNeedsPaint();
}

BlendMode RenderShaderMask::blendMode() {
    return _blendMode;
}

void RenderShaderMask::blendMode(BlendMode value) {
    assert(value != nullptr);
    if (_blendMode == value) {
        return;
    }
    _blendMode = value;
    markNeedsPaint();
}

bool RenderShaderMask::alwaysNeedsCompositing() {
    return child != nullptr;
}

void RenderShaderMask::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        assert(needsCompositing);
        layer = ShaderMaskLayer();
        ;
        context.pushLayer(layer!, super.paint, offset);
        assert(());
    } else {
        layer = nullptr;
    }
}

RenderBackdropFilter::RenderBackdropFilter(BlendMode blendMode, RenderBox child, ImageFilter filter) {
    {
        assert(filter != nullptr);
        assert(blendMode != nullptr);
        _filter = filter;
        _blendMode = blendMode;
        super(child);
    }
}

BackdropFilterLayer RenderBackdropFilter::layer() {
    return (;
}

ImageFilter RenderBackdropFilter::filter() {
    return _filter;
}

void RenderBackdropFilter::filter(ImageFilter value) {
    assert(value != nullptr);
    if (_filter == value) {
        return;
    }
    _filter = value;
    markNeedsPaint();
}

BlendMode RenderBackdropFilter::blendMode() {
    return _blendMode;
}

void RenderBackdropFilter::blendMode(BlendMode value) {
    assert(value != nullptr);
    if (_blendMode == value) {
        return;
    }
    _blendMode = value;
    markNeedsPaint();
}

bool RenderBackdropFilter::alwaysNeedsCompositing() {
    return child != nullptr;
}

void RenderBackdropFilter::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        assert(needsCompositing);
        layer = BackdropFilterLayer();
        layer!.filter = _filter;
        layer!.blendMode = _blendMode;
        context.pushLayer(layer!, super.paint, offset);
        assert(());
    } else {
        layer = nullptr;
    }
}

CustomClipper::CustomClipper(Listenable reclip) {
    {
        _reclip = reclip;
    }
}

void CustomClipper::addListener(VoidCallback listener) {
    return _reclip?.addListener(listener);
}

void CustomClipper::removeListener(VoidCallback listener) {
    return _reclip?.removeListener(listener);
}

Rect CustomClipper::getApproximateClipRect(Size size) {
    return Offset.zero & size;
}

String CustomClipper::toString() {
    return objectRuntimeType(this, "CustomClipper");
}

ShapeBorderClipper::ShapeBorderClipper(ShapeBorder shape, TextDirection textDirection) {
    {
        assert(shape != nullptr);
    }
}

Path ShapeBorderClipper::getClip(Size size) {
    return shape.getOuterPath(Offset.zero & sizetextDirection);
}

bool ShapeBorderClipper::shouldReclip(CustomClipper<Path> oldClipper) {
    if (oldClipper.runtimeType != ShapeBorderClipper) {
        return true;
    }
    ShapeBorderClipper typedOldClipper = (;
    return typedOldClipper.shape != shape || typedOldClipper.textDirection != textDirection;
}

CustomClipper<T> _RenderCustomClip::clipper() {
    return _clipper;
}

void _RenderCustomClip::clipper(CustomClipper<T> newClipper) {
    if (_clipper == newClipper) {
        return;
    }
    CustomClipper<T> oldClipper = _clipper;
    _clipper = newClipper;
    assert(newClipper != nullptr || oldClipper != nullptr);
    if (newClipper == nullptr || oldClipper == nullptr || newClipper.runtimeType != oldClipper.runtimeType || newClipper.shouldReclip(oldClipper)) {
        _markNeedsClip();
    }
    if (attached) {
        oldClipper?.removeListener(_markNeedsClip);
        newClipper?.addListener(_markNeedsClip);
    }
}

void _RenderCustomClip::attach(PipelineOwner owner) {
    super.attach(owner);
    _clipper?.addListener(_markNeedsClip);
}

void _RenderCustomClip::detach() {
    _clipper?.removeListener(_markNeedsClip);
    super.detach();
}

Clip _RenderCustomClip::clipBehavior() {
    return _clipBehavior;
}

void _RenderCustomClip::clipBehavior(Clip value) {
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
    }
}

void _RenderCustomClip::performLayout() {
    Size oldSize = hasSize? size : nullptr;
    super.performLayout();
    if (oldSize != size) {
        _clip = nullptr;
    }
}

Rect _RenderCustomClip::describeApproximatePaintClip(RenderObject child) {
    ;
}

void _RenderCustomClip::debugPaintSize(PaintingContext context, Offset offset) {
    assert(());
}

_RenderCustomClip::_RenderCustomClip(RenderBox child, Clip clipBehavior, CustomClipper<T> clipper) {
    {
        assert(clipBehavior != nullptr);
        _clipper = clipper;
        _clipBehavior = clipBehavior;
        super(child);
    }
}

void _RenderCustomClip::_markNeedsClip() {
    _clip = nullptr;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void _RenderCustomClip::_updateClip() {
    _clip = _clipper?.getClip(size) ?? _defaultClip;
}

RenderClipRect::RenderClipRect(Unknown, Unknown, Unknown) {
    {
        assert(clipBehavior != nullptr);
    }
}

bool RenderClipRect::hitTest(Offset position, BoxHitTestResult result) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!.contains(position)) {
            return false;
        }
    }
    return super.hitTest(resultposition);
}

void RenderClipRect::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != Clip.none) {
            _updateClip();
            layer = context.pushClipRect(needsCompositing, offset, _clip!, super.paintclipBehavior, ();
        } else {
            context.paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipRect::debugPaintSize(PaintingContext context, Offset offset) {
    assert(());
}

Rect RenderClipRect::_defaultClip() {
    return Offset.zero & size;
}

RenderClipRRect::RenderClipRRect(BorderRadiusGeometry borderRadius, Unknown, Unknown, CustomClipper<RRect> clipper, TextDirection textDirection) {
    {
        assert(clipBehavior != nullptr);
        _borderRadius = borderRadius;
        _textDirection = textDirection;
        super(clipper);
    }
    {
        assert(_borderRadius != nullptr || clipper != nullptr);
    }
}

BorderRadiusGeometry RenderClipRRect::borderRadius() {
    return _borderRadius;
}

void RenderClipRRect::borderRadius(BorderRadiusGeometry value) {
    assert(value != nullptr);
    if (_borderRadius == value) {
        return;
    }
    _borderRadius = value;
    _markNeedsClip();
}

TextDirection RenderClipRRect::textDirection() {
    return _textDirection;
}

void RenderClipRRect::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedsClip();
}

bool RenderClipRRect::hitTest(Offset position, BoxHitTestResult result) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!.contains(position)) {
            return false;
        }
    }
    return super.hitTest(resultposition);
}

void RenderClipRRect::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != Clip.none) {
            _updateClip();
            layer = context.pushClipRRect(needsCompositing, offset, _clip!.outerRect, _clip!, super.paintclipBehavior, ();
        } else {
            context.paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipRRect::debugPaintSize(PaintingContext context, Offset offset) {
    assert(());
}

RRect RenderClipRRect::_defaultClip() {
    return _borderRadius.resolve(textDirection).toRRect(Offset.zero & size);
}

RenderClipOval::RenderClipOval(Unknown, Unknown, Unknown) {
    {
        assert(clipBehavior != nullptr);
    }
}

bool RenderClipOval::hitTest(Offset position, BoxHitTestResult result) {
    _updateClip();
    assert(_clip != nullptr);
    Offset center = _clip!.center;
    Offset offset = Offset((position.dx - center.dx) / _clip!.width, (position.dy - center.dy) / _clip!.height);
    if (offset.distanceSquared > 0.25) {
        return false;
    }
    return super.hitTest(resultposition);
}

void RenderClipOval::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != Clip.none) {
            _updateClip();
            layer = context.pushClipPath(needsCompositing, offset, _clip!, _getClipPath(_clip!), super.paintclipBehavior, ();
        } else {
            context.paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipOval::debugPaintSize(PaintingContext context, Offset offset) {
    assert(());
}

Path RenderClipOval::_getClipPath(Rect rect) {
    if (rect != _cachedRect) {
        _cachedRect = rect;
        _cachedPath = ;
    }
    return _cachedPath;
}

Rect RenderClipOval::_defaultClip() {
    return Offset.zero & size;
}

RenderClipPath::RenderClipPath(Unknown, Unknown, Unknown) {
    {
        assert(clipBehavior != nullptr);
    }
}

bool RenderClipPath::hitTest(Offset position, BoxHitTestResult result) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!.contains(position)) {
            return false;
        }
    }
    return super.hitTest(resultposition);
}

void RenderClipPath::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != Clip.none) {
            _updateClip();
            layer = context.pushClipPath(needsCompositing, offset, Offset.zero & size, _clip!, super.paintclipBehavior, ();
        } else {
            context.paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipPath::debugPaintSize(PaintingContext context, Offset offset) {
    assert(());
}

Path RenderClipPath::_defaultClip() {
    return ;
}

double _RenderPhysicalModelBase::elevation() {
    return _elevation;
}

void _RenderPhysicalModelBase::elevation(double value) {
    assert(value != nullptr && value >= 0.0);
    if (elevation == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing;
    _elevation = value;
    if (didNeedCompositing != alwaysNeedsCompositing) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
}

Color _RenderPhysicalModelBase::shadowColor() {
    return _shadowColor;
}

void _RenderPhysicalModelBase::shadowColor(Color value) {
    assert(value != nullptr);
    if (shadowColor == value) {
        return;
    }
    _shadowColor = value;
    markNeedsPaint();
}

Color _RenderPhysicalModelBase::color() {
    return _color;
}

void _RenderPhysicalModelBase::color(Color value) {
    assert(value != nullptr);
    if (color == value) {
        return;
    }
    _color = value;
    markNeedsPaint();
}

void _RenderPhysicalModelBase::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.elevation = elevation;
}

void _RenderPhysicalModelBase::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(DoubleProperty("elevation", elevation));
    description.add(ColorProperty("color", color));
    description.add(ColorProperty("shadowColor", color));
}

_RenderPhysicalModelBase::_RenderPhysicalModelBase(Unknown, Unknown, Unknown, Color color, double elevation, Color shadowColor) {
    {
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
        assert(clipBehavior != nullptr);
        _elevation = elevation;
        _color = color;
        _shadowColor = shadowColor;
    }
}

RenderPhysicalModel::RenderPhysicalModel(BorderRadius borderRadius, Unknown, Unknown, Unknown, Unknown, Unknown, BoxShape shape) {
    {
        assert(shape != nullptr);
        assert(clipBehavior != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
        _shape = shape;
        _borderRadius = borderRadius;
    }
}

BoxShape RenderPhysicalModel::shape() {
    return _shape;
}

void RenderPhysicalModel::shape(BoxShape value) {
    assert(value != nullptr);
    if (shape == value) {
        return;
    }
    _shape = value;
    _markNeedsClip();
}

BorderRadius RenderPhysicalModel::borderRadius() {
    return _borderRadius;
}

void RenderPhysicalModel::borderRadius(BorderRadius value) {
    if (borderRadius == value) {
        return;
    }
    _borderRadius = value;
    _markNeedsClip();
}

bool RenderPhysicalModel::hitTest(Offset position, BoxHitTestResult result) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!.contains(position)) {
            return false;
        }
    }
    return super.hitTest(resultposition);
}

void RenderPhysicalModel::paint(PaintingContext context, Offset offset) {
    if (child == nullptr) {
        layer = nullptr;
        return;
    }
    _updateClip();
    RRect offsetRRect = _clip!.shift(offset);
    Rect offsetBounds = offsetRRect.outerRect;
    Path offsetRRectAsPath = ;
    bool paintShadows = true;
    assert(());
    Canvas canvas = context.canvas;
    if (elevation != 0.0 && paintShadows) {
        canvas.drawRect(offsetBounds.inflate(20.0), _transparentPaint);
        canvas.drawShadow(offsetRRectAsPath, shadowColor, elevation, color.alpha != 0xFF);
    }
    bool usesSaveLayer = clipBehavior == Clip.antiAliasWithSaveLayer;
    if (!usesSaveLayer) {
        canvas.drawRRect(offsetRRect, );
    }
    layer = context.pushClipRRect(needsCompositing, offset, Offset.zero & size, _clip!, (, clipBehavior);
    assert(());
}

void RenderPhysicalModel::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<BoxShape>DiagnosticsProperty("shape", shape));
    description.add(<BorderRadius>DiagnosticsProperty("borderRadius", borderRadius));
}

RRect RenderPhysicalModel::_defaultClip() {
    assert(hasSize);
    assert(_shape != nullptr);
    ;
}

RenderPhysicalShape::RenderPhysicalShape(Unknown, Unknown, CustomClipper<Path> clipper, Unknown, Unknown, Unknown) {
    {
        assert(clipper != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
    }
}

bool RenderPhysicalShape::hitTest(Offset position, BoxHitTestResult result) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!.contains(position)) {
            return false;
        }
    }
    return super.hitTest(resultposition);
}

void RenderPhysicalShape::paint(PaintingContext context, Offset offset) {
    if (child == nullptr) {
        layer = nullptr;
        return;
    }
    _updateClip();
    Rect offsetBounds = offset & size;
    Path offsetPath = _clip!.shift(offset);
    bool paintShadows = true;
    assert(());
    Canvas canvas = context.canvas;
    if (elevation != 0.0 && paintShadows) {
        canvas.drawRect(offsetBounds.inflate(20.0), _transparentPaint);
        canvas.drawShadow(offsetPath, shadowColor, elevation, color.alpha != 0xFF);
    }
    bool usesSaveLayer = clipBehavior == Clip.antiAliasWithSaveLayer;
    if (!usesSaveLayer) {
        canvas.drawPath(offsetPath, );
    }
    layer = context.pushClipPath(needsCompositing, offset, Offset.zero & size, _clip!, (, clipBehavior);
    assert(());
}

void RenderPhysicalShape::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<CustomClipper<Path>>DiagnosticsProperty("clipper", clipper));
}

Path RenderPhysicalShape::_defaultClip() {
    return ;
}

RenderDecoratedBox::RenderDecoratedBox(RenderBox child, ImageConfiguration configuration, Decoration decoration, DecorationPosition position) {
    {
        assert(decoration != nullptr);
        assert(position != nullptr);
        assert(configuration != nullptr);
        _decoration = decoration;
        _position = position;
        _configuration = configuration;
        super(child);
    }
}

Decoration RenderDecoratedBox::decoration() {
    return _decoration;
}

void RenderDecoratedBox::decoration(Decoration value) {
    assert(value != nullptr);
    if (value == _decoration) {
        return;
    }
    _painter?.dispose();
    _painter = nullptr;
    _decoration = value;
    markNeedsPaint();
}

DecorationPosition RenderDecoratedBox::position() {
    return _position;
}

void RenderDecoratedBox::position(DecorationPosition value) {
    assert(value != nullptr);
    if (value == _position) {
        return;
    }
    _position = value;
    markNeedsPaint();
}

ImageConfiguration RenderDecoratedBox::configuration() {
    return _configuration;
}

void RenderDecoratedBox::configuration(ImageConfiguration value) {
    assert(value != nullptr);
    if (value == _configuration) {
        return;
    }
    _configuration = value;
    markNeedsPaint();
}

void RenderDecoratedBox::detach() {
    _painter?.dispose();
    _painter = nullptr;
    super.detach();
    markNeedsPaint();
}

bool RenderDecoratedBox::hitTestSelf(Offset position) {
    return _decoration.hitTest(size, positionconfiguration.textDirection);
}

void RenderDecoratedBox::paint(PaintingContext context, Offset offset) {
    assert(size.width != nullptr);
    assert(size.height != nullptr);
    _painter = _decoration.createBoxPainter(markNeedsPaint);
    ImageConfiguration filledConfiguration = configuration.copyWith(size);
    if (position == DecorationPosition.background) {
        int debugSaveCount;
        assert(());
        _painter!.paint(context.canvas, offset, filledConfiguration);
        assert(());
        if (decoration.isComplex) {
            context.setIsComplexHint();
        }
    }
    super.paint(context, offset);
    if (position == DecorationPosition.foreground) {
        _painter!.paint(context.canvas, offset, filledConfiguration);
        if (decoration.isComplex) {
            context.setIsComplexHint();
        }
    }
}

void RenderDecoratedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(_decoration.toDiagnosticsNode("decoration"));
    properties.add(<ImageConfiguration>DiagnosticsProperty("configuration", configuration));
}

RenderTransform::RenderTransform(AlignmentGeometry alignment, RenderBox child, FilterQuality filterQuality, Offset origin, TextDirection textDirection, Matrix4 transform, bool transformHitTests) {
    {
        assert(transform != nullptr);
        super(child);
    }
    {
        this.transform = transform;
        this.alignment = alignment;
        this.textDirection = textDirection;
        this.filterQuality = filterQuality;
        this.origin = origin;
    }
}

Offset RenderTransform::origin() {
    return _origin;
}

void RenderTransform::origin(Offset value) {
    if (_origin == value) {
        return;
    }
    _origin = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

AlignmentGeometry RenderTransform::alignment() {
    return _alignment;
}

void RenderTransform::alignment(AlignmentGeometry value) {
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

TextDirection RenderTransform::textDirection() {
    return _textDirection;
}

void RenderTransform::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

bool RenderTransform::alwaysNeedsCompositing() {
    return child != nullptr && _filterQuality != nullptr;
}

void RenderTransform::transform(Matrix4 value) {
    assert(value != nullptr);
    if (_transform == value) {
        return;
    }
    _transform = Matrix4.copy(value);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

FilterQuality RenderTransform::filterQuality() {
    return _filterQuality;
}

void RenderTransform::filterQuality(FilterQuality value) {
    if (_filterQuality == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing;
    _filterQuality = value;
    if (didNeedCompositing != alwaysNeedsCompositing) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
}

void RenderTransform::setIdentity() {
    _transform!.setIdentity();
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransform::rotateX(double radians) {
    _transform!.rotateX(radians);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransform::rotateY(double radians) {
    _transform!.rotateY(radians);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransform::rotateZ(double radians) {
    _transform!.rotateZ(radians);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransform::translate(double x, double y, double z) {
    _transform!.translate(x, y, z);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransform::scale(double x, double y, double z) {
    _transform!.scale(x, y, z);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

bool RenderTransform::hitTest(Offset position, BoxHitTestResult result) {
    return hitTestChildren(resultposition);
}

bool RenderTransform::hitTestChildren(Offset position, BoxHitTestResult result) {
    assert(!transformHitTests || _effectiveTransform != nullptr);
    return result.addWithPaintTransform(transformHitTests? _effectiveTransform : nullptr, position, );
}

void RenderTransform::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        Matrix4 transform = _effectiveTransform!;
        if (filterQuality == nullptr) {
            Offset childOffset = MatrixUtils.getAsTranslation(transform);
            if (childOffset == nullptr) {
                double det = transform.determinant();
                if (det == 0 || !det.isFinite) {
                    layer = nullptr;
                    return;
                }
                layer = context.pushTransform(needsCompositing, offset, transform, super.paintlayer is TransformLayer? ( : nullptr);
            } else {
                super.paint(context, offset + childOffset);
                layer = nullptr;
            }
        } else {
            Matrix4 effectiveTransform = ;
            ImageFilter filter = ui.ImageFilter.matrix(effectiveTransform.storagefilterQuality!);
            if (layer is ImageFilterLayer) {
                ImageFilterLayer filterLayer = (;
                filterLayer.imageFilter = filter;
            } else {
                layer = ImageFilterLayer(filter);
            }
            context.pushLayer(layer!, super.paint, offset);
            assert(());
        }
    }
}

void RenderTransform::applyPaintTransform(RenderBox child, Matrix4 transform) {
    transform.multiply(_effectiveTransform!);
}

void RenderTransform::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(TransformProperty("transform matrix", _transform));
    properties.add(<Offset>DiagnosticsProperty("origin", origin));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<bool>DiagnosticsProperty("transformHitTests", transformHitTests));
}

Matrix4 RenderTransform::_effectiveTransform() {
    Alignment resolvedAlignment = alignment?.resolve(textDirection);
    if (_origin == nullptr && resolvedAlignment == nullptr) {
        return _transform;
    }
    Matrix4 result = Matrix4.identity();
    if (_origin != nullptr) {
        result.translate(_origin!.dx, _origin!.dy);
    }
    Offset translation;
    if (resolvedAlignment != nullptr) {
        translation = resolvedAlignment.alongSize(size);
        result.translate(translation.dx, translation.dy);
    }
    result.multiply(_transform!);
    if (resolvedAlignment != nullptr) {
        result.translate(-translation!.dx, -translation.dy);
    }
    if (_origin != nullptr) {
        result.translate(-_origin!.dx, -_origin!.dy);
    }
    return result;
}

RenderFittedBox::RenderFittedBox(AlignmentGeometry alignment, RenderBox child, Clip clipBehavior, BoxFit fit, TextDirection textDirection) {
    {
        assert(fit != nullptr);
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        _fit = fit;
        _alignment = alignment;
        _textDirection = textDirection;
        _clipBehavior = clipBehavior;
        super(child);
    }
}

BoxFit RenderFittedBox::fit() {
    return _fit;
}

void RenderFittedBox::fit(BoxFit value) {
    assert(value != nullptr);
    if (_fit == value) {
        return;
    }
    BoxFit lastFit = _fit;
    _fit = value;
    if (_fitAffectsLayout(lastFit) || _fitAffectsLayout(value)) {
        markNeedsLayout();
    } else {
        _clearPaintData();
        markNeedsPaint();
    }
}

AlignmentGeometry RenderFittedBox::alignment() {
    return _alignment;
}

void RenderFittedBox::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    _clearPaintData();
    _markNeedResolution();
}

TextDirection RenderFittedBox::textDirection() {
    return _textDirection;
}

void RenderFittedBox::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _clearPaintData();
    _markNeedResolution();
}

Size RenderFittedBox::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        Size childSize = child!.getDryLayout(const BoxConstraints());
        bool invalidChildSize = false;
        assert(());
        if (invalidChildSize) {
            assert(debugCannotComputeDryLayout("Child provided invalid size of $childSize."));
            return Size.zero;
        }
        ;
    } else {
        return constraints.smallest;
    }
}

void RenderFittedBox::performLayout() {
    if (child != nullptr) {
        child!.layout(const BoxConstraints()true);
        ;
        _clearPaintData();
    } else {
        size = constraints.smallest;
    }
}

Clip RenderFittedBox::clipBehavior() {
    return _clipBehavior;
}

void RenderFittedBox::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderFittedBox::paint(PaintingContext context, Offset offset) {
    if (child == nullptr || size.isEmpty || child!.size.isEmpty) {
        return;
    }
    _updatePaintData();
    assert(child != nullptr);
    if (_hasVisualOverflow! && clipBehavior != Clip.none) {
        layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, _paintChildWithTransformlayer is ClipRectLayer? ( : nullptr, clipBehavior);
    } else {
        layer = _paintChildWithTransform(context, offset);
    }
}

bool RenderFittedBox::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (size.isEmpty || (child?.size.isEmpty ?? false)) {
        return false;
    }
    _updatePaintData();
    return result.addWithPaintTransform(_transform, position, );
}

bool RenderFittedBox::paintsChild(RenderBox child) {
    assert(child.parent == this);
    return !size.isEmpty && !child.size.isEmpty;
}

void RenderFittedBox::applyPaintTransform(RenderBox child, Matrix4 transform) {
    if (!paintsChild(child)) {
        transform.setZero();
    } else {
        _updatePaintData();
        transform.multiply(_transform!);
    }
}

void RenderFittedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BoxFit>EnumProperty("fit", fit));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
}

void RenderFittedBox::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment.resolve(textDirection);
}

void RenderFittedBox::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsPaint();
}

bool RenderFittedBox::_fitAffectsLayout(BoxFit fit) {
    ;
}

void RenderFittedBox::_clearPaintData() {
    _hasVisualOverflow = nullptr;
    _transform = nullptr;
}

void RenderFittedBox::_updatePaintData() {
    if (_transform != nullptr) {
        return;
    }
    if (child == nullptr) {
        _hasVisualOverflow = false;
        _transform = Matrix4.identity();
    } else {
        _resolve();
        Size childSize = child!.size;
        FittedSizes sizes = applyBoxFit(_fit, childSize, size);
        double scaleX = sizes.destination.width / sizes.source.width;
        double scaleY = sizes.destination.height / sizes.source.height;
        Rect sourceRect = _resolvedAlignment!.inscribe(sizes.source, Offset.zero & childSize);
        Rect destinationRect = _resolvedAlignment!.inscribe(sizes.destination, Offset.zero & size);
        _hasVisualOverflow = sourceRect.width < childSize.width || sourceRect.height < childSize.height;
        assert(scaleX.isFinite && scaleY.isFinite);
        _transform = ;
        assert(_transform!.storage.every());
    }
}

TransformLayer RenderFittedBox::_paintChildWithTransform(PaintingContext context, Offset offset) {
    Offset childOffset = MatrixUtils.getAsTranslation(_transform!);
    if (childOffset == nullptr) {
        return context.pushTransform(needsCompositing, offset, _transform!, super.paintlayer is TransformLayer? ( : nullptr);
    } else {
        super.paint(context, offset + childOffset);
    }
    return nullptr;
}

RenderFractionalTranslation::RenderFractionalTranslation(RenderBox child, bool transformHitTests, Offset translation) {
    {
        assert(translation != nullptr);
        _translation = translation;
        super(child);
    }
}

Offset RenderFractionalTranslation::translation() {
    return _translation;
}

void RenderFractionalTranslation::translation(Offset value) {
    assert(value != nullptr);
    if (_translation == value) {
        return;
    }
    _translation = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

bool RenderFractionalTranslation::hitTest(Offset position, BoxHitTestResult result) {
    return hitTestChildren(resultposition);
}

bool RenderFractionalTranslation::hitTestChildren(Offset position, BoxHitTestResult result) {
    assert(!debugNeedsLayout);
    return result.addWithPaintOffset(transformHitTests? Offset(translation.dx * size.width, translation.dy * size.height) : nullptr, position, );
}

void RenderFractionalTranslation::paint(PaintingContext context, Offset offset) {
    assert(!debugNeedsLayout);
    if (child != nullptr) {
        super.paint(context, Offset(offset.dx + translation.dx * size.width, offset.dy + translation.dy * size.height));
    }
}

void RenderFractionalTranslation::applyPaintTransform(RenderBox child, Matrix4 transform) {
    transform.translate(translation.dx * size.width, translation.dy * size.height);
}

void RenderFractionalTranslation::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("translation", translation));
    properties.add(<bool>DiagnosticsProperty("transformHitTests", transformHitTests));
}

Size RenderPointerListener::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints.biggest;
}

void RenderPointerListener::handleEvent(HitTestEntry entry, PointerEvent event) {
    assert(debugHandleEvent(event, entry));
    if (event is PointerDownEvent) {
        return onPointerDown?.call(event);
    }
    if (event is PointerMoveEvent) {
        return onPointerMove?.call(event);
    }
    if (event is PointerUpEvent) {
        return onPointerUp?.call(event);
    }
    if (event is PointerHoverEvent) {
        return onPointerHover?.call(event);
    }
    if (event is PointerCancelEvent) {
        return onPointerCancel?.call(event);
    }
    if (event is PointerPanZoomStartEvent) {
        return onPointerPanZoomStart?.call(event);
    }
    if (event is PointerPanZoomUpdateEvent) {
        return onPointerPanZoomUpdate?.call(event);
    }
    if (event is PointerPanZoomEndEvent) {
        return onPointerPanZoomEnd?.call(event);
    }
    if (event is PointerSignalEvent) {
        return onPointerSignal?.call(event);
    }
}

void RenderPointerListener::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<FunctionType>FlagsSummary("listeners", "<none>"));
}

RenderMouseRegion::RenderMouseRegion(Unknown, MouseCursor cursor, HitTestBehavior hitTestBehavior, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque, bool validForMouseTracker) {
    {
        assert(opaque != nullptr);
        assert(cursor != nullptr);
        _cursor = cursor;
        _validForMouseTracker = validForMouseTracker;
        _opaque = opaque;
        super(hitTestBehavior ?? HitTestBehavior.opaque);
    }
}

bool RenderMouseRegion::hitTest(Offset position, BoxHitTestResult result) {
    return super.hitTest(resultposition) && _opaque;
}

void RenderMouseRegion::handleEvent(HitTestEntry entry, PointerEvent event) {
    assert(debugHandleEvent(event, entry));
    if (onHover != nullptr && event is PointerHoverEvent) {
        return onHover!(event);
    }
}

bool RenderMouseRegion::opaque() {
    return _opaque;
}

void RenderMouseRegion::opaque(bool value) {
    if (_opaque != value) {
        _opaque = value;
        markNeedsPaint();
    }
}

HitTestBehavior RenderMouseRegion::hitTestBehavior() {
    return behavior;
}

void RenderMouseRegion::hitTestBehavior(HitTestBehavior value) {
    HitTestBehavior newValue = value ?? HitTestBehavior.opaque;
    if (behavior != newValue) {
        behavior = newValue;
        markNeedsPaint();
    }
}

MouseCursor RenderMouseRegion::cursor() {
    return _cursor;
}

void RenderMouseRegion::cursor(MouseCursor value) {
    if (_cursor != value) {
        _cursor = value;
        markNeedsPaint();
    }
}

bool RenderMouseRegion::validForMouseTracker() {
    return _validForMouseTracker;
}

void RenderMouseRegion::attach(PipelineOwner owner) {
    super.attach(owner);
    _validForMouseTracker = true;
}

void RenderMouseRegion::detach() {
    _validForMouseTracker = false;
    super.detach();
}

Size RenderMouseRegion::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints.biggest;
}

void RenderMouseRegion::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<FunctionType>FlagsSummary("listeners", "<none>"));
    properties.add(<MouseCursor>DiagnosticsProperty("cursor", cursorMouseCursor.defer));
    properties.add(<bool>DiagnosticsProperty("opaque", opaquetrue));
    properties.add(FlagProperty("validForMouseTracker"validForMouseTracker, true, "invalid for MouseTracker"));
}

RenderRepaintBoundary::RenderRepaintBoundary(RenderBox child) {
    {
        super(child);
    }
}

bool RenderRepaintBoundary::isRepaintBoundary() {
    return true;
}

Future<Image> RenderRepaintBoundary::toImage(double pixelRatio) {
    assert(!debugNeedsPaint);
    OffsetLayer offsetLayer = (;
    return offsetLayer.toImage(Offset.zero & sizepixelRatio);
}

int RenderRepaintBoundary::debugSymmetricPaintCount() {
    return _debugSymmetricPaintCount;
}

int RenderRepaintBoundary::debugAsymmetricPaintCount() {
    return _debugAsymmetricPaintCount;
}

void RenderRepaintBoundary::debugResetMetrics() {
    assert(());
}

void RenderRepaintBoundary::debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent) {
    assert(());
}

void RenderRepaintBoundary::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    bool inReleaseMode = true;
    assert(());
    if (inReleaseMode) {
        properties.add(DiagnosticsNode.message("(run in debug mode to collect repaint boundary statistics)"));
    }
}

RenderIgnorePointer::RenderIgnorePointer(RenderBox child, bool ignoring, bool ignoringSemantics) {
    {
        _ignoring = ignoring;
        _ignoringSemantics = ignoringSemantics;
        super(child);
    }
    {
        assert(_ignoring != nullptr);
    }
}

bool RenderIgnorePointer::ignoring() {
    return _ignoring;
}

void RenderIgnorePointer::ignoring(bool value) {
    assert(value != nullptr);
    if (value == _ignoring) {
        return;
    }
    _ignoring = value;
    if (_ignoringSemantics == nullptr || !_ignoringSemantics!) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderIgnorePointer::ignoringSemantics() {
    return _ignoringSemantics;
}

void RenderIgnorePointer::ignoringSemantics(bool value) {
    if (value == _ignoringSemantics) {
        return;
    }
    bool oldEffectiveValue = _effectiveIgnoringSemantics;
    _ignoringSemantics = value;
    if (oldEffectiveValue != _effectiveIgnoringSemantics) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderIgnorePointer::hitTest(Offset position, BoxHitTestResult result) {
    return !ignoring && super.hitTest(resultposition);
}

void RenderIgnorePointer::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && !_effectiveIgnoringSemantics) {
        visitor(child!);
    }
}

void RenderIgnorePointer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("ignoring", ignoring));
    properties.add(<bool>DiagnosticsProperty("ignoringSemantics", _effectiveIgnoringSemanticsignoringSemantics == nullptr? "implicitly $_effectiveIgnoringSemantics" : nullptr));
}

bool RenderIgnorePointer::_effectiveIgnoringSemantics() {
    return ignoringSemantics ?? ignoring;
}

RenderOffstage::RenderOffstage(RenderBox child, bool offstage) {
    {
        assert(offstage != nullptr);
        _offstage = offstage;
        super(child);
    }
}

bool RenderOffstage::offstage() {
    return _offstage;
}

void RenderOffstage::offstage(bool value) {
    assert(value != nullptr);
    if (value == _offstage) {
        return;
    }
    _offstage = value;
    markNeedsLayoutForSizedByParentChange();
}

double RenderOffstage::computeMinIntrinsicWidth(double height) {
    if (offstage) {
        return 0.0;
    }
    return super.computeMinIntrinsicWidth(height);
}

double RenderOffstage::computeMaxIntrinsicWidth(double height) {
    if (offstage) {
        return 0.0;
    }
    return super.computeMaxIntrinsicWidth(height);
}

double RenderOffstage::computeMinIntrinsicHeight(double width) {
    if (offstage) {
        return 0.0;
    }
    return super.computeMinIntrinsicHeight(width);
}

double RenderOffstage::computeMaxIntrinsicHeight(double width) {
    if (offstage) {
        return 0.0;
    }
    return super.computeMaxIntrinsicHeight(width);
}

double RenderOffstage::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (offstage) {
        return nullptr;
    }
    return super.computeDistanceToActualBaseline(baseline);
}

bool RenderOffstage::sizedByParent() {
    return offstage;
}

Size RenderOffstage::computeDryLayout(BoxConstraints constraints) {
    if (offstage) {
        return constraints.smallest;
    }
    return super.computeDryLayout(constraints);
}

void RenderOffstage::performResize() {
    assert(offstage);
    super.performResize();
}

void RenderOffstage::performLayout() {
    if (offstage) {
        child?.layout(constraints);
    } else {
        super.performLayout();
    }
}

bool RenderOffstage::hitTest(Offset position, BoxHitTestResult result) {
    return !offstage && super.hitTest(resultposition);
}

bool RenderOffstage::paintsChild(RenderBox child) {
    assert(child.parent == this);
    return !offstage;
}

void RenderOffstage::paint(PaintingContext context, Offset offset) {
    if (offstage) {
        return;
    }
    super.paint(context, offset);
}

void RenderOffstage::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (offstage) {
        return;
    }
    super.visitChildrenForSemantics(visitor);
}

void RenderOffstage::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("offstage", offstage));
}

List<DiagnosticsNode> RenderOffstage::debugDescribeChildren() {
    if (child == nullptr) {
        return ;
    }
    return ;
}

RenderAbsorbPointer::RenderAbsorbPointer(bool absorbing, RenderBox child, bool ignoringSemantics) {
    {
        assert(absorbing != nullptr);
        _absorbing = absorbing;
        _ignoringSemantics = ignoringSemantics;
        super(child);
    }
}

bool RenderAbsorbPointer::absorbing() {
    return _absorbing;
}

void RenderAbsorbPointer::absorbing(bool value) {
    if (_absorbing == value) {
        return;
    }
    _absorbing = value;
    if (ignoringSemantics == nullptr) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderAbsorbPointer::ignoringSemantics() {
    return _ignoringSemantics;
}

void RenderAbsorbPointer::ignoringSemantics(bool value) {
    if (value == _ignoringSemantics) {
        return;
    }
    bool oldEffectiveValue = _effectiveIgnoringSemantics;
    _ignoringSemantics = value;
    if (oldEffectiveValue != _effectiveIgnoringSemantics) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderAbsorbPointer::hitTest(Offset position, BoxHitTestResult result) {
    return absorbing? size.contains(position) : super.hitTest(resultposition);
}

void RenderAbsorbPointer::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && !_effectiveIgnoringSemantics) {
        visitor(child!);
    }
}

void RenderAbsorbPointer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("absorbing", absorbing));
    properties.add(<bool>DiagnosticsProperty("ignoringSemantics", _effectiveIgnoringSemanticsignoringSemantics == nullptr? "implicitly $_effectiveIgnoringSemantics" : nullptr));
}

bool RenderAbsorbPointer::_effectiveIgnoringSemantics() {
    return ignoringSemantics ?? absorbing;
}

void RenderMetaData::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<dynamic>DiagnosticsProperty("metaData", metaData));
}

RenderSemanticsGestureHandler::RenderSemanticsGestureHandler(Unknown, Unknown, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureTapCallback onTap, GestureDragUpdateCallback onVerticalDragUpdate, double scrollFactor) {
    {
        assert(scrollFactor != nullptr);
        _onTap = onTap;
        _onLongPress = onLongPress;
        _onHorizontalDragUpdate = onHorizontalDragUpdate;
        _onVerticalDragUpdate = onVerticalDragUpdate;
    }
}

Set<SemanticsAction> RenderSemanticsGestureHandler::validActions() {
    return _validActions;
}

void RenderSemanticsGestureHandler::validActions(Set<SemanticsAction> value) {
    if (<SemanticsAction>setEquals(value, _validActions)) {
        return;
    }
    _validActions = value;
    markNeedsSemanticsUpdate();
}

GestureTapCallback RenderSemanticsGestureHandler::onTap() {
    return _onTap;
}

void RenderSemanticsGestureHandler::onTap(GestureTapCallback value) {
    if (_onTap == value) {
        return;
    }
    bool hadHandler = _onTap != nullptr;
    _onTap = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

GestureLongPressCallback RenderSemanticsGestureHandler::onLongPress() {
    return _onLongPress;
}

void RenderSemanticsGestureHandler::onLongPress(GestureLongPressCallback value) {
    if (_onLongPress == value) {
        return;
    }
    bool hadHandler = _onLongPress != nullptr;
    _onLongPress = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

GestureDragUpdateCallback RenderSemanticsGestureHandler::onHorizontalDragUpdate() {
    return _onHorizontalDragUpdate;
}

void RenderSemanticsGestureHandler::onHorizontalDragUpdate(GestureDragUpdateCallback value) {
    if (_onHorizontalDragUpdate == value) {
        return;
    }
    bool hadHandler = _onHorizontalDragUpdate != nullptr;
    _onHorizontalDragUpdate = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

GestureDragUpdateCallback RenderSemanticsGestureHandler::onVerticalDragUpdate() {
    return _onVerticalDragUpdate;
}

void RenderSemanticsGestureHandler::onVerticalDragUpdate(GestureDragUpdateCallback value) {
    if (_onVerticalDragUpdate == value) {
        return;
    }
    bool hadHandler = _onVerticalDragUpdate != nullptr;
    _onVerticalDragUpdate = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

void RenderSemanticsGestureHandler::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    if (onTap != nullptr && _isValidAction(SemanticsAction.tap)) {
        config.onTap = onTap;
    }
    if (onLongPress != nullptr && _isValidAction(SemanticsAction.longPress)) {
        config.onLongPress = onLongPress;
    }
    if (onHorizontalDragUpdate != nullptr) {
        if (_isValidAction(SemanticsAction.scrollRight)) {
            config.onScrollRight = _performSemanticScrollRight;
        }
        if (_isValidAction(SemanticsAction.scrollLeft)) {
            config.onScrollLeft = _performSemanticScrollLeft;
        }
    }
    if (onVerticalDragUpdate != nullptr) {
        if (_isValidAction(SemanticsAction.scrollUp)) {
            config.onScrollUp = _performSemanticScrollUp;
        }
        if (_isValidAction(SemanticsAction.scrollDown)) {
            config.onScrollDown = _performSemanticScrollDown;
        }
    }
}

void RenderSemanticsGestureHandler::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    List<String> gestures = ;
    if (gestures.isEmpty) {
        gestures.add("<none>");
    }
    properties.add(<String>IterableProperty("gestures", gestures));
}

bool RenderSemanticsGestureHandler::_isValidAction(SemanticsAction action) {
    return validActions == nullptr || validActions!.contains(action);
}

void RenderSemanticsGestureHandler::_performSemanticScrollLeft() {
    if (onHorizontalDragUpdate != nullptr) {
        double primaryDelta = size.width * -scrollFactor;
        onHorizontalDragUpdate!(DragUpdateDetails(Offset(primaryDelta, 0.0), primaryDelta, localToGlobal(size.center(Offset.zero))));
    }
}

void RenderSemanticsGestureHandler::_performSemanticScrollRight() {
    if (onHorizontalDragUpdate != nullptr) {
        double primaryDelta = size.width * scrollFactor;
        onHorizontalDragUpdate!(DragUpdateDetails(Offset(primaryDelta, 0.0), primaryDelta, localToGlobal(size.center(Offset.zero))));
    }
}

void RenderSemanticsGestureHandler::_performSemanticScrollUp() {
    if (onVerticalDragUpdate != nullptr) {
        double primaryDelta = size.height * -scrollFactor;
        onVerticalDragUpdate!(DragUpdateDetails(Offset(0.0, primaryDelta), primaryDelta, localToGlobal(size.center(Offset.zero))));
    }
}

void RenderSemanticsGestureHandler::_performSemanticScrollDown() {
    if (onVerticalDragUpdate != nullptr) {
        double primaryDelta = size.height * scrollFactor;
        onVerticalDragUpdate!(DragUpdateDetails(Offset(0.0, primaryDelta), primaryDelta, localToGlobal(size.center(Offset.zero))));
    }
}

RenderSemanticsAnnotations::RenderSemanticsAnnotations(RenderBox child, bool container, bool excludeSemantics, bool explicitChildNodes, SemanticsProperties properties, TextDirection textDirection) {
    {
        assert(container != nullptr);
        _container = container;
        _explicitChildNodes = explicitChildNodes;
        _excludeSemantics = excludeSemantics;
        _textDirection = textDirection;
        _properties = properties;
        super(child);
    }
    {
        _updateAttributedFields(_properties);
    }
}

SemanticsProperties RenderSemanticsAnnotations::properties() {
    return _properties;
}

void RenderSemanticsAnnotations::properties(SemanticsProperties value) {
    assert(value != nullptr);
    if (_properties == value) {
        return;
    }
    _properties = value;
    _updateAttributedFields(_properties);
    markNeedsSemanticsUpdate();
}

bool RenderSemanticsAnnotations::container() {
    return _container;
}

void RenderSemanticsAnnotations::container(bool value) {
    assert(value != nullptr);
    if (container == value) {
        return;
    }
    _container = value;
    markNeedsSemanticsUpdate();
}

bool RenderSemanticsAnnotations::explicitChildNodes() {
    return _explicitChildNodes;
}

void RenderSemanticsAnnotations::explicitChildNodes(bool value) {
    assert(value != nullptr);
    if (_explicitChildNodes == value) {
        return;
    }
    _explicitChildNodes = value;
    markNeedsSemanticsUpdate();
}

bool RenderSemanticsAnnotations::excludeSemantics() {
    return _excludeSemantics;
}

void RenderSemanticsAnnotations::excludeSemantics(bool value) {
    assert(value != nullptr);
    if (_excludeSemantics == value) {
        return;
    }
    _excludeSemantics = value;
    markNeedsSemanticsUpdate();
}

TextDirection RenderSemanticsAnnotations::textDirection() {
    return _textDirection;
}

void RenderSemanticsAnnotations::textDirection(TextDirection value) {
    if (textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsSemanticsUpdate();
}

void RenderSemanticsAnnotations::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (excludeSemantics) {
        return;
    }
    super.visitChildrenForSemantics(visitor);
}

void RenderSemanticsAnnotations::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.isSemanticBoundary = container;
    config.explicitChildNodes = explicitChildNodes;
    assert(((_properties.scopesRoute ?? false) && explicitChildNodes) || !(_properties.scopesRoute ?? false), "explicitChildNodes must be set to true if scopes route is true");
    assert(!((_properties.toggled ?? false) && (_properties.checked ?? false)), "A semantics node cannot be toggled and checked at the same time");
    if (_properties.enabled != nullptr) {
        config.isEnabled = _properties.enabled;
    }
    if (_properties.checked != nullptr) {
        config.isChecked = _properties.checked;
    }
    if (_properties.toggled != nullptr) {
        config.isToggled = _properties.toggled;
    }
    if (_properties.selected != nullptr) {
        config.isSelected = _properties.selected!;
    }
    if (_properties.button != nullptr) {
        config.isButton = _properties.button!;
    }
    if (_properties.link != nullptr) {
        config.isLink = _properties.link!;
    }
    if (_properties.slider != nullptr) {
        config.isSlider = _properties.slider!;
    }
    if (_properties.keyboardKey != nullptr) {
        config.isKeyboardKey = _properties.keyboardKey!;
    }
    if (_properties.header != nullptr) {
        config.isHeader = _properties.header!;
    }
    if (_properties.textField != nullptr) {
        config.isTextField = _properties.textField!;
    }
    if (_properties.readOnly != nullptr) {
        config.isReadOnly = _properties.readOnly!;
    }
    if (_properties.focusable != nullptr) {
        config.isFocusable = _properties.focusable!;
    }
    if (_properties.focused != nullptr) {
        config.isFocused = _properties.focused!;
    }
    if (_properties.inMutuallyExclusiveGroup != nullptr) {
        config.isInMutuallyExclusiveGroup = _properties.inMutuallyExclusiveGroup!;
    }
    if (_properties.obscured != nullptr) {
        config.isObscured = _properties.obscured!;
    }
    if (_properties.multiline != nullptr) {
        config.isMultiline = _properties.multiline!;
    }
    if (_properties.hidden != nullptr) {
        config.isHidden = _properties.hidden!;
    }
    if (_properties.image != nullptr) {
        config.isImage = _properties.image!;
    }
    if (_attributedLabel != nullptr) {
        config.attributedLabel = _attributedLabel!;
    }
    if (_attributedValue != nullptr) {
        config.attributedValue = _attributedValue!;
    }
    if (_attributedIncreasedValue != nullptr) {
        config.attributedIncreasedValue = _attributedIncreasedValue!;
    }
    if (_attributedDecreasedValue != nullptr) {
        config.attributedDecreasedValue = _attributedDecreasedValue!;
    }
    if (_attributedHint != nullptr) {
        config.attributedHint = _attributedHint!;
    }
    if (_properties.tooltip != nullptr) {
        config.tooltip = _properties.tooltip!;
    }
    if (_properties.hintOverrides != nullptr && _properties.hintOverrides!.isNotEmpty) {
        config.hintOverrides = _properties.hintOverrides;
    }
    if (_properties.scopesRoute != nullptr) {
        config.scopesRoute = _properties.scopesRoute!;
    }
    if (_properties.namesRoute != nullptr) {
        config.namesRoute = _properties.namesRoute!;
    }
    if (_properties.liveRegion != nullptr) {
        config.liveRegion = _properties.liveRegion!;
    }
    if (_properties.maxValueLength != nullptr) {
        config.maxValueLength = _properties.maxValueLength;
    }
    if (_properties.currentValueLength != nullptr) {
        config.currentValueLength = _properties.currentValueLength;
    }
    if (textDirection != nullptr) {
        config.textDirection = textDirection;
    }
    if (_properties.sortKey != nullptr) {
        config.sortKey = _properties.sortKey;
    }
    if (_properties.tagForChildren != nullptr) {
        config.addTagForChildren(_properties.tagForChildren!);
    }
    if (_properties.onTap != nullptr) {
        config.onTap = _performTap;
    }
    if (_properties.onLongPress != nullptr) {
        config.onLongPress = _performLongPress;
    }
    if (_properties.onDismiss != nullptr) {
        config.onDismiss = _performDismiss;
    }
    if (_properties.onScrollLeft != nullptr) {
        config.onScrollLeft = _performScrollLeft;
    }
    if (_properties.onScrollRight != nullptr) {
        config.onScrollRight = _performScrollRight;
    }
    if (_properties.onScrollUp != nullptr) {
        config.onScrollUp = _performScrollUp;
    }
    if (_properties.onScrollDown != nullptr) {
        config.onScrollDown = _performScrollDown;
    }
    if (_properties.onIncrease != nullptr) {
        config.onIncrease = _performIncrease;
    }
    if (_properties.onDecrease != nullptr) {
        config.onDecrease = _performDecrease;
    }
    if (_properties.onCopy != nullptr) {
        config.onCopy = _performCopy;
    }
    if (_properties.onCut != nullptr) {
        config.onCut = _performCut;
    }
    if (_properties.onPaste != nullptr) {
        config.onPaste = _performPaste;
    }
    if (_properties.onMoveCursorForwardByCharacter != nullptr) {
        config.onMoveCursorForwardByCharacter = _performMoveCursorForwardByCharacter;
    }
    if (_properties.onMoveCursorBackwardByCharacter != nullptr) {
        config.onMoveCursorBackwardByCharacter = _performMoveCursorBackwardByCharacter;
    }
    if (_properties.onMoveCursorForwardByWord != nullptr) {
        config.onMoveCursorForwardByWord = _performMoveCursorForwardByWord;
    }
    if (_properties.onMoveCursorBackwardByWord != nullptr) {
        config.onMoveCursorBackwardByWord = _performMoveCursorBackwardByWord;
    }
    if (_properties.onSetSelection != nullptr) {
        config.onSetSelection = _performSetSelection;
    }
    if (_properties.onSetText != nullptr) {
        config.onSetText = _performSetText;
    }
    if (_properties.onDidGainAccessibilityFocus != nullptr) {
        config.onDidGainAccessibilityFocus = _performDidGainAccessibilityFocus;
    }
    if (_properties.onDidLoseAccessibilityFocus != nullptr) {
        config.onDidLoseAccessibilityFocus = _performDidLoseAccessibilityFocus;
    }
    if (_properties.customSemanticsActions != nullptr) {
        config.customSemanticsActions = _properties.customSemanticsActions!;
    }
}

void RenderSemanticsAnnotations::_updateAttributedFields(SemanticsProperties value) {
    _attributedLabel = _effectiveAttributedLabel(value);
    _attributedValue = _effectiveAttributedValue(value);
    _attributedIncreasedValue = _effectiveAttributedIncreasedValue(value);
    _attributedDecreasedValue = _effectiveAttributedDecreasedValue(value);
    _attributedHint = _effectiveAttributedHint(value);
}

AttributedString RenderSemanticsAnnotations::_effectiveAttributedLabel(SemanticsProperties value) {
    return value.attributedLabel ?? (value.label == nullptr? nullptr : AttributedString(value.label!));
}

AttributedString RenderSemanticsAnnotations::_effectiveAttributedValue(SemanticsProperties value) {
    return value.attributedValue ?? (value.value == nullptr? nullptr : AttributedString(value.value!));
}

AttributedString RenderSemanticsAnnotations::_effectiveAttributedIncreasedValue(SemanticsProperties value) {
    return value.attributedIncreasedValue ?? (value.increasedValue == nullptr? nullptr : AttributedString(value.increasedValue!));
}

AttributedString RenderSemanticsAnnotations::_effectiveAttributedDecreasedValue(SemanticsProperties value) {
    return properties.attributedDecreasedValue ?? (value.decreasedValue == nullptr? nullptr : AttributedString(value.decreasedValue!));
}

AttributedString RenderSemanticsAnnotations::_effectiveAttributedHint(SemanticsProperties value) {
    return value.attributedHint ?? (value.hint == nullptr? nullptr : AttributedString(value.hint!));
}

void RenderSemanticsAnnotations::_performTap() {
    _properties.onTap?.call();
}

void RenderSemanticsAnnotations::_performLongPress() {
    _properties.onLongPress?.call();
}

void RenderSemanticsAnnotations::_performDismiss() {
    _properties.onDismiss?.call();
}

void RenderSemanticsAnnotations::_performScrollLeft() {
    _properties.onScrollLeft?.call();
}

void RenderSemanticsAnnotations::_performScrollRight() {
    _properties.onScrollRight?.call();
}

void RenderSemanticsAnnotations::_performScrollUp() {
    _properties.onScrollUp?.call();
}

void RenderSemanticsAnnotations::_performScrollDown() {
    _properties.onScrollDown?.call();
}

void RenderSemanticsAnnotations::_performIncrease() {
    _properties.onIncrease?.call();
}

void RenderSemanticsAnnotations::_performDecrease() {
    _properties.onDecrease?.call();
}

void RenderSemanticsAnnotations::_performCopy() {
    _properties.onCopy?.call();
}

void RenderSemanticsAnnotations::_performCut() {
    _properties.onCut?.call();
}

void RenderSemanticsAnnotations::_performPaste() {
    _properties.onPaste?.call();
}

void RenderSemanticsAnnotations::_performMoveCursorForwardByCharacter(bool extendSelection) {
    _properties.onMoveCursorForwardByCharacter?.call(extendSelection);
}

void RenderSemanticsAnnotations::_performMoveCursorBackwardByCharacter(bool extendSelection) {
    _properties.onMoveCursorBackwardByCharacter?.call(extendSelection);
}

void RenderSemanticsAnnotations::_performMoveCursorForwardByWord(bool extendSelection) {
    _properties.onMoveCursorForwardByWord?.call(extendSelection);
}

void RenderSemanticsAnnotations::_performMoveCursorBackwardByWord(bool extendSelection) {
    _properties.onMoveCursorBackwardByWord?.call(extendSelection);
}

void RenderSemanticsAnnotations::_performSetSelection(TextSelection selection) {
    _properties.onSetSelection?.call(selection);
}

void RenderSemanticsAnnotations::_performSetText(String text) {
    _properties.onSetText?.call(text);
}

void RenderSemanticsAnnotations::_performDidGainAccessibilityFocus() {
    _properties.onDidGainAccessibilityFocus?.call();
}

void RenderSemanticsAnnotations::_performDidLoseAccessibilityFocus() {
    _properties.onDidLoseAccessibilityFocus?.call();
}

RenderBlockSemantics::RenderBlockSemantics(bool blocking, RenderBox child) {
    {
        _blocking = blocking;
        super(child);
    }
}

bool RenderBlockSemantics::blocking() {
    return _blocking;
}

void RenderBlockSemantics::blocking(bool value) {
    assert(value != nullptr);
    if (value == _blocking) {
        return;
    }
    _blocking = value;
    markNeedsSemanticsUpdate();
}

void RenderBlockSemantics::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.isBlockingSemanticsOfPreviouslyPaintedNodes = blocking;
}

void RenderBlockSemantics::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("blocking", blocking));
}

RenderMergeSemantics::RenderMergeSemantics(RenderBox child) {
    {
        super(child);
    }
}

void RenderMergeSemantics::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    ;
}

RenderExcludeSemantics::RenderExcludeSemantics(RenderBox child, bool excluding) {
    {
        _excluding = excluding;
        super(child);
    }
    {
        assert(_excluding != nullptr);
    }
}

bool RenderExcludeSemantics::excluding() {
    return _excluding;
}

void RenderExcludeSemantics::excluding(bool value) {
    assert(value != nullptr);
    if (value == _excluding) {
        return;
    }
    _excluding = value;
    markNeedsSemanticsUpdate();
}

void RenderExcludeSemantics::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (excluding) {
        return;
    }
    super.visitChildrenForSemantics(visitor);
}

void RenderExcludeSemantics::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("excluding", excluding));
}

RenderIndexedSemantics::RenderIndexedSemantics(RenderBox child, int index) {
    {
        assert(index != nullptr);
        _index = index;
        super(child);
    }
}

int RenderIndexedSemantics::index() {
    return _index;
}

void RenderIndexedSemantics::index(int value) {
    if (value == index) {
        return;
    }
    _index = value;
    markNeedsSemanticsUpdate();
}

void RenderIndexedSemantics::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.indexInParent = index;
}

void RenderIndexedSemantics::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<int>DiagnosticsProperty("index", index));
}

RenderLeaderLayer::RenderLeaderLayer(RenderBox child, LayerLink link) {
    {
        assert(link != nullptr);
        _link = link;
        super(child);
    }
}

LayerLink RenderLeaderLayer::link() {
    return _link;
}

void RenderLeaderLayer::link(LayerLink value) {
    assert(value != nullptr);
    if (_link == value) {
        return;
    }
    _link.leaderSize = nullptr;
    _link = value;
    if (_previousLayoutSize != nullptr) {
        _link.leaderSize = _previousLayoutSize;
    }
    markNeedsPaint();
}

bool RenderLeaderLayer::alwaysNeedsCompositing() {
    return true;
}

void RenderLeaderLayer::performLayout() {
    super.performLayout();
    _previousLayoutSize = size;
    link.leaderSize = size;
}

void RenderLeaderLayer::paint(PaintingContext context, Offset offset) {
    if (layer == nullptr) {
        layer = LeaderLayer(link, offset);
    } else {
        LeaderLayer leaderLayer = (;
        ;
    }
    context.pushLayer(layer!, super.paint, Offset.zero);
    assert(());
}

void RenderLeaderLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<LayerLink>DiagnosticsProperty("link", link));
}

RenderFollowerLayer::RenderFollowerLayer(RenderBox child, Alignment followerAnchor, Alignment leaderAnchor, LayerLink link, Offset offset, bool showWhenUnlinked) {
    {
        assert(link != nullptr);
        assert(showWhenUnlinked != nullptr);
        assert(offset != nullptr);
        _link = link;
        _showWhenUnlinked = showWhenUnlinked;
        _offset = offset;
        _leaderAnchor = leaderAnchor;
        _followerAnchor = followerAnchor;
        super(child);
    }
}

LayerLink RenderFollowerLayer::link() {
    return _link;
}

void RenderFollowerLayer::link(LayerLink value) {
    assert(value != nullptr);
    if (_link == value) {
        return;
    }
    _link = value;
    markNeedsPaint();
}

bool RenderFollowerLayer::showWhenUnlinked() {
    return _showWhenUnlinked;
}

void RenderFollowerLayer::showWhenUnlinked(bool value) {
    assert(value != nullptr);
    if (_showWhenUnlinked == value) {
        return;
    }
    _showWhenUnlinked = value;
    markNeedsPaint();
}

Offset RenderFollowerLayer::offset() {
    return _offset;
}

void RenderFollowerLayer::offset(Offset value) {
    assert(value != nullptr);
    if (_offset == value) {
        return;
    }
    _offset = value;
    markNeedsPaint();
}

Alignment RenderFollowerLayer::leaderAnchor() {
    return _leaderAnchor;
}

void RenderFollowerLayer::leaderAnchor(Alignment value) {
    assert(value != nullptr);
    if (_leaderAnchor == value) {
        return;
    }
    _leaderAnchor = value;
    markNeedsPaint();
}

Alignment RenderFollowerLayer::followerAnchor() {
    return _followerAnchor;
}

void RenderFollowerLayer::followerAnchor(Alignment value) {
    assert(value != nullptr);
    if (_followerAnchor == value) {
        return;
    }
    _followerAnchor = value;
    markNeedsPaint();
}

void RenderFollowerLayer::detach() {
    layer = nullptr;
    super.detach();
}

bool RenderFollowerLayer::alwaysNeedsCompositing() {
    return true;
}

FollowerLayer RenderFollowerLayer::layer() {
    return (;
}

Matrix4 RenderFollowerLayer::getCurrentTransform() {
    return layer?.getLastTransform() ?? Matrix4.identity();
}

bool RenderFollowerLayer::hitTest(Offset position, BoxHitTestResult result) {
    if (link.leader == nullptr && !showWhenUnlinked) {
        return false;
    }
    return hitTestChildren(resultposition);
}

bool RenderFollowerLayer::hitTestChildren(Offset position, BoxHitTestResult result) {
    return result.addWithPaintTransform(getCurrentTransform(), position, );
}

void RenderFollowerLayer::paint(PaintingContext context, Offset offset) {
    Size leaderSize = link.leaderSize;
    assert(link.leaderSize != nullptr || (link.leader == nullptr || leaderAnchor == Alignment.topLeft), "$link: layer is linked to ${link.leader} but a valid leaderSize is not set. leaderSize is required when leaderAnchor is not Alignment.topLeft (current value is $leaderAnchor).");
    Offset effectiveLinkedOffset = leaderSize == nullptr? this.offset : leaderAnchor.alongSize(leaderSize) - followerAnchor.alongSize(size) + this.offset;
    assert(showWhenUnlinked != nullptr);
    if (layer == nullptr) {
        layer = FollowerLayer(link, showWhenUnlinked, effectiveLinkedOffset, offset);
    } else {
        ;
    }
    context.pushLayer(layer!, super.paint, Offset.zeroconst Rect.fromLTRB(double.negativeInfinity, double.negativeInfinity, double.infinity, double.infinity));
    assert(());
}

void RenderFollowerLayer::applyPaintTransform(RenderBox child, Matrix4 transform) {
    transform.multiply(getCurrentTransform());
}

void RenderFollowerLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<LayerLink>DiagnosticsProperty("link", link));
    properties.add(<bool>DiagnosticsProperty("showWhenUnlinked", showWhenUnlinked));
    properties.add(<Offset>DiagnosticsProperty("offset", offset));
    properties.add(TransformProperty("current transform matrix", getCurrentTransform()));
}

RenderAnnotatedRegion::RenderAnnotatedRegion(RenderBox child, bool sized, T value) {
    {
        assert(value != nullptr);
        assert(sized != nullptr);
        _value = value;
        _sized = sized;
        super(child);
    }
}

T RenderAnnotatedRegion::value() {
    return _value;
}

void RenderAnnotatedRegion::value(T newValue) {
    if (_value == newValue) {
        return;
    }
    _value = newValue;
    markNeedsPaint();
}

bool RenderAnnotatedRegion::sized() {
    return _sized;
}

void RenderAnnotatedRegion::sized(bool value) {
    if (_sized == value) {
        return;
    }
    _sized = value;
    markNeedsPaint();
}

void RenderAnnotatedRegion::paint(PaintingContext context, Offset offset) {
    AnnotatedRegionLayer<T> layer = <T>AnnotatedRegionLayer(valuesized? size : nullptr, sized? offset : nullptr);
    context.pushLayer(layer, super.paint, offset);
}
