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
  bundledCode: "#line 1 \"math/ext_gcd.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\n// ax + by = gcd(a,\
    \ b)\u3068\u306A\u308B(x, y)\u3092\u8A08\u7B97\u3057\uFF0Cd = gcd(a, b)\u3092\u8FD4\
    \u3059\n\n// a\u3092d\u3067\u5272\u3063\u3066 a = qb + r\u3068\u3059\u308B\n//\
    \ \u65B9\u7A0B\u5F0F\u306B\u4EE3\u5165\u3059\u308B\u3068\uFF0E\n// (qb + r)x +\
    \ by = d \u21D4 b(qx + y) + rx = d\n// \u3068\u3057\u3066\uFF0C(a, b)\u306E\u554F\
    \u984C\u3092(b, r)\u306E\u554F\u984C\u306B\u5E30\u7740\u3059\u308B\n// bs + rt\
    \ = d\u3092\u6E80\u305F\u3059(s, t)\u304C\u5F97\u3089\u308C\u305F\u3068\u3059\u308B\
    \u3068\uFF0C\n// x = t, y = s - qt\u3068\u5143\u306E\u89E3\u3092\u69CB\u6210\u3067\
    \u304D\u308B\n\n// dx + 0y = d\u3068\u306A\u308B\u306E\u304C\u7D42\u4E86\u6761\
    \u4EF6\n// (x, y) = (1, 0)\u3068\u306A\u308B\n\n// \u9006\u5143\u8A08\u7B97\n\
    // a\u306Em\u4E0A\u3067\u306E\u9006\u5143\u3092\u6C42\u3081\u305F\u3044(a, m\u306F\
    \u4E92\u3044\u306B\u7D20)\n// ax + my = 1 \u21D2 ax \u2261 1 mod m\n// x = a ^\
    \ -1\ntuple<long long, long long, long long> extGCD(long long a, long long b)\
    \ {\n    if(b == 0) return {a, 1, 0};\n    auto [d, y, x] = extGCD(b, a % b);\n\
    \    y -= a / b * x;\n    return {d, x, y};\n}\n\nint main() {\n    long long\
    \ a, b;\n    cin >> a >> b;\n    auto [d, x, y] = extGCD(a, b);\n\n    cout <<\
    \ x << \" \" << y << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u62E1\u5F35\u30E6\u30FC\
    \u30AF\u30EA\u30C3\u30C9\n// ax + by = gcd(a, b)\u3068\u306A\u308B(x, y)\u3092\
    \u8A08\u7B97\u3057\uFF0Cd = gcd(a, b)\u3092\u8FD4\u3059\n\n// a\u3092d\u3067\u5272\
    \u3063\u3066 a = qb + r\u3068\u3059\u308B\n// \u65B9\u7A0B\u5F0F\u306B\u4EE3\u5165\
    \u3059\u308B\u3068\uFF0E\n// (qb + r)x + by = d \u21D4 b(qx + y) + rx = d\n//\
    \ \u3068\u3057\u3066\uFF0C(a, b)\u306E\u554F\u984C\u3092(b, r)\u306E\u554F\u984C\
    \u306B\u5E30\u7740\u3059\u308B\n// bs + rt = d\u3092\u6E80\u305F\u3059(s, t)\u304C\
    \u5F97\u3089\u308C\u305F\u3068\u3059\u308B\u3068\uFF0C\n// x = t, y = s - qt\u3068\
    \u5143\u306E\u89E3\u3092\u69CB\u6210\u3067\u304D\u308B\n\n// dx + 0y = d\u3068\
    \u306A\u308B\u306E\u304C\u7D42\u4E86\u6761\u4EF6\n// (x, y) = (1, 0)\u3068\u306A\
    \u308B\n\n// \u9006\u5143\u8A08\u7B97\n// a\u306Em\u4E0A\u3067\u306E\u9006\u5143\
    \u3092\u6C42\u3081\u305F\u3044(a, m\u306F\u4E92\u3044\u306B\u7D20)\n// ax + my\
    \ = 1 \u21D2 ax \u2261 1 mod m\n// x = a ^ -1\ntuple<long long, long long, long\
    \ long> extGCD(long long a, long long b) {\n    if(b == 0) return {a, 1, 0};\n\
    \    auto [d, y, x] = extGCD(b, a % b);\n    y -= a / b * x;\n    return {d, x,\
    \ y};\n}\n\nint main() {\n    long long a, b;\n    cin >> a >> b;\n    auto [d,\
    \ x, y] = extGCD(a, b);\n\n    cout << x << \" \" << y << endl;\n\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ext_gcd.cpp
layout: document
redirect_from:
- /library/math/ext_gcd.cpp
- /library/math/ext_gcd.cpp.html
title: math/ext_gcd.cpp
---
