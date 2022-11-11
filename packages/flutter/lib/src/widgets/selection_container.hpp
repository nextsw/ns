#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SELECTION_CONTAINER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SELECTION_CONTAINER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"


class SelectionContainerCls : public StatefulWidgetCls {
public:
    SelectionRegistrar registrar;

    Widget child;

    SelectionContainerDelegate delegate;


     SelectionContainerCls(Widget child, SelectionContainerDelegate delegate, Key key, SelectionRegistrar registrar);

    virtual void  disabled(Widget child, Key key);

    static SelectionRegistrar maybeOf(BuildContext context);

    virtual State<SelectionContainer> createState();

private:

    virtual bool _disabled();

};
using SelectionContainer = std::shared_ptr<SelectionContainerCls>;

class _SelectionContainerStateCls : public StateCls<SelectionContainer> {
public:

    virtual void initState();

    virtual void didUpdateWidget(SelectionContainer oldWidget);

    virtual void didChangeDependencies();

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void pushHandleLayers(LayerLink startHandle, LayerLink endHandle);

    virtual SelectedContent getSelectedContent();

    virtual SelectionResult dispatchSelectionEvent(SelectionEvent event);

    virtual SelectionGeometry value();

    virtual Matrix4 getTransformTo(RenderObject ancestor);

    virtual Size size();

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    Set<VoidCallback> _listeners;

    static SelectionGeometry _disabledGeometry;


};
using _SelectionContainerState = std::shared_ptr<_SelectionContainerStateCls>;

class SelectionRegistrarScopeCls : public InheritedWidgetCls {
public:
    SelectionRegistrar registrar;


     SelectionRegistrarScopeCls(Widget child, Key key, SelectionRegistrar registrar);

    virtual bool updateShouldNotify(SelectionRegistrarScope oldWidget);

private:

    virtual void  _disabled(Widget child);

};
using SelectionRegistrarScope = std::shared_ptr<SelectionRegistrarScopeCls>;

class SelectionContainerDelegateCls : public ObjectCls {
public:

    virtual Matrix4 getTransformFrom(Selectable child);

    virtual Matrix4 getTransformTo(RenderObject ancestor);

    virtual Size containerSize();

private:
    BuildContext _selectionContainerContext;


};
using SelectionContainerDelegate = std::shared_ptr<SelectionContainerDelegateCls>;


#endif