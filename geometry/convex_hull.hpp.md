---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
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
    #line 2 \"geometry/ccw.hpp\"\n\nint ccw(Point& a, Point& b, Point& c) {\n    long\
    \ long ret = a.x * b.y + b.x * c.y + c.x * a.y;\n\tret -= b.x * a.y + c.x * b.y\
    \ + a.x * c.y;\n    if(ret > 0) return 1;\n    if(ret < 0) return -1;\n    return\
    \ 0;\n}\n#line 2 \"geometry/convex_hull.hpp\"\n\nvector<Point> convex_hull(vector<Point>\
    \ V) {\n    int N = V.size();\n\n    auto cmp = [&](Point& a, Point& b) -> bool\
    \ {\n        return (a.y < b.y || (a.y == b.y && a.x < b.x));\n    };\n\n    sort(V.begin(),\
    \ V.end(), cmp);\n\n    vector<Point> ret;\n    for(int i = 0; i < N; i++) {\n\
    \        while(ret.size() > 1 && ccw(ret[ret.size() - 2], ret.back(), V[i]) ==\
    \ -1) ret.pop_back();\n        ret.push_back(V[i]);\n    }\n\n    int t = ret.size();\n\
    \    for(int i = N - 2; i >= 0; i--) {\n        while(ret.size() > t && ccw(ret[ret.size()\
    \ - 2], ret.back(), V[i]) == -1) ret.pop_back();\n        ret.push_back(V[i]);\n\
    \    }\n    ret.pop_back();\n    \n    return ret;\n}\n"
  code: "#include \"ccw.hpp\"\n\nvector<Point> convex_hull(vector<Point> V) {\n  \
    \  int N = V.size();\n\n    auto cmp = [&](Point& a, Point& b) -> bool {\n   \
    \     return (a.y < b.y || (a.y == b.y && a.x < b.x));\n    };\n\n    sort(V.begin(),\
    \ V.end(), cmp);\n\n    vector<Point> ret;\n    for(int i = 0; i < N; i++) {\n\
    \        while(ret.size() > 1 && ccw(ret[ret.size() - 2], ret.back(), V[i]) ==\
    \ -1) ret.pop_back();\n        ret.push_back(V[i]);\n    }\n\n    int t = ret.size();\n\
    \    for(int i = N - 2; i >= 0; i--) {\n        while(ret.size() > t && ccw(ret[ret.size()\
    \ - 2], ret.back(), V[i]) == -1) ret.pop_back();\n        ret.push_back(V[i]);\n\
    \    }\n    ret.pop_back();\n    \n    return ret;\n}\n"
  dependsOn:
  - geometry/ccw.hpp
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2024-12-08 06:15:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/geometry/convex_hull.hpp
- /library/geometry/convex_hull.hpp.html
title: geometry/convex_hull.hpp
---
