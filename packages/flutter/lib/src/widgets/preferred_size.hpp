#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PREFERRED_SIZE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PREFERRED_SIZE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"


class PreferredSizeWidgetCls : public ObjectCls {
public:

    virtual Size preferredSize();
private:

};
using PreferredSizeWidget = std::shared_ptr<PreferredSizeWidgetCls>;

class PreferredSizeCls : public StatelessWidgetCls {
public:
    Widget child;

    Size preferredSize;


     PreferredSizeCls(Widget child, Key key, Size preferredSize);
    virtual Widget build(BuildContext context);

private:

};
using PreferredSize = std::shared_ptr<PreferredSizeCls>;


#endif