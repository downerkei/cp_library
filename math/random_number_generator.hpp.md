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
    \ {\n    mt19937 mt;\n    RandomNumberGenerator() : mt(random_device()()) {}\n\
    \    long long operator()(long long a, long long b) { return uniform_int_distribution<long\
    \ long>(a, b - 1)(mt); }\n    long long operator()(long long b) { return (*this)(0,\
    \ b); }\n};\n"
  code: "struct RandomNumberGenerator {\n    mt19937 mt;\n    RandomNumberGenerator()\
    \ : mt(random_device()()) {}\n    long long operator()(long long a, long long\
    \ b) { return uniform_int_distribution<long long>(a, b - 1)(mt); }\n    long long\
    \ operator()(long long b) { return (*this)(0, b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/random_number_generator.hpp
  requiredBy: []
  timestamp: '2025-03-08 01:15:39+09:00'
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
