#ifndef PACKAGES_FLUTTER_SRC_SERVICES_FONT_LOADER
#define PACKAGES_FLUTTER_SRC_SERVICES_FONT_LOADER
#include <base.hpp>
#include <dart/typed_data/typed_data.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>


class FontLoaderCls : public ObjectCls {
public:
    String family;


     FontLoaderCls(String family);

    virtual void addFont(Future<ByteData> bytes);

    virtual Future<void> load();

    virtual Future<void> loadFont(Uint8List list, String family);

private:
    bool _loaded;

    List<Future<Uint8List>> _fontFutures;


};
using FontLoader = std::shared_ptr<FontLoaderCls>;


#endif