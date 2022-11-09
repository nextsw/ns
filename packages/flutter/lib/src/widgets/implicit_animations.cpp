#include "implicit_animations.hpp"
BoxConstraints BoxConstraintsTweenCls::lerp(double t) {
    return BoxConstraintsCls->lerp(begin, end, t)!;
}

Decoration DecorationTweenCls::lerp(double t) {
    return DecorationCls->lerp(begin, end, t)!;
}

EdgeInsets EdgeInsetsTweenCls::lerp(double t) {
    return EdgeInsetsCls->lerp(begin, end, t)!;
}

EdgeInsetsGeometry EdgeInsetsGeometryTweenCls::lerp(double t) {
    return EdgeInsetsGeometryCls->lerp(begin, end, t)!;
}

BorderRadius BorderRadiusTweenCls::lerp(double t) {
    return BorderRadiusCls->lerp(begin, end, t);
}

Border BorderTweenCls::lerp(double t) {
    return BorderCls->lerp(begin, end, t);
}

Matrix4 Matrix4TweenCls::lerp(double t) {
    assert(begin != nullptr);
    assert(end != nullptr);
    Vector3 beginTranslation = Vector3Cls->zero();
    Vector3 endTranslation = Vector3Cls->zero();
    Quaternion beginRotation = QuaternionCls->identity();
    Quaternion endRotation = QuaternionCls->identity();
    Vector3 beginScale = Vector3Cls->zero();
    Vector3 endScale = Vector3Cls->zero();
    begin!->decompose(beginTranslation, beginRotation, beginScale);
    end!->decompose(endTranslation, endRotation, endScale);
    Vector3 lerpTranslation = beginTranslation * (1.0 - t) + endTranslation * t;
    Quaternion lerpRotation = (beginRotation->scaled(1.0 - t) + endRotation->scaled(t))->normalized();
    Vector3 lerpScale = beginScale * (1.0 - t) + endScale * t;
    return Matrix4Cls->compose(lerpTranslation, lerpRotation, lerpScale);
}

TextStyle TextStyleTweenCls::lerp(double t) {
    return TextStyleCls->lerp(begin, end, t)!;
}

ImplicitlyAnimatedWidgetCls::ImplicitlyAnimatedWidgetCls(Curve curve, Duration duration, Unknown key, VoidCallback onEnd) {
    {
        assert(curve != nullptr);
        assert(duration != nullptr);
    }
}

void ImplicitlyAnimatedWidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>("duration", duration->inMilliseconds"ms"));
}

template<typename T : ImplicitlyAnimatedWidget> AnimationController ImplicitlyAnimatedWidgetStateCls<T>::controller() {
    return _controller;
}

template<typename T : ImplicitlyAnimatedWidget> Animation<double> ImplicitlyAnimatedWidgetStateCls<T>::animation() {
    return _animation;
}

template<typename T : ImplicitlyAnimatedWidget> void ImplicitlyAnimatedWidgetStateCls<T>::initState() {
    super->initState();
    _controller->addStatusListener([=] (AnimationStatus status) {
        ;
    });
    _constructTweens();
    didUpdateTweens();
}

template<typename T : ImplicitlyAnimatedWidget> void ImplicitlyAnimatedWidgetStateCls<T>::didUpdateWidget(T oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget->curve != oldWidget->curve) {
        (((CurvedAnimation)_animation))->dispose();
        _animation = _createCurve();
    }
    _controller->duration = widget->duration;
    if (_constructTweens()) {
        forEachTween([=] (Tween<dynamic> tween,dynamic targetValue,TweenConstructor<dynamic> constructor) {
            _updateTween(tween, targetValue);
            return tween;
        });
            auto _c1 = _controller;    _c1.value = auto _c2 = 0.0;    _c2.forward();    _c2;_c1;
        didUpdateTweens();
    }
}

template<typename T : ImplicitlyAnimatedWidget> void ImplicitlyAnimatedWidgetStateCls<T>::dispose() {
    (((CurvedAnimation)_animation))->dispose();
    _controller->dispose();
    super->dispose();
}

template<typename T : ImplicitlyAnimatedWidget> void ImplicitlyAnimatedWidgetStateCls<T>::didUpdateTweens() {
}

template<typename T : ImplicitlyAnimatedWidget> CurvedAnimation ImplicitlyAnimatedWidgetStateCls<T>::_createCurve() {
    return make<CurvedAnimationCls>(_controller, widget->curve);
}

template<typename T : ImplicitlyAnimatedWidget> bool ImplicitlyAnimatedWidgetStateCls<T>::_shouldAnimateTween(dynamic targetValue, Tween<dynamic> tween) {
    return targetValue != (tween->end ?? tween->begin);
}

template<typename T : ImplicitlyAnimatedWidget> void ImplicitlyAnimatedWidgetStateCls<T>::_updateTween(dynamic targetValue, Tween<dynamic> tween) {
    if (tween == nullptr) {
        return;
    }
    auto _c1 = tween;_c1.begin = auto _c2 = tween->evaluate(_animation);_c2.end = targetValue;_c2;_c1;
}

template<typename T : ImplicitlyAnimatedWidget> bool ImplicitlyAnimatedWidgetStateCls<T>::_constructTweens() {
    bool shouldStartAnimation = false;
    forEachTween([=] (Tween<dynamic> tween,dynamic targetValue,TweenConstructor<dynamic> constructor) {
        if (targetValue != nullptr) {
            tween = constructor(targetValue);
            if (_shouldAnimateTween(tween, targetValue)) {
                shouldStartAnimation = true;
            } else {
                tween->end = tween->begin;
            }
        } else {
            tween = nullptr;
        }
        return tween;
    });
    return shouldStartAnimation;
}

template<typename T : ImplicitlyAnimatedWidget> void AnimatedWidgetBaseStateCls<T>::initState() {
    super->initState();
    controller->addListener(_handleAnimationChanged);
}

template<typename T : ImplicitlyAnimatedWidget> void AnimatedWidgetBaseStateCls<T>::_handleAnimationChanged() {
    setState([=] () {
    });
}

AnimatedContainerCls::AnimatedContainerCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Unknown curve, Decoration decoration, Unknown duration, Decoration foregroundDecoration, double height, Unknown key, EdgeInsetsGeometry margin, Unknown onEnd, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width) {
    {
        assert(margin == nullptr || margin->isNonNegative);
        assert(padding == nullptr || padding->isNonNegative);
        assert(decoration == nullptr || decoration->debugAssertIsValid());
        assert(constraints == nullptr || constraints->debugAssertIsValid());
        assert(color == nullptr || decoration == nullptr, "Cannot provide both a color and a decoration\nThe color argument is just a shorthand for "decoration: BoxDecoration(color: color)".");
        decoration = decoration ?? (color != nullptr? make<BoxDecorationCls>(color) : nullptr);
        constraints = (width != nullptr || height != nullptr)? constraints?->tighten(width, height) ?? BoxConstraintsCls->tightFor(width, height) : constraints;
    }
}

AnimatedWidgetBaseState<AnimatedContainer> AnimatedContainerCls::createState() {
    return make<_AnimatedContainerStateCls>();
}

void AnimatedContainerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>("alignment", alignmentfalse, nullptr));
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>("padding", paddingnullptr));
    properties->add(<Decoration>make<DiagnosticsPropertyCls>("bg", decorationnullptr));
    properties->add(<Decoration>make<DiagnosticsPropertyCls>("fg", foregroundDecorationnullptr));
    properties->add(<BoxConstraints>make<DiagnosticsPropertyCls>("constraints", constraintsnullptr, false));
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>("margin", marginnullptr));
    properties->add(<Matrix4>has("transform", transform));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>("transformAlignment", transformAlignmentnullptr));
    properties->add(<Clip>make<DiagnosticsPropertyCls>("clipBehavior", clipBehavior));
}

void _AnimatedContainerStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _alignment = ((AlignmentGeometryTween)visitor(_alignment, widget->alignment, [=] (dynamic value)     {
        make<AlignmentGeometryTweenCls>(((AlignmentGeometry)value));
    }));
    _padding = ((EdgeInsetsGeometryTween)visitor(_padding, widget->padding, [=] (dynamic value)     {
        make<EdgeInsetsGeometryTweenCls>(((EdgeInsetsGeometry)value));
    }));
    _decoration = ((DecorationTween)visitor(_decoration, widget->decoration, [=] (dynamic value)     {
        make<DecorationTweenCls>(((Decoration)value));
    }));
    _foregroundDecoration = ((DecorationTween)visitor(_foregroundDecoration, widget->foregroundDecoration, [=] (dynamic value)     {
        make<DecorationTweenCls>(((Decoration)value));
    }));
    _constraints = ((BoxConstraintsTween)visitor(_constraints, widget->constraints, [=] (dynamic value)     {
        make<BoxConstraintsTweenCls>(((BoxConstraints)value));
    }));
    _margin = ((EdgeInsetsGeometryTween)visitor(_margin, widget->margin, [=] (dynamic value)     {
        make<EdgeInsetsGeometryTweenCls>(((EdgeInsetsGeometry)value));
    }));
    _transform = ((Matrix4Tween)visitor(_transform, widget->transform, [=] (dynamic value)     {
        make<Matrix4TweenCls>(((Matrix4)value));
    }));
    _transformAlignment = ((AlignmentGeometryTween)visitor(_transformAlignment, widget->transformAlignment, [=] (dynamic value)     {
        make<AlignmentGeometryTweenCls>(((AlignmentGeometry)value));
    }));
}

Widget _AnimatedContainerStateCls::build(BuildContext context) {
    Animation<double> animation = this->animation;
    return make<ContainerCls>(_alignment?->evaluate(animation), _padding?->evaluate(animation), _decoration?->evaluate(animation), _foregroundDecoration?->evaluate(animation), _constraints?->evaluate(animation), _margin?->evaluate(animation), _transform?->evaluate(animation), _transformAlignment?->evaluate(animation), widget->clipBehavior, widget->child);
}

void _AnimatedContainerStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>("alignment", _alignmentfalse, nullptr));
    description->add(<EdgeInsetsGeometryTween>make<DiagnosticsPropertyCls>("padding", _paddingnullptr));
    description->add(<DecorationTween>make<DiagnosticsPropertyCls>("bg", _decorationnullptr));
    description->add(<DecorationTween>make<DiagnosticsPropertyCls>("fg", _foregroundDecorationnullptr));
    description->add(<BoxConstraintsTween>make<DiagnosticsPropertyCls>("constraints", _constraintsfalse, nullptr));
    description->add(<EdgeInsetsGeometryTween>make<DiagnosticsPropertyCls>("margin", _marginnullptr));
    description->add(<Matrix4Tween>has("transform", _transform));
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>("transformAlignment", _transformAlignmentnullptr));
}

AnimatedPaddingCls::AnimatedPaddingCls(Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, EdgeInsetsGeometry padding) {
    {
        assert(padding != nullptr);
        assert(padding->isNonNegative);
    }
}

AnimatedWidgetBaseState<AnimatedPadding> AnimatedPaddingCls::createState() {
    return make<_AnimatedPaddingStateCls>();
}

void AnimatedPaddingCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>("padding", padding));
}

void _AnimatedPaddingStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _padding = ((EdgeInsetsGeometryTween)visitor(_padding, widget->padding, [=] (dynamic value)     {
        make<EdgeInsetsGeometryTweenCls>(((EdgeInsetsGeometry)value));
    }));
}

Widget _AnimatedPaddingStateCls::build(BuildContext context) {
    return make<PaddingCls>(_padding!->evaluate(animation)->clamp(EdgeInsetsCls::zero, EdgeInsetsGeometryCls::infinity), widget->child);
}

void _AnimatedPaddingStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<EdgeInsetsGeometryTween>make<DiagnosticsPropertyCls>("padding", _paddingnullptr));
}

AnimatedAlignCls::AnimatedAlignCls(AlignmentGeometry alignment, Widget child, Unknown curve, Unknown duration, double heightFactor, Unknown key, Unknown onEnd, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

AnimatedWidgetBaseState<AnimatedAlign> AnimatedAlignCls::createState() {
    return make<_AnimatedAlignStateCls>();
}

void AnimatedAlignCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>("alignment", alignment));
}

void _AnimatedAlignStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _alignment = ((AlignmentGeometryTween)visitor(_alignment, widget->alignment, [=] (dynamic value)     {
        make<AlignmentGeometryTweenCls>(((AlignmentGeometry)value));
    }));
    if (widget->heightFactor != nullptr) {
        _heightFactorTween = ((Tween<double>)visitor(_heightFactorTween, widget->heightFactor, [=] (dynamic value)         {
            <double>make<TweenCls>(((double)value));
        }));
    }
    if (widget->widthFactor != nullptr) {
        _widthFactorTween = ((Tween<double>)visitor(_widthFactorTween, widget->widthFactor, [=] (dynamic value)         {
            <double>make<TweenCls>(((double)value));
        }));
    }
}

Widget _AnimatedAlignStateCls::build(BuildContext context) {
    return make<AlignCls>(_alignment!->evaluate(animation)!, _heightFactorTween?->evaluate(animation), _widthFactorTween?->evaluate(animation), widget->child);
}

void _AnimatedAlignStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>("alignment", _alignmentnullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>("widthFactor", _widthFactorTweennullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>("heightFactor", _heightFactorTweennullptr));
}

AnimatedPositionedCls::AnimatedPositionedCls(double bottom, Widget child, Unknown curve, Unknown duration, double height, Unknown key, double left, Unknown onEnd, double right, double top, double width) {
    {
        assert(left == nullptr || right == nullptr || width == nullptr);
        assert(top == nullptr || bottom == nullptr || height == nullptr);
    }
}

void AnimatedPositionedCls::fromRect(Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, Rect rect)

AnimatedWidgetBaseState<AnimatedPositioned> AnimatedPositionedCls::createState() {
    return make<_AnimatedPositionedStateCls>();
}

void AnimatedPositionedCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>("left", leftnullptr));
    properties->add(make<DoublePropertyCls>("top", topnullptr));
    properties->add(make<DoublePropertyCls>("right", rightnullptr));
    properties->add(make<DoublePropertyCls>("bottom", bottomnullptr));
    properties->add(make<DoublePropertyCls>("width", widthnullptr));
    properties->add(make<DoublePropertyCls>("height", heightnullptr));
}

void _AnimatedPositionedStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _left = ((Tween<double>)visitor(_left, widget->left, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _top = ((Tween<double>)visitor(_top, widget->top, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _right = ((Tween<double>)visitor(_right, widget->right, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _bottom = ((Tween<double>)visitor(_bottom, widget->bottom, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _width = ((Tween<double>)visitor(_width, widget->width, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _height = ((Tween<double>)visitor(_height, widget->height, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
}

Widget _AnimatedPositionedStateCls::build(BuildContext context) {
    return make<PositionedCls>(_left?->evaluate(animation), _top?->evaluate(animation), _right?->evaluate(animation), _bottom?->evaluate(animation), _width?->evaluate(animation), _height?->evaluate(animation), widget->child);
}

void _AnimatedPositionedStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<Tween<double>>has("left", _left));
    description->add(<Tween<double>>has("top", _top));
    description->add(<Tween<double>>has("right", _right));
    description->add(<Tween<double>>has("bottom", _bottom));
    description->add(<Tween<double>>has("width", _width));
    description->add(<Tween<double>>has("height", _height));
}

AnimatedPositionedDirectionalCls::AnimatedPositionedDirectionalCls(double bottom, Widget child, Unknown curve, Unknown duration, double end, double height, Unknown key, Unknown onEnd, double start, double top, double width) {
    {
        assert(start == nullptr || end == nullptr || width == nullptr);
        assert(top == nullptr || bottom == nullptr || height == nullptr);
    }
}

AnimatedWidgetBaseState<AnimatedPositionedDirectional> AnimatedPositionedDirectionalCls::createState() {
    return make<_AnimatedPositionedDirectionalStateCls>();
}

void AnimatedPositionedDirectionalCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>("start", startnullptr));
    properties->add(make<DoublePropertyCls>("top", topnullptr));
    properties->add(make<DoublePropertyCls>("end", endnullptr));
    properties->add(make<DoublePropertyCls>("bottom", bottomnullptr));
    properties->add(make<DoublePropertyCls>("width", widthnullptr));
    properties->add(make<DoublePropertyCls>("height", heightnullptr));
}

void _AnimatedPositionedDirectionalStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _start = ((Tween<double>)visitor(_start, widget->start, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _top = ((Tween<double>)visitor(_top, widget->top, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _end = ((Tween<double>)visitor(_end, widget->end, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _bottom = ((Tween<double>)visitor(_bottom, widget->bottom, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _width = ((Tween<double>)visitor(_width, widget->width, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _height = ((Tween<double>)visitor(_height, widget->height, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
}

Widget _AnimatedPositionedDirectionalStateCls::build(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    return PositionedCls->directional(DirectionalityCls->of(context), _start?->evaluate(animation), _top?->evaluate(animation), _end?->evaluate(animation), _bottom?->evaluate(animation), _width?->evaluate(animation), _height?->evaluate(animation), widget->child);
}

void _AnimatedPositionedDirectionalStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<Tween<double>>has("start", _start));
    description->add(<Tween<double>>has("top", _top));
    description->add(<Tween<double>>has("end", _end));
    description->add(<Tween<double>>has("bottom", _bottom));
    description->add(<Tween<double>>has("width", _width));
    description->add(<Tween<double>>has("height", _height));
}

AnimatedScaleCls::AnimatedScaleCls(Alignment alignment, Widget child, Unknown curve, Unknown duration, FilterQuality filterQuality, Unknown key, Unknown onEnd, double scale) {
    {
        assert(scale != nullptr);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedScale> AnimatedScaleCls::createState() {
    return make<_AnimatedScaleStateCls>();
}

void AnimatedScaleCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>("scale", scale));
    properties->add(<Alignment>make<DiagnosticsPropertyCls>("alignment", alignmentAlignmentCls::center));
    properties->add(<FilterQuality>make<EnumPropertyCls>("filterQuality", filterQualitynullptr));
}

void _AnimatedScaleStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _scale = ((Tween<double>)visitor(_scale, widget->scale, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
}

void _AnimatedScaleStateCls::didUpdateTweens() {
    _scaleAnimation = animation->drive(_scale!);
}

Widget _AnimatedScaleStateCls::build(BuildContext context) {
    return make<ScaleTransitionCls>(_scaleAnimation, widget->alignment, widget->filterQuality, widget->child);
}

AnimatedRotationCls::AnimatedRotationCls(Alignment alignment, Widget child, Unknown curve, Unknown duration, FilterQuality filterQuality, Unknown key, Unknown onEnd, double turns) {
    {
        assert(turns != nullptr);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedRotation> AnimatedRotationCls::createState() {
    return make<_AnimatedRotationStateCls>();
}

void AnimatedRotationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>("turns", turns));
    properties->add(<Alignment>make<DiagnosticsPropertyCls>("alignment", alignmentAlignmentCls::center));
    properties->add(<FilterQuality>make<EnumPropertyCls>("filterQuality", filterQualitynullptr));
}

void _AnimatedRotationStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _turns = ((Tween<double>)visitor(_turns, widget->turns, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
}

void _AnimatedRotationStateCls::didUpdateTweens() {
    _turnsAnimation = animation->drive(_turns!);
}

Widget _AnimatedRotationStateCls::build(BuildContext context) {
    return make<RotationTransitionCls>(_turnsAnimation, widget->alignment, widget->filterQuality, widget->child);
}

ImplicitlyAnimatedWidgetState<AnimatedSlide> AnimatedSlideCls::createState() {
    return make<_AnimatedSlideStateCls>();
}

void AnimatedSlideCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>("offset", offset));
}

void _AnimatedSlideStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _offset = ((Tween<Offset>)visitor(_offset, widget->offset, [=] (dynamic value)     {
        <Offset>make<TweenCls>(((Offset)value));
    }));
}

void _AnimatedSlideStateCls::didUpdateTweens() {
    _offsetAnimation = animation->drive(_offset!);
}

Widget _AnimatedSlideStateCls::build(BuildContext context) {
    return make<SlideTransitionCls>(_offsetAnimation, widget->child);
}

AnimatedOpacityCls::AnimatedOpacityCls(bool alwaysIncludeSemantics, Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, double opacity) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedOpacity> AnimatedOpacityCls::createState() {
    return make<_AnimatedOpacityStateCls>();
}

void AnimatedOpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>("opacity", opacity));
}

void _AnimatedOpacityStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _opacity = ((Tween<double>)visitor(_opacity, widget->opacity, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
}

void _AnimatedOpacityStateCls::didUpdateTweens() {
    _opacityAnimation = animation->drive(_opacity!);
}

Widget _AnimatedOpacityStateCls::build(BuildContext context) {
    return make<FadeTransitionCls>(_opacityAnimation, widget->alwaysIncludeSemantics, widget->child);
}

SliverAnimatedOpacityCls::SliverAnimatedOpacityCls(bool alwaysIncludeSemantics, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, double opacity, Widget sliver) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
    }
}

ImplicitlyAnimatedWidgetState<SliverAnimatedOpacity> SliverAnimatedOpacityCls::createState() {
    return make<_SliverAnimatedOpacityStateCls>();
}

void SliverAnimatedOpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>("opacity", opacity));
}

void _SliverAnimatedOpacityStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _opacity = ((Tween<double>)visitor(_opacity, widget->opacity, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
}

void _SliverAnimatedOpacityStateCls::didUpdateTweens() {
    _opacityAnimation = animation->drive(_opacity!);
}

Widget _SliverAnimatedOpacityStateCls::build(BuildContext context) {
    return make<SliverFadeTransitionCls>(_opacityAnimation, widget->sliver, widget->alwaysIncludeSemantics);
}

AnimatedDefaultTextStyleCls::AnimatedDefaultTextStyleCls(Widget child, Unknown curve, Unknown duration, Unknown key, int maxLines, Unknown onEnd, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis) {
    {
        assert(style != nullptr);
        assert(child != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(textWidthBasis != nullptr);
    }
}

AnimatedWidgetBaseState<AnimatedDefaultTextStyle> AnimatedDefaultTextStyleCls::createState() {
    return make<_AnimatedDefaultTextStyleStateCls>();
}

void AnimatedDefaultTextStyleCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    style->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>("textAlign", textAlignnullptr));
    properties->add(make<FlagPropertyCls>("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties->add(<TextOverflow>make<EnumPropertyCls>("overflow", overflownullptr));
    properties->add(make<IntPropertyCls>("maxLines", maxLinesnullptr));
    properties->add(<TextWidthBasis>make<EnumPropertyCls>("textWidthBasis", textWidthBasisTextWidthBasisCls::parent));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>("textHeightBehavior", textHeightBehaviornullptr));
}

void _AnimatedDefaultTextStyleStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _style = ((TextStyleTween)visitor(_style, widget->style, [=] (dynamic value)     {
        make<TextStyleTweenCls>(((TextStyle)value));
    }));
}

Widget _AnimatedDefaultTextStyleStateCls::build(BuildContext context) {
    return make<DefaultTextStyleCls>(_style!->evaluate(animation), widget->textAlign, widget->softWrap, widget->overflow, widget->maxLines, widget->textWidthBasis, widget->textHeightBehavior, widget->child);
}

AnimatedPhysicalModelCls::AnimatedPhysicalModelCls(bool animateColor, bool animateShadowColor, BorderRadius borderRadius, Widget child, Clip clipBehavior, Color color, Unknown curve, Unknown duration, double elevation, Unknown key, Unknown onEnd, Color shadowColor, BoxShape shape) {
    {
        assert(child != nullptr);
        assert(shape != nullptr);
        assert(clipBehavior != nullptr);
        assert(borderRadius != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
        assert(animateColor != nullptr);
        assert(animateShadowColor != nullptr);
    }
}

AnimatedWidgetBaseState<AnimatedPhysicalModel> AnimatedPhysicalModelCls::createState() {
    return make<_AnimatedPhysicalModelStateCls>();
}

void AnimatedPhysicalModelCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BoxShape>make<EnumPropertyCls>("shape", shape));
    properties->add(<BorderRadius>make<DiagnosticsPropertyCls>("borderRadius", borderRadius));
    properties->add(make<DoublePropertyCls>("elevation", elevation));
    properties->add(make<ColorPropertyCls>("color", color));
    properties->add(<bool>make<DiagnosticsPropertyCls>("animateColor", animateColor));
    properties->add(make<ColorPropertyCls>("shadowColor", shadowColor));
    properties->add(<bool>make<DiagnosticsPropertyCls>("animateShadowColor", animateShadowColor));
}

void _AnimatedPhysicalModelStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _borderRadius = ((BorderRadiusTween)visitor(_borderRadius, widget->borderRadius, [=] (dynamic value)     {
        make<BorderRadiusTweenCls>(((BorderRadius)value));
    }));
    _elevation = ((Tween<double>)visitor(_elevation, widget->elevation, [=] (dynamic value)     {
        <double>make<TweenCls>(((double)value));
    }));
    _color = ((ColorTween)visitor(_color, widget->color, [=] (dynamic value)     {
        make<ColorTweenCls>(((Color)value));
    }));
    _shadowColor = ((ColorTween)visitor(_shadowColor, widget->shadowColor, [=] (dynamic value)     {
        make<ColorTweenCls>(((Color)value));
    }));
}

Widget _AnimatedPhysicalModelStateCls::build(BuildContext context) {
    return make<PhysicalModelCls>(widget->shape, widget->clipBehavior, _borderRadius!->evaluate(animation), _elevation!->evaluate(animation), widget->animateColor? _color!->evaluate(animation)! : widget->color, widget->animateShadowColor? _shadowColor!->evaluate(animation)! : widget->shadowColor, widget->child);
}

AnimatedFractionallySizedBoxCls::AnimatedFractionallySizedBoxCls(AlignmentGeometry alignment, Widget child, Unknown curve, Unknown duration, double heightFactor, Unknown key, Unknown onEnd, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

AnimatedWidgetBaseState<AnimatedFractionallySizedBox> AnimatedFractionallySizedBoxCls::createState() {
    return make<_AnimatedFractionallySizedBoxStateCls>();
}

void AnimatedFractionallySizedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>("alignment", alignment));
    properties->add(<double>make<DiagnosticsPropertyCls>("widthFactor", widthFactor));
    properties->add(<double>make<DiagnosticsPropertyCls>("heightFactor", heightFactor));
}

void _AnimatedFractionallySizedBoxStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _alignment = ((AlignmentGeometryTween)visitor(_alignment, widget->alignment, [=] (dynamic value)     {
        make<AlignmentGeometryTweenCls>(((AlignmentGeometry)value));
    }));
    if (widget->heightFactor != nullptr) {
        _heightFactorTween = ((Tween<double>)visitor(_heightFactorTween, widget->heightFactor, [=] (dynamic value)         {
            <double>make<TweenCls>(((double)value));
        }));
    }
    if (widget->widthFactor != nullptr) {
        _widthFactorTween = ((Tween<double>)visitor(_widthFactorTween, widget->widthFactor, [=] (dynamic value)         {
            <double>make<TweenCls>(((double)value));
        }));
    }
}

Widget _AnimatedFractionallySizedBoxStateCls::build(BuildContext context) {
    return make<FractionallySizedBoxCls>(_alignment!->evaluate(animation)!, _heightFactorTween?->evaluate(animation), _widthFactorTween?->evaluate(animation), widget->child);
}

void _AnimatedFractionallySizedBoxStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>("alignment", _alignmentnullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>("widthFactor", _widthFactorTweennullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>("heightFactor", _heightFactorTweennullptr));
}
