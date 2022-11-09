#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMAGE_ICON
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMAGE_ICON
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "icon.hpp"
#include "icon_theme.hpp"
#include "icon_theme_data.hpp"
#include "image.hpp"


class ImageIconCls : public StatelessWidgetCls {
public:
    ImageProvider image;

    double size;

    Color color;

    String semanticLabel;


     ImageIconCls(Color color, ImageProvider image, Unknown key, String semanticLabel, double size);
    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ImageIcon = std::shared_ptr<ImageIconCls>;


#endif