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
  bundledCode: "#line 1 \"math/random_number_generator.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct RandomNumberGenerator {\n    mt19937 mt;\n\n  \
    \  RandomNumberGenerator() : mt(random_device()()) {}\n\n    // [a, b)\u306E\u7BC4\
    \u56F2\n    long long operator()(long long a, long long b) {\n        uniform_int_distribution<long\
    \ long> dist(a, b - 1);\n        return dist(mt);\n    }\n\n    // [0, b)\u306E\
    \u7BC4\u56F2\n    long long operator()(long long b) {\n        return (*this)(0,\
    \ b);\n    }\n};\n\nint main() {\n    RandomNumberGenerator rnd;\n\n    cout <<\
    \ rnd(10) << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct RandomNumberGenerator\
    \ {\n    mt19937 mt;\n\n    RandomNumberGenerator() : mt(random_device()()) {}\n\
    \n    // [a, b)\u306E\u7BC4\u56F2\n    long long operator()(long long a, long\
    \ long b) {\n        uniform_int_distribution<long long> dist(a, b - 1);\n   \
    \     return dist(mt);\n    }\n\n    // [0, b)\u306E\u7BC4\u56F2\n    long long\
    \ operator()(long long b) {\n        return (*this)(0, b);\n    }\n};\n\nint main()\
    \ {\n    RandomNumberGenerator rnd;\n\n    cout << rnd(10) << endl;\n\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/random_number_generator.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/random_number_generator.cpp
layout: document
redirect_from:
- /library/math/random_number_generator.cpp
- /library/math/random_number_generator.cpp.html
title: math/random_number_generator.cpp
---
