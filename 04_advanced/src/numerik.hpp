#pragma once
#include <cmath>
#include <cstddef>
#include <functional>

double newton(std::function<double(double)> fx, std::function<float(float)> fderiv, double x0, size_t n);

template <typename T>
T newtonTemp(std::function<T(T)> fx, std::function<T(T)> fderiv, T x0, size_t n)
{
    return {};
    // TODO
}

template <typename T>
T fxTemp(T x)
{
    return x * x * x + 4 * x * x - 7 * x + 12;
}

template <typename T>
T fderivTemp(T x)
{
    return 3 * x * x + 8 * x - 7;
}
