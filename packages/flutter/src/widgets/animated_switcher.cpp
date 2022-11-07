#include "animated_switcher.hpp"
String _ChildEntry::toString() {
    return "Entry#${shortHash(this)}($widgetChild)";
}

_ChildEntry::_ChildEntry(Animation<double> animation, AnimationController controller, Widget transition, Widget widgetChild) {
    {
        assert(animation != nullptr);
        assert(transition != nullptr);
        assert(controller != nullptr);
    }
}

AnimatedSwitcher::AnimatedSwitcher(Widget child, Duration duration, Unknown, AnimatedSwitcherLayoutBuilder layoutBuilder, Duration reverseDuration, Curve switchInCurve, Curve switchOutCurve, AnimatedSwitcherTransitionBuilder transitionBuilder) {
    {
        assert(duration != nullptr);
        assert(switchInCurve != nullptr);
        assert(switchOutCurve != nullptr);
        assert(transitionBuilder != nullptr);
        assert(layoutBuilder != nullptr);
    }
}

State<AnimatedSwitcher> AnimatedSwitcher::createState() {
    return _AnimatedSwitcherState();
}

Widget AnimatedSwitcher::defaultTransitionBuilder(Animation<double> animation, Widget child) {
    return FadeTransition(animation, child);
}

Widget AnimatedSwitcher::defaultLayoutBuilder(Widget currentChild, List<Widget> previousChildren) {
    return Stack(Alignment.center, );
}

void AnimatedSwitcher::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("duration", duration.inMilliseconds"ms"));
    properties.add(IntProperty("reverseDuration", reverseDuration?.inMilliseconds"ms", nullptr));
}

void _AnimatedSwitcherState::initState() {
    super.initState();
    _addEntryForNewChild(false);
}

void _AnimatedSwitcherState::didUpdateWidget(AnimatedSwitcher oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.transitionBuilder != oldWidget.transitionBuilder) {
        _outgoingEntries.forEach(_updateTransitionForEntry);
        if (_currentEntry != nullptr) {
            _updateTransitionForEntry(_currentEntry!);
        }
        _markChildWidgetCacheAsDirty();
    }
    bool hasNewChild = widget.child != nullptr;
    bool hasOldChild = _currentEntry != nullptr;
    if (hasNewChild != hasOldChild || hasNewChild && !Widget.canUpdate(widget.child!, _currentEntry!.widgetChild)) {
        _childNumber = 1;
        _addEntryForNewChild(true);
    } else     {
        if (_currentEntry != nullptr) {
        assert(hasOldChild && hasNewChild);
        assert(Widget.canUpdate(widget.child!, _currentEntry!.widgetChild));
        _currentEntry!.widgetChild = widget.child!;
        _updateTransitionForEntry(_currentEntry!);
        _markChildWidgetCacheAsDirty();
    }
;
    }}

void _AnimatedSwitcherState::dispose() {
    if (_currentEntry != nullptr) {
        _currentEntry!.controller.dispose();
    }
    for (_ChildEntry entry : _outgoingEntries) {
        entry.controller.dispose();
    }
    super.dispose();
}

Widget _AnimatedSwitcherState::build(BuildContext context) {
    _rebuildOutgoingWidgetsIfNeeded();
    return widget.layoutBuilder(_currentEntry?.transition, _outgoingWidgets!);
}

void _AnimatedSwitcherState::_addEntryForNewChild(bool animate) {
    assert(animate || _currentEntry == nullptr);
    if (_currentEntry != nullptr) {
        assert(animate);
        assert(!_outgoingEntries.contains(_currentEntry));
        _outgoingEntries.add(_currentEntry!);
        _currentEntry!.controller.reverse();
        _markChildWidgetCacheAsDirty();
        _currentEntry = nullptr;
    }
    if (widget.child == nullptr) {
        return;
    }
    AnimationController controller = AnimationController(widget.duration, widget.reverseDuration, this);
    Animation<double> animation = CurvedAnimation(controller, widget.switchInCurve, widget.switchOutCurve);
    _currentEntry = _newEntry(widget.child!, controller, animation, widget.transitionBuilder);
    if (animate) {
        controller.forward();
    } else {
        assert(_outgoingEntries.isEmpty);
        controller.value = 1.0;
    }
}

_ChildEntry _AnimatedSwitcherState::_newEntry(Animation<double> animation, AnimatedSwitcherTransitionBuilder builder, Widget child, AnimationController controller) {
    _ChildEntry entry = _ChildEntry(child, KeyedSubtree.wrap(builder(child, animation), _childNumber), animation, controller);
    animation.addStatusListener();
    return entry;
}

void _AnimatedSwitcherState::_markChildWidgetCacheAsDirty() {
    _outgoingWidgets = nullptr;
}

void _AnimatedSwitcherState::_updateTransitionForEntry(_ChildEntry entry) {
    entry.transition = KeyedSubtree(entry.transition.key, widget.transitionBuilder(entry.widgetChild, entry.animation));
}

void _AnimatedSwitcherState::_rebuildOutgoingWidgetsIfNeeded() {
    _outgoingWidgets = <Widget>unmodifiable(_outgoingEntries.<Widget>map());
    assert(_outgoingEntries.length == _outgoingWidgets!.length);
    assert(_outgoingEntries.isEmpty || _outgoingEntries.last.transition == _outgoingWidgets!.last);
}
