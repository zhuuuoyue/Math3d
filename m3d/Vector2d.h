#pragma once

#include "m3d.h"

#include <cassert>
#include <algorithm>

#include "utils.h"

namespace m3d {

class M3D_API Vector2d {
public:

    /// <summary>
    /// 零向量
    /// </summary>
    static const Vector2d zero;

    /// <summary>
    /// X 方向上的单位向量
    /// </summary>
    static const Vector2d unit_x;

    /// <summary>
    /// Y 方向上的单位向量
    /// </summary>
    static const Vector2d unit_y;

    /// <summary>
    /// 二维向量构造函数
    /// </summary>
    /// <param name="x_">X 分量</param>
    /// <param name="y_">Y 分量</param>
    /// <param name="z_">Z 分量</param>
    explicit Vector2d(double x_ = 0, double y_ = 0)
        : data{ x_, y_ } {
    }

    /// <summary>
    /// 二维向量拷贝构造函数
    /// </summary>
    /// <param name="other">待拷贝的二维向量</param>
    Vector2d(const Vector2d& other)
        : data{ other.x(), other.y() } {
    }

    /// <summary>
    /// 二维向量赋值运算符
    /// </summary>
    /// <param name="other">值二维向量</param>
    /// <returns>待赋值的二维向量</returns>
    Vector2d& operator=(const Vector2d& other) {
        x() = other.x();
        y() = other.y();
        return *this;
    }

    /// <summary>
    /// 二维向量的 X 分量
    /// </summary>
    /// <returns>X 分量</returns>
    double x() const {
        return data[0];
    }

    /// <summary>
    /// 二维向量的 X 分量
    /// </summary>
    /// <returns>X 分量</returns>
    double& x() {
        return data[0];
    }

    /// <summary>
    /// 二维向量 X 分量赋值
    /// </summary>
    /// <param name="value">值</param>
    /// <returns>二维向量本身</returns>
    Vector2d& x(double value) {
        x() = value;
        return *this;
    }

    /// <summary>
    /// 二维向量的 Y 分量
    /// </summary>
    /// <returns>Y 分量</returns>
    double y() const {
        return data[1];
    }

    /// <summary>
    /// 二维向量的 Y 分量
    /// </summary>
    /// <returns>Y 分量</returns>
    double& y() {
        return data[1];
    }

    /// <summary>
    /// 二维向量 Y 分量赋值
    /// </summary>
    /// <param name="value">值</param>
    /// <returns>二维向量本身</returns>
    Vector2d& y(double value) {
        y() = value;
        return *this;
    }

    /// <summary>
    /// 比较两个向量是否相等
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>相等则返回 true，不相等则返回 false</returns>
    bool operator==(const Vector2d& other) const {
        return utils::is_equal(x(), other.x()) && utils::is_equal(y(), other.y());
    }

    /// <summary>
    /// 比较两个二维向量是否不相等
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>不相等则返回 true，相等则返回 false</returns>
    bool operator!=(const Vector2d& other) const {
        return !(*this == other);
    }

    /// <summary>
    /// 二维向量取正
    /// </summary>
    /// <returns>取正后的二维向量</returns>
    Vector2d operator+() const {
        return Vector2d(*this);
    }

    /// <summary>
    /// 二维向量取负
    /// </summary>
    /// <returns>取负后的二维向量</returns>
    Vector2d operator-() const {
        return Vector2d{ -x(), -y() };
    }

    /// <summary>
    /// 二维向量相加
    /// </summary>
    /// <param name="other">另一个二维向量</param>
    /// <returns>两个二维向量相加的结果</returns>
    Vector2d operator+(const Vector2d& other) const {
        return Vector2d{ x() + other.x(), y() + other.y() };
    }

    /// <summary>
    /// 二维向量相减
    /// </summary>
    /// <param name="other">被减向量</param>
    /// <returns>两个二维向量相减结果</returns>
    Vector2d operator-(const Vector2d& other) const {
        return Vector2d{ x() - other.x(), y() - other.y() };
    }

    /// <summary>
    /// 二维向量与标量相乘
    /// </summary>
    /// <param name="value">标量乘数</param>
    /// <returns>二维向量与标量相乘结果</returns>
    Vector2d operator*(double value) const {
        return Vector2d{ value * x(), value * y() };
    }

    /// <summary>
    /// 二维向量除以非零标量
    /// </summary>
    /// <param name="value">标量除数</param>
    /// <returns>二维向量与标量相除结果</returns>
    Vector2d operator/(double value) const {
        assert(!utils::is_zero(value));
        return Vector2d{ x() / value, y() / value };
    }

    /// <summary>
    /// 二维向量自加
    /// </summary>
    /// <param name="other">被加二维向量</param>
    /// <returns>二维向量自身</returns>
    Vector2d& operator+=(const Vector2d& other) {
        x() += other.x();
        y() += other.y();
        return *this;
    }

    /// <summary>
    /// 二维向量自减
    /// </summary>
    /// <param name="other">被减二维向量</param>
    /// <returns>二维向量自身</returns>
    Vector2d& operator-=(const Vector2d& other) {
        x() -= other.x();
        y() -= other.y();
        return *this;
    }

    /// <summary>
    /// 二维向量自乘
    /// </summary>
    /// <param name="value">标量乘数</param>
    /// <returns>二维向量自身</returns>
    Vector2d& operator*=(double value) {
        x() *= value;
        y() *= value;
        return *this;
    }

    /// <summary>
    /// 二维向量自除
    /// </summary>
    /// <param name="value">非零标量除数</param>
    /// <returns>二维向量自身</returns>
    Vector2d& operator/=(double value) {
        assert(!utils::is_zero(value));
        x() /= value;
        y() /= value;
        return *this;
    }

    /// <summary>
    /// 二维向量的长度
    /// </summary>
    /// <returns>长度</returns>
    double length() const {
        return sqrt(x() * x() + y() * y());
    }

    /// <summary>
    /// 二维向量的长度
    /// </summary>
    /// <returns>长度</returns>
    double magnitude() const {
        return length();
    }

    /// <summary>
    /// 非零二维向量标准化
    /// </summary>
    /// <returns>标准化后的二维向量自身</returns>
    Vector2d& normalize() {
        double mag = magnitude();
        return *this /= mag;
    }

    /// <summary>
    /// 二维向量点乘
    /// </summary>
    /// <param name="other">另一个二维向量</param>
    /// <returns>点乘结果</returns>
    double operator*(const Vector2d& other) const {
        return x() * other.x() + y() * other.y();
    }

    /// <summary>
    /// 二维向量点乘
    /// </summary>
    /// <param name="other">另一个二维向量</param>
    /// <returns>点乘结果</returns>
    double dot_product(const Vector2d& other) const {
        return *this * other;
    }

private:

    double data[2]; // x, y
};
}

/// <summary>
/// 标量与二维向量相乘
/// </summary>
/// <param name="value">标量</param>
/// <param name="vec">二维向量</param>
/// <returns>标量与二维向量相乘的结果</returns>
inline m3d::Vector2d operator*(double value, const m3d::Vector2d& vec) {
    return vec * value;
}

namespace m3d {
namespace utils {

/// <summary>
/// 判断二维向量是否是零向量
/// </summary>
/// <param name="vec">待判断的向量</param>
/// <returns>是则返回 true，否则返回 false</returns>
M3D_API bool is_zero(const Vector2d& vec);

/// <summary>
/// 求两个二维点的距离
/// </summary>
/// <param name="a">第一个点</param>
/// <param name="b">第二个点</param>
/// <returns>距离</returns>
M3D_API double distance(const Vector2d& a, const Vector2d& b);

}
}
