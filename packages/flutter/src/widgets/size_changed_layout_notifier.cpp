#include "size_changed_layout_notifier.hpp"
RenderObject SizeChangedLayoutNotifier::createRenderObject(BuildContext context) {
    return _RenderSizeChangedWithCallback();
}

void _RenderSizeChangedWithCallback::performLayout() {
    super.performLayout();
    if (_oldSize != nullptr && size != _oldSize) {
        onLayoutChangedCallback();
    }
    _oldSize = size;
}

_RenderSizeChangedWithCallback::_RenderSizeChangedWithCallback(RenderBox child, VoidCallback onLayoutChangedCallback) {
    {
        assert(onLayoutChangedCallback != nullptr);
        super(child);
    }
}
