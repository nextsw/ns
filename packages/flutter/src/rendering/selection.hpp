#ifndef SELECTION_H
#define SELECTION_H
#include <memory>

#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "layer.hpp"
#include "object.hpp"



enum SelectionResult{
    next,
    previous,
    end,
    pending,
    none,
} // end SelectionResult

class SelectionHandler {
public:

    void pushHandleLayers(LayerLink endHandle, LayerLink startHandle);

    SelectedContent getSelectedContent();

    SelectionResult dispatchSelectionEvent(SelectionEvent event);

private:

};

class SelectedContent {
public:
    String plainText;


     SelectedContent(String plainText);

private:

};

class Selectable {
public:

    Matrix4 getTransformTo(RenderObject ancestor);

    Size size();

    void dispose();

private:

};

class SelectionRegistrant {
public:

    SelectionRegistrar registrar();

    void  registrar(SelectionRegistrar value);

    void dispose();

private:
    SelectionRegistrar _registrar;

    bool _subscribedToSelectionRegistrar;


    void _updateSelectionRegistrarSubscription();

    void _removeSelectionRegistrarSubscription();

};

class SelectionUtils {
public:

    static SelectionResult getResultBasedOnRect(Offset point, Rect targetRect);

    static Offset adjustDragOffset(TextDirection direction, Offset point, Rect targetRect);

private:

    void  _();

};

enum SelectionEventType{
    startEdgeUpdate,
    endEdgeUpdate,
    clear,
    selectAll,
    selectWord,
} // end SelectionEventType

class SelectionEvent {
public:
    SelectionEventType type;


private:

    void  _(SelectionEventType type);

};

class SelectAllSelectionEvent : SelectionEvent {
public:

     SelectAllSelectionEvent();

private:

};

class ClearSelectionEvent : SelectionEvent {
public:

     ClearSelectionEvent();

private:

};

class SelectWordSelectionEvent : SelectionEvent {
public:
    Offset globalPosition;


     SelectWordSelectionEvent(Offset globalPosition);

private:

};

class SelectionEdgeUpdateEvent : SelectionEvent {
public:
    Offset globalPosition;


    void  forStart(Offset globalPosition);

    void  forEnd(Offset globalPosition);

private:

};

class SelectionRegistrar {
public:

    void add(Selectable selectable);

    void remove(Selectable selectable);

private:

};

enum SelectionStatus{
    uncollapsed,
    collapsed,
    none,
} // end SelectionStatus

class SelectionGeometry {
public:
    SelectionPoint startSelectionPoint;

    SelectionPoint endSelectionPoint;

    SelectionStatus status;

    bool hasContent;


     SelectionGeometry(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status);

    bool hasSelection();

    SelectionGeometry copyWith(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status);

    bool ==(Object other);

    int hashCode();

private:

};

class SelectionPoint {
public:
    Offset localPosition;

    double lineHeight;

    TextSelectionHandleType handleType;


     SelectionPoint(TextSelectionHandleType handleType, double lineHeight, Offset localPosition);

    bool ==(Object other);

    int hashCode();

private:

};

enum TextSelectionHandleType{
    left,
    right,
    collapsed,
} // end TextSelectionHandleType

#endif