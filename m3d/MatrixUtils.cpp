#include "MatrixUtils.h"

#include <numeric>

namespace m3d {
    namespace utils {
        Vector2d transform(const Vector2d& src, const Matrix2d& mat) {
            return to_vector(to_row_matrix(src) * mat);
        }

        Vector3d transform(const Vector3d& src, const Matrix3d& mat) {
            return to_vector(to_row_matrix(src) * mat);
        }

        Matrix2d create_rotation_matrix_2d(double rad) {
            double c = cos(rad);
            double s = sin(rad);
            return create_matrix_2d({ c, s, -s, c });
        }
    }
}
