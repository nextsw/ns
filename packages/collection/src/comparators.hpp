#ifndef PACKAGES_COLLECTION_SRC_COMPARATORS
#define PACKAGES_COLLECTION_SRC_COMPARATORS
#include <base.hpp>

#include <dart/core/core.hpp>

int _zero;

int _upperCaseA;

int _upperCaseZ;

int _lowerCaseA;

int _lowerCaseZ;

int _asciiCaseBit;

bool equalsIgnoreAsciiCase(String a, String b);

int hashIgnoreAsciiCase(String stringValue);

int compareAsciiUpperCase(String a, String b);

int compareAsciiLowerCase(String a, String b);

int compareNatural(String a, String b);

int compareAsciiLowerCaseNatural(String a, String b);

int compareAsciiUpperCaseNatural(String a, String b);

int _compareNaturally(String a, int aChar, String b, int bChar, int index);

int _compareNumerically(String a, int aChar, String b, int bChar, int index);

int _compareDigitCount(String a, String b, int i, int j);

bool _isDigit(int charCode);

bool _isNonZeroNumberSuffix(int index, String stringValue);



#endif