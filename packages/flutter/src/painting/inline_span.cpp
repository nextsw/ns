#include "inline_span.hpp"
int AccumulatorCls::value() {
    return _value;
}

void AccumulatorCls::increment(int addend) {
    assert(addend >= 0);
    _value += addend;
}

InlineSpanSemanticsInformationCls::InlineSpanSemanticsInformationCls(String text, bool isPlaceholder, GestureRecognizer recognizer, String semanticsLabel, List<StringAttribute> stringAttributes) {
    {
        assert(text != nullptr);
        assert(isPlaceholder != nullptr);
        assert(isPlaceholder == false || (text == __s("\uFFFC") && semanticsLabel == nullptr && recognizer == nullptr));
        requiresOwnNode = isPlaceholder || recognizer != nullptr;
    }
}

bool InlineSpanSemanticsInformationCls::==(Object other) {
    return is<InlineSpanSemanticsInformation>(other) && other->text == text && other->semanticsLabel == semanticsLabel && other->recognizer == recognizer && other->isPlaceholder == isPlaceholder && <StringAttribute>listEquals(other->stringAttributes, stringAttributes);
}

int InlineSpanSemanticsInformationCls::hashCode() {
    return ObjectCls->hash(text, semanticsLabel, recognizer, isPlaceholder);
}

String InlineSpanSemanticsInformationCls::toString() {
    return __sf("%s{text: %s, semanticsLabel: %s, recognizer: %s}", objectRuntimeType(this, __s("InlineSpanSemanticsInformation")), text, semanticsLabel, recognizer);
}

List<InlineSpanSemanticsInformation> combineSemanticsInfo(List<InlineSpanSemanticsInformation> infoList) {
    List<InlineSpanSemanticsInformation> combined = makeList();
    String workingText = __s("");
    String workingLabel = __s("");
    List<StringAttribute> workingAttributes = makeList();
    for (InlineSpanSemanticsInformation info : infoList) {
        if (info->requiresOwnNode) {
            combined->add(make<InlineSpanSemanticsInformationCls>(workingText, workingLabel, workingAttributes));
            workingText = __s("");
            workingLabel = __s("");
            workingAttributes = makeList();
            combined->add(info);
        } else {
            workingText += info->text;
            String effectiveLabel = info->semanticsLabel | info->text;
            for (StringAttribute infoAttribute : info->stringAttributes) {
                workingAttributes->add(infoAttribute->copy(make<TextRangeCls>(infoAttribute->range->start + workingLabel->length(), infoAttribute->range->end + workingLabel->length())));
            }
            workingLabel += effectiveLabel;
        }
    }
    combined->add(make<InlineSpanSemanticsInformationCls>(workingText, workingLabel, workingAttributes));
    return combined;
}

InlineSpan InlineSpanCls::getSpanForPosition(TextPosition position) {
    assert(debugAssertIsValid());
    Accumulator offset = make<AccumulatorCls>();
    InlineSpan result;
    visitChildren([=] (InlineSpan span) {
        result = span->getSpanForPositionVisitor(position, offset);
        return result == nullptr;
    });
    return result;
}

String InlineSpanCls::toPlainText(bool includePlaceholders, bool includeSemanticsLabels) {
    StringBuffer buffer = make<StringBufferCls>();
    computeToPlainText(buffer, includeSemanticsLabels, includePlaceholders);
    return buffer->toString();
}

List<InlineSpanSemanticsInformation> InlineSpanCls::getSemanticsInformation() {
    List<InlineSpanSemanticsInformation> collector = makeList();
    computeSemanticsInformation(collector);
    return collector;
}

int InlineSpanCls::codeUnitAt(int index) {
    if ( < 0) {
        return nullptr;
    }
    Accumulator offset = make<AccumulatorCls>();
    int result;
    visitChildren([=] (InlineSpan span) {
        result = span->codeUnitAtVisitor(index, offset);
        return result == nullptr;
    });
    return result;
}

bool InlineSpanCls::debugAssertIsValid() {
    return true;
}

bool InlineSpanCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<InlineSpan>(other) && other->style == style;
}

int InlineSpanCls::hashCode() {
    return style->hashCode();
}

void InlineSpanCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->defaultDiagnosticsTreeStyle = DiagnosticsTreeStyleCls::whitespace;
    if (style != nullptr) {
        style!->debugFillProperties(properties);
    }
}
