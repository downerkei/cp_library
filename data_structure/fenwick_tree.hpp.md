---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_point_add_range_sum_fenwick.test.cpp
    title: verify/yosupo/yosupo_point_add_range_sum_fenwick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/fenwick_tree.hpp\"\ntemplate <typename T>\n\
    struct FenwickTree {\n  public:\n    FenwickTree(int n) : n_(n), data(n) {}\n\n\
    \    void add(int p, T x) {\n        p++;\n        while(p <= n_) {\n        \
    \    data[p - 1] += x;\n            p += p & -p;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T s = 0;\n        while(r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n\n    T sum(int\
    \ r, int l) {\n        return sum(l) - sum(r);\n    }\n\n  private:\n    int n_;\n\
    \    vector<T> data;\n};\n"
  code: "template <typename T>\nstruct FenwickTree {\n  public:\n    FenwickTree(int\
    \ n) : n_(n), data(n) {}\n\n    void add(int p, T x) {\n        p++;\n       \
    \ while(p <= n_) {\n            data[p - 1] += x;\n            p += p & -p;\n\
    \        }\n    }\n\n    T sum(int r) {\n        T s = 0;\n        while(r > 0)\
    \ {\n            s += data[r - 1];\n            r -= r & -r;\n        }\n    \
    \    return s;\n    }\n\n    T sum(int r, int l) {\n        return sum(l) - sum(r);\n\
    \    }\n\n  private:\n    int n_;\n    vector<T> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2024-06-25 02:44:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_point_add_range_sum_fenwick.test.cpp
documentation_of: data_structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/data_structure/fenwick_tree.hpp
- /library/data_structure/fenwick_tree.hpp.html
title: data_structure/fenwick_tree.hpp
---
