#include "viewport.hpp"
ViewportCls::ViewportCls(double anchor, AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Key center, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown key, ViewportOffset offset, List<Widget> slivers) {
    {
        assert(offset != nullptr);
        assert(slivers != nullptr);
        assert(center == nullptr || slivers->where([=] (Widget child)         {
            child->key == center;
        })->length == 1);
        assert(cacheExtentStyle != nullptr);
        assert(cacheExtentStyle != CacheExtentStyleCls::viewport || cacheExtent != nullptr);
        assert(clipBehavior != nullptr);
    }
}

AxisDirection ViewportCls::getDefaultCrossAxisDirection(AxisDirection axisDirection, BuildContext context) {
    assert(axisDirection != nullptr);
    ;
}

RenderViewport ViewportCls::createRenderObject(BuildContext context) {
    return make<RenderViewportCls>(axisDirection, crossAxisDirection ?? ViewportCls->getDefaultCrossAxisDirection(context, axisDirection), anchor, offset, cacheExtent, cacheExtentStyle, clipBehavior);
}

void ViewportCls::updateRenderObject(BuildContext context, RenderViewport renderObject) {
    auto _c1 = renderObject;_c1.axisDirection = auto _c2 = axisDirection;_c2.crossAxisDirection = auto _c3 = crossAxisDirection ?? ViewportCls->getDefaultCrossAxisDirection(context, axisDirection);_c3.anchor = auto _c4 = anchor;_c4.offset = auto _c5 = offset;_c5.cacheExtent = auto _c6 = cacheExtent;_c6.cacheExtentStyle = auto _c7 = cacheExtentStyle;_c7.clipBehavior = clipBehavior;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

MultiChildRenderObjectElement ViewportCls::createElement() {
    return make<_ViewportElementCls>(this);
}

void ViewportCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AxisDirection>make<EnumPropertyCls>("axisDirection", axisDirection));
    properties->add(<AxisDirection>make<EnumPropertyCls>("crossAxisDirection", crossAxisDirectionnullptr));
    properties->add(make<DoublePropertyCls>("anchor", anchor));
    properties->add(<ViewportOffset>make<DiagnosticsPropertyCls>("offset", offset));
    if (center != nullptr) {
        properties->add(<Key>make<DiagnosticsPropertyCls>("center", center));
    } else     {
        if (children->isNotEmpty && children->first->key != nullptr) {
        properties->add(<Key>make<DiagnosticsPropertyCls>("center", children->first->key"implicit"));
    }
;
    }    properties->add(<double>make<DiagnosticsPropertyCls>("cacheExtent", cacheExtent));
    properties->add(<CacheExtentStyle>make<DiagnosticsPropertyCls>("cacheExtentStyle", cacheExtentStyle));
}

RenderViewport _ViewportElementCls::renderObject() {
    return ((RenderViewport)super->renderObject);
}

void _ViewportElementCls::mount(Object newSlot, Element parent) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    super->mount(parent, newSlot);
    _updateCenter();
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _ViewportElementCls::update(MultiChildRenderObjectWidget newWidget) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    super->update(newWidget);
    _updateCenter();
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _ViewportElementCls::insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot) {
    super->insertRenderObjectChild(child, slot);
    if (!_doingMountOrUpdate && slot->index == _centerSlotIndex) {
        renderObject->center = ((RenderSliver)child);
    }
}

void _ViewportElementCls::moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot) {
    super->moveRenderObjectChild(child, oldSlot, newSlot);
    assert(_doingMountOrUpdate);
}

void _ViewportElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    super->removeRenderObjectChild(child, slot);
    if (!_doingMountOrUpdate && renderObject->center == child) {
        renderObject->center = nullptr;
    }
}

void _ViewportElementCls::debugVisitOnstageChildren(ElementVisitor visitor) {
    children->where([=] (Element e) {
        RenderSliver renderSliver = ((RenderSliver)e->renderObject!);
        return renderSliver->geometry!->visible;
    })->forEach(visitor);
}

void _ViewportElementCls::_updateCenter() {
    Viewport viewport = ((Viewport)widget);
    if (viewport->center != nullptr) {
        int elementIndex = 0;
        for (Element e : children) {
            if (e->widget->key == viewport->center) {
                renderObject->center = ((RenderSliver)e->renderObject);
                                break;
            }
            elementIndex++;
        }
        assert( < children->length);
        _centerSlotIndex = elementIndex;
    } else     {
        if (children->isNotEmpty) {
        renderObject->center = ((RenderSliver)children->first->renderObject);
        _centerSlotIndex = 0;
    } else {
        renderObject->center = nullptr;
        _centerSlotIndex = nullptr;
    }
;
    }}

ShrinkWrappingViewportCls::ShrinkWrappingViewportCls(AxisDirection axisDirection, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown key, ViewportOffset offset, List<Widget> slivers) {
    {
        assert(offset != nullptr);
    }
}

RenderShrinkWrappingViewport ShrinkWrappingViewportCls::createRenderObject(BuildContext context) {
    return make<RenderShrinkWrappingViewportCls>(axisDirection, crossAxisDirection ?? ViewportCls->getDefaultCrossAxisDirection(context, axisDirection), offset, clipBehavior);
}

void ShrinkWrappingViewportCls::updateRenderObject(BuildContext context, RenderShrinkWrappingViewport renderObject) {
    auto _c1 = renderObject;_c1.axisDirection = auto _c2 = axisDirection;_c2.crossAxisDirection = auto _c3 = crossAxisDirection ?? ViewportCls->getDefaultCrossAxisDirection(context, axisDirection);_c3.offset = auto _c4 = offset;_c4.clipBehavior = clipBehavior;_c4;_c3;_c2;_c1;
}

void ShrinkWrappingViewportCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AxisDirection>make<EnumPropertyCls>("axisDirection", axisDirection));
    properties->add(<AxisDirection>make<EnumPropertyCls>("crossAxisDirection", crossAxisDirectionnullptr));
    properties->add(<ViewportOffset>make<DiagnosticsPropertyCls>("offset", offset));
}
