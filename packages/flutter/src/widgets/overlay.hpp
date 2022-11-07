#ifndef OVERLAY_H
#define OVERLAY_H
#include <memory>

#include <collection/collection.hpp>
#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "ticker_provider.hpp"



class OverlayEntry {
public:
    WidgetBuilder builder;


     OverlayEntry(WidgetBuilder builder, bool maintainState, bool opaque);

    bool opaque();

    void  opaque(bool value);

    bool maintainState();

    void  maintainState(bool value);

    bool mounted();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void remove();

    void markNeedsBuild();

    void dispose();

    String toString();

private:
    bool _opaque;

    bool _maintainState;

    ValueNotifier<bool> _overlayStateMounted;

    OverlayState _overlay;

    GlobalKey<_OverlayEntryWidgetState> _key;

    bool _disposedByOwner;


    void _didUnmount();

};

class _OverlayEntryWidget : StatefulWidget {
public:
    OverlayEntry entry;

    bool tickerEnabled;


    _OverlayEntryWidgetState createState();

private:

     _OverlayEntryWidget(OverlayEntry entry, Key key, bool tickerEnabled);

};

class _OverlayEntryWidgetState : State<_OverlayEntryWidget> {
public:

    void initState();

    void dispose();

    Widget build(BuildContext context);

private:

    void _markNeedsBuild();

};

class Overlay : StatefulWidget {
public:
    List<OverlayEntry> initialEntries;

    Clip clipBehavior;


     Overlay(Clip clipBehavior, List<OverlayEntry> initialEntries, Unknown);

    static OverlayState of(BuildContext context, Widget debugRequiredFor, bool rootOverlay);

    OverlayState createState();

private:

};

class OverlayState : State<Overlay> {
public:

    void initState();

    void insert(OverlayEntry above, OverlayEntry below, OverlayEntry entry);

    void insertAll(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> entries);

    void rearrange(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> newEntries);

    bool debugIsVisible(OverlayEntry entry);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    List<OverlayEntry> _entries;


    int _insertionIndex(OverlayEntry above, OverlayEntry below);

    bool _debugVerifyInsertPosition(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> newEntries);

    void _markDirty();

    void _didChangeEntryOpacity();

};

class _Theatre : MultiChildRenderObjectWidget {
public:
    int skipCount;

    Clip clipBehavior;


    _TheatreElement createElement();

    _RenderTheatre createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _RenderTheatre renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _Theatre(Unknown, Clip clipBehavior, int skipCount);

};

class _TheatreElement : MultiChildRenderObjectElement {
public:

    _RenderTheatre renderObject();

    void debugVisitOnstageChildren(ElementVisitor visitor);

private:

     _TheatreElement(_Theatre widget);

};

class _RenderTheatre : RenderBox {
public:

    void setupParentData(RenderBox child);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    int skipCount();

    void  skipCount(int value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    bool sizedByParent();

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paintStack(PaintingContext context, Offset offset);

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    Rect describeApproximatePaintClip(RenderObject child);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    bool _hasVisualOverflow;

    Alignment _resolvedAlignment;

    TextDirection _textDirection;

    int _skipCount;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


     _RenderTheatre(List<RenderBox> children, Clip clipBehavior, int skipCount, TextDirection textDirection);

    void _resolve();

    void _markNeedResolution();

    RenderBox _firstOnstageChild();

    RenderBox _lastOnstageChild();

    int _onstageChildCount();

};

#endif