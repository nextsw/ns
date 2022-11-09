#include "system_navigator.hpp"
Future<void> SystemNavigatorCls::pop(bool animated) {
    await await SystemChannelsCls::platform-><void>invokeMethod("SystemNavigator.pop", animated);
}

Future<void> SystemNavigatorCls::selectSingleEntryHistory() {
    return SystemChannelsCls::navigation-><void>invokeMethod("selectSingleEntryHistory");
}

Future<void> SystemNavigatorCls::selectMultiEntryHistory() {
    return SystemChannelsCls::navigation-><void>invokeMethod("selectMultiEntryHistory");
}

Future<void> SystemNavigatorCls::routeInformationUpdated(String location, bool replace, Object state) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("location", location);map1.set("state", state);map1.set("replace", replace);return SystemChannelsCls::navigation-><void>invokeMethod("routeInformationUpdated", list1);
}

Future<void> SystemNavigatorCls::routeUpdated(String previousRouteName, String routeName) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("previousRouteName", previousRouteName);map1.set("routeName", routeName);return SystemChannelsCls::navigation-><void>invokeMethod("routeUpdated", list1);
}
