#ifndef PACKAGES_FLUTTER_SRC_PAINTING_DECORATION_IMAGE
#define PACKAGES_FLUTTER_SRC_PAINTING_DECORATION_IMAGE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/developer/developer.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
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

class DecorationImageCls : public ObjectCls {
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


     DecorationImageCls(AlignmentGeometry alignment, Rect centerSlice, ColorFilter colorFilter, FilterQuality filterQuality, BoxFit fit, ImageProvider image, bool invertColors, bool isAntiAlias, bool matchTextDirection, ImageErrorListener onError, double opacity, ImageRepeat repeat, double scale);

    virtual DecorationImagePainter createPainter(VoidCallback onChanged);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using DecorationImage = std::shared_ptr<DecorationImageCls>;

class DecorationImagePainterCls : public ObjectCls {
public:

    virtual void paint(Canvas canvas, Rect rect, Path clipPath, ImageConfiguration configuration);

    virtual void dispose();

    virtual String toString();

private:
    DecorationImage _details;

    VoidCallback _onChanged;

    ImageStream _imageStream;

    ImageInfo _image;


    virtual void  _(DecorationImage _details, VoidCallback _onChanged);

    virtual void _handleImage(ImageInfo value, bool synchronousCall);

};
using DecorationImagePainter = std::shared_ptr<DecorationImagePainterCls>;
Map<String, ImageSizeInfo> _pendingImageSizeInfo;

Set<ImageSizeInfo> _lastFrameImageSizeInfo;

void debugFlushLastFrameImageSizeInfo();

void paintImage(Alignment alignment, Canvas canvas, Rect centerSlice, ColorFilter colorFilter, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, bool flipHorizontally, Image image, bool invertColors, bool isAntiAlias, double opacity, Rect rect, ImageRepeat repeat, double scale);

Iterable<Rect> _generateImageTileRects(Rect outputRect, Rect fundamentalRect, ImageRepeat repeat);

Rect _scaleRect(Rect rect, double scale);



#endif