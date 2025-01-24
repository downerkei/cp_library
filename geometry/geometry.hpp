#include <bits/stdc++.h>
using namespace std;

namespace geometry {

using Real = double;
constexpr Real EPS = 1e-7;

constexpr int sgn(Real a) { return (a < EPS) ? -1 : (EPS < a) ? 1 : 0; }

struct Point {
    Real x, y;
    constexpr Point(Real x=0, Real y=0) : x(x), y(y) {}

    constexpr Point& operator += (const Point& rhs) { return x += rhs.x, y += rhs.y, *this; }
    constexpr Point& operator -= (const Point& rhs) { return x -= rhs.x, y -= rhs.y, *this; }
    constexpr Point& operator *= (Real k) { return x *= k, y *= k, *this; }
    constexpr Point& operator /= (Real k) { return x /= k, y /= k, *this; }

    constexpr Point operator + (const Point& rhs) const { return Point(*this) += rhs; }
    constexpr Point operator - (const Point& rhs) const { return Point(*this) -= rhs; }
    constexpr Point operator * (Real k) const { return Point(*this) *= k; }
    constexpr Point operator / (Real k) const { return Point(*this) /= k; }
    friend constexpr Point operator * (Real k, const Point& p) { return Point(p.x * k, p.y * k); }

    constexpr Point operator - () const { return Point() - *this; }

    constexpr bool operator < (const Point& rhs) const { return sgn(x - rhs.x) ? (x < rhs.x) : (y < rhs.y); }
    constexpr bool operator > (const Point& rhs) const { return rhs < *this; }
    constexpr bool operator == (const Point& rhs) const { return sgn(x - rhs.x) && sgn(y - rhs.y); }
    constexpr bool operator != (const Point& rhs) const { return !(*this == rhs); }

    constexpr Real norm2() const { return x * x + y * y; }
    constexpr Real norm() const { return sqrt(norm2()); }
    constexpr Real arg() const { return atan2(y, x); }
    constexpr Point rotate(Real theta) const { return Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }

    friend istream& operator >> (istream& is, Point& p) { return is >> p.x >> p.y; }
    friend ostream& operator << (ostream& os, const Point& p) { return os << "(" << p.x << ", " << p.y << ")"; }

    friend constexpr Real dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    friend constexpr Real cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

    friend constexpr Real norm2(const Point& p) { return p.norm2(); }
    friend constexpr Real norm(const Point& p) { return p.norm(); }
    friend constexpr Real arg(const Point& p) { return p.arg(); }
};

struct Line {
    Point s, t;
    constexpr Line(Point s=Point(0, 0), Point t=Point(0, 0)) : s(s), t(t) {}
    constexpr Point dir() const { return t - s; }
    constexpr Real norm() const { return dir().norm(); }

    friend constexpr Point dir(const Line& l) { return l.dir(); }
    friend constexpr Real norm(const Line& l) { return l.norm(); }
};

Point projection(const Line& l, const Point& p) {
    Real t = dot(p - l.s, l.t - l.s) / norm2(l.t - l.s);
    return l.s + l.dir() * t;
}

Point reflection(const Line& l, const Point& p) {
    Point x = projection(l, p);
    return 2 * x - p;
}

// +1 : a - b, a - c : ccw
// -1 : a - b, a - c : cw
// +2 : c - a - b    : on_back
// -2 : a - b - c    : on_front
//  0 : a - c - b    : on_segment
int ccw(const Point& a, Point b, Point c) {
    b -= a, c -= a;
    if(sgn(cross(b, c)) == 1) return 1;
    if(sgn(cross(b, c)) == -1) return -1;
    if(sgn(dot(b, c)) == -1) return 2;
    if(b.norm2() < c.norm2()) return -2;
    return 0; 
}

bool is_parallel(const Line& a, const Line& b) {
    return sgn(cross(a.dir(), b.dir())) == 0;
}

bool is_orthogonal(const Line& a, const Line& b) {
    return sgn(dot(a.dir(), b.dir())) == 0;
}

bool is_intersect(const Line& a, const Line& b) {
    return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;
}

Point cross_point(const Line& a, const Line& b) {
    Real d1 = cross(a.dir(), b.dir());
    Real d2 = cross(a.dir(), a.t - b.s);
    return b.s + b.dir() * (d2 / d1);
}

Real dist(const Point& a, const Point& b) {
    return norm(a - b);
}
Real dist_lp(const Line& l, const Point& p) {
    return abs(cross(l.dir(), p - l.s)) / norm(l);
}
Real dist_sp(const Line& l, const Point& p) {
    if(sgn(dot(l.dir(), p - l.s)) == -1) return norm(p - l.s);
    if(sgn(dot(-l.dir(), p - l.t)) == -1) return norm(p - l.t);
    return dist_lp(l, p);
}
Real dist_ss(const Line& a, const Line& b) {
    if(is_intersect(a, b)) return 0;
    return min({dist_sp(a, b.s), dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b, a.t)});
}

struct Polygon : public vector<Point> {
    using vector<Point>::vector;
    Real area() const {
        int sz = size();
        Real ret = 0;
        for(int i = 0; i < sz; i++) {
            ret += cross((*this)[i], (*this)[(i + 1) % sz]);
        }
        return ret / 2;
    }

    bool is_convex() const {
        int sz = size();
        for(int i = 0; i < sz; i++) {
            if(ccw((*this)[i], (*this)[(i + 1) % sz], (*this)[(i + 2) % sz]) == -1) false;
        }
        return true;
    }

    // 2 : contain
    // 1 : on line
    // 0 : outside
    int contain(const Point& p) const {
        bool in = false;
        int sz = size();
        for(int i = 0; i < sz; i++) {
            Point a = (*this)[i] - p;
            Point b = (*this)[(i + 1) % sz] - p;
            if(a.y > b.y) std::swap(a, b);
            if(sgn(a.y) == -1 && sgn(b.y) == 1 && sgn(cross(a, b)) == 1) in ^= 1;
            if(sgn(cross(a, b)) == -1 && sgn(dot(a, b)) == -1) return 1;
        }
        return 2 * in;
    }

    pair<int, int> diameter() const {
        assert(is_convex());
        int sz = size();
        int right = max_element(begin(), end()) - begin();
        int left = min_element(begin(), end()) - begin();
        Real max_dist = norm2((*this)[left] - (*this)[right]);
        pair<int, int> ret = {left, right};
        for(int i = 0; i < sz; i++) {
            Point pre = (*this)[(left + 1) % sz] - (*this)[left];
            Point nxt = (*this)[right] - (*this)[(right + 1) % sz];
            if(ccw(Point(0, 0), pre, nxt) == 1) left = (left + 1) % sz;
            else right = (right + 1) % sz;
            if(norm2((*this)[left] - (*this)[right]) > max_dist) max_dist = norm2((*this)[left] - (*this)[right]), ret = {left, right};
        }
        return ret;
    }

    friend Real area(const Polygon& pol) { return pol.area(); }
    friend bool is_convex(const Polygon& pol) { return pol.is_convex(); }
    friend int contain(const Polygon& pol, const Point& p) { return pol.contain(p); }
    friend pair<int, int> diameter(const Polygon& pol) { return pol.diameter(); } 
};

Polygon convex_hull(Polygon pol) {
    int sz = pol.size();
    sort(pol.begin(), pol.end());
    Polygon ret;
    for(int i = 0; i < sz; i++) {
        while(ret.size() > 1 && ccw(ret[ret.size() - 2], ret.back(), pol[i]) == -1) ret.pop_back();
        ret.push_back(pol[i]);
    }
    int t = ret.size();
    for(int i = sz - 2; i >= 0; i--) {
        while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), pol[i]) == -1) ret.pop_back();
        ret.push_back(pol[i]);
    }
    ret.pop_back();
    return ret;
}

}  // namespace geometry

using namespace geometry;