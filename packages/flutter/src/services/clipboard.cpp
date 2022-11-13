#include "clipboard.hpp"
Future<void> ClipboardCls::setData(ClipboardData data) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("text"), data->text);await SystemChannelsCls::platform-><void>invokeMethod(__s("Clipboard.setData"), list1);
}

Future<ClipboardData> ClipboardCls::getData(String format) {
    Map<String, Object> result = await SystemChannelsCls::platform->invokeMethod(__s("Clipboard.getData"), format);
    if (result == nullptr) {
        return nullptr;
    }
    return make<ClipboardDataCls>(as<String>(result[__s("text")]));
}

Future<bool> ClipboardCls::hasStrings() {
    Map<String, Object> result = await SystemChannelsCls::platform->invokeMethod(__s("Clipboard.hasStrings"), ClipboardCls::kTextPlain);
    if (result == nullptr) {
        return false;
    }
    return as<bool>(result[__s("value")]);
}
