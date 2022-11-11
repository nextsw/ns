#include "proxy_box.hpp"
RenderProxyBoxCls::RenderProxyBoxCls(RenderBox child) {
    {
        this->child = child;
    }
}

template<typename T>
void RenderProxyBoxMixinCls<T>::setupParentData(RenderObject child) {
    if (!is<ParentData>(child->parentData)) {
        child->parentData = make<ParentDataCls>();
    }
}

template<typename T>
double RenderProxyBoxMixinCls<T>::computeMinIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!->getMinIntrinsicWidth(height);
    }
    return 0.0;
}

template<typename T>
double RenderProxyBoxMixinCls<T>::computeMaxIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!->getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

template<typename T>
double RenderProxyBoxMixinCls<T>::computeMinIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!->getMinIntrinsicHeight(width);
    }
    return 0.0;
}

template<typename T>
double RenderProxyBoxMixinCls<T>::computeMaxIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!->getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

template<typename T>
double RenderProxyBoxMixinCls<T>::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (child != nullptr) {
        return child!->getDistanceToActualBaseline(baseline);
    }
    return super->computeDistanceToActualBaseline(baseline);
}

template<typename T>
Size RenderProxyBoxMixinCls<T>::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        return child!->getDryLayout(constraints);
    }
    return computeSizeForNoChild(constraints);
}

template<typename T>
void RenderProxyBoxMixinCls<T>::performLayout() {
    if (child != nullptr) {
        child!->layout(constraintstrue);
        size = child!->size;
    } else {
        size = computeSizeForNoChild(constraints);
    }
}

template<typename T>
Size RenderProxyBoxMixinCls<T>::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints->smallest();
}

template<typename T>
bool RenderProxyBoxMixinCls<T>::hitTestChildren(BoxHitTestResult result, Offset position) {
    return child?->hitTest(resultposition) | false;
}

template<typename T>
void RenderProxyBoxMixinCls<T>::applyPaintTransform(RenderObject child, Matrix4 transform) {
}

template<typename T>
void RenderProxyBoxMixinCls<T>::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context->paintChild(child!, offset);
    }
}

RenderProxyBoxWithHitTestBehaviorCls::RenderProxyBoxWithHitTestBehaviorCls(HitTestBehavior behavior, RenderBox child) : RenderProxyBox(child) {
}

bool RenderProxyBoxWithHitTestBehaviorCls::hitTest(BoxHitTestResult result, Offset position) {
    bool hitTarget = false;
    if (size->contains(position)) {
        hitTarget = hitTestChildren(resultposition) || hitTestSelf(position);
        if (hitTarget || behavior == HitTestBehaviorCls::translucent) {
            result->add(make<BoxHitTestEntryCls>(this, position));
        }
    }
    return hitTarget;
}

bool RenderProxyBoxWithHitTestBehaviorCls::hitTestSelf(Offset position) {
    return behavior == HitTestBehaviorCls::opaque;
}

void RenderProxyBoxWithHitTestBehaviorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<HitTestBehavior>make<EnumPropertyCls>(__s("behavior"), behaviornullptr));
}

RenderConstrainedBoxCls::RenderConstrainedBoxCls(BoxConstraints additionalConstraints, RenderBox child) : RenderProxyBox(child) {
    {
        assert(additionalConstraints != nullptr);
        assert(additionalConstraints->debugAssertIsValid());
        _additionalConstraints = additionalConstraints;
    }
}

BoxConstraints RenderConstrainedBoxCls::additionalConstraints() {
    return _additionalConstraints;
}

void RenderConstrainedBoxCls::additionalConstraints(BoxConstraints value) {
    assert(value != nullptr);
    assert(value->debugAssertIsValid());
    if (_additionalConstraints == value) {
        return;
    }
    _additionalConstraints = value;
    markNeedsLayout();
}

double RenderConstrainedBoxCls::computeMinIntrinsicWidth(double height) {
    if (_additionalConstraints->hasBoundedWidth() && _additionalConstraints->hasTightWidth()) {
        return _additionalConstraints->minWidth;
    }
    double width = super->computeMinIntrinsicWidth(height);
    assert(width->isFinite);
    if (!_additionalConstraints->hasInfiniteWidth()) {
        return _additionalConstraints->constrainWidth(width);
    }
    return width;
}

double RenderConstrainedBoxCls::computeMaxIntrinsicWidth(double height) {
    if (_additionalConstraints->hasBoundedWidth() && _additionalConstraints->hasTightWidth()) {
        return _additionalConstraints->minWidth;
    }
    double width = super->computeMaxIntrinsicWidth(height);
    assert(width->isFinite);
    if (!_additionalConstraints->hasInfiniteWidth()) {
        return _additionalConstraints->constrainWidth(width);
    }
    return width;
}

double RenderConstrainedBoxCls::computeMinIntrinsicHeight(double width) {
    if (_additionalConstraints->hasBoundedHeight() && _additionalConstraints->hasTightHeight()) {
        return _additionalConstraints->minHeight;
    }
    double height = super->computeMinIntrinsicHeight(width);
    assert(height->isFinite);
    if (!_additionalConstraints->hasInfiniteHeight()) {
        return _additionalConstraints->constrainHeight(height);
    }
    return height;
}

double RenderConstrainedBoxCls::computeMaxIntrinsicHeight(double width) {
    if (_additionalConstraints->hasBoundedHeight() && _additionalConstraints->hasTightHeight()) {
        return _additionalConstraints->minHeight;
    }
    double height = super->computeMaxIntrinsicHeight(width);
    assert(height->isFinite);
    if (!_additionalConstraints->hasInfiniteHeight()) {
        return _additionalConstraints->constrainHeight(height);
    }
    return height;
}

void RenderConstrainedBoxCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    if (child != nullptr) {
        child!->layout(_additionalConstraints->enforce(constraints)true);
        size = child!->size;
    } else {
        size = _additionalConstraints->enforce(constraints)->constrain(SizeCls::zero);
    }
}

Size RenderConstrainedBoxCls::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        return child!->getDryLayout(_additionalConstraints->enforce(constraints));
    } else {
        return _additionalConstraints->enforce(constraints)->constrain(SizeCls::zero);
    }
}

void RenderConstrainedBoxCls::debugPaintSize(PaintingContext context, Offset offset) {
    super->debugPaintSize(context, offset);
    assert([=] () {
        Paint paint;
        if (child == nullptr || child!->size->isEmpty) {
                    auto _c1 = make<PaintCls>();        _c1.color = make<ColorCls>(0x90909090);paint = _c1;
            context->canvas()->drawRect(offset & size, paint);
        }
        return true;
    }());
}

void RenderConstrainedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BoxConstraints>make<DiagnosticsPropertyCls>(__s("additionalConstraints"), additionalConstraints()));
}

RenderLimitedBoxCls::RenderLimitedBoxCls(RenderBox child, double maxHeight, double maxWidth) : RenderProxyBox(child) {
    {
        assert(maxWidth != nullptr && maxWidth >= 0.0);
        assert(maxHeight != nullptr && maxHeight >= 0.0);
        _maxWidth = maxWidth;
        _maxHeight = maxHeight;
    }
}

double RenderLimitedBoxCls::maxWidth() {
    return _maxWidth;
}

void RenderLimitedBoxCls::maxWidth(double value) {
    assert(value != nullptr && value >= 0.0);
    if (_maxWidth == value) {
        return;
    }
    _maxWidth = value;
    markNeedsLayout();
}

double RenderLimitedBoxCls::maxHeight() {
    return _maxHeight;
}

void RenderLimitedBoxCls::maxHeight(double value) {
    assert(value != nullptr && value >= 0.0);
    if (_maxHeight == value) {
        return;
    }
    _maxHeight = value;
    markNeedsLayout();
}

Size RenderLimitedBoxCls::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(constraints, ChildLayoutHelperCls::dryLayoutChild);
}

void RenderLimitedBoxCls::performLayout() {
    size = _computeSize(constraints, ChildLayoutHelperCls::layoutChild);
}

void RenderLimitedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("maxWidth"), maxWidth()double->infinity));
    properties->add(make<DoublePropertyCls>(__s("maxHeight"), maxHeight()double->infinity));
}

BoxConstraints RenderLimitedBoxCls::_limitConstraints(BoxConstraints constraints) {
    return make<BoxConstraintsCls>(constraints->minWidth, constraints->hasBoundedWidth()? constraints->maxWidth : constraints->constrainWidth(maxWidth()), constraints->minHeight, constraints->hasBoundedHeight()? constraints->maxHeight : constraints->constrainHeight(maxHeight()));
}

Size RenderLimitedBoxCls::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    if (child != nullptr) {
        Size childSize = layoutChild(child!, _limitConstraints(constraints));
        return constraints->constrain(childSize);
    }
    return _limitConstraints(constraints)->constrain(SizeCls::zero);
}

RenderAspectRatioCls::RenderAspectRatioCls(double aspectRatio, RenderBox child) : RenderProxyBox(child) {
    {
        assert(aspectRatio != nullptr);
        assert(aspectRatio > 0.0);
        assert(aspectRatio->isFinite);
        _aspectRatio = aspectRatio;
    }
}

double RenderAspectRatioCls::aspectRatio() {
    return _aspectRatio;
}

void RenderAspectRatioCls::aspectRatio(double value) {
    assert(value != nullptr);
    assert(value > 0.0);
    assert(value->isFinite);
    if (_aspectRatio == value) {
        return;
    }
    _aspectRatio = value;
    markNeedsLayout();
}

double RenderAspectRatioCls::computeMinIntrinsicWidth(double height) {
    if (height->isFinite) {
        return height * _aspectRatio;
    }
    if (child != nullptr) {
        return child!->getMinIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderAspectRatioCls::computeMaxIntrinsicWidth(double height) {
    if (height->isFinite) {
        return height * _aspectRatio;
    }
    if (child != nullptr) {
        return child!->getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

double RenderAspectRatioCls::computeMinIntrinsicHeight(double width) {
    if (width->isFinite) {
        return width / _aspectRatio;
    }
    if (child != nullptr) {
        return child!->getMinIntrinsicHeight(width);
    }
    return 0.0;
}

double RenderAspectRatioCls::computeMaxIntrinsicHeight(double width) {
    if (width->isFinite) {
        return width / _aspectRatio;
    }
    if (child != nullptr) {
        return child!->getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

Size RenderAspectRatioCls::computeDryLayout(BoxConstraints constraints) {
    return _applyAspectRatio(constraints);
}

void RenderAspectRatioCls::performLayout() {
    size = computeDryLayout(constraints);
    if (child != nullptr) {
        child!->layout(BoxConstraintsCls->tight(size));
    }
}

void RenderAspectRatioCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("aspectRatio"), aspectRatio()));
}

Size RenderAspectRatioCls::_applyAspectRatio(BoxConstraints constraints) {
    assert(constraints->debugAssertIsValid());
    assert([=] () {
        if (!constraints->hasBoundedWidth() && !constraints->hasBoundedHeight()) {
            throw make<FlutterErrorCls>(__s("$runtimeType has unbounded constraints.\nThis $runtimeType was given an aspect ratio of $aspectRatio but was given both unbounded width and unbounded height constraints. Because both constraints were unbounded, this render object doesn't know how much size to consume."));
        }
        return true;
    }());
    if (constraints->isTight()) {
        return constraints->smallest();
    }
    double width = constraints->maxWidth;
    double height;
    if (width->isFinite) {
        height = width / _aspectRatio;
    } else {
        height = constraints->maxHeight;
        width = height * _aspectRatio;
    }
    if (width > constraints->maxWidth) {
        width = constraints->maxWidth;
        height = width / _aspectRatio;
    }
    if (height > constraints->maxHeight) {
        height = constraints->maxHeight;
        width = height * _aspectRatio;
    }
    if ( < constraints->minWidth) {
        width = constraints->minWidth;
        height = width / _aspectRatio;
    }
    if ( < constraints->minHeight) {
        height = constraints->minHeight;
        width = height * _aspectRatio;
    }
    return constraints->constrain(make<SizeCls>(width, height));
}

RenderIntrinsicWidthCls::RenderIntrinsicWidthCls(RenderBox child, double stepHeight, double stepWidth) : RenderProxyBox(child) {
    {
        assert(stepWidth == nullptr || stepWidth > 0.0);
        assert(stepHeight == nullptr || stepHeight > 0.0);
        _stepWidth = stepWidth;
        _stepHeight = stepHeight;
    }
}

double RenderIntrinsicWidthCls::stepWidth() {
    return _stepWidth;
}

void RenderIntrinsicWidthCls::stepWidth(double value) {
    assert(value == nullptr || value > 0.0);
    if (value == _stepWidth) {
        return;
    }
    _stepWidth = value;
    markNeedsLayout();
}

double RenderIntrinsicWidthCls::stepHeight() {
    return _stepHeight;
}

void RenderIntrinsicWidthCls::stepHeight(double value) {
    assert(value == nullptr || value > 0.0);
    if (value == _stepHeight) {
        return;
    }
    _stepHeight = value;
    markNeedsLayout();
}

double RenderIntrinsicWidthCls::computeMinIntrinsicWidth(double height) {
    return computeMaxIntrinsicWidth(height);
}

double RenderIntrinsicWidthCls::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    double width = child!->getMaxIntrinsicWidth(height);
    return _applyStep(width, _stepWidth);
}

double RenderIntrinsicWidthCls::computeMinIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!width->isFinite) {
        width = computeMaxIntrinsicWidth(double->infinity);
    }
    assert(width->isFinite);
    double height = child!->getMinIntrinsicHeight(width);
    return _applyStep(height, _stepHeight);
}

double RenderIntrinsicWidthCls::computeMaxIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!width->isFinite) {
        width = computeMaxIntrinsicWidth(double->infinity);
    }
    assert(width->isFinite);
    double height = child!->getMaxIntrinsicHeight(width);
    return _applyStep(height, _stepHeight);
}

Size RenderIntrinsicWidthCls::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(ChildLayoutHelperCls::dryLayoutChild, constraints);
}

void RenderIntrinsicWidthCls::performLayout() {
    size = _computeSize(ChildLayoutHelperCls::layoutChild, constraints);
}

void RenderIntrinsicWidthCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("stepWidth"), stepWidth()));
    properties->add(make<DoublePropertyCls>(__s("stepHeight"), stepHeight()));
}

double RenderIntrinsicWidthCls::_applyStep(double input, double step) {
    assert(input->isFinite);
    if (step == nullptr) {
        return input;
    }
    return (input / step)->ceil() * step;
}

Size RenderIntrinsicWidthCls::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    if (child != nullptr) {
        if (!constraints->hasTightWidth()) {
            double width = child!->getMaxIntrinsicWidth(constraints->maxHeight);
            assert(width->isFinite);
            constraints = constraints->tighten(_applyStep(width, _stepWidth));
        }
        if (_stepHeight != nullptr) {
            double height = child!->getMaxIntrinsicHeight(constraints->maxWidth);
            assert(height->isFinite);
            constraints = constraints->tighten(_applyStep(height, _stepHeight));
        }
        return layoutChild(child!, constraints);
    } else {
        return constraints->smallest();
    }
}

RenderIntrinsicHeightCls::RenderIntrinsicHeightCls(RenderBox child) : RenderProxyBox(child) {
}

double RenderIntrinsicHeightCls::computeMinIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!height->isFinite) {
        height = child!->getMaxIntrinsicHeight(double->infinity);
    }
    assert(height->isFinite);
    return child!->getMinIntrinsicWidth(height);
}

double RenderIntrinsicHeightCls::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    if (!height->isFinite) {
        height = child!->getMaxIntrinsicHeight(double->infinity);
    }
    assert(height->isFinite);
    return child!->getMaxIntrinsicWidth(height);
}

double RenderIntrinsicHeightCls::computeMinIntrinsicHeight(double width) {
    return computeMaxIntrinsicHeight(width);
}

Size RenderIntrinsicHeightCls::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(ChildLayoutHelperCls::dryLayoutChild, constraints);
}

void RenderIntrinsicHeightCls::performLayout() {
    size = _computeSize(ChildLayoutHelperCls::layoutChild, constraints);
}

Size RenderIntrinsicHeightCls::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    if (child != nullptr) {
        if (!constraints->hasTightHeight()) {
            double height = child!->getMaxIntrinsicHeight(constraints->maxWidth);
            assert(height->isFinite);
            constraints = constraints->tighten(height);
        }
        return layoutChild(child!, constraints);
    } else {
        return constraints->smallest();
    }
}

RenderOpacityCls::RenderOpacityCls(bool alwaysIncludeSemantics, RenderBox child, double opacity) : RenderProxyBox(child) {
    {
        assert(opacity != nullptr);
        assert(opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
        _opacity = opacity;
        _alwaysIncludeSemantics = alwaysIncludeSemantics;
        _alpha = ui->ColorCls->getAlphaFromOpacity(opacity);
    }
}

bool RenderOpacityCls::alwaysNeedsCompositing() {
    return child != nullptr && _alpha > 0;
}

double RenderOpacityCls::opacity() {
    return _opacity;
}

void RenderOpacityCls::opacity(double value) {
    assert(value != nullptr);
    assert(value >= 0.0 && value <= 1.0);
    if (_opacity == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing();
    bool wasVisible = _alpha != 0;
    _opacity = value;
    _alpha = ui->ColorCls->getAlphaFromOpacity(_opacity);
    if (didNeedCompositing != alwaysNeedsCompositing()) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
    if (wasVisible != (_alpha != 0) && !alwaysIncludeSemantics()) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderOpacityCls::alwaysIncludeSemantics() {
    return _alwaysIncludeSemantics;
}

void RenderOpacityCls::alwaysIncludeSemantics(bool value) {
    if (value == _alwaysIncludeSemantics) {
        return;
    }
    _alwaysIncludeSemantics = value;
    markNeedsSemanticsUpdate();
}

bool RenderOpacityCls::paintsChild(RenderBox child) {
    assert(child->parent == this);
    return _alpha > 0;
}

void RenderOpacityCls::paint(PaintingContext context, Offset offset) {
    if (child == nullptr) {
        return;
    }
    if (_alpha == 0) {
        layer = nullptr;
        return;
    }
    assert(needsCompositing);
    layer = context->pushOpacity(offset, _alpha, super->paintas<OpacityLayer>(layer));
    assert([=] () {
        layer!->debugCreator = debugCreator;
        return true;
    }());
}

void RenderOpacityCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && (_alpha != 0 || alwaysIncludeSemantics())) {
        visitor(child!);
    }
}

void RenderOpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("opacity"), opacity()));
    properties->add(make<FlagPropertyCls>(__s("alwaysIncludeSemantics")alwaysIncludeSemantics(), __s("alwaysIncludeSemantics")));
}

template<typename T>
bool RenderAnimatedOpacityMixinCls<T>::isRepaintBoundary() {
    return child != nullptr && _currentlyIsRepaintBoundary!;
}

template<typename T>
OffsetLayer RenderAnimatedOpacityMixinCls<T>::updateCompositedLayer(OpacityLayer oldLayer) {
    OpacityLayer updatedLayer = oldLayer | make<OpacityLayerCls>();
    updatedLayer->alpha() = _alpha;
    return updatedLayer;
}

template<typename T>
Animation<double> RenderAnimatedOpacityMixinCls<T>::opacity() {
    return _opacity!;
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::opacity(Animation<double> value) {
    assert(value != nullptr);
    if (_opacity == value) {
        return;
    }
    if (attached && _opacity != nullptr) {
        opacity()->removeListener(_updateOpacity);
    }
    _opacity = value;
    if (attached) {
        opacity()->addListener(_updateOpacity);
    }
    _updateOpacity();
}

template<typename T>
bool RenderAnimatedOpacityMixinCls<T>::alwaysIncludeSemantics() {
    return _alwaysIncludeSemantics!;
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::alwaysIncludeSemantics(bool value) {
    if (value == _alwaysIncludeSemantics) {
        return;
    }
    _alwaysIncludeSemantics = value;
    markNeedsSemanticsUpdate();
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::attach(PipelineOwner owner) {
    super->attach(owner);
    opacity()->addListener(_updateOpacity);
    _updateOpacity();
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::detach() {
    opacity()->removeListener(_updateOpacity);
    super->detach();
}

template<typename T>
bool RenderAnimatedOpacityMixinCls<T>::paintsChild(RenderObject child) {
    assert(child->parent == this);
    return opacity()->value() > 0;
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::paint(PaintingContext context, Offset offset) {
    if (_alpha == 0) {
        return;
    }
    super->paint(context, offset);
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && (_alpha != 0 || alwaysIncludeSemantics())) {
        visitor(child!);
    }
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("opacity"), opacity()));
    properties->add(make<FlagPropertyCls>(__s("alwaysIncludeSemantics")alwaysIncludeSemantics(), __s("alwaysIncludeSemantics")));
}

template<typename T>
void RenderAnimatedOpacityMixinCls<T>::_updateOpacity() {
    int oldAlpha = _alpha;
    _alpha = ui->ColorCls->getAlphaFromOpacity(opacity()->value());
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

RenderAnimatedOpacityCls::RenderAnimatedOpacityCls(bool alwaysIncludeSemantics, RenderBox child, Animation<double> opacity) : RenderProxyBox(child) {
    {
        assert(opacity != nullptr);
        assert(alwaysIncludeSemantics != nullptr);
    }
    {
        this->opacity = opacity;
        this->alwaysIncludeSemantics = alwaysIncludeSemantics;
    }
}

RenderShaderMaskCls::RenderShaderMaskCls(BlendMode blendMode, RenderBox child, ShaderCallback shaderCallback) : RenderProxyBox(child) {
    {
        assert(shaderCallback != nullptr);
        assert(blendMode != nullptr);
        _shaderCallback = shaderCallback;
        _blendMode = blendMode;
    }
}

ShaderMaskLayer RenderShaderMaskCls::layer() {
    return as<ShaderMaskLayer>(super->layer);
}

ShaderCallback RenderShaderMaskCls::shaderCallback() {
    return _shaderCallback;
}

void RenderShaderMaskCls::shaderCallback(ShaderCallback value) {
    assert(value != nullptr);
    if (_shaderCallback == value) {
        return;
    }
    _shaderCallback = value;
    markNeedsPaint();
}

BlendMode RenderShaderMaskCls::blendMode() {
    return _blendMode;
}

void RenderShaderMaskCls::blendMode(BlendMode value) {
    assert(value != nullptr);
    if (_blendMode == value) {
        return;
    }
    _blendMode = value;
    markNeedsPaint();
}

bool RenderShaderMaskCls::alwaysNeedsCompositing() {
    return child != nullptr;
}

void RenderShaderMaskCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        assert(needsCompositing);
        layer() |= make<ShaderMaskLayerCls>();
            auto _c1 = layer()!;    _c1.shader = auto _c2 = _shaderCallback(OffsetCls::zero & size);    _c2.maskRect = auto _c3 = offset & size;    _c3.blendMode() = _blendMode;    _c3;    _c2;_c1;
        context->pushLayer(layer()!, super->paint, offset);
        assert([=] () {
            layer()!->debugCreator = debugCreator;
            return true;
        }());
    } else {
        layer() = nullptr;
    }
}

RenderBackdropFilterCls::RenderBackdropFilterCls(BlendMode blendMode, RenderBox child, ImageFilter filter) : RenderProxyBox(child) {
    {
        assert(filter != nullptr);
        assert(blendMode != nullptr);
        _filter = filter;
        _blendMode = blendMode;
    }
}

BackdropFilterLayer RenderBackdropFilterCls::layer() {
    return as<BackdropFilterLayer>(super->layer);
}

ImageFilter RenderBackdropFilterCls::filter() {
    return _filter;
}

void RenderBackdropFilterCls::filter(ImageFilter value) {
    assert(value != nullptr);
    if (_filter == value) {
        return;
    }
    _filter = value;
    markNeedsPaint();
}

BlendMode RenderBackdropFilterCls::blendMode() {
    return _blendMode;
}

void RenderBackdropFilterCls::blendMode(BlendMode value) {
    assert(value != nullptr);
    if (_blendMode == value) {
        return;
    }
    _blendMode = value;
    markNeedsPaint();
}

bool RenderBackdropFilterCls::alwaysNeedsCompositing() {
    return child != nullptr;
}

void RenderBackdropFilterCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        assert(needsCompositing);
        layer() |= make<BackdropFilterLayerCls>();
        layer()!->filter() = _filter;
        layer()!->blendMode() = _blendMode;
        context->pushLayer(layer()!, super->paint, offset);
        assert([=] () {
            layer()!->debugCreator = debugCreator;
            return true;
        }());
    } else {
        layer() = nullptr;
    }
}

template<typename T>
CustomClipperCls<T>::CustomClipperCls(Listenable reclip) {
    {
        _reclip = reclip;
    }
}

template<typename T>
void CustomClipperCls<T>::addListener(VoidCallback listener) {
    return _reclip?->addListener(listener);
}

template<typename T>
void CustomClipperCls<T>::removeListener(VoidCallback listener) {
    return _reclip?->removeListener(listener);
}

template<typename T>
Rect CustomClipperCls<T>::getApproximateClipRect(Size size) {
    return OffsetCls::zero & size;
}

template<typename T>
String CustomClipperCls<T>::toString() {
    return objectRuntimeType(this, __s("CustomClipper"));
}

ShapeBorderClipperCls::ShapeBorderClipperCls(ShapeBorder shape, TextDirection textDirection) {
    {
        assert(shape != nullptr);
    }
}

Path ShapeBorderClipperCls::getClip(Size size) {
    return shape->getOuterPath(OffsetCls::zero & sizetextDirection);
}

bool ShapeBorderClipperCls::shouldReclip(CustomClipper<Path> oldClipper) {
    if (oldClipper->runtimeType != ShapeBorderClipperCls) {
        return true;
    }
    ShapeBorderClipper typedOldClipper = as<ShapeBorderClipper>(oldClipper);
    return typedOldClipper->shape != shape || typedOldClipper->textDirection != textDirection;
}

template<typename T>
CustomClipper<T> _RenderCustomClipCls<T>::clipper() {
    return _clipper;
}

template<typename T>
void _RenderCustomClipCls<T>::clipper(CustomClipper<T> newClipper) {
    if (_clipper == newClipper) {
        return;
    }
    CustomClipper<T> oldClipper = _clipper;
    _clipper = newClipper;
    assert(newClipper != nullptr || oldClipper != nullptr);
    if (newClipper == nullptr || oldClipper == nullptr || newClipper->runtimeType != oldClipper->runtimeType || newClipper->shouldReclip(oldClipper)) {
        _markNeedsClip();
    }
    if (attached) {
        oldClipper?->removeListener(_markNeedsClip);
        newClipper?->addListener(_markNeedsClip);
    }
}

template<typename T>
void _RenderCustomClipCls<T>::attach(PipelineOwner owner) {
    super->attach(owner);
    _clipper?->addListener(_markNeedsClip);
}

template<typename T>
void _RenderCustomClipCls<T>::detach() {
    _clipper?->removeListener(_markNeedsClip);
    super->detach();
}

template<typename T>
Clip _RenderCustomClipCls<T>::clipBehavior() {
    return _clipBehavior;
}

template<typename T>
void _RenderCustomClipCls<T>::clipBehavior(Clip value) {
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
    }
}

template<typename T>
void _RenderCustomClipCls<T>::performLayout() {
    Size oldSize = hasSize? size : nullptr;
    super->performLayout();
    if (oldSize != size) {
        _clip = nullptr;
    }
}

template<typename T>
Rect _RenderCustomClipCls<T>::describeApproximatePaintClip(RenderObject child) {
    ;
}

template<typename T>
void _RenderCustomClipCls<T>::debugPaintSize(PaintingContext context, Offset offset) {
    assert([=] () {
            auto _c1 = make<PaintCls>();    _c1.shader = auto _c2 = ui->GradientCls->linear(OffsetCls::zero, make<OffsetCls>(10.0, 10.0), makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem), makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem), TileModeCls::repeated);    _c2.strokeWidth = auto _c3 = 2.0;    _c3.style = PaintingStyleCls::stroke;    _c3;    _c2;_debugPaint |= _c1;
            auto _c4 = make<TextPainterCls>(make<TextSpanCls>(__s("✂"), make<TextStyleCls>(make<ColorCls>(0xFFFF00FF), 14.0)), TextDirectionCls::rtl);    _c4.layout();_debugText |= _c4;
        return true;
    }());
}

template<typename T>
_RenderCustomClipCls<T>::_RenderCustomClipCls(RenderBox child, Clip clipBehavior, CustomClipper<T> clipper) : RenderProxyBox(child) {
    {
        assert(clipBehavior != nullptr);
        _clipper = clipper;
        _clipBehavior = clipBehavior;
    }
}

template<typename T>
void _RenderCustomClipCls<T>::_markNeedsClip() {
    _clip = nullptr;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

template<typename T>
void _RenderCustomClipCls<T>::_updateClip() {
    _clip |= _clipper?->getClip(size) | _defaultClip();
}

RenderClipRectCls::RenderClipRectCls(Unknown child, Unknown clipBehavior, Unknown clipper) {
    {
        assert(clipBehavior != nullptr);
    }
}

bool RenderClipRectCls::hitTest(BoxHitTestResult result, Offset position) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!->contains(position)) {
            return false;
        }
    }
    return super->hitTest(resultposition);
}

void RenderClipRectCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != ClipCls::none) {
            _updateClip();
            layer = context->pushClipRect(needsCompositing, offset, _clip!, super->paintclipBehavior, as<ClipRectLayer>(layer));
        } else {
            context->paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipRectCls::debugPaintSize(PaintingContext context, Offset offset) {
    assert([=] () {
        if (child != nullptr) {
            super->debugPaintSize(context, offset);
            if (clipBehavior != ClipCls::none) {
                context->canvas()->drawRect(_clip!->shift(offset), _debugPaint!);
                _debugText!->paint(context->canvas(), offset + make<OffsetCls>(_clip!->width / 8.0, -_debugText!->text!->style!->fontSize! * 1.1));
            }
        }
        return true;
    }());
}

Rect RenderClipRectCls::_defaultClip() {
    return OffsetCls::zero & size;
}

RenderClipRRectCls::RenderClipRRectCls(BorderRadiusGeometry borderRadius, Unknown child, Unknown clipBehavior, CustomClipper<RRect> clipper, TextDirection textDirection) : _RenderCustomClip<RRect>(clipper) {
    {
        assert(clipBehavior != nullptr);
        _borderRadius = borderRadius;
        _textDirection = textDirection;
    }
    {
        assert(_borderRadius != nullptr || clipper != nullptr);
    }
}

BorderRadiusGeometry RenderClipRRectCls::borderRadius() {
    return _borderRadius;
}

void RenderClipRRectCls::borderRadius(BorderRadiusGeometry value) {
    assert(value != nullptr);
    if (_borderRadius == value) {
        return;
    }
    _borderRadius = value;
    _markNeedsClip();
}

TextDirection RenderClipRRectCls::textDirection() {
    return _textDirection;
}

void RenderClipRRectCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedsClip();
}

bool RenderClipRRectCls::hitTest(BoxHitTestResult result, Offset position) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!->contains(position)) {
            return false;
        }
    }
    return super->hitTest(resultposition);
}

void RenderClipRRectCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != ClipCls::none) {
            _updateClip();
            layer = context->pushClipRRect(needsCompositing, offset, _clip!->outerRect, _clip!, super->paintclipBehavior, as<ClipRRectLayer>(layer));
        } else {
            context->paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipRRectCls::debugPaintSize(PaintingContext context, Offset offset) {
    assert([=] () {
        if (child != nullptr) {
            super->debugPaintSize(context, offset);
            if (clipBehavior != ClipCls::none) {
                context->canvas()->drawRRect(_clip!->shift(offset), _debugPaint!);
                _debugText!->paint(context->canvas(), offset + make<OffsetCls>(_clip!->tlRadiusX, -_debugText!->text!->style!->fontSize! * 1.1));
            }
        }
        return true;
    }());
}

RRect RenderClipRRectCls::_defaultClip() {
    return _borderRadius->resolve(textDirection())->toRRect(OffsetCls::zero & size);
}

RenderClipOvalCls::RenderClipOvalCls(Unknown child, Unknown clipBehavior, Unknown clipper) {
    {
        assert(clipBehavior != nullptr);
    }
}

bool RenderClipOvalCls::hitTest(BoxHitTestResult result, Offset position) {
    _updateClip();
    assert(_clip != nullptr);
    Offset center = _clip!->center;
    Offset offset = make<OffsetCls>((position->dx() - center->dx()) / _clip!->width, (position->dy() - center->dy()) / _clip!->height);
    if (offset->distanceSquared() > 0.25) {
        return false;
    }
    return super->hitTest(resultposition);
}

void RenderClipOvalCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != ClipCls::none) {
            _updateClip();
            layer = context->pushClipPath(needsCompositing, offset, _clip!, _getClipPath(_clip!), super->paintclipBehavior, as<ClipPathLayer>(layer));
        } else {
            context->paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipOvalCls::debugPaintSize(PaintingContext context, Offset offset) {
    assert([=] () {
        if (child != nullptr) {
            super->debugPaintSize(context, offset);
            if (clipBehavior != ClipCls::none) {
                context->canvas()->drawPath(_getClipPath(_clip!)->shift(offset), _debugPaint!);
                _debugText!->paint(context->canvas(), offset + make<OffsetCls>((_clip!->width - _debugText!->width) / 2.0, -_debugText!->text!->style!->fontSize! * 1.1));
            }
        }
        return true;
    }());
}

Path RenderClipOvalCls::_getClipPath(Rect rect) {
    if (rect != _cachedRect) {
        _cachedRect = rect;
            auto _c1 = make<PathCls>();    _c1.addOval(_cachedRect!);_cachedPath = _c1;
    }
    return _cachedPath;
}

Rect RenderClipOvalCls::_defaultClip() {
    return OffsetCls::zero & size;
}

RenderClipPathCls::RenderClipPathCls(Unknown child, Unknown clipBehavior, Unknown clipper) {
    {
        assert(clipBehavior != nullptr);
    }
}

bool RenderClipPathCls::hitTest(BoxHitTestResult result, Offset position) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!->contains(position)) {
            return false;
        }
    }
    return super->hitTest(resultposition);
}

void RenderClipPathCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        if (clipBehavior != ClipCls::none) {
            _updateClip();
            layer = context->pushClipPath(needsCompositing, offset, OffsetCls::zero & size, _clip!, super->paintclipBehavior, as<ClipPathLayer>(layer));
        } else {
            context->paintChild(child!, offset);
            layer = nullptr;
        }
    } else {
        layer = nullptr;
    }
}

void RenderClipPathCls::debugPaintSize(PaintingContext context, Offset offset) {
    assert([=] () {
        if (child != nullptr) {
            super->debugPaintSize(context, offset);
            if (clipBehavior != ClipCls::none) {
                context->canvas()->drawPath(_clip!->shift(offset), _debugPaint!);
                _debugText!->paint(context->canvas(), offset);
            }
        }
        return true;
    }());
}

Path RenderClipPathCls::_defaultClip() {
    return _c1;
}

template<typename T>
double _RenderPhysicalModelBaseCls<T>::elevation() {
    return _elevation;
}

template<typename T>
void _RenderPhysicalModelBaseCls<T>::elevation(double value) {
    auto _c1 = make<PathCls>();_c1.addRect(OffsetCls::zero & size);assert(value != nullptr && value >= 0.0);
    if (elevation() == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing;
    _elevation = value;
    if (didNeedCompositing != alwaysNeedsCompositing) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
}

template<typename T>
Color _RenderPhysicalModelBaseCls<T>::shadowColor() {
    return _shadowColor;
}

template<typename T>
void _RenderPhysicalModelBaseCls<T>::shadowColor(Color value) {
    assert(value != nullptr);
    if (shadowColor() == value) {
        return;
    }
    _shadowColor = value;
    markNeedsPaint();
}

template<typename T>
Color _RenderPhysicalModelBaseCls<T>::color() {
    return _color;
}

template<typename T>
void _RenderPhysicalModelBaseCls<T>::color(Color value) {
    assert(value != nullptr);
    if (color() == value) {
        return;
    }
    _color = value;
    markNeedsPaint();
}

template<typename T>
void _RenderPhysicalModelBaseCls<T>::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->elevation() = elevation();
}

template<typename T>
void _RenderPhysicalModelBaseCls<T>::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(make<DoublePropertyCls>(__s("elevation"), elevation()));
    description->add(make<ColorPropertyCls>(__s("color"), color()));
    description->add(make<ColorPropertyCls>(__s("shadowColor"), color()));
}

template<typename T>
_RenderPhysicalModelBaseCls<T>::_RenderPhysicalModelBaseCls(Unknown child, Unknown clipBehavior, Unknown clipper, Color color, double elevation, Color shadowColor) {
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

RenderPhysicalModelCls::RenderPhysicalModelCls(BorderRadius borderRadius, Unknown child, Unknown clipBehavior, Unknown color, Unknown elevation, Unknown shadowColor, BoxShape shape) {
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

BoxShape RenderPhysicalModelCls::shape() {
    return _shape;
}

void RenderPhysicalModelCls::shape(BoxShape value) {
    assert(value != nullptr);
    if (shape() == value) {
        return;
    }
    _shape = value;
    _markNeedsClip();
}

BorderRadius RenderPhysicalModelCls::borderRadius() {
    return _borderRadius;
}

void RenderPhysicalModelCls::borderRadius(BorderRadius value) {
    if (borderRadius() == value) {
        return;
    }
    _borderRadius = value;
    _markNeedsClip();
}

bool RenderPhysicalModelCls::hitTest(BoxHitTestResult result, Offset position) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!->contains(position)) {
            return false;
        }
    }
    return super->hitTest(resultposition);
}

void RenderPhysicalModelCls::paint(PaintingContext context, Offset offset) {
    if (child == nullptr) {
        layer = nullptr;
        return;
    }
    _updateClip();
    RRect offsetRRect = _clip!->shift(offset);
    Rect offsetBounds = offsetRRect->outerRect();
    auto _c1 = make<PathCls>();_c1.addRRect(offsetRRect);Path offsetRRectAsPath = _c1;
    bool paintShadows = true;
    assert([=] () {
        if (debugDisableShadows) {
            if (elevation > 0.0) {
                            auto _c2 = make<PaintCls>();            _c2.color = auto _c3 = shadowColor;            _c3.style = auto _c4 = PaintingStyleCls::stroke;            _c4.strokeWidth = elevation * 2.0;            _c4;            _c3;context->canvas()->drawRRect(offsetRRect, _c2);
            }
            paintShadows = false;
        }
        return true;
    }());
    Canvas canvas = context->canvas();
    if (elevation != 0.0 && paintShadows) {
        canvas->drawRect(offsetBounds->inflate(20.0), _transparentPaint);
        canvas->drawShadow(offsetRRectAsPath, shadowColor, elevation, color->alpha != 0xFF);
    }
    bool usesSaveLayer = clipBehavior == ClipCls::antiAliasWithSaveLayer;
    if (!usesSaveLayer) {
            auto _c5 = make<PaintCls>();    _c5.color = color;canvas->drawRRect(offsetRRect, _c5);
    }
    layer = context->pushClipRRect(needsCompositing, offset, OffsetCls::zero & size, _clip!, [=] (PaintingContext context,Offset offset) {
        if (usesSaveLayer) {
                    auto _c6 = make<PaintCls>();        _c6.color = color;context->canvas->drawPaint(_c6);
        }
        super->paint(context, offset);
    }as<ClipRRectLayer>(layer), clipBehavior);
    assert([=] () {
        layer?->debugCreator = debugCreator;
        return true;
    }());
}

void RenderPhysicalModelCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<BoxShape>make<DiagnosticsPropertyCls>(__s("shape"), shape()));
    description->add(<BorderRadius>make<DiagnosticsPropertyCls>(__s("borderRadius"), borderRadius()));
}

RRect RenderPhysicalModelCls::_defaultClip() {
    assert(hasSize);
    assert(_shape != nullptr);
    ;
}

RenderPhysicalShapeCls::RenderPhysicalShapeCls(Unknown child, Unknown clipBehavior, CustomClipper<Path> clipper, Unknown color, Unknown elevation, Unknown shadowColor) {
    {
        assert(clipper != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
    }
}

bool RenderPhysicalShapeCls::hitTest(BoxHitTestResult result, Offset position) {
    if (_clipper != nullptr) {
        _updateClip();
        assert(_clip != nullptr);
        if (!_clip!->contains(position)) {
            return false;
        }
    }
    return super->hitTest(resultposition);
}

void RenderPhysicalShapeCls::paint(PaintingContext context, Offset offset) {
    if (child == nullptr) {
        layer = nullptr;
        return;
    }
    _updateClip();
    Rect offsetBounds = offset & size;
    Path offsetPath = _clip!->shift(offset);
    bool paintShadows = true;
    assert([=] () {
        if (debugDisableShadows) {
            if (elevation > 0.0) {
                            auto _c1 = make<PaintCls>();            _c1.color = auto _c2 = shadowColor;            _c2.style = auto _c3 = PaintingStyleCls::stroke;            _c3.strokeWidth = elevation * 2.0;            _c3;            _c2;context->canvas()->drawPath(offsetPath, _c1);
            }
            paintShadows = false;
        }
        return true;
    }());
    Canvas canvas = context->canvas();
    if (elevation != 0.0 && paintShadows) {
        canvas->drawRect(offsetBounds->inflate(20.0), _transparentPaint);
        canvas->drawShadow(offsetPath, shadowColor, elevation, color->alpha != 0xFF);
    }
    bool usesSaveLayer = clipBehavior == ClipCls::antiAliasWithSaveLayer;
    if (!usesSaveLayer) {
            auto _c4 = make<PaintCls>();    _c4.color = color;canvas->drawPath(offsetPath, _c4);
    }
    layer = context->pushClipPath(needsCompositing, offset, OffsetCls::zero & size, _clip!, [=] (PaintingContext context,Offset offset) {
        if (usesSaveLayer) {
                    auto _c5 = make<PaintCls>();        _c5.color = color;context->canvas->drawPaint(_c5);
        }
        super->paint(context, offset);
    }as<ClipPathLayer>(layer), clipBehavior);
    assert([=] () {
        layer?->debugCreator = debugCreator;
        return true;
    }());
}

void RenderPhysicalShapeCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<CustomClipper<Path>>make<DiagnosticsPropertyCls>(__s("clipper"), clipper));
}

Path RenderPhysicalShapeCls::_defaultClip() {
    return _c1;
}

RenderDecoratedBoxCls::RenderDecoratedBoxCls(RenderBox child, ImageConfiguration configuration, Decoration decoration, DecorationPosition position) : RenderProxyBox(child) {
    {
            auto _c1 = make<PathCls>();    _c1.addRect(OffsetCls::zero & size);assert(decoration != nullptr);
        assert(position != nullptr);
        assert(configuration != nullptr);
        _decoration = decoration;
        _position = position;
        _configuration = configuration;
    }
}

Decoration RenderDecoratedBoxCls::decoration() {
    return _decoration;
}

void RenderDecoratedBoxCls::decoration(Decoration value) {
    assert(value != nullptr);
    if (value == _decoration) {
        return;
    }
    _painter?->dispose();
    _painter = nullptr;
    _decoration = value;
    markNeedsPaint();
}

DecorationPosition RenderDecoratedBoxCls::position() {
    return _position;
}

void RenderDecoratedBoxCls::position(DecorationPosition value) {
    assert(value != nullptr);
    if (value == _position) {
        return;
    }
    _position = value;
    markNeedsPaint();
}

ImageConfiguration RenderDecoratedBoxCls::configuration() {
    return _configuration;
}

void RenderDecoratedBoxCls::configuration(ImageConfiguration value) {
    assert(value != nullptr);
    if (value == _configuration) {
        return;
    }
    _configuration = value;
    markNeedsPaint();
}

void RenderDecoratedBoxCls::detach() {
    _painter?->dispose();
    _painter = nullptr;
    super->detach();
    markNeedsPaint();
}

bool RenderDecoratedBoxCls::hitTestSelf(Offset position) {
    return _decoration->hitTest(size, positionconfiguration()->textDirection);
}

void RenderDecoratedBoxCls::paint(PaintingContext context, Offset offset) {
    assert(size->width != nullptr);
    assert(size->height != nullptr);
    _painter |= _decoration->createBoxPainter(markNeedsPaint);
    ImageConfiguration filledConfiguration = configuration()->copyWith(size);
    if (position() == DecorationPositionCls::background) {
        int debugSaveCount;
        assert([=] () {
            debugSaveCount = context->canvas()->getSaveCount();
            return true;
        }());
        _painter!->paint(context->canvas(), offset, filledConfiguration);
        assert([=] () {
            if (debugSaveCount != context->canvas()->getSaveCount()) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
            }
            return true;
        }());
        if (decoration()->isComplex()) {
            context->setIsComplexHint();
        }
    }
    super->paint(context, offset);
    if (position() == DecorationPositionCls::foreground) {
        _painter!->paint(context->canvas(), offset, filledConfiguration);
        if (decoration()->isComplex()) {
            context->setIsComplexHint();
        }
    }
}

void RenderDecoratedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(_decoration->toDiagnosticsNode(__s("decoration")));
    properties->add(<ImageConfiguration>make<DiagnosticsPropertyCls>(__s("configuration"), configuration()));
}

RenderTransformCls::RenderTransformCls(AlignmentGeometry alignment, RenderBox child, FilterQuality filterQuality, Offset origin, TextDirection textDirection, Matrix4 transform, bool transformHitTests) : RenderProxyBox(child) {
    {
        assert(transform != nullptr);
    }
    {
        this->transform = transform;
        this->alignment = alignment;
        this->textDirection = textDirection;
        this->filterQuality = filterQuality;
        this->origin = origin;
    }
}

Offset RenderTransformCls::origin() {
    return _origin;
}

void RenderTransformCls::origin(Offset value) {
    if (_origin == value) {
        return;
    }
    _origin = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

AlignmentGeometry RenderTransformCls::alignment() {
    return _alignment;
}

void RenderTransformCls::alignment(AlignmentGeometry value) {
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

TextDirection RenderTransformCls::textDirection() {
    return _textDirection;
}

void RenderTransformCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

bool RenderTransformCls::alwaysNeedsCompositing() {
    return child != nullptr && _filterQuality != nullptr;
}

void RenderTransformCls::transform(Matrix4 value) {
    assert(value != nullptr);
    if (_transform == value) {
        return;
    }
    _transform = Matrix4Cls->copy(value);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

FilterQuality RenderTransformCls::filterQuality() {
    return _filterQuality;
}

void RenderTransformCls::filterQuality(FilterQuality value) {
    if (_filterQuality == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing();
    _filterQuality = value;
    if (didNeedCompositing != alwaysNeedsCompositing()) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
}

void RenderTransformCls::setIdentity() {
    _transform!->setIdentity();
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransformCls::rotateX(double radians) {
    _transform!->rotateX(radians);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransformCls::rotateY(double radians) {
    _transform!->rotateY(radians);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransformCls::rotateZ(double radians) {
    _transform!->rotateZ(radians);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransformCls::translate(double x, double y, double z) {
    _transform!->translate(x, y, z);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

void RenderTransformCls::scale(double x, double y, double z) {
    _transform!->scale(x, y, z);
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

bool RenderTransformCls::hitTest(BoxHitTestResult result, Offset position) {
    return hitTestChildren(resultposition);
}

bool RenderTransformCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    assert(!transformHitTests || _effectiveTransform() != nullptr);
    return result->addWithPaintTransform(transformHitTests? _effectiveTransform() : nullptr, position, [=] (BoxHitTestResult result,Offset position) {
        return super->hitTestChildren(resultposition);
    });
}

void RenderTransformCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        Matrix4 transform = _effectiveTransform()!;
        if (filterQuality() == nullptr) {
            Offset childOffset = MatrixUtilsCls->getAsTranslation(transform);
            if (childOffset == nullptr) {
                double det = transform->determinant();
                if (det == 0 || !det->isFinite) {
                    layer = nullptr;
                    return;
                }
                layer = context->pushTransform(needsCompositing, offset, transform, super->paintis<TransformLayer>(layer)? as<TransformLayer>(layer) : nullptr);
            } else {
                super->paint(context, offset + childOffset);
                layer = nullptr;
            }
        } else {
                    auto _c1 = Matrix4Cls->translationValues(offset->dx(), offset->dy(), 0.0);        _c1.auto _c2 = multiply(transform);        _c2.translate(-offset->dx(), -offset->dy());        _c2;Matrix4 effectiveTransform = _c1;
            ImageFilter filter = ui->ImageFilterCls->matrix(effectiveTransform->storage()filterQuality()!);
            if (is<ImageFilterLayer>(layer)) {
                ImageFilterLayer filterLayer = as<ImageFilterLayer>(as<ImageFilterLayerCls>(layer)!);
                filterLayer->imageFilter() = filter;
            } else {
                layer = make<ImageFilterLayerCls>(filter);
            }
            context->pushLayer(layer!, super->paint, offset);
            assert([=] () {
                layer!->debugCreator = debugCreator;
                return true;
            }());
        }
    }
}

void RenderTransformCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    transform->multiply(_effectiveTransform()!);
}

void RenderTransformCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<TransformPropertyCls>(__s("transform matrix"), _transform));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("origin"), origin()));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment()));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection()nullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("transformHitTests"), transformHitTests));
}

Matrix4 RenderTransformCls::_effectiveTransform() {
    Alignment resolvedAlignment = alignment()?->resolve(textDirection());
    if (_origin == nullptr && resolvedAlignment == nullptr) {
        return _transform;
    }
    Matrix4 result = Matrix4Cls->identity();
    if (_origin != nullptr) {
        result->translate(_origin!->dx(), _origin!->dy());
    }
    Offset translation;
    if (resolvedAlignment != nullptr) {
        translation = resolvedAlignment->alongSize(size);
        result->translate(translation->dx(), translation->dy());
    }
    result->multiply(_transform!);
    if (resolvedAlignment != nullptr) {
        result->translate(-translation!->dx(), -translation->dy());
    }
    if (_origin != nullptr) {
        result->translate(-_origin!->dx(), -_origin!->dy());
    }
    return result;
}

RenderFittedBoxCls::RenderFittedBoxCls(AlignmentGeometry alignment, RenderBox child, Clip clipBehavior, BoxFit fit, TextDirection textDirection) : RenderProxyBox(child) {
    {
        assert(fit != nullptr);
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        _fit = fit;
        _alignment = alignment;
        _textDirection = textDirection;
        _clipBehavior = clipBehavior;
    }
}

BoxFit RenderFittedBoxCls::fit() {
    return _fit;
}

void RenderFittedBoxCls::fit(BoxFit value) {
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

AlignmentGeometry RenderFittedBoxCls::alignment() {
    return _alignment;
}

void RenderFittedBoxCls::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    _clearPaintData();
    _markNeedResolution();
}

TextDirection RenderFittedBoxCls::textDirection() {
    return _textDirection;
}

void RenderFittedBoxCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _clearPaintData();
    _markNeedResolution();
}

Size RenderFittedBoxCls::computeDryLayout(BoxConstraints constraints) {
    if (child != nullptr) {
        Size childSize = child!->getDryLayout(make<BoxConstraintsCls>());
        bool invalidChildSize = false;
        assert([=] () {
            if (RenderObjectCls::debugCheckingIntrinsics && childSize->width() * childSize->height() == 0.0) {
                invalidChildSize = true;
            }
            return true;
        }());
        if (invalidChildSize) {
            assert(debugCannotComputeDryLayout(__s("Child provided invalid size of $childSize.")));
            return SizeCls::zero;
        }
        ;
    } else {
        return constraints->smallest();
    }
}

void RenderFittedBoxCls::performLayout() {
    if (child != nullptr) {
        child!->layout(make<BoxConstraintsCls>()true);
        ;
        _clearPaintData();
    } else {
        size = constraints->smallest;
    }
}

Clip RenderFittedBoxCls::clipBehavior() {
    return _clipBehavior;
}

void RenderFittedBoxCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderFittedBoxCls::paint(PaintingContext context, Offset offset) {
    if (child == nullptr || size->isEmpty || child!->size->isEmpty) {
        return;
    }
    _updatePaintData();
    assert(child != nullptr);
    if (_hasVisualOverflow! && clipBehavior() != ClipCls::none) {
        layer = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, _paintChildWithTransformis<ClipRectLayer>(layer)? as<ClipRectLayer>(layer!) : nullptr, clipBehavior());
    } else {
        layer = _paintChildWithTransform(context, offset);
    }
}

bool RenderFittedBoxCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    if (size->isEmpty || (child?->size->isEmpty | false)) {
        return false;
    }
    _updatePaintData();
    return result->addWithPaintTransform(_transform, position, [=] (BoxHitTestResult result,Offset position) {
        return super->hitTestChildren(resultposition);
    });
}

bool RenderFittedBoxCls::paintsChild(RenderBox child) {
    assert(child->parent == this);
    return !size->isEmpty && !child->size()->isEmpty();
}

void RenderFittedBoxCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    if (!paintsChild(child)) {
        transform->setZero();
    } else {
        _updatePaintData();
        transform->multiply(_transform!);
    }
}

void RenderFittedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BoxFit>make<EnumPropertyCls>(__s("fit"), fit()));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment()));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection()nullptr));
}

void RenderFittedBoxCls::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment()->resolve(textDirection());
}

void RenderFittedBoxCls::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsPaint();
}

bool RenderFittedBoxCls::_fitAffectsLayout(BoxFit fit) {
    ;
}

void RenderFittedBoxCls::_clearPaintData() {
    _hasVisualOverflow = nullptr;
    _transform = nullptr;
}

void RenderFittedBoxCls::_updatePaintData() {
    if (_transform != nullptr) {
        return;
    }
    if (child == nullptr) {
        _hasVisualOverflow = false;
        _transform = Matrix4Cls->identity();
    } else {
        _resolve();
        Size childSize = child!->size;
        FittedSizes sizes = applyBoxFit(_fit, childSize, size);
        double scaleX = sizes->destination->width() / sizes->source->width();
        double scaleY = sizes->destination->height() / sizes->source->height();
        Rect sourceRect = _resolvedAlignment!->inscribe(sizes->source, OffsetCls::zero & childSize);
        Rect destinationRect = _resolvedAlignment!->inscribe(sizes->destination, OffsetCls::zero & size);
        _hasVisualOverflow = sourceRect->width() < childSize->width() || sourceRect->height() < childSize->height();
        assert(scaleX->isFinite && scaleY->isFinite);
            auto _c1 = Matrix4Cls->translationValues(destinationRect->left, destinationRect->top, 0.0);    _c1.auto _c2 = scale(scaleX, scaleY, 1.0);    _c2.translate(-sourceRect->left, -sourceRect->top);    _c2;_transform = _c1;
        assert(_transform!->storage()->every([=] (double value)         {
            value->isFinite;
        }));
    }
}

TransformLayer RenderFittedBoxCls::_paintChildWithTransform(PaintingContext context, Offset offset) {
    Offset childOffset = MatrixUtilsCls->getAsTranslation(_transform!);
    if (childOffset == nullptr) {
        return context->pushTransform(needsCompositing, offset, _transform!, super->paintis<TransformLayer>(layer)? as<TransformLayer>(layer!) : nullptr);
    } else {
        super->paint(context, offset + childOffset);
    }
    return nullptr;
}

RenderFractionalTranslationCls::RenderFractionalTranslationCls(RenderBox child, bool transformHitTests, Offset translation) : RenderProxyBox(child) {
    {
        assert(translation != nullptr);
        _translation = translation;
    }
}

Offset RenderFractionalTranslationCls::translation() {
    return _translation;
}

void RenderFractionalTranslationCls::translation(Offset value) {
    assert(value != nullptr);
    if (_translation == value) {
        return;
    }
    _translation = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

bool RenderFractionalTranslationCls::hitTest(BoxHitTestResult result, Offset position) {
    return hitTestChildren(resultposition);
}

bool RenderFractionalTranslationCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    assert(!debugNeedsLayout);
    return result->addWithPaintOffset(transformHitTests? make<OffsetCls>(translation()->dx() * size->width, translation()->dy() * size->height) : nullptr, position, [=] (BoxHitTestResult result,Offset position) {
        return super->hitTestChildren(resultposition);
    });
}

void RenderFractionalTranslationCls::paint(PaintingContext context, Offset offset) {
    assert(!debugNeedsLayout);
    if (child != nullptr) {
        super->paint(context, make<OffsetCls>(offset->dx() + translation()->dx() * size->width, offset->dy() + translation()->dy() * size->height));
    }
}

void RenderFractionalTranslationCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    transform->translate(translation()->dx() * size->width, translation()->dy() * size->height);
}

void RenderFractionalTranslationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("translation"), translation()));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("transformHitTests"), transformHitTests));
}

Size RenderPointerListenerCls::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints->biggest();
}

void RenderPointerListenerCls::handleEvent(PointerEvent event, HitTestEntry entry) {
    assert(debugHandleEvent(event, entry));
    if (is<PointerDownEvent>(event)) {
        return onPointerDown?->call(as<PointerDownEventCls>(event));
    }
    if (is<PointerMoveEvent>(event)) {
        return onPointerMove?->call(as<PointerMoveEventCls>(event));
    }
    if (is<PointerUpEvent>(event)) {
        return onPointerUp?->call(as<PointerUpEventCls>(event));
    }
    if (is<PointerHoverEvent>(event)) {
        return onPointerHover?->call(as<PointerHoverEventCls>(event));
    }
    if (is<PointerCancelEvent>(event)) {
        return onPointerCancel?->call(as<PointerCancelEventCls>(event));
    }
    if (is<PointerPanZoomStartEvent>(event)) {
        return onPointerPanZoomStart?->call(as<PointerPanZoomStartEventCls>(event));
    }
    if (is<PointerPanZoomUpdateEvent>(event)) {
        return onPointerPanZoomUpdate?->call(as<PointerPanZoomUpdateEventCls>(event));
    }
    if (is<PointerPanZoomEndEvent>(event)) {
        return onPointerPanZoomEnd?->call(as<PointerPanZoomEndEventCls>(event));
    }
    if (is<PointerSignalEvent>(event)) {
        return onPointerSignal?->call(as<PointerSignalEventCls>(event));
    }
}

void RenderPointerListenerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    Map<String, std::function<void ()>> map1 = make<MapCls<>>();map1.set(__s("down"), onPointerDown);map1.set(__s("move"), onPointerMove);map1.set(__s("up"), onPointerUp);map1.set(__s("hover"), onPointerHover);map1.set(__s("cancel"), onPointerCancel);map1.set(__s("panZoomStart"), onPointerPanZoomStart);map1.set(__s("panZoomUpdate"), onPointerPanZoomUpdate);map1.set(__s("panZoomEnd"), onPointerPanZoomEnd);map1.set(__s("signal"), onPointerSignal);properties->add(<std::function<void ()>>make<FlagsSummaryCls>(__s("listeners"), list1__s("<none>")));
}

RenderMouseRegionCls::RenderMouseRegionCls(Unknown child, MouseCursor cursor, HitTestBehavior hitTestBehavior, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque, bool validForMouseTracker) : RenderProxyBoxWithHitTestBehavior(hitTestBehavior | HitTestBehaviorCls::opaque) {
    {
        assert(opaque != nullptr);
        assert(cursor != nullptr);
        _cursor = cursor;
        _validForMouseTracker = validForMouseTracker;
        _opaque = opaque;
    }
}

bool RenderMouseRegionCls::hitTest(BoxHitTestResult result, Offset position) {
    return super->hitTest(resultposition) && _opaque;
}

void RenderMouseRegionCls::handleEvent(PointerEvent event, HitTestEntry entry) {
    assert(debugHandleEvent(event, entry));
    if (onHover != nullptr && is<PointerHoverEvent>(event)) {
        return onHover!(event);
    }
}

bool RenderMouseRegionCls::opaque() {
    return _opaque;
}

void RenderMouseRegionCls::opaque(bool value) {
    if (_opaque != value) {
        _opaque = value;
        markNeedsPaint();
    }
}

HitTestBehavior RenderMouseRegionCls::hitTestBehavior() {
    return behavior;
}

void RenderMouseRegionCls::hitTestBehavior(HitTestBehavior value) {
    HitTestBehavior newValue = value | HitTestBehaviorCls::opaque;
    if (behavior != newValue) {
        behavior = newValue;
        markNeedsPaint();
    }
}

MouseCursor RenderMouseRegionCls::cursor() {
    return _cursor;
}

void RenderMouseRegionCls::cursor(MouseCursor value) {
    if (_cursor != value) {
        _cursor = value;
        markNeedsPaint();
    }
}

bool RenderMouseRegionCls::validForMouseTracker() {
    return _validForMouseTracker;
}

void RenderMouseRegionCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _validForMouseTracker = true;
}

void RenderMouseRegionCls::detach() {
    _validForMouseTracker = false;
    super->detach();
}

Size RenderMouseRegionCls::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints->biggest();
}

void RenderMouseRegionCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    Map<String, std::function<void ()>> map1 = make<MapCls<>>();map1.set(__s("enter"), onEnter);map1.set(__s("hover"), onHover);map1.set(__s("exit"), onExit);properties->add(<std::function<void ()>>make<FlagsSummaryCls>(__s("listeners"), list1__s("<none>")));
    properties->add(<MouseCursor>make<DiagnosticsPropertyCls>(__s("cursor"), cursor()MouseCursorCls::defer));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("opaque"), opaque()true));
    properties->add(make<FlagPropertyCls>(__s("validForMouseTracker")validForMouseTracker(), true, __s("invalid for MouseTracker")));
}

RenderRepaintBoundaryCls::RenderRepaintBoundaryCls(RenderBox child) : RenderProxyBox(child) {
}

bool RenderRepaintBoundaryCls::isRepaintBoundary() {
    return true;
}

Future<Image> RenderRepaintBoundaryCls::toImage(double pixelRatio) {
    assert(!debugNeedsPaint);
    OffsetLayer offsetLayer = as<OffsetLayer>(layer!);
    return offsetLayer->toImage(OffsetCls::zero & sizepixelRatio);
}

int RenderRepaintBoundaryCls::debugSymmetricPaintCount() {
    return _debugSymmetricPaintCount;
}

int RenderRepaintBoundaryCls::debugAsymmetricPaintCount() {
    return _debugAsymmetricPaintCount;
}

void RenderRepaintBoundaryCls::debugResetMetrics() {
    assert([=] () {
        _debugSymmetricPaintCount = 0;
        _debugAsymmetricPaintCount = 0;
        return true;
    }());
}

void RenderRepaintBoundaryCls::debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent) {
    assert([=] () {
        if (includedParent && includedChild) {
            _debugSymmetricPaintCount += 1;
        } else {
            _debugAsymmetricPaintCount += 1;
        }
        return true;
    }());
}

void RenderRepaintBoundaryCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    bool inReleaseMode = true;
    assert([=] () {
        inReleaseMode = false;
        if (debugSymmetricPaintCount() + debugAsymmetricPaintCount() == 0) {
            properties->add(make<MessagePropertyCls>(__s("usefulness ratio"), __s("no metrics collected yet (never painted)")));
        } else {
            double fraction = debugAsymmetricPaintCount() / (debugSymmetricPaintCount() + debugAsymmetricPaintCount());
            String diagnosis;
            if (debugSymmetricPaintCount() +  < 5) {
                diagnosis = __s("insufficient data to draw conclusion (less than five repaints)");
            } else             {
                if (fraction > 0.9) {
                diagnosis = __s("this is an outstandingly useful repaint boundary and should definitely be kept");
            } else             {
                if (fraction > 0.5) {
                diagnosis = __s("this is a useful repaint boundary and should be kept");
            } else             {
                if (fraction > 0.30) {
                diagnosis = __s("this repaint boundary is probably useful, but maybe it would be more useful in tandem with adding more repaint boundaries elsewhere");
            } else             {
                if (fraction > 0.1) {
                diagnosis = __s("this repaint boundary does sometimes show value, though currently not that often");
            } else             {
                if (debugAsymmetricPaintCount() == 0) {
                diagnosis = __s("this repaint boundary is astoundingly ineffectual and should be removed");
            } else {
                diagnosis = __s("this repaint boundary is not very effective and should probably be removed");
            }
;
            };
            };
            };
            };
            }            properties->add(make<PercentPropertyCls>(__s("metrics"), fraction__s("useful"), __s("$debugSymmetricPaintCount bad vs $debugAsymmetricPaintCount good")));
            properties->add(make<MessagePropertyCls>(__s("diagnosis"), diagnosis));
        }
        return true;
    }());
    if (inReleaseMode) {
        properties->add(DiagnosticsNodeCls->message(__s("(run in debug mode to collect repaint boundary statistics)")));
    }
}

RenderIgnorePointerCls::RenderIgnorePointerCls(RenderBox child, bool ignoring, bool ignoringSemantics) : RenderProxyBox(child) {
    {
        _ignoring = ignoring;
        _ignoringSemantics = ignoringSemantics;
    }
    {
        assert(_ignoring != nullptr);
    }
}

bool RenderIgnorePointerCls::ignoring() {
    return _ignoring;
}

void RenderIgnorePointerCls::ignoring(bool value) {
    assert(value != nullptr);
    if (value == _ignoring) {
        return;
    }
    _ignoring = value;
    if (_ignoringSemantics == nullptr || !_ignoringSemantics!) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderIgnorePointerCls::ignoringSemantics() {
    return _ignoringSemantics;
}

void RenderIgnorePointerCls::ignoringSemantics(bool value) {
    if (value == _ignoringSemantics) {
        return;
    }
    bool oldEffectiveValue = _effectiveIgnoringSemantics();
    _ignoringSemantics = value;
    if (oldEffectiveValue != _effectiveIgnoringSemantics()) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderIgnorePointerCls::hitTest(BoxHitTestResult result, Offset position) {
    return !ignoring() && super->hitTest(resultposition);
}

void RenderIgnorePointerCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && !_effectiveIgnoringSemantics()) {
        visitor(child!);
    }
}

void RenderIgnorePointerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoring"), ignoring()));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoringSemantics"), _effectiveIgnoringSemantics()ignoringSemantics() == nullptr? __s("implicitly $_effectiveIgnoringSemantics") : nullptr));
}

bool RenderIgnorePointerCls::_effectiveIgnoringSemantics() {
    return ignoringSemantics() | ignoring();
}

RenderOffstageCls::RenderOffstageCls(RenderBox child, bool offstage) : RenderProxyBox(child) {
    {
        assert(offstage != nullptr);
        _offstage = offstage;
    }
}

bool RenderOffstageCls::offstage() {
    return _offstage;
}

void RenderOffstageCls::offstage(bool value) {
    assert(value != nullptr);
    if (value == _offstage) {
        return;
    }
    _offstage = value;
    markNeedsLayoutForSizedByParentChange();
}

double RenderOffstageCls::computeMinIntrinsicWidth(double height) {
    if (offstage()) {
        return 0.0;
    }
    return super->computeMinIntrinsicWidth(height);
}

double RenderOffstageCls::computeMaxIntrinsicWidth(double height) {
    if (offstage()) {
        return 0.0;
    }
    return super->computeMaxIntrinsicWidth(height);
}

double RenderOffstageCls::computeMinIntrinsicHeight(double width) {
    if (offstage()) {
        return 0.0;
    }
    return super->computeMinIntrinsicHeight(width);
}

double RenderOffstageCls::computeMaxIntrinsicHeight(double width) {
    if (offstage()) {
        return 0.0;
    }
    return super->computeMaxIntrinsicHeight(width);
}

double RenderOffstageCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (offstage()) {
        return nullptr;
    }
    return super->computeDistanceToActualBaseline(baseline);
}

bool RenderOffstageCls::sizedByParent() {
    return offstage();
}

Size RenderOffstageCls::computeDryLayout(BoxConstraints constraints) {
    if (offstage()) {
        return constraints->smallest();
    }
    return super->computeDryLayout(constraints);
}

void RenderOffstageCls::performResize() {
    assert(offstage());
    super->performResize();
}

void RenderOffstageCls::performLayout() {
    if (offstage()) {
        child?->layout(constraints);
    } else {
        super->performLayout();
    }
}

bool RenderOffstageCls::hitTest(BoxHitTestResult result, Offset position) {
    return !offstage() && super->hitTest(resultposition);
}

bool RenderOffstageCls::paintsChild(RenderBox child) {
    assert(child->parent == this);
    return !offstage();
}

void RenderOffstageCls::paint(PaintingContext context, Offset offset) {
    if (offstage()) {
        return;
    }
    super->paint(context, offset);
}

void RenderOffstageCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (offstage()) {
        return;
    }
    super->visitChildrenForSemantics(visitor);
}

void RenderOffstageCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("offstage"), offstage()));
}

List<DiagnosticsNode> RenderOffstageCls::debugDescribeChildren() {
    if (child == nullptr) {
        return makeList();
    }
    return makeList(ArrayItem);
}

RenderAbsorbPointerCls::RenderAbsorbPointerCls(bool absorbing, RenderBox child, bool ignoringSemantics) : RenderProxyBox(child) {
    {
        assert(absorbing != nullptr);
        _absorbing = absorbing;
        _ignoringSemantics = ignoringSemantics;
    }
}

bool RenderAbsorbPointerCls::absorbing() {
    return _absorbing;
}

void RenderAbsorbPointerCls::absorbing(bool value) {
    if (_absorbing == value) {
        return;
    }
    _absorbing = value;
    if (ignoringSemantics() == nullptr) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderAbsorbPointerCls::ignoringSemantics() {
    return _ignoringSemantics;
}

void RenderAbsorbPointerCls::ignoringSemantics(bool value) {
    if (value == _ignoringSemantics) {
        return;
    }
    bool oldEffectiveValue = _effectiveIgnoringSemantics();
    _ignoringSemantics = value;
    if (oldEffectiveValue != _effectiveIgnoringSemantics()) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderAbsorbPointerCls::hitTest(BoxHitTestResult result, Offset position) {
    return absorbing()? size->contains(position) : super->hitTest(resultposition);
}

void RenderAbsorbPointerCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && !_effectiveIgnoringSemantics()) {
        visitor(child!);
    }
}

void RenderAbsorbPointerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("absorbing"), absorbing()));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoringSemantics"), _effectiveIgnoringSemantics()ignoringSemantics() == nullptr? __s("implicitly $_effectiveIgnoringSemantics") : nullptr));
}

bool RenderAbsorbPointerCls::_effectiveIgnoringSemantics() {
    return ignoringSemantics() | absorbing();
}

void RenderMetaDataCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<dynamic>make<DiagnosticsPropertyCls>(__s("metaData"), metaData));
}

RenderSemanticsGestureHandlerCls::RenderSemanticsGestureHandlerCls(Unknown behavior, Unknown child, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureTapCallback onTap, GestureDragUpdateCallback onVerticalDragUpdate, double scrollFactor) {
    {
        assert(scrollFactor != nullptr);
        _onTap = onTap;
        _onLongPress = onLongPress;
        _onHorizontalDragUpdate = onHorizontalDragUpdate;
        _onVerticalDragUpdate = onVerticalDragUpdate;
    }
}

Set<SemanticsAction> RenderSemanticsGestureHandlerCls::validActions() {
    return _validActions;
}

void RenderSemanticsGestureHandlerCls::validActions(Set<SemanticsAction> value) {
    if (<SemanticsAction>setEquals(value, _validActions)) {
        return;
    }
    _validActions = value;
    markNeedsSemanticsUpdate();
}

GestureTapCallback RenderSemanticsGestureHandlerCls::onTap() {
    return _onTap;
}

void RenderSemanticsGestureHandlerCls::onTap(GestureTapCallback value) {
    if (_onTap == value) {
        return;
    }
    bool hadHandler = _onTap != nullptr;
    _onTap = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

GestureLongPressCallback RenderSemanticsGestureHandlerCls::onLongPress() {
    return _onLongPress;
}

void RenderSemanticsGestureHandlerCls::onLongPress(GestureLongPressCallback value) {
    if (_onLongPress == value) {
        return;
    }
    bool hadHandler = _onLongPress != nullptr;
    _onLongPress = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

GestureDragUpdateCallback RenderSemanticsGestureHandlerCls::onHorizontalDragUpdate() {
    return _onHorizontalDragUpdate;
}

void RenderSemanticsGestureHandlerCls::onHorizontalDragUpdate(GestureDragUpdateCallback value) {
    if (_onHorizontalDragUpdate == value) {
        return;
    }
    bool hadHandler = _onHorizontalDragUpdate != nullptr;
    _onHorizontalDragUpdate = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

GestureDragUpdateCallback RenderSemanticsGestureHandlerCls::onVerticalDragUpdate() {
    return _onVerticalDragUpdate;
}

void RenderSemanticsGestureHandlerCls::onVerticalDragUpdate(GestureDragUpdateCallback value) {
    if (_onVerticalDragUpdate == value) {
        return;
    }
    bool hadHandler = _onVerticalDragUpdate != nullptr;
    _onVerticalDragUpdate = value;
    if ((value != nullptr) != hadHandler) {
        markNeedsSemanticsUpdate();
    }
}

void RenderSemanticsGestureHandlerCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    if (onTap() != nullptr && _isValidAction(SemanticsActionCls::tap)) {
        config->onTap() = onTap();
    }
    if (onLongPress() != nullptr && _isValidAction(SemanticsActionCls::longPress)) {
        config->onLongPress() = onLongPress();
    }
    if (onHorizontalDragUpdate() != nullptr) {
        if (_isValidAction(SemanticsActionCls::scrollRight)) {
            config->onScrollRight() = _performSemanticScrollRight;
        }
        if (_isValidAction(SemanticsActionCls::scrollLeft)) {
            config->onScrollLeft() = _performSemanticScrollLeft;
        }
    }
    if (onVerticalDragUpdate() != nullptr) {
        if (_isValidAction(SemanticsActionCls::scrollUp)) {
            config->onScrollUp() = _performSemanticScrollUp;
        }
        if (_isValidAction(SemanticsActionCls::scrollDown)) {
            config->onScrollDown() = _performSemanticScrollDown;
        }
    }
}

void RenderSemanticsGestureHandlerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    List<String> list1 = make<ListCls<>>();if (onTap() != nullptr) {    list1.add(ArrayItem);}if (onLongPress() != nullptr) {    list1.add(ArrayItem);}if (onHorizontalDragUpdate() != nullptr) {    list1.add(ArrayItem);}if (onVerticalDragUpdate() != nullptr) {    list1.add(ArrayItem);}List<String> gestures = list1;
    if (gestures->isEmpty) {
        gestures->add(__s("<none>"));
    }
    properties->add(<String>make<IterablePropertyCls>(__s("gestures"), gestures));
}

bool RenderSemanticsGestureHandlerCls::_isValidAction(SemanticsAction action) {
    return validActions() == nullptr || validActions()!->contains(action);
}

void RenderSemanticsGestureHandlerCls::_performSemanticScrollLeft() {
    if (onHorizontalDragUpdate() != nullptr) {
        double primaryDelta = size->width * -scrollFactor;
        onHorizontalDragUpdate()!(make<DragUpdateDetailsCls>(make<OffsetCls>(primaryDelta, 0.0), primaryDelta, localToGlobal(size->center(OffsetCls::zero))));
    }
}

void RenderSemanticsGestureHandlerCls::_performSemanticScrollRight() {
    if (onHorizontalDragUpdate() != nullptr) {
        double primaryDelta = size->width * scrollFactor;
        onHorizontalDragUpdate()!(make<DragUpdateDetailsCls>(make<OffsetCls>(primaryDelta, 0.0), primaryDelta, localToGlobal(size->center(OffsetCls::zero))));
    }
}

void RenderSemanticsGestureHandlerCls::_performSemanticScrollUp() {
    if (onVerticalDragUpdate() != nullptr) {
        double primaryDelta = size->height * -scrollFactor;
        onVerticalDragUpdate()!(make<DragUpdateDetailsCls>(make<OffsetCls>(0.0, primaryDelta), primaryDelta, localToGlobal(size->center(OffsetCls::zero))));
    }
}

void RenderSemanticsGestureHandlerCls::_performSemanticScrollDown() {
    if (onVerticalDragUpdate() != nullptr) {
        double primaryDelta = size->height * scrollFactor;
        onVerticalDragUpdate()!(make<DragUpdateDetailsCls>(make<OffsetCls>(0.0, primaryDelta), primaryDelta, localToGlobal(size->center(OffsetCls::zero))));
    }
}

RenderSemanticsAnnotationsCls::RenderSemanticsAnnotationsCls(RenderBox child, bool container, bool excludeSemantics, bool explicitChildNodes, SemanticsProperties properties, TextDirection textDirection) : RenderProxyBox(child) {
    {
        assert(container != nullptr);
        _container = container;
        _explicitChildNodes = explicitChildNodes;
        _excludeSemantics = excludeSemantics;
        _textDirection = textDirection;
        _properties = properties;
    }
    {
        _updateAttributedFields(_properties);
    }
}

SemanticsProperties RenderSemanticsAnnotationsCls::properties() {
    return _properties;
}

void RenderSemanticsAnnotationsCls::properties(SemanticsProperties value) {
    assert(value != nullptr);
    if (_properties == value) {
        return;
    }
    _properties = value;
    _updateAttributedFields(_properties);
    markNeedsSemanticsUpdate();
}

bool RenderSemanticsAnnotationsCls::container() {
    return _container;
}

void RenderSemanticsAnnotationsCls::container(bool value) {
    assert(value != nullptr);
    if (container() == value) {
        return;
    }
    _container = value;
    markNeedsSemanticsUpdate();
}

bool RenderSemanticsAnnotationsCls::explicitChildNodes() {
    return _explicitChildNodes;
}

void RenderSemanticsAnnotationsCls::explicitChildNodes(bool value) {
    assert(value != nullptr);
    if (_explicitChildNodes == value) {
        return;
    }
    _explicitChildNodes = value;
    markNeedsSemanticsUpdate();
}

bool RenderSemanticsAnnotationsCls::excludeSemantics() {
    return _excludeSemantics;
}

void RenderSemanticsAnnotationsCls::excludeSemantics(bool value) {
    assert(value != nullptr);
    if (_excludeSemantics == value) {
        return;
    }
    _excludeSemantics = value;
    markNeedsSemanticsUpdate();
}

TextDirection RenderSemanticsAnnotationsCls::textDirection() {
    return _textDirection;
}

void RenderSemanticsAnnotationsCls::textDirection(TextDirection value) {
    if (textDirection() == value) {
        return;
    }
    _textDirection = value;
    markNeedsSemanticsUpdate();
}

void RenderSemanticsAnnotationsCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (excludeSemantics()) {
        return;
    }
    super->visitChildrenForSemantics(visitor);
}

void RenderSemanticsAnnotationsCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->isSemanticBoundary() = container();
    config->explicitChildNodes = explicitChildNodes();
    assert(((_properties->scopesRoute | false) && explicitChildNodes()) || !(_properties->scopesRoute | false), __s("explicitChildNodes must be set to true if scopes route is true"));
    assert(!((_properties->toggled | false) && (_properties->checked | false)), __s("A semantics node cannot be toggled and checked at the same time"));
    if (_properties->enabled != nullptr) {
        config->isEnabled() = _properties->enabled;
    }
    if (_properties->checked != nullptr) {
        config->isChecked() = _properties->checked;
    }
    if (_properties->toggled != nullptr) {
        config->isToggled() = _properties->toggled;
    }
    if (_properties->selected != nullptr) {
        config->isSelected() = _properties->selected!;
    }
    if (_properties->button != nullptr) {
        config->isButton() = _properties->button!;
    }
    if (_properties->link != nullptr) {
        config->isLink() = _properties->link!;
    }
    if (_properties->slider != nullptr) {
        config->isSlider() = _properties->slider!;
    }
    if (_properties->keyboardKey != nullptr) {
        config->isKeyboardKey() = _properties->keyboardKey!;
    }
    if (_properties->header != nullptr) {
        config->isHeader() = _properties->header!;
    }
    if (_properties->textField != nullptr) {
        config->isTextField() = _properties->textField!;
    }
    if (_properties->readOnly != nullptr) {
        config->isReadOnly() = _properties->readOnly!;
    }
    if (_properties->focusable != nullptr) {
        config->isFocusable() = _properties->focusable!;
    }
    if (_properties->focused != nullptr) {
        config->isFocused() = _properties->focused!;
    }
    if (_properties->inMutuallyExclusiveGroup != nullptr) {
        config->isInMutuallyExclusiveGroup() = _properties->inMutuallyExclusiveGroup!;
    }
    if (_properties->obscured != nullptr) {
        config->isObscured() = _properties->obscured!;
    }
    if (_properties->multiline != nullptr) {
        config->isMultiline() = _properties->multiline!;
    }
    if (_properties->hidden != nullptr) {
        config->isHidden() = _properties->hidden!;
    }
    if (_properties->image != nullptr) {
        config->isImage() = _properties->image!;
    }
    if (_attributedLabel != nullptr) {
        config->attributedLabel() = _attributedLabel!;
    }
    if (_attributedValue != nullptr) {
        config->attributedValue() = _attributedValue!;
    }
    if (_attributedIncreasedValue != nullptr) {
        config->attributedIncreasedValue() = _attributedIncreasedValue!;
    }
    if (_attributedDecreasedValue != nullptr) {
        config->attributedDecreasedValue() = _attributedDecreasedValue!;
    }
    if (_attributedHint != nullptr) {
        config->attributedHint() = _attributedHint!;
    }
    if (_properties->tooltip != nullptr) {
        config->tooltip() = _properties->tooltip!;
    }
    if (_properties->hintOverrides != nullptr && _properties->hintOverrides!->isNotEmpty()) {
        config->hintOverrides() = _properties->hintOverrides;
    }
    if (_properties->scopesRoute != nullptr) {
        config->scopesRoute() = _properties->scopesRoute!;
    }
    if (_properties->namesRoute != nullptr) {
        config->namesRoute() = _properties->namesRoute!;
    }
    if (_properties->liveRegion != nullptr) {
        config->liveRegion() = _properties->liveRegion!;
    }
    if (_properties->maxValueLength != nullptr) {
        config->maxValueLength() = _properties->maxValueLength;
    }
    if (_properties->currentValueLength != nullptr) {
        config->currentValueLength() = _properties->currentValueLength;
    }
    if (textDirection() != nullptr) {
        config->textDirection() = textDirection();
    }
    if (_properties->sortKey != nullptr) {
        config->sortKey() = _properties->sortKey;
    }
    if (_properties->tagForChildren != nullptr) {
        config->addTagForChildren(_properties->tagForChildren!);
    }
    if (_properties->onTap != nullptr) {
        config->onTap() = _performTap;
    }
    if (_properties->onLongPress != nullptr) {
        config->onLongPress() = _performLongPress;
    }
    if (_properties->onDismiss != nullptr) {
        config->onDismiss() = _performDismiss;
    }
    if (_properties->onScrollLeft != nullptr) {
        config->onScrollLeft() = _performScrollLeft;
    }
    if (_properties->onScrollRight != nullptr) {
        config->onScrollRight() = _performScrollRight;
    }
    if (_properties->onScrollUp != nullptr) {
        config->onScrollUp() = _performScrollUp;
    }
    if (_properties->onScrollDown != nullptr) {
        config->onScrollDown() = _performScrollDown;
    }
    if (_properties->onIncrease != nullptr) {
        config->onIncrease() = _performIncrease;
    }
    if (_properties->onDecrease != nullptr) {
        config->onDecrease() = _performDecrease;
    }
    if (_properties->onCopy != nullptr) {
        config->onCopy() = _performCopy;
    }
    if (_properties->onCut != nullptr) {
        config->onCut() = _performCut;
    }
    if (_properties->onPaste != nullptr) {
        config->onPaste() = _performPaste;
    }
    if (_properties->onMoveCursorForwardByCharacter != nullptr) {
        config->onMoveCursorForwardByCharacter() = _performMoveCursorForwardByCharacter;
    }
    if (_properties->onMoveCursorBackwardByCharacter != nullptr) {
        config->onMoveCursorBackwardByCharacter() = _performMoveCursorBackwardByCharacter;
    }
    if (_properties->onMoveCursorForwardByWord != nullptr) {
        config->onMoveCursorForwardByWord() = _performMoveCursorForwardByWord;
    }
    if (_properties->onMoveCursorBackwardByWord != nullptr) {
        config->onMoveCursorBackwardByWord() = _performMoveCursorBackwardByWord;
    }
    if (_properties->onSetSelection != nullptr) {
        config->onSetSelection() = _performSetSelection;
    }
    if (_properties->onSetText != nullptr) {
        config->onSetText() = _performSetText;
    }
    if (_properties->onDidGainAccessibilityFocus != nullptr) {
        config->onDidGainAccessibilityFocus() = _performDidGainAccessibilityFocus;
    }
    if (_properties->onDidLoseAccessibilityFocus != nullptr) {
        config->onDidLoseAccessibilityFocus() = _performDidLoseAccessibilityFocus;
    }
    if (_properties->customSemanticsActions != nullptr) {
        config->customSemanticsActions() = _properties->customSemanticsActions!;
    }
}

void RenderSemanticsAnnotationsCls::_updateAttributedFields(SemanticsProperties value) {
    _attributedLabel = _effectiveAttributedLabel(value);
    _attributedValue = _effectiveAttributedValue(value);
    _attributedIncreasedValue = _effectiveAttributedIncreasedValue(value);
    _attributedDecreasedValue = _effectiveAttributedDecreasedValue(value);
    _attributedHint = _effectiveAttributedHint(value);
}

AttributedString RenderSemanticsAnnotationsCls::_effectiveAttributedLabel(SemanticsProperties value) {
    return value->attributedLabel | (value->label == nullptr? nullptr : make<AttributedStringCls>(value->label!));
}

AttributedString RenderSemanticsAnnotationsCls::_effectiveAttributedValue(SemanticsProperties value) {
    return value->attributedValue | (value->value == nullptr? nullptr : make<AttributedStringCls>(value->value!));
}

AttributedString RenderSemanticsAnnotationsCls::_effectiveAttributedIncreasedValue(SemanticsProperties value) {
    return value->attributedIncreasedValue | (value->increasedValue == nullptr? nullptr : make<AttributedStringCls>(value->increasedValue!));
}

AttributedString RenderSemanticsAnnotationsCls::_effectiveAttributedDecreasedValue(SemanticsProperties value) {
    return properties()->attributedDecreasedValue | (value->decreasedValue == nullptr? nullptr : make<AttributedStringCls>(value->decreasedValue!));
}

AttributedString RenderSemanticsAnnotationsCls::_effectiveAttributedHint(SemanticsProperties value) {
    return value->attributedHint | (value->hint == nullptr? nullptr : make<AttributedStringCls>(value->hint!));
}

void RenderSemanticsAnnotationsCls::_performTap() {
    _properties->onTap?->call();
}

void RenderSemanticsAnnotationsCls::_performLongPress() {
    _properties->onLongPress?->call();
}

void RenderSemanticsAnnotationsCls::_performDismiss() {
    _properties->onDismiss?->call();
}

void RenderSemanticsAnnotationsCls::_performScrollLeft() {
    _properties->onScrollLeft?->call();
}

void RenderSemanticsAnnotationsCls::_performScrollRight() {
    _properties->onScrollRight?->call();
}

void RenderSemanticsAnnotationsCls::_performScrollUp() {
    _properties->onScrollUp?->call();
}

void RenderSemanticsAnnotationsCls::_performScrollDown() {
    _properties->onScrollDown?->call();
}

void RenderSemanticsAnnotationsCls::_performIncrease() {
    _properties->onIncrease?->call();
}

void RenderSemanticsAnnotationsCls::_performDecrease() {
    _properties->onDecrease?->call();
}

void RenderSemanticsAnnotationsCls::_performCopy() {
    _properties->onCopy?->call();
}

void RenderSemanticsAnnotationsCls::_performCut() {
    _properties->onCut?->call();
}

void RenderSemanticsAnnotationsCls::_performPaste() {
    _properties->onPaste?->call();
}

void RenderSemanticsAnnotationsCls::_performMoveCursorForwardByCharacter(bool extendSelection) {
    _properties->onMoveCursorForwardByCharacter?->call(extendSelection);
}

void RenderSemanticsAnnotationsCls::_performMoveCursorBackwardByCharacter(bool extendSelection) {
    _properties->onMoveCursorBackwardByCharacter?->call(extendSelection);
}

void RenderSemanticsAnnotationsCls::_performMoveCursorForwardByWord(bool extendSelection) {
    _properties->onMoveCursorForwardByWord?->call(extendSelection);
}

void RenderSemanticsAnnotationsCls::_performMoveCursorBackwardByWord(bool extendSelection) {
    _properties->onMoveCursorBackwardByWord?->call(extendSelection);
}

void RenderSemanticsAnnotationsCls::_performSetSelection(TextSelection selection) {
    _properties->onSetSelection?->call(selection);
}

void RenderSemanticsAnnotationsCls::_performSetText(String text) {
    _properties->onSetText?->call(text);
}

void RenderSemanticsAnnotationsCls::_performDidGainAccessibilityFocus() {
    _properties->onDidGainAccessibilityFocus?->call();
}

void RenderSemanticsAnnotationsCls::_performDidLoseAccessibilityFocus() {
    _properties->onDidLoseAccessibilityFocus?->call();
}

RenderBlockSemanticsCls::RenderBlockSemanticsCls(bool blocking, RenderBox child) : RenderProxyBox(child) {
    {
        _blocking = blocking;
    }
}

bool RenderBlockSemanticsCls::blocking() {
    return _blocking;
}

void RenderBlockSemanticsCls::blocking(bool value) {
    assert(value != nullptr);
    if (value == _blocking) {
        return;
    }
    _blocking = value;
    markNeedsSemanticsUpdate();
}

void RenderBlockSemanticsCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->isBlockingSemanticsOfPreviouslyPaintedNodes = blocking();
}

void RenderBlockSemanticsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("blocking"), blocking()));
}

RenderMergeSemanticsCls::RenderMergeSemanticsCls(RenderBox child) : RenderProxyBox(child) {
}

void RenderMergeSemanticsCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    auto _c1 = config;_c1.isSemanticBoundary = auto _c2 = true;_c2.isMergingSemanticsOfDescendants = true;_c2;_c1;
}

RenderExcludeSemanticsCls::RenderExcludeSemanticsCls(RenderBox child, bool excluding) : RenderProxyBox(child) {
    {
        _excluding = excluding;
    }
    {
        assert(_excluding != nullptr);
    }
}

bool RenderExcludeSemanticsCls::excluding() {
    return _excluding;
}

void RenderExcludeSemanticsCls::excluding(bool value) {
    assert(value != nullptr);
    if (value == _excluding) {
        return;
    }
    _excluding = value;
    markNeedsSemanticsUpdate();
}

void RenderExcludeSemanticsCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (excluding()) {
        return;
    }
    super->visitChildrenForSemantics(visitor);
}

void RenderExcludeSemanticsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("excluding"), excluding()));
}

RenderIndexedSemanticsCls::RenderIndexedSemanticsCls(RenderBox child, int index) : RenderProxyBox(child) {
    {
        assert(index != nullptr);
        _index = index;
    }
}

int RenderIndexedSemanticsCls::index() {
    return _index;
}

void RenderIndexedSemanticsCls::index(int value) {
    if (value == index()) {
        return;
    }
    _index = value;
    markNeedsSemanticsUpdate();
}

void RenderIndexedSemanticsCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->indexInParent() = index();
}

void RenderIndexedSemanticsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("index"), index()));
}

RenderLeaderLayerCls::RenderLeaderLayerCls(RenderBox child, LayerLink link) : RenderProxyBox(child) {
    {
        assert(link != nullptr);
        _link = link;
    }
}

LayerLink RenderLeaderLayerCls::link() {
    return _link;
}

void RenderLeaderLayerCls::link(LayerLink value) {
    assert(value != nullptr);
    if (_link == value) {
        return;
    }
    _link->leaderSize = nullptr;
    _link = value;
    if (_previousLayoutSize != nullptr) {
        _link->leaderSize = _previousLayoutSize;
    }
    markNeedsPaint();
}

bool RenderLeaderLayerCls::alwaysNeedsCompositing() {
    return true;
}

void RenderLeaderLayerCls::performLayout() {
    super->performLayout();
    _previousLayoutSize = size;
    link()->leaderSize = size;
}

void RenderLeaderLayerCls::paint(PaintingContext context, Offset offset) {
    if (layer == nullptr) {
        layer = make<LeaderLayerCls>(link(), offset);
    } else {
        LeaderLayer leaderLayer = as<LeaderLayer>(layer!);
            auto _c1 = leaderLayer;    _c1.link() = auto _c2 = link();    _c2.offset = offset;    _c2;_c1;
    }
    context->pushLayer(layer!, super->paint, OffsetCls::zero);
    assert([=] () {
        layer!->debugCreator = debugCreator;
        return true;
    }());
}

void RenderLeaderLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<LayerLink>make<DiagnosticsPropertyCls>(__s("link"), link()));
}

RenderFollowerLayerCls::RenderFollowerLayerCls(RenderBox child, Alignment followerAnchor, Alignment leaderAnchor, LayerLink link, Offset offset, bool showWhenUnlinked) : RenderProxyBox(child) {
    {
        assert(link != nullptr);
        assert(showWhenUnlinked != nullptr);
        assert(offset != nullptr);
        _link = link;
        _showWhenUnlinked = showWhenUnlinked;
        _offset = offset;
        _leaderAnchor = leaderAnchor;
        _followerAnchor = followerAnchor;
    }
}

LayerLink RenderFollowerLayerCls::link() {
    return _link;
}

void RenderFollowerLayerCls::link(LayerLink value) {
    assert(value != nullptr);
    if (_link == value) {
        return;
    }
    _link = value;
    markNeedsPaint();
}

bool RenderFollowerLayerCls::showWhenUnlinked() {
    return _showWhenUnlinked;
}

void RenderFollowerLayerCls::showWhenUnlinked(bool value) {
    assert(value != nullptr);
    if (_showWhenUnlinked == value) {
        return;
    }
    _showWhenUnlinked = value;
    markNeedsPaint();
}

Offset RenderFollowerLayerCls::offset() {
    return _offset;
}

void RenderFollowerLayerCls::offset(Offset value) {
    assert(value != nullptr);
    if (_offset == value) {
        return;
    }
    _offset = value;
    markNeedsPaint();
}

Alignment RenderFollowerLayerCls::leaderAnchor() {
    return _leaderAnchor;
}

void RenderFollowerLayerCls::leaderAnchor(Alignment value) {
    assert(value != nullptr);
    if (_leaderAnchor == value) {
        return;
    }
    _leaderAnchor = value;
    markNeedsPaint();
}

Alignment RenderFollowerLayerCls::followerAnchor() {
    return _followerAnchor;
}

void RenderFollowerLayerCls::followerAnchor(Alignment value) {
    assert(value != nullptr);
    if (_followerAnchor == value) {
        return;
    }
    _followerAnchor = value;
    markNeedsPaint();
}

void RenderFollowerLayerCls::detach() {
    layer() = nullptr;
    super->detach();
}

bool RenderFollowerLayerCls::alwaysNeedsCompositing() {
    return true;
}

FollowerLayer RenderFollowerLayerCls::layer() {
    return as<FollowerLayer>(super->layer);
}

Matrix4 RenderFollowerLayerCls::getCurrentTransform() {
    return layer()?->getLastTransform() | Matrix4Cls->identity();
}

bool RenderFollowerLayerCls::hitTest(BoxHitTestResult result, Offset position) {
    if (link()->leader() == nullptr && !showWhenUnlinked()) {
        return false;
    }
    return hitTestChildren(resultposition);
}

bool RenderFollowerLayerCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    return result->addWithPaintTransform(getCurrentTransform(), position, [=] (BoxHitTestResult result,Offset position) {
        return super->hitTestChildren(resultposition);
    });
}

void RenderFollowerLayerCls::paint(PaintingContext context, Offset offset) {
    Size leaderSize = link()->leaderSize;
    assert(link()->leaderSize != nullptr || (link()->leader() == nullptr || leaderAnchor() == AlignmentCls::topLeft), __s("$link: layer is linked to ${link.leader} but a valid leaderSize is not set. leaderSize is required when leaderAnchor is not Alignment.topLeft (current value is $leaderAnchor)."));
    Offset effectiveLinkedOffset = leaderSize == nullptr? this->offset : leaderAnchor()->alongSize(leaderSize) - followerAnchor()->alongSize(size) + this->offset;
    assert(showWhenUnlinked() != nullptr);
    if (layer() == nullptr) {
        layer() = make<FollowerLayerCls>(link(), showWhenUnlinked(), effectiveLinkedOffset, offset);
    } else {
            auto _c1 = layer();    _c1.link() = auto _c2 = link();    _c2.showWhenUnlinked() = auto _c3 = showWhenUnlinked();    _c3.linkedOffset = auto _c4 = effectiveLinkedOffset;    _c4.unlinkedOffset = offset;    _c4;    _c3;    _c2;_c1;
    }
    context->pushLayer(layer()!, super->paint, OffsetCls::zeroRectCls->fromLTRB(double->negativeInfinity, double->negativeInfinity, double->infinity, double->infinity));
    assert([=] () {
        layer()!->debugCreator = debugCreator;
        return true;
    }());
}

void RenderFollowerLayerCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    transform->multiply(getCurrentTransform());
}

void RenderFollowerLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<LayerLink>make<DiagnosticsPropertyCls>(__s("link"), link()));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("showWhenUnlinked"), showWhenUnlinked()));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("offset"), offset()));
    properties->add(make<TransformPropertyCls>(__s("current transform matrix"), getCurrentTransform()));
}

template<typename T>
RenderAnnotatedRegionCls<T>::RenderAnnotatedRegionCls(RenderBox child, bool sized, T value) : RenderProxyBox(child) {
    {
        assert(value != nullptr);
        assert(sized != nullptr);
        _value = value;
        _sized = sized;
    }
}

template<typename T>
T RenderAnnotatedRegionCls<T>::value() {
    return _value;
}

template<typename T>
void RenderAnnotatedRegionCls<T>::value(T newValue) {
    if (_value == newValue) {
        return;
    }
    _value = newValue;
    markNeedsPaint();
}

template<typename T>
bool RenderAnnotatedRegionCls<T>::sized() {
    return _sized;
}

template<typename T>
void RenderAnnotatedRegionCls<T>::sized(bool value) {
    if (_sized == value) {
        return;
    }
    _sized = value;
    markNeedsPaint();
}

template<typename T>
void RenderAnnotatedRegionCls<T>::paint(PaintingContext context, Offset offset) {
    AnnotatedRegionLayer<T> layer = <T>make<AnnotatedRegionLayerCls>(value()sized()? size : nullptr, sized()? offset : nullptr);
    context->pushLayer(layer, super->paint, offset);
}
