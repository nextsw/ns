#include "clipboard.hpp"
Future<void> ClipboardCls::setData(ClipboardData data) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("text", data->text);await await SystemChannelsCls::platform-><void>invokeMethod("Clipboard.setData", list1);
}

Future<ClipboardData> ClipboardCls::getData(String format) {
    Map<String, dynamic> result = await SystemChannelsCls::platform->invokeMethod("Clipboard.getData", format);
    if (result == nullptr) {
        return nullptr;
    }
    return make<ClipboardDataCls>(((String)result["text"]));
}

Future<bool> ClipboardCls::hasStrings() {
    Map<String, dynamic> result = await SystemChannelsCls::platform->invokeMethod("Clipboard.hasStrings", ClipboardCls::kTextPlain);
    if (result == nullptr) {
        return false;
    }
    return ((bool)result["value"]);
}
