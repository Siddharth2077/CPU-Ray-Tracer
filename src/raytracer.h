#pragma once

#include <cmath>
#include <limits>
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;

// Constants:
const float f_infinity = std::numeric_limits<float>::infinity();
const double f_pi = 3.1415927f;

// Utility function:
/// Converts angle in degrees to radians.
float deg_to_rad(float angle_in_degrees) {
    return angle_in_degrees * (f_pi / 180.0f);
}

// Common headers: defined below so that dependencies and constants defined above are accessible by these header files
#include "ray.h"
#include "color.h"
#include "vector3.h"