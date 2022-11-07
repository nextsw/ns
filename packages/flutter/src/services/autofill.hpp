#ifndef AUTOFILL_H
#define AUTOFILL_H
#include <memory>
#include "text_input.hpp"

#include <flutter/foundation.hpp>
#include "text_input.hpp"



class AutofillHints {
public:
    static const String addressCity;

    static const String addressCityAndState;

    static const String addressState;

    static const String birthday;

    static const String birthdayDay;

    static const String birthdayMonth;

    static const String birthdayYear;

    static const String countryCode;

    static const String countryName;

    static const String creditCardExpirationDate;

    static const String creditCardExpirationDay;

    static const String creditCardExpirationMonth;

    static const String creditCardExpirationYear;

    static const String creditCardFamilyName;

    static const String creditCardGivenName;

    static const String creditCardMiddleName;

    static const String creditCardName;

    static const String creditCardNumber;

    static const String creditCardSecurityCode;

    static const String creditCardType;

    static const String email;

    static const String familyName;

    static const String fullStreetAddress;

    static const String gender;

    static const String givenName;

    static const String impp;

    static const String jobTitle;

    static const String language;

    static const String location;

    static const String middleInitial;

    static const String middleName;

    static const String name;

    static const String namePrefix;

    static const String nameSuffix;

    static const String newPassword;

    static const String newUsername;

    static const String nickname;

    static const String oneTimeCode;

    static const String organizationName;

    static const String password;

    static const String photo;

    static const String postalAddress;

    static const String postalAddressExtended;

    static const String postalAddressExtendedPostalCode;

    static const String postalCode;

    static const String streetAddressLevel1;

    static const String streetAddressLevel2;

    static const String streetAddressLevel3;

    static const String streetAddressLevel4;

    static const String streetAddressLine1;

    static const String streetAddressLine2;

    static const String streetAddressLine3;

    static const String sublocality;

    static const String telephoneNumber;

    static const String telephoneNumberAreaCode;

    static const String telephoneNumberCountryCode;

    static const String telephoneNumberDevice;

    static const String telephoneNumberExtension;

    static const String telephoneNumberLocal;

    static const String telephoneNumberLocalPrefix;

    static const String telephoneNumberLocalSuffix;

    static const String telephoneNumberNational;

    static const String transactionAmount;

    static const String transactionCurrency;

    static const String url;

    static const String username;


private:

    void  _();

};

class AutofillConfiguration {
public:
    static const AutofillConfiguration disabled;

    bool enabled;

    String uniqueIdentifier;

    List<String> autofillHints;

    TextEditingValue currentEditingValue;

    String hintText;


     AutofillConfiguration(List<String> autofillHints, TextEditingValue currentEditingValue, String hintText, String uniqueIdentifier);

    Map<String, dynamic> toJson();

private:

    void  _(List<String> autofillHints, TextEditingValue currentEditingValue, bool enabled, String hintText, String uniqueIdentifier);

};

class AutofillClient {
public:

    String autofillId();

    TextInputConfiguration textInputConfiguration();

    void autofill(TextEditingValue newEditingValue);

private:

};

class AutofillScope {
public:

    AutofillClient getAutofillClient(String autofillId);

    Iterable<AutofillClient> autofillClients();

    TextInputConnection attach(TextInputConfiguration configuration, TextInputClient trigger);

private:

};

class _AutofillScopeTextInputConfiguration : TextInputConfiguration {
public:
    Iterable<TextInputConfiguration> allConfigurations;


    Map<String, dynamic> toJson();

private:

     _AutofillScopeTextInputConfiguration(Iterable<TextInputConfiguration> allConfigurations, TextInputConfiguration currentClientConfiguration);

};

class AutofillScopeMixin {
public:

    TextInputConnection attach(TextInputConfiguration configuration, TextInputClient trigger);

private:

};

#endif