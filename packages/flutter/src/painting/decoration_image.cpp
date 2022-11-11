#include "decoration_image.hpp"
DecorationImageCls::DecorationImageCls(AlignmentGeometry alignment, Rect centerSlice, ColorFilter colorFilter, FilterQuality filterQuality, BoxFit fit, ImageProvider image, bool invertColors, bool isAntiAlias, bool matchTextDirection, ImageErrorListener onError, double opacity, ImageRepeat repeat, double scale) {
    {
        assert(image != nullptr);
        assert(alignment != nullptr);
        assert(repeat != nullptr);
        assert(matchTextDirection != nullptr);
        assert(scale != nullptr);
    }
}

DecorationImagePainter DecorationImageCls::createPainter(VoidCallback onChanged) {
    assert(onChanged != nullptr);
    return DecorationImagePainterCls->_(this, onChanged);
}

bool DecorationImageCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<DecorationImage>(other) && other->image == image && other->colorFilter == colorFilter && other->fit == fit && other->alignment == alignment && other->centerSlice == centerSlice && other->repeat == repeat && other->matchTextDirection == matchTextDirection && other->scale == scale && other->opacity == opacity && other->filterQuality == filterQuality && other->invertColors == invertColors && other->isAntiAlias == isAntiAlias;
}

int DecorationImageCls::hashCode() {
    return ObjectCls->hash(image, colorFilter, fit, alignment, centerSlice, repeat, matchTextDirection, scale, opacity, filterQuality, invertColors, isAntiAlias);
}

String DecorationImageCls::toString() {
    List<String> list1 = make<ListCls<>>();list1.add(ArrayItem);if (colorFilter != nullptr) {    list1.add(ArrayItem);}if (fit != nullptr && !(fit == BoxFitCls::fill && centerSlice != nullptr) && !(fit == BoxFitCls::scaleDown && centerSlice == nullptr)) {    list1.add(ArrayItem);}list1.add(ArrayItem);if (centerSlice != nullptr) {    list1.add(ArrayItem);}if (repeat != ImageRepeatCls::noRepeat) {    list1.add(ArrayItem);}if (matchTextDirection) {    list1.add(ArrayItem);}list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);if (invertColors) {    list1.add(ArrayItem);}if (isAntiAlias) {    list1.add(ArrayItem);}List<String> properties = list1;
    return __s("${objectRuntimeType(this, 'DecorationImage')}(${properties.join(", ")})");
}

void DecorationImagePainterCls::paint(Canvas canvas, Path clipPath, ImageConfiguration configuration, Rect rect) {
    assert(canvas != nullptr);
    assert(rect != nullptr);
    assert(configuration != nullptr);
    bool flipHorizontally = false;
    if (_details->matchTextDirection) {
        assert([=] () {
            if (configuration->textDirection == nullptr) {
                ;
            }
            return true;
        }());
        if (configuration->textDirection == TextDirectionCls::rtl) {
            flipHorizontally = true;
        }
    }
    ImageStream newImageStream = _details->image->resolve(configuration);
    if (newImageStream->key() != _imageStream?->key) {
        ImageStreamListener listener = make<ImageStreamListenerCls>(_handleImage_details->onError);
        _imageStream?->removeListener(listener);
        _imageStream = newImageStream;
        _imageStream!->addListener(listener);
    }
    if (_image == nullptr) {
        return;
    }
    if (clipPath != nullptr) {
        canvas->save();
        canvas->clipPath(clipPath);
    }
    paintImage(canvas, rect, _image!->image, _image!->debugLabel, _details->scale * _image!->scale, _details->colorFilter, _details->fit, _details->alignment->resolve(configuration->textDirection), _details->centerSlice, _details->repeat, flipHorizontally, _details->opacity, _details->filterQuality, _details->invertColors, _details->isAntiAlias);
    if (clipPath != nullptr) {
        canvas->restore();
    }
}

void DecorationImagePainterCls::dispose() {
    _imageStream?->removeListener(make<ImageStreamListenerCls>(_handleImage_details->onError));
    _image?->dispose();
    _image = nullptr;
}

String DecorationImagePainterCls::toString() {
    return __s("${objectRuntimeType(this, 'DecorationImagePainter')}(stream: $_imageStream, image: $_image) for $_details");
}

void DecorationImagePainterCls::_(DecorationImage _details, VoidCallback _onChanged)

void DecorationImagePainterCls::_handleImage(bool synchronousCall, ImageInfo value) {
    if (_image == value) {
        return;
    }
    if (_image != nullptr && _image!->isCloneOf(value)) {
        value->dispose();
        return;
    }
    _image?->dispose();
    _image = value;
    assert(_onChanged != nullptr);
    if (!synchronousCall) {
        _onChanged();
    }
}

void debugFlushLastFrameImageSizeInfo() {
    assert([=] () {
        _lastFrameImageSizeInfo = makeSet();
        return true;
    }());
}

void paintImage(Alignment alignment, Canvas canvas, Rect centerSlice, ColorFilter colorFilter, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, bool flipHorizontally, Image image, bool invertColors, bool isAntiAlias, double opacity, Rect rect, ImageRepeat repeat, double scale) {
    assert(canvas != nullptr);
    assert(image != nullptr);
    assert(alignment != nullptr);
    assert(repeat != nullptr);
    assert(flipHorizontally != nullptr);
    assert(isAntiAlias != nullptr);
    assert(image->debugGetOpenHandleStackTraces()?->isNotEmpty or true, __s("Cannot paint an image that is disposed.\nThe caller of paintImage is expected to wait to dispose the image until after painting has completed."));
    if (rect->isEmpty()) {
        return;
    }
    Size outputSize = rect->size();
    Size inputSize = make<SizeCls>(image->width->toDouble(), image->height->toDouble());
    Offset sliceBorder;
    if (centerSlice != nullptr) {
        sliceBorder = as<Offset>(inputSize / scale - centerSlice->size());
        outputSize = as<Size>(outputSize - sliceBorder);
        inputSize = as<Size>(inputSize - sliceBorder * scale);
    }
    fit = centerSlice == nullptr? BoxFitCls::scaleDown : BoxFitCls::fill;
    assert(centerSlice == nullptr || (fit != BoxFitCls::none && fit != BoxFitCls::cover));
    FittedSizes fittedSizes = applyBoxFit(fit, inputSize / scale, outputSize);
    Size sourceSize = fittedSizes->source * scale;
    Size destinationSize = fittedSizes->destination;
    if (centerSlice != nullptr) {
        outputSize = sliceBorder!;
        destinationSize = sliceBorder;
        assert(sourceSize == inputSize, __s("centerSlice was used with a BoxFit that does not guarantee that the image is fully visible."));
    }
    if (repeat != ImageRepeatCls::noRepeat && destinationSize == outputSize) {
        repeat = ImageRepeatCls::noRepeat;
    }
    auto _c1 = make<PaintCls>();_c1.isAntiAlias = isAntiAlias;Paint paint = _c1;
    if (colorFilter != nullptr) {
        paint->colorFilter = colorFilter;
    }
    paint->color() = ColorCls->fromRGBO(0, 0, 0, opacity);
    paint->filterQuality = filterQuality;
    paint->invertColors = invertColors;
    double halfWidthDelta = (outputSize->width() - destinationSize->width()) / 2.0;
    double halfHeightDelta = (outputSize->height() - destinationSize->height()) / 2.0;
    double dx = halfWidthDelta + (flipHorizontally? -alignment->x : alignment->x) * halfWidthDelta;
    double dy = halfHeightDelta + alignment->y * halfHeightDelta;
    Offset destinationPosition = rect->topLeft()->translate(dx, dy);
    Rect destinationRect = destinationPosition & destinationSize;
    bool invertedCanvas = false;
    if (!kReleaseMode) {
        ImageSizeInfo sizeInfo = make<ImageSizeInfoCls>(debugImageLabel or __s("<Unknown Image(${image.width}×${image.height})>"), make<SizeCls>(image->width->toDouble(), image->height->toDouble()), outputSize * PaintingBindingCls::instance->window->devicePixelRatio);
        assert([=] () {
            if (debugInvertOversizedImages && sizeInfo->decodedSizeInBytes() > sizeInfo->displaySizeInBytes() + debugImageOverheadAllowance) {
                int overheadInKilobytes = (sizeInfo->decodedSizeInBytes() - sizeInfo->displaySizeInBytes()) ~/ 1024;
                int outputWidth = sizeInfo->displaySize->width()->toInt();
                int outputHeight = sizeInfo->displaySize->height()->toInt();
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(__s("Image $debugImageLabel has a display size of $outputWidth×$outputHeight but a decode size of ${image.width}×${image.height}, which uses an additional ${overheadInKilobytes}KB.\n\nConsider resizing the asset ahead of time, supplying a cacheWidth parameter of $outputWidth, a cacheHeight parameter of $outputHeight, or using a ResizeImage."), __s("painting library"), make<ErrorDescriptionCls>(__s("while painting an image"))));
                            auto _c2 = make<PaintCls>();            _c2.colorFilter = ColorFilterCls->matrix(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));canvas->saveLayer(destinationRect, _c2);
                double dy = -(rect->top + rect->height() / 2.0);
                canvas->translate(0.0, -dy);
                canvas->scale(1.0, -1.0);
                canvas->translate(0.0, dy);
                invertedCanvas = true;
            }
            return true;
        }());
        if (!_lastFrameImageSizeInfo->contains(sizeInfo)) {
            ImageSizeInfo existingSizeInfo = _pendingImageSizeInfo[sizeInfo->source];
            if (existingSizeInfo == nullptr || existingSizeInfo->displaySizeInBytes() < sizeInfo->displaySizeInBytes()) {
                _pendingImageSizeInfo[sizeInfo->source!] = sizeInfo;
            }
            debugOnPaintImage?->call(sizeInfo);
            SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
                _lastFrameImageSizeInfo = _pendingImageSizeInfo->values->toSet();
                if (_pendingImageSizeInfo->isEmpty) {
                    return;
                }
                            Map<String, Object> map3 = make<MapCls<>>();            for (ImageSizeInfo imageSizeInfo : _pendingImageSizeInfo->values)                 {                                ;                            }            {                map3.set(imageSizeInfo->source!, imageSizeInfo->toJson());            }developer->postEvent(__s("Flutter.ImageSizesForFrame"), list3);
                _pendingImageSizeInfo = makeMap(makeList(), makeList();
            });
        }
    }
    bool needSave = centerSlice != nullptr || repeat != ImageRepeatCls::noRepeat || flipHorizontally;
    if (needSave) {
        canvas->save();
    }
    if (repeat != ImageRepeatCls::noRepeat) {
        canvas->clipRect(rect);
    }
    if (flipHorizontally) {
        double dx = -(rect->left + rect->width() / 2.0);
        canvas->translate(-dx, 0.0);
        canvas->scale(-1.0, 1.0);
        canvas->translate(dx, 0.0);
    }
    if (centerSlice == nullptr) {
        Rect sourceRect = alignment->inscribe(sourceSize, OffsetCls::zero & inputSize);
        if (repeat == ImageRepeatCls::noRepeat) {
            canvas->drawImageRect(image, sourceRect, destinationRect, paint);
        } else {
            for (Rect tileRect : _generateImageTileRects(rect, destinationRect, repeat)) {
                canvas->drawImageRect(image, sourceRect, tileRect, paint);
            }
        }
    } else {
        canvas->scale(1 / scale);
        if (repeat == ImageRepeatCls::noRepeat) {
            canvas->drawImageNine(image, _scaleRect(centerSlice, scale), _scaleRect(destinationRect, scale), paint);
        } else {
            for (Rect tileRect : _generateImageTileRects(rect, destinationRect, repeat)) {
                canvas->drawImageNine(image, _scaleRect(centerSlice, scale), _scaleRect(tileRect, scale), paint);
            }
        }
    }
    if (needSave) {
        canvas->restore();
    }
    if (invertedCanvas) {
        canvas->restore();
    }
}

Iterable<Rect> _generateImageTileRects(Rect fundamentalRect, Rect outputRect, ImageRepeat repeat) {
    int startX = 0;
    int startY = 0;
    int stopX = 0;
    int stopY = 0;
    double strideX = fundamentalRect->width();
    double strideY = fundamentalRect->height();
    if (repeat == ImageRepeatCls::repeat || repeat == ImageRepeatCls::repeatX) {
        startX = ((outputRect->left - fundamentalRect->left) / strideX)->floor();
        stopX = ((outputRect->right - fundamentalRect->right) / strideX)->ceil();
    }
    if (repeat == ImageRepeatCls::repeat || repeat == ImageRepeatCls::repeatY) {
        startY = ((outputRect->top - fundamentalRect->top) / strideY)->floor();
        stopY = ((outputRect->bottom - fundamentalRect->bottom) / strideY)->ceil();
    }
    List<Rect> list1 = make<ListCls<>>();for (; i <= stopX; ++i)     {        ;    }{    list1.add(ArrayItem);}return list1;
}

Rect _scaleRect(Rect rect, double scale) {
    return RectCls->fromLTRB(rect->left * scale, rect->top * scale, rect->right * scale, rect->bottom * scale);
}
