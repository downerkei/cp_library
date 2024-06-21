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
  bundledCode: "#line 1 \"math/is_prime.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nbool isPrime(int p) {\n    if(p < 2) return false;\n\n    for(int i\
    \ = 2; i * i <= p; i++) {\n        if(p % i == 0) return false;\n    }\n\n   \
    \ return true;\n}\n\nint main() {\n    for(int i = 0; i < 10; i++) {\n       \
    \ cout << i << \": \" << isPrime(i) << endl;\n    }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nbool isPrime(int p) {\n\
    \    if(p < 2) return false;\n\n    for(int i = 2; i * i <= p; i++) {\n      \
    \  if(p % i == 0) return false;\n    }\n\n    return true;\n}\n\nint main() {\n\
    \    for(int i = 0; i < 10; i++) {\n        cout << i << \": \" << isPrime(i)\
    \ << endl;\n    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is_prime.cpp
layout: document
redirect_from:
- /library/math/is_prime.cpp
- /library/math/is_prime.cpp.html
title: math/is_prime.cpp
---
