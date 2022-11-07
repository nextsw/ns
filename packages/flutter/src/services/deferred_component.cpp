#include "deferred_component.hpp"
Future<void> DeferredComponent::installDeferredComponent(String componentName) {
    await await SystemChannels.deferredComponent.<void>invokeMethod("installDeferredComponent", );
}

Future<void> DeferredComponent::uninstallDeferredComponent(String componentName) {
    await await SystemChannels.deferredComponent.<void>invokeMethod("uninstallDeferredComponent", );
}
