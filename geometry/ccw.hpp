#include "point.hpp"

int ccw(Point& a, Point& b, Point& c) {
    long long ret = a.x * b.y + b.x * c.y + c.x * a.y;
	ret -= b.x * a.y + c.x * b.y + a.x * c.y;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}
