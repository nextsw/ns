#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT_SELECTION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT_SELECTION
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/math/math.hpp>
#include <packages/characters/characters.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "constants.hpp"
#include "container.hpp"
#include "editable_text.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "overlay.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"

Duration _kDragSelectionUpdateThrottle;


class ToolbarItemsParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:
    bool shouldPaint;


    virtual String toString();

private:

};
using ToolbarItemsParentData = std::shared_ptr<ToolbarItemsParentDataCls>;

class TextSelectionControlsCls : public ObjectCls {
public:

    virtual Widget buildHandle(BuildContext context, VoidCallback onTap, double textLineHeight, TextSelectionHandleType type);
    virtual Offset getHandleAnchor(double textLineHeight, TextSelectionHandleType type);
    virtual Widget buildToolbar(ClipboardStatusNotifier clipboardStatus, BuildContext context, TextSelectionDelegate delegate, List<TextSelectionPoint> endpoints, Rect globalEditableRegion, Offset lastSecondaryTapDownPosition, Offset position, double textLineHeight);
    virtual Size getHandleSize(double textLineHeight);
    virtual bool canCut(TextSelectionDelegate delegate);

    virtual bool canCopy(TextSelectionDelegate delegate);

    virtual bool canPaste(TextSelectionDelegate delegate);

    virtual bool canSelectAll(TextSelectionDelegate delegate);

    virtual void handleCut(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate);

    virtual void handleCopy(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate);

    virtual Future<void> handlePaste(TextSelectionDelegate delegate);

    virtual void handleSelectAll(TextSelectionDelegate delegate);

private:

};
using TextSelectionControls = std::shared_ptr<TextSelectionControlsCls>;

class TextSelectionOverlayCls : public ObjectCls {
public:
    static Duration fadeDuration;

    RenderEditable renderObject;

    TextSelectionControls selectionControls;

    TextSelectionDelegate selectionDelegate;


     TextSelectionOverlayCls(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, bool handlesVisible, VoidCallback onSelectionHandleTapped, RenderEditable renderObject, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, LayerLink startHandleLayerLink, LayerLink toolbarLayerLink, TextEditingValue value);

    virtual TextEditingValue value();

    virtual bool handlesVisible();

    virtual void  handlesVisible(bool visible);

    virtual void showHandles();

    virtual void hideHandles();

    virtual void showToolbar();

    virtual void update(TextEditingValue newValue);

    virtual void updateForScroll();

    virtual bool handlesAreVisible();

    virtual bool toolbarIsVisible();

    virtual void hide();

    virtual void hideToolbar();

    virtual void dispose();

private:
    SelectionOverlay _selectionOverlay;

    TextEditingValue _value;

    ValueNotifier<bool> _effectiveStartHandleVisibility;

    ValueNotifier<bool> _effectiveEndHandleVisibility;

    ValueNotifier<bool> _effectiveToolbarVisibility;

    bool _handlesVisible;

    Offset _dragEndPosition;

    Offset _dragStartPosition;


    virtual TextSelection _selection();

    virtual void _updateTextSelectionOverlayVisibilities();

    virtual void _updateSelectionOverlay();

    virtual double _getStartGlyphHeight();

    virtual double _getEndGlyphHeight();

    virtual void _handleSelectionEndHandleDragStart(DragStartDetails details);

    virtual void _handleSelectionEndHandleDragUpdate(DragUpdateDetails details);

    virtual void _handleSelectionStartHandleDragStart(DragStartDetails details);

    virtual void _handleSelectionStartHandleDragUpdate(DragUpdateDetails details);

    virtual void _handleSelectionHandleChanged(bool isEnd, TextSelection newSelection);

    virtual TextSelectionHandleType _chooseType(TextSelectionHandleType ltrType, TextSelectionHandleType rtlType, TextDirection textDirection);

};
using TextSelectionOverlay = std::shared_ptr<TextSelectionOverlayCls>;

class SelectionOverlayCls : public ObjectCls {
public:
    BuildContext context;

    ValueListenable<bool> startHandlesVisible;

    ValueChanged<DragStartDetails> onStartHandleDragStart;

    ValueChanged<DragUpdateDetails> onStartHandleDragUpdate;

    ValueChanged<DragEndDetails> onStartHandleDragEnd;

    ValueListenable<bool> endHandlesVisible;

    ValueChanged<DragStartDetails> onEndHandleDragStart;

    ValueChanged<DragUpdateDetails> onEndHandleDragUpdate;

    ValueChanged<DragEndDetails> onEndHandleDragEnd;

    ValueListenable<bool> toolbarVisible;

    Widget debugRequiredFor;

    LayerLink toolbarLayerLink;

    LayerLink startHandleLayerLink;

    LayerLink endHandleLayerLink;

    TextSelectionControls selectionControls;

    TextSelectionDelegate selectionDelegate;

    DragStartBehavior dragStartBehavior;

    VoidCallback onSelectionHandleTapped;

    ClipboardStatusNotifier clipboardStatus;

    static Duration fadeDuration;


     SelectionOverlayCls(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, TextSelectionHandleType endHandleType, ValueListenable<bool> endHandlesVisible, double lineHeightAtEnd, double lineHeightAtStart, ValueChanged<DragEndDetails> onEndHandleDragEnd, ValueChanged<DragStartDetails> onEndHandleDragStart, ValueChanged<DragUpdateDetails> onEndHandleDragUpdate, VoidCallback onSelectionHandleTapped, ValueChanged<DragEndDetails> onStartHandleDragEnd, ValueChanged<DragStartDetails> onStartHandleDragStart, ValueChanged<DragUpdateDetails> onStartHandleDragUpdate, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, List<TextSelectionPoint> selectionEndpoints, LayerLink startHandleLayerLink, TextSelectionHandleType startHandleType, ValueListenable<bool> startHandlesVisible, LayerLink toolbarLayerLink, Offset toolbarLocation, ValueListenable<bool> toolbarVisible);

    virtual TextSelectionHandleType startHandleType();

    virtual void  startHandleType(TextSelectionHandleType value);

    virtual double lineHeightAtStart();

    virtual void  lineHeightAtStart(double value);

    virtual TextSelectionHandleType endHandleType();

    virtual void  endHandleType(TextSelectionHandleType value);

    virtual double lineHeightAtEnd();

    virtual void  lineHeightAtEnd(double value);

    virtual List<TextSelectionPoint> selectionEndpoints();

    virtual void  selectionEndpoints(List<TextSelectionPoint> value);

    virtual Offset toolbarLocation();

    virtual void  toolbarLocation(Offset value);

    virtual void showHandles();

    virtual void hideHandles();

    virtual void showToolbar();

    virtual void hide();

    virtual void hideToolbar();

    virtual void dispose();

private:
    TextSelectionHandleType _startHandleType;

    double _lineHeightAtStart;

    TextSelectionHandleType _endHandleType;

    double _lineHeightAtEnd;

    List<TextSelectionPoint> _selectionEndpoints;

    Offset _toolbarLocation;

    List<OverlayEntry> _handles;

    OverlayEntry _toolbar;

    bool _buildScheduled;


    virtual void _markNeedsBuild();

    virtual Widget _buildStartHandle(BuildContext context);

    virtual Widget _buildEndHandle(BuildContext context);

    virtual Widget _buildToolbar(BuildContext context);

};
using SelectionOverlay = std::shared_ptr<SelectionOverlayCls>;

class _SelectionToolbarOverlayCls : public StatefulWidgetCls {
public:
    double preferredLineHeight;

    Offset toolbarLocation;

    LayerLink layerLink;

    Rect editingRegion;

    TextSelectionControls selectionControls;

    ValueListenable<bool> visibility;

    Offset midpoint;

    List<TextSelectionPoint> selectionEndpoints;

    TextSelectionDelegate selectionDelegate;

    ClipboardStatusNotifier clipboardStatus;


    virtual _SelectionToolbarOverlayState createState();

private:

     _SelectionToolbarOverlayCls(ClipboardStatusNotifier clipboardStatus, Rect editingRegion, LayerLink layerLink, Offset midpoint, double preferredLineHeight, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, List<TextSelectionPoint> selectionEndpoints, Offset toolbarLocation, ValueListenable<bool> visibility);
};
using _SelectionToolbarOverlay = std::shared_ptr<_SelectionToolbarOverlayCls>;

class _SelectionToolbarOverlayStateCls : public StateCls<_SelectionToolbarOverlay> {
public:

    virtual void initState();

    virtual void didUpdateWidget(_SelectionToolbarOverlay oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    AnimationController _controller;


    virtual Animation<double> _opacity();

    virtual void _toolbarVisibilityChanged();

};
using _SelectionToolbarOverlayState = std::shared_ptr<_SelectionToolbarOverlayStateCls>;

class _SelectionHandleOverlayCls : public StatefulWidgetCls {
public:
    LayerLink handleLayerLink;

    VoidCallback onSelectionHandleTapped;

    ValueChanged<DragStartDetails> onSelectionHandleDragStart;

    ValueChanged<DragUpdateDetails> onSelectionHandleDragUpdate;

    ValueChanged<DragEndDetails> onSelectionHandleDragEnd;

    TextSelectionControls selectionControls;

    ValueListenable<bool> visibility;

    double preferredLineHeight;

    TextSelectionHandleType type;

    DragStartBehavior dragStartBehavior;


    virtual State<_SelectionHandleOverlay> createState();

private:

     _SelectionHandleOverlayCls(DragStartBehavior dragStartBehavior, LayerLink handleLayerLink, ValueChanged<DragEndDetails> onSelectionHandleDragEnd, ValueChanged<DragStartDetails> onSelectionHandleDragStart, ValueChanged<DragUpdateDetails> onSelectionHandleDragUpdate, VoidCallback onSelectionHandleTapped, double preferredLineHeight, TextSelectionControls selectionControls, TextSelectionHandleType type, ValueListenable<bool> visibility);
};
using _SelectionHandleOverlay = std::shared_ptr<_SelectionHandleOverlayCls>;

class _SelectionHandleOverlayStateCls : public StateCls<_SelectionHandleOverlay> {
public:

    virtual void initState();

    virtual void didUpdateWidget(_SelectionHandleOverlay oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    AnimationController _controller;


    virtual Animation<double> _opacity();

    virtual void _handleVisibilityChanged();

};
using _SelectionHandleOverlayState = std::shared_ptr<_SelectionHandleOverlayStateCls>;

class TextSelectionGestureDetectorBuilderDelegateCls : public ObjectCls {
public:

    virtual GlobalKey<EditableTextState> editableTextKey();
    virtual bool forcePressEnabled();
    virtual bool selectionEnabled();
private:

};
using TextSelectionGestureDetectorBuilderDelegate = std::shared_ptr<TextSelectionGestureDetectorBuilderDelegateCls>;

class TextSelectionGestureDetectorBuilderCls : public ObjectCls {
public:
    TextSelectionGestureDetectorBuilderDelegate delegate;


     TextSelectionGestureDetectorBuilderCls(TextSelectionGestureDetectorBuilderDelegate delegate);

    virtual bool shouldShowSelectionToolbar();

    virtual EditableTextState editableText();

    virtual RenderEditable renderEditable();

    virtual void onTapDown(TapDownDetails details);

    virtual void onForcePressStart(ForcePressDetails details);

    virtual void onForcePressEnd(ForcePressDetails details);

    virtual void onSingleTapUp(TapUpDetails details);

    virtual void onSingleTapCancel();

    virtual void onSingleLongTapStart(LongPressStartDetails details);

    virtual void onSingleLongTapMoveUpdate(LongPressMoveUpdateDetails details);

    virtual void onSingleLongTapEnd(LongPressEndDetails details);

    virtual void onSecondaryTap();

    virtual void onSecondaryTapDown(TapDownDetails details);

    virtual void onDoubleTapDown(TapDownDetails details);

    virtual void onDragSelectionStart(DragStartDetails details);

    virtual void onDragSelectionUpdate(DragStartDetails startDetails, DragUpdateDetails updateDetails);

    virtual void onDragSelectionEnd(DragEndDetails details);

    virtual Widget buildGestureDetector(HitTestBehavior behavior, Widget child, Key key);

private:
    bool _shouldShowSelectionToolbar;

    double _dragStartViewportOffset;

    bool _isShiftTapping;

    TextSelection _shiftTapDragSelection;


    virtual bool _lastSecondaryTapWasOnSelection();

    virtual void _expandSelection(SelectionChangedCause cause, TextSelection fromSelection, Offset offset);

    virtual void _extendSelection(SelectionChangedCause cause, Offset offset);

    virtual bool _isShiftPressed();

};
using TextSelectionGestureDetectorBuilder = std::shared_ptr<TextSelectionGestureDetectorBuilderCls>;

class TextSelectionGestureDetectorCls : public StatefulWidgetCls {
public:
    GestureTapDownCallback onTapDown;

    GestureForcePressStartCallback onForcePressStart;

    GestureForcePressEndCallback onForcePressEnd;

    GestureTapCallback onSecondaryTap;

    GestureTapDownCallback onSecondaryTapDown;

    GestureTapUpCallback onSingleTapUp;

    GestureTapCancelCallback onSingleTapCancel;

    GestureLongPressStartCallback onSingleLongTapStart;

    GestureLongPressMoveUpdateCallback onSingleLongTapMoveUpdate;

    GestureLongPressEndCallback onSingleLongTapEnd;

    GestureTapDownCallback onDoubleTapDown;

    GestureDragStartCallback onDragSelectionStart;

    DragSelectionUpdateCallback onDragSelectionUpdate;

    GestureDragEndCallback onDragSelectionEnd;

    HitTestBehavior behavior;

    Widget child;


     TextSelectionGestureDetectorCls(HitTestBehavior behavior, Widget child, Unknown key, GestureTapDownCallback onDoubleTapDown, GestureDragEndCallback onDragSelectionEnd, GestureDragStartCallback onDragSelectionStart, DragSelectionUpdateCallback onDragSelectionUpdate, GestureForcePressEndCallback onForcePressEnd, GestureForcePressStartCallback onForcePressStart, GestureTapCallback onSecondaryTap, GestureTapDownCallback onSecondaryTapDown, GestureLongPressEndCallback onSingleLongTapEnd, GestureLongPressMoveUpdateCallback onSingleLongTapMoveUpdate, GestureLongPressStartCallback onSingleLongTapStart, GestureTapCancelCallback onSingleTapCancel, GestureTapUpCallback onSingleTapUp, GestureTapDownCallback onTapDown);

    virtual State<StatefulWidget> createState();

private:

};
using TextSelectionGestureDetector = std::shared_ptr<TextSelectionGestureDetectorCls>;

class _TextSelectionGestureDetectorStateCls : public StateCls<TextSelectionGestureDetector> {
public:

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    Timer _doubleTapTimer;

    Offset _lastTapOffset;

    bool _isDoubleTap;

    DragStartDetails _lastDragStartDetails;

    DragUpdateDetails _lastDragUpdateDetails;

    Timer _dragUpdateThrottleTimer;


    virtual void _handleTapDown(TapDownDetails details);

    virtual void _handleTapUp(TapUpDetails details);

    virtual void _handleTapCancel();

    virtual void _handleDragStart(DragStartDetails details);

    virtual void _handleDragUpdate(DragUpdateDetails details);

    virtual void _handleDragUpdateThrottled();

    virtual void _handleDragEnd(DragEndDetails details);

    virtual void _forcePressStarted(ForcePressDetails details);

    virtual void _forcePressEnded(ForcePressDetails details);

    virtual void _handleLongPressStart(LongPressStartDetails details);

    virtual void _handleLongPressMoveUpdate(LongPressMoveUpdateDetails details);

    virtual void _handleLongPressEnd(LongPressEndDetails details);

    virtual void _doubleTapTimeout();

    virtual bool _isWithinDoubleTapTolerance(Offset secondTapOffset);

};
using _TextSelectionGestureDetectorState = std::shared_ptr<_TextSelectionGestureDetectorStateCls>;

class ClipboardStatusNotifierCls : public ValueNotifierCls<ClipboardStatus> {
public:

     ClipboardStatusNotifierCls(ClipboardStatus value);

    virtual bool disposed();

    virtual Future<void> update();

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void didChangeAppLifecycleState(AppLifecycleState state);

    virtual void dispose();

private:
    bool _disposed;


};
using ClipboardStatusNotifier = std::shared_ptr<ClipboardStatusNotifierCls>;

enum ClipboardStatus{
    pasteable,
    unknown,
    notPasteable,
} // end ClipboardStatus


#endif