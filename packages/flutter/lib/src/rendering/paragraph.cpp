#include "paragraph.hpp"
String TextParentDataCls::toString() {
    List<String> list1 = make<ListCls<>>();list1.add(ArrayItem);if (scale != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);List<String> values = list1;
    return values->join(__s("; "));
}

PlaceholderSpanIndexSemanticsTagCls::PlaceholderSpanIndexSemanticsTagCls(int index) : SemanticsTag(__s("PlaceholderSpanIndexSemanticsTag(%s)")) {
}

bool PlaceholderSpanIndexSemanticsTagCls::==(Object other) {
    return is<PlaceholderSpanIndexSemanticsTag>(other) && other->index == index;
}

int PlaceholderSpanIndexSemanticsTagCls::hashCode() {
    return ObjectCls->hash(PlaceholderSpanIndexSemanticsTagCls, index);
}

RenderParagraphCls::RenderParagraphCls(InlineSpan text, List<RenderBox> children, Locale locale, int maxLines, TextOverflow overflow, SelectionRegistrar registrar, Color selectionColor, bool softWrap, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(text != nullptr);
        assert(text->debugAssertIsValid());
        assert(textAlign != nullptr);
        assert(textDirection != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(textScaleFactor != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(textWidthBasis != nullptr);
        _softWrap = softWrap;
        _overflow = overflow;
        _selectionColor = selectionColor;
        _textPainter = make<TextPainterCls>(text, textAlign, textDirection, textScaleFactor, maxLines, overflow == TextOverflowCls::ellipsis? _kEllipsis : nullptr, locale, strutStyle, textWidthBasis, textHeightBehavior);
    }
    {
        addAll(children);
        _extractPlaceholderSpans(text);
        this->registrar = registrar;
    }
}

void RenderParagraphCls::setupParentData(RenderBox child) {
    if (!is<TextParentData>(child->parentData)) {
        child->parentData = make<TextParentDataCls>();
    }
}

InlineSpan RenderParagraphCls::text() {
    return _textPainter->text()!;
}

void RenderParagraphCls::text(InlineSpan value) {
    assert(value != nullptr);
    ;
    _removeSelectionRegistrarSubscription();
    _disposeSelectableFragments();
    _updateSelectionRegistrarSubscription();
}

List<TextSelection> RenderParagraphCls::selections() {
    if (_lastSelectableFragments == nullptr) {
        return makeList();
    }
    List<TextSelection> results = makeList();
    for (_SelectableFragment fragment : _lastSelectableFragments!) {
        if (fragment->_textSelectionStart != nullptr && fragment->_textSelectionEnd != nullptr && fragment->_textSelectionStart!->offset != fragment->_textSelectionEnd!->offset) {
            results->add(make<TextSelectionCls>(fragment->_textSelectionStart!->offset, fragment->_textSelectionEnd!->offset));
        }
    }
    return results;
}

SelectionRegistrar RenderParagraphCls::registrar() {
    return _registrar;
}

void RenderParagraphCls::registrar(SelectionRegistrar value) {
    if (value == _registrar) {
        return;
    }
    _removeSelectionRegistrarSubscription();
    _disposeSelectableFragments();
    _registrar = value;
    _updateSelectionRegistrarSubscription();
}

void RenderParagraphCls::markNeedsLayout() {
    _lastSelectableFragments?->forEach([=] (_SelectableFragment element) {
        element->didChangeParagraphLayout();
    });
    super->markNeedsLayout();
}

void RenderParagraphCls::dispose() {
    _removeSelectionRegistrarSubscription();
    _lastSelectableFragments = nullptr;
    super->dispose();
}

TextAlign RenderParagraphCls::textAlign() {
    return _textPainter->textAlign();
}

void RenderParagraphCls::textAlign(TextAlign value) {
    assert(value != nullptr);
    if (_textPainter->textAlign() == value) {
        return;
    }
    _textPainter->textAlign() = value;
    markNeedsPaint();
}

TextDirection RenderParagraphCls::textDirection() {
    return _textPainter->textDirection()!;
}

void RenderParagraphCls::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (_textPainter->textDirection() == value) {
        return;
    }
    _textPainter->textDirection() = value;
    markNeedsLayout();
}

bool RenderParagraphCls::softWrap() {
    return _softWrap;
}

void RenderParagraphCls::softWrap(bool value) {
    assert(value != nullptr);
    if (_softWrap == value) {
        return;
    }
    _softWrap = value;
    markNeedsLayout();
}

TextOverflow RenderParagraphCls::overflow() {
    return _overflow;
}

void RenderParagraphCls::overflow(TextOverflow value) {
    assert(value != nullptr);
    if (_overflow == value) {
        return;
    }
    _overflow = value;
    _textPainter->ellipsis() = value == TextOverflowCls::ellipsis? _kEllipsis : nullptr;
    markNeedsLayout();
}

double RenderParagraphCls::textScaleFactor() {
    return _textPainter->textScaleFactor();
}

void RenderParagraphCls::textScaleFactor(double value) {
    assert(value != nullptr);
    if (_textPainter->textScaleFactor() == value) {
        return;
    }
    _textPainter->textScaleFactor() = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

int RenderParagraphCls::maxLines() {
    return _textPainter->maxLines();
}

void RenderParagraphCls::maxLines(int value) {
    assert(value == nullptr || value > 0);
    if (_textPainter->maxLines() == value) {
        return;
    }
    _textPainter->maxLines() = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

Locale RenderParagraphCls::locale() {
    return _textPainter->locale();
}

void RenderParagraphCls::locale(Locale value) {
    if (_textPainter->locale() == value) {
        return;
    }
    _textPainter->locale() = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

StrutStyle RenderParagraphCls::strutStyle() {
    return _textPainter->strutStyle();
}

void RenderParagraphCls::strutStyle(StrutStyle value) {
    if (_textPainter->strutStyle() == value) {
        return;
    }
    _textPainter->strutStyle() = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

TextWidthBasis RenderParagraphCls::textWidthBasis() {
    return _textPainter->textWidthBasis();
}

void RenderParagraphCls::textWidthBasis(TextWidthBasis value) {
    assert(value != nullptr);
    if (_textPainter->textWidthBasis() == value) {
        return;
    }
    _textPainter->textWidthBasis() = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

TextHeightBehavior RenderParagraphCls::textHeightBehavior() {
    return _textPainter->textHeightBehavior();
}

void RenderParagraphCls::textHeightBehavior(TextHeightBehavior value) {
    if (_textPainter->textHeightBehavior() == value) {
        return;
    }
    _textPainter->textHeightBehavior() = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

Color RenderParagraphCls::selectionColor() {
    return _selectionColor;
}

void RenderParagraphCls::selectionColor(Color value) {
    if (_selectionColor == value) {
        return;
    }
    _selectionColor = value;
    if (_lastSelectableFragments?->any([=] (_SelectableFragment fragment) {
        fragment->value->hasSelection;
    }) | false) {
        markNeedsPaint();
    }
}

double RenderParagraphCls::computeMinIntrinsicWidth(double height) {
    if (!_canComputeIntrinsics()) {
        return 0.0;
    }
    _computeChildrenWidthWithMinIntrinsics(height);
    _layoutText();
    return _textPainter->minIntrinsicWidth();
}

double RenderParagraphCls::computeMaxIntrinsicWidth(double height) {
    if (!_canComputeIntrinsics()) {
        return 0.0;
    }
    _computeChildrenWidthWithMaxIntrinsics(height);
    _layoutText();
    return _textPainter->maxIntrinsicWidth();
}

double RenderParagraphCls::computeMinIntrinsicHeight(double width) {
    return _computeIntrinsicHeight(width);
}

double RenderParagraphCls::computeMaxIntrinsicHeight(double width) {
    return _computeIntrinsicHeight(width);
}

double RenderParagraphCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout());
    assert(constraints() != nullptr);
    assert(constraints()->debugAssertIsValid());
    _layoutTextWithConstraints(constraints());
    return _textPainter->computeDistanceToActualBaseline(TextBaselineCls::alphabetic);
}

bool RenderParagraphCls::hitTestSelf(Offset position) {
    return true;
}

bool RenderParagraphCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    bool hitText = false;
    TextPosition textPosition = _textPainter->getPositionForOffset(position);
    InlineSpan span = _textPainter->text()!->getSpanForPosition(textPosition);
    if (span != nullptr && is<HitTestTarget>(span)) {
        result->add(make<HitTestEntryCls>(as<HitTestTarget>(span)));
        hitText = true;
    }
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter->inlinePlaceholderBoxes()!->length()) {
        TextParentData textParentData = as<TextParentData>(child->parentData!);
            auto _c1 = Matrix4Cls->translationValues(textParentData->offset->dx(), textParentData->offset->dy(), 0.0);    _c1.scale(textParentData->scale, textParentData->scale, textParentData->scale);Matrix4 transform = _c1;
        bool isHit = result->addWithPaintTransform(transform, position, [=] (BoxHitTestResult result,Offset transformed) {
    assert([=] () {
        Offset manualPosition = (position - textParentData->offset) / textParentData->scale!;
        return (transformed->dx - manualPosition->dx())->abs() < precisionErrorTolerance && (transformed->dy - manualPosition->dy())->abs() < precisionErrorTolerance;
    }());
    return child!->hitTest(result, transformed);
});
        if (isHit) {
            return true;
        }
        child = childAfter(child);
        childIndex += 1;
    }
    return hitText;
}

bool RenderParagraphCls::debugHasOverflowShader() {
    return _overflowShader != nullptr;
}

void RenderParagraphCls::systemFontsDidChange() {
    super->systemFontsDidChange();
    _textPainter->markNeedsLayout();
}

Size RenderParagraphCls::computeDryLayout(BoxConstraints constraints) {
    if (!_canComputeDryLayout()) {
        assert(debugCannotComputeDryLayout(__s("Dry layout not available for alignments that require baseline.")));
        return SizeCls::zero;
    }
    _textPainter->setPlaceholderDimensions(_layoutChildren(constraints, true));
    _layoutText(constraints->minWidth, constraints->maxWidth);
    return constraints->constrain(_textPainter->size());
}

void RenderParagraphCls::performLayout() {
    BoxConstraints constraints = this->constraints();
    _placeholderDimensions = _layoutChildren(constraints);
    _layoutTextWithConstraints(constraints);
    _setParentData();
    Size textSize = _textPainter->size();
    bool textDidExceedMaxLines = _textPainter->didExceedMaxLines();
    size() = constraints->constrain(textSize);
    bool didOverflowHeight = size()->height() < textSize->height() || textDidExceedMaxLines;
    bool didOverflowWidth = size()->width() < textSize->width();
    bool hasVisualOverflow = didOverflowWidth || didOverflowHeight;
    if (hasVisualOverflow) {
        ;
    } else {
        _needsClipping = false;
        _overflowShader = nullptr;
    }
}

void RenderParagraphCls::paint(PaintingContext context, Offset offset) {
    _layoutTextWithConstraints(constraints());
    assert([=] () {
        if (debugRepaintTextRainbowEnabled) {
                    auto _c1 = make<PaintCls>();        _c1.color = debugCurrentRepaintColor->toColor();Paint paint = _c1;
            context->canvas()->drawRect(offset & size(), paint);
        }
        return true;
    }());
    if (_needsClipping) {
        Rect bounds = offset & size();
        if (_overflowShader != nullptr) {
            context->canvas()->saveLayer(bounds, make<PaintCls>());
        } else {
            context->canvas()->save();
        }
        context->canvas()->clipRect(bounds);
    }
    _textPainter->paint(context->canvas(), offset);
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter->inlinePlaceholderBoxes()!->length()) {
        TextParentData textParentData = as<TextParentData>(child->parentData!);
        double scale = textParentData->scale!;
        context->pushTransform(needsCompositing(), offset + textParentData->offset, Matrix4Cls->diagonal3Values(scale, scale, scale), [=] (PaintingContext context,Offset offset) {
            context->paintChild(child!, offset);
        });
        child = childAfter(child);
        childIndex += 1;
    }
    if (_needsClipping) {
        if (_overflowShader != nullptr) {
            context->canvas()->translate(offset->dx(), offset->dy());
                    auto _c2 = make<PaintCls>();        _c2.blendMode = auto _c3 = BlendModeCls::modulate;        _c3.shader = _overflowShader;        _c3;Paint paint = _c2;
            context->canvas()->drawRect(OffsetCls::zero & size(), paint);
        }
        context->canvas()->restore();
    }
    if (_lastSelectableFragments != nullptr) {
        for (_SelectableFragment fragment : _lastSelectableFragments!) {
            fragment->paint(context, offset);
        }
    }
    super->paint(context, offset);
}

Offset RenderParagraphCls::getOffsetForCaret(TextPosition position, Rect caretPrototype) {
    assert(!debugNeedsLayout());
    _layoutTextWithConstraints(constraints());
    return _textPainter->getOffsetForCaret(position, caretPrototype);
}

double RenderParagraphCls::getFullHeightForCaret(TextPosition position) {
    assert(!debugNeedsLayout());
    _layoutTextWithConstraints(constraints());
    return _textPainter->getFullHeightForCaret(position, RectCls::zero);
}

List<TextBox> RenderParagraphCls::getBoxesForSelection(TextSelection selection, BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle) {
    assert(!debugNeedsLayout());
    assert(boxHeightStyle != nullptr);
    assert(boxWidthStyle != nullptr);
    _layoutTextWithConstraints(constraints());
    return _textPainter->getBoxesForSelection(selection, boxHeightStyle, boxWidthStyle);
}

TextPosition RenderParagraphCls::getPositionForOffset(Offset offset) {
    assert(!debugNeedsLayout());
    _layoutTextWithConstraints(constraints());
    return _textPainter->getPositionForOffset(offset);
}

TextRange RenderParagraphCls::getWordBoundary(TextPosition position) {
    assert(!debugNeedsLayout());
    _layoutTextWithConstraints(constraints());
    return _textPainter->getWordBoundary(position);
}

Size RenderParagraphCls::textSize() {
    assert(!debugNeedsLayout());
    return _textPainter->size();
}

void RenderParagraphCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    _semanticsInfo = text()->getSemanticsInformation();
    if (_semanticsInfo!->any([=] (InlineSpanSemanticsInformation info) {
        info->recognizer != nullptr;
    })) {
        config->explicitChildNodes = true;
        config->isSemanticBoundary() = true;
    } else {
        if (_cachedAttributedLabel == nullptr) {
            StringBuffer buffer = make<StringBufferCls>();
            int offset = 0;
            List<StringAttribute> attributes = makeList();
            for (InlineSpanSemanticsInformation info : _semanticsInfo!) {
                String label = info->semanticsLabel | info->text;
                for (StringAttribute infoAttribute : info->stringAttributes) {
                    TextRange originalRange = infoAttribute->range;
                    attributes->add(infoAttribute->copy(make<TextRangeCls>(offset + originalRange->start, offset + originalRange->end)));
                }
                buffer->write(label);
                offset += label->length();
            }
            _cachedAttributedLabel = make<AttributedStringCls>(buffer->toString(), attributes);
        }
        config->attributedLabel() = _cachedAttributedLabel!;
        config->textDirection() = textDirection();
    }
}

void RenderParagraphCls::assembleSemanticsNode(SemanticsNode node, SemanticsConfiguration config, Iterable<SemanticsNode> children) {
    assert(_semanticsInfo != nullptr && _semanticsInfo!->isNotEmpty());
    List<SemanticsNode> newChildren = makeList();
    TextDirection currentDirection = textDirection();
    Rect currentRect;
    double ordinal = 0.0;
    int start = 0;
    int placeholderIndex = 0;
    int childIndex = 0;
    RenderBox child = firstChild;
    LinkedHashMap<Key, SemanticsNode> newChildCache = <Key, SemanticsNode>make<LinkedHashMapCls>();
    _cachedCombinedSemanticsInfos |= combineSemanticsInfo(_semanticsInfo!);
    for (InlineSpanSemanticsInformation info : _cachedCombinedSemanticsInfos!) {
        TextSelection selection = make<TextSelectionCls>(start, start + info->text->length);
        start += info->text->length;
        if (info->isPlaceholder) {
            while (children->length() > childIndex && children->elementAt(childIndex)->isTagged(make<PlaceholderSpanIndexSemanticsTagCls>(placeholderIndex))) {
                SemanticsNode childNode = children->elementAt(childIndex);
                TextParentData parentData = as<TextParentData>(child!->parentData!);
                assert(parentData->scale != nullptr || parentData->offset == OffsetCls::zero);
                if (parentData->scale != nullptr) {
                    childNode->rect() = RectCls->fromLTWH(childNode->rect()->left, childNode->rect()->top, childNode->rect()->width() * parentData->scale!, childNode->rect()->height() * parentData->scale!);
                    newChildren->add(childNode);
                }
                childIndex += 1;
            }
            child = childAfter(child!);
            placeholderIndex += 1;
        } else {
            TextDirection initialDirection = currentDirection;
            List<TextBox> rects = getBoxesForSelection(selection);
            if (rects->isEmpty()) {
                continue;
            }
            Rect rect = rects->first->toRect();
            currentDirection = rects->first->direction;
            for (TextBox textBox : rects->skip(1)) {
                rect = rect->expandToInclude(textBox->toRect());
                currentDirection = textBox->direction;
            }
            rect = RectCls->fromLTWH(math->max(0.0, rect->left), math->max(0.0, rect->top), math->min(rect->width(), constraints()->maxWidth), math->min(rect->height(), constraints()->maxHeight));
            currentRect = RectCls->fromLTRB(rect->left->floorToDouble() - 4.0, rect->top->floorToDouble() - 4.0, rect->right->ceilToDouble() + 4.0, rect->bottom->ceilToDouble() + 4.0);
                    auto _c1 = make<SemanticsConfigurationCls>();        _c1.sortKey = auto _c2 = make<OrdinalSortKeyCls>(ordinal++);        _c2.textDirection() = auto _c3 = initialDirection;        _c3.attributedLabel = make<AttributedStringCls>(info->semanticsLabel | info->text, info->stringAttributes);        _c3;        _c2;SemanticsConfiguration configuration = _c1;
            GestureRecognizer recognizer = info->recognizer;
            if (recognizer != nullptr) {
                if (is<TapGestureRecognizer>(recognizer)) {
                    if (as<TapGestureRecognizerCls>(recognizer)->onTap != nullptr) {
                        configuration->onTap() = recognizer->onTap;
                        configuration->isLink() = true;
                    }
                } else {
                    if (is<DoubleTapGestureRecognizer>(recognizer)) {
                    if (as<DoubleTapGestureRecognizerCls>(recognizer)->onDoubleTap != nullptr) {
                        configuration->onTap() = recognizer->onDoubleTap;
                        configuration->isLink() = true;
                    }
                } else {
                    if (is<LongPressGestureRecognizer>(recognizer)) {
                    if (as<LongPressGestureRecognizerCls>(recognizer)->onLongPress != nullptr) {
                        configuration->onLongPress() = recognizer->onLongPress;
                    }
                } else {
                    assert(false, __s("%s)"));
                }
;
                };
                }            }
            if (node->parentPaintClipRect != nullptr) {
                Rect paintRect = node->parentPaintClipRect!->intersect(currentRect);
                configuration->isHidden() = paintRect->isEmpty() && !currentRect->isEmpty();
            }
            SemanticsNode newChild;
            if (_cachedChildNodes?->isNotEmpty() | false) {
                newChild = _cachedChildNodes!->remove(_cachedChildNodes!->keys()->first())!;
            } else {
                UniqueKey key = make<UniqueKeyCls>();
                newChild = make<SemanticsNodeCls>(key, _createShowOnScreenFor(key));
            }
                    auto _c4 = newChild;        _c4.auto _c5 = updateWith(configuration);        _c5.rect = currentRect;        _c5;_c4;
            newChildCache[newChild->key!] = newChild;
            newChildren->add(newChild);
        }
    }
    assert(childIndex == children->length());
    assert(child == nullptr);
    _cachedChildNodes = newChildCache;
    node->updateWith(config, newChildren);
}

void RenderParagraphCls::clearSemantics() {
    super->clearSemantics();
    _cachedChildNodes = nullptr;
}

List<DiagnosticsNode> RenderParagraphCls::debugDescribeChildren() {
    return makeList(ArrayItem);
}

void RenderParagraphCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>(__s("textAlign"), textAlign()));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection()));
    properties->add(make<FlagPropertyCls>(__s("softWrap"), softWrap(), __s("wrapping at box width"), __s("no wrapping except at line break characters"), true));
    properties->add(<TextOverflow>make<EnumPropertyCls>(__s("overflow"), overflow()));
    properties->add(make<DoublePropertyCls>(__s("textScaleFactor"), textScaleFactor(), 1.0));
    properties->add(<Locale>make<DiagnosticsPropertyCls>(__s("locale"), locale(), nullptr));
    properties->add(make<IntPropertyCls>(__s("maxLines"), maxLines(), __s("unlimited")));
}

void RenderParagraphCls::_updateSelectionRegistrarSubscription() {
    if (_registrar == nullptr) {
        return;
    }
    _lastSelectableFragments |= _getSelectableFragments();
    _lastSelectableFragments!->forEach(_registrar!->add);
}

void RenderParagraphCls::_removeSelectionRegistrarSubscription() {
    if (_registrar == nullptr || _lastSelectableFragments == nullptr) {
        return;
    }
    _lastSelectableFragments!->forEach(_registrar!->remove);
}

List<_SelectableFragment> RenderParagraphCls::_getSelectableFragments() {
    String plainText = text()->toPlainText(false);
    List<_SelectableFragment> result = makeList();
    int start = 0;
    while ( < plainText->length()) {
        int end = plainText->indexOf(_placeholderCharacter, start);
        if (start != end) {
            if (end == -1) {
                end = plainText->length();
            }
            result->add(make<_SelectableFragmentCls>(this, make<TextRangeCls>(start, end)));
            start = end;
        }
        start += 1;
    }
    return result;
}

void RenderParagraphCls::_disposeSelectableFragments() {
    if (_lastSelectableFragments == nullptr) {
        return;
    }
    for (_SelectableFragment fragment : _lastSelectableFragments!) {
        fragment->dispose();
    }
    _lastSelectableFragments = nullptr;
}

void RenderParagraphCls::_extractPlaceholderSpans(InlineSpan span) {
    _placeholderSpans = makeList();
    span->visitChildren([=] (InlineSpan span) {
        if (is<PlaceholderSpan>(span)) {
            _placeholderSpans->add(as<PlaceholderSpanCls>(span));
        }
        return true;
    });
}

Offset RenderParagraphCls::_getOffsetForPosition(TextPosition position) {
    return getOffsetForCaret(position, RectCls::zero) + make<OffsetCls>(0, getFullHeightForCaret(position) | 0.0);
}

double RenderParagraphCls::_computeIntrinsicHeight(double width) {
    if (!_canComputeIntrinsics()) {
        return 0.0;
    }
    _computeChildrenHeightWithMinIntrinsics(width);
    _layoutText(width, width);
    return _textPainter->height();
}

bool RenderParagraphCls::_canComputeIntrinsics() {
    for (PlaceholderSpan span : _placeholderSpans) {
        ;
    }
    return true;
}

void RenderParagraphCls::_computeChildrenWidthWithMaxIntrinsics(double height) {
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensionsCls::empty);
    int childIndex = 0;
    while (child != nullptr) {
        placeholderDimensions[childIndex] = make<PlaceholderDimensionsCls>(make<SizeCls>(child->getMaxIntrinsicWidth(double->infinity), 0.0), _placeholderSpans[childIndex]->alignment, _placeholderSpans[childIndex]->baseline);
        child = childAfter(child);
        childIndex += 1;
    }
    _textPainter->setPlaceholderDimensions(placeholderDimensions);
}

void RenderParagraphCls::_computeChildrenWidthWithMinIntrinsics(double height) {
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensionsCls::empty);
    int childIndex = 0;
    while (child != nullptr) {
        placeholderDimensions[childIndex] = make<PlaceholderDimensionsCls>(make<SizeCls>(child->getMinIntrinsicWidth(double->infinity), 0.0), _placeholderSpans[childIndex]->alignment, _placeholderSpans[childIndex]->baseline);
        child = childAfter(child);
        childIndex += 1;
    }
    _textPainter->setPlaceholderDimensions(placeholderDimensions);
}

void RenderParagraphCls::_computeChildrenHeightWithMinIntrinsics(double width) {
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensionsCls::empty);
    int childIndex = 0;
    width = width / textScaleFactor();
    while (child != nullptr) {
        Size size = child->getDryLayout(make<BoxConstraintsCls>(width));
        placeholderDimensions[childIndex] = make<PlaceholderDimensionsCls>(size, _placeholderSpans[childIndex]->alignment, _placeholderSpans[childIndex]->baseline);
        child = childAfter(child);
        childIndex += 1;
    }
    _textPainter->setPlaceholderDimensions(placeholderDimensions);
}

void RenderParagraphCls::_layoutText(double maxWidth, double minWidth) {
    bool widthMatters = softWrap() || overflow() == TextOverflowCls::ellipsis;
    _textPainter->layout(minWidth, widthMatters? maxWidth : double->infinity);
}

void RenderParagraphCls::_layoutTextWithConstraints(BoxConstraints constraints) {
    _textPainter->setPlaceholderDimensions(_placeholderDimensions);
    _layoutText(constraints->minWidth, constraints->maxWidth);
}

List<PlaceholderDimensions> RenderParagraphCls::_layoutChildren(BoxConstraints constraints, bool dry) {
    if (childCount == 0) {
        return makeList();
    }
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensionsCls::empty);
    int childIndex = 0;
    BoxConstraints boxConstraints = make<BoxConstraintsCls>(constraints->maxWidth);
    boxConstraints = boxConstraints / textScaleFactor();
    while (child != nullptr) {
        double baselineOffset;
        Size childSize;
        if (!dry) {
            child->layout(boxConstraints, true);
            childSize = child->size();
            ;
        } else {
            assert(_placeholderSpans[childIndex]->alignment != ui->PlaceholderAlignmentCls::baseline);
            childSize = child->getDryLayout(boxConstraints);
        }
        placeholderDimensions[childIndex] = make<PlaceholderDimensionsCls>(childSize, _placeholderSpans[childIndex]->alignment, _placeholderSpans[childIndex]->baseline, baselineOffset);
        child = childAfter(child);
        childIndex += 1;
    }
    return placeholderDimensions;
}

void RenderParagraphCls::_setParentData() {
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter->inlinePlaceholderBoxes()!->length()) {
        TextParentData textParentData = as<TextParentData>(child->parentData!);
        textParentData->offset = make<OffsetCls>(_textPainter->inlinePlaceholderBoxes()![childIndex]->left, _textPainter->inlinePlaceholderBoxes()![childIndex]->top);
        textParentData->scale = _textPainter->inlinePlaceholderScales()![childIndex];
        child = childAfter(child);
        childIndex += 1;
    }
}

bool RenderParagraphCls::_canComputeDryLayout() {
    for (PlaceholderSpan span : _placeholderSpans) {
        ;
    }
    return true;
}

VoidCallback RenderParagraphCls::_createShowOnScreenFor(Key key) {
    return [=] () {
        SemanticsNode node = _cachedChildNodes![key]!;
        showOnScreen(this, node->rect());
    };
}

SelectionGeometry _SelectableFragmentCls::value() {
    return _selectionGeometry;
}

SelectionResult _SelectableFragmentCls::dispatchSelectionEvent(SelectionEvent event) {
    SelectionResult result;
    TextPosition existingSelectionStart = _textSelectionStart;
    TextPosition existingSelectionEnd = _textSelectionEnd;
    ;
    if (existingSelectionStart != _textSelectionStart || existingSelectionEnd != _textSelectionEnd) {
        _didChangeSelection();
    }
    return result;
}

SelectedContent _SelectableFragmentCls::getSelectedContent() {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return nullptr;
    }
    int start = math->min(_textSelectionStart!->offset, _textSelectionEnd!->offset);
    int end = math->max(_textSelectionStart!->offset, _textSelectionEnd!->offset);
    return make<SelectedContentCls>(paragraph->text()->toPlainText(false)->substring(start, end));
}

Matrix4 _SelectableFragmentCls::getTransformToParagraph() {
    return Matrix4Cls->translationValues(_rect()->left, _rect()->top, 0.0);
}

Matrix4 _SelectableFragmentCls::getTransformTo(RenderObject ancestor) {
    auto _c1 = getTransformToParagraph();_c1.multiply(paragraph->getTransformTo(ancestor));return _c1;
}

void _SelectableFragmentCls::pushHandleLayers(LayerLink startHandle, LayerLink endHandle) {
    if (!paragraph->attached()) {
        assert(startHandle == nullptr && endHandle == nullptr, __s("Only clean up can be called."));
        return;
    }
    if (_startHandleLayerLink != startHandle) {
        _startHandleLayerLink = startHandle;
        paragraph->markNeedsPaint();
    }
    if (_endHandleLayerLink != endHandle) {
        _endHandleLayerLink = endHandle;
        paragraph->markNeedsPaint();
    }
}

void _SelectableFragmentCls::didChangeParagraphLayout() {
    _cachedRect = nullptr;
}

Size _SelectableFragmentCls::size() {
    return _rect()->size();
}

void _SelectableFragmentCls::paint(PaintingContext context, Offset offset) {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return;
    }
    if (paragraph->selectionColor() != nullptr) {
        TextSelection selection = make<TextSelectionCls>(_textSelectionStart!->offset, _textSelectionEnd!->offset);
            auto _c1 = make<PaintCls>();    _c1.style = auto _c2 = PaintingStyleCls::fill;    _c2.color = paragraph->selectionColor()!;    _c2;Paint selectionPaint = _c1;
        for (TextBox textBox : paragraph->getBoxesForSelection(selection)) {
            context->canvas()->drawRect(textBox->toRect()->shift(offset), selectionPaint);
        }
    }
    Matrix4 transform = getTransformToParagraph();
    if (_startHandleLayerLink != nullptr && value()->startSelectionPoint != nullptr) {
        context->pushLayer(make<LeaderLayerCls>(_startHandleLayerLink!, offset + MatrixUtilsCls->transformPoint(transform, value()->startSelectionPoint!->localPosition)), [=] (PaintingContext context,Offset offset) {
        }, OffsetCls::zero);
    }
    if (_endHandleLayerLink != nullptr && value()->endSelectionPoint != nullptr) {
        context->pushLayer(make<LeaderLayerCls>(_endHandleLayerLink!, offset + MatrixUtilsCls->transformPoint(transform, value()->endSelectionPoint!->localPosition)), [=] (PaintingContext context,Offset offset) {
        }, OffsetCls::zero);
    }
}

_SelectableFragmentCls::_SelectableFragmentCls(RenderParagraph paragraph, TextRange range) {
    {
        assert(range->isValid() && !range->isCollapsed() && range->isNormalized());
    }
    {
        _selectionGeometry = _getSelectionGeometry();
    }
}

void _SelectableFragmentCls::_updateSelectionGeometry() {
    SelectionGeometry newValue = _getSelectionGeometry();
    if (_selectionGeometry == newValue) {
        return;
    }
    _selectionGeometry = newValue;
    notifyListeners();
}

SelectionGeometry _SelectableFragmentCls::_getSelectionGeometry() {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return make<SelectionGeometryCls>(SelectionStatusCls::none, true);
    }
    int selectionStart = _textSelectionStart!->offset;
    int selectionEnd = _textSelectionEnd!->offset;
    bool isReversed = selectionStart > selectionEnd;
    Offset startOffsetInParagraphCoordinates = paragraph->_getOffsetForPosition(make<TextPositionCls>(selectionStart));
    Offset endOffsetInParagraphCoordinates = selectionStart == selectionEnd? startOffsetInParagraphCoordinates : paragraph->_getOffsetForPosition(make<TextPositionCls>(selectionEnd));
    bool flipHandles = isReversed != (TextDirectionCls::rtl == paragraph->textDirection());
    auto _c1 = getTransformToParagraph();_c1.invert();Matrix4 paragraphToFragmentTransform = _c1;
    return make<SelectionGeometryCls>(make<SelectionPointCls>(MatrixUtilsCls->transformPoint(paragraphToFragmentTransform, startOffsetInParagraphCoordinates), paragraph->_textPainter->preferredLineHeight(), flipHandles? TextSelectionHandleTypeCls::right : TextSelectionHandleTypeCls::left), make<SelectionPointCls>(MatrixUtilsCls->transformPoint(paragraphToFragmentTransform, endOffsetInParagraphCoordinates), paragraph->_textPainter->preferredLineHeight(), flipHandles? TextSelectionHandleTypeCls::left : TextSelectionHandleTypeCls::right), _textSelectionStart!->offset == _textSelectionEnd!->offset? SelectionStatusCls::collapsed : SelectionStatusCls::uncollapsed, true);
}

void _SelectableFragmentCls::_didChangeSelection() {
    paragraph->markNeedsPaint();
    _updateSelectionGeometry();
}

SelectionResult _SelectableFragmentCls::_updateSelectionEdge(Offset globalPosition, bool isEnd) {
    _setSelectionPosition(nullptr, isEnd);
    Matrix4 transform = paragraph->getTransformTo(nullptr);
    transform->invert();
    Offset localPosition = MatrixUtilsCls->transformPoint(transform, globalPosition);
    if (_rect()->isEmpty()) {
        return SelectionUtilsCls->getResultBasedOnRect(_rect(), localPosition);
    }
    Offset adjustedOffset = SelectionUtilsCls->adjustDragOffset(_rect(), localPosition, paragraph->textDirection());
    TextPosition position = _clampTextPosition(paragraph->getPositionForOffset(adjustedOffset));
    _setSelectionPosition(position, isEnd);
    if (position->offset == range->end) {
        return SelectionResultCls::next;
    }
    if (position->offset == range->start) {
        return SelectionResultCls::previous;
    }
    return SelectionUtilsCls->getResultBasedOnRect(_rect(), localPosition);
}

TextPosition _SelectableFragmentCls::_clampTextPosition(TextPosition position) {
    if (position->offset > range->end || (position->offset == range->end && position->affinity == TextAffinityCls::downstream)) {
        return make<TextPositionCls>(range->end, TextAffinityCls::upstream);
    }
    if (position->offset < range->start) {
        return make<TextPositionCls>(range->start);
    }
    return position;
}

void _SelectableFragmentCls::_setSelectionPosition(TextPosition position, bool isEnd) {
    if (isEnd) {
        _textSelectionEnd = position;
    } else {
        _textSelectionStart = position;
    }
}

SelectionResult _SelectableFragmentCls::_handleClearSelection() {
    _textSelectionStart = nullptr;
    _textSelectionEnd = nullptr;
    return SelectionResultCls::none;
}

SelectionResult _SelectableFragmentCls::_handleSelectAll() {
    _textSelectionStart = make<TextPositionCls>(range->start);
    _textSelectionEnd = make<TextPositionCls>(range->end, TextAffinityCls::upstream);
    return SelectionResultCls::none;
}

SelectionResult _SelectableFragmentCls::_handleSelectWord(Offset globalPosition) {
    TextPosition position = paragraph->getPositionForOffset(paragraph->globalToLocal(globalPosition));
    if (_positionIsWithinCurrentSelection(position)) {
        return SelectionResultCls::end;
    }
    TextRange word = paragraph->getWordBoundary(position);
    assert(word->isNormalized());
    assert(word->start >= range->start && word->end <= range->end);
    TextPosition start;
    TextPosition end;
    if (position->offset >= word->end) {
        start = end = make<TextPositionCls>(position->offset);
    } else {
        start = make<TextPositionCls>(word->start);
        end = make<TextPositionCls>(word->end, TextAffinityCls::upstream);
    }
    _textSelectionStart = start;
    _textSelectionEnd = end;
    return SelectionResultCls::end;
}

bool _SelectableFragmentCls::_positionIsWithinCurrentSelection(TextPosition position) {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return false;
    }
    TextPosition currentStart;
    TextPosition currentEnd;
    if (_compareTextPositions(_textSelectionStart!, _textSelectionEnd!) > 0) {
        currentStart = _textSelectionStart!;
        currentEnd = _textSelectionEnd!;
    } else {
        currentStart = _textSelectionEnd!;
        currentEnd = _textSelectionStart!;
    }
    return _compareTextPositions(currentStart, position) >= 0 && _compareTextPositions(currentEnd, position) <= 0;
}

int _SelectableFragmentCls::_compareTextPositions(TextPosition position, TextPosition otherPosition) {
    if (position->offset < otherPosition->offset) {
        return 1;
    } else {
        if (position->offset > otherPosition->offset) {
        return -1;
    } else {
        if (position->affinity == otherPosition->affinity) {
        return 0;
    } else {
        return position->affinity == TextAffinityCls::upstream? 1 : -1;
    }
;
    };
    }}

Rect _SelectableFragmentCls::_rect() {
    if (_cachedRect == nullptr) {
        List<TextBox> boxes = paragraph->getBoxesForSelection(make<TextSelectionCls>(range->start, range->end));
        if (boxes->isNotEmpty()) {
            Rect result = boxes->first->toRect();
            for (;  < boxes->length(); index += 1) {
                result = result->expandToInclude(boxes[index]->toRect());
            }
            _cachedRect = result;
        } else {
            Offset offset = paragraph->_getOffsetForPosition(make<TextPositionCls>(range->start));
            _cachedRect = RectCls->fromPoints(offset, offset->translate(0, -paragraph->_textPainter->preferredLineHeight()));
        }
    }
    return _cachedRect!;
}
