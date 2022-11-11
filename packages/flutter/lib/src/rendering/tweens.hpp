#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_TWEENS
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_TWEENS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>


class FractionalOffsetTweenCls : public TweenCls<FractionalOffset> {
public:

     FractionalOffsetTweenCls(T begin, T end);
    virtual FractionalOffset lerp(double t);

private:

};
using FractionalOffsetTween = std::shared_ptr<FractionalOffsetTweenCls>;

class AlignmentTweenCls : public TweenCls<Alignment> {
public:

     AlignmentTweenCls(T begin, T end);
    virtual Alignment lerp(double t);

private:

};
using AlignmentTween = std::shared_ptr<AlignmentTweenCls>;

class AlignmentGeometryTweenCls : public TweenCls<AlignmentGeometry> {
public:

     AlignmentGeometryTweenCls(T begin, T end);
    virtual AlignmentGeometry lerp(double t);

private:

};
using AlignmentGeometryTween = std::shared_ptr<AlignmentGeometryTweenCls>;


#endif