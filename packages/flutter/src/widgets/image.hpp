#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <flutter/painting.hpp>

#include <async/async.hpp>
#include <io/io.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/semantics.hpp>
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

Future<void> precacheImage(BuildContext context, ImageErrorListener onError, ImageProvider provider, Size size);


class Image : StatefulWidget {
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


     Image(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, ImageProvider image, bool isAntiAlias, Unknown, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, String semanticLabel, double width);

    void  network(AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, Map<String, String> headers, double height, bool isAntiAlias, Unknown, ImageLoadingBuilder loadingBuilder, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, String src, double width);

    void  file(AlignmentGeometry alignment, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, File file, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width);

    void  asset(AlignmentGeometry alignment, AssetBundle bundle, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown, bool matchTextDirection, String name, Animation<double> opacity, String package, ImageRepeat repeat, double scale, String semanticLabel, double width);

    void  memory(AlignmentGeometry alignment, Uint8List bytes, int cacheHeight, int cacheWidth, Rect centerSlice, Color color, BlendMode colorBlendMode, ImageErrorWidgetBuilder errorBuilder, bool excludeFromSemantics, FilterQuality filterQuality, BoxFit fit, ImageFrameBuilder frameBuilder, bool gaplessPlayback, double height, bool isAntiAlias, Unknown, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, String semanticLabel, double width);

    State<Image> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _ImageState : State<Image> {
public:

    void initState();

    void dispose();

    void didChangeDependencies();

    void didUpdateWidget(Image oldWidget);

    void didChangeAccessibilityFeatures();

    void reassemble();

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

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


    void _updateInvertColors();

    void _resolveImage();

    ImageStreamListener _getListener(bool recreateListener);

    void _handleImageFrame(ImageInfo imageInfo, bool synchronousCall);

    void _handleImageChunk(ImageChunkEvent event);

    void _replaceImage(ImageInfo info);

    void _updateSourceStream(ImageStream newStream);

    void _listenToStream();

    void _stopListeningToStream(bool keepStreamAlive);

    Widget _debugBuildErrorWidget(BuildContext context, Object error);

};

#endif