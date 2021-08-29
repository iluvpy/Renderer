#pragma once

#include <cmath>
#include "Structs.hpp"

namespace Util 
{

    // rotates pos around origin by angle (angle in radians)
    Point Rotate(const Point& pos, const Point& origin, float angle);
    inline float ToRadians(float angle) { return angle * M_PI/180; }
	
};