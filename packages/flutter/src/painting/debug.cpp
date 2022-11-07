#include "debug.hpp"
int ImageSizeInfo::displaySizeInBytes() {
    return _sizeToBytes(displaySize);
}

int ImageSizeInfo::decodedSizeInBytes() {
    return _sizeToBytes(imageSize);
}

Map<String, Object> ImageSizeInfo::toJson() {
    return ;
}

bool ImageSizeInfo::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ImageSizeInfo && other.source == source && other.imageSize == imageSize && other.displaySize == displaySize;
}

int ImageSizeInfo::hashCode() {
    return Object.hash(source, displaySize, imageSize);
}

String ImageSizeInfo::toString() {
    return "ImageSizeInfo($source, imageSize: $imageSize, displaySize: $displaySize)";
}

int ImageSizeInfo::_sizeToBytes(Size size) {
    return (size.width * size.height * 4 * (4 / 3)).toInt();
}

bool debugAssertAllPaintingVarsUnset(bool debugDisableShadowsOverride, String reason) {
    assert(());
    return true;
}

bool _defaultPictureCapture(Picture picture) {
    return true;
}

bool _defaultImageCapture(Image image) {
    return true;
}
