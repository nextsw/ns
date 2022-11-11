#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_STATUS_TRANSITIONS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_STATUS_TRANSITIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include "basic.hpp"
#include "framework.hpp"


class StatusTransitionWidgetCls : public StatefulWidgetCls {
public:
    Animation<double> animation;


     StatusTransitionWidgetCls(Animation<double> animation, Key key);

    virtual Widget build(BuildContext context);
    virtual State<StatusTransitionWidget> createState();

private:

};
using StatusTransitionWidget = std::shared_ptr<StatusTransitionWidgetCls>;

class _StatusTransitionStateCls : public StateCls<StatusTransitionWidget> {
public:

    virtual void initState();

    virtual void didUpdateWidget(StatusTransitionWidget oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

    virtual void _animationStatusChanged(AnimationStatus status);

};
using _StatusTransitionState = std::shared_ptr<_StatusTransitionStateCls>;


#endif