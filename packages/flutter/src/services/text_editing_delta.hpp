#ifndef TEXT_EDITING_DELTA_H
#define TEXT_EDITING_DELTA_H
#include <memory>
#include <ui.hpp>
#include "text_editing.hpp"
#include "text_input.hpp"

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "text_editing.hpp"
#include "text_input.hpp"


TextAffinity _toTextAffinity(String affinity);

String _replace(int end, String originalText, String replacementText, int start);


class TextEditingDelta {
public:
    String oldText;

    TextSelection selection;

    TextRange composing;


     TextEditingDelta(TextRange composing, String oldText, TextSelection selection);

    void  fromJSON(Map<String, dynamic> encoded);

    TextEditingValue apply(TextEditingValue value);

private:

};

class TextEditingDeltaInsertion : TextEditingDelta {
public:
    String textInserted;

    int insertionOffset;


     TextEditingDeltaInsertion(Unknown, int insertionOffset, Unknown, Unknown, String textInserted);

    TextEditingValue apply(TextEditingValue value);

private:

};

class TextEditingDeltaDeletion : TextEditingDelta {
public:
    TextRange deletedRange;


     TextEditingDeltaDeletion(Unknown, TextRange deletedRange, Unknown, Unknown);

    String textDeleted();

    TextEditingValue apply(TextEditingValue value);

private:

};

class TextEditingDeltaReplacement : TextEditingDelta {
public:
    String replacementText;

    TextRange replacedRange;


     TextEditingDeltaReplacement(Unknown, Unknown, TextRange replacedRange, String replacementText, Unknown);

    String textReplaced();

    TextEditingValue apply(TextEditingValue value);

private:

};

class TextEditingDeltaNonTextUpdate : TextEditingDelta {
public:

     TextEditingDeltaNonTextUpdate(Unknown, Unknown, Unknown);

    TextEditingValue apply(TextEditingValue value);

private:

};

#endif