---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/inversion_number.hpp
    title: math/inversion_number.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_5_d.test.cpp
    title: verify/aoj/aoj_alds1_5_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_point_add_range_sum_fenwick.test.cpp
    title: verify/yosupo/yosupo_point_add_range_sum_fenwick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/fenwick_tree.hpp\"\ntemplate <typename T=int>\n\
    struct FenwickTree {\n    int n;\n    vector<T> data;\n    FenwickTree(int n)\
    \ : n(n), data(n, 0) {}\n\n    void add(int p, T x) {\n        p++;\n        while(p\
    \ <= n) {\n            data[p - 1] += x;\n            p += p & -p;\n        }\n\
    \    }\n\n    T sum(int r) {\n        T s = 0;\n        while(r > 0) {\n     \
    \       s += data[r - 1];\n            r -= r & -r;\n        }\n        return\
    \ s;\n    }\n    \n    T sum(int l, int r) {\n        return sum(r) - sum(l);\n\
    \    }\n};\n"
  code: "template <typename T=int>\nstruct FenwickTree {\n    int n;\n    vector<T>\
    \ data;\n    FenwickTree(int n) : n(n), data(n, 0) {}\n\n    void add(int p, T\
    \ x) {\n        p++;\n        while(p <= n) {\n            data[p - 1] += x;\n\
    \            p += p & -p;\n        }\n    }\n\n    T sum(int r) {\n        T s\
    \ = 0;\n        while(r > 0) {\n            s += data[r - 1];\n            r -=\
    \ r & -r;\n        }\n        return s;\n    }\n    \n    T sum(int l, int r)\
    \ {\n        return sum(r) - sum(l);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy:
  - math/inversion_number.hpp
  timestamp: '2025-02-11 15:51:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_point_add_range_sum_fenwick.test.cpp
  - verify/aoj/aoj_alds1_5_d.test.cpp
documentation_of: data_structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/data_structure/fenwick_tree.hpp
- /library/data_structure/fenwick_tree.hpp.html
title: data_structure/fenwick_tree.hpp
---
