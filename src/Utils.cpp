#include "Utils.hpp"

Point Util::Rotate(const Point& pos, const Point& origin, float angle) {

    float _cos, _sin;
    _sin = sin(angle);
    _cos = cos(angle);

    float ox, oy;
    ox = origin.x;
    oy = origin.y;

    // set x and y and translate with origin
    float x, y; 
    x = pos.x - ox;
    y = pos.y - oy;

    // rotate and translate back
    x = x * _cos - y * _sin + ox;
    y = x * _sin + y * _cos + oy;

    return Point{x, y};
}
