#ifndef PACKAGES_FLUTTER_SRC_GESTURES_POINTER_ROUTER
#define PACKAGES_FLUTTER_SRC_GESTURES_POINTER_ROUTER
#include <base.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "events.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "events.hpp"


class PointerRouterCls : public ObjectCls {
public:

    virtual void addRoute(int pointer, PointerRoute route, Matrix4 transform);

    virtual void removeRoute(int pointer, PointerRoute route);

    virtual void addGlobalRoute(PointerRoute route, Matrix4 transform);

    virtual void removeGlobalRoute(PointerRoute route);

    virtual int debugGlobalRouteCount();

    virtual void route(PointerEvent event);

private:
    Map<int, Map<PointerRoute, Matrix4>> _routeMap;

    Map<PointerRoute, Matrix4> _globalRoutes;


    virtual void _dispatch(PointerEvent event, PointerRoute route, Matrix4 transform);

    virtual void _dispatchEventToRoutes(Map<PointerRoute, Matrix4> copiedRoutes, PointerEvent event, Map<PointerRoute, Matrix4> referenceRoutes);

};
using PointerRouter = std::shared_ptr<PointerRouterCls>;


#endif