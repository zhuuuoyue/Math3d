#include "Vector3d.h"

namespace m3d {

const Vector3d Vector3d::zero{ 0, 0, 0 };
const Vector3d Vector3d::unit_x{ 1, 0, 0 };
const Vector3d Vector3d::unit_y{ 0, 1, 0 };
const Vector3d Vector3d::unit_z{ 0, 0, 1 };

namespace utils {

double distance(const Vector3d p1, const Vector3d& p2) {
    return (p1 - p2).length();
}

bool is_zero(const Vector3d& vec) {
    return vec == Vector3d::zero;
}

}
}
