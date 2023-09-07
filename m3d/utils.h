#pragma once

#include "m3d.h"
#include "constants.h"

namespace m3d {
namespace utils {

M3D_API bool is_equal(double a, double b, double tolerance = constants::DOUBLE_EPS);
M3D_API bool is_zero(double value, double tolerance = constants::DOUBLE_EPS);

}
}
