---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/longest_increasing_subsequence.hpp
    title: dp/longest_increasing_subsequence.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
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
    \    }\n    return lis.size();\n}\n#line 7 \"verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int N;\n    cin >> N;\n    vector<int> A(N);\n\n    for(int i = 0; i\
    \ < N; i++) {\n        cin >> A[i];\n    }\n\n    auto lis = longest_increasing_subsequence<int>(A);\n\
    \n    vector<int> ans(lis.size(), 0);\n    int it = 0;\n    for(int i = 0; i <\
    \ N; i++) {\n        if(A[i] == lis[it]) {\n            ans[it] = i;\n       \
    \     it++;\n            if(it == lis.size()) break;\n        }\n    }\n\n   \
    \ cout << ans.size() << \"\\n\";\n    for(auto a : ans) {\n        cout << a <<\
    \ \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../dp/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int N;\n    cin >> N;\n    vector<int> A(N);\n\n    for(int i = 0; i\
    \ < N; i++) {\n        cin >> A[i];\n    }\n\n    auto lis = longest_increasing_subsequence<int>(A);\n\
    \n    vector<int> ans(lis.size(), 0);\n    int it = 0;\n    for(int i = 0; i <\
    \ N; i++) {\n        if(A[i] == lis[it]) {\n            ans[it] = i;\n       \
    \     it++;\n            if(it == lis.size()) break;\n        }\n    }\n\n   \
    \ cout << ans.size() << \"\\n\";\n    for(auto a : ans) {\n        cout << a <<\
    \ \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - dp/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2026-07-20 02:34:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp
- /verify/verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp.html
title: verify/yosupo/yosupo_longest_increasing_subsequence.test.cpp
---
