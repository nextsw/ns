#ifndef TEXT_FORMATTER_H
#define TEXT_FORMATTER_H
#include <memory>
#include <flutter/foundation.hpp>
#include "text_input.hpp"

#include <math/math.hpp>
#include <characters/characters.hpp>
#include <flutter/foundation.hpp>
#include "text_input.hpp"



enum MaxLengthEnforcement{
    none,
    enforced,
    truncateAfterCompositionEnds,
} // end MaxLengthEnforcement

class TextInputFormatter {
public:

    TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);

    static TextInputFormatter withFunction(TextInputFormatFunction formatFunction);

private:

};

class _SimpleTextInputFormatter : TextInputFormatter {
public:
    TextInputFormatFunction formatFunction;


    TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);

private:

     _SimpleTextInputFormatter(TextInputFormatFunction formatFunction);

};

class _MutableTextRange {
public:
    int base;

    int extent;


    static _MutableTextRange fromComposingRange(TextRange range);

    static _MutableTextRange fromTextSelection(TextSelection selection);

private:

     _MutableTextRange(int base, int extent);

};

class _TextEditingValueAccumulator {
public:
    TextEditingValue inputValue;

    StringBuffer stringBuffer;

    _MutableTextRange selection;

    _MutableTextRange composingRegion;

    bool debugFinalized;


    TextEditingValue finalize();

private:

     _TextEditingValueAccumulator(TextEditingValue inputValue);

};

class FilteringTextInputFormatter : TextInputFormatter {
public:
    Pattern filterPattern;

    bool allow;

    String replacementString;

    static TextInputFormatter singleLineFormatter;

    static TextInputFormatter digitsOnly;


     FilteringTextInputFormatter(bool allow, Pattern filterPattern, String replacementString);

    void  allow(Pattern filterPattern, String replacementString);

    void  deny(Pattern filterPattern, String replacementString);

    TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);

private:

    void _processRegion(bool isBannedRegion, int regionEnd, int regionStart, _TextEditingValueAccumulator state);

};

class LengthLimitingTextInputFormatter : TextInputFormatter {
public:
    int maxLength;

    MaxLengthEnforcement maxLengthEnforcement;


     LengthLimitingTextInputFormatter(int maxLength, MaxLengthEnforcement maxLengthEnforcement);

    static MaxLengthEnforcement getDefaultMaxLengthEnforcement(TargetPlatform platform);

    static TextEditingValue truncate(int maxLength, TextEditingValue value);

    TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);

private:

};

#endif