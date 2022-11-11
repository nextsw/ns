#ifndef PACKAGES_FLUTTER_SRC_GESTURES_LSQ_SOLVER
#define PACKAGES_FLUTTER_SRC_GESTURES_LSQ_SOLVER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>


class _VectorCls : public ObjectCls {
public:

    virtual void  fromVOL(List<double> values, int offset, int length);

    virtual double operator[](int i);

    virtual void operator[]=(int i, double value);

    virtual double operator*(_Vector a);

    virtual double norm();

private:
    int _offset;

    int _length;

    List<double> _elements;


     _VectorCls(int size);

};
using _Vector = std::shared_ptr<_VectorCls>;

class _MatrixCls : public ObjectCls {
public:

    virtual double get(int row, int col);

    virtual void set(int row, int col, double value);

    virtual _Vector getRow(int row);

private:
    int _columns;

    List<double> _elements;


     _MatrixCls(int rows, int cols);

};
using _Matrix = std::shared_ptr<_MatrixCls>;

class PolynomialFitCls : public ObjectCls {
public:
    List<double> coefficients;

    double confidence;


     PolynomialFitCls(int degree);

private:

};
using PolynomialFit = std::shared_ptr<PolynomialFitCls>;

class LeastSquaresSolverCls : public ObjectCls {
public:
    List<double> x;

    List<double> y;

    List<double> w;


     LeastSquaresSolverCls(List<double> x, List<double> y, List<double> w);

    virtual PolynomialFit solve(int degree);

private:

};
using LeastSquaresSolver = std::shared_ptr<LeastSquaresSolverCls>;


#endif