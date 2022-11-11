#include "breaks.hpp"
Breaks BreaksCls::copy() {
    return make<BreaksCls>(base, cursor, end, state);
}

int BreaksCls::nextBreak() {
    while ( < end) {
        auto breakAt = cursor;
        auto char = base->codeUnitAt(cursor++);
        if (charValue & 0xFC00 != 0xD800) {
            state = move(state, low(charValue));
            if (state & stateNoBreak == 0) {
                return breakAt;
            }
            continue;
        }
        auto category = categoryControl;
        if ( < end) {
            auto nextChar = base->codeUnitAt(cursor);
            if (nextChar & 0xFC00 == 0xDC00) {
                category = high(charValue, nextChar);
                cursor++;
            }
        }
        state = move(state, category);
        if (state & stateNoBreak == 0) {
            return breakAt;
        }
    }
    state = move(state, categoryEoT);
    if (state & stateNoBreak == 0)     {
        return cursor;
    }
    return -1;
}

BackBreaks BackBreaksCls::copy() {
    return make<BackBreaksCls>(base, cursor, start, state);
}

int BackBreaksCls::nextBreak() {
    while (cursor > start) {
        auto breakAt = cursor;
        auto char = base->codeUnitAt(--cursor);
        if (charValue & 0xFC00 != 0xDC00) {
            state = moveBack(state, low(charValue));
            if (state >= stateLookaheadMin)             {
                state = _lookAhead(state);
            }
            if (state & stateNoBreak == 0) {
                return breakAt;
            }
            continue;
        }
        auto category = categoryControl;
        if (cursor >= start) {
            auto prevChar = base->codeUnitAt(cursor - 1);
            if (prevChar & 0xFC00 == 0xD800) {
                category = high(prevChar, charValue);
                cursor = 1;
            }
        }
        state = moveBack(state, category);
        if (state >= stateLookaheadMin)         {
            state = _lookAhead(state);
        }
        if (state & stateNoBreak == 0) {
            return breakAt;
        }
    }
    state = moveBack(state, categoryEoT);
    if (state >= stateLookaheadMin)     {
        state = _lookAhead(state);
    }
    if (state & stateNoBreak == 0)     {
        return cursor;
    }
    return -1;
}

int BackBreaksCls::_lookAhead(int state) {
    return lookAhead(base, start, cursor, state);
}

int lookAhead(String base, int cursor, int start, int state) {
    assert(state >= stateLookaheadMin);
    if (state == stateRegionalLookahead) {
        return lookAheadRegional(base, start, cursor);
    }
    if (state == stateZWJPictographicLookahead) {
        auto prevPic = lookAheadPictorgraphicExtend(base, start, cursor);
        if (prevPic >= 0)         {
            return stateZWJPictographic | stateNoBreak;
        }
        return stateExtend;
    }
    throw make<StateErrorCls>(__s("Unexpected state: ${state.toRadixString(16)}"));
}

int lookAheadRegional(String base, int cursor, int start) {
    auto count = 0;
    auto index = cursor;
    while (index - 2 >= start) {
        auto tail = base->codeUnitAt(index - 1);
        if (tail & 0xFC00 != 0xDC00)         {
            break;
        }
        auto lead = base->codeUnitAt(index - 2);
        if (lead & 0xFC00 != 0xD800)         {
            break;
        }
        auto category = high(lead, tail);
        if (category != categoryRegionalIndicator)         {
            break;
        }
        index = 2;
        count = 1;
    }
    if (count == 0) {
        return stateRegionalEven | stateNoBreak;
    } else {
        return stateRegionalOdd;
    }
}

int lookAheadPictorgraphicExtend(String base, int cursor, int start) {
    auto index = cursor;
    while (index > start) {
        auto char = base->codeUnitAt(--index);
        auto prevChar = 0;
        auto category = categoryControl;
        if (charValue & 0xFC00 != 0xDC00) {
            category = low(charValue);
        } else         {
            if (index > start && (prevChar = base->codeUnitAt(--index)) & 0xFC00 == 0xD800) {
            category = high(prevChar, charValue);
        } else {
            break;
        }
;
        }        if (category == categoryPictographic) {
            return index;
        }
        if (category != categoryExtend)         {
            break;
        }
    }
    return -1;
}

bool isGraphemeClusterBoundary(int end, int index, int start, String text) {
    assert(0 <= start);
    assert(start <= index);
    assert(index <= end);
    assert(end <= text->length());
    if ( < index &&  < end) {
        auto char = text->codeUnitAt(index);
        auto prevChar = text->codeUnitAt(index - 1);
        auto catAfter = categoryControl;
        if (charValue & 0xF800 != 0xD800) {
            catAfter = low(charValue);
        } else         {
            if (charValue & 0xFC00 == 0xD800) {
            if (index + 1 >= end)             {
                return true;
            }
            auto nextChar = text->codeUnitAt(index + 1);
            if (nextChar & 0xFC00 != 0xDC00)             {
                return true;
            }
            catAfter = high(charValue, nextChar);
        } else {
            return prevChar & 0xFC00 != 0xD800;
        }
;
        }        auto catBefore = categoryControl;
        if (prevChar & 0xFC00 != 0xDC00) {
            catBefore = low(prevChar);
            index = 1;
        } else {
            index = 2;
            if (start <= index) {
                auto prevPrevChar = text->codeUnitAt(index);
                if (prevPrevChar & 0xFC00 != 0xD800) {
                    return true;
                }
                catBefore = high(prevPrevChar, prevChar);
            } else {
                return true;
            }
        }
        auto state = moveBack(stateEoTNoBreak, catAfter);
        assert( < stateLookaheadMin);
        state = moveBack(state, catBefore);
        if (state >= stateLookaheadMin) {
            state = lookAhead(text, start, index, state);
        }
        return state & stateNoBreak == 0;
    }
    return start != end;
}

int previousBreak(int end, int index, int start, String text) {
    assert(0 <= start);
    assert(start <= index);
    assert(index <= end);
    assert(end <= text->length());
    if (index == start || index == end)     {
        return index;
    }
    auto indexBefore = index;
    auto nextChar = text->codeUnitAt(index);
    auto category = categoryControl;
    if (nextChar & 0xF800 != 0xD800) {
        category = low(nextChar);
    } else     {
        if (nextChar & 0xFC00 == 0xD800) {
        auto indexAfter = index + 1;
        if ( < end) {
            auto secondChar = text->codeUnitAt(indexAfter);
            if (secondChar & 0xFC00 == 0xDC00) {
                category = high(nextChar, secondChar);
            }
        }
    } else {
        auto prevChar = text->codeUnitAt(index - 1);
        if (prevChar & 0xFC00 == 0xD800) {
            category = high(prevChar, nextChar);
            indexBefore = 1;
        }
    }
;
    }    return make<BackBreaksCls>(text, indexBefore, start, moveBack(stateEoTNoBreak, category))->nextBreak();
}

int nextBreak(int end, int index, int start, String text) {
    assert(0 <= start);
    assert(start <= index);
    assert(index <= end);
    assert(end <= text->length());
    if (index == start || index == end)     {
        return index;
    }
    auto indexBefore = index - 1;
    auto prevChar = text->codeUnitAt(indexBefore);
    auto prevCategory = categoryControl;
    if (prevChar & 0xF800 != 0xD800) {
        prevCategory = low(prevChar);
    } else     {
        if (prevChar & 0xFC00 == 0xD800) {
        auto nextChar = text->codeUnitAt(index);
        if (nextChar & 0xFC00 == 0xDC00) {
            index = 1;
            if (index == end)             {
                return end;
            }
            prevCategory = high(prevChar, nextChar);
        }
    } else     {
        if (indexBefore > start) {
        auto secondCharIndex = indexBefore - 1;
        auto secondChar = text->codeUnitAt(secondCharIndex);
        if (secondChar & 0xFC00 == 0xD800) {
            indexBefore = secondCharIndex;
            prevCategory = high(secondChar, prevChar);
        }
    }
;
    };
    }    auto state = stateOther;
    if (prevCategory == categoryRegionalIndicator) {
        auto prevState = lookAheadRegional(text, start, indexBefore);
        if (prevState != stateRegionalOdd) {
            state = stateRegionalSingle;
        }
    } else     {
        if (prevCategory == categoryZWJ || prevCategory == categoryExtend) {
        auto prevPic = lookAheadPictorgraphicExtend(text, start, indexBefore);
        if (prevPic >= 0) {
            state = prevCategory == categoryZWJ? statePictographicZWJ : statePictographic;
        }
    } else {
        state = move(stateSoTNoBreak, prevCategory);
    }
;
    }    return make<BreaksCls>(text, index, text->length(), state)->nextBreak();
}
