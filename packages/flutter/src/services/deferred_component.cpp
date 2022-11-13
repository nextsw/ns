#include "deferred_component.hpp"
Future<void> DeferredComponentCls::installDeferredComponent(String componentName) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("loadingUnitId"), -1);map1.set(__s("componentName"), componentName);await SystemChannelsCls::deferredComponent-><void>invokeMethod(__s("installDeferredComponent"), list1);
}

Future<void> DeferredComponentCls::uninstallDeferredComponent(String componentName) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("loadingUnitId"), -1);map1.set(__s("componentName"), componentName);await SystemChannelsCls::deferredComponent-><void>invokeMethod(__s("uninstallDeferredComponent"), list1);
}
