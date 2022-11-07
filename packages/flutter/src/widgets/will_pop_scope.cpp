#include "will_pop_scope.hpp"
WillPopScope::WillPopScope(Widget child, Unknown, WillPopCallback onWillPop) {
    {
        assert(child != nullptr);
    }
}

State<WillPopScope> WillPopScope::createState() {
    return _WillPopScopeState();
}

void _WillPopScopeState::didChangeDependencies() {
    super.didChangeDependencies();
    if (widget.onWillPop != nullptr) {
        _route?.removeScopedWillPopCallback(widget.onWillPop!);
    }
    _route = ModalRoute.of(context);
    if (widget.onWillPop != nullptr) {
        _route?.addScopedWillPopCallback(widget.onWillPop!);
    }
}

void _WillPopScopeState::didUpdateWidget(WillPopScope oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.onWillPop != oldWidget.onWillPop && _route != nullptr) {
        if (oldWidget.onWillPop != nullptr) {
            _route!.removeScopedWillPopCallback(oldWidget.onWillPop!);
        }
        if (widget.onWillPop != nullptr) {
            _route!.addScopedWillPopCallback(widget.onWillPop!);
        }
    }
}

void _WillPopScopeState::dispose() {
    if (widget.onWillPop != nullptr) {
        _route?.removeScopedWillPopCallback(widget.onWillPop!);
    }
    super.dispose();
}

Widget _WillPopScopeState::build(BuildContext context) {
    return widget.child;
}
