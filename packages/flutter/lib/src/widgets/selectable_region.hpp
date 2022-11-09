#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SELECTABLE_REGION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SELECTABLE_REGION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
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

Set<PointerDeviceKind> _kLongPressSelectionDevices;


class SelectableRegionCls : public StatefulWidgetCls {
public:
    FocusNode focusNode;

    Widget child;

    TextSelectionControls selectionControls;


     SelectableRegionCls(Widget child, FocusNode focusNode, Unknown key, TextSelectionControls selectionControls);
    virtual State<StatefulWidget> createState();

private:

};
using SelectableRegion = std::shared_ptr<SelectableRegionCls>;

class _SelectableRegionStateCls : public StateCls<SelectableRegion> {
public:
    TextEditingValue textEditingValue;


    virtual void initState();

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(SelectableRegion oldWidget);

    virtual bool cutEnabled();

    virtual bool pasteEnabled();

    virtual void hideToolbar(bool hideHandles);

    virtual void selectAll(SelectionChangedCause cause);

    virtual void copySelection(SelectionChangedCause cause);

    virtual void bringIntoView(TextPosition position);

    virtual void cutSelection(SelectionChangedCause cause);

    virtual void userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value);

    virtual Future<void> pasteText(SelectionChangedCause cause);

    virtual void add(Selectable selectable);

    virtual void remove(Selectable selectable);

    virtual void dispose();

    virtual Widget build(BuildContext context);

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


    virtual bool _hasSelectionOverlayGeometry();

    template<typename T : Intent>  virtual Action<T> _makeOverridable(Action<T> defaultAction);

    virtual void _handleFocusChanged();

    virtual void _updateSelectionStatus();

    virtual void _initMouseGestureRecognizer();

    virtual void _initTouchGestureRecognizer();

    virtual void _startNewMouseSelectionGesture(DragDownDetails details);

    virtual void _handleMouseDragStart(DragStartDetails details);

    virtual void _handleMouseDragUpdate(DragUpdateDetails details);

    virtual void _handleMouseDragEnd(DragEndDetails details);

    virtual void _handleTouchLongPressStart(LongPressStartDetails details);

    virtual void _handleTouchLongPressMoveUpdate(LongPressMoveUpdateDetails details);

    virtual void _handleTouchLongPressEnd(LongPressEndDetails details);

    virtual void _handleRightClickDown(TapDownDetails details);

    virtual bool _userDraggingSelectionEnd();

    virtual void _triggerSelectionEndEdgeUpdate();

    virtual void _stopSelectionEndEdgeUpdate();

    virtual bool _userDraggingSelectionStart();

    virtual void _triggerSelectionStartEdgeUpdate();

    virtual void _stopSelectionStartEdgeUpdate();

    virtual void _handleSelectionStartHandleDragStart(DragStartDetails details);

    virtual void _handleSelectionStartHandleDragUpdate(DragUpdateDetails details);

    virtual void _handleSelectionEndHandleDragStart(DragStartDetails details);

    virtual void _handleSelectionEndHandleDragUpdate(DragUpdateDetails details);

    virtual void _createSelectionOverlay();

    virtual void _updateSelectionOverlay();

    virtual bool _showHandles();

    virtual bool _showToolbar(Offset location);

    virtual void _selectEndTo(bool continuous, Offset offset);

    virtual void _selectStartTo(bool continuous, Offset offset);

    virtual void _selectWordAt(Offset offset);

    virtual void _finalizeSelection();

    virtual void _clearSelection();

    virtual Future<void> _copy();

};
using _SelectableRegionState = std::shared_ptr<_SelectableRegionStateCls>;

template<typename T : Intent> class _NonOverrideActionCls : public ContextActionCls<T> {
public:

    virtual Object invokeAction(BuildContext context, T intent);
    virtual Object invoke(BuildContext context, T intent);

private:

};
template<typename T : Intent> using _NonOverrideAction = std::shared_ptr<_NonOverrideActionCls<T : Intent>>;

class _SelectAllActionCls : public _NonOverrideActionCls<SelectAllTextIntent> {
public:
    _SelectableRegionState state;


    virtual void invokeAction(BuildContext context, SelectAllTextIntent intent);

private:

     _SelectAllActionCls(_SelectableRegionState state);
};
using _SelectAllAction = std::shared_ptr<_SelectAllActionCls>;

class _CopySelectionActionCls : public _NonOverrideActionCls<CopySelectionTextIntent> {
public:
    _SelectableRegionState state;


    virtual void invokeAction(BuildContext context, CopySelectionTextIntent intent);

private:

     _CopySelectionActionCls(_SelectableRegionState state);
};
using _CopySelectionAction = std::shared_ptr<_CopySelectionActionCls>;

class _SelectableRegionContainerDelegateCls : public MultiSelectableSelectionContainerDelegateCls {
public:

    virtual void remove(Selectable selectable);

    virtual SelectionResult handleSelectAll(SelectAllSelectionEvent event);

    virtual SelectionResult handleSelectWord(SelectWordSelectionEvent event);

    virtual SelectionResult handleClearSelection(ClearSelectionEvent event);

    virtual SelectionResult handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event);

    virtual void dispose();

    virtual SelectionResult dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable);

    virtual void ensureChildUpdated(Selectable selectable);

    virtual void didChangeSelectables();

private:
    Set<Selectable> _hasReceivedStartEvent;

    Set<Selectable> _hasReceivedEndEvent;

    Offset _lastStartEdgeUpdateGlobalPosition;

    Offset _lastEndEdgeUpdateGlobalPosition;


    virtual void _updateLastEdgeEventsFromGeometries();

};
using _SelectableRegionContainerDelegate = std::shared_ptr<_SelectableRegionContainerDelegateCls>;

class MultiSelectableSelectionContainerDelegateCls : public SelectionContainerDelegateCls {
public:
    List<Selectable> selectables;

    int currentSelectionEndIndex;

    int currentSelectionStartIndex;


    virtual void add(Selectable selectable);

    virtual void remove(Selectable selectable);

    virtual void layoutDidChange();

    virtual void didChangeSelectables();

    virtual SelectionGeometry value();

    virtual Comparator<Selectable> compareOrder();

    virtual SelectionGeometry getSelectionGeometry();

    virtual void pushHandleLayers(LayerLink endHandle, LayerLink startHandle);

    virtual SelectedContent getSelectedContent();

    virtual SelectionResult handleSelectAll(SelectAllSelectionEvent event);

    virtual SelectionResult handleSelectWord(SelectWordSelectionEvent event);

    virtual SelectionResult handleClearSelection(ClearSelectionEvent event);

    virtual SelectionResult handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event);

    virtual SelectionResult dispatchSelectionEvent(SelectionEvent event);

    virtual void dispose();

    virtual void ensureChildUpdated(Selectable selectable);
    virtual SelectionResult dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable);

private:
    static double _kSelectionHandleDrawableAreaPadding;

    LayerLink _startHandleLayer;

    Selectable _startHandleLayerOwner;

    LayerLink _endHandleLayer;

    Selectable _endHandleLayerOwner;

    bool _isHandlingSelectionEvent;

    bool _scheduledSelectableUpdate;

    bool _selectionInProgress;

    Set<Selectable> _additions;

    SelectionGeometry _selectionGeometry;


    virtual void _scheduleSelectableUpdate();

    virtual void _updateSelectables();

    virtual void _flushAdditions();

    virtual void _removeSelectable(Selectable selectable);

    virtual void _updateSelectionGeometry();

    virtual int _compareScreenOrder(Selectable a, Selectable b);

    static int _compareVertically(Rect a, Rect b);

    static int _compareHorizontally(Rect a, Rect b);

    virtual void _handleSelectableGeometryChange();

    virtual int _adjustSelectionIndexBasedOnSelectionGeometry(int currentIndex, int towardIndex);

    virtual void _updateHandleLayersAndOwners();

    virtual SelectionResult _initSelection(SelectionEdgeUpdateEvent event, bool isEnd);

    virtual SelectionResult _adjustSelection(SelectionEdgeUpdateEvent event, bool isEnd);

};
using MultiSelectableSelectionContainerDelegate = std::shared_ptr<MultiSelectableSelectionContainerDelegateCls>;


#endif