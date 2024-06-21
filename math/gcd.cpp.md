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
  bundledCode: "#line 1 \"math/gcd.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nlong long GCD(long long a, long long b) {\n    if(b == 0) return a;\n\
    \    return GCD(b, a % b);\n}\n\nint main() {\n\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nlong long GCD(long long\
    \ a, long long b) {\n    if(b == 0) return a;\n    return GCD(b, a % b);\n}\n\n\
    int main() {\n\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/gcd.cpp
  requiredBy: []
  timestamp: '2024-06-21 01:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gcd.cpp
layout: document
redirect_from:
- /library/math/gcd.cpp
- /library/math/gcd.cpp.html
title: math/gcd.cpp
---
