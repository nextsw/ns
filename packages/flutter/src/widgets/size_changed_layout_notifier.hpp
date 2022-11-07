#ifndef SIZE_CHANGED_LAYOUT_NOTIFIER_H
#define SIZE_CHANGED_LAYOUT_NOTIFIER_H
#include <memory>

#include <flutter/rendering.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"



class SizeChangedLayoutNotification : LayoutChangedNotification {
public:

     SizeChangedLayoutNotification();

private:

};

class SizeChangedLayoutNotifier : SingleChildRenderObjectWidget {
public:

     SizeChangedLayoutNotifier(Unknown, Unknown);

    RenderObject createRenderObject(BuildContext context);

private:

};

class _RenderSizeChangedWithCallback : RenderProxyBox {
public:
    VoidCallback onLayoutChangedCallback;


    void performLayout();

private:
    Size _oldSize;


     _RenderSizeChangedWithCallback(RenderBox child, VoidCallback onLayoutChangedCallback);

};

#endif