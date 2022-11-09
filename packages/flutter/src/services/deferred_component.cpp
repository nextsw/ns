#include "deferred_component.hpp"
Future<void> DeferredComponentCls::installDeferredComponent(String componentName) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("loadingUnitId", -1);map1.set("componentName", componentName);await await SystemChannelsCls::deferredComponent-><void>invokeMethod("installDeferredComponent", list1);
}

Future<void> DeferredComponentCls::uninstallDeferredComponent(String componentName) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("loadingUnitId", -1);map1.set("componentName", componentName);await await SystemChannelsCls::deferredComponent-><void>invokeMethod("uninstallDeferredComponent", list1);
}
