// g++ test1.cpp matrix.h -o test1
#include <iostream>

#include "matrix.h"

auto basic() -> void {
    Matrix<double> m(10, 10, -1);
    std::cout << "rows: " << m.get_rows() << std::endl;
    std::cout << "cols: " << m.get_cols() << std::endl;
    std::cout << "m[5][4]: " << m[5][4] << std::endl;
    m[5][4] = 3.14;
    std::cout << "m[5][4]: " << m[5][4] << "\n\n";
}

auto add() -> void {
    // Given
    Matrix<int> a(5, 5, 1), b(5, 5, 2);

    // When
    Matrix<int> c = a + b;
    a += b;

    // Then
    std::cout << c << "\n\n";
    std::cout << a << "\n\n";
}

auto sub() -> void {
    // Given
    Matrix<int> a(5, 5, 0), b(5, 5, 10);

    // When
    Matrix<int> c = a - b;
    a -= b;

    // Then
    std::cout << c << "\n\n";
    std::cout << a << "\n\n";
}

auto mul1() -> void {
    // Given
    Matrix<int> a(5, 5, 10), b(5, 5, 10);
    int n = 5;

    // When
    Matrix<int> c = a * n;
    a *= n;

    // Then
    std::cout << c << "\n\n";
    std::cout << a << "\n\n";
}

auto mul2() -> void {
    // Given
    Matrix<int> a = {
        {1, 2, 3},
        {4, 5, 6},
    };
    Matrix<int> b = {
        {1, 2},
        {3, 4},
        {5, 6},
    };

    // When
    Matrix<int> c = a * b;

    // Then
    std::cout << c << "\n\n";
}

auto pow() -> void {
    // Given
    Matrix<int> a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int n = 3;

    // When
    Matrix<int> c = a ^ n;

    // Then
    std::cout << c << "\n\n";
}

auto solve_linear_systems1() -> void {
    // Given
    Matrix<double> a = {
        {3, 7, -5, 47},
        {1, 4, 1, 58},
        {8, -3, 9, 88},
    };

    // When
    bool res = Matrix<double>::solve_linear_systems(a);

    // Then
    std::cout << (res ? "unique solution" : "no unique solution") << std::endl;
    std::cout << a << std::endl;
    if(res) {
        std::cout << "Solution is: ";
        std::vector<double> sol = a.get_solution();
        for(const auto& v : sol) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
}

auto solve_linear_systems2() -> void {
    // Given
    Matrix<double> a = {
        {3, 7, -5, 47},
        {1, 4, 1, 58},
        {2, 3, -6, -11},
    };

    // When
    bool res = Matrix<double>::solve_linear_systems(a);

    // Then
    std::cout << (res ? "unique solution" : "no unique solution") << std::endl;
    std::cout << a << std::endl;
    if(res) {
        std::cout << "Solution is: ";
        std::vector<double> sol = a.get_solution();
        for(const auto& v : sol) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
}

auto solve_linear_systems3() -> void {
    // Given
    Matrix<double> a = {
        {3, 7, -5, 47},
        {1, 4, 1, 58},
        {2, 3, -6, 5},
    };

    // When
    bool res = Matrix<double>::solve_linear_systems(a);

    // Then
    std::cout << (res ? "unique solution" : "no unique solution") << std::endl;
    std::cout << a << std::endl;
    if(res) {
        std::cout << "Solution is: ";
        std::vector<double> sol = a.get_solution();
        for(const auto& v : sol) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
}

auto solve_xor_linear_systems1() -> void {
    // Given
    Matrix<int> a = {
        {1, 1, 1, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 0},
    };

    // When
    bool res = Matrix<int>::solve_xor_linear_systems(a);

    // Then
    if(res) {
        std::cout << "Solution is: ";
        std::vector<int> sol = a.get_solution();
        for(const auto& v : sol) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    } else {
        std::cout << "no unique solution\n";
    }
}

void t() {
    // Given
    Matrix<int> a = {
        {1, 2, 3},
        {4, 5, 6},
    };

    // When
    Matrix<int> res = a.t();

    // Then
    std::cout << res << std::endl;
}

auto main() -> int {
    basic();
    add();
    sub();
    mul1();
    mul2();
    pow();
    solve_linear_systems1();
    solve_linear_systems2();
    solve_linear_systems3();
    solve_xor_linear_systems1();
    t();
}