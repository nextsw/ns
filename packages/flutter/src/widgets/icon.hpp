#ifndef ICON_H
#define ICON_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "icon_data.hpp"
#include "icon_theme.hpp"
#include "icon_theme_data.hpp"



class Icon : StatelessWidget {
public:
    IconData icon;

    double size;

    Color color;

    String semanticLabel;

    TextDirection textDirection;

    List<Shadow> shadows;


     Icon(Color color, IconData icon, Unknown, String semanticLabel, List<Shadow> shadows, double size, TextDirection textDirection);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif