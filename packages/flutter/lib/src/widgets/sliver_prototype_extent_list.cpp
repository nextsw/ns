#include "sliver_prototype_extent_list.hpp"
SliverPrototypeExtentListCls::SliverPrototypeExtentListCls(SliverChildDelegate delegate, Key key, Widget prototypeItem) {
    {
        assert(prototypeItem != nullptr);
    }
}

RenderSliverMultiBoxAdaptor SliverPrototypeExtentListCls::createRenderObject(BuildContext context) {
    _SliverPrototypeExtentListElement element = as<_SliverPrototypeExtentListElement>(context);
    return make<_RenderSliverPrototypeExtentListCls>(element);
}

SliverMultiBoxAdaptorElement SliverPrototypeExtentListCls::createElement() {
    return make<_SliverPrototypeExtentListElementCls>(this);
}

_RenderSliverPrototypeExtentList _SliverPrototypeExtentListElementCls::renderObject() {
    return as<_RenderSliverPrototypeExtentList>(super->renderObject);
}

void _SliverPrototypeExtentListElementCls::insertRenderObjectChild(RenderObject child, Object slot) {
    if (slot == _prototypeSlot) {
        assert(is<RenderBox>(child));
        renderObject()->child = as<RenderBox>(child);
    } else {
        super->insertRenderObjectChild(child, as<int>(slot));
    }
}

void _SliverPrototypeExtentListElementCls::didAdoptChild(RenderBox child) {
    if (child != renderObject()->child) {
        super->didAdoptChild(child);
    }
}

void _SliverPrototypeExtentListElementCls::moveRenderObjectChild(RenderBox child, Object oldSlot, Object newSlot) {
    if (newSlot == _prototypeSlot) {
        assert(false);
    } else {
        super->moveRenderObjectChild(child, as<int>(oldSlot), as<int>(newSlot));
    }
}

void _SliverPrototypeExtentListElementCls::removeRenderObjectChild(RenderBox child, Object slot) {
    if (renderObject()->child == child) {
        renderObject()->child = nullptr;
    } else {
        super->removeRenderObjectChild(child, as<int>(slot));
    }
}

void _SliverPrototypeExtentListElementCls::visitChildren(ElementVisitor visitor) {
    if (_prototype != nullptr) {
        visitor(_prototype!);
    }
    super->visitChildren(visitor);
}

void _SliverPrototypeExtentListElementCls::mount(Element parent, Object newSlot) {
    super->mount(parent, newSlot);
    _prototype = updateChild(_prototype, (as<SliverPrototypeExtentList>(widget()))->prototypeItem, _prototypeSlot);
}

void _SliverPrototypeExtentListElementCls::update(SliverPrototypeExtentList newWidget) {
    super->update(newWidget);
    assert(widget() == newWidget);
    _prototype = updateChild(_prototype, (as<SliverPrototypeExtentList>(widget()))->prototypeItem, _prototypeSlot);
}

RenderBox _RenderSliverPrototypeExtentListCls::child() {
    return _child;
}

void _RenderSliverPrototypeExtentListCls::child(RenderBox value) {
    if (_child != nullptr) {
        dropChild(_child!);
    }
    _child = value;
    if (_child != nullptr) {
        adoptChild(_child!);
    }
    markNeedsLayout();
}

void _RenderSliverPrototypeExtentListCls::performLayout() {
    child()!->layout(constraints()->asBoxConstraints(), true);
    super->performLayout();
}

void _RenderSliverPrototypeExtentListCls::attach(PipelineOwner owner) {
    super->attach(owner);
    if (_child != nullptr) {
        _child!->attach(owner);
    }
}

void _RenderSliverPrototypeExtentListCls::detach() {
    super->detach();
    if (_child != nullptr) {
        _child!->detach();
    }
}

void _RenderSliverPrototypeExtentListCls::redepthChildren() {
    if (_child != nullptr) {
        redepthChild(_child!);
    }
    super->redepthChildren();
}

void _RenderSliverPrototypeExtentListCls::visitChildren(RenderObjectVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
    super->visitChildren(visitor);
}

double _RenderSliverPrototypeExtentListCls::itemExtent() {
    assert(child() != nullptr && child()!->hasSize());
    return constraints()->axis() == AxisCls::vertical? child()!->size()->height() : child()!->size()->width();
}

_RenderSliverPrototypeExtentListCls::_RenderSliverPrototypeExtentListCls(_SliverPrototypeExtentListElement childManager) : RenderSliverFixedExtentBoxAdaptor(childManager) {
}
