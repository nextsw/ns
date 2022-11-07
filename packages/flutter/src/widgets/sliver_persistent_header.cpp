#include "sliver_persistent_header.hpp"
TickerProvider SliverPersistentHeaderDelegate::vsync() {
    return nullptr;
}

FloatingHeaderSnapConfiguration SliverPersistentHeaderDelegate::snapConfiguration() {
    return nullptr;
}

OverScrollHeaderStretchConfiguration SliverPersistentHeaderDelegate::stretchConfiguration() {
    return nullptr;
}

PersistentHeaderShowOnScreenConfiguration SliverPersistentHeaderDelegate::showOnScreenConfiguration() {
    return nullptr;
}

SliverPersistentHeader::SliverPersistentHeader(SliverPersistentHeaderDelegate delegate, bool floating, Unknown, bool pinned) {
    {
        assert(delegate != nullptr);
        assert(pinned != nullptr);
        assert(floating != nullptr);
    }
}

Widget SliverPersistentHeader::build(BuildContext context) {
    if (floating && pinned) {
        return _SliverFloatingPinnedPersistentHeader(delegate);
    }
    if (pinned) {
        return _SliverPinnedPersistentHeader(delegate);
    }
    if (floating) {
        return _SliverFloatingPersistentHeader(delegate);
    }
    return _SliverScrollingPersistentHeader(delegate);
}

void SliverPersistentHeader::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverPersistentHeaderDelegate>DiagnosticsProperty("delegate", delegate));
    List<String> flags = ;
    if (flags.isEmpty) {
        flags.add("normal");
    }
    properties.add(<String>IterableProperty("mode", flags));
}

_FloatingHeaderState _FloatingHeader::createState() {
    return _FloatingHeaderState();
}

void _FloatingHeaderState::didChangeDependencies() {
    super.didChangeDependencies();
    if (_position != nullptr) {
        _position!.isScrollingNotifier.removeListener(_isScrollingListener);
    }
    _position = Scrollable.of(context)?.position;
    if (_position != nullptr) {
        _position!.isScrollingNotifier.addListener(_isScrollingListener);
    }
}

void _FloatingHeaderState::dispose() {
    if (_position != nullptr) {
        _position!.isScrollingNotifier.removeListener(_isScrollingListener);
    }
    super.dispose();
}

Widget _FloatingHeaderState::build(BuildContext context) {
    return widget.child;
}

RenderSliverFloatingPersistentHeader _FloatingHeaderState::_headerRenderer() {
    return context.<RenderSliverFloatingPersistentHeader>findAncestorRenderObjectOfType();
}

void _FloatingHeaderState::_isScrollingListener() {
    assert(_position != nullptr);
    RenderSliverFloatingPersistentHeader header = _headerRenderer();
    if (_position!.isScrollingNotifier.value) {
        header?.updateScrollStartDirection(_position!.userScrollDirection);
        header?.maybeStopSnapAnimation(_position!.userScrollDirection);
    } else {
        header?.maybeStartSnapAnimation(_position!.userScrollDirection);
    }
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverPersistentHeaderElement::renderObject() {
    return (;
}

void _SliverPersistentHeaderElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    renderObject._element = this;
}

void _SliverPersistentHeaderElement::unmount() {
    renderObject._element = nullptr;
    super.unmount();
}

void _SliverPersistentHeaderElement::update(_SliverPersistentHeaderRenderObjectWidget newWidget) {
    _SliverPersistentHeaderRenderObjectWidget oldWidget = (;
    super.update(newWidget);
    SliverPersistentHeaderDelegate newDelegate = newWidget.delegate;
    SliverPersistentHeaderDelegate oldDelegate = oldWidget.delegate;
    if (newDelegate != oldDelegate && (newDelegate.runtimeType != oldDelegate.runtimeType || newDelegate.shouldRebuild(oldDelegate))) {
        renderObject.triggerRebuild();
    }
}

void _SliverPersistentHeaderElement::performRebuild() {
    super.performRebuild();
    renderObject.triggerRebuild();
}

void _SliverPersistentHeaderElement::forgetChild(Element child) {
    assert(child == this.child);
    this.child = nullptr;
    super.forgetChild(child);
}

void _SliverPersistentHeaderElement::insertRenderObjectChild(RenderBox child, Object slot) {
    assert(renderObject.debugValidateChild(child));
    renderObject.child = child;
}

void _SliverPersistentHeaderElement::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void _SliverPersistentHeaderElement::removeRenderObjectChild(RenderObject child, Object slot) {
    renderObject.child = nullptr;
}

void _SliverPersistentHeaderElement::visitChildren(ElementVisitor visitor) {
    if (child != nullptr) {
        visitor(child!);
    }
}

_SliverPersistentHeaderElement::_SliverPersistentHeaderElement(bool floating, _SliverPersistentHeaderRenderObjectWidget widget) {
    {
        assert(floating != nullptr);
    }
}

void _SliverPersistentHeaderElement::_build(bool overlapsContent, double shrinkOffset) {
    owner!.buildScope(this, );
}

_SliverPersistentHeaderElement _SliverPersistentHeaderRenderObjectWidget::createElement() {
    return _SliverPersistentHeaderElement(thisfloating);
}

void _SliverPersistentHeaderRenderObjectWidget::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<SliverPersistentHeaderDelegate>DiagnosticsProperty("delegate", delegate));
}

_SliverPersistentHeaderRenderObjectWidget::_SliverPersistentHeaderRenderObjectWidget(SliverPersistentHeaderDelegate delegate, bool floating) {
    {
        assert(delegate != nullptr);
        assert(floating != nullptr);
    }
}

double _RenderSliverPersistentHeaderForWidgetsMixin::minExtent() {
    return (().delegate.minExtent;
}

double _RenderSliverPersistentHeaderForWidgetsMixin::maxExtent() {
    return (().delegate.maxExtent;
}

void _RenderSliverPersistentHeaderForWidgetsMixin::updateChild(bool overlapsContent, double shrinkOffset) {
    assert(_element != nullptr);
    _element!._build(shrinkOffset, overlapsContent);
}

void _RenderSliverPersistentHeaderForWidgetsMixin::triggerRebuild() {
    markNeedsLayout();
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverScrollingPersistentHeader::createRenderObject(BuildContext context) {
    return _RenderSliverScrollingPersistentHeaderForWidgets(delegate.stretchConfiguration);
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverPinnedPersistentHeader::createRenderObject(BuildContext context) {
    return _RenderSliverPinnedPersistentHeaderForWidgets(delegate.stretchConfiguration, delegate.showOnScreenConfiguration);
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverFloatingPersistentHeader::createRenderObject(BuildContext context) {
    return _RenderSliverFloatingPersistentHeaderForWidgets(delegate.vsync, delegate.snapConfiguration, delegate.stretchConfiguration, delegate.showOnScreenConfiguration);
}

void _SliverFloatingPersistentHeader::updateRenderObject(BuildContext context, _RenderSliverFloatingPersistentHeaderForWidgets renderObject) {
    renderObject.vsync = delegate.vsync;
    renderObject.snapConfiguration = delegate.snapConfiguration;
    renderObject.stretchConfiguration = delegate.stretchConfiguration;
    renderObject.showOnScreenConfiguration = delegate.showOnScreenConfiguration;
}

_SliverFloatingPersistentHeader::_SliverFloatingPersistentHeader(Unknown) {
    {
        super(true);
    }
}

_RenderSliverPersistentHeaderForWidgetsMixin _SliverFloatingPinnedPersistentHeader::createRenderObject(BuildContext context) {
    return _RenderSliverFloatingPinnedPersistentHeaderForWidgets(delegate.vsync, delegate.snapConfiguration, delegate.stretchConfiguration, delegate.showOnScreenConfiguration);
}

void _SliverFloatingPinnedPersistentHeader::updateRenderObject(BuildContext context, _RenderSliverFloatingPinnedPersistentHeaderForWidgets renderObject) {
    renderObject.vsync = delegate.vsync;
    renderObject.snapConfiguration = delegate.snapConfiguration;
    renderObject.stretchConfiguration = delegate.stretchConfiguration;
    renderObject.showOnScreenConfiguration = delegate.showOnScreenConfiguration;
}

_SliverFloatingPinnedPersistentHeader::_SliverFloatingPinnedPersistentHeader(Unknown) {
    {
        super(true);
    }
}
