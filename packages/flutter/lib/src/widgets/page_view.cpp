#include "page_view.hpp"
PageControllerCls::PageControllerCls(int initialPage, bool keepPage, double viewportFraction) {
    {
        assert(initialPage != nullptr);
        assert(keepPage != nullptr);
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
    }
}

double PageControllerCls::page() {
    assert(positions->isNotEmpty, "PageController.page cannot be accessed before a PageView is built with it.");
    assert(positions->length == 1, "The page property cannot be read when multiple PageViews are attached to the same PageController.");
    _PagePosition position = ((_PagePosition)this->position);
    return position->page;
}

Future<void> PageControllerCls::animateToPage(Curve curve, Duration duration, int page) {
    _PagePosition position = ((_PagePosition)this->position);
    if (position->_cachedPage != nullptr) {
        position->_cachedPage = page->toDouble();
        return <void>value();
    }
    return position->animateTo(position->getPixelsFromPage(page->toDouble())duration, curve);
}

void PageControllerCls::jumpToPage(int page) {
    _PagePosition position = ((_PagePosition)this->position);
    if (position->_cachedPage != nullptr) {
        position->_cachedPage = page->toDouble();
        return;
    }
    position->jumpTo(position->getPixelsFromPage(page->toDouble()));
}

Future<void> PageControllerCls::nextPage(Curve curve, Duration duration) {
    return animateToPage(page!->round() + 1duration, curve);
}

Future<void> PageControllerCls::previousPage(Curve curve, Duration duration) {
    return animateToPage(page!->round() - 1duration, curve);
}

ScrollPosition PageControllerCls::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return make<_PagePositionCls>(physics, context, initialPage, keepPage, viewportFraction, oldPosition);
}

void PageControllerCls::attach(ScrollPosition position) {
    super->attach(position);
    _PagePosition pagePosition = ((_PagePosition)position);
    pagePosition->viewportFraction = viewportFraction;
}

PageMetrics PageMetricsCls::copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction) {
    return make<PageMetricsCls>(minScrollExtent ?? (hasContentDimensions? this->minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this->maxScrollExtent : nullptr), pixels ?? (hasPixels? this->pixels : nullptr), viewportDimension ?? (hasViewportDimension? this->viewportDimension : nullptr), axisDirection ?? this->axisDirection, viewportFraction ?? this->viewportFraction);
}

double PageMetricsCls::page() {
    return math->max(0.0, clampDouble(pixels, minScrollExtent, maxScrollExtent)) / math->max(1.0, viewportDimension * viewportFraction);
}

Future<void> _PagePositionCls::ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, Curve curve, Duration duration, RenderObject object, RenderObject targetRenderObject) {
    return super->ensureVisible(objectalignment, duration, curve, alignmentPolicy);
}

double _PagePositionCls::viewportFraction() {
    return _viewportFraction;
}

void _PagePositionCls::viewportFraction(double value) {
    if (_viewportFraction == value) {
        return;
    }
    double oldPage = page;
    _viewportFraction = value;
    if (oldPage != nullptr) {
        forcePixels(getPixelsFromPage(oldPage));
    }
}

double _PagePositionCls::getPageFromPixels(double pixels, double viewportDimension) {
    assert(viewportDimension > 0.0);
    double actual = math->max(0.0, pixels - _initialPageOffset) / (viewportDimension * viewportFraction);
    double round = actual->roundToDouble();
    if ((actual - round)->abs() < precisionErrorTolerance) {
        return round;
    }
    return actual;
}

double _PagePositionCls::getPixelsFromPage(double page) {
    return page * viewportDimension * viewportFraction + _initialPageOffset;
}

double _PagePositionCls::page() {
    assert(!hasPixels || hasContentDimensions, "Page value is only available after content dimensions are established.");
    return !hasPixels || !hasContentDimensions? nullptr : _cachedPage ?? getPageFromPixels(clampDouble(pixels, minScrollExtent, maxScrollExtent), viewportDimension);
}

void _PagePositionCls::saveScrollOffset() {
    PageStorageCls->of(context->storageContext)?->writeState(context->storageContext, _cachedPage ?? getPageFromPixels(pixels, viewportDimension));
}

void _PagePositionCls::restoreScrollOffset() {
    if (!hasPixels) {
        double value = ((double)PageStorageCls->of(context->storageContext)?->readState(context->storageContext));
        if (value != nullptr) {
            _pageToUseOnStartup = value;
        }
    }
}

void _PagePositionCls::saveOffset() {
    context->saveOffset(_cachedPage ?? getPageFromPixels(pixels, viewportDimension));
}

void _PagePositionCls::restoreOffset(bool initialRestore, double offset) {
    assert(initialRestore != nullptr);
    assert(offset != nullptr);
    if (initialRestore) {
        _pageToUseOnStartup = offset;
    } else {
        jumpTo(getPixelsFromPage(offset));
    }
}

bool _PagePositionCls::applyViewportDimension(double viewportDimension) {
    double oldViewportDimensions = hasViewportDimension? this->viewportDimension : nullptr;
    if (viewportDimension == oldViewportDimensions) {
        return true;
    }
    bool result = super->applyViewportDimension(viewportDimension);
    double oldPixels = hasPixels? pixels : nullptr;
    double page;
    if (oldPixels == nullptr) {
        page = _pageToUseOnStartup;
    } else     {
        if (oldViewportDimensions == 0.0) {
        page = _cachedPage!;
    } else {
        page = getPageFromPixels(oldPixels, oldViewportDimensions!);
    }
;
    }    double newPixels = getPixelsFromPage(page);
    _cachedPage = (viewportDimension == 0.0)? page : nullptr;
    if (newPixels != oldPixels) {
        correctPixels(newPixels);
        return false;
    }
    return result;
}

void _PagePositionCls::absorb(ScrollPosition other) {
    super->absorb(other);
    assert(_cachedPage == nullptr);
    if (other is! _PagePosition) {
        return;
    }
    if (other->_cachedPage != nullptr) {
        _cachedPage = other->_cachedPage;
    }
}

bool _PagePositionCls::applyContentDimensions(double maxScrollExtent, double minScrollExtent) {
    double newMinScrollExtent = minScrollExtent + _initialPageOffset;
    return super->applyContentDimensions(newMinScrollExtent, math->max(newMinScrollExtent, maxScrollExtent - _initialPageOffset));
}

PageMetrics _PagePositionCls::copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction) {
    return make<PageMetricsCls>(minScrollExtent ?? (hasContentDimensions? this->minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this->maxScrollExtent : nullptr), pixels ?? (hasPixels? this->pixels : nullptr), viewportDimension ?? (hasViewportDimension? this->viewportDimension : nullptr), axisDirection ?? this->axisDirection, viewportFraction ?? this->viewportFraction);
}

_PagePositionCls::_PagePositionCls(Unknown context, int initialPage, bool keepPage, Unknown oldPosition, Unknown physics, double viewportFraction) {
    {
        assert(initialPage != nullptr);
        assert(keepPage != nullptr);
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
        _viewportFraction = viewportFraction;
        _pageToUseOnStartup = initialPage->toDouble();
    }
}

double _PagePositionCls::_initialPageOffset() {
    return math->max(0, viewportDimension * (viewportFraction - 1) / 2);
}

_ForceImplicitScrollPhysics _ForceImplicitScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<_ForceImplicitScrollPhysicsCls>(allowImplicitScrolling, buildParent(ancestor));
}

_ForceImplicitScrollPhysicsCls::_ForceImplicitScrollPhysicsCls(bool allowImplicitScrolling, Unknown parent) {
    {
        assert(allowImplicitScrolling != nullptr);
    }
}

PageScrollPhysics PageScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<PageScrollPhysicsCls>(buildParent(ancestor));
}

Simulation PageScrollPhysicsCls::createBallisticSimulation(ScrollMetrics position, double velocity) {
    if ((velocity <= 0.0 && position->pixels <= position->minScrollExtent) || (velocity >= 0.0 && position->pixels >= position->maxScrollExtent)) {
        return super->createBallisticSimulation(position, velocity);
    }
    Tolerance tolerance = this->tolerance;
    double target = _getTargetPixels(position, tolerance, velocity);
    if (target != position->pixels) {
        return make<ScrollSpringSimulationCls>(spring, position->pixels, target, velocitytolerance);
    }
    return nullptr;
}

bool PageScrollPhysicsCls::allowImplicitScrolling() {
    return false;
}

double PageScrollPhysicsCls::_getPage(ScrollMetrics position) {
    if (position is _PagePosition) {
        return position->page!;
    }
    return position->pixels / position->viewportDimension;
}

double PageScrollPhysicsCls::_getPixels(double page, ScrollMetrics position) {
    if (position is _PagePosition) {
        return position->getPixelsFromPage(page);
    }
    return page * position->viewportDimension;
}

double PageScrollPhysicsCls::_getTargetPixels(ScrollMetrics position, Tolerance tolerance, double velocity) {
    double page = _getPage(position);
    if ( < -tolerance->velocity) {
        page = 0.5;
    } else     {
        if (velocity > tolerance->velocity) {
        page = 0.5;
    }
;
    }    return _getPixels(position, page->roundToDouble());
}

PageViewCls::PageViewCls(bool allowImplicitScrolling, List<Widget> children, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Unknown key, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection) {
    {
        assert(allowImplicitScrolling != nullptr);
        assert(clipBehavior != nullptr);
        controller = controller ?? _defaultPageController;
        childrenDelegate = make<SliverChildListDelegateCls>(children);
    }
}

void PageViewCls::builder(bool allowImplicitScrolling, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown key, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection)

void PageViewCls::custom(bool allowImplicitScrolling, SliverChildDelegate childrenDelegate, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Unknown key, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection)

State<PageView> PageViewCls::createState() {
    return make<_PageViewStateCls>();
}

void _PageViewStateCls::initState() {
    super->initState();
    _lastReportedPage = widget->controller->initialPage;
}

Widget _PageViewStateCls::build(BuildContext context) {
    AxisDirection axisDirection = _getDirection(context);
    ScrollPhysics physics = make<_ForceImplicitScrollPhysicsCls>(widget->allowImplicitScrolling)->applyTo(widget->pageSnapping? _kPagePhysics->applyTo(widget->physics ?? widget->scrollBehavior?->getScrollPhysics(context)) : widget->physics ?? widget->scrollBehavior?->getScrollPhysics(context));
    return <ScrollNotification>make<NotificationListenerCls>([=] (ScrollNotification notification) {
        if (notification->depth == 0 && widget->onPageChanged != nullptr && notification is ScrollUpdateNotification) {
            PageMetrics metrics = ((PageMetrics)notification->metrics);
            int currentPage = metrics->page!->round();
            if (currentPage != _lastReportedPage) {
                _lastReportedPage = currentPage;
                widget->onPageChanged!(currentPage);
            }
        }
        return false;
    }, make<ScrollableCls>(widget->dragStartBehavior, axisDirection, widget->controller, physics, widget->restorationId, widget->scrollBehavior ?? ScrollConfigurationCls->of(context)->copyWith(false), [=] (BuildContext context,ViewportOffset position) {
        return make<ViewportCls>(widget->allowImplicitScrolling? 1.0 : 0.0, CacheExtentStyleCls::viewport, axisDirection, position, widget->clipBehavior, makeList(ArrayItem));
    }));
}

void _PageViewStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<Axis>make<EnumPropertyCls>("scrollDirection", widget->scrollDirection));
    description->add(make<FlagPropertyCls>("reverse"widget->reverse, "reversed"));
    description->add(<PageController>make<DiagnosticsPropertyCls>("controller", widget->controllerfalse));
    description->add(<ScrollPhysics>make<DiagnosticsPropertyCls>("physics", widget->physicsfalse));
    description->add(make<FlagPropertyCls>("pageSnapping"widget->pageSnapping, "snapping disabled"));
    description->add(make<FlagPropertyCls>("allowImplicitScrolling"widget->allowImplicitScrolling, "allow implicit scrolling"));
}

AxisDirection _PageViewStateCls::_getDirection(BuildContext context) {
    ;
}
