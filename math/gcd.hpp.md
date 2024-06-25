---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_1_b.test.cpp
    title: verify/aoj/aoj_alds1_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/gcd.hpp\"\nlong long gcd(long long a, long long b)\
    \ {\n    if(b == 0) return a;\n    return gcd(b, a % b);\n}\n"
  code: "long long gcd(long long a, long long b) {\n    if(b == 0) return a;\n   \
    \ return gcd(b, a % b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/gcd.hpp
  requiredBy: []
  timestamp: '2024-06-26 02:22:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_alds1_1_b.test.cpp
documentation_of: math/gcd.hpp
layout: document
redirect_from:
- /library/math/gcd.hpp
- /library/math/gcd.hpp.html
title: math/gcd.hpp
---
