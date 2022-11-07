#ifndef TEXT_SPAN_H
#define TEXT_SPAN_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/services.hpp>
#include "basic_types.hpp"
#include "inline_span.hpp"
#include "text_painter.hpp"



class TextSpan : InlineSpan {
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


     TextSpan(List<InlineSpan> children, Locale locale, MouseCursor mouseCursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, GestureRecognizer recognizer, String semanticsLabel, bool spellOut, Unknown, String text);

    MouseCursor cursor();

    bool validForMouseTracker();

    void handleEvent(HitTestEntry entry, PointerEvent event);

    void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);

    bool visitChildren(InlineSpanVisitor visitor);

    InlineSpan getSpanForPositionVisitor(Accumulator offset, TextPosition position);

    void computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels);

    void computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector, Locale inheritedLocale, bool inheritedSpellOut);

    int codeUnitAtVisitor(int index, Accumulator offset);

    void describeSemantics(Accumulator offset, List<dynamic> semanticsElements, List<int> semanticsOffsets);

    bool debugAssertIsValid();

    RenderComparison compareTo(InlineSpan other);

    bool ==(Object other);

    int hashCode();

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

private:

};

#endif