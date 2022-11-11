#include "lsq_solver.hpp"
void _VectorCls::fromVOL(int length, int offset, List<double> values)

double _VectorCls::[](int i) {
    return _elements[i + _offset];
}

void _VectorCls::[]=(int i, double value) {
    _elements[i + _offset] = value;
}

double _VectorCls::*(_Vector a) {
    double result = 0.0;
    for (;  < _length; i = 1) {
        result = this[i] * a[i];
    }
    return result;
}

double _VectorCls::norm() {
    return math->sqrt(this * this);
}

_VectorCls::_VectorCls(int size) {
    {
        _offset = 0;
        _length = size;
        _elements = make<Float64ListCls>(size);
    }
}

double _MatrixCls::get(int col, int row) {
    return _elements[row * _columns + col];
}

void _MatrixCls::set(int col, int row, double value) {
    _elements[row * _columns + col] = value;
}

_Vector _MatrixCls::getRow(int row) {
    return _VectorCls->fromVOL(_elements, row * _columns, _columns);
}

_MatrixCls::_MatrixCls(int cols, int rows) {
    {
        _columns = cols;
        _elements = make<Float64ListCls>(rows * cols);
    }
}

PolynomialFitCls::PolynomialFitCls(int degree) {
    {
        coefficients = make<Float64ListCls>(degree + 1);
    }
}

LeastSquaresSolverCls::LeastSquaresSolverCls(List<double> w, List<double> x, List<double> y) {
    {
        assert(x->length == y->length);
        assert(y->length == w->length);
    }
}

PolynomialFit LeastSquaresSolverCls::solve(int degree) {
    if (degree > x->length) {
        return nullptr;
    }
    PolynomialFit result = make<PolynomialFitCls>(degree);
    int m = x->length;
    int n = degree + 1;
    _Matrix a = make<_MatrixCls>(n, m);
    for (;  < m; h = 1) {
        a->set(0, h, w[h]);
        for (;  < n; i = 1) {
            a->set(i, h, a->get(i - 1, h) * x[h]);
        }
    }
    _Matrix q = make<_MatrixCls>(n, m);
    _Matrix r = make<_MatrixCls>(n, n);
    for (;  < n; j = 1) {
        for (;  < m; h = 1) {
            q->set(j, h, a->get(j, h));
        }
        for (;  < j; i = 1) {
            double dot = q->getRow(j) * q->getRow(i);
            for (;  < m; h = 1) {
                q->set(j, h, q->get(j, h) - dot * q->get(i, h));
            }
        }
        double norm = q->getRow(j)->norm();
        if ( < precisionErrorTolerance) {
            return nullptr;
        }
        double inverseNorm = 1.0 / norm;
        for (;  < m; h = 1) {
            q->set(j, h, q->get(j, h) * inverseNorm);
        }
        for (;  < n; i = 1) {
            r->set(j, i,  < j? 0.0 : q->getRow(j) * a->getRow(i));
        }
    }
    _Vector wy = make<_VectorCls>(m);
    for (;  < m; h = 1) {
        wy[h] = y[h] * w[h];
    }
    for (; i >= 0; i = 1) {
        result->coefficients[i] = q->getRow(i) * wy;
        for (; j > i; j = 1) {
            result->coefficients[i] = r->get(i, j) * result->coefficients[j];
        }
        result->coefficients[i] = r->get(i, i);
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
        double err = y[h] - result->coefficients[0];
        for (;  < n; i = 1) {
            term = x[h];
            err = term * result->coefficients[i];
        }
        sumSquaredError = w[h] * w[h] * err * err;
        double v = y[h] - yMean;
        sumSquaredTotal = w[h] * w[h] * v * v;
    }
    result->confidence = sumSquaredTotal <= precisionErrorTolerance? 1.0 : 1.0 - (sumSquaredError / sumSquaredTotal);
    return result;
}
