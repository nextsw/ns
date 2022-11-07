#include "autofill.hpp"
AutofillConfiguration::AutofillConfiguration(List<String> autofillHints, TextEditingValue currentEditingValue, String hintText, String uniqueIdentifier) {
    {
        this._(true, uniqueIdentifier, autofillHints, currentEditingValue, hintText);
    }
}

Map<String, dynamic> AutofillConfiguration::toJson() {
    return enabled?  : nullptr;
}

void AutofillConfiguration::_(List<String> autofillHints, TextEditingValue currentEditingValue, bool enabled, String hintText, String uniqueIdentifier)

Map<String, dynamic> _AutofillScopeTextInputConfiguration::toJson() {
    Map<String, dynamic> result = super.toJson();
    result["fields"] = allConfigurations.map().toList(false);
    return result;
}

_AutofillScopeTextInputConfiguration::_AutofillScopeTextInputConfiguration(Iterable<TextInputConfiguration> allConfigurations, TextInputConfiguration currentClientConfiguration) {
    {
        assert(allConfigurations != nullptr);
        assert(currentClientConfiguration != nullptr);
        super(currentClientConfiguration.inputType, currentClientConfiguration.obscureText, currentClientConfiguration.autocorrect, currentClientConfiguration.smartDashesType, currentClientConfiguration.smartQuotesType, currentClientConfiguration.enableSuggestions, currentClientConfiguration.inputAction, currentClientConfiguration.textCapitalization, currentClientConfiguration.keyboardAppearance, currentClientConfiguration.actionLabel, currentClientConfiguration.autofillConfiguration);
    }
}

TextInputConnection AutofillScopeMixin::attach(TextInputConfiguration configuration, TextInputClient trigger) {
    assert(trigger != nullptr);
    assert(!autofillClients.any(), "Every client in AutofillScope.autofillClients must enable autofill");
    TextInputConfiguration inputConfiguration = _AutofillScopeTextInputConfiguration(autofillClients.map(), configuration);
    return TextInput.attach(trigger, inputConfiguration);
}
