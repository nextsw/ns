#include "page_view.hpp"
PageController::PageController(int initialPage, bool keepPage, double viewportFraction) {
    {
        assert(initialPage != nullptr);
        assert(keepPage != nullptr);
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
    }
}

double PageController::page() {
    assert(positions.isNotEmpty, "PageController.page cannot be accessed before a PageView is built with it.");
    assert(positions.length == 1, "The page property cannot be read when multiple PageViews are attached to the same PageController.");
    _PagePosition position = (;
    return position.page;
}

Future<void> PageController::animateToPage(Curve curve, Duration duration, int page) {
    _PagePosition position = (;
    if (position._cachedPage != nullptr) {
        position._cachedPage = page.toDouble();
        return <void>value();
    }
    return position.animateTo(position.getPixelsFromPage(page.toDouble())duration, curve);
}

void PageController::jumpToPage(int page) {
    _PagePosition position = (;
    if (position._cachedPage != nullptr) {
        position._cachedPage = page.toDouble();
        return;
    }
    position.jumpTo(position.getPixelsFromPage(page.toDouble()));
}

Future<void> PageController::nextPage(Curve curve, Duration duration) {
    return animateToPage(page!.round() + 1duration, curve);
}

Future<void> PageController::previousPage(Curve curve, Duration duration) {
    return animateToPage(page!.round() - 1duration, curve);
}

ScrollPosition PageController::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return _PagePosition(physics, context, initialPage, keepPage, viewportFraction, oldPosition);
}

void PageController::attach(ScrollPosition position) {
    super.attach(position);
    _PagePosition pagePosition = (;
    pagePosition.viewportFraction = viewportFraction;
}

PageMetrics PageMetrics::copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction) {
    return PageMetrics(minScrollExtent ?? (hasContentDimensions? this.minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this.maxScrollExtent : nullptr), pixels ?? (hasPixels? this.pixels : nullptr), viewportDimension ?? (hasViewportDimension? this.viewportDimension : nullptr), axisDirection ?? this.axisDirection, viewportFraction ?? this.viewportFraction);
}

double PageMetrics::page() {
    return math.max(0.0, clampDouble(pixels, minScrollExtent, maxScrollExtent)) / math.max(1.0, viewportDimension * viewportFraction);
}

Future<void> _PagePosition::ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, Curve curve, Duration duration, RenderObject object, RenderObject targetRenderObject) {
    return super.ensureVisible(objectalignment, duration, curve, alignmentPolicy);
}

double _PagePosition::viewportFraction() {
    return _viewportFraction;
}

void _PagePosition::viewportFraction(double value) {
    if (_viewportFraction == value) {
        return;
    }
    double oldPage = page;
    _viewportFraction = value;
    if (oldPage != nullptr) {
        forcePixels(getPixelsFromPage(oldPage));
    }
}

double _PagePosition::getPageFromPixels(double pixels, double viewportDimension) {
    assert(viewportDimension > 0.0);
    double actual = math.max(0.0, pixels - _initialPageOffset) / (viewportDimension * viewportFraction);
    double round = actual.roundToDouble();
    if ((actual - round).abs() < precisionErrorTolerance) {
        return round;
    }
    return actual;
}

double _PagePosition::getPixelsFromPage(double page) {
    return page * viewportDimension * viewportFraction + _initialPageOffset;
}

double _PagePosition::page() {
    assert(!hasPixels || hasContentDimensions, "Page value is only available after content dimensions are established.");
    return !hasPixels || !hasContentDimensions? nullptr : _cachedPage ?? getPageFromPixels(clampDouble(pixels, minScrollExtent, maxScrollExtent), viewportDimension);
}

void _PagePosition::saveScrollOffset() {
    PageStorage.of(context.storageContext)?.writeState(context.storageContext, _cachedPage ?? getPageFromPixels(pixels, viewportDimension));
}

void _PagePosition::restoreScrollOffset() {
    if (!hasPixels) {
        double value = (;
        if (value != nullptr) {
            _pageToUseOnStartup = value;
        }
    }
}

void _PagePosition::saveOffset() {
    context.saveOffset(_cachedPage ?? getPageFromPixels(pixels, viewportDimension));
}

void _PagePosition::restoreOffset(bool initialRestore, double offset) {
    assert(initialRestore != nullptr);
    assert(offset != nullptr);
    if (initialRestore) {
        _pageToUseOnStartup = offset;
    } else {
        jumpTo(getPixelsFromPage(offset));
    }
}

bool _PagePosition::applyViewportDimension(double viewportDimension) {
    double oldViewportDimensions = hasViewportDimension? this.viewportDimension : nullptr;
    if (viewportDimension == oldViewportDimensions) {
        return true;
    }
    bool result = super.applyViewportDimension(viewportDimension);
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

void _PagePosition::absorb(ScrollPosition other) {
    super.absorb(other);
    assert(_cachedPage == nullptr);
    if (other is! _PagePosition) {
        return;
    }
    if (other._cachedPage != nullptr) {
        _cachedPage = other._cachedPage;
    }
}

bool _PagePosition::applyContentDimensions(double maxScrollExtent, double minScrollExtent) {
    double newMinScrollExtent = minScrollExtent + _initialPageOffset;
    return super.applyContentDimensions(newMinScrollExtent, math.max(newMinScrollExtent, maxScrollExtent - _initialPageOffset));
}

PageMetrics _PagePosition::copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction) {
    return PageMetrics(minScrollExtent ?? (hasContentDimensions? this.minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this.maxScrollExtent : nullptr), pixels ?? (hasPixels? this.pixels : nullptr), viewportDimension ?? (hasViewportDimension? this.viewportDimension : nullptr), axisDirection ?? this.axisDirection, viewportFraction ?? this.viewportFraction);
}

_PagePosition::_PagePosition(Unknown, int initialPage, bool keepPage, Unknown, Unknown, double viewportFraction) {
    {
        assert(initialPage != nullptr);
        assert(keepPage != nullptr);
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
        _viewportFraction = viewportFraction;
        _pageToUseOnStartup = initialPage.toDouble();
        super(nullptr, keepPage);
    }
}

double _PagePosition::_initialPageOffset() {
    return math.max(0, viewportDimension * (viewportFraction - 1) / 2);
}

_ForceImplicitScrollPhysics _ForceImplicitScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return _ForceImplicitScrollPhysics(allowImplicitScrolling, buildParent(ancestor));
}

_ForceImplicitScrollPhysics::_ForceImplicitScrollPhysics(bool allowImplicitScrolling, Unknown) {
    {
        assert(allowImplicitScrolling != nullptr);
    }
}

PageScrollPhysics PageScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return PageScrollPhysics(buildParent(ancestor));
}

Simulation PageScrollPhysics::createBallisticSimulation(ScrollMetrics position, double velocity) {
    if ((velocity <= 0.0 && position.pixels <= position.minScrollExtent) || (velocity >= 0.0 && position.pixels >= position.maxScrollExtent)) {
        return super.createBallisticSimulation(position, velocity);
    }
    Tolerance tolerance = this.tolerance;
    double target = _getTargetPixels(position, tolerance, velocity);
    if (target != position.pixels) {
        return ScrollSpringSimulation(spring, position.pixels, target, velocitytolerance);
    }
    return nullptr;
}

bool PageScrollPhysics::allowImplicitScrolling() {
    return false;
}

double PageScrollPhysics::_getPage(ScrollMetrics position) {
    if (position is _PagePosition) {
        return position.page!;
    }
    return position.pixels / position.viewportDimension;
}

double PageScrollPhysics::_getPixels(double page, ScrollMetrics position) {
    if (position is _PagePosition) {
        return position.getPixelsFromPage(page);
    }
    return page * position.viewportDimension;
}

double PageScrollPhysics::_getTargetPixels(ScrollMetrics position, Tolerance tolerance, double velocity) {
    double page = _getPage(position);
    if ( < -tolerance.velocity) {
        page = 0.5;
    } else     {
        if (velocity > tolerance.velocity) {
        page = 0.5;
    }
;
    }    return _getPixels(position, page.roundToDouble());
}

PageView::PageView(bool allowImplicitScrolling, List<Widget> children, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Unknown, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection) {
    {
        assert(allowImplicitScrolling != nullptr);
        assert(clipBehavior != nullptr);
        controller = controller ?? _defaultPageController;
        childrenDelegate = SliverChildListDelegate(children);
    }
}

void PageView::builder(bool allowImplicitScrolling, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection)

void PageView::custom(bool allowImplicitScrolling, SliverChildDelegate childrenDelegate, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Unknown, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection)

State<PageView> PageView::createState() {
    return _PageViewState();
}

void _PageViewState::initState() {
    super.initState();
    _lastReportedPage = widget.controller.initialPage;
}

Widget _PageViewState::build(BuildContext context) {
    AxisDirection axisDirection = _getDirection(context);
    ScrollPhysics physics = _ForceImplicitScrollPhysics(widget.allowImplicitScrolling).applyTo(widget.pageSnapping? _kPagePhysics.applyTo(widget.physics ?? widget.scrollBehavior?.getScrollPhysics(context)) : widget.physics ?? widget.scrollBehavior?.getScrollPhysics(context));
    return <ScrollNotification>NotificationListener(, Scrollable(widget.dragStartBehavior, axisDirection, widget.controller, physics, widget.restorationId, widget.scrollBehavior ?? ScrollConfiguration.of(context).copyWith(false), ));
}

void _PageViewState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<Axis>EnumProperty("scrollDirection", widget.scrollDirection));
    description.add(FlagProperty("reverse"widget.reverse, "reversed"));
    description.add(<PageController>DiagnosticsProperty("controller", widget.controllerfalse));
    description.add(<ScrollPhysics>DiagnosticsProperty("physics", widget.physicsfalse));
    description.add(FlagProperty("pageSnapping"widget.pageSnapping, "snapping disabled"));
    description.add(FlagProperty("allowImplicitScrolling"widget.allowImplicitScrolling, "allow implicit scrolling"));
}

AxisDirection _PageViewState::_getDirection(BuildContext context) {
    ;
}
