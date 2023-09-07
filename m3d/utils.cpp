#include "utils.h"

#include <algorithm>

namespace m3d {
namespace utils {

bool is_equal(double a, double b, double tolerance) {
    return abs(a - b) < tolerance;
}

bool is_zero(double value, double tolerance) {
    return abs(value) < tolerance;
}

}
}
