---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_5_d.test.cpp
    title: verify/aoj/aoj_alds1_5_d.test.cpp
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
    \    }\n};\n#line 2 \"math/inversion_number.hpp\"\n\ntemplate<typename T>\nlong\
    \ long inversion_number(const vector<T>& A) {\n    vector<T> B = A;\n    sort(B.begin(),\
    \ B.end());\n    B.erase(unique(B.begin(), B.end()), B.end());\n\n    FenwickTree<T>\
    \ bit(B.size());\n\n    long long ret = 0;\n    for(int i = 0; i < (int)A.size();\
    \ i++) {\n        int rank = lower_bound(B.begin(), B.end(), A[i]) - B.begin()\
    \ + 1;\n        ret += i - bit.sum(rank);\n        bit.add(rank, 1);\n    }\n\
    \    return ret;\n}\n"
  code: "#include \"../data_structure/fenwick_tree.hpp\"\n\ntemplate<typename T>\n\
    long long inversion_number(const vector<T>& A) {\n    vector<T> B = A;\n    sort(B.begin(),\
    \ B.end());\n    B.erase(unique(B.begin(), B.end()), B.end());\n\n    FenwickTree<T>\
    \ bit(B.size());\n\n    long long ret = 0;\n    for(int i = 0; i < (int)A.size();\
    \ i++) {\n        int rank = lower_bound(B.begin(), B.end(), A[i]) - B.begin()\
    \ + 1;\n        ret += i - bit.sum(rank);\n        bit.add(rank, 1);\n    }\n\
    \    return ret;\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  isVerificationFile: false
  path: math/inversion_number.hpp
  requiredBy: []
  timestamp: '2025-02-11 15:51:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_alds1_5_d.test.cpp
documentation_of: math/inversion_number.hpp
layout: document
redirect_from:
- /library/math/inversion_number.hpp
- /library/math/inversion_number.hpp.html
title: math/inversion_number.hpp
---
