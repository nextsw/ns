#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_SWITCHER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_SWITCHER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"


class _ChildEntryCls : public ObjectCls {
public:
    AnimationController controller;

    Animation<double> animation;

    Widget transition;

    Widget widgetChild;


    virtual String toString();

private:

     _ChildEntryCls(Animation<double> animation, AnimationController controller, Widget transition, Widget widgetChild);

};
using _ChildEntry = std::shared_ptr<_ChildEntryCls>;

class AnimatedSwitcherCls : public StatefulWidgetCls {
public:
    Widget child;

    Duration duration;

    Duration reverseDuration;

    Curve switchInCurve;

    Curve switchOutCurve;

    AnimatedSwitcherTransitionBuilder transitionBuilder;

    AnimatedSwitcherLayoutBuilder layoutBuilder;


     AnimatedSwitcherCls(Widget child, Duration duration, Unknown key, AnimatedSwitcherLayoutBuilder layoutBuilder, Duration reverseDuration, Curve switchInCurve, Curve switchOutCurve, AnimatedSwitcherTransitionBuilder transitionBuilder);

    virtual State<AnimatedSwitcher> createState();

    static Widget defaultTransitionBuilder(Widget child, Animation<double> animation);

    static Widget defaultLayoutBuilder(Widget currentChild, List<Widget> previousChildren);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedSwitcher = std::shared_ptr<AnimatedSwitcherCls>;

class _AnimatedSwitcherStateCls : public StateCls<AnimatedSwitcher> {
public:

    virtual void initState();

    virtual void didUpdateWidget(AnimatedSwitcher oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    _ChildEntry _currentEntry;

    Set<_ChildEntry> _outgoingEntries;

    List<Widget> _outgoingWidgets;

    int _childNumber;


    virtual void _addEntryForNewChild(bool animate);

    virtual _ChildEntry _newEntry(Animation<double> animation, AnimatedSwitcherTransitionBuilder builder, Widget child, AnimationController controller);

    virtual void _markChildWidgetCacheAsDirty();

    virtual void _updateTransitionForEntry(_ChildEntry entry);

    virtual void _rebuildOutgoingWidgetsIfNeeded();

};
using _AnimatedSwitcherState = std::shared_ptr<_AnimatedSwitcherStateCls>;


#endif