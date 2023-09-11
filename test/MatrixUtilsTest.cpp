#include "pch.h"
#include "MatrixUtils.h"

using namespace m3d;
using namespace m3d::utils;

using Row2d = Matrix<1, 2, double>;
using Column2d = Matrix<2, 1, double>;

using Row3d = Matrix<1, 3, double>;
using Column3d = Matrix<3, 1, double>;

TEST(MatrixUtils, ToRowMatrix2d) {
    Row2d result = to_row_matrix(Vector2d{ 1, 2 });
    Row2d expect = create_matrix<1, 2, double>({ 1, 2 });
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, ToColumnMatrix2d) {
    Column2d result = to_column_matrix(Vector2d{ 1, 2 });
    Column2d expect = create_matrix<2, 1, double>({ 1, 2 });
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, ToRowMatrix3d) {
    Row3d result = to_row_matrix(Vector3d{ 1, 2, 3 });
    Row3d expect = create_matrix<1, 3, double>({ 1, 2, 3 });
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, ToColumnMatrix3d) {
    Column3d result = to_column_matrix(Vector3d{ 1, 2, 3 });
    Column3d expect = create_matrix<3, 1, double>({ 1, 2, 3 });
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, Matrix12ToVector) {
    Vector2d result = to_vector(create_matrix<1, 2, double>({ 1, 2 }));
    Vector2d expect{ 1, 2 };
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, Matrix21ToVector) {
    Vector2d result = to_vector(create_matrix<2, 1, double>({ 1, 2 }));
    Vector2d expect{ 1, 2 };
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, Matrix13ToVector) {
    Vector3d result = to_vector(create_matrix<1, 3, double>({ 1, 2, 3 }));
    Vector3d expect{ 1, 2, 3 };
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, Matrix31ToVector) {
    Vector3d result = to_vector(create_matrix<3, 1, double>({ 1, 2, 3 }));
    Vector3d expect{ 1, 2, 3 };
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, Transform2d) {
    Vector2d point{ 1, 1 };
    Matrix2d matrix = create_matrix_2d({ 0, 1, -1, 0 });
    Vector2d result = transform(point, matrix);
    Vector2d expect{ -1, 1 };
    EXPECT_EQ(result, expect);
}

TEST(MatrixUtils, Transform3d) {
    Vector3d point{ 1, 1, 1 };
    Matrix3d matrix = create_matrix_3d({ 1, 0, 0, 0, 0, 1, 0, -1, 0 });
    Vector3d result = transform(point, matrix);
    Vector3d expect{ 1, -1, 1 };
    EXPECT_EQ(result, expect);
}
