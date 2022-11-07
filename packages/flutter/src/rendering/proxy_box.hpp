#ifndef PROXY_BOX_H
#define PROXY_BOX_H
#include <memory>
#include <flutter/gestures.hpp>

#include <ui/ui.hpp>
#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/semantics.hpp>
#include <flutter/services.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "layout_helper.hpp"
#include "object.hpp"



class RenderProxyBox : RenderBox {
public:

     RenderProxyBox(RenderBox child);

private:

};

class RenderProxyBoxMixin<T extends RenderBox> {
public:

    void setupParentData(RenderObject child);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    Size computeSizeForNoChild(BoxConstraints constraints);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    void paint(PaintingContext context, Offset offset);

private:

};

enum HitTestBehavior{
    deferToChild,
    opaque,
    translucent,
} // end HitTestBehavior

class RenderProxyBoxWithHitTestBehavior : RenderProxyBox {
public:
    HitTestBehavior behavior;


     RenderProxyBoxWithHitTestBehavior(HitTestBehavior behavior, RenderBox child);

    bool hitTest(Offset position, BoxHitTestResult result);

    bool hitTestSelf(Offset position);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RenderConstrainedBox : RenderProxyBox {
public:

     RenderConstrainedBox(BoxConstraints additionalConstraints, RenderBox child);

    BoxConstraints additionalConstraints();

    void  additionalConstraints(BoxConstraints value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    void performLayout();

    Size computeDryLayout(BoxConstraints constraints);

    void debugPaintSize(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    BoxConstraints _additionalConstraints;


};

class RenderLimitedBox : RenderProxyBox {
public:

     RenderLimitedBox(RenderBox child, double maxHeight, double maxWidth);

    double maxWidth();

    void  maxWidth(double value);

    double maxHeight();

    void  maxHeight(double value);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _maxWidth;

    double _maxHeight;


    BoxConstraints _limitConstraints(BoxConstraints constraints);

    Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};

class RenderAspectRatio : RenderProxyBox {
public:

     RenderAspectRatio(double aspectRatio, RenderBox child);

    double aspectRatio();

    void  aspectRatio(double value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _aspectRatio;


    Size _applyAspectRatio(BoxConstraints constraints);

};

class RenderIntrinsicWidth : RenderProxyBox {
public:

     RenderIntrinsicWidth(RenderBox child, double stepHeight, double stepWidth);

    double stepWidth();

    void  stepWidth(double value);

    double stepHeight();

    void  stepHeight(double value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _stepWidth;

    double _stepHeight;


    static double _applyStep(double input, double step);

    Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};

class RenderIntrinsicHeight : RenderProxyBox {
public:

     RenderIntrinsicHeight(RenderBox child);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

private:

    Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};

class RenderOpacity : RenderProxyBox {
public:

     RenderOpacity(bool alwaysIncludeSemantics, RenderBox child, double opacity);

    bool alwaysNeedsCompositing();

    double opacity();

    void  opacity(double value);

    bool alwaysIncludeSemantics();

    void  alwaysIncludeSemantics(bool value);

    bool paintsChild(RenderBox child);

    void paint(PaintingContext context, Offset offset);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;

    double _opacity;

    bool _alwaysIncludeSemantics;


};

class RenderAnimatedOpacityMixin<T extends RenderObject> {
public:

    bool isRepaintBoundary();

    OffsetLayer updateCompositedLayer(OpacityLayer oldLayer);

    Animation<double> opacity();

    void  opacity(Animation<double> value);

    bool alwaysIncludeSemantics();

    void  alwaysIncludeSemantics(bool value);

    void attach(PipelineOwner owner);

    void detach();

    bool paintsChild(RenderObject child);

    void paint(PaintingContext context, Offset offset);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;

    bool _currentlyIsRepaintBoundary;

    Animation<double> _opacity;

    bool _alwaysIncludeSemantics;


    void _updateOpacity();

};

class RenderAnimatedOpacity : RenderProxyBox {
public:

     RenderAnimatedOpacity(bool alwaysIncludeSemantics, RenderBox child, Animation<double> opacity);

private:

};

class RenderShaderMask : RenderProxyBox {
public:

     RenderShaderMask(BlendMode blendMode, RenderBox child, ShaderCallback shaderCallback);

    ShaderMaskLayer layer();

    ShaderCallback shaderCallback();

    void  shaderCallback(ShaderCallback value);

    BlendMode blendMode();

    void  blendMode(BlendMode value);

    bool alwaysNeedsCompositing();

    void paint(PaintingContext context, Offset offset);

private:
    ShaderCallback _shaderCallback;

    BlendMode _blendMode;


};

class RenderBackdropFilter : RenderProxyBox {
public:

     RenderBackdropFilter(BlendMode blendMode, RenderBox child, ImageFilter filter);

    BackdropFilterLayer layer();

    ImageFilter filter();

    void  filter(ImageFilter value);

    BlendMode blendMode();

    void  blendMode(BlendMode value);

    bool alwaysNeedsCompositing();

    void paint(PaintingContext context, Offset offset);

private:
    ImageFilter _filter;

    BlendMode _blendMode;


};

class CustomClipper<T> : Listenable {
public:

     CustomClipper(Listenable reclip);

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    T getClip(Size size);

    Rect getApproximateClipRect(Size size);

    bool shouldReclip(CustomClipper<T> oldClipper);

    String toString();

private:
    Listenable _reclip;


};

class ShapeBorderClipper : CustomClipper<Path> {
public:
    ShapeBorder shape;

    TextDirection textDirection;


     ShapeBorderClipper(ShapeBorder shape, TextDirection textDirection);

    Path getClip(Size size);

    bool shouldReclip(CustomClipper<Path> oldClipper);

private:

};

class _RenderCustomClip<T> : RenderProxyBox {
public:

    CustomClipper<T> clipper();

    void  clipper(CustomClipper<T> newClipper);

    void attach(PipelineOwner owner);

    void detach();

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void performLayout();

    Rect describeApproximatePaintClip(RenderObject child);

    void debugPaintSize(PaintingContext context, Offset offset);

private:
    CustomClipper<T> _clipper;

    T _clip;

    Clip _clipBehavior;

    Paint _debugPaint;

    TextPainter _debugText;


     _RenderCustomClip(RenderBox child, Clip clipBehavior, CustomClipper<T> clipper);

    void _markNeedsClip();

    T _defaultClip();

    void _updateClip();

};

class RenderClipRect : _RenderCustomClip<Rect> {
public:

     RenderClipRect(Unknown, Unknown, Unknown);

    bool hitTest(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugPaintSize(PaintingContext context, Offset offset);

private:

    Rect _defaultClip();

};

class RenderClipRRect : _RenderCustomClip<RRect> {
public:

     RenderClipRRect(BorderRadiusGeometry borderRadius, Unknown, Unknown, CustomClipper<RRect> clipper, TextDirection textDirection);

    BorderRadiusGeometry borderRadius();

    void  borderRadius(BorderRadiusGeometry value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    bool hitTest(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugPaintSize(PaintingContext context, Offset offset);

private:
    BorderRadiusGeometry _borderRadius;

    TextDirection _textDirection;


    RRect _defaultClip();

};

class RenderClipOval : _RenderCustomClip<Rect> {
public:

     RenderClipOval(Unknown, Unknown, Unknown);

    bool hitTest(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugPaintSize(PaintingContext context, Offset offset);

private:
    Rect _cachedRect;

    Path _cachedPath;


    Path _getClipPath(Rect rect);

    Rect _defaultClip();

};

class RenderClipPath : _RenderCustomClip<Path> {
public:

     RenderClipPath(Unknown, Unknown, Unknown);

    bool hitTest(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugPaintSize(PaintingContext context, Offset offset);

private:

    Path _defaultClip();

};

class _RenderPhysicalModelBase<T> : _RenderCustomClip<T> {
public:

    double elevation();

    void  elevation(double value);

    Color shadowColor();

    void  shadowColor(Color value);

    Color color();

    void  color(Color value);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    double _elevation;

    Color _shadowColor;

    Color _color;


     _RenderPhysicalModelBase(Unknown, Unknown, Unknown, Color color, double elevation, Color shadowColor);

};
Paint _transparentPaint;


class RenderPhysicalModel : _RenderPhysicalModelBase<RRect> {
public:

     RenderPhysicalModel(BorderRadius borderRadius, Unknown, Unknown, Unknown, Unknown, Unknown, BoxShape shape);

    BoxShape shape();

    void  shape(BoxShape value);

    BorderRadius borderRadius();

    void  borderRadius(BorderRadius value);

    bool hitTest(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    BoxShape _shape;

    BorderRadius _borderRadius;


    RRect _defaultClip();

};

class RenderPhysicalShape : _RenderPhysicalModelBase<Path> {
public:

     RenderPhysicalShape(Unknown, Unknown, CustomClipper<Path> clipper, Unknown, Unknown, Unknown);

    bool hitTest(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:

    Path _defaultClip();

};

enum DecorationPosition{
    background,
    foreground,
} // end DecorationPosition

class RenderDecoratedBox : RenderProxyBox {
public:

     RenderDecoratedBox(RenderBox child, ImageConfiguration configuration, Decoration decoration, DecorationPosition position);

    Decoration decoration();

    void  decoration(Decoration value);

    DecorationPosition position();

    void  position(DecorationPosition value);

    ImageConfiguration configuration();

    void  configuration(ImageConfiguration value);

    void detach();

    bool hitTestSelf(Offset position);

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    BoxPainter _painter;

    Decoration _decoration;

    DecorationPosition _position;

    ImageConfiguration _configuration;


};

class RenderTransform : RenderProxyBox {
public:
    bool transformHitTests;


     RenderTransform(AlignmentGeometry alignment, RenderBox child, FilterQuality filterQuality, Offset origin, TextDirection textDirection, Matrix4 transform, bool transformHitTests);

    Offset origin();

    void  origin(Offset value);

    AlignmentGeometry alignment();

    void  alignment(AlignmentGeometry value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    bool alwaysNeedsCompositing();

    void  transform(Matrix4 value);

    FilterQuality filterQuality();

    void  filterQuality(FilterQuality value);

    void setIdentity();

    void rotateX(double radians);

    void rotateY(double radians);

    void rotateZ(double radians);

    void translate(double x, double y, double z);

    void scale(double x, double y, double z);

    bool hitTest(Offset position, BoxHitTestResult result);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Offset _origin;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;

    Matrix4 _transform;

    FilterQuality _filterQuality;


    Matrix4 _effectiveTransform();

};

class RenderFittedBox : RenderProxyBox {
public:

     RenderFittedBox(AlignmentGeometry alignment, RenderBox child, Clip clipBehavior, BoxFit fit, TextDirection textDirection);

    BoxFit fit();

    void  fit(BoxFit value);

    AlignmentGeometry alignment();

    void  alignment(AlignmentGeometry value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void paint(PaintingContext context, Offset offset);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    bool paintsChild(RenderBox child);

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Alignment _resolvedAlignment;

    BoxFit _fit;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;

    bool _hasVisualOverflow;

    Matrix4 _transform;

    Clip _clipBehavior;


    void _resolve();

    void _markNeedResolution();

    bool _fitAffectsLayout(BoxFit fit);

    void _clearPaintData();

    void _updatePaintData();

    TransformLayer _paintChildWithTransform(PaintingContext context, Offset offset);

};

class RenderFractionalTranslation : RenderProxyBox {
public:
    bool transformHitTests;


     RenderFractionalTranslation(RenderBox child, bool transformHitTests, Offset translation);

    Offset translation();

    void  translation(Offset value);

    bool hitTest(Offset position, BoxHitTestResult result);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Offset _translation;


};

class RenderPointerListener : RenderProxyBoxWithHitTestBehavior {
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


     RenderPointerListener(Unknown, Unknown, PointerCancelEventListener onPointerCancel, PointerDownEventListener onPointerDown, PointerHoverEventListener onPointerHover, PointerMoveEventListener onPointerMove, PointerPanZoomEndEventListener onPointerPanZoomEnd, PointerPanZoomStartEventListener onPointerPanZoomStart, PointerPanZoomUpdateEventListener onPointerPanZoomUpdate, PointerSignalEventListener onPointerSignal, PointerUpEventListener onPointerUp);

    Size computeSizeForNoChild(BoxConstraints constraints);

    void handleEvent(HitTestEntry entry, PointerEvent event);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RenderMouseRegion : RenderProxyBoxWithHitTestBehavior {
public:
    PointerEnterEventListener onEnter;

    PointerHoverEventListener onHover;

    PointerExitEventListener onExit;


     RenderMouseRegion(Unknown, MouseCursor cursor, HitTestBehavior hitTestBehavior, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque, bool validForMouseTracker);

    bool hitTest(Offset position, BoxHitTestResult result);

    void handleEvent(HitTestEntry entry, PointerEvent event);

    bool opaque();

    void  opaque(bool value);

    HitTestBehavior hitTestBehavior();

    void  hitTestBehavior(HitTestBehavior value);

    MouseCursor cursor();

    void  cursor(MouseCursor value);

    bool validForMouseTracker();

    void attach(PipelineOwner owner);

    void detach();

    Size computeSizeForNoChild(BoxConstraints constraints);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _opaque;

    MouseCursor _cursor;

    bool _validForMouseTracker;


};

class RenderRepaintBoundary : RenderProxyBox {
public:

     RenderRepaintBoundary(RenderBox child);

    bool isRepaintBoundary();

    Future<Image> toImage(double pixelRatio);

    int debugSymmetricPaintCount();

    int debugAsymmetricPaintCount();

    void debugResetMetrics();

    void debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _debugSymmetricPaintCount;

    int _debugAsymmetricPaintCount;


};

class RenderIgnorePointer : RenderProxyBox {
public:

     RenderIgnorePointer(RenderBox child, bool ignoring, bool ignoringSemantics);

    bool ignoring();

    void  ignoring(bool value);

    bool ignoringSemantics();

    void  ignoringSemantics(bool value);

    bool hitTest(Offset position, BoxHitTestResult result);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _ignoring;

    bool _ignoringSemantics;


    bool _effectiveIgnoringSemantics();

};

class RenderOffstage : RenderProxyBox {
public:

     RenderOffstage(RenderBox child, bool offstage);

    bool offstage();

    void  offstage(bool value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    bool sizedByParent();

    Size computeDryLayout(BoxConstraints constraints);

    void performResize();

    void performLayout();

    bool hitTest(Offset position, BoxHitTestResult result);

    bool paintsChild(RenderBox child);

    void paint(PaintingContext context, Offset offset);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    bool _offstage;


};

class RenderAbsorbPointer : RenderProxyBox {
public:

     RenderAbsorbPointer(bool absorbing, RenderBox child, bool ignoringSemantics);

    bool absorbing();

    void  absorbing(bool value);

    bool ignoringSemantics();

    void  ignoringSemantics(bool value);

    bool hitTest(Offset position, BoxHitTestResult result);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _absorbing;

    bool _ignoringSemantics;


    bool _effectiveIgnoringSemantics();

};

class RenderMetaData : RenderProxyBoxWithHitTestBehavior {
public:
    dynamic metaData;


     RenderMetaData(Unknown, Unknown, dynamic metaData);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RenderSemanticsGestureHandler : RenderProxyBoxWithHitTestBehavior {
public:
    double scrollFactor;


     RenderSemanticsGestureHandler(Unknown, Unknown, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureTapCallback onTap, GestureDragUpdateCallback onVerticalDragUpdate, double scrollFactor);

    Set<SemanticsAction> validActions();

    void  validActions(Set<SemanticsAction> value);

    GestureTapCallback onTap();

    void  onTap(GestureTapCallback value);

    GestureLongPressCallback onLongPress();

    void  onLongPress(GestureLongPressCallback value);

    GestureDragUpdateCallback onHorizontalDragUpdate();

    void  onHorizontalDragUpdate(GestureDragUpdateCallback value);

    GestureDragUpdateCallback onVerticalDragUpdate();

    void  onVerticalDragUpdate(GestureDragUpdateCallback value);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Set<SemanticsAction> _validActions;

    GestureTapCallback _onTap;

    GestureLongPressCallback _onLongPress;

    GestureDragUpdateCallback _onHorizontalDragUpdate;

    GestureDragUpdateCallback _onVerticalDragUpdate;


    bool _isValidAction(SemanticsAction action);

    void _performSemanticScrollLeft();

    void _performSemanticScrollRight();

    void _performSemanticScrollUp();

    void _performSemanticScrollDown();

};

class RenderSemanticsAnnotations : RenderProxyBox {
public:

     RenderSemanticsAnnotations(RenderBox child, bool container, bool excludeSemantics, bool explicitChildNodes, SemanticsProperties properties, TextDirection textDirection);

    SemanticsProperties properties();

    void  properties(SemanticsProperties value);

    bool container();

    void  container(bool value);

    bool explicitChildNodes();

    void  explicitChildNodes(bool value);

    bool excludeSemantics();

    void  excludeSemantics(bool value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

private:
    SemanticsProperties _properties;

    bool _container;

    bool _explicitChildNodes;

    bool _excludeSemantics;

    AttributedString _attributedLabel;

    AttributedString _attributedValue;

    AttributedString _attributedIncreasedValue;

    AttributedString _attributedDecreasedValue;

    AttributedString _attributedHint;

    TextDirection _textDirection;


    void _updateAttributedFields(SemanticsProperties value);

    AttributedString _effectiveAttributedLabel(SemanticsProperties value);

    AttributedString _effectiveAttributedValue(SemanticsProperties value);

    AttributedString _effectiveAttributedIncreasedValue(SemanticsProperties value);

    AttributedString _effectiveAttributedDecreasedValue(SemanticsProperties value);

    AttributedString _effectiveAttributedHint(SemanticsProperties value);

    void _performTap();

    void _performLongPress();

    void _performDismiss();

    void _performScrollLeft();

    void _performScrollRight();

    void _performScrollUp();

    void _performScrollDown();

    void _performIncrease();

    void _performDecrease();

    void _performCopy();

    void _performCut();

    void _performPaste();

    void _performMoveCursorForwardByCharacter(bool extendSelection);

    void _performMoveCursorBackwardByCharacter(bool extendSelection);

    void _performMoveCursorForwardByWord(bool extendSelection);

    void _performMoveCursorBackwardByWord(bool extendSelection);

    void _performSetSelection(TextSelection selection);

    void _performSetText(String text);

    void _performDidGainAccessibilityFocus();

    void _performDidLoseAccessibilityFocus();

};

class RenderBlockSemantics : RenderProxyBox {
public:

     RenderBlockSemantics(bool blocking, RenderBox child);

    bool blocking();

    void  blocking(bool value);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _blocking;


};

class RenderMergeSemantics : RenderProxyBox {
public:

     RenderMergeSemantics(RenderBox child);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

private:

};

class RenderExcludeSemantics : RenderProxyBox {
public:

     RenderExcludeSemantics(RenderBox child, bool excluding);

    bool excluding();

    void  excluding(bool value);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _excluding;


};

class RenderIndexedSemantics : RenderProxyBox {
public:

     RenderIndexedSemantics(RenderBox child, int index);

    int index();

    void  index(int value);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _index;


};

class RenderLeaderLayer : RenderProxyBox {
public:

     RenderLeaderLayer(RenderBox child, LayerLink link);

    LayerLink link();

    void  link(LayerLink value);

    bool alwaysNeedsCompositing();

    void performLayout();

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    Size _previousLayoutSize;


};

class RenderFollowerLayer : RenderProxyBox {
public:

     RenderFollowerLayer(RenderBox child, Alignment followerAnchor, Alignment leaderAnchor, LayerLink link, Offset offset, bool showWhenUnlinked);

    LayerLink link();

    void  link(LayerLink value);

    bool showWhenUnlinked();

    void  showWhenUnlinked(bool value);

    Offset offset();

    void  offset(Offset value);

    Alignment leaderAnchor();

    void  leaderAnchor(Alignment value);

    Alignment followerAnchor();

    void  followerAnchor(Alignment value);

    void detach();

    bool alwaysNeedsCompositing();

    FollowerLayer layer();

    Matrix4 getCurrentTransform();

    bool hitTest(Offset position, BoxHitTestResult result);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    bool _showWhenUnlinked;

    Offset _offset;

    Alignment _leaderAnchor;

    Alignment _followerAnchor;


};

class RenderAnnotatedRegion<T extends Object> : RenderProxyBox {
public:
    bool alwaysNeedsCompositing;


     RenderAnnotatedRegion(RenderBox child, bool sized, T value);

    T value();

    void  value(T newValue);

    bool sized();

    void  sized(bool value);

    void paint(PaintingContext context, Offset offset);

private:
    T _value;

    bool _sized;


};

#endif