#include "numerik.hpp"

#include <cstddef>

double newton(std::function<double(double)> fx, std::function<float(float)> fderiv, double x0, size_t n)
{
    if (n == 0) {
        return x0;
    }
    auto x_prev = newton(fx, fderiv, x0, n - 1);
    return x_prev - fx(x_prev) / fderiv(x_prev);
}
