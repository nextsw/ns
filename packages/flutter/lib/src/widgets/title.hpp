#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TITLE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TITLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "framework.hpp"


class TitleCls : public StatelessWidgetCls {
public:
    String title;

    Color color;

    Widget child;


     TitleCls(Widget child, Color color, Key key, String title);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Title = std::shared_ptr<TitleCls>;


#endif