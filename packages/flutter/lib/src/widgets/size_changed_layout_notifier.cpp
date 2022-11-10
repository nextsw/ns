#include "size_changed_layout_notifier.hpp"
RenderObject SizeChangedLayoutNotifierCls::createRenderObject(BuildContext context) {
    return make<_RenderSizeChangedWithCallbackCls>([=] () {
        make<SizeChangedLayoutNotificationCls>()->dispatch(context);
    });
}

void _RenderSizeChangedWithCallbackCls::performLayout() {
    super->performLayout();
    if (_oldSize != nullptr && size != _oldSize) {
        onLayoutChangedCallback();
    }
    _oldSize = size;
}

_RenderSizeChangedWithCallbackCls::_RenderSizeChangedWithCallbackCls(RenderBox child, VoidCallback onLayoutChangedCallback) : RenderProxyBox(child) {
    {
        assert(onLayoutChangedCallback != nullptr);
    }
}
