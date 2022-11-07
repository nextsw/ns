#ifndef TWEENS_H
#define TWEENS_H
#include <memory>

#include <flutter/animation.hpp>
#include <flutter/painting.hpp>



class FractionalOffsetTween : Tween<FractionalOffset> {
public:

     FractionalOffsetTween(Unknown, Unknown);

    FractionalOffset lerp(double t);

private:

};

class AlignmentTween : Tween<Alignment> {
public:

     AlignmentTween(Unknown, Unknown);

    Alignment lerp(double t);

private:

};

class AlignmentGeometryTween : Tween<AlignmentGeometry> {
public:

     AlignmentGeometryTween(Unknown, Unknown);

    AlignmentGeometry lerp(double t);

private:

};

#endif