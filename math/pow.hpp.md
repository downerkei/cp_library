---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_ntl_1_b.test.cpp
    title: verify/aoj/aoj_ntl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/pow.hpp\"\nlong long pow(long long b, long long e)\
    \ {\n    long long ret = 1;\n    while(e) {\n        if(e & 1) ret *= b;\n   \
    \     b *= b;\n        e >>= 1;\n    }\n    return ret;\n}\n\nlong long modpow(long\
    \ long b, long long e, long long MOD=998244353) {\n    long long ret = 1;\n  \
    \  b %= MOD;\n    while(e) {\n        if(e & 1) ret = ret * b % MOD;\n       \
    \ b = b * b % MOD;\n        e >>= 1;\n    }\n    return ret;\n}\n"
  code: "long long pow(long long b, long long e) {\n    long long ret = 1;\n    while(e)\
    \ {\n        if(e & 1) ret *= b;\n        b *= b;\n        e >>= 1;\n    }\n \
    \   return ret;\n}\n\nlong long modpow(long long b, long long e, long long MOD=998244353)\
    \ {\n    long long ret = 1;\n    b %= MOD;\n    while(e) {\n        if(e & 1)\
    \ ret = ret * b % MOD;\n        b = b * b % MOD;\n        e >>= 1;\n    }\n  \
    \  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/pow.hpp
  requiredBy: []
  timestamp: '2025-02-25 02:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_ntl_1_b.test.cpp
documentation_of: math/pow.hpp
layout: document
redirect_from:
- /library/math/pow.hpp
- /library/math/pow.hpp.html
title: math/pow.hpp
---
