---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: math/ext_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
  bundledCode: "#line 1 \"verify/aoj/aoj_ntl_1_e.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/ext_gcd.hpp\"\
    \ntuple<long long, long long, long long> ext_gcd(long long a, long long b) {\n\
    \    if(b == 0) return {a, 1, 0};\n    auto [d, y, x] = ext_gcd(b, a % b);\n \
    \   y -= a / b * x;\n    return {d, x, y};\n}\n#line 7 \"verify/aoj/aoj_ntl_1_e.test.cpp\"\
    \n\nint main() {\n    int a, b;\n    cin >> a >> b;\n    auto [d, x, y] = ext_gcd(a,\
    \ b);\n    cout << x << \" \" << y << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/ext_gcd.hpp\"\
    \n\nint main() {\n    int a, b;\n    cin >> a >> b;\n    auto [d, x, y] = ext_gcd(a,\
    \ b);\n    cout << x << \" \" << y << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_ntl_1_e.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 02:37:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_ntl_1_e.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_ntl_1_e.test.cpp
- /verify/verify/aoj/aoj_ntl_1_e.test.cpp.html
title: verify/aoj/aoj_ntl_1_e.test.cpp
---
