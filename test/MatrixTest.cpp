#include "pch.h"
#include "Matrix.h"
#include "MatrixUtils.h"
#include <vector>

using namespace m3d;
using namespace m3d::utils;

TEST(Matrix, EqualOperator) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    Matrix2d b = create_matrix_2d({ 1, 2, 3, 4 });
    EXPECT_EQ(a, b);
}

TEST(Matrix, NotEqualOperator) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    Matrix2d b = create_matrix_2d({ 1, 2, 3, 5 });
    EXPECT_NE(a, b);
}

TEST(Matrix, DefaultConstructor) {
    Matrix2d a;
    Matrix2d b = create_matrix_2d({ 0, 0, 0, 0 });
    EXPECT_EQ(a, b);
}

TEST(Matrix, Constructor) {
    Matrix2d a{ 3 };
    Matrix2d b = create_matrix_2d({ 3, 3, 3, 3 });
    EXPECT_EQ(a, b);
}

TEST(Matrix, CopyConstructor) {
    Matrix3d a = create_matrix_3d({ 3, 1, 4, 1, 5, 9, 2, 6, 5 });
    Matrix3d b{ a };
    EXPECT_EQ(a, b);
}

TEST(Matrix, AssignOperator) {
    Matrix3d a = create_matrix_3d({ 3, 1, 4, 1, 5, 9, 2, 6, 5 });
    Matrix3d b;
    b = a;
    EXPECT_EQ(a, b);
}

TEST(Matrix, Shape) {
    Matrix3d mat;
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
    EXPECT_EQ(mat.size(), 9);
}

TEST(Matrix, AccessElements) {
    std::vector<double> values{ 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    Matrix3d mat = create_matrix_3d(values);
    size_t i{ 0 };
    for (size_t r = 0; r < mat.rows(); ++r) {
        for (size_t c = 0; c < mat.columns(); ++c) {
            EXPECT_DOUBLE_EQ(mat(r, c), values[i]);
            EXPECT_DOUBLE_EQ(mat.at(r, c), values[i]);
            ++i;
        }
    }
}

TEST(Matrix, IsSquare) {
    Matrix3d a;
    EXPECT_TRUE(a.is_square());
    Matrix<2, 3, double> b;
    EXPECT_FALSE(b.is_square());
}

TEST(Matrix, IsDiagonal) {
    Matrix<2, 3, double> a;
    EXPECT_FALSE(a.is_diagonal());
    Matrix3d b;
    EXPECT_TRUE(b.is_diagonal());
    Matrix3d c = create_matrix_3d({ 1, 0, 0, 0, 1, 0, 0, 0, 1 });
    EXPECT_TRUE(c.is_diagonal());
    Matrix3d d = create_matrix_3d({ 1, 0, 1, 0, 1, 0, 0, 0, 1 });
    EXPECT_FALSE(d.is_diagonal());
    Matrix3d e = create_matrix_3d({ 1, 0, 0, 0, 2, 0, 0, 0, 3 });
    EXPECT_TRUE(e.is_diagonal());
}

TEST(Matrix, IsIdentity) {
    Matrix2d a = create_matrix_2d({ 1, 0, 0, 1 });
    EXPECT_TRUE(a.is_identity());
    Matrix3d b = create_matrix_3d({ 1, 0, 0, 0, 1, 0, 0, 0, 1 });
    EXPECT_TRUE(b.is_identity());
    Matrix3d c = create_matrix_3d({ 1, 0, 0, 0, 2, 0, 0, 0, 3 });
    EXPECT_FALSE(c.is_identity());
}

TEST(Matrix, Transpose) {
    Matrix<4, 3, double> before = create_matrix<4, 3, double>({
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
        });
    Matrix<3, 4, double> after = before.transpose();
    Matrix<3, 4, double> expected = create_matrix<3, 4, double>({
        1, 4, 7, 10, 2, 5, 8, 11, 3, 6, 9, 12
        });
    EXPECT_EQ(after, expected);
}

TEST(Matrix, Positive) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    Matrix2d b = +a;
    EXPECT_EQ(a, b);
}

TEST(Matrix, Negative) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    Matrix2d b = -a;
    Matrix2d c = create_matrix_2d({ -1, -2, -3, -4 });
    EXPECT_EQ(b, c);
}

TEST(Matrix, Add) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    Matrix2d b = create_matrix_2d({ 2, 3, 4, 5 });
    Matrix2d c = a + b;
    Matrix2d d = create_matrix_2d({ 3, 5, 7, 9 });
    EXPECT_EQ(c, d);
    a += b;
    EXPECT_EQ(a, d);
}

TEST(Matrix, Minus) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    Matrix2d b = create_matrix_2d({ 2, 3, 4, 5 });
    Matrix2d c = a - b;
    Matrix2d d = create_matrix_2d({ -1, -1, -1, -1 });
    EXPECT_EQ(c, d);
    a -= b;
    EXPECT_EQ(a, d);
}

TEST(Matrix, TimesK) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    double k = 0.5;
    Matrix2d c = a * k;
    Matrix2d d = create_matrix_2d({ 0.5, 1, 1.5, 2 });
    EXPECT_EQ(c, d);
    Matrix2d e = k * a;
    EXPECT_EQ(e, d);
    a *= k;
    EXPECT_EQ(a, d);
}

TEST(Matrix, Divide) {
    Matrix2d a = create_matrix_2d({ 1, 2, 3, 4 });
    double k = 2;
    Matrix2d c = a / k;
    Matrix2d d = create_matrix_2d({ 0.5, 1, 1.5, 2 });
    EXPECT_EQ(c, d);
    a /= k;
    EXPECT_EQ(a, d);
}

TEST(Matrix, Times2d) {
    Matrix2d a = create_matrix_2d({ -3, 0, 5, 0.5 });
    Matrix2d b = create_matrix_2d({ -7, 2, 4, 6 });
    Matrix2d result = a * b;
    Matrix2d expect = create_matrix_2d({ 21, -6, -33, 13 });
    EXPECT_EQ(result, expect);
}

TEST(Matrix, Times3d) {
    Matrix3d a = create_matrix_3d({
        1, -5, 3,
        0, -2, 6,
        7, 2, -4
        });
    Matrix3d b = create_matrix_3d({
        -8, 6, 1,
        7, 0, -3,
        2, 4, 5
        });
    Matrix3d result = a * b;
    Matrix3d expect = create_matrix_3d({
        -37, 18, 31,
        -2, 24, 36,
        -50, 26, -19
        });
    EXPECT_EQ(result, expect);
}
