#ifndef PACKAGES_FLUTTER_SRC_PAINTING_TEXT_SPAN
#define PACKAGES_FLUTTER_SRC_PAINTING_TEXT_SPAN
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic_types.hpp"
#include "inline_span.hpp"
#include "text_painter.hpp"


class TextSpanCls : public InlineSpanCls {
public:
    String text;

    List<InlineSpan> children;

    GestureRecognizer recognizer;

    MouseCursor mouseCursor;

    PointerEnterEventListener onEnter;

    PointerExitEventListener onExit;

    String semanticsLabel;

    Locale locale;

    bool spellOut;


     TextSpanCls(List<InlineSpan> children, Locale locale, MouseCursor mouseCursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, GestureRecognizer recognizer, String semanticsLabel, bool spellOut, TextStyle style, String text);

    virtual MouseCursor cursor();

    virtual bool validForMouseTracker();

    virtual void handleEvent(PointerEvent event, HitTestEntry<any> entry);

    virtual void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);

    virtual bool visitChildren(InlineSpanVisitor visitor);

    virtual InlineSpan getSpanForPositionVisitor(TextPosition position, Accumulator offset);

    virtual void computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels);

    virtual void computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector, Locale inheritedLocale, bool inheritedSpellOut);

    virtual int codeUnitAtVisitor(int index, Accumulator offset);

    virtual void describeSemantics(Accumulator offset, List<int> semanticsOffsets, List<Object> semanticsElements);

    virtual bool debugAssertIsValid();

    virtual RenderComparison compareTo(InlineSpan other);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:

};
using TextSpan = std::shared_ptr<TextSpanCls>;


#endif