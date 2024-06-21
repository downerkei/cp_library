---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/pow.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nlong long pow(long long b, long long e) {\n    long long ret = 1;\n\
    \    while(e) {\n        if(e & 1) ret *= b;\n        b *= b;\n        e >>= 1;\n\
    \    }\n    return ret;\n}\n\nlong long modpow(long long b, long long e, long\
    \ long MOD=998244353) {\n    long long ret = 1;\n    while(e) {\n        if(e\
    \ & 1) ret = ret * b % MOD;\n        b = b * b % MOD;\n        e >>= 1;\n    }\n\
    \    return ret;\n}\n\nint main() {\n    cout << pow(2, 10) << endl;\n\n    return\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nlong long pow(long long\
    \ b, long long e) {\n    long long ret = 1;\n    while(e) {\n        if(e & 1)\
    \ ret *= b;\n        b *= b;\n        e >>= 1;\n    }\n    return ret;\n}\n\n\
    long long modpow(long long b, long long e, long long MOD=998244353) {\n    long\
    \ long ret = 1;\n    while(e) {\n        if(e & 1) ret = ret * b % MOD;\n    \
    \    b = b * b % MOD;\n        e >>= 1;\n    }\n    return ret;\n}\n\nint main()\
    \ {\n    cout << pow(2, 10) << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/pow.cpp
  requiredBy: []
  timestamp: '2024-06-21 01:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow.cpp
layout: document
redirect_from:
- /library/math/pow.cpp
- /library/math/pow.cpp.html
title: math/pow.cpp
---
