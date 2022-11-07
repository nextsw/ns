#include "decoration_image.hpp"
DecorationImage::DecorationImage(AlignmentGeometry alignment, Rect centerSlice, ColorFilter colorFilter, FilterQuality filterQuality, BoxFit fit, ImageProvider image, bool invertColors, bool isAntiAlias, bool matchTextDirection, ImageErrorListener onError, double opacity, ImageRepeat repeat, double scale) {
    {
        assert(image != nullptr);
        assert(alignment != nullptr);
        assert(repeat != nullptr);
        assert(matchTextDirection != nullptr);
        assert(scale != nullptr);
    }
}

DecorationImagePainter DecorationImage::createPainter(VoidCallback onChanged) {
    assert(onChanged != nullptr);
    return DecorationImagePainter._(this, onChanged);
}

bool DecorationImage::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is DecorationImage && other.image == image && other.colorFilter == colorFilter && other.fit == fit && other.alignment == alignment && other.centerSlice == centerSlice && other.repeat == repeat && other.matchTextDirection == matchTextDirection && other.scale == scale && other.opacity == opacity && other.filterQuality == filterQuality && other.invertColors == invertColors && other.isAntiAlias == isAntiAlias;
}

int DecorationImage::hashCode() {
    return Object.hash(image, colorFilter, fit, alignment, centerSlice, repeat, matchTextDirection, scale, opacity, filterQuality, invertColors, isAntiAlias);
}

String DecorationImage::toString() {
    List<String> properties = ;
    return "${objectRuntimeType(this, 'DecorationImage')}(${properties.join(", ")})";
}

void DecorationImagePainter::paint(Canvas canvas, Path clipPath, ImageConfiguration configuration, Rect rect) {
    assert(canvas != nullptr);
    assert(rect != nullptr);
    assert(configuration != nullptr);
    bool flipHorizontally = false;
    if (_details.matchTextDirection) {
        assert(());
        if (configuration.textDirection == TextDirection.rtl) {
            flipHorizontally = true;
        }
    }
    ImageStream newImageStream = _details.image.resolve(configuration);
    if (newImageStream.key != _imageStream?.key) {
        ImageStreamListener listener = ImageStreamListener(_handleImage_details.onError);
        _imageStream?.removeListener(listener);
        _imageStream = newImageStream;
        _imageStream!.addListener(listener);
    }
    if (_image == nullptr) {
        return;
    }
    if (clipPath != nullptr) {
        canvas.save();
        canvas.clipPath(clipPath);
    }
    paintImage(canvas, rect, _image!.image, _image!.debugLabel, _details.scale * _image!.scale, _details.colorFilter, _details.fit, _details.alignment.resolve(configuration.textDirection), _details.centerSlice, _details.repeat, flipHorizontally, _details.opacity, _details.filterQuality, _details.invertColors, _details.isAntiAlias);
    if (clipPath != nullptr) {
        canvas.restore();
    }
}

void DecorationImagePainter::dispose() {
    _imageStream?.removeListener(ImageStreamListener(_handleImage_details.onError));
    _image?.dispose();
    _image = nullptr;
}

String DecorationImagePainter::toString() {
    return "${objectRuntimeType(this, 'DecorationImagePainter')}(stream: $_imageStream, image: $_image) for $_details";
}

void DecorationImagePainter::_(DecorationImage _details, VoidCallback _onChanged)

void DecorationImagePainter::_handleImage(bool synchronousCall, ImageInfo value) {
    if (_image == value) {
        return;
    }
    if (_image != nullptr && _image!.isCloneOf(value)) {
        value.dispose();
        return;
    }
    _image?.dispose();
    _image = value;
    assert(_onChanged != nullptr);
    if (!synchronousCall) {
        _onChanged();
    }
}

void debugFlushLastFrameImageSizeInfo() {
    assert(());
}

void paintImage(Alignment alignment, Canvas canvas, Rect centerSlice, ColorFilter colorFilter, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, bool flipHorizontally, Image image, bool invertColors, bool isAntiAlias, double opacity, Rect rect, ImageRepeat repeat, double scale) {
    assert(canvas != nullptr);
    assert(image != nullptr);
    assert(alignment != nullptr);
    assert(repeat != nullptr);
    assert(flipHorizontally != nullptr);
    assert(isAntiAlias != nullptr);
    assert(image.debugGetOpenHandleStackTraces()?.isNotEmpty ?? true, "Cannot paint an image that is disposed.\nThe caller of paintImage is expected to wait to dispose the image until after painting has completed.");
    if (rect.isEmpty) {
        return;
    }
    Size outputSize = rect.size;
    Size inputSize = Size(image.width.toDouble(), image.height.toDouble());
    Offset sliceBorder;
    if (centerSlice != nullptr) {
        sliceBorder = (;
        outputSize = (;
        inputSize = (;
    }
    fit = centerSlice == nullptr? BoxFit.scaleDown : BoxFit.fill;
    assert(centerSlice == nullptr || (fit != BoxFit.none && fit != BoxFit.cover));
    FittedSizes fittedSizes = applyBoxFit(fit, inputSize / scale, outputSize);
    Size sourceSize = fittedSizes.source * scale;
    Size destinationSize = fittedSizes.destination;
    if (centerSlice != nullptr) {
        outputSize = sliceBorder!;
        destinationSize = sliceBorder;
        assert(sourceSize == inputSize, "centerSlice was used with a BoxFit that does not guarantee that the image is fully visible.");
    }
    if (repeat != ImageRepeat.noRepeat && destinationSize == outputSize) {
        repeat = ImageRepeat.noRepeat;
    }
    Paint paint = ;
    if (colorFilter != nullptr) {
        paint.colorFilter = colorFilter;
    }
    paint.color = Color.fromRGBO(0, 0, 0, opacity);
    paint.filterQuality = filterQuality;
    paint.invertColors = invertColors;
    double halfWidthDelta = (outputSize.width - destinationSize.width) / 2.0;
    double halfHeightDelta = (outputSize.height - destinationSize.height) / 2.0;
    double dx = halfWidthDelta + (flipHorizontally? -alignment.x : alignment.x) * halfWidthDelta;
    double dy = halfHeightDelta + alignment.y * halfHeightDelta;
    Offset destinationPosition = rect.topLeft.translate(dx, dy);
    Rect destinationRect = destinationPosition & destinationSize;
    bool invertedCanvas = false;
    if (!kReleaseMode) {
        ImageSizeInfo sizeInfo = ImageSizeInfo(debugImageLabel ?? "<Unknown Image(${image.width}×${image.height})>", Size(image.width.toDouble(), image.height.toDouble()), outputSize * PaintingBinding.instance.window.devicePixelRatio);
        assert(());
        if (!_lastFrameImageSizeInfo.contains(sizeInfo)) {
            ImageSizeInfo existingSizeInfo = _pendingImageSizeInfo[sizeInfo.source];
            if (existingSizeInfo == nullptr || existingSizeInfo.displaySizeInBytes < sizeInfo.displaySizeInBytes) {
                _pendingImageSizeInfo[sizeInfo.source!] = sizeInfo;
            }
            debugOnPaintImage?.call(sizeInfo);
            SchedulerBinding.instance.addPostFrameCallback();
        }
    }
    bool needSave = centerSlice != nullptr || repeat != ImageRepeat.noRepeat || flipHorizontally;
    if (needSave) {
        canvas.save();
    }
    if (repeat != ImageRepeat.noRepeat) {
        canvas.clipRect(rect);
    }
    if (flipHorizontally) {
        double dx = -(rect.left + rect.width / 2.0);
        canvas.translate(-dx, 0.0);
        canvas.scale(-1.0, 1.0);
        canvas.translate(dx, 0.0);
    }
    if (centerSlice == nullptr) {
        Rect sourceRect = alignment.inscribe(sourceSize, Offset.zero & inputSize);
        if (repeat == ImageRepeat.noRepeat) {
            canvas.drawImageRect(image, sourceRect, destinationRect, paint);
        } else {
            for (Rect tileRect : _generateImageTileRects(rect, destinationRect, repeat)) {
                canvas.drawImageRect(image, sourceRect, tileRect, paint);
            }
        }
    } else {
        canvas.scale(1 / scale);
        if (repeat == ImageRepeat.noRepeat) {
            canvas.drawImageNine(image, _scaleRect(centerSlice, scale), _scaleRect(destinationRect, scale), paint);
        } else {
            for (Rect tileRect : _generateImageTileRects(rect, destinationRect, repeat)) {
                canvas.drawImageNine(image, _scaleRect(centerSlice, scale), _scaleRect(tileRect, scale), paint);
            }
        }
    }
    if (needSave) {
        canvas.restore();
    }
    if (invertedCanvas) {
        canvas.restore();
    }
}

Iterable<Rect> _generateImageTileRects(Rect fundamentalRect, Rect outputRect, ImageRepeat repeat) {
    int startX = 0;
    int startY = 0;
    int stopX = 0;
    int stopY = 0;
    double strideX = fundamentalRect.width;
    double strideY = fundamentalRect.height;
    if (repeat == ImageRepeat.repeat || repeat == ImageRepeat.repeatX) {
        startX = ((outputRect.left - fundamentalRect.left) / strideX).floor();
        stopX = ((outputRect.right - fundamentalRect.right) / strideX).ceil();
    }
    if (repeat == ImageRepeat.repeat || repeat == ImageRepeat.repeatY) {
        startY = ((outputRect.top - fundamentalRect.top) / strideY).floor();
        stopY = ((outputRect.bottom - fundamentalRect.bottom) / strideY).ceil();
    }
    return ;
}

Rect _scaleRect(Rect rect, double scale) {
    return Rect.fromLTRB(rect.left * scale, rect.top * scale, rect.right * scale, rect.bottom * scale);
}
