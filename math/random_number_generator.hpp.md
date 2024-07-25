---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/montgomery_modint_32.test.cpp
    title: verify/unit_test/montgomery_modint_32.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/sqrt_floor.test.cpp
    title: verify/unit_test/sqrt_floor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/random_number_generator.hpp\"\nstruct RandomNumberGenerator\
    \ {\n    mt19937 mt;\n\n    RandomNumberGenerator() : mt(random_device()()) {}\n\
    \n    // [a, b)\u306E\u7BC4\u56F2\n    long long operator()(long long a, long\
    \ long b) {\n        uniform_int_distribution<long long> dist(a, b - 1);\n   \
    \     return dist(mt);\n    }\n\n    // [0, b)\u306E\u7BC4\u56F2\n    long long\
    \ operator()(long long b) {\n        return (*this)(0, b);\n    }\n};\n"
  code: "struct RandomNumberGenerator {\n    mt19937 mt;\n\n    RandomNumberGenerator()\
    \ : mt(random_device()()) {}\n\n    // [a, b)\u306E\u7BC4\u56F2\n    long long\
    \ operator()(long long a, long long b) {\n        uniform_int_distribution<long\
    \ long> dist(a, b - 1);\n        return dist(mt);\n    }\n\n    // [0, b)\u306E\
    \u7BC4\u56F2\n    long long operator()(long long b) {\n        return (*this)(0,\
    \ b);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/random_number_generator.hpp
  requiredBy: []
  timestamp: '2024-06-22 04:42:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/montgomery_modint_32.test.cpp
  - verify/unit_test/sqrt_floor.test.cpp
documentation_of: math/random_number_generator.hpp
layout: document
redirect_from:
- /library/math/random_number_generator.hpp
- /library/math/random_number_generator.hpp.html
title: math/random_number_generator.hpp
---
