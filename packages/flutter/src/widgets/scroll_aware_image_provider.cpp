#include "scroll_aware_image_provider.hpp"
ScrollAwareImageProvider::ScrollAwareImageProvider(DisposableBuildContext context, ImageProvider<T> imageProvider) {
    {
        assert(context != nullptr);
        assert(imageProvider != nullptr);
    }
}

void ScrollAwareImageProvider::resolveStreamForKey(ImageConfiguration configuration, ImageErrorListener handleError, T key, ImageStream stream) {
    if (stream.completer != nullptr || PaintingBinding.instance.imageCache.containsKey(key)) {
        imageProvider.resolveStreamForKey(configuration, stream, key, handleError);
        return;
    }
    if (context.context == nullptr) {
        return;
    }
    if (Scrollable.recommendDeferredLoadingForContext(context.context!)) {
        SchedulerBinding.instance.scheduleFrameCallback();
        return;
    }
    imageProvider.resolveStreamForKey(configuration, stream, key, handleError);
}

ImageStreamCompleter ScrollAwareImageProvider::load(DecoderCallback decode, T key) {
    return imageProvider.load(key, decode);
}

ImageStreamCompleter ScrollAwareImageProvider::loadBuffer(DecoderBufferCallback decode, T key) {
    return imageProvider.loadBuffer(key, decode);
}

Future<T> ScrollAwareImageProvider::obtainKey(ImageConfiguration configuration) {
    return imageProvider.obtainKey(configuration);
}
