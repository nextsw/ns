#include "text_formatter.hpp"
TextInputFormatter TextInputFormatter::withFunction(TextInputFormatFunction formatFunction) {
    return _SimpleTextInputFormatter(formatFunction);
}

TextEditingValue _SimpleTextInputFormatter::formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue) {
    return formatFunction(oldValue, newValue);
}

_SimpleTextInputFormatter::_SimpleTextInputFormatter(TextInputFormatFunction formatFunction) {
    {
        assert(formatFunction != nullptr);
    }
}

_MutableTextRange _MutableTextRange::fromComposingRange(TextRange range) {
    return range.isValid && !range.isCollapsed? _MutableTextRange(range.start, range.end) : nullptr;
}

_MutableTextRange _MutableTextRange::fromTextSelection(TextSelection selection) {
    return selection.isValid? _MutableTextRange(selection.baseOffset, selection.extentOffset) : nullptr;
}

TextEditingValue _TextEditingValueAccumulator::finalize() {
    debugFinalized = true;
    _MutableTextRange selection = this.selection;
    _MutableTextRange composingRegion = this.composingRegion;
    return TextEditingValue(stringBuffer.toString(), composingRegion == nullptr || composingRegion.base == composingRegion.extent? TextRange.empty : TextRange(composingRegion.base, composingRegion.extent), selection == nullptr? const TextSelection.collapsed(-1) : TextSelection(selection.base, selection.extent, inputValue.selection.affinity, inputValue.selection.isDirectional));
}

_TextEditingValueAccumulator::_TextEditingValueAccumulator(TextEditingValue inputValue) {
    {
        selection = _MutableTextRange.fromTextSelection(inputValue.selection);
        composingRegion = _MutableTextRange.fromComposingRange(inputValue.composing);
    }
}

FilteringTextInputFormatter::FilteringTextInputFormatter(bool allow, Pattern filterPattern, String replacementString) {
    {
        assert(filterPattern != nullptr);
        assert(allow != nullptr);
        assert(replacementString != nullptr);
    }
}

void FilteringTextInputFormatter::allow(Pattern filterPattern, String replacementString)

void FilteringTextInputFormatter::deny(Pattern filterPattern, String replacementString)

TextEditingValue FilteringTextInputFormatter::formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue) {
    _TextEditingValueAccumulator formatState = _TextEditingValueAccumulator(newValue);
    assert(!formatState.debugFinalized);
    Iterable<Match> matches = filterPattern.allMatches(newValue.text);
    Match previousMatch;
    for (Match match : matches) {
        assert(match.end >= match.start);
        _processRegion(allow, previousMatch?.end ?? 0, match.start, formatState);
        assert(!formatState.debugFinalized);
        _processRegion(!allow, match.start, match.end, formatState);
        assert(!formatState.debugFinalized);
        previousMatch = match;
    }
    _processRegion(allow, previousMatch?.end ?? 0, newValue.text.length, formatState);
    assert(!formatState.debugFinalized);
    return formatState.finalize();
}

void FilteringTextInputFormatter::_processRegion(bool isBannedRegion, int regionEnd, int regionStart, _TextEditingValueAccumulator state) {
    String replacementString = isBannedRegion? (regionStart == regionEnd? "" : this.replacementString) : state.inputValue.text.substring(regionStart, regionEnd);
    state.stringBuffer.write(replacementString);
    if (replacementString.length == regionEnd - regionStart) {
        return;
    }
    ;
    state.selection?.base = adjustIndex(state.inputValue.selection.baseOffset);
    state.selection?.extent = adjustIndex(state.inputValue.selection.extentOffset);
    state.composingRegion?.base = adjustIndex(state.inputValue.composing.start);
    state.composingRegion?.extent = adjustIndex(state.inputValue.composing.end);
}

LengthLimitingTextInputFormatter::LengthLimitingTextInputFormatter(int maxLength, MaxLengthEnforcement maxLengthEnforcement) {
    {
        assert(maxLength == nullptr || maxLength == -1 || maxLength > 0);
    }
}

MaxLengthEnforcement LengthLimitingTextInputFormatter::getDefaultMaxLengthEnforcement(TargetPlatform platform) {
    if (kIsWeb) {
        return MaxLengthEnforcement.truncateAfterCompositionEnds;
    } else {
        ;
    }
}

TextEditingValue LengthLimitingTextInputFormatter::truncate(int maxLength, TextEditingValue value) {
    CharacterRange iterator = CharacterRange(value.text);
    if (value.text.characters.length > maxLength) {
        iterator.expandNext(maxLength);
    }
    String truncated = iterator.current;
    return TextEditingValue(truncated, value.selection.copyWith(math.min(value.selection.start, truncated.length), math.min(value.selection.end, truncated.length)), !value.composing.isCollapsed && truncated.length > value.composing.start? TextRange(value.composing.start, math.min(value.composing.end, truncated.length)) : TextRange.empty);
}

TextEditingValue LengthLimitingTextInputFormatter::formatEditUpdate(TextEditingValue newValue, TextEditingValue oldValue) {
    int maxLength = this.maxLength;
    if (maxLength == nullptr || maxLength == -1 || newValue.text.characters.length <= maxLength) {
        return newValue;
    }
    assert(maxLength > 0);
    ;
}
