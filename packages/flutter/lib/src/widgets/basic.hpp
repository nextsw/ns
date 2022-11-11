#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BASIC
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BASIC
#include <base.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "binding.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "localizations.hpp"
#include "widget_span.hpp"


class _UbiquitousInheritedElementCls : public InheritedElementCls {
public:

    virtual void setDependencies(Element dependent, Object value);

    virtual Object getDependencies(Element dependent);

    virtual void notifyClients(InheritedWidget oldWidget);

private:

     _UbiquitousInheritedElementCls(Unknown widget);
    static void _recurseChildren(Element element, ElementVisitor visitor);

};
using _UbiquitousInheritedElement = std::shared_ptr<_UbiquitousInheritedElementCls>;

class _UbiquitousInheritedWidgetCls : public InheritedWidgetCls {
public:

    virtual InheritedElement createElement();

private:

     _UbiquitousInheritedWidgetCls(Widget child, Key key);
};
using _UbiquitousInheritedWidget = std::shared_ptr<_UbiquitousInheritedWidgetCls>;

class DirectionalityCls : public _UbiquitousInheritedWidgetCls {
public:
    TextDirection textDirection;


     DirectionalityCls(Widget child, Key key, TextDirection textDirection);

    static TextDirection of(BuildContext context);

    static TextDirection maybeOf(BuildContext context);

    virtual bool updateShouldNotify(Directionality oldWidget);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Directionality = std::shared_ptr<DirectionalityCls>;

class OpacityCls : public SingleChildRenderObjectWidgetCls {
public:
    double opacity;

    bool alwaysIncludeSemantics;


     OpacityCls(bool alwaysIncludeSemantics, Widget child, Key key, double opacity);

    virtual RenderOpacity createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderOpacity renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Opacity = std::shared_ptr<OpacityCls>;

class ShaderMaskCls : public SingleChildRenderObjectWidgetCls {
public:
    ShaderCallback shaderCallback;

    BlendMode blendMode;


     ShaderMaskCls(BlendMode blendMode, Widget child, Key key, ShaderCallback shaderCallback);

    virtual RenderShaderMask createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderShaderMask renderObject);

private:

};
using ShaderMask = std::shared_ptr<ShaderMaskCls>;

class BackdropFilterCls : public SingleChildRenderObjectWidgetCls {
public:
    ImageFilter filter;

    BlendMode blendMode;


     BackdropFilterCls(BlendMode blendMode, Widget child, ImageFilter filter, Key key);

    virtual RenderBackdropFilter createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderBackdropFilter renderObject);

private:

};
using BackdropFilter = std::shared_ptr<BackdropFilterCls>;

class CustomPaintCls : public SingleChildRenderObjectWidgetCls {
public:
    CustomPainter painter;

    CustomPainter foregroundPainter;

    Size size;

    bool isComplex;

    bool willChange;


     CustomPaintCls(Widget child, CustomPainter foregroundPainter, bool isComplex, Key key, CustomPainter painter, Size size, bool willChange);

    virtual RenderCustomPaint createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderCustomPaint renderObject);

    virtual void didUnmountRenderObject(RenderCustomPaint renderObject);

private:

};
using CustomPaint = std::shared_ptr<CustomPaintCls>;

class ClipRectCls : public SingleChildRenderObjectWidgetCls {
public:
    CustomClipper<Rect> clipper;

    Clip clipBehavior;


     ClipRectCls(Widget child, Clip clipBehavior, CustomClipper<Rect> clipper, Key key);

    virtual RenderClipRect createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderClipRect renderObject);

    virtual void didUnmountRenderObject(RenderClipRect renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ClipRect = std::shared_ptr<ClipRectCls>;

class ClipRRectCls : public SingleChildRenderObjectWidgetCls {
public:
    BorderRadiusGeometry borderRadius;

    CustomClipper<RRect> clipper;

    Clip clipBehavior;


     ClipRRectCls(BorderRadiusGeometry borderRadius, Widget child, Clip clipBehavior, CustomClipper<RRect> clipper, Key key);

    virtual RenderClipRRect createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderClipRRect renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ClipRRect = std::shared_ptr<ClipRRectCls>;

class ClipOvalCls : public SingleChildRenderObjectWidgetCls {
public:
    CustomClipper<Rect> clipper;

    Clip clipBehavior;


     ClipOvalCls(Widget child, Clip clipBehavior, CustomClipper<Rect> clipper, Key key);

    virtual RenderClipOval createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderClipOval renderObject);

    virtual void didUnmountRenderObject(RenderClipOval renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ClipOval = std::shared_ptr<ClipOvalCls>;

class ClipPathCls : public SingleChildRenderObjectWidgetCls {
public:
    CustomClipper<Path> clipper;

    Clip clipBehavior;


     ClipPathCls(Widget child, Clip clipBehavior, CustomClipper<Path> clipper, Key key);

    static Widget shape(Widget child, Clip clipBehavior, Key key, ShapeBorder shape);

    virtual RenderClipPath createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderClipPath renderObject);

    virtual void didUnmountRenderObject(RenderClipPath renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ClipPath = std::shared_ptr<ClipPathCls>;

class PhysicalModelCls : public SingleChildRenderObjectWidgetCls {
public:
    BoxShape shape;

    Clip clipBehavior;

    BorderRadius borderRadius;

    double elevation;

    Color color;

    Color shadowColor;


     PhysicalModelCls(BorderRadius borderRadius, Widget child, Clip clipBehavior, Color color, double elevation, Key key, Color shadowColor, BoxShape shape);

    virtual RenderPhysicalModel createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderPhysicalModel renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PhysicalModel = std::shared_ptr<PhysicalModelCls>;

class PhysicalShapeCls : public SingleChildRenderObjectWidgetCls {
public:
    CustomClipper<Path> clipper;

    Clip clipBehavior;

    double elevation;

    Color color;

    Color shadowColor;


     PhysicalShapeCls(Widget child, Clip clipBehavior, CustomClipper<Path> clipper, Color color, double elevation, Key key, Color shadowColor);

    virtual RenderPhysicalShape createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderPhysicalShape renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PhysicalShape = std::shared_ptr<PhysicalShapeCls>;

class TransformCls : public SingleChildRenderObjectWidgetCls {
public:
    Matrix4 transform;

    Offset origin;

    AlignmentGeometry alignment;

    bool transformHitTests;

    FilterQuality filterQuality;


     TransformCls(AlignmentGeometry alignment, Widget child, FilterQuality filterQuality, Key key, Offset origin, Matrix4 transform, bool transformHitTests);

    virtual void  rotate(AlignmentGeometry alignment, double angle, Widget child, FilterQuality filterQuality, Key key, Offset origin, bool transformHitTests);

    virtual void  translate(Widget child, FilterQuality filterQuality, Key key, Offset offset, bool transformHitTests);

    virtual void  scale(AlignmentGeometry alignment, Widget child, FilterQuality filterQuality, Key key, Offset origin, double scale, double scaleX, double scaleY, bool transformHitTests);

    virtual RenderTransform createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderTransform renderObject);

private:

    static Matrix4 _computeRotation(double radians);

    static Matrix4 _createZRotation(double sin, double cos);

};
using Transform = std::shared_ptr<TransformCls>;

class CompositedTransformTargetCls : public SingleChildRenderObjectWidgetCls {
public:
    LayerLink link;


     CompositedTransformTargetCls(Widget child, Key key, LayerLink link);

    virtual RenderLeaderLayer createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderLeaderLayer renderObject);

private:

};
using CompositedTransformTarget = std::shared_ptr<CompositedTransformTargetCls>;

class CompositedTransformFollowerCls : public SingleChildRenderObjectWidgetCls {
public:
    LayerLink link;

    bool showWhenUnlinked;

    Alignment targetAnchor;

    Alignment followerAnchor;

    Offset offset;


     CompositedTransformFollowerCls(Widget child, Alignment followerAnchor, Key key, LayerLink link, Offset offset, bool showWhenUnlinked, Alignment targetAnchor);

    virtual RenderFollowerLayer createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderFollowerLayer renderObject);

private:

};
using CompositedTransformFollower = std::shared_ptr<CompositedTransformFollowerCls>;

class FittedBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    BoxFit fit;

    AlignmentGeometry alignment;

    Clip clipBehavior;


     FittedBoxCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, BoxFit fit, Key key);

    virtual RenderFittedBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderFittedBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using FittedBox = std::shared_ptr<FittedBoxCls>;

class FractionalTranslationCls : public SingleChildRenderObjectWidgetCls {
public:
    Offset translation;

    bool transformHitTests;


     FractionalTranslationCls(Widget child, Key key, bool transformHitTests, Offset translation);

    virtual RenderFractionalTranslation createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderFractionalTranslation renderObject);

private:

};
using FractionalTranslation = std::shared_ptr<FractionalTranslationCls>;

class RotatedBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    int quarterTurns;


     RotatedBoxCls(Widget child, Key key, int quarterTurns);

    virtual RenderRotatedBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderRotatedBox renderObject);

private:

};
using RotatedBox = std::shared_ptr<RotatedBoxCls>;

class PaddingCls : public SingleChildRenderObjectWidgetCls {
public:
    EdgeInsetsGeometry padding;


     PaddingCls(Widget child, Key key, EdgeInsetsGeometry padding);

    virtual RenderPadding createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderPadding renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Padding = std::shared_ptr<PaddingCls>;

class AlignCls : public SingleChildRenderObjectWidgetCls {
public:
    AlignmentGeometry alignment;

    double widthFactor;

    double heightFactor;


     AlignCls(AlignmentGeometry alignment, Widget child, double heightFactor, Key key, double widthFactor);

    virtual RenderPositionedBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderPositionedBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Align = std::shared_ptr<AlignCls>;

class CenterCls : public AlignCls {
public:

     CenterCls(Widget child, double heightFactor, Key key, double widthFactor);
private:

};
using Center = std::shared_ptr<CenterCls>;

class CustomSingleChildLayoutCls : public SingleChildRenderObjectWidgetCls {
public:
    SingleChildLayoutDelegate delegate;


     CustomSingleChildLayoutCls(Widget child, SingleChildLayoutDelegate delegate, Key key);

    virtual RenderCustomSingleChildLayoutBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderCustomSingleChildLayoutBox renderObject);

private:

};
using CustomSingleChildLayout = std::shared_ptr<CustomSingleChildLayoutCls>;

class LayoutIdCls : public ParentDataWidgetCls<MultiChildLayoutParentData> {
public:
    Object id;


     LayoutIdCls(Widget child, Object id, Key key);

    virtual void applyParentData(RenderObject renderObject);

    virtual Type debugTypicalAncestorWidgetClass();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using LayoutId = std::shared_ptr<LayoutIdCls>;

class CustomMultiChildLayoutCls : public MultiChildRenderObjectWidgetCls {
public:
    MultiChildLayoutDelegate delegate;


     CustomMultiChildLayoutCls(List<Widget> children, MultiChildLayoutDelegate delegate, Key key);

    virtual RenderCustomMultiChildLayoutBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderCustomMultiChildLayoutBox renderObject);

private:

};
using CustomMultiChildLayout = std::shared_ptr<CustomMultiChildLayoutCls>;

class SizedBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    double width;

    double height;


     SizedBoxCls(Widget child, double height, Key key, double width);
    virtual void  expand(Widget child, Key key);

    virtual void  shrink(Widget child, Key key);

    virtual void  fromSize(Widget child, Key key, Size size);

    virtual void  square(Widget child, double dimension, Key key);

    virtual RenderConstrainedBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderConstrainedBox renderObject);

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual BoxConstraints _additionalConstraints();

};
using SizedBox = std::shared_ptr<SizedBoxCls>;

class ConstrainedBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    BoxConstraints constraints;


     ConstrainedBoxCls(Widget child, BoxConstraints constraints, Key key);

    virtual RenderConstrainedBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderConstrainedBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ConstrainedBox = std::shared_ptr<ConstrainedBoxCls>;

class ConstraintsTransformBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    TextDirection textDirection;

    AlignmentGeometry alignment;

    BoxConstraintsTransform constraintsTransform;

    Clip clipBehavior;


     ConstraintsTransformBoxCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, String debugTransformType, Key key, TextDirection textDirection);

    static BoxConstraints unmodified(BoxConstraints constraints);

    static BoxConstraints unconstrained(BoxConstraints constraints);

    static BoxConstraints widthUnconstrained(BoxConstraints constraints);

    static BoxConstraints heightUnconstrained(BoxConstraints constraints);

    static BoxConstraints maxHeightUnconstrained(BoxConstraints constraints);

    static BoxConstraints maxWidthUnconstrained(BoxConstraints constraints);

    static BoxConstraints maxUnconstrained(BoxConstraints constraints);

    virtual RenderConstraintsTransformBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderConstraintsTransformBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    static Map<BoxConstraintsTransform, String> _debugKnownTransforms;

    String _debugTransformLabel;


};
using ConstraintsTransformBox = std::shared_ptr<ConstraintsTransformBoxCls>;

class UnconstrainedBoxCls : public StatelessWidgetCls {
public:
    TextDirection textDirection;

    AlignmentGeometry alignment;

    Axis constrainedAxis;

    Clip clipBehavior;

    Widget child;


     UnconstrainedBoxCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Axis constrainedAxis, Key key, TextDirection textDirection);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual BoxConstraintsTransform _axisToTransform(Axis constrainedAxis);

};
using UnconstrainedBox = std::shared_ptr<UnconstrainedBoxCls>;

class FractionallySizedBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    double widthFactor;

    double heightFactor;

    AlignmentGeometry alignment;


     FractionallySizedBoxCls(AlignmentGeometry alignment, Widget child, double heightFactor, Key key, double widthFactor);

    virtual RenderFractionallySizedOverflowBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderFractionallySizedOverflowBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using FractionallySizedBox = std::shared_ptr<FractionallySizedBoxCls>;

class LimitedBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    double maxWidth;

    double maxHeight;


     LimitedBoxCls(Widget child, Key key, double maxHeight, double maxWidth);

    virtual RenderLimitedBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderLimitedBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using LimitedBox = std::shared_ptr<LimitedBoxCls>;

class OverflowBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    AlignmentGeometry alignment;

    double minWidth;

    double maxWidth;

    double minHeight;

    double maxHeight;


     OverflowBoxCls(AlignmentGeometry alignment, Widget child, Key key, double maxHeight, double maxWidth, double minHeight, double minWidth);
    virtual RenderConstrainedOverflowBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderConstrainedOverflowBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using OverflowBox = std::shared_ptr<OverflowBoxCls>;

class SizedOverflowBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    AlignmentGeometry alignment;

    Size size;


     SizedOverflowBoxCls(AlignmentGeometry alignment, Widget child, Key key, Size size);

    virtual RenderSizedOverflowBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSizedOverflowBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SizedOverflowBox = std::shared_ptr<SizedOverflowBoxCls>;

class OffstageCls : public SingleChildRenderObjectWidgetCls {
public:
    bool offstage;


     OffstageCls(Widget child, Key key, bool offstage);

    virtual RenderOffstage createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderOffstage renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual SingleChildRenderObjectElement createElement();

private:

};
using Offstage = std::shared_ptr<OffstageCls>;

class _OffstageElementCls : public SingleChildRenderObjectElementCls {
public:

    virtual void debugVisitOnstageChildren(ElementVisitor visitor);

private:

     _OffstageElementCls(Offstage widget);
};
using _OffstageElement = std::shared_ptr<_OffstageElementCls>;

class AspectRatioCls : public SingleChildRenderObjectWidgetCls {
public:
    double aspectRatio;


     AspectRatioCls(double aspectRatio, Widget child, Key key);

    virtual RenderAspectRatio createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderAspectRatio renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AspectRatio = std::shared_ptr<AspectRatioCls>;

class IntrinsicWidthCls : public SingleChildRenderObjectWidgetCls {
public:
    double stepWidth;

    double stepHeight;


     IntrinsicWidthCls(Widget child, Key key, double stepHeight, double stepWidth);

    virtual RenderIntrinsicWidth createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderIntrinsicWidth renderObject);

private:

    virtual double _stepWidth();

    virtual double _stepHeight();

};
using IntrinsicWidth = std::shared_ptr<IntrinsicWidthCls>;

class IntrinsicHeightCls : public SingleChildRenderObjectWidgetCls {
public:

     IntrinsicHeightCls(Widget child, Key key);
    virtual RenderIntrinsicHeight createRenderObject(BuildContext context);

private:

};
using IntrinsicHeight = std::shared_ptr<IntrinsicHeightCls>;

class BaselineCls : public SingleChildRenderObjectWidgetCls {
public:
    double baseline;

    TextBaseline baselineType;


     BaselineCls(double baseline, TextBaseline baselineType, Widget child, Key key);

    virtual RenderBaseline createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderBaseline renderObject);

private:

};
using Baseline = std::shared_ptr<BaselineCls>;

class SliverToBoxAdapterCls : public SingleChildRenderObjectWidgetCls {
public:

     SliverToBoxAdapterCls(Widget child, Key key);
    virtual RenderSliverToBoxAdapter createRenderObject(BuildContext context);

private:

};
using SliverToBoxAdapter = std::shared_ptr<SliverToBoxAdapterCls>;

class SliverPaddingCls : public SingleChildRenderObjectWidgetCls {
public:
    EdgeInsetsGeometry padding;


     SliverPaddingCls(Key key, EdgeInsetsGeometry padding, Widget sliver);

    virtual RenderSliverPadding createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverPadding renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverPadding = std::shared_ptr<SliverPaddingCls>;
AxisDirection getAxisDirectionFromAxisReverseAndDirectionality(BuildContext context, Axis axis, bool reverse);


class ListBodyCls : public MultiChildRenderObjectWidgetCls {
public:
    Axis mainAxis;

    bool reverse;


     ListBodyCls(List<Widget> children, Key key, Axis mainAxis, bool reverse);

    virtual RenderListBody createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderListBody renderObject);

private:

    virtual AxisDirection _getDirection(BuildContext context);

};
using ListBody = std::shared_ptr<ListBodyCls>;

class StackCls : public MultiChildRenderObjectWidgetCls {
public:
    AlignmentGeometry alignment;

    TextDirection textDirection;

    StackFit fit;

    Clip clipBehavior;


     StackCls(AlignmentGeometry alignment, List<Widget> children, Clip clipBehavior, StackFit fit, Key key, TextDirection textDirection);

    virtual RenderStack createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderStack renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual bool _debugCheckHasDirectionality(BuildContext context);

};
using Stack = std::shared_ptr<StackCls>;

class IndexedStackCls : public StackCls {
public:
    int index;


     IndexedStackCls(AlignmentGeometry alignment, List<Widget> children, int index, Key key, StackFit sizing, TextDirection textDirection);

    virtual RenderIndexedStack createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderIndexedStack renderObject);

private:

};
using IndexedStack = std::shared_ptr<IndexedStackCls>;

class PositionedCls : public ParentDataWidgetCls<StackParentData> {
public:
    double left;

    double top;

    double right;

    double bottom;

    double width;

    double height;


     PositionedCls(double bottom, Widget child, double height, Key key, double left, double right, double top, double width);

    virtual void  fromRect(Widget child, Key key, Rect rect);

    virtual void  fromRelativeRect(Widget child, Key key, RelativeRect rect);

    virtual void  fill(double bottom, Widget child, Key key, double left, double right, double top);

    virtual void  directional(double bottom, Widget child, double end, double height, Key key, double start, TextDirection textDirection, double top, double width);

    virtual void applyParentData(RenderObject renderObject);

    virtual Type debugTypicalAncestorWidgetClass();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Positioned = std::shared_ptr<PositionedCls>;

class PositionedDirectionalCls : public StatelessWidgetCls {
public:
    double start;

    double top;

    double end;

    double bottom;

    double width;

    double height;

    Widget child;


     PositionedDirectionalCls(double bottom, Widget child, double end, double height, Key key, double start, double top, double width);
    virtual Widget build(BuildContext context);

private:

};
using PositionedDirectional = std::shared_ptr<PositionedDirectionalCls>;

class FlexCls : public MultiChildRenderObjectWidgetCls {
public:
    Axis direction;

    MainAxisAlignment mainAxisAlignment;

    MainAxisSize mainAxisSize;

    CrossAxisAlignment crossAxisAlignment;

    TextDirection textDirection;

    VerticalDirection verticalDirection;

    TextBaseline textBaseline;

    Clip clipBehavior;


     FlexCls(List<Widget> children, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, Key key, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection);

    virtual TextDirection getEffectiveTextDirection(BuildContext context);

    virtual RenderFlex createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderFlex renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual bool _needTextDirection();

};
using Flex = std::shared_ptr<FlexCls>;

class RowCls : public FlexCls {
public:

     RowCls(List<Widget> children, CrossAxisAlignment crossAxisAlignment, Key key, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection);

private:

};
using Row = std::shared_ptr<RowCls>;

class ColumnCls : public FlexCls {
public:

     ColumnCls(List<Widget> children, CrossAxisAlignment crossAxisAlignment, Key key, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection);

private:

};
using Column = std::shared_ptr<ColumnCls>;

class FlexibleCls : public ParentDataWidgetCls<FlexParentData> {
public:
    int flex;

    FlexFit fit;


     FlexibleCls(Widget child, FlexFit fit, int flex, Key key);
    virtual void applyParentData(RenderObject renderObject);

    virtual Type debugTypicalAncestorWidgetClass();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Flexible = std::shared_ptr<FlexibleCls>;

class ExpandedCls : public FlexibleCls {
public:

     ExpandedCls(Widget child, int flex, Key key);

private:

};
using Expanded = std::shared_ptr<ExpandedCls>;

class WrapCls : public MultiChildRenderObjectWidgetCls {
public:
    Axis direction;

    WrapAlignment alignment;

    double spacing;

    WrapAlignment runAlignment;

    double runSpacing;

    WrapCrossAlignment crossAxisAlignment;

    TextDirection textDirection;

    VerticalDirection verticalDirection;

    Clip clipBehavior;


     WrapCls(WrapAlignment alignment, List<Widget> children, Clip clipBehavior, WrapCrossAlignment crossAxisAlignment, Axis direction, Key key, WrapAlignment runAlignment, double runSpacing, double spacing, TextDirection textDirection, VerticalDirection verticalDirection);

    virtual RenderWrap createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderWrap renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Wrap = std::shared_ptr<WrapCls>;

class FlowCls : public MultiChildRenderObjectWidgetCls {
public:
    FlowDelegate delegate;

    Clip clipBehavior;


     FlowCls(List<Widget> children, Clip clipBehavior, FlowDelegate delegate, Key key);

    virtual void  unwrapped(List<Widget> children, Clip clipBehavior, FlowDelegate delegate, Key key);

    virtual RenderFlow createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderFlow renderObject);

private:

};
using Flow = std::shared_ptr<FlowCls>;

class RichTextCls : public MultiChildRenderObjectWidgetCls {
public:
    InlineSpan text;

    TextAlign textAlign;

    TextDirection textDirection;

    bool softWrap;

    TextOverflow overflow;

    double textScaleFactor;

    int maxLines;

    Locale locale;

    StrutStyle strutStyle;

    TextWidthBasis textWidthBasis;

    TextHeightBehavior textHeightBehavior;

    SelectionRegistrar selectionRegistrar;

    Color selectionColor;


     RichTextCls(Key key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, SelectionRegistrar selectionRegistrar, bool softWrap, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    virtual RenderParagraph createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderParagraph renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static List<Widget> _extractChildren(InlineSpan span);

};
using RichText = std::shared_ptr<RichTextCls>;

class RawImageCls : public LeafRenderObjectWidgetCls {
public:
    Image image;

    String debugImageLabel;

    double width;

    double height;

    double scale;

    Color color;

    Animation<double> opacity;

    FilterQuality filterQuality;

    BlendMode colorBlendMode;

    BoxFit fit;

    AlignmentGeometry alignment;

    ImageRepeat repeat;

    Rect centerSlice;

    bool matchTextDirection;

    bool invertColors;

    bool isAntiAlias;


     RawImageCls(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, Key key, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, double width);

    virtual RenderImage createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderImage renderObject);

    virtual void didUnmountRenderObject(RenderImage renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using RawImage = std::shared_ptr<RawImageCls>;

class DefaultAssetBundleCls : public InheritedWidgetCls {
public:
    AssetBundle bundle;


     DefaultAssetBundleCls(AssetBundle bundle, Widget child, Key key);

    static AssetBundle of(BuildContext context);

    virtual bool updateShouldNotify(DefaultAssetBundle oldWidget);

private:

};
using DefaultAssetBundle = std::shared_ptr<DefaultAssetBundleCls>;

class WidgetToRenderBoxAdapterCls : public LeafRenderObjectWidgetCls {
public:
    RenderBox renderBox;

    VoidCallback onBuild;

    VoidCallback onUnmount;


     WidgetToRenderBoxAdapterCls(VoidCallback onBuild, VoidCallback onUnmount, RenderBox renderBox);

    virtual RenderBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderBox renderObject);

    virtual void didUnmountRenderObject(RenderObject renderObject);

private:

};
using WidgetToRenderBoxAdapter = std::shared_ptr<WidgetToRenderBoxAdapterCls>;

class ListenerCls : public SingleChildRenderObjectWidgetCls {
public:
    PointerDownEventListener onPointerDown;

    PointerMoveEventListener onPointerMove;

    PointerUpEventListener onPointerUp;

    PointerHoverEventListener onPointerHover;

    PointerCancelEventListener onPointerCancel;

    PointerPanZoomStartEventListener onPointerPanZoomStart;

    PointerPanZoomUpdateEventListener onPointerPanZoomUpdate;

    PointerPanZoomEndEventListener onPointerPanZoomEnd;

    PointerSignalEventListener onPointerSignal;

    HitTestBehavior behavior;


     ListenerCls(HitTestBehavior behavior, Widget child, Key key, PointerCancelEventListener onPointerCancel, PointerDownEventListener onPointerDown, PointerHoverEventListener onPointerHover, PointerMoveEventListener onPointerMove, PointerPanZoomEndEventListener onPointerPanZoomEnd, PointerPanZoomStartEventListener onPointerPanZoomStart, PointerPanZoomUpdateEventListener onPointerPanZoomUpdate, PointerSignalEventListener onPointerSignal, PointerUpEventListener onPointerUp);

    virtual RenderPointerListener createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderPointerListener renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Listener = std::shared_ptr<ListenerCls>;

class MouseRegionCls : public SingleChildRenderObjectWidgetCls {
public:
    PointerEnterEventListener onEnter;

    PointerHoverEventListener onHover;

    PointerExitEventListener onExit;

    MouseCursor cursor;

    bool opaque;

    HitTestBehavior hitTestBehavior;


     MouseRegionCls(Widget child, MouseCursor cursor, HitTestBehavior hitTestBehavior, Key key, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque);

    virtual RenderMouseRegion createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderMouseRegion renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using MouseRegion = std::shared_ptr<MouseRegionCls>;

class RepaintBoundaryCls : public SingleChildRenderObjectWidgetCls {
public:

     RepaintBoundaryCls(Widget child, Key key);
    virtual void  wrap(Widget child, int childIndex);

    static List<RepaintBoundary> wrapAll(List<Widget> widgets);

    virtual RenderRepaintBoundary createRenderObject(BuildContext context);

private:

};
using RepaintBoundary = std::shared_ptr<RepaintBoundaryCls>;

class IgnorePointerCls : public SingleChildRenderObjectWidgetCls {
public:
    bool ignoring;

    bool ignoringSemantics;


     IgnorePointerCls(Widget child, bool ignoring, bool ignoringSemantics, Key key);

    virtual RenderIgnorePointer createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderIgnorePointer renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using IgnorePointer = std::shared_ptr<IgnorePointerCls>;

class AbsorbPointerCls : public SingleChildRenderObjectWidgetCls {
public:
    bool absorbing;

    bool ignoringSemantics;


     AbsorbPointerCls(bool absorbing, Widget child, bool ignoringSemantics, Key key);

    virtual RenderAbsorbPointer createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderAbsorbPointer renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AbsorbPointer = std::shared_ptr<AbsorbPointerCls>;

class MetaDataCls : public SingleChildRenderObjectWidgetCls {
public:
    dynamic metaData;

    HitTestBehavior behavior;


     MetaDataCls(HitTestBehavior behavior, Widget child, Key key, dynamic metaData);
    virtual RenderMetaData createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderMetaData renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using MetaData = std::shared_ptr<MetaDataCls>;

class SemanticsCls : public SingleChildRenderObjectWidgetCls {
public:
    SemanticsProperties properties;

    bool container;

    bool explicitChildNodes;

    bool excludeSemantics;


     SemanticsCls(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, Widget child, bool container, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool excludeSemantics, bool explicitChildNodes, bool focusable, bool focused, bool header, bool hidden, String hint, bool image, bool inMutuallyExclusiveGroup, String increasedValue, Key key, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, String onLongPressHint, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorForwardByCharacter, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, String onTapHint, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value);

    virtual void  fromProperties(Widget child, bool container, bool excludeSemantics, bool explicitChildNodes, Key key, SemanticsProperties properties);

    virtual RenderSemanticsAnnotations createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSemanticsAnnotations renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual TextDirection _getTextDirection(BuildContext context);

};
using Semantics = std::shared_ptr<SemanticsCls>;

class MergeSemanticsCls : public SingleChildRenderObjectWidgetCls {
public:

     MergeSemanticsCls(Widget child, Key key);
    virtual RenderMergeSemantics createRenderObject(BuildContext context);

private:

};
using MergeSemantics = std::shared_ptr<MergeSemanticsCls>;

class BlockSemanticsCls : public SingleChildRenderObjectWidgetCls {
public:
    bool blocking;


     BlockSemanticsCls(bool blocking, Widget child, Key key);
    virtual RenderBlockSemantics createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderBlockSemantics renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using BlockSemantics = std::shared_ptr<BlockSemanticsCls>;

class ExcludeSemanticsCls : public SingleChildRenderObjectWidgetCls {
public:
    bool excluding;


     ExcludeSemanticsCls(Widget child, bool excluding, Key key);

    virtual RenderExcludeSemantics createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderExcludeSemantics renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ExcludeSemantics = std::shared_ptr<ExcludeSemanticsCls>;

class IndexedSemanticsCls : public SingleChildRenderObjectWidgetCls {
public:
    int index;


     IndexedSemanticsCls(Widget child, int index, Key key);

    virtual RenderIndexedSemantics createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderIndexedSemantics renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using IndexedSemantics = std::shared_ptr<IndexedSemanticsCls>;

class KeyedSubtreeCls : public StatelessWidgetCls {
public:
    Widget child;


     KeyedSubtreeCls(Widget child, Key key);

    virtual void  wrap(Widget child, int childIndex);

    static List<Widget> ensureUniqueKeysForList(List<Widget> items, int baseIndex);

    virtual Widget build(BuildContext context);

private:

};
using KeyedSubtree = std::shared_ptr<KeyedSubtreeCls>;

class BuilderCls : public StatelessWidgetCls {
public:
    WidgetBuilder builder;


     BuilderCls(WidgetBuilder builder, Key key);

    virtual Widget build(BuildContext context);

private:

};
using Builder = std::shared_ptr<BuilderCls>;

class StatefulBuilderCls : public StatefulWidgetCls {
public:
    StatefulWidgetBuilder builder;


     StatefulBuilderCls(StatefulWidgetBuilder builder, Key key);

    virtual State<StatefulBuilder> createState();

private:

};
using StatefulBuilder = std::shared_ptr<StatefulBuilderCls>;

class _StatefulBuilderStateCls : public StateCls<StatefulBuilder> {
public:

    virtual Widget build(BuildContext context);

private:

};
using _StatefulBuilderState = std::shared_ptr<_StatefulBuilderStateCls>;

class ColoredBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    Color color;


     ColoredBoxCls(Widget child, Color color, Key key);

    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ColoredBox = std::shared_ptr<ColoredBoxCls>;

class _RenderColoredBoxCls : public RenderProxyBoxWithHitTestBehaviorCls {
public:

    virtual Color color();

    virtual void  color(Color value);

    virtual void paint(PaintingContext context, Offset offset);

private:
    Color _color;


     _RenderColoredBoxCls(Color color);

};
using _RenderColoredBox = std::shared_ptr<_RenderColoredBoxCls>;


#endif