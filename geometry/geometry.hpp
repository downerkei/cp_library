#include <bits/stdc++.h>
using namespace std;

namespace geometry {

using Real = double;
constexpr Real EPS = 1e-7;

constexpr int sgn(Real a) { return (a < -EPS) ? -1 : (EPS < a) ? 1 : 0; }

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
    constexpr bool operator == (const Point& rhs) const { return !sgn(x - rhs.x) && !sgn(y - rhs.y); }
    constexpr bool operator != (const Point& rhs) const { return !(*this == rhs); }

    constexpr Real norm2() const { return x * x + y * y; }
    constexpr Real norm() const { return sqrt(norm2()); }
    constexpr Real arg() const { return atan2(y, x); }
    constexpr Point rot(Real theta) const { return Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }
    constexpr Point rot90() const { return Point(-y, x); }

    friend constexpr Real norm2(const Point& p) { return p.norm2(); }
    friend constexpr Real norm(const Point& p) { return p.norm(); }
    friend constexpr Real arg(const Point& p) { return p.arg(); }
    friend constexpr Point rot(const Point& p, Real theta) { return p.rot(theta); }
    friend constexpr Point rot90(const Point& p) { return p.rot90(); }

    friend istream& operator >> (istream& is, Point& p) { return is >> p.x >> p.y; }
    friend ostream& operator << (ostream& os, const Point& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

constexpr Real dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
constexpr Real cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
constexpr Point polar(Real r, Real theta) { return Point(r * cos(theta), r * sin(theta)); }

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

struct Line {
    Point s, t;
    constexpr Line(Point s=Point(0, 0), Point t=Point(0, 0)) : s(s), t(t) {}
    constexpr Point dir() const { return t - s; }
    constexpr Real norm() const { return dir().norm(); }
    constexpr Point normalize() const { return (t - s) / norm(); }

    friend constexpr Point dir(const Line& l) { return l.dir(); }
    friend constexpr Real norm(const Line& l) { return l.norm(); }
    friend constexpr Point normalize(const Line& l) { return l.normalize(); }
};

Point projection(const Line& l, const Point& p) {
    Real t = dot(p - l.s, l.t - l.s) / norm2(l.t - l.s);
    return l.s + l.dir() * t;
}
Point reflection(const Line& l, const Point& p) {
    Point x = projection(l, p);
    return 2 * x - p;
}

bool is_parallel(const Line& a, const Line& b) { return sgn(cross(a.dir(), b.dir())) == 0; }
bool is_orthogonal(const Line& a, const Line& b) { return sgn(dot(a.dir(), b.dir())) == 0; }
bool is_intersect(const Line& a, const Line& b) { return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0; }

Point cross_ll(const Line& a, const Line& b) {
    Real d1 = cross(a.dir(), b.dir());
    Real d2 = cross(a.dir(), a.t - b.s);
    return b.s + b.dir() * (d2 / d1);
}

Real dist_pp(const Point& a, const Point& b) {
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
    friend pair<int, int> diameter(const Polygon& pol) { return pol.diameter(); } 
};

// 2 : contain
// 1 : on line
// 0 : outside
int contain(const Polygon& pol, const Point& p) {
    bool in = false;
    int sz = pol.size();
    for(int i = 0; i < sz; i++) {
        Point a = pol[i] - p;
        Point b = pol[(i + 1) % sz] - p;
        if(a.y > b.y) swap(a, b);
        if(sgn(a.y) == -1 && sgn(b.y) == 1 && sgn(cross(a, b)) == 1) in ^= 1;
        if(sgn(cross(a, b)) == -1 && sgn(dot(a, b)) == -1) return 1;
    }
    return 2 * in;
}

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

Polygon convex_cut(const Polygon& pol, const Line& l) {
    int sz = pol.size();
    Polygon ret;
    for(int i = 0; i < pol.size(); i++) {
        int t1 = sgn(cross(l.dir(), pol[i] - l.s)), t2 = sgn(cross(l.dir(), pol[(i + 1) % sz] - l.s));
        if(t1 >= 0) ret.push_back(pol[i]); 
        if(t1 * t2 < 0) ret.push_back(cross_ll(Line(pol[i], pol[(i + 1) % sz]), l));
    }
    return ret;
}

Real closest_pair(vector<Point> ps) {
    auto rec = [](auto f, vector<Point>& ps, int l, int r) -> Real {
        if(r - l < 2) return 1e100;
        int mid = (l + r) / 2;
        Real x = ps[mid].x;
        Real d = min(f(f, ps, l, mid), f(f, ps, mid, r));
        auto it = ps.begin(), itl = it + l, itm = it + mid, itr = it + r;
        inplace_merge(itl, itm, itr, [](Point a, Point b) { return a.y < b.y; });
        vector<Point> near_line;
        for(int i = l; i < r; i++) {
            if(abs(ps[i].x - x) >= d) continue;
            int sz = near_line.size();
            for(int j = sz; j--;) {
                if(ps[i].y - near_line[j].y >= d) break;
                d = min(d, dist_pp(ps[i], near_line[j]));
            }
            near_line.push_back(ps[i]);
        }
        return d;
    };
    sort(ps.begin(), ps.end());
    return rec(rec, ps, 0, ps.size());
}

struct Circle {
    Point p;
    Real r;
    Circle() : p(Point(0, 0)), r(0) {}
    Circle(Point p, Real r) : p(p), r(r) {}
};

int intersection(const Circle& c1, const Circle& c2) {
    Real d = dist_pp(c1.p, c2.p);
    if(sgn(d - (c1.r + c2.r)) == 1) return 4;
    if(sgn(d - (c1.r + c2.r)) == 0) return 3;
    if(sgn(d - abs(c1.r - c2.r)) == 1) return 2;
    if(sgn(d - abs(c1.r - c2.r)) == 0) return 1;
    return 0;
}

pair<Point, Point> cross_cl(const Circle& c, const Line& l) {
    Point proj = projection(l, c.p);
    Real h = dist_lp(l, c.p);
    Real d = sqrt(c.r * c.r - h * h);
    Point p1 = proj + l.normalize() * d;
    Point p2 = proj - l.normalize() * d;
    if(p1 > p2) swap(p1, p2);
    return {p1, p2};
}

Circle incircle(const Point& a, const Point& b, const Point& c) {
    Real d1 = dist_pp(b, c);
    Real d2 = dist_pp(c, a);
    Real d3 = dist_pp(a, b);
    Point ip = (a * d1 + b * d2 + c * d3) / (d1 + d2 + d3);
    Real r = dist_lp(Line(a, b), ip);
    return Circle(ip, r);
}

Circle outcircle(const Point& a, const Point& b, const Point& c) {
    Line l1((a + b) / 2, (a + b) / 2 + rot90(b - a));
    Line l2((b + c) / 2, (b + c) / 2 + rot90(c - b));
    Point op = cross_ll(l1, l2);
    Real r = dist_pp(op, a);
    return Circle(op, r);
}

pair<Point, Point> cross_cc(const Circle& c1, const Circle& c2) {
    Real d = dist_pp(c1.p, c2.p);
    Real theta = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Real phi = arg(c2.p - c1.p);
    Point p1 = c1.p + polar(c1.r, phi - theta);
    Point p2 = c1.p + polar(c1.r, phi + theta);
    if(p1 > p2) swap(p1, p2);
    return {p1, p2};
}

}  // namespace geometry

using namespace geometry;
