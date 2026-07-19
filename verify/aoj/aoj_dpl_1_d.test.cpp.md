---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dp/longest_increasing_subsequence.hpp
    title: dp/longest_increasing_subsequence.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"verify/aoj/aoj_dpl_1_d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"dp/longest_increasing_subsequence.hpp\"\
    \ntemplate<class T = long long>\nvector<T> longest_increasing_subsequence(const\
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
    \    }\n    return lis.size();\n}\n#line 7 \"verify/aoj/aoj_dpl_1_d.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<int> A(n);\n    for(int\
    \ i = 0; i < n; i++) {\n        cin >> A[i];\n    }\n    cout << longest_increasing_subsequence_size<int>(A)\
    \ << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../dp/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<int> A(n);\n    for(int\
    \ i = 0; i < n; i++) {\n        cin >> A[i];\n    }\n    cout << longest_increasing_subsequence_size<int>(A)\
    \ << endl;\n\n    return 0;\n}"
  dependsOn:
  - dp/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_dpl_1_d.test.cpp
  requiredBy: []
  timestamp: '2026-07-20 02:34:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/aoj_dpl_1_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_dpl_1_d.test.cpp
- /verify/verify/aoj/aoj_dpl_1_d.test.cpp.html
title: verify/aoj/aoj_dpl_1_d.test.cpp
---
