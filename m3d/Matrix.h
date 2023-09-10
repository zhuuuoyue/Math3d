#pragma once

#include <vcruntime.h>
#include <cassert>
#include <algorithm>
#include "utils.h"

namespace m3d {

/// <summary>
/// 矩阵
/// </summary>
/// <typeparam name="T">矩阵元素类型</typeparam>
template<size_t R, size_t C, class T>
class Matrix {
public:

    /// <summary>
    /// 矩阵构造函数
    /// </summary>
    Matrix()
        : Matrix{ T{} } {
    }

    /// <summary>
    /// 矩阵构造函数
    /// </summary>
    /// <param name="value">填充值</param>
    explicit Matrix(const T& value) {
        std::fill_n(begin(), size(), value);
    }

    /// <summary>
    /// 矩阵拷贝构造函数
    /// </summary>
    /// <param name="other">被拷贝的矩阵</param>
    Matrix(const Matrix& other) {
        copy_from(other);
    }

    /// <summary>
    /// 矩阵赋值
    /// </summary>
    /// <param name="other">另一个矩阵</param>
    /// <returns>矩阵自身</returns>
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            copy_from(other);
        }
        return *this;
    }

    /// <summary>
    /// 矩阵行数
    /// </summary>
    /// <returns>行数</returns>
    constexpr size_t rows() const {
        return R;
    }

    /// <summary>
    /// 矩阵列数
    /// </summary>
    /// <returns>列数</returns>
    constexpr size_t columns() const {
        return C;
    }

    /// <summary>
    /// 矩阵元素数量
    /// </summary>
    /// <returns>元素数量</returns>
    constexpr size_t size() const {
        return R * C;
    }

    /// <summary>
    /// 按索引访问元素
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>指定索引的元素</returns>
    const T& operator()(size_t r, size_t c) const {
        return data_[index_of(r, c)];
    }

    /// <summary>
    /// 按索引访问元素
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>指定索引的元素</returns>
    T& operator()(size_t r, size_t c) {
        return data_[index_of(r, c)];
    }

    /// <summary>
    /// 按索引访问元素
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>指定索引的元素</returns>
    const T& at(size_t r, size_t c) const {
        assert(is_valid_index_pair(r, c));
        return data_[index_of(r, c)];
    }

    /// <summary>
    /// 按索引访问元素
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>指定索引的元素</returns>
    T& at(size_t r, size_t c) {
        assert(is_valid_index_pair(r, c));
        return data_[index_of(r, c)];
    }

    /// <summary>
    /// 获取数据
    /// </summary>
    /// <returns>数据指针</returns>
    const T* data() const {
        return data_;
    }

    /// <summary>
    /// 获取数据
    /// </summary>
    /// <returns>数据指针</returns>
    T* data() {
        return data_;
    }

    /// <summary>
    /// 判断矩阵是否是方阵
    /// </summary>
    /// <returns>是方阵则返回 true，否则返回 false</returns>
    constexpr bool is_square() const {
        return rows() == columns();
    }

    /// <summary>
    /// 判断矩阵是否是对角矩阵
    /// </summary>
    /// <returns>是对角矩阵则返回 true，否则返回 false</returns>
    bool is_diagonal() const {
        if (!is_square()) {
            return false;
        }
        for (size_t r = 0; r < rows(); ++r) {
            for (size_t c = 0; c < columns(); ++c) {
                if (r != c && !utils::is_zero(at(r, c))) {
                    return false;
                }
            }
        }
        return true;
    }

    /// <summary>
    /// 判断矩阵是否是单位矩阵
    /// </summary>
    /// <returns>是单位矩阵则返回 true，否则返回 false</returns>
    bool is_identity() const {
        if (!is_square()) {
            return false;
        }
        for (size_t r = 0; r < rows(); ++r) {
            for (size_t c = 0; c < columns(); ++c) {
                if (r == c) {
                    if (!utils::is_equal(at(r, c), 1)) {
                        return false;
                    }
                }
                else {
                    if (!utils::is_zero(at(r, c))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    /// <summary>
    /// 矩阵的转置
    /// </summary>
    /// <returns>转置后的矩阵</returns>
    Matrix<C, R, T> transpose() const {
        Matrix<C, R, T> t;
        for (size_t r = 0; r < rows(); ++r) {
            for (size_t c = 0; c < columns(); ++c) {
                t(c, r) = (*this)(r, c);
            }
        }
        return t;
    }

    /// <summary>
    /// 判断两个矩阵是否相等
    /// </summary>
    /// <param name="other">另一个矩阵</param>
    /// <returns>相等则返回 true，不相等则返回 false</returns>
    bool operator==(const Matrix<R, C, T>& other) const {
        const T* a = begin();
        const T* b = other.begin();
        for (size_t i = 0; i < size(); ++i, ++a, ++b) {
            if (!utils::is_equal(*a, *b)) {
                return false;
            }
        }
        return true;
    }

    /// <summary>
    /// 判断两个矩阵是否不相等
    /// </summary>
    /// <param name="other">另一个矩阵</param>
    /// <returns>不相等则返回 true，相等则返回 false</returns>
    bool operator!=(const Matrix<R, C, T>& other) const {
        return !(*this == other);
    }

    /// <summary>
    /// 矩阵取正
    /// </summary>
    /// <returns>取正后的矩阵</returns>
    Matrix<R, C, T> operator+() const {
        return Matrix<R, C, T>(*this);
    }

    /// <summary>
    /// 矩阵取负
    /// </summary>
    /// <returns>取负后的矩阵</returns>
    Matrix<R, C, T> operator-() const {
        return *this * -1;
    }

    /// <summary>
    /// 矩阵加法
    /// </summary>
    /// <param name="other">被加矩阵</param>
    /// <returns>矩阵加法结果</returns>
    Matrix<R, C, T> operator+(const Matrix<R, C, T>& other) const {
        Matrix<R, C, T> result;
        std::transform(begin(), end(), other.begin(), result.begin(), [](const T& a, const T& b) { return a + b; });
        return result;
    }

    /// <summary>
    /// 矩阵减法
    /// </summary>
    /// <param name="other">被减矩阵</param>
    /// <returns>矩阵减法结果</returns>
    Matrix<R, C, T> operator-(const Matrix<R, C, T>& other) const {
        Matrix<R, C, T> result;
        std::transform(begin(), end(), other.begin(), result.begin(), [](const T& a, const T& b) { return a - b; });
        return result;
    }

    /// <summary>
    /// 矩阵乘以标量
    /// </summary>
    /// <param name="k">乘数标量</param>
    /// <returns>矩阵乘以标量结果矩阵</returns>
    Matrix<R, C, T> operator*(const T& k) const {
        Matrix<R, C, T> result;
        std::transform(begin(), end(), result.begin(), [k](const T& src) { return k * src; });
        return result;
    }

    /// <summary>
    /// 矩阵除以标量
    /// </summary>
    /// <param name="k">被除标量</param>
    /// <returns>矩阵除以标量结果矩阵</returns>
    Matrix<R, C, T> operator/(const T& k) const {
        assert(!utils::is_zero(k));
        Matrix<R, C, T> result;
        std::transform(begin(), end(), result.begin(), [k](const T& src) { return src / k; });
        return result;
    }

    /// <summary>
    /// 矩阵的自加
    /// </summary>
    /// <param name="other">被加矩阵</param>
    /// <returns>矩阵自身</returns>
    Matrix<R, C, T>& operator+=(const Matrix<R, C, T>& other) {
        std::transform(begin(), end(), other.begin(), begin(), [](const T& a, const T& b) { return a + b; });
        return *this;
    }

    /// <summary>
    /// 矩阵的自减
    /// </summary>
    /// <param name="other">被减矩阵</param>
    /// <returns>矩阵自身</returns>
    Matrix<R, C, T>& operator-=(const Matrix<R, C, T>& other) {
        std::transform(begin(), end(), other.begin(), begin(), [](const T& a, const T& b) { return a - b; });
        return *this;
    }

    /// <summary>
    /// 矩阵的自乘
    /// </summary>
    /// <param name="k">乘数标量</param>
    /// <returns>矩阵自身</returns>
    Matrix<R, C, T>& operator*=(const T& k) {
        std::transform(begin(), end(), begin(), [k](const T& src) { return k * src; });
        return *this;
    }

    /// <summary>
    /// 矩阵的自除
    /// </summary>
    /// <param name="k">被除标量</param>
    /// <returns>矩阵自身</returns>
    Matrix<R, C, T>& operator/=(const T& k) {
        assert(!utils::is_zero(k));
        std::transform(begin(), end(), begin(), [k](const T& src) { return src / k; });
        return *this;
    }

    /// <summary>
    /// 两个矩阵相乘
    /// </summary>
    /// <param name="other">另一个矩阵</param>
    /// <returns>矩阵乘法结果</returns>
    template<size_t C2>
    Matrix<R, C2, T> operator*(const Matrix<C, C2, T>& other) const {
        Matrix<R, C2, T> result;
        for (size_t r = 0; r < rows(); ++r) {
            for (size_t c = 0; c < other.columns(); ++c) {
                T temp{};
                for (size_t i = 0; i < columns(); ++i) {
                    temp += ((*this)(r, i) * other(i, c));
                }
                result(r, c) = temp;
            }
        }
        return result;
    }

private:

    /// <summary>
    /// 获取开始位置的迭代器
    /// </summary>
    /// <returns>开始位置的迭代器</returns>
    const T* begin() const {
        return data_;
    }

    /// <summary>
    /// 获取开始位置的迭代器
    /// </summary>
    /// <returns>开始位置的迭代器</returns>
    T* begin() {
        return data_;
    }

    /// <summary>
    /// 获取结束位置的迭代器
    /// </summary>
    /// <returns>结束位置的迭代器</returns>
    const T* end() const {
        return data_ + size();
    }

    /// <summary>
    /// 获取结束位置的迭代器
    /// </summary>
    /// <returns>结束位置的迭代器</returns>
    T* end() {
        return data_ + size();
    }

    /// <summary>
    /// 判断行索引是否有效
    /// </summary>
    /// <param name="r">行索引</param>
    /// <returns>有效则返回 true，无效则返回 false</returns>
    bool is_valid_row_index(size_t r) const {
        return r < R;
    }

    /// <summary>
    /// 判断列索引是否有效
    /// </summary>
    /// <param name="c">列索引</param>
    /// <returns>有效则返回 true，无效则返回 false</returns>
    bool is_valid_column_index(size_t c) const {
        return c < C;
    }

    /// <summary>
    /// 判断当前二维索引是否有效
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>有效则返回 true，无效则返回 false</returns>
    bool is_valid_index_pair(size_t r, size_t c) const {
        return is_valid_row_index(r)
            && is_valid_column_index(c);
    }

    /// <summary>
    /// 将二维索引转换成一维索引
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>一维索引</returns>
    size_t index_of(size_t r, size_t c) const {
        return c + r * C;
    }

    /// <summary>
    /// 拷贝另一个矩阵的元素填充当前矩阵
    /// </summary>
    /// <param name="other">另一个矩阵</param>
    void copy_from(const Matrix& other) {
        std::copy(other.begin(), other.end(), begin());
    }

private:

    T data_[R * C];
};

template<class T>
class Matrix<0, 0, T> {};

template<size_t R, class T>
class Matrix<R, 0, T> {};

template<size_t C, class T>
class Matrix<0, C, T> {};

using Matrix2d = m3d::Matrix<2, 2, double>;
using Matrix3d = m3d::Matrix<3, 3, double>;
using Matrix4d = m3d::Matrix<4, 4, double>;

namespace utils {

/// <summary>
/// 生成二维单位矩阵
/// </summary>
/// <returns>二维单位矩阵</returns>
Matrix2d create_identify_matrix_2d();

/// <summary>
/// 生成三维单位矩阵
/// </summary>
/// <returns>三维单位矩阵</returns>
Matrix3d create_identify_matrix_3d();

/// <summary>
/// 生成四维单位矩阵
/// </summary>
/// <returns>四维单位矩阵</returns>
Matrix4d create_identify_matrix_4d();

}
}

/// <summary>
/// 标量与矩阵相乘
/// </summary>
/// <typeparam name="T">矩阵元素类型</typeparam>
/// <param name="k">标量</param>
/// <param name="mat">矩阵</param>
/// <returns>乘法结果</returns>
template<size_t R, size_t C, class T>
inline m3d::Matrix<R, C, T> operator*(const T& k, const m3d::Matrix<R, C, T>& mat) {
    return mat * k;
}
