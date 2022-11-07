#include "slotted_render_object_widget.hpp"
SlottedRenderObjectElement<S> SlottedMultiChildRenderObjectWidgetMixin::createElement() {
    return <S>SlottedRenderObjectElement(this);
}

RenderBox SlottedContainerRenderObjectMixin::childForSlot(S slot) {
    return _slotToChild[slot];
}

Iterable<RenderBox> SlottedContainerRenderObjectMixin::children() {
    return _slotToChild.values;
}

String SlottedContainerRenderObjectMixin::debugNameForSlot(S slot) {
    if (slot is Enum) {
        return slot.name;
    }
    return slot.toString();
}

void SlottedContainerRenderObjectMixin::attach(PipelineOwner owner) {
    super.attach(owner);
    for (RenderBox child : children) {
        child.attach(owner);
    }
}

void SlottedContainerRenderObjectMixin::detach() {
    super.detach();
    for (RenderBox child : children) {
        child.detach();
    }
}

void SlottedContainerRenderObjectMixin::redepthChildren() {
    children.forEach(redepthChild);
}

void SlottedContainerRenderObjectMixin::visitChildren(RenderObjectVisitor visitor) {
    children.forEach(visitor);
}

List<DiagnosticsNode> SlottedContainerRenderObjectMixin::debugDescribeChildren() {
    List<DiagnosticsNode> value = ;
    Map<RenderBox, S> childToSlot = <RenderBox, S>fromIterables(_slotToChild.values, _slotToChild.keys);
    for (RenderBox child : children) {
        _addDiagnostics(child, value, debugNameForSlot(());
    }
    return value;
}

void SlottedContainerRenderObjectMixin::_addDiagnostics(RenderBox child, String name, List<DiagnosticsNode> value) {
    value.add(child.toDiagnosticsNode(name));
}

void SlottedContainerRenderObjectMixin::_setChild(RenderBox child, S slot) {
    RenderBox oldChild = _slotToChild[slot];
    if (oldChild != nullptr) {
        dropChild(oldChild);
        _slotToChild.remove(slot);
    }
    if (child != nullptr) {
        _slotToChild[slot] = child;
        adoptChild(child);
    }
}

SlottedContainerRenderObjectMixin<S> SlottedRenderObjectElement::renderObject() {
    return (;
}

void SlottedRenderObjectElement::visitChildren(ElementVisitor visitor) {
    _slotToChild.values.forEach(visitor);
}

void SlottedRenderObjectElement::forgetChild(Element child) {
    assert(_slotToChild.containsValue(child));
    assert(child.slot is S);
    assert(_slotToChild.containsKey(child.slot));
    _slotToChild.remove(child.slot);
    super.forgetChild(child);
}

void SlottedRenderObjectElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    _updateChildren();
}

void SlottedRenderObjectElement::update(SlottedMultiChildRenderObjectWidgetMixin<S> newWidget) {
    super.update(newWidget);
    assert(widget == newWidget);
    _updateChildren();
}

void SlottedRenderObjectElement::insertRenderObjectChild(RenderBox child, S slot) {
    renderObject._setChild(child, slot);
    assert(renderObject._slotToChild[slot] == child);
}

void SlottedRenderObjectElement::removeRenderObjectChild(RenderBox child, S slot) {
    assert(renderObject._slotToChild[slot] == child);
    renderObject._setChild(nullptr, slot);
    assert(renderObject._slotToChild[slot] == nullptr);
}

void SlottedRenderObjectElement::moveRenderObjectChild(RenderBox child, Object newSlot, Object oldSlot) {
    assert(false, "not reachable");
}

void SlottedRenderObjectElement::_updateChildren() {
    SlottedMultiChildRenderObjectWidgetMixin<S> slottedMultiChildRenderObjectWidgetMixin = (;
    assert((), "${widget.runtimeType}.slots must not change.");
    assert(slottedMultiChildRenderObjectWidgetMixin.slots.toSet().length == slottedMultiChildRenderObjectWidgetMixin.slots.length, "slots must be unique");
    for (S slot : slottedMultiChildRenderObjectWidgetMixin.slots) {
        _updateChild(slottedMultiChildRenderObjectWidgetMixin.childForSlot(slot), slot);
    }
}

void SlottedRenderObjectElement::_updateChild(S slot, Widget widget) {
    Element oldChild = _slotToChild[slot];
    assert(oldChild == nullptr || oldChild.slot == slot);
    Element newChild = updateChild(oldChild, widget, slot);
    if (oldChild != nullptr) {
        _slotToChild.remove(slot);
    }
    if (newChild != nullptr) {
        _slotToChild[slot] = newChild;
    }
}
