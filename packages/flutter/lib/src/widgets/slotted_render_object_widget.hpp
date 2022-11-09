#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLOTTED_RENDER_OBJECT_WIDGET
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLOTTED_RENDER_OBJECT_WIDGET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"


template<typename S> class SlottedMultiChildRenderObjectWidgetMixinCls : public ObjectCls {
public:

    virtual Iterable<S> slots();
    virtual Widget childForSlot(S slot);
    virtual SlottedContainerRenderObjectMixin<S> createRenderObject(BuildContext context);
    virtual void updateRenderObject(BuildContext context, SlottedContainerRenderObjectMixin<S> renderObject);
    virtual SlottedRenderObjectElement<S> createElement();

private:

};
template<typename S> using SlottedMultiChildRenderObjectWidgetMixin = std::shared_ptr<SlottedMultiChildRenderObjectWidgetMixinCls<S>>;

template<typename S> class SlottedContainerRenderObjectMixinCls : public ObjectCls {
public:

    virtual RenderBox childForSlot(S slot);

    virtual Iterable<RenderBox> children();

    virtual String debugNameForSlot(S slot);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void redepthChildren();

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    Map<S, RenderBox> _slotToChild;


    virtual void _addDiagnostics(RenderBox child, String name, List<DiagnosticsNode> value);

    virtual void _setChild(RenderBox child, S slot);

};
template<typename S> using SlottedContainerRenderObjectMixin = std::shared_ptr<SlottedContainerRenderObjectMixinCls<S>>;

template<typename S> class SlottedRenderObjectElementCls : public RenderObjectElementCls {
public:

     SlottedRenderObjectElementCls(SlottedMultiChildRenderObjectWidgetMixin<S> widget);
    virtual SlottedContainerRenderObjectMixin<S> renderObject();

    virtual void visitChildren(ElementVisitor visitor);

    virtual void forgetChild(Element child);

    virtual void mount(Object newSlot, Element parent);

    virtual void update(SlottedMultiChildRenderObjectWidgetMixin<S> newWidget);

    virtual void insertRenderObjectChild(RenderBox child, S slot);

    virtual void removeRenderObjectChild(RenderBox child, S slot);

    virtual void moveRenderObjectChild(RenderBox child, Object newSlot, Object oldSlot);

private:
    Map<S, Element> _slotToChild;

    List<S> _debugPreviousSlots;


    virtual void _updateChildren();

    virtual void _updateChild(S slot, Widget widget);

};
template<typename S> using SlottedRenderObjectElement = std::shared_ptr<SlottedRenderObjectElementCls<S>>;


#endif