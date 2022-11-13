#include "system_navigator.hpp"
Future<void> SystemNavigatorCls::pop(bool animated) {
    await SystemChannelsCls::platform-><void>invokeMethod(__s("SystemNavigator.pop"), animated);
}

Future<void> SystemNavigatorCls::selectSingleEntryHistory() {
    return SystemChannelsCls::navigation-><void>invokeMethod(__s("selectSingleEntryHistory"));
}

Future<void> SystemNavigatorCls::selectMultiEntryHistory() {
    return SystemChannelsCls::navigation-><void>invokeMethod(__s("selectMultiEntryHistory"));
}

Future<void> SystemNavigatorCls::routeInformationUpdated(String location, bool replace, Object state) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("location"), location);map1.set(__s("state"), state);map1.set(__s("replace"), replace);return SystemChannelsCls::navigation-><void>invokeMethod(__s("routeInformationUpdated"), list1);
}

Future<void> SystemNavigatorCls::routeUpdated(String previousRouteName, String routeName) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("previousRouteName"), previousRouteName);map1.set(__s("routeName"), routeName);return SystemChannelsCls::navigation-><void>invokeMethod(__s("routeUpdated"), list1);
}
