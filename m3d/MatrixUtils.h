#pragma once

#include "m3d.h"

#include <vector>

#include "Vector2d.h"
#include "Vector3d.h"
#include "Matrix.h"

namespace m3d {
    namespace utils {

        /// <summary>
        /// 生成矩阵
        /// </summary>
        /// <typeparam name="T">矩阵元素类型</typeparam>
        /// <param name="values">矩阵元素值列表（按行排列）</param>
        /// <returns>生成的矩阵</returns>
        template<size_t R, size_t C, class T>
        Matrix<R, C, T> create_matrix(const std::vector<T>& values) {
            Matrix<R, C, T> result;
            auto src = values.begin();
            size_t n = std::min(result.size(), values.size());
            T* dst = result.data();
            for (size_t offset = 0; offset < n; ++offset, ++dst, ++src) {
                *dst = *src;
            }
            return result;
        }

        /// <summary>
        /// 生成 2 * 2 的 double 矩阵
        /// </summary>
        /// <param name="values">矩阵元素值列表（按行排列）</param>
        /// <returns>生成的矩阵</returns>
        inline Matrix2d create_matrix_2d(const std::vector<double>& values) {
            return create_matrix<2, 2, double>(values);
        }

        /// <summary>
        /// 生成 3 * 3 的 double 矩阵
        /// </summary>
        /// <param name="values">矩阵元素值列表（按行排列）</param>
        /// <returns>生成的矩阵</returns>
        inline Matrix3d create_matrix_3d(const std::vector<double>& values) {
            return create_matrix<3, 3, double>(values);
        }

        /// <summary>
        /// 生成 4 * 4 的 double 矩阵
        /// </summary>
        /// <param name="values">矩阵元素值列表（按行排列）</param>
        /// <returns>生成的矩阵</returns>
        inline Matrix4d create_matrix_4d(const std::vector<double>& values) {
            return create_matrix<4, 4, double>(values);
        }

        /// <summary>
        /// 二维向量转换成一行二列矩阵
        /// </summary>
        /// <param name="vec">二维向量</param>
        /// <returns>一行二列矩阵</returns>
        inline Matrix<1, 2, double> to_row_matrix(const Vector2d& vec) {
            return create_matrix<1, 2, double>({ vec.x(), vec.y() });
        }

        /// <summary>
        /// 二维向量转换成二行一列矩阵
        /// </summary>
        /// <param name="vec">二维向量</param>
        /// <returns>二行一列矩阵</returns>
        inline Matrix<2, 1, double> to_column_matrix(const Vector2d& vec) {
            return create_matrix<2, 1, double>({ vec.x(), vec.y() });
        }

        /// <summary>
        /// 三维向量转换成一行三列矩阵
        /// </summary>
        /// <param name="vec">三维向量</param>
        /// <returns>一行三列矩阵</returns>
        inline Matrix<1, 3, double> to_row_matrix(const Vector3d& vec) {
            return create_matrix<1, 3, double>({ vec.x(), vec.y(), vec.z() });
        }

        /// <summary>
        /// 三维向量转换成三行一列矩阵
        /// </summary>
        /// <param name="vec">三维向量</param>
        /// <returns>三行一列矩阵</returns>
        inline Matrix<3, 1, double> to_column_matrix(const Vector3d& vec) {
            return create_matrix<3, 1, double>({ vec.x(), vec.y(), vec.z() });
        }

        /// <summary>
        /// 一行二列矩阵转换成二维向量
        /// </summary>
        /// <param name="mat">一行二列矩阵</param>
        /// <returns>二维向量</returns>
        inline Vector2d to_vector(const Matrix<1, 2, double>& mat) {
            return Vector2d{ mat(0, 0), mat(0, 1) };
        }

        /// <summary>
        /// 二行一列矩阵转换成二维向量
        /// </summary>
        /// <param name="mat">二行一列矩阵</param>
        /// <returns>二维向量</returns>
        inline Vector2d to_vector(const Matrix<2, 1, double>& mat) {
            return Vector2d{ mat(0, 0), mat(1, 0) };
        }

        /// <summary>
        /// 一行三列矩阵转换成三维向量
        /// </summary>
        /// <param name="mat">一行三列矩阵</param>
        /// <returns>三维向量</returns>
        inline Vector3d to_vector(const Matrix<1, 3, double>& mat) {
            return Vector3d{ mat(0, 0), mat(0, 1), mat(0, 2) };
        }

        /// <summary>
        /// 三行一列矩阵转换成三维向量
        /// </summary>
        /// <param name="mat">三行一列矩阵</param>
        /// <returns>三维向量</returns>
        inline Vector3d to_vector(const Matrix<3, 1, double>& mat) {
            return Vector3d{ mat(0, 0), mat(1, 0), mat(2, 0) };
        }

        /// <summary>
        /// 使用 2 * 2 矩阵对二维点进行变换
        /// </summary>
        /// <param name="src">二维点</param>
        /// <param name="mat">变换矩阵</param>
        /// <returns>变换后的点</returns>
        M3D_API Vector2d transform(const Vector2d& src, const Matrix2d& mat);

        /// <summary>
        /// 使用 3 * 3 矩阵对三维点进行变换
        /// </summary>
        /// <param name="src">三维点</param>
        /// <param name="mat">变换矩阵</param>
        /// <returns>变换后的点</returns>
        M3D_API Vector3d transform(const Vector3d& src, const Matrix3d& mat);

        /// <summary>
        /// 生成二维旋转矩阵
        /// </summary>
        /// <param name="rad">旋转角度（弧度表示）</param>
        /// <returns>旋转矩阵</returns>
        M3D_API Matrix2d create_rotation_matrix_2d(double rad);
    }
}
