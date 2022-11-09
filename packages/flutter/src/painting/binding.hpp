#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BINDING
#define PACKAGES_FLUTTER_SRC_PAINTING_BINDING
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "image_cache.hpp"
#include "shader_warm_up.hpp"


class PaintingBindingCls : public ObjectCls {
public:
    static ShaderWarmUp shaderWarmUp;


    virtual void initInstances();

    static PaintingBinding instance();

    virtual ImageCache imageCache();

    virtual ImageCache createImageCache();

    virtual Future<Codec> instantiateImageCodec(bool allowUpscaling, Uint8List bytes, int cacheHeight, int cacheWidth);

    virtual Future<Codec> instantiateImageCodecFromBuffer(bool allowUpscaling, ImmutableBuffer buffer, int cacheHeight, int cacheWidth);

    virtual void evict(String asset);

    virtual void handleMemoryPressure();

    virtual Listenable systemFonts();

    virtual Future<void> handleSystemMessage(Object systemMessage);

private:
    static PaintingBinding _instance;

    ImageCache _imageCache;

    _SystemFontsNotifier _systemFonts;


};
using PaintingBinding = std::shared_ptr<PaintingBindingCls>;

class _SystemFontsNotifierCls : public ListenableCls {
public:

    virtual void notifyListeners();

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

private:
    Set<VoidCallback> _systemFontsCallbacks;


};
using _SystemFontsNotifier = std::shared_ptr<_SystemFontsNotifierCls>;
ImageCache imageCache();



#endif