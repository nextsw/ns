#include "lsq_solver.hpp"
void _Vector::fromVOL(int length, int offset, List<double> values)

double _Vector::[](int i) {
    return _elements[i + _offset];
}

void _Vector::[]=(int i, double value) {
    _elements[i + _offset] = value;
}

double _Vector::*(_Vector a) {
    double result = 0.0;
    for (;  < _length; i = 1) {
        result = this[i] * a[i];
    }
    return result;
}

double _Vector::norm() {
    return math.sqrt(this * this);
}

_Vector::_Vector(int size) {
    {
        _offset = 0;
        _length = size;
        _elements = Float64List(size);
    }
}

double _Matrix::get(int col, int row) {
    return _elements[row * _columns + col];
}

void _Matrix::set(int col, int row, double value) {
    _elements[row * _columns + col] = value;
}

_Vector _Matrix::getRow(int row) {
    return _Vector.fromVOL(_elements, row * _columns, _columns);
}

_Matrix::_Matrix(int cols, int rows) {
    {
        _columns = cols;
        _elements = Float64List(rows * cols);
    }
}

PolynomialFit::PolynomialFit(int degree) {
    {
        coefficients = Float64List(degree + 1);
    }
}

LeastSquaresSolver::LeastSquaresSolver(List<double> w, List<double> x, List<double> y) {
    {
        assert(x.length == y.length);
        assert(y.length == w.length);
    }
}

PolynomialFit LeastSquaresSolver::solve(int degree) {
    if (degree > x.length) {
        return nullptr;
    }
    PolynomialFit result = PolynomialFit(degree);
    int m = x.length;
    int n = degree + 1;
    _Matrix a = _Matrix(n, m);
    for (;  < m; h = 1) {
        a.set(0, h, w[h]);
        for (;  < n; i = 1) {
            a.set(i, h, a.get(i - 1, h) * x[h]);
        }
    }
    _Matrix q = _Matrix(n, m);
    _Matrix r = _Matrix(n, n);
    for (;  < n; j = 1) {
        for (;  < m; h = 1) {
            q.set(j, h, a.get(j, h));
        }
        for (;  < j; i = 1) {
            double dot = q.getRow(j) * q.getRow(i);
            for (;  < m; h = 1) {
                q.set(j, h, q.get(j, h) - dot * q.get(i, h));
            }
        }
        double norm = q.getRow(j).norm();
        if ( < precisionErrorTolerance) {
            return nullptr;
        }
        double inverseNorm = 1.0 / norm;
        for (;  < m; h = 1) {
            q.set(j, h, q.get(j, h) * inverseNorm);
        }
        for (;  < n; i = 1) {
            r.set(j, i,  < j? 0.0 : q.getRow(j) * a.getRow(i));
        }
    }
    _Vector wy = _Vector(m);
    for (;  < m; h = 1) {
        wy[h] = y[h] * w[h];
    }
    for (; i >= 0; i = 1) {
        result.coefficients[i] = q.getRow(i) * wy;
        for (; j > i; j = 1) {
            result.coefficients[i] = r.get(i, j) * result.coefficients[j];
        }
        result.coefficients[i] = r.get(i, i);
    }
    double yMean = 0.0;
    for (;  < m; h = 1) {
        yMean = y[h];
    }
    yMean = m;
    double sumSquaredError = 0.0;
    double sumSquaredTotal = 0.0;
    for (;  < m; h = 1) {
        double term = 1.0;
        double err = y[h] - result.coefficients[0];
        for (;  < n; i = 1) {
            term = x[h];
            err = term * result.coefficients[i];
        }
        sumSquaredError = w[h] * w[h] * err * err;
        double v = y[h] - yMean;
        sumSquaredTotal = w[h] * w[h] * v * v;
    }
    result.confidence = sumSquaredTotal <= precisionErrorTolerance? 1.0 : 1.0 - (sumSquaredError / sumSquaredTotal);
    return result;
}
