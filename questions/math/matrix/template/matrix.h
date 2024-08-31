/**
 * @brief 矩阵及其常见算法
 * @author ricky
 * @date 2024/8/31
 * @version 1.0
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <iostream>
#include <stdexcept>

/**
 * 泛型参数只允许为可计算的数字类型
 */
template<typename T>
concept ArithmeticType = std::is_arithmetic_v<T>;

/**
 * 矩阵
 * 实现了常用矩阵算法，矩阵存储可运算的数字类型
 */
template<ArithmeticType T>
class Matrix {
public:
    /**
     * 创建一个空的矩阵
     */
    Matrix()
            : rows(0), cols(0), data() {}

    /**
     * 创建方阵
     * @par n 行数=列数
     * @par unit 如果为true则创建单位阵，否则创建全为0的方阵
     */
    explicit Matrix(size_t n, bool unit = false)
            : rows(n), cols(n), data(this->rows, std::vector<T>(this->cols, 0)) {
        if (unit) {
            for (size_t i = 0; i < rows; ++i) {
                data[i][i] = 1;
            }
        }
    }

    /**
     * 使用指定的行数和列数创建矩阵
     * @par rows 行数
     * @par cols 列数
     * @par val 初始化的值
     */
    explicit Matrix(size_t rows, size_t cols, T val = 0)
            : rows(rows), cols(cols), data(this->rows, std::vector<T>(this->cols, val)) {}

    /**
     * 使用初始化列表创建矩阵
     * @par init 初始化列表
     */
    Matrix(const std::initializer_list<std::initializer_list<T>> &init)
            : rows(init.size()), cols(init.begin()->size()), data(this->rows, std::vector<T>(this->cols)) {
        size_t i = 0, j;
        for (const auto &row: init) {
            j = 0;
            if (row.size() != this->cols) {
                throw std::runtime_error("Each row of the matrix must have an equal number of elements.");
            }
            for (const auto &val: row) {
                data[i][j] = val;
                ++j;
            }
            ++i;
        }
    }

    Matrix(const Matrix &other)
            : rows(other.rows), cols(other.cols), data(this->rows, std::vector<T>(this->cols)) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = other[i][j];
            }
        }
    }

    Matrix &operator=(const Matrix &other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data.resize(rows, std::vector<T>(cols));

            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    data[i][j] = other[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix() = default;

    //////////////// 基础操作 ////////////////

    /**
     * 获取行数
     */
    [[nodiscard]] auto get_rows() const noexcept -> size_t {
        return rows;
    }

    /**
     * 获取列数
     */
    [[nodiscard]] auto get_cols() const noexcept -> size_t {
        return cols;
    }

    /**
     * m[i][j]访问
     */
    auto operator[](size_t row) -> std::vector<T>& {
        assert(row < rows);
        return data[row];
    }

    /**
     * 常量矩阵 m[i][j]访问
     */
    auto operator[](size_t row) const -> const std::vector<T>& {
        assert(row < rows);
        return data[row];
    }

    friend auto operator<<(std::ostream &out, const Matrix &m) -> std::ostream& {
        for (size_t i = 0; i < m.rows; ++i) {
            for (size_t j = 0; j < m.cols; ++j) {
                out << m[i][j];
                if (j < m.cols - 1) {
                    out << ' ';
                }
            }
            if (i < m.rows - 1) {
                out << '\n';
            }
        }
        return out;
    }

    /**
     * 判断方阵
     * @return true=是方阵 false=不是方阵
     */
    [[nodiscard]] auto is_square() const noexcept -> bool {
        return rows == cols;
    }

    //////////////// 常用算法 ////////////////

    /**
     * 矩阵加法
     * @par a 矩阵
     * @par b 矩阵
     * @return 计算 a + b
     */
    friend auto operator+(const Matrix &a, const Matrix &b) -> Matrix {
        if (!Matrix::can_linear(a, b)) {
            throw std::runtime_error("Dimension mismatch error: Matrix dimensions do not match for addition.");
        }

        Matrix c(a.rows, b.rows);
        for (size_t i = 0; i < c.rows; ++i) {
            for (size_t j = 0; j < c.cols; ++j) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }

        return c;
    }

    /**
     * 矩阵累加
     * @par other 矩阵
     * @return 计算 this += other
     */
    auto operator+=(const Matrix &other) -> Matrix& {
        if (!Matrix::can_linear(*this, other)) {
            throw std::runtime_error("Dimension mismatch error: Matrix dimensions do not match for addition.");
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] += other[i][j];
            }
        }
        return *this;
    }

    /**
     * 矩阵减法
     * @par a 矩阵
     * @par b 矩阵
     * @return 计算 a - b
     */
    friend auto operator-(const Matrix &a, const Matrix &b) -> Matrix {
        if (!Matrix::can_linear(a, b)) {
            throw std::runtime_error("Dimension mismatch error: Matrix dimensions do not match for subtraction.");
        }

        Matrix c(a.rows, b.rows);
        for (size_t i = 0; i < c.rows; ++i) {
            for (size_t j = 0; j < c.cols; ++j) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }

        return c;
    }

    /**
     * 矩阵累减
     * @par other 矩阵
     * @return 计算 this -= other
     */
    auto operator-=(const Matrix &other) -> Matrix& {
        if (!Matrix::can_linear(*this, other)) {
            throw std::runtime_error("Dimension mismatch error: Matrix dimensions do not match for subtraction.");
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] -= other[i][j];
            }
        }
        return *this;
    }

    /**
     * 数乘矩阵
     * @par n 数
     * @par m 矩阵
     * @return 计算 a * n
     */
    friend auto operator*(size_t n, const Matrix &m) -> Matrix {
        Matrix c(m);
        for (size_t i = 0; i < c.rows; ++i) {
            for (size_t j = 0; j < c.cols; ++j) {
                c[i][j] *= n;
            }
        }
        return c;
    }

    /**
     * 数乘矩阵
     * @par m 矩阵
     * @par n 数
     * @return 计算 a * n
     */
    friend auto operator*(const Matrix &m, T n) -> Matrix {
        Matrix c(m);
        for (size_t i = 0; i < c.rows; ++i) {
            for (size_t j = 0; j < c.cols; ++j) {
                c[i][j] *= n;
            }
        }
        return c;
    }

    /**
     * 数乘矩阵
     * @par n 数
     * @return 计算 this * n
     */
    auto operator*=(T n) -> Matrix& {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] *= n;
            }
        }
        return *this;
    }

    /**
     * 矩阵乘法
     * O(n^3)
     * @par a 矩阵
     * @par b 矩阵
     * @return 计算 a * b
     */
    friend auto operator*(const Matrix &a, const Matrix &b) -> Matrix {
        if (a.cols != b.rows) {
            throw std::runtime_error("Dimension mismatch error: The number of columns in the first matrix must equal the number of rows in the second matrix for multiplication.");
        }

        Matrix c(a.rows, b.cols);
        for (size_t i = 0; i < a.rows; ++i) {
            for (size_t j = 0; j < b.cols; ++j) {
                for (size_t k = 0; k < a.cols; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        return c;
    }

    /**
     * 矩阵快速幂
     * O(n^3 log n)
     * 注意只适用于整型矩阵
     * @par a 底数
     * @par n 指数
     * @return 计算 a^n
     */
    friend auto operator^(Matrix &a, T n) -> Matrix {
        if (!a.is_square()) {
            throw std::runtime_error("Matrix exponentiation must be square.");
        }
        if (n < 0) {
            throw std::runtime_error("The exponent must be greater than 0.");
        }

        Matrix ans(a.rows, true);
        while (n) {
            if (n & 1) {
                ans = ans * a;
            }
            a = a * a;
            n >>= 1;
        }
        return ans;
    }

    /**
     * 解线性方程组
     * O(n^3)
     * 适用于浮点型矩阵
     * 使用高斯-约当消元法
     * @par m 线性方程组矩阵，函数将其变换为简化阶梯矩阵
     * @return true=方程有唯一解 false=方程没有唯一解
     */
    static auto solve_linear_systems(Matrix<T> &m) -> bool {
        const T EPS = 1e-8;  // 定义一个非常小的数，用于判断是否为0

        if (m.cols - m.rows != 1) {
            throw std::runtime_error("Incorrect linear equations.");
        }

        size_t n = m.rows;
        for (size_t i = 0; i < n; ++i) {
            size_t max_idx = i;
            // 查找当前列绝对值最大的行
            for (size_t j = i + 1; j < n; ++j) {
                if (fabs(m.data[j][i]) > fabs(m.data[max_idx][i])) {
                    max_idx = j;
                }
            }

            // 如果最大行不是当前行，则交换
            if (max_idx != i) {
                m.swap_rows(i, max_idx);
            }

            // 检查主元是否为0
            if (fabs(m.data[i][i]) < EPS) {
                return false;  // 没有唯一解
            }

            // 将主元归一化
            T factor = 1.0 / m.data[i][i];
            for (size_t j = i; j < m.cols; ++j) {
                m.data[i][j] *= factor;
            }

            // 消去主元所在列的其他元素
            for (size_t j = 0; j < n; ++j) {
                if (i != j) {
                    factor = -m.data[j][i];
                    for (size_t k = i; k < m.cols; ++k) {
                        m.data[j][k] += m.data[i][k] * factor;
                    }
                }
            }
        }
        return true;
    }

    /**
     * 获取线性方程组的解向量
     * 必须在solve_linear_systems之后调用
     * 当且仅当线性方程组有唯一解时函数有效
     * @return 解向量
     */
    auto get_solution() const -> std::vector<T> {
        std::vector<T> ans;
        for (size_t i = 0; i < rows; ++i) {
            ans.push_back(data[i][cols - 1]);
        }
        return ans;
    }

private:
    size_t rows;  // 行数
    size_t cols;  // 列数
    std::vector<std::vector<T>> data;

    /**
     * 能否线性运算
     * @return true=能 false=不能
     */
    static auto can_linear(const Matrix &a, const Matrix &b) -> bool {
        return a.rows == b.rows && a.cols == b.cols;
    }

    /**
     * 交换矩阵的两行
     * @par col1 行号
     * @par col2 行号
     */
    auto swap_rows(size_t col1, size_t col2) -> void {
        for (size_t k = 0; k < cols; ++k) {
            std::swap(data[col1][k], data[col2][k]);
        }
    }

    /**
     * 交换矩阵的两列
     * @par col1 列号
     * @par col2 列号
     */
    auto swap_cols(size_t col1, size_t col2) -> void {
        for (size_t i = 0; i < rows; ++i) {
            std::swap(data[i][col1], data[i][col2]);
        }
    }
};

#endif  // MATRIX_H