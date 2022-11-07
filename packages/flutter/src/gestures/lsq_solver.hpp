#ifndef LSQ_SOLVER_H
#define LSQ_SOLVER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>



class _Vector {
public:

    void  fromVOL(int length, int offset, List<double> values);

    double [](int i);

    void []=(int i, double value);

    double *(_Vector a);

    double norm();

private:
    int _offset;

    int _length;

    List<double> _elements;


     _Vector(int size);

};

class _Matrix {
public:

    double get(int col, int row);

    void set(int col, int row, double value);

    _Vector getRow(int row);

private:
    int _columns;

    List<double> _elements;


     _Matrix(int cols, int rows);

};

class PolynomialFit {
public:
    List<double> coefficients;

    double confidence;


     PolynomialFit(int degree);

private:

};

class LeastSquaresSolver {
public:
    List<double> x;

    List<double> y;

    List<double> w;


     LeastSquaresSolver(List<double> w, List<double> x, List<double> y);

    PolynomialFit solve(int degree);

private:

};

#endif