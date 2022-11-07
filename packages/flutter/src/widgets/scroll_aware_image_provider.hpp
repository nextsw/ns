#ifndef SCROLL_AWARE_IMAGE_PROVIDER_H
#define SCROLL_AWARE_IMAGE_PROVIDER_H
#include <memory>

#include <async/async.hpp>
#include <flutter/painting.hpp>
#include <flutter/scheduler.hpp>
#include "disposable_build_context.hpp"
#include "framework.hpp"
#include "scrollable.hpp"



class ScrollAwareImageProvider<T extends Object> : ImageProvider<T> {
public:
    DisposableBuildContext context;

    ImageProvider<T> imageProvider;


     ScrollAwareImageProvider(DisposableBuildContext context, ImageProvider<T> imageProvider);

    void resolveStreamForKey(ImageConfiguration configuration, ImageErrorListener handleError, T key, ImageStream stream);

    ImageStreamCompleter load(DecoderCallback decode, T key);

    ImageStreamCompleter loadBuffer(DecoderBufferCallback decode, T key);

    Future<T> obtainKey(ImageConfiguration configuration);

private:

};

#endif