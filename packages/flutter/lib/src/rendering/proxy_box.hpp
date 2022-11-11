#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_PROXY_BOX
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_PROXY_BOX
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "layout_helper.hpp"
#include "object.hpp"


class RenderProxyBoxCls : public RenderBoxCls {
public:

     RenderProxyBoxCls(RenderBox child);

private:

};
using RenderProxyBox = std::shared_ptr<RenderProxyBoxCls>;

template<typename T>
class RenderProxyBoxMixinCls : public ObjectCls {
public:

    virtual void setupParentData(RenderObject child);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual Size computeSizeForNoChild(BoxConstraints constraints);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual void paint(PaintingContext context, Offset offset);

private:

};
template<typename T>
using RenderProxyBoxMixin = std::shared_ptr<RenderProxyBoxMixinCls<T>>;

enum HitTestBehavior{
    deferToChild,
    opaque,
    translucent,
} // end HitTestBehavior

class RenderProxyBoxWithHitTestBehaviorCls : public RenderProxyBoxCls {
public:
    HitTestBehavior behavior;


     RenderProxyBoxWithHitTestBehaviorCls(HitTestBehavior behavior, RenderBox child);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual bool hitTestSelf(Offset position);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using RenderProxyBoxWithHitTestBehavior = std::shared_ptr<RenderProxyBoxWithHitTestBehaviorCls>;

class RenderConstrainedBoxCls : public RenderProxyBoxCls {
public:

     RenderConstrainedBoxCls(BoxConstraints additionalConstraints, RenderBox child);

    virtual BoxConstraints additionalConstraints();

    virtual void  additionalConstraints(BoxConstraints value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual void performLayout();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void debugPaintSize(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    BoxConstraints _additionalConstraints;


};
using RenderConstrainedBox = std::shared_ptr<RenderConstrainedBoxCls>;

class RenderLimitedBoxCls : public RenderProxyBoxCls {
public:

     RenderLimitedBoxCls(RenderBox child, double maxHeight, double maxWidth);

    virtual double maxWidth();

    virtual void  maxWidth(double value);

    virtual double maxHeight();

    virtual void  maxHeight(double value);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _maxWidth;

    double _maxHeight;


    virtual BoxConstraints _limitConstraints(BoxConstraints constraints);

    virtual Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};
using RenderLimitedBox = std::shared_ptr<RenderLimitedBoxCls>;

class RenderAspectRatioCls : public RenderProxyBoxCls {
public:

     RenderAspectRatioCls(double aspectRatio, RenderBox child);

    virtual double aspectRatio();

    virtual void  aspectRatio(double value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _aspectRatio;


    virtual Size _applyAspectRatio(BoxConstraints constraints);

};
using RenderAspectRatio = std::shared_ptr<RenderAspectRatioCls>;

class RenderIntrinsicWidthCls : public RenderProxyBoxCls {
public:

     RenderIntrinsicWidthCls(RenderBox child, double stepHeight, double stepWidth);

    virtual double stepWidth();

    virtual void  stepWidth(double value);

    virtual double stepHeight();

    virtual void  stepHeight(double value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _stepWidth;

    double _stepHeight;


    static double _applyStep(double input, double step);

    virtual Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};
using RenderIntrinsicWidth = std::shared_ptr<RenderIntrinsicWidthCls>;

class RenderIntrinsicHeightCls : public RenderProxyBoxCls {
public:

     RenderIntrinsicHeightCls(RenderBox child);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

private:

    virtual Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};
using RenderIntrinsicHeight = std::shared_ptr<RenderIntrinsicHeightCls>;

class RenderOpacityCls : public RenderProxyBoxCls {
public:

     RenderOpacityCls(bool alwaysIncludeSemantics, RenderBox child, double opacity);

    virtual bool alwaysNeedsCompositing();

    virtual double opacity();

    virtual void  opacity(double value);

    virtual bool alwaysIncludeSemantics();

    virtual void  alwaysIncludeSemantics(bool value);

    virtual bool paintsChild(RenderBox child);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;

    double _opacity;

    bool _alwaysIncludeSemantics;


};
using RenderOpacity = std::shared_ptr<RenderOpacityCls>;

template<typename T>
class RenderAnimatedOpacityMixinCls : public ObjectCls {
public:

    virtual bool isRepaintBoundary();

    virtual OffsetLayer updateCompositedLayer(OpacityLayer oldLayer);

    virtual Animation<double> opacity();

    virtual void  opacity(Animation<double> value);

    virtual bool alwaysIncludeSemantics();

    virtual void  alwaysIncludeSemantics(bool value);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual bool paintsChild(RenderObject child);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;

    bool _currentlyIsRepaintBoundary;

    Animation<double> _opacity;

    bool _alwaysIncludeSemantics;


    virtual void _updateOpacity();

};
template<typename T>
using RenderAnimatedOpacityMixin = std::shared_ptr<RenderAnimatedOpacityMixinCls<T>>;

class RenderAnimatedOpacityCls : public RenderProxyBoxCls {
public:

     RenderAnimatedOpacityCls(bool alwaysIncludeSemantics, RenderBox child, Animation<double> opacity);

private:

};
using RenderAnimatedOpacity = std::shared_ptr<RenderAnimatedOpacityCls>;

class RenderShaderMaskCls : public RenderProxyBoxCls {
public:

     RenderShaderMaskCls(BlendMode blendMode, RenderBox child, ShaderCallback shaderCallback);

    virtual ShaderMaskLayer layer();

    virtual ShaderCallback shaderCallback();

    virtual void  shaderCallback(ShaderCallback value);

    virtual BlendMode blendMode();

    virtual void  blendMode(BlendMode value);

    virtual bool alwaysNeedsCompositing();

    virtual void paint(PaintingContext context, Offset offset);

private:
    ShaderCallback _shaderCallback;

    BlendMode _blendMode;


};
using RenderShaderMask = std::shared_ptr<RenderShaderMaskCls>;

class RenderBackdropFilterCls : public RenderProxyBoxCls {
public:

     RenderBackdropFilterCls(BlendMode blendMode, RenderBox child, ImageFilter filter);

    virtual BackdropFilterLayer layer();

    virtual ImageFilter filter();

    virtual void  filter(ImageFilter value);

    virtual BlendMode blendMode();

    virtual void  blendMode(BlendMode value);

    virtual bool alwaysNeedsCompositing();

    virtual void paint(PaintingContext context, Offset offset);

private:
    ImageFilter _filter;

    BlendMode _blendMode;


};
using RenderBackdropFilter = std::shared_ptr<RenderBackdropFilterCls>;

template<typename T>
class CustomClipperCls : public ListenableCls {
public:

     CustomClipperCls(Listenable reclip);

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual T getClip(Size size);
    virtual Rect getApproximateClipRect(Size size);

    virtual bool shouldReclip(CustomClipper<T> oldClipper);
    virtual String toString();

private:
    Listenable _reclip;


};
template<typename T>
using CustomClipper = std::shared_ptr<CustomClipperCls<T>>;

class ShapeBorderClipperCls : public CustomClipperCls<Path> {
public:
    ShapeBorder shape;

    TextDirection textDirection;


     ShapeBorderClipperCls(ShapeBorder shape, TextDirection textDirection);

    virtual Path getClip(Size size);

    virtual bool shouldReclip(CustomClipper<Path> oldClipper);

private:

};
using ShapeBorderClipper = std::shared_ptr<ShapeBorderClipperCls>;

template<typename T>
class _RenderCustomClipCls : public RenderProxyBoxCls {
public:

    virtual CustomClipper<T> clipper();

    virtual void  clipper(CustomClipper<T> newClipper);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void performLayout();

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual void debugPaintSize(PaintingContext context, Offset offset);

private:
    CustomClipper<T> _clipper;

    T _clip;

    Clip _clipBehavior;

    Paint _debugPaint;

    TextPainter _debugText;


     _RenderCustomClipCls(RenderBox child, Clip clipBehavior, CustomClipper<T> clipper);

    virtual void _markNeedsClip();

    virtual T _defaultClip();
    virtual void _updateClip();

};
template<typename T>
using _RenderCustomClip = std::shared_ptr<_RenderCustomClipCls<T>>;

class RenderClipRectCls : public _RenderCustomClipCls<Rect> {
public:

     RenderClipRectCls(Unknown child, Unknown clipBehavior, Unknown clipper);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugPaintSize(PaintingContext context, Offset offset);

private:

    virtual Rect _defaultClip();

};
using RenderClipRect = std::shared_ptr<RenderClipRectCls>;

class RenderClipRRectCls : public _RenderCustomClipCls<RRect> {
public:

     RenderClipRRectCls(BorderRadiusGeometry borderRadius, Unknown child, Unknown clipBehavior, CustomClipper<RRect> clipper, TextDirection textDirection);

    virtual BorderRadiusGeometry borderRadius();

    virtual void  borderRadius(BorderRadiusGeometry value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugPaintSize(PaintingContext context, Offset offset);

private:
    BorderRadiusGeometry _borderRadius;

    TextDirection _textDirection;


    virtual RRect _defaultClip();

};
using RenderClipRRect = std::shared_ptr<RenderClipRRectCls>;

class RenderClipOvalCls : public _RenderCustomClipCls<Rect> {
public:

     RenderClipOvalCls(Unknown child, Unknown clipBehavior, Unknown clipper);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugPaintSize(PaintingContext context, Offset offset);

private:
    Rect _cachedRect;

    Path _cachedPath;


    virtual Path _getClipPath(Rect rect);

    virtual Rect _defaultClip();

};
using RenderClipOval = std::shared_ptr<RenderClipOvalCls>;

class RenderClipPathCls : public _RenderCustomClipCls<Path> {
public:

     RenderClipPathCls(Unknown child, Unknown clipBehavior, Unknown clipper);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugPaintSize(PaintingContext context, Offset offset);

private:

    virtual Path _defaultClip();

};
using RenderClipPath = std::shared_ptr<RenderClipPathCls>;

template<typename T>
class _RenderPhysicalModelBaseCls : public _RenderCustomClipCls<T> {
public:

    virtual double elevation();

    virtual void  elevation(double value);

    virtual Color shadowColor();

    virtual void  shadowColor(Color value);

    virtual Color color();

    virtual void  color(Color value);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    double _elevation;

    Color _shadowColor;

    Color _color;


     _RenderPhysicalModelBaseCls(Unknown child, Unknown clipBehavior, Unknown clipper, Color color, double elevation, Color shadowColor);

};
template<typename T>
using _RenderPhysicalModelBase = std::shared_ptr<_RenderPhysicalModelBaseCls<T>>;
Paint _transparentPaint;


class RenderPhysicalModelCls : public _RenderPhysicalModelBaseCls<RRect> {
public:

     RenderPhysicalModelCls(BorderRadius borderRadius, Unknown child, Unknown clipBehavior, Unknown color, Unknown elevation, Unknown shadowColor, BoxShape shape);

    virtual BoxShape shape();

    virtual void  shape(BoxShape value);

    virtual BorderRadius borderRadius();

    virtual void  borderRadius(BorderRadius value);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    BoxShape _shape;

    BorderRadius _borderRadius;


    virtual RRect _defaultClip();

};
using RenderPhysicalModel = std::shared_ptr<RenderPhysicalModelCls>;

class RenderPhysicalShapeCls : public _RenderPhysicalModelBaseCls<Path> {
public:

     RenderPhysicalShapeCls(Unknown child, Unknown clipBehavior, CustomClipper<Path> clipper, Unknown color, Unknown elevation, Unknown shadowColor);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:

    virtual Path _defaultClip();

};
using RenderPhysicalShape = std::shared_ptr<RenderPhysicalShapeCls>;

enum DecorationPosition{
    background,
    foreground,
} // end DecorationPosition

class RenderDecoratedBoxCls : public RenderProxyBoxCls {
public:

     RenderDecoratedBoxCls(RenderBox child, ImageConfiguration configuration, Decoration decoration, DecorationPosition position);

    virtual Decoration decoration();

    virtual void  decoration(Decoration value);

    virtual DecorationPosition position();

    virtual void  position(DecorationPosition value);

    virtual ImageConfiguration configuration();

    virtual void  configuration(ImageConfiguration value);

    virtual void detach();

    virtual bool hitTestSelf(Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    BoxPainter _painter;

    Decoration _decoration;

    DecorationPosition _position;

    ImageConfiguration _configuration;


};
using RenderDecoratedBox = std::shared_ptr<RenderDecoratedBoxCls>;

class RenderTransformCls : public RenderProxyBoxCls {
public:
    bool transformHitTests;


     RenderTransformCls(AlignmentGeometry alignment, RenderBox child, FilterQuality filterQuality, Offset origin, TextDirection textDirection, Matrix4 transform, bool transformHitTests);

    virtual Offset origin();

    virtual void  origin(Offset value);

    virtual AlignmentGeometry alignment();

    virtual void  alignment(AlignmentGeometry value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual bool alwaysNeedsCompositing();

    virtual void  transform(Matrix4 value);

    virtual FilterQuality filterQuality();

    virtual void  filterQuality(FilterQuality value);

    virtual void setIdentity();

    virtual void rotateX(double radians);

    virtual void rotateY(double radians);

    virtual void rotateZ(double radians);

    virtual void translate(double x, double y, double z);

    virtual void scale(double x, double y, double z);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Offset _origin;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;

    Matrix4 _transform;

    FilterQuality _filterQuality;


    virtual Matrix4 _effectiveTransform();

};
using RenderTransform = std::shared_ptr<RenderTransformCls>;

class RenderFittedBoxCls : public RenderProxyBoxCls {
public:

     RenderFittedBoxCls(AlignmentGeometry alignment, RenderBox child, Clip clipBehavior, BoxFit fit, TextDirection textDirection);

    virtual BoxFit fit();

    virtual void  fit(BoxFit value);

    virtual AlignmentGeometry alignment();

    virtual void  alignment(AlignmentGeometry value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void paint(PaintingContext context, Offset offset);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual bool paintsChild(RenderBox child);

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Alignment _resolvedAlignment;

    BoxFit _fit;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;

    bool _hasVisualOverflow;

    Matrix4 _transform;

    Clip _clipBehavior;


    virtual void _resolve();

    virtual void _markNeedResolution();

    virtual bool _fitAffectsLayout(BoxFit fit);

    virtual void _clearPaintData();

    virtual void _updatePaintData();

    virtual TransformLayer _paintChildWithTransform(PaintingContext context, Offset offset);

};
using RenderFittedBox = std::shared_ptr<RenderFittedBoxCls>;

class RenderFractionalTranslationCls : public RenderProxyBoxCls {
public:
    bool transformHitTests;


     RenderFractionalTranslationCls(RenderBox child, bool transformHitTests, Offset translation);

    virtual Offset translation();

    virtual void  translation(Offset value);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Offset _translation;


};
using RenderFractionalTranslation = std::shared_ptr<RenderFractionalTranslationCls>;

class RenderPointerListenerCls : public RenderProxyBoxWithHitTestBehaviorCls {
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


     RenderPointerListenerCls(Unknown behavior, Unknown child, PointerCancelEventListener onPointerCancel, PointerDownEventListener onPointerDown, PointerHoverEventListener onPointerHover, PointerMoveEventListener onPointerMove, PointerPanZoomEndEventListener onPointerPanZoomEnd, PointerPanZoomStartEventListener onPointerPanZoomStart, PointerPanZoomUpdateEventListener onPointerPanZoomUpdate, PointerSignalEventListener onPointerSignal, PointerUpEventListener onPointerUp);
    virtual Size computeSizeForNoChild(BoxConstraints constraints);

    virtual void handleEvent(PointerEvent event, HitTestEntry entry);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using RenderPointerListener = std::shared_ptr<RenderPointerListenerCls>;

class RenderMouseRegionCls : public RenderProxyBoxWithHitTestBehaviorCls {
public:
    PointerEnterEventListener onEnter;

    PointerHoverEventListener onHover;

    PointerExitEventListener onExit;


     RenderMouseRegionCls(Unknown child, MouseCursor cursor, HitTestBehavior hitTestBehavior, PointerEnterEventListener onEnter, PointerExitEventListener onExit, PointerHoverEventListener onHover, bool opaque, bool validForMouseTracker);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void handleEvent(PointerEvent event, HitTestEntry entry);

    virtual bool opaque();

    virtual void  opaque(bool value);

    virtual HitTestBehavior hitTestBehavior();

    virtual void  hitTestBehavior(HitTestBehavior value);

    virtual MouseCursor cursor();

    virtual void  cursor(MouseCursor value);

    virtual bool validForMouseTracker();

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual Size computeSizeForNoChild(BoxConstraints constraints);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _opaque;

    MouseCursor _cursor;

    bool _validForMouseTracker;


};
using RenderMouseRegion = std::shared_ptr<RenderMouseRegionCls>;

class RenderRepaintBoundaryCls : public RenderProxyBoxCls {
public:

     RenderRepaintBoundaryCls(RenderBox child);

    virtual bool isRepaintBoundary();

    virtual Future<Image> toImage(double pixelRatio);

    virtual int debugSymmetricPaintCount();

    virtual int debugAsymmetricPaintCount();

    virtual void debugResetMetrics();

    virtual void debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _debugSymmetricPaintCount;

    int _debugAsymmetricPaintCount;


};
using RenderRepaintBoundary = std::shared_ptr<RenderRepaintBoundaryCls>;

class RenderIgnorePointerCls : public RenderProxyBoxCls {
public:

     RenderIgnorePointerCls(RenderBox child, bool ignoring, bool ignoringSemantics);

    virtual bool ignoring();

    virtual void  ignoring(bool value);

    virtual bool ignoringSemantics();

    virtual void  ignoringSemantics(bool value);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _ignoring;

    bool _ignoringSemantics;


    virtual bool _effectiveIgnoringSemantics();

};
using RenderIgnorePointer = std::shared_ptr<RenderIgnorePointerCls>;

class RenderOffstageCls : public RenderProxyBoxCls {
public:

     RenderOffstageCls(RenderBox child, bool offstage);

    virtual bool offstage();

    virtual void  offstage(bool value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual bool sizedByParent();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performResize();

    virtual void performLayout();

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual bool paintsChild(RenderBox child);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    bool _offstage;


};
using RenderOffstage = std::shared_ptr<RenderOffstageCls>;

class RenderAbsorbPointerCls : public RenderProxyBoxCls {
public:

     RenderAbsorbPointerCls(bool absorbing, RenderBox child, bool ignoringSemantics);

    virtual bool absorbing();

    virtual void  absorbing(bool value);

    virtual bool ignoringSemantics();

    virtual void  ignoringSemantics(bool value);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _absorbing;

    bool _ignoringSemantics;


    virtual bool _effectiveIgnoringSemantics();

};
using RenderAbsorbPointer = std::shared_ptr<RenderAbsorbPointerCls>;

class RenderMetaDataCls : public RenderProxyBoxWithHitTestBehaviorCls {
public:
    dynamic metaData;


     RenderMetaDataCls(Unknown behavior, Unknown child, dynamic metaData);
    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using RenderMetaData = std::shared_ptr<RenderMetaDataCls>;

class RenderSemanticsGestureHandlerCls : public RenderProxyBoxWithHitTestBehaviorCls {
public:
    double scrollFactor;


     RenderSemanticsGestureHandlerCls(Unknown behavior, Unknown child, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureTapCallback onTap, GestureDragUpdateCallback onVerticalDragUpdate, double scrollFactor);

    virtual Set<SemanticsAction> validActions();

    virtual void  validActions(Set<SemanticsAction> value);

    virtual GestureTapCallback onTap();

    virtual void  onTap(GestureTapCallback value);

    virtual GestureLongPressCallback onLongPress();

    virtual void  onLongPress(GestureLongPressCallback value);

    virtual GestureDragUpdateCallback onHorizontalDragUpdate();

    virtual void  onHorizontalDragUpdate(GestureDragUpdateCallback value);

    virtual GestureDragUpdateCallback onVerticalDragUpdate();

    virtual void  onVerticalDragUpdate(GestureDragUpdateCallback value);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Set<SemanticsAction> _validActions;

    GestureTapCallback _onTap;

    GestureLongPressCallback _onLongPress;

    GestureDragUpdateCallback _onHorizontalDragUpdate;

    GestureDragUpdateCallback _onVerticalDragUpdate;


    virtual bool _isValidAction(SemanticsAction action);

    virtual void _performSemanticScrollLeft();

    virtual void _performSemanticScrollRight();

    virtual void _performSemanticScrollUp();

    virtual void _performSemanticScrollDown();

};
using RenderSemanticsGestureHandler = std::shared_ptr<RenderSemanticsGestureHandlerCls>;

class RenderSemanticsAnnotationsCls : public RenderProxyBoxCls {
public:

     RenderSemanticsAnnotationsCls(RenderBox child, bool container, bool excludeSemantics, bool explicitChildNodes, SemanticsProperties properties, TextDirection textDirection);

    virtual SemanticsProperties properties();

    virtual void  properties(SemanticsProperties value);

    virtual bool container();

    virtual void  container(bool value);

    virtual bool explicitChildNodes();

    virtual void  explicitChildNodes(bool value);

    virtual bool excludeSemantics();

    virtual void  excludeSemantics(bool value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

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


    virtual void _updateAttributedFields(SemanticsProperties value);

    virtual AttributedString _effectiveAttributedLabel(SemanticsProperties value);

    virtual AttributedString _effectiveAttributedValue(SemanticsProperties value);

    virtual AttributedString _effectiveAttributedIncreasedValue(SemanticsProperties value);

    virtual AttributedString _effectiveAttributedDecreasedValue(SemanticsProperties value);

    virtual AttributedString _effectiveAttributedHint(SemanticsProperties value);

    virtual void _performTap();

    virtual void _performLongPress();

    virtual void _performDismiss();

    virtual void _performScrollLeft();

    virtual void _performScrollRight();

    virtual void _performScrollUp();

    virtual void _performScrollDown();

    virtual void _performIncrease();

    virtual void _performDecrease();

    virtual void _performCopy();

    virtual void _performCut();

    virtual void _performPaste();

    virtual void _performMoveCursorForwardByCharacter(bool extendSelection);

    virtual void _performMoveCursorBackwardByCharacter(bool extendSelection);

    virtual void _performMoveCursorForwardByWord(bool extendSelection);

    virtual void _performMoveCursorBackwardByWord(bool extendSelection);

    virtual void _performSetSelection(TextSelection selection);

    virtual void _performSetText(String text);

    virtual void _performDidGainAccessibilityFocus();

    virtual void _performDidLoseAccessibilityFocus();

};
using RenderSemanticsAnnotations = std::shared_ptr<RenderSemanticsAnnotationsCls>;

class RenderBlockSemanticsCls : public RenderProxyBoxCls {
public:

     RenderBlockSemanticsCls(bool blocking, RenderBox child);

    virtual bool blocking();

    virtual void  blocking(bool value);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _blocking;


};
using RenderBlockSemantics = std::shared_ptr<RenderBlockSemanticsCls>;

class RenderMergeSemanticsCls : public RenderProxyBoxCls {
public:

     RenderMergeSemanticsCls(RenderBox child);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

private:

};
using RenderMergeSemantics = std::shared_ptr<RenderMergeSemanticsCls>;

class RenderExcludeSemanticsCls : public RenderProxyBoxCls {
public:

     RenderExcludeSemanticsCls(RenderBox child, bool excluding);

    virtual bool excluding();

    virtual void  excluding(bool value);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _excluding;


};
using RenderExcludeSemantics = std::shared_ptr<RenderExcludeSemanticsCls>;

class RenderIndexedSemanticsCls : public RenderProxyBoxCls {
public:

     RenderIndexedSemanticsCls(RenderBox child, int index);

    virtual int index();

    virtual void  index(int value);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _index;


};
using RenderIndexedSemantics = std::shared_ptr<RenderIndexedSemanticsCls>;

class RenderLeaderLayerCls : public RenderProxyBoxCls {
public:

     RenderLeaderLayerCls(RenderBox child, LayerLink link);

    virtual LayerLink link();

    virtual void  link(LayerLink value);

    virtual bool alwaysNeedsCompositing();

    virtual void performLayout();

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    Size _previousLayoutSize;


};
using RenderLeaderLayer = std::shared_ptr<RenderLeaderLayerCls>;

class RenderFollowerLayerCls : public RenderProxyBoxCls {
public:

     RenderFollowerLayerCls(RenderBox child, Alignment followerAnchor, Alignment leaderAnchor, LayerLink link, Offset offset, bool showWhenUnlinked);

    virtual LayerLink link();

    virtual void  link(LayerLink value);

    virtual bool showWhenUnlinked();

    virtual void  showWhenUnlinked(bool value);

    virtual Offset offset();

    virtual void  offset(Offset value);

    virtual Alignment leaderAnchor();

    virtual void  leaderAnchor(Alignment value);

    virtual Alignment followerAnchor();

    virtual void  followerAnchor(Alignment value);

    virtual void detach();

    virtual bool alwaysNeedsCompositing();

    virtual FollowerLayer layer();

    virtual Matrix4 getCurrentTransform();

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    bool _showWhenUnlinked;

    Offset _offset;

    Alignment _leaderAnchor;

    Alignment _followerAnchor;


};
using RenderFollowerLayer = std::shared_ptr<RenderFollowerLayerCls>;

template<typename T>
class RenderAnnotatedRegionCls : public RenderProxyBoxCls {
public:
    bool alwaysNeedsCompositing;


     RenderAnnotatedRegionCls(RenderBox child, bool sized, T value);

    virtual T value();

    virtual void  value(T newValue);

    virtual bool sized();

    virtual void  sized(bool value);

    virtual void paint(PaintingContext context, Offset offset);

private:
    T _value;

    bool _sized;


};
template<typename T>
using RenderAnnotatedRegion = std::shared_ptr<RenderAnnotatedRegionCls<T>>;


#endif