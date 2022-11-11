#include "debug.hpp"
int ImageSizeInfoCls::displaySizeInBytes() {
    return _sizeToBytes(displaySize);
}

int ImageSizeInfoCls::decodedSizeInBytes() {
    return _sizeToBytes(imageSize);
}

Map<String, Object> ImageSizeInfoCls::toJson() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("source"), source);map1.set(__s("displaySize"), Map<String, Object> map2 = make<MapCls<>>();map2.set(__s("width"), displaySize->width());map2.set(__s("height"), displaySize->height());list2);map1.set(__s("imageSize"), Map<String, Object> map3 = make<MapCls<>>();map3.set(__s("width"), imageSize->width());map3.set(__s("height"), imageSize->height());list3);map1.set(__s("displaySizeInBytes"), displaySizeInBytes());map1.set(__s("decodedSizeInBytes"), decodedSizeInBytes());return list1;
}

bool ImageSizeInfoCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ImageSizeInfo>(other) && other->source == source && other->imageSize == imageSize && other->displaySize == displaySize;
}

int ImageSizeInfoCls::hashCode() {
    return ObjectCls->hash(source, displaySize, imageSize);
}

String ImageSizeInfoCls::toString() {
    return __s("ImageSizeInfo($source, imageSize: $imageSize, displaySize: $displaySize)");
}

int ImageSizeInfoCls::_sizeToBytes(Size size) {
    return (size->width() * size->height() * 4 * (4 / 3))->toInt();
}

bool debugAssertAllPaintingVarsUnset(bool debugDisableShadowsOverride, String reason) {
    assert([=] () {
        if (debugDisableShadows != debugDisableShadowsOverride || debugNetworkImageHttpClientProvider != nullptr || debugOnPaintImage != nullptr || debugInvertOversizedImages == true || debugImageOverheadAllowance != _imageOverheadAllowanceDefault) {
            throw make<FlutterErrorCls>(reason);
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
