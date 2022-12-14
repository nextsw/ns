#include "binding.hpp"
void PaintingBindingCls::initInstances() {
    super->initInstances();
    _instance = this;
    _imageCache = createImageCache();
    shaderWarmUp?->execute();
}

PaintingBinding PaintingBindingCls::instance() {
    return BindingBaseCls->checkInstance(_instance);
}

ImageCache PaintingBindingCls::imageCache() {
    return _imageCache;
}

ImageCache PaintingBindingCls::createImageCache() {
    return make<ImageCacheCls>();
}

Future<Codec> PaintingBindingCls::instantiateImageCodec(Uint8List bytes, bool allowUpscaling, int cacheHeight, int cacheWidth) {
    assert(cacheWidth == nullptr || cacheWidth > 0);
    assert(cacheHeight == nullptr || cacheHeight > 0);
    assert(allowUpscaling != nullptr);
    return ui->instantiateImageCodec(bytes, cacheWidth, cacheHeight, allowUpscaling);
}

Future<Codec> PaintingBindingCls::instantiateImageCodecFromBuffer(ImmutableBuffer buffer, bool allowUpscaling, int cacheHeight, int cacheWidth) {
    assert(cacheWidth == nullptr || cacheWidth > 0);
    assert(cacheHeight == nullptr || cacheHeight > 0);
    assert(allowUpscaling != nullptr);
    return ui->instantiateImageCodecFromBuffer(buffer, cacheWidth, cacheHeight, allowUpscaling);
}

void PaintingBindingCls::evict(String asset) {
    super->evict(asset);
    imageCache()->clear();
    imageCache()->clearLiveImages();
}

void PaintingBindingCls::handleMemoryPressure() {
    super->handleMemoryPressure();
    imageCache()->clear();
}

Listenable PaintingBindingCls::systemFonts() {
    return _systemFonts;
}

Future<void> PaintingBindingCls::handleSystemMessage(Object systemMessage) {
    await super->handleSystemMessage(systemMessage);
    Map<String, Object> message = as<Map<String, Object>>(systemMessage);
    String type = as<String>(message[__s("type")]);
    ;
    return;
}

void _SystemFontsNotifierCls::notifyListeners() {
    for (VoidCallback callback : _systemFontsCallbacks) {
        callback();
    }
}

void _SystemFontsNotifierCls::addListener(VoidCallback listener) {
    _systemFontsCallbacks->add(listener);
}

void _SystemFontsNotifierCls::removeListener(VoidCallback listener) {
    _systemFontsCallbacks->remove(listener);
}

ImageCache imageCache() {
    return PaintingBindingCls::instance->imageCache;
}
