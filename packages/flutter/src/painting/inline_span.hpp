#ifndef PACKAGES_FLUTTER_SRC_PAINTING_INLINE_SPAN
#define PACKAGES_FLUTTER_SRC_PAINTING_INLINE_SPAN
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic_types.hpp"
#include "text_painter.hpp"
#include "text_span.hpp"
#include "text_style.hpp"


class AccumulatorCls : public ObjectCls {
public:

     AccumulatorCls(int _value);
    virtual int value();

    virtual void increment(int addend);

private:
    int _value;


};
using Accumulator = std::shared_ptr<AccumulatorCls>;

class InlineSpanSemanticsInformationCls : public ObjectCls {
public:
    static InlineSpanSemanticsInformation placeholder;

    String text;

    String semanticsLabel;

    GestureRecognizer recognizer;

    bool isPlaceholder;

    bool requiresOwnNode;

    List<StringAttribute> stringAttributes;


     InlineSpanSemanticsInformationCls(String text, bool isPlaceholder, GestureRecognizer recognizer, String semanticsLabel, List<StringAttribute> stringAttributes);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using InlineSpanSemanticsInformation = std::shared_ptr<InlineSpanSemanticsInformationCls>;
List<InlineSpanSemanticsInformation> combineSemanticsInfo(List<InlineSpanSemanticsInformation> infoList);


class InlineSpanCls : public DiagnosticableTreeCls {
public:
    TextStyle style;


     InlineSpanCls(TextStyle style);
    virtual void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);
    virtual bool visitChildren(InlineSpanVisitor visitor);
    virtual InlineSpan getSpanForPosition(TextPosition position);

    virtual InlineSpan getSpanForPositionVisitor(TextPosition position, Accumulator offset);
    virtual String toPlainText(bool includePlaceholders, bool includeSemanticsLabels);

    virtual List<InlineSpanSemanticsInformation> getSemanticsInformation();

    virtual void computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector);
    virtual void computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels);
    virtual int codeUnitAt(int index);

    virtual int codeUnitAtVisitor(int index, Accumulator offset);
    virtual bool debugAssertIsValid();

    virtual RenderComparison compareTo(InlineSpan other);
    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using InlineSpan = std::shared_ptr<InlineSpanCls>;


#endif