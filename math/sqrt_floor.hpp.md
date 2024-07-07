---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/sqrt_floor.test.cpp
    title: verify/unit_test/sqrt_floor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/sqrt_floor.hpp\"\nlong long sqrt_floor(long long N)\
    \ {\n    assert(0 <= N);\n    unsigned long long root = sqrtl(N);\n    while(root\
    \ * root > N) root--;\n    while((root + 1) * (root + 1) <= N) root++;\n    return\
    \ root;\n}\n"
  code: "long long sqrt_floor(long long N) {\n    assert(0 <= N);\n    unsigned long\
    \ long root = sqrtl(N);\n    while(root * root > N) root--;\n    while((root +\
    \ 1) * (root + 1) <= N) root++;\n    return root;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sqrt_floor.hpp
  requiredBy: []
  timestamp: '2024-07-07 15:05:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/sqrt_floor.test.cpp
documentation_of: math/sqrt_floor.hpp
layout: document
redirect_from:
- /library/math/sqrt_floor.hpp
- /library/math/sqrt_floor.hpp.html
title: math/sqrt_floor.hpp
---
