#ifndef SELECTABLE_REGION_H
#define SELECTABLE_REGION_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "media_query.hpp"
#include "overlay.hpp"
#include "selection_container.hpp"
#include "text_editing_intents.hpp"
#include "text_selection.hpp"


const Set<PointerDeviceKind> _kLongPressSelectionDevices;


class SelectableRegion : StatefulWidget {
public:
    FocusNode focusNode;

    Widget child;

    TextSelectionControls selectionControls;


     SelectableRegion(Widget child, FocusNode focusNode, Unknown, TextSelectionControls selectionControls);

    State<StatefulWidget> createState();

private:

};

class _SelectableRegionState : State<SelectableRegion> {
public:
    TextEditingValue textEditingValue;


    void initState();

    void didChangeDependencies();

    void didUpdateWidget(SelectableRegion oldWidget);

    bool cutEnabled();

    bool pasteEnabled();

    void hideToolbar(bool hideHandles);

    void selectAll(SelectionChangedCause cause);

    void copySelection(SelectionChangedCause cause);

    void bringIntoView(TextPosition position);

    void cutSelection(SelectionChangedCause cause);

    void userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value);

    Future<void> pasteText(SelectionChangedCause cause);

    void add(Selectable selectable);

    void remove(Selectable selectable);

    void dispose();

    Widget build(BuildContext context);

private:
    Map<Type, Action<Intent>> _actions;

    Map<Type, GestureRecognizerFactory> _gestureRecognizers;

    SelectionOverlay _selectionOverlay;

    LayerLink _startHandleLayerLink;

    LayerLink _endHandleLayerLink;

    LayerLink _toolbarLayerLink;

    _SelectableRegionContainerDelegate _selectionDelegate;

    Selectable _selectable;

    Orientation _lastOrientation;

    Offset _selectionEndPosition;

    bool _scheduledSelectionEndEdgeUpdate;

    Offset _selectionStartPosition;

    bool _scheduledSelectionStartEdgeUpdate;

    Offset _selectionStartHandleDragPosition;

    Offset _selectionEndHandleDragPosition;


    bool _hasSelectionOverlayGeometry();

    Action<T> _makeOverridable<T extends Intent>(Action<T> defaultAction);

    void _handleFocusChanged();

    void _updateSelectionStatus();

    void _initMouseGestureRecognizer();

    void _initTouchGestureRecognizer();

    void _startNewMouseSelectionGesture(DragDownDetails details);

    void _handleMouseDragStart(DragStartDetails details);

    void _handleMouseDragUpdate(DragUpdateDetails details);

    void _handleMouseDragEnd(DragEndDetails details);

    void _handleTouchLongPressStart(LongPressStartDetails details);

    void _handleTouchLongPressMoveUpdate(LongPressMoveUpdateDetails details);

    void _handleTouchLongPressEnd(LongPressEndDetails details);

    void _handleRightClickDown(TapDownDetails details);

    bool _userDraggingSelectionEnd();

    void _triggerSelectionEndEdgeUpdate();

    void _stopSelectionEndEdgeUpdate();

    bool _userDraggingSelectionStart();

    void _triggerSelectionStartEdgeUpdate();

    void _stopSelectionStartEdgeUpdate();

    void _handleSelectionStartHandleDragStart(DragStartDetails details);

    void _handleSelectionStartHandleDragUpdate(DragUpdateDetails details);

    void _handleSelectionEndHandleDragStart(DragStartDetails details);

    void _handleSelectionEndHandleDragUpdate(DragUpdateDetails details);

    void _createSelectionOverlay();

    void _updateSelectionOverlay();

    bool _showHandles();

    bool _showToolbar(Offset location);

    void _selectEndTo(bool continuous, Offset offset);

    void _selectStartTo(bool continuous, Offset offset);

    void _selectWordAt(Offset offset);

    void _finalizeSelection();

    void _clearSelection();

    Future<void> _copy();

};

class _NonOverrideAction<T extends Intent> : ContextAction<T> {
public:

    Object invokeAction(BuildContext context, T intent);

    Object invoke(BuildContext context, T intent);

private:

};

class _SelectAllAction : _NonOverrideAction<SelectAllTextIntent> {
public:
    _SelectableRegionState state;


    void invokeAction(BuildContext context, SelectAllTextIntent intent);

private:

     _SelectAllAction(_SelectableRegionState state);

};

class _CopySelectionAction : _NonOverrideAction<CopySelectionTextIntent> {
public:
    _SelectableRegionState state;


    void invokeAction(BuildContext context, CopySelectionTextIntent intent);

private:

     _CopySelectionAction(_SelectableRegionState state);

};

class _SelectableRegionContainerDelegate : MultiSelectableSelectionContainerDelegate {
public:

    void remove(Selectable selectable);

    SelectionResult handleSelectAll(SelectAllSelectionEvent event);

    SelectionResult handleSelectWord(SelectWordSelectionEvent event);

    SelectionResult handleClearSelection(ClearSelectionEvent event);

    SelectionResult handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event);

    void dispose();

    SelectionResult dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable);

    void ensureChildUpdated(Selectable selectable);

    void didChangeSelectables();

private:
    Set<Selectable> _hasReceivedStartEvent;

    Set<Selectable> _hasReceivedEndEvent;

    Offset _lastStartEdgeUpdateGlobalPosition;

    Offset _lastEndEdgeUpdateGlobalPosition;


    void _updateLastEdgeEventsFromGeometries();

};

class MultiSelectableSelectionContainerDelegate : SelectionContainerDelegate {
public:
    List<Selectable> selectables;

    int currentSelectionEndIndex;

    int currentSelectionStartIndex;


    void add(Selectable selectable);

    void remove(Selectable selectable);

    void layoutDidChange();

    void didChangeSelectables();

    SelectionGeometry value();

    Comparator<Selectable> compareOrder();

    SelectionGeometry getSelectionGeometry();

    void pushHandleLayers(LayerLink endHandle, LayerLink startHandle);

    SelectedContent getSelectedContent();

    SelectionResult handleSelectAll(SelectAllSelectionEvent event);

    SelectionResult handleSelectWord(SelectWordSelectionEvent event);

    SelectionResult handleClearSelection(ClearSelectionEvent event);

    SelectionResult handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event);

    SelectionResult dispatchSelectionEvent(SelectionEvent event);

    void dispose();

    void ensureChildUpdated(Selectable selectable);

    SelectionResult dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable);

private:
    static const double _kSelectionHandleDrawableAreaPadding;

    LayerLink _startHandleLayer;

    Selectable _startHandleLayerOwner;

    LayerLink _endHandleLayer;

    Selectable _endHandleLayerOwner;

    bool _isHandlingSelectionEvent;

    bool _scheduledSelectableUpdate;

    bool _selectionInProgress;

    Set<Selectable> _additions;

    SelectionGeometry _selectionGeometry;


    void _scheduleSelectableUpdate();

    void _updateSelectables();

    void _flushAdditions();

    void _removeSelectable(Selectable selectable);

    void _updateSelectionGeometry();

    int _compareScreenOrder(Selectable a, Selectable b);

    static int _compareVertically(Rect a, Rect b);

    static int _compareHorizontally(Rect a, Rect b);

    void _handleSelectableGeometryChange();

    int _adjustSelectionIndexBasedOnSelectionGeometry(int currentIndex, int towardIndex);

    void _updateHandleLayersAndOwners();

    SelectionResult _initSelection(SelectionEdgeUpdateEvent event, bool isEnd);

    SelectionResult _adjustSelection(SelectionEdgeUpdateEvent event, bool isEnd);

};

#endif