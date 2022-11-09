#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_TWEENS
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_TWEENS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>


class FractionalOffsetTweenCls : public TweenCls<FractionalOffset> {
public:

     FractionalOffsetTweenCls(Unknown begin, Unknown end);
    virtual FractionalOffset lerp(double t);

private:

};
using FractionalOffsetTween = std::shared_ptr<FractionalOffsetTweenCls>;

class AlignmentTweenCls : public TweenCls<Alignment> {
public:

     AlignmentTweenCls(Unknown begin, Unknown end);
    virtual Alignment lerp(double t);

private:

};
using AlignmentTween = std::shared_ptr<AlignmentTweenCls>;

class AlignmentGeometryTweenCls : public TweenCls<AlignmentGeometry> {
public:

     AlignmentGeometryTweenCls(Unknown begin, Unknown end);
    virtual AlignmentGeometry lerp(double t);

private:

};
using AlignmentGeometryTween = std::shared_ptr<AlignmentGeometryTweenCls>;


#endif