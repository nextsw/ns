#ifndef PACKAGES_FLUTTER_SRC_SERVICES_TEXT_EDITING_DELTA
#define PACKAGES_FLUTTER_SRC_SERVICES_TEXT_EDITING_DELTA
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "text_editing.hpp"
#include "text_input.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "text_editing.hpp"
#include "text_input.hpp"

TextAffinity _toTextAffinity(String affinity);

String _replace(int end, String originalText, String replacementText, int start);


class TextEditingDeltaCls : public ObjectCls {
public:
    String oldText;

    TextSelection selection;

    TextRange composing;


     TextEditingDeltaCls(TextRange composing, String oldText, TextSelection selection);

    virtual void  fromJSON(Map<String, dynamic> encoded);

    virtual TextEditingValue apply(TextEditingValue value);
private:

};
using TextEditingDelta = std::shared_ptr<TextEditingDeltaCls>;

class TextEditingDeltaInsertionCls : public TextEditingDeltaCls {
public:
    String textInserted;

    int insertionOffset;


     TextEditingDeltaInsertionCls(Unknown composing, int insertionOffset, Unknown oldText, Unknown selection, String textInserted);
    virtual TextEditingValue apply(TextEditingValue value);

private:

};
using TextEditingDeltaInsertion = std::shared_ptr<TextEditingDeltaInsertionCls>;

class TextEditingDeltaDeletionCls : public TextEditingDeltaCls {
public:
    TextRange deletedRange;


     TextEditingDeltaDeletionCls(Unknown composing, TextRange deletedRange, Unknown oldText, Unknown selection);
    virtual String textDeleted();

    virtual TextEditingValue apply(TextEditingValue value);

private:

};
using TextEditingDeltaDeletion = std::shared_ptr<TextEditingDeltaDeletionCls>;

class TextEditingDeltaReplacementCls : public TextEditingDeltaCls {
public:
    String replacementText;

    TextRange replacedRange;


     TextEditingDeltaReplacementCls(Unknown composing, Unknown oldText, TextRange replacedRange, String replacementText, Unknown selection);
    virtual String textReplaced();

    virtual TextEditingValue apply(TextEditingValue value);

private:

};
using TextEditingDeltaReplacement = std::shared_ptr<TextEditingDeltaReplacementCls>;

class TextEditingDeltaNonTextUpdateCls : public TextEditingDeltaCls {
public:

     TextEditingDeltaNonTextUpdateCls(Unknown composing, Unknown oldText, Unknown selection);
    virtual TextEditingValue apply(TextEditingValue value);

private:

};
using TextEditingDeltaNonTextUpdate = std::shared_ptr<TextEditingDeltaNonTextUpdateCls>;


#endif