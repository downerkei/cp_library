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
    \ namespace std;\n\n\nnamespace geometry {\n\nusing Real = double;\nconstexpr\
    \ Real EPS = 1e-7;\n\nstruct Point {\n    Real x, y;\n    constexpr Point(Real\
    \ x=0, Real y=0) : x(x), y(y) {}\n\n    constexpr Point& operator += (const Point&\
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
    \ { return (fabs(x - rhs.x) >= EPS) ? (x < rhs.x) : (y < rhs.y); }\n    constexpr\
    \ bool operator > (const Point& rhs) const { return rhs < *this; }\n    constexpr\
    \ bool operator == (const Point& rhs) const { return fabs(x - rhs.x) < EPS &&\
    \ fabs(y - rhs.y) < EPS; }\n    constexpr bool operator != (const Point& rhs)\
    \ const { return !(*this == rhs); }\n\n    constexpr Real norm2() const { return\
    \ x * x + y * y; }\n    constexpr Real norm() const { return sqrt(norm2()); }\n\
    \    constexpr Real arg() const { return atan2(y, x); }\n    constexpr Point rotate(Real\
    \ theta) const { return Point(x * cos(theta) - y * sin(theta), x * sin(theta)\
    \ + y * cos(theta)); }\n\n    friend istream& operator >> (istream& is, Point&\
    \ p) { return is >> p.x >> p.y; }\n    friend ostream& operator << (ostream& os,\
    \ const Point& p) { return os << \"(\" << p.x << \", \" << p.y << \")\"; }\n\n\
    \    friend constexpr Real dot(const Point& a, const Point& b) { return a.x *\
    \ b.x + a.y * b.y; }\n    friend constexpr Real cross(const Point& a, const Point&\
    \ b) { return a.x * b.y - a.y * b.x; }\n\n    friend constexpr Real norm2(const\
    \ Point& p) { return p.norm2(); }\n    friend constexpr Real norm(const Point&\
    \ p) { return p.norm(); }\n    friend constexpr Real arg(const Point& p) { return\
    \ p.arg(); }\n};\n\nstruct Line {\n    Point s, t;\n    constexpr Line(Point s=Point(0,\
    \ 0), Point t=Point(0, 0)) : s(s), t(t) {}\n    constexpr Point dir() const {\
    \ return t - s; }\n    constexpr Real norm() const { return dir().norm(); }\n\n\
    \    friend constexpr Point dir(const Line& l) { return l.dir(); }\n    friend\
    \ constexpr Real norm(const Line& l) { return l.norm(); }\n};\n\nPoint projection(const\
    \ Line& l, const Point& p) {\n    Real t = dot(p - l.s, l.t - l.s) / norm2(l.t\
    \ - l.s);\n    return l.s + l.dir() * t;\n}\n\nPoint reflection(const Line& l,\
    \ const Point& p) {\n    Point x = projection(l, p);\n    return 2 * x - p;\n\
    }\n\n// +1 : a - b, a - c : ccw\n// -1 : a - b, a - c : cw\n// +2 : c - a - b\
    \    : on_back\n// -2 : a - b - c    : on_front\n//  0 : a - c - b    : on_segment\n\
    int ccw(const Point& a, Point b, Point c) {\n    b -= a, c -= a;\n    if(cross(b,\
    \ c) > EPS) return 1;\n    if(cross(b, c) < -EPS) return -1;\n    if(dot(b, c)\
    \ < -EPS) return 2;\n    if(b.norm2() < c.norm2()) return -2;\n    return 0; \n\
    }\n\nbool is_parallel(const Line& a, const Line& b) {\n    return fabs(cross(a.dir(),\
    \ b.dir())) < EPS;\n}\n\nbool is_orthogonal(const Line& a, const Line& b) {\n\
    \    return fabs(dot(a.dir(), b.dir())) < EPS;\n}\n\nbool is_intersect(const Line&\
    \ a, const Line& b) {\n    return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0\
    \ && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\n}\n\nPoint cross_point(const\
    \ Line& a, const Line& b) {\n    Real d1 = cross(a.dir(), b.dir());\n    Real\
    \ d2 = cross(a.dir(), a.t - b.s);\n    return b.s + b.dir() * (d2 / d1);\n}\n\n\
    Real dist_lp(const Line& l, const Point& p) {\n    return abs(cross(l.dir(), p\
    \ - l.s)) / norm(l);\n}\n\nReal dist_sp(const Line& l, const Point& p) {\n   \
    \ if(dot(l.dir(), p - l.s) < EPS) return norm(p - l.s);\n    if(dot(-l.dir(),\
    \ p - l.t) < EPS) return norm(p - l.t);\n    return dist_lp(l, p);\n}\n\nReal\
    \ dist_ss(const Line& a, const Line& b) {\n    if(is_intersect(a, b)) return 0;\n\
    \    return min({dist_sp(a, b.s), dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b,\
    \ a.t)});\n}\n\nReal area(const vector<Point>& p) {\n    int sz = p.size();\n\
    \    Real ret = 0;\n    for(int i = 0; i < sz; i++) {\n        ret += cross(p[i],\
    \ p[(i + 1) % sz]);\n    }\n    return ret / 2;\n}\n\nbool is_convex(const vector<Point>&\
    \ p) {\n    int sz = p.size();\n    for(int i = 0; i < sz; i++) {\n        if(ccw(p[i],\
    \ p[(i + 1) % sz], p[(i + 2) % sz]) == -1) return false;\n    }\n    return true;\n\
    }\n\n// 2 : contain\n// 1 : on line\n// 0 : outside\nint contain(const vector<Point>&\
    \ g, const Point& p) {\n    bool in = false;\n    int sz = g.size();\n    for(int\
    \ i = 0; i < sz; i++) {\n        Point a = g[i] - p, b = g[(i + 1) % sz] - p;\n\
    \        if(a.y > b.y) swap(a, b);\n        if(a.y <= EPS && EPS <= b.y && EPS\
    \ <= cross(a, b)) in ^= 1;\n        if(fabs(cross(a, b)) < EPS && dot(a, b) <\
    \ EPS) return 1;\n    }\n    return 2 * in;\n}\n\nvector<Point> convex_hull(vector<Point>\
    \ p) {\n    int sz = p.size();\n    sort(p.begin(), p.end());\n    vector<Point>\
    \ ret;\n    for(int i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size()\
    \ - 2], ret.back(), p[i]) == -1) ret.pop_back();\n        ret.push_back(p[i]);\n\
    \    }\n    int t = ret.size();\n    for(int i = sz - 2; i >= 0; i--) {\n    \
    \    while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), p[i]) == -1)\
    \ ret.pop_back();\n        ret.push_back(p[i]);\n    }\n    ret.pop_back();\n\
    \    return ret;\n}\n\npair<int, int> diameter(const vector<Point>& p) {\n   \
    \ int sz = p.size();\n    int right = 0, left = 0;\n    for(int i = 0; i < sz;\
    \ i++) {\n        if(p[i].x < p[left].x) left = i;\n        if(p[i].x > p[right].x)\
    \ right = i;\n    }\n    Real max_dist = norm2(p[left] - p[right]);\n    pair<int,\
    \ int> ret = {left, right};\n    for(int i = 0; i < sz; i++) {\n        Point\
    \ pre = p[(left + 1) % sz] - p[left];\n        Point nxt = p[right] - p[(right\
    \ + 1) % sz];\n        if(ccw(Point(0, 0), pre, nxt) == 1) left = (left + 1) %\
    \ sz;\n        else right = (right + 1) % sz;\n        if(norm2(p[left] - p[right])\
    \ > max_dist) max_dist = norm2(p[left] - p[right]), ret = {left, right};\n   \
    \ }\n    return ret;\n}\n\n}  // namespace geometry\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n\nnamespace geometry {\n\
    \nusing Real = double;\nconstexpr Real EPS = 1e-7;\n\nstruct Point {\n    Real\
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
    \ operator < (const Point& rhs) const { return (fabs(x - rhs.x) >= EPS) ? (x <\
    \ rhs.x) : (y < rhs.y); }\n    constexpr bool operator > (const Point& rhs) const\
    \ { return rhs < *this; }\n    constexpr bool operator == (const Point& rhs) const\
    \ { return fabs(x - rhs.x) < EPS && fabs(y - rhs.y) < EPS; }\n    constexpr bool\
    \ operator != (const Point& rhs) const { return !(*this == rhs); }\n\n    constexpr\
    \ Real norm2() const { return x * x + y * y; }\n    constexpr Real norm() const\
    \ { return sqrt(norm2()); }\n    constexpr Real arg() const { return atan2(y,\
    \ x); }\n    constexpr Point rotate(Real theta) const { return Point(x * cos(theta)\
    \ - y * sin(theta), x * sin(theta) + y * cos(theta)); }\n\n    friend istream&\
    \ operator >> (istream& is, Point& p) { return is >> p.x >> p.y; }\n    friend\
    \ ostream& operator << (ostream& os, const Point& p) { return os << \"(\" << p.x\
    \ << \", \" << p.y << \")\"; }\n\n    friend constexpr Real dot(const Point& a,\
    \ const Point& b) { return a.x * b.x + a.y * b.y; }\n    friend constexpr Real\
    \ cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }\n\n\
    \    friend constexpr Real norm2(const Point& p) { return p.norm2(); }\n    friend\
    \ constexpr Real norm(const Point& p) { return p.norm(); }\n    friend constexpr\
    \ Real arg(const Point& p) { return p.arg(); }\n};\n\nstruct Line {\n    Point\
    \ s, t;\n    constexpr Line(Point s=Point(0, 0), Point t=Point(0, 0)) : s(s),\
    \ t(t) {}\n    constexpr Point dir() const { return t - s; }\n    constexpr Real\
    \ norm() const { return dir().norm(); }\n\n    friend constexpr Point dir(const\
    \ Line& l) { return l.dir(); }\n    friend constexpr Real norm(const Line& l)\
    \ { return l.norm(); }\n};\n\nPoint projection(const Line& l, const Point& p)\
    \ {\n    Real t = dot(p - l.s, l.t - l.s) / norm2(l.t - l.s);\n    return l.s\
    \ + l.dir() * t;\n}\n\nPoint reflection(const Line& l, const Point& p) {\n   \
    \ Point x = projection(l, p);\n    return 2 * x - p;\n}\n\n// +1 : a - b, a -\
    \ c : ccw\n// -1 : a - b, a - c : cw\n// +2 : c - a - b    : on_back\n// -2 :\
    \ a - b - c    : on_front\n//  0 : a - c - b    : on_segment\nint ccw(const Point&\
    \ a, Point b, Point c) {\n    b -= a, c -= a;\n    if(cross(b, c) > EPS) return\
    \ 1;\n    if(cross(b, c) < -EPS) return -1;\n    if(dot(b, c) < -EPS) return 2;\n\
    \    if(b.norm2() < c.norm2()) return -2;\n    return 0; \n}\n\nbool is_parallel(const\
    \ Line& a, const Line& b) {\n    return fabs(cross(a.dir(), b.dir())) < EPS;\n\
    }\n\nbool is_orthogonal(const Line& a, const Line& b) {\n    return fabs(dot(a.dir(),\
    \ b.dir())) < EPS;\n}\n\nbool is_intersect(const Line& a, const Line& b) {\n \
    \   return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 && ccw(b.s, b.t, a.s)\
    \ * ccw(b.s, b.t, a.t) <= 0;\n}\n\nPoint cross_point(const Line& a, const Line&\
    \ b) {\n    Real d1 = cross(a.dir(), b.dir());\n    Real d2 = cross(a.dir(), a.t\
    \ - b.s);\n    return b.s + b.dir() * (d2 / d1);\n}\n\nReal dist_lp(const Line&\
    \ l, const Point& p) {\n    return abs(cross(l.dir(), p - l.s)) / norm(l);\n}\n\
    \nReal dist_sp(const Line& l, const Point& p) {\n    if(dot(l.dir(), p - l.s)\
    \ < EPS) return norm(p - l.s);\n    if(dot(-l.dir(), p - l.t) < EPS) return norm(p\
    \ - l.t);\n    return dist_lp(l, p);\n}\n\nReal dist_ss(const Line& a, const Line&\
    \ b) {\n    if(is_intersect(a, b)) return 0;\n    return min({dist_sp(a, b.s),\
    \ dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b, a.t)});\n}\n\nReal area(const vector<Point>&\
    \ p) {\n    int sz = p.size();\n    Real ret = 0;\n    for(int i = 0; i < sz;\
    \ i++) {\n        ret += cross(p[i], p[(i + 1) % sz]);\n    }\n    return ret\
    \ / 2;\n}\n\nbool is_convex(const vector<Point>& p) {\n    int sz = p.size();\n\
    \    for(int i = 0; i < sz; i++) {\n        if(ccw(p[i], p[(i + 1) % sz], p[(i\
    \ + 2) % sz]) == -1) return false;\n    }\n    return true;\n}\n\n// 2 : contain\n\
    // 1 : on line\n// 0 : outside\nint contain(const vector<Point>& g, const Point&\
    \ p) {\n    bool in = false;\n    int sz = g.size();\n    for(int i = 0; i < sz;\
    \ i++) {\n        Point a = g[i] - p, b = g[(i + 1) % sz] - p;\n        if(a.y\
    \ > b.y) swap(a, b);\n        if(a.y <= EPS && EPS <= b.y && EPS <= cross(a, b))\
    \ in ^= 1;\n        if(fabs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;\n\
    \    }\n    return 2 * in;\n}\n\nvector<Point> convex_hull(vector<Point> p) {\n\
    \    int sz = p.size();\n    sort(p.begin(), p.end());\n    vector<Point> ret;\n\
    \    for(int i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size()\
    \ - 2], ret.back(), p[i]) == -1) ret.pop_back();\n        ret.push_back(p[i]);\n\
    \    }\n    int t = ret.size();\n    for(int i = sz - 2; i >= 0; i--) {\n    \
    \    while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), p[i]) == -1)\
    \ ret.pop_back();\n        ret.push_back(p[i]);\n    }\n    ret.pop_back();\n\
    \    return ret;\n}\n\npair<int, int> diameter(const vector<Point>& p) {\n   \
    \ int sz = p.size();\n    int right = 0, left = 0;\n    for(int i = 0; i < sz;\
    \ i++) {\n        if(p[i].x < p[left].x) left = i;\n        if(p[i].x > p[right].x)\
    \ right = i;\n    }\n    Real max_dist = norm2(p[left] - p[right]);\n    pair<int,\
    \ int> ret = {left, right};\n    for(int i = 0; i < sz; i++) {\n        Point\
    \ pre = p[(left + 1) % sz] - p[left];\n        Point nxt = p[right] - p[(right\
    \ + 1) % sz];\n        if(ccw(Point(0, 0), pre, nxt) == 1) left = (left + 1) %\
    \ sz;\n        else right = (right + 1) % sz;\n        if(norm2(p[left] - p[right])\
    \ > max_dist) max_dist = norm2(p[left] - p[right]), ret = {left, right};\n   \
    \ }\n    return ret;\n}\n\n}  // namespace geometry"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2025-01-22 18:28:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry.hpp
layout: document
redirect_from:
- /library/geometry/geometry.hpp
- /library/geometry/geometry.hpp.html
title: geometry/geometry.hpp
---
