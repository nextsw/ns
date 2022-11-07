#include "sliver_prototype_extent_list.hpp"
SliverPrototypeExtentList::SliverPrototypeExtentList(Unknown, Unknown, Widget prototypeItem) {
    {
        assert(prototypeItem != nullptr);
    }
}

RenderSliverMultiBoxAdaptor SliverPrototypeExtentList::createRenderObject(BuildContext context) {
    _SliverPrototypeExtentListElement element = (;
    return _RenderSliverPrototypeExtentList(element);
}

SliverMultiBoxAdaptorElement SliverPrototypeExtentList::createElement() {
    return _SliverPrototypeExtentListElement(this);
}

_RenderSliverPrototypeExtentList _SliverPrototypeExtentListElement::renderObject() {
    return (;
}

void _SliverPrototypeExtentListElement::insertRenderObjectChild(RenderObject child, Object slot) {
    if (slot == _prototypeSlot) {
        assert(child is RenderBox);
        renderObject.child = (;
    } else {
        super.insertRenderObjectChild(child, ();
    }
}

void _SliverPrototypeExtentListElement::didAdoptChild(RenderBox child) {
    if (child != renderObject.child) {
        super.didAdoptChild(child);
    }
}

void _SliverPrototypeExtentListElement::moveRenderObjectChild(RenderBox child, Object newSlot, Object oldSlot) {
    if (newSlot == _prototypeSlot) {
        assert(false);
    } else {
        super.moveRenderObjectChild(child, (, ();
    }
}

void _SliverPrototypeExtentListElement::removeRenderObjectChild(RenderBox child, Object slot) {
    if (renderObject.child == child) {
        renderObject.child = nullptr;
    } else {
        super.removeRenderObjectChild(child, ();
    }
}

void _SliverPrototypeExtentListElement::visitChildren(ElementVisitor visitor) {
    if (_prototype != nullptr) {
        visitor(_prototype!);
    }
    super.visitChildren(visitor);
}

void _SliverPrototypeExtentListElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    _prototype = updateChild(_prototype, (().prototypeItem, _prototypeSlot);
}

void _SliverPrototypeExtentListElement::update(SliverPrototypeExtentList newWidget) {
    super.update(newWidget);
    assert(widget == newWidget);
    _prototype = updateChild(_prototype, (().prototypeItem, _prototypeSlot);
}

RenderBox _RenderSliverPrototypeExtentList::child() {
    return _child;
}

void _RenderSliverPrototypeExtentList::child(RenderBox value) {
    if (_child != nullptr) {
        dropChild(_child!);
    }
    _child = value;
    if (_child != nullptr) {
        adoptChild(_child!);
    }
    markNeedsLayout();
}

void _RenderSliverPrototypeExtentList::performLayout() {
    child!.layout(constraints.asBoxConstraints()true);
    super.performLayout();
}

void _RenderSliverPrototypeExtentList::attach(PipelineOwner owner) {
    super.attach(owner);
    if (_child != nullptr) {
        _child!.attach(owner);
    }
}

void _RenderSliverPrototypeExtentList::detach() {
    super.detach();
    if (_child != nullptr) {
        _child!.detach();
    }
}

void _RenderSliverPrototypeExtentList::redepthChildren() {
    if (_child != nullptr) {
        redepthChild(_child!);
    }
    super.redepthChildren();
}

void _RenderSliverPrototypeExtentList::visitChildren(RenderObjectVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
    super.visitChildren(visitor);
}

double _RenderSliverPrototypeExtentList::itemExtent() {
    assert(child != nullptr && child!.hasSize);
    return constraints.axis == Axis.vertical? child!.size.height : child!.size.width;
}

_RenderSliverPrototypeExtentList::_RenderSliverPrototypeExtentList(_SliverPrototypeExtentListElement childManager) {
    {
        super(childManager);
    }
}
