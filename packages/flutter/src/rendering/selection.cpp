#include "selection.hpp"
SelectionRegistrar SelectionRegistrant::registrar() {
    return _registrar;
}

void SelectionRegistrant::registrar(SelectionRegistrar value) {
    if (value == _registrar) {
        return;
    }
    if (value == nullptr) {
        removeListener(_updateSelectionRegistrarSubscription);
    } else     {
        if (_registrar == nullptr) {
        addListener(_updateSelectionRegistrarSubscription);
    }
;
    }    _removeSelectionRegistrarSubscription();
    _registrar = value;
    _updateSelectionRegistrarSubscription();
}

void SelectionRegistrant::dispose() {
    _removeSelectionRegistrarSubscription();
    super.dispose();
}

void SelectionRegistrant::_updateSelectionRegistrarSubscription() {
    if (_registrar == nullptr) {
        _subscribedToSelectionRegistrar = false;
        return;
    }
    if (_subscribedToSelectionRegistrar && !value.hasContent) {
        _registrar!.remove(this);
        _subscribedToSelectionRegistrar = false;
    } else     {
        if (!_subscribedToSelectionRegistrar && value.hasContent) {
        _registrar!.add(this);
        _subscribedToSelectionRegistrar = true;
    }
;
    }}

void SelectionRegistrant::_removeSelectionRegistrarSubscription() {
    if (_subscribedToSelectionRegistrar) {
        _registrar!.remove(this);
        _subscribedToSelectionRegistrar = false;
    }
}

SelectionResult SelectionUtils::getResultBasedOnRect(Offset point, Rect targetRect) {
    if (targetRect.contains(point)) {
        return SelectionResult.end;
    }
    if (point.dy < targetRect.top) {
        return SelectionResult.previous;
    }
    if (point.dy > targetRect.bottom) {
        return SelectionResult.next;
    }
    return point.dx >= targetRect.right? SelectionResult.next : SelectionResult.previous;
}

Offset SelectionUtils::adjustDragOffset(TextDirection direction, Offset point, Rect targetRect) {
    if (targetRect.contains(point)) {
        return point;
    }
    if (point.dy <= targetRect.top || point.dy <= targetRect.bottom && point.dx <= targetRect.left) {
        return direction == TextDirection.ltr? targetRect.topLeft : targetRect.topRight;
    } else {
        return direction == TextDirection.ltr? targetRect.bottomRight : targetRect.bottomLeft;
    }
}

SelectAllSelectionEvent::SelectAllSelectionEvent() {
    {
        super._(SelectionEventType.selectAll);
    }
}

ClearSelectionEvent::ClearSelectionEvent() {
    {
        super._(SelectionEventType.clear);
    }
}

SelectWordSelectionEvent::SelectWordSelectionEvent(Offset globalPosition) {
    {
        super._(SelectionEventType.selectWord);
    }
}

void SelectionEdgeUpdateEvent::forStart(Offset globalPosition)

void SelectionEdgeUpdateEvent::forEnd(Offset globalPosition)

SelectionGeometry::SelectionGeometry(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status) {
    {
        assert((startSelectionPoint == nullptr && endSelectionPoint == nullptr) || status != SelectionStatus.none);
    }
}

bool SelectionGeometry::hasSelection() {
    return status != SelectionStatus.none;
}

SelectionGeometry SelectionGeometry::copyWith(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status) {
    return SelectionGeometry(startSelectionPoint ?? this.startSelectionPoint, endSelectionPoint ?? this.endSelectionPoint, status ?? this.status, hasContent ?? this.hasContent);
}

bool SelectionGeometry::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is SelectionGeometry && other.startSelectionPoint == startSelectionPoint && other.endSelectionPoint == endSelectionPoint && other.status == status && other.hasContent == hasContent;
}

int SelectionGeometry::hashCode() {
    return Object.hash(startSelectionPoint, endSelectionPoint, status, hasContent);
}

SelectionPoint::SelectionPoint(TextSelectionHandleType handleType, double lineHeight, Offset localPosition) {
    {
        assert(localPosition != nullptr);
        assert(lineHeight != nullptr);
        assert(handleType != nullptr);
    }
}

bool SelectionPoint::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is SelectionPoint && other.localPosition == localPosition && other.lineHeight == lineHeight && other.handleType == handleType;
}

int SelectionPoint::hashCode() {
    return Object.hash(localPosition, lineHeight, handleType);
}
