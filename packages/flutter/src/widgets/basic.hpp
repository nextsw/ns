#ifndef BASIC_H
#define BASIC_H
#include <memory>
#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/painting.hpp>
#include <flutter/rendering.hpp>
#include <flutter/services.hpp>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/services.hpp>
#include "binding.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "localizations.hpp"
#include "widget_span.hpp"



class _UbiquitousInheritedElement : InheritedElement {
public:

    void setDependencies(Element dependent, Object value);

    Object getDependencies(Element dependent);

    void notifyClients(InheritedWidget oldWidget);

private:

     _UbiquitousInheritedElement(Unknown);

    static void _recurseChildren(Element element, ElementVisitor visitor);

};

class _UbiquitousInheritedWidget : InheritedWidget {
public:

    InheritedElement createElement();

private:

     _UbiquitousInheritedWidget(Unknown, Unknown);

};

class Directionality : _UbiquitousInheritedWidget {
public:
    TextDirection textDirection;


     Directionality(Unknown, Unknown, TextDirection textDirection);

    static TextDirection of(BuildContext context);

    static TextDirection maybeOf(BuildContext context);

    bool updateShouldNotify(Directionality oldWidget);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Opacity : SingleChildRenderObjectWidget {
public:
    double opacity;

    bool alwaysIncludeSemantics;


     Opacity(bool alwaysIncludeSemantics, Unknown, Unknown, double opacity);

    RenderOpacity createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderOpacity renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ShaderMask : SingleChildRenderObjectWidget {
public:
    ShaderCallback shaderCallback;

    BlendMode blendMode;


     ShaderMask(BlendMode blendMode, Unknown, Unknown, ShaderCallback shaderCallback);

    RenderShaderMask createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderShaderMask renderObject);

private:

};

class BackdropFilter : SingleChildRenderObjectWidget {
public:
    ImageFilter filter;

    BlendMode blendMode;


     BackdropFilter(BlendMode blendMode, Unknown, ImageFilter filter, Unknown);

    RenderBackdropFilter createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderBackdropFilter renderObject);

private:

};

class CustomPaint : SingleChildRenderObjectWidget {
public:
    CustomPainter painter;

    CustomPainter foregroundPainter;

    Size size;

    bool isComplex;

    bool willChange;


     CustomPaint(Unknown, CustomPainter foregroundPainter, bool isComplex, Unknown, CustomPainter painter, Size size, bool willChange);

    RenderCustomPaint createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderCustomPaint renderObject);

    void didUnmountRenderObject(RenderCustomPaint renderObject);

private:

};

class ClipRect : SingleChildRenderObjectWidget {
public:
    CustomClipper<Rect> clipper;

    Clip clipBehavior;


     ClipRect(Unknown, Clip clipBehavior, CustomClipper<Rect> clipper, Unknown);

    RenderClipRect createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderClipRect renderObject);

    void didUnmountRenderObject(RenderClipRect renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ClipRRect : SingleChildRenderObjectWidget {
public:
    BorderRadiusGeometry borderRadius;

    CustomClipper<RRect> clipper;

    Clip clipBehavior;


     ClipRRect(BorderRadiusGeometry borderRadius, Unknown, Clip clipBehavior, CustomClipper<RRect> clipper, Unknown);

    RenderClipRRect createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderClipRRect renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ClipOval : SingleChildRenderObjectWidget {
public:
    CustomClipper<Rect> clipper;

    Clip clipBehavior;


     ClipOval(Unknown, Clip clipBehavior, CustomClipper<Rect> clipper, Unknown);

    RenderClipOval createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderClipOval renderObject);

    void didUnmountRenderObject(RenderClipOval renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ClipPath : SingleChildRenderObjectWidget {
public:
    CustomClipper<Path> clipper;

    Clip clipBehavior;


     ClipPath(Unknown, Clip clipBehavior, CustomClipper<Path> clipper, Unknown);

    static Widget shape(Widget child, Clip clipBehavior, Key key, ShapeBorder shape);

    RenderClipPath createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderClipPath renderObject);

    void didUnmountRenderObject(RenderClipPath renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class PhysicalModel : SingleChildRenderObjectWidget {
public:
    BoxShape shape;

    Clip clipBehavior;

    BorderRadius borderRadius;

    double elevation;

    Color color;

    Color shadowColor;


     PhysicalModel(BorderRadius borderRadius, Unknown, Clip clipBehavior, Color color, double elevation, Unknown, Color shadowColor, BoxShape shape);

    RenderPhysicalModel createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderPhysicalModel renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class PhysicalShape : SingleChildRenderObjectWidget {
public:
    CustomClipper<Path> clipper;

    Clip clipBehavior;

    double elevation;

    Color color;

    Color shadowColor;


     PhysicalShape(Unknown, Clip clipBehavior, CustomClipper<Path> clipper, Color color, double elevation, Unknown, Color shadowColor);

    RenderPhysicalShape createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderPhysicalShape renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Transform : SingleChildRenderObjectWidget {
public:
    Matrix4 transform;

    Offset origin;

    AlignmentGeometry alignment;

    bool transformHitTests;

    FilterQuality filterQuality;


     Transform(AlignmentGeometry alignment, Unknown, FilterQuality filterQuality, Unknown, Offset origin, Matrix4 transform, bool transformHitTests);

    void  rotate(AlignmentGeometry alignment, double angle, Unknown, FilterQuality filterQuality, Unknown, Offset origin, bool transformHitTests);

    void  translate(Unknown, FilterQuality filterQuality, Unknown, Offset offset, bool transformHitTests);

    void  scale(AlignmentGeometry alignment, Unknown, FilterQuality filterQuality, Unknown, Offset origin, double scale, double scaleX, double scaleY, bool transformHitTests);

    RenderTransform createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderTransform renderObject);

private:

    static Matrix4 _computeRotation(double radians);

    static Matrix4 _createZRotation(double cos, double sin);

};

class CompositedTransformTarget : SingleChildRenderObjectWidget {
public:
    LayerLink link;


     CompositedTransformTarget(Unknown, Unknown, LayerLink link);

    RenderLeaderLayer createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderLeaderLayer renderObject);

private:

};

class CompositedTransformFollower : SingleChildRenderObjectWidget {
public:
    LayerLink link;

    bool showWhenUnlinked;

    Alignment targetAnchor;

    Alignment followerAnchor;

    Offset offset;


     CompositedTransformFollower(Unknown, Alignment followerAnchor, Unknown, LayerLink link, Offset offset, bool showWhenUnlinked, Alignment targetAnchor);

    RenderFollowerLayer createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderFollowerLayer renderObject);

private:

};

class FittedBox : SingleChildRenderObjectWidget {
public:
    BoxFit fit;

    AlignmentGeometry alignment;

    Clip clipBehavior;


     FittedBox(AlignmentGeometry alignment, Unknown, Clip clipBehavior, BoxFit fit, Unknown);

    RenderFittedBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderFittedBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class FractionalTranslation : SingleChildRenderObjectWidget {
public:
    Offset translation;

    bool transformHitTests;


     FractionalTranslation(Unknown, Unknown, bool transformHitTests, Offset translation);

    RenderFractionalTranslation createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderFractionalTranslation renderObject);

private:

};

class RotatedBox : SingleChildRenderObjectWidget {
public:
    int quarterTurns;


     RotatedBox(Unknown, Unknown, int quarterTurns);

    RenderRotatedBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderRotatedBox renderObject);

private:

};

class Padding : SingleChildRenderObjectWidget {
public:
    EdgeInsetsGeometry padding;


     Padding(Unknown, Unknown, EdgeInsetsGeometry padding);

    RenderPadding createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderPadding renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Align : SingleChildRenderObjectWidget {
public:
    AlignmentGeometry alignment;

    double widthFactor;

    double heightFactor;


     Align(AlignmentGeometry alignment, Unknown, double heightFactor, Unknown, double widthFactor);

    RenderPositionedBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderPositionedBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Center : Align {
public:

     Center(Unknown, Unknown, Unknown, Unknown);

private:

};

class CustomSingleChildLayout : SingleChildRenderObjectWidget {
public:
    SingleChildLayoutDelegate delegate;


     CustomSingleChildLayout(Unknown, SingleChildLayoutDelegate delegate, Unknown);

    RenderCustomSingleChildLayoutBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderCustomSingleChildLayoutBox renderObject);

private:

};

class LayoutId : ParentDataWidget<MultiChildLayoutParentData> {
public:
    Object id;


     LayoutId(Unknown, Object id, Key key);

    void applyParentData(RenderObject renderObject);

    Type debugTypicalAncestorWidgetClass();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class CustomMultiChildLayout : MultiChildRenderObjectWidget {
public:
    MultiChildLayoutDelegate delegate;


     CustomMultiChildLayout(Unknown, MultiChildLayoutDelegate delegate, Unknown);

    RenderCustomMultiChildLayoutBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderCustomMultiChildLayoutBox renderObject);

private:

};

class SizedBox : SingleChildRenderObjectWidget {
public:
    double width;

    double height;


     SizedBox(Unknown, double height, Unknown, double width);

    void  expand(Unknown, Unknown);

    void  shrink(Unknown, Unknown);

    void  fromSize(Unknown, Unknown, Size size);

    void  square(Unknown, double dimension, Unknown);

    RenderConstrainedBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderConstrainedBox renderObject);

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    BoxConstraints _additionalConstraints();

};

class ConstrainedBox : SingleChildRenderObjectWidget {
public:
    BoxConstraints constraints;


     ConstrainedBox(Unknown, BoxConstraints constraints, Unknown);

    RenderConstrainedBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderConstrainedBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ConstraintsTransformBox : SingleChildRenderObjectWidget {
public:
    TextDirection textDirection;

    AlignmentGeometry alignment;

    BoxConstraintsTransform constraintsTransform;

    Clip clipBehavior;


     ConstraintsTransformBox(AlignmentGeometry alignment, Unknown, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, String debugTransformType, Unknown, TextDirection textDirection);

    static BoxConstraints unmodified(BoxConstraints constraints);

    static BoxConstraints unconstrained(BoxConstraints constraints);

    static BoxConstraints widthUnconstrained(BoxConstraints constraints);

    static BoxConstraints heightUnconstrained(BoxConstraints constraints);

    static BoxConstraints maxHeightUnconstrained(BoxConstraints constraints);

    static BoxConstraints maxWidthUnconstrained(BoxConstraints constraints);

    static BoxConstraints maxUnconstrained(BoxConstraints constraints);

    RenderConstraintsTransformBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderConstraintsTransformBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    static Map<BoxConstraintsTransform, String> _debugKnownTransforms;

    String _debugTransformLabel;


};

class UnconstrainedBox : StatelessWidget {
public:
    TextDirection textDirection;

    AlignmentGeometry alignment;

    Axis constrainedAxis;

    Clip clipBehavior;

    Widget child;


     UnconstrainedBox(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Axis constrainedAxis, Unknown, TextDirection textDirection);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    BoxConstraintsTransform _axisToTransform(Axis constrainedAxis);

};

class FractionallySizedBox : SingleChildRenderObjectWidget {
public:
    double widthFactor;

    double heightFactor;

    AlignmentGeometry alignment;


     FractionallySizedBox(AlignmentGeometry alignment, Unknown, double heightFactor, Unknown, double widthFactor);

    RenderFractionallySizedOverflowBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderFractionallySizedOverflowBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class LimitedBox : SingleChildRenderObjectWidget {
public:
    double maxWidth;

    double maxHeight;


     LimitedBox(Unknown, Unknown, double maxHeight, double maxWidth);

    RenderLimitedBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderLimitedBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class OverflowBox : SingleChildRenderObjectWidget {
public:
    AlignmentGeometry alignment;

    double minWidth;

    double maxWidth;

    double minHeight;

    double maxHeight;


     OverflowBox(AlignmentGeometry alignment, Unknown, Unknown, double maxHeight, double maxWidth, double minHeight, double minWidth);

    RenderConstrainedOverflowBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderConstrainedOverflowBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SizedOverflowBox : SingleChildRenderObjectWidget {
public:
    AlignmentGeometry alignment;

    Size size;


     SizedOverflowBox(AlignmentGeometry alignment, Unknown, Unknown, Size size);

    RenderSizedOverflowBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSizedOverflowBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Offstage : SingleChildRenderObjectWidget {
public:
    bool offstage;


     Offstage(Unknown, Unknown, bool offstage);

    RenderOffstage createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderOffstage renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    SingleChildRenderObjectElement createElement();

private:

};

class _OffstageElement : SingleChildRenderObjectElement {
public:

    void debugVisitOnstageChildren(ElementVisitor visitor);

private:

     _OffstageElement(Offstage widget);

};

class AspectRatio : SingleChildRenderObjectWidget {
public:
    double aspectRatio;


     AspectRatio(double aspectRatio, Unknown, Unknown);

    RenderAspectRatio createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderAspectRatio renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class IntrinsicWidth : SingleChildRenderObjectWidget {
public:
    double stepWidth;

    double stepHeight;


     IntrinsicWidth(Unknown, Unknown, double stepHeight, double stepWidth);

    RenderIntrinsicWidth createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderIntrinsicWidth renderObject);

private:

    double _stepWidth();

    double _stepHeight();

};

class IntrinsicHeight : SingleChildRenderObjectWidget {
public:

     IntrinsicHeight(Unknown, Unknown);

    RenderIntrinsicHeight createRenderObject(BuildContext context);

private:

};

class Baseline : SingleChildRenderObjectWidget {
public:
    double baseline;

    TextBaseline baselineType;


     Baseline(double baseline, TextBaseline baselineType, Unknown, Unknown);

    RenderBaseline createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderBaseline renderObject);

private:

};

class SliverToBoxAdapter : SingleChildRenderObjectWidget {
public:

     SliverToBoxAdapter(Unknown, Unknown);

    RenderSliverToBoxAdapter createRenderObject(BuildContext context);

private:

};

class SliverPadding : SingleChildRenderObjectWidget {
public:
    EdgeInsetsGeometry padding;


     SliverPadding(Unknown, EdgeInsetsGeometry padding, Widget sliver);

    RenderSliverPadding createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverPadding renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
AxisDirection getAxisDirectionFromAxisReverseAndDirectionality(Axis axis, BuildContext context, bool reverse);


class ListBody : MultiChildRenderObjectWidget {
public:
    Axis mainAxis;

    bool reverse;


     ListBody(Unknown, Unknown, Axis mainAxis, bool reverse);

    RenderListBody createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderListBody renderObject);

private:

    AxisDirection _getDirection(BuildContext context);

};

class Stack : MultiChildRenderObjectWidget {
public:
    AlignmentGeometry alignment;

    TextDirection textDirection;

    StackFit fit;

    Clip clipBehavior;


     Stack(AlignmentGeometry alignment, Unknown, Clip clipBehavior, StackFit fit, Unknown, TextDirection textDirection);

    RenderStack createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderStack renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    bool _debugCheckHasDirectionality(BuildContext context);

};

class IndexedStack : Stack {
public:
    int index;


     IndexedStack(Unknown, Unknown, int index, Unknown, StackFit sizing, Unknown);

    RenderIndexedStack createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderIndexedStack renderObject);

private:

};

class Positioned : ParentDataWidget<StackParentData> {
public:
    double left;

    double top;

    double right;

    double bottom;

    double width;

    double height;


     Positioned(double bottom, Unknown, double height, Unknown, double left, double right, double top, double width);

    void  fromRect(Unknown, Unknown, Rect rect);

    void  fromRelativeRect(Unknown, Unknown, RelativeRect rect);

    void  fill(double bottom, Unknown, Unknown, double left, double right, double top);

    void  directional(double bottom, Widget child, double end, double height, Key key, double start, TextDirection textDirection, double top, double width);

    void applyParentData(RenderObject renderObject);

    Type debugTypicalAncestorWidgetClass();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class PositionedDirectional : StatelessWidget {
public:
    double start;

    double top;

    double end;

    double bottom;

    double width;

    double height;

    Widget child;


     PositionedDirectional(double bottom, Widget child, double end, double height, Unknown, double start, double top, double width);

    Widget build(BuildContext context);

private:

};

class Flex : MultiChildRenderObjectWidget {
public:
    Axis direction;

    MainAxisAlignment mainAxisAlignment;

    MainAxisSize mainAxisSize;

    CrossAxisAlignment crossAxisAlignment;

    TextDirection textDirection;

    VerticalDirection verticalDirection;

    TextBaseline textBaseline;

    Clip clipBehavior;


     Flex(Unknown, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, Unknown, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection);

    TextDirection getEffectiveTextDirection(BuildContext context);

    RenderFlex createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderFlex renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    bool _needTextDirection();

};

class Row : Flex {
public:

     Row(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

private:

};

class Column : Flex {
public:

     Column(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

private:

};

class Flexible : ParentDataWidget<FlexParentData> {
public:
    int flex;

    FlexFit fit;


     Flexible(Unknown, FlexFit fit, int flex, Unknown);

    void applyParentData(RenderObject renderObject);

    Type debugTypicalAncestorWidgetClass();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Expanded : Flexible {
public:

     Expanded(Unknown, Unknown, Unknown);

private:

};

class Wrap : MultiChildRenderObjectWidget {
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


     Wrap(WrapAlignment alignment, Unknown, Clip clipBehavior, WrapCrossAlignment crossAxisAlignment, Axis direction, Unknown, WrapAlignment runAlignment, double runSpacing, double spacing, TextDirection textDirection, VerticalDirection verticalDirection);

    RenderWrap createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderWrap renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Flow : MultiChildRenderObjectWidget {
public:
    FlowDelegate delegate;

    Clip clipBehavior;


     Flow(List<Widget> children, Clip clipBehavior, FlowDelegate delegate, Unknown);

    void  unwrapped(Unknown, Clip clipBehavior, FlowDelegate delegate, Unknown);

    RenderFlow createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderFlow renderObject);

private:

};

class RichText : MultiChildRenderObjectWidget {
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


     RichText(Unknown, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, SelectionRegistrar selectionRegistrar, bool softWrap, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    RenderParagraph createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderParagraph renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static List<Widget> _extractChildren(InlineSpan span);

};

class RawImage : LeafRenderObjectWidget {
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


     RawImage(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, Unknown, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, double width);

    RenderImage createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderImage renderObject);

    void didUnmountRenderObject(RenderImage renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class DefaultAssetBundle : InheritedWidget {
public:
    AssetBundle bundle;


     DefaultAssetBundle(AssetBundle bundle, Unknown, Unknown);

    static AssetBundle of(BuildContext context);

    bool updateShouldNotify(DefaultAssetBundle oldWidget);

private:

};

class WidgetToRenderBoxAdapter : LeafRenderObjectWidget {
public:
    RenderBox renderBox;

    VoidCallback onBuild;

    VoidCallback onUnmount;


     WidgetToRenderBoxAdapter(VoidCallback onBuild, VoidCallback onUnmount, RenderBox renderBox);

    RenderBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderBox renderObject);

    void didUnmountRenderObject(RenderObject renderObject);

private:

};

class Listener : SingleChildRenderObjectWidget {
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


     Listener(HitTestBehavior behavior, Unknown, Unknown, PointerCancelEventListener onPointerCancel, PointerDownEventListener onPointerDown, PointerHoverEventListener onPointerHover, PointerMoveEventListener onPointerMove, PointerPanZoomEndEventListener onPointerPanZoomEnd, PointerPanZoomStartEventListener onPointerPanZoomStart, PointerPanZoomUpdateEventListener onPointerPanZoomUpdate, PointerSignalEventListener onPointerSignal, PointerUpEventListener onPointerUp);

    RenderPointerListener createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderPointerListener renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class MouseRegion : SingleChildRenderObjectWidget {
public:
    PointerEnterEventListener onEnter;

    PointerHoverEventListener onHover;

    PointerExitEventListener onExit;

    MouseCursor cursor;

    bool opaque;

    HitTestBehavior hitTestBehavior;


     MouseRegion(Unknown, MouseCursor cursor, HitTestBehavior hitTestBehavior, Unknown, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque);

    RenderMouseRegion createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderMouseRegion renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RepaintBoundary : SingleChildRenderObjectWidget {
public:

     RepaintBoundary(Unknown, Unknown);

    void  wrap(Widget child, int childIndex);

    static List<RepaintBoundary> wrapAll(List<Widget> widgets);

    RenderRepaintBoundary createRenderObject(BuildContext context);

private:

};

class IgnorePointer : SingleChildRenderObjectWidget {
public:
    bool ignoring;

    bool ignoringSemantics;


     IgnorePointer(Unknown, bool ignoring, bool ignoringSemantics, Unknown);

    RenderIgnorePointer createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderIgnorePointer renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class AbsorbPointer : SingleChildRenderObjectWidget {
public:
    bool absorbing;

    bool ignoringSemantics;


     AbsorbPointer(bool absorbing, Unknown, bool ignoringSemantics, Unknown);

    RenderAbsorbPointer createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderAbsorbPointer renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class MetaData : SingleChildRenderObjectWidget {
public:
    dynamic metaData;

    HitTestBehavior behavior;


     MetaData(HitTestBehavior behavior, Unknown, Unknown, dynamic metaData);

    RenderMetaData createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderMetaData renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Semantics : SingleChildRenderObjectWidget {
public:
    SemanticsProperties properties;

    bool container;

    bool explicitChildNodes;

    bool excludeSemantics;


     Semantics(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, Widget child, bool container, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool excludeSemantics, bool explicitChildNodes, bool focusable, bool focused, bool header, bool hidden, String hint, bool image, bool inMutuallyExclusiveGroup, String increasedValue, Key key, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, String onLongPressHint, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorForwardByCharacter, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, String onTapHint, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value);

    void  fromProperties(Unknown, bool container, bool excludeSemantics, bool explicitChildNodes, Unknown, SemanticsProperties properties);

    RenderSemanticsAnnotations createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSemanticsAnnotations renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    TextDirection _getTextDirection(BuildContext context);

};

class MergeSemantics : SingleChildRenderObjectWidget {
public:

     MergeSemantics(Unknown, Unknown);

    RenderMergeSemantics createRenderObject(BuildContext context);

private:

};

class BlockSemantics : SingleChildRenderObjectWidget {
public:
    bool blocking;


     BlockSemantics(bool blocking, Unknown, Unknown);

    RenderBlockSemantics createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderBlockSemantics renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ExcludeSemantics : SingleChildRenderObjectWidget {
public:
    bool excluding;


     ExcludeSemantics(Unknown, bool excluding, Unknown);

    RenderExcludeSemantics createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderExcludeSemantics renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class IndexedSemantics : SingleChildRenderObjectWidget {
public:
    int index;


     IndexedSemantics(Unknown, int index, Unknown);

    RenderIndexedSemantics createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderIndexedSemantics renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class KeyedSubtree : StatelessWidget {
public:
    Widget child;


     KeyedSubtree(Widget child, Unknown);

    void  wrap(Widget child, int childIndex);

    static List<Widget> ensureUniqueKeysForList(int baseIndex, List<Widget> items);

    Widget build(BuildContext context);

private:

};

class Builder : StatelessWidget {
public:
    WidgetBuilder builder;


     Builder(WidgetBuilder builder, Unknown);

    Widget build(BuildContext context);

private:

};

class StatefulBuilder : StatefulWidget {
public:
    StatefulWidgetBuilder builder;


     StatefulBuilder(StatefulWidgetBuilder builder, Unknown);

    State<StatefulBuilder> createState();

private:

};

class _StatefulBuilderState : State<StatefulBuilder> {
public:

    Widget build(BuildContext context);

private:

};

class ColoredBox : SingleChildRenderObjectWidget {
public:
    Color color;


     ColoredBox(Unknown, Color color, Unknown);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _RenderColoredBox : RenderProxyBoxWithHitTestBehavior {
public:

    Color color();

    void  color(Color value);

    void paint(PaintingContext context, Offset offset);

private:
    Color _color;


     _RenderColoredBox(Color color);

};

#endif