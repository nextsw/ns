#include "font_loader.hpp"
FontLoaderCls::FontLoaderCls(String family) {
    {
        _loaded = false;
        _fontFutures = makeList();
    }
}

void FontLoaderCls::addFont(Future<ByteData> bytes) {
    if (_loaded) {
        throw make<StateErrorCls>(__s("FontLoader is already loaded"));
    }
    _fontFutures->add(bytes->then([=] (ByteData data)     {
        Uint8ListCls->view(data->buffer, data->offsetInBytes, data->lengthInBytes);
    }));
}

Future<void> FontLoaderCls::load() {
    if (_loaded) {
        throw make<StateErrorCls>(__s("FontLoader is already loaded"));
    }
    _loaded = true;
    Iterable<Future<void>> loadFutures = _fontFutures->map([=] (Future<Uint8List> f) {
    f-><void>then([=] (Uint8List list) {
    loadFont(list, family);
});
});
    await await FutureCls->wait(loadFutures->toList());
}

Future<void> FontLoaderCls::loadFont(Uint8List list, String family) {
    return loadFontFromList(list, family);
}
