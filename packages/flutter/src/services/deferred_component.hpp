#ifndef PACKAGES_FLUTTER_SRC_SERVICES_DEFERRED_COMPONENT
#define PACKAGES_FLUTTER_SRC_SERVICES_DEFERRED_COMPONENT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include "system_channels.hpp"


class DeferredComponentCls : public ObjectCls {
public:

    static Future<void> installDeferredComponent(String componentName);

    static Future<void> uninstallDeferredComponent(String componentName);

private:

    virtual void  _();
};
using DeferredComponent = std::shared_ptr<DeferredComponentCls>;


#endif