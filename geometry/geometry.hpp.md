---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/geometry.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nnamespace geometry {\n\nusing Real = double;\nconstexpr Real\
    \ EPS = 1e-7;\n\nconstexpr int sgn(Real a) { return (a < -EPS) ? -1 : (EPS < a)\
    \ ? 1 : 0; }\n\nstruct Point {\n    Real x, y;\n    constexpr Point(Real x=0,\
    \ Real y=0) : x(x), y(y) {}\n\n    constexpr Point& operator += (const Point&\
    \ rhs) { return x += rhs.x, y += rhs.y, *this; }\n    constexpr Point& operator\
    \ -= (const Point& rhs) { return x -= rhs.x, y -= rhs.y, *this; }\n    constexpr\
    \ Point& operator *= (Real k) { return x *= k, y *= k, *this; }\n    constexpr\
    \ Point& operator /= (Real k) { return x /= k, y /= k, *this; }\n\n    constexpr\
    \ Point operator + (const Point& rhs) const { return Point(*this) += rhs; }\n\
    \    constexpr Point operator - (const Point& rhs) const { return Point(*this)\
    \ -= rhs; }\n    constexpr Point operator * (Real k) const { return Point(*this)\
    \ *= k; }\n    constexpr Point operator / (Real k) const { return Point(*this)\
    \ /= k; }\n    friend constexpr Point operator * (Real k, const Point& p) { return\
    \ Point(p.x * k, p.y * k); }\n\n    constexpr Point operator - () const { return\
    \ Point() - *this; }\n\n    constexpr bool operator < (const Point& rhs) const\
    \ { return sgn(x - rhs.x) ? (x < rhs.x) : (y < rhs.y); }\n    constexpr bool operator\
    \ > (const Point& rhs) const { return rhs < *this; }\n    constexpr bool operator\
    \ == (const Point& rhs) const { return !sgn(x - rhs.x) && !sgn(y - rhs.y); }\n\
    \    constexpr bool operator != (const Point& rhs) const { return !(*this == rhs);\
    \ }\n\n    constexpr Real norm2() const { return x * x + y * y; }\n    constexpr\
    \ Real norm() const { return sqrt(norm2()); }\n    constexpr Real arg() const\
    \ { return atan2(y, x); }\n    constexpr Point rot(Real theta) const { return\
    \ Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }\n\
    \    constexpr Point rot90() const { return Point(-y, x); }\n\n    friend constexpr\
    \ Real norm2(const Point& p) { return p.norm2(); }\n    friend constexpr Real\
    \ norm(const Point& p) { return p.norm(); }\n    friend constexpr Real arg(const\
    \ Point& p) { return p.arg(); }\n    friend constexpr Point rot(const Point& p,\
    \ Real theta) { return p.rot(theta); }\n    friend constexpr Point rot90(const\
    \ Point& p) { return p.rot90(); }\n\n    friend istream& operator >> (istream&\
    \ is, Point& p) { return is >> p.x >> p.y; }\n    friend ostream& operator <<\
    \ (ostream& os, const Point& p) { return os << \"(\" << p.x << \", \" << p.y <<\
    \ \")\"; }\n};\n\nconstexpr Real dot(const Point& a, const Point& b) { return\
    \ a.x * b.x + a.y * b.y; }\nconstexpr Real cross(const Point& a, const Point&\
    \ b) { return a.x * b.y - a.y * b.x; }\nconstexpr Point polar(Real r, Real theta)\
    \ { return Point(r * cos(theta), r * sin(theta)); }\n\n// +1 : a - b, a - c :\
    \ ccw\n// -1 : a - b, a - c : cw\n// +2 : c - a - b    : on_back\n// -2 : a -\
    \ b - c    : on_front\n//  0 : a - c - b    : on_segment\nint ccw(const Point&\
    \ a, Point b, Point c) {\n    b -= a, c -= a;\n    if(sgn(cross(b, c)) == 1) return\
    \ 1;\n    if(sgn(cross(b, c)) == -1) return -1;\n    if(sgn(dot(b, c)) == -1)\
    \ return 2;\n    if(b.norm2() < c.norm2()) return -2;\n    return 0; \n}\n\nstruct\
    \ Line {\n    Point s, t;\n    constexpr Line(Point s=Point(0, 0), Point t=Point(0,\
    \ 0)) : s(s), t(t) {}\n    constexpr Point dir() const { return t - s; }\n   \
    \ constexpr Real norm() const { return dir().norm(); }\n    constexpr Point normalize()\
    \ const { return (t - s) / norm(); }\n\n    friend constexpr Point dir(const Line&\
    \ l) { return l.dir(); }\n    friend constexpr Real norm(const Line& l) { return\
    \ l.norm(); }\n    friend constexpr Point normalize(const Line& l) { return l.normalize();\
    \ }\n};\n\nPoint projection(const Line& l, const Point& p) {\n    Real t = dot(p\
    \ - l.s, l.t - l.s) / norm2(l.t - l.s);\n    return l.s + l.dir() * t;\n}\nPoint\
    \ reflection(const Line& l, const Point& p) {\n    Point x = projection(l, p);\n\
    \    return 2 * x - p;\n}\n\nbool is_parallel(const Line& a, const Line& b) {\
    \ return sgn(cross(a.dir(), b.dir())) == 0; }\nbool is_orthogonal(const Line&\
    \ a, const Line& b) { return sgn(dot(a.dir(), b.dir())) == 0; }\nbool is_intersect(const\
    \ Line& a, const Line& b) { return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <=\
    \ 0 && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0; }\n\nPoint cross_ll(const\
    \ Line& a, const Line& b) {\n    Real d1 = cross(a.dir(), b.dir());\n    Real\
    \ d2 = cross(a.dir(), a.t - b.s);\n    return b.s + b.dir() * (d2 / d1);\n}\n\n\
    Real dist_pp(const Point& a, const Point& b) {\n    return norm(a - b);\n}\nReal\
    \ dist_lp(const Line& l, const Point& p) {\n    return abs(cross(l.dir(), p -\
    \ l.s)) / norm(l);\n}\nReal dist_sp(const Line& l, const Point& p) {\n    if(sgn(dot(l.dir(),\
    \ p - l.s)) == -1) return norm(p - l.s);\n    if(sgn(dot(-l.dir(), p - l.t)) ==\
    \ -1) return norm(p - l.t);\n    return dist_lp(l, p);\n}\nReal dist_ss(const\
    \ Line& a, const Line& b) {\n    if(is_intersect(a, b)) return 0;\n    return\
    \ min({dist_sp(a, b.s), dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b, a.t)});\n\
    }\n\nstruct Polygon : public vector<Point> {\n    using vector<Point>::vector;\n\
    \    Real area() const {\n        int sz = size();\n        Real ret = 0;\n  \
    \      for(int i = 0; i < sz; i++) {\n            ret += cross((*this)[i], (*this)[(i\
    \ + 1) % sz]);\n        }\n        return ret / 2;\n    }\n\n    bool is_convex()\
    \ const {\n        int sz = size();\n        for(int i = 0; i < sz; i++) {\n \
    \           if(ccw((*this)[i], (*this)[(i + 1) % sz], (*this)[(i + 2) % sz]) ==\
    \ -1) false;\n        }\n        return true;\n    }\n\n    pair<int, int> diameter()\
    \ const {\n        assert(is_convex());\n        int sz = size();\n        int\
    \ right = max_element(begin(), end()) - begin();\n        int left = min_element(begin(),\
    \ end()) - begin();\n        Real max_dist = norm2((*this)[left] - (*this)[right]);\n\
    \        pair<int, int> ret = {left, right};\n        for(int i = 0; i < sz; i++)\
    \ {\n            Point pre = (*this)[(left + 1) % sz] - (*this)[left];\n     \
    \       Point nxt = (*this)[right] - (*this)[(right + 1) % sz];\n            if(ccw(Point(0,\
    \ 0), pre, nxt) == 1) left = (left + 1) % sz;\n            else right = (right\
    \ + 1) % sz;\n            if(norm2((*this)[left] - (*this)[right]) > max_dist)\
    \ max_dist = norm2((*this)[left] - (*this)[right]), ret = {left, right};\n   \
    \     }\n        return ret;\n    }\n\n    friend Real area(const Polygon& pol)\
    \ { return pol.area(); }\n    friend bool is_convex(const Polygon& pol) { return\
    \ pol.is_convex(); }\n    friend pair<int, int> diameter(const Polygon& pol) {\
    \ return pol.diameter(); } \n};\n\n// 2 : contain\n// 1 : on line\n// 0 : outside\n\
    int contain(const Polygon& pol, const Point& p) {\n    bool in = false;\n    int\
    \ sz = pol.size();\n    for(int i = 0; i < sz; i++) {\n        Point a = pol[i]\
    \ - p;\n        Point b = pol[(i + 1) % sz] - p;\n        if(a.y > b.y) swap(a,\
    \ b);\n        if(sgn(a.y) == -1 && sgn(b.y) == 1 && sgn(cross(a, b)) == 1) in\
    \ ^= 1;\n        if(sgn(cross(a, b)) == -1 && sgn(dot(a, b)) == -1) return 1;\n\
    \    }\n    return 2 * in;\n}\n\nPolygon convex_hull(Polygon pol) {\n    int sz\
    \ = pol.size();\n    sort(pol.begin(), pol.end());\n    Polygon ret;\n    for(int\
    \ i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size() -\
    \ 2], ret.back(), pol[i]) == -1) ret.pop_back();\n        ret.push_back(pol[i]);\n\
    \    }\n    int t = ret.size();\n    for(int i = sz - 2; i >= 0; i--) {\n    \
    \    while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), pol[i]) == -1)\
    \ ret.pop_back();\n        ret.push_back(pol[i]);\n    }\n    ret.pop_back();\n\
    \    return ret;\n}\n\nPolygon convex_cut(const Polygon& pol, const Line& l) {\n\
    \    int sz = pol.size();\n    Polygon ret;\n    for(int i = 0; i < pol.size();\
    \ i++) {\n        int t1 = sgn(cross(l.dir(), pol[i] - l.s)), t2 = sgn(cross(l.dir(),\
    \ pol[(i + 1) % sz] - l.s));\n        if(t1 >= 0) ret.push_back(pol[i]); \n  \
    \      if(t1 * t2 < 0) ret.push_back(cross_ll(Line(pol[i], pol[(i + 1) % sz]),\
    \ l));\n    }\n    return ret;\n}\n\nReal closest_pair(vector<Point> ps) {\n \
    \   auto rec = [](auto f, vector<Point>& ps, int l, int r) -> Real {\n       \
    \ if(r - l < 2) return 1e100;\n        int mid = (l + r) / 2;\n        Real x\
    \ = ps[mid].x;\n        Real d = min(f(f, ps, l, mid), f(f, ps, mid, r));\n  \
    \      auto it = ps.begin(), itl = it + l, itm = it + mid, itr = it + r;\n   \
    \     inplace_merge(itl, itm, itr, [](Point a, Point b) { return a.y < b.y; });\n\
    \        vector<Point> near_line;\n        for(int i = l; i < r; i++) {\n    \
    \        if(abs(ps[i].x - x) >= d) continue;\n            int sz = near_line.size();\n\
    \            for(int j = sz; j--;) {\n                if(ps[i].y - near_line[j].y\
    \ >= d) break;\n                d = min(d, dist_pp(ps[i], near_line[j]));\n  \
    \          }\n            near_line.push_back(ps[i]);\n        }\n        return\
    \ d;\n    };\n    sort(ps.begin(), ps.end());\n    return rec(rec, ps, 0, ps.size());\n\
    }\n\nstruct Circle {\n    Point p;\n    Real r;\n    Circle() : p(Point(0, 0)),\
    \ r(0) {}\n    Circle(Point p, Real r) : p(p), r(r) {}\n};\n\nint intersection(const\
    \ Circle& c1, const Circle& c2) {\n    Real d = dist_pp(c1.p, c2.p);\n    if(sgn(d\
    \ - (c1.r + c2.r)) == 1) return 4;\n    if(sgn(d - (c1.r + c2.r)) == 0) return\
    \ 3;\n    if(sgn(d - abs(c1.r - c2.r)) == 1) return 2;\n    if(sgn(d - abs(c1.r\
    \ - c2.r)) == 0) return 1;\n    return 0;\n}\n\npair<Point, Point> cross_cl(const\
    \ Circle& c, const Line& l) {\n    Point proj = projection(l, c.p);\n    Real\
    \ h = dist_lp(l, c.p);\n    Real d = sqrt(c.r * c.r - h * h);\n    Point p1 =\
    \ proj + l.normalize() * d;\n    Point p2 = proj - l.normalize() * d;\n    if(p1\
    \ > p2) swap(p1, p2);\n    return {p1, p2};\n}\n\nCircle incircle(const Point&\
    \ a, const Point& b, const Point& c) {\n    Real d1 = dist_pp(b, c);\n    Real\
    \ d2 = dist_pp(c, a);\n    Real d3 = dist_pp(a, b);\n    Point ip = (a * d1 +\
    \ b * d2 + c * d3) / (d1 + d2 + d3);\n    Real r = dist_lp(Line(a, b), ip);\n\
    \    return Circle(ip, r);\n}\n\nCircle outcircle(const Point& a, const Point&\
    \ b, const Point& c) {\n    Line l1((a + b) / 2, (a + b) / 2 + rot90(b - a));\n\
    \    Line l2((b + c) / 2, (b + c) / 2 + rot90(c - b));\n    Point op = cross_ll(l1,\
    \ l2);\n    Real r = dist_pp(op, a);\n    return Circle(op, r);\n}\n\npair<Point,\
    \ Point> cross_cc(const Circle& c1, const Circle& c2) {\n    Real d = dist_pp(c1.p,\
    \ c2.p);\n    Real theta = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r\
    \ * d));\n    Real phi = arg(c2.p - c1.p);\n    Point p1 = c1.p + polar(c1.r,\
    \ phi - theta);\n    Point p2 = c1.p + polar(c1.r, phi + theta);\n    if(p1 >\
    \ p2) swap(p1, p2);\n    return {p1, p2};\n}\n\npair<Point, Point> tangent_cp(const\
    \ Circle& c, const Point& p) {\n    return cross_cc(c, Circle(p, sqrt(norm2(c.p\
    \ - p) - c.r * c.r)));\n}\n\nvector<Line> tangent_cc(const Circle& c1, const Circle&\
    \ c2) {\n    vector<Line> ret;\n    Real d = dist_pp(c1.p, c2.p);\n    if(sgn(d)\
    \ == 0) return {};\n    Point u = Line(c1.p, c2.p).normalize();\n    Point v =\
    \ rot90(u);\n    for(int s : {-1, 1}) {\n        Real h = (c1.r + c2.r * s) /\
    \ d;\n        if(sgn(h * h - 1) == 0) ret.push_back(Line(c1.p + h * u * c1.r,\
    \ c1.p + h * u * c1.r + v));\n        else if(sgn(h * h - 1) == -1) {\n      \
    \      Point U = u * h;\n            Point V = v * sqrt(1 - h * h);\n        \
    \    ret.push_back(Line(c1.p + (U + V) * c1.r, c2.p - (U + V) * c2.r * s));\n\
    \            ret.push_back(Line(c1.p + (U - V) * c1.r, c2.p - (U - V) * c2.r *\
    \ s));\n        } \n    }\n    return ret;\n}\n\n}  // namespace geometry\n\n\
    using namespace geometry;\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace geometry {\n\n\
    using Real = double;\nconstexpr Real EPS = 1e-7;\n\nconstexpr int sgn(Real a)\
    \ { return (a < -EPS) ? -1 : (EPS < a) ? 1 : 0; }\n\nstruct Point {\n    Real\
    \ x, y;\n    constexpr Point(Real x=0, Real y=0) : x(x), y(y) {}\n\n    constexpr\
    \ Point& operator += (const Point& rhs) { return x += rhs.x, y += rhs.y, *this;\
    \ }\n    constexpr Point& operator -= (const Point& rhs) { return x -= rhs.x,\
    \ y -= rhs.y, *this; }\n    constexpr Point& operator *= (Real k) { return x *=\
    \ k, y *= k, *this; }\n    constexpr Point& operator /= (Real k) { return x /=\
    \ k, y /= k, *this; }\n\n    constexpr Point operator + (const Point& rhs) const\
    \ { return Point(*this) += rhs; }\n    constexpr Point operator - (const Point&\
    \ rhs) const { return Point(*this) -= rhs; }\n    constexpr Point operator * (Real\
    \ k) const { return Point(*this) *= k; }\n    constexpr Point operator / (Real\
    \ k) const { return Point(*this) /= k; }\n    friend constexpr Point operator\
    \ * (Real k, const Point& p) { return Point(p.x * k, p.y * k); }\n\n    constexpr\
    \ Point operator - () const { return Point() - *this; }\n\n    constexpr bool\
    \ operator < (const Point& rhs) const { return sgn(x - rhs.x) ? (x < rhs.x) :\
    \ (y < rhs.y); }\n    constexpr bool operator > (const Point& rhs) const { return\
    \ rhs < *this; }\n    constexpr bool operator == (const Point& rhs) const { return\
    \ !sgn(x - rhs.x) && !sgn(y - rhs.y); }\n    constexpr bool operator != (const\
    \ Point& rhs) const { return !(*this == rhs); }\n\n    constexpr Real norm2()\
    \ const { return x * x + y * y; }\n    constexpr Real norm() const { return sqrt(norm2());\
    \ }\n    constexpr Real arg() const { return atan2(y, x); }\n    constexpr Point\
    \ rot(Real theta) const { return Point(x * cos(theta) - y * sin(theta), x * sin(theta)\
    \ + y * cos(theta)); }\n    constexpr Point rot90() const { return Point(-y, x);\
    \ }\n\n    friend constexpr Real norm2(const Point& p) { return p.norm2(); }\n\
    \    friend constexpr Real norm(const Point& p) { return p.norm(); }\n    friend\
    \ constexpr Real arg(const Point& p) { return p.arg(); }\n    friend constexpr\
    \ Point rot(const Point& p, Real theta) { return p.rot(theta); }\n    friend constexpr\
    \ Point rot90(const Point& p) { return p.rot90(); }\n\n    friend istream& operator\
    \ >> (istream& is, Point& p) { return is >> p.x >> p.y; }\n    friend ostream&\
    \ operator << (ostream& os, const Point& p) { return os << \"(\" << p.x << \"\
    , \" << p.y << \")\"; }\n};\n\nconstexpr Real dot(const Point& a, const Point&\
    \ b) { return a.x * b.x + a.y * b.y; }\nconstexpr Real cross(const Point& a, const\
    \ Point& b) { return a.x * b.y - a.y * b.x; }\nconstexpr Point polar(Real r, Real\
    \ theta) { return Point(r * cos(theta), r * sin(theta)); }\n\n// +1 : a - b, a\
    \ - c : ccw\n// -1 : a - b, a - c : cw\n// +2 : c - a - b    : on_back\n// -2\
    \ : a - b - c    : on_front\n//  0 : a - c - b    : on_segment\nint ccw(const\
    \ Point& a, Point b, Point c) {\n    b -= a, c -= a;\n    if(sgn(cross(b, c))\
    \ == 1) return 1;\n    if(sgn(cross(b, c)) == -1) return -1;\n    if(sgn(dot(b,\
    \ c)) == -1) return 2;\n    if(b.norm2() < c.norm2()) return -2;\n    return 0;\
    \ \n}\n\nstruct Line {\n    Point s, t;\n    constexpr Line(Point s=Point(0, 0),\
    \ Point t=Point(0, 0)) : s(s), t(t) {}\n    constexpr Point dir() const { return\
    \ t - s; }\n    constexpr Real norm() const { return dir().norm(); }\n    constexpr\
    \ Point normalize() const { return (t - s) / norm(); }\n\n    friend constexpr\
    \ Point dir(const Line& l) { return l.dir(); }\n    friend constexpr Real norm(const\
    \ Line& l) { return l.norm(); }\n    friend constexpr Point normalize(const Line&\
    \ l) { return l.normalize(); }\n};\n\nPoint projection(const Line& l, const Point&\
    \ p) {\n    Real t = dot(p - l.s, l.t - l.s) / norm2(l.t - l.s);\n    return l.s\
    \ + l.dir() * t;\n}\nPoint reflection(const Line& l, const Point& p) {\n    Point\
    \ x = projection(l, p);\n    return 2 * x - p;\n}\n\nbool is_parallel(const Line&\
    \ a, const Line& b) { return sgn(cross(a.dir(), b.dir())) == 0; }\nbool is_orthogonal(const\
    \ Line& a, const Line& b) { return sgn(dot(a.dir(), b.dir())) == 0; }\nbool is_intersect(const\
    \ Line& a, const Line& b) { return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <=\
    \ 0 && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0; }\n\nPoint cross_ll(const\
    \ Line& a, const Line& b) {\n    Real d1 = cross(a.dir(), b.dir());\n    Real\
    \ d2 = cross(a.dir(), a.t - b.s);\n    return b.s + b.dir() * (d2 / d1);\n}\n\n\
    Real dist_pp(const Point& a, const Point& b) {\n    return norm(a - b);\n}\nReal\
    \ dist_lp(const Line& l, const Point& p) {\n    return abs(cross(l.dir(), p -\
    \ l.s)) / norm(l);\n}\nReal dist_sp(const Line& l, const Point& p) {\n    if(sgn(dot(l.dir(),\
    \ p - l.s)) == -1) return norm(p - l.s);\n    if(sgn(dot(-l.dir(), p - l.t)) ==\
    \ -1) return norm(p - l.t);\n    return dist_lp(l, p);\n}\nReal dist_ss(const\
    \ Line& a, const Line& b) {\n    if(is_intersect(a, b)) return 0;\n    return\
    \ min({dist_sp(a, b.s), dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b, a.t)});\n\
    }\n\nstruct Polygon : public vector<Point> {\n    using vector<Point>::vector;\n\
    \    Real area() const {\n        int sz = size();\n        Real ret = 0;\n  \
    \      for(int i = 0; i < sz; i++) {\n            ret += cross((*this)[i], (*this)[(i\
    \ + 1) % sz]);\n        }\n        return ret / 2;\n    }\n\n    bool is_convex()\
    \ const {\n        int sz = size();\n        for(int i = 0; i < sz; i++) {\n \
    \           if(ccw((*this)[i], (*this)[(i + 1) % sz], (*this)[(i + 2) % sz]) ==\
    \ -1) false;\n        }\n        return true;\n    }\n\n    pair<int, int> diameter()\
    \ const {\n        assert(is_convex());\n        int sz = size();\n        int\
    \ right = max_element(begin(), end()) - begin();\n        int left = min_element(begin(),\
    \ end()) - begin();\n        Real max_dist = norm2((*this)[left] - (*this)[right]);\n\
    \        pair<int, int> ret = {left, right};\n        for(int i = 0; i < sz; i++)\
    \ {\n            Point pre = (*this)[(left + 1) % sz] - (*this)[left];\n     \
    \       Point nxt = (*this)[right] - (*this)[(right + 1) % sz];\n            if(ccw(Point(0,\
    \ 0), pre, nxt) == 1) left = (left + 1) % sz;\n            else right = (right\
    \ + 1) % sz;\n            if(norm2((*this)[left] - (*this)[right]) > max_dist)\
    \ max_dist = norm2((*this)[left] - (*this)[right]), ret = {left, right};\n   \
    \     }\n        return ret;\n    }\n\n    friend Real area(const Polygon& pol)\
    \ { return pol.area(); }\n    friend bool is_convex(const Polygon& pol) { return\
    \ pol.is_convex(); }\n    friend pair<int, int> diameter(const Polygon& pol) {\
    \ return pol.diameter(); } \n};\n\n// 2 : contain\n// 1 : on line\n// 0 : outside\n\
    int contain(const Polygon& pol, const Point& p) {\n    bool in = false;\n    int\
    \ sz = pol.size();\n    for(int i = 0; i < sz; i++) {\n        Point a = pol[i]\
    \ - p;\n        Point b = pol[(i + 1) % sz] - p;\n        if(a.y > b.y) swap(a,\
    \ b);\n        if(sgn(a.y) == -1 && sgn(b.y) == 1 && sgn(cross(a, b)) == 1) in\
    \ ^= 1;\n        if(sgn(cross(a, b)) == -1 && sgn(dot(a, b)) == -1) return 1;\n\
    \    }\n    return 2 * in;\n}\n\nPolygon convex_hull(Polygon pol) {\n    int sz\
    \ = pol.size();\n    sort(pol.begin(), pol.end());\n    Polygon ret;\n    for(int\
    \ i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size() -\
    \ 2], ret.back(), pol[i]) == -1) ret.pop_back();\n        ret.push_back(pol[i]);\n\
    \    }\n    int t = ret.size();\n    for(int i = sz - 2; i >= 0; i--) {\n    \
    \    while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), pol[i]) == -1)\
    \ ret.pop_back();\n        ret.push_back(pol[i]);\n    }\n    ret.pop_back();\n\
    \    return ret;\n}\n\nPolygon convex_cut(const Polygon& pol, const Line& l) {\n\
    \    int sz = pol.size();\n    Polygon ret;\n    for(int i = 0; i < pol.size();\
    \ i++) {\n        int t1 = sgn(cross(l.dir(), pol[i] - l.s)), t2 = sgn(cross(l.dir(),\
    \ pol[(i + 1) % sz] - l.s));\n        if(t1 >= 0) ret.push_back(pol[i]); \n  \
    \      if(t1 * t2 < 0) ret.push_back(cross_ll(Line(pol[i], pol[(i + 1) % sz]),\
    \ l));\n    }\n    return ret;\n}\n\nReal closest_pair(vector<Point> ps) {\n \
    \   auto rec = [](auto f, vector<Point>& ps, int l, int r) -> Real {\n       \
    \ if(r - l < 2) return 1e100;\n        int mid = (l + r) / 2;\n        Real x\
    \ = ps[mid].x;\n        Real d = min(f(f, ps, l, mid), f(f, ps, mid, r));\n  \
    \      auto it = ps.begin(), itl = it + l, itm = it + mid, itr = it + r;\n   \
    \     inplace_merge(itl, itm, itr, [](Point a, Point b) { return a.y < b.y; });\n\
    \        vector<Point> near_line;\n        for(int i = l; i < r; i++) {\n    \
    \        if(abs(ps[i].x - x) >= d) continue;\n            int sz = near_line.size();\n\
    \            for(int j = sz; j--;) {\n                if(ps[i].y - near_line[j].y\
    \ >= d) break;\n                d = min(d, dist_pp(ps[i], near_line[j]));\n  \
    \          }\n            near_line.push_back(ps[i]);\n        }\n        return\
    \ d;\n    };\n    sort(ps.begin(), ps.end());\n    return rec(rec, ps, 0, ps.size());\n\
    }\n\nstruct Circle {\n    Point p;\n    Real r;\n    Circle() : p(Point(0, 0)),\
    \ r(0) {}\n    Circle(Point p, Real r) : p(p), r(r) {}\n};\n\nint intersection(const\
    \ Circle& c1, const Circle& c2) {\n    Real d = dist_pp(c1.p, c2.p);\n    if(sgn(d\
    \ - (c1.r + c2.r)) == 1) return 4;\n    if(sgn(d - (c1.r + c2.r)) == 0) return\
    \ 3;\n    if(sgn(d - abs(c1.r - c2.r)) == 1) return 2;\n    if(sgn(d - abs(c1.r\
    \ - c2.r)) == 0) return 1;\n    return 0;\n}\n\npair<Point, Point> cross_cl(const\
    \ Circle& c, const Line& l) {\n    Point proj = projection(l, c.p);\n    Real\
    \ h = dist_lp(l, c.p);\n    Real d = sqrt(c.r * c.r - h * h);\n    Point p1 =\
    \ proj + l.normalize() * d;\n    Point p2 = proj - l.normalize() * d;\n    if(p1\
    \ > p2) swap(p1, p2);\n    return {p1, p2};\n}\n\nCircle incircle(const Point&\
    \ a, const Point& b, const Point& c) {\n    Real d1 = dist_pp(b, c);\n    Real\
    \ d2 = dist_pp(c, a);\n    Real d3 = dist_pp(a, b);\n    Point ip = (a * d1 +\
    \ b * d2 + c * d3) / (d1 + d2 + d3);\n    Real r = dist_lp(Line(a, b), ip);\n\
    \    return Circle(ip, r);\n}\n\nCircle outcircle(const Point& a, const Point&\
    \ b, const Point& c) {\n    Line l1((a + b) / 2, (a + b) / 2 + rot90(b - a));\n\
    \    Line l2((b + c) / 2, (b + c) / 2 + rot90(c - b));\n    Point op = cross_ll(l1,\
    \ l2);\n    Real r = dist_pp(op, a);\n    return Circle(op, r);\n}\n\npair<Point,\
    \ Point> cross_cc(const Circle& c1, const Circle& c2) {\n    Real d = dist_pp(c1.p,\
    \ c2.p);\n    Real theta = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r\
    \ * d));\n    Real phi = arg(c2.p - c1.p);\n    Point p1 = c1.p + polar(c1.r,\
    \ phi - theta);\n    Point p2 = c1.p + polar(c1.r, phi + theta);\n    if(p1 >\
    \ p2) swap(p1, p2);\n    return {p1, p2};\n}\n\npair<Point, Point> tangent_cp(const\
    \ Circle& c, const Point& p) {\n    return cross_cc(c, Circle(p, sqrt(norm2(c.p\
    \ - p) - c.r * c.r)));\n}\n\nvector<Line> tangent_cc(const Circle& c1, const Circle&\
    \ c2) {\n    vector<Line> ret;\n    Real d = dist_pp(c1.p, c2.p);\n    if(sgn(d)\
    \ == 0) return {};\n    Point u = Line(c1.p, c2.p).normalize();\n    Point v =\
    \ rot90(u);\n    for(int s : {-1, 1}) {\n        Real h = (c1.r + c2.r * s) /\
    \ d;\n        if(sgn(h * h - 1) == 0) ret.push_back(Line(c1.p + h * u * c1.r,\
    \ c1.p + h * u * c1.r + v));\n        else if(sgn(h * h - 1) == -1) {\n      \
    \      Point U = u * h;\n            Point V = v * sqrt(1 - h * h);\n        \
    \    ret.push_back(Line(c1.p + (U + V) * c1.r, c2.p - (U + V) * c2.r * s));\n\
    \            ret.push_back(Line(c1.p + (U - V) * c1.r, c2.p - (U - V) * c2.r *\
    \ s));\n        } \n    }\n    return ret;\n}\n\n}  // namespace geometry\n\n\
    using namespace geometry;"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2025-02-01 05:24:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry.hpp
layout: document
redirect_from:
- /library/geometry/geometry.hpp
- /library/geometry/geometry.hpp.html
title: geometry/geometry.hpp
---
