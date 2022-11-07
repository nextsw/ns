#ifndef ANIMATED_SWITCHER_H
#define ANIMATED_SWITCHER_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"



class _ChildEntry {
public:
    AnimationController controller;

    Animation<double> animation;

    Widget transition;

    Widget widgetChild;


    String toString();

private:

     _ChildEntry(Animation<double> animation, AnimationController controller, Widget transition, Widget widgetChild);

};

class AnimatedSwitcher : StatefulWidget {
public:
    Widget child;

    Duration duration;

    Duration reverseDuration;

    Curve switchInCurve;

    Curve switchOutCurve;

    AnimatedSwitcherTransitionBuilder transitionBuilder;

    AnimatedSwitcherLayoutBuilder layoutBuilder;


     AnimatedSwitcher(Widget child, Duration duration, Unknown, AnimatedSwitcherLayoutBuilder layoutBuilder, Duration reverseDuration, Curve switchInCurve, Curve switchOutCurve, AnimatedSwitcherTransitionBuilder transitionBuilder);

    State<AnimatedSwitcher> createState();

    static Widget defaultTransitionBuilder(Animation<double> animation, Widget child);

    static Widget defaultLayoutBuilder(Widget currentChild, List<Widget> previousChildren);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedSwitcherState : State<AnimatedSwitcher> {
public:

    void initState();

    void didUpdateWidget(AnimatedSwitcher oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    _ChildEntry _currentEntry;

    Set<_ChildEntry> _outgoingEntries;

    List<Widget> _outgoingWidgets;

    int _childNumber;


    void _addEntryForNewChild(bool animate);

    _ChildEntry _newEntry(Animation<double> animation, AnimatedSwitcherTransitionBuilder builder, Widget child, AnimationController controller);

    void _markChildWidgetCacheAsDirty();

    void _updateTransitionForEntry(_ChildEntry entry);

    void _rebuildOutgoingWidgetsIfNeeded();

};

#endif