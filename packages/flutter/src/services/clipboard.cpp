#include "clipboard.hpp"
Future<void> Clipboard::setData(ClipboardData data) {
    await await SystemChannels.platform.<void>invokeMethod("Clipboard.setData", );
}

Future<ClipboardData> Clipboard::getData(String format) {
    Map<String, dynamic> result = await SystemChannels.platform.invokeMethod("Clipboard.getData", format);
    if (result == nullptr) {
        return nullptr;
    }
    return ClipboardData(();
}

Future<bool> Clipboard::hasStrings() {
    Map<String, dynamic> result = await SystemChannels.platform.invokeMethod("Clipboard.hasStrings", Clipboard.kTextPlain);
    if (result == nullptr) {
        return false;
    }
    return (;
}
