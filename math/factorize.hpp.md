---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_ntl_1_a.test.cpp
    title: verify/aoj/aoj_ntl_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/factorize.hpp\"\nvector<pair<long long, int>> factorize(long\
    \ long N) {\n    vector<pair<long long, int>> ret;\n    for(long long p = 2; p\
    \ * p <= N; p++) {\n        if(N % p != 0) continue;\n        int e = 0;\n   \
    \     while(N % p == 0) {\n            N /= p;\n            e++;\n        }\n\
    \        ret.push_back({p, e});\n    }\n    if(N != 1) ret.push_back({N, 1});\n\
    \    return ret;\n}\n"
  code: "vector<pair<long long, int>> factorize(long long N) {\n    vector<pair<long\
    \ long, int>> ret;\n    for(long long p = 2; p * p <= N; p++) {\n        if(N\
    \ % p != 0) continue;\n        int e = 0;\n        while(N % p == 0) {\n     \
    \       N /= p;\n            e++;\n        }\n        ret.push_back({p, e});\n\
    \    }\n    if(N != 1) ret.push_back({N, 1});\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy: []
  timestamp: '2024-06-26 01:56:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_ntl_1_a.test.cpp
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
