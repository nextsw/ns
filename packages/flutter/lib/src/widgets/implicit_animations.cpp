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

ImplicitlyAnimatedWidgetCls::ImplicitlyAnimatedWidgetCls(Curve curve, Duration duration, Key key, VoidCallback onEnd) {
    {
        assert(curve != nullptr);
        assert(duration != nullptr);
    }
}

void ImplicitlyAnimatedWidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("duration"), duration->inMilliseconds(), __s("ms")));
}

template<typename T>
AnimationController ImplicitlyAnimatedWidgetStateCls<T>::controller() {
    return _controller;
}

template<typename T>
Animation<double> ImplicitlyAnimatedWidgetStateCls<T>::animation() {
    return _animation;
}

template<typename T>
void ImplicitlyAnimatedWidgetStateCls<T>::initState() {
    super->initState();
    _controller->addStatusListener([=] (AnimationStatus status) {
        ;
    });
    _constructTweens();
    didUpdateTweens();
}

template<typename T>
void ImplicitlyAnimatedWidgetStateCls<T>::didUpdateWidget(T oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->curve != oldWidget->curve) {
        (as<CurvedAnimation>(_animation))->dispose();
        _animation = _createCurve();
    }
    _controller->duration = widget()->duration;
    if (_constructTweens()) {
        forEachTween([=] (Tween<Object> tween,Object targetValue,TweenConstructor<Object> constructor) {
            _updateTween(tween, targetValue);
            return tween;
        });
            auto _c1 = _controller;    _c1.value = auto _c2 = 0.0;    _c2.forward();    _c2;_c1;
        didUpdateTweens();
    }
}

template<typename T>
void ImplicitlyAnimatedWidgetStateCls<T>::dispose() {
    (as<CurvedAnimation>(_animation))->dispose();
    _controller->dispose();
    super->dispose();
}

template<typename T>
void ImplicitlyAnimatedWidgetStateCls<T>::didUpdateTweens() {
}

template<typename T>
CurvedAnimation ImplicitlyAnimatedWidgetStateCls<T>::_createCurve() {
    return make<CurvedAnimationCls>(_controller, widget()->curve);
}

template<typename T>
bool ImplicitlyAnimatedWidgetStateCls<T>::_shouldAnimateTween(Tween<Object> tween, Object targetValue) {
    return targetValue != (tween->end | tween->begin);
}

template<typename T>
void ImplicitlyAnimatedWidgetStateCls<T>::_updateTween(Tween<Object> tween, Object targetValue) {
    if (tween == nullptr) {
        return;
    }
    auto _c1 = tween;_c1.begin = auto _c2 = tween->evaluate(_animation);_c2.end = targetValue;_c2;_c1;
}

template<typename T>
bool ImplicitlyAnimatedWidgetStateCls<T>::_constructTweens() {
    bool shouldStartAnimation = false;
    forEachTween([=] (Tween<Object> tween,Object targetValue,TweenConstructor<Object> constructor) {
        if (targetValue != nullptr) {
            tween |= constructor(targetValue);
            if (_shouldAnimateTween(tween, targetValue)) {
                shouldStartAnimation = true;
            } else {
                tween->end |= tween->begin;
            }
        } else {
            tween = nullptr;
        }
        return tween;
    });
    return shouldStartAnimation;
}

template<typename T>
void AnimatedWidgetBaseStateCls<T>::initState() {
    super->initState();
    controller()->addListener(_handleAnimationChanged);
}

template<typename T>
void AnimatedWidgetBaseStateCls<T>::_handleAnimationChanged() {
    setState([=] () {
    });
}

AnimatedContainerCls::AnimatedContainerCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Curve curve, Decoration decoration, Duration duration, Decoration foregroundDecoration, double height, Key key, EdgeInsetsGeometry margin, VoidCallback onEnd, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width) {
    {
        assert(margin == nullptr || margin->isNonNegative());
        assert(padding == nullptr || padding->isNonNegative());
        assert(decoration == nullptr || decoration->debugAssertIsValid());
        assert(constraints == nullptr || constraints->debugAssertIsValid());
        assert(color == nullptr || decoration == nullptr, __s("Cannot provide both a color and a decoration\nThe color argument is just a shorthand for "decoration: BoxDecoration(color: color)"."));
        decoration = decoration | (color != nullptr? make<BoxDecorationCls>(color) : nullptr);
        constraints = (width != nullptr || height != nullptr)? constraints?->tighten(width, height) | BoxConstraintsCls->tightFor(width, height) : constraints;
    }
}

AnimatedWidgetBaseState<AnimatedContainer> AnimatedContainerCls::createState() {
    return make<_AnimatedContainerStateCls>();
}

void AnimatedContainerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment, false, nullptr));
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding, nullptr));
    properties->add(<Decoration>make<DiagnosticsPropertyCls>(__s("bg"), decoration, nullptr));
    properties->add(<Decoration>make<DiagnosticsPropertyCls>(__s("fg"), foregroundDecoration, nullptr));
    properties->add(<BoxConstraints>make<DiagnosticsPropertyCls>(__s("constraints"), constraints, nullptr, false));
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("margin"), margin, nullptr));
    properties->add(<Matrix4>has(__s("transform"), transform));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("transformAlignment"), transformAlignment, nullptr));
    properties->add(<Clip>make<DiagnosticsPropertyCls>(__s("clipBehavior"), clipBehavior));
}

void _AnimatedContainerStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _alignment = as<AlignmentGeometryTween>(visitor(_alignment, widget()->alignment, [=] (Object value) {
        make<AlignmentGeometryTweenCls>(as<AlignmentGeometry>(value));
    }));
    _padding = as<EdgeInsetsGeometryTween>(visitor(_padding, widget()->padding, [=] (Object value) {
        make<EdgeInsetsGeometryTweenCls>(as<EdgeInsetsGeometry>(value));
    }));
    _decoration = as<DecorationTween>(visitor(_decoration, widget()->decoration, [=] (Object value) {
        make<DecorationTweenCls>(as<Decoration>(value));
    }));
    _foregroundDecoration = as<DecorationTween>(visitor(_foregroundDecoration, widget()->foregroundDecoration, [=] (Object value) {
        make<DecorationTweenCls>(as<Decoration>(value));
    }));
    _constraints = as<BoxConstraintsTween>(visitor(_constraints, widget()->constraints, [=] (Object value) {
        make<BoxConstraintsTweenCls>(as<BoxConstraints>(value));
    }));
    _margin = as<EdgeInsetsGeometryTween>(visitor(_margin, widget()->margin, [=] (Object value) {
        make<EdgeInsetsGeometryTweenCls>(as<EdgeInsetsGeometry>(value));
    }));
    _transform = as<Matrix4Tween>(visitor(_transform, widget()->transform, [=] (Object value) {
        make<Matrix4TweenCls>(as<Matrix4>(value));
    }));
    _transformAlignment = as<AlignmentGeometryTween>(visitor(_transformAlignment, widget()->transformAlignment, [=] (Object value) {
        make<AlignmentGeometryTweenCls>(as<AlignmentGeometry>(value));
    }));
}

Widget _AnimatedContainerStateCls::build(BuildContext context) {
    Animation<double> animation = this->animation();
    return make<ContainerCls>(_alignment?->evaluate(animation), _padding?->evaluate(animation), _decoration?->evaluate(animation), _foregroundDecoration?->evaluate(animation), _constraints?->evaluate(animation), _margin?->evaluate(animation), _transform?->evaluate(animation), _transformAlignment?->evaluate(animation), widget()->clipBehavior, widget()->child);
}

void _AnimatedContainerStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>(__s("alignment"), _alignment, false, nullptr));
    description->add(<EdgeInsetsGeometryTween>make<DiagnosticsPropertyCls>(__s("padding"), _padding, nullptr));
    description->add(<DecorationTween>make<DiagnosticsPropertyCls>(__s("bg"), _decoration, nullptr));
    description->add(<DecorationTween>make<DiagnosticsPropertyCls>(__s("fg"), _foregroundDecoration, nullptr));
    description->add(<BoxConstraintsTween>make<DiagnosticsPropertyCls>(__s("constraints"), _constraints, false, nullptr));
    description->add(<EdgeInsetsGeometryTween>make<DiagnosticsPropertyCls>(__s("margin"), _margin, nullptr));
    description->add(<Matrix4Tween>has(__s("transform"), _transform));
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>(__s("transformAlignment"), _transformAlignment, nullptr));
}

AnimatedPaddingCls::AnimatedPaddingCls(Widget child, Curve curve, Duration duration, Key key, VoidCallback onEnd, EdgeInsetsGeometry padding) {
    {
        assert(padding != nullptr);
        assert(padding->isNonNegative());
    }
}

AnimatedWidgetBaseState<AnimatedPadding> AnimatedPaddingCls::createState() {
    return make<_AnimatedPaddingStateCls>();
}

void AnimatedPaddingCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding));
}

void _AnimatedPaddingStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _padding = as<EdgeInsetsGeometryTween>(visitor(_padding, widget()->padding, [=] (Object value) {
        make<EdgeInsetsGeometryTweenCls>(as<EdgeInsetsGeometry>(value));
    }));
}

Widget _AnimatedPaddingStateCls::build(BuildContext context) {
    return make<PaddingCls>(_padding!->evaluate(animation())->clamp(EdgeInsetsCls::zero, EdgeInsetsGeometryCls::infinity), widget()->child);
}

void _AnimatedPaddingStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<EdgeInsetsGeometryTween>make<DiagnosticsPropertyCls>(__s("padding"), _padding, nullptr));
}

AnimatedAlignCls::AnimatedAlignCls(AlignmentGeometry alignment, Widget child, Curve curve, Duration duration, double heightFactor, Key key, VoidCallback onEnd, double widthFactor) {
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
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
}

void _AnimatedAlignStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _alignment = as<AlignmentGeometryTween>(visitor(_alignment, widget()->alignment, [=] (Object value) {
        make<AlignmentGeometryTweenCls>(as<AlignmentGeometry>(value));
    }));
    if (widget()->heightFactor != nullptr) {
        _heightFactorTween = as<Tween<double>>(visitor(_heightFactorTween, widget()->heightFactor, [=] (Object value) {
            <double>make<TweenCls>(as<double>(value));
        }));
    }
    if (widget()->widthFactor != nullptr) {
        _widthFactorTween = as<Tween<double>>(visitor(_widthFactorTween, widget()->widthFactor, [=] (Object value) {
            <double>make<TweenCls>(as<double>(value));
        }));
    }
}

Widget _AnimatedAlignStateCls::build(BuildContext context) {
    return make<AlignCls>(_alignment!->evaluate(animation())!, _heightFactorTween?->evaluate(animation()), _widthFactorTween?->evaluate(animation()), widget()->child);
}

void _AnimatedAlignStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>(__s("alignment"), _alignment, nullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>(__s("widthFactor"), _widthFactorTween, nullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>(__s("heightFactor"), _heightFactorTween, nullptr));
}

AnimatedPositionedCls::AnimatedPositionedCls(double bottom, Widget child, Curve curve, Duration duration, double height, Key key, double left, VoidCallback onEnd, double right, double top, double width) {
    {
        assert(left == nullptr || right == nullptr || width == nullptr);
        assert(top == nullptr || bottom == nullptr || height == nullptr);
    }
}

void AnimatedPositionedCls::fromRect(Unknown child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, Rect rect)

AnimatedWidgetBaseState<AnimatedPositioned> AnimatedPositionedCls::createState() {
    return make<_AnimatedPositionedStateCls>();
}

void AnimatedPositionedCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("left"), left, nullptr));
    properties->add(make<DoublePropertyCls>(__s("top"), top, nullptr));
    properties->add(make<DoublePropertyCls>(__s("right"), right, nullptr));
    properties->add(make<DoublePropertyCls>(__s("bottom"), bottom, nullptr));
    properties->add(make<DoublePropertyCls>(__s("width"), width, nullptr));
    properties->add(make<DoublePropertyCls>(__s("height"), height, nullptr));
}

void _AnimatedPositionedStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _left = as<Tween<double>>(visitor(_left, widget()->left, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _top = as<Tween<double>>(visitor(_top, widget()->top, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _right = as<Tween<double>>(visitor(_right, widget()->right, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _bottom = as<Tween<double>>(visitor(_bottom, widget()->bottom, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _width = as<Tween<double>>(visitor(_width, widget()->width, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _height = as<Tween<double>>(visitor(_height, widget()->height, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
}

Widget _AnimatedPositionedStateCls::build(BuildContext context) {
    return make<PositionedCls>(_left?->evaluate(animation()), _top?->evaluate(animation()), _right?->evaluate(animation()), _bottom?->evaluate(animation()), _width?->evaluate(animation()), _height?->evaluate(animation()), widget()->child);
}

void _AnimatedPositionedStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<Tween<double>>has(__s("left"), _left));
    description->add(<Tween<double>>has(__s("top"), _top));
    description->add(<Tween<double>>has(__s("right"), _right));
    description->add(<Tween<double>>has(__s("bottom"), _bottom));
    description->add(<Tween<double>>has(__s("width"), _width));
    description->add(<Tween<double>>has(__s("height"), _height));
}

AnimatedPositionedDirectionalCls::AnimatedPositionedDirectionalCls(double bottom, Widget child, Curve curve, Duration duration, double end, double height, Key key, VoidCallback onEnd, double start, double top, double width) {
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
    properties->add(make<DoublePropertyCls>(__s("start"), start, nullptr));
    properties->add(make<DoublePropertyCls>(__s("top"), top, nullptr));
    properties->add(make<DoublePropertyCls>(__s("end"), end, nullptr));
    properties->add(make<DoublePropertyCls>(__s("bottom"), bottom, nullptr));
    properties->add(make<DoublePropertyCls>(__s("width"), width, nullptr));
    properties->add(make<DoublePropertyCls>(__s("height"), height, nullptr));
}

void _AnimatedPositionedDirectionalStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _start = as<Tween<double>>(visitor(_start, widget()->start, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _top = as<Tween<double>>(visitor(_top, widget()->top, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _end = as<Tween<double>>(visitor(_end, widget()->end, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _bottom = as<Tween<double>>(visitor(_bottom, widget()->bottom, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _width = as<Tween<double>>(visitor(_width, widget()->width, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _height = as<Tween<double>>(visitor(_height, widget()->height, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
}

Widget _AnimatedPositionedDirectionalStateCls::build(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    return PositionedCls->directional(DirectionalityCls->of(context), _start?->evaluate(animation()), _top?->evaluate(animation()), _end?->evaluate(animation()), _bottom?->evaluate(animation()), _width?->evaluate(animation()), _height?->evaluate(animation()), widget()->child);
}

void _AnimatedPositionedDirectionalStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<Tween<double>>has(__s("start"), _start));
    description->add(<Tween<double>>has(__s("top"), _top));
    description->add(<Tween<double>>has(__s("end"), _end));
    description->add(<Tween<double>>has(__s("bottom"), _bottom));
    description->add(<Tween<double>>has(__s("width"), _width));
    description->add(<Tween<double>>has(__s("height"), _height));
}

AnimatedScaleCls::AnimatedScaleCls(Alignment alignment, Widget child, Curve curve, Duration duration, FilterQuality filterQuality, Key key, VoidCallback onEnd, double scale) {
    {
        assert(scale != nullptr);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedScale> AnimatedScaleCls::createState() {
    return make<_AnimatedScaleStateCls>();
}

void AnimatedScaleCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("scale"), scale));
    properties->add(<Alignment>make<DiagnosticsPropertyCls>(__s("alignment"), alignment, AlignmentCls::center));
    properties->add(<FilterQuality>make<EnumPropertyCls>(__s("filterQuality"), filterQuality, nullptr));
}

void _AnimatedScaleStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _scale = as<Tween<double>>(visitor(_scale, widget()->scale, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
}

void _AnimatedScaleStateCls::didUpdateTweens() {
    _scaleAnimation = animation()->drive(_scale!);
}

Widget _AnimatedScaleStateCls::build(BuildContext context) {
    return make<ScaleTransitionCls>(_scaleAnimation, widget()->alignment, widget()->filterQuality, widget()->child);
}

AnimatedRotationCls::AnimatedRotationCls(Alignment alignment, Widget child, Curve curve, Duration duration, FilterQuality filterQuality, Key key, VoidCallback onEnd, double turns) {
    {
        assert(turns != nullptr);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedRotation> AnimatedRotationCls::createState() {
    return make<_AnimatedRotationStateCls>();
}

void AnimatedRotationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("turns"), turns));
    properties->add(<Alignment>make<DiagnosticsPropertyCls>(__s("alignment"), alignment, AlignmentCls::center));
    properties->add(<FilterQuality>make<EnumPropertyCls>(__s("filterQuality"), filterQuality, nullptr));
}

void _AnimatedRotationStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _turns = as<Tween<double>>(visitor(_turns, widget()->turns, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
}

void _AnimatedRotationStateCls::didUpdateTweens() {
    _turnsAnimation = animation()->drive(_turns!);
}

Widget _AnimatedRotationStateCls::build(BuildContext context) {
    return make<RotationTransitionCls>(_turnsAnimation, widget()->alignment, widget()->filterQuality, widget()->child);
}

ImplicitlyAnimatedWidgetState<AnimatedSlide> AnimatedSlideCls::createState() {
    return make<_AnimatedSlideStateCls>();
}

void AnimatedSlideCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("offset"), offset));
}

void _AnimatedSlideStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _offset = as<Tween<Offset>>(visitor(_offset, widget()->offset, [=] (Object value) {
        <Offset>make<TweenCls>(as<Offset>(value));
    }));
}

void _AnimatedSlideStateCls::didUpdateTweens() {
    _offsetAnimation = animation()->drive(_offset!);
}

Widget _AnimatedSlideStateCls::build(BuildContext context) {
    return make<SlideTransitionCls>(_offsetAnimation, widget()->child);
}

AnimatedOpacityCls::AnimatedOpacityCls(bool alwaysIncludeSemantics, Widget child, Curve curve, Duration duration, Key key, VoidCallback onEnd, double opacity) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedOpacity> AnimatedOpacityCls::createState() {
    return make<_AnimatedOpacityStateCls>();
}

void AnimatedOpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("opacity"), opacity));
}

void _AnimatedOpacityStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _opacity = as<Tween<double>>(visitor(_opacity, widget()->opacity, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
}

void _AnimatedOpacityStateCls::didUpdateTweens() {
    _opacityAnimation = animation()->drive(_opacity!);
}

Widget _AnimatedOpacityStateCls::build(BuildContext context) {
    return make<FadeTransitionCls>(_opacityAnimation, widget()->alwaysIncludeSemantics, widget()->child);
}

SliverAnimatedOpacityCls::SliverAnimatedOpacityCls(bool alwaysIncludeSemantics, Curve curve, Duration duration, Key key, VoidCallback onEnd, double opacity, Widget sliver) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
    }
}

ImplicitlyAnimatedWidgetState<SliverAnimatedOpacity> SliverAnimatedOpacityCls::createState() {
    return make<_SliverAnimatedOpacityStateCls>();
}

void SliverAnimatedOpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("opacity"), opacity));
}

void _SliverAnimatedOpacityStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _opacity = as<Tween<double>>(visitor(_opacity, widget()->opacity, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
}

void _SliverAnimatedOpacityStateCls::didUpdateTweens() {
    _opacityAnimation = animation()->drive(_opacity!);
}

Widget _SliverAnimatedOpacityStateCls::build(BuildContext context) {
    return make<SliverFadeTransitionCls>(_opacityAnimation, widget()->sliver, widget()->alwaysIncludeSemantics);
}

AnimatedDefaultTextStyleCls::AnimatedDefaultTextStyleCls(Widget child, Curve curve, Duration duration, Key key, int maxLines, VoidCallback onEnd, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis) {
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
    properties->add(<TextAlign>make<EnumPropertyCls>(__s("textAlign"), textAlign, nullptr));
    properties->add(make<FlagPropertyCls>(__s("softWrap"), softWrap, __s("wrapping at box width"), __s("no wrapping except at line break characters"), true));
    properties->add(<TextOverflow>make<EnumPropertyCls>(__s("overflow"), overflow, nullptr));
    properties->add(make<IntPropertyCls>(__s("maxLines"), maxLines, nullptr));
    properties->add(<TextWidthBasis>make<EnumPropertyCls>(__s("textWidthBasis"), textWidthBasis, TextWidthBasisCls::parent));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>(__s("textHeightBehavior"), textHeightBehavior, nullptr));
}

void _AnimatedDefaultTextStyleStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _style = as<TextStyleTween>(visitor(_style, widget()->style, [=] (Object value) {
        make<TextStyleTweenCls>(as<TextStyle>(value));
    }));
}

Widget _AnimatedDefaultTextStyleStateCls::build(BuildContext context) {
    return make<DefaultTextStyleCls>(_style!->evaluate(animation()), widget()->textAlign, widget()->softWrap, widget()->overflow, widget()->maxLines, widget()->textWidthBasis, widget()->textHeightBehavior, widget()->child);
}

AnimatedPhysicalModelCls::AnimatedPhysicalModelCls(bool animateColor, bool animateShadowColor, BorderRadius borderRadius, Widget child, Clip clipBehavior, Color color, Curve curve, Duration duration, double elevation, Key key, VoidCallback onEnd, Color shadowColor, BoxShape shape) {
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
    properties->add(<BoxShape>make<EnumPropertyCls>(__s("shape"), shape));
    properties->add(<BorderRadius>make<DiagnosticsPropertyCls>(__s("borderRadius"), borderRadius));
    properties->add(make<DoublePropertyCls>(__s("elevation"), elevation));
    properties->add(make<ColorPropertyCls>(__s("color"), color));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("animateColor"), animateColor));
    properties->add(make<ColorPropertyCls>(__s("shadowColor"), shadowColor));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("animateShadowColor"), animateShadowColor));
}

void _AnimatedPhysicalModelStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _borderRadius = as<BorderRadiusTween>(visitor(_borderRadius, widget()->borderRadius, [=] (Object value) {
        make<BorderRadiusTweenCls>(as<BorderRadius>(value));
    }));
    _elevation = as<Tween<double>>(visitor(_elevation, widget()->elevation, [=] (Object value) {
        <double>make<TweenCls>(as<double>(value));
    }));
    _color = as<ColorTween>(visitor(_color, widget()->color, [=] (Object value) {
        make<ColorTweenCls>(as<Color>(value));
    }));
    _shadowColor = as<ColorTween>(visitor(_shadowColor, widget()->shadowColor, [=] (Object value) {
        make<ColorTweenCls>(as<Color>(value));
    }));
}

Widget _AnimatedPhysicalModelStateCls::build(BuildContext context) {
    return make<PhysicalModelCls>(widget()->shape, widget()->clipBehavior, _borderRadius!->evaluate(animation()), _elevation!->evaluate(animation()), widget()->animateColor? _color!->evaluate(animation())! : widget()->color, widget()->animateShadowColor? _shadowColor!->evaluate(animation())! : widget()->shadowColor, widget()->child);
}

AnimatedFractionallySizedBoxCls::AnimatedFractionallySizedBoxCls(AlignmentGeometry alignment, Widget child, Curve curve, Duration duration, double heightFactor, Key key, VoidCallback onEnd, double widthFactor) {
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
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(<double>make<DiagnosticsPropertyCls>(__s("widthFactor"), widthFactor));
    properties->add(<double>make<DiagnosticsPropertyCls>(__s("heightFactor"), heightFactor));
}

void _AnimatedFractionallySizedBoxStateCls::forEachTween(TweenVisitor<Object> visitor) {
    _alignment = as<AlignmentGeometryTween>(visitor(_alignment, widget()->alignment, [=] (Object value) {
        make<AlignmentGeometryTweenCls>(as<AlignmentGeometry>(value));
    }));
    if (widget()->heightFactor != nullptr) {
        _heightFactorTween = as<Tween<double>>(visitor(_heightFactorTween, widget()->heightFactor, [=] (Object value) {
            <double>make<TweenCls>(as<double>(value));
        }));
    }
    if (widget()->widthFactor != nullptr) {
        _widthFactorTween = as<Tween<double>>(visitor(_widthFactorTween, widget()->widthFactor, [=] (Object value) {
            <double>make<TweenCls>(as<double>(value));
        }));
    }
}

Widget _AnimatedFractionallySizedBoxStateCls::build(BuildContext context) {
    return make<FractionallySizedBoxCls>(_alignment!->evaluate(animation())!, _heightFactorTween?->evaluate(animation()), _widthFactorTween?->evaluate(animation()), widget()->child);
}

void _AnimatedFractionallySizedBoxStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<AlignmentGeometryTween>make<DiagnosticsPropertyCls>(__s("alignment"), _alignment, nullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>(__s("widthFactor"), _widthFactorTween, nullptr));
    description->add(<Tween<double>>make<DiagnosticsPropertyCls>(__s("heightFactor"), _heightFactorTween, nullptr));
}
