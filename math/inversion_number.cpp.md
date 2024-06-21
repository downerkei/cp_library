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
  bundledCode: "#line 1 \"math/inversion_number.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\nstruct FenwickTree {\n  public:\n\
    \    FenwickTree(int n) : n_(n), data(n) {}\n\n    void add(int p, T x) {\n  \
    \      p++;\n        while(p <= n_) {\n            data[p - 1] += x;\n       \
    \     p += p & -p;\n        }\n    }\n\n    T sum(int r) {\n        T s = 0;\n\
    \        while(r > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n\
    \        }\n        return s;\n    }\n\n    T sum(int r, int l) {\n        return\
    \ sum(l) - sum(r);\n    }\n\n  private:\n    int n_;\n    vector<T> data;\n};\n\
    \n// \u8EE2\u5012\u6570\u3092\u6C42\u3081\u308B\n// FenwickTree\u304C\u5FC5\u8981\
    \ntemplate<typename T>\nlong long inversion_number(const vector<T>& A) {\n   \
    \ vector<T> B = A;\n    sort(B.begin(), B.end());\n    B.erase(unique(B.begin(),\
    \ B.end()), B.end());\n\n    FenwickTree<T> bit(B.size());\n\n    long long ret\
    \ = 0;\n    for(int i = 0; i < (int)A.size(); i++) {\n        int rank = lower_bound(B.begin(),\
    \ B.end(), A[i]) - B.begin() + 1;\n        ret += i - bit.sum(rank);\n       \
    \ bit.add(rank, 1);\n    }\n    return ret;\n}\n\nint main() {\n    int N;\n \
    \   cin >> N;\n    vector<int> A(N);\n    for(int i = 0; i < N; i++) {\n     \
    \   cin >> A[i];\n    }\n    cout << inversion_number<int> (A) << endl;\n\n  \
    \  return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T>\n\
    struct FenwickTree {\n  public:\n    FenwickTree(int n) : n_(n), data(n) {}\n\n\
    \    void add(int p, T x) {\n        p++;\n        while(p <= n_) {\n        \
    \    data[p - 1] += x;\n            p += p & -p;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T s = 0;\n        while(r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n\n    T sum(int\
    \ r, int l) {\n        return sum(l) - sum(r);\n    }\n\n  private:\n    int n_;\n\
    \    vector<T> data;\n};\n\n// \u8EE2\u5012\u6570\u3092\u6C42\u3081\u308B\n//\
    \ FenwickTree\u304C\u5FC5\u8981\ntemplate<typename T>\nlong long inversion_number(const\
    \ vector<T>& A) {\n    vector<T> B = A;\n    sort(B.begin(), B.end());\n    B.erase(unique(B.begin(),\
    \ B.end()), B.end());\n\n    FenwickTree<T> bit(B.size());\n\n    long long ret\
    \ = 0;\n    for(int i = 0; i < (int)A.size(); i++) {\n        int rank = lower_bound(B.begin(),\
    \ B.end(), A[i]) - B.begin() + 1;\n        ret += i - bit.sum(rank);\n       \
    \ bit.add(rank, 1);\n    }\n    return ret;\n}\n\nint main() {\n    int N;\n \
    \   cin >> N;\n    vector<int> A(N);\n    for(int i = 0; i < N; i++) {\n     \
    \   cin >> A[i];\n    }\n    cout << inversion_number<int> (A) << endl;\n\n  \
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/inversion_number.cpp
  requiredBy: []
  timestamp: '2024-06-21 01:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inversion_number.cpp
layout: document
redirect_from:
- /library/math/inversion_number.cpp
- /library/math/inversion_number.cpp.html
title: math/inversion_number.cpp
---
