#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_OVERLAY
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_OVERLAY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "ticker_provider.hpp"


class OverlayEntryCls : public ObjectCls {
public:
    WidgetBuilder builder;


     OverlayEntryCls(WidgetBuilder builder, bool maintainState, bool opaque);

    virtual bool opaque();

    virtual void  opaque(bool value);

    virtual bool maintainState();

    virtual void  maintainState(bool value);

    virtual bool mounted();

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void remove();

    virtual void markNeedsBuild();

    virtual void dispose();

    virtual String toString();

private:
    bool _opaque;

    bool _maintainState;

    ValueNotifier<bool> _overlayStateMounted;

    OverlayState _overlay;

    GlobalKey<_OverlayEntryWidgetState> _key;

    bool _disposedByOwner;


    virtual void _didUnmount();

};
using OverlayEntry = std::shared_ptr<OverlayEntryCls>;

class _OverlayEntryWidgetCls : public StatefulWidgetCls {
public:
    OverlayEntry entry;

    bool tickerEnabled;


    virtual _OverlayEntryWidgetState createState();

private:

     _OverlayEntryWidgetCls(OverlayEntry entry, Key key, bool tickerEnabled);

};
using _OverlayEntryWidget = std::shared_ptr<_OverlayEntryWidgetCls>;

class _OverlayEntryWidgetStateCls : public StateCls<_OverlayEntryWidget> {
public:

    virtual void initState();

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

    virtual void _markNeedsBuild();

};
using _OverlayEntryWidgetState = std::shared_ptr<_OverlayEntryWidgetStateCls>;

class OverlayCls : public StatefulWidgetCls {
public:
    List<OverlayEntry> initialEntries;

    Clip clipBehavior;


     OverlayCls(Clip clipBehavior, List<OverlayEntry> initialEntries, Unknown key);

    static OverlayState of(BuildContext context, Widget debugRequiredFor, bool rootOverlay);

    virtual OverlayState createState();

private:

};
using Overlay = std::shared_ptr<OverlayCls>;

class OverlayStateCls : public StateCls<Overlay> {
public:

    virtual void initState();

    virtual void insert(OverlayEntry entry, OverlayEntry above, OverlayEntry below);

    virtual void insertAll(Iterable<OverlayEntry> entries, OverlayEntry above, OverlayEntry below);

    virtual void rearrange(Iterable<OverlayEntry> newEntries, OverlayEntry above, OverlayEntry below);

    virtual bool debugIsVisible(OverlayEntry entry);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    List<OverlayEntry> _entries;


    virtual int _insertionIndex(OverlayEntry below, OverlayEntry above);

    virtual bool _debugVerifyInsertPosition(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> newEntries);

    virtual void _markDirty();

    virtual void _didChangeEntryOpacity();

};
using OverlayState = std::shared_ptr<OverlayStateCls>;

class _TheatreCls : public MultiChildRenderObjectWidgetCls {
public:
    int skipCount;

    Clip clipBehavior;


    virtual _TheatreElement createElement();

    virtual _RenderTheatre createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _RenderTheatre renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _TheatreCls(Unknown children, Clip clipBehavior, int skipCount);

};
using _Theatre = std::shared_ptr<_TheatreCls>;

class _TheatreElementCls : public MultiChildRenderObjectElementCls {
public:

    virtual _RenderTheatre renderObject();

    virtual void debugVisitOnstageChildren(ElementVisitor visitor);

private:

     _TheatreElementCls(_Theatre widget);
};
using _TheatreElement = std::shared_ptr<_TheatreElementCls>;

class _RenderTheatreCls : public RenderBoxCls {
public:

    virtual void setupParentData(RenderBox child);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual int skipCount();

    virtual void  skipCount(int value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual bool sizedByParent();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paintStack(PaintingContext context, Offset offset);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    bool _hasVisualOverflow;

    Alignment _resolvedAlignment;

    TextDirection _textDirection;

    int _skipCount;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


     _RenderTheatreCls(List<RenderBox> children, Clip clipBehavior, int skipCount, TextDirection textDirection);

    virtual void _resolve();

    virtual void _markNeedResolution();

    virtual RenderBox _firstOnstageChild();

    virtual RenderBox _lastOnstageChild();

    virtual int _onstageChildCount();

};
using _RenderTheatre = std::shared_ptr<_RenderTheatreCls>;


#endif