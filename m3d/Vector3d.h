#pragma once

#include "m3d.h"

#include <cassert>
#include <algorithm>

#include "utils.h"

namespace m3d {

class M3D_API Vector3d {
public:

    /// <summary>
    /// 零向量
    /// </summary>
    static const Vector3d zero;

    /// <summary>
    /// X 方向上的单位向量
    /// </summary>
    static const Vector3d unit_x;

    /// <summary>
    /// Y 方向上的单位向量
    /// </summary>
    static const Vector3d unit_y;

    /// <summary>
    /// Z 方向上的单位向量
    /// </summary>
    static const Vector3d unit_z;

    /// <summary>
    /// 三维向量构造函数
    /// </summary>
    /// <param name="x_">X 分量</param>
    /// <param name="y_">Y 分量</param>
    /// <param name="z_">Z 分量</param>
    explicit Vector3d(double x_ = 0, double y_ = 0, double z_ = 0)
        : data{ x_, y_, z_ } {
    }

    /// <summary>
    /// 三维向量拷贝构造函数
    /// </summary>
    /// <param name="other">待拷贝的三维向量</param>
    Vector3d(const Vector3d& other)
        : data{ other.x(), other.y(), other.z() } {
    }

    /// <summary>
    /// 三维向量赋值运算符
    /// </summary>
    /// <param name="other">值三维向量</param>
    /// <returns>待赋值的三维向量</returns>
    Vector3d& operator=(const Vector3d& other) {
        x() = other.x();
        y() = other.y();
        z() = other.z();
        return *this;
    }

    /// <summary>
    /// 三维向量的 X 分量
    /// </summary>
    /// <returns>X 分量</returns>
    double x() const {
        return data[0];
    }

    /// <summary>
    /// 三维向量的 X 分量
    /// </summary>
    /// <returns>X 分量</returns>
    double& x() {
        return data[0];
    }

    /// <summary>
    /// 三维向量 X 分量赋值
    /// </summary>
    /// <param name="value">值</param>
    /// <returns>三维向量本身</returns>
    Vector3d& x(double value) {
        data[0] = value;
        return *this;
    }

    /// <summary>
    /// 三维向量的 Y 分量
    /// </summary>
    /// <returns>Y 分量</returns>
    double y() const {
        return data[1];
    }

    /// <summary>
    /// 三维向量的 Y 分量
    /// </summary>
    /// <returns>Y 分量</returns>
    double& y() {
        return data[1];
    }

    /// <summary>
    /// 三维向量 Y 分量赋值
    /// </summary>
    /// <param name="value">值</param>
    /// <returns>三维向量本身</returns>
    Vector3d& y(double value) {
        data[1] = value;
        return *this;
    }

    /// <summary>
    /// 三维向量的 Z 分量
    /// </summary>
    /// <returns>Z 分量</returns>
    double z() const {
        return data[2];
    }

    /// <summary>
    /// 三维向量的 Z 分量
    /// </summary>
    /// <returns>Z 分量</returns>
    double& z() {
        return data[2];
    }

    /// <summary>
    /// 三维向量 Z 分量赋值
    /// </summary>
    /// <param name="value">值</param>
    /// <returns>三维向量本身</returns>
    Vector3d& z(double value) {
        data[2] = value;
        return *this;
    }

    /// <summary>
    /// 比较两个向量是否相等
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>相等则返回 true，不相等则返回 false</returns>
    bool operator==(const Vector3d& other) const {
        return utils::is_equal(x(), other.x())
            && utils::is_equal(y(), other.y())
            && utils::is_equal(z(), other.z());
    }

    /// <summary>
    /// 比较两个三维向量是否不相等
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>不相等则返回 true，相等则返回 false</returns>
    bool operator!=(const Vector3d& other) const {
        return !(*this == other);
    }

    /// <summary>
    /// 三维向量取正
    /// </summary>
    /// <returns>取正后的三维向量</returns>
    Vector3d operator+() const {
        return Vector3d{ x(), y(), z() };
    }

    /// <summary>
    /// 三维向量取负
    /// </summary>
    /// <returns>取负后的三维向量</returns>
    Vector3d operator-() const {
        return Vector3d{ -x(), -y(), -z() };
    }

    /// <summary>
    /// 三维向量相加
    /// </summary>
    /// <param name="other">另一个三维向量</param>
    /// <returns>两个三维向量相加的结果</returns>
    Vector3d operator+(const Vector3d& other) const {
        return Vector3d{ x() + other.x(), y() + other.y(), z() + other.z() };
    }

    /// <summary>
    /// 三维向量相减
    /// </summary>
    /// <param name="other">被减向量</param>
    /// <returns>两个三维向量相减结果</returns>
    Vector3d operator-(const Vector3d& other) const {
        return Vector3d{ x() - other.x(), y() - other.y(), z() - other.z() };
    }

    /// <summary>
    /// 三维向量与标量相乘
    /// </summary>
    /// <param name="value">标量乘数</param>
    /// <returns>三维向量与标量相乘结果</returns>
    Vector3d operator*(double value) const {
        return Vector3d{ x() * value, y() * value, z() * value };
    }

    /// <summary>
    /// 三维向量除以非零标量
    /// </summary>
    /// <param name="value">标量除数</param>
    /// <returns>三维向量与标量相除结果</returns>
    Vector3d operator/(double value) const {
        assert(!utils::is_zero(value));
        return Vector3d{ x() / value, y() / value, z() / value };
    }

    /// <summary>
    /// 三维向量自加
    /// </summary>
    /// <param name="other">被加三维向量</param>
    /// <returns>三维向量自身</returns>
    Vector3d& operator+=(const Vector3d& other) {
        x() += other.x();
        y() += other.y();
        z() += other.z();
        return *this;
    }

    /// <summary>
    /// 三维向量自减
    /// </summary>
    /// <param name="other">被减三维向量</param>
    /// <returns>三维向量自身</returns>
    Vector3d& operator-=(const Vector3d& other) {
        x() -= other.x();
        y() -= other.y();
        z() -= other.z();
        return *this;
    }

    /// <summary>
    /// 三维向量自乘
    /// </summary>
    /// <param name="value">标量乘数</param>
    /// <returns>三维向量自身</returns>
    Vector3d& operator*=(double value) {
        x() *= value;
        y() *= value;
        z() *= value;
        return *this;
    }

    /// <summary>
    /// 三维向量自除
    /// </summary>
    /// <param name="value">非零标量除数</param>
    /// <returns>三维向量自身</returns>
    Vector3d& operator/=(double value) {
        assert(!utils::is_zero(value));
        x() /= value;
        y() /= value;
        z() /= value;
        return *this;
    }

    /// <summary>
    /// 求向量的长度
    /// </summary>
    /// <returns>向量长度</returns>
    double length() const {
        return sqrt(x() * x() + y() * y() + z() * z());
    }

    /// <summary>
    /// 求向量的长度
    /// </summary>
    /// <returns>向量长度</returns>
    double magnitude() const {
        return length();
    }

    /// <summary>
    /// 非零三维向量标准化
    /// </summary>
    /// <returns>三维向量自身</returns>
    Vector3d& normalize() {
        double mag = magnitude();
        assert(!utils::is_zero(mag));
        x() /= mag;
        y() /= mag;
        z() /= mag;
        return *this;
    }

    /// <summary>
    /// 向量点乘
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>点积</returns>
    double operator*(const Vector3d& other) const {
        return x() * other.x() + y() * other.y() + z() * other.z();
    }

    /// <summary>
    /// 向量点乘
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>点积</returns>
    double dot_product(const Vector3d& other) const {
        return *this * other;
    }

    /// <summary>
    /// 向量叉乘
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>叉积</returns>
    Vector3d cross_product(const Vector3d& other) const {
        return Vector3d{
            y() * other.z() - z() * other.y(),
            z() * other.x() - x() * other.z(),
            x() * other.y() - y() * other.x()
        };
    }

private:

    double data[3]; // x, y, z
};
}

/// <summary>
/// 标量与三维向量相乘
/// </summary>
/// <param name="value">标量</param>
/// <param name="vec">三维向量</param>
/// <returns>标量与三维向量相乘的结果</returns>
inline m3d::Vector3d operator*(double value, const m3d::Vector3d& vec) {
    return vec * value;
}

namespace m3d {
namespace utils {

/// <summary>
/// 求两个点之间的距离
/// </summary>
/// <param name="p1">第一点</param>
/// <param name="p2">第二点</param>
/// <returns>距离</returns>
M3D_API double distance(const Vector3d p1, const Vector3d& p2);

/// <summary>
/// 判断一个向量是否是零向量
/// </summary>
/// <param name="vec">待判断的向量</param>
/// <returns>是则返回 true，否则返回 false</returns>
M3D_API bool is_zero(const Vector3d& vec);

}
}
