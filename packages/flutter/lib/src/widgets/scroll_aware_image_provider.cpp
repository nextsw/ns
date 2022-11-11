#include "scroll_aware_image_provider.hpp"
template<typename T> ScrollAwareImageProviderCls<T>::ScrollAwareImageProviderCls(DisposableBuildContext context, ImageProvider<T> imageProvider) {
    {
        assert(context != nullptr);
        assert(imageProvider != nullptr);
    }
}

template<typename T> void ScrollAwareImageProviderCls<T>::resolveStreamForKey(ImageConfiguration configuration, ImageErrorListener handleError, T key, ImageStream stream) {
    if (stream->completer() != nullptr || PaintingBindingCls::instance->imageCache->containsKey(key)) {
        imageProvider->resolveStreamForKey(configuration, stream, key, handleError);
        return;
    }
    if (context->context == nullptr) {
        return;
    }
    if (ScrollableCls->recommendDeferredLoadingForContext(context->context!)) {
        SchedulerBindingCls::instance->scheduleFrameCallback([=] () {
            scheduleMicrotask([=] ()             {
                resolveStreamForKey(configuration, stream, key, handleError);
            });
        });
        return;
    }
    imageProvider->resolveStreamForKey(configuration, stream, key, handleError);
}

template<typename T> ImageStreamCompleter ScrollAwareImageProviderCls<T>::load(DecoderCallback decode, T key) {
    return imageProvider->load(key, decode);
}

template<typename T> ImageStreamCompleter ScrollAwareImageProviderCls<T>::loadBuffer(DecoderBufferCallback decode, T key) {
    return imageProvider->loadBuffer(key, decode);
}

template<typename T> Future<T> ScrollAwareImageProviderCls<T>::obtainKey(ImageConfiguration configuration) {
    return imageProvider->obtainKey(configuration);
}
