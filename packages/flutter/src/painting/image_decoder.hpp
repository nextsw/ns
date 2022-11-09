#ifndef PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_DECODER
#define PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_DECODER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/typed_data/typed_data.hpp>
#include <dart/ui/ui.hpp>
#include "binding.hpp"

Future<Image> decodeImageFromList(Uint8List bytes);



#endif