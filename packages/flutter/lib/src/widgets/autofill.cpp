#include "autofill.hpp"
AutofillGroupCls::AutofillGroupCls(Widget child, Unknown key, AutofillContextAction onDisposeAction) {
    {
        assert(child != nullptr);
    }
}

AutofillGroupState AutofillGroupCls::of(BuildContext context) {
    _AutofillScope scope = context-><_AutofillScope>dependOnInheritedWidgetOfExactType();
    return scope?->_scope;
}

AutofillGroupState AutofillGroupCls::createState() {
    return make<AutofillGroupStateCls>();
}

AutofillClient AutofillGroupStateCls::getAutofillClient(String autofillId) {
    return _clients[autofillId];
}

Iterable<AutofillClient> AutofillGroupStateCls::autofillClients() {
    return _clients->values->where([=] (AutofillClient client)     {
        client->textInputConfiguration->autofillConfiguration->enabled;
    });
}

void AutofillGroupStateCls::register(AutofillClient client) {
    assert(client != nullptr);
    _clients->putIfAbsent(client->autofillId, [=] ()     {
        client;
    });
}

void AutofillGroupStateCls::unregister(String autofillId) {
    assert(autofillId != nullptr && _clients->containsKey(autofillId));
    _clients->remove(autofillId);
}

void AutofillGroupStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _isTopmostAutofillGroup = AutofillGroupCls->of(context) == nullptr;
}

Widget AutofillGroupStateCls::build(BuildContext context) {
    return make<_AutofillScopeCls>(this, widget->child);
}

void AutofillGroupStateCls::dispose() {
    super->dispose();
    if (!_isTopmostAutofillGroup || widget->onDisposeAction == nullptr) {
        return;
    }
    ;
}

AutofillGroup _AutofillScopeCls::client() {
    return _scope!->widget;
}

bool _AutofillScopeCls::updateShouldNotify(_AutofillScope old) {
    return _scope != old->_scope;
}

_AutofillScopeCls::_AutofillScopeCls(AutofillGroupState autofillScopeState, Unknown child) {
    {
        _scope = autofillScopeState;
    }
}
