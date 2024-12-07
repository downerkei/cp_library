---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/convex_hull.hpp
    title: geometry/convex_hull.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/point.hpp\"\nstruct Point {\n    int x, y;\n};\n\
    #line 2 \"geometry/ccw.hpp\"\n\nint ccw(Point& a, Point& b, Point& c) {\n    long\
    \ long ret = a.x * b.y + b.x * c.y + c.x * a.y;\n\tret -= b.x * a.y + c.x * b.y\
    \ + a.x * c.y;\n    if(ret > 0) return 1;\n    if(ret < 0) return -1;\n    return\
    \ 0;\n}\n"
  code: "#include \"point.hpp\"\n\nint ccw(Point& a, Point& b, Point& c) {\n    long\
    \ long ret = a.x * b.y + b.x * c.y + c.x * a.y;\n\tret -= b.x * a.y + c.x * b.y\
    \ + a.x * c.y;\n    if(ret > 0) return 1;\n    if(ret < 0) return -1;\n    return\
    \ 0;\n}\n"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/ccw.hpp
  requiredBy:
  - geometry/convex_hull.hpp
  timestamp: '2024-12-08 05:37:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/ccw.hpp
layout: document
redirect_from:
- /library/geometry/ccw.hpp
- /library/geometry/ccw.hpp.html
title: geometry/ccw.hpp
---
