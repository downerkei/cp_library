---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_1_c.test.cpp
    title: verify/aoj/aoj_alds1_1_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/is_prime.hpp\"\nbool is_prime(long long p) {\n    if(p\
    \ < 2) return false;\n\n    for(long long i = 2; i * i <= p; i++) {\n        if(p\
    \ % i == 0) return false;\n    }\n\n    return true;\n}\n"
  code: "bool is_prime(long long p) {\n    if(p < 2) return false;\n\n    for(long\
    \ long i = 2; i * i <= p; i++) {\n        if(p % i == 0) return false;\n    }\n\
    \n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy: []
  timestamp: '2024-06-25 09:33:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_alds1_1_c.test.cpp
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: math/is_prime.hpp
---
