---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
  bundledCode: "#line 1 \"verify/aoj/aoj_ntl_1_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/factorize.hpp\"\
    \nvector<pair<long long, int>> factorize(long long N) {\n    assert(0 < N);\n\
    \    vector<pair<long long, int>> ret;\n    for(long long p = 2; p * p <= N; p++)\
    \ {\n        if(N % p != 0) continue;\n        int e = 0;\n        while(N % p\
    \ == 0) {\n            N /= p;\n            e++;\n        }\n        ret.push_back({p,\
    \ e});\n    }\n    if(N != 1) ret.push_back({N, 1});\n    return ret;\n}\n#line\
    \ 7 \"verify/aoj/aoj_ntl_1_a.test.cpp\"\n\nint main() {\n    int N;\n    cin >>\
    \ N;\n    auto primes = factorize(N);\n    cout << N << ':';\n    for(auto [p,\
    \ e] : primes) {\n        while(e--) {\n            cout << ' ' << p;\n      \
    \  }\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/factorize.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    auto primes = factorize(N);\n\
    \    cout << N << ':';\n    for(auto [p, e] : primes) {\n        while(e--) {\n\
    \            cout << ' ' << p;\n        }\n    }\n    cout << endl;\n\n    return\
    \ 0;\n}"
  dependsOn:
  - math/factorize.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_ntl_1_a.test.cpp
  requiredBy: []
  timestamp: '2024-07-03 11:46:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_ntl_1_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_ntl_1_a.test.cpp
- /verify/verify/aoj/aoj_ntl_1_a.test.cpp.html
title: verify/aoj/aoj_ntl_1_a.test.cpp
---
