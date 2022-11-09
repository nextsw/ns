#ifndef PACKAGES_FLUTTER_SRC_PAINTING_DEBUG
#define PACKAGES_FLUTTER_SRC_PAINTING_DEBUG
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>

bool debugDisableShadows;

HttpClientProvider debugNetworkImageHttpClientProvider;


class ImageSizeInfoCls : public ObjectCls {
public:
    String source;

    Size displaySize;

    Size imageSize;


     ImageSizeInfoCls(Size displaySize, Size imageSize, String source);
    virtual int displaySizeInBytes();

    virtual int decodedSizeInBytes();

    virtual Map<String, Object> toJson();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual int _sizeToBytes(Size size);

};
using ImageSizeInfo = std::shared_ptr<ImageSizeInfoCls>;
PaintImageCallback debugOnPaintImage;

bool debugInvertOversizedImages;

int _imageOverheadAllowanceDefault;

int debugImageOverheadAllowance;

bool debugAssertAllPaintingVarsUnset(bool debugDisableShadowsOverride, String reason);

ShaderWarmUpPictureCallback debugCaptureShaderWarmUpPicture;

bool _defaultPictureCapture(Picture picture);

ShaderWarmUpImageCallback debugCaptureShaderWarmUpImage;

bool _defaultImageCapture(Image image);



#endif