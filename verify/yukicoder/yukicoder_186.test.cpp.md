---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/crt.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  - icon: ':question:'
    path: math/ext_gcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/186
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "#line 1 \"verify/yukicoder/yukicoder_186.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/186\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"math/ext_gcd.hpp\"\ntuple<long long, long long,\
    \ long long> ext_gcd(long long a, long long b) {\n    if(b == 0) return {a, 1,\
    \ 0};\n    auto [d, y, x] = ext_gcd(b, a % b);\n    y -= a / b * x;\n    return\
    \ {d, x, y};\n}\n#line 2 \"math/crt.hpp\"\n\ninline long long safe_mod(long long\
    \ a, long long m) {\n    return (a % m + m) % m;\n}\n\npair<long long, long long>\
    \ crt(const vector<long long>& b, const vector<long long>& m) {\n    assert(b.size()\
    \ == m.size());\n    long long r = 0, M = 1;\n    for(int i = 0; i < (int)b.size();\
    \ i++) {\n        auto [d, p, q] = ext_gcd(M, m[i]);\n        if((b[i] - r) %\
    \ d != 0) return {0, -1};\n        long long tmp = (b[i] - r) / d * p % (m[i]\
    \ / d);\n        r += M * tmp;\n        M *= m[i] / d;\n    }\n    r = safe_mod(r,\
    \ M);\n    return {r, M};\n}\n#line 7 \"verify/yukicoder/yukicoder_186.test.cpp\"\
    \n\nint main() {\n    vector<long long> X(3), Y(3);\n    for(int i = 0; i < 3;\
    \ i++) {\n        cin >> X[i] >> Y[i];\n    }\n    auto [r, m] = crt(X, Y);\n\
    \    \n    if(m == -1) cout << -1 << endl;\n    else if(r == 0) cout << m << endl;\n\
    \    else cout << r << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/186\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../math/crt.hpp\"\n\nint main() {\n    vector<long\
    \ long> X(3), Y(3);\n    for(int i = 0; i < 3; i++) {\n        cin >> X[i] >>\
    \ Y[i];\n    }\n    auto [r, m] = crt(X, Y);\n    \n    if(m == -1) cout << -1\
    \ << endl;\n    else if(r == 0) cout << m << endl;\n    else cout << r << endl;\n\
    \n    return 0;\n}\n"
  dependsOn:
  - math/crt.hpp
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: verify/yukicoder/yukicoder_186.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 03:18:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yukicoder/yukicoder_186.test.cpp
layout: document
redirect_from:
- /verify/verify/yukicoder/yukicoder_186.test.cpp
- /verify/verify/yukicoder/yukicoder_186.test.cpp.html
title: verify/yukicoder/yukicoder_186.test.cpp
---
