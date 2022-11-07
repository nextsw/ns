#ifndef IMAGE_DECODER_H
#define IMAGE_DECODER_H
#include <memory>

#include <typed_data/typed_data.hpp>
#include <ui/ui.hpp>
#include "binding.hpp"


Future<Image> decodeImageFromList(Uint8List bytes);


#endif