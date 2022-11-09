#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_THIRD_PARTY_NOISE
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_THIRD_PARTY_NOISE
#include <base.hpp>

#include <dart/core/core.hpp>


class SimplexNoiseCls : public ObjectCls {
public:

     SimplexNoiseCls(Random r);

    virtual double noise2D(double xin, double yin);

    virtual double noise3D(double xin, double yin, double zin);

    virtual double noise4D(double w, double x, double y, double z);

private:
    static List<List<double>> _grad3;

    static List<List<double>> _grad4;

    List<int> _perm;

    List<int> _permMod12;

    static auto  _F2;

    static auto  _G2;

    static double _f3;

    static double _g3;

    static auto  _F4;

    static auto  _G4;


    virtual double _dot2(List<double> g, double x, double y);

    virtual double _dot3(List<double> g, double x, double y, double z);

    virtual double _dot4(List<double> g, double w, double x, double y, double z);

};
using SimplexNoise = std::shared_ptr<SimplexNoiseCls>;


#endif