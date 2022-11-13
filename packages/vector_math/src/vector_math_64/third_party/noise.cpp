#include "noise.hpp"
SimplexNoiseCls::SimplexNoiseCls(Random r) {
    {
        r |= math->make<RandomCls>();
        auto p = <int>generate(256, [=] (Unknown  _) {
    r!->nextInt(256);
}, false);
        _perm = <int>generate(p->length * 2, [=] (int i) {
            p[i % p->length];
        }, false);
        _permMod12 = <int>generate(_perm->length(), [=] (int i) {
            _perm[i] % 12;
        }, false);
    }
}

double SimplexNoiseCls::noise2D(double xin, double yin) {
    double n0, n1, n2;
    auto s = (xin + yin) * _F2;
    auto i = (xin + s)->floor();
    auto j = (yin + s)->floor();
    auto t = (i + j) * _G2;
    auto X0 = i - t;
    auto Y0 = j - t;
    auto x0 = xin - X0;
    auto y0 = yin - Y0;
    int i1, j1;
    if (x0 > y0) {
        i1 = 1;
        j1 = 0;
    } else {
        i1 = 0;
        j1 = 1;
    }
    auto x1 = x0 - i1 + _G2;
    auto y1 = y0 - j1 + _G2;
    auto x2 = x0 - 1.0 + 2.0 * _G2;
    auto y2 = y0 - 1.0 + 2.0 * _G2;
    auto ii = i & 255;
    auto jj = j & 255;
    auto gi0 = _permMod12[ii + _perm[jj]];
    auto gi1 = _permMod12[ii + i1 + _perm[jj + j1]];
    auto gi2 = _permMod12[ii + 1 + _perm[jj + 1]];
    auto t0 = 0.5 - x0 * x0 - y0 * y0;
    if ( < 0) {
        n0 = 0.0;
    } else {
        t0 *= t0;
        n0 = t0 * t0 * _dot2(_grad3[gi0], x0, y0);
    }
    auto t1 = 0.5 - x1 * x1 - y1 * y1;
    if ( < 0) {
        n1 = 0.0;
    } else {
        t1 *= t1;
        n1 = t1 * t1 * _dot2(_grad3[gi1], x1, y1);
    }
    auto t2 = 0.5 - x2 * x2 - y2 * y2;
    if ( < 0) {
        n2 = 0.0;
    } else {
        t2 *= t2;
        n2 = t2 * t2 * _dot2(_grad3[gi2], x2, y2);
    }
    return 70.0 * (n0 + n1 + n2);
}

double SimplexNoiseCls::noise3D(double xin, double yin, double zin) {
    double n0, n1, n2, n3;
    auto s = (xin + yin + zin) * _f3;
    auto i = (xin + s)->floor();
    auto j = (yin + s)->floor();
    auto k = (zin + s)->floor();
    auto t = (i + j + k) * _g3;
    auto X0 = i - t;
    auto Y0 = j - t;
    auto Z0 = k - t;
    auto x0 = xin - X0;
    auto y0 = yin - Y0;
    auto z0 = zin - Z0;
    int i1, j1, k1;
    int i2, j2, k2;
    if (x0 >= y0) {
        if (y0 >= z0) {
            i1 = 1;
            j1 = 0;
            k1 = 0;
            i2 = 1;
            j2 = 1;
            k2 = 0;
        } else {
            if (x0 >= z0) {
            i1 = 1;
            j1 = 0;
            k1 = 0;
            i2 = 1;
            j2 = 0;
            k2 = 1;
        } else {
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 1;
            j2 = 0;
            k2 = 1;
        }
;
        }    } else {
        if ( < z0) {
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 0;
            j2 = 1;
            k2 = 1;
        } else {
            if ( < z0) {
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 0;
            j2 = 1;
            k2 = 1;
        } else {
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 1;
            j2 = 1;
            k2 = 0;
        }
;
        }    }
    auto x1 = x0 - i1 + _g3;
    auto y1 = y0 - j1 + _g3;
    auto z1 = z0 - k1 + _g3;
    auto x2 = x0 - i2 + 2.0 * _g3;
    auto y2 = y0 - j2 + 2.0 * _g3;
    auto z2 = z0 - k2 + 2.0 * _g3;
    auto x3 = x0 - 1.0 + 3.0 * _g3;
    auto y3 = y0 - 1.0 + 3.0 * _g3;
    auto z3 = z0 - 1.0 + 3.0 * _g3;
    auto ii = i & 255;
    auto jj = j & 255;
    auto kk = k & 255;
    auto gi0 = _permMod12[ii + _perm[jj + _perm[kk]]];
    auto gi1 = _permMod12[ii + i1 + _perm[jj + j1 + _perm[kk + k1]]];
    auto gi2 = _permMod12[ii + i2 + _perm[jj + j2 + _perm[kk + k2]]];
    auto gi3 = _permMod12[ii + 1 + _perm[jj + 1 + _perm[kk + 1]]];
    auto t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;
    if ( < 0) {
        n0 = 0.0;
    } else {
        t0 *= t0;
        n0 = t0 * t0 * _dot3(_grad3[gi0], x0, y0, z0);
    }
    auto t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1;
    if ( < 0) {
        n1 = 0.0;
    } else {
        t1 *= t1;
        n1 = t1 * t1 * _dot3(_grad3[gi1], x1, y1, z1);
    }
    auto t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;
    if ( < 0) {
        n2 = 0.0;
    } else {
        t2 *= t2;
        n2 = t2 * t2 * _dot3(_grad3[gi2], x2, y2, z2);
    }
    auto t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;
    if ( < 0) {
        n3 = 0.0;
    } else {
        t3 *= t3;
        n3 = t3 * t3 * _dot3(_grad3[gi3], x3, y3, z3);
    }
    return 32.0 * (n0 + n1 + n2 + n3);
}

double SimplexNoiseCls::noise4D(double x, double y, double z, double w) {
    double n0, n1, n2, n3, n4;
    auto s = (x + y + z + w) * _F4;
    auto i = (x + s)->floor();
    auto j = (y + s)->floor();
    auto k = (z + s)->floor();
    auto l = (w + s)->floor();
    auto t = (i + j + k + l) * _G4;
    auto X0 = i - t;
    auto Y0 = j - t;
    auto Z0 = k - t;
    auto W0 = l - t;
    auto x0 = x - X0;
    auto y0 = y - Y0;
    auto z0 = z - Z0;
    auto w0 = w - W0;
    auto rankx = 0;
    auto ranky = 0;
    auto rankz = 0;
    auto rankw = 0;
    if (x0 > y0) {
        rankx++;
    } else {
        ranky++;
    }
    if (x0 > z0) {
        rankx++;
    } else {
        rankz++;
    }
    if (x0 > w0) {
        rankx++;
    } else {
        rankw++;
    }
    if (y0 > z0) {
        ranky++;
    } else {
        rankz++;
    }
    if (y0 > w0) {
        ranky++;
    } else {
        rankw++;
    }
    if (z0 > w0) {
        rankz++;
    } else {
        rankw++;
    }
    int i1, j1, k1, l1;
    int i2, j2, k2, l2;
    int i3, j3, k3, l3;
    i1 = rankx >= 3? 1 : 0;
    j1 = ranky >= 3? 1 : 0;
    k1 = rankz >= 3? 1 : 0;
    l1 = rankw >= 3? 1 : 0;
    i2 = rankx >= 2? 1 : 0;
    j2 = ranky >= 2? 1 : 0;
    k2 = rankz >= 2? 1 : 0;
    l2 = rankw >= 2? 1 : 0;
    i3 = rankx >= 1? 1 : 0;
    j3 = ranky >= 1? 1 : 0;
    k3 = rankz >= 1? 1 : 0;
    l3 = rankw >= 1? 1 : 0;
    auto x1 = x0 - i1 + _G4;
    auto y1 = y0 - j1 + _G4;
    auto z1 = z0 - k1 + _G4;
    auto w1 = w0 - l1 + _G4;
    auto x2 = x0 - i2 + 2.0 * _G4;
    auto y2 = y0 - j2 + 2.0 * _G4;
    auto z2 = z0 - k2 + 2.0 * _G4;
    auto w2 = w0 - l2 + 2.0 * _G4;
    auto x3 = x0 - i3 + 3.0 * _G4;
    auto y3 = y0 - j3 + 3.0 * _G4;
    auto z3 = z0 - k3 + 3.0 * _G4;
    auto w3 = w0 - l3 + 3.0 * _G4;
    auto x4 = x0 - 1.0 + 4.0 * _G4;
    auto y4 = y0 - 1.0 + 4.0 * _G4;
    auto z4 = z0 - 1.0 + 4.0 * _G4;
    auto w4 = w0 - 1.0 + 4.0 * _G4;
    auto ii = i & 255;
    auto jj = j & 255;
    auto kk = k & 255;
    auto ll = l & 255;
    auto gi0 = _perm[ii + _perm[jj + _perm[kk + _perm[ll]]]] % 32;
    auto gi1 = _perm[ii + i1 + _perm[jj + j1 + _perm[kk + k1 + _perm[ll + l1]]]] % 32;
    auto gi2 = _perm[ii + i2 + _perm[jj + j2 + _perm[kk + k2 + _perm[ll + l2]]]] % 32;
    auto gi3 = _perm[ii + i3 + _perm[jj + j3 + _perm[kk + k3 + _perm[ll + l3]]]] % 32;
    auto gi4 = _perm[ii + 1 + _perm[jj + 1 + _perm[kk + 1 + _perm[ll + 1]]]] % 32;
    auto t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0 - w0 * w0;
    if ( < 0) {
        n0 = 0.0;
    } else {
        t0 *= t0;
        n0 = t0 * t0 * _dot4(_grad4[gi0], x0, y0, z0, w0);
    }
    auto t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1 - w1 * w1;
    if ( < 0) {
        n1 = 0.0;
    } else {
        t1 *= t1;
        n1 = t1 * t1 * _dot4(_grad4[gi1], x1, y1, z1, w1);
    }
    auto t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2 - w2 * w2;
    if ( < 0) {
        n2 = 0.0;
    } else {
        t2 *= t2;
        n2 = t2 * t2 * _dot4(_grad4[gi2], x2, y2, z2, w2);
    }
    auto t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3 - w3 * w3;
    if ( < 0) {
        n3 = 0.0;
    } else {
        t3 *= t3;
        n3 = t3 * t3 * _dot4(_grad4[gi3], x3, y3, z3, w3);
    }
    auto t4 = 0.6 - x4 * x4 - y4 * y4 - z4 * z4 - w4 * w4;
    if ( < 0) {
        n4 = 0.0;
    } else {
        t4 *= t4;
        n4 = t4 * t4 * _dot4(_grad4[gi4], x4, y4, z4, w4);
    }
    return 27.0 * (n0 + n1 + n2 + n3 + n4);
}

double SimplexNoiseCls::_dot2(List<double> g, double x, double y) {
    return g[0] * x + g[1] * y;
}

double SimplexNoiseCls::_dot3(List<double> g, double x, double y, double z) {
    return g[0] * x + g[1] * y + g[2] * z;
}

double SimplexNoiseCls::_dot4(List<double> g, double x, double y, double z, double w) {
    return g[0] * x + g[1] * y + g[2] * z + g[3] * w;
}
