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
    \ EPS = 1e-7;\nconstexpr Real PI = numbers::pi;\n\nconstexpr int sgn(Real a) {\
    \ return (a < -EPS) ? -1 : (EPS < a) ? 1 : 0; }\n\nstruct Point {\n    Real x,\
    \ y;\n    constexpr Point(Real x=0, Real y=0) : x(x), y(y) {}\n\n    constexpr\
    \ Point& operator += (const Point& rhs) { return x += rhs.x, y += rhs.y, *this;\
    \ }\n    constexpr Point& operator -= (const Point& rhs) { return x -= rhs.x,\
    \ y -= rhs.y, *this; }\n    constexpr Point& operator *= (const Point& rhs) {\
    \ return *this = Point(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x); }\n    constexpr\
    \ Point& operator /= (const Point& rhs) { return *this *= rhs.conj() * rhs.norm2();\
    \ }\n    constexpr Point& operator *= (Real k) { return x *= k, y *= k, *this;\
    \ }\n    constexpr Point& operator /= (Real k) { return x /= k, y /= k, *this;\
    \ }\n\n    constexpr Point operator + (const Point& rhs) const { return Point(*this)\
    \ += rhs; }\n    constexpr Point operator - (const Point& rhs) const { return\
    \ Point(*this) -= rhs; }\n    constexpr Point operator * (const Point& rhs) const\
    \ { return Point(*this) *= rhs; }\n    constexpr Point operator / (const Point&\
    \ rhs) const { return Point(*this) /= rhs; }\n    constexpr Point operator * (Real\
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
    \ }\n    constexpr Point conj() const { return Point(x, -y); }\n\n    friend constexpr\
    \ Real norm2(const Point& p) { return p.norm2(); }\n    friend constexpr Real\
    \ norm(const Point& p) { return p.norm(); }\n    friend constexpr Real arg(const\
    \ Point& p) { return p.arg(); }\n    friend constexpr Point rot(const Point& p,\
    \ Real theta) { return p.rot(theta); }\n    friend constexpr Point rot90(const\
    \ Point& p) { return p.rot90(); }\n    friend constexpr Point conj(const Point&\
    \ p) { return p.conj(); }\n\n    friend istream& operator >> (istream& is, Point&\
    \ p) { return is >> p.x >> p.y; }\n    friend ostream& operator << (ostream& os,\
    \ const Point& p) { return os << \"(\" << p.x << \", \" << p.y << \")\"; }\n};\n\
    \nconstexpr Real dot(const Point& a, const Point& b) { return a.x * b.x + a.y\
    \ * b.y; }\nconstexpr Real cross(const Point& a, const Point& b) { return a.x\
    \ * b.y - a.y * b.x; }\nconstexpr Point polar(Real r, Real theta) { return Point(r\
    \ * cos(theta), r * sin(theta)); }\n\n// +1 : a - b, a - c : ccw\n// -1 : a -\
    \ b, a - c : cw\n// +2 : c - a - b    : on_back\n// -2 : a - b - c    : on_front\n\
    //  0 : a - c - b    : on_segment\nint ccw(const Point& a, Point b, Point c) {\n\
    \    b -= a, c -= a;\n    if(sgn(cross(b, c)) == 1) return 1;\n    if(sgn(cross(b,\
    \ c)) == -1) return -1;\n    if(sgn(dot(b, c)) == -1) return 2;\n    if(b.norm2()\
    \ < c.norm2()) return -2;\n    return 0; \n}\n\nstruct Line {\n    Point s, t;\n\
    \    constexpr Line(Point s=Point(0, 0), Point t=Point(0, 0)) : s(s), t(t) {}\n\
    \    constexpr Point dir() const { return t - s; }\n    constexpr Real norm()\
    \ const { return dir().norm(); }\n    constexpr Point normalize() const { return\
    \ (t - s) / norm(); }\n\n    friend constexpr Point dir(const Line& l) { return\
    \ l.dir(); }\n    friend constexpr Real norm(const Line& l) { return l.norm();\
    \ }\n    friend constexpr Point normalize(const Line& l) { return l.normalize();\
    \ }\n};\n\nPoint projection(const Line& l, const Point& p) {\n    Real t = dot(p\
    \ - l.s, l.t - l.s) / norm2(l.t - l.s);\n    return l.s + l.dir() * t;\n}\nPoint\
    \ reflection(const Line& l, const Point& p) {\n    Point x = projection(l, p);\n\
    \    return 2 * x - p;\n}\n\nbool is_parallel(const Line& a, const Line& b) {\
    \ return sgn(cross(a.dir(), b.dir())) == 0; }\nbool is_orthogonal(const Line&\
    \ a, const Line& b) { return sgn(dot(a.dir(), b.dir())) == 0; }\nbool is_intersect(const\
    \ Line& a, const Line& b) { \n    return sgn(ccw(a.s, a.t, b.s)) * sgn(ccw(a.s,\
    \ a.t, b.t)) <= 0 && sgn(ccw(b.s, b.t, a.s)) * sgn(ccw(b.s, b.t, a.t)) <= 0; \n\
    }\n\nPoint cross_ll(const Line& a, const Line& b) {\n    Real d1 = cross(a.dir(),\
    \ b.dir());\n    Real d2 = cross(a.dir(), a.t - b.s);\n    return b.s + b.dir()\
    \ * (d2 / d1);\n}\n\nReal dist_pp(const Point& a, const Point& b) {\n    return\
    \ norm(a - b);\n}\nReal dist_lp(const Line& l, const Point& p) {\n    return abs(cross(l.dir(),\
    \ p - l.s)) / norm(l);\n}\nReal dist_sp(const Line& l, const Point& p) {\n   \
    \ if(sgn(dot(l.dir(), p - l.s)) == -1) return norm(p - l.s);\n    if(sgn(dot(-l.dir(),\
    \ p - l.t)) == -1) return norm(p - l.t);\n    return dist_lp(l, p);\n}\nReal dist_ss(const\
    \ Line& a, const Line& b) {\n    if(is_intersect(a, b)) return 0;\n    return\
    \ min({dist_sp(a, b.s), dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b, a.t)});\n\
    }\n\nstruct Polygon : public vector<Point> {\n    using vector<Point>::vector;\n\
    \    Real area() const {\n        int sz = size();\n        Real ret = 0;\n  \
    \      for(int i = 0; i < sz; i++) {\n            ret += cross((*this)[i], (*this)[(i\
    \ + 1) % sz]);\n        }\n        return ret / 2;\n    }\n\n    bool is_convex()\
    \ const {\n        int sz = size();\n        for(int i = 0; i < sz; i++) {\n \
    \           if(ccw((*this)[i], (*this)[(i + 1) % sz], (*this)[(i + 2) % sz]) ==\
    \ -1) return false;\n        }\n        return true;\n    }\n\n    pair<int, int>\
    \ diameter() const {\n        assert(is_convex());\n        int sz = size();\n\
    \        int right = max_element(begin(), end()) - begin();\n        int left\
    \ = min_element(begin(), end()) - begin();\n        Real max_dist = norm2((*this)[left]\
    \ - (*this)[right]);\n        pair<int, int> ret = {left, right};\n        for(int\
    \ i = 0; i < sz; i++) {\n            Point pre = (*this)[(left + 1) % sz] - (*this)[left];\n\
    \            Point nxt = (*this)[right] - (*this)[(right + 1) % sz];\n       \
    \     if(ccw(Point(0, 0), pre, nxt) == 1) left = (left + 1) % sz;\n          \
    \  else right = (right + 1) % sz;\n            if(norm2((*this)[left] - (*this)[right])\
    \ > max_dist) max_dist = norm2((*this)[left] - (*this)[right]), ret = {left, right};\n\
    \        }\n        return ret;\n    }\n\n    friend Real area(const Polygon&\
    \ pol) { return pol.area(); }\n    friend bool is_convex(const Polygon& pol) {\
    \ return pol.is_convex(); }\n    friend pair<int, int> diameter(const Polygon&\
    \ pol) { return pol.diameter(); } \n};\n\n// 2 : contain\n// 1 : on line\n// 0\
    \ : outside\nint contain(const Polygon& pol, const Point& p) {\n    bool in =\
    \ false;\n    int sz = pol.size();\n    for(int i = 0; i < sz; i++) {\n      \
    \  Point a = pol[i] - p;\n        Point b = pol[(i + 1) % sz] - p;\n        if(a.y\
    \ > b.y) swap(a, b);\n        if(sgn(a.y) <= 0 && sgn(b.y) == 1 && sgn(cross(a,\
    \ b)) == -1) in ^= 1;\n        if(sgn(cross(a, b)) == 0 && sgn(dot(a, b)) == -1)\
    \ return 1;\n    }\n    return 2 * in;\n}\n\nPolygon convex_hull(Polygon pol)\
    \ {\n    int sz = pol.size();\n    sort(pol.begin(), pol.end());\n    Polygon\
    \ ret;\n    for(int i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size()\
    \ - 2], ret.back(), pol[i]) == -1) ret.pop_back();\n        ret.push_back(pol[i]);\n\
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
    \ proj + l.normalize() * d;\n    Point p2 = proj - l.normalize() * d;\n    if(dist_pp(p1,\
    \ l.s) > dist_pp(p2, l.s)) swap(p1, p2);\n    return {p1, p2};\n}\n\nCircle incircle(const\
    \ Point& a, const Point& b, const Point& c) {\n    Real d1 = dist_pp(b, c);\n\
    \    Real d2 = dist_pp(c, a);\n    Real d3 = dist_pp(a, b);\n    Point ip = (a\
    \ * d1 + b * d2 + c * d3) / (d1 + d2 + d3);\n    Real r = dist_lp(Line(a, b),\
    \ ip);\n    return Circle(ip, r);\n}\n\nCircle outcircle(const Point& a, const\
    \ Point& b, const Point& c) {\n    Line l1((a + b) / 2, (a + b) / 2 + rot90(b\
    \ - a));\n    Line l2((b + c) / 2, (b + c) / 2 + rot90(c - b));\n    Point op\
    \ = cross_ll(l1, l2);\n    Real r = dist_pp(op, a);\n    return Circle(op, r);\n\
    }\n\npair<Point, Point> cross_cc(const Circle& c1, const Circle& c2) {\n    Real\
    \ d = dist_pp(c1.p, c2.p);\n    Real theta = acos((c1.r * c1.r + d * d - c2.r\
    \ * c2.r) / (2 * c1.r * d));\n    Real phi = arg(c2.p - c1.p);\n    Point p1 =\
    \ c1.p + polar(c1.r, phi - theta);\n    Point p2 = c1.p + polar(c1.r, phi + theta);\n\
    \    if(p1 > p2) swap(p1, p2);\n    return {p1, p2};\n}\n\npair<Point, Point>\
    \ tangent_cp(const Circle& c, const Point& p) {\n    return cross_cc(c, Circle(p,\
    \ sqrt(norm2(c.p - p) - c.r * c.r)));\n}\n\nvector<Line> tangent_cc(const Circle&\
    \ c1, const Circle& c2) {\n    vector<Line> ret;\n    Real d = dist_pp(c1.p, c2.p);\n\
    \    if(sgn(d) == 0) return {};\n    Point u = Line(c1.p, c2.p).normalize();\n\
    \    Point v = rot90(u);\n    for(int s : {-1, 1}) {\n        Real h = (c1.r +\
    \ c2.r * s) / d;\n        if(sgn(h * h - 1) == 0) ret.push_back(Line(c1.p + h\
    \ * u * c1.r, c1.p + h * u * c1.r + v));\n        else if(sgn(h * h - 1) == -1)\
    \ {\n            Point U = u * h;\n            Point V = v * sqrt(1 - h * h);\n\
    \            ret.push_back(Line(c1.p + (U + V) * c1.r, c2.p - (U + V) * c2.r *\
    \ s));\n            ret.push_back(Line(c1.p + (U - V) * c1.r, c2.p - (U - V) *\
    \ c2.r * s));\n        } \n    }\n    return ret;\n}\n\nReal get_angle(const Point&\
    \ a, const Point& b) {\n    return (b * conj(a)).arg();\n}\n\nReal common_area_cp(const\
    \ Circle& c, const Polygon& pol) {\n    int sz = pol.size();\n    auto cross_area\
    \ = [&](const Point& a, const Point& b) -> Real {\n        Point va = a - c.p,\
    \ vb = b - c.p;\n        Real f = cross(va, vb), ret = 0;\n        if(sgn(f) ==\
    \ 0) return 0;\n        if(sgn(c.r - max(norm(va), norm(vb))) >= 0) return f;\n\
    \        if(sgn(dist_sp(Line(a, b), c.p) - c.r) >= 0) return c.r * c.r * get_angle(va,\
    \ vb);\n        auto [cp1, cp2] = cross_cl(c, Line(a, b));\n        cp1 -= c.p,\
    \ cp2 -= c.p;\n        if(ccw(va, vb, cp1) != 0) cp1 = cp2;\n        if(ccw(va,\
    \ vb, cp2) != 0) cp2 = cp1;\n        ret += (sgn(c.r - norm(va)) >= 0) ? cross(va,\
    \ cp1) : c.r * c.r * get_angle(va, cp1);\n        ret += cross(cp1, cp2);\n  \
    \      ret += (sgn(c.r - norm(vb)) >= 0) ? cross(cp2, vb) : c.r * c.r * get_angle(cp2,\
    \ vb);\n        return ret;\n    };\n    Real ret = 0;\n    for(int i = 0; i <\
    \ sz; i++) {\n        ret += cross_area(pol[i], pol[(i + 1) % sz]);\n    }\n \
    \   return ret * 0.5;\n}\n\nReal common_area_cc(const Circle& c1, const Circle&\
    \ c2) {\n    Real d = dist_pp(c1.p, c2.p);\n    if(sgn(c1.r + c2.r - d) <= 0)\
    \ return 0;\n    if(sgn(d - abs(c1.r - c2.r)) <= 0) {\n        Real r = min(c1.r,\
    \ c2.r);\n        return PI * r * r;\n    }\n    auto area = [&](const Circle&\
    \ c1, const Circle& c2) -> Real {\n        Real theta = 2 * acos((d * d + c1.r\
    \ * c1.r - c2.r * c2.r) / (2 * d * c1.r));\n        return (theta - sin(theta))\
    \ * c1.r * c1.r * 0.5;\n    };\n    return area(c1, c2) + area(c2, c1);\n}\n\n\
    }  // namespace geometry\n\nusing namespace geometry;\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace geometry {\n\n\
    using Real = double;\nconstexpr Real EPS = 1e-7;\nconstexpr Real PI = numbers::pi;\n\
    \nconstexpr int sgn(Real a) { return (a < -EPS) ? -1 : (EPS < a) ? 1 : 0; }\n\n\
    struct Point {\n    Real x, y;\n    constexpr Point(Real x=0, Real y=0) : x(x),\
    \ y(y) {}\n\n    constexpr Point& operator += (const Point& rhs) { return x +=\
    \ rhs.x, y += rhs.y, *this; }\n    constexpr Point& operator -= (const Point&\
    \ rhs) { return x -= rhs.x, y -= rhs.y, *this; }\n    constexpr Point& operator\
    \ *= (const Point& rhs) { return *this = Point(x * rhs.x - y * rhs.y, x * rhs.y\
    \ + y * rhs.x); }\n    constexpr Point& operator /= (const Point& rhs) { return\
    \ *this *= rhs.conj() * rhs.norm2(); }\n    constexpr Point& operator *= (Real\
    \ k) { return x *= k, y *= k, *this; }\n    constexpr Point& operator /= (Real\
    \ k) { return x /= k, y /= k, *this; }\n\n    constexpr Point operator + (const\
    \ Point& rhs) const { return Point(*this) += rhs; }\n    constexpr Point operator\
    \ - (const Point& rhs) const { return Point(*this) -= rhs; }\n    constexpr Point\
    \ operator * (const Point& rhs) const { return Point(*this) *= rhs; }\n    constexpr\
    \ Point operator / (const Point& rhs) const { return Point(*this) /= rhs; }\n\
    \    constexpr Point operator * (Real k) const { return Point(*this) *= k; }\n\
    \    constexpr Point operator / (Real k) const { return Point(*this) /= k; }\n\
    \    friend constexpr Point operator * (Real k, const Point& p) { return Point(p.x\
    \ * k, p.y * k); }\n\n    constexpr Point operator - () const { return Point()\
    \ - *this; }\n\n    constexpr bool operator < (const Point& rhs) const { return\
    \ sgn(x - rhs.x) ? (x < rhs.x) : (y < rhs.y); }\n    constexpr bool operator >\
    \ (const Point& rhs) const { return rhs < *this; }\n    constexpr bool operator\
    \ == (const Point& rhs) const { return !sgn(x - rhs.x) && !sgn(y - rhs.y); }\n\
    \    constexpr bool operator != (const Point& rhs) const { return !(*this == rhs);\
    \ }\n\n    constexpr Real norm2() const { return x * x + y * y; }\n    constexpr\
    \ Real norm() const { return sqrt(norm2()); }\n    constexpr Real arg() const\
    \ { return atan2(y, x); }\n    constexpr Point rot(Real theta) const { return\
    \ Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }\n\
    \    constexpr Point rot90() const { return Point(-y, x); }\n    constexpr Point\
    \ conj() const { return Point(x, -y); }\n\n    friend constexpr Real norm2(const\
    \ Point& p) { return p.norm2(); }\n    friend constexpr Real norm(const Point&\
    \ p) { return p.norm(); }\n    friend constexpr Real arg(const Point& p) { return\
    \ p.arg(); }\n    friend constexpr Point rot(const Point& p, Real theta) { return\
    \ p.rot(theta); }\n    friend constexpr Point rot90(const Point& p) { return p.rot90();\
    \ }\n    friend constexpr Point conj(const Point& p) { return p.conj(); }\n\n\
    \    friend istream& operator >> (istream& is, Point& p) { return is >> p.x >>\
    \ p.y; }\n    friend ostream& operator << (ostream& os, const Point& p) { return\
    \ os << \"(\" << p.x << \", \" << p.y << \")\"; }\n};\n\nconstexpr Real dot(const\
    \ Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }\nconstexpr Real\
    \ cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }\nconstexpr\
    \ Point polar(Real r, Real theta) { return Point(r * cos(theta), r * sin(theta));\
    \ }\n\n// +1 : a - b, a - c : ccw\n// -1 : a - b, a - c : cw\n// +2 : c - a -\
    \ b    : on_back\n// -2 : a - b - c    : on_front\n//  0 : a - c - b    : on_segment\n\
    int ccw(const Point& a, Point b, Point c) {\n    b -= a, c -= a;\n    if(sgn(cross(b,\
    \ c)) == 1) return 1;\n    if(sgn(cross(b, c)) == -1) return -1;\n    if(sgn(dot(b,\
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
    \ Line& a, const Line& b) { \n    return sgn(ccw(a.s, a.t, b.s)) * sgn(ccw(a.s,\
    \ a.t, b.t)) <= 0 && sgn(ccw(b.s, b.t, a.s)) * sgn(ccw(b.s, b.t, a.t)) <= 0; \n\
    }\n\nPoint cross_ll(const Line& a, const Line& b) {\n    Real d1 = cross(a.dir(),\
    \ b.dir());\n    Real d2 = cross(a.dir(), a.t - b.s);\n    return b.s + b.dir()\
    \ * (d2 / d1);\n}\n\nReal dist_pp(const Point& a, const Point& b) {\n    return\
    \ norm(a - b);\n}\nReal dist_lp(const Line& l, const Point& p) {\n    return abs(cross(l.dir(),\
    \ p - l.s)) / norm(l);\n}\nReal dist_sp(const Line& l, const Point& p) {\n   \
    \ if(sgn(dot(l.dir(), p - l.s)) == -1) return norm(p - l.s);\n    if(sgn(dot(-l.dir(),\
    \ p - l.t)) == -1) return norm(p - l.t);\n    return dist_lp(l, p);\n}\nReal dist_ss(const\
    \ Line& a, const Line& b) {\n    if(is_intersect(a, b)) return 0;\n    return\
    \ min({dist_sp(a, b.s), dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b, a.t)});\n\
    }\n\nstruct Polygon : public vector<Point> {\n    using vector<Point>::vector;\n\
    \    Real area() const {\n        int sz = size();\n        Real ret = 0;\n  \
    \      for(int i = 0; i < sz; i++) {\n            ret += cross((*this)[i], (*this)[(i\
    \ + 1) % sz]);\n        }\n        return ret / 2;\n    }\n\n    bool is_convex()\
    \ const {\n        int sz = size();\n        for(int i = 0; i < sz; i++) {\n \
    \           if(ccw((*this)[i], (*this)[(i + 1) % sz], (*this)[(i + 2) % sz]) ==\
    \ -1) return false;\n        }\n        return true;\n    }\n\n    pair<int, int>\
    \ diameter() const {\n        assert(is_convex());\n        int sz = size();\n\
    \        int right = max_element(begin(), end()) - begin();\n        int left\
    \ = min_element(begin(), end()) - begin();\n        Real max_dist = norm2((*this)[left]\
    \ - (*this)[right]);\n        pair<int, int> ret = {left, right};\n        for(int\
    \ i = 0; i < sz; i++) {\n            Point pre = (*this)[(left + 1) % sz] - (*this)[left];\n\
    \            Point nxt = (*this)[right] - (*this)[(right + 1) % sz];\n       \
    \     if(ccw(Point(0, 0), pre, nxt) == 1) left = (left + 1) % sz;\n          \
    \  else right = (right + 1) % sz;\n            if(norm2((*this)[left] - (*this)[right])\
    \ > max_dist) max_dist = norm2((*this)[left] - (*this)[right]), ret = {left, right};\n\
    \        }\n        return ret;\n    }\n\n    friend Real area(const Polygon&\
    \ pol) { return pol.area(); }\n    friend bool is_convex(const Polygon& pol) {\
    \ return pol.is_convex(); }\n    friend pair<int, int> diameter(const Polygon&\
    \ pol) { return pol.diameter(); } \n};\n\n// 2 : contain\n// 1 : on line\n// 0\
    \ : outside\nint contain(const Polygon& pol, const Point& p) {\n    bool in =\
    \ false;\n    int sz = pol.size();\n    for(int i = 0; i < sz; i++) {\n      \
    \  Point a = pol[i] - p;\n        Point b = pol[(i + 1) % sz] - p;\n        if(a.y\
    \ > b.y) swap(a, b);\n        if(sgn(a.y) <= 0 && sgn(b.y) == 1 && sgn(cross(a,\
    \ b)) == -1) in ^= 1;\n        if(sgn(cross(a, b)) == 0 && sgn(dot(a, b)) == -1)\
    \ return 1;\n    }\n    return 2 * in;\n}\n\nPolygon convex_hull(Polygon pol)\
    \ {\n    int sz = pol.size();\n    sort(pol.begin(), pol.end());\n    Polygon\
    \ ret;\n    for(int i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size()\
    \ - 2], ret.back(), pol[i]) == -1) ret.pop_back();\n        ret.push_back(pol[i]);\n\
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
    \ proj + l.normalize() * d;\n    Point p2 = proj - l.normalize() * d;\n    if(dist_pp(p1,\
    \ l.s) > dist_pp(p2, l.s)) swap(p1, p2);\n    return {p1, p2};\n}\n\nCircle incircle(const\
    \ Point& a, const Point& b, const Point& c) {\n    Real d1 = dist_pp(b, c);\n\
    \    Real d2 = dist_pp(c, a);\n    Real d3 = dist_pp(a, b);\n    Point ip = (a\
    \ * d1 + b * d2 + c * d3) / (d1 + d2 + d3);\n    Real r = dist_lp(Line(a, b),\
    \ ip);\n    return Circle(ip, r);\n}\n\nCircle outcircle(const Point& a, const\
    \ Point& b, const Point& c) {\n    Line l1((a + b) / 2, (a + b) / 2 + rot90(b\
    \ - a));\n    Line l2((b + c) / 2, (b + c) / 2 + rot90(c - b));\n    Point op\
    \ = cross_ll(l1, l2);\n    Real r = dist_pp(op, a);\n    return Circle(op, r);\n\
    }\n\npair<Point, Point> cross_cc(const Circle& c1, const Circle& c2) {\n    Real\
    \ d = dist_pp(c1.p, c2.p);\n    Real theta = acos((c1.r * c1.r + d * d - c2.r\
    \ * c2.r) / (2 * c1.r * d));\n    Real phi = arg(c2.p - c1.p);\n    Point p1 =\
    \ c1.p + polar(c1.r, phi - theta);\n    Point p2 = c1.p + polar(c1.r, phi + theta);\n\
    \    if(p1 > p2) swap(p1, p2);\n    return {p1, p2};\n}\n\npair<Point, Point>\
    \ tangent_cp(const Circle& c, const Point& p) {\n    return cross_cc(c, Circle(p,\
    \ sqrt(norm2(c.p - p) - c.r * c.r)));\n}\n\nvector<Line> tangent_cc(const Circle&\
    \ c1, const Circle& c2) {\n    vector<Line> ret;\n    Real d = dist_pp(c1.p, c2.p);\n\
    \    if(sgn(d) == 0) return {};\n    Point u = Line(c1.p, c2.p).normalize();\n\
    \    Point v = rot90(u);\n    for(int s : {-1, 1}) {\n        Real h = (c1.r +\
    \ c2.r * s) / d;\n        if(sgn(h * h - 1) == 0) ret.push_back(Line(c1.p + h\
    \ * u * c1.r, c1.p + h * u * c1.r + v));\n        else if(sgn(h * h - 1) == -1)\
    \ {\n            Point U = u * h;\n            Point V = v * sqrt(1 - h * h);\n\
    \            ret.push_back(Line(c1.p + (U + V) * c1.r, c2.p - (U + V) * c2.r *\
    \ s));\n            ret.push_back(Line(c1.p + (U - V) * c1.r, c2.p - (U - V) *\
    \ c2.r * s));\n        } \n    }\n    return ret;\n}\n\nReal get_angle(const Point&\
    \ a, const Point& b) {\n    return (b * conj(a)).arg();\n}\n\nReal common_area_cp(const\
    \ Circle& c, const Polygon& pol) {\n    int sz = pol.size();\n    auto cross_area\
    \ = [&](const Point& a, const Point& b) -> Real {\n        Point va = a - c.p,\
    \ vb = b - c.p;\n        Real f = cross(va, vb), ret = 0;\n        if(sgn(f) ==\
    \ 0) return 0;\n        if(sgn(c.r - max(norm(va), norm(vb))) >= 0) return f;\n\
    \        if(sgn(dist_sp(Line(a, b), c.p) - c.r) >= 0) return c.r * c.r * get_angle(va,\
    \ vb);\n        auto [cp1, cp2] = cross_cl(c, Line(a, b));\n        cp1 -= c.p,\
    \ cp2 -= c.p;\n        if(ccw(va, vb, cp1) != 0) cp1 = cp2;\n        if(ccw(va,\
    \ vb, cp2) != 0) cp2 = cp1;\n        ret += (sgn(c.r - norm(va)) >= 0) ? cross(va,\
    \ cp1) : c.r * c.r * get_angle(va, cp1);\n        ret += cross(cp1, cp2);\n  \
    \      ret += (sgn(c.r - norm(vb)) >= 0) ? cross(cp2, vb) : c.r * c.r * get_angle(cp2,\
    \ vb);\n        return ret;\n    };\n    Real ret = 0;\n    for(int i = 0; i <\
    \ sz; i++) {\n        ret += cross_area(pol[i], pol[(i + 1) % sz]);\n    }\n \
    \   return ret * 0.5;\n}\n\nReal common_area_cc(const Circle& c1, const Circle&\
    \ c2) {\n    Real d = dist_pp(c1.p, c2.p);\n    if(sgn(c1.r + c2.r - d) <= 0)\
    \ return 0;\n    if(sgn(d - abs(c1.r - c2.r)) <= 0) {\n        Real r = min(c1.r,\
    \ c2.r);\n        return PI * r * r;\n    }\n    auto area = [&](const Circle&\
    \ c1, const Circle& c2) -> Real {\n        Real theta = 2 * acos((d * d + c1.r\
    \ * c1.r - c2.r * c2.r) / (2 * d * c1.r));\n        return (theta - sin(theta))\
    \ * c1.r * c1.r * 0.5;\n    };\n    return area(c1, c2) + area(c2, c1);\n}\n\n\
    }  // namespace geometry\n\nusing namespace geometry;\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2025-03-08 01:15:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry.hpp
layout: document
title: Geometry
---

## 概要

2次元幾何ライブラリ．

点，直線・線分，多角形，円に対する基本演算をまとめている．
実数型は `double`，誤差判定は `EPS = 1e-7` を使う．

```cpp
#include "geometry/geometry.hpp"
```

## 基本

```cpp
using Real = double;
constexpr Real EPS = 1e-7;
constexpr Real PI = numbers::pi;
```

### sgn

```cpp
int sgn(Real a)
```

* `a < -EPS` なら `-1`
* `-EPS <= a <= EPS` なら `0`
* `EPS < a` なら `1`

計算時間は $O(1)$．

## Point

```cpp
struct Point {
    Real x, y;
};
```

2次元ベクトルを表す．複素数のように足し算，引き算，スカラー倍，回転などができる．

### コンストラクタ

```cpp
Point p(Real x = 0, Real y = 0)
```

### 演算

```cpp
p + q
p - q
p * k
k * p
p / k
-p
```

`Point` 同士の `*`，`/` は複素数としての積・商を表す．

```cpp
p * q
p / q
```

比較は `x`，次に `y` の辞書順で行う．等号は `EPS` を考慮する．

```cpp
p < q
p == q
```

### 関数

```cpp
Real norm2(Point p)
Real norm(Point p)
Real arg(Point p)
Point rot(Point p, Real theta)
Point rot90(Point p)
Point conj(Point p)
Real dot(Point a, Point b)
Real cross(Point a, Point b)
Point polar(Real r, Real theta)
```

* `norm2(p)` は $|p|^2$ を返す．
* `norm(p)` は $|p|$ を返す．
* `arg(p)` は偏角を返す．
* `rot(p, theta)` は `p` を `theta` ラジアン回転する．
* `rot90(p)` は `p` を反時計回りに $90^\circ$ 回転する．
* `conj(p)` は `p` の共役を返す．
* `dot(a, b)` は内積を返す．
* `cross(a, b)` は外積を返す．
* `polar(r, theta)` は極座標 $(r, theta)$ の点を返す．

計算時間はいずれも $O(1)$．

## ccw

```cpp
int ccw(Point a, Point b, Point c)
```

点 `a` から見た `b`，`c` の位置関係を返す．

| 返り値 | 意味 |
| --- | --- |
| `1` | `a -> b -> c` が反時計回り |
| `-1` | `a -> b -> c` が時計回り |
| `2` | `c, a, b` の順に一直線上 |
| `-2` | `a, b, c` の順に一直線上 |
| `0` | `c` が線分 `ab` 上 |

計算時間は $O(1)$．

## Line

```cpp
struct Line {
    Point s, t;
};
```

直線または線分を表す．関数名の `l` は直線，`s` は線分として扱うことを表す．

### コンストラクタ

```cpp
Line l(Point s = Point(0, 0), Point t = Point(0, 0))
```

### 関数

```cpp
Point dir(Line l)
Real norm(Line l)
Point normalize(Line l)
Point projection(Line l, Point p)
Point reflection(Line l, Point p)
bool is_parallel(Line a, Line b)
bool is_orthogonal(Line a, Line b)
bool is_intersect(Line a, Line b)
Point cross_ll(Line a, Line b)
```

* `dir(l)` は方向ベクトル `l.t - l.s` を返す．
* `norm(l)` は `dir(l)` の長さを返す．
* `normalize(l)` は単位方向ベクトルを返す．
* `projection(l, p)` は点 `p` の直線 `l` への射影を返す．
* `reflection(l, p)` は点 `p` の直線 `l` に関する反射点を返す．
* `is_parallel(a, b)` は2直線が平行かを返す．
* `is_orthogonal(a, b)` は2直線が直交するかを返す．
* `is_intersect(a, b)` は2線分が交差するかを返す．
* `cross_ll(a, b)` は2直線の交点を返す．平行でないことが前提．

計算時間はいずれも $O(1)$．

## 距離

```cpp
Real dist_pp(Point a, Point b)
Real dist_lp(Line l, Point p)
Real dist_sp(Line s, Point p)
Real dist_ss(Line a, Line b)
```

* `dist_pp(a, b)` は点と点の距離を返す．
* `dist_lp(l, p)` は直線 `l` と点 `p` の距離を返す．
* `dist_sp(s, p)` は線分 `s` と点 `p` の距離を返す．
* `dist_ss(a, b)` は線分 `a` と線分 `b` の距離を返す．

計算時間はいずれも $O(1)$．

## Polygon

```cpp
struct Polygon : public vector<Point> {};
```

多角形を表す．頂点は順番に入れる．

### 関数

```cpp
Real area(Polygon pol)
bool is_convex(Polygon pol)
pair<int, int> diameter(Polygon pol)
int contain(Polygon pol, Point p)
Polygon convex_hull(Polygon pol)
Polygon convex_cut(Polygon pol, Line l)
Real closest_pair(vector<Point> ps)
```

* `area(pol)` は符号付き面積を返す．頂点が反時計回りなら正になる．
* `is_convex(pol)` は凸多角形かを返す．時計回りの曲がりがあると `false`．
* `diameter(pol)` は凸多角形の最遠点対の添字を返す．`pol` が凸であることが前提．
* `contain(pol, p)` は点 `p` と多角形 `pol` の包含関係を返す．
* `convex_hull(pol)` は点集合の凸包を返す．
* `convex_cut(pol, l)` は凸多角形 `pol` を直線 `l` の左側で切った凸多角形を返す．
* `closest_pair(ps)` は点集合の最近点対距離を返す．

### contain

```cpp
int contain(Polygon pol, Point p)
```

| 返り値 | 意味 |
| --- | --- |
| `2` | 内部 |
| `1` | 辺上 |
| `0` | 外部 |

### 計算時間

* `area`: $O(n)$
* `is_convex`: $O(n)$
* `diameter`: $O(n)$
* `contain`: $O(n)$
* `convex_hull`: $O(n \log n)$
* `convex_cut`: $O(n)$
* `closest_pair`: $O(n \log n)$

## Circle

```cpp
struct Circle {
    Point p;
    Real r;
};
```

中心 `p`，半径 `r` の円を表す．

### コンストラクタ

```cpp
Circle c()
Circle c(Point p, Real r)
```

## 円の関数

```cpp
int intersection(Circle c1, Circle c2)
pair<Point, Point> cross_cl(Circle c, Line l)
Circle incircle(Point a, Point b, Point c)
Circle outcircle(Point a, Point b, Point c)
pair<Point, Point> cross_cc(Circle c1, Circle c2)
pair<Point, Point> tangent_cp(Circle c, Point p)
vector<Line> tangent_cc(Circle c1, Circle c2)
Real common_area_cp(Circle c, Polygon pol)
Real common_area_cc(Circle c1, Circle c2)
```

* `intersection(c1, c2)` は2円の位置関係を返す．
* `cross_cl(c, l)` は円 `c` と直線 `l` の交点を返す．交点があることが前提．
* `incircle(a, b, c)` は三角形 `abc` の内接円を返す．
* `outcircle(a, b, c)` は三角形 `abc` の外接円を返す．
* `cross_cc(c1, c2)` は2円の交点を返す．交点があることが前提．
* `tangent_cp(c, p)` は点 `p` から円 `c` へ引いた2本の接線の接点を返す．
* `tangent_cc(c1, c2)` は2円の共通接線を返す．
* `common_area_cp(c, pol)` は円 `c` と多角形 `pol` の共通部分の面積を返す．
* `common_area_cc(c1, c2)` は2円の共通部分の面積を返す．

### intersection

```cpp
int intersection(Circle c1, Circle c2)
```

| 返り値 | 意味 |
| --- | --- |
| `4` | 離れている |
| `3` | 外接する |
| `2` | 2点で交わる |
| `1` | 内接する |
| `0` | 一方が他方の内部にあり交わらない |

### 計算時間

* `intersection`: $O(1)$
* `cross_cl`: $O(1)$
* `incircle`: $O(1)$
* `outcircle`: $O(1)$
* `cross_cc`: $O(1)$
* `tangent_cp`: $O(1)$
* `tangent_cc`: $O(1)$
* `common_area_cp`: $O(n)$
* `common_area_cc`: $O(1)$

## 使用例

```cpp
#include <bits/stdc++.h>
#include "geometry/geometry.hpp"
using namespace std;

int main() {
    Point a(0, 0), b(3, 0), c(0, 4);

    cout << dist_pp(a, b) << endl;       // 3
    cout << area(Polygon{a, b, c}) << endl; // 6

    Line s(a, b);
    cout << dist_sp(s, c) << endl;       // 4
}
```
