#ifndef PACKAGES_FLUTTER_SRC_SERVICES_TEXT_EDITING
#define PACKAGES_FLUTTER_SRC_SERVICES_TEXT_EDITING
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>


class TextSelectionCls : public TextRangeCls {
public:
    int baseOffset;

    int extentOffset;

    TextAffinity affinity;

    bool isDirectional;


     TextSelectionCls(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional);

    virtual void  collapsed(TextAffinity affinity, int offset);

    virtual void  fromPosition(TextPosition position);

    virtual TextPosition base();

    virtual TextPosition extent();

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual TextSelection copyWith(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional);

    virtual TextSelection expandTo(TextPosition position, bool extentAtIndex);

    virtual TextSelection extendTo(TextPosition position);

private:

};
using TextSelection = std::shared_ptr<TextSelectionCls>;


#endif