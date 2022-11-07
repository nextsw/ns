#ifndef INLINE_SPAN_H
#define INLINE_SPAN_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "basic_types.hpp"
#include "text_painter.hpp"
#include "text_span.hpp"
#include "text_style.hpp"



class Accumulator {
public:

     Accumulator(int _value);

    int value();

    void increment(int addend);

private:
    int _value;


};

class InlineSpanSemanticsInformation {
public:
    static const InlineSpanSemanticsInformation placeholder;

    String text;

    String semanticsLabel;

    GestureRecognizer recognizer;

    bool isPlaceholder;

    bool requiresOwnNode;

    List<StringAttribute> stringAttributes;


     InlineSpanSemanticsInformation(bool isPlaceholder, GestureRecognizer recognizer, String semanticsLabel, List<StringAttribute> stringAttributes, String text);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};
List<InlineSpanSemanticsInformation> combineSemanticsInfo(List<InlineSpanSemanticsInformation> infoList);


class InlineSpan : DiagnosticableTree {
public:
    TextStyle style;


     InlineSpan(TextStyle style);

    void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);

    bool visitChildren(InlineSpanVisitor visitor);

    InlineSpan getSpanForPosition(TextPosition position);

    InlineSpan getSpanForPositionVisitor(Accumulator offset, TextPosition position);

    String toPlainText(bool includePlaceholders, bool includeSemanticsLabels);

    List<InlineSpanSemanticsInformation> getSemanticsInformation();

    void computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector);

    void computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels);

    int codeUnitAt(int index);

    int codeUnitAtVisitor(int index, Accumulator offset);

    bool debugAssertIsValid();

    RenderComparison compareTo(InlineSpan other);

    bool ==(Object other);

    int hashCode();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif