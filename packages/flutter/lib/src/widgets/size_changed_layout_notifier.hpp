#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SIZE_CHANGED_LAYOUT_NOTIFIER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SIZE_CHANGED_LAYOUT_NOTIFIER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"


class SizeChangedLayoutNotificationCls : public LayoutChangedNotificationCls {
public:

     SizeChangedLayoutNotificationCls();
private:

};
using SizeChangedLayoutNotification = std::shared_ptr<SizeChangedLayoutNotificationCls>;

class SizeChangedLayoutNotifierCls : public SingleChildRenderObjectWidgetCls {
public:

     SizeChangedLayoutNotifierCls(Unknown child, Unknown key);
    virtual RenderObject createRenderObject(BuildContext context);

private:

};
using SizeChangedLayoutNotifier = std::shared_ptr<SizeChangedLayoutNotifierCls>;

class _RenderSizeChangedWithCallbackCls : public RenderProxyBoxCls {
public:
    VoidCallback onLayoutChangedCallback;


    virtual void performLayout();

private:
    Size _oldSize;


     _RenderSizeChangedWithCallbackCls(RenderBox child, VoidCallback onLayoutChangedCallback);

};
using _RenderSizeChangedWithCallback = std::shared_ptr<_RenderSizeChangedWithCallbackCls>;


#endif