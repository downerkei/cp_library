---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/random_number_generator.hpp
    title: math/random_number_generator.hpp
  - icon: ':heavy_check_mark:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/sqrt_floor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"math/sqrt_floor.hpp\"\nlong long sqrt_floor(long\
    \ long N) {\n    assert(0 <= N);\n    unsigned long long root = sqrtl(N);\n  \
    \  while(root * root > N) root--;\n    while((root + 1) * (root + 1) <= N) root++;\n\
    \    return root;\n}\n#line 1 \"math/random_number_generator.hpp\"\nstruct RandomNumberGenerator\
    \ {\n    mt19937 mt;\n\n    RandomNumberGenerator() : mt(random_device()()) {}\n\
    \n    // [a, b)\u306E\u7BC4\u56F2\n    long long operator()(long long a, long\
    \ long b) {\n        uniform_int_distribution<long long> dist(a, b - 1);\n   \
    \     return dist(mt);\n    }\n\n    // [0, b)\u306E\u7BC4\u56F2\n    long long\
    \ operator()(long long b) {\n        return (*this)(0, b);\n    }\n};\n#line 8\
    \ \"verify/unit_test/sqrt_floor.test.cpp\"\n\nRandomNumberGenerator rnd;\n\nvoid\
    \ test() {\n    assert(sqrt_floor(0) == 0);\n    assert(sqrt_floor(1) == 1);\n\
    \    assert(sqrt_floor(4) == 2);\n    assert(sqrt_floor(9) == 3);\n    assert(sqrt_floor(16)\
    \ == 4);\n\n    assert(sqrt_floor(2) == 1);\n    assert(sqrt_floor(3) == 1);\n\
    \    assert(sqrt_floor(5) == 2);\n    assert(sqrt_floor(8) == 2);\n    assert(sqrt_floor(10)\
    \ == 3);\n\n    assert(sqrt_floor(1000000000000000000LL) == 1000000000);\n   \
    \ assert(sqrt_floor(999999999999999999LL) == 999999999);\n\n    assert(sqrt_floor(9223372030926249001LL)\
    \ == 3037000499LL);\n    assert(sqrt_floor(9223372036854775807LL) == 3037000499LL);\n\
    \n    for(int i = 0; i < 1e7; i++) {\n        long long a = rnd(INT64_MAX);\n\
    \        unsigned long long root = sqrt_floor(a);\n        assert(root * root\
    \ <= a);\n        assert((root + 1) * (root + 1) > a);\n    }\n\n    for(int i\
    \ = 0; i < 1e7; i++) {\n        long long a = rnd(INT32_MAX);\n        long long\
    \ a2 = a * a;\n        assert(sqrt_floor(a2) == a);\n    }\n\n    cerr << \"All\
    \ tests passed\" << endl;\n}\n\nint main() {\n    test();\n    int A, B;\n   \
    \ cin >> A >> B;\n    cout << A + B << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../math/sqrt_floor.hpp\"\n#include \"../../math/random_number_generator.hpp\"\
    \n\nRandomNumberGenerator rnd;\n\nvoid test() {\n    assert(sqrt_floor(0) == 0);\n\
    \    assert(sqrt_floor(1) == 1);\n    assert(sqrt_floor(4) == 2);\n    assert(sqrt_floor(9)\
    \ == 3);\n    assert(sqrt_floor(16) == 4);\n\n    assert(sqrt_floor(2) == 1);\n\
    \    assert(sqrt_floor(3) == 1);\n    assert(sqrt_floor(5) == 2);\n    assert(sqrt_floor(8)\
    \ == 2);\n    assert(sqrt_floor(10) == 3);\n\n    assert(sqrt_floor(1000000000000000000LL)\
    \ == 1000000000);\n    assert(sqrt_floor(999999999999999999LL) == 999999999);\n\
    \n    assert(sqrt_floor(9223372030926249001LL) == 3037000499LL);\n    assert(sqrt_floor(9223372036854775807LL)\
    \ == 3037000499LL);\n\n    for(int i = 0; i < 1e7; i++) {\n        long long a\
    \ = rnd(INT64_MAX);\n        unsigned long long root = sqrt_floor(a);\n      \
    \  assert(root * root <= a);\n        assert((root + 1) * (root + 1) > a);\n \
    \   }\n\n    for(int i = 0; i < 1e7; i++) {\n        long long a = rnd(INT32_MAX);\n\
    \        long long a2 = a * a;\n        assert(sqrt_floor(a2) == a);\n    }\n\n\
    \    cerr << \"All tests passed\" << endl;\n}\n\nint main() {\n    test();\n \
    \   int A, B;\n    cin >> A >> B;\n    cout << A + B << endl;\n\n    return 0;\n\
    }\n"
  dependsOn:
  - math/sqrt_floor.hpp
  - math/random_number_generator.hpp
  isVerificationFile: true
  path: verify/unit_test/sqrt_floor.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 15:05:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/sqrt_floor.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/sqrt_floor.test.cpp
- /verify/verify/unit_test/sqrt_floor.test.cpp.html
title: verify/unit_test/sqrt_floor.test.cpp
---
