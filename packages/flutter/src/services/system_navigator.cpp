#include "system_navigator.hpp"
Future<void> SystemNavigator::pop(bool animated) {
    await await SystemChannels.platform.<void>invokeMethod("SystemNavigator.pop", animated);
}

Future<void> SystemNavigator::selectSingleEntryHistory() {
    return SystemChannels.navigation.<void>invokeMethod("selectSingleEntryHistory");
}

Future<void> SystemNavigator::selectMultiEntryHistory() {
    return SystemChannels.navigation.<void>invokeMethod("selectMultiEntryHistory");
}

Future<void> SystemNavigator::routeInformationUpdated(String location, bool replace, Object state) {
    return SystemChannels.navigation.<void>invokeMethod("routeInformationUpdated", );
}

Future<void> SystemNavigator::routeUpdated(String previousRouteName, String routeName) {
    return SystemChannels.navigation.<void>invokeMethod("routeUpdated", );
}
