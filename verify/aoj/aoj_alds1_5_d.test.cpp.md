---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: math/inversion_number.hpp
    title: math/inversion_number.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
  bundledCode: "#line 1 \"verify/aoj/aoj_alds1_5_d.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/fenwick_tree.hpp\"\ntemplate\
    \ <typename T=int>\nstruct FenwickTree {\n    int n;\n    vector<T> data;\n  \
    \  FenwickTree(int n) : n(n), data(n, 0) {}\n\n    void add(int p, T x) {\n  \
    \      for(p++; p <= n; p += p & -p) data[p - 1] += x;\n    }\n\n    T sum(int\
    \ r) {\n        T s = 0;\n        for(; r; r -= r & -r) s += data[r - 1];\n  \
    \      return s;\n    }\n    \n    T sum(int l, int r) {\n        return sum(r)\
    \ - sum(l);\n    }\n};\n#line 2 \"math/inversion_number.hpp\"\n\ntemplate<typename\
    \ T>\nlong long inversion_number(const vector<T>& A) {\n    vector<T> B = A;\n\
    \    sort(B.begin(), B.end());\n    B.erase(unique(B.begin(), B.end()), B.end());\n\
    \n    FenwickTree<T> bit(B.size());\n\n    long long ret = 0;\n    for(int i =\
    \ 0; i < (int)A.size(); i++) {\n        int rank = lower_bound(B.begin(), B.end(),\
    \ A[i]) - B.begin() + 1;\n        ret += i - bit.sum(rank);\n        bit.add(rank,\
    \ 1);\n    }\n    return ret;\n}\n#line 7 \"verify/aoj/aoj_alds1_5_d.test.cpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    cout << inversion_number<int>(A)\
    \ << endl;\n    \n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/inversion_number.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    cout << inversion_number<int>(A)\
    \ << endl;\n    \n\n    return 0;\n}\n"
  dependsOn:
  - math/inversion_number.hpp
  - data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_alds1_5_d.test.cpp
  requiredBy: []
  timestamp: '2025-02-27 06:13:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_alds1_5_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_alds1_5_d.test.cpp
- /verify/verify/aoj/aoj_alds1_5_d.test.cpp.html
title: verify/aoj/aoj_alds1_5_d.test.cpp
---
