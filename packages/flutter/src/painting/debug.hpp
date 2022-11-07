#ifndef DEBUG_H
#define DEBUG_H
#include <memory>

#include <io/io.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>


bool debugDisableShadows;

HttpClientProvider debugNetworkImageHttpClientProvider;


class ImageSizeInfo {
public:
    String source;

    Size displaySize;

    Size imageSize;


     ImageSizeInfo(Size displaySize, Size imageSize, String source);

    int displaySizeInBytes();

    int decodedSizeInBytes();

    Map<String, Object> toJson();

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    int _sizeToBytes(Size size);

};
PaintImageCallback debugOnPaintImage;

bool debugInvertOversizedImages;

const int _imageOverheadAllowanceDefault;

int debugImageOverheadAllowance;

bool debugAssertAllPaintingVarsUnset(bool debugDisableShadowsOverride, String reason);

ShaderWarmUpPictureCallback debugCaptureShaderWarmUpPicture;

bool _defaultPictureCapture(Picture picture);

ShaderWarmUpImageCallback debugCaptureShaderWarmUpImage;

bool _defaultImageCapture(Image image);


#endif