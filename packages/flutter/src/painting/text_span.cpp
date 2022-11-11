#include "text_span.hpp"
TextSpanCls::TextSpanCls(List<InlineSpan> children, Locale locale, MouseCursor mouseCursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, GestureRecognizer recognizer, String semanticsLabel, bool spellOut, TextStyle style, String text) {
    {
        mouseCursor = mouseCursor | (recognizer == nullptr? MouseCursorCls::defer : SystemMouseCursorsCls::click);
        assert(!(text == nullptr && semanticsLabel != nullptr));
    }
}

MouseCursor TextSpanCls::cursor() {
    return mouseCursor;
}

bool TextSpanCls::validForMouseTracker() {
    return true;
}

void TextSpanCls::handleEvent(PointerEvent event, HitTestEntry entry) {
    if (is<PointerDownEvent>(event)) {
        recognizer?->addPointer(as<PointerDownEventCls>(event));
    }
}

void TextSpanCls::build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor) {
    assert(debugAssertIsValid());
    bool hasStyle = style != nullptr;
    if (hasStyle) {
        builder->pushStyle(style!->getTextStyle(textScaleFactor));
    }
    if (text != nullptr) {
        try {
            builder->addText(text!);
        } catch (ArgumentError exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("painting library"), make<ErrorDescriptionCls>(__s("while building a TextSpan"))));
            builder->addText(__s("\uFFFD"));
        };
    }
    if (children != nullptr) {
        for (InlineSpan child : children!) {
            assert(child != nullptr);
            child->build(builder, textScaleFactor, dimensions);
        }
    }
    if (hasStyle) {
        builder->pop();
    }
}

bool TextSpanCls::visitChildren(InlineSpanVisitor visitor) {
    if (text != nullptr) {
        if (!visitor(this)) {
            return false;
        }
    }
    if (children != nullptr) {
        for (InlineSpan child : children!) {
            if (!child->visitChildren(visitor)) {
                return false;
            }
        }
    }
    return true;
}

InlineSpan TextSpanCls::getSpanForPositionVisitor(TextPosition position, Accumulator offset) {
    if (text == nullptr) {
        return nullptr;
    }
    TextAffinity affinity = position->affinity;
    int targetOffset = position->offset;
    int endOffset = offset->value() + text!->length();
    if (offset->value() == targetOffset && affinity == TextAffinityCls::downstream || offset->value() < targetOffset &&  < endOffset || endOffset == targetOffset && affinity == TextAffinityCls::upstream) {
        return this;
    }
    offset->increment(text!->length());
    return nullptr;
}

void TextSpanCls::computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels) {
    assert(debugAssertIsValid());
    if (semanticsLabel != nullptr && includeSemanticsLabels) {
        buffer->write(semanticsLabel);
    } else {
        if (text != nullptr) {
        buffer->write(text);
    }
;
    }    if (children != nullptr) {
        for (InlineSpan child : children!) {
            child->computeToPlainText(buffer, includeSemanticsLabels, includePlaceholders);
        }
    }
}

void TextSpanCls::computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector, Locale inheritedLocale, bool inheritedSpellOut) {
    assert(debugAssertIsValid());
    Locale effectiveLocale = locale | inheritedLocale;
    bool effectiveSpellOut = spellOut | inheritedSpellOut;
    if (text != nullptr) {
        int textLength = semanticsLabel?->length() | text!->length();
            List<StringAttribute> list1 = make<ListCls<>>();    if (effectiveSpellOut && textLength > 0) {        list1.add(ArrayItem);    }if (effectiveLocale != nullptr && textLength > 0) {        list1.add(ArrayItem);    }collector->add(make<InlineSpanSemanticsInformationCls>(text!, list1, semanticsLabel, recognizer));
    }
    if (children != nullptr) {
        for (InlineSpan child : children!) {
            if (is<TextSpan>(child)) {
                as<TextSpanCls>(child)->computeSemanticsInformation(collector, effectiveLocale, effectiveSpellOut);
            } else {
                child->computeSemanticsInformation(collector);
            }
        }
    }
}

int TextSpanCls::codeUnitAtVisitor(int index, Accumulator offset) {
    if (text == nullptr) {
        return nullptr;
    }
    if (index - offset->value() < text!->length()) {
        return text!->codeUnitAt(index - offset->value());
    }
    offset->increment(text!->length());
    return nullptr;
}

void TextSpanCls::describeSemantics(Accumulator offset, List<int> semanticsOffsets, List<dynamic> semanticsElements) {
    if (recognizer != nullptr && (is<TapGestureRecognizer>(recognizer) || is<LongPressGestureRecognizer>(recognizer))) {
        int length = semanticsLabel?->length() | text!->length();
        semanticsOffsets->add(offset->value());
        semanticsOffsets->add(offset->value() + length);
        semanticsElements->add(recognizer);
    }
    offset->increment(text != nullptr? text!->length() : 0);
}

bool TextSpanCls::debugAssertIsValid() {
    assert([=] () {
        if (children != nullptr) {
            for (InlineSpan child : children!) {
                if (child == nullptr) {
                    throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
                }
                assert(child->debugAssertIsValid());
            }
        }
        return true;
    }());
    return super->debugAssertIsValid();
}

RenderComparison TextSpanCls::compareTo(InlineSpan other) {
    if (identical(this, other)) {
        return RenderComparisonCls::identical;
    }
    if (other->runtimeType != runtimeType) {
        return RenderComparisonCls::layout;
    }
    TextSpan textSpan = as<TextSpan>(other);
    if (textSpan->text != text || children?->length() != textSpan->children?->length || (style == nullptr) != (textSpan->style == nullptr)) {
        return RenderComparisonCls::layout;
    }
    RenderComparison result = recognizer == textSpan->recognizer? RenderComparisonCls::identical : RenderComparisonCls::metadata;
    if (style != nullptr) {
        RenderComparison candidate = style!->compareTo(textSpan->style!);
        if (candidate->index > result->index) {
            result = candidate;
        }
        if (result == RenderComparisonCls::layout) {
            return result;
        }
    }
    if (children != nullptr) {
        for (;  < children!->length(); index += 1) {
            RenderComparison candidate = children![index]->compareTo(textSpan->children![index]);
            if (candidate->index > result->index) {
                result = candidate;
            }
            if (result == RenderComparisonCls::layout) {
                return result;
            }
        }
    }
    return result;
}

bool TextSpanCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    if (super != other) {
        return false;
    }
    return is<TextSpan>(other) && other->text == text && other->recognizer == recognizer && other->semanticsLabel == semanticsLabel && onEnter == other->onEnter && onExit == other->onExit && mouseCursor == other->mouseCursor && <InlineSpan>listEquals(other->children, children);
}

int TextSpanCls::hashCode() {
    return ObjectCls->hash(super->hashCode(), text, recognizer, semanticsLabel, onEnter, onExit, mouseCursor, children == nullptr? nullptr : ObjectCls->hashAll(children!));
}

String TextSpanCls::toStringShort() {
    return objectRuntimeType(this, __s("TextSpan"));
}

void TextSpanCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("text"), text, false, nullptr));
    if (style == nullptr && text == nullptr && children == nullptr) {
        properties->add(DiagnosticsNodeCls->message(__s("(empty)")));
    }
    properties->add(<GestureRecognizer>make<DiagnosticsPropertyCls>(__s("recognizer"), recognizer, recognizer?->runtimeType->toString(), nullptr));
    Map<String, std::function<void ()>> map1 = make<MapCls<>>();map1.set(__s("enter"), onEnter);map1.set(__s("exit"), onExit);properties->add(<std::function<void ()>>make<FlagsSummaryCls>(__s("callbacks"), list1));
    properties->add(<MouseCursor>make<DiagnosticsPropertyCls>(__s("mouseCursor"), cursor(), MouseCursorCls::defer));
    if (semanticsLabel != nullptr) {
        properties->add(make<StringPropertyCls>(__s("semanticsLabel"), semanticsLabel));
    }
}

List<DiagnosticsNode> TextSpanCls::debugDescribeChildren() {
    if (children == nullptr) {
        return makeList();
    }
    return children!-><DiagnosticsNode>map([=] (InlineSpan child) {
        if (child != nullptr) {
            return child->toDiagnosticsNode();
        } else {
            return DiagnosticsNodeCls->message(__s("<null child>"));
        }
    })->toList();
}
