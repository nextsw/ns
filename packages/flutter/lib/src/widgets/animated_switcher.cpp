#include "animated_switcher.hpp"
String _ChildEntryCls::toString() {
    return __s("Entry#${shortHash(this)}($widgetChild)");
}

_ChildEntryCls::_ChildEntryCls(Animation<double> animation, AnimationController controller, Widget transition, Widget widgetChild) {
    {
        assert(animation != nullptr);
        assert(transition != nullptr);
        assert(controller != nullptr);
    }
}

AnimatedSwitcherCls::AnimatedSwitcherCls(Widget child, Duration duration, Key key, AnimatedSwitcherLayoutBuilder layoutBuilder, Duration reverseDuration, Curve switchInCurve, Curve switchOutCurve, AnimatedSwitcherTransitionBuilder transitionBuilder) {
    {
        assert(duration != nullptr);
        assert(switchInCurve != nullptr);
        assert(switchOutCurve != nullptr);
        assert(transitionBuilder != nullptr);
        assert(layoutBuilder != nullptr);
    }
}

State<AnimatedSwitcher> AnimatedSwitcherCls::createState() {
    return make<_AnimatedSwitcherStateCls>();
}

Widget AnimatedSwitcherCls::defaultTransitionBuilder(Widget child, Animation<double> animation) {
    return make<FadeTransitionCls>(animation, child);
}

Widget AnimatedSwitcherCls::defaultLayoutBuilder(Widget currentChild, List<Widget> previousChildren) {
    List<Widget> list1 = make<ListCls<>>();for (auto _x1 : previousChildren) {{    list1.add(_x1);}if (currentChild != nullptr) {    list1.add(ArrayItem);}return make<StackCls>(AlignmentCls::center, list1);
}

void AnimatedSwitcherCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("duration"), duration->inMilliseconds(), __s("ms")));
    properties->add(make<IntPropertyCls>(__s("reverseDuration"), reverseDuration?->inMilliseconds(), __s("ms"), nullptr));
}

void _AnimatedSwitcherStateCls::initState() {
    super->initState();
    _addEntryForNewChild(false);
}

void _AnimatedSwitcherStateCls::didUpdateWidget(AnimatedSwitcher oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->transitionBuilder != oldWidget->transitionBuilder) {
        _outgoingEntries->forEach(_updateTransitionForEntry);
        if (_currentEntry != nullptr) {
            _updateTransitionForEntry(_currentEntry!);
        }
        _markChildWidgetCacheAsDirty();
    }
    bool hasNewChild = widget()->child != nullptr;
    bool hasOldChild = _currentEntry != nullptr;
    if (hasNewChild != hasOldChild || hasNewChild && !WidgetCls->canUpdate(widget()->child!, _currentEntry!->widgetChild)) {
        _childNumber += 1;
        _addEntryForNewChild(true);
    } else {
        if (_currentEntry != nullptr) {
        assert(hasOldChild && hasNewChild);
        assert(WidgetCls->canUpdate(widget()->child!, _currentEntry!->widgetChild));
        _currentEntry!->widgetChild = widget()->child!;
        _updateTransitionForEntry(_currentEntry!);
        _markChildWidgetCacheAsDirty();
    }
;
    }}

void _AnimatedSwitcherStateCls::dispose() {
    if (_currentEntry != nullptr) {
        _currentEntry!->controller->dispose();
    }
    for (_ChildEntry entry : _outgoingEntries) {
        entry->controller->dispose();
    }
    super->dispose();
}

Widget _AnimatedSwitcherStateCls::build(BuildContext context) {
    _rebuildOutgoingWidgetsIfNeeded();
    return widget()->layoutBuilder(_currentEntry?->transition, _outgoingWidgets!);
}

void _AnimatedSwitcherStateCls::_addEntryForNewChild(bool animate) {
    assert(animate || _currentEntry == nullptr);
    if (_currentEntry != nullptr) {
        assert(animate);
        assert(!_outgoingEntries->contains(_currentEntry));
        _outgoingEntries->add(_currentEntry!);
        _currentEntry!->controller->reverse();
        _markChildWidgetCacheAsDirty();
        _currentEntry = nullptr;
    }
    if (widget()->child == nullptr) {
        return;
    }
    AnimationController controller = make<AnimationControllerCls>(widget()->duration, widget()->reverseDuration, this);
    Animation<double> animation = make<CurvedAnimationCls>(controller, widget()->switchInCurve, widget()->switchOutCurve);
    _currentEntry = _newEntry(widget()->child!, controller, animation, widget()->transitionBuilder);
    if (animate) {
        controller->forward();
    } else {
        assert(_outgoingEntries->isEmpty());
        controller->value() = 1.0;
    }
}

_ChildEntry _AnimatedSwitcherStateCls::_newEntry(Animation<double> animation, AnimatedSwitcherTransitionBuilder builder, Widget child, AnimationController controller) {
    _ChildEntry entry = make<_ChildEntryCls>(child, KeyedSubtreeCls->wrap(builder(child, animation), _childNumber), animation, controller);
    animation->addStatusListener([=] (AnimationStatus status) {
        if (status == AnimationStatusCls::dismissed) {
            setState([=] () {
                assert(mounted());
                assert(_outgoingEntries->contains(entry));
                _outgoingEntries->remove(entry);
                _markChildWidgetCacheAsDirty();
            });
            controller->dispose();
        }
    });
    return entry;
}

void _AnimatedSwitcherStateCls::_markChildWidgetCacheAsDirty() {
    _outgoingWidgets = nullptr;
}

void _AnimatedSwitcherStateCls::_updateTransitionForEntry(_ChildEntry entry) {
    entry->transition = make<KeyedSubtreeCls>(entry->transition->key, widget()->transitionBuilder(entry->widgetChild, entry->animation));
}

void _AnimatedSwitcherStateCls::_rebuildOutgoingWidgetsIfNeeded() {
    _outgoingWidgets |= <Widget>unmodifiable(_outgoingEntries-><Widget>map([=] (_ChildEntry entry) {
        entry->transition;
    }));
    assert(_outgoingEntries->length() == _outgoingWidgets!->length());
    assert(_outgoingEntries->isEmpty() || _outgoingEntries->last()->transition == _outgoingWidgets!->last);
}
