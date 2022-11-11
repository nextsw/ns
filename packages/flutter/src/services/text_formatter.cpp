#include "text_formatter.hpp"
TextInputFormatter TextInputFormatterCls::withFunction(TextInputFormatFunction formatFunction) {
    return make<_SimpleTextInputFormatterCls>(formatFunction);
}

TextEditingValue _SimpleTextInputFormatterCls::formatEditUpdate(TextEditingValue oldValue, TextEditingValue newValue) {
    return formatFunction(oldValue, newValue);
}

_SimpleTextInputFormatterCls::_SimpleTextInputFormatterCls(TextInputFormatFunction formatFunction) {
    {
        assert(formatFunction != nullptr);
    }
}

_MutableTextRange _MutableTextRangeCls::fromComposingRange(TextRange range) {
    return range->isValid() && !range->isCollapsed()? make<_MutableTextRangeCls>(range->start, range->end) : nullptr;
}

_MutableTextRange _MutableTextRangeCls::fromTextSelection(TextSelection selection) {
    return selection->isValid()? make<_MutableTextRangeCls>(selection->baseOffset, selection->extentOffset) : nullptr;
}

TextEditingValue _TextEditingValueAccumulatorCls::finalize() {
    debugFinalized = true;
    _MutableTextRange selection = this->selection;
    _MutableTextRange composingRegion = this->composingRegion;
    return make<TextEditingValueCls>(stringBuffer->toString(), composingRegion == nullptr || composingRegion->base == composingRegion->extent? TextRangeCls::empty : make<TextRangeCls>(composingRegion->base, composingRegion->extent), selection == nullptr? TextSelectionCls->collapsed(-1) : make<TextSelectionCls>(selection->base, selection->extent, inputValue->selection->affinity, inputValue->selection->isDirectional));
}

_TextEditingValueAccumulatorCls::_TextEditingValueAccumulatorCls(TextEditingValue inputValue) {
    {
        selection = _MutableTextRangeCls->fromTextSelection(inputValue->selection);
        composingRegion = _MutableTextRangeCls->fromComposingRange(inputValue->composing);
    }
}

FilteringTextInputFormatterCls::FilteringTextInputFormatterCls(Pattern filterPattern, Unknown allow, String replacementString) {
    {
        assert(filterPattern != nullptr);
        assert(allow != nullptr);
        assert(replacementString != nullptr);
    }
}

void FilteringTextInputFormatterCls::allow(Pattern filterPattern, String replacementString)

void FilteringTextInputFormatterCls::deny(Pattern filterPattern, String replacementString)

TextEditingValue FilteringTextInputFormatterCls::formatEditUpdate(TextEditingValue oldValue, TextEditingValue newValue) {
    _TextEditingValueAccumulator formatState = make<_TextEditingValueAccumulatorCls>(newValue);
    assert(!formatState->debugFinalized);
    Iterable<Match> matches = filterPattern->allMatches(newValue->text);
    Match previousMatch;
    for (Match match : matches) {
        assert(match->end >= match->start);
        _processRegion(allow, previousMatch?->end() | 0, match->start, formatState);
        assert(!formatState->debugFinalized);
        _processRegion(!allow, match->start, match->end, formatState);
        assert(!formatState->debugFinalized);
        previousMatch = match;
    }
    _processRegion(allow, previousMatch?->end() | 0, newValue->text->length(), formatState);
    assert(!formatState->debugFinalized);
    return formatState->finalize();
}

void FilteringTextInputFormatterCls::_processRegion(bool isBannedRegion, int regionStart, int regionEnd, _TextEditingValueAccumulator state) {
    String replacementString = isBannedRegion? (regionStart == regionEnd? __s("") : this->replacementString) : state->inputValue->text->substring(regionStart, regionEnd);
    state->stringBuffer->write(replacementString);
    if (replacementString->length() == regionEnd - regionStart) {
        return;
    }
    InlineMethod;
    state->selection?->base += adjustIndex(state->inputValue->selection->baseOffset);
    state->selection?->extent += adjustIndex(state->inputValue->selection->extentOffset);
    state->composingRegion?->base += adjustIndex(state->inputValue->composing->start);
    state->composingRegion?->extent += adjustIndex(state->inputValue->composing->end);
}

LengthLimitingTextInputFormatterCls::LengthLimitingTextInputFormatterCls(int maxLength, MaxLengthEnforcement maxLengthEnforcement) {
    {
        assert(maxLength == nullptr || maxLength == -1 || maxLength > 0);
    }
}

MaxLengthEnforcement LengthLimitingTextInputFormatterCls::getDefaultMaxLengthEnforcement(TargetPlatform platform) {
    if (kIsWeb) {
        return MaxLengthEnforcementCls::truncateAfterCompositionEnds;
    } else {
        ;
    }
}

TextEditingValue LengthLimitingTextInputFormatterCls::truncate(TextEditingValue value, int maxLength) {
    CharacterRange iterator = make<CharacterRangeCls>(value->text);
    if (value->text->characters->length > maxLength) {
        iterator->expandNext(maxLength);
    }
    String truncated = iterator->current();
    return make<TextEditingValueCls>(truncated, value->selection->copyWith(math->min(value->selection->start, truncated->length()), math->min(value->selection->end, truncated->length())), !value->composing->isCollapsed() && truncated->length() > value->composing->start? make<TextRangeCls>(value->composing->start, math->min(value->composing->end, truncated->length())) : TextRangeCls::empty);
}

TextEditingValue LengthLimitingTextInputFormatterCls::formatEditUpdate(TextEditingValue oldValue, TextEditingValue newValue) {
    int maxLength = this->maxLength;
    if (maxLength == nullptr || maxLength == -1 || newValue->text->characters->length <= maxLength) {
        return newValue;
    }
    assert(maxLength > 0);
    ;
}
