#include "debug.hpp"
int ImageSizeInfoCls::displaySizeInBytes() {
    return _sizeToBytes(displaySize);
}

int ImageSizeInfoCls::decodedSizeInBytes() {
    return _sizeToBytes(imageSize);
}

Map<String, Object> ImageSizeInfoCls::toJson() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set("source", source);map1.set("displaySize", Map<String, Object> map2 = make<MapCls<>>();map2.set("width", displaySize->width);map2.set("height", displaySize->height);list2);map1.set("imageSize", Map<String, Object> map3 = make<MapCls<>>();map3.set("width", imageSize->width);map3.set("height", imageSize->height);list3);map1.set("displaySizeInBytes", displaySizeInBytes);map1.set("decodedSizeInBytes", decodedSizeInBytes);return list1;
}

bool ImageSizeInfoCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is ImageSizeInfo && other->source == source && other->imageSize == imageSize && other->displaySize == displaySize;
}

int ImageSizeInfoCls::hashCode() {
    return ObjectCls->hash(source, displaySize, imageSize);
}

String ImageSizeInfoCls::toString() {
    return "ImageSizeInfo($source, imageSize: $imageSize, displaySize: $displaySize)";
}

int ImageSizeInfoCls::_sizeToBytes(Size size) {
    return (size->width * size->height * 4 * (4 / 3))->toInt();
}

bool debugAssertAllPaintingVarsUnset(bool debugDisableShadowsOverride, String reason) {
    assert([=] () {
        if (debugDisableShadows != debugDisableShadowsOverride || debugNetworkImageHttpClientProvider != nullptr || debugOnPaintImage != nullptr || debugInvertOversizedImages == true || debugImageOverheadAllowance != _imageOverheadAllowanceDefault) {
            ;
        }
        return true;
    }());
    return true;
}

bool _defaultPictureCapture(Picture picture) {
    return true;
}

bool _defaultImageCapture(Image image) {
    return true;
}
