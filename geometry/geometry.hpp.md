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
    \ == (const Point& rhs) const { return sgn(x - rhs.x) && sgn(y - rhs.y); }\n \
    \   constexpr bool operator != (const Point& rhs) const { return !(*this == rhs);\
    \ }\n\n    constexpr Real norm2() const { return x * x + y * y; }\n    constexpr\
    \ Real norm() const { return sqrt(norm2()); }\n    constexpr Real arg() const\
    \ { return atan2(y, x); }\n    constexpr Point rotate(Real theta) const { return\
    \ Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }\n\
    \n    friend istream& operator >> (istream& is, Point& p) { return is >> p.x >>\
    \ p.y; }\n    friend ostream& operator << (ostream& os, const Point& p) { return\
    \ os << \"(\" << p.x << \", \" << p.y << \")\"; }\n\n    friend constexpr Real\
    \ dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }\n    friend\
    \ constexpr Real cross(const Point& a, const Point& b) { return a.x * b.y - a.y\
    \ * b.x; }\n\n    friend constexpr Real norm2(const Point& p) { return p.norm2();\
    \ }\n    friend constexpr Real norm(const Point& p) { return p.norm(); }\n   \
    \ friend constexpr Real arg(const Point& p) { return p.arg(); }\n};\n\nstruct\
    \ Line {\n    Point s, t;\n    constexpr Line(Point s=Point(0, 0), Point t=Point(0,\
    \ 0)) : s(s), t(t) {}\n    constexpr Point dir() const { return t - s; }\n   \
    \ constexpr Real norm() const { return dir().norm(); }\n\n    friend constexpr\
    \ Point dir(const Line& l) { return l.dir(); }\n    friend constexpr Real norm(const\
    \ Line& l) { return l.norm(); }\n};\n\nPoint projection(const Line& l, const Point&\
    \ p) {\n    Real t = dot(p - l.s, l.t - l.s) / norm2(l.t - l.s);\n    return l.s\
    \ + l.dir() * t;\n}\n\nPoint reflection(const Line& l, const Point& p) {\n   \
    \ Point x = projection(l, p);\n    return 2 * x - p;\n}\n\n// +1 : a - b, a -\
    \ c : ccw\n// -1 : a - b, a - c : cw\n// +2 : c - a - b    : on_back\n// -2 :\
    \ a - b - c    : on_front\n//  0 : a - c - b    : on_segment\nint ccw(const Point&\
    \ a, Point b, Point c) {\n    b -= a, c -= a;\n    if(sgn(cross(b, c)) == 1) return\
    \ 1;\n    if(sgn(cross(b, c)) == -1) return -1;\n    if(sgn(dot(b, c)) == -1)\
    \ return 2;\n    if(b.norm2() < c.norm2()) return -2;\n    return 0; \n}\n\nbool\
    \ is_parallel(const Line& a, const Line& b) {\n    return sgn(cross(a.dir(), b.dir()))\
    \ == 0;\n}\n\nbool is_orthogonal(const Line& a, const Line& b) {\n    return sgn(dot(a.dir(),\
    \ b.dir())) == 0;\n}\n\nbool is_intersect(const Line& a, const Line& b) {\n  \
    \  return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 && ccw(b.s, b.t, a.s) *\
    \ ccw(b.s, b.t, a.t) <= 0;\n}\n\nPoint cross_point(const Line& a, const Line&\
    \ b) {\n    Real d1 = cross(a.dir(), b.dir());\n    Real d2 = cross(a.dir(), a.t\
    \ - b.s);\n    return b.s + b.dir() * (d2 / d1);\n}\n\nReal dist(const Point&\
    \ a, const Point& b) {\n    return norm(a - b);\n}\nReal dist_lp(const Line& l,\
    \ const Point& p) {\n    return abs(cross(l.dir(), p - l.s)) / norm(l);\n}\nReal\
    \ dist_sp(const Line& l, const Point& p) {\n    if(sgn(dot(l.dir(), p - l.s))\
    \ == -1) return norm(p - l.s);\n    if(sgn(dot(-l.dir(), p - l.t)) == -1) return\
    \ norm(p - l.t);\n    return dist_lp(l, p);\n}\nReal dist_ss(const Line& a, const\
    \ Line& b) {\n    if(is_intersect(a, b)) return 0;\n    return min({dist_sp(a,\
    \ b.s), dist_sp(a, b.t), dist_sp(b, a.s), dist_sp(b, a.t)});\n}\n\nstruct Polygon\
    \ : public vector<Point> {\n    using vector<Point>::vector;\n    Real area()\
    \ const {\n        int sz = size();\n        Real ret = 0;\n        for(int i\
    \ = 0; i < sz; i++) {\n            ret += cross((*this)[i], (*this)[(i + 1) %\
    \ sz]);\n        }\n        return ret / 2;\n    }\n\n    bool is_convex() const\
    \ {\n        int sz = size();\n        for(int i = 0; i < sz; i++) {\n       \
    \     if(ccw((*this)[i], (*this)[(i + 1) % sz], (*this)[(i + 2) % sz]) == -1)\
    \ false;\n        }\n        return true;\n    }\n\n    // 2 : contain\n    //\
    \ 1 : on line\n    // 0 : outside\n    int contain(const Point& p) const {\n \
    \       bool in = false;\n        int sz = size();\n        for(int i = 0; i <\
    \ sz; i++) {\n            Point a = (*this)[i] - p;\n            Point b = (*this)[(i\
    \ + 1) % sz] - p;\n            if(a.y > b.y) std::swap(a, b);\n            if(sgn(a.y)\
    \ == -1 && sgn(b.y) == 1 && sgn(cross(a, b)) == 1) in ^= 1;\n            if(sgn(cross(a,\
    \ b)) == -1 && sgn(dot(a, b)) == -1) return 1;\n        }\n        return 2 *\
    \ in;\n    }\n\n    pair<int, int> diameter() const {\n        assert(is_convex());\n\
    \        int sz = size();\n        int right = max_element(begin(), end()) - begin();\n\
    \        int left = min_element(begin(), end()) - begin();\n        Real max_dist\
    \ = norm2((*this)[left] - (*this)[right]);\n        pair<int, int> ret = {left,\
    \ right};\n        for(int i = 0; i < sz; i++) {\n            Point pre = (*this)[(left\
    \ + 1) % sz] - (*this)[left];\n            Point nxt = (*this)[right] - (*this)[(right\
    \ + 1) % sz];\n            if(ccw(Point(0, 0), pre, nxt) == 1) left = (left +\
    \ 1) % sz;\n            else right = (right + 1) % sz;\n            if(norm2((*this)[left]\
    \ - (*this)[right]) > max_dist) max_dist = norm2((*this)[left] - (*this)[right]),\
    \ ret = {left, right};\n        }\n        return ret;\n    }\n\n    friend Real\
    \ area(const Polygon& pol) { return pol.area(); }\n    friend bool is_convex(const\
    \ Polygon& pol) { return pol.is_convex(); }\n    friend int contain(const Polygon&\
    \ pol, const Point& p) { return pol.contain(p); }\n    friend pair<int, int> diameter(const\
    \ Polygon& pol) { return pol.diameter(); } \n};\n\nPolygon convex_hull(Polygon\
    \ pol) {\n    int sz = pol.size();\n    sort(pol.begin(), pol.end());\n    Polygon\
    \ ret;\n    for(int i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size()\
    \ - 2], ret.back(), pol[i]) == -1) ret.pop_back();\n        ret.push_back(pol[i]);\n\
    \    }\n    int t = ret.size();\n    for(int i = sz - 2; i >= 0; i--) {\n    \
    \    while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), pol[i]) == -1)\
    \ ret.pop_back();\n        ret.push_back(pol[i]);\n    }\n    ret.pop_back();\n\
    \    return ret;\n}\n\nPolygon convex_cut(const Polygon& pol, const Line& l) {\n\
    \    int sz = pol.size();\n    Polygon ret;\n    for(int i = 0; i < pol.size();\
    \ i++) {\n        int t1 = sgn(cross(l.dir(), pol[i] - l.s)), t2 = sgn(cross(l.dir(),\
    \ pol[(i + 1) % sz] - l.s));\n        if(t1 >= 0) ret.push_back(pol[i]); \n  \
    \      if(t1 * t2 < 0) ret.push_back(cross_point(Line(pol[i], pol[(i + 1) % sz]),\
    \ l));\n    }\n    return ret;\n}\n\nReal closest_pair(vector<Point> ps) {\n \
    \   auto rec = [](auto f, vector<Point>& ps, int l, int r) -> Real {\n       \
    \ if(r - l < 2) return 1e100;\n        int mid = (l + r) / 2;\n        Real x\
    \ = ps[mid].x;\n        Real d = min(f(f, ps, l, mid), f(f, ps, mid, r));\n  \
    \      auto it = ps.begin(), itl = it + l, itm = it + mid, itr = it + r;\n   \
    \     inplace_merge(itl, itm, itr, [](Point a, Point b) { return a.y < b.y; });\n\
    \        vector<Point> near_line;\n        for(int i = l; i < r; i++) {\n    \
    \        if(abs(ps[i].x - x) >= d) continue;\n            int sz = near_line.size();\n\
    \            for(int j = sz; j--;) {\n                if(ps[i].y - near_line[j].y\
    \ >= d) break;\n                d = min(d, dist(ps[i], near_line[j]));\n     \
    \       }\n            near_line.push_back(ps[i]);\n        }\n        return\
    \ d;\n    };\n    sort(ps.begin(), ps.end());\n    return rec(rec, ps, 0, ps.size());\n\
    }\n\nstruct Circle {\n    Point p;\n    Real r;\n    Circle() : p(Point(0, 0)),\
    \ r(0) {}\n    Circle(Point p, Real r) : p(p), r(r) {}\n\n    int intersection(const\
    \ Circle& c) {\n        Real d = dist(p, c.p);\n        if(sgn(d - (r + c.r))\
    \ == 1) return 4;\n        if(sgn(d - (r + c.r)) == 0) return 3;\n        if(sgn(d\
    \ - abs(r - c.r)) == 1) return 2;\n        if(sgn(d - abs(r - c.r)) == 0) return\
    \ 1;\n        return 0;\n    }\n};\n\n}  // namespace geometry\n\nusing namespace\
    \ geometry;\n"
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
    \ sgn(x - rhs.x) && sgn(y - rhs.y); }\n    constexpr bool operator != (const Point&\
    \ rhs) const { return !(*this == rhs); }\n\n    constexpr Real norm2() const {\
    \ return x * x + y * y; }\n    constexpr Real norm() const { return sqrt(norm2());\
    \ }\n    constexpr Real arg() const { return atan2(y, x); }\n    constexpr Point\
    \ rotate(Real theta) const { return Point(x * cos(theta) - y * sin(theta), x *\
    \ sin(theta) + y * cos(theta)); }\n\n    friend istream& operator >> (istream&\
    \ is, Point& p) { return is >> p.x >> p.y; }\n    friend ostream& operator <<\
    \ (ostream& os, const Point& p) { return os << \"(\" << p.x << \", \" << p.y <<\
    \ \")\"; }\n\n    friend constexpr Real dot(const Point& a, const Point& b) {\
    \ return a.x * b.x + a.y * b.y; }\n    friend constexpr Real cross(const Point&\
    \ a, const Point& b) { return a.x * b.y - a.y * b.x; }\n\n    friend constexpr\
    \ Real norm2(const Point& p) { return p.norm2(); }\n    friend constexpr Real\
    \ norm(const Point& p) { return p.norm(); }\n    friend constexpr Real arg(const\
    \ Point& p) { return p.arg(); }\n};\n\nstruct Line {\n    Point s, t;\n    constexpr\
    \ Line(Point s=Point(0, 0), Point t=Point(0, 0)) : s(s), t(t) {}\n    constexpr\
    \ Point dir() const { return t - s; }\n    constexpr Real norm() const { return\
    \ dir().norm(); }\n\n    friend constexpr Point dir(const Line& l) { return l.dir();\
    \ }\n    friend constexpr Real norm(const Line& l) { return l.norm(); }\n};\n\n\
    Point projection(const Line& l, const Point& p) {\n    Real t = dot(p - l.s, l.t\
    \ - l.s) / norm2(l.t - l.s);\n    return l.s + l.dir() * t;\n}\n\nPoint reflection(const\
    \ Line& l, const Point& p) {\n    Point x = projection(l, p);\n    return 2 *\
    \ x - p;\n}\n\n// +1 : a - b, a - c : ccw\n// -1 : a - b, a - c : cw\n// +2 :\
    \ c - a - b    : on_back\n// -2 : a - b - c    : on_front\n//  0 : a - c - b \
    \   : on_segment\nint ccw(const Point& a, Point b, Point c) {\n    b -= a, c -=\
    \ a;\n    if(sgn(cross(b, c)) == 1) return 1;\n    if(sgn(cross(b, c)) == -1)\
    \ return -1;\n    if(sgn(dot(b, c)) == -1) return 2;\n    if(b.norm2() < c.norm2())\
    \ return -2;\n    return 0; \n}\n\nbool is_parallel(const Line& a, const Line&\
    \ b) {\n    return sgn(cross(a.dir(), b.dir())) == 0;\n}\n\nbool is_orthogonal(const\
    \ Line& a, const Line& b) {\n    return sgn(dot(a.dir(), b.dir())) == 0;\n}\n\n\
    bool is_intersect(const Line& a, const Line& b) {\n    return ccw(a.s, a.t, b.s)\
    \ * ccw(a.s, a.t, b.t) <= 0 && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\n\
    }\n\nPoint cross_point(const Line& a, const Line& b) {\n    Real d1 = cross(a.dir(),\
    \ b.dir());\n    Real d2 = cross(a.dir(), a.t - b.s);\n    return b.s + b.dir()\
    \ * (d2 / d1);\n}\n\nReal dist(const Point& a, const Point& b) {\n    return norm(a\
    \ - b);\n}\nReal dist_lp(const Line& l, const Point& p) {\n    return abs(cross(l.dir(),\
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
    \ -1) false;\n        }\n        return true;\n    }\n\n    // 2 : contain\n \
    \   // 1 : on line\n    // 0 : outside\n    int contain(const Point& p) const\
    \ {\n        bool in = false;\n        int sz = size();\n        for(int i = 0;\
    \ i < sz; i++) {\n            Point a = (*this)[i] - p;\n            Point b =\
    \ (*this)[(i + 1) % sz] - p;\n            if(a.y > b.y) std::swap(a, b);\n   \
    \         if(sgn(a.y) == -1 && sgn(b.y) == 1 && sgn(cross(a, b)) == 1) in ^= 1;\n\
    \            if(sgn(cross(a, b)) == -1 && sgn(dot(a, b)) == -1) return 1;\n  \
    \      }\n        return 2 * in;\n    }\n\n    pair<int, int> diameter() const\
    \ {\n        assert(is_convex());\n        int sz = size();\n        int right\
    \ = max_element(begin(), end()) - begin();\n        int left = min_element(begin(),\
    \ end()) - begin();\n        Real max_dist = norm2((*this)[left] - (*this)[right]);\n\
    \        pair<int, int> ret = {left, right};\n        for(int i = 0; i < sz; i++)\
    \ {\n            Point pre = (*this)[(left + 1) % sz] - (*this)[left];\n     \
    \       Point nxt = (*this)[right] - (*this)[(right + 1) % sz];\n            if(ccw(Point(0,\
    \ 0), pre, nxt) == 1) left = (left + 1) % sz;\n            else right = (right\
    \ + 1) % sz;\n            if(norm2((*this)[left] - (*this)[right]) > max_dist)\
    \ max_dist = norm2((*this)[left] - (*this)[right]), ret = {left, right};\n   \
    \     }\n        return ret;\n    }\n\n    friend Real area(const Polygon& pol)\
    \ { return pol.area(); }\n    friend bool is_convex(const Polygon& pol) { return\
    \ pol.is_convex(); }\n    friend int contain(const Polygon& pol, const Point&\
    \ p) { return pol.contain(p); }\n    friend pair<int, int> diameter(const Polygon&\
    \ pol) { return pol.diameter(); } \n};\n\nPolygon convex_hull(Polygon pol) {\n\
    \    int sz = pol.size();\n    sort(pol.begin(), pol.end());\n    Polygon ret;\n\
    \    for(int i = 0; i < sz; i++) {\n        while(ret.size() > 1 && ccw(ret[ret.size()\
    \ - 2], ret.back(), pol[i]) == -1) ret.pop_back();\n        ret.push_back(pol[i]);\n\
    \    }\n    int t = ret.size();\n    for(int i = sz - 2; i >= 0; i--) {\n    \
    \    while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), pol[i]) == -1)\
    \ ret.pop_back();\n        ret.push_back(pol[i]);\n    }\n    ret.pop_back();\n\
    \    return ret;\n}\n\nPolygon convex_cut(const Polygon& pol, const Line& l) {\n\
    \    int sz = pol.size();\n    Polygon ret;\n    for(int i = 0; i < pol.size();\
    \ i++) {\n        int t1 = sgn(cross(l.dir(), pol[i] - l.s)), t2 = sgn(cross(l.dir(),\
    \ pol[(i + 1) % sz] - l.s));\n        if(t1 >= 0) ret.push_back(pol[i]); \n  \
    \      if(t1 * t2 < 0) ret.push_back(cross_point(Line(pol[i], pol[(i + 1) % sz]),\
    \ l));\n    }\n    return ret;\n}\n\nReal closest_pair(vector<Point> ps) {\n \
    \   auto rec = [](auto f, vector<Point>& ps, int l, int r) -> Real {\n       \
    \ if(r - l < 2) return 1e100;\n        int mid = (l + r) / 2;\n        Real x\
    \ = ps[mid].x;\n        Real d = min(f(f, ps, l, mid), f(f, ps, mid, r));\n  \
    \      auto it = ps.begin(), itl = it + l, itm = it + mid, itr = it + r;\n   \
    \     inplace_merge(itl, itm, itr, [](Point a, Point b) { return a.y < b.y; });\n\
    \        vector<Point> near_line;\n        for(int i = l; i < r; i++) {\n    \
    \        if(abs(ps[i].x - x) >= d) continue;\n            int sz = near_line.size();\n\
    \            for(int j = sz; j--;) {\n                if(ps[i].y - near_line[j].y\
    \ >= d) break;\n                d = min(d, dist(ps[i], near_line[j]));\n     \
    \       }\n            near_line.push_back(ps[i]);\n        }\n        return\
    \ d;\n    };\n    sort(ps.begin(), ps.end());\n    return rec(rec, ps, 0, ps.size());\n\
    }\n\nstruct Circle {\n    Point p;\n    Real r;\n    Circle() : p(Point(0, 0)),\
    \ r(0) {}\n    Circle(Point p, Real r) : p(p), r(r) {}\n\n    int intersection(const\
    \ Circle& c) {\n        Real d = dist(p, c.p);\n        if(sgn(d - (r + c.r))\
    \ == 1) return 4;\n        if(sgn(d - (r + c.r)) == 0) return 3;\n        if(sgn(d\
    \ - abs(r - c.r)) == 1) return 2;\n        if(sgn(d - abs(r - c.r)) == 0) return\
    \ 1;\n        return 0;\n    }\n};\n\n}  // namespace geometry\n\nusing namespace\
    \ geometry;"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2025-01-29 03:22:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry.hpp
layout: document
redirect_from:
- /library/geometry/geometry.hpp
- /library/geometry/geometry.hpp.html
title: geometry/geometry.hpp
---
