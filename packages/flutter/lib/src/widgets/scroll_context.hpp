#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_CONTEXT
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_CONTEXT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"
#include "ticker_provider.hpp"


class ScrollContextCls : public ObjectCls {
public:

    virtual BuildContext notificationContext();
    virtual BuildContext storageContext();
    virtual TickerProvider vsync();
    virtual AxisDirection axisDirection();
    virtual void setIgnorePointer(bool value);
    virtual void setCanDrag(bool value);
    virtual void setSemanticsActions(Set<SemanticsAction> actions);
    virtual void saveOffset(double offset);
private:

};
using ScrollContext = std::shared_ptr<ScrollContextCls>;


#endif