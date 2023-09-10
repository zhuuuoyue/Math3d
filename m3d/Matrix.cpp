#include "Matrix.h"

namespace m3d {
namespace utils {
Matrix2d create_identify_matrix_2d() {
    Matrix2d mat;
    mat(0, 0) = 1;
    mat(1, 1) = 1;
    return mat;
}
Matrix3d create_identify_matrix_3d() {
    Matrix3d mat;
    mat(0, 0) = 1;
    mat(1, 1) = 1;
    mat(2, 2) = 1;
    return mat;
}
Matrix4d create_identify_matrix_4d() {
    Matrix4d mat;
    mat(0, 0) = 1;
    mat(1, 1) = 1;
    mat(2, 2) = 1;
    mat(3, 3) = 1;
    return mat;
}
}
}
