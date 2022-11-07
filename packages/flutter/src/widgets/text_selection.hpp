#ifndef TEXT_SELECTION_H
#define TEXT_SELECTION_H
#include <memory>
#include <flutter/services.hpp>

#include <async/async.hpp>
#include <math/math.hpp>
#include <characters/characters.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
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


const Duration _kDragSelectionUpdateThrottle;


class ToolbarItemsParentData : ContainerBoxParentData<RenderBox> {
public:
    bool shouldPaint;


    String toString();

private:

};

class TextSelectionControls {
public:

    Widget buildHandle(BuildContext context, VoidCallback onTap, double textLineHeight, TextSelectionHandleType type);

    Offset getHandleAnchor(double textLineHeight, TextSelectionHandleType type);

    Widget buildToolbar(ClipboardStatusNotifier clipboardStatus, BuildContext context, TextSelectionDelegate delegate, List<TextSelectionPoint> endpoints, Rect globalEditableRegion, Offset lastSecondaryTapDownPosition, Offset position, double textLineHeight);

    Size getHandleSize(double textLineHeight);

    bool canCut(TextSelectionDelegate delegate);

    bool canCopy(TextSelectionDelegate delegate);

    bool canPaste(TextSelectionDelegate delegate);

    bool canSelectAll(TextSelectionDelegate delegate);

    void handleCut(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate);

    void handleCopy(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate);

    Future<void> handlePaste(TextSelectionDelegate delegate);

    void handleSelectAll(TextSelectionDelegate delegate);

private:

};

class TextSelectionOverlay {
public:
    static const Duration fadeDuration;

    RenderEditable renderObject;

    TextSelectionControls selectionControls;

    TextSelectionDelegate selectionDelegate;


     TextSelectionOverlay(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, bool handlesVisible, VoidCallback onSelectionHandleTapped, RenderEditable renderObject, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, LayerLink startHandleLayerLink, LayerLink toolbarLayerLink, TextEditingValue value);

    TextEditingValue value();

    bool handlesVisible();

    void  handlesVisible(bool visible);

    void showHandles();

    void hideHandles();

    void showToolbar();

    void update(TextEditingValue newValue);

    void updateForScroll();

    bool handlesAreVisible();

    bool toolbarIsVisible();

    void hide();

    void hideToolbar();

    void dispose();

private:
    SelectionOverlay _selectionOverlay;

    TextEditingValue _value;

    ValueNotifier<bool> _effectiveStartHandleVisibility;

    ValueNotifier<bool> _effectiveEndHandleVisibility;

    ValueNotifier<bool> _effectiveToolbarVisibility;

    bool _handlesVisible;

    Offset _dragEndPosition;

    Offset _dragStartPosition;


    TextSelection _selection();

    void _updateTextSelectionOverlayVisibilities();

    void _updateSelectionOverlay();

    double _getStartGlyphHeight();

    double _getEndGlyphHeight();

    void _handleSelectionEndHandleDragStart(DragStartDetails details);

    void _handleSelectionEndHandleDragUpdate(DragUpdateDetails details);

    void _handleSelectionStartHandleDragStart(DragStartDetails details);

    void _handleSelectionStartHandleDragUpdate(DragUpdateDetails details);

    void _handleSelectionHandleChanged(bool isEnd, TextSelection newSelection);

    TextSelectionHandleType _chooseType(TextSelectionHandleType ltrType, TextSelectionHandleType rtlType, TextDirection textDirection);

};

class SelectionOverlay {
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

    static const Duration fadeDuration;


     SelectionOverlay(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, TextSelectionHandleType endHandleType, ValueListenable<bool> endHandlesVisible, double lineHeightAtEnd, double lineHeightAtStart, ValueChanged<DragEndDetails> onEndHandleDragEnd, ValueChanged<DragStartDetails> onEndHandleDragStart, ValueChanged<DragUpdateDetails> onEndHandleDragUpdate, VoidCallback onSelectionHandleTapped, ValueChanged<DragEndDetails> onStartHandleDragEnd, ValueChanged<DragStartDetails> onStartHandleDragStart, ValueChanged<DragUpdateDetails> onStartHandleDragUpdate, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, List<TextSelectionPoint> selectionEndpoints, LayerLink startHandleLayerLink, TextSelectionHandleType startHandleType, ValueListenable<bool> startHandlesVisible, LayerLink toolbarLayerLink, Offset toolbarLocation, ValueListenable<bool> toolbarVisible);

    TextSelectionHandleType startHandleType();

    void  startHandleType(TextSelectionHandleType value);

    double lineHeightAtStart();

    void  lineHeightAtStart(double value);

    TextSelectionHandleType endHandleType();

    void  endHandleType(TextSelectionHandleType value);

    double lineHeightAtEnd();

    void  lineHeightAtEnd(double value);

    List<TextSelectionPoint> selectionEndpoints();

    void  selectionEndpoints(List<TextSelectionPoint> value);

    Offset toolbarLocation();

    void  toolbarLocation(Offset value);

    void showHandles();

    void hideHandles();

    void showToolbar();

    void hide();

    void hideToolbar();

    void dispose();

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


    void _markNeedsBuild();

    Widget _buildStartHandle(BuildContext context);

    Widget _buildEndHandle(BuildContext context);

    Widget _buildToolbar(BuildContext context);

};

class _SelectionToolbarOverlay : StatefulWidget {
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


    _SelectionToolbarOverlayState createState();

private:

     _SelectionToolbarOverlay(ClipboardStatusNotifier clipboardStatus, Rect editingRegion, LayerLink layerLink, Offset midpoint, double preferredLineHeight, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, List<TextSelectionPoint> selectionEndpoints, Offset toolbarLocation, ValueListenable<bool> visibility);

};

class _SelectionToolbarOverlayState : State<_SelectionToolbarOverlay> {
public:

    void initState();

    void didUpdateWidget(_SelectionToolbarOverlay oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    AnimationController _controller;


    Animation<double> _opacity();

    void _toolbarVisibilityChanged();

};

class _SelectionHandleOverlay : StatefulWidget {
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


    State<_SelectionHandleOverlay> createState();

private:

     _SelectionHandleOverlay(DragStartBehavior dragStartBehavior, LayerLink handleLayerLink, ValueChanged<DragEndDetails> onSelectionHandleDragEnd, ValueChanged<DragStartDetails> onSelectionHandleDragStart, ValueChanged<DragUpdateDetails> onSelectionHandleDragUpdate, VoidCallback onSelectionHandleTapped, double preferredLineHeight, TextSelectionControls selectionControls, TextSelectionHandleType type, ValueListenable<bool> visibility);

};

class _SelectionHandleOverlayState : State<_SelectionHandleOverlay> {
public:

    void initState();

    void didUpdateWidget(_SelectionHandleOverlay oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    AnimationController _controller;


    Animation<double> _opacity();

    void _handleVisibilityChanged();

};

class TextSelectionGestureDetectorBuilderDelegate {
public:

    GlobalKey<EditableTextState> editableTextKey();

    bool forcePressEnabled();

    bool selectionEnabled();

private:

};

class TextSelectionGestureDetectorBuilder {
public:
    TextSelectionGestureDetectorBuilderDelegate delegate;


     TextSelectionGestureDetectorBuilder(TextSelectionGestureDetectorBuilderDelegate delegate);

    bool shouldShowSelectionToolbar();

    EditableTextState editableText();

    RenderEditable renderEditable();

    void onTapDown(TapDownDetails details);

    void onForcePressStart(ForcePressDetails details);

    void onForcePressEnd(ForcePressDetails details);

    void onSingleTapUp(TapUpDetails details);

    void onSingleTapCancel();

    void onSingleLongTapStart(LongPressStartDetails details);

    void onSingleLongTapMoveUpdate(LongPressMoveUpdateDetails details);

    void onSingleLongTapEnd(LongPressEndDetails details);

    void onSecondaryTap();

    void onSecondaryTapDown(TapDownDetails details);

    void onDoubleTapDown(TapDownDetails details);

    void onDragSelectionStart(DragStartDetails details);

    void onDragSelectionUpdate(DragStartDetails startDetails, DragUpdateDetails updateDetails);

    void onDragSelectionEnd(DragEndDetails details);

    Widget buildGestureDetector(HitTestBehavior behavior, Widget child, Key key);

private:
    bool _shouldShowSelectionToolbar;

    double _dragStartViewportOffset;

    bool _isShiftTapping;

    TextSelection _shiftTapDragSelection;


    bool _lastSecondaryTapWasOnSelection();

    void _expandSelection(SelectionChangedCause cause, TextSelection fromSelection, Offset offset);

    void _extendSelection(SelectionChangedCause cause, Offset offset);

    bool _isShiftPressed();

};

class TextSelectionGestureDetector : StatefulWidget {
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


     TextSelectionGestureDetector(HitTestBehavior behavior, Widget child, Unknown, GestureTapDownCallback onDoubleTapDown, GestureDragEndCallback onDragSelectionEnd, GestureDragStartCallback onDragSelectionStart, DragSelectionUpdateCallback onDragSelectionUpdate, GestureForcePressEndCallback onForcePressEnd, GestureForcePressStartCallback onForcePressStart, GestureTapCallback onSecondaryTap, GestureTapDownCallback onSecondaryTapDown, GestureLongPressEndCallback onSingleLongTapEnd, GestureLongPressMoveUpdateCallback onSingleLongTapMoveUpdate, GestureLongPressStartCallback onSingleLongTapStart, GestureTapCancelCallback onSingleTapCancel, GestureTapUpCallback onSingleTapUp, GestureTapDownCallback onTapDown);

    State<StatefulWidget> createState();

private:

};

class _TextSelectionGestureDetectorState : State<TextSelectionGestureDetector> {
public:

    void dispose();

    Widget build(BuildContext context);

private:
    Timer _doubleTapTimer;

    Offset _lastTapOffset;

    bool _isDoubleTap;

    DragStartDetails _lastDragStartDetails;

    DragUpdateDetails _lastDragUpdateDetails;

    Timer _dragUpdateThrottleTimer;


    void _handleTapDown(TapDownDetails details);

    void _handleTapUp(TapUpDetails details);

    void _handleTapCancel();

    void _handleDragStart(DragStartDetails details);

    void _handleDragUpdate(DragUpdateDetails details);

    void _handleDragUpdateThrottled();

    void _handleDragEnd(DragEndDetails details);

    void _forcePressStarted(ForcePressDetails details);

    void _forcePressEnded(ForcePressDetails details);

    void _handleLongPressStart(LongPressStartDetails details);

    void _handleLongPressMoveUpdate(LongPressMoveUpdateDetails details);

    void _handleLongPressEnd(LongPressEndDetails details);

    void _doubleTapTimeout();

    bool _isWithinDoubleTapTolerance(Offset secondTapOffset);

};

class ClipboardStatusNotifier : ValueNotifier<ClipboardStatus> {
public:

     ClipboardStatusNotifier(ClipboardStatus value);

    bool disposed();

    Future<void> update();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void didChangeAppLifecycleState(AppLifecycleState state);

    void dispose();

private:
    bool _disposed;


};

enum ClipboardStatus{
    pasteable,
    unknown,
    notPasteable,
} // end ClipboardStatus

#endif