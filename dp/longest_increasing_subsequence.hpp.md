---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_dpl_1_d.test.cpp
    title: verify/aoj/aoj_dpl_1_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp
    title: verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/longest_increasing_subsequence.hpp\"\ntemplate<class\
    \ T = long long>\nvector<T> longest_increasing_subsequence(const vector<T>& A)\
    \ {\n    vector<T> tail;\n    vector<int> tail_idx;\n    vector<int> pre_idx(A.size(),\
    \ -1);\n    for(int i = 0; i < ssize(A); i++) {\n        // strictly -> lb, nondecreasing\
    \ -> ub\n        int len = ranges::lower_bound(tail, A[i]) - tail.begin();\n\n\
    \        if(len > 0) pre_idx[i] = tail_idx[len - 1];\n        if(len == ssize(tail))\
    \ {\n            tail.push_back(A[i]);\n            tail_idx.push_back(i);\n \
    \       }\n        else {\n            tail[len] = A[i];\n            tail_idx[len]\
    \ = i;\n        }\n    }\n\n    vector<T> lis;\n    if(tail_idx.empty()) return\
    \ lis;\n\n    for(int i = tail_idx.back(); i != -1; i = pre_idx[i]) {\n      \
    \  lis.push_back(A[i]);\n    }\n\n    ranges::reverse(lis);\n    return lis;\n\
    }\n\n\ntemplate<class T=long long>\nint longest_increasing_subsequence_size(const\
    \ vector<T> &A) {\n    vector<T> lis;\n    for(const auto& p : A) {\n        //\
    \ strictly -> lb, nondecreasing -> ub\n        auto it = ranges::lower_bound(lis,\
    \ p);\n        if(lis.end() == it) lis.push_back(p);\n        else *it = p;\n\
    \    }\n    return lis.size();\n}\n"
  code: "template<class T = long long>\nvector<T> longest_increasing_subsequence(const\
    \ vector<T>& A) {\n    vector<T> tail;\n    vector<int> tail_idx;\n    vector<int>\
    \ pre_idx(A.size(), -1);\n    for(int i = 0; i < ssize(A); i++) {\n        //\
    \ strictly -> lb, nondecreasing -> ub\n        int len = ranges::lower_bound(tail,\
    \ A[i]) - tail.begin();\n\n        if(len > 0) pre_idx[i] = tail_idx[len - 1];\n\
    \        if(len == ssize(tail)) {\n            tail.push_back(A[i]);\n       \
    \     tail_idx.push_back(i);\n        }\n        else {\n            tail[len]\
    \ = A[i];\n            tail_idx[len] = i;\n        }\n    }\n\n    vector<T> lis;\n\
    \    if(tail_idx.empty()) return lis;\n\n    for(int i = tail_idx.back(); i !=\
    \ -1; i = pre_idx[i]) {\n        lis.push_back(A[i]);\n    }\n\n    ranges::reverse(lis);\n\
    \    return lis;\n}\n\n\ntemplate<class T=long long>\nint longest_increasing_subsequence_size(const\
    \ vector<T> &A) {\n    vector<T> lis;\n    for(const auto& p : A) {\n        //\
    \ strictly -> lb, nondecreasing -> ub\n        auto it = ranges::lower_bound(lis,\
    \ p);\n        if(lis.end() == it) lis.push_back(p);\n        else *it = p;\n\
    \    }\n    return lis.size();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2026-07-20 02:34:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_dpl_1_d.test.cpp
  - verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp
documentation_of: dp/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/dp/longest_increasing_subsequence.hpp
- /library/dp/longest_increasing_subsequence.hpp.html
title: dp/longest_increasing_subsequence.hpp
---
