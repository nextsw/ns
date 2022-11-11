#include "pointer_router.hpp"
void PointerRouterCls::addRoute(int pointer, PointerRoute route, Matrix4 transform) {
    Map<PointerRoute, Matrix4> routes = _routeMap->putIfAbsent(pointer, [=] () {
    makeMap(makeList(), makeList();
});
    assert(!routes->containsKey(route));
    routes[route] = transform;
}

void PointerRouterCls::removeRoute(int pointer, PointerRoute route) {
    assert(_routeMap->containsKey(pointer));
    Map<PointerRoute, Matrix4> routes = _routeMap[pointer]!;
    assert(routes->containsKey(route));
    routes->remove(route);
    if (routes->isEmpty()) {
        _routeMap->remove(pointer);
    }
}

void PointerRouterCls::addGlobalRoute(PointerRoute route, Matrix4 transform) {
    assert(!_globalRoutes->containsKey(route));
    _globalRoutes[route] = transform;
}

void PointerRouterCls::removeGlobalRoute(PointerRoute route) {
    assert(_globalRoutes->containsKey(route));
    _globalRoutes->remove(route);
}

int PointerRouterCls::debugGlobalRouteCount() {
    int count;
    assert([=] () {
        count = _globalRoutes->length();
        return true;
    }());
    if (count != nullptr) {
        return count!;
    }
    throw make<UnsupportedErrorCls>(__s("debugGlobalRouteCount is not supported in release builds"));
}

void PointerRouterCls::route(PointerEvent event) {
    Map<PointerRoute, Matrix4> routes = _routeMap[event->pointer];
    Map<PointerRoute, Matrix4> copiedGlobalRoutes = <PointerRoute, Matrix4>of(_globalRoutes);
    if (routes != nullptr) {
        _dispatchEventToRoutes(event, routes, <PointerRoute, Matrix4>of(routes));
    }
    _dispatchEventToRoutes(event, _globalRoutes, copiedGlobalRoutes);
}

void PointerRouterCls::_dispatch(PointerEvent event, PointerRoute route, Matrix4 transform) {
    try {
        event = event->transformed(transform);
        route(event);
    } catch (Unknown exception) {
        InformationCollector collector;
        assert([=] () {
            collector = [=] () {
                makeList(ArrayItem, ArrayItem, ArrayItem);
            };
            return true;
        }());
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("gesture library"), make<ErrorDescriptionCls>(__s("while routing a pointer event")), collector));
    };
}

void PointerRouterCls::_dispatchEventToRoutes(PointerEvent event, Map<PointerRoute, Matrix4> referenceRoutes, Map<PointerRoute, Matrix4> copiedRoutes) {
    copiedRoutes->forEach([=] (PointerRoute route,Matrix4 transform) {
        if (referenceRoutes->containsKey(route)) {
            _dispatch(event, route, transform);
        }
    });
}
