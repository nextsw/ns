#include "font_loader.hpp"
FontLoader::FontLoader(String family) {
    {
        _loaded = false;
        _fontFutures = ;
    }
}

void FontLoader::addFont(Future<ByteData> bytes) {
    if (_loaded) {
        ;
    }
    _fontFutures.add(bytes.then());
}

Future<void> FontLoader::load() {
    if (_loaded) {
        ;
    }
    _loaded = true;
    Iterable<Future<void>> loadFutures = _fontFutures.map();
    await await Future.wait(loadFutures.toList());
}

Future<void> FontLoader::loadFont(String family, Uint8List list) {
    return loadFontFromList(listfamily);
}
