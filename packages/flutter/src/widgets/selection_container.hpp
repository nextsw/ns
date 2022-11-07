#ifndef SELECTION_CONTAINER_H
#define SELECTION_CONTAINER_H
#include <memory>

#include <flutter/rendering.hpp>
#include "framework.hpp"



class SelectionContainer : StatefulWidget {
public:
    SelectionRegistrar registrar;

    Widget child;

    SelectionContainerDelegate delegate;


     SelectionContainer(Widget child, SelectionContainerDelegate delegate, Unknown, SelectionRegistrar registrar);

    void  disabled(Widget child, Unknown);

    static SelectionRegistrar maybeOf(BuildContext context);

    State<SelectionContainer> createState();

private:

    bool _disabled();

};

class _SelectionContainerState : State<SelectionContainer> {
public:

    void initState();

    void didUpdateWidget(SelectionContainer oldWidget);

    void didChangeDependencies();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void pushHandleLayers(LayerLink endHandle, LayerLink startHandle);

    SelectedContent getSelectedContent();

    SelectionResult dispatchSelectionEvent(SelectionEvent event);

    SelectionGeometry value();

    Matrix4 getTransformTo(RenderObject ancestor);

    Size size();

    void dispose();

    Widget build(BuildContext context);

private:
    Set<VoidCallback> _listeners;

    static const SelectionGeometry _disabledGeometry;


};

class SelectionRegistrarScope : InheritedWidget {
public:
    SelectionRegistrar registrar;


     SelectionRegistrarScope(Unknown, Unknown, SelectionRegistrar registrar);

    bool updateShouldNotify(SelectionRegistrarScope oldWidget);

private:

    void  _disabled(Unknown);

};

class SelectionContainerDelegate {
public:

    Matrix4 getTransformFrom(Selectable child);

    Matrix4 getTransformTo(RenderObject ancestor);

    Size containerSize();

private:
    BuildContext _selectionContainerContext;


};

#endif