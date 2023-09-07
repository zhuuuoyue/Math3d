#pragma once

#include "m3d.h"

#include <cassert>
#include <algorithm>

#include "utils.h"

namespace m3d {

class M3D_API Vector3d {
public:

    static const Vector3d zero;
    static const Vector3d unit_x;
    static const Vector3d unit_y;
    static const Vector3d unit_z;

    explicit Vector3d(double x_ = 0, double y_ = 0, double z_ = 0)
        : data{ x_, y_, z_ } {
    }

    Vector3d(const Vector3d& other)
        : data{ other.x(), other.y(), other.z() } {
    }

    Vector3d& operator=(const Vector3d& other) {
        x() = other.x();
        y() = other.y();
        z() = other.z();
        return *this;
    }

    double x() const { return data[0]; }

    double& x() { return data[0]; }

    Vector3d& x(double value) {
        data[0] = value;
        return *this;
    }

    double y() const { return data[1]; }

    double& y() { return data[1]; }

    Vector3d& y(double value) {
        data[1] = value;
        return *this;
    }

    double z() const { return data[2]; }

    double& z() { return data[2]; }

    Vector3d& z(double value) {
        data[2] = value;
        return *this;
    }

    bool operator==(const Vector3d& other) const {
        return utils::is_equal(x(), other.x())
            && utils::is_equal(y(), other.y())
            && utils::is_equal(z(), other.z());
    }

    bool operator!=(const Vector3d& other) const {
        return !(*this == other);
    }

    Vector3d operator+() const {
        return Vector3d{ x(), y(), z() };
    }

    Vector3d operator-() const {
        return Vector3d{ -x(), -y(), -z() };
    }

    Vector3d operator+(const Vector3d& other) const {
        return Vector3d{ x() + other.x(), y() + other.y(), z() + other.z() };
    }

    Vector3d operator-(const Vector3d& other) const {
        return Vector3d{ x() - other.x(), y() - other.y(), z() - other.z() };
    }

    Vector3d operator*(double value) const {
        return Vector3d{ x() * value, y() * value, z() * value };
    }

    Vector3d operator/(double value) const {
        assert(!utils::is_zero(value));
        return Vector3d{ x() / value, y() / value, z() / value };
    }

    Vector3d& operator+=(const Vector3d& other) {
        x() += other.x();
        y() += other.y();
        z() += other.z();
        return *this;
    }

    Vector3d& operator-=(const Vector3d& other) {
        x() -= other.x();
        y() -= other.y();
        z() -= other.z();
        return *this;
    }

    Vector3d& operator*=(double value) {
        x() *= value;
        y() *= value;
        z() *= value;
        return *this;
    }

    Vector3d& operator/=(double value) {
        assert(!utils::is_zero(value));
        x() /= value;
        y() /= value;
        z() /= value;
        return *this;
    }

    double length() const {
        return sqrt(x() * x() + y() * y() + z() * z());
    }

    double magnitude() const {
        return length();
    }

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

inline Vector3d operator*(double value, const Vector3d& vec) {
    return vec * value;
}

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
