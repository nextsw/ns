#ifndef DECORATION_IMAGE_H
#define DECORATION_IMAGE_H
#include <memory>

#include <developer/developer.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include "alignment.hpp"
#include "basic_types.hpp"
#include "binding.hpp"
#include "borders.hpp"
#include "box_fit.hpp"
#include "debug.hpp"
#include "image_provider.hpp"
#include "image_stream.hpp"



enum ImageRepeat{
    repeat,
    repeatX,
    repeatY,
    noRepeat,
} // end ImageRepeat

class DecorationImage {
public:
    ImageProvider image;

    ImageErrorListener onError;

    ColorFilter colorFilter;

    BoxFit fit;

    AlignmentGeometry alignment;

    Rect centerSlice;

    ImageRepeat repeat;

    bool matchTextDirection;

    double scale;

    double opacity;

    FilterQuality filterQuality;

    bool invertColors;

    bool isAntiAlias;


     DecorationImage(AlignmentGeometry alignment, Rect centerSlice, ColorFilter colorFilter, FilterQuality filterQuality, BoxFit fit, ImageProvider image, bool invertColors, bool isAntiAlias, bool matchTextDirection, ImageErrorListener onError, double opacity, ImageRepeat repeat, double scale);

    DecorationImagePainter createPainter(VoidCallback onChanged);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class DecorationImagePainter {
public:

    void paint(Canvas canvas, Path clipPath, ImageConfiguration configuration, Rect rect);

    void dispose();

    String toString();

private:
    DecorationImage _details;

    VoidCallback _onChanged;

    ImageStream _imageStream;

    ImageInfo _image;


    void  _(DecorationImage _details, VoidCallback _onChanged);

    void _handleImage(bool synchronousCall, ImageInfo value);

};
Map<String, ImageSizeInfo> _pendingImageSizeInfo;

Set<ImageSizeInfo> _lastFrameImageSizeInfo;

void debugFlushLastFrameImageSizeInfo();

void paintImage(Alignment alignment, Canvas canvas, Rect centerSlice, ColorFilter colorFilter, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, bool flipHorizontally, Image image, bool invertColors, bool isAntiAlias, double opacity, Rect rect, ImageRepeat repeat, double scale);

Iterable<Rect> _generateImageTileRects(Rect fundamentalRect, Rect outputRect, ImageRepeat repeat);

Rect _scaleRect(Rect rect, double scale);


#endif