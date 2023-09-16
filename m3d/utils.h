#pragma once

#include "m3d.h"
#include "constants.h"

namespace m3d {
    namespace utils {

        /// <summary>
        /// 判断两个 double 浮点数是否相等
        /// </summary>
        /// <param name="a">第一个浮点数</param>
        /// <param name="b">第二个浮点数</param>
        /// <param name="tolerance">判断容差</param>
        /// <returns>相等则返回 true，否则返回 false</returns>
        M3D_API bool is_equal(double a, double b, double tolerance = constants::DOUBLE_EPS);

        /// <summary>
        /// 判断 double 浮点数是否为零
        /// </summary>
        /// <param name="value">待判断的值</param>
        /// <param name="tolerance">判断容差</param>
        /// <returns>是则返回 true，否则返回 false</returns>
        M3D_API bool is_zero(double value, double tolerance = constants::DOUBLE_EPS);

        /// <summary>
        /// 弧度转角度
        /// </summary>
        /// <param name="rad">弧度</param>
        /// <returns>角度</returns>
        M3D_API double to_degree(double rad);

        /// <summary>
        /// 角度转弧度
        /// </summary>
        /// <param name="deg">角度</param>
        /// <returns>弧度</returns>
        M3D_API double to_radius(double deg);

    }
}
