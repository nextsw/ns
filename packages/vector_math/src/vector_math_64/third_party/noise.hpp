#ifndef NOISE_H
#define NOISE_H
#include <memory>




class SimplexNoise {
public:

     SimplexNoise(Random r);

    double noise2D(double xin, double yin);

    double noise3D(double xin, double yin, double zin);

    double noise4D(double w, double x, double y, double z);

private:
    static List<List<double>> _grad3;

    static List<List<double>> _grad4;

    List<int> _perm;

    List<int> _permMod12;

    static auto  _F2;

    static auto  _G2;

    static const double _f3;

    static const double _g3;

    static auto  _F4;

    static auto  _G4;


    double _dot2(List<double> g, double x, double y);

    double _dot3(List<double> g, double x, double y, double z);

    double _dot4(List<double> g, double w, double x, double y, double z);

};

#endif