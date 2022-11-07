#ifndef ICON_THEME_DATA_H
#define ICON_THEME_DATA_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/painting.hpp>
#include "framework.hpp"



class IconThemeData {
public:
    Color color;

    double size;

    List<Shadow> shadows;


     IconThemeData(Color color, double opacity, List<Shadow> shadows, double size);

    void  fallback();

    IconThemeData copyWith(Color color, double opacity, List<Shadow> shadows, double size);

    IconThemeData merge(IconThemeData other);

    IconThemeData resolve(BuildContext context);

    bool isConcrete();

    double opacity();

    static IconThemeData lerp(IconThemeData a, IconThemeData b, double t);

    bool ==(Object other);

    int hashCode();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _opacity;


};

#endif