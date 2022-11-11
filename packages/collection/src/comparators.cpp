#include "comparators.hpp"
bool equalsIgnoreAsciiCase(String a, String b) {
    if (a->length() != b->length())     {
        return false;
    }
    for (;  < a->length(); i++) {
        auto aChar = a->codeUnitAt(i);
        auto bChar = b->codeUnitAt(i);
        if (aChar == bChar)         {
            continue;
        }
        if (aChar ^ bChar != _asciiCaseBit)         {
            return false;
        }
        auto aCharLowerCase = aChar | _asciiCaseBit;
        if (_lowerCaseA <= aCharLowerCase && aCharLowerCase <= _lowerCaseZ) {
            continue;
        }
        return false;
    }
    return true;
}

int hashIgnoreAsciiCase(String stringValue) {
    auto hash = 0;
    for (;  < stringValue->length(); i++) {
        auto char = stringValue->codeUnitAt(i);
        if (_lowerCaseA <= char && char <= _lowerCaseZ)         {
            char = _asciiCaseBit;
        }
        hash = 0x1fffffff & (hash + char);
        hash = 0x1fffffff & (hash + ((0x0007ffff & hash) << 10));
        hash = 6;
    }
    hash = 0x1fffffff & (hash + ((0x03ffffff & hash) << 3));
    hash = 11;
    return 0x1fffffff & (hash + ((0x00003fff & hash) << 15));
}

int compareAsciiUpperCase(String a, String b) {
    auto defaultResult = 0;
    for (;  < a->length(); i++) {
        if (i >= b->length())         {
            return 1;
        }
        auto aChar = a->codeUnitAt(i);
        auto bChar = b->codeUnitAt(i);
        if (aChar == bChar)         {
            continue;
        }
        auto aUpperCase = aChar;
        auto bUpperCase = bChar;
        if (_lowerCaseA <= aChar && aChar <= _lowerCaseZ) {
            aUpperCase = _asciiCaseBit;
        }
        if (_lowerCaseA <= bChar && bChar <= _lowerCaseZ) {
            bUpperCase = _asciiCaseBit;
        }
        if (aUpperCase != bUpperCase)         {
            return (aUpperCase - bUpperCase)->sign();
        }
        if (defaultResult == 0)         {
            defaultResult = (aChar - bChar);
        }
    }
    if (b->length() > a->length())     {
        return -1;
    }
    return defaultResult->sign();
}

int compareAsciiLowerCase(String a, String b) {
    auto defaultResult = 0;
    for (;  < a->length(); i++) {
        if (i >= b->length())         {
            return 1;
        }
        auto aChar = a->codeUnitAt(i);
        auto bChar = b->codeUnitAt(i);
        if (aChar == bChar)         {
            continue;
        }
        auto aLowerCase = aChar;
        auto bLowerCase = bChar;
        if (_upperCaseA <= bChar && bChar <= _upperCaseZ) {
            bLowerCase = _asciiCaseBit;
        }
        if (_upperCaseA <= aChar && aChar <= _upperCaseZ) {
            aLowerCase = _asciiCaseBit;
        }
        if (aLowerCase != bLowerCase)         {
            return (aLowerCase - bLowerCase)->sign();
        }
        if (defaultResult == 0)         {
            defaultResult = aChar - bChar;
        }
    }
    if (b->length() > a->length())     {
        return -1;
    }
    return defaultResult->sign();
}

int compareNatural(String a, String b) {
    for (;  < a->length(); i++) {
        if (i >= b->length())         {
            return 1;
        }
        auto aChar = a->codeUnitAt(i);
        auto bChar = b->codeUnitAt(i);
        if (aChar != bChar) {
            return _compareNaturally(a, b, i, aChar, bChar);
        }
    }
    if (b->length() > a->length())     {
        return -1;
    }
    return 0;
}

int compareAsciiLowerCaseNatural(String a, String b) {
    auto defaultResult = 0;
    for (;  < a->length(); i++) {
        if (i >= b->length())         {
            return 1;
        }
        auto aChar = a->codeUnitAt(i);
        auto bChar = b->codeUnitAt(i);
        if (aChar == bChar)         {
            continue;
        }
        auto aLowerCase = aChar;
        auto bLowerCase = bChar;
        if (_upperCaseA <= aChar && aChar <= _upperCaseZ) {
            aLowerCase = _asciiCaseBit;
        }
        if (_upperCaseA <= bChar && bChar <= _upperCaseZ) {
            bLowerCase = _asciiCaseBit;
        }
        if (aLowerCase != bLowerCase) {
            return _compareNaturally(a, b, i, aLowerCase, bLowerCase);
        }
        if (defaultResult == 0)         {
            defaultResult = aChar - bChar;
        }
    }
    if (b->length() > a->length())     {
        return -1;
    }
    return defaultResult->sign();
}

int compareAsciiUpperCaseNatural(String a, String b) {
    auto defaultResult = 0;
    for (;  < a->length(); i++) {
        if (i >= b->length())         {
            return 1;
        }
        auto aChar = a->codeUnitAt(i);
        auto bChar = b->codeUnitAt(i);
        if (aChar == bChar)         {
            continue;
        }
        auto aUpperCase = aChar;
        auto bUpperCase = bChar;
        if (_lowerCaseA <= aChar && aChar <= _lowerCaseZ) {
            aUpperCase = _asciiCaseBit;
        }
        if (_lowerCaseA <= bChar && bChar <= _lowerCaseZ) {
            bUpperCase = _asciiCaseBit;
        }
        if (aUpperCase != bUpperCase) {
            return _compareNaturally(a, b, i, aUpperCase, bUpperCase);
        }
        if (defaultResult == 0)         {
            defaultResult = aChar - bChar;
        }
    }
    if (b->length() > a->length())     {
        return -1;
    }
    return defaultResult->sign();
}

int _compareNaturally(String a, int aChar, String b, int bChar, int index) {
    assert(aChar != bChar);
    auto aIsDigit = _isDigit(aChar);
    auto bIsDigit = _isDigit(bChar);
    if (aIsDigit) {
        if (bIsDigit) {
            return _compareNumerically(a, b, aChar, bChar, index);
        } else         {
            if (index > 0 && _isDigit(a->codeUnitAt(index - 1))) {
            return 1;
        }
;
        }    } else     {
        if (bIsDigit && index > 0 && _isDigit(b->codeUnitAt(index - 1))) {
        return -1;
    }
;
    }    return (aChar - bChar)->sign();
}

int _compareNumerically(String a, int aChar, String b, int bChar, int index) {
    if (_isNonZeroNumberSuffix(a, index)) {
        auto result = _compareDigitCount(a, b, index, index);
        if (result != 0)         {
            return result;
        }
        return (aChar - bChar)->sign();
    }
    auto aIndex = index;
    auto bIndex = index;
    if (aChar == _zero) {
        do {
            aIndex++;
            if (aIndex == a->length())             {
                return -1;
            }
            aChar = a->codeUnitAt(aIndex);
        } while (aChar == _zero);
        if (!_isDigit(aChar))         {
            return -1;
        }
    } else     {
        if (bChar == _zero) {
        do {
            bIndex++;
            if (bIndex == b->length())             {
                return 1;
            }
            bChar = b->codeUnitAt(bIndex);
        } while (bChar == _zero);
        if (!_isDigit(bChar))         {
            return 1;
        }
    }
;
    }    if (aChar != bChar) {
        auto result = _compareDigitCount(a, b, aIndex, bIndex);
        if (result != 0)         {
            return result;
        }
        return (aChar - bChar)->sign();
    }
    while (true) {
        auto aIsDigit = false;
        auto bIsDigit = false;
        aChar = 0;
        bChar = 0;
        if (++ < a->length()) {
            aChar = a->codeUnitAt(aIndex);
            aIsDigit = _isDigit(aChar);
        }
        if (++ < b->length()) {
            bChar = b->codeUnitAt(bIndex);
            bIsDigit = _isDigit(bChar);
        }
        if (aIsDigit) {
            if (bIsDigit) {
                if (aChar == bChar)                 {
                    continue;
                }
                                break;
            }
            return 1;
        } else         {
            if (bIsDigit) {
            return -1;
        } else {
            return (aIndex - bIndex)->sign();
        }
;
        }    }
    auto result = _compareDigitCount(a, b, aIndex, bIndex);
    if (result != 0)     {
        return result;
    }
    return (aChar - bChar)->sign();
}

int _compareDigitCount(String a, String b, int i, int j) {
    while (++ < a->length()) {
        auto aIsDigit = _isDigit(a->codeUnitAt(i));
        if (++j == b->length())         {
            return aIsDigit? 1 : 0;
        }
        auto bIsDigit = _isDigit(b->codeUnitAt(j));
        if (aIsDigit) {
            if (bIsDigit)             {
                continue;
            }
            return 1;
        } else         {
            if (bIsDigit) {
            return -1;
        } else {
            return 0;
        }
;
        }    }
    if (++ < b->length() && _isDigit(b->codeUnitAt(j))) {
        return -1;
    }
    return 0;
}

bool _isDigit(int charCode) {
    return (charCode ^ _zero) <= 9;
}

bool _isNonZeroNumberSuffix(int index, String stringValue) {
    while (--index >= 0) {
        auto char = stringValue->codeUnitAt(index);
        if (char != _zero)         {
            return _isDigit(char);
        }
    }
    return false;
}
