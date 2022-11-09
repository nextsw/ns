#include "image_decoder.hpp"
Future<Image> decodeImageFromList(Uint8List bytes) {
    Codec codec = await PaintingBindingCls::instance->instantiateImageCodec(bytes);
    FrameInfo frameInfo = await codec->getNextFrame();
    return frameInfo->image;
}
