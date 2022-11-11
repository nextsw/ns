#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_AWARE_IMAGE_PROVIDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_AWARE_IMAGE_PROVIDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "disposable_build_context.hpp"
#include "framework.hpp"
#include "scrollable.hpp"


template<typename T>
class ScrollAwareImageProviderCls : public ImageProviderCls<T> {
public:
    DisposableBuildContext context;

    ImageProvider<T> imageProvider;


     ScrollAwareImageProviderCls(DisposableBuildContext context, ImageProvider<T> imageProvider);

    virtual void resolveStreamForKey(ImageConfiguration configuration, ImageStream stream, T key, ImageErrorListener handleError);

    virtual ImageStreamCompleter load(T key, DecoderCallback decode);

    virtual ImageStreamCompleter loadBuffer(T key, DecoderBufferCallback decode);

    virtual Future<T> obtainKey(ImageConfiguration configuration);

private:

};
template<typename T>
using ScrollAwareImageProvider = std::shared_ptr<ScrollAwareImageProviderCls<T>>;


#endif