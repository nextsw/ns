#ifndef FONT_LOADER_H
#define FONT_LOADER_H
#include <memory>
#include <typed_data.hpp>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>



class FontLoader {
public:
    String family;


     FontLoader(String family);

    void addFont(Future<ByteData> bytes);

    Future<void> load();

    Future<void> loadFont(String family, Uint8List list);

private:
    bool _loaded;

    List<Future<Uint8List>> _fontFutures;


};

#endif