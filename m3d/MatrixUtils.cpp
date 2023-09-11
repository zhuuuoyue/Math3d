#include "MatrixUtils.h"

namespace m3d {
    namespace utils {
        Vector2d transform(const Vector2d& src, const Matrix2d& mat) {
            return to_vector(to_row_matrix(src) * mat);
        }

        Vector3d transform(const Vector3d& src, const Matrix3d& mat) {
            return to_vector(to_row_matrix(src) * mat);
        }
    }
}
