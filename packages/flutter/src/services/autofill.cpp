#include "autofill.hpp"
AutofillConfigurationCls::AutofillConfigurationCls(List<String> autofillHints, TextEditingValue currentEditingValue, String hintText, String uniqueIdentifier) {
    {
        this->_(true, uniqueIdentifier, autofillHints, currentEditingValue, hintText);
    }
}

Map<String, dynamic> AutofillConfigurationCls::toJson() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("uniqueIdentifier", uniqueIdentifier);map1.set("hints", autofillHints);map1.set("editingValue", currentEditingValue->toJSON());if (hintText != nullptr) {    map1.set("hintText", hintText);}return enabled? list1 : nullptr;
}

void AutofillConfigurationCls::_(List<String> autofillHints, TextEditingValue currentEditingValue, bool enabled, String hintText, String uniqueIdentifier)

Map<String, dynamic> _AutofillScopeTextInputConfigurationCls::toJson() {
    Map<String, dynamic> result = super->toJson();
    result["fields"] = allConfigurations->map([=] (TextInputConfiguration configuration)     {
        configuration->toJson();
    })->toList(false);
    return result;
}

_AutofillScopeTextInputConfigurationCls::_AutofillScopeTextInputConfigurationCls(Iterable<TextInputConfiguration> allConfigurations, TextInputConfiguration currentClientConfiguration) {
    {
        assert(allConfigurations != nullptr);
        assert(currentClientConfiguration != nullptr);
    }
}

TextInputConnection AutofillScopeMixinCls::attach(TextInputConfiguration configuration, TextInputClient trigger) {
    assert(trigger != nullptr);
    assert(!autofillClients->any([=] (AutofillClient client)     {
        !client->textInputConfiguration->autofillConfiguration->enabled;
    }), "Every client in AutofillScope.autofillClients must enable autofill");
    TextInputConfiguration inputConfiguration = make<_AutofillScopeTextInputConfigurationCls>(autofillClients->map([=] (AutofillClient client) {
    client->textInputConfiguration;
}), configuration);
    return TextInputCls->attach(trigger, inputConfiguration);
}
