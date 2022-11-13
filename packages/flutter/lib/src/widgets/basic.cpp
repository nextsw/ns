#include "basic.hpp"
void _UbiquitousInheritedElementCls::setDependencies(Element dependent, Object value) {
    assert(value == nullptr);
}

Object _UbiquitousInheritedElementCls::getDependencies(Element dependent) {
    return nullptr;
}

void _UbiquitousInheritedElementCls::notifyClients(InheritedWidget oldWidget) {
    _recurseChildren(this, [=] (Element element) {
        if (element->doesDependOnInheritedElement(this)) {
            notifyDependent(oldWidget, element);
        }
    });
}

void _UbiquitousInheritedElementCls::_recurseChildren(Element element, ElementVisitor visitor) {
    element->visitChildren([=] (Element child) {
        _recurseChildren(child, visitor);
    });
    visitor(element);
}

InheritedElement _UbiquitousInheritedWidgetCls::createElement() {
    return make<_UbiquitousInheritedElementCls>(this);
}

DirectionalityCls::DirectionalityCls(Widget child, Key key, TextDirection textDirection) {
    {
        assert(textDirection != nullptr);
        assert(child != nullptr);
    }
}

TextDirection DirectionalityCls::of(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    Directionality widget = context-><Directionality>dependOnInheritedWidgetOfExactType()!;
    return widget->textDirection;
}

TextDirection DirectionalityCls::maybeOf(BuildContext context) {
    Directionality widget = context-><Directionality>dependOnInheritedWidgetOfExactType();
    return widget?->textDirection;
}

bool DirectionalityCls::updateShouldNotify(Directionality oldWidget) {
    return textDirection != oldWidget->textDirection;
}

void DirectionalityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection));
}

OpacityCls::OpacityCls(bool alwaysIncludeSemantics, Widget child, Key key, double opacity) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
    }
}

RenderOpacity OpacityCls::createRenderObject(BuildContext context) {
    return make<RenderOpacityCls>(opacity, alwaysIncludeSemantics);
}

void OpacityCls::updateRenderObject(BuildContext context, RenderOpacity renderObject) {
    auto _c1 = renderObject;_c1.opacity = auto _c2 = opacity;_c2.alwaysIncludeSemantics = alwaysIncludeSemantics;_c2;_c1;
}

void OpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("opacity"), opacity));
    properties->add(make<FlagPropertyCls>(__s("alwaysIncludeSemantics"), alwaysIncludeSemantics, __s("alwaysIncludeSemantics")));
}

ShaderMaskCls::ShaderMaskCls(BlendMode blendMode, Widget child, Key key, ShaderCallback shaderCallback) {
    {
        assert(shaderCallback != nullptr);
        assert(blendMode != nullptr);
    }
}

RenderShaderMask ShaderMaskCls::createRenderObject(BuildContext context) {
    return make<RenderShaderMaskCls>(shaderCallback, blendMode);
}

void ShaderMaskCls::updateRenderObject(BuildContext context, RenderShaderMask renderObject) {
    auto _c1 = renderObject;_c1.shaderCallback = auto _c2 = shaderCallback;_c2.blendMode = blendMode;_c2;_c1;
}

BackdropFilterCls::BackdropFilterCls(BlendMode blendMode, Widget child, ImageFilter filter, Key key) {
    {
        assert(filter != nullptr);
    }
}

RenderBackdropFilter BackdropFilterCls::createRenderObject(BuildContext context) {
    return make<RenderBackdropFilterCls>(filter, blendMode);
}

void BackdropFilterCls::updateRenderObject(BuildContext context, RenderBackdropFilter renderObject) {
    auto _c1 = renderObject;_c1.filter = auto _c2 = filter;_c2.blendMode = blendMode;_c2;_c1;
}

CustomPaintCls::CustomPaintCls(Widget child, CustomPainter foregroundPainter, bool isComplex, Key key, CustomPainter painter, Size size, bool willChange) {
    {
        assert(size != nullptr);
        assert(isComplex != nullptr);
        assert(willChange != nullptr);
        assert(painter != nullptr || foregroundPainter != nullptr || (!isComplex && !willChange));
    }
}

RenderCustomPaint CustomPaintCls::createRenderObject(BuildContext context) {
    return make<RenderCustomPaintCls>(painter, foregroundPainter, size, isComplex, willChange);
}

void CustomPaintCls::updateRenderObject(BuildContext context, RenderCustomPaint renderObject) {
    auto _c1 = renderObject;_c1.painter = auto _c2 = painter;_c2.foregroundPainter = auto _c3 = foregroundPainter;_c3.preferredSize = auto _c4 = size;_c4.isComplex = auto _c5 = isComplex;_c5.willChange = willChange;_c5;_c4;_c3;_c2;_c1;
}

void CustomPaintCls::didUnmountRenderObject(RenderCustomPaint renderObject) {
    auto _c1 = renderObject;_c1.painter = auto _c2 = nullptr;_c2.foregroundPainter = nullptr;_c2;_c1;
}

ClipRectCls::ClipRectCls(Widget child, Clip clipBehavior, CustomClipper<Rect> clipper, Key key) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderClipRect ClipRectCls::createRenderObject(BuildContext context) {
    return make<RenderClipRectCls>(clipper, clipBehavior);
}

void ClipRectCls::updateRenderObject(BuildContext context, RenderClipRect renderObject) {
    auto _c1 = renderObject;_c1.clipper = auto _c2 = clipper;_c2.clipBehavior = clipBehavior;_c2;_c1;
}

void ClipRectCls::didUnmountRenderObject(RenderClipRect renderObject) {
    renderObject->clipper = nullptr;
}

void ClipRectCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<CustomClipper<Rect>>make<DiagnosticsPropertyCls>(__s("clipper"), clipper, nullptr));
}

ClipRRectCls::ClipRRectCls(BorderRadiusGeometry borderRadius, Widget child, Clip clipBehavior, CustomClipper<RRect> clipper, Key key) {
    {
        assert(borderRadius != nullptr || clipper != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderClipRRect ClipRRectCls::createRenderObject(BuildContext context) {
    return make<RenderClipRRectCls>(borderRadius!, clipper, clipBehavior, DirectionalityCls->maybeOf(context));
}

void ClipRRectCls::updateRenderObject(BuildContext context, RenderClipRRect renderObject) {
    auto _c1 = renderObject;_c1.borderRadius = auto _c2 = borderRadius!;_c2.clipBehavior = auto _c3 = clipBehavior;_c3.clipper = auto _c4 = clipper;_c4.textDirection = DirectionalityCls->maybeOf(context);_c4;_c3;_c2;_c1;
}

void ClipRRectCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BorderRadiusGeometry>make<DiagnosticsPropertyCls>(__s("borderRadius"), borderRadius, false, nullptr));
    properties->add(<CustomClipper<RRect>>make<DiagnosticsPropertyCls>(__s("clipper"), clipper, nullptr));
}

ClipOvalCls::ClipOvalCls(Widget child, Clip clipBehavior, CustomClipper<Rect> clipper, Key key) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderClipOval ClipOvalCls::createRenderObject(BuildContext context) {
    return make<RenderClipOvalCls>(clipper, clipBehavior);
}

void ClipOvalCls::updateRenderObject(BuildContext context, RenderClipOval renderObject) {
    auto _c1 = renderObject;_c1.clipper = auto _c2 = clipper;_c2.clipBehavior = clipBehavior;_c2;_c1;
}

void ClipOvalCls::didUnmountRenderObject(RenderClipOval renderObject) {
    renderObject->clipper = nullptr;
}

void ClipOvalCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<CustomClipper<Rect>>make<DiagnosticsPropertyCls>(__s("clipper"), clipper, nullptr));
}

ClipPathCls::ClipPathCls(Widget child, Clip clipBehavior, CustomClipper<Path> clipper, Key key) {
    {
        assert(clipBehavior != nullptr);
    }
}

Widget ClipPathCls::shape(Widget child, Clip clipBehavior, Key key, ShapeBorder shape) {
    assert(clipBehavior != nullptr);
    assert(shape != nullptr);
    return make<BuilderCls>(key, [=] (BuildContext context) {
        return make<ClipPathCls>(make<ShapeBorderClipperCls>(shape, DirectionalityCls->maybeOf(context)), clipBehavior, child);
    });
}

RenderClipPath ClipPathCls::createRenderObject(BuildContext context) {
    return make<RenderClipPathCls>(clipper, clipBehavior);
}

void ClipPathCls::updateRenderObject(BuildContext context, RenderClipPath renderObject) {
    auto _c1 = renderObject;_c1.clipper = auto _c2 = clipper;_c2.clipBehavior = clipBehavior;_c2;_c1;
}

void ClipPathCls::didUnmountRenderObject(RenderClipPath renderObject) {
    renderObject->clipper = nullptr;
}

void ClipPathCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<CustomClipper<Path>>make<DiagnosticsPropertyCls>(__s("clipper"), clipper, nullptr));
}

PhysicalModelCls::PhysicalModelCls(BorderRadius borderRadius, Widget child, Clip clipBehavior, Color color, double elevation, Key key, Color shadowColor, BoxShape shape) {
    {
        assert(shape != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderPhysicalModel PhysicalModelCls::createRenderObject(BuildContext context) {
    return make<RenderPhysicalModelCls>(shape, clipBehavior, borderRadius, elevation, color, shadowColor);
}

void PhysicalModelCls::updateRenderObject(BuildContext context, RenderPhysicalModel renderObject) {
    auto _c1 = renderObject;_c1.shape = auto _c2 = shape;_c2.clipBehavior = auto _c3 = clipBehavior;_c3.borderRadius = auto _c4 = borderRadius;_c4.elevation = auto _c5 = elevation;_c5.color = auto _c6 = color;_c6.shadowColor = shadowColor;_c6;_c5;_c4;_c3;_c2;_c1;
}

void PhysicalModelCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BoxShape>make<EnumPropertyCls>(__s("shape"), shape));
    properties->add(<BorderRadius>make<DiagnosticsPropertyCls>(__s("borderRadius"), borderRadius));
    properties->add(make<DoublePropertyCls>(__s("elevation"), elevation));
    properties->add(make<ColorPropertyCls>(__s("color"), color));
    properties->add(make<ColorPropertyCls>(__s("shadowColor"), shadowColor));
}

PhysicalShapeCls::PhysicalShapeCls(Widget child, Clip clipBehavior, CustomClipper<Path> clipper, Color color, double elevation, Key key, Color shadowColor) {
    {
        assert(clipper != nullptr);
        assert(clipBehavior != nullptr);
        assert(elevation != nullptr && elevation >= 0.0);
        assert(color != nullptr);
        assert(shadowColor != nullptr);
    }
}

RenderPhysicalShape PhysicalShapeCls::createRenderObject(BuildContext context) {
    return make<RenderPhysicalShapeCls>(clipper, clipBehavior, elevation, color, shadowColor);
}

void PhysicalShapeCls::updateRenderObject(BuildContext context, RenderPhysicalShape renderObject) {
    auto _c1 = renderObject;_c1.clipper = auto _c2 = clipper;_c2.clipBehavior = auto _c3 = clipBehavior;_c3.elevation = auto _c4 = elevation;_c4.color = auto _c5 = color;_c5.shadowColor = shadowColor;_c5;_c4;_c3;_c2;_c1;
}

void PhysicalShapeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<CustomClipper<Path>>make<DiagnosticsPropertyCls>(__s("clipper"), clipper));
    properties->add(make<DoublePropertyCls>(__s("elevation"), elevation));
    properties->add(make<ColorPropertyCls>(__s("color"), color));
    properties->add(make<ColorPropertyCls>(__s("shadowColor"), shadowColor));
}

TransformCls::TransformCls(AlignmentGeometry alignment, Widget child, FilterQuality filterQuality, Key key, Offset origin, Matrix4 transform, bool transformHitTests) {
    {
        assert(transform != nullptr);
    }
}

void TransformCls::rotate(AlignmentGeometry alignment, double angle, Widget child, FilterQuality filterQuality, Key key, Offset origin, bool transformHitTests)

void TransformCls::translate(Widget child, FilterQuality filterQuality, Key key, Offset offset, bool transformHitTests)

void TransformCls::scale(AlignmentGeometry alignment, Widget child, FilterQuality filterQuality, Key key, Offset origin, double scale, double scaleX, double scaleY, bool transformHitTests)

RenderTransform TransformCls::createRenderObject(BuildContext context) {
    return make<RenderTransformCls>(transform, origin, alignment, DirectionalityCls->maybeOf(context), transformHitTests, filterQuality);
}

void TransformCls::updateRenderObject(BuildContext context, RenderTransform renderObject) {
    auto _c1 = renderObject;_c1.transform = auto _c2 = transform;_c2.origin = auto _c3 = origin;_c3.alignment = auto _c4 = alignment;_c4.textDirection = auto _c5 = DirectionalityCls->maybeOf(context);_c5.transformHitTests = auto _c6 = transformHitTests;_c6.filterQuality = filterQuality;_c6;_c5;_c4;_c3;_c2;_c1;
}

Matrix4 TransformCls::_computeRotation(double radians) {
    assert(radians->isFinite(), __sf("Cannot compute the rotation matrix for a non-finite angle: %s", radians));
    if (radians == 0.0) {
        return Matrix4Cls->identity();
    }
    double sin = math->sin(radians);
    if (sin == 1.0) {
        return _createZRotation(1.0, 0.0);
    }
    if (sin == -1.0) {
        return _createZRotation(-1.0, 0.0);
    }
    double cos = math->cos(radians);
    if (cos == -1.0) {
        return _createZRotation(0.0, -1.0);
    }
    return _createZRotation(sin, cos);
}

Matrix4 TransformCls::_createZRotation(double sin, double cos) {
    Matrix4 result = Matrix4Cls->zero();
    result->storage()[0] = cos;
    result->storage()[1] = sin;
    result->storage()[4] = -sin;
    result->storage()[5] = cos;
    result->storage()[10] = 1.0;
    result->storage()[15] = 1.0;
    return result;
}

CompositedTransformTargetCls::CompositedTransformTargetCls(Widget child, Key key, LayerLink link) {
    {
        assert(link != nullptr);
    }
}

RenderLeaderLayer CompositedTransformTargetCls::createRenderObject(BuildContext context) {
    return make<RenderLeaderLayerCls>(link);
}

void CompositedTransformTargetCls::updateRenderObject(BuildContext context, RenderLeaderLayer renderObject) {
    renderObject->link = link;
}

CompositedTransformFollowerCls::CompositedTransformFollowerCls(Widget child, Alignment followerAnchor, Key key, LayerLink link, Offset offset, bool showWhenUnlinked, Alignment targetAnchor) {
    {
        assert(link != nullptr);
        assert(showWhenUnlinked != nullptr);
        assert(offset != nullptr);
        assert(targetAnchor != nullptr);
        assert(followerAnchor != nullptr);
    }
}

RenderFollowerLayer CompositedTransformFollowerCls::createRenderObject(BuildContext context) {
    return make<RenderFollowerLayerCls>(link, showWhenUnlinked, offset, targetAnchor, followerAnchor);
}

void CompositedTransformFollowerCls::updateRenderObject(BuildContext context, RenderFollowerLayer renderObject) {
    auto _c1 = renderObject;_c1.link = auto _c2 = link;_c2.showWhenUnlinked = auto _c3 = showWhenUnlinked;_c3.offset = auto _c4 = offset;_c4.leaderAnchor = auto _c5 = targetAnchor;_c5.followerAnchor = followerAnchor;_c5;_c4;_c3;_c2;_c1;
}

FittedBoxCls::FittedBoxCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, BoxFit fit, Key key) {
    {
        assert(fit != nullptr);
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderFittedBox FittedBoxCls::createRenderObject(BuildContext context) {
    return make<RenderFittedBoxCls>(fit, alignment, DirectionalityCls->maybeOf(context), clipBehavior);
}

void FittedBoxCls::updateRenderObject(BuildContext context, RenderFittedBox renderObject) {
    auto _c1 = renderObject;_c1.fit = auto _c2 = fit;_c2.alignment = auto _c3 = alignment;_c3.textDirection = auto _c4 = DirectionalityCls->maybeOf(context);_c4.clipBehavior = clipBehavior;_c4;_c3;_c2;_c1;
}

void FittedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BoxFit>make<EnumPropertyCls>(__s("fit"), fit));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
}

FractionalTranslationCls::FractionalTranslationCls(Widget child, Key key, bool transformHitTests, Offset translation) {
    {
        assert(translation != nullptr);
    }
}

RenderFractionalTranslation FractionalTranslationCls::createRenderObject(BuildContext context) {
    return make<RenderFractionalTranslationCls>(translation, transformHitTests);
}

void FractionalTranslationCls::updateRenderObject(BuildContext context, RenderFractionalTranslation renderObject) {
    auto _c1 = renderObject;_c1.translation = auto _c2 = translation;_c2.transformHitTests = transformHitTests;_c2;_c1;
}

RotatedBoxCls::RotatedBoxCls(Widget child, Key key, int quarterTurns) {
    {
        assert(quarterTurns != nullptr);
    }
}

RenderRotatedBox RotatedBoxCls::createRenderObject(BuildContext context) {
    return make<RenderRotatedBoxCls>(quarterTurns);
}

void RotatedBoxCls::updateRenderObject(BuildContext context, RenderRotatedBox renderObject) {
    renderObject->quarterTurns = quarterTurns;
}

PaddingCls::PaddingCls(Widget child, Key key, EdgeInsetsGeometry padding) {
    {
        assert(padding != nullptr);
    }
}

RenderPadding PaddingCls::createRenderObject(BuildContext context) {
    return make<RenderPaddingCls>(padding, DirectionalityCls->maybeOf(context));
}

void PaddingCls::updateRenderObject(BuildContext context, RenderPadding renderObject) {
    auto _c1 = renderObject;_c1.padding = auto _c2 = padding;_c2.textDirection = DirectionalityCls->maybeOf(context);_c2;_c1;
}

void PaddingCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding));
}

AlignCls::AlignCls(AlignmentGeometry alignment, Widget child, double heightFactor, Key key, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

RenderPositionedBox AlignCls::createRenderObject(BuildContext context) {
    return make<RenderPositionedBoxCls>(alignment, widthFactor, heightFactor, DirectionalityCls->maybeOf(context));
}

void AlignCls::updateRenderObject(BuildContext context, RenderPositionedBox renderObject) {
    auto _c1 = renderObject;_c1.alignment = auto _c2 = alignment;_c2.widthFactor = auto _c3 = widthFactor;_c3.heightFactor = auto _c4 = heightFactor;_c4.textDirection = DirectionalityCls->maybeOf(context);_c4;_c3;_c2;_c1;
}

void AlignCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(make<DoublePropertyCls>(__s("widthFactor"), widthFactor, nullptr));
    properties->add(make<DoublePropertyCls>(__s("heightFactor"), heightFactor, nullptr));
}

CustomSingleChildLayoutCls::CustomSingleChildLayoutCls(Widget child, SingleChildLayoutDelegate delegate, Key key) {
    {
        assert(delegate != nullptr);
    }
}

RenderCustomSingleChildLayoutBox CustomSingleChildLayoutCls::createRenderObject(BuildContext context) {
    return make<RenderCustomSingleChildLayoutBoxCls>(delegate);
}

void CustomSingleChildLayoutCls::updateRenderObject(BuildContext context, RenderCustomSingleChildLayoutBox renderObject) {
    renderObject->delegate = delegate;
}

LayoutIdCls::LayoutIdCls(Widget child, Object id, Key key) : ParentDataWidget<MultiChildLayoutParentData>(key | <Object>make<ValueKeyCls>(id)) {
    {
        assert(child != nullptr);
        assert(id != nullptr);
    }
}

void LayoutIdCls::applyParentData(RenderObject renderObject) {
    assert(is<MultiChildLayoutParentData>(renderObject->parentData));
    MultiChildLayoutParentData parentData = as<MultiChildLayoutParentData>(renderObject->parentData!);
    if (parentData->id != id) {
        parentData->id = id;
        AbstractNode targetParent = renderObject->parent();
        if (is<RenderObject>(targetParent)) {
            as<RenderObjectCls>(targetParent)->markNeedsLayout();
        }
    }
}

Type LayoutIdCls::debugTypicalAncestorWidgetClass() {
    return CustomMultiChildLayoutCls;
}

void LayoutIdCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Object>make<DiagnosticsPropertyCls>(__s("id"), id));
}

CustomMultiChildLayoutCls::CustomMultiChildLayoutCls(List<Widget> children, MultiChildLayoutDelegate delegate, Key key) {
    {
        assert(delegate != nullptr);
    }
}

RenderCustomMultiChildLayoutBox CustomMultiChildLayoutCls::createRenderObject(BuildContext context) {
    return make<RenderCustomMultiChildLayoutBoxCls>(delegate);
}

void CustomMultiChildLayoutCls::updateRenderObject(BuildContext context, RenderCustomMultiChildLayoutBox renderObject) {
    renderObject->delegate = delegate;
}

void SizedBoxCls::expand(Widget child, Key key)

void SizedBoxCls::shrink(Widget child, Key key)

void SizedBoxCls::fromSize(Widget child, Key key, Size size)

void SizedBoxCls::square(Widget child, double dimension, Key key)

RenderConstrainedBox SizedBoxCls::createRenderObject(BuildContext context) {
    return make<RenderConstrainedBoxCls>(_additionalConstraints());
}

void SizedBoxCls::updateRenderObject(BuildContext context, RenderConstrainedBox renderObject) {
    renderObject->additionalConstraints() = _additionalConstraints();
}

String SizedBoxCls::toStringShort() {
    String type;
    if (width == double->infinity && height == double->infinity) {
        type = __sf("%s.expand", objectRuntimeType(this, __s("SizedBox")));
    } else {
        if (width == 0.0 && height == 0.0) {
        type = __sf("%s.shrink", objectRuntimeType(this, __s("SizedBox")));
    } else {
        type = objectRuntimeType(this, __s("SizedBox"));
    }
;
    }    return key == nullptr? type : __sf("%s-%s", type, key);
}

void SizedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    DiagnosticLevel level;
    if ((width == double->infinity && height == double->infinity) || (width == 0.0 && height == 0.0)) {
        level = DiagnosticLevelCls::hidden;
    } else {
        level = DiagnosticLevelCls::info;
    }
    properties->add(make<DoublePropertyCls>(__s("width"), width, nullptr, level));
    properties->add(make<DoublePropertyCls>(__s("height"), height, nullptr, level));
}

BoxConstraints SizedBoxCls::_additionalConstraints() {
    return BoxConstraintsCls->tightFor(width, height);
}

ConstrainedBoxCls::ConstrainedBoxCls(Widget child, BoxConstraints constraints, Key key) {
    {
        assert(constraints != nullptr);
        assert(constraints->debugAssertIsValid());
    }
}

RenderConstrainedBox ConstrainedBoxCls::createRenderObject(BuildContext context) {
    return make<RenderConstrainedBoxCls>(constraints);
}

void ConstrainedBoxCls::updateRenderObject(BuildContext context, RenderConstrainedBox renderObject) {
    renderObject->additionalConstraints() = constraints;
}

void ConstrainedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BoxConstraints>make<DiagnosticsPropertyCls>(__s("constraints"), constraints, false));
}

ConstraintsTransformBoxCls::ConstraintsTransformBoxCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, String debugTransformType, Key key, TextDirection textDirection) {
    {
        _debugTransformLabel = debugTransformType;
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
        assert(constraintsTransform != nullptr);
        assert(debugTransformType != nullptr);
    }
}

BoxConstraints ConstraintsTransformBoxCls::unmodified(BoxConstraints constraints) {
    return constraints;
}

BoxConstraints ConstraintsTransformBoxCls::unconstrained(BoxConstraints constraints) {
    return make<BoxConstraintsCls>();
}

BoxConstraints ConstraintsTransformBoxCls::widthUnconstrained(BoxConstraints constraints) {
    return constraints->heightConstraints();
}

BoxConstraints ConstraintsTransformBoxCls::heightUnconstrained(BoxConstraints constraints) {
    return constraints->widthConstraints();
}

BoxConstraints ConstraintsTransformBoxCls::maxHeightUnconstrained(BoxConstraints constraints) {
    return constraints->copyWith(double->infinity);
}

BoxConstraints ConstraintsTransformBoxCls::maxWidthUnconstrained(BoxConstraints constraints) {
    return constraints->copyWith(double->infinity);
}

BoxConstraints ConstraintsTransformBoxCls::maxUnconstrained(BoxConstraints constraints) {
    return constraints->copyWith(double->infinity, double->infinity);
}

RenderConstraintsTransformBox ConstraintsTransformBoxCls::createRenderObject(BuildContext context) {
    return make<RenderConstraintsTransformBoxCls>(textDirection | DirectionalityCls->maybeOf(context), alignment, constraintsTransform, clipBehavior);
}

void ConstraintsTransformBoxCls::updateRenderObject(BuildContext context, RenderConstraintsTransformBox renderObject) {
    auto _c1 = renderObject;_c1.textDirection = auto _c2 = textDirection | DirectionalityCls->maybeOf(context);_c2.constraintsTransform = auto _c3 = constraintsTransform;_c3.alignment = auto _c4 = alignment;_c4.clipBehavior = clipBehavior;_c4;_c3;_c2;_c1;
}

void ConstraintsTransformBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    String debugTransformLabel = _debugTransformLabel->isNotEmpty()? _debugTransformLabel : _debugKnownTransforms[constraintsTransform];
    if (debugTransformLabel != nullptr) {
        properties->add(<String>make<DiagnosticsPropertyCls>(__s("constraints transform"), debugTransformLabel));
    }
}

UnconstrainedBoxCls::UnconstrainedBoxCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Axis constrainedAxis, Key key, TextDirection textDirection) {
    {
        assert(alignment != nullptr);
        assert(clipBehavior != nullptr);
    }
}

Widget UnconstrainedBoxCls::build(BuildContext context) {
    return make<ConstraintsTransformBoxCls>(textDirection, alignment, clipBehavior, _axisToTransform(constrainedAxis), child);
}

void UnconstrainedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(<Axis>make<EnumPropertyCls>(__s("constrainedAxis"), constrainedAxis, nullptr));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
}

BoxConstraintsTransform UnconstrainedBoxCls::_axisToTransform(Axis constrainedAxis) {
    if (constrainedAxis != nullptr) {
        ;
    } else {
        return ConstraintsTransformBoxCls::unconstrained;
    }
}

FractionallySizedBoxCls::FractionallySizedBoxCls(AlignmentGeometry alignment, Widget child, double heightFactor, Key key, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(widthFactor == nullptr || widthFactor >= 0.0);
        assert(heightFactor == nullptr || heightFactor >= 0.0);
    }
}

RenderFractionallySizedOverflowBox FractionallySizedBoxCls::createRenderObject(BuildContext context) {
    return make<RenderFractionallySizedOverflowBoxCls>(alignment, widthFactor, heightFactor, DirectionalityCls->maybeOf(context));
}

void FractionallySizedBoxCls::updateRenderObject(BuildContext context, RenderFractionallySizedOverflowBox renderObject) {
    auto _c1 = renderObject;_c1.alignment = auto _c2 = alignment;_c2.widthFactor = auto _c3 = widthFactor;_c3.heightFactor = auto _c4 = heightFactor;_c4.textDirection = DirectionalityCls->maybeOf(context);_c4;_c3;_c2;_c1;
}

void FractionallySizedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(make<DoublePropertyCls>(__s("widthFactor"), widthFactor, nullptr));
    properties->add(make<DoublePropertyCls>(__s("heightFactor"), heightFactor, nullptr));
}

LimitedBoxCls::LimitedBoxCls(Widget child, Key key, double maxHeight, double maxWidth) {
    {
        assert(maxWidth != nullptr && maxWidth >= 0.0);
        assert(maxHeight != nullptr && maxHeight >= 0.0);
    }
}

RenderLimitedBox LimitedBoxCls::createRenderObject(BuildContext context) {
    return make<RenderLimitedBoxCls>(maxWidth, maxHeight);
}

void LimitedBoxCls::updateRenderObject(BuildContext context, RenderLimitedBox renderObject) {
    auto _c1 = renderObject;_c1.maxWidth = auto _c2 = maxWidth;_c2.maxHeight = maxHeight;_c2;_c1;
}

void LimitedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("maxWidth"), maxWidth, double->infinity));
    properties->add(make<DoublePropertyCls>(__s("maxHeight"), maxHeight, double->infinity));
}

RenderConstrainedOverflowBox OverflowBoxCls::createRenderObject(BuildContext context) {
    return make<RenderConstrainedOverflowBoxCls>(alignment, minWidth, maxWidth, minHeight, maxHeight, DirectionalityCls->maybeOf(context));
}

void OverflowBoxCls::updateRenderObject(BuildContext context, RenderConstrainedOverflowBox renderObject) {
    auto _c1 = renderObject;_c1.alignment = auto _c2 = alignment;_c2.minWidth = auto _c3 = minWidth;_c3.maxWidth = auto _c4 = maxWidth;_c4.minHeight = auto _c5 = minHeight;_c5.maxHeight = auto _c6 = maxHeight;_c6.textDirection = DirectionalityCls->maybeOf(context);_c6;_c5;_c4;_c3;_c2;_c1;
}

void OverflowBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(make<DoublePropertyCls>(__s("minWidth"), minWidth, nullptr));
    properties->add(make<DoublePropertyCls>(__s("maxWidth"), maxWidth, nullptr));
    properties->add(make<DoublePropertyCls>(__s("minHeight"), minHeight, nullptr));
    properties->add(make<DoublePropertyCls>(__s("maxHeight"), maxHeight, nullptr));
}

SizedOverflowBoxCls::SizedOverflowBoxCls(AlignmentGeometry alignment, Widget child, Key key, Size size) {
    {
        assert(size != nullptr);
        assert(alignment != nullptr);
    }
}

RenderSizedOverflowBox SizedOverflowBoxCls::createRenderObject(BuildContext context) {
    return make<RenderSizedOverflowBoxCls>(alignment, size, DirectionalityCls->of(context));
}

void SizedOverflowBoxCls::updateRenderObject(BuildContext context, RenderSizedOverflowBox renderObject) {
    auto _c1 = renderObject;_c1.alignment = auto _c2 = alignment;_c2.requestedSize = auto _c3 = size;_c3.textDirection = DirectionalityCls->of(context);_c3;_c2;_c1;
}

void SizedOverflowBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(<Size>make<DiagnosticsPropertyCls>(__s("size"), size, nullptr));
}

OffstageCls::OffstageCls(Widget child, Key key, bool offstage) {
    {
        assert(offstage != nullptr);
    }
}

RenderOffstage OffstageCls::createRenderObject(BuildContext context) {
    return make<RenderOffstageCls>(offstage);
}

void OffstageCls::updateRenderObject(BuildContext context, RenderOffstage renderObject) {
    renderObject->offstage = offstage;
}

void OffstageCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("offstage"), offstage));
}

SingleChildRenderObjectElement OffstageCls::createElement() {
    return make<_OffstageElementCls>(this);
}

void _OffstageElementCls::debugVisitOnstageChildren(ElementVisitor visitor) {
    if (!(as<Offstage>(widget()))->offstage) {
        super->debugVisitOnstageChildren(visitor);
    }
}

AspectRatioCls::AspectRatioCls(double aspectRatio, Widget child, Key key) {
    {
        assert(aspectRatio != nullptr);
        assert(aspectRatio > 0.0);
    }
}

RenderAspectRatio AspectRatioCls::createRenderObject(BuildContext context) {
    return make<RenderAspectRatioCls>(aspectRatio);
}

void AspectRatioCls::updateRenderObject(BuildContext context, RenderAspectRatio renderObject) {
    renderObject->aspectRatio = aspectRatio;
}

void AspectRatioCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("aspectRatio"), aspectRatio));
}

IntrinsicWidthCls::IntrinsicWidthCls(Widget child, Key key, double stepHeight, double stepWidth) {
    {
        assert(stepWidth == nullptr || stepWidth >= 0.0);
        assert(stepHeight == nullptr || stepHeight >= 0.0);
    }
}

RenderIntrinsicWidth IntrinsicWidthCls::createRenderObject(BuildContext context) {
    return make<RenderIntrinsicWidthCls>(_stepWidth(), _stepHeight());
}

void IntrinsicWidthCls::updateRenderObject(BuildContext context, RenderIntrinsicWidth renderObject) {
    auto _c1 = renderObject;_c1.stepWidth = auto _c2 = _stepWidth();_c2.stepHeight = _stepHeight();_c2;_c1;
}

double IntrinsicWidthCls::_stepWidth() {
    return stepWidth == 0.0? nullptr : stepWidth;
}

double IntrinsicWidthCls::_stepHeight() {
    return stepHeight == 0.0? nullptr : stepHeight;
}

RenderIntrinsicHeight IntrinsicHeightCls::createRenderObject(BuildContext context) {
    return make<RenderIntrinsicHeightCls>();
}

BaselineCls::BaselineCls(double baseline, TextBaseline baselineType, Widget child, Key key) {
    {
        assert(baseline != nullptr);
        assert(baselineType != nullptr);
    }
}

RenderBaseline BaselineCls::createRenderObject(BuildContext context) {
    return make<RenderBaselineCls>(baseline, baselineType);
}

void BaselineCls::updateRenderObject(BuildContext context, RenderBaseline renderObject) {
    auto _c1 = renderObject;_c1.baseline = auto _c2 = baseline;_c2.baselineType = baselineType;_c2;_c1;
}

RenderSliverToBoxAdapter SliverToBoxAdapterCls::createRenderObject(BuildContext context) {
    return make<RenderSliverToBoxAdapterCls>();
}

SliverPaddingCls::SliverPaddingCls(Key key, EdgeInsetsGeometry padding, Widget sliver) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(padding != nullptr);
    }
}

RenderSliverPadding SliverPaddingCls::createRenderObject(BuildContext context) {
    return make<RenderSliverPaddingCls>(padding, DirectionalityCls->of(context));
}

void SliverPaddingCls::updateRenderObject(BuildContext context, RenderSliverPadding renderObject) {
    auto _c1 = renderObject;_c1.padding = auto _c2 = padding;_c2.textDirection = DirectionalityCls->of(context);_c2;_c1;
}

void SliverPaddingCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding));
}

AxisDirection getAxisDirectionFromAxisReverseAndDirectionality(BuildContext context, Axis axis, bool reverse) {
    ;
}

ListBodyCls::ListBodyCls(List<Widget> children, Key key, Axis mainAxis, bool reverse) {
    {
        assert(mainAxis != nullptr);
    }
}

RenderListBody ListBodyCls::createRenderObject(BuildContext context) {
    return make<RenderListBodyCls>(_getDirection(context));
}

void ListBodyCls::updateRenderObject(BuildContext context, RenderListBody renderObject) {
    renderObject->axisDirection() = _getDirection(context);
}

AxisDirection ListBodyCls::_getDirection(BuildContext context) {
    return getAxisDirectionFromAxisReverseAndDirectionality(context, mainAxis, reverse);
}

StackCls::StackCls(AlignmentGeometry alignment, List<Widget> children, Clip clipBehavior, StackFit fit, Key key, TextDirection textDirection) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderStack StackCls::createRenderObject(BuildContext context) {
    assert(_debugCheckHasDirectionality(context));
    return make<RenderStackCls>(alignment, textDirection | DirectionalityCls->maybeOf(context), fit, clipBehavior);
}

void StackCls::updateRenderObject(BuildContext context, RenderStack renderObject) {
    assert(_debugCheckHasDirectionality(context));
    auto _c1 = renderObject;_c1.alignment = auto _c2 = alignment;_c2.textDirection = auto _c3 = textDirection | DirectionalityCls->maybeOf(context);_c3.fit = auto _c4 = fit;_c4.clipBehavior = clipBehavior;_c4;_c3;_c2;_c1;
}

void StackCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    properties->add(<StackFit>make<EnumPropertyCls>(__s("fit"), fit));
    properties->add(<Clip>make<EnumPropertyCls>(__s("clipBehavior"), clipBehavior, ClipCls::hardEdge));
}

bool StackCls::_debugCheckHasDirectionality(BuildContext context) {
    if (is<AlignmentDirectional>(alignment) && textDirection == nullptr) {
        assert(debugCheckHasDirectionality(context, __s("to resolve the 'alignment' argument"), alignment == AlignmentDirectionalCls::topStart? __s("The default value for 'alignment' is AlignmentDirectional.topStart, which requires a text direction.") : nullptr, __sf("Instead of providing a Directionality widget, another solution would be passing a non-directional 'alignment', or an explicit 'textDirection', to the %s.", runtimeType)));
    }
    return true;
}

IndexedStackCls::IndexedStackCls(AlignmentGeometry alignment, List<Widget> children, int index, Key key, StackFit sizing, TextDirection textDirection) : Stack(sizing) {
}

RenderIndexedStack IndexedStackCls::createRenderObject(BuildContext context) {
    assert(_debugCheckHasDirectionality(context));
    return make<RenderIndexedStackCls>(index, alignment, textDirection | DirectionalityCls->maybeOf(context));
}

void IndexedStackCls::updateRenderObject(BuildContext context, RenderIndexedStack renderObject) {
    assert(_debugCheckHasDirectionality(context));
    auto _c1 = renderObject;_c1.index = auto _c2 = index;_c2.alignment = auto _c3 = alignment;_c3.textDirection = textDirection | DirectionalityCls->maybeOf(context);_c3;_c2;_c1;
}

PositionedCls::PositionedCls(double bottom, Widget child, double height, Key key, double left, double right, double top, double width) {
    {
        assert(left == nullptr || right == nullptr || width == nullptr);
        assert(top == nullptr || bottom == nullptr || height == nullptr);
    }
}

void PositionedCls::fromRect(Widget child, Key key, Rect rect)

void PositionedCls::fromRelativeRect(Widget child, Key key, RelativeRect rect)

void PositionedCls::fill(double bottom, Widget child, Key key, double left, double right, double top)

void PositionedCls::directional(double bottom, Widget child, double end, double height, Key key, double start, TextDirection textDirection, double top, double width) {
    assert(textDirection != nullptr);
    double left;
    double right;
    ;
    return make<PositionedCls>(key, left, top, right, bottom, width, height, child);
}

void PositionedCls::applyParentData(RenderObject renderObject) {
    assert(is<StackParentData>(renderObject->parentData));
    StackParentData parentData = as<StackParentData>(renderObject->parentData!);
    bool needsLayout = false;
    if (parentData->left != left) {
        parentData->left = left;
        needsLayout = true;
    }
    if (parentData->top != top) {
        parentData->top = top;
        needsLayout = true;
    }
    if (parentData->right != right) {
        parentData->right = right;
        needsLayout = true;
    }
    if (parentData->bottom != bottom) {
        parentData->bottom = bottom;
        needsLayout = true;
    }
    if (parentData->width != width) {
        parentData->width = width;
        needsLayout = true;
    }
    if (parentData->height != height) {
        parentData->height = height;
        needsLayout = true;
    }
    if (needsLayout) {
        AbstractNode targetParent = renderObject->parent();
        if (is<RenderObject>(targetParent)) {
            as<RenderObjectCls>(targetParent)->markNeedsLayout();
        }
    }
}

Type PositionedCls::debugTypicalAncestorWidgetClass() {
    return StackCls;
}

void PositionedCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("left"), left, nullptr));
    properties->add(make<DoublePropertyCls>(__s("top"), top, nullptr));
    properties->add(make<DoublePropertyCls>(__s("right"), right, nullptr));
    properties->add(make<DoublePropertyCls>(__s("bottom"), bottom, nullptr));
    properties->add(make<DoublePropertyCls>(__s("width"), width, nullptr));
    properties->add(make<DoublePropertyCls>(__s("height"), height, nullptr));
}

Widget PositionedDirectionalCls::build(BuildContext context) {
    return PositionedCls->directional(DirectionalityCls->of(context), start, top, end, bottom, width, height, child);
}

FlexCls::FlexCls(List<Widget> children, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, Key key, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection) {
    {
        assert(direction != nullptr);
        assert(mainAxisAlignment != nullptr);
        assert(mainAxisSize != nullptr);
        assert(crossAxisAlignment != nullptr);
        assert(verticalDirection != nullptr);
        assert(crossAxisAlignment != CrossAxisAlignmentCls::baseline || textBaseline != nullptr, __s("textBaseline is required if you specify the crossAxisAlignment with CrossAxisAlignment.baseline"));
        assert(clipBehavior != nullptr);
    }
}

TextDirection FlexCls::getEffectiveTextDirection(BuildContext context) {
    return textDirection | (_needTextDirection()? DirectionalityCls->maybeOf(context) : nullptr);
}

RenderFlex FlexCls::createRenderObject(BuildContext context) {
    return make<RenderFlexCls>(direction, mainAxisAlignment, mainAxisSize, crossAxisAlignment, getEffectiveTextDirection(context), verticalDirection, textBaseline, clipBehavior);
}

void FlexCls::updateRenderObject(BuildContext context, RenderFlex renderObject) {
    auto _c1 = renderObject;_c1.direction = auto _c2 = direction;_c2.mainAxisAlignment = auto _c3 = mainAxisAlignment;_c3.mainAxisSize = auto _c4 = mainAxisSize;_c4.crossAxisAlignment = auto _c5 = crossAxisAlignment;_c5.textDirection = auto _c6 = getEffectiveTextDirection(context);_c6.verticalDirection = auto _c7 = verticalDirection;_c7.textBaseline = auto _c8 = textBaseline;_c8.clipBehavior = clipBehavior;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

void FlexCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Axis>make<EnumPropertyCls>(__s("direction"), direction));
    properties->add(<MainAxisAlignment>make<EnumPropertyCls>(__s("mainAxisAlignment"), mainAxisAlignment));
    properties->add(<MainAxisSize>make<EnumPropertyCls>(__s("mainAxisSize"), mainAxisSize, MainAxisSizeCls::max));
    properties->add(<CrossAxisAlignment>make<EnumPropertyCls>(__s("crossAxisAlignment"), crossAxisAlignment));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    properties->add(<VerticalDirection>make<EnumPropertyCls>(__s("verticalDirection"), verticalDirection, VerticalDirectionCls::down));
    properties->add(<TextBaseline>make<EnumPropertyCls>(__s("textBaseline"), textBaseline, nullptr));
}

bool FlexCls::_needTextDirection() {
    assert(direction != nullptr);
    ;
}

RowCls::RowCls(List<Widget> children, CrossAxisAlignment crossAxisAlignment, Key key, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection) : Flex(AxisCls::horizontal) {
}

ColumnCls::ColumnCls(List<Widget> children, CrossAxisAlignment crossAxisAlignment, Key key, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection) : Flex(AxisCls::vertical) {
}

void FlexibleCls::applyParentData(RenderObject renderObject) {
    assert(is<FlexParentData>(renderObject->parentData));
    FlexParentData parentData = as<FlexParentData>(renderObject->parentData!);
    bool needsLayout = false;
    if (parentData->flex != flex) {
        parentData->flex = flex;
        needsLayout = true;
    }
    if (parentData->fit != fit) {
        parentData->fit = fit;
        needsLayout = true;
    }
    if (needsLayout) {
        AbstractNode targetParent = renderObject->parent();
        if (is<RenderObject>(targetParent)) {
            as<RenderObjectCls>(targetParent)->markNeedsLayout();
        }
    }
}

Type FlexibleCls::debugTypicalAncestorWidgetClass() {
    return FlexCls;
}

void FlexibleCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("flex"), flex));
}

ExpandedCls::ExpandedCls(Widget child, int flex, Key key) : Flexible(FlexFitCls::tight) {
}

WrapCls::WrapCls(WrapAlignment alignment, List<Widget> children, Clip clipBehavior, WrapCrossAlignment crossAxisAlignment, Axis direction, Key key, WrapAlignment runAlignment, double runSpacing, double spacing, TextDirection textDirection, VerticalDirection verticalDirection) {
    {
        assert(clipBehavior != nullptr);
    }
}

RenderWrap WrapCls::createRenderObject(BuildContext context) {
    return make<RenderWrapCls>(direction, alignment, spacing, runAlignment, runSpacing, crossAxisAlignment, textDirection | DirectionalityCls->maybeOf(context), verticalDirection, clipBehavior);
}

void WrapCls::updateRenderObject(BuildContext context, RenderWrap renderObject) {
    auto _c1 = renderObject;_c1.direction = auto _c2 = direction;_c2.alignment = auto _c3 = alignment;_c3.spacing = auto _c4 = spacing;_c4.runAlignment = auto _c5 = runAlignment;_c5.runSpacing = auto _c6 = runSpacing;_c6.crossAxisAlignment = auto _c7 = crossAxisAlignment;_c7.textDirection = auto _c8 = textDirection | DirectionalityCls->maybeOf(context);_c8.verticalDirection = auto _c9 = verticalDirection;_c9.clipBehavior = clipBehavior;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

void WrapCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Axis>make<EnumPropertyCls>(__s("direction"), direction));
    properties->add(<WrapAlignment>make<EnumPropertyCls>(__s("alignment"), alignment));
    properties->add(make<DoublePropertyCls>(__s("spacing"), spacing));
    properties->add(<WrapAlignment>make<EnumPropertyCls>(__s("runAlignment"), runAlignment));
    properties->add(make<DoublePropertyCls>(__s("runSpacing"), runSpacing));
    properties->add(<WrapCrossAlignment>make<EnumPropertyCls>(__s("crossAxisAlignment"), crossAxisAlignment));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    properties->add(<VerticalDirection>make<EnumPropertyCls>(__s("verticalDirection"), verticalDirection, VerticalDirectionCls::down));
}

FlowCls::FlowCls(List<Widget> children, Clip clipBehavior, FlowDelegate delegate, Key key) : MultiChildRenderObjectWidget(RepaintBoundaryCls->wrapAll(children)) {
    {
        assert(delegate != nullptr);
        assert(clipBehavior != nullptr);
    }
}

void FlowCls::unwrapped(List<Widget> children, Clip clipBehavior, FlowDelegate delegate, Key key)

RenderFlow FlowCls::createRenderObject(BuildContext context) {
    return make<RenderFlowCls>(delegate, clipBehavior);
}

void FlowCls::updateRenderObject(BuildContext context, RenderFlow renderObject) {
    renderObject->delegate = delegate;
    renderObject->clipBehavior = clipBehavior;
}

RichTextCls::RichTextCls(Key key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, SelectionRegistrar selectionRegistrar, bool softWrap, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) : MultiChildRenderObjectWidget(_extractChildren(text)) {
    {
        assert(text != nullptr);
        assert(textAlign != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(textScaleFactor != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(textWidthBasis != nullptr);
        assert(selectionRegistrar == nullptr || selectionColor != nullptr);
    }
}

RenderParagraph RichTextCls::createRenderObject(BuildContext context) {
    assert(textDirection != nullptr || debugCheckHasDirectionality(context));
    return make<RenderParagraphCls>(text, textAlign, textDirection | DirectionalityCls->of(context), softWrap, overflow, textScaleFactor, maxLines, strutStyle, textWidthBasis, textHeightBehavior, locale | LocalizationsCls->maybeLocaleOf(context), selectionRegistrar, selectionColor);
}

void RichTextCls::updateRenderObject(BuildContext context, RenderParagraph renderObject) {
    assert(textDirection != nullptr || debugCheckHasDirectionality(context));
    auto _c1 = renderObject;_c1.text = auto _c2 = text;_c2.textAlign = auto _c3 = textAlign;_c3.textDirection = auto _c4 = textDirection | DirectionalityCls->of(context);_c4.softWrap = auto _c5 = softWrap;_c5.overflow = auto _c6 = overflow;_c6.textScaleFactor = auto _c7 = textScaleFactor;_c7.maxLines = auto _c8 = maxLines;_c8.strutStyle = auto _c9 = strutStyle;_c9.textWidthBasis = auto _c10 = textWidthBasis;_c10.textHeightBehavior = auto _c11 = textHeightBehavior;_c11.locale = auto _c12 = locale | LocalizationsCls->maybeLocaleOf(context);_c12.registrar = auto _c13 = selectionRegistrar;_c13.selectionColor = selectionColor;_c13;_c12;_c11;_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

void RichTextCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>(__s("textAlign"), textAlign, TextAlignCls::start));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    properties->add(make<FlagPropertyCls>(__s("softWrap"), softWrap, __s("wrapping at box width"), __s("no wrapping except at line break characters"), true));
    properties->add(<TextOverflow>make<EnumPropertyCls>(__s("overflow"), overflow, TextOverflowCls::clip));
    properties->add(make<DoublePropertyCls>(__s("textScaleFactor"), textScaleFactor, 1.0));
    properties->add(make<IntPropertyCls>(__s("maxLines"), maxLines, __s("unlimited")));
    properties->add(<TextWidthBasis>make<EnumPropertyCls>(__s("textWidthBasis"), textWidthBasis, TextWidthBasisCls::parent));
    properties->add(make<StringPropertyCls>(__s("text"), text->toPlainText()));
    properties->add(<Locale>make<DiagnosticsPropertyCls>(__s("locale"), locale, nullptr));
    properties->add(<StrutStyle>make<DiagnosticsPropertyCls>(__s("strutStyle"), strutStyle, nullptr));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>(__s("textHeightBehavior"), textHeightBehavior, nullptr));
}

List<Widget> RichTextCls::_extractChildren(InlineSpan span) {
    int index = 0;
    List<Widget> result = makeList();
    span->visitChildren([=] (InlineSpan span) {
        if (is<WidgetSpan>(span)) {
            result->add(make<SemanticsCls>(make<PlaceholderSpanIndexSemanticsTagCls>(index++), as<WidgetSpanCls>(span)->child));
        }
        return true;
    });
    return result;
}

RawImageCls::RawImageCls(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, Key key, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, double width) {
    {
        assert(scale != nullptr);
        assert(alignment != nullptr);
        assert(repeat != nullptr);
        assert(matchTextDirection != nullptr);
        assert(isAntiAlias != nullptr);
    }
}

RenderImage RawImageCls::createRenderObject(BuildContext context) {
    assert((!matchTextDirection && is<Alignment>(alignment)) || debugCheckHasDirectionality(context));
    assert(image?->debugGetOpenHandleStackTraces()?->isNotEmpty | true, __s("Creator of a RawImage disposed of the image when the RawImage still needed it."));
    return make<RenderImageCls>(image?->clone(), debugImageLabel, width, height, scale, color, opacity, colorBlendMode, fit, alignment, repeat, centerSlice, matchTextDirection, matchTextDirection || !is<Alignment>(alignment)? DirectionalityCls->of(context) : nullptr, invertColors, isAntiAlias, filterQuality);
}

void RawImageCls::updateRenderObject(BuildContext context, RenderImage renderObject) {
    assert(image?->debugGetOpenHandleStackTraces()?->isNotEmpty | true, __s("Creator of a RawImage disposed of the image when the RawImage still needed it."));
    auto _c1 = renderObject;_c1.image = auto _c2 = image?->clone();_c2.debugImageLabel = auto _c3 = debugImageLabel;_c3.width = auto _c4 = width;_c4.height = auto _c5 = height;_c5.scale = auto _c6 = scale;_c6.color = auto _c7 = color;_c7.opacity = auto _c8 = opacity;_c8.colorBlendMode = auto _c9 = colorBlendMode;_c9.fit = auto _c10 = fit;_c10.alignment = auto _c11 = alignment;_c11.repeat = auto _c12 = repeat;_c12.centerSlice = auto _c13 = centerSlice;_c13.matchTextDirection = auto _c14 = matchTextDirection;_c14.textDirection = matchTextDirection || !is<Alignment>(alignment)? DirectionalityCls->of(context) : auto _c15 = nullptr;_c15.invertColors = auto _c16 = invertColors;_c16.isAntiAlias = auto _c17 = isAntiAlias;_c17.filterQuality = filterQuality;_c17;_c16;_c15;_c14;_c13;_c12;_c11;_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

void RawImageCls::didUnmountRenderObject(RenderImage renderObject) {
    renderObject->image = nullptr;
}

void RawImageCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Image>make<DiagnosticsPropertyCls>(__s("image"), image));
    properties->add(make<DoublePropertyCls>(__s("width"), width, nullptr));
    properties->add(make<DoublePropertyCls>(__s("height"), height, nullptr));
    properties->add(make<DoublePropertyCls>(__s("scale"), scale, 1.0));
    properties->add(make<ColorPropertyCls>(__s("color"), color, nullptr));
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("opacity"), opacity, nullptr));
    properties->add(<BlendMode>make<EnumPropertyCls>(__s("colorBlendMode"), colorBlendMode, nullptr));
    properties->add(<BoxFit>make<EnumPropertyCls>(__s("fit"), fit, nullptr));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment, nullptr));
    properties->add(<ImageRepeat>make<EnumPropertyCls>(__s("repeat"), repeat, ImageRepeatCls::noRepeat));
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("centerSlice"), centerSlice, nullptr));
    properties->add(make<FlagPropertyCls>(__s("matchTextDirection"), matchTextDirection, __s("match text direction")));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("invertColors"), invertColors));
    properties->add(<FilterQuality>make<EnumPropertyCls>(__s("filterQuality"), filterQuality));
}

DefaultAssetBundleCls::DefaultAssetBundleCls(AssetBundle bundle, Widget child, Key key) {
    {
        assert(bundle != nullptr);
        assert(child != nullptr);
    }
}

AssetBundle DefaultAssetBundleCls::of(BuildContext context) {
    DefaultAssetBundle result = context-><DefaultAssetBundle>dependOnInheritedWidgetOfExactType();
    return result?->bundle | rootBundle;
}

bool DefaultAssetBundleCls::updateShouldNotify(DefaultAssetBundle oldWidget) {
    return bundle != oldWidget->bundle;
}

WidgetToRenderBoxAdapterCls::WidgetToRenderBoxAdapterCls(VoidCallback onBuild, VoidCallback onUnmount, RenderBox renderBox) : LeafRenderObjectWidget(make<GlobalObjectKeyCls>(renderBox)) {
    {
        assert(renderBox != nullptr);
    }
}

RenderBox WidgetToRenderBoxAdapterCls::createRenderObject(BuildContext context) {
    return renderBox;
}

void WidgetToRenderBoxAdapterCls::updateRenderObject(BuildContext context, RenderBox renderObject) {
    onBuild?->call();
}

void WidgetToRenderBoxAdapterCls::didUnmountRenderObject(RenderObject renderObject) {
    assert(renderObject == renderBox);
    onUnmount?->call();
}

ListenerCls::ListenerCls(HitTestBehavior behavior, Widget child, Key key, PointerCancelEventListener onPointerCancel, PointerDownEventListener onPointerDown, PointerHoverEventListener onPointerHover, PointerMoveEventListener onPointerMove, PointerPanZoomEndEventListener onPointerPanZoomEnd, PointerPanZoomStartEventListener onPointerPanZoomStart, PointerPanZoomUpdateEventListener onPointerPanZoomUpdate, PointerSignalEventListener onPointerSignal, PointerUpEventListener onPointerUp) {
    {
        assert(behavior != nullptr);
    }
}

RenderPointerListener ListenerCls::createRenderObject(BuildContext context) {
    return make<RenderPointerListenerCls>(onPointerDown, onPointerMove, onPointerUp, onPointerHover, onPointerCancel, onPointerPanZoomStart, onPointerPanZoomUpdate, onPointerPanZoomEnd, onPointerSignal, behavior);
}

void ListenerCls::updateRenderObject(BuildContext context, RenderPointerListener renderObject) {
    auto _c1 = renderObject;_c1.onPointerDown = auto _c2 = onPointerDown;_c2.onPointerMove = auto _c3 = onPointerMove;_c3.onPointerUp = auto _c4 = onPointerUp;_c4.onPointerHover = auto _c5 = onPointerHover;_c5.onPointerCancel = auto _c6 = onPointerCancel;_c6.onPointerPanZoomStart = auto _c7 = onPointerPanZoomStart;_c7.onPointerPanZoomUpdate = auto _c8 = onPointerPanZoomUpdate;_c8.onPointerPanZoomEnd = auto _c9 = onPointerPanZoomEnd;_c9.onPointerSignal = auto _c10 = onPointerSignal;_c10.behavior = behavior;_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

void ListenerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    List<String> list1 = make<ListCls<>>();if (onPointerDown != nullptr) {    list1.add(ArrayItem);}if (onPointerMove != nullptr) {    list1.add(ArrayItem);}if (onPointerUp != nullptr) {    list1.add(ArrayItem);}if (onPointerHover != nullptr) {    list1.add(ArrayItem);}if (onPointerCancel != nullptr) {    list1.add(ArrayItem);}if (onPointerPanZoomStart != nullptr) {    list1.add(ArrayItem);}if (onPointerPanZoomUpdate != nullptr) {    list1.add(ArrayItem);}if (onPointerPanZoomEnd != nullptr) {    list1.add(ArrayItem);}if (onPointerSignal != nullptr) {    list1.add(ArrayItem);}List<String> listeners = list1;
    properties->add(<String>make<IterablePropertyCls>(__s("listeners"), listeners, __s("<none>")));
    properties->add(<HitTestBehavior>make<EnumPropertyCls>(__s("behavior"), behavior));
}

MouseRegionCls::MouseRegionCls(Widget child, MouseCursor cursor, HitTestBehavior hitTestBehavior, Key key, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque) {
    {
        assert(cursor != nullptr);
        assert(opaque != nullptr);
    }
}

RenderMouseRegion MouseRegionCls::createRenderObject(BuildContext context) {
    return make<RenderMouseRegionCls>(onEnter, onHover, onExit, cursor, opaque, hitTestBehavior);
}

void MouseRegionCls::updateRenderObject(BuildContext context, RenderMouseRegion renderObject) {
    auto _c1 = renderObject;_c1.onEnter = auto _c2 = onEnter;_c2.onHover = auto _c3 = onHover;_c3.onExit = auto _c4 = onExit;_c4.cursor = auto _c5 = cursor;_c5.opaque = auto _c6 = opaque;_c6.hitTestBehavior = hitTestBehavior;_c6;_c5;_c4;_c3;_c2;_c1;
}

void MouseRegionCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    List<String> listeners = makeList();
    if (onEnter != nullptr) {
        listeners->add(__s("enter"));
    }
    if (onExit != nullptr) {
        listeners->add(__s("exit"));
    }
    if (onHover != nullptr) {
        listeners->add(__s("hover"));
    }
    properties->add(<String>make<IterablePropertyCls>(__s("listeners"), listeners, __s("<none>")));
    properties->add(<MouseCursor>make<DiagnosticsPropertyCls>(__s("cursor"), cursor, nullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("opaque"), opaque, true));
}

void RepaintBoundaryCls::wrap(Widget child, int childIndex) {
    assert(child != nullptr);
    Key key = child->key != nullptr? <Key>make<ValueKeyCls>(child->key!) : <int>make<ValueKeyCls>(childIndex);
    return make<RepaintBoundaryCls>(key, child);
}

List<RepaintBoundary> RepaintBoundaryCls::wrapAll(List<Widget> widgets) {
    return list1;
}

RenderRepaintBoundary RepaintBoundaryCls::createRenderObject(BuildContext context) {
    return make<RenderRepaintBoundaryCls>();
}

IgnorePointerCls::IgnorePointerCls(Widget child, bool ignoring, bool ignoringSemantics, Key key) {
    {
            List<RepaintBoundary> list1 = make<ListCls<>>();    for (;  < widgets->length(); ++i) {            ;        }    {        list1.add(ArrayItem);    }assert(ignoring != nullptr);
    }
}

RenderIgnorePointer IgnorePointerCls::createRenderObject(BuildContext context) {
    return make<RenderIgnorePointerCls>(ignoring, ignoringSemantics);
}

void IgnorePointerCls::updateRenderObject(BuildContext context, RenderIgnorePointer renderObject) {
    auto _c1 = renderObject;_c1.ignoring = auto _c2 = ignoring;_c2.ignoringSemantics = ignoringSemantics;_c2;_c1;
}

void IgnorePointerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoring"), ignoring));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoringSemantics"), ignoringSemantics, nullptr));
}

AbsorbPointerCls::AbsorbPointerCls(bool absorbing, Widget child, bool ignoringSemantics, Key key) {
    {
        assert(absorbing != nullptr);
    }
}

RenderAbsorbPointer AbsorbPointerCls::createRenderObject(BuildContext context) {
    return make<RenderAbsorbPointerCls>(absorbing, ignoringSemantics);
}

void AbsorbPointerCls::updateRenderObject(BuildContext context, RenderAbsorbPointer renderObject) {
    auto _c1 = renderObject;_c1.absorbing = auto _c2 = absorbing;_c2.ignoringSemantics = ignoringSemantics;_c2;_c1;
}

void AbsorbPointerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("absorbing"), absorbing));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoringSemantics"), ignoringSemantics, nullptr));
}

RenderMetaData MetaDataCls::createRenderObject(BuildContext context) {
    return make<RenderMetaDataCls>(metaData, behavior);
}

void MetaDataCls::updateRenderObject(BuildContext context, RenderMetaData renderObject) {
    auto _c1 = renderObject;_c1.metaData = auto _c2 = metaData;_c2.behavior = behavior;_c2;_c1;
}

void MetaDataCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<HitTestBehavior>make<EnumPropertyCls>(__s("behavior"), behavior));
    properties->add(<Object>make<DiagnosticsPropertyCls>(__s("metaData"), metaData));
}

SemanticsCls::SemanticsCls(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, Widget child, bool container, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool excludeSemantics, bool explicitChildNodes, bool focusable, bool focused, bool header, bool hidden, String hint, bool image, bool inMutuallyExclusiveGroup, String increasedValue, Key key, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, String onLongPressHint, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorForwardByCharacter, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, String onTapHint, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value) {
    {
        this->fromProperties(key, child, container, explicitChildNodes, excludeSemantics, make<SemanticsPropertiesCls>(enabled, checked, toggled, selected, button, slider, keyboardKey, link, header, textField, readOnly, focusable, focused, inMutuallyExclusiveGroup, obscured, multiline, scopesRoute, namesRoute, hidden, image, liveRegion, maxValueLength, currentValueLength, label, attributedLabel, value, attributedValue, increasedValue, attributedIncreasedValue, decreasedValue, attributedDecreasedValue, hint, attributedHint, tooltip, textDirection, sortKey, tagForChildren, onTap, onLongPress, onScrollLeft, onScrollRight, onScrollUp, onScrollDown, onIncrease, onDecrease, onCopy, onCut, onPaste, onMoveCursorForwardByCharacter, onMoveCursorBackwardByCharacter, onDidGainAccessibilityFocus, onDidLoseAccessibilityFocus, onDismiss, onSetSelection, onSetText, customSemanticsActions, onTapHint != nullptr || onLongPressHint != nullptr? make<SemanticsHintOverridesCls>(onTapHint, onLongPressHint) : nullptr));
    }
}

void SemanticsCls::fromProperties(Widget child, bool container, bool excludeSemantics, bool explicitChildNodes, Key key, SemanticsProperties properties)

RenderSemanticsAnnotations SemanticsCls::createRenderObject(BuildContext context) {
    return make<RenderSemanticsAnnotationsCls>(container, explicitChildNodes, excludeSemantics, properties, _getTextDirection(context));
}

void SemanticsCls::updateRenderObject(BuildContext context, RenderSemanticsAnnotations renderObject) {
    auto _c1 = renderObject;_c1.container = auto _c2 = container;_c2.explicitChildNodes = auto _c3 = explicitChildNodes;_c3.excludeSemantics = auto _c4 = excludeSemantics;_c4.properties = auto _c5 = properties;_c5.textDirection = _getTextDirection(context);_c5;_c4;_c3;_c2;_c1;
}

void SemanticsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("container"), container));
    properties->add(<SemanticsProperties>make<DiagnosticsPropertyCls>(__s("properties"), this->properties));
    this->properties->debugFillProperties(properties);
}

TextDirection SemanticsCls::_getTextDirection(BuildContext context) {
    if (properties->textDirection != nullptr) {
        return properties->textDirection;
    }
    bool containsText = properties->attributedLabel != nullptr || properties->label != nullptr || properties->value != nullptr || properties->hint != nullptr || properties->tooltip != nullptr;
    if (!containsText) {
        return nullptr;
    }
    return DirectionalityCls->maybeOf(context);
}

RenderMergeSemantics MergeSemanticsCls::createRenderObject(BuildContext context) {
    return make<RenderMergeSemanticsCls>();
}

RenderBlockSemantics BlockSemanticsCls::createRenderObject(BuildContext context) {
    return make<RenderBlockSemanticsCls>(blocking);
}

void BlockSemanticsCls::updateRenderObject(BuildContext context, RenderBlockSemantics renderObject) {
    renderObject->blocking = blocking;
}

void BlockSemanticsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("blocking"), blocking));
}

ExcludeSemanticsCls::ExcludeSemanticsCls(Widget child, bool excluding, Key key) {
    {
        assert(excluding != nullptr);
    }
}

RenderExcludeSemantics ExcludeSemanticsCls::createRenderObject(BuildContext context) {
    return make<RenderExcludeSemanticsCls>(excluding);
}

void ExcludeSemanticsCls::updateRenderObject(BuildContext context, RenderExcludeSemantics renderObject) {
    renderObject->excluding = excluding;
}

void ExcludeSemanticsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("excluding"), excluding));
}

IndexedSemanticsCls::IndexedSemanticsCls(Widget child, int index, Key key) {
    {
        assert(index != nullptr);
    }
}

RenderIndexedSemantics IndexedSemanticsCls::createRenderObject(BuildContext context) {
    return make<RenderIndexedSemanticsCls>(index);
}

void IndexedSemanticsCls::updateRenderObject(BuildContext context, RenderIndexedSemantics renderObject) {
    renderObject->index = index;
}

void IndexedSemanticsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("index"), index));
}

KeyedSubtreeCls::KeyedSubtreeCls(Widget child, Key key) {
    {
        assert(child != nullptr);
    }
}

void KeyedSubtreeCls::wrap(Widget child, int childIndex) {
    Key key = child->key != nullptr? <Key>make<ValueKeyCls>(child->key!) : <int>make<ValueKeyCls>(childIndex);
    return make<KeyedSubtreeCls>(key, child);
}

List<Widget> KeyedSubtreeCls::ensureUniqueKeysForList(List<Widget> items, int baseIndex) {
    if (items == nullptr || items->isEmpty()) {
        return items;
    }
    List<Widget> itemsWithUniqueKeys = makeList();
    int itemIndex = baseIndex;
    for (Widget item : items) {
        itemsWithUniqueKeys->add(KeyedSubtreeCls->wrap(item, itemIndex));
        itemIndex += 1;
    }
    assert(!debugItemsHaveDuplicateKeys(itemsWithUniqueKeys));
    return itemsWithUniqueKeys;
}

Widget KeyedSubtreeCls::build(BuildContext context) {
    return child;
}

BuilderCls::BuilderCls(WidgetBuilder builder, Key key) {
    {
        assert(builder != nullptr);
    }
}

Widget BuilderCls::build(BuildContext context) {
    return builder(context);
}

StatefulBuilderCls::StatefulBuilderCls(StatefulWidgetBuilder builder, Key key) {
    {
        assert(builder != nullptr);
    }
}

State<StatefulBuilder> StatefulBuilderCls::createState() {
    return make<_StatefulBuilderStateCls>();
}

Widget _StatefulBuilderStateCls::build(BuildContext context) {
    return widget()->builder(context, setState);
}

ColoredBoxCls::ColoredBoxCls(Widget child, Color color, Key key) {
    {
        assert(color != nullptr);
    }
}

RenderObject ColoredBoxCls::createRenderObject(BuildContext context) {
    return make<_RenderColoredBoxCls>(color);
}

void ColoredBoxCls::updateRenderObject(BuildContext context, RenderObject renderObject) {
    (as<_RenderColoredBox>(renderObject))->color = color;
}

void ColoredBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Color>make<DiagnosticsPropertyCls>(__s("color"), color));
}

Color _RenderColoredBoxCls::color() {
    return _color;
}

void _RenderColoredBoxCls::color(Color value) {
    assert(value != nullptr);
    if (value == _color) {
        return;
    }
    _color = value;
    markNeedsPaint();
}

void _RenderColoredBoxCls::paint(PaintingContext context, Offset offset) {
    if (size() > SizeCls::zero) {
            auto _c1 = make<PaintCls>();    _c1.color() = color();context->canvas()->drawRect(offset & size(), _c1);
    }
    if (child != nullptr) {
        context->paintChild(child!, offset);
    }
}

_RenderColoredBoxCls::_RenderColoredBoxCls(Color color) : RenderProxyBoxWithHitTestBehavior(HitTestBehaviorCls::opaque) {
    {
        _color = color;
    }
}
