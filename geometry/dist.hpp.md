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
    #line 2 \"geometry/dist.hpp\"\n\ninline long long dist(Point& a, Point& b) {\n\
    \    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);\n}\n"
  code: "#include \"point.hpp\"\n\ninline long long dist(Point& a, Point& b) {\n \
    \   return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);\n}\n"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/dist.hpp
  requiredBy: []
  timestamp: '2024-12-08 05:37:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/dist.hpp
layout: document
redirect_from:
- /library/geometry/dist.hpp
- /library/geometry/dist.hpp.html
title: geometry/dist.hpp
---
