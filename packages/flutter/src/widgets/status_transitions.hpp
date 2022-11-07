#ifndef STATUS_TRANSITIONS_H
#define STATUS_TRANSITIONS_H
#include <memory>

#include "basic.hpp"
#include "framework.hpp"



class StatusTransitionWidget : StatefulWidget {
public:
    Animation<double> animation;


     StatusTransitionWidget(Animation<double> animation, Unknown);

    Widget build(BuildContext context);

    State<StatusTransitionWidget> createState();

private:

};

class _StatusTransitionState : State<StatusTransitionWidget> {
public:

    void initState();

    void didUpdateWidget(StatusTransitionWidget oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:

    void _animationStatusChanged(AnimationStatus status);

};

#endif