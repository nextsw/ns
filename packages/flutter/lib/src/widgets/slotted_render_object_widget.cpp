#include "slotted_render_object_widget.hpp"
template<typename S>
SlottedRenderObjectElement<S> SlottedMultiChildRenderObjectWidgetMixinCls<S>::createElement() {
    return <S>make<SlottedRenderObjectElementCls>(this);
}

template<typename S>
RenderBox SlottedContainerRenderObjectMixinCls<S>::childForSlot(S slot) {
    return _slotToChild[slot];
}

template<typename S>
Iterable<RenderBox> SlottedContainerRenderObjectMixinCls<S>::children() {
    return _slotToChild->values();
}

template<typename S>
String SlottedContainerRenderObjectMixinCls<S>::debugNameForSlot(S slot) {
    if (is<Enum>(slot)) {
        return as<EnumCls>(slot)->name;
    }
    return slot->toString();
}

template<typename S>
void SlottedContainerRenderObjectMixinCls<S>::attach(PipelineOwner owner) {
    super->attach(owner);
    for (RenderBox child : children()) {
        child->attach(owner);
    }
}

template<typename S>
void SlottedContainerRenderObjectMixinCls<S>::detach() {
    super->detach();
    for (RenderBox child : children()) {
        child->detach();
    }
}

template<typename S>
void SlottedContainerRenderObjectMixinCls<S>::redepthChildren() {
    children()->forEach(redepthChild);
}

template<typename S>
void SlottedContainerRenderObjectMixinCls<S>::visitChildren(RenderObjectVisitor visitor) {
    children()->forEach(visitor);
}

template<typename S>
List<DiagnosticsNode> SlottedContainerRenderObjectMixinCls<S>::debugDescribeChildren() {
    List<DiagnosticsNode> value = makeList();
    Map<RenderBox, S> childToSlot = <RenderBox, S>fromIterables(_slotToChild->values(), _slotToChild->keys());
    for (RenderBox child : children()) {
        _addDiagnostics(child, value, debugNameForSlot(as<S>(childToSlot[child])));
    }
    return value;
}

template<typename S>
void SlottedContainerRenderObjectMixinCls<S>::_addDiagnostics(RenderBox child, List<DiagnosticsNode> value, String name) {
    value->add(child->toDiagnosticsNode(name));
}

template<typename S>
void SlottedContainerRenderObjectMixinCls<S>::_setChild(RenderBox child, S slot) {
    RenderBox oldChild = _slotToChild[slot];
    if (oldChild != nullptr) {
        dropChild(oldChild);
        _slotToChild->remove(slot);
    }
    if (child != nullptr) {
        _slotToChild[slot] = child;
        adoptChild(child);
    }
}

template<typename S>
SlottedContainerRenderObjectMixin<S> SlottedRenderObjectElementCls<S>::renderObject() {
    return as<SlottedContainerRenderObjectMixin<S>>(super->renderObject);
}

template<typename S>
void SlottedRenderObjectElementCls<S>::visitChildren(ElementVisitor visitor) {
    _slotToChild->values()->forEach(visitor);
}

template<typename S>
void SlottedRenderObjectElementCls<S>::forgetChild(Element child) {
    assert(_slotToChild->containsValue(child));
    assert(is<S>(child->slot()));
    assert(_slotToChild->containsKey(child->slot()));
    _slotToChild->remove(child->slot());
    super->forgetChild(child);
}

template<typename S>
void SlottedRenderObjectElementCls<S>::mount(Element parent, Object newSlot) {
    super->mount(parent, newSlot);
    _updateChildren();
}

template<typename S>
void SlottedRenderObjectElementCls<S>::update(SlottedMultiChildRenderObjectWidgetMixin<S> newWidget) {
    super->update(newWidget);
    assert(widget() == newWidget);
    _updateChildren();
}

template<typename S>
void SlottedRenderObjectElementCls<S>::insertRenderObjectChild(RenderBox child, S slot) {
    renderObject()->_setChild(child, slot);
    assert(renderObject()->_slotToChild[slot] == child);
}

template<typename S>
void SlottedRenderObjectElementCls<S>::removeRenderObjectChild(RenderBox child, S slot) {
    assert(renderObject()->_slotToChild[slot] == child);
    renderObject()->_setChild(nullptr, slot);
    assert(renderObject()->_slotToChild[slot] == nullptr);
}

template<typename S>
void SlottedRenderObjectElementCls<S>::moveRenderObjectChild(RenderBox child, Object oldSlot, Object newSlot) {
    assert(false, __s("not reachable"));
}

template<typename S>
void SlottedRenderObjectElementCls<S>::_updateChildren() {
    SlottedMultiChildRenderObjectWidgetMixin<S> slottedMultiChildRenderObjectWidgetMixin = as<SlottedMultiChildRenderObjectWidgetMixin<S>>(widget());
    assert([=] () {
        _debugPreviousSlots |= slottedMultiChildRenderObjectWidgetMixin->slots()->toList();
        return listEquals(_debugPreviousSlots, slottedMultiChildRenderObjectWidgetMixin->slots()->toList());
    }(), __sf("%s.slots must not change.", widget()->runtimeType));
    assert(slottedMultiChildRenderObjectWidgetMixin->slots()->toSet()->length() == slottedMultiChildRenderObjectWidgetMixin->slots()->length(), __s("slots must be unique"));
    for (S slot : slottedMultiChildRenderObjectWidgetMixin->slots()) {
        _updateChild(slottedMultiChildRenderObjectWidgetMixin->childForSlot(slot()), slot());
    }
}

template<typename S>
void SlottedRenderObjectElementCls<S>::_updateChild(Widget widget, S slot) {
    Element oldChild = _slotToChild[slot];
    assert(oldChild == nullptr || oldChild->slot == slot);
    Element newChild = updateChild(oldChild, widget, slot);
    if (oldChild != nullptr) {
        _slotToChild->remove(slot);
    }
    if (newChild != nullptr) {
        _slotToChild[slot] = newChild;
    }
}
