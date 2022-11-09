#ifndef PACKAGES_FLUTTER_SRC_SERVICES_TEXT_LAYOUT_METRICS
#define PACKAGES_FLUTTER_SRC_SERVICES_TEXT_LAYOUT_METRICS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "text_editing.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "text_editing.hpp"


class TextLayoutMetricsCls : public ObjectCls {
public:

    static bool isWhitespace(int codeUnit);

    virtual TextSelection getLineAtOffset(TextPosition position);
    virtual TextRange getWordBoundary(TextPosition position);
    virtual TextPosition getTextPositionAbove(TextPosition position);
    virtual TextPosition getTextPositionBelow(TextPosition position);
private:

};
using TextLayoutMetrics = std::shared_ptr<TextLayoutMetricsCls>;


#endif