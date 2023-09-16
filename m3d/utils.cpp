#include "utils.h"

#include <algorithm>

#include "constants.h"

namespace m3d {
    namespace utils {

        bool is_equal(double a, double b, double tolerance) {
            return abs(a - b) < tolerance;
        }

        bool is_zero(double value, double tolerance) {
            return abs(value) < tolerance;
        }

        double to_degree(double rad) {
            return rad / constants::PI * 180;
        }

        double to_radius(double deg) {
            return deg / 180 * constants::PI;
        }

    }
}
