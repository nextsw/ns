#include "basic.hpp"
void _UbiquitousInheritedElement::setDependencies(Element dependent, Object value) {
    assert(value == nullptr);
}

Object _UbiquitousInheritedElement::getDependencies(Element dependent) {
    return nullptr;
}

void _UbiquitousInheritedElement::notifyClients(InheritedWidget oldWidget) {
    _recurseChildren(this, );
}

void _UbiquitousInheritedElement::_recurseChildren(Element element, ElementVisitor visitor) {
    element.visitChildren();
    visitor(element);
}

InheritedElement _UbiquitousInheritedWidget::createElement() {
    return _UbiquitousInheritedElement(this);
}

Directionality::Directionality(Unknown, Unknown, TextDirection textDirection) {
    {
        assert(textDirection != nullptr);
        assert(child != nullptr);
    }
}

TextDirection Directionality::of(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    Directionality widget = context.<Directionality>dependOnInheritedWidgetOfExactType()!;
    return widget.textDirection;
}

TextDirection Directionality::maybeOf(BuildContext context) {
    Directionality widget = context.<Directionality>dependOnInheritedWidgetOfExactType();
    return widget?.textDirection;
}

bool Directionality::updateShouldNotify(Directionality oldWidget) {
    return textDirection != oldWidget.textDirection;
}

void Directionality::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TextDirection>EnumProperty("textDirection", textDirection));
}

Opacity::Opacity(bool alwaysIncludeSemantics, Unknown, Unknown, double opacity) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
    }
}

RenderOpacity Opacity::createRenderObject(BuildContext context) {
    return RenderOpacity(opacity, alwaysIncludeSemantics);
}

void Opacity::updateRenderObject(BuildContext context, RenderOpacity renderObject) {
    ;
}

void Opacity::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("opacity", opacity));
    properties.add(FlagProperty("alwaysIncludeSemantics"alwaysIncludeSemantics, "alwaysIncludeSemantics"));
}

ShaderMask::ShaderMask(BlendMode blendMode, Unknown, Unknown, ShaderCallback shaderCallback) {
    {
        assert(shaderCallback != nullptr);
        assert(blendMode != nullptr);
    }
}

RenderShaderMask ShaderMask::createRenderObject(BuildContext context) {
    return RenderShaderMask(shaderCallback, blendMode);
}

void ShaderMask::updateRenderObject(BuildContext context, RenderShaderMask renderObject) {
    ;
}

BackdropFilter::BackdropFilter(BlendMode blendMode, Unknown, ImageFilter filter, Unknown) {
    {
        assert(filter != nullptr);
    }
}

RenderBackdropFilter BackdropFilter::createRenderObject(BuildContext context) {
    return RenderBackdropFilter(filter, blendMode);
}

void BackdropFilter::updateRenderObject(BuildContext context, RenderBackdropFilter renderObject) {
    ;
}

CustomPaint::CustomPaint(Unknown, CustomPainter foregroundPainter, bool isComplex, Unknown, CustomPainter painter, Size size, bool willChange) {
    {
        assert(size != nullptr);
        assert(isComplex != nullptr);
        assert(willChange != nullptr);
        assert(painter != nullptr || foregroundPainter != nullptr || (!isComplex && !willChange));
    }
}

RenderCustomPaint CustomPaint::createRenderObject(BuildContext context) {
    return RenderCustomPaint(painter, foregroundPainter, size, isComplex, willChange);
}

void CustomPaint::updateRenderObject(BuildContext context, RenderCustomPaint renderObject) {
    ;
}

void CustomPaint::didUnmountRenderObject(RenderCustomPaint renderObject) {
    ;
}

ClipRect::ClipRect(Unknown, Clip clipBehavior, CustomClipper<Rect> clipper, Unknown) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderClipRect ClipRect::createRenderObject(BuildContext context) {
    return RenderClipRect(clipper, clipBehavior);
}

void ClipRect::updateRenderObject(BuildContext context, RenderClipRect renderObject) {
    ;
}

void ClipRect::didUnmountRenderObject(RenderClipRect renderObject) {
    renderObject.clipper = nullptr;
}

void ClipRect::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<CustomClipper<Rect>>DiagnosticsProperty("clipper", clippernullptr));
}

ClipRRect::ClipRRect(BorderRadiusGeometry borderRadius, Unknown, Clip clipBehavior, CustomClipper<RRect> clipper, Unknown) {
    {
        assert(borderRadius != nullptr || clipper != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderClipRRect ClipRRect::createRenderObject(BuildContext context) {
    return RenderClipRRect(borderRadius!, clipper, clipBehavior, Directionality.maybeOf(context));
}

void ClipRRect::updateRenderObject(BuildContext context, RenderClipRRect renderObject) {
    ;
}

void ClipRRect::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BorderRadiusGeometry>DiagnosticsProperty("borderRadius", borderRadiusfalse, nullptr));
    properties.add(<CustomClipper<RRect>>DiagnosticsProperty("clipper", clippernullptr));
}

ClipOval::ClipOval(Unknown, Clip clipBehavior, CustomClipper<Rect> clipper, Unknown) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderClipOval ClipOval::createRenderObject(BuildContext context) {
    return RenderClipOval(clipper, clipBehavior);
}

void ClipOval::updateRenderObject(BuildContext context, RenderClipOval renderObject) {
    ;
}

void ClipOval::didUnmountRenderObject(RenderClipOval renderObject) {
    renderObject.clipper = nullptr;
}

void ClipOval::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<CustomClipper<Rect>>DiagnosticsProperty("clipper", clippernullptr));
}

ClipPath::ClipPath(Unknown, Clip clipBehavior, CustomClipper<Path> clipper, Unknown) {
    {
        assert(clipBehavior != nullptr);
    }
}

Widget ClipPath::shape(Widget child, Clip clipBehavior, Key key, ShapeBorder shape) {
    assert(clipBehavior != nullptr);
    assert(shape != nullptr);
    return Builder(key, );
}

RenderClipPath ClipPath::createRenderObject(BuildContext context) {
    return RenderClipPath(clipper, clipBehavior);
}

void ClipPath::updateRenderObject(BuildContext context, RenderClipPath renderObject) {
    ;
}

void ClipPath::didUnmountRenderObject(RenderClipPath renderObject) {
    renderObject.clipper = nullptr;
}

void ClipPath::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<CustomClipper<Path>>DiagnosticsProperty("clipper", clippernullptr));
}

PhysicalModel::PhysicalModel(BorderRadius borderRadius, Unknown, Clip clipBehavior, Color color, double elevation, Unknown, Color shadowColor, BoxShape shape) {
    {
        assert(shape != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderPhysicalModel PhysicalModel::createRenderObject(BuildContext context) {
    return RenderPhysicalModel(shape, clipBehavior, borderRadius, elevation, color, shadowColor);
}

void PhysicalModel::updateRenderObject(BuildContext context, RenderPhysicalModel renderObject) {
    ;
}

void PhysicalModel::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BoxShape>EnumProperty("shape", shape));
    properties.add(<BorderRadius>DiagnosticsProperty("borderRadius", borderRadius));
    properties.add(DoubleProperty("elevation", elevation));
    properties.add(ColorProperty("color", color));
    properties.add(ColorProperty("shadowColor", shadowColor));
}

PhysicalShape::PhysicalShape(Unknown, Clip clipBehavior, CustomClipper<Path> clipper, Color color, double elevation, Unknown, Color shadowColor) {
    {
        assert(clipper != nullptr);
        assert(clipBehavior != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
    }
}

RenderPhysicalShape PhysicalShape::createRenderObject(BuildContext context) {
    return RenderPhysicalShape(clipper, clipBehavior, elevation, color, shadowColor);
}

void PhysicalShape::updateRenderObject(BuildContext context, RenderPhysicalShape renderObject) {
    ;
}

void PhysicalShape::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<CustomClipper<Path>>DiagnosticsProperty("clipper", clipper));
    properties.add(DoubleProperty("elevation", elevation));
    properties.add(ColorProperty("color", color));
    properties.add(ColorProperty("shadowColor", shadowColor));
}

Transform::Transform(AlignmentGeometry alignment, Unknown, FilterQuality filterQuality, Unknown, Offset origin, Matrix4 transform, bool transformHitTests) {
    {
        assert(transform != nullptr);
    }
}

void Transform::rotate(AlignmentGeometry alignment, double angle, Unknown, FilterQuality filterQuality, Unknown, Offset origin, bool transformHitTests)

void Transform::translate(Unknown, FilterQuality filterQuality, Unknown, Offset offset, bool transformHitTests)

void Transform::scale(AlignmentGeometry alignment, Unknown, FilterQuality filterQuality, Unknown, Offset origin, double scale, double scaleX, double scaleY, bool transformHitTests)

RenderTransform Transform::createRenderObject(BuildContext context) {
    return RenderTransform(transform, origin, alignment, Directionality.maybeOf(context), transformHitTests, filterQuality);
}

void Transform::updateRenderObject(BuildContext context, RenderTransform renderObject) {
    ;
}

Matrix4 Transform::_computeRotation(double radians) {
    assert(radians.isFinite, "Cannot compute the rotation matrix for a non-finite angle: $radians");
    if (radians == 0.0) {
        return Matrix4.identity();
    }
    double sin = math.sin(radians);
    if (sin == 1.0) {
        return _createZRotation(1.0, 0.0);
    }
    if (sin == -1.0) {
        return _createZRotation(-1.0, 0.0);
    }
    double cos = math.cos(radians);
    if (cos == -1.0) {
        return _createZRotation(0.0, -1.0);
    }
    return _createZRotation(sin, cos);
}

Matrix4 Transform::_createZRotation(double cos, double sin) {
    Matrix4 result = Matrix4.zero();
    result.storage[0] = cos;
    result.storage[1] = sin;
    result.storage[4] = -sin;
    result.storage[5] = cos;
    result.storage[10] = 1.0;
    result.storage[15] = 1.0;
    return result;
}

CompositedTransformTarget::CompositedTransformTarget(Unknown, Unknown, LayerLink link) {
    {
        assert(link != nullptr);
    }
}

RenderLeaderLayer CompositedTransformTarget::createRenderObject(BuildContext context) {
    return RenderLeaderLayer(link);
}

void CompositedTransformTarget::updateRenderObject(BuildContext context, RenderLeaderLayer renderObject) {
    renderObject.link = link;
}

CompositedTransformFollower::CompositedTransformFollower(Unknown, Alignment followerAnchor, Unknown, LayerLink link, Offset offset, bool showWhenUnlinked, Alignment targetAnchor) {
    {
        assert(link != nullptr);
        assert(showWhenUnlinked != nullptr);
        assert(offset != nullptr);
        assert(targetAnchor != nullptr);
        assert(followerAnchor != nullptr);
    }
}

RenderFollowerLayer CompositedTransformFollower::createRenderObject(BuildContext context) {
    return RenderFollowerLayer(link, showWhenUnlinked, offset, targetAnchor, followerAnchor);
}

void CompositedTransformFollower::updateRenderObject(BuildContext context, RenderFollowerLayer renderObject) {
    ;
}

FittedBox::FittedBox(AlignmentGeometry alignment, Unknown, Clip clipBehavior, BoxFit fit, Unknown) {
    {
        assert(fit != nullptr);
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderFittedBox FittedBox::createRenderObject(BuildContext context) {
    return RenderFittedBox(fit, alignment, Directionality.maybeOf(context), clipBehavior);
}

void FittedBox::updateRenderObject(BuildContext context, RenderFittedBox renderObject) {
    ;
}

void FittedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BoxFit>EnumProperty("fit", fit));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
}

FractionalTranslation::FractionalTranslation(Unknown, Unknown, bool transformHitTests, Offset translation) {
    {
        assert(translation != nullptr);
    }
}

RenderFractionalTranslation FractionalTranslation::createRenderObject(BuildContext context) {
    return RenderFractionalTranslation(translation, transformHitTests);
}

void FractionalTranslation::updateRenderObject(BuildContext context, RenderFractionalTranslation renderObject) {
    ;
}

RotatedBox::RotatedBox(Unknown, Unknown, int quarterTurns) {
    {
        assert(quarterTurns != nullptr);
    }
}

RenderRotatedBox RotatedBox::createRenderObject(BuildContext context) {
    return RenderRotatedBox(quarterTurns);
}

void RotatedBox::updateRenderObject(BuildContext context, RenderRotatedBox renderObject) {
    renderObject.quarterTurns = quarterTurns;
}

Padding::Padding(Unknown, Unknown, EdgeInsetsGeometry padding) {
    {
        assert(padding != nullptr);
    }
}

RenderPadding Padding::createRenderObject(BuildContext context) {
    return RenderPadding(padding, Directionality.maybeOf(context));
}

void Padding::updateRenderObject(BuildContext context, RenderPadding renderObject) {
    ;
}

void Padding::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", padding));
}

Align::Align(AlignmentGeometry alignment, Unknown, double heightFactor, Unknown, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

RenderPositionedBox Align::createRenderObject(BuildContext context) {
    return RenderPositionedBox(alignment, widthFactor, heightFactor, Directionality.maybeOf(context));
}

void Align::updateRenderObject(BuildContext context, RenderPositionedBox renderObject) {
    ;
}

void Align::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(DoubleProperty("widthFactor", widthFactornullptr));
    properties.add(DoubleProperty("heightFactor", heightFactornullptr));
}

CustomSingleChildLayout::CustomSingleChildLayout(Unknown, SingleChildLayoutDelegate delegate, Unknown) {
    {
        assert(delegate != nullptr);
    }
}

RenderCustomSingleChildLayoutBox CustomSingleChildLayout::createRenderObject(BuildContext context) {
    return RenderCustomSingleChildLayoutBox(delegate);
}

void CustomSingleChildLayout::updateRenderObject(BuildContext context, RenderCustomSingleChildLayoutBox renderObject) {
    renderObject.delegate = delegate;
}

LayoutId::LayoutId(Unknown, Object id, Key key) {
    {
        assert(child != nullptr);
        assert(id != nullptr);
        super(key ?? <Object>ValueKey(id));
    }
}

void LayoutId::applyParentData(RenderObject renderObject) {
    assert(renderObject.parentData is MultiChildLayoutParentData);
    MultiChildLayoutParentData parentData = (;
    if (parentData.id != id) {
        parentData.id = id;
        AbstractNode targetParent = renderObject.parent;
        if (targetParent is RenderObject) {
            targetParent.markNeedsLayout();
        }
    }
}

Type LayoutId::debugTypicalAncestorWidgetClass() {
    return CustomMultiChildLayout;
}

void LayoutId::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Object>DiagnosticsProperty("id", id));
}

CustomMultiChildLayout::CustomMultiChildLayout(Unknown, MultiChildLayoutDelegate delegate, Unknown) {
    {
        assert(delegate != nullptr);
    }
}

RenderCustomMultiChildLayoutBox CustomMultiChildLayout::createRenderObject(BuildContext context) {
    return RenderCustomMultiChildLayoutBox(delegate);
}

void CustomMultiChildLayout::updateRenderObject(BuildContext context, RenderCustomMultiChildLayoutBox renderObject) {
    renderObject.delegate = delegate;
}

void SizedBox::expand(Unknown, Unknown)

void SizedBox::shrink(Unknown, Unknown)

void SizedBox::fromSize(Unknown, Unknown, Size size)

void SizedBox::square(Unknown, double dimension, Unknown)

RenderConstrainedBox SizedBox::createRenderObject(BuildContext context) {
    return RenderConstrainedBox(_additionalConstraints);
}

void SizedBox::updateRenderObject(BuildContext context, RenderConstrainedBox renderObject) {
    renderObject.additionalConstraints = _additionalConstraints;
}

String SizedBox::toStringShort() {
    String type;
    if (width == double.infinity && height == double.infinity) {
        type = "${objectRuntimeType(this, 'SizedBox')}.expand";
    } else     {
        if (width == 0.0 && height == 0.0) {
        type = "${objectRuntimeType(this, 'SizedBox')}.shrink";
    } else {
        type = objectRuntimeType(this, "SizedBox");
    }
;
    }    return key == nullptr? type : "$type-$key";
}

void SizedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    DiagnosticLevel level;
    if ((width == double.infinity && height == double.infinity) || (width == 0.0 && height == 0.0)) {
        level = DiagnosticLevel.hidden;
    } else {
        level = DiagnosticLevel.info;
    }
    properties.add(DoubleProperty("width", widthnullptr, level));
    properties.add(DoubleProperty("height", heightnullptr, level));
}

BoxConstraints SizedBox::_additionalConstraints() {
    return BoxConstraints.tightFor(width, height);
}

ConstrainedBox::ConstrainedBox(Unknown, BoxConstraints constraints, Unknown) {
    {
        assert(constraints != nullptr);
        assert(constraints.debugAssertIsValid());
    }
}

RenderConstrainedBox ConstrainedBox::createRenderObject(BuildContext context) {
    return RenderConstrainedBox(constraints);
}

void ConstrainedBox::updateRenderObject(BuildContext context, RenderConstrainedBox renderObject) {
    renderObject.additionalConstraints = constraints;
}

void ConstrainedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BoxConstraints>DiagnosticsProperty("constraints", constraintsfalse));
}

ConstraintsTransformBox::ConstraintsTransformBox(AlignmentGeometry alignment, Unknown, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, String debugTransformType, Unknown, TextDirection textDirection) {
    {
        _debugTransformLabel = debugTransformType;
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        assert(constraintsTransform != nullptr);
        assert(debugTransformType != nullptr);
    }
}

BoxConstraints ConstraintsTransformBox::unmodified(BoxConstraints constraints) {
    return constraints;
}

BoxConstraints ConstraintsTransformBox::unconstrained(BoxConstraints constraints) {
    return const BoxConstraints();
}

BoxConstraints ConstraintsTransformBox::widthUnconstrained(BoxConstraints constraints) {
    return constraints.heightConstraints();
}

BoxConstraints ConstraintsTransformBox::heightUnconstrained(BoxConstraints constraints) {
    return constraints.widthConstraints();
}

BoxConstraints ConstraintsTransformBox::maxHeightUnconstrained(BoxConstraints constraints) {
    return constraints.copyWith(double.infinity);
}

BoxConstraints ConstraintsTransformBox::maxWidthUnconstrained(BoxConstraints constraints) {
    return constraints.copyWith(double.infinity);
}

BoxConstraints ConstraintsTransformBox::maxUnconstrained(BoxConstraints constraints) {
    return constraints.copyWith(double.infinity, double.infinity);
}

RenderConstraintsTransformBox ConstraintsTransformBox::createRenderObject(BuildContext context) {
    return RenderConstraintsTransformBox(textDirection ?? Directionality.maybeOf(context), alignment, constraintsTransform, clipBehavior);
}

void ConstraintsTransformBox::updateRenderObject(BuildContext context, RenderConstraintsTransformBox renderObject) {
    ;
}

void ConstraintsTransformBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    String debugTransformLabel = _debugTransformLabel.isNotEmpty? _debugTransformLabel : _debugKnownTransforms[constraintsTransform];
    if (debugTransformLabel != nullptr) {
        properties.add(<String>DiagnosticsProperty("constraints transform", debugTransformLabel));
    }
}

UnconstrainedBox::UnconstrainedBox(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Axis constrainedAxis, Unknown, TextDirection textDirection) {
    {
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
    }
}

Widget UnconstrainedBox::build(BuildContext context) {
    return ConstraintsTransformBox(textDirection, alignment, clipBehavior, _axisToTransform(constrainedAxis), child);
}

void UnconstrainedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<Axis>EnumProperty("constrainedAxis", constrainedAxisnullptr));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
}

BoxConstraintsTransform UnconstrainedBox::_axisToTransform(Axis constrainedAxis) {
    if (constrainedAxis != nullptr) {
        ;
    } else {
        return ConstraintsTransformBox.unconstrained;
    }
}

FractionallySizedBox::FractionallySizedBox(AlignmentGeometry alignment, Unknown, double heightFactor, Unknown, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

RenderFractionallySizedOverflowBox FractionallySizedBox::createRenderObject(BuildContext context) {
    return RenderFractionallySizedOverflowBox(alignment, widthFactor, heightFactor, Directionality.maybeOf(context));
}

void FractionallySizedBox::updateRenderObject(BuildContext context, RenderFractionallySizedOverflowBox renderObject) {
    ;
}

void FractionallySizedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(DoubleProperty("widthFactor", widthFactornullptr));
    properties.add(DoubleProperty("heightFactor", heightFactornullptr));
}

LimitedBox::LimitedBox(Unknown, Unknown, double maxHeight, double maxWidth) {
    {
        assert(maxWidth != nullptr && maxWidth >= 0.0);
        assert(maxHeight != nullptr && maxHeight >= 0.0);
    }
}

RenderLimitedBox LimitedBox::createRenderObject(BuildContext context) {
    return RenderLimitedBox(maxWidth, maxHeight);
}

void LimitedBox::updateRenderObject(BuildContext context, RenderLimitedBox renderObject) {
    ;
}

void LimitedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("maxWidth", maxWidthdouble.infinity));
    properties.add(DoubleProperty("maxHeight", maxHeightdouble.infinity));
}

RenderConstrainedOverflowBox OverflowBox::createRenderObject(BuildContext context) {
    return RenderConstrainedOverflowBox(alignment, minWidth, maxWidth, minHeight, maxHeight, Directionality.maybeOf(context));
}

void OverflowBox::updateRenderObject(BuildContext context, RenderConstrainedOverflowBox renderObject) {
    ;
}

void OverflowBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(DoubleProperty("minWidth", minWidthnullptr));
    properties.add(DoubleProperty("maxWidth", maxWidthnullptr));
    properties.add(DoubleProperty("minHeight", minHeightnullptr));
    properties.add(DoubleProperty("maxHeight", maxHeightnullptr));
}

SizedOverflowBox::SizedOverflowBox(AlignmentGeometry alignment, Unknown, Unknown, Size size) {
    {
        assert(size != nullptr);
        assert(alignment != nullptr);
    }
}

RenderSizedOverflowBox SizedOverflowBox::createRenderObject(BuildContext context) {
    return RenderSizedOverflowBox(alignment, size, Directionality.of(context));
}

void SizedOverflowBox::updateRenderObject(BuildContext context, RenderSizedOverflowBox renderObject) {
    ;
}

void SizedOverflowBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<Size>DiagnosticsProperty("size", sizenullptr));
}

Offstage::Offstage(Unknown, Unknown, bool offstage) {
    {
        assert(offstage != nullptr);
    }
}

RenderOffstage Offstage::createRenderObject(BuildContext context) {
    return RenderOffstage(offstage);
}

void Offstage::updateRenderObject(BuildContext context, RenderOffstage renderObject) {
    renderObject.offstage = offstage;
}

void Offstage::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("offstage", offstage));
}

SingleChildRenderObjectElement Offstage::createElement() {
    return _OffstageElement(this);
}

void _OffstageElement::debugVisitOnstageChildren(ElementVisitor visitor) {
    if (!(().offstage) {
        super.debugVisitOnstageChildren(visitor);
    }
}

AspectRatio::AspectRatio(double aspectRatio, Unknown, Unknown) {
    {
        assert(aspectRatio != nullptr);
        assert(aspectRatio > 0.0);
    }
}

RenderAspectRatio AspectRatio::createRenderObject(BuildContext context) {
    return RenderAspectRatio(aspectRatio);
}

void AspectRatio::updateRenderObject(BuildContext context, RenderAspectRatio renderObject) {
    renderObject.aspectRatio = aspectRatio;
}

void AspectRatio::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("aspectRatio", aspectRatio));
}

IntrinsicWidth::IntrinsicWidth(Unknown, Unknown, double stepHeight, double stepWidth) {
    {
        assert(stepWidth == nullptr || stepWidth >= 0.0);
        assert(stepHeight == nullptr || stepHeight >= 0.0);
    }
}

RenderIntrinsicWidth IntrinsicWidth::createRenderObject(BuildContext context) {
    return RenderIntrinsicWidth(_stepWidth, _stepHeight);
}

void IntrinsicWidth::updateRenderObject(BuildContext context, RenderIntrinsicWidth renderObject) {
    ;
}

double IntrinsicWidth::_stepWidth() {
    return stepWidth == 0.0? nullptr : stepWidth;
}

double IntrinsicWidth::_stepHeight() {
    return stepHeight == 0.0? nullptr : stepHeight;
}

RenderIntrinsicHeight IntrinsicHeight::createRenderObject(BuildContext context) {
    return RenderIntrinsicHeight();
}

Baseline::Baseline(double baseline, TextBaseline baselineType, Unknown, Unknown) {
    {
        assert(baseline != nullptr);
        assert(baselineType != nullptr);
    }
}

RenderBaseline Baseline::createRenderObject(BuildContext context) {
    return RenderBaseline(baseline, baselineType);
}

void Baseline::updateRenderObject(BuildContext context, RenderBaseline renderObject) {
    ;
}

RenderSliverToBoxAdapter SliverToBoxAdapter::createRenderObject(BuildContext context) {
    return RenderSliverToBoxAdapter();
}

SliverPadding::SliverPadding(Unknown, EdgeInsetsGeometry padding, Widget sliver) {
    {
        assert(padding != nullptr);
        super(sliver);
    }
}

RenderSliverPadding SliverPadding::createRenderObject(BuildContext context) {
    return RenderSliverPadding(padding, Directionality.of(context));
}

void SliverPadding::updateRenderObject(BuildContext context, RenderSliverPadding renderObject) {
    ;
}

void SliverPadding::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", padding));
}

AxisDirection getAxisDirectionFromAxisReverseAndDirectionality(Axis axis, BuildContext context, bool reverse) {
    ;
}

ListBody::ListBody(Unknown, Unknown, Axis mainAxis, bool reverse) {
    {
        assert(mainAxis != nullptr);
    }
}

RenderListBody ListBody::createRenderObject(BuildContext context) {
    return RenderListBody(_getDirection(context));
}

void ListBody::updateRenderObject(BuildContext context, RenderListBody renderObject) {
    renderObject.axisDirection = _getDirection(context);
}

AxisDirection ListBody::_getDirection(BuildContext context) {
    return getAxisDirectionFromAxisReverseAndDirectionality(context, mainAxis, reverse);
}

Stack::Stack(AlignmentGeometry alignment, Unknown, Clip clipBehavior, StackFit fit, Unknown, TextDirection textDirection) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderStack Stack::createRenderObject(BuildContext context) {
    assert(_debugCheckHasDirectionality(context));
    return RenderStack(alignment, textDirection ?? Directionality.maybeOf(context), fit, clipBehavior);
}

void Stack::updateRenderObject(BuildContext context, RenderStack renderObject) {
    assert(_debugCheckHasDirectionality(context));
    ;
}

void Stack::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<StackFit>EnumProperty("fit", fit));
    properties.add(<Clip>EnumProperty("clipBehavior", clipBehaviorClip.hardEdge));
}

bool Stack::_debugCheckHasDirectionality(BuildContext context) {
    if (alignment is AlignmentDirectional && textDirection == nullptr) {
        assert(debugCheckHasDirectionality(context"to resolve the 'alignment' argument", alignment == AlignmentDirectional.topStart? "The default value for 'alignment' is AlignmentDirectional.topStart, which requires a text direction." : nullptr, "Instead of providing a Directionality widget, another solution would be passing a non-directional 'alignment', or an explicit 'textDirection', to the $runtimeType."));
    }
    return true;
}

IndexedStack::IndexedStack(Unknown, Unknown, int index, Unknown, StackFit sizing, Unknown) {
    {
        super(sizing);
    }
}

RenderIndexedStack IndexedStack::createRenderObject(BuildContext context) {
    assert(_debugCheckHasDirectionality(context));
    return RenderIndexedStack(index, alignment, textDirection ?? Directionality.maybeOf(context));
}

void IndexedStack::updateRenderObject(BuildContext context, RenderIndexedStack renderObject) {
    assert(_debugCheckHasDirectionality(context));
    ;
}

Positioned::Positioned(double bottom, Unknown, double height, Unknown, double left, double right, double top, double width) {
    {
        assert(left == nullptr || right == nullptr || width == nullptr);
        assert(top == nullptr || bottom == nullptr || height == nullptr);
    }
}

void Positioned::fromRect(Unknown, Unknown, Rect rect)

void Positioned::fromRelativeRect(Unknown, Unknown, RelativeRect rect)

void Positioned::fill(double bottom, Unknown, Unknown, double left, double right, double top)

void Positioned::directional(double bottom, Widget child, double end, double height, Key key, double start, TextDirection textDirection, double top, double width) {
    assert(textDirection != nullptr);
    double left;
    double right;
    ;
    return Positioned(key, left, top, right, bottom, width, height, child);
}

void Positioned::applyParentData(RenderObject renderObject) {
    assert(renderObject.parentData is StackParentData);
    StackParentData parentData = (;
    bool needsLayout = false;
    if (parentData.left != left) {
        parentData.left = left;
        needsLayout = true;
    }
    if (parentData.top != top) {
        parentData.top = top;
        needsLayout = true;
    }
    if (parentData.right != right) {
        parentData.right = right;
        needsLayout = true;
    }
    if (parentData.bottom != bottom) {
        parentData.bottom = bottom;
        needsLayout = true;
    }
    if (parentData.width != width) {
        parentData.width = width;
        needsLayout = true;
    }
    if (parentData.height != height) {
        parentData.height = height;
        needsLayout = true;
    }
    if (needsLayout) {
        AbstractNode targetParent = renderObject.parent;
        if (targetParent is RenderObject) {
            targetParent.markNeedsLayout();
        }
    }
}

Type Positioned::debugTypicalAncestorWidgetClass() {
    return Stack;
}

void Positioned::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("left", leftnullptr));
    properties.add(DoubleProperty("top", topnullptr));
    properties.add(DoubleProperty("right", rightnullptr));
    properties.add(DoubleProperty("bottom", bottomnullptr));
    properties.add(DoubleProperty("width", widthnullptr));
    properties.add(DoubleProperty("height", heightnullptr));
}

Widget PositionedDirectional::build(BuildContext context) {
    return Positioned.directional(Directionality.of(context), start, top, end, bottom, width, height, child);
}

Flex::Flex(Unknown, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, Unknown, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection) {
    {
        assert(direction != nullptr);
        assert(mainAxisAlignment != nullptr);
        assert(mainAxisSize != nullptr);
        assert(crossAxisAlignment != nullptr);
        assert(verticalDirection != nullptr);
        assert(crossAxisAlignment != CrossAxisAlignment.baseline || textBaseline != nullptr, "textBaseline is required if you specify the crossAxisAlignment with CrossAxisAlignment.baseline");
        assert(clipBehavior != nullptr);
    }
}

TextDirection Flex::getEffectiveTextDirection(BuildContext context) {
    return textDirection ?? (_needTextDirection? Directionality.maybeOf(context) : nullptr);
}

RenderFlex Flex::createRenderObject(BuildContext context) {
    return RenderFlex(direction, mainAxisAlignment, mainAxisSize, crossAxisAlignment, getEffectiveTextDirection(context), verticalDirection, textBaseline, clipBehavior);
}

void Flex::updateRenderObject(BuildContext context, RenderFlex renderObject) {
    ;
}

void Flex::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Axis>EnumProperty("direction", direction));
    properties.add(<MainAxisAlignment>EnumProperty("mainAxisAlignment", mainAxisAlignment));
    properties.add(<MainAxisSize>EnumProperty("mainAxisSize", mainAxisSizeMainAxisSize.max));
    properties.add(<CrossAxisAlignment>EnumProperty("crossAxisAlignment", crossAxisAlignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<VerticalDirection>EnumProperty("verticalDirection", verticalDirectionVerticalDirection.down));
    properties.add(<TextBaseline>EnumProperty("textBaseline", textBaselinenullptr));
}

bool Flex::_needTextDirection() {
    assert(direction != nullptr);
    ;
}

Row::Row(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(Axis.horizontal);
    }
}

Column::Column(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(Axis.vertical);
    }
}

void Flexible::applyParentData(RenderObject renderObject) {
    assert(renderObject.parentData is FlexParentData);
    FlexParentData parentData = (;
    bool needsLayout = false;
    if (parentData.flex != flex) {
        parentData.flex = flex;
        needsLayout = true;
    }
    if (parentData.fit != fit) {
        parentData.fit = fit;
        needsLayout = true;
    }
    if (needsLayout) {
        AbstractNode targetParent = renderObject.parent;
        if (targetParent is RenderObject) {
            targetParent.markNeedsLayout();
        }
    }
}

Type Flexible::debugTypicalAncestorWidgetClass() {
    return Flex;
}

void Flexible::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("flex", flex));
}

Expanded::Expanded(Unknown, Unknown, Unknown) {
    {
        super(FlexFit.tight);
    }
}

Wrap::Wrap(WrapAlignment alignment, Unknown, Clip clipBehavior, WrapCrossAlignment crossAxisAlignment, Axis direction, Unknown, WrapAlignment runAlignment, double runSpacing, double spacing, TextDirection textDirection, VerticalDirection verticalDirection) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderWrap Wrap::createRenderObject(BuildContext context) {
    return RenderWrap(direction, alignment, spacing, runAlignment, runSpacing, crossAxisAlignment, textDirection ?? Directionality.maybeOf(context), verticalDirection, clipBehavior);
}

void Wrap::updateRenderObject(BuildContext context, RenderWrap renderObject) {
    ;
}

void Wrap::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Axis>EnumProperty("direction", direction));
    properties.add(<WrapAlignment>EnumProperty("alignment", alignment));
    properties.add(DoubleProperty("spacing", spacing));
    properties.add(<WrapAlignment>EnumProperty("runAlignment", runAlignment));
    properties.add(DoubleProperty("runSpacing", runSpacing));
    properties.add(<WrapCrossAlignment>EnumProperty("crossAxisAlignment", crossAxisAlignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<VerticalDirection>EnumProperty("verticalDirection", verticalDirectionVerticalDirection.down));
}

Flow::Flow(List<Widget> children, Clip clipBehavior, FlowDelegate delegate, Unknown) {
    {
        assert(delegate != nullptr);
        assert(clipBehavior != nullptr);
        super(RepaintBoundary.wrapAll(children));
    }
}

void Flow::unwrapped(Unknown, Clip clipBehavior, FlowDelegate delegate, Unknown)

RenderFlow Flow::createRenderObject(BuildContext context) {
    return RenderFlow(delegate, clipBehavior);
}

void Flow::updateRenderObject(BuildContext context, RenderFlow renderObject) {
    renderObject.delegate = delegate;
    renderObject.clipBehavior = clipBehavior;
}

RichText::RichText(Unknown, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, SelectionRegistrar selectionRegistrar, bool softWrap, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(text != nullptr);
        assert(textAlign != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(textScaleFactor != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(textWidthBasis != nullptr);
        assert(selectionRegistrar == nullptr || selectionColor != nullptr);
        super(_extractChildren(text));
    }
}

RenderParagraph RichText::createRenderObject(BuildContext context) {
    assert(textDirection != nullptr || debugCheckHasDirectionality(context));
    return RenderParagraph(texttextAlign, textDirection ?? Directionality.of(context), softWrap, overflow, textScaleFactor, maxLines, strutStyle, textWidthBasis, textHeightBehavior, locale ?? Localizations.maybeLocaleOf(context), selectionRegistrar, selectionColor);
}

void RichText::updateRenderObject(BuildContext context, RenderParagraph renderObject) {
    assert(textDirection != nullptr || debugCheckHasDirectionality(context));
    ;
}

void RichText::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TextAlign>EnumProperty("textAlign", textAlignTextAlign.start));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(FlagProperty("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties.add(<TextOverflow>EnumProperty("overflow", overflowTextOverflow.clip));
    properties.add(DoubleProperty("textScaleFactor", textScaleFactor1.0));
    properties.add(IntProperty("maxLines", maxLines"unlimited"));
    properties.add(<TextWidthBasis>EnumProperty("textWidthBasis", textWidthBasisTextWidthBasis.parent));
    properties.add(StringProperty("text", text.toPlainText()));
    properties.add(<Locale>DiagnosticsProperty("locale", localenullptr));
    properties.add(<StrutStyle>DiagnosticsProperty("strutStyle", strutStylenullptr));
    properties.add(<TextHeightBehavior>DiagnosticsProperty("textHeightBehavior", textHeightBehaviornullptr));
}

List<Widget> RichText::_extractChildren(InlineSpan span) {
    int index = 0;
    List<Widget> result = ;
    span.visitChildren();
    return result;
}

RawImage::RawImage(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, Unknown, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, double width) {
    {
        assert(scale != nullptr);
        assert(alignment != nullptr);
        assert(repeat != nullptr);
        assert(matchTextDirection != nullptr);
        assert(isAntiAlias != nullptr);
    }
}

RenderImage RawImage::createRenderObject(BuildContext context) {
    assert((!matchTextDirection && alignment is Alignment) || debugCheckHasDirectionality(context));
    assert(image?.debugGetOpenHandleStackTraces()?.isNotEmpty ?? true, "Creator of a RawImage disposed of the image when the RawImage still needed it.");
    return RenderImage(image?.clone(), debugImageLabel, width, height, scale, color, opacity, colorBlendMode, fit, alignment, repeat, centerSlice, matchTextDirection, matchTextDirection || alignment is! Alignment? Directionality.of(context) : nullptr, invertColors, isAntiAlias, filterQuality);
}

void RawImage::updateRenderObject(BuildContext context, RenderImage renderObject) {
    assert(image?.debugGetOpenHandleStackTraces()?.isNotEmpty ?? true, "Creator of a RawImage disposed of the image when the RawImage still needed it.");
    ;
}

void RawImage::didUnmountRenderObject(RenderImage renderObject) {
    renderObject.image = nullptr;
}

void RawImage::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Image>DiagnosticsProperty("image", image));
    properties.add(DoubleProperty("width", widthnullptr));
    properties.add(DoubleProperty("height", heightnullptr));
    properties.add(DoubleProperty("scale", scale1.0));
    properties.add(ColorProperty("color", colornullptr));
    properties.add(<Animation<double>>DiagnosticsProperty("opacity", opacitynullptr));
    properties.add(<BlendMode>EnumProperty("colorBlendMode", colorBlendModenullptr));
    properties.add(<BoxFit>EnumProperty("fit", fitnullptr));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignmentnullptr));
    properties.add(<ImageRepeat>EnumProperty("repeat", repeatImageRepeat.noRepeat));
    properties.add(<Rect>DiagnosticsProperty("centerSlice", centerSlicenullptr));
    properties.add(FlagProperty("matchTextDirection"matchTextDirection, "match text direction"));
    properties.add(<bool>DiagnosticsProperty("invertColors", invertColors));
    properties.add(<FilterQuality>EnumProperty("filterQuality", filterQuality));
}

DefaultAssetBundle::DefaultAssetBundle(AssetBundle bundle, Unknown, Unknown) {
    {
        assert(bundle != nullptr);
        assert(child != nullptr);
    }
}

AssetBundle DefaultAssetBundle::of(BuildContext context) {
    DefaultAssetBundle result = context.<DefaultAssetBundle>dependOnInheritedWidgetOfExactType();
    return result?.bundle ?? rootBundle;
}

bool DefaultAssetBundle::updateShouldNotify(DefaultAssetBundle oldWidget) {
    return bundle != oldWidget.bundle;
}

WidgetToRenderBoxAdapter::WidgetToRenderBoxAdapter(VoidCallback onBuild, VoidCallback onUnmount, RenderBox renderBox) {
    {
        assert(renderBox != nullptr);
        super(GlobalObjectKey(renderBox));
    }
}

RenderBox WidgetToRenderBoxAdapter::createRenderObject(BuildContext context) {
    return renderBox;
}

void WidgetToRenderBoxAdapter::updateRenderObject(BuildContext context, RenderBox renderObject) {
    onBuild?.call();
}

void WidgetToRenderBoxAdapter::didUnmountRenderObject(RenderObject renderObject) {
    assert(renderObject == renderBox);
    onUnmount?.call();
}

Listener::Listener(HitTestBehavior behavior, Unknown, Unknown, PointerCancelEventListener onPointerCancel, PointerDownEventListener onPointerDown, PointerHoverEventListener onPointerHover, PointerMoveEventListener onPointerMove, PointerPanZoomEndEventListener onPointerPanZoomEnd, PointerPanZoomStartEventListener onPointerPanZoomStart, PointerPanZoomUpdateEventListener onPointerPanZoomUpdate, PointerSignalEventListener onPointerSignal, PointerUpEventListener onPointerUp) {
    {
        assert(behavior != nullptr);
    }
}

RenderPointerListener Listener::createRenderObject(BuildContext context) {
    return RenderPointerListener(onPointerDown, onPointerMove, onPointerUp, onPointerHover, onPointerCancel, onPointerPanZoomStart, onPointerPanZoomUpdate, onPointerPanZoomEnd, onPointerSignal, behavior);
}

void Listener::updateRenderObject(BuildContext context, RenderPointerListener renderObject) {
    ;
}

void Listener::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    List<String> listeners = ;
    properties.add(<String>IterableProperty("listeners", listeners"<none>"));
    properties.add(<HitTestBehavior>EnumProperty("behavior", behavior));
}

MouseRegion::MouseRegion(Unknown, MouseCursor cursor, HitTestBehavior hitTestBehavior, Unknown, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque) {
    {
        assert(cursor != nullptr);
        assert(opaque != nullptr);
    }
}

RenderMouseRegion MouseRegion::createRenderObject(BuildContext context) {
    return RenderMouseRegion(onEnter, onHover, onExit, cursor, opaque, hitTestBehavior);
}

void MouseRegion::updateRenderObject(BuildContext context, RenderMouseRegion renderObject) {
    ;
}

void MouseRegion::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    List<String> listeners = ;
    if (onEnter != nullptr) {
        listeners.add("enter");
    }
    if (onExit != nullptr) {
        listeners.add("exit");
    }
    if (onHover != nullptr) {
        listeners.add("hover");
    }
    properties.add(<String>IterableProperty("listeners", listeners"<none>"));
    properties.add(<MouseCursor>DiagnosticsProperty("cursor", cursornullptr));
    properties.add(<bool>DiagnosticsProperty("opaque", opaquetrue));
}

void RepaintBoundary::wrap(Widget child, int childIndex) {
    assert(child != nullptr);
    Key key = child.key != nullptr? <Key>ValueKey(child.key!) : <int>ValueKey(childIndex);
    return RepaintBoundary(key, child);
}

List<RepaintBoundary> RepaintBoundary::wrapAll(List<Widget> widgets) {
    return ;
}

RenderRepaintBoundary RepaintBoundary::createRenderObject(BuildContext context) {
    return RenderRepaintBoundary();
}

IgnorePointer::IgnorePointer(Unknown, bool ignoring, bool ignoringSemantics, Unknown) {
    {
        assert(ignoring != nullptr);
    }
}

RenderIgnorePointer IgnorePointer::createRenderObject(BuildContext context) {
    return RenderIgnorePointer(ignoring, ignoringSemantics);
}

void IgnorePointer::updateRenderObject(BuildContext context, RenderIgnorePointer renderObject) {
    ;
}

void IgnorePointer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("ignoring", ignoring));
    properties.add(<bool>DiagnosticsProperty("ignoringSemantics", ignoringSemanticsnullptr));
}

AbsorbPointer::AbsorbPointer(bool absorbing, Unknown, bool ignoringSemantics, Unknown) {
    {
        assert(absorbing != nullptr);
    }
}

RenderAbsorbPointer AbsorbPointer::createRenderObject(BuildContext context) {
    return RenderAbsorbPointer(absorbing, ignoringSemantics);
}

void AbsorbPointer::updateRenderObject(BuildContext context, RenderAbsorbPointer renderObject) {
    ;
}

void AbsorbPointer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("absorbing", absorbing));
    properties.add(<bool>DiagnosticsProperty("ignoringSemantics", ignoringSemanticsnullptr));
}

RenderMetaData MetaData::createRenderObject(BuildContext context) {
    return RenderMetaData(metaData, behavior);
}

void MetaData::updateRenderObject(BuildContext context, RenderMetaData renderObject) {
    ;
}

void MetaData::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<HitTestBehavior>EnumProperty("behavior", behavior));
    properties.add(<dynamic>DiagnosticsProperty("metaData", metaData));
}

Semantics::Semantics(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, Widget child, bool container, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool excludeSemantics, bool explicitChildNodes, bool focusable, bool focused, bool header, bool hidden, String hint, bool image, bool inMutuallyExclusiveGroup, String increasedValue, Key key, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, String onLongPressHint, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorForwardByCharacter, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, String onTapHint, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value) {
    {
        this.fromProperties(key, child, container, explicitChildNodes, excludeSemantics, SemanticsProperties(enabled, checked, toggled, selected, button, slider, keyboardKey, link, header, textField, readOnly, focusable, focused, inMutuallyExclusiveGroup, obscured, multiline, scopesRoute, namesRoute, hidden, image, liveRegion, maxValueLength, currentValueLength, label, attributedLabel, value, attributedValue, increasedValue, attributedIncreasedValue, decreasedValue, attributedDecreasedValue, hint, attributedHint, tooltip, textDirection, sortKey, tagForChildren, onTap, onLongPress, onScrollLeft, onScrollRight, onScrollUp, onScrollDown, onIncrease, onDecrease, onCopy, onCut, onPaste, onMoveCursorForwardByCharacter, onMoveCursorBackwardByCharacter, onDidGainAccessibilityFocus, onDidLoseAccessibilityFocus, onDismiss, onSetSelection, onSetText, customSemanticsActions, onTapHint != nullptr || onLongPressHint != nullptr? SemanticsHintOverrides(onTapHint, onLongPressHint) : nullptr));
    }
}

void Semantics::fromProperties(Unknown, bool container, bool excludeSemantics, bool explicitChildNodes, Unknown, SemanticsProperties properties)

RenderSemanticsAnnotations Semantics::createRenderObject(BuildContext context) {
    return RenderSemanticsAnnotations(container, explicitChildNodes, excludeSemantics, properties, _getTextDirection(context));
}

void Semantics::updateRenderObject(BuildContext context, RenderSemanticsAnnotations renderObject) {
    ;
}

void Semantics::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("container", container));
    properties.add(<SemanticsProperties>DiagnosticsProperty("properties", this.properties));
    this.properties.debugFillProperties(properties);
}

TextDirection Semantics::_getTextDirection(BuildContext context) {
    if (properties.textDirection != nullptr) {
        return properties.textDirection;
    }
    bool containsText = properties.attributedLabel != nullptr || properties.label != nullptr || properties.value != nullptr || properties.hint != nullptr || properties.tooltip != nullptr;
    if (!containsText) {
        return nullptr;
    }
    return Directionality.maybeOf(context);
}

RenderMergeSemantics MergeSemantics::createRenderObject(BuildContext context) {
    return RenderMergeSemantics();
}

RenderBlockSemantics BlockSemantics::createRenderObject(BuildContext context) {
    return RenderBlockSemantics(blocking);
}

void BlockSemantics::updateRenderObject(BuildContext context, RenderBlockSemantics renderObject) {
    renderObject.blocking = blocking;
}

void BlockSemantics::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("blocking", blocking));
}

ExcludeSemantics::ExcludeSemantics(Unknown, bool excluding, Unknown) {
    {
        assert(excluding != nullptr);
    }
}

RenderExcludeSemantics ExcludeSemantics::createRenderObject(BuildContext context) {
    return RenderExcludeSemantics(excluding);
}

void ExcludeSemantics::updateRenderObject(BuildContext context, RenderExcludeSemantics renderObject) {
    renderObject.excluding = excluding;
}

void ExcludeSemantics::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("excluding", excluding));
}

IndexedSemantics::IndexedSemantics(Unknown, int index, Unknown) {
    {
        assert(index != nullptr);
    }
}

RenderIndexedSemantics IndexedSemantics::createRenderObject(BuildContext context) {
    return RenderIndexedSemantics(index);
}

void IndexedSemantics::updateRenderObject(BuildContext context, RenderIndexedSemantics renderObject) {
    renderObject.index = index;
}

void IndexedSemantics::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<int>DiagnosticsProperty("index", index));
}

KeyedSubtree::KeyedSubtree(Widget child, Unknown) {
    {
        assert(child != nullptr);
    }
}

void KeyedSubtree::wrap(Widget child, int childIndex) {
    Key key = child.key != nullptr? <Key>ValueKey(child.key!) : <int>ValueKey(childIndex);
    return KeyedSubtree(key, child);
}

List<Widget> KeyedSubtree::ensureUniqueKeysForList(int baseIndex, List<Widget> items) {
    if (items == nullptr || items.isEmpty) {
        return items;
    }
    List<Widget> itemsWithUniqueKeys = ;
    int itemIndex = baseIndex;
    for (Widget item : items) {
        itemsWithUniqueKeys.add(KeyedSubtree.wrap(item, itemIndex));
        itemIndex = 1;
    }
    assert(!debugItemsHaveDuplicateKeys(itemsWithUniqueKeys));
    return itemsWithUniqueKeys;
}

Widget KeyedSubtree::build(BuildContext context) {
    return child;
}

Builder::Builder(WidgetBuilder builder, Unknown) {
    {
        assert(builder != nullptr);
    }
}

Widget Builder::build(BuildContext context) {
    return builder(context);
}

StatefulBuilder::StatefulBuilder(StatefulWidgetBuilder builder, Unknown) {
    {
        assert(builder != nullptr);
    }
}

State<StatefulBuilder> StatefulBuilder::createState() {
    return _StatefulBuilderState();
}

Widget _StatefulBuilderState::build(BuildContext context) {
    return widget.builder(context, setState);
}

ColoredBox::ColoredBox(Unknown, Color color, Unknown) {
    {
        assert(color != nullptr);
    }
}

RenderObject ColoredBox::createRenderObject(BuildContext context) {
    return _RenderColoredBox(color);
}

void ColoredBox::updateRenderObject(BuildContext context, RenderObject renderObject) {
    (().color = color;
}

void ColoredBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Color>DiagnosticsProperty("color", color));
}

Color _RenderColoredBox::color() {
    return _color;
}

void _RenderColoredBox::color(Color value) {
    assert(value != nullptr);
    if (value == _color) {
        return;
    }
    _color = value;
    markNeedsPaint();
}

void _RenderColoredBox::paint(PaintingContext context, Offset offset) {
    if (size > Size.zero) {
        context.canvas.drawRect(offset & size, );
    }
    if (child != nullptr) {
        context.paintChild(child!, offset);
    }
}

_RenderColoredBox::_RenderColoredBox(Color color) {
    {
        _color = color;
        super(HitTestBehavior.opaque);
    }
}
