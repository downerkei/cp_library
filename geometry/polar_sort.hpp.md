---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/point.hpp\"\nstruct Point {\n    int x, y;\n};\n\
    #line 2 \"geometry/polar_sort.hpp\"\n\nint up(const Point& p) {\n    if(p.y >\
    \ 0 || (p.y == 0 && p.x < 0)) return 1;\n    if(p.y < 0 || (p.y == 0 && p.x >\
    \ 0)) return -1;\n    return 0;\n}\n\nbool cmp(const Point& a, const Point& b)\
    \ {\n    if(up(a) == up(b)) return (long long)a.y * b.x < (long long)b.y * a.x;\n\
    \    return up(a) < up(b);\n}\n\nvoid polar_sort(vector<Point>& V) {\n    sort(V.begin(),\
    \ V.end(), cmp);\n}\n"
  code: "#include \"point.hpp\"\n\nint up(const Point& p) {\n    if(p.y > 0 || (p.y\
    \ == 0 && p.x < 0)) return 1;\n    if(p.y < 0 || (p.y == 0 && p.x > 0)) return\
    \ -1;\n    return 0;\n}\n\nbool cmp(const Point& a, const Point& b) {\n    if(up(a)\
    \ == up(b)) return (long long)a.y * b.x < (long long)b.y * a.x;\n    return up(a)\
    \ < up(b);\n}\n\nvoid polar_sort(vector<Point>& V) {\n    sort(V.begin(), V.end(),\
    \ cmp);\n}\n"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/polar_sort.hpp
  requiredBy: []
  timestamp: '2024-12-08 04:47:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/polar_sort.hpp
layout: document
redirect_from:
- /library/geometry/polar_sort.hpp
- /library/geometry/polar_sort.hpp.html
title: geometry/polar_sort.hpp
---
