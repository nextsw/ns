#ifndef SCROLL_CONTEXT_H
#define SCROLL_CONTEXT_H
#include <memory>

#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include "framework.hpp"
#include "ticker_provider.hpp"



class ScrollContext {
public:

    BuildContext notificationContext();

    BuildContext storageContext();

    TickerProvider vsync();

    AxisDirection axisDirection();

    void setIgnorePointer(bool value);

    void setCanDrag(bool value);

    void setSemanticsActions(Set<SemanticsAction> actions);

    void saveOffset(double offset);

private:

};

#endif