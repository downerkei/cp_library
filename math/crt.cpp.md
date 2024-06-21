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
  bundledCode: "#line 1 \"math/crt.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ninline long long safe_mod(long long a, long long m) {\n    return (a\
    \ % m + m) % m;\n}\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\n//\
    \ ax + by = gcd(a, b)\u3092\u6E80\u305F\u3059(gcd(a, b), x, y)\u3092\u8FD4\u3059\
    \ntuple<long long, long long, long long> extGCD(long long a, long long b) {\n\
    \    if(b == 0) return {a, 1, 0};\n    auto [d, y, x] = extGCD(b, a % b);\n  \
    \  y -= a / b * x;\n    return {d, x, y};\n}\n\n// \u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\n// x \u2261 b1 mod m1, x \u2261 b2 mod m2\u3092\u307F\u305F\u3059x\u304C\
    x \u2261 r mod m\u3068\u66F8\u3051\u308B\u3068\u304D\uFF0C\n// (r, m)\u3092\u8FD4\
    \u3059\uFF0C\u89E3\u304C\u306A\u3051\u308C\u3070(0, -1)\u3092\u8FD4\u3059\n\n\
    // x \u2261 b1 mod m1, x \u2261 b2 mod m2\u3092\u307F\u305F\u3059x \u2261 r mod\
    \ m\u304C\u5B58\u5728\u3059\u308B\u306B\u306F\uFF0C\n// b1 \u2261 b2 mod gcd(m1,\
    \ m2)\u304C\u5FC5\u8981\n\n// d = gcd(m1, m2)\u3068\u304A\u304F\u3068\uFF0Cm1p\
    \ + m2q = d\u3092\u6E80\u305F\u3059(p, q)\u304C\u69CB\u6210\u3067\u304D\u308B\n\
    // b1 \u2261 b2 mod d\u3088\u308A\uFF0Cb2 - b1\u306Fd\u3067\u5272\u308A\u5207\u308C\
    \u308B\uFF0E\n// s = (b2 - b1) / d\u3068\u304A\u304F\u3068\uFF0Csm1p + sm2q =\
    \ b2 - b1\u3068\u306A\u308B\uFF0E\n// \u5F0F\u5909\u5F62\u3057\uFF0Cb1 + sm1p\
    \ = b2 - sm2q\u3068\u3057\uFF0C\u5DE6\u8FBA\u3092x\u3068\u304A\u304F\u3068\uFF0C\
    \n// x \u2261 b1 mod m1, x \u2261 b2 mod m2\u3092\u6E80\u305F\u3059\uFF0E\npair<long\
    \ long, long long> CRT(const vector<long long>& b, const vector<long long>& m)\
    \ {\n    long long r = 0, M = 1;\n    for(int i = 0; i < (int)b.size(); i++) {\n\
    \        auto [d, p, q] = extGCD(M, m[i]);\n        if((b[i] - r) % d != 0) return\
    \ {0, -1};\n        long long tmp = (b[i] - r) / d * p % (m[i] / d);\n       \
    \ r += M * tmp;\n        M *= m[i] / d;\n    }\n    r = safe_mod(r, M);\n    return\
    \ {r, M};\n}\n\nint main() {\n    vector<long long> b(3), m(3);\n    for(int i\
    \ = 0; i < 3; i++) {\n        cin >> b[i] >> m[i];\n    }\n    auto [R, M] = CRT(b,\
    \ m);\n    if(M == -1) cout << -1 << endl;\n    else if(R == 0) cout << M << endl;\n\
    \    else cout << R << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ninline long long safe_mod(long\
    \ long a, long long m) {\n    return (a % m + m) % m;\n}\n\n// \u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\n// ax + by = gcd(a, b)\u3092\u6E80\u305F\u3059\
    (gcd(a, b), x, y)\u3092\u8FD4\u3059\ntuple<long long, long long, long long> extGCD(long\
    \ long a, long long b) {\n    if(b == 0) return {a, 1, 0};\n    auto [d, y, x]\
    \ = extGCD(b, a % b);\n    y -= a / b * x;\n    return {d, x, y};\n}\n\n// \u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\n// x \u2261 b1 mod m1, x \u2261 b2 mod m2\u3092\
    \u307F\u305F\u3059x\u304Cx \u2261 r mod m\u3068\u66F8\u3051\u308B\u3068\u304D\uFF0C\
    \n// (r, m)\u3092\u8FD4\u3059\uFF0C\u89E3\u304C\u306A\u3051\u308C\u3070(0, -1)\u3092\
    \u8FD4\u3059\n\n// x \u2261 b1 mod m1, x \u2261 b2 mod m2\u3092\u307F\u305F\u3059\
    x \u2261 r mod m\u304C\u5B58\u5728\u3059\u308B\u306B\u306F\uFF0C\n// b1 \u2261\
    \ b2 mod gcd(m1, m2)\u304C\u5FC5\u8981\n\n// d = gcd(m1, m2)\u3068\u304A\u304F\
    \u3068\uFF0Cm1p + m2q = d\u3092\u6E80\u305F\u3059(p, q)\u304C\u69CB\u6210\u3067\
    \u304D\u308B\n// b1 \u2261 b2 mod d\u3088\u308A\uFF0Cb2 - b1\u306Fd\u3067\u5272\
    \u308A\u5207\u308C\u308B\uFF0E\n// s = (b2 - b1) / d\u3068\u304A\u304F\u3068\uFF0C\
    sm1p + sm2q = b2 - b1\u3068\u306A\u308B\uFF0E\n// \u5F0F\u5909\u5F62\u3057\uFF0C\
    b1 + sm1p = b2 - sm2q\u3068\u3057\uFF0C\u5DE6\u8FBA\u3092x\u3068\u304A\u304F\u3068\
    \uFF0C\n// x \u2261 b1 mod m1, x \u2261 b2 mod m2\u3092\u6E80\u305F\u3059\uFF0E\
    \npair<long long, long long> CRT(const vector<long long>& b, const vector<long\
    \ long>& m) {\n    long long r = 0, M = 1;\n    for(int i = 0; i < (int)b.size();\
    \ i++) {\n        auto [d, p, q] = extGCD(M, m[i]);\n        if((b[i] - r) % d\
    \ != 0) return {0, -1};\n        long long tmp = (b[i] - r) / d * p % (m[i] /\
    \ d);\n        r += M * tmp;\n        M *= m[i] / d;\n    }\n    r = safe_mod(r,\
    \ M);\n    return {r, M};\n}\n\nint main() {\n    vector<long long> b(3), m(3);\n\
    \    for(int i = 0; i < 3; i++) {\n        cin >> b[i] >> m[i];\n    }\n    auto\
    \ [R, M] = CRT(b, m);\n    if(M == -1) cout << -1 << endl;\n    else if(R == 0)\
    \ cout << M << endl;\n    else cout << R << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/crt.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/crt.cpp
layout: document
redirect_from:
- /library/math/crt.cpp
- /library/math/crt.cpp.html
title: math/crt.cpp
---
