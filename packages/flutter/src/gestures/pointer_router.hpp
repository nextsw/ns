#ifndef POINTER_ROUTER_H
#define POINTER_ROUTER_H
#include <memory>
#include <vector_math/vector_math_64.hpp>
#include "events.hpp"

#include <flutter/foundation.hpp>
#include "events.hpp"



class PointerRouter {
public:

    void addRoute(int pointer, PointerRoute route, Matrix4 transform);

    void removeRoute(int pointer, PointerRoute route);

    void addGlobalRoute(PointerRoute route, Matrix4 transform);

    void removeGlobalRoute(PointerRoute route);

    int debugGlobalRouteCount();

    void route(PointerEvent event);

private:
    Map<int, Map<PointerRoute, Matrix4>> _routeMap;

    Map<PointerRoute, Matrix4> _globalRoutes;


    void _dispatch(PointerEvent event, PointerRoute route, Matrix4 transform);

    void _dispatchEventToRoutes(Map<PointerRoute, Matrix4> copiedRoutes, PointerEvent event, Map<PointerRoute, Matrix4> referenceRoutes);

};

#endif