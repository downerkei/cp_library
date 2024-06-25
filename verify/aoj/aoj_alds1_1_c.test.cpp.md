---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"verify/aoj/aoj_alds1_1_c.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/is_prime.hpp\"\nbool\
    \ is_prime(long long p) {\n    if(p < 2) return false;\n\n    for(long long i\
    \ = 2; i * i <= p; i++) {\n        if(p % i == 0) return false;\n    }\n\n   \
    \ return true;\n}\n#line 7 \"verify/aoj/aoj_alds1_1_c.test.cpp\"\n\nint main()\
    \ {\n    int N;\n    cin >> N;\n    int ans = 0;\n    while(N--) {\n        int\
    \ a;\n        cin >> a;\n        ans += is_prime(a);\n    }\n    cout << ans <<\
    \ endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/is_prime.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    int ans = 0;\n    while(N--)\
    \ {\n        int a;\n        cin >> a;\n        ans += is_prime(a);\n    }\n \
    \   cout << ans << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - math/is_prime.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_alds1_1_c.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 09:33:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_alds1_1_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_alds1_1_c.test.cpp
- /verify/verify/aoj/aoj_alds1_1_c.test.cpp.html
title: verify/aoj/aoj_alds1_1_c.test.cpp
---
