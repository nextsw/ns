#ifndef SLOTTED_RENDER_OBJECT_WIDGET_H
#define SLOTTED_RENDER_OBJECT_WIDGET_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "framework.hpp"



class SlottedMultiChildRenderObjectWidgetMixin<S> {
public:

    Iterable<S> slots();

    Widget childForSlot(S slot);

    SlottedContainerRenderObjectMixin<S> createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, SlottedContainerRenderObjectMixin<S> renderObject);

    SlottedRenderObjectElement<S> createElement();

private:

};

class SlottedContainerRenderObjectMixin<S> {
public:

    RenderBox childForSlot(S slot);

    Iterable<RenderBox> children();

    String debugNameForSlot(S slot);

    void attach(PipelineOwner owner);

    void detach();

    void redepthChildren();

    void visitChildren(RenderObjectVisitor visitor);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    Map<S, RenderBox> _slotToChild;


    void _addDiagnostics(RenderBox child, String name, List<DiagnosticsNode> value);

    void _setChild(RenderBox child, S slot);

};

class SlottedRenderObjectElement<S> : RenderObjectElement {
public:

     SlottedRenderObjectElement(SlottedMultiChildRenderObjectWidgetMixin<S> widget);

    SlottedContainerRenderObjectMixin<S> renderObject();

    void visitChildren(ElementVisitor visitor);

    void forgetChild(Element child);

    void mount(Object newSlot, Element parent);

    void update(SlottedMultiChildRenderObjectWidgetMixin<S> newWidget);

    void insertRenderObjectChild(RenderBox child, S slot);

    void removeRenderObjectChild(RenderBox child, S slot);

    void moveRenderObjectChild(RenderBox child, Object newSlot, Object oldSlot);

private:
    Map<S, Element> _slotToChild;

    List<S> _debugPreviousSlots;


    void _updateChildren();

    void _updateChild(S slot, Widget widget);

};

#endif