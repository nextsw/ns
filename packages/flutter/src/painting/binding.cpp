#include "binding.hpp"
void PaintingBinding::initInstances() {
    super.initInstances();
    _instance = this;
    _imageCache = createImageCache();
    shaderWarmUp?.execute();
}

PaintingBinding PaintingBinding::instance() {
    return BindingBase.checkInstance(_instance);
}

ImageCache PaintingBinding::imageCache() {
    return _imageCache;
}

ImageCache PaintingBinding::createImageCache() {
    return ImageCache();
}

Future<Codec> PaintingBinding::instantiateImageCodec(bool allowUpscaling, Uint8List bytes, int cacheHeight, int cacheWidth) {
    assert(cacheWidth == nullptr || cacheWidth > 0);
    assert(cacheHeight == nullptr || cacheHeight > 0);
    assert(allowUpscaling != nullptr);
    return ui.instantiateImageCodec(bytescacheWidth, cacheHeight, allowUpscaling);
}

Future<Codec> PaintingBinding::instantiateImageCodecFromBuffer(bool allowUpscaling, ImmutableBuffer buffer, int cacheHeight, int cacheWidth) {
    assert(cacheWidth == nullptr || cacheWidth > 0);
    assert(cacheHeight == nullptr || cacheHeight > 0);
    assert(allowUpscaling != nullptr);
    return ui.instantiateImageCodecFromBuffer(buffercacheWidth, cacheHeight, allowUpscaling);
}

void PaintingBinding::evict(String asset) {
    super.evict(asset);
    imageCache.clear();
    imageCache.clearLiveImages();
}

void PaintingBinding::handleMemoryPressure() {
    super.handleMemoryPressure();
    imageCache.clear();
}

Listenable PaintingBinding::systemFonts() {
    return _systemFonts;
}

Future<void> PaintingBinding::handleSystemMessage(Object systemMessage) {
    await await super.handleSystemMessage(systemMessage);
    Map<String, dynamic> message = (;
    String type = (;
    ;
    return;
}

void _SystemFontsNotifier::notifyListeners() {
    for (VoidCallback callback : _systemFontsCallbacks) {
        callback();
    }
}

void _SystemFontsNotifier::addListener(VoidCallback listener) {
    _systemFontsCallbacks.add(listener);
}

void _SystemFontsNotifier::removeListener(VoidCallback listener) {
    _systemFontsCallbacks.remove(listener);
}

ImageCache imageCache() {
    return PaintingBinding.instance.imageCache;
}
