#include "point.hpp"

int up(const Point& p) {
    if(p.y > 0 || (p.y == 0 && p.x < 0)) return 1;
    if(p.y < 0 || (p.y == 0 && p.x > 0)) return -1;
    return 0;
}

bool cmp(const Point& a, const Point& b) {
    if(up(a) == up(b)) return (long long)a.y * b.x < (long long)b.y * a.x;
    return up(a) < up(b);
}
