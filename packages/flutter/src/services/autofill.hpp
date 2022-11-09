#ifndef PACKAGES_FLUTTER_SRC_SERVICES_AUTOFILL
#define PACKAGES_FLUTTER_SRC_SERVICES_AUTOFILL
#include <base.hpp>
#include "text_input.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "text_input.hpp"


class AutofillHintsCls : public ObjectCls {
public:
    static String addressCity;

    static String addressCityAndState;

    static String addressState;

    static String birthday;

    static String birthdayDay;

    static String birthdayMonth;

    static String birthdayYear;

    static String countryCode;

    static String countryName;

    static String creditCardExpirationDate;

    static String creditCardExpirationDay;

    static String creditCardExpirationMonth;

    static String creditCardExpirationYear;

    static String creditCardFamilyName;

    static String creditCardGivenName;

    static String creditCardMiddleName;

    static String creditCardName;

    static String creditCardNumber;

    static String creditCardSecurityCode;

    static String creditCardType;

    static String email;

    static String familyName;

    static String fullStreetAddress;

    static String gender;

    static String givenName;

    static String impp;

    static String jobTitle;

    static String language;

    static String location;

    static String middleInitial;

    static String middleName;

    static String name;

    static String namePrefix;

    static String nameSuffix;

    static String newPassword;

    static String newUsername;

    static String nickname;

    static String oneTimeCode;

    static String organizationName;

    static String password;

    static String photo;

    static String postalAddress;

    static String postalAddressExtended;

    static String postalAddressExtendedPostalCode;

    static String postalCode;

    static String streetAddressLevel1;

    static String streetAddressLevel2;

    static String streetAddressLevel3;

    static String streetAddressLevel4;

    static String streetAddressLine1;

    static String streetAddressLine2;

    static String streetAddressLine3;

    static String sublocality;

    static String telephoneNumber;

    static String telephoneNumberAreaCode;

    static String telephoneNumberCountryCode;

    static String telephoneNumberDevice;

    static String telephoneNumberExtension;

    static String telephoneNumberLocal;

    static String telephoneNumberLocalPrefix;

    static String telephoneNumberLocalSuffix;

    static String telephoneNumberNational;

    static String transactionAmount;

    static String transactionCurrency;

    static String url;

    static String username;


private:

    virtual void  _();
};
using AutofillHints = std::shared_ptr<AutofillHintsCls>;

class AutofillConfigurationCls : public ObjectCls {
public:
    static AutofillConfiguration disabled;

    bool enabled;

    String uniqueIdentifier;

    List<String> autofillHints;

    TextEditingValue currentEditingValue;

    String hintText;


     AutofillConfigurationCls(List<String> autofillHints, TextEditingValue currentEditingValue, String hintText, String uniqueIdentifier);

    virtual Map<String, dynamic> toJson();

private:

    virtual void  _(List<String> autofillHints, TextEditingValue currentEditingValue, bool enabled, String hintText, String uniqueIdentifier);

};
using AutofillConfiguration = std::shared_ptr<AutofillConfigurationCls>;

class AutofillClientCls : public ObjectCls {
public:

    virtual String autofillId();
    virtual TextInputConfiguration textInputConfiguration();
    virtual void autofill(TextEditingValue newEditingValue);
private:

};
using AutofillClient = std::shared_ptr<AutofillClientCls>;

class AutofillScopeCls : public ObjectCls {
public:

    virtual AutofillClient getAutofillClient(String autofillId);
    virtual Iterable<AutofillClient> autofillClients();
    virtual TextInputConnection attach(TextInputConfiguration configuration, TextInputClient trigger);
private:

};
using AutofillScope = std::shared_ptr<AutofillScopeCls>;

class _AutofillScopeTextInputConfigurationCls : public TextInputConfigurationCls {
public:
    Iterable<TextInputConfiguration> allConfigurations;


    virtual Map<String, dynamic> toJson();

private:

     _AutofillScopeTextInputConfigurationCls(Iterable<TextInputConfiguration> allConfigurations, TextInputConfiguration currentClientConfiguration);

};
using _AutofillScopeTextInputConfiguration = std::shared_ptr<_AutofillScopeTextInputConfigurationCls>;

class AutofillScopeMixinCls : public ObjectCls {
public:

    virtual TextInputConnection attach(TextInputConfiguration configuration, TextInputClient trigger);

private:

};
using AutofillScopeMixin = std::shared_ptr<AutofillScopeMixinCls>;


#endif