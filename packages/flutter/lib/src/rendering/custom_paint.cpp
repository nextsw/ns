#include "custom_paint.hpp"
CustomPainterCls::CustomPainterCls(Listenable repaint) {
    {
        _repaint = repaint;
    }
}

void CustomPainterCls::addListener(VoidCallback listener) {
    return _repaint?->addListener(listener);
}

void CustomPainterCls::removeListener(VoidCallback listener) {
    return _repaint?->removeListener(listener);
}

SemanticsBuilderCallback CustomPainterCls::semanticsBuilder() {
    return nullptr;
}

bool CustomPainterCls::shouldRebuildSemantics(CustomPainter oldDelegate) {
    return shouldRepaint(oldDelegate);
}

bool CustomPainterCls::hitTest(Offset position) {
    return nullptr;
}

String CustomPainterCls::toString() {
    return __s("%s$%s");
}

CustomPainterSemanticsCls::CustomPainterSemanticsCls(Key key, SemanticsProperties properties, Rect rect, Set<SemanticsTag> tags, Matrix4 transform) {
    {
        assert(rect != nullptr);
        assert(properties != nullptr);
    }
}

RenderCustomPaintCls::RenderCustomPaintCls(RenderBox child, CustomPainter foregroundPainter, bool isComplex, CustomPainter painter, Size preferredSize, bool willChange) : RenderProxyBox(child) {
    {
        assert(preferredSize != nullptr);
        _painter = painter;
        _foregroundPainter = foregroundPainter;
        _preferredSize = preferredSize;
    }
}

CustomPainter RenderCustomPaintCls::painter() {
    return _painter;
}

void RenderCustomPaintCls::painter(CustomPainter value) {
    if (_painter == value) {
        return;
    }
    CustomPainter oldPainter = _painter;
    _painter = value;
    _didUpdatePainter(_painter, oldPainter);
}

CustomPainter RenderCustomPaintCls::foregroundPainter() {
    return _foregroundPainter;
}

void RenderCustomPaintCls::foregroundPainter(CustomPainter value) {
    if (_foregroundPainter == value) {
        return;
    }
    CustomPainter oldPainter = _foregroundPainter;
    _foregroundPainter = value;
    _didUpdatePainter(_foregroundPainter, oldPainter);
}

Size RenderCustomPaintCls::preferredSize() {
    return _preferredSize;
}

void RenderCustomPaintCls::preferredSize(Size value) {
    assert(value != nullptr);
    if (preferredSize() == value) {
        return;
    }
    _preferredSize = value;
    markNeedsLayout();
}

double RenderCustomPaintCls::computeMinIntrinsicWidth(double height) {
    if (child == nullptr) {
        return preferredSize()->width()->isFinite()? preferredSize()->width() : 0;
    }
    return super->computeMinIntrinsicWidth(height);
}

double RenderCustomPaintCls::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return preferredSize()->width()->isFinite()? preferredSize()->width() : 0;
    }
    return super->computeMaxIntrinsicWidth(height);
}

double RenderCustomPaintCls::computeMinIntrinsicHeight(double width) {
    if (child == nullptr) {
        return preferredSize()->height()->isFinite()? preferredSize()->height() : 0;
    }
    return super->computeMinIntrinsicHeight(width);
}

double RenderCustomPaintCls::computeMaxIntrinsicHeight(double width) {
    if (child == nullptr) {
        return preferredSize()->height()->isFinite()? preferredSize()->height() : 0;
    }
    return super->computeMaxIntrinsicHeight(width);
}

void RenderCustomPaintCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _painter?->addListener(markNeedsPaint);
    _foregroundPainter?->addListener(markNeedsPaint);
}

void RenderCustomPaintCls::detach() {
    _painter?->removeListener(markNeedsPaint);
    _foregroundPainter?->removeListener(markNeedsPaint);
    super->detach();
}

bool RenderCustomPaintCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    if (_foregroundPainter != nullptr && (_foregroundPainter!->hitTest(position) | false)) {
        return true;
    }
    return super->hitTestChildren(result, position);
}

bool RenderCustomPaintCls::hitTestSelf(Offset position) {
    return _painter != nullptr && (_painter!->hitTest(position) | true);
}

void RenderCustomPaintCls::performLayout() {
    super->performLayout();
    markNeedsSemanticsUpdate();
}

Size RenderCustomPaintCls::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints->constrain(preferredSize());
}

void RenderCustomPaintCls::paint(PaintingContext context, Offset offset) {
    if (_painter != nullptr) {
        _paintWithPainter(context->canvas(), offset, _painter!);
        _setRasterCacheHints(context);
    }
    super->paint(context, offset);
    if (_foregroundPainter != nullptr) {
        _paintWithPainter(context->canvas(), offset, _foregroundPainter!);
        _setRasterCacheHints(context);
    }
}

void RenderCustomPaintCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    _backgroundSemanticsBuilder = painter()?->semanticsBuilder();
    _foregroundSemanticsBuilder = foregroundPainter()?->semanticsBuilder();
    config->isSemanticBoundary() = _backgroundSemanticsBuilder != nullptr || _foregroundSemanticsBuilder != nullptr;
}

void RenderCustomPaintCls::assembleSemanticsNode(SemanticsNode node, SemanticsConfiguration config, Iterable<SemanticsNode> children) {
    assert([=] () {
        if (child == nullptr && children->isNotEmpty()) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem));
        }
        return true;
    }());
    List<CustomPainterSemantics> backgroundSemantics = _backgroundSemanticsBuilder != nullptr? _backgroundSemanticsBuilder!(size()) : makeList();
    _backgroundSemanticsNodes = _updateSemanticsChildren(_backgroundSemanticsNodes, backgroundSemantics);
    List<CustomPainterSemantics> foregroundSemantics = _foregroundSemanticsBuilder != nullptr? _foregroundSemanticsBuilder!(size()) : makeList();
    _foregroundSemanticsNodes = _updateSemanticsChildren(_foregroundSemanticsNodes, foregroundSemantics);
    bool hasBackgroundSemantics = _backgroundSemanticsNodes != nullptr && _backgroundSemanticsNodes!->isNotEmpty();
    bool hasForegroundSemantics = _foregroundSemanticsNodes != nullptr && _foregroundSemanticsNodes!->isNotEmpty();
    List<SemanticsNode> list1 = make<ListCls<>>();if (hasBackgroundSemantics) {    list1.add(ArrayItem);}for (auto _x1 : children) {{    list1.add(_x1);}if (hasForegroundSemantics) {    list1.add(ArrayItem);}List<SemanticsNode> finalChildren = list1;
    super->assembleSemanticsNode(node, config, finalChildren);
}

void RenderCustomPaintCls::clearSemantics() {
    super->clearSemantics();
    _backgroundSemanticsNodes = nullptr;
    _foregroundSemanticsNodes = nullptr;
}

void RenderCustomPaintCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<MessagePropertyCls>(__s("painter"), __s("%s)")));
    properties->add(make<MessagePropertyCls>(__s("foregroundPainter"), __s("%s,"), foregroundPainter() != nullptr? DiagnosticLevelCls::info : DiagnosticLevelCls::fine));
    properties->add(<Size>make<DiagnosticsPropertyCls>(__s("preferredSize"), preferredSize(), SizeCls::zero));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("isComplex"), isComplex, false));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("willChange"), willChange, false));
}

void RenderCustomPaintCls::_didUpdatePainter(CustomPainter newPainter, CustomPainter oldPainter) {
    if (newPainter == nullptr) {
        assert(oldPainter != nullptr);
        markNeedsPaint();
    } else {
        if (oldPainter == nullptr || newPainter->runtimeType != oldPainter->runtimeType || newPainter->shouldRepaint(oldPainter)) {
        markNeedsPaint();
    }
;
    }    if (attached()) {
        oldPainter?->removeListener(markNeedsPaint);
        newPainter?->addListener(markNeedsPaint);
    }
    if (newPainter == nullptr) {
        assert(oldPainter != nullptr);
        if (attached()) {
            markNeedsSemanticsUpdate();
        }
    } else {
        if (oldPainter == nullptr || newPainter->runtimeType != oldPainter->runtimeType || newPainter->shouldRebuildSemantics(oldPainter)) {
        markNeedsSemanticsUpdate();
    }
;
    }}

void RenderCustomPaintCls::_paintWithPainter(Canvas canvas, Offset offset, CustomPainter painter) {
    int debugPreviousCanvasSaveCount;
    canvas->save();
    assert([=] () {
        debugPreviousCanvasSaveCount = canvas->getSaveCount();
        return true;
    }());
    if (offset != OffsetCls::zero) {
        canvas->translate(offset->dx(), offset->dy());
    }
    painter->paint(canvas, size());
    assert([=] () {
        int debugNewCanvasSaveCount = canvas->getSaveCount();
        if (debugNewCanvasSaveCount > debugPreviousCanvasSaveCount) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        if ( < debugPreviousCanvasSaveCount) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return debugNewCanvasSaveCount == debugPreviousCanvasSaveCount;
    }());
    canvas->restore();
}

void RenderCustomPaintCls::_setRasterCacheHints(PaintingContext context) {
    if (isComplex) {
        context->setIsComplexHint();
    }
    if (willChange) {
        context->setWillChangeHint();
    }
}

List<SemanticsNode> RenderCustomPaintCls::_updateSemanticsChildren(List<SemanticsNode> oldSemantics, List<CustomPainterSemantics> newChildSemantics) {
    oldSemantics = oldSemantics | makeList();
    newChildSemantics = newChildSemantics | makeList();
    assert([=] () {
        Map<Key, int> keys = <Key, int>make<HashMapCls>();
        List<DiagnosticsNode> information = makeList();
        for (;  < newChildSemantics!->length(); i += 1) {
            CustomPainterSemantics child = newChildSemantics[i];
            if (child->key != nullptr) {
                if (keys->containsKey(child->key)) {
                    information->add(make<ErrorDescriptionCls>(__s("- duplicate key %s$%s)")));
                }
                keys[child->key!] = i;
            }
        }
        if (information->isNotEmpty()) {
            information->insert(0, make<ErrorSummaryCls>(__s("Failed to update the list of CustomPainterSemantics:")));
            throw FlutterErrorCls->fromParts(information);
        }
        return true;
    }());
    int newChildrenTop = 0;
    int oldChildrenTop = 0;
    int newChildrenBottom = newChildSemantics->length() - 1;
    int oldChildrenBottom = oldSemantics->length() - 1;
    List<SemanticsNode> newChildren = <SemanticsNode>filled(newChildSemantics->length(), nullptr);
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        SemanticsNode oldChild = oldSemantics[oldChildrenTop];
        CustomPainterSemantics newSemantics = newChildSemantics[newChildrenTop];
        if (!_canUpdateSemanticsChild(oldChild, newSemantics)) {
            break;
        }
        SemanticsNode newChild = _updateSemanticsChild(oldChild, newSemantics);
        newChildren[newChildrenTop] = newChild;
        newChildrenTop += 1;
        oldChildrenTop += 1;
    }
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        SemanticsNode oldChild = oldSemantics[oldChildrenBottom];
        CustomPainterSemantics newChild = newChildSemantics[newChildrenBottom];
        if (!_canUpdateSemanticsChild(oldChild, newChild)) {
            break;
        }
        oldChildrenBottom -= 1;
        newChildrenBottom -= 1;
    }
    bool haveOldChildren = oldChildrenTop <= oldChildrenBottom;
    Map<Key, SemanticsNode> oldKeyedChildren;
    if (haveOldChildren) {
        oldKeyedChildren = makeMap(makeList(), makeList();
        while (oldChildrenTop <= oldChildrenBottom) {
            SemanticsNode oldChild = oldSemantics[oldChildrenTop];
            if (oldChild->key != nullptr) {
                oldKeyedChildren[oldChild->key!] = oldChild;
            }
            oldChildrenTop += 1;
        }
    }
    while (newChildrenTop <= newChildrenBottom) {
        SemanticsNode oldChild;
        CustomPainterSemantics newSemantics = newChildSemantics[newChildrenTop];
        if (haveOldChildren) {
            Key key = newSemantics->key;
            if (key != nullptr) {
                oldChild = oldKeyedChildren[key];
                if (oldChild != nullptr) {
                    if (_canUpdateSemanticsChild(oldChild, newSemantics)) {
                        oldKeyedChildren->remove(key);
                    } else {
                        oldChild = nullptr;
                    }
                }
            }
        }
        assert(oldChild == nullptr || _canUpdateSemanticsChild(oldChild, newSemantics));
        SemanticsNode newChild = _updateSemanticsChild(oldChild, newSemantics);
        assert(oldChild == newChild || oldChild == nullptr);
        newChildren[newChildrenTop] = newChild;
        newChildrenTop += 1;
    }
    assert(oldChildrenTop == oldChildrenBottom + 1);
    assert(newChildrenTop == newChildrenBottom + 1);
    assert(newChildSemantics->length() - newChildrenTop == oldSemantics->length() - oldChildrenTop);
    newChildrenBottom = newChildSemantics->length() - 1;
    oldChildrenBottom = oldSemantics->length() - 1;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        SemanticsNode oldChild = oldSemantics[oldChildrenTop];
        CustomPainterSemantics newSemantics = newChildSemantics[newChildrenTop];
        assert(_canUpdateSemanticsChild(oldChild, newSemantics));
        SemanticsNode newChild = _updateSemanticsChild(oldChild, newSemantics);
        assert(oldChild == newChild);
        newChildren[newChildrenTop] = newChild;
        newChildrenTop += 1;
        oldChildrenTop += 1;
    }
    assert([=] () {
        for (SemanticsNode node : newChildren) {
            assert(node != nullptr);
        }
        return true;
    }());
    return newChildren-><SemanticsNode>cast();
}

bool RenderCustomPaintCls::_canUpdateSemanticsChild(SemanticsNode oldChild, CustomPainterSemantics newSemantics) {
    return oldChild->key == newSemantics->key;
}

SemanticsNode RenderCustomPaintCls::_updateSemanticsChild(SemanticsNode oldChild, CustomPainterSemantics newSemantics) {
    assert(oldChild == nullptr || _canUpdateSemanticsChild(oldChild, newSemantics));
    SemanticsNode newChild = oldChild | make<SemanticsNodeCls>(newSemantics->key);
    SemanticsProperties properties = newSemantics->properties;
    SemanticsConfiguration config = make<SemanticsConfigurationCls>();
    if (properties->sortKey != nullptr) {
        config->sortKey() = properties->sortKey;
    }
    if (properties->checked != nullptr) {
        config->isChecked() = properties->checked;
    }
    if (properties->selected != nullptr) {
        config->isSelected() = properties->selected!;
    }
    if (properties->button != nullptr) {
        config->isButton() = properties->button!;
    }
    if (properties->link != nullptr) {
        config->isLink() = properties->link!;
    }
    if (properties->textField != nullptr) {
        config->isTextField() = properties->textField!;
    }
    if (properties->slider != nullptr) {
        config->isSlider() = properties->slider!;
    }
    if (properties->keyboardKey != nullptr) {
        config->isKeyboardKey() = properties->keyboardKey!;
    }
    if (properties->readOnly != nullptr) {
        config->isReadOnly() = properties->readOnly!;
    }
    if (properties->focusable != nullptr) {
        config->isFocusable() = properties->focusable!;
    }
    if (properties->focused != nullptr) {
        config->isFocused() = properties->focused!;
    }
    if (properties->enabled != nullptr) {
        config->isEnabled() = properties->enabled;
    }
    if (properties->inMutuallyExclusiveGroup != nullptr) {
        config->isInMutuallyExclusiveGroup() = properties->inMutuallyExclusiveGroup!;
    }
    if (properties->obscured != nullptr) {
        config->isObscured() = properties->obscured!;
    }
    if (properties->multiline != nullptr) {
        config->isMultiline() = properties->multiline!;
    }
    if (properties->hidden != nullptr) {
        config->isHidden() = properties->hidden!;
    }
    if (properties->header != nullptr) {
        config->isHeader() = properties->header!;
    }
    if (properties->scopesRoute != nullptr) {
        config->scopesRoute() = properties->scopesRoute!;
    }
    if (properties->namesRoute != nullptr) {
        config->namesRoute() = properties->namesRoute!;
    }
    if (properties->liveRegion != nullptr) {
        config->liveRegion() = properties->liveRegion!;
    }
    if (properties->maxValueLength != nullptr) {
        config->maxValueLength() = properties->maxValueLength;
    }
    if (properties->currentValueLength != nullptr) {
        config->currentValueLength() = properties->currentValueLength;
    }
    if (properties->toggled != nullptr) {
        config->isToggled() = properties->toggled;
    }
    if (properties->image != nullptr) {
        config->isImage() = properties->image!;
    }
    if (properties->label != nullptr) {
        config->label() = properties->label!;
    }
    if (properties->value != nullptr) {
        config->value() = properties->value!;
    }
    if (properties->increasedValue != nullptr) {
        config->increasedValue() = properties->increasedValue!;
    }
    if (properties->decreasedValue != nullptr) {
        config->decreasedValue() = properties->decreasedValue!;
    }
    if (properties->hint != nullptr) {
        config->hint() = properties->hint!;
    }
    if (properties->textDirection != nullptr) {
        config->textDirection() = properties->textDirection;
    }
    if (properties->onTap != nullptr) {
        config->onTap() = properties->onTap;
    }
    if (properties->onLongPress != nullptr) {
        config->onLongPress() = properties->onLongPress;
    }
    if (properties->onScrollLeft != nullptr) {
        config->onScrollLeft() = properties->onScrollLeft;
    }
    if (properties->onScrollRight != nullptr) {
        config->onScrollRight() = properties->onScrollRight;
    }
    if (properties->onScrollUp != nullptr) {
        config->onScrollUp() = properties->onScrollUp;
    }
    if (properties->onScrollDown != nullptr) {
        config->onScrollDown() = properties->onScrollDown;
    }
    if (properties->onIncrease != nullptr) {
        config->onIncrease() = properties->onIncrease;
    }
    if (properties->onDecrease != nullptr) {
        config->onDecrease() = properties->onDecrease;
    }
    if (properties->onCopy != nullptr) {
        config->onCopy() = properties->onCopy;
    }
    if (properties->onCut != nullptr) {
        config->onCut() = properties->onCut;
    }
    if (properties->onPaste != nullptr) {
        config->onPaste() = properties->onPaste;
    }
    if (properties->onMoveCursorForwardByCharacter != nullptr) {
        config->onMoveCursorForwardByCharacter() = properties->onMoveCursorForwardByCharacter;
    }
    if (properties->onMoveCursorBackwardByCharacter != nullptr) {
        config->onMoveCursorBackwardByCharacter() = properties->onMoveCursorBackwardByCharacter;
    }
    if (properties->onMoveCursorForwardByWord != nullptr) {
        config->onMoveCursorForwardByWord() = properties->onMoveCursorForwardByWord;
    }
    if (properties->onMoveCursorBackwardByWord != nullptr) {
        config->onMoveCursorBackwardByWord() = properties->onMoveCursorBackwardByWord;
    }
    if (properties->onSetSelection != nullptr) {
        config->onSetSelection() = properties->onSetSelection;
    }
    if (properties->onSetText != nullptr) {
        config->onSetText() = properties->onSetText;
    }
    if (properties->onDidGainAccessibilityFocus != nullptr) {
        config->onDidGainAccessibilityFocus() = properties->onDidGainAccessibilityFocus;
    }
    if (properties->onDidLoseAccessibilityFocus != nullptr) {
        config->onDidLoseAccessibilityFocus() = properties->onDidLoseAccessibilityFocus;
    }
    if (properties->onDismiss != nullptr) {
        config->onDismiss() = properties->onDismiss;
    }
    newChild->updateWith(config, makeList());
    auto _c1 = newChild;_c1.rect = auto _c2 = newSemantics->rect;_c2.transform = auto _c3 = newSemantics->transform;_c3.tags = newSemantics->tags;_c3;_c2;_c1;
    return newChild;
}
