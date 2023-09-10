#include "Vector2d.h"

namespace m3d {
const Vector2d Vector2d::zero{ 0, 0 };
const Vector2d Vector2d::unit_x{ 1, 0 };
const Vector2d Vector2d::unit_y{ 0, 1 };

namespace utils {

bool is_zero(const Vector2d& vec) {
    return vec == Vector2d::zero;
}

double distance(const Vector2d& a, const Vector2d& b) {
    return (a - b).length();
}

}
}
