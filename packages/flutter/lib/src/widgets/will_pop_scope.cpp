#include "will_pop_scope.hpp"
WillPopScopeCls::WillPopScopeCls(Widget child, Key key, WillPopCallback onWillPop) {
    {
        assert(child != nullptr);
    }
}

State<WillPopScope> WillPopScopeCls::createState() {
    return make<_WillPopScopeStateCls>();
}

void _WillPopScopeStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    if (widget()->onWillPop != nullptr) {
        _route?->removeScopedWillPopCallback(widget()->onWillPop!);
    }
    _route = ModalRouteCls->of(context());
    if (widget()->onWillPop != nullptr) {
        _route?->addScopedWillPopCallback(widget()->onWillPop!);
    }
}

void _WillPopScopeStateCls::didUpdateWidget(WillPopScope oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->onWillPop != oldWidget->onWillPop && _route != nullptr) {
        if (oldWidget->onWillPop != nullptr) {
            _route!->removeScopedWillPopCallback(oldWidget->onWillPop!);
        }
        if (widget()->onWillPop != nullptr) {
            _route!->addScopedWillPopCallback(widget()->onWillPop!);
        }
    }
}

void _WillPopScopeStateCls::dispose() {
    if (widget()->onWillPop != nullptr) {
        _route?->removeScopedWillPopCallback(widget()->onWillPop!);
    }
    super->dispose();
}

Widget _WillPopScopeStateCls::build(BuildContext context) {
    return widget()->child;
}
