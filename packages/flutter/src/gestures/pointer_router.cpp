#include "pointer_router.hpp"
void PointerRouter::addRoute(int pointer, PointerRoute route, Matrix4 transform) {
    Map<PointerRoute, Matrix4> routes = _routeMap.putIfAbsent(pointer, );
    assert(!routes.containsKey(route));
    routes[route] = transform;
}

void PointerRouter::removeRoute(int pointer, PointerRoute route) {
    assert(_routeMap.containsKey(pointer));
    Map<PointerRoute, Matrix4> routes = _routeMap[pointer]!;
    assert(routes.containsKey(route));
    routes.remove(route);
    if (routes.isEmpty) {
        _routeMap.remove(pointer);
    }
}

void PointerRouter::addGlobalRoute(PointerRoute route, Matrix4 transform) {
    assert(!_globalRoutes.containsKey(route));
    _globalRoutes[route] = transform;
}

void PointerRouter::removeGlobalRoute(PointerRoute route) {
    assert(_globalRoutes.containsKey(route));
    _globalRoutes.remove(route);
}

int PointerRouter::debugGlobalRouteCount() {
    int count;
    assert(());
    if (count != nullptr) {
        return count!;
    }
    ;
}

void PointerRouter::route(PointerEvent event) {
    Map<PointerRoute, Matrix4> routes = _routeMap[event.pointer];
    Map<PointerRoute, Matrix4> copiedGlobalRoutes = <PointerRoute, Matrix4>of(_globalRoutes);
    if (routes != nullptr) {
        _dispatchEventToRoutes(event, routes, <PointerRoute, Matrix4>of(routes));
    }
    _dispatchEventToRoutes(event, _globalRoutes, copiedGlobalRoutes);
}

void PointerRouter::_dispatch(PointerEvent event, PointerRoute route, Matrix4 transform) {
    ;
}

void PointerRouter::_dispatchEventToRoutes(Map<PointerRoute, Matrix4> copiedRoutes, PointerEvent event, Map<PointerRoute, Matrix4> referenceRoutes) {
    copiedRoutes.forEach();
}
