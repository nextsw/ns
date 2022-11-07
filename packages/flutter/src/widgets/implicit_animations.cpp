#include "implicit_animations.hpp"
BoxConstraints BoxConstraintsTween::lerp(double t) {
    return BoxConstraints.lerp(begin, end, t)!;
}

Decoration DecorationTween::lerp(double t) {
    return Decoration.lerp(begin, end, t)!;
}

EdgeInsets EdgeInsetsTween::lerp(double t) {
    return EdgeInsets.lerp(begin, end, t)!;
}

EdgeInsetsGeometry EdgeInsetsGeometryTween::lerp(double t) {
    return EdgeInsetsGeometry.lerp(begin, end, t)!;
}

BorderRadius BorderRadiusTween::lerp(double t) {
    return BorderRadius.lerp(begin, end, t);
}

Border BorderTween::lerp(double t) {
    return Border.lerp(begin, end, t);
}

Matrix4 Matrix4Tween::lerp(double t) {
    assert(begin != nullptr);
    assert(end != nullptr);
    Vector3 beginTranslation = Vector3.zero();
    Vector3 endTranslation = Vector3.zero();
    Quaternion beginRotation = Quaternion.identity();
    Quaternion endRotation = Quaternion.identity();
    Vector3 beginScale = Vector3.zero();
    Vector3 endScale = Vector3.zero();
    begin!.decompose(beginTranslation, beginRotation, beginScale);
    end!.decompose(endTranslation, endRotation, endScale);
    Vector3 lerpTranslation = beginTranslation * (1.0 - t) + endTranslation * t;
    Quaternion lerpRotation = (beginRotation.scaled(1.0 - t) + endRotation.scaled(t)).normalized();
    Vector3 lerpScale = beginScale * (1.0 - t) + endScale * t;
    return Matrix4.compose(lerpTranslation, lerpRotation, lerpScale);
}

TextStyle TextStyleTween::lerp(double t) {
    return TextStyle.lerp(begin, end, t)!;
}

ImplicitlyAnimatedWidget::ImplicitlyAnimatedWidget(Curve curve, Duration duration, Unknown, VoidCallback onEnd) {
    {
        assert(curve != nullptr);
        assert(duration != nullptr);
    }
}

void ImplicitlyAnimatedWidget::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("duration", duration.inMilliseconds"ms"));
}

AnimationController ImplicitlyAnimatedWidgetState::controller() {
    return _controller;
}

Animation<double> ImplicitlyAnimatedWidgetState::animation() {
    return _animation;
}

void ImplicitlyAnimatedWidgetState::initState() {
    super.initState();
    _controller.addStatusListener();
    _constructTweens();
    didUpdateTweens();
}

void ImplicitlyAnimatedWidgetState::didUpdateWidget(T oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.curve != oldWidget.curve) {
        (().dispose();
        _animation = _createCurve();
    }
    _controller.duration = widget.duration;
    if (_constructTweens()) {
        forEachTween();
        ;
        didUpdateTweens();
    }
}

void ImplicitlyAnimatedWidgetState::dispose() {
    (().dispose();
    _controller.dispose();
    super.dispose();
}

void ImplicitlyAnimatedWidgetState::didUpdateTweens() {
}

CurvedAnimation ImplicitlyAnimatedWidgetState::_createCurve() {
    return CurvedAnimation(_controller, widget.curve);
}

bool ImplicitlyAnimatedWidgetState::_shouldAnimateTween(dynamic targetValue, Tween<dynamic> tween) {
    return targetValue != (tween.end ?? tween.begin);
}

void ImplicitlyAnimatedWidgetState::_updateTween(dynamic targetValue, Tween<dynamic> tween) {
    if (tween == nullptr) {
        return;
    }
    ;
}

bool ImplicitlyAnimatedWidgetState::_constructTweens() {
    bool shouldStartAnimation = false;
    forEachTween();
    return shouldStartAnimation;
}

void AnimatedWidgetBaseState::initState() {
    super.initState();
    controller.addListener(_handleAnimationChanged);
}

void AnimatedWidgetBaseState::_handleAnimationChanged() {
    setState();
}

AnimatedContainer::AnimatedContainer(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Unknown, Decoration decoration, Unknown, Decoration foregroundDecoration, double height, Unknown, EdgeInsetsGeometry margin, Unknown, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width) {
    {
        assert(margin == nullptr || margin.isNonNegative);
        assert(padding == nullptr || padding.isNonNegative);
        assert(decoration == nullptr || decoration.debugAssertIsValid());
        assert(constraints == nullptr || constraints.debugAssertIsValid());
        assert(color == nullptr || decoration == nullptr, "Cannot provide both a color and a decoration\nThe color argument is just a shorthand for "decoration: BoxDecoration(color: color)".");
        decoration = decoration ?? (color != nullptr? BoxDecoration(color) : nullptr);
        constraints = (width != nullptr || height != nullptr)? constraints?.tighten(width, height) ?? BoxConstraints.tightFor(width, height) : constraints;
    }
}

AnimatedWidgetBaseState<AnimatedContainer> AnimatedContainer::createState() {
    return _AnimatedContainerState();
}

void AnimatedContainer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignmentfalse, nullptr));
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", paddingnullptr));
    properties.add(<Decoration>DiagnosticsProperty("bg", decorationnullptr));
    properties.add(<Decoration>DiagnosticsProperty("fg", foregroundDecorationnullptr));
    properties.add(<BoxConstraints>DiagnosticsProperty("constraints", constraintsnullptr, false));
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("margin", marginnullptr));
    properties.add(<Matrix4>has("transform", transform));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("transformAlignment", transformAlignmentnullptr));
    properties.add(<Clip>DiagnosticsProperty("clipBehavior", clipBehavior));
}

void _AnimatedContainerState::forEachTween(TweenVisitor<dynamic> visitor) {
    _alignment = (;
    _padding = (;
    _decoration = (;
    _foregroundDecoration = (;
    _constraints = (;
    _margin = (;
    _transform = (;
    _transformAlignment = (;
}

Widget _AnimatedContainerState::build(BuildContext context) {
    Animation<double> animation = this.animation;
    return Container(_alignment?.evaluate(animation), _padding?.evaluate(animation), _decoration?.evaluate(animation), _foregroundDecoration?.evaluate(animation), _constraints?.evaluate(animation), _margin?.evaluate(animation), _transform?.evaluate(animation), _transformAlignment?.evaluate(animation), widget.clipBehavior, widget.child);
}

void _AnimatedContainerState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<AlignmentGeometryTween>DiagnosticsProperty("alignment", _alignmentfalse, nullptr));
    description.add(<EdgeInsetsGeometryTween>DiagnosticsProperty("padding", _paddingnullptr));
    description.add(<DecorationTween>DiagnosticsProperty("bg", _decorationnullptr));
    description.add(<DecorationTween>DiagnosticsProperty("fg", _foregroundDecorationnullptr));
    description.add(<BoxConstraintsTween>DiagnosticsProperty("constraints", _constraintsfalse, nullptr));
    description.add(<EdgeInsetsGeometryTween>DiagnosticsProperty("margin", _marginnullptr));
    description.add(<Matrix4Tween>has("transform", _transform));
    description.add(<AlignmentGeometryTween>DiagnosticsProperty("transformAlignment", _transformAlignmentnullptr));
}

AnimatedPadding::AnimatedPadding(Widget child, Unknown, Unknown, Unknown, Unknown, EdgeInsetsGeometry padding) {
    {
        assert(padding != nullptr);
        assert(padding.isNonNegative);
    }
}

AnimatedWidgetBaseState<AnimatedPadding> AnimatedPadding::createState() {
    return _AnimatedPaddingState();
}

void AnimatedPadding::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", padding));
}

void _AnimatedPaddingState::forEachTween(TweenVisitor<dynamic> visitor) {
    _padding = (;
}

Widget _AnimatedPaddingState::build(BuildContext context) {
    return Padding(_padding!.evaluate(animation).clamp(EdgeInsets.zero, EdgeInsetsGeometry.infinity), widget.child);
}

void _AnimatedPaddingState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<EdgeInsetsGeometryTween>DiagnosticsProperty("padding", _paddingnullptr));
}

AnimatedAlign::AnimatedAlign(AlignmentGeometry alignment, Widget child, Unknown, Unknown, double heightFactor, Unknown, Unknown, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

AnimatedWidgetBaseState<AnimatedAlign> AnimatedAlign::createState() {
    return _AnimatedAlignState();
}

void AnimatedAlign::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
}

void _AnimatedAlignState::forEachTween(TweenVisitor<dynamic> visitor) {
    _alignment = (;
    if (widget.heightFactor != nullptr) {
        _heightFactorTween = (;
    }
    if (widget.widthFactor != nullptr) {
        _widthFactorTween = (;
    }
}

Widget _AnimatedAlignState::build(BuildContext context) {
    return Align(_alignment!.evaluate(animation)!, _heightFactorTween?.evaluate(animation), _widthFactorTween?.evaluate(animation), widget.child);
}

void _AnimatedAlignState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<AlignmentGeometryTween>DiagnosticsProperty("alignment", _alignmentnullptr));
    description.add(<Tween<double>>DiagnosticsProperty("widthFactor", _widthFactorTweennullptr));
    description.add(<Tween<double>>DiagnosticsProperty("heightFactor", _heightFactorTweennullptr));
}

AnimatedPositioned::AnimatedPositioned(double bottom, Widget child, Unknown, Unknown, double height, Unknown, double left, Unknown, double right, double top, double width) {
    {
        assert(left == nullptr || right == nullptr || width == nullptr);
        assert(top == nullptr || bottom == nullptr || height == nullptr);
    }
}

void AnimatedPositioned::fromRect(Widget child, Unknown, Unknown, Unknown, Unknown, Rect rect)

AnimatedWidgetBaseState<AnimatedPositioned> AnimatedPositioned::createState() {
    return _AnimatedPositionedState();
}

void AnimatedPositioned::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("left", leftnullptr));
    properties.add(DoubleProperty("top", topnullptr));
    properties.add(DoubleProperty("right", rightnullptr));
    properties.add(DoubleProperty("bottom", bottomnullptr));
    properties.add(DoubleProperty("width", widthnullptr));
    properties.add(DoubleProperty("height", heightnullptr));
}

void _AnimatedPositionedState::forEachTween(TweenVisitor<dynamic> visitor) {
    _left = (;
    _top = (;
    _right = (;
    _bottom = (;
    _width = (;
    _height = (;
}

Widget _AnimatedPositionedState::build(BuildContext context) {
    return Positioned(_left?.evaluate(animation), _top?.evaluate(animation), _right?.evaluate(animation), _bottom?.evaluate(animation), _width?.evaluate(animation), _height?.evaluate(animation), widget.child);
}

void _AnimatedPositionedState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<Tween<double>>has("left", _left));
    description.add(<Tween<double>>has("top", _top));
    description.add(<Tween<double>>has("right", _right));
    description.add(<Tween<double>>has("bottom", _bottom));
    description.add(<Tween<double>>has("width", _width));
    description.add(<Tween<double>>has("height", _height));
}

AnimatedPositionedDirectional::AnimatedPositionedDirectional(double bottom, Widget child, Unknown, Unknown, double end, double height, Unknown, Unknown, double start, double top, double width) {
    {
        assert(start == nullptr || end == nullptr || width == nullptr);
        assert(top == nullptr || bottom == nullptr || height == nullptr);
    }
}

AnimatedWidgetBaseState<AnimatedPositionedDirectional> AnimatedPositionedDirectional::createState() {
    return _AnimatedPositionedDirectionalState();
}

void AnimatedPositionedDirectional::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("start", startnullptr));
    properties.add(DoubleProperty("top", topnullptr));
    properties.add(DoubleProperty("end", endnullptr));
    properties.add(DoubleProperty("bottom", bottomnullptr));
    properties.add(DoubleProperty("width", widthnullptr));
    properties.add(DoubleProperty("height", heightnullptr));
}

void _AnimatedPositionedDirectionalState::forEachTween(TweenVisitor<dynamic> visitor) {
    _start = (;
    _top = (;
    _end = (;
    _bottom = (;
    _width = (;
    _height = (;
}

Widget _AnimatedPositionedDirectionalState::build(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    return Positioned.directional(Directionality.of(context), _start?.evaluate(animation), _top?.evaluate(animation), _end?.evaluate(animation), _bottom?.evaluate(animation), _width?.evaluate(animation), _height?.evaluate(animation), widget.child);
}

void _AnimatedPositionedDirectionalState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<Tween<double>>has("start", _start));
    description.add(<Tween<double>>has("top", _top));
    description.add(<Tween<double>>has("end", _end));
    description.add(<Tween<double>>has("bottom", _bottom));
    description.add(<Tween<double>>has("width", _width));
    description.add(<Tween<double>>has("height", _height));
}

AnimatedScale::AnimatedScale(Alignment alignment, Widget child, Unknown, Unknown, FilterQuality filterQuality, Unknown, Unknown, double scale) {
    {
        assert(scale != nullptr);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedScale> AnimatedScale::createState() {
    return _AnimatedScaleState();
}

void AnimatedScale::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("scale", scale));
    properties.add(<Alignment>DiagnosticsProperty("alignment", alignmentAlignment.center));
    properties.add(<FilterQuality>EnumProperty("filterQuality", filterQualitynullptr));
}

void _AnimatedScaleState::forEachTween(TweenVisitor<dynamic> visitor) {
    _scale = (;
}

void _AnimatedScaleState::didUpdateTweens() {
    _scaleAnimation = animation.drive(_scale!);
}

Widget _AnimatedScaleState::build(BuildContext context) {
    return ScaleTransition(_scaleAnimation, widget.alignment, widget.filterQuality, widget.child);
}

AnimatedRotation::AnimatedRotation(Alignment alignment, Widget child, Unknown, Unknown, FilterQuality filterQuality, Unknown, Unknown, double turns) {
    {
        assert(turns != nullptr);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedRotation> AnimatedRotation::createState() {
    return _AnimatedRotationState();
}

void AnimatedRotation::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("turns", turns));
    properties.add(<Alignment>DiagnosticsProperty("alignment", alignmentAlignment.center));
    properties.add(<FilterQuality>EnumProperty("filterQuality", filterQualitynullptr));
}

void _AnimatedRotationState::forEachTween(TweenVisitor<dynamic> visitor) {
    _turns = (;
}

void _AnimatedRotationState::didUpdateTweens() {
    _turnsAnimation = animation.drive(_turns!);
}

Widget _AnimatedRotationState::build(BuildContext context) {
    return RotationTransition(_turnsAnimation, widget.alignment, widget.filterQuality, widget.child);
}

ImplicitlyAnimatedWidgetState<AnimatedSlide> AnimatedSlide::createState() {
    return _AnimatedSlideState();
}

void AnimatedSlide::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("offset", offset));
}

void _AnimatedSlideState::forEachTween(TweenVisitor<dynamic> visitor) {
    _offset = (;
}

void _AnimatedSlideState::didUpdateTweens() {
    _offsetAnimation = animation.drive(_offset!);
}

Widget _AnimatedSlideState::build(BuildContext context) {
    return SlideTransition(_offsetAnimation, widget.child);
}

AnimatedOpacity::AnimatedOpacity(bool alwaysIncludeSemantics, Widget child, Unknown, Unknown, Unknown, Unknown, double opacity) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
    }
}

ImplicitlyAnimatedWidgetState<AnimatedOpacity> AnimatedOpacity::createState() {
    return _AnimatedOpacityState();
}

void AnimatedOpacity::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("opacity", opacity));
}

void _AnimatedOpacityState::forEachTween(TweenVisitor<dynamic> visitor) {
    _opacity = (;
}

void _AnimatedOpacityState::didUpdateTweens() {
    _opacityAnimation = animation.drive(_opacity!);
}

Widget _AnimatedOpacityState::build(BuildContext context) {
    return FadeTransition(_opacityAnimation, widget.alwaysIncludeSemantics, widget.child);
}

SliverAnimatedOpacity::SliverAnimatedOpacity(bool alwaysIncludeSemantics, Unknown, Unknown, Unknown, Unknown, double opacity, Widget sliver) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
    }
}

ImplicitlyAnimatedWidgetState<SliverAnimatedOpacity> SliverAnimatedOpacity::createState() {
    return _SliverAnimatedOpacityState();
}

void SliverAnimatedOpacity::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("opacity", opacity));
}

void _SliverAnimatedOpacityState::forEachTween(TweenVisitor<dynamic> visitor) {
    _opacity = (;
}

void _SliverAnimatedOpacityState::didUpdateTweens() {
    _opacityAnimation = animation.drive(_opacity!);
}

Widget _SliverAnimatedOpacityState::build(BuildContext context) {
    return SliverFadeTransition(_opacityAnimation, widget.sliver, widget.alwaysIncludeSemantics);
}

AnimatedDefaultTextStyle::AnimatedDefaultTextStyle(Widget child, Unknown, Unknown, Unknown, int maxLines, Unknown, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis) {
    {
        assert(style != nullptr);
        assert(child != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(textWidthBasis != nullptr);
    }
}

AnimatedWidgetBaseState<AnimatedDefaultTextStyle> AnimatedDefaultTextStyle::createState() {
    return _AnimatedDefaultTextStyleState();
}

void AnimatedDefaultTextStyle::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    style.debugFillProperties(properties);
    properties.add(<TextAlign>EnumProperty("textAlign", textAlignnullptr));
    properties.add(FlagProperty("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties.add(<TextOverflow>EnumProperty("overflow", overflownullptr));
    properties.add(IntProperty("maxLines", maxLinesnullptr));
    properties.add(<TextWidthBasis>EnumProperty("textWidthBasis", textWidthBasisTextWidthBasis.parent));
    properties.add(<TextHeightBehavior>DiagnosticsProperty("textHeightBehavior", textHeightBehaviornullptr));
}

void _AnimatedDefaultTextStyleState::forEachTween(TweenVisitor<dynamic> visitor) {
    _style = (;
}

Widget _AnimatedDefaultTextStyleState::build(BuildContext context) {
    return DefaultTextStyle(_style!.evaluate(animation), widget.textAlign, widget.softWrap, widget.overflow, widget.maxLines, widget.textWidthBasis, widget.textHeightBehavior, widget.child);
}

AnimatedPhysicalModel::AnimatedPhysicalModel(bool animateColor, bool animateShadowColor, BorderRadius borderRadius, Widget child, Clip clipBehavior, Color color, Unknown, Unknown, double elevation, Unknown, Unknown, Color shadowColor, BoxShape shape) {
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

AnimatedWidgetBaseState<AnimatedPhysicalModel> AnimatedPhysicalModel::createState() {
    return _AnimatedPhysicalModelState();
}

void AnimatedPhysicalModel::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BoxShape>EnumProperty("shape", shape));
    properties.add(<BorderRadius>DiagnosticsProperty("borderRadius", borderRadius));
    properties.add(DoubleProperty("elevation", elevation));
    properties.add(ColorProperty("color", color));
    properties.add(<bool>DiagnosticsProperty("animateColor", animateColor));
    properties.add(ColorProperty("shadowColor", shadowColor));
    properties.add(<bool>DiagnosticsProperty("animateShadowColor", animateShadowColor));
}

void _AnimatedPhysicalModelState::forEachTween(TweenVisitor<dynamic> visitor) {
    _borderRadius = (;
    _elevation = (;
    _color = (;
    _shadowColor = (;
}

Widget _AnimatedPhysicalModelState::build(BuildContext context) {
    return PhysicalModel(widget.shape, widget.clipBehavior, _borderRadius!.evaluate(animation), _elevation!.evaluate(animation), widget.animateColor? _color!.evaluate(animation)! : widget.color, widget.animateShadowColor? _shadowColor!.evaluate(animation)! : widget.shadowColor, widget.child);
}

AnimatedFractionallySizedBox::AnimatedFractionallySizedBox(AlignmentGeometry alignment, Widget child, Unknown, Unknown, double heightFactor, Unknown, Unknown, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

AnimatedWidgetBaseState<AnimatedFractionallySizedBox> AnimatedFractionallySizedBox::createState() {
    return _AnimatedFractionallySizedBoxState();
}

void AnimatedFractionallySizedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<double>DiagnosticsProperty("widthFactor", widthFactor));
    properties.add(<double>DiagnosticsProperty("heightFactor", heightFactor));
}

void _AnimatedFractionallySizedBoxState::forEachTween(TweenVisitor<dynamic> visitor) {
    _alignment = (;
    if (widget.heightFactor != nullptr) {
        _heightFactorTween = (;
    }
    if (widget.widthFactor != nullptr) {
        _widthFactorTween = (;
    }
}

Widget _AnimatedFractionallySizedBoxState::build(BuildContext context) {
    return FractionallySizedBox(_alignment!.evaluate(animation)!, _heightFactorTween?.evaluate(animation), _widthFactorTween?.evaluate(animation), widget.child);
}

void _AnimatedFractionallySizedBoxState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<AlignmentGeometryTween>DiagnosticsProperty("alignment", _alignmentnullptr));
    description.add(<Tween<double>>DiagnosticsProperty("widthFactor", _widthFactorTweennullptr));
    description.add(<Tween<double>>DiagnosticsProperty("heightFactor", _heightFactorTweennullptr));
}
