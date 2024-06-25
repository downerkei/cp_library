---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp
  bundledCode: "#line 1 \"verify/aoj/aoj_ntl_1_b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/pow.hpp\"\
    \nlong long pow(long long b, long long e) {\n    long long ret = 1;\n    while(e)\
    \ {\n        if(e & 1) ret *= b;\n        b *= b;\n        e >>= 1;\n    }\n \
    \   return ret;\n}\n\nlong long modpow(long long b, long long e, long long MOD=998244353)\
    \ {\n    long long ret = 1;\n    while(e) {\n        if(e & 1) ret = ret * b %\
    \ MOD;\n        b = b * b % MOD;\n        e >>= 1;\n    }\n    return ret;\n}\n\
    #line 7 \"verify/aoj/aoj_ntl_1_b.test.cpp\"\n\nint main() {\n    int m, n;\n \
    \   cin >> m >> n;\n\n    cout << modpow(m, n, (int)1e9+7) << endl;\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/pow.hpp\"\
    \n\nint main() {\n    int m, n;\n    cin >> m >> n;\n\n    cout << modpow(m, n,\
    \ (int)1e9+7) << endl;\n\n    return 0;\n}"
  dependsOn:
  - math/pow.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_ntl_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 02:06:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_ntl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_ntl_1_b.test.cpp
- /verify/verify/aoj/aoj_ntl_1_b.test.cpp.html
title: verify/aoj/aoj_ntl_1_b.test.cpp
---
