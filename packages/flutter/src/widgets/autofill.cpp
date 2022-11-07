#include "autofill.hpp"
AutofillGroup::AutofillGroup(Widget child, Unknown, AutofillContextAction onDisposeAction) {
    {
        assert(child != nullptr);
    }
}

AutofillGroupState AutofillGroup::of(BuildContext context) {
    _AutofillScope scope = context.<_AutofillScope>dependOnInheritedWidgetOfExactType();
    return scope?._scope;
}

AutofillGroupState AutofillGroup::createState() {
    return AutofillGroupState();
}

AutofillClient AutofillGroupState::getAutofillClient(String autofillId) {
    return _clients[autofillId];
}

Iterable<AutofillClient> AutofillGroupState::autofillClients() {
    return _clients.values.where();
}

void AutofillGroupState::register(AutofillClient client) {
    assert(client != nullptr);
    _clients.putIfAbsent(client.autofillId, );
}

void AutofillGroupState::unregister(String autofillId) {
    assert(autofillId != nullptr && _clients.containsKey(autofillId));
    _clients.remove(autofillId);
}

void AutofillGroupState::didChangeDependencies() {
    super.didChangeDependencies();
    _isTopmostAutofillGroup = AutofillGroup.of(context) == nullptr;
}

Widget AutofillGroupState::build(BuildContext context) {
    return _AutofillScope(this, widget.child);
}

void AutofillGroupState::dispose() {
    super.dispose();
    if (!_isTopmostAutofillGroup || widget.onDisposeAction == nullptr) {
        return;
    }
    ;
}

AutofillGroup _AutofillScope::client() {
    return _scope!.widget;
}

bool _AutofillScope::updateShouldNotify(_AutofillScope old) {
    return _scope != old._scope;
}

_AutofillScope::_AutofillScope(AutofillGroupState autofillScopeState, Unknown) {
    {
        _scope = autofillScopeState;
    }
}
