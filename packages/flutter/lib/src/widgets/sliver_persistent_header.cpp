#include "sliver_persistent_header.hpp"
TickerProvider SliverPersistentHeaderDelegateCls::vsync() {
    return nullptr;
}

FloatingHeaderSnapConfiguration SliverPersistentHeaderDelegateCls::snapConfiguration() {
    return nullptr;
}

OverScrollHeaderStretchConfiguration SliverPersistentHeaderDelegateCls::stretchConfiguration() {
    return nullptr;
}

PersistentHeaderShowOnScreenConfiguration SliverPersistentHeaderDelegateCls::showOnScreenConfiguration() {
    return nullptr;
}

SliverPersistentHeaderCls::SliverPersistentHeaderCls(SliverPersistentHeaderDelegate delegate, bool floating, Unknown key, bool pinned) {
    {
        assert(delegate != nullptr);
        assert(pinned != nullptr);
        assert(floating != nullptr);
    }
}

Widget SliverPersistentHeaderCls::build(BuildContext context) {
    if (floating && pinned) {
        return make<_SliverFloatingPinnedPersistentHeaderCls>(delegate);
    }
    if (pinned) {
        return make<_SliverPinnedPersistentHeaderCls>(delegate);
    }
    if (floating) {
        return make<_SliverFloatingPersistentHeaderCls>(delegate);
    }
    return make<_SliverScrollingPersistentHeaderCls>(delegate);
}

void SliverPersistentHeaderCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverPersistentHeaderDelegate>make<DiagnosticsPropertyCls>(__s("delegate"), delegate));
    List<String> list1 = make<ListCls<>>();if (pinned) {    list1.add(ArrayItem);}if (floating) {    list1.add(ArrayItem);}List<String> flags = list1;
    if (flags->isEmpty) {
        flags->add(__s("normal"));
    }
    properties->add(<String>make<IterablePropertyCls>(__s("mode"), flags));
}

_FloatingHeaderState _FloatingHeaderCls::createState() {
    return make<_FloatingHeaderStateCls>();
}

void _FloatingHeaderStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    if (_position != nullptr) {
        _position!->isScrollingNotifier->removeListener(_isScrollingListener);
    }
    _position = ScrollableCls->of(context)?->position;
    if (_position != nullptr) {
        _position!->isScrollingNotifier->addListener(_isScrollingListener);
    }
}

void _FloatingHeaderStateCls::dispose() {
    if (_position != nullptr) {
        _position!->isScrollingNotifier->removeListener(_isScrollingListener);
    }
    super->dispose();
}

Widget _FloatingHeaderStateCls::build(BuildContext context) {
    return widget->child;
}

RenderSliverFloatingPersistentHeader _FloatingHeaderStateCls::_headerRenderer() {
    return context-><RenderSliverFloatingPersistentHeader>findAncestorRenderObjectOfType();
}

void _FloatingHeaderStateCls::_isScrollingListener() {
    assert(_position != nullptr);
    RenderSliverFloatingPersistentHeader header = _headerRenderer();
    if (_position!->isScrollingNotifier->value()) {
        header?->updateScrollStartDirection(_position!->userScrollDirection);
        header?->maybeStopSnapAnimation(_position!->userScrollDirection);
    } else {
        header?->maybeStartSnapAnimation(_position!->userScrollDirection);
    }
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverPersistentHeaderElementCls::renderObject() {
    return as<_RenderSliverPersistentHeaderForWidgetsMixin>(super->renderObject);
}

void _SliverPersistentHeaderElementCls::mount(Object newSlot, Element parent) {
    super->mount(parent, newSlot);
    renderObject()->_element = this;
}

void _SliverPersistentHeaderElementCls::unmount() {
    renderObject()->_element = nullptr;
    super->unmount();
}

void _SliverPersistentHeaderElementCls::update(_SliverPersistentHeaderRenderObjectWidget newWidget) {
    _SliverPersistentHeaderRenderObjectWidget oldWidget = as<_SliverPersistentHeaderRenderObjectWidget>(widget);
    super->update(newWidget);
    SliverPersistentHeaderDelegate newDelegate = newWidget->delegate;
    SliverPersistentHeaderDelegate oldDelegate = oldWidget->delegate;
    if (newDelegate != oldDelegate && (newDelegate->runtimeType != oldDelegate->runtimeType || newDelegate->shouldRebuild(oldDelegate))) {
        renderObject()->triggerRebuild();
    }
}

void _SliverPersistentHeaderElementCls::performRebuild() {
    super->performRebuild();
    renderObject()->triggerRebuild();
}

void _SliverPersistentHeaderElementCls::forgetChild(Element child) {
    assert(child == this->child);
    this->child = nullptr;
    super->forgetChild(child);
}

void _SliverPersistentHeaderElementCls::insertRenderObjectChild(RenderBox child, Object slot) {
    assert(renderObject()->debugValidateChild(child));
    renderObject()->child = child;
}

void _SliverPersistentHeaderElementCls::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void _SliverPersistentHeaderElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    renderObject()->child = nullptr;
}

void _SliverPersistentHeaderElementCls::visitChildren(ElementVisitor visitor) {
    if (child != nullptr) {
        visitor(child!);
    }
}

_SliverPersistentHeaderElementCls::_SliverPersistentHeaderElementCls(bool floating, _SliverPersistentHeaderRenderObjectWidget widget) {
    {
        assert(floating != nullptr);
    }
}

void _SliverPersistentHeaderElementCls::_build(bool overlapsContent, double shrinkOffset) {
    owner!->buildScope(this, [=] () {
        _SliverPersistentHeaderRenderObjectWidget sliverPersistentHeaderRenderObjectWidget = as<_SliverPersistentHeaderRenderObjectWidget>(widget);
        child = updateChild(child, floating? make<_FloatingHeaderCls>(sliverPersistentHeaderRenderObjectWidget->delegate->build(this, shrinkOffset, overlapsContent)) : sliverPersistentHeaderRenderObjectWidget->delegate->build(this, shrinkOffset, overlapsContent), nullptr);
    });
}

_SliverPersistentHeaderElement _SliverPersistentHeaderRenderObjectWidgetCls::createElement() {
    return make<_SliverPersistentHeaderElementCls>(thisfloating);
}

void _SliverPersistentHeaderRenderObjectWidgetCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<SliverPersistentHeaderDelegate>make<DiagnosticsPropertyCls>(__s("delegate"), delegate));
}

_SliverPersistentHeaderRenderObjectWidgetCls::_SliverPersistentHeaderRenderObjectWidgetCls(SliverPersistentHeaderDelegate delegate, bool floating) {
    {
        assert(delegate != nullptr);
        assert(floating != nullptr);
    }
}

double _RenderSliverPersistentHeaderForWidgetsMixinCls::minExtent() {
    return (as<_SliverPersistentHeaderRenderObjectWidget>(_element!->widget))->delegate->minExtent();
}

double _RenderSliverPersistentHeaderForWidgetsMixinCls::maxExtent() {
    return (as<_SliverPersistentHeaderRenderObjectWidget>(_element!->widget))->delegate->maxExtent();
}

void _RenderSliverPersistentHeaderForWidgetsMixinCls::updateChild(bool overlapsContent, double shrinkOffset) {
    assert(_element != nullptr);
    _element!->_build(shrinkOffset, overlapsContent);
}

void _RenderSliverPersistentHeaderForWidgetsMixinCls::triggerRebuild() {
    markNeedsLayout();
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverScrollingPersistentHeaderCls::createRenderObject(BuildContext context) {
    return make<_RenderSliverScrollingPersistentHeaderForWidgetsCls>(delegate->stretchConfiguration);
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverPinnedPersistentHeaderCls::createRenderObject(BuildContext context) {
    return make<_RenderSliverPinnedPersistentHeaderForWidgetsCls>(delegate->stretchConfiguration, delegate->showOnScreenConfiguration);
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverFloatingPersistentHeaderCls::createRenderObject(BuildContext context) {
    return make<_RenderSliverFloatingPersistentHeaderForWidgetsCls>(delegate->vsync, delegate->snapConfiguration, delegate->stretchConfiguration, delegate->showOnScreenConfiguration);
}

void _SliverFloatingPersistentHeaderCls::updateRenderObject(BuildContext context, _RenderSliverFloatingPersistentHeaderForWidgets renderObject) {
    renderObject->vsync = delegate->vsync;
    renderObject->snapConfiguration = delegate->snapConfiguration;
    renderObject->stretchConfiguration = delegate->stretchConfiguration;
    renderObject->showOnScreenConfiguration = delegate->showOnScreenConfiguration;
}

_SliverFloatingPersistentHeaderCls::_SliverFloatingPersistentHeaderCls(Unknown delegate) {
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverFloatingPinnedPersistentHeaderCls::createRenderObject(BuildContext context) {
    return make<_RenderSliverFloatingPinnedPersistentHeaderForWidgetsCls>(delegate->vsync, delegate->snapConfiguration, delegate->stretchConfiguration, delegate->showOnScreenConfiguration);
}

void _SliverFloatingPinnedPersistentHeaderCls::updateRenderObject(BuildContext context, _RenderSliverFloatingPinnedPersistentHeaderForWidgets renderObject) {
    renderObject->vsync = delegate->vsync;
    renderObject->snapConfiguration = delegate->snapConfiguration;
    renderObject->stretchConfiguration = delegate->stretchConfiguration;
    renderObject->showOnScreenConfiguration = delegate->showOnScreenConfiguration;
}

_SliverFloatingPinnedPersistentHeaderCls::_SliverFloatingPinnedPersistentHeaderCls(Unknown delegate) {
}
