#ifndef DEFERRED_COMPONENT_H
#define DEFERRED_COMPONENT_H
#include <memory>

#include <async/async.hpp>
#include "system_channels.hpp"



class DeferredComponent {
public:

    static Future<void> installDeferredComponent(String componentName);

    static Future<void> uninstallDeferredComponent(String componentName);

private:

    void  _();

};

#endif