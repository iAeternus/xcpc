#ifndef DOUBLE_H
#define DOUBLE_H

#include <cmath>

/**
 * Double 包装类
 * 实现给定精度的浮点数的运算
 */
class Double {
public:
    Double()
        : number(0) {}

    Double(int number)
        : number(number) {}

    Double(long number)
        : number(number) {}

    Double(long long number)
        : number(number) {}

    Double(float number)
        : number(number) {}

    Double(double number)
        : number(number) {}

    Double(const int number)
        : number(number) {}

    Double(const long number)
        : number(number) {}

    Double(const long long number)
        : number(number) {}

    Double(const float number)
        : number(number) {}

    Double(const double number)
        : number(number) {}

    Double(const Double& other) = default;
    Double& operator=(const Double& other) = default;

    Double(Double&& other) noexcept = default;
    Double& operator=(Double&& other) noexcept = default;



private:
    double number;

    static constexpr double EPS = 1e-8;
};

static const Double PI = Double(acos(-1.0));

#endif  // DOUBLE_H