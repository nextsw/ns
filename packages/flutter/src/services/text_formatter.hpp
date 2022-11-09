#ifndef PACKAGES_FLUTTER_SRC_SERVICES_TEXT_FORMATTER
#define PACKAGES_FLUTTER_SRC_SERVICES_TEXT_FORMATTER
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "text_input.hpp"

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/characters/characters.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "text_input.hpp"


enum MaxLengthEnforcement{
    none,
    enforced,
    truncateAfterCompositionEnds,
} // end MaxLengthEnforcement

class TextInputFormatterCls : public ObjectCls {
public:

    virtual TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);
    static TextInputFormatter withFunction(TextInputFormatFunction formatFunction);

private:

};
using TextInputFormatter = std::shared_ptr<TextInputFormatterCls>;

class _SimpleTextInputFormatterCls : public TextInputFormatterCls {
public:
    TextInputFormatFunction formatFunction;


    virtual TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);

private:

     _SimpleTextInputFormatterCls(TextInputFormatFunction formatFunction);

};
using _SimpleTextInputFormatter = std::shared_ptr<_SimpleTextInputFormatterCls>;

class _MutableTextRangeCls : public ObjectCls {
public:
    int base;

    int extent;


    static _MutableTextRange fromComposingRange(TextRange range);

    static _MutableTextRange fromTextSelection(TextSelection selection);

private:

     _MutableTextRangeCls(int base, int extent);
};
using _MutableTextRange = std::shared_ptr<_MutableTextRangeCls>;

class _TextEditingValueAccumulatorCls : public ObjectCls {
public:
    TextEditingValue inputValue;

    StringBuffer stringBuffer;

    _MutableTextRange selection;

    _MutableTextRange composingRegion;

    bool debugFinalized;


    virtual TextEditingValue finalize();

private:

     _TextEditingValueAccumulatorCls(TextEditingValue inputValue);

};
using _TextEditingValueAccumulator = std::shared_ptr<_TextEditingValueAccumulatorCls>;

class FilteringTextInputFormatterCls : public TextInputFormatterCls {
public:
    Pattern filterPattern;

    bool allow;

    String replacementString;

    static TextInputFormatter singleLineFormatter;

    static TextInputFormatter digitsOnly;


     FilteringTextInputFormatterCls(bool allow, Pattern filterPattern, String replacementString);

    virtual void  allow(Pattern filterPattern, String replacementString);

    virtual void  deny(Pattern filterPattern, String replacementString);

    virtual TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);

private:

    virtual void _processRegion(bool isBannedRegion, int regionEnd, int regionStart, _TextEditingValueAccumulator state);

};
using FilteringTextInputFormatter = std::shared_ptr<FilteringTextInputFormatterCls>;

class LengthLimitingTextInputFormatterCls : public TextInputFormatterCls {
public:
    int maxLength;

    MaxLengthEnforcement maxLengthEnforcement;


     LengthLimitingTextInputFormatterCls(int maxLength, MaxLengthEnforcement maxLengthEnforcement);

    static MaxLengthEnforcement getDefaultMaxLengthEnforcement(TargetPlatform platform);

    static TextEditingValue truncate(int maxLength, TextEditingValue value);

    virtual TextEditingValue formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue);

private:

};
using LengthLimitingTextInputFormatter = std::shared_ptr<LengthLimitingTextInputFormatterCls>;


#endif