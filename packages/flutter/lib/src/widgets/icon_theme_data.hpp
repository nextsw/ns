#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON_THEME_DATA
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON_THEME_DATA
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"


class IconThemeDataCls : public ObjectCls {
public:
    Color color;

    double size;

    List<Shadow> shadows;


     IconThemeDataCls(Color color, double opacity, List<Shadow> shadows, double size);

    virtual void  fallback();

    virtual IconThemeData copyWith(Color color, double opacity, List<Shadow> shadows, double size);

    virtual IconThemeData merge(IconThemeData other);

    virtual IconThemeData resolve(BuildContext context);

    virtual bool isConcrete();

    virtual double opacity();

    static IconThemeData lerp(IconThemeData a, IconThemeData b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _opacity;


};
using IconThemeData = std::shared_ptr<IconThemeDataCls>;


#endif