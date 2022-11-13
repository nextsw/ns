#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SELECTION
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SELECTION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "layer.hpp"
#include "object.hpp"


enum SelectionResult{
    next,
    previous,
    end,
    pending,
    none,
} // end SelectionResult

class SelectionHandlerCls : public ObjectCls {
public:

    virtual void pushHandleLayers(LayerLink startHandle, LayerLink endHandle);
    virtual SelectedContent getSelectedContent();
    virtual SelectionResult dispatchSelectionEvent(SelectionEvent event);
private:

};
using SelectionHandler = std::shared_ptr<SelectionHandlerCls>;

class SelectedContentCls : public ObjectCls {
public:
    String plainText;


     SelectedContentCls(String plainText);
private:

};
using SelectedContent = std::shared_ptr<SelectedContentCls>;

class SelectableCls : public ObjectCls {
public:

    virtual Matrix4 getTransformTo(RenderObject ancestor);
    virtual Size size();
    virtual void dispose();
private:

};
using Selectable = std::shared_ptr<SelectableCls>;

class SelectionRegistrantCls : public ObjectCls {
public:

    virtual SelectionRegistrar registrar();

    virtual void  registrar(SelectionRegistrar value);

    virtual void dispose();

private:
    SelectionRegistrar _registrar;

    bool _subscribedToSelectionRegistrar;


    virtual void _updateSelectionRegistrarSubscription();

    virtual void _removeSelectionRegistrarSubscription();

};
using SelectionRegistrant = std::shared_ptr<SelectionRegistrantCls>;

class SelectionUtilsCls : public ObjectCls {
public:

    static SelectionResult getResultBasedOnRect(Rect targetRect, Offset point);

    static Offset adjustDragOffset(Rect targetRect, Offset point, TextDirection direction);

private:

    virtual void  _();
};
using SelectionUtils = std::shared_ptr<SelectionUtilsCls>;

enum SelectionEventType{
    startEdgeUpdate,
    endEdgeUpdate,
    clear,
    selectAll,
    selectWord,
} // end SelectionEventType

class SelectionEventCls : public ObjectCls {
public:
    SelectionEventType type;


private:

    virtual void  _(Unknown type);
};
using SelectionEvent = std::shared_ptr<SelectionEventCls>;

class SelectAllSelectionEventCls : public SelectionEventCls {
public:

     SelectAllSelectionEventCls();

private:

};
using SelectAllSelectionEvent = std::shared_ptr<SelectAllSelectionEventCls>;

class ClearSelectionEventCls : public SelectionEventCls {
public:

     ClearSelectionEventCls();

private:

};
using ClearSelectionEvent = std::shared_ptr<ClearSelectionEventCls>;

class SelectWordSelectionEventCls : public SelectionEventCls {
public:
    Offset globalPosition;


     SelectWordSelectionEventCls(Offset globalPosition);

private:

};
using SelectWordSelectionEvent = std::shared_ptr<SelectWordSelectionEventCls>;

class SelectionEdgeUpdateEventCls : public SelectionEventCls {
public:
    Offset globalPosition;


    virtual void  forStart(Unknown globalPosition);

    virtual void  forEnd(Unknown globalPosition);

private:

};
using SelectionEdgeUpdateEvent = std::shared_ptr<SelectionEdgeUpdateEventCls>;

class SelectionRegistrarCls : public ObjectCls {
public:

    virtual void add(Selectable selectable);
    virtual void remove(Selectable selectable);
private:

};
using SelectionRegistrar = std::shared_ptr<SelectionRegistrarCls>;

enum SelectionStatus{
    uncollapsed,
    collapsed,
    none,
} // end SelectionStatus

class SelectionGeometryCls : public ObjectCls {
public:
    SelectionPoint startSelectionPoint;

    SelectionPoint endSelectionPoint;

    SelectionStatus status;

    bool hasContent;


     SelectionGeometryCls(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status);

    virtual bool hasSelection();

    virtual SelectionGeometry copyWith(SelectionPoint endSelectionPoint, bool hasContent, SelectionPoint startSelectionPoint, SelectionStatus status);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

};
using SelectionGeometry = std::shared_ptr<SelectionGeometryCls>;

class SelectionPointCls : public ObjectCls {
public:
    Offset localPosition;

    double lineHeight;

    TextSelectionHandleType handleType;


     SelectionPointCls(TextSelectionHandleType handleType, double lineHeight, Offset localPosition);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

};
using SelectionPoint = std::shared_ptr<SelectionPointCls>;

enum TextSelectionHandleType{
    left,
    right,
    collapsed,
} // end TextSelectionHandleType


#endif