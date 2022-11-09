#include "selection.hpp"
SelectionRegistrar SelectionRegistrantCls::registrar() {
    return _registrar;
}

void SelectionRegistrantCls::registrar(SelectionRegistrar value) {
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

void SelectionRegistrantCls::dispose() {
    _removeSelectionRegistrarSubscription();
    super->dispose();
}

void SelectionRegistrantCls::_updateSelectionRegistrarSubscription() {
    if (_registrar == nullptr) {
        _subscribedToSelectionRegistrar = false;
        return;
    }
    if (_subscribedToSelectionRegistrar && !value->hasContent) {
        _registrar!->remove(this);
        _subscribedToSelectionRegistrar = false;
    } else     {
        if (!_subscribedToSelectionRegistrar && value->hasContent) {
        _registrar!->add(this);
        _subscribedToSelectionRegistrar = true;
    }
;
    }}

void SelectionRegistrantCls::_removeSelectionRegistrarSubscription() {
    if (_subscribedToSelectionRegistrar) {
        _registrar!->remove(this);
        _subscribedToSelectionRegistrar = false;
    }
}

SelectionResult SelectionUtilsCls::getResultBasedOnRect(Offset point, Rect targetRect) {
    if (targetRect->contains(point)) {
        return SelectionResultCls::end;
    }
    if (point->dy < targetRect->top) {
        return SelectionResultCls::previous;
    }
    if (point->dy > targetRect->bottom) {
        return SelectionResultCls::next;
    }
    return point->dx >= targetRect->right? SelectionResultCls::next : SelectionResultCls::previous;
}

Offset SelectionUtilsCls::adjustDragOffset(TextDirection direction, Offset point, Rect targetRect) {
    if (targetRect->contains(point)) {
        return point;
    }
    if (point->dy <= targetRect->top || point->dy <= targetRect->bottom && point->dx <= targetRect->left) {
        return direction == TextDirectionCls::ltr? targetRect->topLeft : targetRect->topRight;
    } else {
        return direction == TextDirectionCls::ltr? targetRect->bottomRight : targetRect->bottomLeft;
    }
}

SelectAllSelectionEventCls::SelectAllSelectionEventCls() {
    {
        super->_(SelectionEventTypeCls::selectAll);
    }
}

ClearSelectionEventCls::ClearSelectionEventCls() {
    {
        super->_(SelectionEventTypeCls::clear);
    }
}

SelectWordSelectionEventCls::SelectWordSelectionEventCls(Offset globalPosition) {
    {
        super->_(SelectionEventTypeCls::selectWord);
    }
}

void SelectionEdgeUpdateEventCls::forStart(Offset globalPosition)

void SelectionEdgeUpdateEventCls::forEnd(Offset globalPosition)

SelectionGeometryCls::SelectionGeometryCls(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status) {
    {
        assert((startSelectionPoint == nullptr && endSelectionPoint == nullptr) || status != SelectionStatusCls::none);
    }
}

bool SelectionGeometryCls::hasSelection() {
    return status != SelectionStatusCls::none;
}

SelectionGeometry SelectionGeometryCls::copyWith(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status) {
    return make<SelectionGeometryCls>(startSelectionPoint ?? this->startSelectionPoint, endSelectionPoint ?? this->endSelectionPoint, status ?? this->status, hasContent ?? this->hasContent);
}

bool SelectionGeometryCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is SelectionGeometry && other->startSelectionPoint == startSelectionPoint && other->endSelectionPoint == endSelectionPoint && other->status == status && other->hasContent == hasContent;
}

int SelectionGeometryCls::hashCode() {
    return ObjectCls->hash(startSelectionPoint, endSelectionPoint, status, hasContent);
}

SelectionPointCls::SelectionPointCls(TextSelectionHandleType handleType, double lineHeight, Offset localPosition) {
    {
        assert(localPosition != nullptr);
        assert(lineHeight != nullptr);
        assert(handleType != nullptr);
    }
}

bool SelectionPointCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is SelectionPoint && other->localPosition == localPosition && other->lineHeight == lineHeight && other->handleType == handleType;
}

int SelectionPointCls::hashCode() {
    return ObjectCls->hash(localPosition, lineHeight, handleType);
}
