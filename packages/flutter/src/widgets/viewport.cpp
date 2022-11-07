#include "viewport.hpp"
Viewport::Viewport(double anchor, AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Key center, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown, ViewportOffset offset, List<Widget> slivers) {
    {
        assert(offset != nullptr);
        assert(slivers != nullptr);
        assert(center == nullptr || slivers.where().length == 1);
        assert(cacheExtentStyle != nullptr);
        assert(cacheExtentStyle != CacheExtentStyle.viewport || cacheExtent != nullptr);
        assert(clipBehavior != nullptr);
        super(slivers);
    }
}

AxisDirection Viewport::getDefaultCrossAxisDirection(AxisDirection axisDirection, BuildContext context) {
    assert(axisDirection != nullptr);
    ;
}

RenderViewport Viewport::createRenderObject(BuildContext context) {
    return RenderViewport(axisDirection, crossAxisDirection ?? Viewport.getDefaultCrossAxisDirection(context, axisDirection), anchor, offset, cacheExtent, cacheExtentStyle, clipBehavior);
}

void Viewport::updateRenderObject(BuildContext context, RenderViewport renderObject) {
    ;
}

MultiChildRenderObjectElement Viewport::createElement() {
    return _ViewportElement(this);
}

void Viewport::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AxisDirection>EnumProperty("axisDirection", axisDirection));
    properties.add(<AxisDirection>EnumProperty("crossAxisDirection", crossAxisDirectionnullptr));
    properties.add(DoubleProperty("anchor", anchor));
    properties.add(<ViewportOffset>DiagnosticsProperty("offset", offset));
    if (center != nullptr) {
        properties.add(<Key>DiagnosticsProperty("center", center));
    } else     {
        if (children.isNotEmpty && children.first.key != nullptr) {
        properties.add(<Key>DiagnosticsProperty("center", children.first.key"implicit"));
    }
;
    }    properties.add(<double>DiagnosticsProperty("cacheExtent", cacheExtent));
    properties.add(<CacheExtentStyle>DiagnosticsProperty("cacheExtentStyle", cacheExtentStyle));
}

RenderViewport _ViewportElement::renderObject() {
    return (;
}

void _ViewportElement::mount(Object newSlot, Element parent) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    super.mount(parent, newSlot);
    _updateCenter();
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _ViewportElement::update(MultiChildRenderObjectWidget newWidget) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    super.update(newWidget);
    _updateCenter();
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _ViewportElement::insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot) {
    super.insertRenderObjectChild(child, slot);
    if (!_doingMountOrUpdate && slot.index == _centerSlotIndex) {
        renderObject.center = (;
    }
}

void _ViewportElement::moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot) {
    super.moveRenderObjectChild(child, oldSlot, newSlot);
    assert(_doingMountOrUpdate);
}

void _ViewportElement::removeRenderObjectChild(RenderObject child, Object slot) {
    super.removeRenderObjectChild(child, slot);
    if (!_doingMountOrUpdate && renderObject.center == child) {
        renderObject.center = nullptr;
    }
}

void _ViewportElement::debugVisitOnstageChildren(ElementVisitor visitor) {
    children.where().forEach(visitor);
}

void _ViewportElement::_updateCenter() {
    Viewport viewport = (;
    if (viewport.center != nullptr) {
        int elementIndex = 0;
        for (Element e : children) {
            if (e.widget.key == viewport.center) {
                renderObject.center = (;
                                break;
            }
            elementIndex++;
        }
        assert( < children.length);
        _centerSlotIndex = elementIndex;
    } else     {
        if (children.isNotEmpty) {
        renderObject.center = (;
        _centerSlotIndex = 0;
    } else {
        renderObject.center = nullptr;
        _centerSlotIndex = nullptr;
    }
;
    }}

ShrinkWrappingViewport::ShrinkWrappingViewport(AxisDirection axisDirection, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown, ViewportOffset offset, List<Widget> slivers) {
    {
        assert(offset != nullptr);
        super(slivers);
    }
}

RenderShrinkWrappingViewport ShrinkWrappingViewport::createRenderObject(BuildContext context) {
    return RenderShrinkWrappingViewport(axisDirection, crossAxisDirection ?? Viewport.getDefaultCrossAxisDirection(context, axisDirection), offset, clipBehavior);
}

void ShrinkWrappingViewport::updateRenderObject(BuildContext context, RenderShrinkWrappingViewport renderObject) {
    ;
}

void ShrinkWrappingViewport::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AxisDirection>EnumProperty("axisDirection", axisDirection));
    properties.add(<AxisDirection>EnumProperty("crossAxisDirection", crossAxisDirectionnullptr));
    properties.add(<ViewportOffset>DiagnosticsProperty("offset", offset));
}
