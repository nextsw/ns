#ifndef COMPARATORS_H
#define COMPARATORS_H
#include <memory>



const int _zero;

const int _upperCaseA;

const int _upperCaseZ;

const int _lowerCaseA;

const int _lowerCaseZ;

const int _asciiCaseBit;

bool equalsIgnoreAsciiCase(String a, String b);

int hashIgnoreAsciiCase(String string);

int compareAsciiUpperCase(String a, String b);

int compareAsciiLowerCase(String a, String b);

int compareNatural(String a, String b);

int compareAsciiLowerCaseNatural(String a, String b);

int compareAsciiUpperCaseNatural(String a, String b);

int _compareNaturally(String a, int aChar, String b, int bChar, int index);

int _compareNumerically(String a, int aChar, String b, int bChar, int index);

int _compareDigitCount(String a, String b, int i, int j);

bool _isDigit(int charCode);

bool _isNonZeroNumberSuffix(int index, String string);


#endif