#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMAGE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMAGE
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/io/io.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "disposable_build_context.hpp"
#include "framework.hpp"
#include "localizations.hpp"
#include "media_query.hpp"
#include "placeholder.hpp"
#include "scroll_aware_image_provider.hpp"
#include "text.hpp"
#include "ticker_provider.hpp"

ImageConfiguration createLocalImageConfiguration(BuildContext context, Size size);

Future<void> precacheImage(ImageProvider provider, BuildContext context, ImageErrorListener onError, Size size);


class ImageCls : public StatefulWidgetCls {
public:
    ImageProvider image;

    ImageFrameBuilder frameBuilder;

    ImageLoadingBuilder loadingBuilder;

    ImageErrorWidgetBuilder errorBuilder;

    double width;

    double height;

    Color color;

    Animation<double> opacity;

    FilterQuality filterQuality;

    BlendMode colorBlendMode;

    BoxFit fit;

    AlignmentGeometry alignment;

    ImageRepeat repeat;

    Rect centerSlice;

    bool matchTextDirection;

    bool gaplessPlayback;

    String semanticLabel;

    bool excludeFromSemantics;

    bool isAntiAlias;


     ImageCls(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, ImageProvider image, bool isAntiAlias, Key key, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, String semanticLabel, double width);

    virtual void  network(String src, AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, Map<String, String> headers, double height, bool isAntiAlias, Key key, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width);

    virtual void  file(File file, AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Key key, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width);

    virtual void  asset(String name, AlignmentGeometry alignment, AssetBundle bundle, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Key key, bool matchTextDirection, Animation<double> opacity, String package, ImageRepeat repeat, double scale, String semanticLabel, double width);

    virtual void  memory(Uint8List bytes, AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Key key, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width);

    virtual State<Image> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Image = std::shared_ptr<ImageCls>;

class _ImageStateCls : public StateCls<Image> {
public:

    virtual void initState();

    virtual void dispose();

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(Image oldWidget);

    virtual void didChangeAccessibilityFeatures();

    virtual void reassemble();

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    ImageStream _imageStream;

    ImageInfo _imageInfo;

    ImageChunkEvent _loadingProgress;

    bool _isListeningToStream;

    bool _invertColors;

    int _frameNumber;

    bool _wasSynchronouslyLoaded;

    DisposableBuildContext<State<Image>> _scrollAwareContext;

    Object _lastException;

    StackTrace _lastStack;

    ImageStreamCompleterHandle _completerHandle;

    ImageStreamListener _imageStreamListener;


    virtual void _updateInvertColors();

    virtual void _resolveImage();

    virtual ImageStreamListener _getListener(bool recreateListener);

    virtual void _handleImageFrame(ImageInfo imageInfo, bool synchronousCall);

    virtual void _handleImageChunk(ImageChunkEvent event);

    virtual void _replaceImage(ImageInfo info);

    virtual void _updateSourceStream(ImageStream newStream);

    virtual void _listenToStream();

    virtual void _stopListeningToStream(bool keepStreamAlive);

    virtual Widget _debugBuildErrorWidget(BuildContext context, Object error);

};
using _ImageState = std::shared_ptr<_ImageStateCls>;


#endif