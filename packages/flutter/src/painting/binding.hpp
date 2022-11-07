#ifndef BINDING_H
#define BINDING_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "image_cache.hpp"
#include "shader_warm_up.hpp"



class PaintingBinding {
public:
    static ShaderWarmUp shaderWarmUp;


    void initInstances();

    static PaintingBinding instance();

    ImageCache imageCache();

    ImageCache createImageCache();

    Future<Codec> instantiateImageCodec(bool allowUpscaling, Uint8List bytes, int cacheHeight, int cacheWidth);

    Future<Codec> instantiateImageCodecFromBuffer(bool allowUpscaling, ImmutableBuffer buffer, int cacheHeight, int cacheWidth);

    void evict(String asset);

    void handleMemoryPressure();

    Listenable systemFonts();

    Future<void> handleSystemMessage(Object systemMessage);

private:
    static PaintingBinding _instance;

    ImageCache _imageCache;

    _SystemFontsNotifier _systemFonts;


};

class _SystemFontsNotifier : Listenable {
public:

    void notifyListeners();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

private:
    Set<VoidCallback> _systemFontsCallbacks;


};
ImageCache imageCache();


#endif