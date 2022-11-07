#ifndef IMAGE_ICON_H
#define IMAGE_ICON_H
#include <memory>

#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "icon.hpp"
#include "icon_theme.hpp"
#include "icon_theme_data.hpp"
#include "image.hpp"



class ImageIcon : StatelessWidget {
public:
    ImageProvider image;

    double size;

    Color color;

    String semanticLabel;


     ImageIcon(Color color, ImageProvider image, Unknown, String semanticLabel, double size);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif