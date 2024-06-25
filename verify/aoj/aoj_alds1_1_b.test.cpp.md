---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/gcd.hpp
    title: math/gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_B
  bundledCode: "#line 1 \"verify/aoj/aoj_alds1_1_b.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_B\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"math/gcd.hpp\"\nlong long gcd(long long a, long\
    \ long b) {\n    if(b == 0) return a;\n    return gcd(b, a % b);\n}\n#line 7 \"\
    verify/aoj/aoj_alds1_1_b.test.cpp\"\n\nint main() {\n    int x, y;\n    cin >>\
    \ x >> y;\n    cout << gcd(x, y) << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_B\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/gcd.hpp\"\
    \n\nint main() {\n    int x, y;\n    cin >> x >> y;\n    cout << gcd(x, y) <<\
    \ endl;\n\n    return 0;\n}\n"
  dependsOn:
  - math/gcd.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_alds1_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 02:22:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_alds1_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_alds1_1_b.test.cpp
- /verify/verify/aoj/aoj_alds1_1_b.test.cpp.html
title: verify/aoj/aoj_alds1_1_b.test.cpp
---
